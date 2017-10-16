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
static uint32_t 			ulIPAddressFound;					// IP ����� NTP �������
static TickType_t 			uxSendTime;							// ����� �������� ���������
uint64_t	startSendTimeMs;
uint64_t	TravelTimeMs;


static char cRecvBuffer[ sizeof( struct SNtpPacket ) + 64 ];

static enum EStatus xStatus = EStatusLookup;

static int xUDPSocket = NULL;

static void prvReadTime( struct SNtpPacket * pxPacket );
void 		prvNTPPacketInit(void);

BOOL		Hal_setTimeToMB_Date( uint16_t * MDateBuf );

// ������� -----------------------------
extern xQueueHandle 	ModbusSentTime;		// ������� ��� �������� � ������
extern xQueueHandle 	ModbusSentQueue;		// ������� ��� �������� � ������


extern bool			SetTimeNow;
extern uint8_t		writeNmb;
extern uint16_t		SNTP_Period;
extern int8_t		TimeZone_my;
/*  ���� ------------------------------------------------------------*/
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

	int conn = GetSocket_num(self);		// ��������� ���� �� ����� �����

	if (sent)
	{

		prvNTPPacketInit();

        prepareServerAddress(address, port, &serverAddress);

        if (lostSNTPPackets < 30000)	lostSNTPPackets++;						// ������� ��������� �������
        startSendTimeMs = Hal_getTimeInMs();
//		uxSendTime = xTaskGetTickCount();		// ���������� ����� ��������
		ret = sendto( conn, ( void * )&xNTPPacket, sizeof(xNTPPacket), 0, (struct sockaddr *) &serverAddress, AddressSizeFrom );	// ����� � ���� ���������� �����������.
		if (ret<1) return 1;
//		USART_0TRACE("SNTP: ���������� UDP ��������� � %s:%u\n", address, port);
		return 0;
	}else
	{
		ret = recvfrom( conn, (void *)recv_buffer, buflen, 0,(struct sockaddr *)&serverAddress, &AddressSizeFrom );		// � serverAddress ����� ����� ����������� �����������


		if(ret == 0) {
		  USART_TRACE_RED("SNTP: ��������� ���������� �� ������� �������. ���������.\n");
 		  Socket_destroy(conn);
		  return 0;
		}else
		if(ret < 0) {
//		  USART_TRACE_ReED("SNTP: �� ������ ������ �� ���������. ���������. %i\n",ret);
//		  Socket_destroy(conn);
		  return 0;
		}
	  // --------------------------------------------------------------
//		USART_TRACE_GREEN("SNTP: ������� UDP ��������� �� %s:%u\n", serverAddress.sin_addr.s_addr, serverAddress.sin_port);

		if( ret < sizeof(xNTPPacket) )
		{
			USART_TRACE_RED("SNTP: ��������� ������ ��� xNTPPacket. %ld\n", ret);
		    return 0;
		}
		else
		{
			// ������� ��������� �� ������� �������. ����� ������� ��� �� ����� ����� ����� �� �������
			prvReadTime( ( struct SNtpPacket *)recv_buffer );		// �������������� �����

			lostSNTPPackets = 0;
			//if (lostSNTPPackets )	lostSNTPPackets--;						// ������� ��������� �������

		    // �������� ����� ��������� ������������� �������.
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
 * 83AA7E80 seconds 1������ 1970� 0:0:0
 * �������� ������ � �������� UTC ����� ������� ����
 *****************************************************************************************************/
void prvNTPPacketInit(void)
{
	memset (&xNTPPacket, '\0', sizeof(xNTPPacket));

	xNTPPacket.flags = 0xDB;							/* value 0xDB : mode 3 (client), version 3, leap indicator unknown 3 */ // ��������� ���������(2 ����), ����� ������(3 ����),�����(3 ����)
	xNTPPacket.stratum = 3;							//������� ����(8 ���) (2-15	��������� ������, ������������ NTP)
	xNTPPacket.poll = 10;								/* 10 means 1 << 10 = 1024 seconds */ 	// �������� ������(8 ���)  �������� ����� ��������� ��������� ������.
	xNTPPacket.precision = 250;						/* = 250 = 0.015625 seconds */		 	//��������
	xNTPPacket.rootDelay = 0x0D2E;						/* 0x5D2E = 23854 or (23854/65535)= 0.3640 sec */	//�������� (����� ����� ��������������� ������� � ��� ������� � �������� ������� NTP.)
	xNTPPacket.rootDispersion = 0x0008CAC8;				/* 0x0008CAC8 = 8.7912  seconds */	//(����� ��������� ��� ��������� ������� � �������� ������� NTP.)

	/* use the recorded NTP time */
	// �������� �� ����� ����� � ms �� ��������� 70-�� ����.
	uint64_t	 uxSecs = Hal_getTimeInMs();			//FreeRTOS_time( NULL );/* apTime may be NULL, returns seconds */
	//NTP ����� ������������� � �������� 1 ������ 1900 ����, � �� � 1970, ������� �� ������� NTP ����� �������� ����� 70 ��� (� ������ ���������� ���)
//	uxSecs += Timezone*60*60*1000;

	xNTPPacket.referenceTimestamp.seconds = base1970 + (uxSecs/1000);//3697447200 - 2400 - 43200 - 172800 - 1482192000 - 8640000 +2505600 + 86400;	/* Current time */
	xNTPPacket.referenceTimestamp.fraction = (uxSecs%1000)*base1ms;//(uxSecs%1000)*4294968; 1mc ��������

	xNTPPacket.transmitTimestamp.seconds = base1970 + (uxSecs/1000);
	xNTPPacket.transmitTimestamp.fraction = (uxSecs%1000)*base1ms;//(uxSecs%1000)*4294968; 1mc ��������			43645464

	/* Transform the contents of the fields from native to big endian. */
	prvSwapFields( &xNTPPacket );
}

/*****************************************************************************************************
 * static void prvReadTime( struct SNtpPacket * pxPacket )
 * ����� �������� ���� ������� ��������������� �������
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
//	uxTravelTime = xTaskGetTickCount() - uxSendTime;							// ����� �� ������ �������� �� �������� ������� � �����
	TravelTimeMs = Hal_getTimeInMs() - startSendTimeMs;							// ����� �� ������ �������� �� �������� ������� d ��
	prvSwapFields( pxPacket );													// Transform the contents of the fields from big to native endian.

	// ���������� �����
	/*
	 * originateTimestamp	- ������ �������� ������ �� ������.
	 * receiveTimestamp 	- ������ ������ �� ������.
	 * transmitTimestamp	- ����� ��������� �������� ��� �������.
	 */
	uxCurrentSeconds = pxPacket->receiveTimestamp.seconds - TIME1970;
	uxCurrentMS = pxPacket->receiveTimestamp.fraction / base1ms;
	uxCurrentSeconds += uxCurrentMS / 1000;
	uxCurrentMS = uxCurrentMS % 1000;

	CurrentTimeMS = (uint64_t)uxCurrentSeconds*1000 + (uint64_t)uxCurrentMS;				// ���������� ����� (����� ������ �� �������)

	uint64_t uxOriginateSeconds = pxPacket->originateTimestamp.seconds - TIME1970;
	uint64_t uxOriginateMS = pxPacket->originateTimestamp.fraction / base1ms;
	uxOriginateSeconds += uxOriginateMS / 1000;
	uxOriginateMS = uxOriginateMS % 1000;
	OriginateTimeMS = (uint64_t)uxOriginateSeconds*1000 + (uint64_t)uxOriginateMS;		// ����� �������� ����

	// ���������� ������� ����� = ������� ����� +(��� - ���� � ������ �������) ����� �������� �������� + TravelTimeMs/2(��������������, ������� ��� ����� �������� = ������� ������)
	CorrectTimeMS = (int64_t)CurrentTimeMS - (int64_t)OriginateTimeMS;
	// ������������ ����� ���� �� ������� ����� ������ ��� � ����. ��� ������ ��� ���� �������� �����
	// ��������� ����� ������� � ������������ �����

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
			DelayTimeMSForWait = DelayTimeMS - StrobeSynchTime;		// ����� � ���� �������
		}else
		{
		// -12...0
			DelayTimeMSForWait = Secunda-StrobeSynchTime + DelayTimeMS;		// ������ � ��������� �������
		}
	}
	vTaskDelay(DelayTimeMSForWait);
	taskENTER_CRITICAL();
	if (CorrectTimeMS != 0) Hal_setTimeInMs(Hal_getTimeInMs() + CorrectTimeMS + TimeZone_my*60*60*1000);					// ����� ��������, ��������
    taskEXIT_CRITICAL();

    // ���������� ����� �����
    Hal_setCalibrTime(SNTP_Period,(int16_t)CorrectTimeMS%1000);

    // ��������� ���� ������ ���� ���� � �������.
    if (CorrectTimeMS != 0) {
		writeNmb = MB_Wr_Set_Time;
		SetTimeNow = true;
		AddToQueueMB(ModbusSentTime, 	MB_Wrt_Set_Time		,MB_Slaveaddr);		// ��������� �������	ModbusSentTime
		USART_TRACE_RED("����� �� NTP. ����:%i ms �������:%u ms, ping:%u ms , �����:%u ms\n",(int16_t)CorrectTimeMS,DelayTimeMS,(uint16_t)TravelTimeMs,DelayTimeMSForWait);
		taskYIELD();// �������� ������. ��� ������� ��������� �������
    }else{
    	USART_TRACE_GREEN("����� �� NTP. ����:%i ms �������:%u ms, ping:%u ms , �����:%u ms\n",(int16_t)CorrectTimeMS,DelayTimeMS,(uint16_t)TravelTimeMs,DelayTimeMSForWait);
    }

#else

#if defined (Time1ms)
	if (CorrectTimeMS > 0) {
		if (DelayTimeMS < 989)//>10
		{
			vTaskDelay(989 - DelayTimeMS);//-11
			taskENTER_CRITICAL();
			Hal_setTimeInMs(Hal_getTimeInMs() + (CorrectTimeMS - DelayTimeMS) + 1000 + TimeZone_my*60*60*1000);					// ����� ��������, ��������
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
			//DelayTimeMS = 1000 - DelayTimeMS;						// ���������� � ������������� ��������
			//CorrectTimeMS = CorrectTimeMS + 1000;


			if (DelayTimeMS > 10)
			{
				vTaskDelay(989 - (1000 - DelayTimeMS));
				//vTaskDelay(DelayTimeMS);
				taskENTER_CRITICAL();
				Hal_setTimeInMs(Hal_getTimeInMs() - (1-CorrectTimeMS - DelayTimeMS) + 000 + TimeZone_my*60*60*1000);					// ����� ��������, ��������
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
	USART_TRACE("ms:%u. ����� �� NTP. ����:%ims ��������:%ums\n",DelayTimeMS,(int16_t)CorrectTimeMS,(uint16_t)TravelTimeMs);

#else
	Hal_setTimeInMs(Hal_getTimeInMs() + CorrectTimeMS + TimeZone_my*60*60*1000);					// ����� ��������, ��������
	writeNmb = 10;
#endif

#endif

}


/********************************************************************************************************
 * Hal_setTimeToMB_Date
 * ��������� ����� � ����� MODBUS
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
