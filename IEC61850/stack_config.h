/*
 * config.h
 *
 * Contains global defines to configure the stack. You need to recompile the stack to make
 * changes effective (make clean; make)
 *
 */

#ifndef STACK_CONFIG_H_
#define STACK_CONFIG_H_

/* print debugging information with printf */
#define DEBUG 					1
#define DEBUG_MMS_SERVER 		0
#define DEBUG_MMS_CLIENT		1
#define	DEBUG_IED_SERVER		0
#define	DEBUG_ISO_SERVER		0
#define	DEBUG_SOCKET			1
#define	DEBUG_GOOSE_PUBLISHER	1

#define STATIC_MODEL 			1

#define sockTimeOut				5

/* Maximum MMS PDU SIZE - default is 65000 */
#define MMS_MAXIMUM_PDU_SIZE 			16384//4096//2048						//1200//4096//8192//2048

// reserve 64k for dynamic memory allocation  this can be optimized maybe there is a good guess for the required memory size
// sendNextReportEntry()
#define LOCAL_STORAGE_MEMORY			16384

#define	CONFIG_MMS_MAXIMUM_PDU_SIZE		MMS_MAXIMUM_PDU_SIZE

/*
 * Enable single threaded mode
 *
 * 1 ==> server runs in single threaded mode (a single thread for the server and all client connections) (один поток для сервера и все клиентские соединения)
 * 0 ==> server runs in multi-threaded mode (one thread for each connection and one server background thread )
 * 0 ==> Сервер работает в многопоточном режиме (один поток для каждого соединения и одного сервера в фоновом потоке)
 */
#define CONFIG_MMS_SINGLE_THREADED 		0	//0

/*
 * Optimize stack for threadless operation - don't use semaphores
 *
 * WARNING: If set to 1 normal single- and multi-threaded server are no longer working!
 */
#define CONFIG_MMS_THREADLESS_STACK 	1	//1				// для многопоточности


/* number of concurrent MMS client connections the server accepts, -1 for no limit */
#define CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS 		3

/* activate TCP keep alive mechanism. 1 -> activate */
/*
 * Механизм tcp_keepalive имеет двойное назначение:
 * он может использоваться как для искусственного поддержания активности соединения,
 * так и для выявления разорванных (так называемых «полуоткрытых») соединений.
 */
#define CONFIG_ACTIVATE_TCP_KEEPALIVE 	1

/* time (in s) between last message and first keepalive message */
#define CONFIG_TCP_KEEPALIVE_IDLE 		5

/* time between subsequent keepalive messages if no ack received */
#define CONFIG_TCP_KEEPALIVE_INTERVAL 	2

/* number of not missing keepalive responses until socket is considered dead */
#define CONFIG_TCP_KEEPALIVE_CNT 		2

/* maximum COTP (ISO 8073) TPDU size - valid range is 1024 - 16384 */
#define CONFIG_COTP_MAX_TPDU_SIZE 		4096//1024

/* timeout while reading from TCP stream in ms */
#define CONFIG_TCP_READ_TIMEOUT_MS 		1000				//1000

// поддержка GOOSE в сборке -------------------------------------------------------------------------------------------
/* Set to 1 to include GOOSE support in the build. Otherwise set to 0 */
#define CONFIG_INCLUDE_GOOSE_SUPPORT 				0//1

/* Ethernet interface ID for GOOSE and SV */
#define CONFIG_ETHERNET_INTERFACE_ID "eth0"

/* The GOOSE retransmission interval in ms for the stable condition - i.e. no monitored value changed */
#define CONFIG_GOOSE_STABLE_STATE_TRANSMISSION_INTERVAL 5000

/* The GOOSE retransmission interval in ms in the case an event happens. */
#define CONFIG_GOOSE_EVENT_RETRANSMISSION_INTERVAL 500

/* The number of GOOSE retransmissions after an event */
#define CONFIG_GOOSE_EVENT_RETRANSMISSION_COUNT 	2

#define CONFIG_GOOSE_GOID_WRITABLE 					0
#define CONFIG_GOOSE_DATSET_WRITABLE 				0
#define CONFIG_GOOSE_CONFREV_WRITABLE 				0
#define CONFIG_GOOSE_NDSCOM_WRITABLE 				0
#define CONFIG_GOOSE_DSTADDRESS_WRITABLE 			0
#define CONFIG_GOOSE_MINTIME_WRITABLE 				0
#define CONFIG_GOOSE_MAXTIME_WRITABLE 				0
#define CONFIG_GOOSE_FIXEDOFFS_WRITABLE 			0

/* The default value for the priority field of the 802.1Q header (allowed range 0-7) */
#define CONFIG_GOOSE_DEFAULT_PRIORITY 				4

/* The default value for the VLAN ID field of the 802.1Q header - the allowed range is 2-4096 or 0 if VLAN/priority is not used */
#define CONFIG_GOOSE_DEFAULT_VLAN_ID 				0

/* Configure the 16 bit APPID field in the GOOSE header */
#define CONFIG_GOOSE_DEFAULT_APPID 					0x1000

/* Default destination MAC address for GOOSE */
#define CONFIG_GOOSE_DEFAULT_DST_ADDRESS {0x01, 0x0c, 0xcd, 0x01, 0x00, 0x01}

//------------------------------------------------------------------------------------------------------------------------
/* include support for IEC 61850 control services */
#define CONFIG_IEC61850_CONTROL_SERVICE 	1

/* The default select timeout in ms. This will apply only if no sboTimeout attribute exists for a control object. Set to 0 for no timeout. */
#define CONFIG_CONTROL_DEFAULT_SBO_TIMEOUT 	15000

//------------------------------------------------------------------------------------------------------------------------
/* include support for IEC 61850 reporting services */
#define CONFIG_IEC61850_REPORT_SERVICE 		1

/* support buffered report control blocks with ResvTms field */
#define CONFIG_IEC61850_BRCB_WITH_RESVTMS 	0

/* The default buffer size of buffered RCBs in bytes */
#define CONFIG_REPORTING_DEFAULT_REPORT_BUFFER_SIZE 	4096

//------------------------------------------------------------------------------------------------------------------------
/* include support for setting groups */
#define CONFIG_IEC61850_SETTING_GROUPS 		1

/* default reservation time of a setting group control block in s */
#define CONFIG_IEC61850_SG_RESVTMS 			300

//------------------------------------------------------------------------------------------------------------------------
/* include support for IEC 61850 log services */
#define CONFIG_IEC61850_LOG_SERVICE 		0

//------------------------------------------------------------------------------------------------------------------------
/* MMS virtual file store base path - where MMS file services are looking for files */
#define CONFIG_VIRTUAL_FILESTORE_BASEPATH "./vmd-filestore/"

/* Maximum number of open file per MMS connection (for MMS file read service) */
#define CONFIG_MMS_MAX_NUMBER_OF_OPEN_FILES_PER_CONNECTION 	5

//------------------------------------------------------------------------------------------------------------------------
/* Maximum number of the domain specific data sets - this also includes the static (pre-configured) and dynamic data sets */
#define CONFIG_MMS_MAX_NUMBER_OF_DOMAIN_SPECIFIC_DATA_SETS 		10

/* Maximum number of association specific data sets */
#define CONFIG_MMS_MAX_NUMBER_OF_ASSOCIATION_SPECIFIC_DATA_SETS 10

/* Maximum number of VMD specific data sets */
#define CONFIG_MMS_MAX_NUMBER_OF_VMD_SPECIFIC_DATA_SETS 		10

/* Maximum number of the members in a data set (named variable list) */
#define CONFIG_MMS_MAX_NUMBER_OF_DATA_SET_MEMBERS 				100
//------------------------------------------------------------------------------------------------------------------------



/* Enable reporting - Note reporting also includes datasets */
#define CONFIG_REPORTING 	1

/* Definition of supported services */
#define MMS_DEFAULT_PROFILE 1

#if MMS_DEFAULT_PROFILE
#define MMS_READ_SERVICE 					1
#define MMS_WRITE_SERVICE 					1
#define MMS_GET_NAME_LIST 					1
#define MMS_JOURNAL_SERVICE 				0
#define MMS_GET_VARIABLE_ACCESS_ATTRIBUTES 	1
#define MMS_DATA_SET_SERVICE 				1
#define MMS_DYNAMIC_DATA_SETS 				1
#define MMS_GET_DATA_SET_ATTRIBUTES 		1
#define MMS_STATUS_SERVICE 					0
#define MMS_IDENTIFY_SERVICE 				0
#define MMS_FILE_SERVICE 					1
#endif /* MMS_DEFAULT_PROFILE */

#if (MMS_WRITE_SERVICE != 1)
#undef CONFIG_IEC61850_CONTROL_SERVICE
#define CONFIG_IEC61850_CONTROL_SERVICE 0
#endif

#endif /* STACK_CONFIG_H_ */

/* support flat named variable name space required by IEC 61850-8-1 MMS mapping */
#define CONFIG_MMS_SUPPORT_FLATTED_NAME_SPACE 			1

/* VMD scope named variables are not used by IEC 61850 (one application is ICCP) */
#define CONFIG_MMS_SUPPORT_VMD_SCOPE_NAMED_VARIABLES 	0

/* Sort getNameList response according to the MMS specified collation order - this is required by the standard
 * Set to 0 only for performance reasons and when no certification is required! */
#define CONFIG_MMS_SORT_NAME_LIST 						1

#define CONFIG_INCLUDE_PLATFORM_SPECIFIC_HEADERS 		0

/* use short FC defines as in old API */
#define CONFIG_PROVIDE_OLD_FC_DEFINES 					0
