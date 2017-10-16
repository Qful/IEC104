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
#if defined (MR851)
#include "static_model_MR851.h"
#endif
#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"
#endif

#include "datatoPTOC.h"					// ����������� ������ � PTOC
#include "datatoPTOV.h"					// ����������� ������ � PTOV PTUV
#include "datatoPTOF.h"					// ����������� ������ � PTOF PTUF
#include "datatoGGIO.h"					// ����������� ������ �
#include "datatoPDIF.h"					// ����������� ������ �
#include "datatoPDIS.h"
#include "datatoPTTR.h"
#include "datatoRREC.h"					// ����������� ������ �
#include "datatoCSWI.h"					// ����������� ������ �
#include "datatoPTRC.h"					// ����������� ������ �
#include "datatoMMXU.h"
#include "datatoMSQI.h"
#include "datatoRFLO.h"
#include "datatoPDPR.h"
#include "datatoATTC.h"
#include "datatoLLN0LPHD.h"
#include "datatoSG.h"					// ��������� ������ �������
/*Modbus includes ------------------------------------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbport.h"
#include "modbus.h"

/*������ SPI -----------------------------------------------------------------*/
#include "ExtSPImem.h"

/*���������� ������� �� USART ------------------------------------------------*/
#include "DebugConsole.h"

/* HTTP ������ ��� ���������� �������� ---------------------------------------*/
#include "httpServer.h"

/* NTP ������  ---------------------------------------*/
#include "sntpclient.h"


/* define --------------------------------------------------------------------*/
#define DEBUG_CONSOLE_STACK_SIZE		( configMINIMAL_STACK_SIZE * 4 )		// configMINIMAL_STACK_SIZE * 4 * N = 3072�����			// * 4 ������ ��� 32 ���� ����  ���� 5 11.07.2016
#define DEBUG_CONSOLE_TASK_PRIORITY		osPriorityAboveNormal//osPriorityNormal

#define IEC850_STACK_SIZE				( configMINIMAL_STACK_SIZE * 10 )		// 3072�����			configMINIMAL_STACK_SIZE * 7		8- 05122016 12-30012017 ������
#define IEC850Task__PRIORITY			osPriorityHigh//osPriorityNormal//osPriorityAboveNormal

#define	MODBUSTask_STACK_SIZE			( configMINIMAL_STACK_SIZE * 4 )		// 1024�����			onfigMINIMAL_STACK_SIZE * 2
#define MODBUSTask__PRIORITY			osPriorityAboveNormal//osPriorityBelowNormal//osPriorityNormal

#define	HTTPTask_STACK_SIZE				( configMINIMAL_STACK_SIZE * 4 )		// 1024�����			onfigMINIMAL_STACK_SIZE * 2
#define HTTPTask__PRIORITY				osPriorityNormal

#define DEBUG_USARTOUT_STACK_SIZE		( configMINIMAL_STACK_SIZE * 4 )
#define DEBUG_USARTOUT_TASK_PRIORITY	osPriorityRealtime


/* Variables -----------------------------------------------------------------*/
extern uint16_t	GLOBAL_QUALITY;
// �������� -----------------------------
static xSemaphoreHandle xConsoleMutex = NULL;			// ������� ������ � �������

osMutexId xIEC850StartMutex;		// ������� ���������� � ������� TCP/IP
osMutexDef(xIEC850StartMutex);

osMutexId xIEC850ServerStartMutex;		// ������� ���������� � ������� TCP/IP
osMutexDef(xIEC850ServerStartMutex);

extern IedServer 	iedServer;
extern uint16_t		SNTP_Period;
extern int16_t		lostSNTPPackets;


extern uint64_t 	nextSynchTime;
extern bool 		resynch;
extern bool		getJurnals;
// ���������� ��������� ��� ������ ������ ������� MODBUS
	typedef struct					// ��� �������� ����� ������� ��������.
	{
	  MBFrame	MBData;
	  uint8_t 	Source;
	} xData;

// ������� -----------------------------
xQueueHandle 	ModbusSentTime;		// ������� ��� �������� � ������
xQueueHandle 	ModbusSentQueue;		// ������� ��� �������� � ������

xQueueHandle 	Rd_SysNoteQueue;		// ������� ��� �������� ������� �������
xQueueHandle 	Rd_ErrorNoteQueue;		// ������� ��� �������� ������� ������
xQueueHandle 	Rd_FileQueue;			// ������� ��� �������� ������
xQueueHandle 	Rd_UstavkiQueue;		// ������� ��� �������� �������

xQueueHandle	xDebugUsartOut;			// ������� ��� �������� � ����������


osThreadId defaultTaskHandle;
osThreadId IEC850TaskHandle;
osThreadId MBUSTaskHandle;
osThreadId CONSOLETaskHandle;
osThreadId DEBUGUSARTOUTTaskHandle;


extern 	RTC_HandleTypeDef hrtc;

//  --------------------------------------------------------------------------------
bool				IP_ready = false;
bool				SetTimeNow = false;
bool				Reset_SysNoteNow = false;

int8_t				Nextread = 0;
volatile  uint8_t	ReadNmb=0;
uint16_t			NumbBlokReadMB = 0;	// �����
uint8_t				writeNmb;
uint8_t	  			writeNmbSG;			// ����� ������ �������.

uint16_t			GlobalAddrSysNote=0;
uint16_t			GlobalAddrErrorNote=0;
errMB_data			cntErrorMD;
//Master mode: ���� ������
//Master mode: ���� ������ ������������ �������

#if defined (MR5_700)

extern uint16_t   ucErrorNoteBuf[MB_NumbErrorNote];
extern uint16_t   ucSysNoteBuf[MB_NumbSysNote];
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucSWCrash[MB_NumbSWCrash];
extern uint16_t   ucConfigBufSW[MB_NumbConfigSW];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucAutomatBuf[MB_NumbAutomat];
extern uint16_t   ucOutSignalBuf[MB_NumbConfigOut];
extern uint16_t   ucSystemCfgBuf[MB_NumbSystemCfg];
extern uint16_t   ucConfigBufExZ[MB_NumbConfigExZ];
extern uint16_t   ucConfigBufMTZ[MB_NumbConfigMTZ];
extern uint16_t   ucConfigBufI2I1I0[MB_NumbConfigI2I1I0];
extern uint16_t   ucConfigBufF[MB_NumbConfigF];
extern uint16_t   ucConfigBufU[MB_NumbConfigU];

// ������ ������ -----------------------
extern uint16_t   usErrorNoteStart;
extern uint16_t   usSysNoteStart;
extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigStartSWCrash;	// ������ �����������
extern uint16_t   usConfigStartSW;			// ������������ �����������
extern uint16_t   usConfigUstavkiStart;		// ����� �������
extern uint16_t   usConfigAutomatStart;		// ��������� ����������
extern uint16_t   usConfigOutStart;			// ������ ������������ �������� ��������
extern uint16_t   usSystemCfgStart;			// ��������� �������
extern uint16_t   usConfigStartExZ;			// ������������ ������� �����
extern uint16_t   usConfigStartMTZ;			// ������������ ������� �����
extern uint16_t   usConfigStartI2I1I0;		// ������������ �������������� ������
extern uint16_t   usConfigStartF;			// ������������ ������ �� �������
extern uint16_t   usConfigStartU;			// ������������ ������ �� ����������

#endif
#if defined (MR5_600)

extern uint16_t   ucErrorNoteBuf[MB_NumbErrorNote];
extern uint16_t   ucSysNoteBuf[MB_NumbSysNote];
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucOutSignalBuf[MB_NumbConfigOut];
extern uint16_t   ucSystemCfgBuf[MB_NumbSystemCfg];
extern uint16_t   ucConfigBufExZ[MB_NumbConfigExZ];
extern uint16_t   ucConfigBufF[MB_NumbConfigF];
extern uint16_t   ucConfigBufU[MB_NumbConfigU];

// ������ ������ -----------------------
extern uint16_t   usErrorNoteStart;
extern uint16_t   usSysNoteStart;
extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigStartSWCrash;	// ������ �����������
extern uint16_t   usConfigStartSW;			// ������������ �����������
extern uint16_t   usConfigUstavkiStart;		// ����� �������
extern uint16_t   usConfigAutomatStart;		// ��������� ����������
extern uint16_t   usConfigOutStart;			// ������ ������������ �������� ��������
extern uint16_t   usSystemCfgStart;			// ��������� �������
extern uint16_t   usConfigStartExZ;			// ������������ ������� �����
extern uint16_t   usConfigStartMTZ;			// ������������ ������� �����
extern uint16_t   usConfigStartI2I1I0;		// ������������ �������������� ������
extern uint16_t   usConfigStartF;			// ������������ ������ �� �������
extern uint16_t   usConfigStartU;			// ������������ ������ �� ����������

#endif
#if defined (MR5_500)

extern uint16_t   ucErrorNoteBuf[MB_NumbErrorNote];
extern uint16_t   ucSysNoteBuf[MB_NumbSysNote];
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucSWCrash[MB_NumbSWCrash];
extern uint16_t   ucConfigBufSW[MB_NumbConfigSW];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucAutomatBuf[MB_NumbAutomat];
extern uint16_t   ucOutSignalBuf[MB_NumbConfigOut];
extern uint16_t   ucSystemCfgBuf[MB_NumbSystemCfg];
extern uint16_t   ucConfigBufExZ[MB_NumbConfigExZ];
extern uint16_t   ucConfigBufMTZ[MB_NumbConfigMTZ];
extern uint16_t   ucConfigBufI2I1I0[MB_NumbConfigI2I1I0];

// ������ ������ -----------------------
extern uint16_t   usErrorNoteStart;
extern uint16_t   usSysNoteStart;
extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigStartSWCrash;	// ������ �����������
extern uint16_t   usConfigStartSW;			// ������������ �����������
extern uint16_t   usConfigUstavkiStart;		// ����� �������
extern uint16_t   usConfigAutomatStart;		// ��������� ����������
extern uint16_t   usConfigOutStart;			// ������ ������������ �������� ��������
extern uint16_t   usSystemCfgStart;			// ��������� �������
extern uint16_t   usConfigStartExZ;			// ������������ ������� �����
extern uint16_t   usConfigStartMTZ;			// ������������ ������� �����
extern uint16_t   usConfigStartI2I1I0;		// ������������ �������������� ������

#endif

#if defined (MR771)

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usMConfigStartSW;
extern uint16_t   usConfigUstavkiStart;			// ������ �������
extern uint16_t   usConfigAutomatStart;			// ��������� ����������
extern uint16_t   usConfigVLSInStart;			// ������ ������������ ������� ���������� ��������
extern uint16_t   usConfigVLSOutStart;			// ������ ������������ �������� ���������� ��������
extern uint16_t   usConfigAPWStart;				// ������������ ���
extern uint16_t   usSystemCfgStart;				// ��������� �������
extern uint16_t   usConfigTRMeasStart;			// ������������ �������������� ������
extern uint16_t   usSGStart;					// ��������� ������ �������
extern uint16_t   usSWCntStart;					// ������ �����������


extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucSGBuf[MB_NumbSG];
extern uint16_t   ucSWCNTBuf[MB_NumbSw_CNT];
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
extern uint16_t   usConfigUstavkiStart;			// ������ �������
extern uint16_t   usConfigAutomatStart;			// ��������� ����������
extern uint16_t   usConfigVLSInStart;			// ������ ������������ ������� ���������� ��������
extern uint16_t   usConfigVLSOutStart;			// ������ ������������ �������� ���������� ��������
extern uint16_t   usConfigAPWStart;				// ������������ ���
extern uint16_t   usSystemCfgStart;				// ��������� �������
extern uint16_t   usConfigTRMeasStart;			// ������������ �������������� ������
extern uint16_t   usSGStart;					// ��������� ������ �������
extern uint16_t   usSWCntStart;					// ������ �����������


extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucSGBuf[MB_NumbSG];
extern uint16_t   ucSWCNTBuf[MB_NumbSw_CNT];

#endif
#if defined (MR801)

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usMConfigStartSW;
extern uint16_t   usConfigUstavkiStart;			// ������ �������
extern uint16_t   usConfigAutomatStart;			// ��������� ����������
extern uint16_t   usConfigVLSInStart;			// ������ ������������ ������� ���������� ��������
extern uint16_t   usConfigVLSOutStart;			// ������ ������������ �������� ���������� ��������
extern uint16_t   usConfigAPWStart;				// ������������ ���
extern uint16_t   usConfigAWRStart;				// ������������ ���
extern uint16_t   usSystemCfgStart;				// ��������� �������
extern uint16_t   usConfigTRMeasStart;			// ������������ �������������� ������
extern uint16_t   usConfigTRPWRStart;			// ������������ �������� ������
extern uint16_t   usSWCntStart;					// ������ �����������


extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucSWCNTBuf[MB_NumbSw_CNT];

#endif
#if defined (MR851)

extern uint16_t   ucMDateBuf[MB_NumbDate];

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigUstavkiStart;			// ������ �������
extern uint16_t   usSystemCfgStart;				// ��������� �������
extern uint16_t   usRPNStart;

#endif
#if defined (MR901) || defined (MR902)

extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];

extern uint16_t   usConfigOtherUstavkiStart;			// ������ ����� �������
extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigUstavkiStart;			// ������ �������
extern uint16_t   usConfigAutomatStart;			// ��������� ����������
extern uint16_t   usSystemCfgStart;				// ��������� �������
extern uint16_t   usConfigTRMeasStart;			// ������������ �������������� ������

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
extern volatile uint8_t	MAC_ADDR[6];


float		GetRealP(float	Currdata, uint16_t	ktn,  uint16_t	Ittf);
void 		StartTimersTask(void const * argument);
void 		StartMODBUSTask(void const * argument);
void 		FREERTOS_Init(void);
extern void vRegisterDEBUGCommands( void );

void 		FastMODBUSTask(void const * argument);

/* Hook prototypes */

void ReStartIEC850_task(void) {

	USART_TRACE_BLUE("�������. \n");
	NVIC_SystemReset();

}
/*************************************************************************
 * FREERTOS_Init
 *************************************************************************/
void FREERTOS_Init(void) {
 size_t	fre,fre_pr;
 /* BEGIN RTOS_MUTEX */
	// �������� ������� ��� ���������� ������� � �������
	xConsoleMutex = osMutexCreate(NULL);

	// �������� ������� ��� ���������� ������� � TCP/IP �����
	xIEC850StartMutex = osMutexCreate(NULL);
	// �������� ������� ��� ���������� ������� � ������ �������
	xIEC850ServerStartMutex = osMutexCreate(NULL);

	osMutexWait(xIEC850StartMutex,0);					// ������� �������
	osMutexWait(xIEC850ServerStartMutex,0);				// ������� �������

  /* END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
//	vSemaphoreCreateBinary( xBinarySemaphore );			//��������� �������� �������
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */



	fre = xPortGetFreeHeapSize();			// ������ ����
	fre_pr = fre;
	USART_TRACE("������ ����:%u ����\n",fre);

	osThreadDef(ModBUS, FastMODBUSTask, MODBUSTask__PRIORITY ,0, MODBUSTask_STACK_SIZE);//	������ ������ �������
	MBUSTaskHandle = osThreadCreate(osThread(ModBUS), NULL);

//	osThreadDef(MBUS, StartMODBUSTask, MODBUSTask__PRIORITY ,0, MODBUSTask_STACK_SIZE);//256
//	MBUSTaskHandle = osThreadCreate(osThread(MBUS), NULL);

	osThreadDef(IEC850, StartIEC850Task,IEC850Task__PRIORITY,0, IEC850_STACK_SIZE);//1024		//1500 �������� IEC850Task__PRIORITY
	IEC850TaskHandle = osThreadCreate(osThread(IEC850), NULL);

	// ������ ������, ������� ��������� ������� � ������� USART �����.
//	osThreadDef(CONSOLE, DEBUGConsoleTask, DEBUG_CONSOLE_TASK_PRIORITY ,0, DEBUG_CONSOLE_STACK_SIZE);
//	CONSOLETaskHandle = osThreadCreate(osThread(CONSOLE), NULL);
	// ������������ ������� �������
//	vRegisterDEBUGCommands();


//	osThreadDef(DEBUG_OUT, DEBUGUSARTOUTTask, DEBUG_USARTOUT_TASK_PRIORITY ,0, DEBUG_USARTOUT_STACK_SIZE);
//	DEBUGUSARTOUTTaskHandle = osThreadCreate(osThread(DEBUG_OUT), NULL);

//	osThreadDef(HTTP, StartHTTPTask, HTTPTask__PRIORITY ,0, HTTPTask_STACK_SIZE);
//	MBUSTaskHandle = osThreadCreate(osThread(HTTP), NULL);

 //  fre = xPortGetFreeHeapSize();
 //  USART_TRACE("���� IEC850:%u ����\n",fre_pr - fre);
 //  fre_pr = fre;

/*
  osThreadDef(IEC104, StartIEC104Task, osPriorityAboveNormal,0, 640);//1024
  defaultTaskHandle = osThreadCreate(osThread(IEC104), NULL);
  fre = xPortGetFreeHeapSize();
  USART_TRACE("FreeHeap(IEC104):%u\n",fre);

  // �������� ���� ������ ����� IEC104. ������� ����� ������ ���
  if (defaultTaskHandle)
  {
	  osThreadDef(Timers, StartTimersTask, osPriorityNormal,0, 128);//128
	  defaultTaskHandle = osThreadCreate(osThread(Timers), NULL);

	  fre = xPortGetFreeHeapSize();
	  USART_TRACE("FreeHeap(Timers):%u\n",fre);
  }
*/

//  fre = xPortGetFreeHeapSize();
//  USART_TRACE("���� MBUS:%u ����\n",fre_pr - fre);
//  fre_pr = fre;

 //   fre = xPortGetFreeHeapSize();			// ������ ����
//   USART_TRACE("���� CONSOLE:%u ����\n",fre_pr - fre);
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
   USART_TRACE("�������� %u ����\n",fre);

  /* USER CODE END RTOS_QUEUES */
}

/*************************************************************************
 * MR801
 *************************************************************************/
#if defined (MR801)
void StartMODBUSTask(void const * argument)
{
	uint16_t			NumbBlokReadMBLim=0;
	uint16_t			SizeBlokReadMB = MaxSizeBlok;			// ������ ������ ������
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
   	   		USART_TRACE_GREEN("1.��������� ����� � �������.\n");
   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
   	   	}
   	   	else
		if (((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS)||(Nextread)){		// ������������� ����� MODBUS � �������� MB_PerForReadMODBUS(��)
			Nextread = false;
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>2 && ReadNmb<10)ReadNmb = 1;

			//--------------- ������������� ����� ------------------------------------
			if ((ReadNmb == 1) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = 10;			// ������ ���

			//--------------- ����������� ------------------------------------
	   	   	if (writeNmb == 1) {
	   	   		USART_TRACE_GREEN("����������� ON\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwON,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 2) {
	   	   		USART_TRACE_RED("����������� OFF\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwOFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}

	   	   	if (writeNmb == 3) {
	   	   		USART_TRACE_RED("����� ���������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 4) {
	   	   		USART_TRACE_RED("����� ����� �������������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������� \n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 6) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 7) {
	   	   		USART_TRACE_RED("������������ ������ ������� 0.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SGroupe0,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 8) {
	   	   		USART_TRACE_RED("������������ ������ ������� 1.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SGroupe1,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 9) {
	   	   		USART_TRACE_RED("����� ������ ������� �������.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 10) {
	   	   		USART_TRACE_GREEN("2.��������� ����� � �������.\n");
	   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
	   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
	   	   	}
	   		currentTime = Hal_getTimeInMs();

			//--------------- ���� ������ -----------------------------------------
	   	   	if (writeNmb == 0){	// ������ ��� ������� ��������.
				Port_Off(LED_out_GREEN);
			//--------------- ������������� ����� ������ ���� �� �������� NTP -----
	   	     if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) {					//���� ������ ��� �� ������ ������������� �����
					ReadNmb = LimitRead;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("����������������� �����. �����:0x%X\n",(unsigned int)currentTime);
				}
	   	     }
			// ������� ����� ������ ������ ��� ������ �� ������� ��������, �������� ���� ������� ������
			if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG0) && ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG1) == 0))
					usConfigUstavkiStart = MB_StartUstavkiaddr0;
			 else	usConfigUstavkiStart = MB_StartUstavkiaddr1;



			// ������������� ������
	   	   	if (ReadNmb==0)  		eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);					// ������ ������� ����������
	   	   	else if (ReadNmb==1)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// ������ ���������� ����
	   	   	else if (ReadNmb==2) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);				// ������ ���������� ����

	   		// ����������� ������
	   	   	else if (ReadNmb==10)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// ������ ���������� ����
	   	   	else if (ReadNmb==11) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);						// ������ �������� �������
	   	   	else if (ReadNmb==12) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSystemCfgStart,MB_NumbSystemCfg,RT_WAITING_FOREVER);				// ������ ������������ �������
	   	   	else if (ReadNmb==13) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSWCntStart,MB_NumbSw_CNT,RT_WAITING_FOREVER);					// ������ ������� �����������
	   	   	else if (ReadNmb==14) 	ReadNmb = 19;	// ������� � 20

	   	  	else if (ReadNmb==20) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigStartSW,MB_NumbConfigSW,RT_WAITING_FOREVER);}				// ������ ������������ �����������
	   	  	else if (ReadNmb==21) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAPWStart,MB_NumbConfigAPW,RT_WAITING_FOREVER);}			// ������ ������������ ���
	   	  	else if (ReadNmb==22) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAWRStart,MB_NumbConfigAWR,RT_WAITING_FOREVER);}			// ������ ������������ ���+���
	   	  	else if (ReadNmb==23) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRPWRStart,MB_NumbConfigTRPWR,RT_WAITING_FOREVER);}		// ������ ���� ������� �������� ������
	   	  	else if (ReadNmb==24) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRMeasStart,MB_NumbConfigTRMeas,RT_WAITING_FOREVER);}		// ������ ���� ������� �������������� ������
	   	  	else if (ReadNmb==25) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfigVLSIn,MB_NumbConfigVLSIn,RT_WAITING_FOREVER);}		// ������ ������������ ������� ���������� ��������
	   	  	else if (ReadNmb==26) {																													// ������ ������������ �������� ���������� ��������

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
	   					   USART_TRACE_BLUE("%u-%u:������:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
	   					   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
	   	  				}

	   	  			}
	   	  	else if (ReadNmb==27) {																													// ������ �������� ��� ��������� ������ �������

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
						   USART_TRACE_BLUE("%u-%u:������:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
						   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
					  }

	   	  			}
	   	  	else if (ReadNmb==28) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAutomatStart,MB_NumbAutomat,RT_WAITING_FOREVER);}			// ������ ���������� ����������
	   	  	else {ReadNmb++;}

//	   	 ReadNmb = 29;
	   	   	LimitRead = 29;
	   	   	if (ReadNmb >= LimitRead) { ReadNmb = 1; osMutexRelease(xIEC850StartMutex);}
	   	   	if (IP_ready) {osMutexRelease(xIEC850StartMutex);}

	   	   	} else{
	   	   		if (writeNmb == 9 ) ReadNmb = 10;			// ���� ���� ������ � ������� ������ �� ���� ��������� �������. ����� ��� ����������.
	   	   		writeNmb = 0;
	   	   	}
/*******************************************************
 * ��������� ������������ ������� ���������
 *******************************************************/
			if(IEC850TaskHandle && (iedServer != NULL)){
				IedServer_lockDataModel(iedServer);																	// ����������� ���������� mmsServer'��

// LLN0 Health --------
					Set_LLN0(1,currentTime);
// PROT_IPTOC1..8 ------						������ �� ��������� ����
					Set_IPTOC(8,currentTime);
// PROT_I20PTOC1..6 ------						������ �� ��������� �� ����� � ��������� ���� �������� ������������������
					Set_I20PTOC(6,currentTime);
// PROT_UPTOV1..4 ------						������ �� ��������� ����������
					Set_UPTOV(4,currentTime);
// PROT_UPTUV1..4 ------						������ �� ��������� ����������
					Set_UPTUV(4,currentTime);
// PROT_UPTOF1..4 ------						������ �� ��������� �������
					Set_PTOF(4,currentTime);
// PROT_UPTUF1..4 ------						������ �� ��������� �������
					Set_PTUF(4,currentTime);
// PROT_VZGGIO1..16 ------						������� ������
					Set_VZGGIO(16,currentTime);
// PROT_IDPDIF ------							���� ������
					Set_IDPDIF(1,currentTime);
// PROT_IDDPDIF ------							���� ������
					Set_IDDPDIF(1,currentTime);
// PROT_IDDMPDIF ------							���� ������
					Set_IDDMPDIF(1,currentTime);
// PROT_ID0PDIF ------							���� ������
					Set_ID0PDIF(3,currentTime);
// PROT_RREC ------
					Set_RREC(1,currentTime);
// PROT_AVRGGIO ------
					Set_AVRGGIO(1,currentTime);
// PROT_LZSHPTOC ------									���
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
		errorType = eMBMasterPoll();						// ��������� ������� �� MODBUS.
		if (errorType == MB_ETIMEDOUT){
    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
			Port_On(LED_out_RED);
//    		ReadNmb++;
			GLOBAL_QUALITY =  QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
    		Port_Off(LED1);
		}else
		if (errorType == MB_ENOERR || errorType == MB_ESENT){
			if (writeNmb == 10) {writeNmb = 0;}
//	   		USART_TRACE_RED("MB_ENOERR: %u\n",ReadNmb);
		}else
		if (errorType == MB_ERECVDATA){
			Port_On(LED_out_GREEN);
			Port_Off(LED_out_RED);
			GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
//			vTaskDelay(5);									// ������ �����, �� �������� ������� ������.
			Nextread = true;
		}


		taskYIELD();										// �������� ������.
	}
}
#endif
/*******************************************************
 * MR851
 *******************************************************/
#if defined	(MR851)
void StartMODBUSTask(void const * argument)
{
	uint16_t			NumbBlokReadMBLim=0;
	uint16_t			SizeBlokReadMB = MaxSizeBlok;			// ������ ������ ������
	uint16_t			addrConfig;

	uint8_t				LimitRead=0xFE;
	uint32_t			TimerReadMB;
	eMBErrorCode		errorType;
	uint64_t 			currentTime;
	RTC_TimeTypeDef 	Time;


	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();

	cntErrorMD.errAnalog = 0;
	cntErrorMD.errDiscreet = 0;
	writeNmb = 0;
	ReadNmb = 0;

	Port_On(LED1);

	TimerReadMB = HAL_GetTick();

	for(;;)
	{
   	   	if (writeNmb == 10) {
   	   		USART_TRACE_GREEN("1.��������� ����� � �������.\n");
   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
   	   	}
   	   	else
		if (((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS)||(Nextread)){		// ������������� ����� MODBUS � �������� MB_PerForReadMODBUS(��)
			Nextread = false;
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>3 && ReadNmb<10)ReadNmb = 1;

			//--------------- ������������� ����� ------------------------------------
			if ((ReadNmb == 1) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = 10;			// ������ ���

			//--------------- ����������� ------------------------------------

	   	   	if (writeNmb == MB_Wr_Set_ExtMode) {
	   	   		USART_TRACE_RED("���. ����. �����\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Set_ExtMode,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_LEDS_OFF) {
	   	   		USART_TRACE_RED("����� ���������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_Error_OFF) {
	   	   		USART_TRACE_RED("����� ����� �������������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_SysNote_OFF) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������� \n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_BLK_OFF) {
	   	   		USART_TRACE_RED("����� ����������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_BLK_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_DRIVE_UP) {
	   	   		USART_TRACE_RED("������: ���������.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_DRIVE_UP,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_DRIVE_DWN) {
	   	   		USART_TRACE_RED("������: �������.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_DRIVE_DWN,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_Clr_ExtMode) {
	   	   		USART_TRACE_RED("����� ����. �����\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Clr_ExtMode,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_Set_Time) {
	   	   		USART_TRACE_GREEN("2.��������� ����� � �������.\n");
	   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
	   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
	   	   	}
	   		currentTime = Hal_getTimeInMs();

			//--------------- ���� ������ -----------------------------------------
	   	   	if (writeNmb == 0){	// ������ ��� ������� ��������.
				Port_Off(LED_out_GREEN);
			//--------------- ������������� ����� ������ ���� �� �������� NTP -----
	   	     if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) {					//���� ������ ��� �� ������ ������������� �����
					ReadNmb = LimitRead;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("����������������� �����. �����:0x%X\n",(unsigned int)currentTime);
				}
	   	     }


			// ������������� ������
	   	   	if (ReadNmb==0)  		eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);					// ������ ������� ����������
	   	   	else if (ReadNmb==1)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// ������ ���������� ����
	   	   	else if (ReadNmb==2) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);				// ������ ���������� ����
	   	   	else if (ReadNmb==3) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usRPNStart,MB_NumbRPN,RT_WAITING_FOREVER);							// ������ ���� �������

	   		// ����������� ������
//	   	   	else if (ReadNmb==10)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// ������ ���������� ����
	   	   	else if (ReadNmb==10) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);						// ������ �������� �������
	   	   	else if (ReadNmb==11) {	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSystemCfgStart,MB_NumbSystemCfg,RT_WAITING_FOREVER);	NumbBlokReadMB = 0;}			// ������ ������������ �������
	   	  	else if (ReadNmb==12) {																													// ������ �������� ��� ��������� ������ �������

						//if (NumbBlokReadMBLim == 0) NumbBlokReadMB = 0;

						NumbBlokReadMBLim = (uint16_t)MB_NumbUstavki;
						NumbBlokReadMBLim = NumbBlokReadMBLim/(uint16_t)MaxSizeBlok;

						addrConfig = usConfigUstavkiStart + NumbBlokReadMB * MaxSizeBlok;

						if (NumbBlokReadMB == NumbBlokReadMBLim){
							SizeBlokReadMB = (uint16_t)MB_NumbUstavki;
							SizeBlokReadMB = SizeBlokReadMB % (uint16_t)MaxSizeBlok;

							//ReadNmb++; // ��������� �������� ��������� ������ � ������
						}

						if (NumbBlokReadMB > NumbBlokReadMBLim){
							addrConfig = 0;
						NumbBlokReadMB = 0;
						NumbBlokReadMBLim = 0;
						SizeBlokReadMB = MaxSizeBlok;
						ReadNmb++;
						} else
						if(SizeBlokReadMB) {
						   USART_TRACE_BLUE("%u-%u:������:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
						   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
					  }

	   	  			}	   	   	else {ReadNmb++;}

	   	   	LimitRead = 13;
	   	   	if (ReadNmb >= LimitRead) { ReadNmb = 1; osMutexRelease(xIEC850StartMutex);}
	   	   	if (IP_ready) {osMutexRelease(xIEC850StartMutex);}
	   	   	} else{
	   	   		if (writeNmb == MB_Wr_SysNote_OFF ) ReadNmb = 10;			// ���� ���� ������ � ������� ������ �� ���� ��������� �������. ����� ��� ����������.
	   	   		writeNmb = 0;
	   	   	}
/*******************************************************
 * ��������� ������������ ������� ���������
 *******************************************************/
			if(IEC850TaskHandle && (iedServer != NULL)){
				IedServer_lockDataModel(iedServer);																	// ����������� ���������� mmsServer'��

// RPN_LLN0 Health --------
					Set_LLN0(1,currentTime);
// RPN_ATCC ------
					Set_ATCC(1,currentTime);

// CTRL_GGIO ------
					Set_XCBRGGIO(1,currentTime);


// GGIO_IN24GGIO ------
					Set_INGGIO(16,currentTime);
					Set_OUTGGIO(15,currentTime);
					Set_LEDGGIO(12,currentTime);

// LD0 SG
					Set_SG(0,currentTime);

				IedServer_unlockDataModel(iedServer);
			}
/*******************************************************
 *
 *******************************************************/
		}
		errorType = eMBMasterPoll();						// ��������� ������� �� MODBUS.
		if (errorType == MB_ETIMEDOUT){
    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
       		 switch (ReadNmb){
        		case 2:
        			cntErrorMD.errAnalog++;
        			break;
        		case 1:
        			cntErrorMD.errDiscreet++;
        			break;
        		default:
        			cntErrorMD.errSW++;
        			break;
        		}
			vTaskDelay(20);									// ������ �����, �� �������� ������� ������.
			Port_On(LED_out_RED);
//    		ReadNmb++;
			GLOBAL_QUALITY =  QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
    		Port_Off(LED1);
		}else
		if (errorType == MB_ENOERR || errorType == MB_ESENT){
			if (writeNmb == 10) {writeNmb = 0;}
//	   		USART_TRACE_RED("MB_ENOERR: %u\n",ReadNmb);
		}else
		if (errorType == MB_ERECVDATA){
			Port_On(LED_out_GREEN);
			Port_Off(LED_out_RED);
			GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
			vTaskDelay(20);									// ������ �����, �� �������� ������� ������.
			Nextread = true;
		}

		taskYIELD();										// �������� ������.
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
	uint16_t			SizeBlokReadMB = MaxSizeBlok;			// ������ ������ ������
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
   	   		USART_TRACE_GREEN("1.��������� ����� � �������.\n");
   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
   	   	}
   	   	else
		if (((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS)||(Nextread)){		// ������������� ����� MODBUS � �������� MB_PerForReadMODBUS(��)
			Nextread = false;
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>2 && ReadNmb<10)ReadNmb = 1;

			//--------------- ������������� ����� ------------------------------------
			if ((ReadNmb == 1) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = 10;			// ������ ���

			//--------------- ����������� ------------------------------------
	   	   	if (writeNmb == 1) {
	   	   		USART_TRACE_GREEN("����������� ON\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwON,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 2) {
	   	   		USART_TRACE_RED("����������� OFF\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwOFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}

	   	   	if (writeNmb == 3) {
	   	   		USART_TRACE_RED("����� ���������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 4) {
	   	   		USART_TRACE_RED("����� ����� �������������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������� \n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 6) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 7) {
	   	   		USART_TRACE_RED("������������ ������ ������� %u\n",writeNmbSG);
	   	   		eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_Startaddr_SG,writeNmbSG - 1,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 9) {
	   	   		USART_TRACE_RED("����� ������ ������� �������.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 10) {
	   	   		USART_TRACE_GREEN("2.��������� ����� � �������.\n");
	   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
	   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
	   	   	}
	   		currentTime = Hal_getTimeInMs();

			//--------------- ���� ������ -----------------------------------------
	   	   	if (writeNmb == 0){	// ������ ��� ������� ��������.

				Port_Off(LED_out_GREEN);

			//--------------- ������������� ����� ������ ���� �� �������� NTP -----
	   	     if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) {					//���� ������ ��� �� ������ ������������� �����
					ReadNmb = LimitRead;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("����������������� �����. �����:0x%X\n",(unsigned int)currentTime);
				}
	   	     }

			// ������� ����� ������ ������ ��� ������ �� ������� ��������, �������� ���� ������� ������
	   	     {
	   	    	 uint16_t	adin = (uint16_t)MB_NumbUstavki;
	   	    	 adin = adin * ucSGBuf[0];
	   	    	 //adin = adin * ucMAnalogInBuf[MB_offset_SG];
	   	    	 usConfigUstavkiStart = (uint16_t)MB_StartUstavkiaddr0 + adin;
	   	     }

//TODO: �������
//			ReadNmb = 29;

			// ������������� ������
	   	   	if (ReadNmb==0)  		eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);					// ������ ������� ����������
	   	   	else if (ReadNmb==1)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// ������ ���������� ����
	   	   	else if (ReadNmb==2) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);				// ������ ���������� ����

	   		// ����������� ������
	   	   	else if (ReadNmb==10)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// ������ ���������� ����
	   	   	else if (ReadNmb==11) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);						// ������ �������� �������
	   	   	else if (ReadNmb==12) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSystemCfgStart,MB_NumbSystemCfg,RT_WAITING_FOREVER);				// ������ ������������ �������
	   	   	else if (ReadNmb==13) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSGStart,MB_NumbSG,RT_WAITING_FOREVER);							// ������ ������ �������
	   	   	else if (ReadNmb==14) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSWCntStart,MB_NumbSw_CNT,RT_WAITING_FOREVER);						// ������ ������� �����������
	   	   	else if (ReadNmb==15) 	ReadNmb = 19;	// ������� � 20

	   	  	else if (ReadNmb==20) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigStartSW,MB_NumbConfigSW,RT_WAITING_FOREVER);}				// ������ ������������ �����������
	   	   	else if (ReadNmb==21) {	ReadNmb = 26;NumbBlokReadMBLim = 0;	}// ������� � 27

// ������ ��������� � ������� �������
//	   	  	else if (ReadNmb==21) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAPWStart,MB_NumbConfigAPW,RT_WAITING_FOREVER);}			// ������ ������������ ���
//	   	  	else if (ReadNmb==22) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAWRStart,MB_NumbConfigAWR,RT_WAITING_FOREVER);}			// ������ ������������ ���+���
//	   	  	else if (ReadNmb==23) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRPWRStart,MB_NumbConfigTRPWR,RT_WAITING_FOREVER);}		// ������ ���� ������� �������� ������
//	   	  	else if (ReadNmb==24) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRMeasStart,MB_NumbConfigTRMeas,RT_WAITING_FOREVER);}		// ������ ���� ������� �������������� ������
//	   	  	else if (ReadNmb==25) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfigVLSIn,MB_NumbConfigVLSIn,RT_WAITING_FOREVER);}		// ������ ������������ ������� ���������� ��������
/*	   	  	else if (ReadNmb==26) {																													// ������ ������������ �������� ���������� ��������

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
						   USART_TRACE_BLUE("%u-%u:������:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
						   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
						}

	   	  			}
*/
	   	  	else if (ReadNmb==27) {																													// ������ �������� ��� ��������� ������ �������

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
							   USART_TRACE_BLUE("%u-%u:������:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
							   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
						  }


	   	  			}
	   	  	else if (ReadNmb==28) {																													// ������ ���������� ����������.

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
	   	  				   	   USART_TRACE_BLUE("%u-%u:������:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
	   	  					   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
	   	  			   	  }
	   	  				else {
	   	  					NumbBlokReadMB = 0;
	   	  					SizeBlokReadMB = MaxSizeBlok;
	   	  					ReadNmb++;
	   	  				}

	   	  				if((SizeBlokReadMB != MaxSizeBlok) && (NumbBlokReadMB > NumbBlokReadMBLim))	{																																			// ���������
	   	  					NumbBlokReadMB = 0;
	   	  					SizeBlokReadMB = MaxSizeBlok;
	   	  					ReadNmb++;
	   	  				}
	   	  			}

//	   	  	else if (ReadNmb==26) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfigVLSOut,MB_NumbConfigVLSOut,RT_WAITING_FOREVER);}		// ������ ������������ �������� ���������� ��������
//	   	  	else if (ReadNmb==27) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigUstavkiStart,MB_NumbUstavki,RT_WAITING_FOREVER);}			// ������ �������� ��� ��������� ������ �������
	   	  	else if (ReadNmb==28) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAutomatStart,MB_NumbAutomat,RT_WAITING_FOREVER);}			// ������ ���������� ����������
	   	  	else {ReadNmb++;}

	   	   	LimitRead = 29;
	   	   	if (ReadNmb >= LimitRead) { ReadNmb = 1; osMutexRelease(xIEC850StartMutex);}
	   	   	if (IP_ready) {osMutexRelease(xIEC850StartMutex);}

	   	   	} else{
	   	   		if (writeNmb == 9 ) ReadNmb = 10;			// ���� ���� ������ � ������� ������ �� ���� ��������� �������. ����� ��� ����������.
	   	   		writeNmb = 0;
	   	   	}
/*******************************************************
 * ��������� ������������ ������� ���������
 *******************************************************/
			if(IEC850TaskHandle && (iedServer != NULL)){
				IedServer_lockDataModel(iedServer);																	// ����������� ���������� mmsServer'��

// PROT_LLN0 Health --------
				{
					uint32_t	LLN0_Health = STVALINT32_OK;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {LLN0_Health = STVALINT32_Warning;}
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LLN0_Health_stVal, LLN0_Health);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LLN0_Health_t, currentTime);
				}
// PROT_IPTOC1..8 ------						������ �� ��������� ����
					Set_IPTOC(6,currentTime);
// PROT_I20PTOC1..6 ------						������ �� ��������� �� ����� � ��������� ���� �������� ������������������
					Set_I20PTOC(8,currentTime);
// Set_I2I1PTOC ------
					Set_I2I1PTOC(1,currentTime);
// Set_IPTUC ------
					Set_IPTUC(1,currentTime);
// PROT_UPTOV1..4 ------						������ �� ��������� ����������
					Set_UPTOV(4,currentTime);
// PROT_UPTUV1..4 ------						������ �� ��������� ����������
					Set_UPTUV(4,currentTime);
// PROT_UPTOF1..4 ------						������ �� ��������� �������
					Set_PTOF(4,currentTime);
// PROT_UPTUF1..4 ------						������ �� ��������� �������
					Set_PTUF(4,currentTime);
// PROT_VZGGIO1..16 ------						������� ������
					Set_VZGGIO(16,currentTime);
// PROT_PDIS ------
					Set_PDIS(4,currentTime);
// PROT_RREC ------
					Set_RREC(1,currentTime);
// PROT_AVRGGIO ------
					Set_AVRGGIO(1,currentTime);
// PROT_NBLKGGIO ------
					Set_NBLKGGIO(1,currentTime);
// PROT_RBRF ------
					Set_RBRF(1,currentTime);
// PROT_RSYN ------
					Set_RSYN(1,currentTime);
// PROT_RPSB ------
					Set_RPSB(1,currentTime);
// PROT_RFLO ------
					Set_RFLO(1,currentTime);
// PROT_QPTTR ------
					Set_QPTTR(2,currentTime);
// PROT_BLKPTTR ------
					Set_BLKPTTR(1,currentTime);
// PROT_RFLO ------
					Set_PDPR(2,currentTime);
// PROT_IARCPTOC ------
					Set_IARCPTOC(1,currentTime);
// CTRL_CSWI ------
					Set_CSWI(1,currentTime);
// CTRL_XCBR ------
					Set_XCBR(1,currentTime);
// CTRL_PTRC ------
					Set_PTRC(1,currentTime);
// CTRL_GGIO ------
					Set_XCBRGGIO(1,currentTime);
// MES_MMXU ------
					Set_MMXU(1,currentTime);
// MES_MSQI ------
					Set_MSQI(1,currentTime);

// GGIO_IN24GGIO ------
					Set_INGGIO(40,currentTime);
					Set_OUTGGIO(34,currentTime);
					Set_LEDGGIO(16,currentTime);
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
		errorType = eMBMasterPoll();						// ��������� ������� �� MODBUS.
		if (errorType == MB_ETIMEDOUT){
			Port_On(LED_out_RED);
    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
			vTaskDelay(5);									// ������ �����, �� �������� ������� ������.

			GLOBAL_QUALITY =  QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
    		Port_Off(LED1);
		}else
		if (errorType == MB_ENOERR || errorType == MB_ESENT){
			if (writeNmb == 10) {writeNmb = 0;}
//	   		USART_TRACE_RED("MB_ENOERR: %u\n",ReadNmb);
		}else
		if (errorType == MB_ERECVDATA){
			Port_On(LED_out_GREEN);
			Port_Off(LED_out_RED);

			GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
			vTaskDelay(5);									// ������ �����, �� �������� ������� ������.
			Nextread = true;
		}


		taskYIELD();										// �������� ������.
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
	uint16_t			SizeBlokReadMB = MaxSizeBlok;			// ������ ������ ������
	uint16_t			addrConfig;

	uint8_t				LimitRead=0xFE;
	uint32_t			TimerReadMB;
	eMBErrorCode		errorType;
	uint64_t 			currentTime;
	RTC_TimeTypeDef 	Time;


	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();

	cntErrorMD.errAnalog = 0;
	cntErrorMD.errDiscreet = 0;
	writeNmb = 0;
	ReadNmb = 0;

	Port_On(LED1);

	TimerReadMB = HAL_GetTick();

	for(;;)
	{
   	   	if (writeNmb == 10) {
   	   		USART_TRACE_GREEN("1.��������� ����� � �������.\n");
   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
   	   	}
   	   	else
		if (((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS)||(Nextread)){		// ������������� ����� MODBUS � �������� MB_PerForReadMODBUS(��)
			Nextread = false;
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>2 && ReadNmb<10)ReadNmb = 1;

			//--------------- ������������� ����� ------------------------------------
			if ((ReadNmb == 1) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = 10;			// ������ ���

			//--------------- ����������� ------------------------------------

	   	   	if (writeNmb == 3) {
	   	   		USART_TRACE_RED("����� ���������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 4) {
	   	   		USART_TRACE_RED("����� ����� �������������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������� \n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 6) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 7) {
	   	   		USART_TRACE_RED("������������ ������ ������� 0.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SGroupe0,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 8) {
	   	   		USART_TRACE_RED("������������ ������ ������� 1.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SGroupe1,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 9) {
	   	   		USART_TRACE_RED("����� ������ ������� �������.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 10) {
	   	   		USART_TRACE_GREEN("2.��������� ����� � �������.\n");
	   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
	   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
	   	   	}
	   		currentTime = Hal_getTimeInMs();

			//--------------- ���� ������ -----------------------------------------
	   	   	if (writeNmb == 0){	// ������ ��� ������� ��������.
				Port_Off(LED_out_GREEN);
			//--------------- ������������� ����� ������ ���� �� �������� NTP -----
	   	     if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) {					//���� ������ ��� �� ������ ������������� �����
					ReadNmb = LimitRead;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("����������������� �����. �����:0x%X\n",(unsigned int)currentTime);
				}
	   	     }
			// ������� ����� ������ ������ ��� ������ �� ������� ��������, �������� ���� ������� ������
			if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG0) && ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG1) == 0))
					usConfigUstavkiStart = MB_StartUstavkiaddr0;
			 else	usConfigUstavkiStart = MB_StartUstavkiaddr1;



			// ������������� ������
	   	   	if (ReadNmb==0)  		eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);					// ������ ������� ����������
	   	   	else if (ReadNmb==1)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// ������ ���������� ����
	   	   	else if (ReadNmb==2) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);				// ������ ���������� ����

	   		// ����������� ������
	   	   	else if (ReadNmb==10)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// ������ ���������� ����
	   	   	else if (ReadNmb==11) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);						// ������ �������� �������
	   	   	else if (ReadNmb==12) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSystemCfgStart,MB_NumbSystemCfg,RT_WAITING_FOREVER);				// ������ ������������ �������
	   	  	else if (ReadNmb==13) 	ReadNmb = 19;	// ������� � 20

	   	  	else if (ReadNmb==20) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRMeasStart,MB_NumbConfigTRMeas,RT_WAITING_FOREVER);}		// ������ ���� ������� �������������� ������
	   	  	else if (ReadNmb==21) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfigVLSIn,MB_NumbConfigVLSIn,RT_WAITING_FOREVER);}		// ������ ������������ ������� ���������� ��������
	   	  	else if (ReadNmb==22) {																													// ������ ������������ �������� ���������� ��������

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
	   					   USART_TRACE_BLUE("%u-%u:������:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
	   					   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
	   	  				}

	   	  			}
	   	  	else if (ReadNmb==23) {																// ������ �������� ��� ��������� ������ �������

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
								USART_TRACE_BLUE("%u-%u:������:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
								eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
						}
	   	  			}
	   	  	else if (ReadNmb==24) {															// ������ ����� �������
						if (NumbBlokReadMBLim == 0) NumbBlokReadMB = 0;

						NumbBlokReadMBLim = (uint16_t)MB_NumbOtherUstavki;
						NumbBlokReadMBLim = NumbBlokReadMBLim/(uint16_t)MaxSizeBlok;

						addrConfig = usConfigOtherUstavkiStart + NumbBlokReadMB * MaxSizeBlok;

						if (NumbBlokReadMB == NumbBlokReadMBLim){
							SizeBlokReadMB = (uint16_t)MB_NumbOtherUstavki;
							SizeBlokReadMB = SizeBlokReadMB % (uint16_t)MaxSizeBlok;
						}

						if (NumbBlokReadMB > NumbBlokReadMBLim){
							addrConfig = 0;
							NumbBlokReadMB = 0;
							NumbBlokReadMBLim = 0;
							SizeBlokReadMB = MaxSizeBlok;
							ReadNmb++;
						} else
							if((SizeBlokReadMB) && addrConfig<(usConfigOtherUstavkiStart+MB_NumbOtherUstavki)) {
								USART_TRACE_BLUE("%u-%u:������:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
								eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
						}

	   	  			}

	   	  	else if (ReadNmb==25) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAutomatStart,MB_NumbAutomat,RT_WAITING_FOREVER);}			// ������ ���������� ����������
	   	  	else {ReadNmb++;}

//	   	 ReadNmb = 29;
	   	   	LimitRead = 26;
	   	   	if (ReadNmb >= LimitRead) { ReadNmb = 1; osMutexRelease(xIEC850StartMutex);}
	   	   	if (IP_ready) {osMutexRelease(xIEC850StartMutex);}
	   	   	} else{
	   	   		if (writeNmb == 9 ) ReadNmb = 10;			// ���� ���� ������ � ������� ������ �� ���� ��������� �������. ����� ��� ����������.
	   	   		writeNmb = 0;
	   	   	}
/*******************************************************
 * ��������� ������������ ������� ���������
 *******************************************************/
			if(IEC850TaskHandle && (iedServer != NULL)){
				IedServer_lockDataModel(iedServer);																	// ����������� ���������� mmsServer'��

// LLN0 Health --------
					Set_LLN0(1,currentTime);
// PROT_IPTOC1..8 ------						������ �� ��������� ����
					Set_IPTOC(32,currentTime);
// PROT_VZGGIO1..16 ------						������� ������
					Set_VZGGIO(16,currentTime);
// PROT_IDPDIF ------
					Set_IDPDIF(3,currentTime);
// PROT_IDMPDIF ------
					Set_IDMPDIF(3,currentTime);
// PROT_RREC ------ ���������� 901_902
					Set_RBRF(19,currentTime);

// CTRL_LLN0 ------

// CTRL_PTRC ------
					Set_PTRC(20,currentTime);
// CTRL_GGIO ------
					Set_XCBRGGIO(1,currentTime);
#if defined	(MR901)
// MES_MMXN ------
					Set_MMXN(1,currentTime);
#endif
#if defined	(MR902)
// MES_MMXU ------
					Set_MMXU(6,currentTime);
#endif
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
		errorType = eMBMasterPoll();						// ��������� ������� �� MODBUS.
		if (errorType == MB_ETIMEDOUT){
    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
    		switch (ReadNmb){
    		case 2:
    			cntErrorMD.errAnalog++;
    			break;
    		case 1:
    			cntErrorMD.errDiscreet++;
    			break;
    		default:
    			cntErrorMD.errSW++;
    			break;
    		}
			vTaskDelay(5);									// ������ �����, �� �������� ������� ������.
			Port_On(LED_out_RED);
//    		ReadNmb++;
			GLOBAL_QUALITY =  QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
    		Port_Off(LED1);
		}else
		if (errorType == MB_ENOERR || errorType == MB_ESENT){
			if (writeNmb == 10) {writeNmb = 0;}
//	   		USART_TRACE_RED("MB_ENOERR: %u\n",ReadNmb);
		}else
		if (errorType == MB_ERECVDATA){
			Port_On(LED_out_GREEN);
			Port_Off(LED_out_RED);
			GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
			vTaskDelay(5);									// ������ �����, �� �������� ������� ������.
			Nextread = true;
		}

		taskYIELD();										// �������� ������.
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
	uint16_t			SizeBlokReadMB = MaxSizeBlok;			// ������ ������ ������
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
   	   		USART_TRACE_GREEN("1.��������� ����� � �������.\n");
   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
   	   	}
   	   	else
		if (((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS)||(Nextread)){		// ������������� ����� MODBUS � �������� MB_PerForReadMODBUS(��)
			Nextread = false;
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>MB_Rd_Analog && ReadNmb<MB_Rd_AllUstavki)ReadNmb = MB_Rd_Discreet;

			//--------------- ������������� ����� ------------------------------------
			if ((ReadNmb == MB_Rd_Discreet) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = MB_Rd_AllUstavki;			// ������ ���

			//--------------- ����������� ------------------------------------
	   	   	if (writeNmb == 1) {
	   	   		USART_TRACE_GREEN("����������� ON\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwON,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 2) {
	   	   		USART_TRACE_RED("����������� OFF\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwOFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}

	   	   	if (writeNmb == 3) {
	   	   		USART_TRACE_RED("����� ���������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 4) {
	   	   		USART_TRACE_RED("����� ����� �������������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������� \n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 6) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 7) {
	   	   		USART_TRACE_RED("������������ ������ ������� %u\n",writeNmbSG);
	   	   		eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_Startaddr_SG,writeNmbSG - 1,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 9) {
	   	   		USART_TRACE_RED("����� ������ ������� �������.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_Sw,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 10) {
	   	   		USART_TRACE_GREEN("2.��������� ����� � �������.\n");
	   	   		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
	   	   		eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
	   	   	}
	   		currentTime = Hal_getTimeInMs();

			//--------------- ���� ������ -----------------------------------------
	   	   	if (writeNmb == 0){	// ������ ��� ������� ��������.
				Port_Off(LED_out_GREEN);
			//--------------- ������������� ����� ������ ���� �� �������� NTP -----
	   	     if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) {					//���� ������ ��� �� ������ ������������� �����
					ReadNmb = LimitRead;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("����������������� �����. �����:0x%X\n",(unsigned int)currentTime);
				}
	   	     }

			// ������� ����� ������ ������ ��� ������ �� ������� ��������, �������� ���� ������� ������
	   	     {
	   	    	 uint16_t	adin = (uint16_t)MB_NumbUstavki;
	   	    	 adin = adin * ucSGBuf[0];
	   	    	 //adin = adin * ucMAnalogInBuf[MB_offset_SG];
	   	    	 usConfigUstavkiStart = (uint16_t)MB_StartUstavkiaddr0 + adin;
	   	     }

//TODO: �������
//			ReadNmb = 29;

			// ������������� ������
	   	   	if (ReadNmb==0)  		eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);					// ������ ������� ����������
	   	   	else if (ReadNmb==1)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// ������ ���������� ����
	   	   	else if (ReadNmb==2) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);				// ������ ���������� ����

	   		// ����������� ������
	   	   	else if (ReadNmb==10)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);				// ������ ���������� ����
	   	   	else if (ReadNmb==11) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);						// ������ �������� �������
	   	   	else if (ReadNmb==12) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSystemCfgStart,MB_NumbSystemCfg,RT_WAITING_FOREVER);				// ������ ������������ �������
	   	   	else if (ReadNmb==13) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSGStart,MB_NumbSG,RT_WAITING_FOREVER);							// ������ ������ �������
	   	   	else if (ReadNmb==14) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSWCntStart,MB_NumbSw_CNT,RT_WAITING_FOREVER);						// ������ ������� �����������

	   	   	else if (ReadNmb==15) 	ReadNmb = 19;	// ������� � 20

	   	  	else if (ReadNmb==20) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigStartSW,MB_NumbConfigSW,RT_WAITING_FOREVER);}				// ������ ������������ �����������
	   	   	else if (ReadNmb==21) {	ReadNmb = 26;NumbBlokReadMBLim = 0;	}// ������� � 27

// ������ ��������� � ������� �������
//	   	  	else if (ReadNmb==21) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAPWStart,MB_NumbConfigAPW,RT_WAITING_FOREVER);}			// ������ ������������ ���
//	   	  	else if (ReadNmb==22) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAWRStart,MB_NumbConfigAWR,RT_WAITING_FOREVER);}			// ������ ������������ ���+���
//	   	  	else if (ReadNmb==23) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRPWRStart,MB_NumbConfigTRPWR,RT_WAITING_FOREVER);}		// ������ ���� ������� �������� ������
//	   	  	else if (ReadNmb==24) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigTRMeasStart,MB_NumbConfigTRMeas,RT_WAITING_FOREVER);}		// ������ ���� ������� �������������� ������
//	   	  	else if (ReadNmb==25) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfigVLSIn,MB_NumbConfigVLSIn,RT_WAITING_FOREVER);}		// ������ ������������ ������� ���������� ��������
/*	   	  	else if (ReadNmb==26) {																													// ������ ������������ �������� ���������� ��������

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
						   USART_TRACE_BLUE("%u-%u:������:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
						   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
						}

	   	  			}
*/
	   	  	else if (ReadNmb==27) {																													// ������ �������� ��� ��������� ������ �������

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
							   USART_TRACE_BLUE("%u-%u:������:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
							   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
						  }


	   	  			}
	   	  	else if (ReadNmb==28) {																													// ������ ���������� ����������.

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
	   	  				   	   USART_TRACE_BLUE("%u-%u:������:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
	   	  					   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
	   	  			   	  }
	   	  				else {
	   	  					NumbBlokReadMB = 0;
	   	  					SizeBlokReadMB = MaxSizeBlok;
	   	  					ReadNmb++;
	   	  				}

	   	  				if((SizeBlokReadMB != MaxSizeBlok) && (NumbBlokReadMB > NumbBlokReadMBLim))	{																																			// ���������
	   	  					NumbBlokReadMB = 0;
	   	  					SizeBlokReadMB = MaxSizeBlok;
	   	  					ReadNmb++;
	   	  				}
	   	  			}

//	   	  	else if (ReadNmb==26) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfigVLSOut,MB_NumbConfigVLSOut,RT_WAITING_FOREVER);}		// ������ ������������ �������� ���������� ��������
//	   	  	else if (ReadNmb==27) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigUstavkiStart,MB_NumbUstavki,RT_WAITING_FOREVER);}			// ������ �������� ��� ��������� ������ �������
	   	  	else if (ReadNmb==28) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAutomatStart,MB_NumbAutomat,RT_WAITING_FOREVER);}			// ������ ���������� ����������
	   	  	else {ReadNmb++;}

	   	   	LimitRead = 29;
	   	   	if (ReadNmb >= LimitRead) { ReadNmb = 1; osMutexRelease(xIEC850StartMutex);}
	   	   	if (IP_ready) {osMutexRelease(xIEC850StartMutex);}

	   	   	} else{
	   	   		if (writeNmb == 9 ) ReadNmb = 10;			// ���� ���� ������ � ������� ������ �� ���� ��������� �������. ����� ��� ����������.
	   	   		writeNmb = 0;
	   	   	}
/*******************************************************
 * ��������� ������������ ������� ���������
 *******************************************************/
			if(IEC850TaskHandle && (iedServer != NULL)){
				IedServer_lockDataModel(iedServer);																	// ����������� ���������� mmsServer'��

// PROT_LLN0 Health --------
				{
					uint32_t	LLN0_Health = STVALINT32_OK;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {LLN0_Health = STVALINT32_Warning;}
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LLN0_Health_stVal, LLN0_Health);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LLN0_Health_t, currentTime);
				}
// PROT_IPTOC1..8 ------						������ �� ��������� ����
					Set_IPTOC(6,currentTime);
// PROT_I20PTOC1..6 ------						������ �� ��������� �� ����� � ��������� ���� �������� ������������������
					Set_I20PTOC(8,currentTime);
// Set_I2I1PTOC ------
					Set_I2I1PTOC(1,currentTime);
// Set_IPTUC ------
					Set_IPTUC(1,currentTime);
// PROT_UPTOV1..4 ------						������ �� ��������� ����������
					Set_UPTOV(4,currentTime);
// PROT_UPTUV1..4 ------						������ �� ��������� ����������
					Set_UPTUV(4,currentTime);
// PROT_UPTOF1..4 ------						������ �� ��������� �������
					Set_PTOF(4,currentTime);
// PROT_UPTUF1..4 ------						������ �� ��������� �������
					Set_PTUF(4,currentTime);
// PROT_VZGGIO1..16 ------						������� ������
					Set_VZGGIO(16,currentTime);
// PROT_PDIS ------
					Set_PDIS(10,currentTime);
// PROT_RREC ------
					Set_RREC(1,currentTime);
// PROT_RBRF ------
					Set_RBRF(1,currentTime);
// PROT_RSYN ------
					Set_RSYN(1,currentTime);
// PROT_RPSB ------
					Set_RPSB(10,currentTime);
// PROT_RFLO ------
					Set_RFLO(1,currentTime);
// PROT_QPTTR ------
					Set_QPTTR(2,currentTime);
// PROT_BLKPTTR ------
					Set_BLKPTTR(1,currentTime);

// CTRL_CSWI ------
					Set_CSWI(1,currentTime);
// CTRL_XCBR ------
					Set_XCBR(1,currentTime);
// CTRL_PTRC ------
					Set_PTRC(1,currentTime);
// CTRL_GGIO ------
					Set_XCBRGGIO(1,currentTime);
// MES_MMXU ------
					Set_MMXU(1,currentTime);
// MES_MSQI ------
					Set_MSQI(1,currentTime);

// GGIO_IN24GGIO ------
					Set_INGGIO(42,currentTime);
					Set_OUTGGIO(34,currentTime);
					Set_LEDGGIO(16,currentTime);
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
		errorType = eMBMasterPoll();						// ��������� ������� �� MODBUS.
		if (errorType == MB_ETIMEDOUT){
			Port_On(LED_out_RED);
    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
			vTaskDelay(5);									// ������ �����, �� �������� ������� ������.

			GLOBAL_QUALITY =  QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
    		Port_Off(LED1);
		}else
		if (errorType == MB_ENOERR || errorType == MB_ESENT){
			if (writeNmb == 10) {writeNmb = 0;}
//	   		USART_TRACE_RED("MB_ENOERR: %u\n",ReadNmb);
		}else
		if (errorType == MB_ERECVDATA){
			Port_On(LED_out_GREEN);
			Port_Off(LED_out_RED);
			GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
			vTaskDelay(5);									// ������ �����, �� �������� ������� ������.
			Nextread = true;
		}


		taskYIELD();										// �������� ������.
	}
}
#endif
/*******************************************************
 * MR5_700 MODBUS
 *******************************************************/
#if defined (MR5_700)
void StartMODBUSTask(void const * argument)
{
	eMBMasterReqErrCode	sentToBuff = MB_MRE_NO_ERR;

	extern uint64_t nextSynchTime;
	extern bool resynch;
	uint32_t			TimerReadMB;
	eMBErrorCode		errorType;
	uint8_t				i;
	RTC_TimeTypeDef 	Time;
	uint8_t  			PerForSynch;
	uint8_t				CurrSG;
	uint8_t				LimitRead=0xFE;
	uint64_t 			currentTime;
	extern const uint8_t userConfig[];

//	osMutexWait(xIEC850StartMutex, osWaitForever);				// ������� ������� ��� ���������� TCP ���� �� ������� ��������� IP
//	USART_TRACE_BLUE("MODBUS ������ ������� IEC850Start\n");

//	usMDiscInStart = MB_StartDiscreetaddr;

	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();

//	vTaskDelay(1000);
	writeNmb = MB_Wr_none;
	ReadNmb = MB_Rd_Revision;

	Port_On(LED1);
/*
	{
		uint8_t 			HardFaultcnt;												// ������� ������������
		memory_read((uint8_t *)&HardFaultcnt,_IfHardFault,sizeof(HardFaultcnt));						// ������ IP �� ������� ������
		HardFaultcnt++;
		memory_write_to_mem((uint8_t *)&HardFaultcnt,_IfHardFault,sizeof(HardFaultcnt));
		USART_TRACE_GREEN("����� ��������: %u\n",HardFaultcnt);
	}
*/
	TimerReadMB = HAL_GetTick();
	for(;;)
	{
 //		IedServer_setControlHandler(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1, (ControlHandler)controlListener, &iedModel_GGIO_OUTGGIO1_SPCSO1);

		// ����������� ��� ��������� ����� �� ����� ��� �����, � ����� ���������
	 	if (SetTimeNow) {
	 			writeNmb = MB_Wr_Set_Time;
				USART_TRACE_GREEN("1.������� ��������� ����� � �������.(%u) \n",errorType);
				Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
				sentToBuff = eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
				if (sentToBuff == MB_MRE_NO_ERR) SetTimeNow = false;
		}
	 	else
		//if (((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS)||(Nextread)){		// ������������� ����� MODBUS � �������� MB_PerForReadMODBUS(��)
			{
			Nextread = false;
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>MB_Rd_Analog && ReadNmb<MB_Rd_AllUstavki)ReadNmb = MB_Rd_Discreet;

			//--------------- ������������� ����� ------------------------------------
			if ((ReadNmb == MB_Rd_Discreet) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = MB_Rd_AllUstavki;			// ������ ���

			//--------------- ����������� ------------------------------------
	   	   	if (writeNmb == MB_Wr_SwON) {
	   	   		USART_TRACE_GREEN("����������� ON\n");
	   	   		sentToBuff = eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwON,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_SwOFF) {
	   	   		USART_TRACE_RED("����������� OFF\n");
	   	   		sentToBuff = eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwOFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}

	   	   	if (writeNmb == MB_Wr_Reset_LEDS) {
	   	   		USART_TRACE_RED("����� ���������\n");
	   	   		sentToBuff = eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_Reset_Error) {
	   	   		USART_TRACE_RED("����� ����� �������������\n");
	   	   		sentToBuff = eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������� \n");
	   	   		sentToBuff = eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_Reset_ErrorNote) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������\n");
	   	   		sentToBuff = eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_SG_set_0) {
	   	   		USART_TRACE_RED("������������ ������ ������� 0.\n");
	   	   		sentToBuff = eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_addr_SG,MB_selectGroupe0,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_SG_set_1) {
	   	   		USART_TRACE_RED("������������ ������ ������� 1.\n");
	   	   		sentToBuff = eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_addr_SG,MB_selectGroupe1,RT_WAITING_FOREVER);
	   	   	}
	   	   	if ((writeNmb == MB_Wr_Reset_SysNote) || Reset_SysNoteNow) {
	   	   		writeNmb = MB_Wr_Reset_SysNote;
	   	   		USART_TRACE_RED("����� ������ ������� �������. (%u)\n",errorType);
	   	   		sentToBuff = eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   		if (sentToBuff == MB_MRE_NO_ERR) Reset_SysNoteNow = false;
	   	   	}
	   	 	if (writeNmb == MB_Wr_Set_Time) {
				USART_TRACE_GREEN("2.��������� ����� � �������.\n");
				Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
	   	   		sentToBuff = eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
			}
			currentTime = Hal_getTimeInMs();

			//--------------- ���� ������ -----------------------------------------
	   	   	if (writeNmb == MB_Wr_none){	// ������ ��� ������� ��������.
				Port_Off(LED_out_GREEN);
			//--------------- ������������� ����� ������ ���� �� �������� NTP -----
			 if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) {					//���� ������ ��� �� ������ ������������� �����
					ReadNmb = MB_Rd_EndAddr;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("����������������� �����. �����:0x%X\n",(unsigned int)currentTime);
				}
			 }

			// ������� ����� ������ ������ ��� ������ �� ������� ��������, �������� ���� ������� ������
			if (ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSettingGr){
				usConfigStartMTZ 	= MB_StartConfigMTZ_SG1;
				usConfigStartI2I1I0	= MB_StartConfigI2I1I0_SG1;
				usConfigStartF		= MB_StartConfigF_SG1;
				usConfigStartU		= MB_StartConfigU_SG1;
			}
			 else{
				usConfigStartMTZ 	= MB_StartConfigMTZ_SG0;
				usConfigStartI2I1I0	= MB_StartConfigI2I1I0_SG0;
				usConfigStartF		= MB_StartConfigF_SG0;
				usConfigStartU		= MB_StartConfigU_SG0;
			 }

			// ������ ������, ����� ������� �������� �������
	   	   	if (ReadNmb==MB_Rd_Revision){eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);getJurnals = true;}							// ������ ������� ����������
			// ������������� ������
	   	   	else if (ReadNmb==MB_Rd_Discreet){
	   	   		sentToBuff = eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);
	   	   	}
	   	   	else if (ReadNmb==MB_Rd_Analog)  {
	   	   		sentToBuff = eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);
	   		}

	   		// ����������� ������
	   	   	else if (ReadNmb==MB_Rd_AllUstavki)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);	// ������ ���������� ����
	   	   	else if (ReadNmb==11) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);						// ������ �������� �������
	   	   	else if (ReadNmb==12) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSystemCfgStart,MB_NumbSystemCfg,RT_WAITING_FOREVER);				// ������ ������������ �������
	   	   	else if (ReadNmb==13) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigUstavkiStart,MB_NumbUstavki,RT_WAITING_FOREVER);			// ������ �������
	   	   	else if (ReadNmb==14) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartSWCrash,MB_NumbSWCrash,RT_WAITING_FOREVER);			// ������ ������� �����������
	   	   	else if (ReadNmb==15) 	ReadNmb = 19;	// ������� � 20

	   	   	else if (ReadNmb==20) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartSW,MB_NumbConfigSW,RT_WAITING_FOREVER);}				// ������ ������������ �����������
	   	  	else if (ReadNmb==21) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigOutStart,MB_NumbConfigOut,RT_WAITING_FOREVER);}			// ������ ������������ �������� ��������
	   	  	else if (ReadNmb==22) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAutomatStart,MB_NumbAutomat,RT_WAITING_FOREVER);}			// ������ ������������ ����������
	   	  	else if (ReadNmb==23) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartExZ,MB_NumbConfigExZ,RT_WAITING_FOREVER);}			// ������ ������������ ������� �����
	   	  	else if (ReadNmb==24) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartMTZ,MB_NumbConfigMTZ,RT_WAITING_FOREVER);}			// ������ ������������ ������� �����
	   	  	else if (ReadNmb==25) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartI2I1I0,MB_NumbConfigI2I1I0,RT_WAITING_FOREVER);}		// ������ ������������ �������������� �����
	   	  	else if (ReadNmb==26) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartF,MB_NumbConfigF,RT_WAITING_FOREVER);}				// ������ ������������ ������ �� �������
	   	  	else if (ReadNmb==27) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartU,MB_NumbConfigU,RT_WAITING_FOREVER);}				// ������ ������������ ������ �� ����������
	   	   	else if (ReadNmb==28) {
	   	   			if (getJurnals) {ReadNmb = MB_Rd_Discreet;/*MB_Rd_SysNote;*/}						//���� ������ ��������� �������� �������
	   	   			else			ReadNmb = MB_Rd_Discreet;						//����� � ����
	   	   	}

	   		// ������ ������ ����������� ������, � ��������� �� ���� (1 ������)
	   	  	else if (ReadNmb==MB_Rd_SysNote) 	{ eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSysNoteStart,MB_NumbSysNote,RT_WAITING_FOREVER);}		// ������ ��������� ������ � ������� �������
	   	  	else if (ReadNmb==MB_Rd_ErrorNote) 	{ eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usErrorNoteStart,MB_NumbErrorNote,RT_WAITING_FOREVER);}	// ������ ��������� ������ � ������� ������

	   	  	else {ReadNmb++;}

//			LimitRead = MB_Rd_EndAddr;
			if (ReadNmb >= MB_Rd_EndAddr) { ReadNmb = MB_Rd_Discreet; osMutexRelease(xIEC850StartMutex);}
			if (IP_ready) {osMutexRelease(xIEC850StartMutex);}

			} else{
				if ( sentToBuff == MB_MRE_NO_ERR){
					if (writeNmb == MB_Wr_Reset_SysNote ) 	ReadNmb = MB_Rd_SysNote;//ReadNmb = 10;			// ���� ���� ������ � ������� ������ �� ���� ��������� �������. ����� ��� ����������. �� ������� �������� ������ � �������
					if (writeNmb == MB_Wr_Reset_ErrorNote) ReadNmb = MB_Rd_ErrorNote;		// �������� ���� �������� ����
					writeNmb = MB_Wr_none;
				}
			}

/*******************************************************
* ��������� ������������ ������� ���������
*******************************************************/

if(IEC850TaskHandle && (iedServer != NULL)){

            IedServer_lockDataModel(iedServer);																	// ����������� ���������� mmsServer'��

// PROT_IPTOC1..8 ------
					Set_IPTOC(4,currentTime);
// PROT_I20PTOC1 ------
					Set_I2PTOC(2,currentTime);
					Set_I0PTOC(2,currentTime);
// Set_INPTOC ------
					Set_INPTOC(2,currentTime);
// Set_IGPTOC ------
					Set_IGPTOC(1,currentTime);
// Set_I2I1PTOC ------
					Set_I2I1PTOC(1,currentTime);
// PROT_UPTOV1 ------
					Set_UPTOV(2,currentTime);
// PROT_UPTUV1 ------
					Set_UPTUV(2,currentTime);
// PROT_U2PTOV1 ------
					Set_U2PTOV(2,currentTime);
// PROT_U0PTOV1 ------
					Set_U0PTOV(2,currentTime);
// PROT_UPTOF1 ------
					Set_PTOF(2,currentTime);
// PROT_UPTUF1 ------
					Set_PTUF(2,currentTime);
// PROT_VZGGIO1..8 ------
					Set_VZGGIO(8,currentTime);

// PROT_RREC ------
					Set_RREC(1,currentTime);
// PROT_AVRGGIO ------
					Set_AVRGGIO(1,currentTime);
// Set_LZSHPTOC ------
					Set_LZSHPTOC(1,currentTime);
// PROT_RBRF ------
					Set_RBRF(1,currentTime);

// CTRL_CSWI ------
					Set_CSWI(1,currentTime);
// CTRL_XCBR ------
					Set_XCBR(1,currentTime);
// CTRL_PTRC ------
					Set_PTRC(1,currentTime);

// CTRL_GGIO ------
					Set_XCBRGGIO(1,currentTime);
// MES_MMXU ------
					Set_MMXU(1,currentTime);
// MES_MSQI ------
					Set_MSQI(1,currentTime);
// PROT_RFLO ------
					Set_RFLO(1,currentTime);

// GGIO_IN24GGIO ------
					Set_INGGIO(16,currentTime);
					Set_OUTGGIO(8,currentTime);
					Set_LEDGGIO(12,currentTime);
					Set_SSLGGIO(24,currentTime);
					Set_VLSGGIO(8,currentTime);
					Set_LSGGIO(8,currentTime);

// LD0 SG
					Set_SG(0,currentTime);

    IedServer_unlockDataModel(iedServer);																// ����� ���������� mmsServer'��
}
/*******************************************************
 *
 *******************************************************/
	}
		if ( sentToBuff == MB_MRE_NO_ERR){
			if (writeNmb == MB_Wr_Reset_SysNote ) 	ReadNmb = MB_Rd_SysNote;	//ReadNmb = 10;			// ���� ���� ������ � ������� ������ �� ���� ��������� �������. ����� ��� ����������. �� ������� �������� ������ � �������
			if (writeNmb == MB_Wr_Reset_ErrorNote) 	ReadNmb = MB_Rd_ErrorNote;	// �������� ���� �������� ����
			if (writeNmb == MB_Wr_Set_Time) 		writeNmb = MB_Wr_none;
			writeNmb = MB_Wr_none;
		}

			errorType = eMBMasterPoll();						// ��������� ������� �� MODBUS.
			if (errorType == MB_ETIMEDOUT){
				USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
				 switch (ReadNmb){
					case 2:
						cntErrorMD.errAnalog++;
						break;
					case 1:
						cntErrorMD.errDiscreet++;
						break;
					default:
						cntErrorMD.errSW++;
						break;
					}
				vTaskDelay(5);									// ������ �����, �� �������� ������� ������.
				Port_On(LED_out_RED);
	//    		ReadNmb++;
				GLOBAL_QUALITY =  QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
				Port_Off(LED1);
			}else
			if (errorType == MB_ENOERR || errorType == MB_ESENT){
				if (writeNmb == MB_Wr_Set_Time) {writeNmb = MB_Wr_none;}
	//	   		USART_TRACE_RED("MB_ENOERR: %u\n",ReadNmb);
			}else
			if (errorType == MB_ERECVDATA){
				Port_On(LED_out_GREEN);
				Port_Off(LED_out_RED);
				GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
				vTaskDelay(5);									// ������ �����, �� �������� ������� ������.
				Nextread = true;
			}

		taskYIELD();										// �������� ������.
	}
}
#endif
/*******************************************************
 * MR5_600 MODBUS
 *******************************************************/
#if defined (MR5_600)
void FastMODBUSTask(void const * argument)
{
	eMBErrorCode		errorType = MB_ENOERR;
	eMBMasterReqErrCode	errorSent = MB_MRE_NO_ERR;

	ModbusMessage 	pxTxMessage;

	volatile  uint8_t	MbNmbMessage=0;

	// ������� ������� �� 20 ��������� ��� �������� � ������
	ModbusSentQueue 	= xQueueCreate( 20, sizeof(ModbusMessage));			// �������� �������
	ModbusSentTime		= xQueueCreate( 2, sizeof(ModbusMessage));			// �������������� �������, �� ��� ����������� ������ ���� ��-�� ���������

	Rd_SysNoteQueue 	= xQueueCreate( 5, sizeof(ModbusMessage));			// ���. �������, �� ��� �� ������ ������� ��������� � ��������
	Rd_ErrorNoteQueue 	= xQueueCreate( 10, sizeof(ModbusMessage));
	Rd_UstavkiQueue		= xQueueCreate( 10, sizeof(ModbusMessage));
	Rd_FileQueue 		= xQueueCreate( 20, sizeof(ModbusMessage));

	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();

//	AddToQueueMB(ModbusSentTime, 	MB_Wr_Set_Time		,MB_Slaveaddr);		// ��������� �������


	AddToQueueMB(ModbusSentQueue, 	MB_Rd_Revision		,MB_Slaveaddr);
	AddToQueueMB(ModbusSentQueue, 	MB_Rd_Get_Time		,MB_Slaveaddr);
	AddToQueueMB(ModbusSentQueue, 	MB_Rd_Syscfg		,MB_Slaveaddr);

	AddToQueueMB(Rd_UstavkiQueue, 	MB_Rd_Ustavki		,MB_Slaveaddr);
	AddToQueueMB(ModbusSentQueue, 	MB_Rd_ConfigOut		,MB_Slaveaddr);
	AddToQueueMB(ModbusSentQueue, 	MB_Rd_ConfigExZ		,MB_Slaveaddr);
	AddToQueueMB(ModbusSentQueue, 	MB_Rd_ConfigF		,MB_Slaveaddr);
	AddToQueueMB(ModbusSentQueue, 	MB_Rd_ConfigU		,MB_Slaveaddr);


//	AddToQueueMB(Rd_UstavkiQueue, 	MB_Rd_AllUstavki	,MB_Slaveaddr);
	AddToQueueMB(Rd_SysNoteQueue, 	MB_Rd_SysNote		,MB_Slaveaddr);
	AddToQueueMB(Rd_ErrorNoteQueue, MB_Rd_ErrorNote		,MB_Slaveaddr);

	MbNmbMessage = MB_Rd_Discreet;


	for(;;)
	{
		//xQueueSend( ModbusSentQueue, ( void * ) &toSend, portMAX_DELAY  );		// �������� � ������� ���������
		//xQueueSendToFront( ModbusSentQueue, ( void * ) &toSend, portMAX_DELAY  ); // �������� � ������ ������� ���������
		//xQueueReceive( ModbusSentQueue, &( rec ), portMAX_DELAY ); 				// ����� �� ������� ���������

		errorType = eMBMasterPoll();						// ��������� ������� �� MODBUS.

		// ������ ���� �� ������� � ����������, � �� ��������
		if (errorType == MB_ENOERR){

// ������� �������

			if( xQueueReceive( ModbusSentTime, &(pxTxMessage),( TickType_t ) 0 ) )
			{
				errorSent = eMBMasterSendMessage(&pxTxMessage);
				USART_TRACE_GREEN("��� \n");
				if (errorSent == MB_MRE_NO_ERR) {
					errorType = eMBMasterPoll();	// ��� �����.
					MbNmbMessage = MB_Rd_Discreet;
					USART_TRACE_GREEN("������ ������� ������� cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);
				} else{
					xQueueSendToFront( ModbusSentTime, ( void * )&pxTxMessage, portMAX_DELAY);	// �������� � ������� ��������� � ������
//					AddToQueueMB(ModbusSentTime, 	MB_Wrt_Set_Time		,MB_Slaveaddr);		// �� ���������� �����, ������ � ������� �����.
				}
			}
// �������,��������
			else
			// � ������ ������� ������� �� ������, ���� �� �� ������������������
			if (MbNmbMessage==MB_Rd_Discreet){
				eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);
			}
			else
			if (MbNmbMessage==MB_Rd_Analog)  {
				eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);
			}

// �� ���������, ����� �������
			else
			if (MbNmbMessage > MB_Rd_Analog) {
	// ����� �������
				if( xQueueReceive( ModbusSentQueue, &(pxTxMessage),( TickType_t ) 0 ) )		// ����� �� ������� ���������
				{
					errorSent = eMBMasterSendMessage(&pxTxMessage);
					if (errorSent == MB_MRE_NO_ERR) {
						MbNmbMessage = MB_Rd_Discreet;
						USART_TRACE_GREEN("������ ����� ������� cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);
					} else{
						xQueueSendToFront( ModbusSentQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// �������� ��������� � ������
					}
				}else
	// ������� ������
				if( xQueueReceive( Rd_SysNoteQueue, &(pxTxMessage),( TickType_t ) 0 ) )
				{
					errorSent = eMBMasterSendMessage(&pxTxMessage);
					if (errorSent == MB_MRE_NO_ERR) {
						MbNmbMessage = MB_Rd_Discreet;
						USART_TRACE_GREEN("������ ������� ������� cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);
					} else{
						xQueueSendToFront( Rd_SysNoteQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// �������� ��������� � ������
					}
				}else
	// ������� ������
				if( xQueueReceive( Rd_ErrorNoteQueue, &(pxTxMessage),( TickType_t ) 0 ) )
				{
					errorSent = eMBMasterSendMessage(&pxTxMessage);
					if (errorSent == MB_MRE_NO_ERR) {
						MbNmbMessage = MB_Rd_Discreet;
						USART_TRACE_GREEN("������ ������� ������ cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);
					} else{
						xQueueSendToFront( Rd_ErrorNoteQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// �������� ��������� � ������
					}
				}
				else{
					MbNmbMessage = MB_Rd_Discreet;
				}
			}//!if (ReadNmb > MB_Rd_Analog)

		}//!if (errorType == MB_ENOERR)
		else
		if (errorType == MB_ETIMEDOUT){
			Port_On(LED_out_RED);
			GLOBAL_QUALITY =  QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
		}else
		if (errorType == MB_ERECVDATA){
			MbNmbMessage++;					// �� ��� ������� �� ����� ���������
			Port_On(LED_out_GREEN);
			Port_Off(LED_out_RED);
			GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
			osMutexRelease(xIEC850StartMutex);
		}
	taskYIELD();										// �������� ������.

	}// !for(;;)
}

/*******************************************************
 * MR5_600 MODBUS
 *******************************************************/
void StartMODBUSTask(void const * argument)
{
	uint16_t			NumbBlokReadMBLim=0;
	uint16_t			SizeBlokReadMB = MaxSizeBlok;			// ������ ������ ������
	uint16_t			addrConfig;
	eMBMasterReqErrCode sentToBuff = MB_MRE_NO_ERR;

	extern uint64_t nextSynchTime;
	extern bool resynch;
	uint32_t			TimerReadMB;
	eMBErrorCode		errorType;
	uint8_t				i;
	RTC_TimeTypeDef 	Time;
	uint8_t  			PerForSynch;
	uint8_t				CurrSG;
	uint8_t				LimitRead=0xFE;
	uint64_t 			currentTime;
	extern const uint8_t userConfig[];

//	osMutexWait(xIEC850StartMutex, osWaitForever);				// ������� ������� ��� ���������� TCP ���� �� ������� ��������� IP
//	USART_TRACE_BLUE("MODBUS ������ ������� IEC850Start\n");

//	usMDiscInStart = MB_StartDiscreetaddr;

	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();

//	vTaskDelay(1000);
	writeNmb = MB_Wr_none;
	ReadNmb = MB_Rd_Revision;

	Port_On(LED1);
/*
	{
		uint8_t 			HardFaultcnt;												// ������� ������������
		memory_read((uint8_t *)&HardFaultcnt,_IfHardFault,sizeof(HardFaultcnt));						// ������ IP �� ������� ������
		HardFaultcnt++;
		memory_write_to_mem((uint8_t *)&HardFaultcnt,_IfHardFault,sizeof(HardFaultcnt));
		USART_TRACE_GREEN("����� ��������: %u\n",HardFaultcnt);
	}
*/
	TimerReadMB = HAL_GetTick();
	for(;;)
	{
 //		IedServer_setControlHandler(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1, (ControlHandler)controlListener, &iedModel_GGIO_OUTGGIO1_SPCSO1);

		// ����������� ��� ��������� ����� �� ����� ��� �����, � ����� ���������
	 	if (SetTimeNow) {
	 			writeNmb = MB_Wr_Set_Time;
				USART_TRACE_GREEN("1.������� ��������� ����� � �������.(%u) \n",errorType);
				Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
				sentToBuff = eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
				if (sentToBuff == MB_MRE_NO_ERR) SetTimeNow = false;
		}
	 	else
//		if (((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS)||(Nextread)){		// ������������� ����� MODBUS � �������� MB_PerForReadMODBUS(��)
	 		if (Nextread){		// ������������� ����� MODBUS � �������� MB_PerForReadMODBUS(��)
			Nextread = false;
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>MB_Rd_Analog && ReadNmb<MB_Rd_AllUstavki)ReadNmb = MB_Rd_Discreet;

			//--------------- ������������� ����� ------------------------------------
			if ((ReadNmb == MB_Rd_Discreet) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = MB_Rd_AllUstavki;			// ������ ���

			//--------------- ����������� ------------------------------------

	   	   	if (writeNmb == MB_Wr_Reset_LEDS) {
	   	   		USART_TRACE_RED("����� ���������\n");
	   	   		sentToBuff = eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_Reset_Error) {
	   	   		USART_TRACE_RED("����� ����� �������������\n");
	   	   		sentToBuff = eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������� \n");
	   	   		sentToBuff = eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_Reset_ErrorNote) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������\n");
	   	   		sentToBuff = eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_SG_set_0) {
	   	   		USART_TRACE_RED("������������ ������ ������� 0.\n");
	   	   		sentToBuff = eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_addr_SG,MB_selectGroupe0,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_SG_set_1) {
	   	   		USART_TRACE_RED("������������ ������ ������� 1.\n");
	   	   		sentToBuff = eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_addr_SG,MB_selectGroupe1,RT_WAITING_FOREVER);
	   	   	}
	   	   	if ((writeNmb == MB_Wr_Reset_SysNote) || Reset_SysNoteNow) {
	   	   		writeNmb = MB_Wr_Reset_SysNote;
	   	   		USART_TRACE_RED("����� ������ ������� �������. (%u)\n",errorType);
	   	   		sentToBuff = eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   		if (sentToBuff == MB_MRE_NO_ERR) Reset_SysNoteNow = false;
	   	   	}
	   	 	if (writeNmb == MB_Wr_Set_Time) {
				USART_TRACE_GREEN("2.��������� ����� � ������� �� �������. (%u)\n",errorType);
				Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
				sentToBuff = eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
			}
			currentTime = Hal_getTimeInMs();

			//--------------- ���� ������ -----------------------------------------
	   	   	if (writeNmb == MB_Wr_none){	// ������ ��� ������� ��������.
				Port_Off(LED_out_GREEN);
			//--------------- ������������� ����� ������ ���� �� �������� NTP -----
			 if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) {					//���� ������ ��� �� ������ ������������� �����
					ReadNmb = MB_Rd_EndAddr;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("����������������� ����� �� �������. �����:0x%X\n",(unsigned int)currentTime);
				}
			 } else
				 if(lostSNTPPackets>_limitlostSNTPPackets){
					ReadNmb = MB_Rd_EndAddr;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("����������������� ����� ����� ��������� NTP. �����:0x%X\n",(unsigned int)currentTime);
					lostSNTPPackets = 0;
			 }

			// ������� ����� ������ ������ ��� ������ �� ������� ��������, �������� ���� ������� ������
			if (ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSettingGr){
				usConfigStartF		= MB_StartConfigF_SG1;
				usConfigStartU		= MB_StartConfigU_SG1;
				usConfigStartExZ	= MB_StartConfigExZ_SG1;
			}
			 else{
				usConfigStartF		= MB_StartConfigF_SG0;
				usConfigStartU		= MB_StartConfigU_SG0;
				usConfigStartExZ 	= MB_StartConfigExZ_SG0;
			 }

			// ������ ������, ����� ������� �������� �������
	   	   	if (ReadNmb==MB_Rd_Revision){eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);getJurnals = true;}							// ������ ������� ����������
			// ������������� ������
	   	   	else if (ReadNmb==MB_Rd_Discreet){
	   	   		eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);
	   	   	}
	   	   	else if (ReadNmb==MB_Rd_Analog)  {
	   			eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);
	   		}

	   		// ����������� ������
	   	   	else if (ReadNmb==MB_Rd_AllUstavki)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);	// ������ ���������� ����
	   	   	else if (ReadNmb==MB_Rd_Get_Time) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);			// ������ �������� �������
	   	   	else if (ReadNmb==MB_Rd_Syscfg) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSystemCfgStart,MB_NumbSystemCfg,RT_WAITING_FOREVER);	// ������ ������������ �������
	   	   	else if (ReadNmb==MB_Rd_Ustavki) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigUstavkiStart,MB_NumbUstavki,RT_WAITING_FOREVER);	// ������ �������
//	   	   	else if (ReadNmb==14) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartSWCrash,MB_NumbSWCrash,RT_WAITING_FOREVER);			// ������ ������� �����������
	   	   	else if (ReadNmb==14) 	ReadNmb = 19;	// ������� � 20


	   	  	else if (ReadNmb==MB_Rd_ConfigOut) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigOutStart,MB_NumbConfigOut,RT_WAITING_FOREVER);}			// ������ ������������ �������� ��������
	   	  	else if (ReadNmb==MB_Rd_ConfigExZ) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartExZ,MB_NumbConfigExZ,RT_WAITING_FOREVER);}			// ������ ������������ ������� �����
	   	  	else if (ReadNmb==MB_Rd_ConfigF) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartF,MB_NumbConfigF,RT_WAITING_FOREVER);}				// ������ ������������ ������ �� �������
//	   	  	else if (ReadNmb==MB_Rd_ConfigU) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartU,MB_NumbConfigU,RT_WAITING_FOREVER);}				// ������ ������������ ������ �� ����������
	   	  	else if (ReadNmb==MB_Rd_ConfigU) {																													// ������ �������� ��� ��������� ������ �������

	   	  				if (NumbBlokReadMBLim == 0) NumbBlokReadMB = 0;

	  					NumbBlokReadMBLim = (uint16_t)MB_NumbConfigU;
	  					NumbBlokReadMBLim = NumbBlokReadMBLim/(uint16_t)MaxSizeBlok;

	   	  				addrConfig = usConfigStartU + NumbBlokReadMB * MaxSizeBlok;

	   	  				if (NumbBlokReadMB == NumbBlokReadMBLim){
	   	  					SizeBlokReadMB = (uint16_t)MB_NumbConfigU;
	   	  					SizeBlokReadMB = SizeBlokReadMB % (uint16_t)MaxSizeBlok;
	   	  				}

	   	  				if (NumbBlokReadMB > NumbBlokReadMBLim){
	   	  					addrConfig = 0;
							NumbBlokReadMB = 0;
							NumbBlokReadMBLim = 0;
							SizeBlokReadMB = MaxSizeBlok;
							ReadNmb++;
	   	  				} else
					    if((SizeBlokReadMB) && addrConfig<(usConfigStartU+MB_NumbConfigU)) {
							   USART_TRACE_BLUE("%u-%u:������:0x%X\n",ReadNmb,NumbBlokReadMB,(unsigned int)addrConfig);
							   eMBMasterReqReadHoldingRegister(MB_Slaveaddr,addrConfig,SizeBlokReadMB,RT_WAITING_FOREVER);
						  }


	   	  			}
	   	  	else if (ReadNmb==24) {
	   	   			if (getJurnals) {ReadNmb = MB_Rd_Discreet;/*MB_Rd_SysNote;*/}						//���� ������ ��������� �������� �������
	   	   			else			ReadNmb = MB_Rd_Discreet;						//����� � ����
	   	   	}

	   		// ������ ������ ����������� ������, � ��������� �� ���� (1 ������)
	   	  	else if (ReadNmb==MB_Rd_SysNote) 	{ eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSysNoteStart,MB_NumbSysNote,RT_WAITING_FOREVER);}		// ������ ��������� ������ � ������� �������
	   	  	else if (ReadNmb==MB_Rd_ErrorNote) 	{ eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usErrorNoteStart,MB_NumbErrorNote,RT_WAITING_FOREVER);}	// ������ ��������� ������ � ������� ������

	   	  	else {ReadNmb++;}

//			LimitRead = MB_Rd_EndAddr;
			if (ReadNmb >= MB_Rd_EndAddr) { ReadNmb = MB_Rd_Discreet; osMutexRelease(xIEC850StartMutex);}
			if (IP_ready) {osMutexRelease(xIEC850StartMutex);}

			} else{
				if (sentToBuff == MB_MRE_NO_ERR){
				//	if (writeNmb == MB_Wr_Reset_SysNote ) 	ReadNmb = MB_Rd_Discreet;	//MB_Rd_SysNote;//ReadNmb = 10;			// ���� ���� ������ � ������� ������ �� ���� ��������� �������. ����� ��� ����������. �� ������� �������� ������ � �������
				//	if (writeNmb == MB_Wr_Reset_ErrorNote) ReadNmb = MB_Rd_ErrorNote;		// �������� ���� �������� ����
					writeNmb = MB_Wr_none;
				}
			}

/*******************************************************
* ��������� ������������ ������� ���������
*******************************************************/

if(IEC850TaskHandle && (iedServer != NULL)){

            IedServer_lockDataModel(iedServer);																	// ����������� ���������� mmsServer'��

//			vTaskDelay(15);
// PROT_UPTOV ------
					Set_UPTOV(4,currentTime);
// PROT_UPTUV ------
					Set_UPTUV(4,currentTime);
// PROT_U2PTOV ------
					Set_U2PTOV(2,currentTime);
// PROT_U0PTOV ------
					Set_U0PTOV(4,currentTime);
// PROT_U1PTUV ------
					Set_U1PTUV(2,currentTime);
// PROT_UPTOF ------
					Set_PTOF(4,currentTime);
// PROT_UPTUF ------
					Set_PTUF(4,currentTime);
// PROT_VZGGIO1..8 ------
					Set_VZGGIO(8,currentTime);

// CTRL_PTRC ------
					Set_PTRC(1,currentTime);

// CTRL_GGIO ------
					Set_XCBRGGIO(1,currentTime);
// MES_MMXU ------
					Set_MMXU(1,currentTime);
// MES_MSQI ------
					Set_MSQI(1,currentTime);

// GGIO_IN24GGIO ------

					Set_INGGIO(8,currentTime);
					Set_OUTGGIO(16,currentTime);
					Set_LEDGGIO(12,currentTime);
					Set_SSLGGIO(24,currentTime);
					Set_VLSGGIO(8,currentTime);
					Set_LSGGIO(8,currentTime);

// LD0 SG
					Set_SG(0,currentTime);

    IedServer_unlockDataModel(iedServer);																// ����� ���������� mmsServer'��
}
/*******************************************************
 *
 *******************************************************/
	}
		if (sentToBuff == MB_MRE_NO_ERR){
	//		if (writeNmb == MB_Wr_Reset_SysNote ) 	ReadNmb = MB_Rd_Discreet;		//MB_Rd_SysNote;//ReadNmb = 10;			// ���� ���� ������ � ������� ������ �� ���� ��������� �������. ����� ��� ����������. �� ������� �������� ������ � �������
	//		if (writeNmb == MB_Wr_Reset_ErrorNote) 	ReadNmb = MB_Rd_ErrorNote;		// �������� ���� �������� ����
			if (writeNmb == MB_Wr_Set_Time) 		writeNmb = MB_Wr_none;
			if (writeNmb == MB_Wr_Reset_SysNote)	writeNmb = MB_Wr_none;
			writeNmb = MB_Wr_none;
		}

			errorType = eMBMasterPoll();						// ��������� ������� �� MODBUS.
			if (errorType == MB_ETIMEDOUT){
				USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
				 switch (ReadNmb){
					case 2:
						cntErrorMD.errAnalog++;
						break;
					case 1:
						cntErrorMD.errDiscreet++;
						break;
					default:
						cntErrorMD.errSW++;
						break;
					}
				vTaskDelay(5);									// ������ �����, �� �������� ������� ������.
				Port_On(LED_out_RED);
	//    		ReadNmb++;
				GLOBAL_QUALITY =  QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
				Port_Off(LED1);
			}else
			if (errorType == MB_ENOERR || errorType == MB_ESENT){
//				if (writeNmb == MB_Wr_Set_Time) {writeNmb = MB_Wr_none;}
	//	   		USART_TRACE_RED("MB_ENOERR: %u\n",ReadNmb);
				Nextread = true;	// ������� ������
			}else
			if (errorType == MB_ERECVDATA){
				Port_On(LED_out_GREEN);
				Port_Off(LED_out_RED);
				GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
				//vTaskDelay(5);									// ������ �����, �� �������� ������� ������.
				Nextread = true;
			}else
				if (errorType == MB_NOTASK){
					Nextread = true;
				}

		taskYIELD();										// �������� ������.
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
	eMBErrorCode		errorType;
	uint8_t				i;
	RTC_TimeTypeDef 	Time;
	uint8_t  			PerForSynch;
	uint8_t				CurrSG;
	uint8_t				LimitRead=0xFE;
	uint64_t 			currentTime;
	extern const uint8_t userConfig[];

//	osMutexWait(xIEC850StartMutex, osWaitForever);				// ������� ������� ��� ���������� TCP ���� �� ������� ��������� IP
//	USART_TRACE_BLUE("MODBUS ������ ������� IEC850Start\n");

//	usMDiscInStart = MB_StartDiscreetaddr;

	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();

//	vTaskDelay(1000);
	writeNmb = MB_Wr_none;
	ReadNmb = MB_Rd_Revision;

	Port_On(LED1);
/*
	{
		uint8_t 			HardFaultcnt;												// ������� ������������
		memory_read((uint8_t *)&HardFaultcnt,_IfHardFault,sizeof(HardFaultcnt));						// ������ IP �� ������� ������
		HardFaultcnt++;
		memory_write_to_mem((uint8_t *)&HardFaultcnt,_IfHardFault,sizeof(HardFaultcnt));
		USART_TRACE_GREEN("����� ��������: %u\n",HardFaultcnt);
	}
*/
	TimerReadMB = HAL_GetTick();
	for(;;)
	{
 //		IedServer_setControlHandler(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1, (ControlHandler)controlListener, &iedModel_GGIO_OUTGGIO1_SPCSO1);

		// ����������� ��� ��������� ����� �� ����� ��� �����, � ����� ���������
	 	if (writeNmb == MB_Wr_Set_Time) {
				USART_TRACE_GREEN("1.��������� ����� � �������.\n");
				Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
				eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
		   	   	}
	 	else
		if (((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS)||(Nextread)){		// ������������� ����� MODBUS � �������� MB_PerForReadMODBUS(��)
			Nextread = false;
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>MB_Rd_Analog && ReadNmb<MB_Rd_AllUstavki)ReadNmb = MB_Rd_Discreet;

			//--------------- ������������� ����� ------------------------------------
			if ((ReadNmb == MB_Rd_Discreet) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = MB_Rd_AllUstavki;			// ������ ���

			//--------------- ����������� ------------------------------------
	   	   	if (writeNmb == MB_Wr_SwON) {
	   	   		USART_TRACE_GREEN("����������� ON\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwON,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_SwOFF) {
	   	   		USART_TRACE_RED("����������� OFF\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwOFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}

	   	   	if (writeNmb == MB_Wr_Reset_LEDS) {
	   	   		USART_TRACE_RED("����� ���������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_Reset_Error) {
	   	   		USART_TRACE_RED("����� ����� �������������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������� \n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_Reset_ErrorNote) {
	   	   		USART_TRACE_RED("����� ����� ����� ������ � ������� ������\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_SG_set_0) {
	   	   		USART_TRACE_RED("������������ ������ ������� 0.\n");
	   	   		eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_addr_SG,MB_selectGroupe0,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_SG_set_1) {
	   	   		USART_TRACE_RED("������������ ������ ������� 1.\n");
	   	   		eMBMasterReqWriteHoldingRegister(MB_Slaveaddr,MB_addr_SG,MB_selectGroupe1,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == MB_Wr_Reset_SysNote) {
	   	   		USART_TRACE_RED("����� ������ ������� �������.\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	 	if (writeNmb == MB_Wr_Set_Time) {
				USART_TRACE_GREEN("2.��������� ����� � �������.\n");
				Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
				eMBMasterReqWriteMultipleHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate*2, (USHORT *)&ucMDateBuf,RT_WAITING_FOREVER);
			}
			currentTime = Hal_getTimeInMs();

			//--------------- ���� ������ -----------------------------------------
	   	   	if (writeNmb == MB_Wr_none){	// ������ ��� ������� ��������.
				Port_Off(LED_out_GREEN);
			//--------------- ������������� ����� ������ ���� �� �������� NTP -----
			 if(SNTP_Period == 0){
				if ((currentTime > nextSynchTime) && resynch) {					//���� ������ ��� �� ������ ������������� �����
					ReadNmb = MB_Rd_EndAddr;
					eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);
					USART_TRACE_BLUE("����������������� �����. �����:0x%X\n",(unsigned int)currentTime);
				}
			 }

			// ������� ����� ������ ������ ��� ������ �� ������� ��������, �������� ���� ������� ������
			if (ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSettingGr){
				usConfigStartMTZ 	= MB_StartConfigMTZ_SG1;
				usConfigStartI2I1I0	= MB_StartConfigI2I1I0_SG1;
			}
			 else{
				usConfigStartMTZ 	= MB_StartConfigMTZ_SG0;
				usConfigStartI2I1I0	= MB_StartConfigI2I1I0_SG0;
			 }

			// ������ ������, ����� ������� �������� �������
	   	   	if (ReadNmb==MB_Rd_Revision){eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);getJurnals = true;}							// ������ ������� ����������
			// ������������� ������
	   	   	else if (ReadNmb==MB_Rd_Discreet){
	   	   		eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);
	   	   	}
	   	   	else if (ReadNmb==MB_Rd_Analog)  {
	   			eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);
	   		}

	   		// ����������� ������
	   	   	else if (ReadNmb==MB_Rd_AllUstavki)	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);	// ������ ���������� ����
	   	   	else if (ReadNmb==11) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);						// ������ �������� �������
	   	   	else if (ReadNmb==12) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSystemCfgStart,MB_NumbSystemCfg,RT_WAITING_FOREVER);				// ������ ������������ �������
	   	   	else if (ReadNmb==13) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigUstavkiStart,MB_NumbUstavki,RT_WAITING_FOREVER);			// ������ �������
	   	   	else if (ReadNmb==14) 	eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartSWCrash,MB_NumbSWCrash,RT_WAITING_FOREVER);			// ������ ������� �����������
	   	   	else if (ReadNmb==15) 	ReadNmb = 19;	// ������� � 20

	   	   	else if (ReadNmb==20) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartSW,MB_NumbConfigSW,RT_WAITING_FOREVER);}				// ������ ������������ �����������
	   	  	else if (ReadNmb==21) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigOutStart,MB_NumbConfigOut,RT_WAITING_FOREVER);}			// ������ ������������ �������� ��������
	   	  	else if (ReadNmb==22) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigAutomatStart,MB_NumbAutomat,RT_WAITING_FOREVER);}			// ������ ������������ ����������
	   	  	else if (ReadNmb==23) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartExZ,MB_NumbConfigExZ,RT_WAITING_FOREVER);}			// ������ ������������ ������� �����
	   	  	else if (ReadNmb==24) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartMTZ,MB_NumbConfigMTZ,RT_WAITING_FOREVER);}			// ������ ������������ ������� �����
	   	  	else if (ReadNmb==25) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartI2I1I0,MB_NumbConfigI2I1I0,RT_WAITING_FOREVER);}		// ������ ������������ �������������� �����
	   	  	//else if (ReadNmb==26) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartF,MB_NumbConfigF,RT_WAITING_FOREVER);}				// ������ ������������ ������ �� �������
	   	  	//else if (ReadNmb==27) { eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usConfigStartU,MB_NumbConfigU,RT_WAITING_FOREVER);}				// ������ ������������ ������ �� ����������
	   	   	else if (ReadNmb==26) {
	   	   			if (getJurnals) {ReadNmb = MB_Rd_Discreet;/*MB_Rd_SysNote;*/}						//���� ������ ��������� �������� �������
	   	   			else			ReadNmb = MB_Rd_Discreet;						//����� � ����
	   	   	}

	   		// ������ ������ ����������� ������, � ��������� �� ���� (1 ������)
	   	  	else if (ReadNmb==MB_Rd_SysNote) 	{ eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usSysNoteStart,MB_NumbSysNote,RT_WAITING_FOREVER);}		// ������ ��������� ������ � ������� �������
	   	  	else if (ReadNmb==MB_Rd_ErrorNote) 	{ eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usErrorNoteStart,MB_NumbErrorNote,RT_WAITING_FOREVER);}	// ������ ��������� ������ � ������� ������

	   	  	else {ReadNmb++;}

//			LimitRead = MB_Rd_EndAddr;
			if (ReadNmb >= MB_Rd_EndAddr) { ReadNmb = MB_Rd_Discreet; osMutexRelease(xIEC850StartMutex);}
			if (IP_ready) {osMutexRelease(xIEC850StartMutex);}

			} else{
				if (writeNmb == MB_Wr_Reset_SysNote ) 	ReadNmb = MB_Rd_SysNote;//ReadNmb = 10;			// ���� ���� ������ � ������� ������ �� ���� ��������� �������. ����� ��� ����������. �� ������� �������� ������ � �������
				if (writeNmb == MB_Wr_Reset_ErrorNote) ReadNmb = MB_Rd_ErrorNote;		// �������� ���� �������� ����
				writeNmb = MB_Wr_none;
			}

/*******************************************************
* ��������� ������������ ������� ���������
*******************************************************/

if(IEC850TaskHandle && (iedServer != NULL)){

            IedServer_lockDataModel(iedServer);																	// ����������� ���������� mmsServer'��

// PROT_IPTOC1..8 ------
					Set_IPTOC(4,currentTime);
// PROT_I20PTOC1 ------
					Set_I2PTOC(2,currentTime);
					Set_I0PTOC(2,currentTime);
// Set_INPTOC ------
					Set_INPTOC(2,currentTime);
// Set_IGPTOC ------
					Set_IGPTOC(1,currentTime);
// Set_I2I1PTOC ------
					Set_I2I1PTOC(1,currentTime);
// PROT_VZGGIO1..8 ------
					Set_VZGGIO(8,currentTime);
// PROT_FLSGGIO
					//Set_FLSGGIO(1,currentTime);			//??


// PROT_RREC ------
					Set_RREC(1,currentTime);
// PROT_FRREC ------
					Set_FRREC(1,currentTime);

// PROT_AVRGGIO ------
					Set_AVRGGIO(1,currentTime);
// Set_LZSHPTOC ------
					Set_LZSHPTOC(1,currentTime);
// PROT_RBRF ------
					Set_RBRF(1,currentTime);

// CTRL_CSWI ------
					Set_CSWI(1,currentTime);
// CTRL_XCBR ------
					Set_XCBR(1,currentTime);
// CTRL_PTRC ------
					Set_PTRC(1,currentTime);

// CTRL_GGIO ------
					Set_XCBRGGIO(1,currentTime);
// MES_MMXU ------
					Set_MMXU(1,currentTime);
// MES_MSQI ------
					Set_MSQI(1,currentTime);

// GGIO_IN24GGIO ------
					Set_INGGIO(16,currentTime);
					Set_OUTGGIO(8,currentTime);
					Set_LEDGGIO(12,currentTime);
					Set_SSLGGIO(24,currentTime);
					Set_VLSGGIO(8,currentTime);
					Set_LSGGIO(8,currentTime);

// LD0 SG
					Set_SG(0,currentTime);

    IedServer_unlockDataModel(iedServer);																// ����� ���������� mmsServer'��
}
/*******************************************************
 *
 *******************************************************/
	}
			errorType = eMBMasterPoll();						// ��������� ������� �� MODBUS.
			if (errorType == MB_ETIMEDOUT){
				USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
				 switch (ReadNmb){
					case 2:
						cntErrorMD.errAnalog++;
						break;
					case 1:
						cntErrorMD.errDiscreet++;
						break;
					default:
						cntErrorMD.errSW++;
						break;
					}
				vTaskDelay(5);									// ������ �����, �� �������� ������� ������.
				Port_On(LED_out_RED);
	//    		ReadNmb++;
				GLOBAL_QUALITY =  QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
				Port_Off(LED1);
			}else
			if (errorType == MB_ENOERR || errorType == MB_ESENT){
				if (writeNmb == MB_Wr_Set_Time) {writeNmb = MB_Wr_none;}
	//	   		USART_TRACE_RED("MB_ENOERR: %u\n",ReadNmb);
			}else
			if (errorType == MB_ERECVDATA){
				Port_On(LED_out_GREEN);
				Port_Off(LED_out_RED);
				GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
				vTaskDelay(5);									// ������ �����, �� �������� ������� ������.
				Nextread = true;
			}

		taskYIELD();										// �������� ������.
	}
}
#endif

/*************************************************************************
 * ���������� ������������
 *************************************************************************/
void	CSWI_Pos_Oper_Set(bool newState, uint64_t timeStamp){
#if defined (MR771)
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal, newState)){
    }
    if (newState) writeNmb = MB_Wr_SwON; else writeNmb = MB_Wr_SwOFF;
#endif
/*************************************************************************
 * MR761 MR762 MR763
 *************************************************************************/
#if defined (MR761) || defined (MR762) || defined (MR763)
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal, newState)){
    }
    if (newState) writeNmb = MB_Wr_SwON; else writeNmb = MB_Wr_SwOFF;
#endif
#if defined (MR801)
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal, newState)){
    }
    if (newState) writeNmb = MB_Wr_SwON; else writeNmb = MB_Wr_SwOFF;
#endif
#if defined (MR901)
#endif
#if defined (MR902)
#endif
#if defined (MR5_700)
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal, newState)){
    }

    if (newState) writeNmb = MB_Wr_SwON; else writeNmb = MB_Wr_SwOFF;
#endif
#if defined (MR5_500)
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal, newState)){
    }
    if (newState) writeNmb = MB_Wr_SwON; else writeNmb = MB_Wr_SwOFF;
#endif
}
/*************************************************************************
 * ���������� ��������
 *************************************************************************/
#if defined (MR851)
void	ATCC_TapChg_Pos_Oper_Set(uint16_t newState, uint64_t timeStamp){
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_TapChg_Oper_T, timeStamp);
    IedServer_updateInt32AttributeValue(iedServer, &iedModel_RPN_ATCC1_TapChg_Oper_ctlVal, newState);

    switch	(newState){
    case	STVALBITSTRING_STOP:
    	break;
    case	STVALBITSTRING_HIGHER:
    	writeNmb = 7;
    	break;
    case	STVALBITSTRING_LOWER:
    	writeNmb = 8;
    	break;
    }
}
/*************************************************************************
 * ������������� �����
 *************************************************************************/
void	ATCC_ParOp_Pos_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_ParOp_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_RPN_ATCC1_ParOp_Oper_ctlVal, 0);
    if (newState) writeNmb = MB_Wr_Set_ExtMode;
    else		  writeNmb = MB_Wr_Clr_ExtMode;
}
#endif

/*************************************************************************
 * ������� ������ ������ � ���������
 *************************************************************************/
void	GGIO_LEDGGIO1_SPCSO1_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal, 0);
    if (newState) writeNmb = MB_Wr_LEDS_OFF; //3

}

void	GGIO_SPCSO1_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal, 0);
    if (newState) writeNmb = MB_Wr_Error_OFF; //4

}
void	GGIO_SPCSO2_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal, 0);
    if (newState) writeNmb = MB_Wr_SysNote_OFF; //5

}
void	GGIO_SPCSO3_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal, 0);
    if (newState) writeNmb = MB_Wr_BLK_OFF; //6

}
