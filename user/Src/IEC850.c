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
//#include "MmsPdu.h"

#include "iedserverdataupdate.h"

#include "goose_receiver.h"
/*Modbus includes ------------------------------------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbport.h"
#include "modbus.h"



#define WEBSERVER_THREAD_PRIO    ( tskIDLE_PRIORITY + 4 )
/* Variables -----------------------------------------------------------------*/
extern RTC_TimeTypeDef StartsTime;
extern RTC_DateTypeDef StartsDate;


// ����������� ����
FATFS RAMDISKFatFs;  /* File system object for RAM disk logical drive */
char RAMDISKPath[4]; /* RAM disk logical drive path */
uint8_t	buffer[100];

BYTE Buff[4096] __attribute__ ((aligned (4))) ;	/* Working buffer */



// ����
extern volatile uint8_t	MAC_ADDR[6];
extern uint8_t		IP_ADDR[4];
extern uint8_t		NETMASK_ADDR[4];
extern uint8_t		GW_ADDR[4];
extern uint8_t		SNTP_IP_ADDR[4];
extern uint16_t		SNTP_Period;
extern int8_t		TimeZone_my;

extern uint8_t		writeNmb;
extern	uint8_t	  writeNmbSG;			// ����� ������ �������.


//extern IedServer iedServer;
IedServer iedServer = NULL;

static int running = 0;

uint64_t 	nextSynchTime = 0;
bool 		resynch = false;
bool		getJurnals = false;

extern struct netconn *newconn850;
extern struct netif 	gnetif;


extern osMutexId xIEC850StartMutex;
extern osMutexId xIEC850ServerStartMutex;


extern osSemaphoreId Netif_LinkSemaphore;
extern struct link_str link_arg;
/*  ���� ------------------------------------------------------------*/
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
 * gooseListener
 * ������� ��� ��� ������
 *************************************************************************/
void	gooseListener(GooseSubscriber subscriber, void* parameter)
{
    printf("GOOSE event:\n");
    printf("  stNum: %u sqNum: %u\n", GooseSubscriber_getStNum(subscriber), GooseSubscriber_getSqNum(subscriber));
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
/*
static CheckHandlerResult	checkHandler(void* parameter, MmsValue* ctlVal, bool test, bool interlockCheck, ClientConnection connection)
{
    printf("check handler called!\n");

    if (interlockCheck)
        printf("  with interlock check bit set!\n");

    if (parameter == &iedModel_GGIO_INGGIO1_SPCSO1)
        return CONTROL_ACCEPTED;

    if (parameter == &iedModel_GGIO_INGGIO1_SPCSO2)
        return CONTROL_ACCEPTED;

    if (parameter == &iedModel_GGIO_INGGIO1_SPCSO3)
        return CONTROL_ACCEPTED;

    if (parameter == &iedModel_GGIO_INGGIO1_SPCSO4)
        return CONTROL_ACCEPTED;

    return CONTROL_OBJECT_UNDEFINED;
}
*/
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
    if (dataAttribute == IED&iedModel_erter_ZINV1_OutVarSet_setMag_f) { //&iedModel_GenericIO_GGIO1_NamPlt_vendor

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

long p3;
extern osThreadId IEC850TaskHandle;


/*
	IP_ADDR[0] = 192;
	IP_ADDR[1] = 168;
	IP_ADDR[2] = 0;
	IP_ADDR[3] = 252;
*/
//	iedServer = IedServer_create(&iedModel);	// �������� IED ����������� ����������

	osMutexRelease(xIEC850ServerStartMutex);

// 1. ���� �������� ���������� �������� IP
	    osStatus status = osMutexWait(xIEC850StartMutex,osWaitForever);		// �����������
	    if (status != osOK) {
	    	// �� ����������, �� ��� �����.
			USART_TRACE_RED("�� ����������, �� ��� �����.\n");
	    }

	    // �������� ����� �������� ������.
		  HAL_RTC_GetTime((RTC_HandleTypeDef *)&hrtc, &StartsTime, FORMAT_BIN);
		  HAL_RTC_GetDate((RTC_HandleTypeDef *)&hrtc, &StartsDate, FORMAT_BIN);


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
			  SNTP_Period = 0;
		  }

		iedServer = IedServer_create(&iedModel,(uint16_t)IP_ADDR[3]);		// �������� IED ����������� ����������
		USART_TRACE_GREEN("�������� IP, ��������� ������.\n");

		Port_Off(LED_out_RED);

	    // 2. ���������� ������ ��������� ����.
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

	    tcpip_init( NULL, NULL );									// ������� tcp_ip stack, ���� TCP/IP
	    // �������� ������� ��������� IP
    	Netif_Config((char*)IP_ADDR,(char*)NETMASK_ADDR,(char*)GW_ADDR);		// Initialize the LwIP stack

// 3. ����������� ���� ������� � ���������� ��������� ��� ����� ������
	    USART_TRACE_GREEN("��������� ������ � ������ ������� 61850\n");
// 4. ��������� ����������� 61850
	    USART_TRACE_GREEN("��������� ����������� 61850\n");

// -----------------------------------------------------------------------------

	    if(FATFS_LinkDriver(&SRAMDISK_Driver, RAMDISKPath) == 0)				  // Link the RAM disk I/O driver SPIDISK_Driver   SRAMDISK_Driver
	    {
	      if(f_mount(&RAMDISKFatFs, (TCHAR const*)RAMDISKPath, 0) != FR_OK)	      // ��������� ����
	      {
	  	    USART_TRACE_RED("������ ������������ �����\n");
	      }
	      else
	      {
	       // if(f_mkfs((TCHAR const*)RAMDISKPath, 0, 0) != FR_OK)
	    	  if(f_mkfs((const TCHAR*)RAMDISKPath, FM_FAT, 0, Buff, sizeof Buff)!= FR_OK)	// ����������� ����
	        {
		  	    USART_TRACE_RED("������ �������������� �����\n");
	        }
	        else
	        {
		  	    USART_TRACE_GREEN("���� ������ �������\n");
		  	  if (f_mkdir("MMSfiles") != FR_OK){
			  	    USART_TRACE_RED("������ �������� �������� MMSfiles\n");
		  	  } else
		  	  {
			  	    USART_TRACE_GREEN("������� MMSfiles/ ������ �������\n");

			 // 	   DIR dirHandle;
			 // 	  if(f_opendir(&dirHandle, (TCHAR const*)"MMSfiles") == FR_OK){				// Open directory
			 // 		USART_TRACE("������� ������� 0:/MMSfiles>\n");
			 // 	  }

			  		//portENTER_CRITICAL();
			  	    {
			  	    	FIL 	Myfile;

						if(f_open(&Myfile,_SystemNote, FA_CREATE_ALWAYS | FA_WRITE) == FR_OK){
							USART_TRACE("������� ���� SystemLog.bin\n");
							/*
							if(f_write(&Myfile,"������ �������:\n", strlen("������ �������:\n"), NULL) == FR_OK){
								USART_TRACE("�������� � ����.\n");
								f_close(&Myfile);
							}
							*/
						}

						//AddToFileMessageString(_SystemNote,"testAppend\n");
						//AddToFileMessageString(_SystemNote,"testAppend1\n");

						if(f_open(&Myfile,_ErrorNote, FA_CREATE_ALWAYS | FA_WRITE) == FR_OK){
							USART_TRACE("������� ���� AlarmLog.bin\n");
							/*
							if(f_write(&Myfile,"������ ������:\n", strlen("������ ������:\n"), NULL) == FR_OK){
								USART_TRACE("�������� � ����.\n");
								f_close(&Myfile);
							}
							*/
						}
			  	    }
			  	   // portEXIT_CRITICAL();


			  		uint8_t res;
			  	    FATFS *fs;
			  	    DWORD fre_clust, fre_sect, tot_sect;


			  	    /* Get volume information and free clusters of drive 1 */
			  	    res = f_getfree(RAMDISKPath, &fre_clust, &fs);

			  	    /* Get total sectors and free sectors */
			  	    tot_sect = (fs->n_fatent - 2) * fs->csize;
			  	    fre_sect = fre_clust * fs->csize;

			  	    /* Print the free space (assuming 512 bytes/sector) */
			  	    printf("������ ����� %lu KB. �������� %lu KB \n", tot_sect / 2, fre_sect / 2);
		  	  }
	        }
	      }
	    }
// -----------------------------------------------------------------------------
	    Port_Off(LED1);

	for(;;) {

		// -------------------------------------------------------------------------------------------------------------------
		// -------------------------------------------------------------------------------------------------------------------
		//iedServer = IedServer_create(&iedModel);								// �������� IED ����������� ����������
		// �������� ��������� ������
		AcseAuthenticationParameter auth = GLOBAL_MALLOC(sizeof(AcseAuthenticationParameter));

		char* password = "testpw";
	    auth->mechanism = ACSE_AUTH_PASSWORD;
	    auth->value.password.octetString = (uint8_t*) password;
	    auth->value.password.passwordLength = strlen(password);
	    //������
//		IsoServer_setAuthenticationParameter(isoServer, auth);

		// -------------------------------------------------------------------------------------------------------------------
		// ������� �������� ��� ���������, ��� ���������� �� �������
		// -------------------------------------------------------------------------------------------------------------------

		// �������� �� �������� &iedModel_GenericIO_GGIO1_Ind1. ��������� �� �������-���������� controlHandlerForBinaryOutput � �������� (&iedModel_GenericIO_GGIO1_Ind1) ���� ������� ������������ ��������� ��������.
		// ���������� ������������

#if defined (MR761) || defined (MR762) || defined (MR763)
	    IedServer_setControlHandler(iedServer, &iedModel_CTRL_CSWI1_Pos, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_CSWI1_Pos_Oper);
	    IedServer_setControlHandler(iedServer, &iedModel_CTRL_XCBR1_Mod,(ControlHandler) controlHandlerForBinaryOutput, &iedModel_CTRL_XCBR1_Mod_Oper);
#endif
#if defined (MR771)
	    IedServer_setControlHandler(iedServer, &iedModel_CTRL_CSWI1_Pos, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_CSWI1_Pos_Oper);
	    IedServer_setControlHandler(iedServer, &iedModel_CTRL_XCBR1_Mod,(ControlHandler) controlHandlerForBinaryOutput, &iedModel_CTRL_XCBR1_Mod_Oper);
#endif
#if defined (MR801)
	    IedServer_setControlHandler(iedServer, &iedModel_CTRL_CSWI1_Pos, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_CSWI1_Pos_Oper);
	    IedServer_setControlHandler(iedServer, &iedModel_CTRL_XCBR1_Mod,(ControlHandler) controlHandlerForBinaryOutput, &iedModel_CTRL_XCBR1_Mod_Oper);
#endif
#if defined (MR5_700)
	    IedServer_setControlHandler(iedServer, &iedModel_CTRL_CSWI1_Pos, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_CSWI1_Pos_Oper);
	    IedServer_setControlHandler(iedServer, &iedModel_CTRL_XCBR1_Mod,(ControlHandler) controlHandlerForBinaryOutput, &iedModel_CTRL_XCBR1_Mod_Oper);
#endif
#if defined (MR5_500)
	    IedServer_setControlHandler(iedServer, &iedModel_CTRL_CSWI1_Pos, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_CSWI1_Pos_Oper);
	    IedServer_setControlHandler(iedServer, &iedModel_CTRL_XCBR1_Mod,(ControlHandler) controlHandlerForBinaryOutput, &iedModel_CTRL_XCBR1_Mod_Oper);
#endif

#if defined (MR851)
	    IedServer_setControlHandler(iedServer, &iedModel_RPN_ATCC1_TapChg, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_RPN_ATCC1_TapChg_Oper);
	    IedServer_setControlHandler(iedServer, &iedModel_RPN_ATCC1_ParOp, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_RPN_ATCC1_ParOp_Oper);

#endif

		IedServer_setControlHandler(iedServer, &iedModel_CTRL_GGIO1_SPCSO1, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_GGIO1_SPCSO1_Oper);
		IedServer_setControlHandler(iedServer, &iedModel_CTRL_GGIO1_SPCSO2, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_GGIO1_SPCSO2_Oper);
		IedServer_setControlHandler(iedServer, &iedModel_CTRL_GGIO1_SPCSO3, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_GGIO1_SPCSO3_Oper);
		IedServer_setControlHandler(iedServer, &iedModel_CTRL_GGIO1_SPCSO4, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_GGIO1_SPCSO4_Oper);


	    /* this is optional - performs operative checks */
	 //   IedServer_setPerformCheckHandler(iedServer, &iedModel_GGIO_INGGIO1_SPCSO1, checkHandler, &iedModel_GGIO_INGGIO1_SPCSO1);
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

#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
			//--------------- Goose -------------------------
		    // ������������ �����.
			IedServer_setGooseInterfaceId(iedServer, CONFIG_ETHERNET_INTERFACE_ID);			// ��������� ����� ������� ����� ����� ����. (��� �� ����, �� � ��� ����)

		    GooseReceiver Goosereceiver = GooseReceiver_create();
		    GooseReceiver_setInterfaceId(Goosereceiver, CONFIG_ETHERNET_INTERFACE_ID);		// ��������� ����� ������� ����� ��������� ����. (��� �� ����, �� � ��� ����)

		    // ������ ��� -----
		    GooseSubscriber subscriber = GooseSubscriber_create("MR5PO70N125LD0/LLN0$GO$gcbDiscret", NULL, NULL);		// ������������� �� ���.
		    GooseSubscriber_setAppId(subscriber, 999);
		    GooseSubscriber_setListener(subscriber, gooseListener, NULL);					// ������� ��� ��������� ����������� ��������� ����
		    GooseReceiver_addSubscriber(Goosereceiver, subscriber);
		    // ----------------
		    // ������ ��� -----
		    subscriber = GooseSubscriber_create("MR5PO70N125LD0/LLN0$GO$gcbAnalog", NULL, NULL);		// ������������� �� ���.
		    GooseSubscriber_setAppId(subscriber, 999);
		    GooseSubscriber_setListener(subscriber, gooseListener, NULL);					// ������� ��� ��������� ����������� ��������� ����
		    GooseReceiver_addSubscriber(Goosereceiver, subscriber);
		    // ----------------
		    // ������ ��� -----
		    subscriber = GooseSubscriber_create("A1LD0/LLN0$GO$gcbsignal_goose", NULL, NULL);		// ������������� �� ���.
		    GooseSubscriber_setAppId(subscriber, 3);
		    GooseSubscriber_setListener(subscriber, gooseListener, NULL);					// ������� ��� ��������� ����������� ��������� ����
		    GooseReceiver_addSubscriber(Goosereceiver, subscriber);
		    // ----------------

		    GooseReceiver_start(Goosereceiver);					// �������� ������� ���� �����.
			//--------------- Goose -------------------------
#endif
			if (!IedServer_isRunning(iedServer)) {
				USART_TRACE_RED("������ ������� �������! �������.\n");
				IedServer_destroy(iedServer);
			}

//			osMutexRelease(xIEC850ServerStartMutex);

#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
			//--------------- Goose -------------------------
			// ���������� ����� �����. Start GOOSE publishing
			IedServer_enableGoosePublishing(iedServer);
			//--------------- Goose -------------------------
#endif
			running = 1;


			printf("memory gap = %u\r\n", xPortGetFreeHeapSize());
			printf("task count = %u\r\n",(unsigned int)uxTaskGetNumberOfTasks());
			static signed char taskInfoBuf[48 * 8];
			vTaskGetRunTimeStats((char *)taskInfoBuf);
			printf("%s\r\n", taskInfoBuf);

			// ������ -------
			Print_Sockets();
			// --------------
			while (running) {

				IedServer_processIncomingData(iedServer);						// ������ ���������� ������������ ��� ����� ������ � ����������
																				// ��������� ���� �� ���������� �� �����?
				IedServer_performPeriodicTasks(iedServer);						// ������ ���������� ������������ ������� ����� 61850

				IedServer_PeriodicUpdateNewData(iedServer);						// ���������� ������ � ������ �� ������� ������

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
	bool 		newState;
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


#if defined (MR761) || defined (MR762) || defined (MR763)
	    // �����������
	    if (parameter == &iedModel_CTRL_CSWI1_Pos_Oper)	{
	    	USART_TRACE_GREEN("������� ���������� ������������ &iedModel_CTRL_CSWI1_Pos_Oper\n");
	    	CSWI_Pos_Oper_Set(newState, timeStamp);
	    }
#endif
#if defined (MR771)
	    // �����������
	    if (parameter == &iedModel_CTRL_CSWI1_Pos_Oper)	{
	    	USART_TRACE_GREEN("������� ���������� ������������ &iedModel_CTRL_CSWI1_Pos_Oper\n");
	    	CSWI_Pos_Oper_Set(newState, timeStamp);
	    }
#endif
#if defined (MR801)
	    // �����������
	    if (parameter == &iedModel_CTRL_CSWI1_Pos_Oper)	{
	    	USART_TRACE_GREEN("������� ���������� ������������ &iedModel_CTRL_CSWI1_Pos_Oper\n");
	    	CSWI_Pos_Oper_Set(newState, timeStamp);
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
#if defined (MR5_700)
	    // �����������
	    if (parameter == &iedModel_CTRL_CSWI1_Pos_Oper)	{
	    	USART_TRACE_GREEN("������� ���������� ������������ &iedModel_CTRL_CSWI1_Pos_Oper\n");
	    	CSWI_Pos_Oper_Set(newState, timeStamp);
	    }
#endif
#if defined (MR5_500)
	    // �����������
	    if (parameter == &iedModel_CTRL_CSWI1_Pos_Oper)	{
	    	USART_TRACE_GREEN("������� ���������� ������������ &iedModel_CTRL_CSWI1_Pos_Oper\n");
	    	CSWI_Pos_Oper_Set(newState, timeStamp);
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
	    	USART_TRACE_GREEN("����� ����������\n");
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
    /* When the netif is fully configured this function must be called.*/
    netif_set_up(&gnetif);
  }
  else
  {
    /* When the netif link is down this function must be called */
    netif_set_down(&gnetif);
  }
/*
  // Set the link callback function, this function is called on change of link status
  netif_set_link_callback(&gnetif, ethernetif_update_config);

  // create a binary semaphore used for informing ethernetif of frame reception
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
#if defined (MR761) || defined (MR762) || defined (MR763)
		writeNmbSG = actSG;
		writeNmb = 7;
#endif
#if defined (MR771)
		writeNmbSG = actSG;
		writeNmb = 7;
#endif
#if defined (MR801)
		writeNmbSG = actSG;
		if (actSG == 1) 	writeNmb = 7;
		else
		if (actSG == 2) 	writeNmb = 8;
#endif
#if defined (MR901) || defined (MR902)
		writeNmbSG = actSG;
		if (actSG == 1) 	writeNmb = 7;
		else
		if (actSG == 2) 	writeNmb = 8;
#endif
#if defined (MR5_500) || defined (MR5_600) || defined (MR5_700)
		writeNmbSG = actSG;
	if (actSG == 1) 	writeNmb = 7;
	else
	if (actSG == 2) 	writeNmb = 8;
#endif


	// ��� ������� ������������ ������ ������� � ������������ ����
  // IedServer_updateInt32AttributeValue(iedServer, &iedModel_LD0_LLN0_RstTms_setVal, 1);
}
//--------------------------------------------------------------------
static void		loadEditSgValues (int editSG)
{
//    IedServer_updateInt32AttributeValue(iedServer, &iedModel_SE_LD0_LLN0_RstTms_setVal, 2);
}

/***********************************************************************
 * AddToFileMessageString
 * ������� � ����� ����� ������
 ***********************************************************************/
int		AddToFileMessageString(const TCHAR* file, TCHAR* message){

  	FIL 	Myfile;
  	int		ret;

	if(f_open(&Myfile,file, FA_OPEN_APPEND | FA_WRITE) == FR_OK){
		if(f_write(&Myfile,message, strlen(message), NULL) == FR_OK){
			f_close(&Myfile);
			ret = true;

		}else ret = false;
	}else ret = false;

	return	ret;
}
/***********************************************************************
 * AddToFileMessageWord
 * ������� � ����� ����� ����� �����
 * numb - ����� ����
 ***********************************************************************/
int		AddToFileMessageWord(const TCHAR* file, uint8_t* Data,uint16_t numb,uint8_t	mode){

  	FIL 	Myfile;
  	int		ret,i;
	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;

	HAL_RTC_GetTime((RTC_HandleTypeDef *)&hrtc, &sTime, FORMAT_BIN);			// ������ �����
	HAL_RTC_GetDate((RTC_HandleTypeDef *)&hrtc, &sDate, FORMAT_BIN);			// ������ ����


	if(f_open(&Myfile,file, mode) == FR_OK){

		//f_lseek(&Myfile,0);		// �������� ������� ��� �����

		for(i=0;i<numb;i++){
			f_write(&Myfile,(void*)&Data[i+1], 1, NULL);
			f_write(&Myfile,(void*)&Data[i], 1, NULL);
			i++;
		}

		// ������� ��������� ������ �����, ���� ��������� �����, �� ������� �����
		//f_lseek(&Myfile,8*128);		// ������� �� ����� � ������ �������
		//f_truncate(&Myfile);
	f_close(&Myfile);

	set_timestampFile((char *)file,sDate.Year,sDate.Month,sDate.Date,sTime.Hours,sTime.Minutes,sTime.Seconds);
	}else ret = false;

	return	ret;
}
