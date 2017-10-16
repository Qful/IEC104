/*
 * sntpclient.c
 *
 *  Created on: 28.02.2017
 *      Author: sagok
 */


/* ----------------------- FreeRTOS includes --------------------------------*/
/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "timers.h"

#include "port.h"

#include "cmsis_os.h"


#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"
#include "stm32f4xx_hal_tim.h"
#include "stm32f4xx_it.h"


#include "main.h"
#include "hal_time.h"
#include "hal_socket.h"
#include <string.h>

#include "NTPClient.h"
#include "sntpclient.h"
#include "lwip/sockets.h"

#include "modbus.h"
//int iTimeZone = 3600 * Timezone;

enum EStatus {
	EStatusLookup,
	EStatusAsking,
	EStatusPause,
	EStatusFailed,
};

static struct SNtpPacket 	xNTPPacket;
static uint32_t 			ulIPAddressFound;					// IP адрес NTP сервера
static TickType_t 			uxSendTime;							// время отправки сообщения
uint64_t	startSendTimeMs;
uint64_t	TravelTimeMs;


static char cRecvBuffer[ sizeof( struct SNtpPacket ) + 64 ];

static enum EStatus xStatus = EStatusLookup;

static int xUDPSocket = NULL;

static void prvReadTime( struct SNtpPacket * pxPacket );
void 		prvNTPPacketInit(void);

BOOL		Hal_setTimeToMB_Date( uint16_t * MDateBuf );

// очереди -----------------------------
extern xQueueHandle 	ModbusSentTime;		// очередь для отправки в модбас
extern xQueueHandle 	ModbusSentQueue;		// очередь для отправки в модбас


extern bool			SetTimeNow;
extern uint8_t		writeNmb;
extern uint16_t		SNTP_Period;
extern int8_t		TimeZone_my;
/*  Часы ------------------------------------------------------------*/
extern RTC_HandleTypeDef hrtc;
/*  -----------------------------------------------------------------*/
extern	RTC_TimeTypeDef lastSynchTime;
extern	RTC_DateTypeDef lastSynchDate;

extern	int16_t	lostSNTPPackets;

/*****************************************************************************************************
 * void sntp_client_serve(Socket self)
 *
 *****************************************************************************************************/
int sntp_client_serve(Socket self, const char* address, int port, int sent){

	struct sockaddr_in serverAddress;

	socklen_t			AddressSizeFrom;
	int 				ret;
	unsigned char 		recv_buffer[ sizeof( struct SNtpPacket ) + 64 ];
	int 				buflen = sizeof( struct SNtpPacket ) + 64;


	AddressSizeFrom = sizeof(serverAddress);

	int conn = GetSocket_num(self);		// проверяем есть ли такой сокет

	if (sent)
	{

		prvNTPPacketInit();

        prepareServerAddress(address, port, &serverAddress);

        if (lostSNTPPackets < 30000)	lostSNTPPackets++;						// подсчет потеряных пакетов
        startSendTimeMs = Hal_getTimeInMs();
//		uxSendTime = xTaskGetTickCount();		// запоминаем время отправки
		ret = sendto( conn, ( void * )&xNTPPacket, sizeof(xNTPPacket), 0, (struct sockaddr *) &serverAddress, AddressSizeFrom );	// адрес и порт получателя дэйтаграммы.
		if (ret<1) return 1;
//		USART_0TRACE("SNTP: Отправляем UDP сообщение к %s:%u\n", address, port);
		return 0;
	}else
	{
		ret = recvfrom( conn, (void *)recv_buffer, buflen, 0,(struct sockaddr *)&serverAddress, &AddressSizeFrom );		// в serverAddress будет адрес отправителя дэйтаграммы


		if(ret == 0) {
		  USART_TRACE_RED("SNTP: Разорвали соединение со стороны клиента. Закрываем.\n");
 		  Socket_destroy(conn);
		  return 0;
		}else
		if(ret < 0) {
//		  USART_TRACE_ReED("SNTP: Из буфера ничего не прочитали. Закрываем. %i\n",ret);
//		  Socket_destroy(conn);
		  return 0;
		}
	  // --------------------------------------------------------------
//		USART_TRACE_GREEN("SNTP: приняли UDP сообщение от %s:%u\n", serverAddress.sin_addr.s_addr, serverAddress.sin_port);

		if( ret < sizeof(xNTPPacket) )
		{
			USART_TRACE_RED("SNTP: прочитали меньше чем xNTPPacket. %ld\n", ret);
		    return 0;
		}
		else
		{
			// приняли сообщение от сервера времени. Нужно указать что не нужно брать время из модбаса
			prvReadTime( ( struct SNtpPacket *)recv_buffer );		// расшифровываем время

			lostSNTPPackets = 0;
			//if (lostSNTPPackets )	lostSNTPPackets--;						// подсчет потеряных пакетов

		    // получили время последней синхронизации времени.
			  HAL_RTC_GetTime((RTC_HandleTypeDef *)&hrtc, &lastSynchTime, FORMAT_BIN);
			  HAL_RTC_GetDate((RTC_HandleTypeDef *)&hrtc, &lastSynchDate, FORMAT_BIN);

		}
		  return 1;
	  // --------------------------------------------------------------
	}
}

/*****************************************************************************************************
 * static void prvSwapFields( struct SNtpPacket *pxPacket)
 *
 *****************************************************************************************************/
static void prvSwapFields( struct SNtpPacket *pxPacket)
{
	/* NTP messages are big-endian */
	pxPacket->rootDelay = htonl( pxPacket->rootDelay );
	pxPacket->rootDispersion = htonl( pxPacket->rootDispersion );

	pxPacket->referenceTimestamp.seconds = htonl( pxPacket->referenceTimestamp.seconds );
	pxPacket->referenceTimestamp.fraction = htonl( pxPacket->referenceTimestamp.fraction );

	pxPacket->originateTimestamp.seconds = htonl( pxPacket->originateTimestamp.seconds );
	pxPacket->originateTimestamp.fraction = htonl( pxPacket->originateTimestamp.fraction );

	pxPacket->receiveTimestamp.seconds = htonl( pxPacket->receiveTimestamp.seconds );
	pxPacket->receiveTimestamp.fraction = htonl( pxPacket->receiveTimestamp.fraction );

	pxPacket->transmitTimestamp.seconds = htonl( pxPacket->transmitTimestamp.seconds );
	pxPacket->transmitTimestamp.fraction = htonl( pxPacket->transmitTimestamp.fraction );
}

/*****************************************************************************************************
 * static void prvNTPPacketInit( )
 * 83AA7E80 seconds 1января 1970г 0:0:0
 * отсылаем запрос с временем UTC убрав часовой пояс
 *****************************************************************************************************/
void prvNTPPacketInit(void)
{
	memset (&xNTPPacket, '\0', sizeof(xNTPPacket));

	xNTPPacket.flags = 0xDB;							/* value 0xDB : mode 3 (client), version 3, leap indicator unknown 3 */ // Индикатор коррекции(2 бита), Номер версии(3 бита),Режим(3 бита)
	xNTPPacket.stratum = 3;							//Часовой слой(8 бит) (2-15	Вторичный сервер, использующий NTP)
	xNTPPacket.poll = 10;								/* 10 means 1 << 10 = 1024 seconds */ 	// Интервал опроса(8 бит)  Значение равно двоичному логарифму секунд.
	xNTPPacket.precision = 250;						/* = 250 = 0.015625 seconds */		 	//Точность
	xNTPPacket.rootDelay = 0x0D2E;						/* 0x5D2E = 23854 or (23854/65535)= 0.3640 sec */	//Задержка (Общее время распространения сигнала в обе стороны в коротком формате NTP.)
	xNTPPacket.rootDispersion = 0x0008CAC8;				/* 0x0008CAC8 = 8.7912  seconds */	//(Общая дисперсия для источника времени в коротком формате NTP.)

	/* use the recorded NTP time */
	// Получаем от часов время в ms от лохматого 70-го года.
	uint64_t	 uxSecs = Hal_getTimeInMs();			//FreeRTOS_time( NULL );/* apTime may be NULL, returns seconds */
	//NTP время отсчитывается с полуночи 1 января 1900 года, а не с 1970, поэтому из времени NTP нужно вычитать почти 70 лет (с учётом високосных лет)
//	uxSecs += Timezone*60*60*1000;

	xNTPPacket.referenceTimestamp.seconds = base1970 + (uxSecs/1000);//3697447200 - 2400 - 43200 - 172800 - 1482192000 - 8640000 +2505600 + 86400;	/* Current time */
	xNTPPacket.referenceTimestamp.fraction = (uxSecs%1000)*base1ms;//(uxSecs%1000)*4294968; 1mc точность

	xNTPPacket.transmitTimestamp.seconds = base1970 + (uxSecs/1000);
	xNTPPacket.transmitTimestamp.fraction = (uxSecs%1000)*base1ms;//(uxSecs%1000)*4294968; 1mc точность			43645464

	/* Transform the contents of the fields from native to big endian. */
	prvSwapFields( &xNTPPacket );
}

/*****************************************************************************************************
 * static void prvReadTime( struct SNtpPacket * pxPacket )
 * нужно доделать учет времени распространения сигнала
 *****************************************************************************************************/
//#define		StrobeSynchTime		11
#define		Secunda				1000

static void prvReadTime( struct SNtpPacket * pxPacket )
{
//	uint64_t	PreviousMS = 0;
	uint64_t	CurrentTimeMS;
	uint64_t	OriginateTimeMS;
	int64_t		CorrectTimeMS;

	uint16_t		DelayTimeMS;

	uint16_t		StrobeSynchTime;

	uint16_t		DelayTimeMSForWait = 0;

//	FF_TimeStruct_t xTimeStruct;
//	time_t uxPreviousSeconds;
//	time_t uxPreviousMS;

	time_t uxCurrentSeconds;
	time_t uxCurrentMS;

//	const char *pcTimeUnit;
//	int32_t ilDiff;
//	TickType_t uxTravelTime;

	StrobeSynchTime = Hal_getTimeInMs()%1000 - 1;
//	uxTravelTime = xTaskGetTickCount() - uxSendTime;							// время от начала передачи до текущего момента в тиках
	TravelTimeMs = Hal_getTimeInMs() - startSendTimeMs;							// время от начала передачи до текущего момента d мс
	prvSwapFields( pxPacket );													// Transform the contents of the fields from big to native endian.

	// полученное время
	/*
	 * originateTimestamp	- клиент отправил запрос на сервер.
	 * receiveTimestamp 	- запрос пришел на сервер.
	 * transmitTimestamp	- ответ отправлен сервером для клиента.
	 */
	uxCurrentSeconds = pxPacket->receiveTimestamp.seconds - TIME1970;
	uxCurrentMS = pxPacket->receiveTimestamp.fraction / base1ms;
	uxCurrentSeconds += uxCurrentMS / 1000;
	uxCurrentMS = uxCurrentMS % 1000;

	CurrentTimeMS = (uint64_t)uxCurrentSeconds*1000 + (uint64_t)uxCurrentMS;				// правильное время (прием пакета на сервере)

	uint64_t uxOriginateSeconds = pxPacket->originateTimestamp.seconds - TIME1970;
	uint64_t uxOriginateMS = pxPacket->originateTimestamp.fraction / base1ms;
	uxOriginateSeconds += uxOriginateMS / 1000;
	uxOriginateMS = uxOriginateMS % 1000;
	OriginateTimeMS = (uint64_t)uxOriginateSeconds*1000 + (uint64_t)uxOriginateMS;		// время отправки мной

	// правильное текущее время = текущее время +(или - если в другую сторону) время принятия сервером + TravelTimeMs/2(приблизительно, считаем что время отправки = времени приема)
	CorrectTimeMS = (int64_t)CurrentTimeMS - (int64_t)OriginateTimeMS;
	// полоительное число если на сервере время больше чем у меня. Это значит мне надо подвести вперёд
	// дожидаюсь конец секунды и устанавливаю время

	if (CorrectTimeMS < 0){
		DelayTimeMS = (-CorrectTimeMS)%1000;
		USART_TRACE_GREEN("-ms %u, lev %u\n",DelayTimeMS,StrobeSynchTime);
	} else {
		DelayTimeMS = CorrectTimeMS%1000;
		USART_TRACE_RED("+ms %u, lev %u\n",DelayTimeMS,StrobeSynchTime);
	}

//#define	Time1ms
#define	Time1ms_debug
#if defined (Time1ms_debug)
	if (CorrectTimeMS > 0) {
		if (DelayTimeMS > (Secunda-StrobeSynchTime)){
		// +989... +nd
			DelayTimeMSForWait = Secunda-StrobeSynchTime + (Secunda - DelayTimeMS);
		}else
		{
		// 0...+989
			DelayTimeMSForWait = Secunda-StrobeSynchTime - DelayTimeMS;
		}
	} else
	if (CorrectTimeMS < 0) {
		if (DelayTimeMS > StrobeSynchTime){
		// -nd...-12
			DelayTimeMSForWait = DelayTimeMS - StrobeSynchTime;		// можно в этом периоде
		}else
		{
		// -12...0
			DelayTimeMSForWait = Secunda-StrobeSynchTime + DelayTimeMS;		// только в следующей секунде
		}
	}
	vTaskDelay(DelayTimeMSForWait);
	taskENTER_CRITICAL();
	if (CorrectTimeMS != 0) Hal_setTimeInMs(Hal_getTimeInMs() + CorrectTimeMS + TimeZone_my*60*60*1000);					// готов диапазон, работает
    taskEXIT_CRITICAL();

    // калибровка ухода часов
    Hal_setCalibrTime(SNTP_Period,(int16_t)CorrectTimeMS%1000);

    // установим часы только если ушли в сторону.
    if (CorrectTimeMS != 0) {
		writeNmb = MB_Wr_Set_Time;
		SetTimeNow = true;
		AddToQueueMB(ModbusSentTime, 	MB_Wrt_Set_Time		,MB_Slaveaddr);		// установка времени	ModbusSentTime
		USART_TRACE_RED("время из NTP. уход:%i ms дробная:%u ms, ping:%u ms , пауза:%u ms\n",(int16_t)CorrectTimeMS,DelayTimeMS,(uint16_t)TravelTimeMs,DelayTimeMSForWait);
		taskYIELD();// отпустим задачу. для быстрой установки времени
    }else{
    	USART_TRACE_GREEN("время из NTP. уход:%i ms дробная:%u ms, ping:%u ms , пауза:%u ms\n",(int16_t)CorrectTimeMS,DelayTimeMS,(uint16_t)TravelTimeMs,DelayTimeMSForWait);
    }

#else

#if defined (Time1ms)
	if (CorrectTimeMS > 0) {
		if (DelayTimeMS < 989)//>10
		{
			vTaskDelay(989 - DelayTimeMS);//-11
			taskENTER_CRITICAL();
			Hal_setTimeInMs(Hal_getTimeInMs() + (CorrectTimeMS - DelayTimeMS) + 1000 + TimeZone_my*60*60*1000);					// готов диапазон, работает
		    taskEXIT_CRITICAL();
			USART_TRACE("0... 990 ms\n");
		} else
		{
			vTaskDelay(988 + (1000 - DelayTimeMS));	//990
			taskENTER_CRITICAL();
			Hal_setTimeInMs(Hal_getTimeInMs() + (CorrectTimeMS - DelayTimeMS) + 1000 + TimeZone_my*60*60*1000);
		    taskEXIT_CRITICAL();
			USART_TRACE("991... ms. d:%u\n",DelayTimeMS);
		}
		 writeNmb = 10;
	}
	else
		if (CorrectTimeMS < 0){
			//DelayTimeMS = 1000 - DelayTimeMS;						// перевернем в положительную радержку
			//CorrectTimeMS = CorrectTimeMS + 1000;


			if (DelayTimeMS > 10)
			{
				vTaskDelay(989 - (1000 - DelayTimeMS));
				//vTaskDelay(DelayTimeMS);
				taskENTER_CRITICAL();
				Hal_setTimeInMs(Hal_getTimeInMs() - (1-CorrectTimeMS - DelayTimeMS) + 000 + TimeZone_my*60*60*1000);					// готов диапазон, работает
			    taskEXIT_CRITICAL();
				USART_TRACE_GREEN("-990...0 ms\n");
			} else
			{
				//vTaskDelay(988 + (1000 - DelayTimeMS));
				//taskENTER_CRITICAL();
				//Hal_setTimeInMs(Hal_getTimeInMs() - (-CorrectTimeMS + DelayTimeMS) + 000 + TimeZone_my*60*60*1000);
			    //taskEXIT_CRITICAL();

				//vTaskDelay(DelayTimeMS);	//989
				//taskENTER_CRITICAL();
				//Hal_setTimeInMs(Hal_getTimeInMs() - (1-CorrectTimeMS - DelayTimeMS) + 000 + TimeZone_my*60*60*1000);
				//taskEXIT_CRITICAL();
				USART_TRACE_BLUE("...-990 ms\n")
			}

			 writeNmb = 10;
	}
	USART_TRACE("ms:%u. время из NTP. уход:%ims задержка:%ums\n",DelayTimeMS,(int16_t)CorrectTimeMS,(uint16_t)TravelTimeMs);

#else
	Hal_setTimeInMs(Hal_getTimeInMs() + CorrectTimeMS + TimeZone_my*60*60*1000);					// готов диапазон, работает
	writeNmb = 10;
#endif

#endif

}


/********************************************************************************************************
 * Hal_setTimeToMB_Date
 * установка часов в буфер MODBUS
 *********************************************************************************************************/
BOOL	Hal_setTimeToMB_Date( uint16_t * MDateBuf ){

	extern 	RTC_HandleTypeDef hrtc;

	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;

//	USART_TRACE("Hal_getTimeInMs %u.%u.%u\n",sTime.Hours,sTime.Minutes,sTime.Seconds);

	HAL_RTC_GetTime(&hrtc, &sTime, FORMAT_BIN);
//	USART_TRACE("Hal_getTimeInMs %u.%u.%u\n",sTime.Hours,sTime.Minutes,sTime.Seconds);

	MDateBuf[3] = sTime.Hours;//+Timezone;
//	if (sTime.TimeFormat == RTC_HOURFORMAT12_PM){
//		MDateBuf[3] += 12;
//	}
	MDateBuf[4] = sTime.Minutes;
	MDateBuf[5] = sTime.Seconds;
	MDateBuf[6] = (1000 - (sTime.SubSeconds * 1000 / hrtc.Init.SynchPrediv)); //sTime.SubSeconds;

	HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);
//	USART_TRACE("Hal_getTimeInMs %u.%u.%u\n",sTime.Hours,sTime.Minutes,sTime.Seconds);

	MDateBuf[0] = sDate.Year;
	MDateBuf[1] = sDate.Month;
	MDateBuf[2] = sDate.Date;

	return	TRUE;
}
