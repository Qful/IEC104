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

// �������� �������
#include "ff.h"
#include "filesystem.h"

/* ���� --*/
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

// ����
extern volatile uint8_t	MAC_ADDR[6];
extern uint8_t		IP_ADDR[4];
extern uint8_t		NETMASK_ADDR[4];
extern uint8_t		GW_ADDR[4];
extern uint8_t		SNTP_IP_ADDR[4];
extern uint16_t		SNTP_Period;

extern	uint8_t	  writeNmbSG;			// ����� ������ �������.

extern struct netif 	gnetif;


extern osMutexId xIEC850StartMutex;
extern osMutexId xFTPStartMutex;				// ������� ���������� � ������� FTP


extern osSemaphoreId Netif_LinkSemaphore;
extern struct link_str link_arg;
/*  ���� ------------------------------------------------------------*/
extern RTC_HandleTypeDef hrtc;
/*  -----------------------------------------------------------------*/

/*  ������� ---------------------------------------------------------*/
extern	xQueueHandle 	ModbusSentQueue;	// ������� ��� �������� � ������
extern xQueueHandle 	ModbusSentTime;		// ������� ��� �������� � ������

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
/* ����������, ������ � ��� ����������� ����������� �������� � �����-���� �������.
 * ����� ������ ������ ��������, ������������ ������� ��������� ���������� ��������.
 * ���� ������� ��������� ����������� ���������� �������, ������������ �������
 * ��������� ���� ����������, ������� ��� ���������� � �������.
 * ���� ������� �� ��������� ����������, �� ����������� ���������� �� ���������.
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

// 1. ���� �������� ���������� �������� IP
	    osStatus status = osMutexWait(xIEC850StartMutex,TIMEOUT_startServer);		// �����������	TIMEOUT_startServer
	    if (status != osOK) {
	    	// �� ����������, �� ��� �����.
			USART_TRACE_RED("�� �������� IP. ��� ����� MB.\n");
	    }else{
	    	USART_TRACE_GREEN("�������� IP, ��������� ������.\n");
	    }
		Port_Off(LED_out_RED);

	    Network_Start();

	    // �������� ����� �������� ������.
		HAL_RTC_GetTime((RTC_HandleTypeDef *)&hrtc, &StartsTime, FORMAT_BIN);
		HAL_RTC_GetDate((RTC_HandleTypeDef *)&hrtc, &StartsDate, FORMAT_BIN);

		iedServer = IedServer_create(&iedModel,(uint16_t)IP_ADDR[3]);			// �������� IED ����������� ����������
		//IedServer_setAuthenticator(iedServer, clientAuthenticator, NULL); 	// ���. ��������� ������

	    // 2. ���������� ������ ��������� ����.
		IsoServer isoServer = IedServer_getIsoServer(iedServer);
		IsoServer_setEthernetParam(isoServer,(char*)IP_ADDR,(char*)NETMASK_ADDR,(char*)GW_ADDR);

    	// ��������� ������ ������ ��������� �� ������ �������� �����
		osMutexRelease(xFTPStartMutex);

	    // ����� ������ ����� ----------------------------------------
		PHY_setSwitchMode(isoServer);

	    Port_Off(LED1);
		Port_Off(LED_out_GREEN);

	for(;;) {

		// -------------------------------------------------------------------------------------------------------------------
		// ������� �������� ��� ���������, ��� ���������� �� �������
		// -------------------------------------------------------------------------------------------------------------------

	    // ���������� ������������
#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763) || defined (MR801) ||\
	defined (MR5_500) || defined (MR5_700) || defined (MR741)
	    IedServer_setControlHandler(iedServer, &iedModel_CTRL_CSWI1_Pos, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_CSWI1_Pos_Oper);
	    IedServer_setControlHandler(iedServer, &iedModel_CTRL_XCBR1_Mod,(ControlHandler) controlHandlerForBinaryOutput, &iedModel_CTRL_XCBR1_Mod_Oper);
#endif
	    // ���������� ��������
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
 * ��������������� ������
 *
 *****************************************************************************************************/
		while (1){

			IedServer_setConnectionIndicationHandler(iedServer, (IedConnectionIndicationHandler) connectionHandler, NULL);

		#if (CONFIG_MMS_THREADLESS_STACK == 1)
			IedServer_startThreadless(iedServer, 102);		    // ����������� ������ ��������� ���� � ������� ����������.
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
			// ������� ����� �����.
		    GooseReceiverFile*	GooseCfgFile = GooseReceiver_ConfigCreate();
		    if (GooseReceiver_ParseConfigFile(GooseCfgFile, _GooseREcfg) == true){
			    GooseReceiver Goosereceiver = GooseReceiver_create();
			    GooseReceiver_addSubscriberFromConfigFile(Goosereceiver,GooseCfgFile);
			    GooseReceiver_start(Goosereceiver);															// �������� ������� ���� �����.
		    }
	        //--------------- Goose -------------------------
#endif

			if (!IedServer_isRunning(iedServer)) {
				USART_TRACE_RED("������ ������� �������! �������.\n");
				IedServer_destroy(iedServer);
			}else{
				AddToQueueMB(ModbusSentQueue, 	MB_Rd_Revision		,MB_Slaveaddr);		// ������ ����������
			}


#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
			//--------------- Goose -------------------------
			// ���������� ����� �����. Start GOOSE publishing
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

			// ������ -------
			Print_Sockets();
			// --------------
			while (running) {

				IedServer_processIncomingData(iedServer);						// ������ ���������� ������������ ��� ����� ������ � ����������. �������� �� ������� �����
																				// ��������� ���� �� ���������� �� �����?
				// ������� �������������� ������
				IedServer_PeriodicUpdateNewData(iedServer);						// ���������� ������ � ������ �� ������� ������. �������� ����� �������.

				// �� ���������� �������� ������ � ���������
				IedServer_performPeriodicTasks(iedServer);						// ������ ���������� ������������ ������� ����� 61850
				taskYIELD();													// �������� ������.
//				vTaskDelay(1);

			}

			IedServer_stopThreadless(iedServer);								// stop MMS server - close TCP server socket and all client sockets
			IedServer_destroy(iedServer);							    		// Cleanup - free all resources
		}
/*****************************************************************************************************
 *
 * !��������������� ������
 *
 *****************************************************************************************************/
	}
}
/*************************************************************************
 * controlHandlerForBinaryOutput
 *  ������� �������� ��� �������� ��������. ����� ��������� ���� ������ ��
 *  �������, ����� ���������� ��� �������.
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
		 	 	 	 	 USART_TRACE("������� ������� �������� MMS_BOOLEAN:\n");
		 	 	 	 	 if (MmsValue_getBoolean(value))	{USART_TRACE_GREEN("on\n");}
		 	 	 	 	 else  {USART_TRACE_RED("off\n");}

		 	 	 	 	  newState = MmsValue_getBoolean(value);
		break;
	case	MMS_BIT_STRING:
						 newStateBitstr = MmsValue_getBitStringAsInteger(value);
		break;
	default:
		 USART_TRACE_RED("������� �� ��������\n");
		break;
	}

	    uint64_t timeStamp = Hal_getTimeInMs();


#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763) ||\
	defined (MR801) ||\
	defined (MR5_700) || defined (MR5_500) || defined (MR741)
	    // �����������
	    if (parameter == &iedModel_CTRL_CSWI1_Pos_Oper)	{
	    	USART_TRACE_GREEN("������� ���������� ������������ &iedModel_CTRL_CSWI1_Pos_Oper\n");
	    	CSWI_Pos_Oper_Set(newState, timeStamp);
			AddToQueueMB(ModbusSentQueue, 	MB_Rd_ConfigSWCrash	,MB_Slaveaddr);			// �������� ������
	    }
#endif
#if defined (MR851)
	    // ������
	    if (parameter == &iedModel_RPN_ATCC1_TapChg_Oper)	{
	    	USART_TRACE_GREEN("������� ���������� ��������.\n");
	    	ATCC_TapChg_Pos_Oper_Set(newStateBitstr, timeStamp);
	    }
	    if (parameter == &iedModel_RPN_ATCC1_ParOp_Oper)	{
	    	USART_TRACE_GREEN("������� ���������� ����. �������.\n");
	    	ATCC_ParOp_Pos_Oper(newState, timeStamp);
	    }
#endif


	    if (parameter == &iedModel_CTRL_GGIO1_SPCSO1_Oper)	{
	    	USART_TRACE_GREEN("����� ����� ����� �������������\n");
	    	GGIO_SPCSO1_Oper(newState, timeStamp);
	    }
	    if (parameter == &iedModel_CTRL_GGIO1_SPCSO2_Oper)	{
	    	USART_TRACE_GREEN("����� ����� ����� ������ � ������� �������\n");
	    	GGIO_SPCSO2_Oper(newState, timeStamp);
	    }
	    if (parameter == &iedModel_CTRL_GGIO1_SPCSO3_Oper)	{
	    	USART_TRACE_GREEN("����� ���������� ��� ������ � ������� ������\n");
	    	GGIO_SPCSO3_Oper(newState, timeStamp);
	    }

	    // ����� ���������
	    if (parameter == &iedModel_CTRL_GGIO1_SPCSO4_Oper)	{
	    	USART_TRACE_GREEN("����� ���������\n");
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

  USART_TRACE_BLUE("MAC:%.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n",MAC_ADDR[0], MAC_ADDR[1], MAC_ADDR[2], MAC_ADDR[3],MAC_ADDR[4],MAC_ADDR[5]);	// �������� ����� ���������� ����������
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

  netif_add(&gnetif, &ipaddr, &netmask, &gw, NULL, &ethernetif_init, &tcpip_input);				// ethernetif_init - ������ ����� ��� ������. tcpip_input - ������� ������ ������

  /*  Registers the default network interface. */
  netif_set_default(&gnetif);

  if (netif_is_link_up(&gnetif))
  {
    /* ����� netif ��������� ��������, ��� ������� ������ ���� �������. */
    netif_set_up(&gnetif);
  }
  else
  {
    /* ����� netif ���������, ��� ������� ����� ������� */
    netif_set_down(&gnetif);
  }

  // ������� ��������� ���������� �����������/����������. �� ������� �����
/*
  // ethernetif_update_config - �� ��������� LINK ��������
  netif_set_link_callback(&gnetif, ethernetif_update_config);

  // ����� ������� �� ���������� ����������
  osSemaphoreDef(Netif_SEM);
  Netif_LinkSemaphore = osSemaphoreCreate(osSemaphore(Netif_SEM) , 1 );

  link_arg.netif = &gnetif;
  link_arg.semaphore = Netif_LinkSemaphore;
  // Create the Ethernet link handler thread
  USART_TRACE_MAGENTA("(LinkThr) Create the Ethernet link handler thread.\n");
#if defined(__GNUC__)
  osThreadDef(LinkThr, ethernetif_set_link, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 2);	// configMINIMAL_STACK_SIZE * 5 ��������
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
// �������� �� ���������� IP ������
  if (IP_ADDR[0] == 0xFF || IP_ADDR[3] == 0xFF || IP_ADDR[0] == 0 || IP_ADDR[1] == 0 ){
	  IP_ADDR[0] = first_IP_ADDR0;
	  IP_ADDR[1] = first_IP_ADDR1;
	  IP_ADDR[2] = first_IP_ADDR2;
	  IP_ADDR[3] = first_IP_ADDR3;
  }
// �������� �� ���������� IP NTP ������
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

	// ��������� ���� "TCP/IP"
	tcpip_init( NULL, NULL );												// ������� tcp_ip stack, ���� TCP/IP
	Netif_Config((char*)IP_ADDR,(char*)NETMASK_ADDR,(char*)GW_ADDR);		// Initialize the LwIP stack

    //netif_set_addr(&gnetif, &first_ipaddr , &netmask, &gw);
    //netif_set_up(&gnetif);
}
/***********************************************************************
 * activeSgChangedHandler
 * ��������� ������ ActSG ������ ������� �� ethernet.
 * ���������� ������� ������ ������ � ������
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

		AddToQueueMB(ModbusSentTime,  MB_Wrt_SG_set_ManNumb	,MB_Slaveaddr);		// ���������
//    	AddToQueueMB(ModbusSentQueue, MB_Rd_NumbSG			,MB_Slaveaddr);		// ������ ������ �������� ����� �������

#endif

	// ��� ������� ������������ ������ ������� � ������������ ����
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
