/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  *
  * COPYRIGHT(c) 2015 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "port.h"
#include "cmsis_os.h"
#include "queue.h"

#include "main.h"
#include "time.h"
#include "stdlib.h"
//#include "stdbool.h"
#include "string.h"

#include "ethernetif.h"
#include "lwip/tcpip.h"
#include "lwip/init.h"
#include "lwip/netif.h"
#include "lwip/api.h"
#include "lwip/sys.h"

// IEC 60870-5-104
#include "iec104.h"
#include "usart.h"

// IEC 61850
#include "iec850.h"
#include "iec61850_server.h"
//#include "static_model.h"

#if defined (MR5_700)
#include "static_model_MR5_700.h"
#endif
#if defined (MR5_600)
#include "static_model_MR5_600.h"
#endif
#if defined (MR5_500)
#include "static_model_MR5_500.h"
#endif
#if defined (MR771)
#include "static_model_MR771.h"
#endif
#if defined (MR761) || defined (MR762) || defined (MR763)
#include "static_model_MR76x.h"
#endif
#if defined (MR801)
#include "static_model_MR801.h"
#endif
#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"
#endif

#include "datatoPTOC.h"					// модификация данных в PTOC
#include "datatoPTOV.h"					// модификация данных в PTOV PTUV
#include "datatoPTOF.h"					// модификация данных в PTOF PTUF
#include "datatoGGIO.h"					// модификация данных в
#include "datatoPDIF.h"					// модификация данных в
#include "datatoRREC.h"					// модификация данных в
#include "datatoCSWI.h"					// модификация данных в
#include "datatoPTRC.h"					// модификация данных в
#include "datatoMMXU.h"
#include "datatoMSQI.h"
#include "datatoLLN0LPHD.h"
#include "datatoSG.h"					// изменения группы уставок
/*Modbus includes ------------------------------------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbport.h"
#include "modbus.h"

/*память SPI -----------------------------------------------------------------*/
#include "ExtSPImem.h"

/*консольный дебагер на USART ------------------------------------------------*/
#include "DebugConsole.h"

/* HTTP сервер для обновления прошивки ---------------------------------------*/
#include "httpServer.h"

/* NTP клиент  ---------------------------------------*/
#include "sntpclient.h"


/* define --------------------------------------------------------------------*/
#define DEBUG_CONSOLE_STACK_SIZE		( configMINIMAL_STACK_SIZE * 4 )		// configMINIMAL_STACK_SIZE * 4 * N = 3072байта			// * 4 потому как 32 бита ядро  было 5 11.07.2016
#define DEBUG_CONSOLE_TASK_PRIORITY		osPriorityAboveNormal//osPriorityNormal

#define IEC850_STACK_SIZE				( configMINIMAL_STACK_SIZE * 10 )		// 3072байта			configMINIMAL_STACK_SIZE * 7		8- 05122016 12-30012017 виснет
#define IEC850Task__PRIORITY			osPriorityHigh//osPriorityNormal//osPriorityAboveNormal

#define	MODBUSTask_STACK_SIZE			( configMINIMAL_STACK_SIZE * 4 )		// 1024байта			onfigMINIMAL_STACK_SIZE * 2
#define MODBUSTask__PRIORITY			osPriorityAboveNormal//osPriorityBelowNormal//osPriorityNormal

#define	HTTPTask_STACK_SIZE				( configMINIMAL_STACK_SIZE * 4 )		// 1024байта			onfigMINIMAL_STACK_SIZE * 2
#define HTTPTask__PRIORITY				osPriorityNormal

#define DEBUG_USARTOUT_STACK_SIZE		( configMINIMAL_STACK_SIZE * 4 )
#define DEBUG_USARTOUT_TASK_PRIORITY	osPriorityRealtime


/* Variables -----------------------------------------------------------------*/
extern uint16_t	GLOBAL_QUALITY;
// мьютексы -----------------------------
static xSemaphoreHandle xConsoleMutex = NULL;			// мьютекс печати в консоль

osMutexId xIEC850StartMutex;		// мьютекс готовности к запуску TCP/IP
osMutexDef(xIEC850StartMutex);

osMutexId xIEC850ServerStartMutex;		// мьютекс готовности к запуску TCP/IP
osMutexDef(xIEC850ServerStartMutex);

xQueueHandle		xDebugUsartOut;			// очередь бля отправки в юсартдебаг

extern IedServer 	iedServer;
extern uint16_t		SNTP_Period;

extern uint64_t 	nextSynchTime;
extern bool 		resynch;

// переделать структуру под формат данных запроса MODBUS
	typedef struct					// для передачи через очереди структур.
	{
	  MBFrame	MBData;
	  uint8_t 	Source;
	} xData;

osThreadId defaultTaskHandle;
osThreadId IEC850TaskHandle;
osThreadId MBUSTaskHandle;
osThreadId CONSOLETaskHandle;
osThreadId DEBUGUSARTOUTTaskHandle;


extern 	RTC_HandleTypeDef hrtc;

//  --------------------------------------------------------------------------------
int8_t				Nextread = 0;
uint8_t				ReadNmb=0;
uint16_t			NumbBlokReadMB = 0;	// куски
uint8_t				writeNmb;
uint8_t	  			writeNmbSG;			// номер группы уставок.

//Master mode: База данных
//Master mode: База данных конфигурации системы

#if defined (MR5_700)

extern uint16_t   usMDateStart;
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   usMRevStart;
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   usMDiscInStart;
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   usMConfigStart;
extern uint16_t   ucMConfigBuf[MB_NumbConfig];
extern uint16_t   usMConfigStartall;
extern uint16_t   ucMConfigBufall[MB_NumbConfigall];
extern uint16_t   usMConfigStartSWCrash;
extern uint16_t   ucMSWCrash[MB_NumbSWCrash];

extern uint16_t	    Ktt,Ktn;
#endif
#if defined (MR5_600)

extern uint16_t   usMDateStart;
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   usMRevStart;
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   usMDiscInStart;
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   usMConfigStart;
extern uint16_t   ucMConfigBuf[MB_NumbConfig];
extern uint16_t   usMConfigStartall;
extern uint16_t   ucMConfigBufall[MB_NumbConfigall];
extern uint16_t   usMConfigStartSWCrash;
extern uint16_t   ucMSWCrash[MB_NumbSWCrash];

extern uint16_t	    Ktn;
#endif
#if defined (MR5_500)

extern uint16_t   usMDateStart;
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   usMRevStart;
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   usMDiscInStart;
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   usMConfigStart;
extern uint16_t   ucMConfigBuf[MB_NumbConfig];
extern uint16_t   usMConfigStartall;
extern uint16_t   ucMConfigBufall[MB_NumbConfigall];
extern uint16_t   usMConfigStartSWCrash;
extern uint16_t   ucMSWCrash[MB_NumbSWCrash];

extern uint16_t	    Ktt,Ktn;
#endif

#if defined (MR771)

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usMConfigStartSW;
extern uint16_t   usConfigUstavkiStart;			// группа уставок
extern uint16_t   usConfigAutomatStart;			// параметры автоматики
extern uint16_t   usConfigVLSInStart;			// чтение конфигурации входных логических сигналов
extern uint16_t   usConfigVLSOutStart;			// чтение конфигурации выходных логических сигналов
extern uint16_t   usConfigAPWStart;				// конфигурация АПВ
extern uint16_t   usSystemCfgStart;				// параметры системы
extern uint16_t   usConfigTRMeasStart;			// конфигурация измерительного транса
extern uint16_t   usSGStart;					// параметры группы уставок


extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern	uint16_t   ucSGBuf[MB_NumbSG];

#endif
/*************************************************************************
 * MR761 MR762 MR763
 *************************************************************************/
#if defined (MR761) || defined (MR762) || defined (MR763)

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usMConfigStartSW;
extern uint16_t   usConfigUstavkiStart;			// группа уставок
extern uint16_t   usConfigAutomatStart;			// параметры автоматики
extern uint16_t   usConfigVLSInStart;			// чтение конфигурации входных логических сигналов
extern uint16_t   usConfigVLSOutStart;			// чтение конфигурации выходных логических сигналов
extern uint16_t   usConfigAPWStart;				// конфигурация АПВ
extern uint16_t   usSystemCfgStart;				// параметры системы
extern uint16_t   usConfigTRMeasStart;			// конфигурация измерительного транса
extern uint16_t   usSGStart;					// параметры группы уставок


extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern	uint16_t   ucSGBuf[MB_NumbSG];

#endif
#if defined (MR801)

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usMConfigStartSW;
extern uint16_t   usConfigUstavkiStart;			// группа уставок
extern uint16_t   usConfigAutomatStart;			// параметры автоматики
extern uint16_t   usConfigVLSInStart;			// чтение конфигурации входных логических сигналов
extern uint16_t   usConfigVLSOutStart;			// чтение конфигурации выходных логических сигналов
extern uint16_t   usConfigAPWStart;				// конфигурация АПВ
extern uint16_t   usConfigAWRStart;				// конфигурация АВР
extern uint16_t   usSystemCfgStart;				// параметры системы
extern uint16_t   usConfigTRMeasStart;			// конфигурация измерительного транса
extern uint16_t   usConfigTRPWRStart;			// конфигурация силового транса


extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
#endif

#if defined (MR901) || defined (MR902)

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usMConfigStartSW;
extern uint16_t   usConfigUstavkiStart;			// группа уставок
extern uint16_t   usConfigAutomatStart;			// параметры автоматики
extern uint16_t   usConfigVLSInStart;			// чтение конфигурации входных логических сигналов
extern uint16_t   usConfigVLSOutStart;			// чтение конфигурации выходных логических сигналов
extern uint16_t   usConfigAPWStart;				// конфигурация АПВ
extern uint16_t   usConfigAWRStart;				// конфигурация АВР
extern uint16_t   usSystemCfgStart;				// параметры системы
extern uint16_t   usConfigTRMeasStart;			// конфигурация измерительного транса
extern uint16_t   usConfigTRPWRStart;			// конфигурация силового транса


extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
#endif
//  --------------------------------------------------------------------------------

struct netconn *conn, *newconn;
struct netconn *conn850,*newconn850;

struct netif 	first_gnetif,second_gnetif,gnetif;
struct ip_addr 	first_ipaddr,second_ipaddr;
struct ip_addr 	netmask;
struct ip_addr 	gw;

/* Semaphore to signal Ethernet Link state update */
osSemaphoreId Netif_LinkSemaphore = NULL;
/* Ethernet link thread Argument */
struct link_str link_arg;

struct iechooks default_hooks;
struct iecsock 	*s;

uint8_t *outbuf;
size_t  outbufLen;

/* Function prototypes -------------------------------------------------------*/

//int16_t		GetDirGeneral(uint8_t	Currdata);
//float		GetRealU(uint16_t	Currdata, uint16_t	ktn);
float		GetRealP(float	Currdata, uint16_t	ktn,  uint16_t	Ittf);

void StartTimersTask(void const * argument);
void StartMODBUSTask(void const * argument);

extern volatile uint8_t	MAC_ADDR[6];


void FREERTOS_Init(void);

extern void vRegisterDEBUGCommands( void );

/* Hook prototypes */

void ReStartIEC850_task(void) {

	USART_TRACE_BLUE("Рестарт. \n");
	NVIC_SystemReset();

}
/*************************************************************************
 * FREERTOS_Init
 *************************************************************************/
void FREERTOS_Init(void) {
 size_t	fre,fre_pr;
 /* BEGIN RTOS_MUTEX */
	// Создадим мьютекс для блокировки доступа к консоли
	xConsoleMutex = osMutexCreate(NULL);

	// Создадим мьютекс для блокировки доступа к TCP/IP таску
	xIEC850StartMutex = osMutexCreate(NULL);
	// Создадим мьютекс для блокировки доступа к данным сервера
	xIEC850ServerStartMutex = osMutexCreate(NULL);

	osMutexWait(xIEC850StartMutex,0);						// забрали семафор
	osMutexWait(xIEC850ServerStartMutex,0);				// забрали семафор

  /* END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
//	vSemaphoreCreateBinary( xBinarySemaphore );			//создается двоичный семафор
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */



	fre = xPortGetFreeHeapSize();			// размер кучи
	fre_pr = fre;
	USART_TRACE("размер кучи:%u байт\n",fre);

	osThreadDef(MBUS, StartMODBUSTask, MODBUSTask__PRIORITY ,0, MODBUSTask_STACK_SIZE);//256
	MBUSTaskHandle = osThreadCreate(osThread(MBUS), NULL);

	osThreadDef(IEC850, StartIEC850Task,IEC850Task__PRIORITY,0, IEC850_STACK_SIZE);//1024		//1500 работало IEC850Task__PRIORITY
	IEC850TaskHandle = osThreadCreate(osThread(IEC850), NULL);

	// Создаём задачу, которая реализует консоль с помощью USART порта.
//	osThreadDef(CONSOLE, DEBUGConsoleTask, DEBUG_CONSOLE_TASK_PRIORITY ,0, DEBUG_CONSOLE_STACK_SIZE);
//	CONSOLETaskHandle = osThreadCreate(osThread(CONSOLE), NULL);
	// регистрируем команды консоли
//	vRegisterDEBUGCommands();


//	osThreadDef(DEBUG_OUT, DEBUGUSARTOUTTask, DEBUG_USARTOUT_TASK_PRIORITY ,0, DEBUG_USARTOUT_STACK_SIZE);
//	DEBUGUSARTOUTTaskHandle = osThreadCreate(osThread(DEBUG_OUT), NULL);

//	osThreadDef(HTTP, StartHTTPTask, HTTPTask__PRIORITY ,0, HTTPTask_STACK_SIZE);
//	MBUSTaskHandle = osThreadCreate(osThread(HTTP), NULL);

 //  fre = xPortGetFreeHeapSize();
 //  USART_TRACE("стек IEC850:%u байт\n",fre_pr - fre);
 //  fre_pr = fre;

/*
  osThreadDef(IEC104, StartIEC104Task, osPriorityAboveNormal,0, 640);//1024
  defaultTaskHandle = osThreadCreate(osThread(IEC104), NULL);
  fre = xPortGetFreeHeapSize();
  USART_TRACE("FreeHeap(IEC104):%u\n",fre);

  // создадим таск только после IEC104. Таймера нужны только там
  if (defaultTaskHandle)
  {
	  osThreadDef(Timers, StartTimersTask, osPriorityNormal,0, 128);//128
	  defaultTaskHandle = osThreadCreate(osThread(Timers), NULL);

	  fre = xPortGetFreeHeapSize();
	  USART_TRACE("FreeHeap(Timers):%u\n",fre);
  }
*/

//  fre = xPortGetFreeHeapSize();
//  USART_TRACE("стек MBUS:%u байт\n",fre_pr - fre);
//  fre_pr = fre;

 //   fre = xPortGetFreeHeapSize();			// размер кучи
//   USART_TRACE("стек CONSOLE:%u байт\n",fre_pr - fre);
//   fre_pr = fre;

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
//   xQueueMODBUS = xQueueCreate( 3, sizeof(xData) );

  /* definition and creation of xQueueMODBUS */
//  osMessageQDef(xQueueMODBUS, 3, sizeof(xData));
//  xQueueMODBUSHandle = osMessageCreate(osMessageQ(xQueueMODBUS), NULL);

   fre = xPortGetFreeHeapSize();
   USART_TRACE("осталось %u байт\n",fre);

  /* USER CODE END RTOS_QUEUES */
}

/*************************************************************************
 * MR801
 *************************************************************************/
#if defined (MR801)
void StartMODBUSTask(void const * argument)
{
	uint16_t			NumbBlokReadMBLim=0;
	uint16_t			SizeBlokReadMB = MaxSizeBlok;			// размер одного пакета
	uint16_t			addrConfig;

	uint8_t				LimitRead=0xFE;
	uint32_t			TimerReadMB;
	eMBErrorCode		errorType;
	uint64_t 			currentTime;
	RTC_TimeTypeDef 	Time;


	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();

	writeNmb = 0;
	ReadNmb = 0;

	Port_On(LED1);

	TimerReadMB = HAL_GetTick();

	for(;;)
	{
   	   	if (writeNmb == 10) {
   	   		USART_TRACE_GREEN("1.Установка часов в приборе.\n");
   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
   	   	}
   	   	else
		if (((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS)||(Nextread)){		// периодический опрос MODBUS с периодом MB_PerForReadMODBUS(мс)
			Nextread = false;
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>2 && ReadNmb<10)ReadNmb = 1;

			//--------------- синхронизация часов ------------------------------------
			if ((ReadNmb == 1) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = 10;			// первый раз

			//--------------- Выключатель ------------------------------------
	   	   	if (writeNmb == 1) {
	   	   		USART_TRACE_GREEN("Выключатель ON\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwON,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 2) {
	   	   		USART_TRACE_RED("Выключатель OFF\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwOFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}

	   	   	if (writeNmb == 3) {
	   	   		USART_TRACE_RED("сброс индикации\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 4) {
	   	   		USART_TRACE_RED("сброс новой неисправности\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале системы \n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 6) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале аварий\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 7) {
	   	   		USART_TRACE_RED("Переключение группы уставок 0.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SGroupe0,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 8) {
	   	   		USART_TRACE_RED("Переключение группы уставок 1.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SGroupe1,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 9) {
	   	   		USART_TRACE_RED("Сброс записи журнала системы.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 10) {
	   	   		USART_TRACE_GREEN("2.Установка часов в приборе.\n");
	   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
	   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
	   	   	}
	   		currentTime = Hal_getTimeInMs();

			//--------------- База чтения -----------------------------------------
	   	   	if (writeNmb == 0){	// запись без очереди выполним.

			//--------------- синхронизация часов только если не работает NTP -----
	   	     if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) {					//если прошел час то делаем синхронизацию снова
					ReadNmb = LimitRead;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("Пересинхронизация часов. время:0x%X\n",(unsigned int)currentTime);
				}
	   	     }
			// уставки нужно читать только той группы по которой работаем, Выделить одну область памяти
			if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG0) && ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG1) == 0))
					usConfigUstavkiStart = MB_StartUstavkiaddr0;
			 else	usConfigUstavkiStart = MB_StartUstavkiaddr1;



			// периодическое чтение
	   	   	if (ReadNmb==0)  		eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);					// чтение ревизии устройства
	   	   	else if (ReadNmb==1)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// чтение дискретной базы
	   	   	else if (ReadNmb==2) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);				// чтение аналоговой базы

	   		// однократное чтение
	   	   	else if (ReadNmb==10)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// чтение дискретной базы
	   	   	else if (ReadNmb==11) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);						// чтение текущего времени
	   	   	else if (ReadNmb==12) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSystemCfgStart,MB_NumbSystemCfg,RT_WAITING_FOREVER);					// чтение конфигурации системы
	   	  	else if (ReadNmb==13) 	ReadNmb = 19;	// прыгнем к 20

	   	  	else if (ReadNmb==20) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigStartSW,MB_NumbConfigSW,RT_WAITING_FOREVER);}				// чтение конфигурации выключателя
	   	  	else if (ReadNmb==21) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAPWStart,MB_NumbConfigAPW,RT_WAITING_FOREVER);}			// чтение конфигурации АПВ
	   	  	else if (ReadNmb==22) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAWRStart,MB_NumbConfigAWR,RT_WAITING_FOREVER);}			// чтение конфигурации АВР+ЛЗШ
	   	  	else if (ReadNmb==23) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRPWRStart,MB_NumbConfigTRPWR,RT_WAITING_FOREVER);}		// чтение всех уставок силового транса
	   	  	else if (ReadNmb==24) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRMeasStart,MB_NumbConfigTRMeas,RT_WAITING_FOREVER);}		// чтение всех уставок измерительного транса
	   	  	else if (ReadNmb==25) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfigVLSIn,MB_NumbConfigVLSIn,RT_WAITING_FOREVER);}		// чтение конфигурации входных логических сигналов
	   	  	else if (ReadNmb==26) {																													// чтение конфигурации выходных логических сигналов

	  					NumbBlokReadMBLim = (uint16_t)MB_NumbConfigVLSOut;
	  					NumbBlokReadMBLim = NumbBlokReadMBLim/(uint16_t)MaxSizeBlok;

	   	  				addrConfig = MB_StartConfigVLSOut + NumbBlokReadMB * MaxSizeBlok;

	   	  				if (NumbBlokReadMB == NumbBlokReadMBLim){
	   	  					SizeBlokReadMB = (uint16_t)MB_NumbConfigVLSOut;
	   	  					SizeBlokReadMB = SizeBlokReadMB % (uint16_t)MaxSizeBlok;
	   	  				}


	   	  				if (NumbBlokReadMB > NumbBlokReadMBLim){
	   	  					addrConfig = 0;
							NumbBlokReadMB = 0;
							NumbBlokReadMBLim = 0;
							SizeBlokReadMB = MaxSizeBlok;
							ReadNmb++;
	   	  				} else
	   	  				if((SizeBlokReadMB) && addrConfig<(MB_StartConfigVLSOut+MB_NumbConfigVLSOut)){
	   					   USART_TRACE_BLUE("%u-%u:Запрос:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
	   					   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
	   	  				}

	   	  			}
	   	  	else if (ReadNmb==27) {																													// чтение основной или резервной группы уставок

	   	  				if (NumbBlokReadMBLim == 0) NumbBlokReadMB = 0;

	  					NumbBlokReadMBLim = (uint16_t)MB_NumbUstavki;
	  					NumbBlokReadMBLim = NumbBlokReadMBLim/(uint16_t)MaxSizeBlok;

	   	  				addrConfig = usConfigUstavkiStart + NumbBlokReadMB * MaxSizeBlok;

	   	  				if (NumbBlokReadMB == NumbBlokReadMBLim){
	   	  					SizeBlokReadMB = (uint16_t)MB_NumbUstavki;
	   	  					SizeBlokReadMB = SizeBlokReadMB % (uint16_t)MaxSizeBlok;
	   	  				}else{
	   	  				}

	   	  			   if((SizeBlokReadMB) && addrConfig<(usConfigUstavkiStart+MB_NumbUstavki)) {
	   	  				   	   USART_TRACE_BLUE("%u-%u:Запрос:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
	   	  					   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
	   	  			   	  }
	   	  				else {
	   	  					NumbBlokReadMB = 0;
	   	  					SizeBlokReadMB = MaxSizeBlok;
	   	  					ReadNmb++;
	   	  				}

	   	  				if((SizeBlokReadMB != MaxSizeBlok) && (NumbBlokReadMB > NumbBlokReadMBLim))	{																																			// закончили
	   	  					NumbBlokReadMB = 0;
	   	  					SizeBlokReadMB = MaxSizeBlok;
	   	  					ReadNmb++;
	   	  				}
	   	  			}
//	   	  	else if (ReadNmb==26) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfigVLSOut,MB_NumbConfigVLSOut,RT_WAITING_FOREVER);}		// чтение конфигурации выходных логических сигналов
//	   	  	else if (ReadNmb==27) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigUstavkiStart,MB_NumbUstavki,RT_WAITING_FOREVER);}			// чтение основной или резервной группы уставок
	   	  	else if (ReadNmb==28) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAutomatStart,MB_NumbAutomat,RT_WAITING_FOREVER);}			// чтение параметров автоматики
	   	  	else {ReadNmb++;}

//	   	 ReadNmb = 29;
	   	   	LimitRead = 29;
	   	   	if (ReadNmb >= LimitRead) { ReadNmb = 1; osMutexRelease(xIEC850StartMutex);}

	   	   	} else{
	   	   		if (writeNmb == 9 ) ReadNmb = 10;			// если была запись в журнале ситемы то были изменения уставок. Нужно все перечитать.
	   	   		writeNmb = 0;
	   	   	}
/*******************************************************
 * наполняем оперативными данными структуру
 *******************************************************/
			if(IEC850TaskHandle && (iedServer != NULL)){
				IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

// LLN0 Health --------
					Set_LLN0(1,currentTime);
// PROT_IPTOC1..8 ------						защита по повышению тока
					Set_IPTOC(8,currentTime);
// PROT_I20PTOC1..6 ------						защита от замыкания на землю и повешения тока обратной последовательности
					Set_I20PTOC(6,currentTime);
// PROT_UPTOV1..4 ------						защита по повышению напряжения
					Set_UPTOV(4,currentTime);
// PROT_UPTUV1..4 ------						защита по понижению напряжения
					Set_UPTUV(4,currentTime);
// PROT_UPTOF1..4 ------						защита по повышению частоты
					Set_PTOF(4,currentTime);
// PROT_UPTUF1..4 ------						защита по понижению частоты
					Set_PTUF(4,currentTime);
// PROT_VZGGIO1..16 ------						внешняя защита
					Set_VZGGIO(16,currentTime);
// PROT_IDPDIF ------							дифф защита
					Set_IDPDIF(1,currentTime);
// PROT_IDDPDIF ------							дифф защита
					Set_IDDPDIF(1,currentTime);
// PROT_IDDMPDIF ------							дифф защита
					Set_IDDMPDIF(1,currentTime);
// PROT_ID0PDIF ------							дифф защита
					Set_ID0PDIF(3,currentTime);
// PROT_RREC ------
					Set_RREC(1,currentTime);
// PROT_AVRGGIO ------
					Set_AVRGGIO(1,currentTime);
// PROT_LZSHPTOC ------									ЛЗШ
					Set_LZSHPTOC(1,currentTime);
// PROT_RREC ------
					Set_RBRF(1,currentTime);
// CTRL_LLN0 ------

// CTRL_CSWI ------
					Set_CSWI(1,currentTime);
// CTRL_PTRC ------
					Set_PTRC(1,currentTime);
// CTRL_XCBR ------
					Set_XCBR(1,currentTime);
// CTRL_GGIO ------
					Set_XCBRGGIO(1,currentTime);
// MES_MMXU ------
					Set_MMXU(1,currentTime);
// MES_MSQI ------
					Set_MSQI(1,currentTime);

// GGIO_IN24GGIO ------
					Set_INGGIO(24,currentTime);
					Set_OUTGGIO(18,currentTime);
					Set_LEDGGIO(12,currentTime);
					Set_SSLGGIO(32,currentTime);
					Set_VLSGGIO(16,currentTime);
					Set_LSGGIO(16,currentTime);
// LD0 SG
					Set_SG(0,currentTime);

				IedServer_unlockDataModel(iedServer);
			}
/*******************************************************
 *
 *******************************************************/
		}
		errorType = eMBMasterPoll();						// мониторим события от MODBUS.
		if (errorType == MB_ETIMEDOUT){
    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
//    		ReadNmb++;
			GLOBAL_QUALITY =  QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
    		Port_Off(LED1);
		}else
		if (errorType == MB_ENOERR || errorType == MB_ESENT){
			if (writeNmb == 10) {writeNmb = 0;}
//	   		USART_TRACE_RED("MB_ENOERR: %u\n",ReadNmb);
		}else
		if (errorType == MB_ERECVDATA){
			GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
//			vTaskDelay(5);									// делаем паузу, не успевает принять запрос.
			Nextread = true;
		}


		taskYIELD();										// отпустим задачу.
	}
}
#endif
/*******************************************************
 * MR761 MR762 MR763
 *******************************************************/
#if defined	(MR761) || defined	(MR762) || defined	(MR763)
void StartMODBUSTask(void const * argument)
{
	uint16_t			NumbBlokReadMBLim=0;
	uint16_t			SizeBlokReadMB = MaxSizeBlok;			// размер одного пакета
	uint16_t			addrConfig;

	uint8_t				LimitRead=0xFE;
	uint32_t			TimerReadMB;
	eMBErrorCode		errorType;
	uint64_t 			currentTime;
	RTC_TimeTypeDef 	Time;


	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();

	writeNmb = 0;
	ReadNmb = 0;

	Port_On(LED1);

	TimerReadMB = HAL_GetTick();

	for(;;)
	{
   	   	if (writeNmb == 10) {
   	   		USART_TRACE_GREEN("1.Установка часов в приборе.\n");
   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
   	   	}
   	   	else
		if (((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS)||(Nextread)){		// периодический опрос MODBUS с периодом MB_PerForReadMODBUS(мс)
			Nextread = false;
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>2 && ReadNmb<10)ReadNmb = 1;

			//--------------- синхронизация часов ------------------------------------
			if ((ReadNmb == 1) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = 10;			// первый раз

			//--------------- Выключатель ------------------------------------
	   	   	if (writeNmb == 1) {
	   	   		USART_TRACE_GREEN("Выключатель ON\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwON,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 2) {
	   	   		USART_TRACE_RED("Выключатель OFF\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwOFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}

	   	   	if (writeNmb == 3) {
	   	   		USART_TRACE_RED("сброс индикации\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 4) {
	   	   		USART_TRACE_RED("сброс новой неисправности\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале системы \n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 6) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале аварий\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 7) {
	   	   		USART_TRACE_RED("Переключение группы уставок %u\n",writeNmbSG);
	   	   		eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_Startaddr_SG,writeNmbSG - 1,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 9) {
	   	   		USART_TRACE_RED("Сброс записи журнала системы.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 10) {
	   	   		USART_TRACE_GREEN("2.Установка часов в приборе.\n");
	   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
	   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
	   	   	}
	   		currentTime = Hal_getTimeInMs();

			//--------------- База чтения -----------------------------------------
	   	   	if (writeNmb == 0){	// запись без очереди выполним.

			//--------------- синхронизация часов только если не работает NTP -----
	   	     if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) {					//если прошел час то делаем синхронизацию снова
					ReadNmb = LimitRead;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("Пересинхронизация часов. время:0x%X\n",(unsigned int)currentTime);
				}
	   	     }
			// уставки нужно читать только той группы по которой работаем, Выделить одну область памяти

			usConfigUstavkiStart = ucSGBuf[0];

//TODO: удалить
			ReadNmb = 29;

			// периодическое чтение
	   	   	if (ReadNmb==0)  		eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);					// чтение ревизии устройства
	   	   	else if (ReadNmb==1)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// чтение дискретной базы
	   	   	else if (ReadNmb==2) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);				// чтение аналоговой базы

	   		// однократное чтение
	   	   	else if (ReadNmb==10) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);						// чтение текущего времени
	   	   	else if (ReadNmb==11) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSystemCfgStart,MB_NumbSystemCfg,RT_WAITING_FOREVER);				// чтение конфигурации системы
	   	   	else if (ReadNmb==12) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSGStart,MB_NumbSG,RT_WAITING_FOREVER);							// чтение группы уставок

	   	   	else if (ReadNmb==13) 	ReadNmb = 20;	// прыгнем к 20

	   	  	else if (ReadNmb==20) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigStartSW,MB_NumbConfigSW,RT_WAITING_FOREVER);}				// чтение конфигурации выключателя
	   	  	else if (ReadNmb==21) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAPWStart,MB_NumbConfigAPW,RT_WAITING_FOREVER);}			// чтение конфигурации АПВ
//	   	  	else if (ReadNmb==22) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAWRStart,MB_NumbConfigAWR,RT_WAITING_FOREVER);}			// чтение конфигурации АВР+ЛЗШ
//	   	  	else if (ReadNmb==23) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRPWRStart,MB_NumbConfigTRPWR,RT_WAITING_FOREVER);}		// чтение всех уставок силового транса
	   	  	else if (ReadNmb==24) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRMeasStart,MB_NumbConfigTRMeas,RT_WAITING_FOREVER);}		// чтение всех уставок измерительного транса
	   	  	else if (ReadNmb==25) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfigVLSIn,MB_NumbConfigVLSIn,RT_WAITING_FOREVER);}		// чтение конфигурации входных логических сигналов
	   	  	else if (ReadNmb==26) {																													// чтение конфигурации выходных логических сигналов

	   	  				if (NumbBlokReadMBLim == 0) NumbBlokReadMB = 0;

						NumbBlokReadMBLim = (uint16_t)MB_NumbConfigVLSOut;
						NumbBlokReadMBLim = NumbBlokReadMBLim/(uint16_t)MaxSizeBlok;

						addrConfig = MB_StartConfigVLSOut + NumbBlokReadMB * MaxSizeBlok;

						if (NumbBlokReadMB == NumbBlokReadMBLim){
							SizeBlokReadMB = (uint16_t)MB_NumbConfigVLSOut;
							SizeBlokReadMB = SizeBlokReadMB % (uint16_t)MaxSizeBlok;
						}


						if (NumbBlokReadMB > NumbBlokReadMBLim){
							addrConfig = 0;
							NumbBlokReadMB = 0;
							NumbBlokReadMBLim = 0;
							SizeBlokReadMB = MaxSizeBlok;
							ReadNmb++;
						} else
						if((SizeBlokReadMB) && addrConfig<(MB_StartConfigVLSOut+MB_NumbConfigVLSOut)){
						   USART_TRACE_BLUE("%u-%u:Запрос:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
						   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
						}

	   	  			}
	   	  	else if (ReadNmb==27) {																													// чтение основной или резервной группы уставок

						if (NumbBlokReadMBLim == 0) NumbBlokReadMB = 0;

						NumbBlokReadMBLim = (uint16_t)MB_NumbUstavki;
						NumbBlokReadMBLim = NumbBlokReadMBLim/(uint16_t)MaxSizeBlok;

						addrConfig = usConfigUstavkiStart + NumbBlokReadMB * MaxSizeBlok;

						if (NumbBlokReadMB == NumbBlokReadMBLim){
							SizeBlokReadMB = (uint16_t)MB_NumbUstavki;
							SizeBlokReadMB = SizeBlokReadMB % (uint16_t)MaxSizeBlok;
						}

						if (NumbBlokReadMB > NumbBlokReadMBLim){
							addrConfig = 0;
							NumbBlokReadMB = 0;
							NumbBlokReadMBLim = 0;
							SizeBlokReadMB = MaxSizeBlok;
							ReadNmb++;
						} else
					   if((SizeBlokReadMB) && addrConfig<(usConfigUstavkiStart+MB_NumbUstavki)) {
							   USART_TRACE_BLUE("%u-%u:Запрос:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
							   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
						  }
	   	  			}
//	   	  	else if (ReadNmb==26) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfigVLSOut,MB_NumbConfigVLSOut,RT_WAITING_FOREVER);}		// чтение конфигурации выходных логических сигналов
//	   	  	else if (ReadNmb==27) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigUstavkiStart,MB_NumbUstavki,RT_WAITING_FOREVER);}			// чтение основной или резервной группы уставок
	   	  	else if (ReadNmb==28) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAutomatStart,MB_NumbAutomat,RT_WAITING_FOREVER);}			// чтение параметров автоматики
	   	  	else {ReadNmb++;}

	   	   	LimitRead = 29;
	   	   	if (ReadNmb >= LimitRead) { ReadNmb = 1; osMutexRelease(xIEC850StartMutex);}

	   	   	} else{
	   	   		if (writeNmb == 9 ) ReadNmb = 10;			// если была запись в журнале ситемы то были изменения уставок. Нужно все перечитать.
	   	   		writeNmb = 0;
	   	   	}
/*******************************************************
 * наполняем оперативными данными структуру
 *******************************************************/
			if(IEC850TaskHandle && (iedServer != NULL)){
				IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

// PROT_LLN0 Health --------
				{
					uint32_t	LLN0_Health = STVALINT32_OK;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {LLN0_Health = STVALINT32_Warning;}
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LLN0_Health_stVal, LLN0_Health);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LLN0_Health_t, currentTime);
				}
// PROT_IPTOC1..8 ------						защита по повышению тока
//					Set_IPTOC(8,currentTime);
// Set_I2I1PTOC ------
//					Set_I2I1PTOC(1,currentTime);
// Set_IPTUC ------
//					Set_IPTUC(1,currentTime);
// PROT_I20PTOC1..6 ------						защита от замыкания на землю и повешения тока обратной последовательности
//					Set_I20PTOC(6,currentTime);
// PROT_UPTOV1..4 ------						защита по повышению напряжения
//					Set_UPTOV(4,currentTime);
// PROT_UPTUV1..4 ------						защита по понижению напряжения
//					Set_UPTUV(4,currentTime);
// PROT_UPTOF1..4 ------						защита по повышению частоты
//					Set_PTOF(4,currentTime);
// PROT_UPTUF1..4 ------						защита по понижению частоты
//					Set_PTUF(4,currentTime);
// PROT_VZGGIO1..16 ------						внешняя защита
//					Set_VZGGIO(16,currentTime);
// PROT_RREC ------
//					Set_RREC(1,currentTime);
// PROT_RREC ------
//					Set_RBRF(1,currentTime);

// CTRL_CSWI ------
//					Set_CSWI(1,currentTime);
// CTRL_PTRC ------
//					Set_PTRC(1,currentTime);
// CTRL_XCBR ------
//					Set_XCBR(1,currentTime);
// CTRL_GGIO ------
//					Set_XCBRGGIO(1,currentTime);
// MES_MMXU ------
//					Set_MMXU(1,currentTime);

// GGIO_IN24GGIO ------
//					Set_INGGIO(24,currentTime);
//					Set_OUTGGIO(18,currentTime);
//					Set_LEDGGIO(12,currentTime);
//					Set_SSLGGIO(32,currentTime);
//					Set_VLSGGIO(16,currentTime);
//					Set_LSGGIO(16,currentTime);
// LD0 SG
//					Set_SG(0,currentTime);

				IedServer_unlockDataModel(iedServer);
			}
/*******************************************************
 *
 *******************************************************/
		}
		errorType = eMBMasterPoll();						// мониторим события от MODBUS.
		if (errorType == MB_ETIMEDOUT){
    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
//    		ReadNmb++;
			GLOBAL_QUALITY =  QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
    		Port_Off(LED1);
		}else
		if (errorType == MB_ENOERR || errorType == MB_ESENT){
			if (writeNmb == 10) {writeNmb = 0;}
//	   		USART_TRACE_RED("MB_ENOERR: %u\n",ReadNmb);
		}else
		if (errorType == MB_ERECVDATA){
			GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
//			vTaskDelay(5);									// делаем паузу, не успевает принять запрос.
			Nextread = true;
		}


		taskYIELD();										// отпустим задачу.
	}
}
#endif
/*******************************************************
 * MR901 MR902
 *******************************************************/
#if defined	(MR901) || defined	(MR902)
void StartMODBUSTask(void const * argument)
{
	uint16_t			NumbBlokReadMBLim=0;
	uint16_t			SizeBlokReadMB = MaxSizeBlok;			// размер одного пакета
	uint16_t			addrConfig;

	uint8_t				LimitRead=0xFE;
	uint32_t			TimerReadMB;
	eMBErrorCode		errorType;
	uint64_t 			currentTime;
	RTC_TimeTypeDef 	Time;


	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();

	writeNmb = 0;
	ReadNmb = 0;

	Port_On(LED1);

	TimerReadMB = HAL_GetTick();

	for(;;)
	{
   	   	if (writeNmb == 10) {
   	   		USART_TRACE_GREEN("1.Установка часов в приборе.\n");
   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
   	   	}
   	   	else
		if (((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS)||(Nextread)){		// периодический опрос MODBUS с периодом MB_PerForReadMODBUS(мс)
			Nextread = false;
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>2 && ReadNmb<10)ReadNmb = 1;

			//--------------- синхронизация часов ------------------------------------
			if ((ReadNmb == 1) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = 10;			// первый раз

			//--------------- Выключатель ------------------------------------
	   	   	if (writeNmb == 1) {
	   	   		USART_TRACE_GREEN("Выключатель ON\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwON,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 2) {
	   	   		USART_TRACE_RED("Выключатель OFF\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwOFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}

	   	   	if (writeNmb == 3) {
	   	   		USART_TRACE_RED("сброс индикации\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 4) {
	   	   		USART_TRACE_RED("сброс новой неисправности\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале системы \n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 6) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале аварий\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 7) {
	   	   		USART_TRACE_RED("Переключение группы уставок 0.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SGroupe0,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 8) {
	   	   		USART_TRACE_RED("Переключение группы уставок 1.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SGroupe1,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 9) {
	   	   		USART_TRACE_RED("Сброс записи журнала системы.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 10) {
	   	   		USART_TRACE_GREEN("2.Установка часов в приборе.\n");
	   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
	   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
	   	   	}
	   		currentTime = Hal_getTimeInMs();

			//--------------- База чтения -----------------------------------------
	   	   	if (writeNmb == 0){	// запись без очереди выполним.

			//--------------- синхронизация часов только если не работает NTP -----
	   	     if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) {					//если прошел час то делаем синхронизацию снова
					ReadNmb = LimitRead;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("Пересинхронизация часов. время:0x%X\n",(unsigned int)currentTime);
				}
	   	     }
			// уставки нужно читать только той группы по которой работаем, Выделить одну область памяти
			if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG0) && ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG1) == 0))
					usConfigUstavkiStart = MB_StartUstavkiaddr0;
			 else	usConfigUstavkiStart = MB_StartUstavkiaddr1;



			// периодическое чтение
	   	   	if (ReadNmb==0)  		eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);					// чтение ревизии устройства
	   	   	else if (ReadNmb==1)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// чтение дискретной базы
	   	   	else if (ReadNmb==2) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);				// чтение аналоговой базы

	   		// однократное чтение
	   	   	else if (ReadNmb==10)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// чтение дискретной базы
	   	   	else if (ReadNmb==11) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);						// чтение текущего времени
	   	   	else if (ReadNmb==12) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSystemCfgStart,MB_NumbSystemCfg,RT_WAITING_FOREVER);				// чтение конфигурации системы
	   	  	else if (ReadNmb==13) 	ReadNmb = 19;	// прыгнем к 20

	   	  	else if (ReadNmb==20) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigStartSW,MB_NumbConfigSW,RT_WAITING_FOREVER);}				// чтение конфигурации выключателя
	   	  	else if (ReadNmb==21) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAPWStart,MB_NumbConfigAPW,RT_WAITING_FOREVER);}			// чтение конфигурации АПВ
	   	  	else if (ReadNmb==22) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAWRStart,MB_NumbConfigAWR,RT_WAITING_FOREVER);}			// чтение конфигурации АВР+ЛЗШ
	   	  	else if (ReadNmb==23) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRPWRStart,MB_NumbConfigTRPWR,RT_WAITING_FOREVER);}		// чтение всех уставок силового транса
	   	  	else if (ReadNmb==24) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRMeasStart,MB_NumbConfigTRMeas,RT_WAITING_FOREVER);}		// чтение всех уставок измерительного транса
	   	  	else if (ReadNmb==25) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfigVLSIn,MB_NumbConfigVLSIn,RT_WAITING_FOREVER);}		// чтение конфигурации входных логических сигналов
	   	  	else if (ReadNmb==26) {																													// чтение конфигурации выходных логических сигналов

	  					NumbBlokReadMBLim = (uint16_t)MB_NumbConfigVLSOut;
	  					NumbBlokReadMBLim = NumbBlokReadMBLim/(uint16_t)MaxSizeBlok;

	   	  				addrConfig = MB_StartConfigVLSOut + NumbBlokReadMB * MaxSizeBlok;

	   	  				if (NumbBlokReadMB == NumbBlokReadMBLim){
	   	  					SizeBlokReadMB = (uint16_t)MB_NumbConfigVLSOut;
	   	  					SizeBlokReadMB = SizeBlokReadMB % (uint16_t)MaxSizeBlok;
	   	  				}


	   	  				if (NumbBlokReadMB > NumbBlokReadMBLim){
	   	  					addrConfig = 0;
							NumbBlokReadMB = 0;
							NumbBlokReadMBLim = 0;
							SizeBlokReadMB = MaxSizeBlok;
							ReadNmb++;
	   	  				} else
	   	  				if((SizeBlokReadMB) && addrConfig<(MB_StartConfigVLSOut+MB_NumbConfigVLSOut)){
	   					   USART_TRACE_BLUE("%u-%u:Запрос:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
	   					   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
	   	  				}

	   	  			}
	   	  	else if (ReadNmb==27) {																													// чтение основной или резервной группы уставок

	   	  				if (NumbBlokReadMBLim == 0) NumbBlokReadMB = 0;

	  					NumbBlokReadMBLim = (uint16_t)MB_NumbUstavki;
	  					NumbBlokReadMBLim = NumbBlokReadMBLim/(uint16_t)MaxSizeBlok;

	   	  				addrConfig = usConfigUstavkiStart + NumbBlokReadMB * MaxSizeBlok;

	   	  				if (NumbBlokReadMB == NumbBlokReadMBLim){
	   	  					SizeBlokReadMB = (uint16_t)MB_NumbUstavki;
	   	  					SizeBlokReadMB = SizeBlokReadMB % (uint16_t)MaxSizeBlok;
	   	  				}else{
	   	  				}

	   	  			   if((SizeBlokReadMB) && addrConfig<(usConfigUstavkiStart+MB_NumbUstavki)) {
	   	  				   	   USART_TRACE_BLUE("%u-%u:Запрос:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
	   	  					   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
	   	  			   	  }
	   	  				else {
	   	  					NumbBlokReadMB = 0;
	   	  					SizeBlokReadMB = MaxSizeBlok;
	   	  					ReadNmb++;
	   	  				}

	   	  				if((SizeBlokReadMB != MaxSizeBlok) && (NumbBlokReadMB > NumbBlokReadMBLim))	{																																			// закончили
	   	  					NumbBlokReadMB = 0;
	   	  					SizeBlokReadMB = MaxSizeBlok;
	   	  					ReadNmb++;
	   	  				}
	   	  			}
//	   	  	else if (ReadNmb==26) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfigVLSOut,MB_NumbConfigVLSOut,RT_WAITING_FOREVER);}		// чтение конфигурации выходных логических сигналов
//	   	  	else if (ReadNmb==27) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigUstavkiStart,MB_NumbUstavki,RT_WAITING_FOREVER);}			// чтение основной или резервной группы уставок
	   	  	else if (ReadNmb==28) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAutomatStart,MB_NumbAutomat,RT_WAITING_FOREVER);}			// чтение параметров автоматики
	   	  	else {ReadNmb++;}

//	   	 ReadNmb = 29;
	   	   	LimitRead = 29;
	   	   	if (ReadNmb >= LimitRead) { ReadNmb = 1; osMutexRelease(xIEC850StartMutex);}

	   	   	} else{
	   	   		if (writeNmb == 9 ) ReadNmb = 10;			// если была запись в журнале ситемы то были изменения уставок. Нужно все перечитать.
	   	   		writeNmb = 0;
	   	   	}
/*******************************************************
 * наполняем оперативными данными структуру
 *******************************************************/
			if(IEC850TaskHandle && (iedServer != NULL)){
				IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

// LLN0 Health --------
					Set_LLN0(1,currentTime);
// PROT_IPTOC1..8 ------						защита по повышению тока
//					Set_IPTOC(8,currentTime);
// PROT_I20PTOC1..6 ------						защита от замыкания на землю и повешения тока обратной последовательности
//					Set_I20PTOC(6,currentTime);
// PROT_UPTOV1..4 ------						защита по повышению напряжения
//					Set_UPTOV(4,currentTime);
// PROT_UPTUV1..4 ------						защита по понижению напряжения
//					Set_UPTUV(4,currentTime);
// PROT_UPTOF1..4 ------						защита по повышению частоты
//					Set_PTOF(4,currentTime);
// PROT_UPTUF1..4 ------						защита по понижению частоты
//					Set_PTUF(4,currentTime);
// PROT_VZGGIO1..16 ------						внешняя защита
//					Set_VZGGIO(16,currentTime);
// PROT_IDPDIF ------							дифф защита
//					Set_IDPDIF(1,currentTime);
// PROT_IDDPDIF ------							дифф защита
//					Set_IDDPDIF(1,currentTime);
// PROT_IDDMPDIF ------							дифф защита
//					Set_IDDMPDIF(1,currentTime);
// PROT_ID0PDIF ------							дифф защита
//					Set_ID0PDIF(3,currentTime);
// PROT_RREC ------
//					Set_RREC(1,currentTime);
// PROT_AVRGGIO ------
//					Set_AVRGGIO(1,currentTime);
// PROT_LZSHPTOC ------									ЛЗШ
//					Set_LZSHPTOC(1,currentTime);
// PROT_RREC ------
//					Set_RBRF(1,currentTime);
// CTRL_LLN0 ------

// CTRL_CSWI ------
//					Set_CSWI(1,currentTime);
// CTRL_PTRC ------
//					Set_PTRC(1,currentTime);
// CTRL_XCBR ------
//					Set_XCBR(1,currentTime);
// CTRL_GGIO ------
//					Set_XCBRGGIO(1,currentTime);
// MES_MMXU ------
//					Set_MMXU(1,currentTime);
// MES_MSQI ------
//					Set_MSQI(1,currentTime);

// GGIO_IN24GGIO ------
//					Set_INGGIO(24,currentTime);
//					Set_OUTGGIO(18,currentTime);
//					Set_LEDGGIO(12,currentTime);
//					Set_SSLGGIO(32,currentTime);
//					Set_VLSGGIO(16,currentTime);
//					Set_LSGGIO(16,currentTime);
// LD0 SG
//					Set_SG(0,currentTime);

				IedServer_unlockDataModel(iedServer);
			}
/*******************************************************
 *
 *******************************************************/
		}
		errorType = eMBMasterPoll();						// мониторим события от MODBUS.
		if (errorType == MB_ETIMEDOUT){
    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
			vTaskDelay(5);									// делаем паузу, не успевает принять запрос.
//    		ReadNmb++;
			GLOBAL_QUALITY =  QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
    		Port_Off(LED1);
		}else
		if (errorType == MB_ENOERR || errorType == MB_ESENT){
			if (writeNmb == 10) {writeNmb = 0;}
//	   		USART_TRACE_RED("MB_ENOERR: %u\n",ReadNmb);
		}else
		if (errorType == MB_ERECVDATA){
			GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
			vTaskDelay(5);									// делаем паузу, не успевает принять запрос.
			Nextread = true;
		}

		taskYIELD();										// отпустим задачу.
	}
}
#endif
/*******************************************************
 * MR771 MODBUS
 *******************************************************/
#if defined	(MR771)
void StartMODBUSTask(void const * argument)
{
	uint16_t			NumbBlokReadMBLim=0;
	uint16_t			SizeBlokReadMB = MaxSizeBlok;			// размер одного пакета
	uint16_t			addrConfig;

	uint8_t				LimitRead=0xFE;
	uint32_t			TimerReadMB;
	eMBErrorCode		errorType;
	uint64_t 			currentTime;
	RTC_TimeTypeDef 	Time;


	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();

	writeNmb = 0;
	ReadNmb = 0;

	Port_On(LED1);

	TimerReadMB = HAL_GetTick();

	for(;;)
	{
   	   	if (writeNmb == 10) {
   	   		USART_TRACE_GREEN("1.Установка часов в приборе.\n");
   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
   	   	}
   	   	else
		if (((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS)||(Nextread)){		// периодический опрос MODBUS с периодом MB_PerForReadMODBUS(мс)
			Nextread = false;
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>2 && ReadNmb<10)ReadNmb = 1;

			//--------------- синхронизация часов ------------------------------------
			if ((ReadNmb == 1) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = 10;			// первый раз

			//--------------- Выключатель ------------------------------------
	   	   	if (writeNmb == 1) {
	   	   		USART_TRACE_GREEN("Выключатель ON\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwON,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 2) {
	   	   		USART_TRACE_RED("Выключатель OFF\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwOFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}

	   	   	if (writeNmb == 3) {
	   	   		USART_TRACE_RED("сброс индикации\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 4) {
	   	   		USART_TRACE_RED("сброс новой неисправности\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале системы \n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 6) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале аварий\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 7) {
	   	   		USART_TRACE_RED("Переключение группы уставок %u\n",writeNmbSG);
	   	   		eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_Startaddr_SG,writeNmbSG - 1,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 9) {
	   	   		USART_TRACE_RED("Сброс записи журнала системы.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 10) {
	   	   		USART_TRACE_GREEN("2.Установка часов в приборе.\n");
	   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
	   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
	   	   	}
	   		currentTime = Hal_getTimeInMs();

			//--------------- База чтения -----------------------------------------
	   	   	if (writeNmb == 0){	// запись без очереди выполним.

			//--------------- синхронизация часов только если не работает NTP -----
	   	     if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) {					//если прошел час то делаем синхронизацию снова
					ReadNmb = LimitRead;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("Пересинхронизация часов. время:0x%X\n",(unsigned int)currentTime);
				}
	   	     }

			// уставки нужно читать только той группы по которой работаем, Выделить одну область памяти
	   	     {
	   	    	 uint16_t	adin = (uint16_t)MB_NumbUstavki;
	   	    	 adin = adin * ucSGBuf[0];
	   	    	 usConfigUstavkiStart = (uint16_t)MB_StartUstavkiaddr0 + adin;
	   	     }

//TODO: удалить
//			ReadNmb = 29;

			// периодическое чтение
	   	   	if (ReadNmb==0)  		eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);					// чтение ревизии устройства
	   	   	else if (ReadNmb==1)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// чтение дискретной базы
	   	   	else if (ReadNmb==2) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);				// чтение аналоговой базы

	   		// однократное чтение
	   	   	else if (ReadNmb==10)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// чтение дискретной базы
	   	   	else if (ReadNmb==11) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);						// чтение текущего времени
	   	   	else if (ReadNmb==12) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSystemCfgStart,MB_NumbSystemCfg,RT_WAITING_FOREVER);				// чтение конфигурации системы
	   	   	else if (ReadNmb==13) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSGStart,MB_NumbSG,RT_WAITING_FOREVER);							// чтение группы уставок

	   	   	else if (ReadNmb==14) 	ReadNmb = 19;	// прыгнем к 20

	   	  	else if (ReadNmb==20) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigStartSW,MB_NumbConfigSW,RT_WAITING_FOREVER);}				// чтение конфигурации выключателя
	   	   	else if (ReadNmb==21) 	ReadNmb = 26;	// прыгнем к 27

// данные находятся в группах уставок
//	   	  	else if (ReadNmb==21) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAPWStart,MB_NumbConfigAPW,RT_WAITING_FOREVER);}			// чтение конфигурации АПВ
//	   	  	else if (ReadNmb==22) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAWRStart,MB_NumbConfigAWR,RT_WAITING_FOREVER);}			// чтение конфигурации АВР+ЛЗШ
//	   	  	else if (ReadNmb==23) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRPWRStart,MB_NumbConfigTRPWR,RT_WAITING_FOREVER);}		// чтение всех уставок силового транса
//	   	  	else if (ReadNmb==24) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRMeasStart,MB_NumbConfigTRMeas,RT_WAITING_FOREVER);}		// чтение всех уставок измерительного транса
//	   	  	else if (ReadNmb==25) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfigVLSIn,MB_NumbConfigVLSIn,RT_WAITING_FOREVER);}		// чтение конфигурации входных логических сигналов
/*	   	  	else if (ReadNmb==26) {																													// чтение конфигурации выходных логических сигналов

	   	  				if (NumbBlokReadMBLim == 0) NumbBlokReadMB = 0;

						NumbBlokReadMBLim = (uint16_t)MB_NumbConfigVLSOut;
						NumbBlokReadMBLim = NumbBlokReadMBLim/(uint16_t)MaxSizeBlok;

						addrConfig = MB_StartConfigVLSOut + NumbBlokReadMB * MaxSizeBlok;

						if (NumbBlokReadMB == NumbBlokReadMBLim){
							SizeBlokReadMB = (uint16_t)MB_NumbConfigVLSOut;
							SizeBlokReadMB = SizeBlokReadMB % (uint16_t)MaxSizeBlok;
						}


						if (NumbBlokReadMB > NumbBlokReadMBLim){
							addrConfig = 0;
							NumbBlokReadMB = 0;
							NumbBlokReadMBLim = 0;
							SizeBlokReadMB = MaxSizeBlok;
							ReadNmb++;
						} else
						if((SizeBlokReadMB) && addrConfig<(MB_StartConfigVLSOut+MB_NumbConfigVLSOut)){
						   USART_TRACE_BLUE("%u-%u:Запрос:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
						   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
						}

	   	  			}
*/
	   	  	else if (ReadNmb==27) {																													// чтение основной или резервной группы уставок

	   	  				if (NumbBlokReadMBLim == 0) NumbBlokReadMB = 0;

	  					NumbBlokReadMBLim = (uint16_t)MB_NumbUstavki;
	  					NumbBlokReadMBLim = NumbBlokReadMBLim/(uint16_t)MaxSizeBlok;

	   	  				addrConfig = usConfigUstavkiStart + NumbBlokReadMB * MaxSizeBlok;

	   	  				if (NumbBlokReadMB == NumbBlokReadMBLim){
	   	  					SizeBlokReadMB = (uint16_t)MB_NumbUstavki;
	   	  					SizeBlokReadMB = SizeBlokReadMB % (uint16_t)MaxSizeBlok;
	   	  				}

	   	  				if (NumbBlokReadMB > NumbBlokReadMBLim){
	   	  					addrConfig = 0;
							NumbBlokReadMB = 0;
							NumbBlokReadMBLim = 0;
							SizeBlokReadMB = MaxSizeBlok;
							ReadNmb++;
	   	  				} else
					    if((SizeBlokReadMB) && addrConfig<(usConfigUstavkiStart+MB_NumbUstavki)) {
							   USART_TRACE_BLUE("%u-%u:Запрос:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
							   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
						  }


	   	  			}
	   	  	else if (ReadNmb==28) {																													// чтение параметров автоматики.

	   	  				if (NumbBlokReadMBLim == 0) NumbBlokReadMB = 0;

	  					NumbBlokReadMBLim = (uint16_t)MB_NumbAutomat;
	  					NumbBlokReadMBLim = NumbBlokReadMBLim/(uint16_t)MaxSizeBlok;

	   	  				addrConfig = usConfigAutomatStart + NumbBlokReadMB * MaxSizeBlok;

	   	  				if (NumbBlokReadMB == NumbBlokReadMBLim){
	   	  					SizeBlokReadMB = (uint16_t)MB_NumbAutomat;
	   	  					SizeBlokReadMB = SizeBlokReadMB % (uint16_t)MaxSizeBlok;
	   	  				}else{
	   	  				}

	   	  			   if((SizeBlokReadMB) && addrConfig<(usConfigAutomatStart+MB_NumbAutomat)) {
	   	  				   	   USART_TRACE_BLUE("%u-%u:Запрос:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
	   	  					   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
	   	  			   	  }
	   	  				else {
	   	  					NumbBlokReadMB = 0;
	   	  					SizeBlokReadMB = MaxSizeBlok;
	   	  					ReadNmb++;
	   	  				}

	   	  				if((SizeBlokReadMB != MaxSizeBlok) && (NumbBlokReadMB > NumbBlokReadMBLim))	{																																			// закончили
	   	  					NumbBlokReadMB = 0;
	   	  					SizeBlokReadMB = MaxSizeBlok;
	   	  					ReadNmb++;
	   	  				}
	   	  			}

//	   	  	else if (ReadNmb==26) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfigVLSOut,MB_NumbConfigVLSOut,RT_WAITING_FOREVER);}		// чтение конфигурации выходных логических сигналов
//	   	  	else if (ReadNmb==27) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigUstavkiStart,MB_NumbUstavki,RT_WAITING_FOREVER);}			// чтение основной или резервной группы уставок
	   	  	else if (ReadNmb==28) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAutomatStart,MB_NumbAutomat,RT_WAITING_FOREVER);}			// чтение параметров автоматики
	   	  	else {ReadNmb++;}

	   	   	LimitRead = 29;
	   	   	if (ReadNmb >= LimitRead) { ReadNmb = 1; osMutexRelease(xIEC850StartMutex);}

	   	   	} else{
	   	   		if (writeNmb == 9 ) ReadNmb = 10;			// если была запись в журнале ситемы то были изменения уставок. Нужно все перечитать.
	   	   		writeNmb = 0;
	   	   	}
/*******************************************************
 * наполняем оперативными данными структуру
 *******************************************************/
			if(IEC850TaskHandle && (iedServer != NULL)){
				IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

// PROT_LLN0 Health --------
				{
					uint32_t	LLN0_Health = STVALINT32_OK;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {LLN0_Health = STVALINT32_Warning;}
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LLN0_Health_stVal, LLN0_Health);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LLN0_Health_t, currentTime);
				}
// PROT_IPTOC1..8 ------						защита по повышению тока
					Set_IPTOC(6,currentTime);
// Set_I2I1PTOC ------
//					Set_I2I1PTOC(1,currentTime);
// Set_IPTUC ------
//					Set_IPTUC(1,currentTime);
// PROT_I20PTOC1..6 ------						защита от замыкания на землю и повешения тока обратной последовательности
//					Set_I20PTOC(6,currentTime);
// PROT_UPTOV1..4 ------						защита по повышению напряжения
//					Set_UPTOV(4,currentTime);
// PROT_UPTUV1..4 ------						защита по понижению напряжения
//					Set_UPTUV(4,currentTime);
// PROT_UPTOF1..4 ------						защита по повышению частоты
//					Set_PTOF(4,currentTime);
// PROT_UPTUF1..4 ------						защита по понижению частоты
//					Set_PTUF(4,currentTime);
// PROT_VZGGIO1..16 ------						внешняя защита
//					Set_VZGGIO(16,currentTime);
// PROT_RREC ------
//					Set_RREC(1,currentTime);
// PROT_RREC ------
//					Set_RBRF(1,currentTime);

// CTRL_CSWI ------
//					Set_CSWI(1,currentTime);
// CTRL_PTRC ------
//					Set_PTRC(1,currentTime);
// CTRL_XCBR ------
//					Set_XCBR(1,currentTime);
// CTRL_GGIO ------
//					Set_XCBRGGIO(1,currentTime);
// MES_MMXU ------
//					Set_MMXU(1,currentTime);

// GGIO_IN24GGIO ------
//					Set_INGGIO(24,currentTime);
//					Set_OUTGGIO(18,currentTime);
//					Set_LEDGGIO(12,currentTime);
//					Set_SSLGGIO(32,currentTime);
//					Set_VLSGGIO(16,currentTime);
//					Set_LSGGIO(16,currentTime);
// LD0 SG
//					Set_SG(0,currentTime);

				IedServer_unlockDataModel(iedServer);
			}
/*******************************************************
 *
 *******************************************************/
		}
		errorType = eMBMasterPoll();						// мониторим события от MODBUS.
		if (errorType == MB_ETIMEDOUT){
    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
			vTaskDelay(5);									// делаем паузу, не успевает принять запрос.

			GLOBAL_QUALITY =  QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
    		Port_Off(LED1);
		}else
		if (errorType == MB_ENOERR || errorType == MB_ESENT){
			if (writeNmb == 10) {writeNmb = 0;}
//	   		USART_TRACE_RED("MB_ENOERR: %u\n",ReadNmb);
		}else
		if (errorType == MB_ERECVDATA){
			GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
			vTaskDelay(5);									// делаем паузу, не успевает принять запрос.
			Nextread = true;
		}


		taskYIELD();										// отпустим задачу.
	}
}
#endif
/*******************************************************
 * MR5_700 MODBUS
 *******************************************************/
#if defined (MR5_700)
void StartMODBUSTask(void const * argument)
{
	extern uint64_t nextSynchTime;
	extern bool resynch;
	uint32_t			TimerReadMB;
	uint8_t				ReadNmb;
	eMBErrorCode		errorType;
	uint8_t				i;
	RTC_TimeTypeDef 	Time;
	uint8_t  			PerForSynch;
	extern const uint8_t userConfig[];

//	osMutexWait(xIEC850StartMutex, osWaitForever);				// забрали мьютекс для блокировки TCP пока не получим настройки IP
//	USART_TRACE_BLUE("MODBUS забрал мьютекс IEC850Start\n");

//	usMDiscInStart = MB_StartDiscreetaddr;

	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();

//	vTaskDelay(1000);
	writeNmb = 0;
	ReadNmb = 0;

	Port_On(LED1);
/*
	{
		uint8_t 			HardFaultcnt;												// счетчик перезапусков
		memory_read((uint8_t *)&HardFaultcnt,_IfHardFault,sizeof(HardFaultcnt));						// читаем IP из внешней флэшки
		HardFaultcnt++;
		memory_write_to_mem((uint8_t *)&HardFaultcnt,_IfHardFault,sizeof(HardFaultcnt));
		USART_TRACE_GREEN("Число запусков: %u\n",HardFaultcnt);
	}
*/
	TimerReadMB = HAL_GetTick();
	for(;;)
	{
 //		IedServer_setControlHandler(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1, (ControlHandler)controlListener, &iedModel_GGIO_OUTGGIO1_SPCSO1);

		// попробовать при установке часов не ждать это время, а сразу отправить
	 	if (writeNmb == 10) {
		   	   		USART_TRACE_RED("Установка часов в приборе.\n");
		   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
		   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (UCHAR *)&ucMDateBuf,RT_WAITING_FOREVER);
		   	   	}
	 	else
		if (((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS)||(Nextread)){		// периодический опрос MODBUS с периодом MB_PerForReadMODBUS(мс)
			Nextread = false;
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>14) {ReadNmb = 1;}
			if (ReadNmb>2 && ReadNmb<10) ReadNmb = 1;

			//--------------- синхронизация часов ------------------------------------
			if ((ReadNmb == 1) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = 10;			// первый раз

			//--------------- Выключатель ------------------------------------
	   	   	if (writeNmb == 1) {
	   	   		USART_TRACE_GREEN("Выключатель ON\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwON,MB_SwON,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 2) {
	   	   		USART_TRACE_RED("Выключатель OFF\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwOFF,MB_SwON,RT_WAITING_FOREVER);
	   	   	}

	   	   	if (writeNmb == 3) {
	   	   		USART_TRACE_RED("сброс индикации\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 4) {
	   	   		USART_TRACE_RED("сброс новой неисправности\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале системы \n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 6) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале аварий\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 7) {
	   	   		USART_TRACE_RED("Переключение группы уставок 0.\n");
	   	   		eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_addr_SG,MB_selectGroupe0,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 8) {
	   	   		USART_TRACE_RED("Переключение группы уставок 1.\n");
	   	   		eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_addr_SG,MB_selectGroupe1,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 9) {
	   	   		USART_TRACE_RED("Сброс записи журнала системы.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
/*
	   	   	if (writeNmb == 10) {
	   	   		USART_TRACE_RED("Установка часов в приборе.\n");
	   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
	   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (UCHAR *)&ucMDateBuf,RT_WAITING_FOREVER);
	   	   	}
*/
	   		uint64_t currentTime = Hal_getTimeInMs();

			//--------------- База чтения -----------------------------------------
	   	   	if (writeNmb == 0){	// запись без очереди выполним.

			//--------------- синхронизация часов только если не работает NTP -----
	   	     if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) {					//если прошел час то делаем синхронизацию снова
					ReadNmb = 15;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("Пересинхронизация часов. время:0x%X\n",(unsigned int)currentTime);
				}
	   	     }
			// периодическое чтение
	   	   	if (ReadNmb==0)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);		// чтение ревизии устройства
	   		if (ReadNmb==1)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);
	   		if (ReadNmb==2)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);

	   		// однократное чтение
	   	   	if (ReadNmb==10) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);				// чтение текущего времени
	   	   	if (ReadNmb==11) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigStart,MB_NumbConfig,RT_WAITING_FOREVER);			// чтение уставок(только IP адрес)
	   	   	if (ReadNmb==12) {eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfig+MB_offset_Ktt,1,RT_WAITING_FOREVER);}		// чтение уставок
	   	   	if (ReadNmb==13) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfig+MB_offset_Ktn,1,RT_WAITING_FOREVER);		// чтение уставок
	   	   	if (ReadNmb==14) {
	   	   		eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfig,MB_NumbConfigall,RT_WAITING_FOREVER);		// чтение всех уставок
	   	   		osMutexRelease(xIEC850StartMutex);
	   	   	}
	   	   	ReadNmb++;	// перенёс вниз, после положительного результата отправки
	   	   	} else{
	   	   		if (writeNmb == 9 ) ReadNmb = 10;
	   	   		writeNmb = 0;
	   	   	}
//+++++++++++++++++++
/*
			errorType = eMBMasterPoll();						// мониторим события от MODBUS.
			if (errorType == MB_ETIMEDOUT){
	    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
	    		//if (ReadNmb) ReadNmb--;
	    	Port_Off(LED1);
			}else
			if (errorType == MB_ENOERR){
				if (writeNmb == 0) ReadNmb++;
			}
*/
//+++++++++++++++++++
if(IEC850TaskHandle && (iedServer != NULL)){

            IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

if (ucMDiscInBuf[MB_offsetError] & MB_errorMSD1){
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
} else
{
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind1_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind2_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind3_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind4_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind5_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind6_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind7_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind8_q,0 | 0);

            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<0));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<1));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<2));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<3));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<4));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<5));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<6));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<7));
}
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind1_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind2_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind3_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind4_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind5_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind6_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind7_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind8_t, currentTime);

if (ucMDiscInBuf[MB_offsetError] & MB_errorMSD2){
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
} else{
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind9_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind10_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind11_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind12_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind13_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind14_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind15_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind16_q,0 | 0);

            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<8));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<9));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<10));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<11));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<12));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<13));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<14));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<15));

}
   	   	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind9_t, currentTime);
      	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind10_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind11_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind12_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind13_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind14_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind15_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind16_t, currentTime);

if (ucMDiscInBuf[MB_offsetError] & MB_errorMRV1){
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
}else{
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO1_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO2_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO3_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO4_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO5_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO6_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO7_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO8_q,0);

          	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<0));
       	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<1));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<2));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<3));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<4));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<5));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<6));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<7));
}
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO1_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO2_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO3_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO4_t, currentTime);
    	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO5_t, currentTime);
     	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO6_t, currentTime);
    	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO7_t, currentTime);
    	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO8_t, currentTime);

//PTOC ------------------------

    IedServer_updateInt32AttributeValue(iedServer,&iedModel_PROT_IPTOC1_Health_stVal,(ucMDiscInBuf[MB_offsetError] & (MB_errorMSAI | MB_errorMSAU)));
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Health_t, currentTime);
	IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Health_q,0);


	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_general,  ucMDiscInBuf[MB_offset_I_IO] & (1<<0));

//	int16_t		Valtmp = GetDirGeneral((ucMDiscInBuf[MB_offsetPTOC] >> 2) & 0b111111);
	int16_t		Valtmp = ucMDiscInBuf[MB_offsetDirGeneral] & 0b11;
	MmsValue* ValMMS = MmsValue_newIntegerFromInt16(Valtmp);

	IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_dirGeneral, ValMMS);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);

	if (ucMDiscInBuf[MB_offsetError] & MB_errorMSAI){
		IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Str_q, QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	} else{
		IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Str_q,0);
	}
	MmsValue_delete(ValMMS);

	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_general,  ucMDiscInBuf[MB_offset_I_IO] & (1<<1));
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_t, currentTime);
	IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Op_q,0);

//!PTOC ------------------------

	if (ucMDiscInBuf[MB_offsetError] & MB_errorMSAU){
		// напряжения
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_res_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Hz_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

	}
	else{
		// напряжения
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsA_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsB_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsC_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_res_q,0);

		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsA_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsB_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsC_q,0);

		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Hz_q,0);
// phV
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ua],Ktn));
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ub],Ktn));
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Uc],Ktn));
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_res_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Un],ucMConfigBufall[MB_offset_Ktnnp]));

// PPV
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Uab],Ktn));
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ubc],Ktn));
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Uca],Ktn));

		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_mag_f,(float)ucMAnalogInBuf[MB_offset_Hz]/256);

	}
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsA_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsB_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsC_t, currentTime);

	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsA_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsB_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsC_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Hz_t, currentTime);

// Аналоговые токовые данные
	if (ucMDiscInBuf[MB_offsetError] & MB_errorMSAI){
		// токи
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_res_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	}
	else{
		// токи
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_res_q,0);
		float CurrA;
		CurrA = (float)(ucMAnalogInBuf[MB_offset_Ia] * 40)/65536 * Ktt;
//		if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotVAZ) {CurrA = -CurrA;}
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsA_cVal_mag_f,CurrA);

		CurrA = (float)(ucMAnalogInBuf[MB_offset_Ib] * 40)/65536 * Ktt;
//		if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotVAZ) {CurrA = -CurrA;}
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsB_cVal_mag_f,CurrA);

		CurrA = (float)(ucMAnalogInBuf[MB_offset_Ic] * 40)/65536 * Ktt;
//		if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotVAZ) {CurrA = -CurrA;}
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsC_cVal_mag_f,CurrA);

		CurrA = (float)(ucMAnalogInBuf[MB_offset_In] * 5)/65536 * ucMConfigBufall[MB_offset_Kttnp];
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_res_cVal_mag_f,CurrA);

	}
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsA_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsB_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsC_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_res_t, currentTime);

    //мощность ----------------------------------------------------
	if ((ucMDiscInBuf[MB_offsetError] & MB_errorMSAU) || (ucMDiscInBuf[MB_offsetError] & MB_errorMSAI)){

		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totW_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totVAr_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totPF_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	}else{
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totW_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totVAr_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totPF_q,0);

		float CurrW;
		CurrW = (float)(ucMAnalogInBuf[MB_offset_TotW]);
		if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotWZ) {CurrW = -CurrW;}
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_mag_f,CurrW);

		CurrW = (float)(ucMAnalogInBuf[MB_offset_TotVAr]);
		if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotVAZ) {CurrW = -CurrW;}
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_mag_f,CurrW);

		CurrW = (float)ucMAnalogInBuf[MB_offset_TotPF]/256;
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_mag_f,CurrW);

	}
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totW_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totVAr_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totPF_t, currentTime);

// !!Аналоговые токовые данные


//CSWI
//-------------------------------

	{
	uint8_t	res=STVALCODEDENUM_INTERMEDIATE;
	if (ucMDiscInBuf[MB_offset_adr0] & MB_offsetSW_OFF) {res |= STVALCODEDENUM_OFF;}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_offsetSW_ON)  {res |= STVALCODEDENUM_ON;} 			//2 - STATE_ON ? 1- STATE_OFF ? 0 -  STATE_INTERMEDIATE

	IedServer_updateBitStrinAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_stVal, res);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Pos_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_t, currentTime);


	uint32_t	res32 = STVALINT32_OK;
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorHard) 	{res32 |= STVALINT32_Warning;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorLogic) 	{res32 |= STVALINT32_Warning;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorData) 	{res32 |= STVALINT32_Warning;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorSW) 		{res32 |= STVALINT32_Warning;}

	IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Health_stVal, res32);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Health_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Health_t, currentTime);

	if (ucMConfigBufall[MB_offset_ControlBits] & MB_bOffset_ControlSDTU){
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Mod_stVal, 1);
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Beh_stVal, 1);
	}else {
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Mod_stVal, 5);
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Beh_stVal, 5);
	}
	IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Mod_q,0);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Beh_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Mod_t, currentTime);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Beh_t, currentTime);

	}
//XCBR
//--------------------------------
	{
	//Pos
	uint8_t	res=STVALCODEDENUM_INTERMEDIATE;
	if (ucMDiscInBuf[MB_offset_adr0] & MB_offsetSW_OFF) {res |= STVALCODEDENUM_OFF;}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_offsetSW_ON)  {res |= STVALCODEDENUM_ON;} 			//2 - STATE_ON ? 1- STATE_OFF ? 0 -  STATE_INTERMEDIATE

	IedServer_updateBitStrinAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Pos_stVal, res);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_XCBR1_Pos_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Pos_t, currentTime);


	uint32_t	res32 = STVALINT32_OK;
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorHard) 	{res32 |= STVALINT32_Warning;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorLogic) 	{res32 |= STVALINT32_Warning;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorData) 	{res32 |= STVALINT32_Warning;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorSW) 		{res32 |= STVALINT32_Warning;}

	IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_XCBR1_Health_stVal, res32);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_XCBR1_Health_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Health_t, currentTime);

	if (ucMConfigBufall[MB_offset_ControlBits] & MB_bOffset_ControlSDTU){
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_XCBR1_Mod_stVal, 1);
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_XCBR1_Beh_stVal, 1);
	}else {
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_XCBR1_Mod_stVal, 5);
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_XCBR1_Beh_stVal, 5);
	}
	IedServer_updateQuality(iedServer,&iedModel_CTRL_XCBR1_Mod_q,0);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_XCBR1_Beh_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Mod_t, currentTime);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Beh_t, currentTime);


	//Loc
	bool XCBR1_Loc=0;
	if (ucMConfigBufall[MB_offset_BlockSDTU]) {XCBR1_Loc = 1;}
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Loc_stVal, XCBR1_Loc);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_XCBR1_Loc_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Loc_t, currentTime);
	}

//	IedServer_updateInt32AttributeValue(iedServer, iedModel_CTRL_XCBR1_OpCnt_stVal,(ucMConfigBufall[MB_offset_BlockSDTU]);

	//--------------------------------

//LEDGGIO1
//--------------------------------
 	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<8));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<9));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<10));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<11));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<12));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<13));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<14));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<15));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<4));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<5));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<6));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<7));

	// статус сброса нидикаторов
	if (ucMDiscInBuf[MB_offsetLED] & 0xFF00){
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_SPCSO1_stVal,  1);
	    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_SPCSO1_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_SPCSO1_stVal,  0);
	    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_SPCSO1_t, currentTime);

	}


    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);


    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind1_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind2_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind3_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind4_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind5_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind6_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind7_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind8_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind9_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind10_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind11_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind12_q,0);

//--------------------------------
// сброс флагов

	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetError){
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
	}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetSysNote){
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO2_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO2_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
	}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetErrorNote){
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO3_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO3_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
	}

//--------------------------------
// MSQI1
	int32_t MSQI_stval = 0;

	if (ucMDiscInBuf[MB_offsetError] & (MB_errorMRV1|MB_errorMSAI)) {
		MSQI_stval = 2;
	} else		MSQI_stval = 1;

	IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI1_Health_stVal,  MSQI_stval);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_Health_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_Health_t, currentTime);

// SeqA
    float	cXtmp = (float)ucMAnalogInBuf[MB_offset_NI1] * 40 * Ktt / 65536;
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c1_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c1_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c1_t, currentTime);

    cXtmp = (float)ucMAnalogInBuf[MB_offset_NI2] * 40 * Ktt / 65536;
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c2_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c2_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c2_t, currentTime);

    cXtmp = (float)ucMAnalogInBuf[MB_offset_NI0] * 40 * Ktt / 65536;
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c3_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c3_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c3_t, currentTime);

// SeqU
    cXtmp = (float)GetRealU(ucMAnalogInBuf[MB_offset_NU1],Ktn);
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c1_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c1_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c1_t, currentTime);

    cXtmp = (float)GetRealU(ucMAnalogInBuf[MB_offset_NU2],Ktn);
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c2_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c2_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c2_t, currentTime);

    cXtmp = (float)GetRealU(ucMAnalogInBuf[MB_offset_NU0],Ktn);
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c3_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c3_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c3_t, currentTime);

//--------------------------------

//--------------------------------
// RFLO
	uint32_t	OMP;
	if (ucMConfigBufall[MB_offset_OMP] & 1){OMP=1;}	else{OMP=5;}
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Mod_stVal,  OMP);
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Beh_stVal,  OMP);

    IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Mod_q,0);
    IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Beh_q,0);

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_Mod_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_Beh_t, currentTime);

	uint32_t	err;
	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetError){err=1;}	else{err=5;}
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Health_stVal,  err);
    IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Health_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_Health_t, currentTime);


    float	fltz = (float)ucMAnalogInBuf[MB_offset_OMPLkz] * (float)ucMConfigBufall[MB_offset_OMP+1] / (float)256000;
	IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_RFLO1_Fltz_mag_f,  (float)fltz);
    IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Fltz_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_Fltz_t, currentTime);

    fltz = (float)ucMAnalogInBuf[MB_offset_OMPLkz]/(float)256;
	IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_RFLO1_FltDiskm_mag_f, fltz);
    IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_FltDiskm_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_FltDiskm_t, currentTime);


//--------------------------------
    // остальные узлыузлы
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LLN0_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LLN0_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LLN0_Mod_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LPHD1_Proxy_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LPHD1_PhyHealth_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
//LEDGGIO1
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);


    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Mod_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Mod_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_t, currentTime);


    // проверяем группу уставок
    uint8_t	currSG = 1;
    if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetSettingGr) currSG = 2;

	if (currSG != IedServer_getActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0))) {
		IedServer_changeActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0),currSG );
		USART_TRACE("Изменилась группа уставок. %u\n",iedModel_LD0_LLN0_sgcb0.actSG);
	}

	// -------------------- были ли изменения в уставках ---------------------------
    if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetSysNote) {
    	// было изменение уставок. Нужно их перечитать.
    	USART_TRACE("Изменились уставки.\n");
    	writeNmb = 9;
    	ucMDiscInBuf[MB_offset_adr0] ^= MB_bOffsetSysNote;
    }


    IedServer_unlockDataModel(iedServer);																// отдаём управление mmsServer'ом
}
//+++++++++++++++++++
		}
		errorType = eMBMasterPoll();						// мониторим события от MODBUS.
		if (errorType == MB_ETIMEDOUT){
    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
    		ReadNmb++;
			GLOBAL_QUALITY =  QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
    		Port_Off(LED1);
		}else
		if (errorType == MB_ENOERR || errorType == MB_ESENT){
			if (writeNmb == 10) {writeNmb = 0;}
//	   		USART_TRACE_RED("MB_ENOERR: %u\n",ReadNmb);
		}else
		if (errorType == MB_ERECVDATA){
			GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
			vTaskDelay(5);									// делаем паузу, не успевает принять запрос.
			Nextread = true;
		}
		/*
		errorType = eMBMasterPoll();						// мониторим события от MODBUS.
		if (errorType == MB_ETIMEDOUT){
    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
    		//if (ReadNmb) ReadNmb--;
    	Port_Off(LED1);
		}else
		if (errorType == MB_ENOERR){
//			if (writeNmb == 0) ReadNmb++;
			if (writeNmb == 10) {writeNmb = 0;}
		}
*/
		taskYIELD();										// отпустим задачу.
	}
}
#endif
/*******************************************************
 * MR5_600 MODBUS
 *******************************************************/
#if defined (MR5_600)
void StartMODBUSTask(void const * argument)
{
	extern uint64_t nextSynchTime;
	extern bool resynch;
	uint32_t			TimerReadMB;
	uint8_t				ReadNmb=0;
	eMBErrorCode		errorType;
	uint8_t				i;
	RTC_TimeTypeDef 	Time;
	uint8_t  			PerForSynch;
	extern const uint8_t userConfig[];

//	osMutexWait(xIEC850StartMutex, osWaitForever);				// забрали мьютекс для блокировки TCP пока не получим настройки IP
//	USART_TRACE_BLUE("MODBUS забрал мьютекс IEC850Start\n");

//	usMDiscInStart = MB_StartDiscreetaddr;

	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();

//	ReadNmb = userConfig[4];			// чтение из flash.

	Port_On(LED1);
	/*
	{
			uint8_t 			HardFaultcnt;												// счетчик перезапусков
			memory_read((uint8_t *)&HardFaultcnt,_IfHardFault,sizeof(HardFaultcnt));						// читаем IP из внешней флэшки
			HardFaultcnt++;
			memory_write_to_mem((uint8_t *)&HardFaultcnt,_IfHardFault,sizeof(HardFaultcnt));
			USART_TRACE_GREEN("Число запусков: %u\n",HardFaultcnt);
		}
*/
	TimerReadMB = HAL_GetTick();
	for(;;)
	{
 //		IedServer_setControlHandler(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1, (ControlHandler)controlListener, &iedModel_GGIO_OUTGGIO1_SPCSO1);

   	   	if (writeNmb == 10) {
   	   		USART_TRACE_RED("Установка часов в приборе.\n");
   	   	Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (uint16_t *)&ucMDateBuf,RT_WAITING_FOREVER);
   	   	}
   	   	else
		if ((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS){					// периодический опрос MODBUS с периодом MB_PerForReadMODBUS(мс)
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>13) {ReadNmb = 1;}
			if (ReadNmb>2 && ReadNmb<10) ReadNmb = 1;

			//--------------- синхронизация часов ------------------------------------
			if ((ReadNmb == 1) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = 10;			// первый раз

			//--------------- Выключатель ------------------------------------
	   	   	if (writeNmb == 1) {
	   	   		USART_TRACE_GREEN("Выключатель ON\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwON,MB_SwON,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 2) {
	   	   		USART_TRACE_RED("Выключатель OFF\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwOFF,MB_SwON,RT_WAITING_FOREVER);
	   	   	}

	   	   	if (writeNmb == 3) {
	   	   		USART_TRACE_RED("сброс индикации\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 4) {
	   	   		USART_TRACE_RED("сброс новой неисправности\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале системы \n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 6) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале аварий\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 7) {
	   	   		USART_TRACE_RED("Переключение группы уставок 0.\n");
	   	   		eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_addr_SG,MB_selectGroupe0,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 8) {
	   	   		USART_TRACE_RED("Переключение группы уставок 1.\n");
	   	   		eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_addr_SG,MB_selectGroupe1,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 9) {
	   	   		USART_TRACE_RED("Сброс записи журнала системы.\n");
	   	   	eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 10) {
	   	   		USART_TRACE_RED("Установка часов в приборе.\n");
	   	   	Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
	   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (uint16_t *)&ucMDateBuf,RT_WAITING_FOREVER);
	   	   	}
	   		uint64_t currentTime = Hal_getTimeInMs();

			//--------------- База чтения ------------------------------------
	   	   	if (writeNmb == 0){	// запись без очереди выполним.

			//--------------- синхронизация часов ------------------------------------
	   	   	// пересинхронизировать будем прибор а не из прибора
	  	    if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) 					//если прошел час то делаем синхронизацию снова
				{
					ReadNmb = 15;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("Пересинхронизация часов. время:0x%X\n",(unsigned int)currentTime);
				}
	  	     }
			// периодическое чтение
	   	   	if (ReadNmb==0)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);		// чтение ревизии устройства
	   		if (ReadNmb==1)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);
	   		if (ReadNmb==2)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);

	   		// однократное чтение
	   	   	if (ReadNmb==10) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);				// чтение текущего времени
	   	   	if (ReadNmb==11) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigStart,MB_NumbConfig,RT_WAITING_FOREVER);			// чтение уставок(только IP адрес)
//	   	   	if (ReadNmb==12) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfig+MB_offset_Ktt,1,RT_WAITING_FOREVER);		// чтение уставок
	   	   	if (ReadNmb==12) {eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfig+MB_offset_Ktn,1,RT_WAITING_FOREVER);}		// чтение уставок
	   	   	if (ReadNmb==13) {
	   	   		eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfig,MB_NumbConfigall,RT_WAITING_FOREVER);					// чтение всех уставок
	   	   		osMutexRelease(xIEC850StartMutex);	// отпустим задачу 61850
	   	   	}
	   	   	ReadNmb++;
	   	   	} else{
	   	   		if (writeNmb == 9 ) ReadNmb = 10;
	   	   		writeNmb = 0;
	   	   	}
//+++++++++++++++++++
/*
	   	 		errorType = eMBMasterPoll();						// мониторим события от MODBUS.
	   	 		if (errorType == MB_ETIMEDOUT){
	   	    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
	   	     		//if (ReadNmb) ReadNmb--;
	   	     	Port_Off(LED1);
	   	 		}
*/
//+++++++++++++++++++
if(IEC850TaskHandle && (iedServer != NULL)){

            IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

if (ucMDiscInBuf[MB_offsetError] & MB_errorMSD1){
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
} else
{
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind1_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind2_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind3_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind4_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind5_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind6_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind7_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind8_q,0 | 0);

            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & MB_boffsetDiscreet1);
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & MB_boffsetDiscreet2);
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & MB_boffsetDiscreet3);
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & MB_boffsetDiscreet4);
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & MB_boffsetDiscreet5);
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & MB_boffsetDiscreet6);
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & MB_boffsetDiscreet7);
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & MB_boffsetDiscreet8);
}
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind1_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind2_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind3_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind4_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind5_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind6_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind7_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind8_t, currentTime);

/*
if (ucMDiscInBuf[MB_offsetError] & MB_errorMSD2){
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
} else{
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind9_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind10_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind11_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind12_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind13_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind14_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind15_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind16_q,0 | 0);

            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<8));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<9));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<10));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<11));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<12));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<13));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<14));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<15));

}
   	   	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind9_t, currentTime);
      	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind10_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind11_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind12_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind13_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind14_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind15_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind16_t, currentTime);
*/
if (ucMDiscInBuf[MB_offsetError] & MB_errorMRV1){
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
}else{
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO1_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO2_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO3_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO4_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO5_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO6_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO7_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO8_q,0);

          	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<0));
       	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<1));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<2));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<3));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<4));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<5));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<6));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<7));
}
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO1_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO2_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO3_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO4_t, currentTime);
    	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO5_t, currentTime);
     	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO6_t, currentTime);
    	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO7_t, currentTime);
    	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO8_t, currentTime);

if (ucMDiscInBuf[MB_offsetError] & MB_errorMRV2){
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
}else{
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO9_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO10_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO11_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO12_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO13_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO14_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO15_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO16_q,0);

			IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO9_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<8));
			IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO10_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<9));
			IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO11_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<10));
			IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO12_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<11));
			IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO13_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<12));
			IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO14_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<13));
			IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO15_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<14));
			IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO16_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<15));
}
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO9_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO10_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO11_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO12_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO13_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO14_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO15_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO16_t, currentTime);

//PTOC
/*
    IedServer_updateInt32AttributeValue(iedServer,&iedModel_PROT_PTOC1_Health_stVal,(ucMDiscInBuf[MB_offsetError] & (MB_errorMSAI | MB_errorMSAU)));
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOC1_Health_t, currentTime);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PTOC1_Health_q,0);


	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOC1_Str_general,  ucMDiscInBuf[MB_offset_I_IO] & (1<<0));

	int16_t		Valtmp = ucMDiscInBuf[MB_offsetDirGeneral] & 0b11;
	MmsValue* ValMMS = MmsValue_newIntegerFromInt16(Valtmp);

	IedServer_updateAttributeValue(iedServer, &iedModel_PROT_PTOC1_Str_dirGeneral, ValMMS);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOC1_Str_t, currentTime);

	if (ucMDiscInBuf[MB_offsetError] & MB_errorMSAI){
		IedServer_updateQuality(iedServer,&iedModel_PROT_PTOC1_Str_q, QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	} else{
		IedServer_updateQuality(iedServer,&iedModel_PROT_PTOC1_Str_q,0);
	}
	MmsValue_delete(ValMMS);

	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOC1_Op_general,  ucMDiscInBuf[MB_offset_I_IO] & (1<<1));
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOC1_Op_t, currentTime);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PTOC1_Op_q,0);
*/

	if (ucMDiscInBuf[MB_offsetError] & MB_errorMSAU){
		// напряжения
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_res_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Hz_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

	}
	else{
		// напряжения
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsA_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsB_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsC_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_res_q,0);

		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsA_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsB_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsC_q,0);

		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Hz_q,0);
// phV
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ua],Ktn));
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ub],Ktn));
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Uc],Ktn));
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_res_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Un],ucMConfigBufall[MB_offset_Ktnnp]));

// PPV
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Uab],Ktn));
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ubc],Ktn));
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Uca],Ktn));

		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_mag_f,(float)ucMAnalogInBuf[MB_offset_Hz]/256);

	}
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsA_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsB_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsC_t, currentTime);

	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsA_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsB_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsC_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Hz_t, currentTime);
/*
// Аналоговые токовые данные
	if (ucMDiscInBuf[MB_offsetError] & MB_errorMSAI){
		// токи
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_res_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	}
	else{
		// токи
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_res_q,0);
		float CurrA;
		CurrA = (float)(ucMAnalogInBuf[MB_offset_Ia] * 40)/65536 * Ktt;
//		if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotVAZ) {CurrA = -CurrA;}
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsA_cVal_mag_f,CurrA);

		CurrA = (float)(ucMAnalogInBuf[MB_offset_Ib] * 40)/65536 * Ktt;
//		if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotVAZ) {CurrA = -CurrA;}
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsB_cVal_mag_f,CurrA);

		CurrA = (float)(ucMAnalogInBuf[MB_offset_Ic] * 40)/65536 * Ktt;
//		if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotVAZ) {CurrA = -CurrA;}
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsC_cVal_mag_f,CurrA);

		CurrA = (float)(ucMAnalogInBuf[MB_offset_In] * 5)/65536 * ucMConfigBufall[MB_offset_Kttnp];
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_res_cVal_mag_f,CurrA);

	}
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsA_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsB_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsC_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_res_t, currentTime);

    //мощность ----------------------------------------------------
	if ((ucMDiscInBuf[MB_offsetError] & MB_errorMSAU) || (ucMDiscInBuf[MB_offsetError] & MB_errorMSAI)){

		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totW_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totVAr_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totPF_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	}else{
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totW_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totVAr_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totPF_q,0);

		float CurrW;
		CurrW = (float)(ucMAnalogInBuf[MB_offset_TotW]);
		if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotWZ) {CurrW = -CurrW;}
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_mag_f,CurrW);

		CurrW = (float)(ucMAnalogInBuf[MB_offset_TotVAr]);
		if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotVAZ) {CurrW = -CurrW;}
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_mag_f,CurrW);

		CurrW = (float)ucMAnalogInBuf[MB_offset_TotPF]/256;
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_mag_f,CurrW);

	}
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totW_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totVAr_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totPF_t, currentTime);
*/
// !!Аналоговые токовые данные

/*
//CSWI
//-------------------------------

	{
	uint8_t	res=STVALCODEDENUM_INTERMEDIATE;
	if (ucMDiscInBuf[MB_offset_adr0] & MB_offsetSW_OFF) {res |= STVALCODEDENUM_OFF;}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_offsetSW_ON)  {res |= STVALCODEDENUM_ON;} 			//2 - STATE_ON ? 1- STATE_OFF ? 0 -  STATE_INTERMEDIATE

	IedServer_updateBitStrinAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_stVal, res);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Pos_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_t, currentTime);

#define MB_bOffsetErrorHard		1<<0
#define MB_bOffsetErrorLogic	1<<1
#define MB_bOffsetErrorData		1<<2

	uint32_t	res32 = STVALINT32_OK;
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorHard) 	{res32 |= STVALINT32_Alarm;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorLogic) 	{res32 |= STVALINT32_Alarm;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorData) 	{res32 |= STVALINT32_Alarm;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorSW) 		{res32 |= STVALINT32_Alarm;}
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Health_stVal, res32);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Health_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Health_t, currentTime);

	}
//XCBR
//--------------------------------
	{
	//Pos
	uint8_t	res=STVALCODEDENUM_INTERMEDIATE;
	if (ucMDiscInBuf[MB_offset_adr0] & MB_offsetSW_OFF) {res |= STVALCODEDENUM_OFF;}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_offsetSW_ON)  {res |= STVALCODEDENUM_ON;} 			//2 - STATE_ON ? 1- STATE_OFF ? 0 -  STATE_INTERMEDIATE

	IedServer_updateBitStrinAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Pos_stVal, res);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_XCBR1_Pos_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Pos_t, currentTime);

	//Loc
	bool XCBR1_Loc=0;
	if (ucMConfigBufall[MB_offset_BlockSDTU]) {XCBR1_Loc = 1;}
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Loc_stVal, XCBR1_Loc);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_XCBR1_Loc_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Loc_t, currentTime);
	}

*/
	//--------------------------------

//LEDGGIO1
//--------------------------------
 	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<8));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<9));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<10));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<11));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<12));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<13));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<14));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<15));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<5));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<4));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<6));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<7));

	// статус сброса нидикаторов
	if (ucMDiscInBuf[MB_offsetLED] & 0xFF00){
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_SPCSO1_stVal,  1);
	    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_SPCSO1_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_SPCSO1_stVal,  0);
	    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_SPCSO1_t, currentTime);

	}


    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);


    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind1_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind2_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind3_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind4_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind5_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind6_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind7_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind8_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind9_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind10_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind11_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind12_q,0);

//--------------------------------
// сброс флагов

	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetError){
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
	}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetSysNote){
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO2_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO2_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
	}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetErrorNote){
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO3_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO3_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
	}

//--------------------------------
// MSQI1
	int32_t MSQI_stval = 0;

	if (ucMDiscInBuf[MB_offsetError] & (MB_errorMRV1)) {
		MSQI_stval = 2;
	} else		MSQI_stval = 1;

	IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI1_Health_stVal,  MSQI_stval);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_Health_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_Health_t, currentTime);
   float  cXtmp;
/*
// SeqA
    cXtmp = (float)ucMAnalogInBuf[MB_offset_NI1] * 40 * Ktt / 65536;
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c1_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c1_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c1_t, currentTime);

    cXtmp = (float)ucMAnalogInBuf[MB_offset_NI2] * 40 * Ktt / 65536;
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c2_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c2_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c2_t, currentTime);

    cXtmp = (float)ucMAnalogInBuf[MB_offset_NI0] * 40 * Ktt / 65536;
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c3_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c3_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c3_t, currentTime);
*/
// SeqU
    cXtmp = (float)GetRealU(ucMAnalogInBuf[MB_offset_NU1],Ktn);
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c1_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c1_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c1_t, currentTime);

    cXtmp = (float)GetRealU(ucMAnalogInBuf[MB_offset_NU2],Ktn);
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c2_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c2_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c2_t, currentTime);

    cXtmp = (float)GetRealU(ucMAnalogInBuf[MB_offset_NU0],Ktn);
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c3_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c3_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c3_t, currentTime);

//--------------------------------

//--------------------------------
// RFLO
/*
	uint32_t	OMP;
	if (ucMConfigBufall[MB_offset_OMP] & 1){OMP=1;}	else{OMP=5;}
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Mod_stVal,  OMP);
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Beh_stVal,  OMP);

    IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Mod_q,0);
    IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Beh_q,0);

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_Mod_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_Beh_t, currentTime);

	uint32_t	err;
	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetError){err=1;}	else{err=5;}
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Health_stVal,  err);
    IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Health_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_Health_t, currentTime);


    float	fltz = (float)ucMAnalogInBuf[MB_offset_OMPLkz] * (float)ucMConfigBufall[MB_offset_OMP+1] / (float)256000;
	IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_RFLO1_Fltz_mag_f,  (float)fltz);
    IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Fltz_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_Fltz_t, currentTime);

    fltz = (float)ucMAnalogInBuf[MB_offset_OMPLkz]/(float)256;
	IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_RFLO1_FltDiskm_mag_f, fltz);
    IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_FltDiskm_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_FltDiskm_t, currentTime);
*/

//--------------------------------
    // остальные узлыузлы
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LLN0_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LLN0_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LLN0_Mod_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LPHD1_Proxy_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LPHD1_PhyHealth_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
//LEDGGIO1
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);


    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Mod_t, currentTime);


    // проверяем группу уставок
    uint8_t	currSG = 1;
    if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetSettingGr) currSG = 2;

	if (currSG != IedServer_getActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0))) {
		IedServer_changeActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0),currSG );
		USART_TRACE("Изменилась группа уставок. %u\n",iedModel_LD0_LLN0_sgcb0.actSG);
	}

	// -------------------- были ли изменения в уставках ---------------------------
    if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetSysNote) {
    	// было изменение уставок. Нужно их перечитать.
    	USART_TRACE("Изменились уставки.\n");
    	writeNmb = 9;
    	ucMDiscInBuf[MB_offset_adr0] ^= MB_bOffsetSysNote;
    }

    IedServer_unlockDataModel(iedServer);																// отдаём управление mmsServer'ом
}
//+++++++++++++++++++
		}

//		errorType = eMBMasterPoll();						// мониторим события от MODBUS.
//		if (errorType == MB_ETIMEDOUT){
//    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
//    	Port_Off(LED1);
//		}

		errorType = eMBMasterPoll();						// мониторим события от MODBUS.
		if (errorType == MB_ETIMEDOUT){
			USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
			//if (ReadNmb) ReadNmb--;
		Port_Off(LED1);
		}else
		if (errorType == MB_ENOERR){
	//			if (writeNmb == 0) ReadNmb++;
			if (writeNmb == 10) {writeNmb = 0;}
		}
		taskYIELD();										// отпустим задачу.
	}
}
#endif
/*******************************************************
 * MR5_500 MODBUS
 *******************************************************/
#if defined (MR5_500)
void StartMODBUSTask(void const * argument)
{
	extern uint64_t nextSynchTime;
	extern bool resynch;
	uint32_t			TimerReadMB;
	uint8_t				ReadNmb=0;
	eMBErrorCode		errorType;
	uint8_t				i;
	RTC_TimeTypeDef 	Time;
	uint8_t  			PerForSynch;
	extern const uint8_t userConfig[];

//	osMutexWait(xIEC850StartMutex, osWaitForever);				// забрали мьютекс для блокировки TCP пока не получим настройки IP
//	USART_TRACE_BLUE("MODBUS забрал мьютекс IEC850Start\n");

//	usMDiscInStart = MB_StartDiscreetaddr;

	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();


	Port_On(LED1);
/*
	{
		uint8_t 			HardFaultcnt;												// счетчик перезапусков
		memory_read((uint8_t *)&HardFaultcnt,_IfHardFault,sizeof(HardFaultcnt));						// читаем IP из внешней флэшки
		HardFaultcnt++;
		memory_write_to_mem((uint8_t *)&HardFaultcnt,_IfHardFault,sizeof(HardFaultcnt));
		USART_TRACE_GREEN("Число запусков: %u\n",HardFaultcnt);
	}
*/
	TimerReadMB = HAL_GetTick();
	for(;;)
	{
 //		IedServer_setControlHandler(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1, (ControlHandler)controlListener, &iedModel_GGIO_OUTGGIO1_SPCSO1);
		if (writeNmb == 10) {
		   	   		USART_TRACE_RED("Установка часов в приборе.\n");
		   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
		   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (UCHAR *)&ucMDateBuf,RT_WAITING_FOREVER);
		   	   	}
		else
		if ((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS){					// периодический опрос MODBUS с периодом MB_PerForReadMODBUS(мс)
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>14) {ReadNmb = 1;}
			if (ReadNmb>2 && ReadNmb<10) ReadNmb = 1;

			//--------------- синхронизация часов ------------------------------------
			if ((ReadNmb == 1) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = 10;			// первый раз

			//--------------- Выключатель ------------------------------------
	   	   	if (writeNmb == 1) {
	   	   		USART_TRACE_GREEN("Выключатель ON\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwON,MB_SwON,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 2) {
	   	   		USART_TRACE_RED("Выключатель OFF\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwOFF,MB_SwON,RT_WAITING_FOREVER);
	   	   	}

	   	   	if (writeNmb == 3) {
	   	   		USART_TRACE_RED("сброс индикации\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 4) {
	   	   		USART_TRACE_RED("сброс новой неисправности\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале системы \n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 6) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале аварий\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 7) {
	   	   		USART_TRACE_RED("Переключение группы уставок 0.\n");
	   	   		eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_addr_SG,MB_selectGroupe0,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 8) {
	   	   		USART_TRACE_RED("Переключение группы уставок 1.\n");
	   	   		eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_addr_SG,MB_selectGroupe1,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 9) {
	   	   		USART_TRACE_RED("Сброс записи журнала системы.\n");
	   	   	eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 10) {
	   	   		USART_TRACE_RED("Установка часов в приборе.\n");
	   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
	   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (UCHAR *)&ucMDateBuf,RT_WAITING_FOREVER);
	   	   	}
	   		uint64_t currentTime = Hal_getTimeInMs();

			//--------------- База чтения ------------------------------------
	   	   	if (writeNmb == 0){	// запись без очереди выполним.

			//--------------- синхронизация часов ------------------------------------
		    if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) {					//если прошел час то делаем синхронизацию снова
					ReadNmb = 15;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("Пересинхронизация часов. время:0x%X\n",(unsigned int)currentTime);
				}
		  	}
			// периодическое чтение
	   	   	if (ReadNmb==0)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);		// чтение ревизии устройства
	   		if (ReadNmb==1)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);
	   		if (ReadNmb==2)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);

	   		// однократное чтение
	   	   	if (ReadNmb==10) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);				// чтение текущего времени
	   	   	if (ReadNmb==11) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigStart,MB_NumbConfig,RT_WAITING_FOREVER);			// чтение уставок(только IP адрес)
	   	   	if (ReadNmb==12) {eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfig+MB_offset_Ktt,1,RT_WAITING_FOREVER);}		// чтение уставок
	   	   	if (ReadNmb==13) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfig+MB_offset_Ktn,1,RT_WAITING_FOREVER);		// чтение уставок
	   	   	if (ReadNmb==14) {
	   	   		eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfig,MB_NumbConfigall,RT_WAITING_FOREVER);		// чтение всех уставок
	   	   		osMutexRelease(xIEC850StartMutex);
	   	   	}
	   	   	ReadNmb++;
	   	   	} else{
	   	   		if (writeNmb == 9 ) ReadNmb = 10;
	   	   		writeNmb = 0;
	   	   	}
//+++++++++++++++++++
/*
	   	 		errorType = eMBMasterPoll();						// мониторим события от MODBUS.
	   	 		if (errorType == MB_ETIMEDOUT){
	   	    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
	   	     		//if (ReadNmb) ReadNmb--;
	   	     	Port_Off(LED1);
	   	 		}
*/
//+++++++++++++++++++
if(IEC850TaskHandle && (iedServer != NULL)){

            IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

if (ucMDiscInBuf[MB_offsetError] & MB_errorMSD1){
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
} else
{
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind1_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind2_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind3_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind4_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind5_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind6_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind7_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind8_q,0 | 0);

            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<0));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<1));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<2));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<3));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<4));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<5));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<6));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<7));
}
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind1_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind2_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind3_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind4_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind5_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind6_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind7_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind8_t, currentTime);

if (ucMDiscInBuf[MB_offsetError] & MB_errorMSD2){
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
} else{
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind9_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind10_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind11_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind12_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind13_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind14_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind15_q,0 | 0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_OUTGGIO1_Ind16_q,0 | 0);

            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<8));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<9));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<10));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<11));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<12));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<13));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<14));
            IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<15));

}
   	   	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind9_t, currentTime);
      	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind10_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind11_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind12_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind13_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind14_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind15_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Ind16_t, currentTime);

if (ucMDiscInBuf[MB_offsetError] & MB_errorMRV1){
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
}else{
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO1_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO2_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO3_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO4_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO5_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO6_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO7_q,0);
			IedServer_updateQuality(iedServer,&iedModel_GGIO_INGGIO1_SPCSO8_q,0);

          	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<0));
       	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<1));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<2));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<3));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<4));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<5));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<6));
      	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<7));
}
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO1_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO2_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO3_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO4_t, currentTime);
    	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO5_t, currentTime);
     	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO6_t, currentTime);
    	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO7_t, currentTime);
    	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_SPCSO8_t, currentTime);

//PTOC

    IedServer_updateInt32AttributeValue(iedServer,&iedModel_PROT_PTOC1_Health_stVal,(ucMDiscInBuf[MB_offsetError] & (MB_errorMSAI | MB_errorMSAU)));
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOC1_Health_t, currentTime);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PTOC1_Health_q,0);


	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOC1_Str_general,  ucMDiscInBuf[MB_offset_I_IO] & (1<<0));

//	int16_t		Valtmp = GetDirGeneral((ucMDiscInBuf[MB_offsetPTOC] >> 2) & 0b111111);
	int16_t		Valtmp = ucMDiscInBuf[MB_offsetDirGeneral] & 0b11;
	MmsValue* ValMMS = MmsValue_newIntegerFromInt16(Valtmp);

	IedServer_updateAttributeValue(iedServer, &iedModel_PROT_PTOC1_Str_dirGeneral, ValMMS);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOC1_Str_t, currentTime);

	if (ucMDiscInBuf[MB_offsetError] & MB_errorMSAI){
		IedServer_updateQuality(iedServer,&iedModel_PROT_PTOC1_Str_q, QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	} else{
		IedServer_updateQuality(iedServer,&iedModel_PROT_PTOC1_Str_q,0);
	}
	MmsValue_delete(ValMMS);

	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOC1_Op_general,  ucMDiscInBuf[MB_offset_I_IO] & (1<<1));
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOC1_Op_t, currentTime);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PTOC1_Op_q,0);

// Аналоговые токовые данные
	if (ucMDiscInBuf[MB_offsetError] & MB_errorMSAI){
		// токи
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_res_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	}
	else{
		// токи
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,0);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_res_q,0);
		float CurrA;
		CurrA = (float)(ucMAnalogInBuf[MB_offset_Ia] * 40)/65536 * Ktt;
//		if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotVAZ) {CurrA = -CurrA;}
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsA_cVal_mag_f,CurrA);

		CurrA = (float)(ucMAnalogInBuf[MB_offset_Ib] * 40)/65536 * Ktt;
//		if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotVAZ) {CurrA = -CurrA;}
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsB_cVal_mag_f,CurrA);

		CurrA = (float)(ucMAnalogInBuf[MB_offset_Ic] * 40)/65536 * Ktt;
//		if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotVAZ) {CurrA = -CurrA;}
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsC_cVal_mag_f,CurrA);

		CurrA = (float)(ucMAnalogInBuf[MB_offset_In] * 5)/65536 * ucMConfigBufall[MB_offset_Kttnp];
		IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_res_cVal_mag_f,CurrA);

	}
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsA_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsB_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsC_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_res_t, currentTime);

// !!Аналоговые токовые данные


//CSWI
//-------------------------------

	{
	uint8_t	res=STVALCODEDENUM_INTERMEDIATE;
	if (ucMDiscInBuf[MB_offset_adr0] & MB_offsetSW_OFF) {res |= STVALCODEDENUM_OFF;}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_offsetSW_ON)  {res |= STVALCODEDENUM_ON;} 			//2 - STATE_ON ? 1- STATE_OFF ? 0 -  STATE_INTERMEDIATE

	IedServer_updateBitStrinAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_stVal, res);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Pos_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_t, currentTime);

#define MB_bOffsetErrorHard		1<<0
#define MB_bOffsetErrorLogic	1<<1
#define MB_bOffsetErrorData		1<<2

	uint32_t	res32 = STVALINT32_OK;
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorHard) 	{res32 |= STVALINT32_Alarm;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorLogic) 	{res32 |= STVALINT32_Alarm;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorData) 	{res32 |= STVALINT32_Alarm;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorSW) 		{res32 |= STVALINT32_Alarm;}
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Health_stVal, res32);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Health_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Health_t, currentTime);

	}
//XCBR
//--------------------------------
	{
	//Pos
	uint8_t	res=STVALCODEDENUM_INTERMEDIATE;
	if (ucMDiscInBuf[MB_offset_adr0] & MB_offsetSW_OFF) {res |= STVALCODEDENUM_OFF;}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_offsetSW_ON)  {res |= STVALCODEDENUM_ON;} 			//2 - STATE_ON ? 1- STATE_OFF ? 0 -  STATE_INTERMEDIATE

	IedServer_updateBitStrinAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Pos_stVal, res);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_XCBR1_Pos_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Pos_t, currentTime);

	//Loc
	bool XCBR1_Loc=0;
	if (ucMConfigBufall[MB_offset_BlockSDTU]) {XCBR1_Loc = 1;}
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Loc_stVal, XCBR1_Loc);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_XCBR1_Loc_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Loc_t, currentTime);
	}

//	IedServer_updateInt32AttributeValue(iedServer, iedModel_CTRL_XCBR1_OpCnt_stVal,(ucMConfigBufall[MB_offset_BlockSDTU]);

	//--------------------------------

//LEDGGIO1
//--------------------------------
 	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<8));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<9));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<10));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<11));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<12));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<13));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<14));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<15));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<4));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<5));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<6));
	IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<7));

	// статус сброса нидикаторов
	if (ucMDiscInBuf[MB_offsetLED] & 0xFF00){
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_SPCSO1_stVal,  1);
	    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_SPCSO1_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_SPCSO1_stVal,  0);
	    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_SPCSO1_t, currentTime);

	}


    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);


    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind1_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind2_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind3_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind4_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind5_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind6_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind7_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind8_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind9_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind10_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind11_q,0);
    IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Ind12_q,0);

//--------------------------------
// сброс флагов

	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetError){
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
	}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetSysNote){
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO2_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO2_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
	}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetErrorNote){
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO3_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0);
	    IedServer_updateQuality(iedServer,&iedModel_CTRL_GGIO1_SPCSO3_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
	}

//--------------------------------
// MSQI1
	int32_t MSQI_stval = 0;

	if (ucMDiscInBuf[MB_offsetError] & (MB_errorMRV1|MB_errorMSAI)) {
		MSQI_stval = 2;
	} else		MSQI_stval = 1;

	IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI1_Health_stVal,  MSQI_stval);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_Health_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_Health_t, currentTime);

// SeqA
    float	cXtmp = (float)ucMAnalogInBuf[MB_offset_NI1] * 40 * Ktt / 65536;
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c1_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c1_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c1_t, currentTime);

    cXtmp = (float)ucMAnalogInBuf[MB_offset_NI2] * 40 * Ktt / 65536;
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c2_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c2_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c2_t, currentTime);

    cXtmp = (float)ucMAnalogInBuf[MB_offset_NI0] * 40 * Ktt / 65536;
    IedServer_updateFloatAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c3_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c3_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c3_t, currentTime);

//--------------------------------
    // остальные узлыузлы
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LLN0_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LLN0_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LLN0_Mod_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LPHD1_Proxy_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LPHD1_PhyHealth_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
//LEDGGIO1
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);


    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Mod_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOC1_Mod_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOC1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOC1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOC1_Str_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOC1_Op_t, currentTime);


    // проверяем группу уставок
    uint8_t	currSG = 1;
    if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetSettingGr) currSG = 2;

	if (currSG != IedServer_getActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0))) {
		IedServer_changeActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0),currSG );
		USART_TRACE("Изменилась группа уставок. %u\n",iedModel_LD0_LLN0_sgcb0.actSG);
	}

	// -------------------- были ли изменения в уставках ---------------------------
    if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetSysNote) {
    	// было изменение уставок. Нужно их перечитать.
    	USART_TRACE("Изменились уставки.\n");
    	writeNmb = 9;
    	ucMDiscInBuf[MB_offset_adr0] ^= MB_bOffsetSysNote;
    }


    IedServer_unlockDataModel(iedServer);																// отдаём управление mmsServer'ом
}
//+++++++++++++++++++
		}

		// перенёс в начало
//		errorType = eMBMasterPoll();						// мониторим события от MODBUS.
//		if (errorType == MB_ETIMEDOUT){
//   		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
//    		//if (ReadNmb) ReadNmb--;
//    	Port_Off(LED1);
//		}

		errorType = eMBMasterPoll();						// мониторим события от MODBUS.
		if (errorType == MB_ETIMEDOUT){
    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
    		//if (ReadNmb) ReadNmb--;
    	Port_Off(LED1);
		}else
		if (errorType == MB_ENOERR){
//			if (writeNmb == 0) ReadNmb++;
			if (writeNmb == 10) {writeNmb = 0;}
		}

		taskYIELD();										// отпустим задачу.
	}
}
#endif


/*************************************************************************
 * GetRealP
 * ktn - коэффициент ТН прочитанные из таблицы уставок 0x1009
 *************************************************************************/
float		GetRealP(float	Currdata, uint16_t	ktn,  uint16_t	Ittf){

float	realP = 0;
float	K;

	if(ktn & 1<<15){
		K = ( ((float)ktn - (float)32768)* (float)1000) /(float)256;
	} else{
		K = (float)ktn/(float)256;
	}
	realP = (float)Currdata/65536*Ittf*K*1.25;

return	realP;
}

/*************************************************************************
 * Управление выключателем
 *************************************************************************/
void	CSWI_Pos_Oper_Set(bool newState, uint64_t timeStamp){
#if defined (MR771)
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal, newState);
    if (newState) writeNmb = 1; else writeNmb = 2;
#endif
/*************************************************************************
 * MR761 MR762 MR763
 *************************************************************************/
#if defined (MR761) || defined (MR762) || defined (MR763)
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal, newState);
    if (newState) writeNmb = 1; else writeNmb = 2;
#endif
#if defined (MR801)
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal, newState);
    if (newState) writeNmb = 1; else writeNmb = 2;
#endif
#if defined (MR901)
#endif
#if defined (MR902)
#endif
#if defined (MR5_700)
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    IedS&iedModel_ateBooleanAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal, newState);
    if (newState) writeNmb = 1; else writeNmb = 2;
#endif
#if defined (MR5_500)
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal, newState);
    if (newState) writeNmb = 1; else writeNmb = 2;
#endif
}

/*************************************************************************
 * Команды сброса флагов и индикации
 *************************************************************************/
void	GGIO_LEDGGIO1_SPCSO1_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_ctlVal, 0);
    if (newState) writeNmb = 3; //else writeNmb = 2;

}

void	GGIO_SPCSO1_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal, 0);
    if (newState) writeNmb = 4; //else writeNmb = 2;

}
void	GGIO_SPCSO2_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal, 0);
    if (newState) writeNmb = 5; //else writeNmb = 2;

}
void	GGIO_SPCSO3_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal, 0);
    if (newState) writeNmb = 6; //else writeNmb = 2;

}
