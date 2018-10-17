/**
  ******************************************************************************
  * File Name          : freertos.c
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

// IEC 60870
#include "iec60870.h"

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
#if defined	(MR741)
#include "static_model_MR741.h"
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

/* TFTP ������ ��� ������ � ������� ------------------------------------------*/
#include "tftpServer.h"

/* FTP ������ ��� ������ � ������� -------------------------------------------*/
#include "ftpServer.h"

/* FS ��������� ������ � ������ ----------------------------------------------*/
#include "fsdata.h"
#include "filesystem.h"

/* NTP ������  ---------------------------------------*/
#include "sntpclient.h"

/* Variables -----------------------------------------------------------------*/
osMutexId xFTPStartMutex;				// ������� ���������� � ������� FTP
osMutexDef(xFTPStartMutex);

osMutexId xIEC850StartMutex;			// ������� ���������� � ������� TCP/IP
osMutexDef(xIEC850StartMutex);

// �������� -----------------------------
static xSemaphoreHandle xConsoleMutex = NULL;			// ������� ������ � �������

extern uint16_t		GLOBAL_QUALITY;
extern uint16_t		TIMEOUT_MB_FOR_QUALITY;

extern IedServer 	iedServer;
extern uint16_t		SNTP_Period;
extern int16_t		lostSNTPPackets;

extern uint64_t 	nextSynchTime;
//extern uint32_t 	nextSynchTime;
extern bool 		resynch;

extern bool			NextPacketIgnor;			// ������������� ������ ����� �������� ���������, ����� ���� ������ ������.

// ���������� ��������� ��� ������ ������ ������� MODBUS
	typedef struct					// ��� �������� ����� ������� ��������.
	{
	  MBFrame	MBData;
	  uint8_t 	Source;
	} xData;

// ������� -----------------------------
xQueueHandle 	ModbusSentTime;			// ������� ��� �������� � ������
xQueueHandle 	ModbusSentQueue;		// ������� ��� �������� � ������

xQueueHandle 	ModbusResponseQueue;	// ������� ��� �������� � ������

xQueueHandle 	Rd_SysNoteQueue;		// ������� ��� �������� ������� �������
xQueueHandle 	Rd_ErrorNoteQueue;		// ������� ��� �������� ������� ������
xQueueHandle 	Rd_OscNoteQueue;		// ������� ��� �������� ������� ������������
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
bool				SetTimeNow = false;

int8_t				Nextread = 0;
uint16_t			NumbBlokReadMB = 0;	// �����
uint8_t				writeNmb;
uint8_t	  			writeNmbSG;			// ����� ������ �������.

uint16_t			GlobalAddrSysNote=0;
uint16_t			GlobalAddrErrorNote=0;
uint16_t			GlobalAddrOscNote=0;

bool				NewSysNoteMessage = false;
bool				NewErrorNoteMessage = false;

errMB_data			cntErrorMD;
uint32_t			cntMBmessage=0;					// ������� ������� � MB.

#if defined (MR771) || \
	defined (MR761) || defined (MR762) || defined (MR763) || \
	defined (MR801) || \
	defined (MR901) || defined (MR902)|| \
	defined (MR851) ||\
	defined (MR5_500) || defined (MR5_600) || defined (MR5_700) ||\
	defined (MR741)


extern uint16_t   usErrorNoteStart;
extern uint16_t   usSysNoteStart;
extern uint16_t   usWrSysNoteStart;

// ������ ������������ -----------------------
extern uint16_t   usOscNoteStart;

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigUstavkiStart;			// ������ �������
extern uint16_t   usConfigOtherUstavkiStart;	// ������ ����� �������

extern uint16_t   usConfigAutomatStart;			// ��������� ����������
extern uint16_t   usSystemCfgStart;				// ��������� �������
extern uint16_t   usConfigTRMeasStart;			// ������������ �������������� ������
extern uint16_t   usSGStart;					// ��������� ������ �������
extern uint16_t   usRPNStart;

extern uint16_t   usConfigOutStart;
extern uint16_t   usConfigStartExZ;
extern uint16_t   usConfigStartF;
extern uint16_t   usConfigStartU;
extern uint16_t   usConfigStartMTZ;
extern uint16_t   usConfigStartI2I1I0;


extern uint16_t   usConfigStartSW;			// ������������ �����������
extern uint16_t   usConfigStartSWCrash;		// ������ �����������

extern uint16_t   usConfigAPWStart;			// ������������ ���								801
extern uint16_t   usConfigAWRStart;			// ������������ ���								801
extern uint16_t   usConfigTRPWRStart;		// ������������ �������� ������					801
extern uint16_t   usConfigVLSInStart;		// ������������ ������� ���������� ��������		801
extern uint16_t   usConfigVLSOutStart;		// ������������ �������� ���������� ��������	801

extern uint16_t   ucRPNBuf[MB_NumbRPN];
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucSGBuf[MB_NumbSG];
extern uint16_t   ucSWCrash[MB_Size_SWCrash];

extern uint16_t   usStartGoose;					// ���� ����� ��� ��������
extern uint16_t   ucGooseBufSent[MB_NumbGoose];
#endif

//  --------------------------------------------------------------------------------

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

extern volatile uint8_t	MAC_ADDR[6];

void 		FREERTOS_Init(void);
extern void vRegisterDEBUGCommands( void );

void 		FastMODBUSTask(void const * argument);

void		SynchTIME(bool	mode);

void		ReadAllUstavki(xQueueHandle SentQueue, uint8_t	Slaveaddr);

/* Hook prototypes */

void ReStartIEC850_task(void) {

	USART_TRACE_BLUE("�������. \n");
	NVIC_SystemReset();

}
/*************************************************************************
 * FREERTOS_Init
 *************************************************************************/
void FREERTOS_Init(void) {
 size_t	fre;

 /* BEGIN RTOS_MUTEX */
	xConsoleMutex 			= osMutexCreate(NULL);							// �������� ������� ��� ���������� ������� � �������
	xIEC850StartMutex 		= osMutexCreate(NULL);							// �������� ������� ��� ���������� ������� � TCP/IP �����
	xFTPStartMutex 			= osMutexCreate(NULL);							// �������� ������� ��� ���������� ������� � FTP �����

	osMutexWait(xIEC850StartMutex,0);										// ������� �������
	osMutexWait(xFTPStartMutex,0);


	ModbusResponseQueue	= xQueueCreate( 4, sizeof( ModbusHead));			// ������� �������.
	// ������� �� ������� �����������
	ModbusSentTime		= xQueueCreate( 10, sizeof(ModbusMessage));			// �������������� �������, �� ��� ����������� ������ ���� ��-�� ���������
	ModbusSentQueue 	= xQueueCreate( 70, sizeof(ModbusMessage));			// 50 �������� �������
//	Rd_UstavkiQueue		= xQueueCreate( 10, sizeof(ModbusMessage));			// ��� �������, ���� �� ���������, ���� ����� ����� ��� ������ �� ��������, �� ������������ �� ���� �������
	Rd_SysNoteQueue 	= xQueueCreate( 30, sizeof(ModbusMessage));			// ������ ������� 6 ������� ��������������� ������
	Rd_ErrorNoteQueue 	= xQueueCreate( 30, sizeof(ModbusMessage));			// ������ ������
	Rd_OscNoteQueue 	= xQueueCreate( 30, sizeof(ModbusMessage));			// ������
	Rd_FileQueue 		= xQueueCreate( 20, sizeof(ModbusMessage));			// �������� �������

	fre = xPortGetFreeHeapSize();
	USART_TRACE("������ ����:%u ����\n",fre);

	filesystem_init();														// ���������� �����

	osThreadDef(ModBUS, FastMODBUSTask, MODBUSTask__PRIORITY ,0, MODBUSTask_STACK_SIZE);
	MBUSTaskHandle = osThreadCreate(osThread(ModBUS), NULL);

	osThreadDef(m61850, StartIEC850Task,IEC850Task__PRIORITY,0, IEC850_STACK_SIZE);
	IEC850TaskHandle = osThreadCreate(osThread(m61850), NULL);

/**
 * https://github.com/mz-automation/lib60870/blob/master/user_guide.adoc ���� �� ������� �������
 * ��� ������� ������� ������ ������. ���� ����� ��������� �� ������� ������. �� ��� ��������� ���� 4��
 */
//	osThreadDef(m60870, StartIEC60870Task,IEC870Task__PRIORITY,0, IEC870_STACK_SIZE);
//	IEC850TaskHandle = osThreadCreate(osThread(m60870), NULL);

	// FTP HTTP SSH
	osThreadDef(FTP, StartFTPTask, FTPTask__PRIORITY ,0, FTPTask_STACK_SIZE);
	MBUSTaskHandle = osThreadCreate(osThread(FTP), NULL);

	// ������ � ������
//	osThreadDef(FS, StartFSTask, FSTask__PRIORITY ,0, FSTask_STACK_SIZE);
//	MBUSTaskHandle = osThreadCreate(osThread(FS), NULL);

	// ������ ������, ������� ��������� ������� � ������� USART �����.
//	osThreadDef(CONSOLE, DEBUGConsoleTask, DEBUG_CONSOLE_TASK_PRIORITY ,0, DEBUG_CONSOLE_STACK_SIZE);
//	CONSOLETaskHandle = osThreadCreate(osThread(CONSOLE), NULL);
	// ������������ ������� �������
//	vRegisterDEBUGCommands();


//	osThreadDef(DEBUG_OUT, DEBUGUSARTOUTTask, DEBUG_USARTOUT_TASK_PRIORITY ,0, DEBUG_USARTOUT_STACK_SIZE);
//	DEBUGUSARTOUTTaskHandle = osThreadCreate(osThread(DEBUG_OUT), NULL);

//	osThreadDef(HTTP, StartHTTPTask, HTTPTask__PRIORITY ,0, HTTPTask_STACK_SIZE);
//	MBUSTaskHandle = osThreadCreate(osThread(HTTP), NULL);

//	osThreadDef(TFTP, StartTFTPTask, TFTPTask__PRIORITY ,0, TFTPTask_STACK_SIZE);
//	MBUSTaskHandle = osThreadCreate(osThread(TFTP), NULL);

 //  fre = xPortGetFreeHeapSize();
 //  USART_TRACE("���� IEC850:%u ����\n",fre_pr - fre);
 //  fre_pr = fre;

/*
  osThreadDef(IEC104, StartIEC104Task, osPriorityAboveNormal,0, 640);//1024
  defaultTaskHandle = osThreadCreate(osThread(IEC104), NULL);
  fre = xPortGetFreeHeapSize();
  USART_TRACE("FreeHeap(IEC104):%u\n",fre);

*/

   fre = xPortGetFreeHeapSize();
   USART_TRACE("�������� %u ����\n",fre);

  /* USER CODE END RTOS_QUEUES */
}

/*******************************************************
 * MODBUS ������� ������.
 * ������������� ��� ���� ��������, ���� ������� �� 3-� ��������
 * � ���������� �� � ����. ������� ���������� ������� ����� ������ ��� ���� ��������.
 *
 *******************************************************/
//TODO: �������� ������ ������� �����������, ������ � ������������� � ��������
void FastMODBUSTask(void const * argument)
{
	eMBErrorCode			errorType 	 = MB_ENOERR;
	eMBMasterReqErrCode		errorSent 	 = MB_MRE_NO_ERR;
	ModbusMessage 			pxTxMessage;
	volatile  uint8_t		MbNmbMessage = 0;

	// �������� ������
	cntErrorMD.errAnalog 	= 0;
	cntErrorMD.errDiscreet 	= 0;
	cntErrorMD.errTx 		= 0;
	cntErrorMD.errALLCRC 	= 0;
	cntErrorMD.errTimeOut	= 0;		// ����� ��������� ������� �� MB

	USART_TRACE_GREEN("---------------------------------------------\n");
	USART_TRACE_GREEN("������� ModbusResponseQueue: 0x%X\n",(unsigned int)ModbusResponseQueue);
	USART_TRACE_GREEN("������� ModbusSentTime: 0x%X\n",(unsigned int)ModbusSentTime);
	USART_TRACE_GREEN("������� ModbusSentQueue: 0x%X\n",(unsigned int)ModbusSentQueue);
	USART_TRACE_GREEN("������� Rd_SysNoteQueue: 0x%X\n",(unsigned int)Rd_SysNoteQueue);
	USART_TRACE_GREEN("������� Rd_ErrorNoteQueue: 0x%X\n",(unsigned int)Rd_ErrorNoteQueue);
	USART_TRACE_GREEN("������� Rd_OscNoteQueue: 0x%X\n",(unsigned int)Rd_OscNoteQueue);
	USART_TRACE_GREEN("������� Rd_FileQueue: 0x%X\n",(unsigned int)Rd_FileQueue);
	USART_TRACE_GREEN("---------------------------------------------\n");


	eMBMasterInit(MB_RTU, 4,MB_Speed,  MB_PAR_NONE);						// ����� � �������� ������
	eMBMasterEnable();

	ReadAllUstavki(ModbusSentQueue, MB_Slaveaddr);							// ������ ���� �������

	MbNmbMessage = MB_Rd_Discreet;

	vTaskDelay(500);
	for(;;)
	{
		SynchTIME((bool)SNTP_Period);			// ������� ������������� �������.

		Port_Off(LEDtst0);
		errorType = eMBMasterPoll();			// ��������� ������� �� MODBUS.
		Port_On(LEDtst0);
		if ((errorType != MB_ENOERR) && (errorType !=MB_ERECVDATA)){
			USART_TRACE_RED("1. ������ ��������: %s\n",eMB_strerr(errorType));
//TODO: ��� ����������� ������������� ������ �� ����� ������ � ��������� ������
//			2 ���� EV_ERROR_RESPOND_TIMEOUT
//			1 ���  ERROR_RECEIVE_DATA
//          ����� ������������ ���� � ����� � ����� �������� ��������� ���������

			/*
			USART_TRACE_RED("��������������. ");
			{
			  uint8_t	i;
			  USART_0TRACE("Func:0x%.2X, Addr:0x%.2X, Size:0x%.2X - ",pxTxMessage.MBFunct, pxTxMessage.StartAddr, pxTxMessage.SizeMessage );
			  for(i=0;i<8;i++) USART_0TRACE("[0x%.4X] ",pxTxMessage.ucData[i]);
			  USART_0TRACE("\n");
			}
			xQueueSendToFront( ModbusSentQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// �������� ���������
			 */
		}
		// ������ ���� �� ������� � ����������, � �� ��������
		if (errorType == MB_ENOERR){

// ������� �������
			if( xQueueReceive( ModbusSentTime, &(pxTxMessage),( TickType_t ) 0 ) )
			{
#if (defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)) || \
	((defined	(MR761) || defined	(MR762) || defined	(MR763)) && (_REVISION_DEVICE <=302)) || (defined	(MR771) && (_REVISION_DEVICE <=106)) ||\
	(defined	(MR801) && (_REVISION_DEVICE <=207))||\
	((defined	(MR901) || defined	(MR902)) && (_REVISION_DEVICE <=206)) ||\
	(defined	(MR851) && (_REVISION_DEVICE <=202))

				errorSent = eMBMasterSendMessage(&pxTxMessage,RT_WAITING_FOREVER);
#else
				errorSent = eMBMasterSendMessage(&pxTxMessage,RT_WAITING_NO);
#endif

				//USART_TRACE_GREEN("��� \n");
				if (errorSent == MB_MRE_NO_ERR) {
					Port_Off(LEDtst0);
					errorType = eMBMasterPoll();	// ��� �����.
					Port_On(LEDtst0);
					if ((errorType != MB_ENOERR) && (errorType !=MB_ERECVDATA)){
						USART_TRACE_RED("2. ������ ��������: %s\n",eMB_strerr(errorType));
					}
					USART_TRACE_GREEN("������ ������� ������� cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);

				} else{
					xQueueSendToFront( ModbusSentTime, ( void * )&pxTxMessage, portMAX_DELAY);	// �� ���������� �����, �������� � ������� ��������� � ������
				}
			}
// �������,��������
//			else
			// � ������ ������� ������� �� ������, ���� �� �� ������������������
			if (MbNmbMessage==MB_Rd_Discreet){
#if (defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)) || \
	((defined	(MR761) || defined	(MR762) || defined	(MR763)) && (_REVISION_DEVICE <=302)) ||\
	(defined	(MR771) && (_REVISION_DEVICE <=106)) ||\
	(defined	(MR801) && (_REVISION_DEVICE <=207))||\
	((defined	(MR901) || defined	(MR902)) && (_REVISION_DEVICE <=206))||\
	(defined	(MR851) && (_REVISION_DEVICE <=202))


				errorSent = eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);
#else
				errorSent = eMBMasterReqReadHoldingRegisterWithAddres(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);
#endif
				if (errorSent == MB_MRE_NO_ERR) MbNmbMessage++;
			}
			else
			if (MbNmbMessage==MB_Rd_Analog)  {
#if (defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)) || \
		((defined	(MR761) || defined	(MR762) || defined	(MR763)) && (_REVISION_DEVICE <=302)) ||\
		(defined	(MR771) && (_REVISION_DEVICE <=106)) ||\
		(defined	(MR801) && (_REVISION_DEVICE <=207))||\
		((defined	(MR901) || defined	(MR902)) && (_REVISION_DEVICE <=206))||\
		(defined	(MR851) && (_REVISION_DEVICE <=202))


				errorSent = eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);
#else
				errorSent = eMBMasterReqReadHoldingRegisterWithAddres(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);
#endif
				if (errorSent == MB_MRE_NO_ERR) MbNmbMessage++;
			}
// �� ���������, ����� �������
			else
			if (MbNmbMessage > MB_Rd_Analog) {
	// ����� �������

				if( xQueueReceive( ModbusSentQueue, &(pxTxMessage),( TickType_t ) 0 ) )		// ����� �� ������� ���������
				{
					errorSent = eMBMasterSendMessage(&pxTxMessage,RT_WAITING_FOREVER);
					if (errorSent == MB_MRE_NO_ERR) {
						Port_Off(LEDtst0);
						errorType = eMBMasterPoll();	// ��� �����.
						if (errorType != MB_ENOERR){
							USART_TRACE_RED("3. ������ ��������, �������������� ������. %u\n",errorType);
							xQueueSendToBack( ModbusSentQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// �������� ��������� � ����� �������
						}else{
						}
						Port_On(LEDtst0);
						MbNmbMessage = MB_Rd_Discreet;
						//USART_TRACE_CYAN("������ ����� ������� cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);
					} else{
						xQueueSendToFront( ModbusSentQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// �������� ��������� � ������

					}
				}else

	// ������� ������
				if( xQueueReceive( Rd_SysNoteQueue, &(pxTxMessage),( TickType_t ) 0 ) )
				{
					errorSent = eMBMasterSendMessage(&pxTxMessage,RT_WAITING_FOREVER);
					if (errorSent == MB_MRE_NO_ERR) {
						MbNmbMessage = MB_Rd_Discreet;
						//USART_TRACE_GREEN("������ ������� ������� cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);
					} else{
						xQueueSendToFront( Rd_SysNoteQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// �������� ��������� � ������
					}
				}else

	// ������� ������
				if( xQueueReceive( Rd_ErrorNoteQueue, &(pxTxMessage),( TickType_t ) 0 ) )
				{
					errorSent = eMBMasterSendMessage(&pxTxMessage,RT_WAITING_FOREVER);
					if (errorSent == MB_MRE_NO_ERR) {
						MbNmbMessage = MB_Rd_Discreet;
						//USART_TRACE_GREEN("������ ������� ������ cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);
					} else{
						xQueueSendToFront( Rd_ErrorNoteQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// �������� ��������� � ������
					}
				}
				else
	// �����������
				if( xQueueReceive( Rd_OscNoteQueue, &(pxTxMessage),( TickType_t ) 0 ) )
				{
					errorSent = eMBMasterSendMessage(&pxTxMessage,RT_WAITING_FOREVER);
					if (errorSent == MB_MRE_NO_ERR) {
						MbNmbMessage = MB_Rd_Discreet;
						//USART_TRACE_GREEN("������ ������������ cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);
					} else{
						xQueueSendToFront( Rd_OscNoteQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// �������� ��������� � ������
					}
				}
				else
	// �����
				if( xQueueReceive( Rd_FileQueue, &(pxTxMessage),( TickType_t ) 0 ) )
				{
					errorSent = eMBMasterSendMessage(&pxTxMessage,RT_WAITING_FOREVER);
					if (errorSent == MB_MRE_NO_ERR) {
						MbNmbMessage = MB_Rd_Discreet;
						USART_TRACE_GREEN("������ ������ cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);
					} else{
						xQueueSendToFront( Rd_FileQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// �������� ��������� � ������
					}
				}
				else{
					MbNmbMessage = MB_Rd_Discreet;
				}
			}

		}//!if (errorType == MB_ENOERR)
 	if (iedServer){
       	IedServer_performPeriodicGooseTasks(iedServer);
 //		IedServer_performPeriodicTasks(iedServer);
 	}

 	//vTaskDelay(5);
	taskYIELD();								// �������� ������.

	}// !for(;;)
}
/*************************************************************************
 * ���������� ������������
 *************************************************************************/
void	CSWI_Pos_Oper_Set(bool newState, uint64_t timeStamp){
/*************************************************************************
 * MR771 MR761 MR762 MR763
 *************************************************************************/
#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763)
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal, newState)){
    }
    if (newState) {
       	AddToQueueMB(ModbusSentTime, MB_Wrt_SwON			,MB_Slaveaddr);//ModbusSentQueue
    }
    else {
    	AddToQueueMB(ModbusSentTime, MB_Wrt_SwOFF			,MB_Slaveaddr);
    }
#endif

#if defined (MR801)
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal, newState)){
    }
    if (newState) {
       	AddToQueueMB(ModbusSentQueue, MB_Wrt_SwON			,MB_Slaveaddr);
    }
    else {
    	AddToQueueMB(ModbusSentQueue, MB_Wrt_SwOFF			,MB_Slaveaddr);
    }
#endif

#if defined (MR901)
#endif

#if defined (MR902)
#endif

#if defined (MR5_700) || defined (MR741)
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal, newState)){
    }

    if (newState){
    	AddToQueueMB(ModbusSentTime, MB_Wrt_SwON			,MB_Slaveaddr);//ModbusSentQueue
    }
    else {
    	AddToQueueMB(ModbusSentTime, MB_Wrt_SwOFF			,MB_Slaveaddr);
    }
	taskYIELD();										// �������� ������.

#endif

#if defined (MR5_500)
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal, newState)){
    }
    if (newState) {
    	AddToQueueMB(ModbusSentTime, MB_Wrt_SwON			,MB_Slaveaddr);//ModbusSentQueue
    }
    else {
    	AddToQueueMB(ModbusSentTime, MB_Wrt_SwOFF			,MB_Slaveaddr);
    }
#endif
}
/*************************************************************************
 * ���������� ��������
 * �������� ����� ��������� ����� ������� � ��������� STO�. �.�. � ���
 * �������� �� �����, ������������ �� ������
 *************************************************************************/
#if defined (MR851)
void	ATCC_TapChg_Pos_Oper_Set(uint16_t newState, uint64_t timeStamp){
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_TapChg_Oper_T, timeStamp);
    IedServer_updateInt32AttributeValue(iedServer, &iedModel_RPN_ATCC1_TapChg_Oper_ctlVal, newState);

    switch	(newState){
    case	STVALBITSTRING_STOP:
    	break;
    case	STVALBITSTRING_HIGHER:
    	AddToQueueMB(ModbusSentQueue, MB_Wrt_DRIVE_UP		,MB_Slaveaddr);
		AddToQueueMB(ModbusSentQueue, MB_Rd_ConfigRPN		,MB_Slaveaddr);			// ������ ������ �������� ��������� ������� ���

    	break;
    case	STVALBITSTRING_LOWER:
    	AddToQueueMB(ModbusSentQueue, MB_Wrt_DRIVE_DWN		,MB_Slaveaddr);
		AddToQueueMB(ModbusSentQueue, MB_Rd_ConfigRPN		,MB_Slaveaddr);			// ������ ������ �������� ��������� ������� ���

    	break;
    }
}
/*************************************************************************
 * ������������� �����
 *************************************************************************/
void	ATCC_ParOp_Pos_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_ParOp_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_RPN_ATCC1_ParOp_Oper_ctlVal, 0);
    if (newState) {
    	AddToQueueMB(ModbusSentQueue, MB_Wrt_Set_ExtMode			,MB_Slaveaddr);
    }
    else		  {
    	AddToQueueMB(ModbusSentQueue, MB_Wrt_Clr_ExtMode			,MB_Slaveaddr);

    }
}
#endif

/*************************************************************************
 * ������� ������ ������ � ���������
 *************************************************************************/
void	GGIO_LEDGGIO1_SPCSO1_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal, 0);
    if (newState) {
    	AddToQueueMB(ModbusSentQueue, MB_Wrt_Reset_LEDS			,MB_Slaveaddr);						//����� ��������� ModbusSentQueue
    }
}

void	GGIO_SPCSO1_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal, 0);
    if (newState) {
    	AddToQueueMB(ModbusSentQueue, MB_Wrt_Reset_Error			,MB_Slaveaddr);					//����� ����� ����� �������������
    }

}
void	GGIO_SPCSO2_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal, 0);
    if (newState) {
		NewSysNoteMessage = false;
       	AddToQueueMB(ModbusSentQueue, MB_Wrt_Reset_SysNote			,MB_Slaveaddr);					//����� ����� ����� ������ � ������� �������
    }

}
void	GGIO_SPCSO3_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal, 0);
    if (newState) {
#if defined (MR851)
       	AddToQueueMB(ModbusSentTime, MB_Wrt_Reset_BLK		,MB_Slaveaddr);						//����� ����������
#else
		NewErrorNoteMessage = false;
       	AddToQueueMB(ModbusSentTime, MB_Wrt_Reset_ErrorNote		,MB_Slaveaddr);					//����� ����� ����� ������ � ������� ������
#endif
    }
}

/*************************************************************************
 * ������������� �������
 * mode - ����� �������������,
 * 	false - ������������� �� ������
 * 	true  - ������������� �� NTP �������
 *
 * 	�������� ������������ �� ������, ���� ���� ��������� NTP �� ��������� �������� �������.
 * 	��� ���������� ���� ����� �� ������.
 *************************************************************************/
void	SynchTIME(bool	mode){

uint64_t 	currTime;
//static uint64_t	nextTestTime;
	//--------------- ������������� ����� ������ ���� �� �������� NTP -----
currTime = Hal_getTimeInMs();

	 if(SNTP_Period == 0){

/*
		if (currTime > nextTestTime) {					//���� ������ ������ �� ������ ������������� �����
		  nextTestTime = currTime + 1000*10;
		  AddToQueueMB(ModbusSentQueue, 	MB_Wrt_Set_Goose		,MB_Slaveaddr);
		}
*/
		if ((currTime > nextSynchTime) && resynch) {					//���� ������ ������ �� ������ ������������� �����
//		if (abs(currTime > nextSynchTime) && resynch) {					//���� ������ ������ �� ������ ������������� �����
			USART_TRACE_BLUE("����������������� ����� �� �������. �����:0x%X\n",(unsigned int)currTime);
			if (AddToQueueMB(ModbusSentQueue, 	MB_Rd_Get_Time		,MB_Slaveaddr) >=0 )
				nextSynchTime = currTime + msInDay;							// ��������� ����������������� �����
		}
	 } else
		 // ���� ������ �� ��������
		 if(lostSNTPPackets>_limitlostSNTPPackets){
			USART_TRACE_BLUE("����������������� ����� ����� ��������� NTP. �����:0x%X\n",(unsigned int)currTime);
			if (AddToQueueMB(ModbusSentQueue, 	MB_Rd_Get_Time		,MB_Slaveaddr) >=0 ){
				lostSNTPPackets = 0;
			}
	 }

}
/*************************************************************************
 * ReadAllUstavki
 * ���������� � ������� ����� ������ ���� �������.
 *************************************************************************/
void	ReadAllUstavki(xQueueHandle SentQueue, uint8_t	Slaveaddr){

	AddToQueueMB(ModbusSentTime, 	MB_Rd_Get_Time		,Slaveaddr);		// � ������ ������� ������� �����, ����� � ��������� �����������
	AddToQueueMB(ModbusSentQueue, 	MB_Rd_Revision		,Slaveaddr);		// ������ ����������
	AddToQueueMB(ModbusSentQueue, 	MB_Rd_Syscfg		,Slaveaddr);		// ������������ � IP �����

#if defined (MR5_500)
	AddToQueueMB(SentQueue, 	MB_Rd_NumbSG		,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSWCrash	,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSW		,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,Slaveaddr);

//	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // ��������� 0 �����
//	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����

#endif

#if defined (MR5_600)
	AddToQueueMB(SentQueue, 	MB_Rd_NumbSG		,Slaveaddr);

//	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // ��������� 0 �����
//	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����


#endif

#if defined (MR5_700) || defined (MR741)
	AddToQueueMB(SentQueue, 	MB_Rd_NumbSG		,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSWCrash	,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSW		,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,Slaveaddr);

//	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // ��������� 0 �����
//	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����

#endif

/*******************************************************
 * MR761 MR762 MR763
 *******************************************************/
#if defined	(MR761) || defined	(MR762) || defined	(MR763)

#if (_REVISION_DEVICE < 303)
//	AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,Slaveaddr);
#endif
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSWCrash	,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_NumbSG		,Slaveaddr);
//	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSW		,Slaveaddr);		// � ������ �������
	AddToQueueMB(SentQueue, 	MB_Rd_AllUstavki	,Slaveaddr);

	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_OscNoteAdr0		,MB_Slaveaddr);
	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // ��������� 0 �����
	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����

	AddToQueueMB(SentQueue, 	MB_Rd_OscNote		,Slaveaddr);		// ������ ������ ������ ������� ������.

#endif
/*******************************************************
 * MR771
 *******************************************************/
#if defined	(MR771)
#if (_REVISION_DEVICE < 107)
	AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,Slaveaddr);
#endif
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSWCrash	,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_NumbSG		,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSW		,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_AllUstavki	,Slaveaddr);

	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_OscNoteAdr0		,MB_Slaveaddr);
	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // ��������� 0 �����
	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����

	AddToQueueMB(SentQueue, 	MB_Rd_OscNote		,Slaveaddr);		// ������ ������ ������ ������� ������.

#endif
/*******************************************************
 * MR801
 *
 * usConfigAPWStart,MB_NumbConfigAPW			// ������ ������������ ���
 * usConfigAWRStart,MB_NumbConfigAWR			// ������ ������������ ���+���
 * usConfigTRPWRStart,MB_NumbConfigTRPWR 		// ������ ���� ������� �������� ������
 * usConfigTRMeasStart,MB_NumbConfigTRMeas 		// ������ ���� ������� �������������� ������
 * MB_StartConfigVLSIn,MB_NumbConfigVLSIn 		// ������ ������������ ������� ���������� ��������
 * MB_StartConfigVLSOut,MB_NumbConfigVLSOut
 *
 *******************************************************/
#if defined	(MR801)

	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSWCrash	,Slaveaddr);	// ������ ������� �����������

	AddToQueueMB(SentQueue, 	MB_Rd_NumbSG		,Slaveaddr);
//	AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,Slaveaddr);	// �������������� ��� �����
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,Slaveaddr);

	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // ��������� 0 �����
	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����

#endif
/*******************************************************
 * MR901 MR902
 * // ������ ����� �������
 * usConfigTRMeasStart,MB_NumbConfigTRMeas 		// ������ ���� ������� �������������� ������
 * MB_StartConfigVLSIn,MB_NumbConfigVLSIn 		// ������ ������������ ������� ���������� ��������
 * MB_StartConfigVLSOut,MB_NumbConfigVLSOut
 *	MB_Rd_AllUstavki
 *
 *******************************************************/
#if defined	(MR901) || defined	(MR902)

	AddToQueueMB(SentQueue, 	MB_Rd_ConfigTRMeas	,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigVLSIn	,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigVLSOut	,Slaveaddr);

	AddToQueueMB(SentQueue, 	MB_Rd_AllUstavki	,Slaveaddr);	// ������ ����� �������
	AddToQueueMB(SentQueue, 	MB_Rd_NumbSG		,Slaveaddr);

//	AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,Slaveaddr);	// �������������� ��� �����
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,Slaveaddr);

	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // ��������� 0 �����
	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����

	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_OscNoteAdr0	,MB_Slaveaddr);
	AddToQueueMB(Rd_SysNoteQueue, 	MB_Rd_OscNote		,Slaveaddr);		// ������ ������ ������ ������� ������.

#endif
/*******************************************************
 * MR851
 * usRPNStart,MB_NumbRPN
 *******************************************************/
#if defined	(MR851)
	usConfigUstavkiStart = MB_StartUstavkiaddr0;
	AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,Slaveaddr);	// ������ ����� �������
//	AddToQueueMB(SentQueue, 	MB_Rd_NumbSG		,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigRPN		,Slaveaddr);	// 1A00

//	AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,Slaveaddr);	//

	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // ��������� 0 �����

#endif

	AddToQueueMB(Rd_SysNoteQueue, 	MB_Rd_SysNote	,Slaveaddr);
#if !defined	(MR851)
	AddToQueueMB(Rd_ErrorNoteQueue, MB_Rd_ErrorNote	,Slaveaddr);
#endif
}
