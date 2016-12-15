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
#include "static_model.h"
#include "mms_mapping.h"

#include "iec61850_cdc.h"
#include "hal_thread.h"

#include "mms_server_connection.h"

//#include "MmsPdu.h"

#include "goose_receiver.h"
/*Modbus includes ------------------------------------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbport.h"
#include "modbus.h"


#define WEBSERVER_THREAD_PRIO    ( tskIDLE_PRIORITY + 4 )
/* Variables -----------------------------------------------------------------*/
extern volatile uint8_t	MAC_ADDR[6];
extern uint8_t		IP_ADDR[4];
extern uint8_t		NETMASK_ADDR[4];
extern uint8_t		GW_ADDR[4];

//extern IedServer iedServer;
IedServer iedServer = NULL;

static int running = 0;


extern struct netconn *newconn850;
extern struct netif 	gnetif;


extern osMutexId xIEC850StartMutex;
extern osMutexId xIEC850ServerStartMutex;


extern osSemaphoreId Netif_LinkSemaphore;
extern struct link_str link_arg;
/*  Часы ------------------------------------------------------------*/
extern RTC_HandleTypeDef hrtc;
/*  -----------------------------------------------------------------*/

osThreadId defaultTaskHandle;

/*  -----------------------------------------------------------------*/

void			observerCallback(DataAttribute* dataAttribute);
void			controlHandlerForBinaryOutput(void* parameter, MmsValue* value, bool test);

void 			sigint_handler(int signalId);

static void 	Netif_Config(char* ipAddress,char* Mask, char* Gateway);



static bool	activeSgChangedHandler (void* parameter, SettingGroupControlBlock* sgcb,	 uint8_t newActSg, ClientConnection connection);
static bool	editSgChangedHandler (void* parameter, SettingGroupControlBlock* sgcb,  uint8_t newEditSg, ClientConnection connection);
static void	editSgConfirmedHandler(void* parameter, SettingGroupControlBlock* sgcb,	uint8_t editSg);
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
 * gooseListener
 *************************************************************************/
void	gooseListener(GooseSubscriber subscriber, void* parameter)
{
    printf("GOOSE event:\n");
    printf("  stNum: %u sqNum: %u\n", GooseSubscriber_getStNum(subscriber),
            GooseSubscriber_getSqNum(subscriber));
    printf("  timeToLive: %u\n", GooseSubscriber_getTimeAllowedToLive(subscriber));
    printf("  timestamp: %"PRIu64"\n", GooseSubscriber_getTimestamp(subscriber));

    MmsValue* values = GooseSubscriber_getDataSetValues(subscriber);

    char buffer[1024];

    MmsValue_printToBuffer(values, buffer, 1024);

    printf("%s\n", buffer);
}
/*************************************************************************
 * CheckHandlerResult
 *************************************************************************/
static CheckHandlerResult	checkHandler(void* parameter, MmsValue* ctlVal, bool test, bool interlockCheck, ClientConnection connection)
{
    printf("check handler called!\n");

    if (interlockCheck)
        printf("  with interlock check bit set!\n");

    if (parameter == IEDMODEL_GGIO_INGGIO1_SPCSO1)
        return CONTROL_ACCEPTED;

    if (parameter == IEDMODEL_GGIO_INGGIO1_SPCSO2)
        return CONTROL_ACCEPTED;

    if (parameter == IEDMODEL_GGIO_INGGIO1_SPCSO3)
        return CONTROL_ACCEPTED;

    if (parameter == IEDMODEL_GGIO_INGGIO1_SPCSO4)
        return CONTROL_ACCEPTED;

    return CONTROL_OBJECT_UNDEFINED;
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
 * writeAccessHandler
 *************************************************************************/
static MmsDataAccessError	writeAccessHandler (DataAttribute* dataAttribute, MmsValue* value, ClientConnection connection, void* parameter)
{
	/*
    if (dataAttribute == IEDMODEL_Inverter_ZINV1_OutVarSet_setMag_f) { //IEDMODEL_GenericIO_GGIO1_NamPlt_vendor

        float newValue = MmsValue_toFloat(value);

        printf("New value for OutVarSet_setMag_f = %f\n", newValue);

        // Check if value is inside of valid range
        if ((newValue >= 0.f) && (newValue <= 1000.1f))
            return DATA_ACCESS_ERROR_SUCCESS;
        else
            return DATA_ACCESS_ERROR_OBJECT_VALUE_INVALID;

    }
*/
    return DATA_ACCESS_ERROR_OBJECT_ACCESS_DENIED;
}

/*************************************************************************
 * StartIEC850Task
 *************************************************************************/
void StartIEC850Task(void const * argument){

extern osThreadId IEC850TaskHandle;


	iedServer = IedServer_create(&iedModel);	// создадим IED электронное устройство

	osMutexRelease(xIEC850ServerStartMutex);

// 1. ждем семафора готовности настроек IP
	    osStatus status = osMutexWait(xIEC850StartMutex,osWaitForever);		// блокируемся
	    if (status != osOK) {
	    	// не запустился, всё нам конец.
			USART_TRACE_RED("не запустился, всё нам конец.\n");
	    }
	    USART_TRACE_GREEN("Получили IP, запускаем сервак.\n");
	    // 2. конфигурим сервер открываем порт.
		IsoServer isoServer = IedServer_getIsoServer(iedServer);
		IsoServer_setEthernetParam(isoServer,(char*)IP_ADDR,(char*)NETMASK_ADDR,(char*)GW_ADDR);

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

	    tcpip_init( NULL, NULL );									// создаем tcp_ip stack, таск TCP/IP
	    // добавить функцию получения IP
    	Netif_Config((char*)IP_ADDR,(char*)NETMASK_ADDR,(char*)GW_ADDR);		// Initialize the LwIP stack

// 3. Информируем таск модбаса о готовности структуры для ввода данных
	    USART_TRACE_GREEN("Разрешаем доступ к данным сервера 61850\n");
// 4. запускаем стейтмашину 61850
	    USART_TRACE_GREEN("запускаем стейтмашину 61850\n");

	    Port_Off(LED1);

	for(;;) {

		// -------------------------------------------------------------------------------------------------------------------
		// -------------------------------------------------------------------------------------------------------------------
		//iedServer = IedServer_create(&iedModel);								// создадим IED электронное устройство
		// включаем парольный доступ
#ifdef	UseOSmem
		AcseAuthenticationParameter auth = pvPortMalloc(sizeof(AcseAuthenticationParameter));
#else
		AcseAuthenticationParameter auth = malloc(sizeof(AcseAuthenticationParameter));
#endif
		// server_example4
		char* password = "testpw";
	    auth->mechanism = ACSE_AUTH_PASSWORD;
	    auth->value.password.octetString = (uint8_t*) password;
	    auth->value.password.passwordLength = strlen(password);
	    //пароль
//		IsoServer_setAuthenticationParameter(isoServer, auth);

		// -------------------------------------------------------------------------------------------------------------------
		// Функции контроля над объектами, при управлении от клиента
		// -------------------------------------------------------------------------------------------------------------------

		// контроль за объектом IEDMODEL_GenericIO_GGIO1_Ind1. Указываем на функцию-обработчик controlHandlerForBinaryOutput и параметр (IEDMODEL_GenericIO_GGIO1_Ind1) если функция обрабатывает несколько объектов.
		// управление выключателем
		IedServer_setControlHandler(iedServer, IEDMODEL_CTRL_CSWI1_Pos, (ControlHandler) controlHandlerForBinaryOutput,IEDMODEL_CTRL_CSWI1_Pos_Oper);

		IedServer_setControlHandler(iedServer, IEDMODEL_GGIO_LEDGGIO1_SPCSO1, (ControlHandler) controlHandlerForBinaryOutput,IEDMODEL_GGIO_LEDGGIO1_SPCSO1_Oper);
		IedServer_setControlHandler(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO1, (ControlHandler) controlHandlerForBinaryOutput,IEDMODEL_CTRL_GGIO1_SPCSO1_Oper);
		IedServer_setControlHandler(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO2, (ControlHandler) controlHandlerForBinaryOutput,IEDMODEL_CTRL_GGIO1_SPCSO2_Oper);
		IedServer_setControlHandler(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO3, (ControlHandler) controlHandlerForBinaryOutput,IEDMODEL_CTRL_GGIO1_SPCSO3_Oper);


//	    IedServer_setControlHandler(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO1,(ControlHandler) controlHandlerForBinaryOutput, IEDMODEL_GGIO_INGGIO1_SPCSO1);
	    IedServer_setControlHandler(iedServer, IEDMODEL_CTRL_XCBR1_Mod,(ControlHandler) controlHandlerForBinaryOutput, IEDMODEL_CTRL_XCBR1_Mod_Oper);


	    /* this is optional - performs operative checks */
	    IedServer_setPerformCheckHandler(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO1, checkHandler, IEDMODEL_GGIO_INGGIO1_SPCSO1);
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
		    SettingGroupControlBlock* sgcb = LogicalDevice_getSettingGroupControlBlock(IEDMODEL_Generic_LD0);

		    loadActiveSgValues(sgcb->actSG);

		    IedServer_setActiveSettingGroupChangedHandler(iedServer, sgcb, activeSgChangedHandler, NULL);
		    IedServer_setEditSettingGroupChangedHandler(iedServer, sgcb, editSgChangedHandler, NULL);
		    IedServer_setEditSettingGroupConfirmationHandler(iedServer, sgcb, editSgConfirmedHandler, NULL);


			//--------------- Goose -------------------------
			IedServer_setGooseInterfaceId(iedServer, CONFIG_ETHERNET_INTERFACE_ID);

		//    GooseReceiver receiver = GooseReceiver_create();
		//    GooseReceiver_setInterfaceId(receiver, "eth0");
		//    GooseSubscriber subscriber = GooseSubscriber_create("simpleIOGenericIO/LLN0$GO$gcbAnalogValues", NULL);
		//    GooseSubscriber_setAppId(subscriber, 1000);
		//    GooseSubscriber_setListener(subscriber, gooseListener, NULL);
		//    GooseReceiver_addSubscriber(receiver, subscriber);
		//    GooseReceiver_start(receiver);
			//--------------- Goose -------------------------


			if (!IedServer_isRunning(iedServer)) {
				USART_TRACE_RED("Ошибка запуска сервера! Останов.\n");
				IedServer_destroy(iedServer);
			}

//			osMutexRelease(xIEC850ServerStartMutex);

			//--------------- Goose -------------------------
			/* Start GOOSE publishing */
			IedServer_enableGoosePublishing(iedServer);
			//--------------- Goose -------------------------

			running = 1;


			printf("memory gap = %u\r\n", xPortGetFreeHeapSize());
			printf("task count = %u\r\n", uxTaskGetNumberOfTasks());
			static signed char taskInfoBuf[48 * 8];
			vTaskGetRunTimeStats(taskInfoBuf );
			printf("%s\r\n", taskInfoBuf);

			while (running) {

				IedServer_processIncomingData(iedServer);						// Должна вызываться периодически для приёма данных и соединений
																				// проверяем было ли соединение на сокет?
				IedServer_performPeriodicTasks(iedServer);						// Должна вызываться периодически монитор служб 61850

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
	USART_TRACE_GREEN("controlHandlerForBinaryOutput MMS_BOOLEAN:\n");

	 if (MmsValue_getType(value) == MMS_BOOLEAN) {
		 USART_TRACE("принята команда контроля MMS_BOOLEAN:\n");

	        if (MmsValue_getBoolean(value)){
	        	USART_TRACE_GREEN("on\n");
	        }
	        else {
	        	USART_TRACE_RED("off\n");
	        }
	    }
	 else{
		 USART_TRACE_RED("команда не MMS_BOOLEAN\n");
	 }

	    uint64_t timeStamp = Hal_getTimeInMs();

	    bool newState = MmsValue_getBoolean(value);

	    // выключатель
	    if (parameter == IEDMODEL_CTRL_CSWI1_Pos_Oper)	{
	    	USART_TRACE_GREEN("команда управления выключателем IEDMODEL_CTRL_CSWI1_Pos_Oper\n");
	    	CSWI_Pos_Oper_Set(newState, timeStamp);
	    }
	    // Сброс индикации
	    if (parameter == IEDMODEL_GGIO_LEDGGIO1_SPCSO1_Oper)	{
	    	USART_TRACE_GREEN("Сброс индикации\n");
	    	GGIO_LEDGGIO1_SPCSO1_Oper(newState, timeStamp);
	    }

	    if (parameter == IEDMODEL_CTRL_GGIO1_SPCSO1_Oper)	{
	    	USART_TRACE_GREEN("Сброс флага новой неисправности\n");
	    	GGIO_SPCSO1_Oper(newState, timeStamp);
	    }
	    if (parameter == IEDMODEL_CTRL_GGIO1_SPCSO2_Oper)	{
	    	USART_TRACE_GREEN("Сброс флага новой записи в журнале системы\n");
	    	GGIO_SPCSO2_Oper(newState, timeStamp);
	    }
	    if (parameter == IEDMODEL_CTRL_GGIO1_SPCSO3_Oper)	{
	    	USART_TRACE_GREEN("Сброс флага новой записи в журнале аварий\n");
	    	GGIO_SPCSO3_Oper(newState, timeStamp);
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
    /* When the netif is fully configured this function must be called.*/
    netif_set_up(&gnetif);
  }
  else
  {
    /* When the netif link is down this function must be called */
    netif_set_down(&gnetif);
  }

  /* Set the link callback function, this function is called on change of link status*/
  netif_set_link_callback(&gnetif, ethernetif_update_config);

  /* create a binary semaphore used for informing ethernetif of frame reception */
  osSemaphoreDef(Netif_SEM);
  Netif_LinkSemaphore = osSemaphoreCreate(osSemaphore(Netif_SEM) , 1 );

  link_arg.netif = &gnetif;
  link_arg.semaphore = Netif_LinkSemaphore;
  /* Create the Ethernet link handler thread */
  USART_TRACE_MAGENTA("(LinkThr) Create the Ethernet link handler thread.\n");
#if defined(__GNUC__)
  osThreadDef(LinkThr, ethernetif_set_link, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 5);
#else
  osThreadDef(LinkThr, ethernetif_set_link, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);
#endif
  osThreadCreate (osThread(LinkThr), &link_arg);
}

//--------------------------------------------------------------------

static bool	activeSgChangedHandler (void* parameter, SettingGroupControlBlock* sgcb,	 uint8_t newActSg, ClientConnection connection)
{
    printf("Switch to setting group %i\n", (int) newActSg);

    loadActiveSgValues(newActSg);

    return true;
}

static bool	editSgChangedHandler (void* parameter, SettingGroupControlBlock* sgcb,  uint8_t newEditSg, ClientConnection connection)
{
    printf("Set edit setting group to %i\n", (int) newEditSg);

    loadEditSgValues(newEditSg);

    return true;
}
static void	editSgConfirmedHandler(void* parameter, SettingGroupControlBlock* sgcb,	uint8_t editSg)
{
    printf("Received edit sg confirm for sg %i\n", editSg);

     if (IedServer_getActiveSettingGroup(iedServer, sgcb) == editSg) {
        loadActiveSgValues(editSg);
    }
}
//--------------------------------------------------------------------
static void		loadActiveSgValues (int actSG)
{

	// тут функция переключения группы уставок с вычитыванием всех
  // IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_LD0_LLN0_RstTms_setVal, 1);
}
//--------------------------------------------------------------------
static void		loadEditSgValues (int editSG)
{
//    IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_SE_LD0_LLN0_RstTms_setVal, 2);
}

