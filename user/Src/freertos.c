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

#include "datatoPTOC.h"					// модификация данных в PTOC
#include "datatoPTOV.h"					// модификация данных в PTOV PTUV
#include "datatoPTOF.h"					// модификация данных в PTOF PTUF
#include "datatoGGIO.h"					// модификация данных в
#include "datatoPDIF.h"					// модификация данных в
#include "datatoPDIS.h"
#include "datatoPTTR.h"
#include "datatoRREC.h"					// модификация данных в
#include "datatoCSWI.h"					// модификация данных в
#include "datatoPTRC.h"					// модификация данных в
#include "datatoMMXU.h"
#include "datatoMSQI.h"
#include "datatoRFLO.h"
#include "datatoPDPR.h"
#include "datatoATTC.h"
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

/* TFTP сервер для работы с файлами ------------------------------------------*/
#include "tftpServer.h"

/* FTP сервер для работы с файлами -------------------------------------------*/
#include "ftpServer.h"

/* FS совмесный доступ к файлам ----------------------------------------------*/
#include "fsdata.h"
#include "filesystem.h"

/* NTP клиент  ---------------------------------------*/
#include "sntpclient.h"

/* Variables -----------------------------------------------------------------*/
osMutexId xFTPStartMutex;				// мьютекс готовности к запуску FTP
osMutexDef(xFTPStartMutex);

osMutexId xIEC850StartMutex;			// мьютекс готовности к запуску TCP/IP
osMutexDef(xIEC850StartMutex);

// мьютексы -----------------------------
static xSemaphoreHandle xConsoleMutex = NULL;			// мьютекс печати в консоль

extern uint16_t		GLOBAL_QUALITY;
extern uint16_t		TIMEOUT_MB_FOR_QUALITY;

extern IedServer 	iedServer;
extern uint16_t		SNTP_Period;
extern int16_t		lostSNTPPackets;

extern uint64_t 	nextSynchTime;
//extern uint32_t 	nextSynchTime;
extern bool 		resynch;

extern bool			NextPacketIgnor;			// игнорирование пакета после срочного сообщения, могут быть ложные данные.

// переделать структуру под формат данных запроса MODBUS
	typedef struct					// для передачи через очереди структур.
	{
	  MBFrame	MBData;
	  uint8_t 	Source;
	} xData;

// очереди -----------------------------
xQueueHandle 	ModbusSentTime;			// очередь для отправки в модбас
xQueueHandle 	ModbusSentQueue;		// очередь для отправки в модбас

xQueueHandle 	ModbusResponseQueue;	// очередь для отправки в модбас

xQueueHandle 	Rd_SysNoteQueue;		// очередь для запросов журналу системы
xQueueHandle 	Rd_ErrorNoteQueue;		// очередь для запросов журналу аварий
xQueueHandle 	Rd_OscNoteQueue;		// очередь для запросов журналу осциллографа
xQueueHandle 	Rd_FileQueue;			// очередь для запросов файлов
xQueueHandle 	Rd_UstavkiQueue;		// очередь для запросов уставок

xQueueHandle	xDebugUsartOut;			// очередь для отправки в юсартдебаг


osThreadId defaultTaskHandle;
osThreadId IEC850TaskHandle;
osThreadId MBUSTaskHandle;
osThreadId CONSOLETaskHandle;
osThreadId DEBUGUSARTOUTTaskHandle;


extern 	RTC_HandleTypeDef hrtc;

//  --------------------------------------------------------------------------------
bool				SetTimeNow = false;

int8_t				Nextread = 0;
uint16_t			NumbBlokReadMB = 0;	// куски
uint8_t				writeNmb;
uint8_t	  			writeNmbSG;			// номер группы уставок.

uint16_t			GlobalAddrSysNote=0;
uint16_t			GlobalAddrErrorNote=0;
uint16_t			GlobalAddrOscNote=0;

bool				NewSysNoteMessage = false;
bool				NewErrorNoteMessage = false;

errMB_data			cntErrorMD;
uint32_t			cntMBmessage=0;					// счетчик пакетов с MB.

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

// журнал осциллограмм -----------------------
extern uint16_t   usOscNoteStart;

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigUstavkiStart;			// группа уставок
extern uint16_t   usConfigOtherUstavkiStart;	// группа общих уставок

extern uint16_t   usConfigAutomatStart;			// параметры автоматики
extern uint16_t   usSystemCfgStart;				// параметры системы
extern uint16_t   usConfigTRMeasStart;			// конфигурация измерительного транса
extern uint16_t   usSGStart;					// параметры группы уставок
extern uint16_t   usRPNStart;

extern uint16_t   usConfigOutStart;
extern uint16_t   usConfigStartExZ;
extern uint16_t   usConfigStartF;
extern uint16_t   usConfigStartU;
extern uint16_t   usConfigStartMTZ;
extern uint16_t   usConfigStartI2I1I0;


extern uint16_t   usConfigStartSW;			// конфигурация Выключателя
extern uint16_t   usConfigStartSWCrash;		// ресурс выключателя

extern uint16_t   usConfigAPWStart;			// конфигурация АПВ								801
extern uint16_t   usConfigAWRStart;			// конфигурация АВР								801
extern uint16_t   usConfigTRPWRStart;		// конфигурация силового транса					801
extern uint16_t   usConfigVLSInStart;		// конфигурация входных логических сигналов		801
extern uint16_t   usConfigVLSOutStart;		// конфигурация выходных логических сигналов	801

extern uint16_t   ucRPNBuf[MB_NumbRPN];
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucSGBuf[MB_NumbSG];
extern uint16_t   ucSWCrash[MB_Size_SWCrash];

extern uint16_t   usStartGoose;					// база гусов для отправки
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

	USART_TRACE_BLUE("Рестарт. \n");
	NVIC_SystemReset();

}
/*************************************************************************
 * FREERTOS_Init
 *************************************************************************/
void FREERTOS_Init(void) {
 size_t	fre;

 /* BEGIN RTOS_MUTEX */
	xConsoleMutex 			= osMutexCreate(NULL);							// Создадим мьютекс для блокировки доступа к консоли
	xIEC850StartMutex 		= osMutexCreate(NULL);							// Создадим мьютекс для блокировки доступа к TCP/IP таску
	xFTPStartMutex 			= osMutexCreate(NULL);							// Создадим мьютекс для блокировки доступа к FTP таску

	osMutexWait(xIEC850StartMutex,0);										// забрали семафор
	osMutexWait(xFTPStartMutex,0);


	ModbusResponseQueue	= xQueueCreate( 4, sizeof( ModbusHead));			// очередь ответов.
	// очереди по порядку приоритетов
	ModbusSentTime		= xQueueCreate( 10, sizeof(ModbusMessage));			// первоочередная очередь, то что откладывать нельзя даже из-за дискретов
	ModbusSentQueue 	= xQueueCreate( 70, sizeof(ModbusMessage));			// 50 основная очередь
//	Rd_UstavkiQueue		= xQueueCreate( 10, sizeof(ModbusMessage));			// все уставки, пока не использую, хотя будет проще чем читать всё отдельно, но переделывать всё базу анализа
	Rd_SysNoteQueue 	= xQueueCreate( 30, sizeof(ModbusMessage));			// журнал системы 6 записей переполняетсяна старте
	Rd_ErrorNoteQueue 	= xQueueCreate( 30, sizeof(ModbusMessage));			// журнал аварий
	Rd_OscNoteQueue 	= xQueueCreate( 30, sizeof(ModbusMessage));			// осцилл
	Rd_FileQueue 		= xQueueCreate( 20, sizeof(ModbusMessage));			// файловая очередь

	fre = xPortGetFreeHeapSize();
	USART_TRACE("размер кучи:%u байт\n",fre);

	filesystem_init();														// подключаем диски

	osThreadDef(ModBUS, FastMODBUSTask, MODBUSTask__PRIORITY ,0, MODBUSTask_STACK_SIZE);
	MBUSTaskHandle = osThreadCreate(osThread(ModBUS), NULL);

	osThreadDef(m61850, StartIEC850Task,IEC850Task__PRIORITY,0, IEC850_STACK_SIZE);
	IEC850TaskHandle = osThreadCreate(osThread(m61850), NULL);

/**
 * https://github.com/mz-automation/lib60870/blob/master/user_guide.adoc инфа по запуску сервера
 * Для каждого клиента создаёт задачи. Кучу нужно перенести во внешнюю память. Но она медленная пинг 4мс
 */
//	osThreadDef(m60870, StartIEC60870Task,IEC870Task__PRIORITY,0, IEC870_STACK_SIZE);
//	IEC850TaskHandle = osThreadCreate(osThread(m60870), NULL);

	// FTP HTTP SSH
	osThreadDef(FTP, StartFTPTask, FTPTask__PRIORITY ,0, FTPTask_STACK_SIZE);
	MBUSTaskHandle = osThreadCreate(osThread(FTP), NULL);

	// Доступ к файлам
//	osThreadDef(FS, StartFSTask, FSTask__PRIORITY ,0, FSTask_STACK_SIZE);
//	MBUSTaskHandle = osThreadCreate(osThread(FS), NULL);

	// Создаём задачу, которая реализует консоль с помощью USART порта.
//	osThreadDef(CONSOLE, DEBUGConsoleTask, DEBUG_CONSOLE_TASK_PRIORITY ,0, DEBUG_CONSOLE_STACK_SIZE);
//	CONSOLETaskHandle = osThreadCreate(osThread(CONSOLE), NULL);
	// регистрируем команды консоли
//	vRegisterDEBUGCommands();


//	osThreadDef(DEBUG_OUT, DEBUGUSARTOUTTask, DEBUG_USARTOUT_TASK_PRIORITY ,0, DEBUG_USARTOUT_STACK_SIZE);
//	DEBUGUSARTOUTTaskHandle = osThreadCreate(osThread(DEBUG_OUT), NULL);

//	osThreadDef(HTTP, StartHTTPTask, HTTPTask__PRIORITY ,0, HTTPTask_STACK_SIZE);
//	MBUSTaskHandle = osThreadCreate(osThread(HTTP), NULL);

//	osThreadDef(TFTP, StartTFTPTask, TFTPTask__PRIORITY ,0, TFTPTask_STACK_SIZE);
//	MBUSTaskHandle = osThreadCreate(osThread(TFTP), NULL);

 //  fre = xPortGetFreeHeapSize();
 //  USART_TRACE("стек IEC850:%u байт\n",fre_pr - fre);
 //  fre_pr = fre;

/*
  osThreadDef(IEC104, StartIEC104Task, osPriorityAboveNormal,0, 640);//1024
  defaultTaskHandle = osThreadCreate(osThread(IEC104), NULL);
  fre = xPortGetFreeHeapSize();
  USART_TRACE("FreeHeap(IEC104):%u\n",fre);

*/

   fre = xPortGetFreeHeapSize();
   USART_TRACE("осталось %u байт\n",fre);

  /* USER CODE END RTOS_QUEUES */
}

/*******************************************************
 * MODBUS функция обмена.
 * универсальная для всех приборов, берёт задания из 3-х очередей
 * и отправляет их в порт. Приёмник обработчик ответов будет разный для всех приборов.
 *
 *******************************************************/
//TODO: добавить чтение ресурса выключателя, вопрос в периодичности и условиях
void FastMODBUSTask(void const * argument)
{
	eMBErrorCode			errorType 	 = MB_ENOERR;
	eMBMasterReqErrCode		errorSent 	 = MB_MRE_NO_ERR;
	ModbusMessage 			pxTxMessage;
	volatile  uint8_t		MbNmbMessage = 0;

	// счетчики ошибок
	cntErrorMD.errAnalog 	= 0;
	cntErrorMD.errDiscreet 	= 0;
	cntErrorMD.errTx 		= 0;
	cntErrorMD.errALLCRC 	= 0;
	cntErrorMD.errTimeOut	= 0;		// число таймаутов ответов из MB

	USART_TRACE_GREEN("---------------------------------------------\n");
	USART_TRACE_GREEN("Очередь ModbusResponseQueue: 0x%X\n",(unsigned int)ModbusResponseQueue);
	USART_TRACE_GREEN("Очередь ModbusSentTime: 0x%X\n",(unsigned int)ModbusSentTime);
	USART_TRACE_GREEN("Очередь ModbusSentQueue: 0x%X\n",(unsigned int)ModbusSentQueue);
	USART_TRACE_GREEN("Очередь Rd_SysNoteQueue: 0x%X\n",(unsigned int)Rd_SysNoteQueue);
	USART_TRACE_GREEN("Очередь Rd_ErrorNoteQueue: 0x%X\n",(unsigned int)Rd_ErrorNoteQueue);
	USART_TRACE_GREEN("Очередь Rd_OscNoteQueue: 0x%X\n",(unsigned int)Rd_OscNoteQueue);
	USART_TRACE_GREEN("Очередь Rd_FileQueue: 0x%X\n",(unsigned int)Rd_FileQueue);
	USART_TRACE_GREEN("---------------------------------------------\n");


	eMBMasterInit(MB_RTU, 4,MB_Speed,  MB_PAR_NONE);						// старт и ожидание тишины
	eMBMasterEnable();

	ReadAllUstavki(ModbusSentQueue, MB_Slaveaddr);							// чтение всех уставок

	MbNmbMessage = MB_Rd_Discreet;

	vTaskDelay(500);
	for(;;)
	{
		SynchTIME((bool)SNTP_Period);			// монитор синхронизации времени.

		Port_Off(LEDtst0);
		errorType = eMBMasterPoll();			// мониторим события от MODBUS.
		Port_On(LEDtst0);
		if ((errorType != MB_ENOERR) && (errorType !=MB_ERECVDATA)){
			USART_TRACE_RED("1. Ошибка отправки: %s\n",eMB_strerr(errorType));
//TODO: тут обязательно перепоставить запрос не меняя данные в отправном буфере
//			2 раза EV_ERROR_RESPOND_TIMEOUT
//			1 раз  ERROR_RECEIVE_DATA
//          далее вываливаемся сюда и ложим в буфер отправки следующее сообщение

			/*
			USART_TRACE_RED("перепостановка. ");
			{
			  uint8_t	i;
			  USART_0TRACE("Func:0x%.2X, Addr:0x%.2X, Size:0x%.2X - ",pxTxMessage.MBFunct, pxTxMessage.StartAddr, pxTxMessage.SizeMessage );
			  for(i=0;i<8;i++) USART_0TRACE("[0x%.4X] ",pxTxMessage.ucData[i]);
			  USART_0TRACE("\n");
			}
			xQueueSendToFront( ModbusSentQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// передача сообщения
			 */
		}
		// только если всё отлично с состоянием, и он свободен
		if (errorType == MB_ENOERR){

// срочная очередь
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

				//USART_TRACE_GREEN("шлём \n");
				if (errorSent == MB_MRE_NO_ERR) {
					Port_Off(LEDtst0);
					errorType = eMBMasterPoll();	// шлём сразу.
					Port_On(LEDtst0);
					if ((errorType != MB_ENOERR) && (errorType !=MB_ERECVDATA)){
						USART_TRACE_RED("2. Ошибка отправки: %s\n",eMB_strerr(errorType));
					}
					USART_TRACE_GREEN("Задача срочной очереди cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);

				} else{
					xQueueSendToFront( ModbusSentTime, ( void * )&pxTxMessage, portMAX_DELAY);	// не получилось сразу, передача в очередь сообщения в начало
				}
			}
// аналоги,дискреты
//			else
			// в первую очередь смотрим за часами, надо ли их засинхронизировать
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
// всё остальное, менее срочное
			else
			if (MbNmbMessage > MB_Rd_Analog) {
	// общая очередь

				if( xQueueReceive( ModbusSentQueue, &(pxTxMessage),( TickType_t ) 0 ) )		// прием из очереди сообщения
				{
					errorSent = eMBMasterSendMessage(&pxTxMessage,RT_WAITING_FOREVER);
					if (errorSent == MB_MRE_NO_ERR) {
						Port_Off(LEDtst0);
						errorType = eMBMasterPoll();	// шлём сразу.
						if (errorType != MB_ENOERR){
							USART_TRACE_RED("3. Ошибка отправки, перепостановка задачи. %u\n",errorType);
							xQueueSendToBack( ModbusSentQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// передача сообщения в конец очереди
						}else{
						}
						Port_On(LEDtst0);
						MbNmbMessage = MB_Rd_Discreet;
						//USART_TRACE_CYAN("Задача общей очереди cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);
					} else{
						xQueueSendToFront( ModbusSentQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// передача сообщения в начало

					}
				}else

	// журнала систем
				if( xQueueReceive( Rd_SysNoteQueue, &(pxTxMessage),( TickType_t ) 0 ) )
				{
					errorSent = eMBMasterSendMessage(&pxTxMessage,RT_WAITING_FOREVER);
					if (errorSent == MB_MRE_NO_ERR) {
						MbNmbMessage = MB_Rd_Discreet;
						//USART_TRACE_GREEN("Задача журнала системы cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);
					} else{
						xQueueSendToFront( Rd_SysNoteQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// передача сообщения в начало
					}
				}else

	// журнала аварий
				if( xQueueReceive( Rd_ErrorNoteQueue, &(pxTxMessage),( TickType_t ) 0 ) )
				{
					errorSent = eMBMasterSendMessage(&pxTxMessage,RT_WAITING_FOREVER);
					if (errorSent == MB_MRE_NO_ERR) {
						MbNmbMessage = MB_Rd_Discreet;
						//USART_TRACE_GREEN("Задача журнала аварий cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);
					} else{
						xQueueSendToFront( Rd_ErrorNoteQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// передача сообщения в начало
					}
				}
				else
	// осциллограф
				if( xQueueReceive( Rd_OscNoteQueue, &(pxTxMessage),( TickType_t ) 0 ) )
				{
					errorSent = eMBMasterSendMessage(&pxTxMessage,RT_WAITING_FOREVER);
					if (errorSent == MB_MRE_NO_ERR) {
						MbNmbMessage = MB_Rd_Discreet;
						//USART_TRACE_GREEN("Задача осциллографа cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);
					} else{
						xQueueSendToFront( Rd_OscNoteQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// передача сообщения в начало
					}
				}
				else
	// Файлы
				if( xQueueReceive( Rd_FileQueue, &(pxTxMessage),( TickType_t ) 0 ) )
				{
					errorSent = eMBMasterSendMessage(&pxTxMessage,RT_WAITING_FOREVER);
					if (errorSent == MB_MRE_NO_ERR) {
						MbNmbMessage = MB_Rd_Discreet;
						USART_TRACE_GREEN("Задача файлов cmd:%u addr:%.4X size:%u (err:%u)\n",pxTxMessage.MBFunct,pxTxMessage.StartAddr,pxTxMessage.SizeMessage,errorSent);
					} else{
						xQueueSendToFront( Rd_FileQueue, ( void * )&pxTxMessage, portMAX_DELAY);	// передача сообщения в начало
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
	taskYIELD();								// отпустим задачу.

	}// !for(;;)
}
/*************************************************************************
 * Управление выключателем
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
	taskYIELD();										// отпустим задачу.

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
 * Управление приводом
 * наверное новое состояние нужно ставить в положение STOР. т.к. у нас
 * движение по шагам, непрерывного не бывает
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
		AddToQueueMB(ModbusSentQueue, MB_Rd_ConfigRPN		,MB_Slaveaddr);			// ставим задачу вычитать параметры привода РПН

    	break;
    case	STVALBITSTRING_LOWER:
    	AddToQueueMB(ModbusSentQueue, MB_Wrt_DRIVE_DWN		,MB_Slaveaddr);
		AddToQueueMB(ModbusSentQueue, MB_Rd_ConfigRPN		,MB_Slaveaddr);			// ставим задачу вычитать параметры привода РПН

    	break;
    }
}
/*************************************************************************
 * Дистанционный режим
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
 * Команды сброса флагов и индикации
 *************************************************************************/
void	GGIO_LEDGGIO1_SPCSO1_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal, 0);
    if (newState) {
    	AddToQueueMB(ModbusSentQueue, MB_Wrt_Reset_LEDS			,MB_Slaveaddr);						//Сброс индикации ModbusSentQueue
    }
}

void	GGIO_SPCSO1_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal, 0);
    if (newState) {
    	AddToQueueMB(ModbusSentQueue, MB_Wrt_Reset_Error			,MB_Slaveaddr);					//Сброс флага новой неисправности
    }

}
void	GGIO_SPCSO2_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal, 0);
    if (newState) {
		NewSysNoteMessage = false;
       	AddToQueueMB(ModbusSentQueue, MB_Wrt_Reset_SysNote			,MB_Slaveaddr);					//Сброс флага новой записи в журнале системы
    }

}
void	GGIO_SPCSO3_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal, 0);
    if (newState) {
#if defined (MR851)
       	AddToQueueMB(ModbusSentTime, MB_Wrt_Reset_BLK		,MB_Slaveaddr);						//Сброс блокировки
#else
		NewErrorNoteMessage = false;
       	AddToQueueMB(ModbusSentTime, MB_Wrt_Reset_ErrorNote		,MB_Slaveaddr);					//Сброс флага новой записи в журнале аварий
#endif
    }
}

/*************************************************************************
 * синхронизация времени
 * mode - режим синхронизации,
 * 	false - синхронизация из модбас
 * 	true  - синхронизация от NTP сервера
 *
 * 	работаем периодически из модбас, если есть настройки NTP то проверяем пропуски ответов.
 * 	при превышении берём время из модбас.
 *************************************************************************/
void	SynchTIME(bool	mode){

uint64_t 	currTime;
//static uint64_t	nextTestTime;
	//--------------- синхронизация часов только если не работает NTP -----
currTime = Hal_getTimeInMs();

	 if(SNTP_Period == 0){

/*
		if (currTime > nextTestTime) {					//если прошел период то делаем синхронизацию снова
		  nextTestTime = currTime + 1000*10;
		  AddToQueueMB(ModbusSentQueue, 	MB_Wrt_Set_Goose		,MB_Slaveaddr);
		}
*/
		if ((currTime > nextSynchTime) && resynch) {					//если прошел период то делаем синхронизацию снова
//		if (abs(currTime > nextSynchTime) && resynch) {					//если прошел период то делаем синхронизацию снова
			USART_TRACE_BLUE("Пересинхронизация часов по графику. время:0x%X\n",(unsigned int)currTime);
			if (AddToQueueMB(ModbusSentQueue, 	MB_Rd_Get_Time		,MB_Slaveaddr) >=0 )
				nextSynchTime = currTime + msInDay;							// следующая пересинхронизация часов
		}
	 } else
		 // если сервер не отвечает
		 if(lostSNTPPackets>_limitlostSNTPPackets){
			USART_TRACE_BLUE("Пересинхронизация часов после пропусков NTP. время:0x%X\n",(unsigned int)currTime);
			if (AddToQueueMB(ModbusSentQueue, 	MB_Rd_Get_Time		,MB_Slaveaddr) >=0 ){
				lostSNTPPackets = 0;
			}
	 }

}
/*************************************************************************
 * ReadAllUstavki
 * постановка в очередь задач чтения всех уставок.
 *************************************************************************/
void	ReadAllUstavki(xQueueHandle SentQueue, uint8_t	Slaveaddr){

	AddToQueueMB(ModbusSentTime, 	MB_Rd_Get_Time		,Slaveaddr);		// в первую очередь получим время, иначе в структуре абракадабра
	AddToQueueMB(ModbusSentQueue, 	MB_Rd_Revision		,Slaveaddr);		// версию устройства
	AddToQueueMB(ModbusSentQueue, 	MB_Rd_Syscfg		,Slaveaddr);		// конфигурацию и IP адрес

#if defined (MR5_500)
	AddToQueueMB(SentQueue, 	MB_Rd_NumbSG		,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSWCrash	,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSW		,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,Slaveaddr);

//	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // установим 0 адрес
//	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // установим 0 адрес

#endif

#if defined (MR5_600)
	AddToQueueMB(SentQueue, 	MB_Rd_NumbSG		,Slaveaddr);

//	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // установим 0 адрес
//	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // установим 0 адрес


#endif

#if defined (MR5_700) || defined (MR741)
	AddToQueueMB(SentQueue, 	MB_Rd_NumbSG		,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSWCrash	,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSW		,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,Slaveaddr);

//	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // установим 0 адрес
//	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // установим 0 адрес

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
//	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSW		,Slaveaddr);		// в группе уставок
	AddToQueueMB(SentQueue, 	MB_Rd_AllUstavki	,Slaveaddr);

	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_OscNoteAdr0		,MB_Slaveaddr);
	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // установим 0 адрес
	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // установим 0 адрес

	AddToQueueMB(SentQueue, 	MB_Rd_OscNote		,Slaveaddr);		// ставим задачу чтения журнала осцилл.

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
	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // установим 0 адрес
	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // установим 0 адрес

	AddToQueueMB(SentQueue, 	MB_Rd_OscNote		,Slaveaddr);		// ставим задачу чтения журнала осцилл.

#endif
/*******************************************************
 * MR801
 *
 * usConfigAPWStart,MB_NumbConfigAPW			// чтение конфигурации АПВ
 * usConfigAWRStart,MB_NumbConfigAWR			// чтение конфигурации АВР+ЛЗШ
 * usConfigTRPWRStart,MB_NumbConfigTRPWR 		// чтение всех уставок силового транса
 * usConfigTRMeasStart,MB_NumbConfigTRMeas 		// чтение всех уставок измерительного транса
 * MB_StartConfigVLSIn,MB_NumbConfigVLSIn 		// чтение конфигурации входных логических сигналов
 * MB_StartConfigVLSOut,MB_NumbConfigVLSOut
 *
 *******************************************************/
#if defined	(MR801)

	AddToQueueMB(SentQueue, 	MB_Rd_ConfigSWCrash	,Slaveaddr);	// чтение ресурса выключателя

	AddToQueueMB(SentQueue, 	MB_Rd_NumbSG		,Slaveaddr);
//	AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,Slaveaddr);	// индивидуальные для групп
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,Slaveaddr);

	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // установим 0 адрес
	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // установим 0 адрес

#endif
/*******************************************************
 * MR901 MR902
 * // чтение Общих уставок
 * usConfigTRMeasStart,MB_NumbConfigTRMeas 		// чтение всех уставок измерительного транса
 * MB_StartConfigVLSIn,MB_NumbConfigVLSIn 		// чтение конфигурации входных логических сигналов
 * MB_StartConfigVLSOut,MB_NumbConfigVLSOut
 *	MB_Rd_AllUstavki
 *
 *******************************************************/
#if defined	(MR901) || defined	(MR902)

	AddToQueueMB(SentQueue, 	MB_Rd_ConfigTRMeas	,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigVLSIn	,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigVLSOut	,Slaveaddr);

	AddToQueueMB(SentQueue, 	MB_Rd_AllUstavki	,Slaveaddr);	// чтение общих уставок
	AddToQueueMB(SentQueue, 	MB_Rd_NumbSG		,Slaveaddr);

//	AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,Slaveaddr);	// индивидуальные для групп
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,Slaveaddr);

	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // установим 0 адрес
	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // установим 0 адрес

	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_OscNoteAdr0	,MB_Slaveaddr);
	AddToQueueMB(Rd_SysNoteQueue, 	MB_Rd_OscNote		,Slaveaddr);		// ставим задачу чтения журнала осцилл.

#endif
/*******************************************************
 * MR851
 * usRPNStart,MB_NumbRPN
 *******************************************************/
#if defined	(MR851)
	usConfigUstavkiStart = MB_StartUstavkiaddr0;
	AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,Slaveaddr);	// чтение общих уставок
//	AddToQueueMB(SentQueue, 	MB_Rd_NumbSG		,Slaveaddr);
	AddToQueueMB(SentQueue, 	MB_Rd_ConfigRPN		,Slaveaddr);	// 1A00

//	AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,Slaveaddr);	//

	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // установим 0 адрес

#endif

	AddToQueueMB(Rd_SysNoteQueue, 	MB_Rd_SysNote	,Slaveaddr);
#if !defined	(MR851)
	AddToQueueMB(Rd_ErrorNoteQueue, MB_Rd_ErrorNote	,Slaveaddr);
#endif
}
