/*
 * IEC850.c
 *
 *  Created on: 09.12.2015
 *      Author: sagok
 */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "queue.h"
#include "signal.h"

#include "stm32f4xx_hal.h"

#include "main.h"
#include "time.h"
#include "stdlib.h"
#include "string.h"

#include "ethernetif.h"
#include "lwip/tcpip.h"
#include "lwip/tcp.h"
#include "lwip/init.h"
#include "lwip/netif.h"
#include "lwip/api.h"
#include "lwip/sys.h"

#include "lwip/dhcp.h"

// Файловая система
#include "ff.h"
#include "filesystem.h"

/* часы --*/
#include "clocks.h"

/*debuger ------------------------------------------------------------*/
#include "DebugConsole.h"

/*iec850 includes ------------------------------------------------------------*/
#include "iec850.h"

#include "byte_buffer.h"

#include "cotp.h"
#include "iso_session.h"
#include "iso_presentation.h"
#include "iso_connection_parameters.h"
//#include "acse.h"
#include "iso_server.h"
#include "iec61850_server.h"

#include "mms_mapping.h"

#include "iec61850_cdc.h"
#include "hal_thread.h"

#include "mms_server_connection.h"


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
#if defined (MR801)
#include "static_model_MR801.h"
#endif
#if defined (MR851)
#include "static_model_MR851.h"
#endif
#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"
#endif
#if defined (MR761) || defined (MR762) || defined (MR763)
#include "static_model_MR76x.h"
#endif
#if defined	(MR741)
#include "static_model_MR741.h"
#endif
#include "iedserverdataupdate.h"
#include "goose_receiver.h"

/*Modbus includes ------------------------------------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbport.h"
#include "modbus.h"


/* Variables -----------------------------------------------------------------*/
IedServer iedServer = NULL;

/* password "database" */
static char* password1 = "user";
static char* password2 = "admin";

static int running = 0;

uint64_t 	nextSynchTime = 0;
//uint32_t 	nextSynchTime = 0;
bool 		resynch = false;

osThreadId defaultTaskHandle;

/* extern Variables ----------------------------------------------------------*/

extern RTC_TimeTypeDef StartsTime;
extern RTC_DateTypeDef StartsDate;

// сеть
extern volatile uint8_t	MAC_ADDR[6];
extern uint8_t		IP_ADDR[4];
extern uint8_t		NETMASK_ADDR[4];
extern uint8_t		GW_ADDR[4];
extern uint8_t		SNTP_IP_ADDR[4];
extern uint16_t		SNTP_Period;

extern	uint8_t	  writeNmbSG;			// номер группы уставок.

extern struct netif 	gnetif;


extern osMutexId xIEC850StartMutex;
extern osMutexId xFTPStartMutex;				// мьютекс готовности к запуску FTP


extern osSemaphoreId Netif_LinkSemaphore;
extern struct link_str link_arg;
/*  Часы ------------------------------------------------------------*/
extern RTC_HandleTypeDef hrtc;
/*  -----------------------------------------------------------------*/

/*  очередь ---------------------------------------------------------*/
extern	xQueueHandle 	ModbusSentQueue;	// очередь для отправки в модбас
extern xQueueHandle 	ModbusSentTime;		// очередь для отправки в модбас

/*  -----------------------------------------------------------------*/
static bool		clientAuthenticator(void* parameter, AcseAuthenticationParameter authParameter, void** securityToken);
void			controlHandlerForBinaryOutput(void* parameter, MmsValue* value, bool test);

void 			sigint_handler(int signalId);

static void 	Netif_Config(char* ipAddress,char* Mask, char* Gateway);
void 			Network_Start(void);


static bool		activeSgChangedHandler (void* parameter, SettingGroupControlBlock* sgcb,	 uint8_t newActSg, ClientConnection connection);
static bool		editSgChangedHandler (void* parameter, SettingGroupControlBlock* sgcb,  uint8_t newEditSg, ClientConnection connection);
static void		editSgConfirmedHandler(void* parameter, SettingGroupControlBlock* sgcb,	uint8_t editSg);
static void		loadActiveSgValues (int actSG);
static void		loadEditSgValues (int editSG);

/*************************************************************************
 * sigint_handler
 *************************************************************************/
/* Фактически, сигнал — это асинхронное уведомление процесса о каком-либо событии.
 * Когда сигнал послан процессу, операционная система прерывает выполнение процесса.
 * Если процесс установил собственный обработчик сигнала, операционная система
 * запускает этот обработчик, передав ему информацию о сигнале.
 * Если процесс не установил обработчик, то выполняется обработчик по умолчанию.
 */
void
sigint_handler(int signalId)
{
    running = 0;
}
/*************************************************************************
 * connectionHandler
 *************************************************************************/
static void	connectionHandler (IedServer self, ClientConnection connection, bool connected, void* parameter)
{
    if (connected){
    	USART_TRACE_GREEN("Connection opened\n");
    }
    else{
    	USART_TRACE_RED("Connection closed\n");
    }
}
/*************************************************************************
 * StartIEC850Task
 *************************************************************************/
void StartIEC850Task(void const * argument){

// 1. ждем семафора готовности настроек IP
	    osStatus status = osMutexWait(xIEC850StartMutex,TIMEOUT_startServer);		// блокируемся	TIMEOUT_startServer
	    if (status != osOK) {
	    	// не запустился, всё нам конец.
			USART_TRACE_RED("не получили IP. Нет связи MB.\n");
	    }else{
	    	USART_TRACE_GREEN("Получили IP, запускаем сервак.\n");
	    }
		Port_Off(LED_out_RED);

	    Network_Start();

	    // получили время включеня модуля.
		HAL_RTC_GetTime((RTC_HandleTypeDef *)&hrtc, &StartsTime, FORMAT_BIN);
		HAL_RTC_GetDate((RTC_HandleTypeDef *)&hrtc, &StartsDate, FORMAT_BIN);

		iedServer = IedServer_create(&iedModel,(uint16_t)IP_ADDR[3]);			// создадим IED электронное устройство
		//IedServer_setAuthenticator(iedServer, clientAuthenticator, NULL); 	// вкл. парольный доступ

	    // 2. конфигурим сервер открываем порт.
		IsoServer isoServer = IedServer_getIsoServer(iedServer);
		IsoServer_setEthernetParam(isoServer,(char*)IP_ADDR,(char*)NETMASK_ADDR,(char*)GW_ADDR);

    	// разрешаем запуск тасков зависящих от старта текущего таска
		osMutexRelease(xFTPStartMutex);

	    // режим работы свича ----------------------------------------
		PHY_setSwitchMode(isoServer);

	    Port_Off(LED1);
		Port_Off(LED_out_GREEN);

	for(;;) {

		// -------------------------------------------------------------------------------------------------------------------
		// Функции контроля над объектами, при управлении от клиента
		// -------------------------------------------------------------------------------------------------------------------

	    // управление выключателем
#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763) || defined (MR801) ||\
	defined (MR5_500) || defined (MR5_700) || defined (MR741)
	    IedServer_setControlHandler(iedServer, &iedModel_CTRL_CSWI1_Pos, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_CSWI1_Pos_Oper);
	    IedServer_setControlHandler(iedServer, &iedModel_CTRL_XCBR1_Mod,(ControlHandler) controlHandlerForBinaryOutput, &iedModel_CTRL_XCBR1_Mod_Oper);
#endif
	    // управление приводом
#if defined (MR851)
	    IedServer_setControlHandler(iedServer, &iedModel_RPN_ATCC1_TapChg, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_RPN_ATCC1_TapChg_Oper);
	    IedServer_setControlHandler(iedServer, &iedModel_RPN_ATCC1_ParOp, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_RPN_ATCC1_ParOp_Oper);

#endif

		IedServer_setControlHandler(iedServer, &iedModel_CTRL_GGIO1_SPCSO1, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_GGIO1_SPCSO1_Oper);
		IedServer_setControlHandler(iedServer, &iedModel_CTRL_GGIO1_SPCSO2, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_GGIO1_SPCSO2_Oper);
		IedServer_setControlHandler(iedServer, &iedModel_CTRL_GGIO1_SPCSO3, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_GGIO1_SPCSO3_Oper);
		IedServer_setControlHandler(iedServer, &iedModel_CTRL_GGIO1_SPCSO4, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_GGIO1_SPCSO4_Oper);

	    // this is optional - performs operative checks
		// IedServer_setPerformCheckHandler(iedServer, &iedModel_GGIO_INGGIO1_SPCSO1, checkHandler, &iedModel_GGIO_INGGIO1_SPCSO1);
/*****************************************************************************************************
 *
 * многоклиентский доступ
 *
 *****************************************************************************************************/
		while (1){

			IedServer_setConnectionIndicationHandler(iedServer, (IedConnectionIndicationHandler) connectionHandler, NULL);

		#if (CONFIG_MMS_THREADLESS_STACK == 1)
			IedServer_startThreadless(iedServer, 102);		    // настраиваем сервер открываем порт и слушаем соединения.
		#else
			IedServer_start(iedServer, 102);					// MMS server will be instructed to start listening to client connections.
		#endif

			//--------------- SG -------------------------
		    SettingGroupControlBlock* sgcb = LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0);

		    IedServer_setActiveSettingGroupChangedHandler(iedServer, sgcb, activeSgChangedHandler, NULL);
		    IedServer_setEditSettingGroupChangedHandler(iedServer, sgcb, editSgChangedHandler, NULL);
		    IedServer_setEditSettingGroupConfirmationHandler(iedServer, sgcb, editSgConfirmedHandler, NULL);

#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1) && (1)
			//--------------- Goose -------------------------
			// приёмная часть гусов.
		    GooseReceiverFile*	GooseCfgFile = GooseReceiver_ConfigCreate();
		    if (GooseReceiver_ParseConfigFile(GooseCfgFile, _GooseREcfg) == true){
			    GooseReceiver Goosereceiver = GooseReceiver_create();
			    GooseReceiver_addSubscriberFromConfigFile(Goosereceiver,GooseCfgFile);
			    GooseReceiver_start(Goosereceiver);															// стартанём приёмный таск гусов.
		    }
	        //--------------- Goose -------------------------
#endif

			if (!IedServer_isRunning(iedServer)) {
				USART_TRACE_RED("Ошибка запуска сервера! Останов.\n");
				IedServer_destroy(iedServer);
			}else{
				AddToQueueMB(ModbusSentQueue, 	MB_Rd_Revision		,MB_Slaveaddr);		// версию устройства
			}


#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
			//--------------- Goose -------------------------
			// передающая часть гусов. Start GOOSE publishing
		    //if (GoosePublishing_ParseConfigFile(iedServer, _GooseTRcfg) == true){
		    	IedServer_enableGoosePublishing(iedServer);
		    //}
			//--------------- Goose -------------------------
#endif
			running = 1;

			USART_TRACE_BLUE("memory gap = %u\r\n", xPortGetFreeHeapSize());
			USART_TRACE_BLUE("task count = %u\r\n",(unsigned int)uxTaskGetNumberOfTasks());
			static signed char taskInfoBuf[48 * 8];
			vTaskGetRunTimeStats((char *)taskInfoBuf);
			USART_TRACE_BLUE("%s\r\n", taskInfoBuf);

			// сокеты -------
			Print_Sockets();
			// --------------
			while (running) {

				IedServer_processIncomingData(iedServer);						// Должна вызываться периодически для приёма данных и соединений. Отвечаем на запросы тутже
																				// проверяем было ли соединение на сокет?
				// сначала проанализируем данные
				IedServer_PeriodicUpdateNewData(iedServer);						// обновление данных в модели из буферов памяти. занимает много времени.

				// по результату отправим отчёты и остальное
				IedServer_performPeriodicTasks(iedServer);						// Должна вызываться периодически монитор служб 61850
				taskYIELD();													// отпустим задачу.
//				vTaskDelay(1);

			}

			IedServer_stopThreadless(iedServer);								// stop MMS server - close TCP server socket and all client sockets
			IedServer_destroy(iedServer);							    		// Cleanup - free all resources
		}
/*****************************************************************************************************
 *
 * !многоклиентский доступ
 *
 *****************************************************************************************************/
	}
}
/*************************************************************************
 * controlHandlerForBinaryOutput
 *  Функция контроля над бинарным объектом. После изменения этих данных от
 *  клиента, будет вызываться эта функция.
 *************************************************************************/
void	controlHandlerForBinaryOutput(void* parameter, MmsValue* value, bool test)
{
	MmsType		TypeCMD;
	bool 		newState = false;
	uint16_t 	newStateBitstr = 0;
	USART_TRACE_GREEN("controlHandlerForBinaryOutput MMS_BOOLEAN:\n");

	TypeCMD = MmsValue_getType(value);
	switch(TypeCMD){

	case	MMS_BOOLEAN:
		 	 	 	 	 USART_TRACE("принята команда контроля MMS_BOOLEAN:\n");
		 	 	 	 	 if (MmsValue_getBoolean(value))	{USART_TRACE_GREEN("on\n");}
		 	 	 	 	 else  {USART_TRACE_RED("off\n");}

		 	 	 	 	  newState = MmsValue_getBoolean(value);
		break;
	case	MMS_BIT_STRING:
						 newStateBitstr = MmsValue_getBitStringAsInteger(value);
		break;
	default:
		 USART_TRACE_RED("команда не опознана\n");
		break;
	}

	    uint64_t timeStamp = Hal_getTimeInMs();


#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763) ||\
	defined (MR801) ||\
	defined (MR5_700) || defined (MR5_500) || defined (MR741)
	    // выключатель
	    if (parameter == &iedModel_CTRL_CSWI1_Pos_Oper)	{
	    	USART_TRACE_GREEN("команда управления выключателем &iedModel_CTRL_CSWI1_Pos_Oper\n");
	    	CSWI_Pos_Oper_Set(newState, timeStamp);
			AddToQueueMB(ModbusSentQueue, 	MB_Rd_ConfigSWCrash	,MB_Slaveaddr);			// вычитаем ресурс
	    }
#endif
#if defined (MR851)
	    // привод
	    if (parameter == &iedModel_RPN_ATCC1_TapChg_Oper)	{
	    	USART_TRACE_GREEN("команда управления приводом.\n");
	    	ATCC_TapChg_Pos_Oper_Set(newStateBitstr, timeStamp);
	    }
	    if (parameter == &iedModel_RPN_ATCC1_ParOp_Oper)	{
	    	USART_TRACE_GREEN("команда управления дист. режимом.\n");
	    	ATCC_ParOp_Pos_Oper(newState, timeStamp);
	    }
#endif


	    if (parameter == &iedModel_CTRL_GGIO1_SPCSO1_Oper)	{
	    	USART_TRACE_GREEN("Сброс флага новой неисправности\n");
	    	GGIO_SPCSO1_Oper(newState, timeStamp);
	    }
	    if (parameter == &iedModel_CTRL_GGIO1_SPCSO2_Oper)	{
	    	USART_TRACE_GREEN("Сброс флага новой записи в журнале системы\n");
	    	GGIO_SPCSO2_Oper(newState, timeStamp);
	    }
	    if (parameter == &iedModel_CTRL_GGIO1_SPCSO3_Oper)	{
	    	USART_TRACE_GREEN("Сброс блокировки или записи в журнале аварий\n");
	    	GGIO_SPCSO3_Oper(newState, timeStamp);
	    }

	    // Сброс индикации
	    if (parameter == &iedModel_CTRL_GGIO1_SPCSO4_Oper)	{
	    	USART_TRACE_GREEN("Сброс индикации\n");
	    	GGIO_LEDGGIO1_SPCSO1_Oper(newState, timeStamp);
	    }
}

/**
  * @brief  Initializes the lwIP stack
  * @param  None
  * @retval None
  */
static void Netif_Config(char* ipAddress,char* Mask, char* Gateway)
{
  struct ip_addr ipaddr;
  struct ip_addr netmask;
  struct ip_addr gw;

  /* IP address default setting */
  IP4_ADDR(&ipaddr, ipAddress[0], ipAddress[1], ipAddress[2], ipAddress[3]);
  IP4_ADDR(&netmask, Mask[0], Mask[1] , Mask[2], Mask[3]);
  IP4_ADDR(&gw, Gateway[0], Gateway[1], Gateway[2], Gateway[3]);

  USART_TRACE_BLUE("MAC:%.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n",MAC_ADDR[0], MAC_ADDR[1], MAC_ADDR[2], MAC_ADDR[3],MAC_ADDR[4],MAC_ADDR[5]);	// временно чтобы отличались устройства
  USART_TRACE_BLUE("IP:%d.%d.%d.%d \n", ipAddress[0], ipAddress[1], ipAddress[2], ipAddress[3]);
  USART_TRACE_BLUE("Gateway:%d.%d.%d.%d \n",Gateway[0], Gateway[1], Gateway[2], Gateway[3]);


  /* - netif_add(struct netif *netif, struct ip_addr *ipaddr,
  struct ip_addr *netmask, struct ip_addr *gw,
  void *state, err_t (* init)(struct netif *netif),
  err_t (* input)(struct pbuf *p, struct netif *netif))

  Adds your network interface to the netif_list. Allocate a struct
  netif and pass a pointer to this structure as the first argument.
  Give pointers to cleared ip_addr structures when using DHCP,
  or fill them with sane numbers otherwise. The state pointer may be NULL.

  The init function pointer must point to a initialization function for
  your ethernet netif interface. The following code illustrates it's use.*/

  netif_add(&gnetif, &ipaddr, &netmask, &gw, NULL, &ethernetif_init, &tcpip_input);				// ethernetif_init - запуск таска для приема. tcpip_input - функция приема данных

  /*  Registers the default network interface. */
  netif_set_default(&gnetif);

  if (netif_is_link_up(&gnetif))
  {
    /* Когда netif полностью настроен, эта функция должна быть вызвана. */
    netif_set_up(&gnetif);
  }
  else
  {
    /* Когда netif отключена, эту функцию нужно вызвать */
    netif_set_down(&gnetif);
  }

  // функция обработки физических подключений/отключений. По статусу линка
/*
  // ethernetif_update_config - по изменению LINK вызываем
  netif_set_link_callback(&gnetif, ethernetif_update_config);

  // через семафор из прерывания управление
  osSemaphoreDef(Netif_SEM);
  Netif_LinkSemaphore = osSemaphoreCreate(osSemaphore(Netif_SEM) , 1 );

  link_arg.netif = &gnetif;
  link_arg.semaphore = Netif_LinkSemaphore;
  // Create the Ethernet link handler thread
  USART_TRACE_MAGENTA("(LinkThr) Create the Ethernet link handler thread.\n");
#if defined(__GNUC__)
  osThreadDef(LinkThr, ethernetif_set_link, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);	// configMINIMAL_STACK_SIZE * 5 уменьшил
#else
  osThreadDef(LinkThr, ethernetif_set_link, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);
#endif
  osThreadCreate (osThread(LinkThr), &link_arg);
*/
}

/***********************************************************************
 *
 ***********************************************************************/
void Network_Start(void)
{
// проверка на валидность IP адреса
  if (IP_ADDR[0] == 0xFF || IP_ADDR[3] == 0xFF || IP_ADDR[0] == 0 || IP_ADDR[1] == 0 ){
	  IP_ADDR[0] = first_IP_ADDR0;
	  IP_ADDR[1] = first_IP_ADDR1;
	  IP_ADDR[2] = first_IP_ADDR2;
	  IP_ADDR[3] = first_IP_ADDR3;
  }
// проверка на валидность IP NTP адреса
  if (SNTP_IP_ADDR[0] == 0xFF || SNTP_IP_ADDR[3] == 0xFF || SNTP_IP_ADDR[0] == 0 || SNTP_IP_ADDR[1] == 0 ){
	  SNTP_IP_ADDR[0] = NTP_IP_ADDR0;
	  SNTP_IP_ADDR[1] = NTP_IP_ADDR1;
	  SNTP_IP_ADDR[2] = NTP_IP_ADDR2;
	  SNTP_IP_ADDR[3] = NTP_IP_ADDR3;
//			  SNTP_Period = 0;
  }
	MAC_ADDR[0]	= MAC_ADDR0;
	MAC_ADDR[1]	= MAC_ADDR1;
	MAC_ADDR[2]	= MAC_ADDR2;
	MAC_ADDR[3]	= IP_ADDR[1];//MAC_ADDR3;
	MAC_ADDR[4]	= IP_ADDR[2];//MAC_ADDR4;
	MAC_ADDR[5]	= IP_ADDR[3];//IP_ADDR[2];//MAC_ADDR5;

	GW_ADDR[0] = IP_ADDR[0];
	GW_ADDR[1] = IP_ADDR[1];
	GW_ADDR[2] = IP_ADDR[2];
	GW_ADDR[3] = 1;

	// запускаем таск "TCP/IP"
	tcpip_init( NULL, NULL );												// создаем tcp_ip stack, таск TCP/IP
	Netif_Config((char*)IP_ADDR,(char*)NETMASK_ADDR,(char*)GW_ADDR);		// Initialize the LwIP stack

    //netif_set_addr(&gnetif, &first_ipaddr , &netmask, &gw);
    //netif_set_up(&gnetif);
}
/***********************************************************************
 * activeSgChangedHandler
 * изменение номера ActSG группы уставок из ethernet.
 * закидываем команду записи номера в модбас
 ***********************************************************************/
static bool	activeSgChangedHandler (void* parameter, SettingGroupControlBlock* sgcb,	 uint8_t newActSg, ClientConnection connection)
{
	USART_TRACE_BLUE("Switch to setting group %i\n", (int) newActSg);

    loadActiveSgValues(newActSg);

    return true;
}

static bool	editSgChangedHandler (void* parameter, SettingGroupControlBlock* sgcb,  uint8_t newEditSg, ClientConnection connection)
{
	USART_TRACE_BLUE("Set edit setting group to %i\n", (int) newEditSg);

    loadEditSgValues(newEditSg);

    return true;
}
static void	editSgConfirmedHandler(void* parameter, SettingGroupControlBlock* sgcb,	uint8_t editSg)
{
	USART_TRACE_BLUE("Received edit sg confirm for sg %i\n", editSg);

 //    if (IedServer_getActiveSettingGroup(iedServer, sgcb) == editSg) {
 //       loadActiveSgValues(editSg);
 //   }
}
//--------------------------------------------------------------------
static void		loadActiveSgValues (int actSG)
{
#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763) ||\
	defined (MR801) ||\
	defined (MR901) || defined (MR902) ||\
	defined (MR851) ||\
	defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)

		writeNmbSG = actSG;

		AddToQueueMB(ModbusSentTime,  MB_Wrt_SG_set_ManNumb	,MB_Slaveaddr);		// приоритет
//    	AddToQueueMB(ModbusSentQueue, MB_Rd_NumbSG			,MB_Slaveaddr);		// ставим задачу вычитать новые уставки

#endif

	// тут функция переключения группы уставок с вычитыванием всех
  // IedServer_updateInt32AttributeValue(iedServer, &iedModel_LD0_LLN0_RstTms_setVal, 1);
}
//--------------------------------------------------------------------
static void		loadEditSgValues (int editSG)
{
//    IedServer_updateInt32AttributeValue(iedServer, &iedModel_SE_LD0_LLN0_RstTms_setVal, 2);
}


/**
 * This is the AcseAuthenticator callback function that is invoked on each client connection attempt.
 * When returning true the server stack accepts the client. Otherwise the connection is rejected.
 */
static bool
clientAuthenticator(void* parameter, AcseAuthenticationParameter authParameter, void** securityToken)
{
    if (authParameter->mechanism == ACSE_AUTH_PASSWORD) {
        if (authParameter->value.password.passwordLength == strlen(password1)) {
            if (memcmp(authParameter->value.password.octetString, password1,
                    authParameter->value.password.passwordLength) == 0)
            {
                *securityToken = (void*) password1;
                return true;
            }

        }
        if (authParameter->value.password.passwordLength == strlen(password2)) {
            if (memcmp(authParameter->value.password.octetString, password2,
                    authParameter->value.password.passwordLength) == 0)
            {
                *securityToken = (void*) password2;
                return true;
            }
        }
    }

    return false;
}
