/*
 * main.h
 *
 *  Created on: 16.06.2015
 *      Author: sagok
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "stdint.h"
#include "stdbool.h"
#include "clocks.h"

// ---------------------------------------
// режим отладки резервирования. Узлы в процессе написания и отладки
//#define	 HSR_Debug_Mode
#define	 PRP_Debug_Mode
// ---------------------------------------

#if defined (MR771)
#include "MbMapMR771.h"
#endif
#if defined (MR801)
#include "MbMapMR801.h"
#endif
#if defined (MR851)
#include "MbMapMR851.h"
#endif
#if defined (MR901) || defined (MR902)
#include "MbMapMR90x.h"
#endif
#if defined (MR761) || defined (MR762)|| defined (MR763)
#include "MbMapMR76x.h"
#endif
#if defined (MR5_700) || defined (MR5_600) || defined (MR5_500)
#include "MbMapMR5all.h"
#endif
#if defined (MR741)
#include "MbMapMR741.h"
#endif
/*
#if defined (MR5_700)
#include "MbMapMR5PO70.h"
#endif
#if defined (MR5_600)
#include "MbMapMR5PO60.h"
#endif
#if defined (MR5_500)
#include "MbMapMR5PO50.h"
#endif
*/
#include "versions/version_num.h"
#include "versions/build_defs.h"

/* define --------------------------------------------------------------------*/

#define INTERFACE_THREAD_STACK_SIZE 	( 350 )			// размер стека задачи, ethernetif_input которая по семафору приёма ETH обрабатывает данные

#define IEC850_STACK_SIZE				( configMINIMAL_STACK_SIZE * 15)	//15
#define IEC850Task__PRIORITY			osPriorityIdle//osPriorityLow//osPriorityLow				//osPriorityAboveNormal

#define IEC870_STACK_SIZE				( configMINIMAL_STACK_SIZE * 2)
#define IEC104Con_STACK_SIZE			( configMINIMAL_STACK_SIZE * 4)
#define IEC870Task__PRIORITY			osPriorityIdle//osPriorityLow

#define	MODBUSTask_STACK_SIZE			( configMINIMAL_STACK_SIZE * 4 )
#define MODBUSTask__PRIORITY			osPriorityIdle//osPriorityLow				//osPriorityAboveNormal

#define	GooseDropTask_STACK_SIZE		( configMINIMAL_STACK_SIZE * 4 )
#define	GooseTask_STACK_SIZE			( configMINIMAL_STACK_SIZE * 8 )
#define GooseTask__PRIORITY				osPriorityIdle//osPriorityLow				//osPriorityAboveNormal

#define	TFTPTask_STACK_SIZE				( configMINIMAL_STACK_SIZE * 2 )
#define TFTPTask__PRIORITY				osPriorityLow

#define	FTPTask_STACK_SIZE				( configMINIMAL_STACK_SIZE * 30 )		//40
#define FTPTask__PRIORITY				osPriorityIdle//osPriorityIdle//osPriorityLow

#define	FSTask_STACK_SIZE				( configMINIMAL_STACK_SIZE * 4 )
#define FSTask__PRIORITY				osPriorityLow

#define	HTTPTask_STACK_SIZE				( configMINIMAL_STACK_SIZE * 4 )
#define HTTPTask__PRIORITY				osPriorityNormal

#define DEBUG_CONSOLE_STACK_SIZE		( configMINIMAL_STACK_SIZE * 4 )
#define DEBUG_CONSOLE_TASK_PRIORITY		osPriorityAboveNormal

#define DEBUG_USARTOUT_STACK_SIZE		( configMINIMAL_STACK_SIZE * 4 )
#define DEBUG_USARTOUT_TASK_PRIORITY	osPriorityRealtime


// добавлять бутлодер в прошивку
#define includeBootloader
#define BootloaderVer 			006
/* по включению загрузчик проверяет вектор(размер микросхемы)
 * 005 - базовая версия. netconn.
 * 006 - добавил псевдопрогресс загрузки, спрятал кнопку загрузить после начала прошивки. перевёл с netconn на сокеты с одним клиентом.
 * 		 Добавил перевод в загрузчик по перемычке RX-GND. на отладочном порту. В этом же режиме устанавливаются NTP по умолчанию если там FF
 *
 * 010 - аналог версии 006 но для изделий с память AS6C1608.
 */

// __LINE__, __FILE__, __DATE__, __TIME__, __func__, __VA_ARGS__
//#define BUILDTIME __TIME__
//#define BUILDDATE __DATE__

/*
 * SWRevision 017 - синхронизация времени NTP точность 1с
 * SWRevision 018 - синхронизация времени NTP точность 1мс. Нужна корректировка аппаратных часов.
 * SWRevision 019 - корректировка аппаратных часов.
 * SWRevision 020 - вывел 25МГц на MCO2 для PHY.
 * SWRevision 021 - Фильтр Калмана для корректировки часов
 * SWRevision 022 - Исправил ошибку с получением уставок. иногда получал IP и не получал уставки. в 600 исправил измерение частоты
 * SWRevision 023 - много изменений.
 * SWRevision 023.1 - исправил ошибки состояния mod,beh в GGIO во всех приборах
 * SWRevision 023.2 - исправил ошибки состояния mod,beh в GGIO во ПО60 на МРВ1,2
 * SWRevision 023.3 - 1. 2025год на старте. 2. синхронизация мремени из модбас при отсутствии ответа от NTP _limitlostSNTPPackets пакетов. 3. Вебинтерфейс время последней синхронизации.
 * SWRevision 023.4 - исправлено много по результатам перепроверки. Обмен MB переделан на задачный режим. РП14Бобруйск
 * SWRevision 023.5 - изменения по содержимому моделей.
 * SWRevision 023.5m - ревизия .5 для могилёва. Тех ключ без IP, в имени SeqV вернул ошибочную SeqU
 * SWRevision 023.6 - МР5ПО50: XCBR1_OpCnt. МР5ПОx0 - перезапросы модбаса. счетчик осциллограмм. Есть возможн. чтения последней осц. чистый дамп.
 * SWRevision 023.7 - созданы 2 пробора MR761T4N4 и MR761T4N5 вместо MR761.
 * ----------------------------------------------------------------------------------------------------------------------
 */
typedef struct
{
  uint32_t	errAnalog;
  uint32_t	errDiscreet;
  uint32_t	errUstavki;
  uint32_t	errJurnal;
  uint32_t	errTx;
  uint32_t	errALLCRC;
  uint32_t	errTimeOut;
} errMB_data;

#ifndef _SWRevision
#define _SWRevision     		"Rev. 023.7("__DATE__"-"__TIME__")"//.6debug
#endif

#ifdef _SPCECIALSWRevision
#define _SWRevision     		"Rev. 023.5m("__DATE__"-"__TIME__")"
#endif

#ifndef _ConfigRevision
#define _ConfigRevision  		"1"
#endif

#define _Vendor		    		"BEMN"
#define _LDNS					"IEC 61850-7-4:2010"

#define _SystemNote				"0:/MMSfiles/SysLog.bin"
#define _ErrorNote				"0:/MMSfiles/AlarmLog.bin"
#define _SystemNoteTmp			"0:/tmp/SysLog.bin"
#define _ErrorNoteTmp			"0:/tmp/AlarmLog.bin"

#define _OneOscTmp				"1:/Osc.bin"

#define _GooseREcfg				"1:/cfg/goosere.cfg"
#define _GooseTRcfg				"1:/cfg/goosetr.cfg"

#define _xRCBcfg				"1:/cfg/xRCB.cfg"

#define _Datasetscfg			"1:/cfg/datasets.cfg"

#define _DataListWrites			"1:/cfg/datwrts.def"

#define _httpServer				"1:/http"							// путь к http серверу

// константы во FLASH
#define _Ifboot					0			// 1 байта
#define _IfIPaddr				1			// 4 байта
#define _IfHardFault			5			// 1 байта				CRC для IP адреса

#define _IfNTP_IP				6			// 4 байта IP адрес
#define _IfNTP_Period			10			// 2 байта период обновления
#define _IfNTP_TimeZone			12			// 1 байта часовой пояс
// !константы во FLASH

static const char EEPROMDEFAULT[] = {0, 192, 168, 0, 201, 0, 192, 168, 0, 122, 60, 00, 3};
#define	EEPROMDEFAULTSIZE		13

#define _NTP_Size				7			// размер блока
#define _startsoft				0xFF
#define _startboot				0

#define 	_limitlostSNTPPackets		10		// предел пропущеных пакетов, при котором начинаем читать время из прибора и не из NTP

// Enable/Disable tracing using LED outputs
#define LED_TRACE_ENABLE            1
// Enable/Disable tracing using USART outputs
#define USART_TRACE_ENABLE          1

void 	printfTime (void);

/* Цветной вавод
 * https://www.opennet.ru/base/dev/console_ctl.txt.html
 *
 print '\033[1;30mGray like Ghost\033[1;m'
print '\033[1;31mRed like Radish\033[1;m'
print '\033[1;32mGreen like Grass\033[1;m'
print '\033[1;33mYellow like Yolk\033[1;m'
print '\033[1;34mBlue like Blood\033[1;m'
print '\033[1;35mMagenta like Mimosa\033[1;m'
print '\033[1;36mCyan like Caribbean\033[1;m'
print '\033[1;37mWhite like Whipped Cream\033[1;m'
print '\033[1;38mCrimson like Chianti\033[1;m'
print '\033[1;41mHighlighted Red like Radish\033[1;m'
print '\033[1;42mHighlighted Green like Grass\033[1;m'
print '\033[1;43mHighlighted Brown like Bear\033[1;m'
print '\033[1;44mHighlighted Blue like Blood\033[1;m'
print '\033[1;45mHighlighted Magenta like Mimosa\033[1;m'
print '\033[1;46mHighlighted Cyan like Caribbean\033[1;m'
print '\033[1;47mHighlighted Gray like Ghost\033[1;m'
print '\033[1;48mHighlighted Crimson like Chianti\033[1;m'

 */

#define TIMEOUT_startServer 		10000//30000
#define TIMEOUT_MB_Response 		10				// число пропусков подряд при потери связи в модбасе


#define SRAM_TIMEOUT     ((uint32_t)0xFFFF)

#if (USART_TRACE_ENABLE)

#define  USART_TRACE(...)	{printfTime();\
							printf("\033[1;mDBG: ") ;\
                            printf(__VA_ARGS__);}
                            //printf("\n");

#define  USART_TRACE_RED(...){printfTime();\
							printf("\033[1;31mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");}

#define  USART_TRACE_Yellow(...){printfTime();\
							printf("\033[1;33mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");}


#define  USART_TRACE_HRED(...){printfTime();\
							printf("\033[1;41mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");}

#define  USART_TRACE_GREEN(...)   {printfTime();\
							printf("\033[1;32mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");}

#define  USART_TRACE_BLUE(...)   {printfTime();\
							printf("\033[1;34mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");}

#define  USART_TRACE_MAGENTA(...)   {printfTime();\
							printf("\033[1;35mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");}

#define  USART_TRACE_CYAN(...)   {printfTime();\
							printf("\033[1;36mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");}

#define  USART_0TRACE(...)  {printf(__VA_ARGS__);}

#else
#define  USART_TRACE(...)
#define  USART_TRACE_RED(...)
#define  USART_TRACE_HRED(...)
#define  USART_TRACE_GREEN(...)
#define  USART_TRACE_BLUE(...)
#define  USART_TRACE_MAGENTA(...)
#define  USART_0TRACE(...)
#endif


#define WorkChannel   			CH485_1			/* активный канал для транзита в MODBUS (1: 485_1, 2: 485_2, 3: ETHERNET-MODBUS, 4:ETHERNET-104 */
#define CH485_1					1
#define CH485_2					2
#define ETHERNETMODBUS			3
#define ETHERNET104				4
#define ETHERNET850				5


#define ECHO_Port				7			/* 7 ECHO — предназначен для тестирования связи путём отправки данных на сервер и получения от него их же в неизменном виде*/
#define TFTP_Port				69			/* 69 тривиальный FTP применяется при установке операционной системы, у нас бутлодер */
#define HTTP_Port				80			/* 80 is the port used for HTTP protocol */
#define SSH_Port				23			// telnet
#define FTP_Port				21			/* 21 для передачи команд FTP */
#define IEC104_Port				2404		/* 2404 is the port used for IEC 60870-5-104 protocol */
#define IEC850_Port				102			/* 102 is the port used for IEC 61850 protocol */
#define NTP_PORT				123			/* 123 NTP порт на сервере, к которому будем коннектится для получения времени.*/

#define	IEC850_SECURE_PORT		3782

//#define NTP_IP       "192.168.0.122"	// адрес NTP сервера

// часовой пояс для временных данных по UTC
//#define	Timezone			+3
#define	msInDay					3600*1000 //3600*1000*24	// число мС в сутках
#define	msIn30min				30*1000

#define	stNTPPeriod				msInDay/60


#ifdef STM32F407xx
/*MAC ADDRESS */
#define MAC_ADDR0   0x21
#define MAC_ADDR1   0x64
#define MAC_ADDR2   0x32
#define MAC_ADDR3   0x32
#define MAC_ADDR4   0xD4
#define MAC_ADDR5   0x42
#else
/*MAC ADDRESS */
// micrell потому, что используем контроллер
#define MAC_ADDR0   0x02			// .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
									//
#define MAC_ADDR1   0x02
#define MAC_ADDR2   0x8C
#define MAC_ADDR3   0x00
#define MAC_ADDR4   0x00
#define MAC_ADDR5   0x00
#endif

#define first_IP_ADDR0   192
#define first_IP_ADDR1   168
#define first_IP_ADDR2   0
#define first_IP_ADDR3   254

/*Static IP ADDRESS*/
#define second_IP_ADDR0   192
#define second_IP_ADDR1   168
#define second_IP_ADDR2   0
#define second_IP_ADDR3   252
/*NETMASK*/
#define NETMASK_ADDR0   255
#define NETMASK_ADDR1   255
#define NETMASK_ADDR2   255
#define NETMASK_ADDR3   0

/*Gateway Address*/
#define GW_ADDR0   192
#define GW_ADDR1   168
#define GW_ADDR2   0
#define GW_ADDR3   1

/*NTP Address*/
#define NTP_IP_ADDR0   	192
#define NTP_IP_ADDR1   	168
#define NTP_IP_ADDR2   	0
#define NTP_IP_ADDR3   	122


//#define		DbPercent		100000		// 0,001%

/* UserID and Password definition *********************************************/
#define USERID       	"admin"
#define PASSWORD     	"admin"

#define USERIDboot       "boot"
#define PASSWORDboot     "admin"

#define LOGIN_SIZE   (15+ sizeof(USERID) + sizeof(PASSWORD))


#define  _RECEIVE_WAIT_lim 		4000
/*
typedef enum
{
	MB_Wr_Set_ExtMode = 2,
	MB_Wr_LEDS_OFF = 3,
	MB_Wr_Error_OFF = 4,
	MB_Wr_SysNote_OFF = 5,
	MB_Wr_BLK_OFF = 6,
	MB_Wr_DRIVE_UP = 7,
	MB_Wr_DRIVE_DWN = 8,
	MB_Wr_Clr_ExtMode = 9,
//	MB_Wr_Set_Time = 10
} Mb_writeCMD;

typedef enum
{
	MB_Wr_none	= 0,
	MB_Wr_SwON = 1,
	MB_Wr_SwOFF = 2,
	MB_Wr_Reset_LEDS = 3,
	MB_Wr_Reset_Error = 4,
//	MB_Wr_Reset_SysNote = 5,
	MB_Wr_Reset_ErrorNote = 6,
	MB_Wr_SG_set_0 = 7,
	MB_Wr_SG_set_1 = 8,
	MB_Wr_Reset_SysNote = 9,
	MB_Wr_Set_Time = 10,

} Mb_writeCMD1;
*/
typedef enum
{
	MB_Rd_Revision			= 0,
	MB_Rd_Discreet			= 1,
	MB_Rd_Analog			= 2,

	MB_Rd_AllUstavki 		= 10,			// общие уставки usConfigOtherUstavkiStart
	MB_Rd_Get_Time 			= 11,
	MB_Rd_Syscfg 			= 12,
	MB_Rd_Ustavki 			= 13,
	MB_Rd_ConfigSWCrash 	= 14,
	MB_Rd_ConfigSW			= 15,
	MB_Rd_NumbSG			= 16,

//	MB_Rd_ConfigOut			= 20,			// тоже самое MB_Rd_ConfigVLSOut
	MB_Rd_ConfigExZ			= 21,
	MB_Rd_ConfigF			= 22,
	MB_Rd_ConfigU			= 23,
	MB_Rd_ConfigMTZ			= 24,
	MB_Rd_ConfigI2I1I0		= 25,
	MB_Rd_ConfigAutomat		= 26,
//	MB_Rd_ConfigZ			= 27,
	MB_Rd_ConfigAPW			= 28,
	MB_Rd_ConfigAWR			= 29,
	MB_Rd_ConfigTRPWR		= 30,
	MB_Rd_ConfigTRMeas		= 31,
	MB_Rd_ConfigVLSIn		= 32,
	MB_Rd_ConfigVLSOut		= 33,
	MB_Rd_ConfigRPN			= 34,

	MB_Rd_SysNote 			= 40,
	MB_Rd_ErrorNote 		= 41,
	MB_Rd_OscNote			= 42,
	MB_Rd_OscMessage		= 43,
	MB_Rd_EndAddr			= 44,
	MB_Rd_none				= 0xFFFF,


	MB_Wrt_Set_Time			= 101,

	MB_Wrt_Reset_LEDS 		= 103,
	MB_Wrt_Reset_Error 		= 104,
	MB_Wrt_Reset_OscNote 	= 105,
	MB_Wrt_Reset_SysNote 	= 106,
	MB_Wrt_Reset_ErrorNote 	= 107,
	MB_Wrt_Reset_BLK		= 108,
	MB_Wrt_Reset_Ustavki 	= 109,

	MB_Wrt_Set_ExtMode 		= 110,
	MB_Wrt_Clr_ExtMode 		= 111,
	MB_Wrt_DRIVE_UP 		= 112,					//851
	MB_Wrt_DRIVE_DWN 		= 113,					//851
	MB_Wrt_SysNoteAdr0		= 114,
	MB_Wrt_ErrorNoteAdr0	= 115,
	MB_Wrt_OscNoteAdr0		= 116,
	MB_Wrt_OscMessageAdrPg	= 117,

	MB_Wrt_SwON 			= 121,
	MB_Wrt_SwOFF 			= 122,

	MB_Wrt_SG_set_0			= 131,
	MB_Wrt_SG_set_1			= 132,

	MB_Wrt_SG_set_ManNumb	= 133,

	MB_Wrt_Set_Goose		= 141,

} Mb_readCMD;

//_______________________________________________________________________________________
// размер буфера для работы DEBUG USART
#define		BOOT_BUF_MAX_OUTPUT_SIZE		250//150

/* Converts a time in milliseconds to a time in ticks. */
#define pdMS_TO_TICKS( xTimeInMs ) ( ( TickType_t ) ( ( ( TickType_t ) ( xTimeInMs ) * ( TickType_t ) configTICK_RATE_HZ ) / ( TickType_t ) 1000 ) )

#include "ConfBoard.h"

/* FatFs includes component */
#include "ff_gen_drv.h"
//#include "spimem_diskio.h"

extern void Port_Init(Port_TypeDef Port,uint32_t mode);
extern void Port_On(Port_TypeDef Port);
extern void Port_Off(Port_TypeDef Port);
extern void Port_Toggle(Port_TypeDef Port);

void vOutputDEBUG( char *pcMessage );

#endif /* MAIN_H_ */
