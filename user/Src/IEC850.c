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
#if defined	(MR801) && defined (OLD)
#include "static_model_MR801.h"
#endif
#if defined	(MR801) && defined (T12N5D58R51)
#include "static_model_MR801_T12N5D58R51.h"
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
#if  defined (MR761OBR)
#include "static_model_MR761OBR.h"
#endif
#if defined	(MR741)
#include "static_model_MR741.h"
#endif

#include "iedserverdataupdate.h"
#include "goose_receiver.h"

#include "sv_publisher.h"
#include "sv_subscriber.h"

#include "datatoSPCS.h"
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

static int running = 0;					// глобальнай флаг управления 850сервера. обнуление приведёт к переиниту 61850 сервера

uint64_t 	nextSynchTime = 0;
//uint32_t 	nextSynchTime = 0;
bool 		resynch = false;

osThreadId defaultTaskHandle;


#if (CONFIG_IEC61850_SAMPLED_VALUES_SUPPORT == 1)
// --------------------------------------------
// тест SV потом удалить
SampledValuesPublisher svPublisher;
SV_ASDU asdu1;
int float1;
int float2;
float fVal1 = 1234.5678f;
float fVal2 = 0.12345f;
// --------------------------------------------
#endif

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


extern osMutexId xNetworkStartMutex;
extern osMutexId xIEC850StartMutex;
extern osMutexId xFTPStartMutex;				// мьютекс готовности к запуску FTP


extern osSemaphoreId Netif_LinkSemaphore;
extern struct link_str link_arg;
/*  Часы ------------------------------------------------------------*/
extern RTC_HandleTypeDef hrtc;
/*  -----------------------------------------------------------------*/

extern uint16_t   ucGooseBufSent[MB_Size_Goose];
extern uint16_t   ucGooseBufDrop[MB_Size_Goose];

/*  очередь ---------------------------------------------------------*/
extern	xQueueHandle 	ModbusSentQueue;	// очередь для отправки в модбас
extern xQueueHandle 	ModbusSentTime;		// очередь для отправки в модбас

extern uint16_t		GLOBAL_QUALITY;
/*  -----------------------------------------------------------------*/
static void		ModelNameModify(IedModel* self, uint16_t	numb);

static bool		clientAuthenticator(void* parameter, AcseAuthenticationParameter authParameter, void** securityToken);


void			IedServer_setControlAllObj(IedServer self);
//ControlHandlerResult			controlHandlerFor_CMDGGIO(void* parameter, MmsValue* value, bool test);
ControlHandlerResult			controlHandlerForBinaryOutput(void* parameter, MmsValue* value, bool test);

static bool		activeSgChangedHandler (void* parameter, SettingGroupControlBlock* sgcb,	 uint8_t newActSg, ClientConnection connection);
static bool		editSgChangedHandler (void* parameter, SettingGroupControlBlock* sgcb,  uint8_t newEditSg, ClientConnection connection);
static void		editSgConfirmedHandler(void* parameter, SettingGroupControlBlock* sgcb,	uint8_t editSg);
static void		loadActiveSgValues (int actSG);
static void		loadEditSgValues (int editSG);

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

		if (filesystem_Read_GlobalConfig(_xGlobalcfg)){							// читаем конфиг перед запуском сервера
			// есть файл конфигурации
		}else{
			// нету файла конфигурации
#ifndef _SPCECIALSWRevision
			ModelNameModify(&iedModel,(uint16_t)IP_ADDR[3]);
#endif
		}

		iedServer = IedServer_create(&iedModel,(uint16_t)IP_ADDR[3]);			// создадим IED электронное устройство
		//IedServer_setAuthenticator(iedServer, clientAuthenticator, NULL); 	// вкл. парольный доступ

	    // 2. конфигурим сервер открываем порт.
		IsoServer isoServer = IedServer_getIsoServer(iedServer);
		IsoServer_setEthernetParam(isoServer,(char*)IP_ADDR,(char*)NETMASK_ADDR,(char*)GW_ADDR);

    	// разрешаем запуск тасков зависящих от старта текущего таска
		osMutexRelease(xFTPStartMutex);


	    Port_Off(LED1);
		Port_Off(LED_out_GREEN);

/*****************************************************************************************************
 *
 * многоклиентский доступ
 *
 *****************************************************************************************************/
		while (1){
// Функции контроля над объектами, при управлении от клиента
			IedServer_setControlAllObj(iedServer);

			// this is optional - performs operative checks
			// IedServer_setPerformCheckHandler(iedServer, &iedModel_GGIO_INGGIO1_SPCSO1, checkHandler, &iedModel_GGIO_INGGIO1_SPCSO1);

			IedServer_setConnectionIndicationHandler(iedServer, (IedConnectionIndicationHandler) connectionHandler, NULL);

#if (CONFIG_IEC61850_LOG_SERVICE == 1)
			LogStorage statusLog = SqliteLogStorage_createInstance("log_status.db");
			LogStorage_setMaxLogEntries(statusLog, 10);
			IedServer_setLogStorage(iedServer, "MR801N150LD0/LLN0$EventLog", statusLog);



#if 1
			uint64_t entryID = LogStorage_addEntry(statusLog, Hal_getTimeInMs());		// добавляем запись, возвращает ID записи

			MmsValue* value = MmsValue_newIntegerFromInt32(123);
			uint8_t blob[256];
			int blobSize = MmsValue_encodeMmsData(value, blob, 0, true);
			LogStorage_addEntryData(statusLog, entryID, "MR801N150LD0/IN58GGIO1$ST$Ind1$stVal", blob, blobSize, 0);
			MmsValue_delete(value);

			value = MmsValue_newUtcTimeByMsTime(Hal_getTimeInMs());
			blobSize = MmsValue_encodeMmsData(value, blob, 0, true);
			MmsValue_delete(value);

			LogStorage_addEntryData(statusLog, entryID, "MR801N150LD0/IN58GGIO1$ST$Ind1$t", blob, blobSize, 0);
			LogStorage_getEntries(statusLog, 0, Hal_getTimeInMs(), NULL, (LogEntryDataCallback) NULL, NULL);
//			LogStorage_getEntries(statusLog, 0, Hal_getTimeInMs(), entryCallback, (LogEntryDataCallback) entryDataCallback, NULL);
#endif

#endif

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
		    }else{
		    	// если нет конфига приёмных гусов, то обнулим GoIN флаги у ЦП.
		    	int i;
		    	for(i=0;i<MB_Size_Goose;i++){
		    		ucGooseBufSent[i] = 0;
		    		ucGooseBufDrop[i] = 0;
		    	}

		    	AddToQueueMB(ModbusSentTime, MB_Wrt_Set_Goose	,MB_Slaveaddr);
		    	AddToQueueMB(ModbusSentTime, MB_Wrt_Set_Goose	,MB_Slaveaddr);
		    }
	        //--------------- Goose -------------------------
#endif

			if (!IedServer_isRunning(iedServer)) {
				USART_TRACE_RED("Err. IEC server. stop\n");
				IedServer_destroy(iedServer);
			}else{
				AddToQueueMB(ModbusSentQueue, 	MB_Rd_Revision		,MB_Slaveaddr);		// версию устройства
			}


#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
			//--------------- Goose -------------------------
			// передающая часть гусов. Start GOOSE publishing
		    //if (GoosePublishing_ParseConfigFile(iedServer, _GooseTRcfg) == true){
		    	IedServer_enableGoosePublishing(iedServer);								// если HSR или PRP нужен переинит
    			AddToQueueMB(ModbusSentQueue, MB_Rd_Syscfg		,MB_Slaveaddr);			// ставим задачу чтения конфига
		    //}
			//--------------- Goose -------------------------
#endif

#if (CONFIG_IEC61850_SAMPLED_VALUES_SUPPORT == 1)
			//--------------- SV -------------------------
    		 svPublisher = SampledValuesPublisher_create("vboxnet0");
    		 asdu1 = SampledValuesPublisher_addASDU(svPublisher, "svpub1", NULL, 1);
    		 float1 = SV_ASDU_addFLOAT(asdu1);
    		 float2 = SV_ASDU_addFLOAT(asdu1);
    		 SampledValuesPublisher_setupComplete(svPublisher);
#endif
			running = 1;

			// сокеты -------
//			Print_Sockets();
			// --------------
			while (running) {
#if (CONFIG_IEC61850_SAMPLED_VALUES_SUPPORT == 1)
// -----------------------------------------------
// при частоте SmpRate = 80 выборок за период и количестве мгновенных значений в одном кадре noASDU = 1, фактическая частота формирования кадров
// составит 80 пактов за период или 4 кГц. В случае частоты взятия выборок SmpRate = 256 выборок за период и количестве выборок в кадре noASDU = 8,
// фактическая частота формирования кадров в сеть составит лишь 1,6 кГц.
//
// Отметим, что фактически присвоение метки абсолютного времени каждой выборке не требуется – требуется лишь чтобы выборки,
// сформированные различными устройствами в один и тот же момент времени имели один и тот же идентификатор. Таким идентификатором
// является поле smpCnt – счётчик выборок. Счётчик за одну секунду пробегает значения от 0 до (SmpRate*50-1).
// Номера присваиваются формируемым выборкам одновременно, так что устройство-приёмник данных МЭК 61850-9-2 может легко установить
// соответствие между получаемыми значениями и производить вычисления на их основе. Для того чтобы все устройства сопряжения формировали
// данные с одними и теми же номерами используется внешний синхронизирующий импульс. При использовании секундного импульса счётчик smpCnt
// принимает значение 0 каждый раз при приходе синхроимпульса. Причём выборке с номером «0» соответствует выборка, взятая в момент прихода импульса.
	            SV_ASDU_setFLOAT(asdu1, float1, fVal1);
		        SV_ASDU_setFLOAT(asdu1, float2, fVal2);

		        SV_ASDU_increaseSmpCnt(asdu1);
		        fVal1 += 1.1f;
		        fVal2 += 0.1f;
		        SampledValuesPublisher_publish(svPublisher);

// -----------------------------------------------
#endif

				IedServer_processIncomingData(iedServer);						// Должна вызываться периодически для приёма данных и соединений. Отвечаем на запросы тутже
																				// проверяем было ли соединение на сокет?
				// сначала проанализируем данные

//				if (GLOBAL_QUALITY == QUALITY_VALIDITY_GOOD){					// нет обменов нет анализа
					IedServer_PeriodicUpdateNewData(iedServer);					// обновление данных в модели из буферов памяти. занимает много времени.
//				}
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

/*************************************************************************
 * IedServer_setControlAllObj
 *  активация Функций контроля над всеми объектами, при управлении от клиента
 *************************************************************************/
void	IedServer_setControlAllObj(IedServer self){

    // управление выключателем
#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763) || (defined (MR801) && defined (OLD)) || defined (MR761OBR) ||\
defined (MR5_500) || defined (MR5_700) || defined (MR741)

    IedServer_setControlHandler(self, &iedModel_CTRL_CSWI1_Pos, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_CSWI1_Pos_Oper);
    IedServer_setControlHandler(self, &iedModel_CTRL_XCBR1_Mod,(ControlHandler) controlHandlerForBinaryOutput, &iedModel_CTRL_XCBR1_Mod_Oper);
#endif

// управление приводом
#if defined (MR851)
    IedServer_setControlHandler(self, &iedModel_RPN_ATCC1_TapChg, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_RPN_ATCC1_TapChg_Oper);
    IedServer_setControlHandler(self, &iedModel_RPN_ATCC1_ParOp, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_RPN_ATCC1_ParOp_Oper);

#endif

#if  defined (MR761OBR)
	setControlGGIO2_SPCSOx(self);
#endif


#if defined	(MR801) && defined (T12N5D58R51)
    IedServer_setControlHandler(self, &iedModel_CTRL_CSWI1_Pos, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_CSWI1_Pos_Oper);
    IedServer_setControlHandler(self, &iedModel_CTRL_XCBR1_Mod,(ControlHandler) controlHandlerForBinaryOutput, &iedModel_CTRL_XCBR1_Mod_Oper);
/*
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO1, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO1_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO2, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO2_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO3, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO3_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO4, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO4_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO5, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO5_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO6, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO6_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO7, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO7_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO8, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO8_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO9, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO9_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO10, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO10_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO11, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO11_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO12, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO12_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO13, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO13_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO14, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO14_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO15, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO15_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO16, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO16_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO17, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO17_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO18, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO18_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO19, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO19_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO20, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO20_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO21, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO21_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO22, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO22_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO23, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO23_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO24, (ControlHandler) controlHandlerFor_CMDGGIO,&iedModel_CTRL_CMD24GGIO1_SPCSO24_Oper);
*/

	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO1, (ControlHandler) controlHandlerFor_CMDGGIO,1);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO2, (ControlHandler) controlHandlerFor_CMDGGIO,2);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO3, (ControlHandler) controlHandlerFor_CMDGGIO,3);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO4, (ControlHandler) controlHandlerFor_CMDGGIO,4);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO5, (ControlHandler) controlHandlerFor_CMDGGIO,5);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO6, (ControlHandler) controlHandlerFor_CMDGGIO,6);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO7, (ControlHandler) controlHandlerFor_CMDGGIO,7);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO8, (ControlHandler) controlHandlerFor_CMDGGIO,8);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO9, (ControlHandler) controlHandlerFor_CMDGGIO,9);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO10, (ControlHandler) controlHandlerFor_CMDGGIO,10);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO11, (ControlHandler) controlHandlerFor_CMDGGIO,11);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO12, (ControlHandler) controlHandlerFor_CMDGGIO,12);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO13, (ControlHandler) controlHandlerFor_CMDGGIO,13);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO14, (ControlHandler) controlHandlerFor_CMDGGIO,14);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO15, (ControlHandler) controlHandlerFor_CMDGGIO,15);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO16, (ControlHandler) controlHandlerFor_CMDGGIO,16);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO17, (ControlHandler) controlHandlerFor_CMDGGIO,17);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO18, (ControlHandler) controlHandlerFor_CMDGGIO,18);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO19, (ControlHandler) controlHandlerFor_CMDGGIO,19);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO20, (ControlHandler) controlHandlerFor_CMDGGIO,20);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO21, (ControlHandler) controlHandlerFor_CMDGGIO,21);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO22, (ControlHandler) controlHandlerFor_CMDGGIO,22);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO23, (ControlHandler) controlHandlerFor_CMDGGIO,23);
	IedServer_setControlHandler(self, &iedModel_CTRL_CMD24GGIO1_SPCSO24, (ControlHandler) controlHandlerFor_CMDGGIO,24);

#endif

// для всех приборов
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO1_SPCSO1, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_GGIO1_SPCSO1_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO1_SPCSO2, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_GGIO1_SPCSO2_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO1_SPCSO3, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_GGIO1_SPCSO3_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO1_SPCSO4, (ControlHandler) controlHandlerForBinaryOutput,&iedModel_CTRL_GGIO1_SPCSO4_Oper);

}

/*************************************************************************
 * controlHandlerForBinaryOutput
 *  Функция контроля над бинарным объектом. После изменения этих данных от
 *  клиента, будет вызываться эта функция.
 *************************************************************************/
ControlHandlerResult	controlHandlerForBinaryOutput(void* parameter, MmsValue* value, bool test)
{
	ControlHandlerResult ret = CONTROL_RESULT_OK;
	MmsType		TypeCMD;
	bool 		newState = false;
	uint16_t 	newStateBitstr = 0;
//	USART_TRACE_GREEN("controlHandlerForBinaryOutput MMS_BOOLEAN:\n");

	TypeCMD = MmsValue_getType(value);
	switch(TypeCMD){

	case	MMS_BOOLEAN:
		 	 	 	 	 USART_TRACE("управление BOOLEAN:\n");
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


#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763) || defined (MR761OBR) ||\
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
return ret;
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
#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763) || defined (MR761OBR) ||\
	defined (MR801) ||\
	defined (MR901) || defined (MR902) ||\
	defined (MR851) ||\
	defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)

		writeNmbSG = actSG;

		AddToQueueMB(ModbusSentTime,  MB_Wrt_SG_set_ManNumb	,MB_Slaveaddr);		// приоритет
//18.03.2019 добавил, не читал группу
		AddToQueueMB(ModbusSentQueue, MB_Rd_NumbSG			,MB_Slaveaddr);		// ставим задачу вычитать новые уставки

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
/******************************************************************************
 * добавим к имени уникальность Nx
 * x - последняя цифра IP
 ******************************************************************************/
static void ModelNameModify(IedModel* self, uint16_t	numb)
// ------ добавим к имени уникальность
{
	uint8_t	addIPtoName[50];
	portCHAR pagehits[5];

	memset(addIPtoName,0,50);
	strcat((char *)addIPtoName,(const char *)self->name);
	sprintf(pagehits,"N%u",numb);
	strcat((char *)addIPtoName, pagehits);

	uint8_t	ln = strlen((const char *)addIPtoName)+1;
	self->name = (char*)GLOBAL_MALLOC(ln);
	memset(self->name,0,ln);
	strcat((char *)self->name,(const char *)addIPtoName);
}
