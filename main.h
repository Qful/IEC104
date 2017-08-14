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
#if defined (MR5_700)
#include "MbMapMR5PO70.h"
#endif
#if defined (MR5_600)
#include "MbMapMR5PO60.h"
#endif

#include "versions/version_num.h"
#include "versions/build_defs.h"


// добавлять бутлодер в прошивку
#define includeBootloader

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
 */
typedef struct					// для передачи через очереди структур.
{
  uint32_t	errAnalog;
  uint32_t	errDiscreet;
  uint32_t	errSW;
} errMB_data;

#ifndef _SWRevision
#define _SWRevision     "SWRev. 023.3("__DATE__"-"__TIME__")"
#endif

#ifndef _ConfigRevision
#define _ConfigRevision  "1"
#endif

#define _Vendor		    "BEMN"
#define _LDNS			"IEC 61850-7-4:2011"

#if defined (MR5_500)
#define _swREV			"MR5 PO50"
#endif
#if defined (MR5_600_)
#define _swREV			"MR5 PO60"
#endif


#define _SystemNote		"0:/MMSfiles/Jurnal.bin"
#define _ErrorNote		"0:/MMSfiles/Error.bin"

// константы во FLASH
#define _Ifboot				0			// 1 байта
#define _IfIPaddr			1			// 4 байта
#define _IfHardFault		5			// 1 байта				CRC для IP адреса

#define _IfNTP_IP			6			// 4 байта IP адрес
#define _IfNTP_Period		10			// 2 байта период обновления
#define _IfNTP_TimeZone		12			// 1 байта часовой пояс
// !константы во FLASH

static const char EEPROMDEFAULT[] = {0, 192, 168, 0, 201, 0, 192, 168, 0, 122, 60, 00, 3};
#define	EEPROMDEFAULTSIZE	13

#define _NTP_Size			7			// размер блока
#define _startsoft			0xFF
#define _startboot			0
//__attribute__((__section__(".eb0rodata"))) const uint8_t userConfig[0x7FFC];// = {1,2,3,4,5,6,7,8,9,0};


// функции тестирования памяти. Только в режиме стека во внутренней паямяти. (_estack = 0x2001FFFF;)
//#define		memtest


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

#define SRAM_TIMEOUT     ((uint32_t)0xFFFF)

#if (USART_TRACE_ENABLE)

#define  USART_TRACE(...)	printfTime();\
							printf("\033[1;mDBG: ") ;\
                            printf(__VA_ARGS__);
                            //printf("\n");

#define  USART_TRACE_RED(...)printfTime();\
							printf("\033[1;31mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");

#define  USART_TRACE_Yellow(...)printfTime();\
							printf("\033[1;33mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");


#define  USART_TRACE_HRED(...)printfTime();\
							printf("\033[1;41mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");

#define  USART_TRACE_GREEN(...)   printfTime();\
							printf("\033[1;32mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");

#define  USART_TRACE_BLUE(...)   printfTime();\
							printf("\033[1;34mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");

#define  USART_TRACE_MAGENTA(...)   printfTime();\
							printf("\033[1;35mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");
#define  USART_0TRACE(...)  printf(__VA_ARGS__);

#else
#define USART_TRACE(...)
#define USART_TRACE_RED(...)
#define  USART_TRACE_HRED(...)
#define  USART_TRACE_GREEN(...)
#define  USART_TRACE_BLUE(...)
#define  USART_TRACE_MAGENTA(...)
#define  USART_0TRACE(...)
#endif


#define WorkChannel   	CH485_1			/* активный канал для транзита в MODBUS (1: 485_1, 2: 485_2, 3: ETHERNET-MODBUS, 4:ETHERNET-104 */
#define CH485_1				1
#define CH485_2				2
#define ETHERNETMODBUS		3
#define ETHERNET104			4
#define ETHERNET850			5


#define ECHO_Port		7			/* 7 ECHO — предназначен для тестирования связи путём отправки данных на сервер и получения от него их же в неизменном виде*/
#define TFTP_Port		69			/* 69 тривиальный FTP применяется при установке операционной системы, у нас бутлодер */
#define HTTP_Port		80			/* 80 is the port used for HTTP protocol */
#define SSH_Port		23			// telnet
#define FTP_Port		21			/* 21 для передачи команд FTP */
#define IEC104_Port		2404		/* 2404 is the port used for IEC 60870-5-104 protocol */
#define IEC850_Port		102			/* 102 is the port used for IEC 61850 protocol */
#define NTP_PORT		123			/* 123 NTP порт на сервере, к которому будем коннектится для получения времени.*/

#define	IEC850_SECURE_PORT		3782

//#define NTP_IP       "192.168.0.122"	// адрес NTP сервера


// часовой пояс для временных данных по UTC
//#define	Timezone	+3
#define	msInDay		3600*1000 //3600*1000*24	// число мС в сутках
#define	msIn30min	30*1000

#define	stNTPPeriod		msInDay/60


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

#ifdef STM32F407xx
/*Static IP ADDRESS for first*/
#define first_IP_ADDR0   192
#define first_IP_ADDR1   168
#define first_IP_ADDR2   0
#define first_IP_ADDR3   253
#else
#define first_IP_ADDR0   192
#define first_IP_ADDR1   168
#define first_IP_ADDR2   0
#define first_IP_ADDR3   254
#endif
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


/* UserID and Password definition *********************************************/
#define USERID       	"admin"
#define PASSWORD     	"admin"

#define USERIDboot       "boot"
#define PASSWORDboot     "admin"

#define LOGIN_SIZE   (15+ sizeof(USERID) + sizeof(PASSWORD))



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

typedef enum
{
	MB_Rd_Revision		= 0,
	MB_Rd_Discreet		= 1,
	MB_Rd_Analog		= 2,

	MB_Rd_AllUstavki 	= 10,
	MB_Rd_SysNote 		= 40,
	MB_Rd_ErrorNote 	= 41,
	MB_Rd_EndAddr		= 42,
	MB_Rd_none			= 0xFF,
} Mb_readCMD;

#if defined (MR5_600_)
//Modbus  MR5-ПО60
#define MB_Speed				115200
#define MB_Slaveaddr   			1

#define MB_StartConfig		   	0x1000			// уставки
#define MB_NumbConfigall   		0x4E			// 7C больше нельзя//274/2			// 274
#define MB_offset_OMP			0x0D
#define MB_offset_BlockSDTU		0x17



#define MB_offset_Ktn			0x0001			//.
#define MB_offset_Ktnnp			0x0003			//.

#define MB_offsetIP				0x0272
#define MB_NumbIP		   		2

#define MB_StartConfigNaddr   	0x1277			// временно читаем только IP адрес учтройства. 1270 - 4 слова
#define MB_NumbConfig	   		2



#define MB_StartDiscreetaddr   	0x1800			// адрес и размер для комманд чтения (3,4)
#define MB_NumbDiscreet   		0x10			// перечисления в словах а ответ в байтах


#define MB_offset_adr0			0x00

#define MB_bOffsetSettingGr		1<<3
#define MB_bOffsetError			1<<5
#define MB_bOffsetSysNote		1<<6
#define MB_bOffsetErrorNote		1<<7


#define MB_offsetLED			0x02
#define MB_offsetRelay			0x03

#define MB_offsetError			0x05
#define MB_bOffsetMCAU			1<<3
#define MB_bOffsetMCAI			1<<4
#define MB_bOffsetMRV			1<<5

#define MB_offsetDiscreet		0x08
#define MB_boffsetDiscreet1		1<<8
#define MB_boffsetDiscreet2		1<<9
#define MB_boffsetDiscreet3		1<<10
#define MB_boffsetDiscreet4		1<<11
#define MB_boffsetDiscreet5		1<<12
#define MB_boffsetDiscreet6		1<<13
#define MB_boffsetDiscreet7		1<<14
#define MB_boffsetDiscreet8		1<<15

#define MB_offsetLogic			0x09


#define MB_offsetDirGeneral		0x18

#define MB_offsetDiscreet4		0x04
#define MB_bOffsetErrorHard		1<<0
#define MB_bOffsetErrorLogic	1<<1
#define MB_bOffsetErrorData		1<<2

#define MB_bOffsetErrorSW		1<<4
#define MB_bOffsetErrorMeasI	1<<5
#define MB_bOffsetErrorMeasU	1<<6
#define MB_bOffsetErrorMeasF	1<<7

#define MB_offsetDiscreet8		0x08

#define MB_offsetSW_OFF			1<<1
#define MB_offsetSW_ON			1<<0

#define MB_PTOC_In				1<<0
#define MB_error_In				1<<1
#define MB_PTOC_Ia				1<<2
#define MB_error_Ia				1<<3
#define MB_PTOC_Ib				1<<4
#define MB_error_Ib				1<<5
#define MB_PTOC_Ic				1<<6
#define MB_error_Ic				1<<7
#define MB_PTOC_I0				1<<8
#define MB_error_I0				1<<9
#define MB_PTOC_I1				1<<10
#define MB_error_I1				1<<11
#define MB_PTOC_I2				1<<12
#define MB_error_I2				1<<13

#define MB_errorMSAU			1<<4
#define MB_errorMRV1			1<<5
#define MB_errorMRV2			1<<6
#define MB_errorMSD1			1<<7




#define MB_StartAnalogINaddr   	0x1900
#define MB_NumbAnalog   		12

#define MB_offset_Un			0x00
#define MB_offset_Ua			0x01
#define MB_offset_Ub			0x02
#define MB_offset_Uc			0x03
#define MB_offset_Uab			0x04
#define MB_offset_Ubc			0x05
#define MB_offset_Uca			0x06
#define MB_offset_NU0			0x07
#define MB_offset_NU1			0x08
#define MB_offset_NU2			0x09
#define MB_offset_Hz			0x0A


#define MB_StartDateNaddr   	0x0200
#define MB_NumbDate		   		7

#define MB_addr_SG				0x0400
#define MB_selectGroupe0		0x0000
#define MB_selectGroupe1		0x0001


#define MB_StartRevNaddr   		0x0500
#define MB_NumbWordRev	   		16

#define MB_addr_SwOFF  			0x1800		//адрес выключеня off
#define MB_addr_SwON   			0x1801		//адрес включеня on
#define MB_SwOFF  				0x0000		//off
#define MB_SwON   				0xFF00		//on

#define MB_addr_LEDS_OFF		0x1804
#define MB_addr_Error_OFF		0x1805
#define MB_addr_SysNote_OFF		0x1806
#define MB_addr_ErrorNote_OFF	0x1807
#define MB_CTRL_OFF				0xFF00

#define MB_addr_Time_SET		0x0200

#define MB_StartSWCrash   		0x1A00			// ресурс выключателя
#define MB_NumbSWCrash			8

#define MB_PerForSynchClock		1				// период пересинхронизации часов
#define MB_PerForReadMODBUS		150				// период опроса модбас в мс

#endif
#if defined (MR5_500_old)
//Modbus  MR5-ПО50
#define MB_Speed				115200
#define MB_Slaveaddr   			1

#define MB_StartConfig		   	0x1000			// уставки
#define MB_NumbConfigall   		0x4E			// 7C больше нельзя//274/2			// 274
#define MB_offset_OMP			0x0D
#define MB_offset_BlockSDTU		0x17


#define MB_offset_Ktt			0x0001			//.
#define MB_offset_Kttnp			0x0002			//.
#define MB_offset_Ktn			0x0009			//.
#define MB_offset_Ktnnp			0x000B			//.

#define MB_offsetIP				0x0272
#define MB_NumbIP		   		2

#define MB_StartConfigNaddr   	0x1272			// временно читаем только IP адрес учтройства. 1270 - 4 слова
#define MB_NumbConfig	   		2



#define MB_StartDiscreetaddr   	0x1800			// адрес и размер для комманд чтения (3,4)
#define MB_offset_adr0			0x00

#define MB_bOffsetSettingGr		1<<3
#define MB_bOffsetError			1<<5
#define MB_bOffsetSysNote		1<<6
#define MB_bOffsetErrorNote		1<<7


#define MB_offsetLED			0x02

#define MB_NumbDiscreet   		0x1B			// перечисления в словах а ответ в байтах
#define MB_offsetRelay			0x03

#define MB_offsetError			0x05
#define MB_bOffsetMCAU			1<<3
#define MB_bOffsetMCAI			1<<4
#define MB_bOffsetMRV			1<<5

#define MB_offsetDiscreet		0x09
#define MB_offsetLogic			0x0A
#define MB_offset_I_IO			0x0B

#define MB_offsetPTOC			0x11
#define MB_bTotVAZ				1<<15
#define MB_bTotWZ				1<<14

#define MB_offsetDirGeneral		0x18

#define MB_offsetDiscreet4		0x04
#define MB_bOffsetErrorHard		1<<0
#define MB_bOffsetErrorLogic	1<<1
#define MB_bOffsetErrorData		1<<2

#define MB_bOffsetErrorSW		1<<4
#define MB_bOffsetErrorMeasI	1<<5
#define MB_bOffsetErrorMeasU	1<<6
#define MB_bOffsetErrorMeasF	1<<7

#define MB_offsetDiscreet8		0x08

#define MB_offsetSW_OFF			1<<1
#define MB_offsetSW_ON			1<<0

#define MB_PTOC_In				1<<0
#define MB_error_In				1<<1
#define MB_PTOC_Ia				1<<2
#define MB_error_Ia				1<<3
#define MB_PTOC_Ib				1<<4
#define MB_error_Ib				1<<5
#define MB_PTOC_Ic				1<<6
#define MB_error_Ic				1<<7
#define MB_PTOC_I0				1<<8
#define MB_error_I0				1<<9
#define MB_PTOC_I1				1<<10
#define MB_error_I1				1<<11
#define MB_PTOC_I2				1<<12
#define MB_error_I2				1<<13

#define MB_errorMSAU			1<<3
#define MB_errorMSAI			1<<4
#define MB_errorMRV1			1<<5
#define MB_errorMSD1			1<<6
#define MB_errorMSD2			1<<7



#define MB_StartAnalogINaddr   	0x1900
#define MB_NumbAnalog   		8		//22

#define MB_offset_In			0x00
#define MB_offset_Ia			0x01
#define MB_offset_Ib			0x02
#define MB_offset_Ic			0x03

#define MB_offset_NI0			0x04
#define MB_offset_NI1			0x05
#define MB_offset_NI2			0x06

#define MB_offset_Un			0x08
#define MB_offset_Ua			0x09
#define MB_offset_Ub			0x0A
#define MB_offset_Uc			0x0B	//11

#define MB_offset_Uab			12
#define MB_offset_Ubc			13
#define MB_offset_Uca			14

#define MB_offset_NU0			15
#define MB_offset_NU1			16
#define MB_offset_NU2			17


#define MB_offset_Hz			18
#define MB_offset_TotPF			19
#define MB_offset_TotW			20
#define MB_offset_TotVAr		21
#define MB_offset_OMPLkz		22

#define MB_StartDateNaddr   	0x0200
#define MB_NumbDate		   		7

#define MB_addr_SG				0x0400
#define MB_selectGroupe0		0x0000
#define MB_selectGroupe1		0x0001


#define MB_StartRevNaddr   		0x0500
#define MB_NumbWordRev	   		16

#define MB_addr_SwOFF  			0x1800		//адрес выключеня off
#define MB_addr_SwON   			0x1801		//адрес включеня on
#define MB_SwOFF  				0x0000		//off
#define MB_SwON   				0xFF00		//on

#define MB_addr_LEDS_OFF		0x1804
#define MB_addr_Error_OFF		0x1805
#define MB_addr_SysNote_OFF		0x1806
#define MB_addr_ErrorNote_OFF	0x1807
#define MB_CTRL_OFF				0xFF00


#define MB_StartSWCrash   		0x1A00			// ресурс выключателя
#define MB_NumbSWCrash			8

#define MB_PerForSynchClock		1				// период пересинхронизации часов
#define MB_PerForReadMODBUS		150				// период опроса модбас в мс
#endif



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
