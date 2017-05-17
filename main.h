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

//#define _RELEASE_BUILD_NUMBER_ ${build_number}

// добавлять бутлодер в прошивку
#define includeBootloader

/*
 * SWRevision 017 - синхронизация времени NTP точность 1с
 * SWRevision 018 - синхронизация времени NTP точность 1мс. Нужна корректировка аппаратных часов.
 * SWRevision 019 - корректировка аппаратных часов.
 * SWRevision 020 - вывел 25МГц на MCO2 для PHY.
 * SWRevision 021 - Фильтр Калмана для корректировки часов
 * SWRevision 022 - Исправил ошибку с получением уставок. иногда получал IP и не получал уставки. в 600 исправил измерение частоты
 */
#ifndef _SWRevision
#define _SWRevision     "SWRevision 023.12052017.1"
#endif

#define _Vendor		    "BEMN"
#define _LDNS			"IEC 61850-7-4:2007"

#if defined (MR5_500)
#define _swREV			"MR5 PO50"
#endif
#if defined (MR5_600)
#define _swREV			"MR5 PO60"
#endif
#if defined (MR5_700)
#define _swREV			"MR5 PO70"
#endif
#if defined (MR771)
//#define _swREV			"MR771"
#endif
#if defined (MR801)
//#define _swREV			"MR801"
#endif
#if defined (MR901)
#define _swREV			"MR901"
#endif
#if defined (MR902)
#define _swREV			"MR902"
#endif
#if defined (MR761)
#define _swREV			"MR761"
#endif
#if defined (MR762)
#define _swREV			"MR762"
#endif
#if defined (MR763)
#define _swREV			"MR763"
#endif



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

/* Flash user area definition *************************************************/
/*
   IMPORTANT NOTE:
   ==============
   Be sure that USER_FLASH_FIRST_PAGE_ADDRESS do not overlap with IAP code.
   For example, with all option enabled the total readonly memory size using
   Atollic TrueSTUDIO compiler v5, is 76676 bytes
   Based on this result four sectors of 16 Kbytes and a sector of 64 Kbytes will
   be used to store the IAP code, so the user Flash address will start from Sector5.

   In this application the define USER_FLASH_FIRST_PAGE_ADDRESS is set to 128K boundary,
   but it can be changed to any other address outside the 1st 128 Kbytes of the Flash.
   */
//#define USER_FLASH_FIRST_PAGE_ADDRESS 0x08020000 /* Only as example see comment */
//#define USER_FLASH_LAST_PAGE_ADDRESS  0x081E0000
//#define USER_FLASH_END_ADDRESS        0x081FFFFF


/* UserID and Password definition *********************************************/
#define USERID       "admin"
#define PASSWORD     "admin"

#define USERIDboot       "boot"
#define PASSWORDboot     "admin"

#define LOGIN_SIZE   (15+ sizeof(USERID) + sizeof(PASSWORD))


/*
//Modbus  MR801
#define MB_Slaveaddr   			1
#define MB_StartDiscreetaddr   	0x0D00
#define MB_NumbDiscreet   		40

#define MB_StartAnalogINaddr   	0x0E00
#define MB_NumbAnalogIN   		57

#define MB_StartDateNaddr   	0x0200
#define MB_NumbDate		   	+	7
*/


#if defined (MR5_700)
//Modbus  MR5-ПО70
#define MB_Speed				115200
#define MB_Slaveaddr   			1

#define MB_StartConfig		   	0x1000			// уставки
#define MB_NumbConfigall   		0x4E			// 7C больше нельзя//274/2			// 274
#define MB_offset_OMP			0x0D
#define MB_offset_BlockSDTU		0x17

#define MB_offset_ControlBits		0x3B
#define MB_bOffset_ControlButtons	1<<0			// управление от кнопок
#define MB_bOffset_ControlKey		1<<1			// управление от ключа
#define MB_bOffset_ControlExt		1<<2			// внешнее управление
#define MB_bOffset_ControlSDTU		1<<3			// управление от СДТУ


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
#define MB_NumbAnalog   		23		//22

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
#define MB_PerForReadMODBUS		100				// период опроса модбас в мс	150
#endif

#if defined (MR5_600)
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
#if defined (MR5_500)
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

/*************************************************************************
 * MR761 MR762 MR763
 *************************************************************************/
#if defined (MR761) || defined (MR762) || defined (MR763)

#define MB_Speed				115200
#define MB_Slaveaddr   			1

// конфигурация выключателя ----------------------------------------------
#define MB_StartConfigSW	   	0x28F0			// конфигурация выключателя
#define MB_Size_ConfSW			16				// 16 слов
#define MB_NumbConfigSW			16

#define	MB_rOffsetControlSW		0				// управление выключателем
#define	MB_bControlSW_Button	1<<0
#define	MB_bControlSW_Switch	1<<1
#define	MB_bControlSW_Extern	1<<2
#define	MB_bControlSW_SDTU		1<<3
#define	MB_bControlSW_CmdOFF	1<<4

#define	MB_rOffsetControlSW_ON		1				// вход положение включено
#define	MB_rOffsetControlSW_OFF		2				// вход положение вЫключено
#define	MB_rOffsetControlSW_ERROR	3				// вход неисправность выключателя

// конфигурация АПВ ----------------------------------------------
#define MB_StartConfigAPW	   	0x1264			// конфигурация АПВ
#define MB_NumbConfigAPW		10				// 10 слов
#define MB_offset_ConfAPW		0x00			// конфигурация АПВ
#define MB_offset_InBlok		0x01			// вход блокировки

#define MB_bOffset_APW_Config_Stat		0b11<<0


// конфигурация измерительного транса ------------------------------------------
#define MB_StartConfigTRMeas	   	0x1278			// конфигурация  измерительного транса
#define MB_NumbConfigTRMeas			0x1288 - MB_StartConfigTRMeas + 1	//

#define MB_offset_Kttf			0				// Ittф
#define MB_offset_Kttn			1				// Ittn
#define MB_offset_Ktnf			8				// ТТНП
#define MB_offset_Ktnn			9				// ТТНHП

// конфигурация входных логических сигналов -------------------------------------
#define MB_StartConfigVLSIn			0x1288
#define MB_NumbConfigVLSIn			0x12E8 - MB_StartConfigVLSIn + 1

// конфигурация выходных логических сигналов -------------------------------------
#define MB_StartConfigVLSOut		0x12E8
#define MB_NumbConfigVLSOut			0x1408 - MB_StartConfigVLSOut + 1

// конфигурация ----------------------------------------------
#define MB_StartConfig		   	0x1000			// уставки

// Группы уставок -----------------------------------------------------------------------------------
#define MB_StartUstavkiaddr0	0x1000			// группа уставок 1
#define MB_StartUstavkiaddr1	0x1428			// группа уставок 2
#define MB_StartUstavkiaddr2	0x1850			// группа уставок 3
#define MB_StartUstavkiaddr3	0x1C78			// группа уставок 4
#define MB_StartUstavkiaddr4	0x20A0			// группа уставок 5
#define MB_StartUstavkiaddr5	0x24C8			// группа уставок 6

#define MB_NumbUstavki			MB_StartUstavkiaddr1 - MB_StartUstavkiaddr0 + 1			// размер блока уставок			0x1D5

#define MB_offset_MTZ_I1		0x1004 - MB_StartUstavkiaddr0		// адрес конфигурации ступени МТЗ защиты
#define MB_offset_MTZ_I2		MB_offset_MTZ_I1+10
#define MB_offset_MTZ_I3		MB_offset_MTZ_I1+20
#define MB_offset_MTZ_I4		MB_offset_MTZ_I1+30
#define MB_offset_MTZ_I5		MB_offset_MTZ_I1+40
#define MB_offset_MTZ_I6		MB_offset_MTZ_I1+50

//конфигурациz ступени МТЗ защиты  I> I*>----------------------------------------------
#define MB_offset_MTZ_I_Config	0				// Конфигурация

// биты
#define MB_bOffset_MTZ_I_Config_Stat		0b11<<0						// состояние


#define MB_offset_Ig_I1		0x104A - MB_StartUstavkiaddr0		// адрес конфигурации ступени МТЗ защиты
#define MB_offset_Ig_I2		MB_offset_Ig_I1+10
#define MB_offset_Ig_I3		MB_offset_Ig_I1+20
#define MB_offset_Ig_I4		MB_offset_Ig_I1+30
#define MB_offset_Ig_I5		MB_offset_Ig_I1+40
#define MB_offset_Ig_I6		MB_offset_Ig_I1+50
#define MB_offset_Ig_I7		MB_offset_Ig_I1+60
#define MB_offset_Ig_I8		MB_offset_Ig_I1+70

//конфигурациz ступени Ig защиты
#define MB_offset_Ig_I_Config	0				// Конфигурация
#define _bSideOffset			4				// привязка к стороне
#define _bLogicOffset			14				// логика

// биты
#define MB_bOffset_Ig_I_Config_Stat		0b11<<0						// состояние
#define MB_bOffset_Ig_I_Config_Logic	0b11<<_bLogicOffset			// логика


// конфигурация токовой защиты от обрыва провода  ----------------------------------------------
#define MB_offsetConfigI2I1	   	0x109A - MB_StartUstavkiaddr0			// конфигурация
#define MB_NumbConfigI2I1		10				// 10 слов
#define MB_offset_ConfI2I1		0x00			// конфигурация

#define MB_bOffset_I2I1_Config_Stat		0b11<<0


// ----------------------------------------------------------------------------------------------
#define MB_StartDiscreetaddr   	0x0D00			// адрес и размер для комманд чтения (3,4)
#define MB_NumbDiscreet   		0x17			// 0x22

#define MB_offset_ErrorOFF		0x14		// аварийное отключение
#define MB_bOffsetErrorOFF		1<<4		// аварийное отключение

#define MB_bOffsetSysNote		1<<0xC		// Новая запись журнала системы
#define MB_bOffsetErrorNote		1<<0xD		// Новая запись журнала аварий

// ---------------------------------
#define MB_offset_Jurnals		0x0E
#define MB_bOffsetError			1<<0xF		// Наличиенеисправности по журналу системы



// --Discreet --
#define MB_offsetDiscreet_1_16	0x00
#define MB_offsetDiscreet_17_32	0x01
#define MB_offsetDiscreet_33_40	0x02

// -Relay --
#define MB_offsetRelay_1		0x10
#define MB_offsetRelay_2		0x10
#define MB_offsetRelay_3		0x10
#define MB_offsetRelay_4		0x10
#define MB_offsetRelay_5		0x10
#define MB_offsetRelay_6		0x10
#define MB_offsetRelay_7		0x10
#define MB_offsetRelay_8		0x10
#define MB_offsetRelay_9		0x10
#define MB_offsetRelay_10		0x10
#define MB_offsetRelay_11		0x10
#define MB_offsetRelay_12		0x10
#define MB_offsetRelay_13		0x10
#define MB_offsetRelay_14		0x10
#define MB_offsetRelay_15		0x10
#define MB_offsetRelay_16		0x10
#define MB_offsetRelay_17		0x11
#define MB_offsetRelay_18		0x11
#define MB_offsetRelay_19		0x11
#define MB_offsetRelay_20		0x11
#define MB_offsetRelay_21		0x11
#define MB_offsetRelay_22		0x11
#define MB_offsetRelay_23		0x11
#define MB_offsetRelay_24		0x11
#define MB_offsetRelay_25		0x11
#define MB_offsetRelay_26		0x11
#define MB_offsetRelay_27		0x11
#define MB_offsetRelay_28		0x11
#define MB_offsetRelay_29		0x11
#define MB_offsetRelay_30		0x11
#define MB_offsetRelay_31		0x11
#define MB_offsetRelay_32		0x11
#define MB_offsetRelay_33		0x12
#define MB_offsetRelay_34		0x12


#define MB_bOffset_Relay_1		1<<0
#define MB_bOffset_Relay_2		1<<1
#define MB_bOffset_Relay_3		1<<2
#define MB_bOffset_Relay_4		1<<3
#define MB_bOffset_Relay_5		1<<4
#define MB_bOffset_Relay_6		1<<5
#define MB_bOffset_Relay_7		1<<6
#define MB_bOffset_Relay_8		1<<7
#define MB_bOffset_Relay_9		1<<8
#define MB_bOffset_Relay_10		1<<9
#define MB_bOffset_Relay_11		1<<10
#define MB_bOffset_Relay_12		1<<11
#define MB_bOffset_Relay_13		1<<12
#define MB_bOffset_Relay_14		1<<13
#define MB_bOffset_Relay_15		1<<14
#define MB_bOffset_Relay_16		1<<15
#define MB_bOffset_Relay_17		1<<0
#define MB_bOffset_Relay_18		1<<1
#define MB_bOffset_Relay_19		1<<2
#define MB_bOffset_Relay_20		1<<3
#define MB_bOffset_Relay_21		1<<4
#define MB_bOffset_Relay_22		1<<5
#define MB_bOffset_Relay_23		1<<6
#define MB_bOffset_Relay_24		1<<7
#define MB_bOffset_Relay_25		1<<8
#define MB_bOffset_Relay_26		1<<9
#define MB_bOffset_Relay_27		1<<10
#define MB_bOffset_Relay_28		1<<11
#define MB_bOffset_Relay_29		1<<12
#define MB_bOffset_Relay_30		1<<13
#define MB_bOffset_Relay_31		1<<14
#define MB_bOffset_Relay_32		1<<15
#define MB_bOffset_Relay_33		1<<0
#define MB_bOffset_Relay_34		1<<1

// ---------------------------------
#define MB_offsetLED_1g			0x12
#define MB_offsetLED_2g			0x12
#define MB_offsetLED_3g			0x12
#define MB_offsetLED_4g			0x12
#define MB_offsetLED_5g			0x12
#define MB_offsetLED_6g			0x12
#define MB_offsetLED_7g			0x12
#define MB_offsetLED_8g			0x13
#define MB_offsetLED_9g			0x13
#define MB_offsetLED_10g		0x13
#define MB_offsetLED_11g		0x13
#define MB_offsetLED_12g		0x13

#define MB_offsetLED_1r			0x12
#define MB_offsetLED_2r			0x12
#define MB_offsetLED_3r			0x12
#define MB_offsetLED_4r			0x12
#define MB_offsetLED_5r			0x12
#define MB_offsetLED_6r			0x12
#define MB_offsetLED_7r			0x12
#define MB_offsetLED_8r			0x13
#define MB_offsetLED_9r			0x13
#define MB_offsetLED_10r		0x13
#define MB_offsetLED_11r		0x13
#define MB_offsetLED_12r		0x13

#define MB_bOffset_LED_1g		1<<0x2
#define MB_bOffset_LED_2g		1<<0x4
#define MB_bOffset_LED_3g		1<<0x6
#define MB_bOffset_LED_4g		1<<0x8
#define MB_bOffset_LED_5g		1<<0xA
#define MB_bOffset_LED_6g		1<<0xC
#define MB_bOffset_LED_7g		1<<0xE
#define MB_bOffset_LED_8g		1<<0x0
#define MB_bOffset_LED_9g		1<<0x2
#define MB_bOffset_LED_10g		1<<0x4
#define MB_bOffset_LED_11g		1<<0x6
#define MB_bOffset_LED_12g		1<<0x8

#define MB_bOffset_LED_1r		1<<0x3
#define MB_bOffset_LED_2r		1<<0x5
#define MB_bOffset_LED_3r		1<<0x7
#define MB_bOffset_LED_4r		1<<0x9
#define MB_bOffset_LED_5r		1<<0xB
#define MB_bOffset_LED_6r		1<<0xD
#define MB_bOffset_LED_7r		1<<0xF
#define MB_bOffset_LED_8r		1<<0x1
#define MB_bOffset_LED_9r		1<<0x3
#define MB_bOffset_LED_10r		1<<0x5
#define MB_bOffset_LED_11r		1<<0x7
#define MB_bOffset_LED_12r		1<<0x9

// SSL -------------------------------
#define MB_offsetSSL_1			0x04
#define MB_offsetSSL_2			0x04
#define MB_offsetSSL_3			0x04
#define MB_offsetSSL_4			0x04
#define MB_offsetSSL_5			0x04
#define MB_offsetSSL_6			0x04
#define MB_offsetSSL_7			0x04
#define MB_offsetSSL_8			0x04
#define MB_offsetSSL_9			0x05
#define MB_offsetSSL_10			0x05
#define MB_offsetSSL_11			0x05
#define MB_offsetSSL_12			0x05
#define MB_offsetSSL_13			0x05
#define MB_offsetSSL_14			0x05
#define MB_offsetSSL_15			0x05
#define MB_offsetSSL_16			0x05
#define MB_offsetSSL_17			0x05
#define MB_offsetSSL_18			0x05
#define MB_offsetSSL_19			0x05
#define MB_offsetSSL_20			0x05
#define MB_offsetSSL_21			0x05
#define MB_offsetSSL_22			0x05
#define MB_offsetSSL_23			0x05
#define MB_offsetSSL_24			0x05
#define MB_offsetSSL_25			0x06
#define MB_offsetSSL_26			0x06
#define MB_offsetSSL_27			0x06
#define MB_offsetSSL_28			0x06
#define MB_offsetSSL_29			0x06
#define MB_offsetSSL_30			0x06
#define MB_offsetSSL_31			0x06
#define MB_offsetSSL_32			0x06

#define MB_bOffset_SSL_1		1<<0x8
#define MB_bOffset_SSL_2		1<<0x9
#define MB_bOffset_SSL_3		1<<0xA
#define MB_bOffset_SSL_4		1<<0xB
#define MB_bOffset_SSL_5		1<<0xC
#define MB_bOffset_SSL_6		1<<0xD
#define MB_bOffset_SSL_7		1<<0xE
#define MB_bOffset_SSL_8		1<<0xF
#define MB_bOffset_SSL_9		1<<0x0
#define MB_bOffset_SSL_10		1<<0x1
#define MB_bOffset_SSL_11		1<<0x2
#define MB_bOffset_SSL_12		1<<0x3
#define MB_bOffset_SSL_13		1<<0x4
#define MB_bOffset_SSL_14		1<<0x5
#define MB_bOffset_SSL_15		1<<0x6
#define MB_bOffset_SSL_16		1<<0x7
#define MB_bOffset_SSL_17		1<<0x8
#define MB_bOffset_SSL_18		1<<0x9
#define MB_bOffset_SSL_19		1<<0xA
#define MB_bOffset_SSL_20		1<<0xB
#define MB_bOffset_SSL_21		1<<0xC
#define MB_bOffset_SSL_22		1<<0xD
#define MB_bOffset_SSL_23		1<<0xE
#define MB_bOffset_SSL_24		1<<0xF
#define MB_bOffset_SSL_25		1<<0x0
#define MB_bOffset_SSL_26		1<<0x1
#define MB_bOffset_SSL_27		1<<0x2
#define MB_bOffset_SSL_28		1<<0x3
#define MB_bOffset_SSL_29		1<<0x4
#define MB_bOffset_SSL_30		1<<0x5
#define MB_bOffset_SSL_31		1<<0x6
#define MB_bOffset_SSL_32		1<<0x7

// VLS -------------------------------
#define MB_offsetVLS_1			0x03
#define MB_offsetVLS_2			0x03
#define MB_offsetVLS_3			0x03
#define MB_offsetVLS_4			0x03
#define MB_offsetVLS_5			0x03
#define MB_offsetVLS_6			0x03
#define MB_offsetVLS_7			0x03
#define MB_offsetVLS_8			0x03
#define MB_offsetVLS_9			0x04
#define MB_offsetVLS_10			0x04
#define MB_offsetVLS_11			0x04
#define MB_offsetVLS_12			0x04
#define MB_offsetVLS_13			0x04
#define MB_offsetVLS_14			0x04
#define MB_offsetVLS_15			0x04
#define MB_offsetVLS_16			0x04


#define MB_bOffset_VLS_1		1<<8
#define MB_bOffset_VLS_2		1<<9
#define MB_bOffset_VLS_3		1<<10
#define MB_bOffset_VLS_4		1<<11
#define MB_bOffset_VLS_5		1<<12
#define MB_bOffset_VLS_6		1<<13
#define MB_bOffset_VLS_7		1<<14
#define MB_bOffset_VLS_8		1<<15
#define MB_bOffset_VLS_9		1<<0
#define MB_bOffset_VLS_10		1<<1
#define MB_bOffset_VLS_11		1<<2
#define MB_bOffset_VLS_12		1<<3
#define MB_bOffset_VLS_13		1<<4
#define MB_bOffset_VLS_14		1<<5
#define MB_bOffset_VLS_15		1<<6
#define MB_bOffset_VLS_16		1<<7

// LS -------------------------------
#define MB_offsetLS_1			0x02
#define MB_offsetLS_2			0x02
#define MB_offsetLS_3			0x02
#define MB_offsetLS_4			0x02
#define MB_offsetLS_5			0x02
#define MB_offsetLS_6			0x02
#define MB_offsetLS_7			0x02
#define MB_offsetLS_8			0x02
#define MB_offsetLS_9			0x03
#define MB_offsetLS_10			0x03
#define MB_offsetLS_11			0x03
#define MB_offsetLS_12			0x03
#define MB_offsetLS_13			0x03
#define MB_offsetLS_14			0x03
#define MB_offsetLS_15			0x03
#define MB_offsetLS_16			0x03

#define MB_bOffset_LS_1			1<<0x8
#define MB_bOffset_LS_2			1<<0x9
#define MB_bOffset_LS_3			1<<0xA
#define MB_bOffset_LS_4			1<<0xB
#define MB_bOffset_LS_5			1<<0xC
#define MB_bOffset_LS_6			1<<0xD
#define MB_bOffset_LS_7			1<<0xE
#define MB_bOffset_LS_8			1<<0xF
#define MB_bOffset_LS_9			1<<0
#define MB_bOffset_LS_10		1<<1
#define MB_bOffset_LS_11		1<<2
#define MB_bOffset_LS_12		1<<3
#define MB_bOffset_LS_13		1<<4
#define MB_bOffset_LS_14		1<<5
#define MB_bOffset_LS_15		1<<6
#define MB_bOffset_LS_16		1<<7

// ---------------------------------

//  I> --
#define MB_offset_IO_I_1		0x07
#define MB_offset_IO_I_2		0x07
#define MB_offset_IO_I_3		0x08
#define MB_offset_IO_I_4		0x08
#define MB_offset_IO_I_5		0x08
#define MB_offset_IO_I_6		0x08

#define MB_b_IO_I1		1<<0xC		// И0 I>1
#define MB_b_IO_I2		1<<0xE		// И0 I>2
#define MB_b_IO_I3		1<<0x0		// И0 I>3
#define MB_b_IO_I4		1<<0x2		// И0 I>4
#define MB_b_IO_I5		1<<0x4		// И0 I>5
#define MB_b_IO_I6		1<<0x6		// И0 I>6

#define MB_offset_SRAB_I_1		0x07
#define MB_offset_SRAB_I_2		0x07
#define MB_offset_SRAB_I_3		0x08
#define MB_offset_SRAB_I_4		0x08
#define MB_offset_SRAB_I_5		0x08
#define MB_offset_SRAB_I_6		0x08

#define MB_b_SRAB_I1		1<<0xD		// СРАБ I>1
#define MB_b_SRAB_I2		1<<0xF		// СРАБ I>2
#define MB_b_SRAB_I3		1<<0x1		// СРАБ I>3
#define MB_b_SRAB_I4		1<<0x3		// СРАБ I>4
#define MB_b_SRAB_I5		1<<0x5		// СРАБ I>5
#define MB_b_SRAB_I6		1<<0x7		// СРАБ I>6

// I*> --
#define MB_offset_IO_Ig_1		0x08
#define MB_offset_IO_Ig_2		0x08
#define MB_offset_IO_Ig_3		0x08
#define MB_offset_IO_Ig_4		0x09
#define MB_offset_IO_Ig_5		0x09
#define MB_offset_IO_Ig_6		0x09
#define MB_offset_IO_Ig_7		0x09
#define MB_offset_IO_Ig_8		0x09

#define MB_b_IO_Ig1		1<<0xA		// И0 I*>1
#define MB_b_IO_Ig2		1<<0xC		// И0 I*>2
#define MB_b_IO_Ig3		1<<0xE		// И0 I*>3
#define MB_b_IO_Ig4		1<<0x0		// И0 I*>4
#define MB_b_IO_Ig5		1<<0x2		// И0 I*>5
#define MB_b_IO_Ig6		1<<0x4		// И0 I*>6
#define MB_b_IO_Ig7		1<<0x6		// И0 I*>7
#define MB_b_IO_Ig8		1<<0x8		// И0 I*>8

#define MB_offset_SRAB_Ig_1		0x08
#define MB_offset_SRAB_Ig_2		0x08
#define MB_offset_SRAB_Ig_3		0x08
#define MB_offset_SRAB_Ig_4		0x09
#define MB_offset_SRAB_Ig_5		0x09
#define MB_offset_SRAB_Ig_6		0x09
#define MB_offset_SRAB_Ig_7		0x09
#define MB_offset_SRAB_Ig_8		0x09

#define MB_b_SRAB_Ig1		1<<0xB		// СРАБ I*>1
#define MB_b_SRAB_Ig2		1<<0xD		// СРАБ I*>2
#define MB_b_SRAB_Ig3		1<<0xF		// СРАБ I*>3
#define MB_b_SRAB_Ig4		1<<0x1		// СРАБ I*>4
#define MB_b_SRAB_Ig5		1<<0x3		// СРАБ I*>5
#define MB_b_SRAB_Ig6		1<<0x5		// СРАБ I*>6
#define MB_b_SRAB_Ig7		1<<0x7		// СРАБ I*>7
#define MB_b_SRAB_Ig8		1<<0x9		// СРАБ I*>8

#define MB_offset_IO_I2I1		0x09
#define MB_offset_SRAB_I2I1		0x09
#define MB_b_IO_I2I1			1<<0xA		// СРАБ I*>1
#define MB_b_SRAB_I2I1			1<<0xB		// СРАБ I*>2


// I --
#define MB_offset_dirPTOC_Ia		0x26		// направления мощности, ошибка направления мощности
#define MB_offset_dirPTOC_Ib		0x26
#define MB_offset_dirPTOC_Ic		0x26
#define MB_offset_dirPTOC_In		0x26
#define MB_offset_dirPTOC_I0		0x26
#define MB_offset_dirPTOC_I2		0x26

#define MB_offset_dirErrorPTOC_Ia	0x26		// направления мощности, ошибка направления мощности
#define MB_offset_dirErrorPTOC_Ib	0x26
#define MB_offset_dirErrorPTOC_Ic	0x26
#define MB_offset_dirErrorPTOC_In	0x26
#define MB_offset_dirErrorPTOC_I0	0x26
#define MB_offset_dirErrorPTOC_I2	0x26

// биты направления и достоверности мощности
#define MB_b_direction_In		1<<0xA		// направления
#define MB_b_direction_Ia		1<<0x0
#define MB_b_direction_Ib		1<<0x2
#define MB_b_direction_Ic		1<<0x4
#define MB_b_direction_I0		1<<0x6
#define MB_b_direction_I2		1<<0x8

#define MB_b_dirError_In		1<<0xB		// ошибка направления
#define MB_b_dirError_Ia		1<<0x1
#define MB_b_dirError_Ib		1<<0x3
#define MB_b_dirError_Ic		1<<0x5
#define MB_b_dirError_I0		1<<0x7
#define MB_b_dirError_I2		1<<0x9

// Z ---
#define MB_offset_dirPTOC_Za		0x26	// направления
#define MB_offset_dirPTOC_Zb		0x26
#define MB_offset_dirPTOC_Zc		0x27
#define MB_offset_dirErrorPTOC_Za	0x26	// ошибка направления
#define MB_offset_dirErrorPTOC_Zb	0x26
#define MB_offset_dirErrorPTOC_Zc	0x27

#define MB_offset_dirPTOC_Zab		0x27
#define MB_offset_dirPTOC_Zbc		0x27
#define MB_offset_dirPTOC_Zca		0x27
#define MB_offset_dirErrorPTOC_Zab	0x27
#define MB_offset_dirErrorPTOC_Zbc	0x27
#define MB_offset_dirErrorPTOC_Zca	0x27

// биты направления и достоверности Z
#define MB_b_direction_Za		1<<0xC		// направления
#define MB_b_direction_Zb		1<<0xE
#define MB_b_direction_Zc		1<<0x0
#define MB_b_dirError_Za		1<<0xD		// ошибка направления
#define MB_b_dirError_Zb		1<<0xE
#define MB_b_dirError_Zc		1<<0x1

#define MB_b_direction_Zab		1<<0x2
#define MB_b_direction_Zbc		1<<0x4
#define MB_b_direction_Zca		1<<0x6
#define MB_b_dirError_Zab		1<<0x3
#define MB_b_dirError_Zbc		1<<0x5
#define MB_b_dirError_Zca		1<<0x7


// U ---
#define MB_offset_IO_Uup_1		0x09
#define MB_offset_IO_Uup_2		0x09
#define MB_offset_IO_Uup_3		0x0A
#define MB_offset_IO_Uup_4		0x0A

#define MB_offset_SRAB_Uup_1	0x09
#define MB_offset_SRAB_Uup_2	0x0A
#define MB_offset_SRAB_Uup_3	0x0A
#define MB_offset_SRAB_Uup_4	0x0A

#define MB_offset_IO_Udn_1		0x0A
#define MB_offset_IO_Udn_2		0x0A
#define MB_offset_IO_Udn_3		0x0A
#define MB_offset_IO_Udn_4		0x0A

#define MB_offset_SRAB_Udn_1	0x0A
#define MB_offset_SRAB_Udn_2	0x0A
#define MB_offset_SRAB_Udn_3	0x0A
#define MB_offset_SRAB_Udn_4	0x0A

#define MB_b_IO_Uup1		1<<0xD		// И0 U>1
#define MB_b_IO_Uup2		1<<0xF		// И0 U>2
#define MB_b_IO_Uup3		1<<0x1		// И0 U>3
#define MB_b_IO_Uup4		1<<0x3		// И0 U>4

#define MB_b_SRAB_Uup1		1<<0xE		// СРАБ U>1
#define MB_b_SRAB_Uup2		1<<0x0		// СРАБ U>2
#define MB_b_SRAB_Uup3		1<<0x2		// СРАБ U>3
#define MB_b_SRAB_Uup4		1<<0x4		// СРАБ U>4

#define MB_b_IO_Udn1		1<<0x5		// И0 U<1
#define MB_b_IO_Udn2		1<<0x7		// И0 U<2
#define MB_b_IO_Udn3		1<<0x9		// И0 U<3
#define MB_b_IO_Udn4		1<<0xB		// И0 U<4

#define MB_b_SRAB_Udn1		1<<0x6		// СРАБ U<1
#define MB_b_SRAB_Udn2		1<<0x8		// СРАБ U<2
#define MB_b_SRAB_Udn3		1<<0xA		// СРАБ U<3
#define MB_b_SRAB_Udn4		1<<0xC		// СРАБ U<4

// F --
#define MB_offset_IO_Fup_1		0x0A
#define MB_offset_IO_Fup_2		0x0A
#define MB_offset_IO_Fup_3		0x0B
#define MB_offset_IO_Fup_4		0x0B

#define MB_offset_SRAB_Fup_1	0x0A
#define MB_offset_SRAB_Fup_2	0x0B
#define MB_offset_SRAB_Fup_3	0x0B
#define MB_offset_SRAB_Fup_4	0x0B

#define MB_offset_IO_Fdn_1		0x0B
#define MB_offset_IO_Fdn_2		0x0B
#define MB_offset_IO_Fdn_3		0x0B
#define MB_offset_IO_Fdn_4		0x0B
#define MB_offset_SRAB_Fdn_1	0x0B
#define MB_offset_SRAB_Fdn_2	0x0B
#define MB_offset_SRAB_Fdn_3	0x0B
#define MB_offset_SRAB_Fdn_4	0x0B

#define MB_b_IO_Fup1		1<<0xD		// И0 F>1
#define MB_b_IO_Fup2		1<<0xF		// И0 F>2
#define MB_b_IO_Fup3		1<<0x1		// И0 F>3
#define MB_b_IO_Fup4		1<<0x3		// И0 F>4

#define MB_b_SRAB_Fup1		1<<0xE		// СРАБ F>1
#define MB_b_SRAB_Fup2		1<<0x0		// СРАБ F>2
#define MB_b_SRAB_Fup3		1<<0x2		// СРАБ F>3
#define MB_b_SRAB_Fup4		1<<0x4		// СРАБ F>4

#define MB_b_IO_Fdn1		1<<0x5		// И0 F<1
#define MB_b_IO_Fdn2		1<<0x7		// И0 F<2
#define MB_b_IO_Fdn3		1<<0x9		// И0 F<3
#define MB_b_IO_Fdn4		1<<0xB		// И0 F<4

#define MB_b_SRAB_Fdn1		1<<0x6		// СРАБ F<1
#define MB_b_SRAB_Fdn2		1<<0x8		// СРАБ F<2
#define MB_b_SRAB_Fdn3		1<<0xA		// СРАБ F<3
#define MB_b_SRAB_Fdn4		1<<0xC		// СРАБ F<4

// внешняя
#define MB_offset_SRAB_ext_1		0x0F
#define MB_offset_SRAB_ext_2		0x0F
#define MB_offset_SRAB_ext_3		0x0F
#define MB_offset_SRAB_ext_4		0x0F
#define MB_offset_SRAB_ext_5		0x0F
#define MB_offset_SRAB_ext_6		0x0F
#define MB_offset_SRAB_ext_7		0x0F
#define MB_offset_SRAB_ext_8		0x0F
#define MB_offset_SRAB_ext_9		0x0F
#define MB_offset_SRAB_ext_10		0x0F
#define MB_offset_SRAB_ext_11		0x0F
#define MB_offset_SRAB_ext_12		0x0F
#define MB_offset_SRAB_ext_13		0x0F
#define MB_offset_SRAB_ext_14		0x0F
#define MB_offset_SRAB_ext_15		0x0F
#define MB_offset_SRAB_ext_16		0x10

#define MB_b_SRAB_ext_1			1<<1
#define MB_b_SRAB_ext_2			1<<2
#define MB_b_SRAB_ext_3			1<<3
#define MB_b_SRAB_ext_4			1<<4
#define MB_b_SRAB_ext_5			1<<5
#define MB_b_SRAB_ext_6			1<<6
#define MB_b_SRAB_ext_7			1<<7
#define MB_b_SRAB_ext_8			1<<8
#define MB_b_SRAB_ext_9			1<<9
#define MB_b_SRAB_ext_10		1<<10
#define MB_b_SRAB_ext_11		1<<11
#define MB_b_SRAB_ext_12		1<<12
#define MB_b_SRAB_ext_13		1<<13
#define MB_b_SRAB_ext_14		1<<14
#define MB_b_SRAB_ext_15		1<<15
#define MB_b_SRAB_ext_16		1<<0

// выключатель
#define MB_offset_SW_status			0x13
#define MB_b_SW_ON					1<<7
#define MB_b_SW_OFF					1<<6

// АПВ
#define MB_offset_SW_ON_APW			0x0C
#define MB_b_SW_ON_APW				1<<0x0E

//УРОВ
//#define MB_offset_UROV				0x0B
//#define MB_b_Rab_UROV				1<<0x0E

// Z ----
#define MB_IO_offsetZ_1			0x06
#define MB_IO_offsetZ_2			0x07

#define MB_Z1_IO				1<<8
#define MB_Z1					1<<9
#define MB_Z2_IO				1<<10
#define MB_Z2					1<<11
#define MB_Z3_IO				1<<12
#define MB_Z3					1<<13
#define MB_Z4_IO				1<<14
#define MB_Z4					1<<15
#define MB_Z5_IO				1<<0
#define MB_Z5					1<<1
#define MB_Z6_IO				1<<2
#define MB_Z6					1<<3
#define MB_Z7_IO				1<<4
#define MB_Z7					1<<5
#define MB_Z8_IO				1<<6
#define MB_Z8					1<<7
#define MB_Z9_IO				1<<8
#define MB_Z9					1<<9
#define MB_Z10_IO				1<<10
#define MB_Z10					1<<11


// ---------------------------------
#define MB_offsetHardFaults		0x16			// неисправность устройства аппаратная

#define MB_offset_errorM1		0x16
#define MB_offset_errorM2		0x16
#define MB_offset_errorM3		0x16
#define MB_offset_errorM4		0x16
#define MB_offset_errorM5		0x16

#define MB_bOffsetModule1		1<<7			// Наличие неисправности модуля 1
#define MB_bOffsetModule2		1<<8			// Наличие неисправности модуля 2
#define MB_bOffsetModule3		1<<9			// Наличие неисправности модуля 3
#define MB_bOffsetModule4		1<<10			// Наличие неисправности модуля 4 аналог
#define MB_bOffsetModule5		1<<11			// Наличие неисправности модуля 5 аналог
#define MB_bOffsetUstavki		1<<12			// Наличие неисправности уставок


// ----------------------------------------------------------------------------------------------
#define MB_StartAnalogINaddr   	0x0E00		// база данных аналогов
#define MB_NumbAnalog   		96			// 96 слов


#define MB_offset_Ia			0
#define MB_offset_Ib			1
#define MB_offset_Ic			2

#define MB_offset_In			6


#define MB_offset_Ua			11
#define MB_offset_Ub			12
#define MB_offset_Uc			13
#define MB_offset_Un			14
#define MB_offset_Un1			15

#define MB_offset_Uab			16
#define MB_offset_Ubc			17
#define MB_offset_Ucd			18

#define MB_offset_Hz			24		// F
#define MB_offset_TotW			26		// P 2слова
#define MB_offset_TotVAr		28		// Q 2слова
#define MB_offset_TotPF			30		// cos

// ----------------------------------------------------------------------------------------------
#define MB_StartDateNaddr   	0x0200
#define MB_NumbDate		   		7

// ----------------------------------------------------------------------------------------------
#define MB_Startaddr_SG			0x0400
#define MB_NumbSG		   		1

#define MB_selectGroupe0		0x0000
#define MB_selectGroupe1		0x0001
#define MB_selectGroupe2		0x0002
#define MB_selectGroupe3		0x0003
#define MB_selectGroupe4		0x0004
#define MB_selectGroupe5		0x0005

// ----------------------------------------------------------------------------------------------
#define MB_StartRevNaddr   		0x0500		// версия 17 слов
#define MB_NumbWordRev	   		17

// - запись в прибор -----------------------------
#define MB_addr_SysNote_OFF		0x0D01
#define MB_addr_ErrorNote_OFF	0x0D02

#define MB_addr_Error_OFF		0x0D04
#define MB_addr_LEDS_OFF		0x0D05

#define MB_addr_SwOFF  			0x0D08		//адрес выключеня off
#define MB_addr_SwON   			0x0D09		//адрес включеня on

#define MB_Sw   				0xFF00		//on
#define MB_CTRL_OFF				0xFF00

// Параметры автоматики -------------------------------------------------------------------------
#define MB_StartAutomat			0x28EE
#define MB_NumbAutomat			0x2988 - MB_StartAutomat + 1

// Параметры системы (они же IP адрес) -----------------------------------------------------------
#define MB_StartSystemCfg		0x2988
#define MB_NumbSystemCfg		10
#define MB_offset_IP			4		// F


#define MB_PerForSynchClock		1				// период пересинхронизации часов
#define MB_PerForReadMODBUS		100				// период опроса модбас в мс	150

#endif

/*************************************************************************
 * MR901 MR902
 *************************************************************************/
#if defined (MR901) || defined (MR902)
#define MB_Speed				115200
#define MB_Slaveaddr   			1

// конфигурация выключателя ----------------------------------------------
#define MB_StartConfigSW	   	0x1000			// конфигурация выключателя
#define MB_offset_ConfigSW 		0x00
#define MB_Size_ConfSW			15				// 14 слов
#define MB_NumbConfigSW			15

#define	MB_rOffsetControlSW		0				// управление выключателем
#define	MB_bControlSW_Button	1<<0
#define	MB_bControlSW_Switch	1<<1
#define	MB_bControlSW_Extern	1<<2
#define	MB_bControlSW_SDTU		1<<3
#define	MB_bControlSW_CmdOFF	1<<4

#define	MB_rOffsetControlSW_ON		1				// вход положение включено
#define	MB_rOffsetControlSW_OFF		2				// вход положение вЫключено
#define	MB_rOffsetControlSW_ERROR	3				// вход неисправность выключателя

// конфигурация АПВ ----------------------------------------------
#define MB_StartConfigAPW	   	0x100E			// конфигурация АПВ
#define MB_NumbConfigAPW		7				// 6 слов
#define MB_offset_ConfAPW		0x00			// конфигурация АПВ
#define MB_offset_InBlok		0x01			// вход блокировки

#define MB_bOffset_APW_Config_Stat		0b11<<0

// конфигурация АВР + ЛЗШ ------------------------------------------
#define MB_StartConfigAWR	   	0x1014			// конфигурация АВР
#define MB_NumbConfigAWR		13				// 10 слов + 2 слова ЛЗШ
#define MB_offset_ConfAWR		0x00			// конфигурация АВР
#define MB_offset_InBlok		0x01			// вход блокировки

#define MB_offset_ConfLZSHAWR		0x101E - MB_StartConfigAWR 			// конфигурация ЛЗШ

#define MB_bOffset_AWR_Config_Stat		0b1111
#define MB_bOffset_LZSH_Config_Stat		0b11

// конфигурация силового транса ------------------------------------------
#define MB_StartConfigTRPWR		   	0x1047			// конфигурация  силового транса
#define MB_NumbConfigTRPWR			22				// 21 слово
#define MB_offset_ConfigS1			0x1048 - MB_StartConfigTRPWR
#define MB_offset_ConfigS2			0x104E - MB_StartConfigTRPWR
#define MB_offset_ConfigS3			0x1054 - MB_StartConfigTRPWR

#define MB_offset_U_Obmotki			0
#define MB_offset_P_Obmotki			1
#define MB_offset_Type_Obmotki		2

// конфигурация измерительного транса ------------------------------------------
#define MB_StartConfigTRMeas	   	0x105C			// конфигурация  измерительного транса
#define MB_NumbConfigTRMeas			0x1074-0x105C+1	//
#define MB_offset_KTHL				0x106E - MB_StartConfigTRMeas
#define MB_offset_KTHX				0x106F - MB_StartConfigTRMeas

#define MB_offset_ConfigTT_L1		0x105C - MB_StartConfigTRMeas
#define MB_offset_ConfigTT_X1		0x105D - MB_StartConfigTRMeas
#define MB_offset_ConfigTT_L2		0x1062 - MB_StartConfigTRMeas
#define MB_offset_ConfigTT_X2		0x1063 - MB_StartConfigTRMeas
#define MB_offset_ConfigTT_L3		0x1068 - MB_StartConfigTRMeas
#define MB_offset_ConfigTT_X3		0x1069 - MB_StartConfigTRMeas


// конфигурация входных логических сигналов -------------------------------------
#define MB_StartConfigVLSIn			0x1074
#define MB_NumbConfigVLSIn			0x10B4 - MB_StartConfigVLSIn + 1

// конфигурация выходных логических сигналов -------------------------------------
#define MB_StartConfigVLSOut		0x10B4
#define MB_NumbConfigVLSOut			0x11B4 - MB_StartConfigVLSOut + 1

// конфигурация ----------------------------------------------
#define MB_StartConfig		   	0x1000			// уставки
#define MB_NumbConfigall   		0x4E			// 7C больше нельзя
#define MB_IncNumbOfConfig		0x428

#define MB_Config0		   		0x1000			// группа уставок 1
#define MB_Config1		   		0x1428			// группа уставок 2
#define MB_Config2		   		0x1850			// группа уставок 3
#define MB_Config3		   		0x1C78			// группа уставок 4
#define MB_Config4		   		0x20A0			// группа уставок 5
#define MB_Config5		   		0x24C8			// группа уставок 6

// Группы уставок -----------------------------------------------------------------------------------
#define MB_StartUstavkiaddr0	0x11B4			// Основная группа уставок
#define MB_StartUstavkiaddr1	0x1388			// Резервная группа уставок
#define MB_NumbUstavki			MB_StartUstavkiaddr1 - MB_StartUstavkiaddr0 + 1			// размер блока уставок			0x1D5


#define MB_offset_DIFFZ			0x11C0 - MB_StartUstavkiaddr0		// адрес конфигурации дифф защиты
#define MB_offset_DIFFOts		0x11CC - MB_StartUstavkiaddr0		// адрес конфигурации дифф отсечки
#define MB_offset_DIFF0_1		0x11D2 - MB_StartUstavkiaddr0		// адрес конфигурации защиты нулевой последовательности
#define MB_offset_DIFF0_2		0x11DC - MB_StartUstavkiaddr0		// адрес конфигурации защиты нулевой последовательности
#define MB_offset_DIFF0_3		0x11E6 - MB_StartUstavkiaddr0		// адрес конфигурации защиты нулевой последовательности

//конфигурациz дифф защиты
#define MB_offset_DIFFZ_Config_Stat		0				// Конфигурация дифф защиты 1 слово состояние
#define MB_offset_DIFFOts_Config		0
#define MB_offset_DIFF0_Config			0

// биты
#define MB_bOffset_DIFFZ_Config_Stat		0b11						// состояние
#define MB_bOffset_DIFFOts_Config_Stat		0b11						// состояние
#define MB_bOffset_DIFFOtsMgn_Config_Stat	0b1000
#define MB_bOffset_DIFF0_Config_Stat		0b11<<0						// состояние


#define MB_offset_MTZ_I1		0x11F0 - MB_StartUstavkiaddr0		// адрес конфигурации ступени МТЗ защиты
#define MB_offset_MTZ_I2		MB_offset_MTZ_I1+10
#define MB_offset_MTZ_I3		MB_offset_MTZ_I1+20
#define MB_offset_MTZ_I4		MB_offset_MTZ_I1+30
#define MB_offset_MTZ_I5		MB_offset_MTZ_I1+40
#define MB_offset_MTZ_I6		MB_offset_MTZ_I1+50
#define MB_offset_MTZ_I7		MB_offset_MTZ_I1+60
#define MB_offset_MTZ_I8		MB_offset_MTZ_I1+70

//конфигурациz ступени МТЗ защиты
#define MB_offset_MTZ_I_Config	0				// Конфигурация
#define _bSideOffset			4				// привязка к стороне
// биты
#define MB_bOffset_MTZ_I_Config_Stat		0b11<<0						// состояние
#define MB_bOffset_MTZ_I_Config_Side		0b11<<_bSideOffset			// привязка к стороне

#define MB_offset_Ig_I1		0x1240 - MB_StartUstavkiaddr0		// адрес конфигурации ступени МТЗ защиты
#define MB_offset_Ig_I2		MB_offset_Ig_I1+10
#define MB_offset_Ig_I3		MB_offset_Ig_I1+20
#define MB_offset_Ig_I4		MB_offset_Ig_I1+30
#define MB_offset_Ig_I5		MB_offset_Ig_I1+40
#define MB_offset_Ig_I6		MB_offset_Ig_I1+50

//конфигурациz ступени Ig защиты
#define MB_offset_Ig_I_Config	0				// Конфигурация
#define _bSideOffset			4				// привязка к стороне
#define _bLogicOffset			14				// логика

// биты
#define MB_bOffset_Ig_I_Config_Stat		0b11<<0						// состояние
#define MB_bOffset_Ig_I_Config_Side		0b11<<_bSideOffset			// привязка к стороне
#define MB_bOffset_Ig_I_Config_Logic	0b11<<_bLogicOffset			// логика

// U
#define MB_offset_Uup_U1		0x127C - MB_StartUstavkiaddr0		// адрес конфигурации ступени МТЗ защиты
#define MB_offset_Uup_U2		MB_offset_Uup_U1+8
#define MB_offset_Uup_U3		MB_offset_Uup_U1+16
#define MB_offset_Uup_U4		MB_offset_Uup_U1+24

#define MB_offset_Udn_U1		0x129C - MB_StartUstavkiaddr0		// адрес конфигурации ступени МТЗ защиты
#define MB_offset_Udn_U2		MB_offset_Udn_U1+8
#define MB_offset_Udn_U3		MB_offset_Udn_U1+16
#define MB_offset_Udn_U4		MB_offset_Udn_U1+24

//конфигурация защит по напряжению
#define MB_offset_Uup_U_Config		0				// Конфигурация
#define MB_offset_Udn_U_Config		0
// биты
#define MB_bOffset_Uup_U_Config_Stat		0b11<<0						// состояние
#define MB_bOffset_Udn_U_Config_Stat		0b11<<0

// F
#define MB_offset_Fup_1		0x12BC - MB_StartUstavkiaddr0		// адрес конфигурации ступени МТЗ защиты
#define MB_offset_Fup_2		MB_offset_Fup_1+8
#define MB_offset_Fup_3		MB_offset_Fup_1+16
#define MB_offset_Fup_4		MB_offset_Fup_1+24

#define MB_offset_Fdn_1		0x12DC - MB_StartUstavkiaddr0		// адрес конфигурации ступени МТЗ защиты
#define MB_offset_Fdn_2		MB_offset_Fdn_1+8
#define MB_offset_Fdn_3		MB_offset_Fdn_1+16
#define MB_offset_Fdn_4		MB_offset_Fdn_1+24

//конфигурация защит по напряжению
#define MB_offset_Fup_Config		0				// Конфигурация
#define MB_offset_Fdn_Config		0
// биты
#define MB_bOffset_Fup_Config_Stat		0b11<<0						// состояние
#define MB_bOffset_Fdn_Config_Stat		0b11<<0

// внешние
#define MB_offset_Ext_1		0x1308 - MB_StartUstavkiaddr0		// адрес конфигурации ступени МТЗ защиты
#define MB_offset_Ext_2		MB_offset_Ext_1+8
#define MB_offset_Ext_3		MB_offset_Ext_2+8
#define MB_offset_Ext_4		MB_offset_Ext_3+8
#define MB_offset_Ext_5		MB_offset_Ext_4+8
#define MB_offset_Ext_6		MB_offset_Ext_5+8
#define MB_offset_Ext_7		MB_offset_Ext_6+8
#define MB_offset_Ext_8		MB_offset_Ext_7+8
#define MB_offset_Ext_9		MB_offset_Ext_8+8
#define MB_offset_Ext_10	MB_offset_Ext_9+8
#define MB_offset_Ext_11	MB_offset_Ext_10+8
#define MB_offset_Ext_12	MB_offset_Ext_11+8
#define MB_offset_Ext_13	MB_offset_Ext_12+8
#define MB_offset_Ext_14	MB_offset_Ext_13+8
#define MB_offset_Ext_15	MB_offset_Ext_14+8
#define MB_offset_Ext_16	MB_offset_Ext_15+8

//конфигурация
#define MB_offset_Ext_Config		0			// Конфигурация
// биты
#define MB_bOffset_Ext_Config_Stat		0b11<<0						// состояние

// ----------------------------------------------------------------------------------------------
#define MB_StartDiscreetaddr   	0x0D00			// адрес и размер для комманд чтения (3,4)
#define MB_NumbDiscreet   		0x23			// 0x22

// ---------------------------------
#define MB_offset_SG			0x0B		// инфо по группе уставок
#define MB_bOffsetSG0			1<<4		// Группа уставок основная
#define MB_bOffsetSG1			1<<5		// Группа уставок резервная

#define MB_offset_ErrorOFF		0x0B		// аварийное отключение
#define MB_bOffsetErrorOFF		1<<7		// аварийное отключение

// ---------------------------------
#define MB_offset_Jurnals		0x0E
#define MB_bOffsetSysNote		1<<3		// Новая запись журнала системы
#define MB_bOffsetErrorNote		1<<4		// Новая запись журнала аварий

#define MB_bOffsetError			1<<6		// Наличиенеисправности по журналу системы

// ---------------------------------
#define MB_offsetHardFaults		0x10			// неисправность устройства аппаратная
#define MB_bOffsetModule1		1<<7			// Наличие неисправности модуля 1
#define MB_bOffsetModule2		1<<8			// Наличие неисправности модуля 2
#define MB_bOffsetModule3		1<<9			// Наличие неисправности модуля 3
#define MB_bOffsetModule4		1<<10			// Наличие неисправности модуля 4 аналог только ТОК
#define MB_bOffsetModule5		1<<11			// Наличие неисправности модуля 5 аналог ТОК и НАПРЯЖЕНИЕ
#define MB_bOffsetUstavki		1<<12			// Наличие неисправности уставок

// ---------------------------------
#define MB_offsetHardFaults1	0x11			// неисправность

#define MB_bOffsetErrorSWAll	0b111100
#define MB_bOffsetErrorSWExt1	1<<2
#define MB_bOffsetErrorBKExt1	1<<3
#define MB_bOffsetErrorSWctrl1	1<<4
#define MB_bOffsetErrorUROV1	1<<5

#define MB_bOffsetErrorCtrl1	1<<6
#define MB_bOffsetErrorCtrl2	1<<7

// ---------------------------------
#define MB_offsetDiscreet_1_16	0x00
#define MB_offsetDiscreet_17_24	0x01



// ---------------------------------
#define MB_offsetRelay_1		0x0C
#define MB_offsetRelay_2		0x0C
#define MB_offsetRelay_3		0x0C
#define MB_offsetRelay_4		0x0C
#define MB_offsetRelay_5		0x0C
#define MB_offsetRelay_6		0x0C
#define MB_offsetRelay_7		0x0C
#define MB_offsetRelay_8		0x0C
#define MB_offsetRelay_9		0x0C
#define MB_offsetRelay_10		0x0C
#define MB_offsetRelay_11		0x0C
#define MB_offsetRelay_12		0x0C
#define MB_offsetRelay_13		0x0C
#define MB_offsetRelay_14		0x0D
#define MB_offsetRelay_15		0x0D
#define MB_offsetRelay_16		0x0D
#define MB_offsetRelay_17		0x0D
#define MB_offsetRelay_18		0x0D

#define MB_bOffset_Relay_1		1<<3
#define MB_bOffset_Relay_2		1<<4
#define MB_bOffset_Relay_3		1<<5
#define MB_bOffset_Relay_4		1<<6
#define MB_bOffset_Relay_5		1<<7
#define MB_bOffset_Relay_6		1<<8
#define MB_bOffset_Relay_7		1<<9
#define MB_bOffset_Relay_8		1<<10
#define MB_bOffset_Relay_9		1<<11
#define MB_bOffset_Relay_10		1<<12
#define MB_bOffset_Relay_11		1<<13
#define MB_bOffset_Relay_12		1<<14
#define MB_bOffset_Relay_13		1<<15
#define MB_bOffset_Relay_14		1<<0
#define MB_bOffset_Relay_15		1<<1
#define MB_bOffset_Relay_16		1<<2
#define MB_bOffset_Relay_17		1<<3
#define MB_bOffset_Relay_18		1<<4

// ---------------------------------
#define MB_offsetLED_1			0x0D
#define MB_offsetLED_2			0x0D
#define MB_offsetLED_3			0x0D
#define MB_offsetLED_4			0x0D
#define MB_offsetLED_5			0x0D
#define MB_offsetLED_6			0x0D
#define MB_offsetLED_7			0x0D
#define MB_offsetLED_8			0x0D
#define MB_offsetLED_9			0x0D
#define MB_offsetLED_10			0x0D
#define MB_offsetLED_11			0x0D
#define MB_offsetLED_12			0x0E
#define MB_offsetLED_13			0x0E
#define MB_offsetLED_14			0x0E
#define MB_offsetLED_15			0x0E
#define MB_offsetLED_16			0x0E


#define MB_bOffset_LED_1		1<<5
#define MB_bOffset_LED_2		1<<6
#define MB_bOffset_LED_3		1<<7
#define MB_bOffset_LED_4		1<<8
#define MB_bOffset_LED_5		1<<9
#define MB_bOffset_LED_6		1<<10
#define MB_bOffset_LED_7		1<<11
#define MB_bOffset_LED_8		1<<12
#define MB_bOffset_LED_9		1<<13
#define MB_bOffset_LED_10		1<<14
#define MB_bOffset_LED_11		1<<15
#define MB_bOffset_LED_12		1<<0
#define MB_bOffset_LED_13		1<<1
#define MB_bOffset_LED_14		1<<2
#define MB_bOffset_LED_15		1<<8
#define MB_bOffset_LED_16		1<<9

// SSL -------------------------------
#define MB_offsetSSL_1			0x09
#define MB_offsetSSL_2			0x09
#define MB_offsetSSL_3			0x09
#define MB_offsetSSL_4			0x09
#define MB_offsetSSL_5			0x09
#define MB_offsetSSL_6			0x09
#define MB_offsetSSL_7			0x09
#define MB_offsetSSL_8			0x09
#define MB_offsetSSL_9			0x09
#define MB_offsetSSL_10			0x09
#define MB_offsetSSL_11			0x09
#define MB_offsetSSL_12			0x09
#define MB_offsetSSL_13			0x09
#define MB_offsetSSL_14			0x0A
#define MB_offsetSSL_15			0x0A
#define MB_offsetSSL_16			0x0A
#define MB_offsetSSL_17			0x0A
#define MB_offsetSSL_18			0x0A
#define MB_offsetSSL_19			0x0A
#define MB_offsetSSL_20			0x0A
#define MB_offsetSSL_21			0x0A
#define MB_offsetSSL_22			0x0A
#define MB_offsetSSL_23			0x0A
#define MB_offsetSSL_24			0x0A
#define MB_offsetSSL_25			0x0A
#define MB_offsetSSL_26			0x0A
#define MB_offsetSSL_27			0x0A
#define MB_offsetSSL_28			0x0A
#define MB_offsetSSL_29			0x0A
#define MB_offsetSSL_30			0x0B
#define MB_offsetSSL_31			0x0B
#define MB_offsetSSL_32			0x0B

#define MB_bOffset_SSL_1		1<<3
#define MB_bOffset_SSL_2		1<<4
#define MB_bOffset_SSL_3		1<<5
#define MB_bOffset_SSL_4		1<<6
#define MB_bOffset_SSL_5		1<<7
#define MB_bOffset_SSL_6		1<<8
#define MB_bOffset_SSL_7		1<<9
#define MB_bOffset_SSL_8		1<<10
#define MB_bOffset_SSL_9		1<<11
#define MB_bOffset_SSL_10		1<<12
#define MB_bOffset_SSL_11		1<<13
#define MB_bOffset_SSL_12		1<<14
#define MB_bOffset_SSL_13		1<<15
#define MB_bOffset_SSL_14		1<<0
#define MB_bOffset_SSL_15		1<<1
#define MB_bOffset_SSL_16		1<<2
#define MB_bOffset_SSL_17		1<<3
#define MB_bOffset_SSL_18		1<<4
#define MB_bOffset_SSL_19		1<<5
#define MB_bOffset_SSL_20		1<<6
#define MB_bOffset_SSL_21		1<<7
#define MB_bOffset_SSL_22		1<<8
#define MB_bOffset_SSL_23		1<<9
#define MB_bOffset_SSL_24		1<<10
#define MB_bOffset_SSL_25		1<<11
#define MB_bOffset_SSL_26		1<<12
#define MB_bOffset_SSL_27		1<<13
#define MB_bOffset_SSL_28		1<<14
#define MB_bOffset_SSL_29		1<<15
#define MB_bOffset_SSL_30		1<<0
#define MB_bOffset_SSL_31		1<<1
#define MB_bOffset_SSL_32		1<<2

// VLS -------------------------------
#define MB_offsetVLS_1			0x02
#define MB_offsetVLS_2			0x02
#define MB_offsetVLS_3			0x02
#define MB_offsetVLS_4			0x02
#define MB_offsetVLS_5			0x02
#define MB_offsetVLS_6			0x02
#define MB_offsetVLS_7			0x02
#define MB_offsetVLS_8			0x02
#define MB_offsetVLS_9			0x03
#define MB_offsetVLS_10			0x03
#define MB_offsetVLS_11			0x03
#define MB_offsetVLS_12			0x03
#define MB_offsetVLS_13			0x03
#define MB_offsetVLS_14			0x03
#define MB_offsetVLS_15			0x03
#define MB_offsetVLS_16			0x03


#define MB_bOffset_VLS_1		1<<8
#define MB_bOffset_VLS_2		1<<9
#define MB_bOffset_VLS_3		1<<10
#define MB_bOffset_VLS_4		1<<11
#define MB_bOffset_VLS_5		1<<12
#define MB_bOffset_VLS_6		1<<13
#define MB_bOffset_VLS_7		1<<14
#define MB_bOffset_VLS_8		1<<15
#define MB_bOffset_VLS_9		1<<0
#define MB_bOffset_VLS_10		1<<1
#define MB_bOffset_VLS_11		1<<2
#define MB_bOffset_VLS_12		1<<3
#define MB_bOffset_VLS_13		1<<4
#define MB_bOffset_VLS_14		1<<5
#define MB_bOffset_VLS_15		1<<6
#define MB_bOffset_VLS_16		1<<7

// LS -------------------------------
#define MB_offsetLS_1			0x01
#define MB_offsetLS_2			0x01
#define MB_offsetLS_3			0x01
#define MB_offsetLS_4			0x01
#define MB_offsetLS_5			0x01
#define MB_offsetLS_6			0x01
#define MB_offsetLS_7			0x01
#define MB_offsetLS_8			0x01
#define MB_offsetLS_9			0x02
#define MB_offsetLS_10			0x02
#define MB_offsetLS_11			0x02
#define MB_offsetLS_12			0x02
#define MB_offsetLS_13			0x02
#define MB_offsetLS_14			0x02
#define MB_offsetLS_15			0x02
#define MB_offsetLS_16			0x02


#define MB_bOffset_LS_1			1<<8
#define MB_bOffset_LS_2			1<<9
#define MB_bOffset_LS_3			1<<10
#define MB_bOffset_LS_4			1<<11
#define MB_bOffset_LS_5			1<<12
#define MB_bOffset_LS_6			1<<13
#define MB_bOffset_LS_7			1<<14
#define MB_bOffset_LS_8			1<<15
#define MB_bOffset_LS_9			1<<0
#define MB_bOffset_LS_10		1<<1
#define MB_bOffset_LS_11		1<<2
#define MB_bOffset_LS_12		1<<3
#define MB_bOffset_LS_13		1<<4
#define MB_bOffset_LS_14		1<<5
#define MB_bOffset_LS_15		1<<6
#define MB_bOffset_LS_16		1<<7

// ---------------------------------

#define MB_offsetDiscreet13		0x13
#define MB_offsetDiscreet14		0x14

#define MB_offsetSW_OFF			1<<1
#define MB_offsetSW_ON			1<<2

#define MB_rOffsetDiscreet16	0x16
#define MB_bOffsetErrorSW		1<<4

#define MB_rOffsetDiscreet17	0x17
#define MB_bOffsetExtErrorSW	1<<2
#define MB_bOffsetErrorSWCtrl	1<<3
#define MB_bOffsetErrorSWCO		1<<4
#define MB_bOffsetErrorSWFail	1<<5
#define MB_bOffsetErrorSWLon	1<<6
#define MB_bOffsetErrorSWLoff	1<<7


#define MB_OffsetLogic			0x00

// ---------------------------------
#define MB_offset_IO_I_1		0x04
#define MB_offset_IO_I_2		0x04
#define MB_offset_IO_I_3		0x04
#define MB_offset_IO_I_4		0x04
#define MB_offset_IO_I_5		0x04
#define MB_offset_IO_I_6		0x04
#define MB_offset_IO_I_7		0x04
#define MB_offset_IO_I_8		0x05
#define MB_b_IO_I1		1<<3		// И0 I>1
#define MB_b_IO_I2		1<<5		// И0 I>2
#define MB_b_IO_I3		1<<7		// И0 I>3
#define MB_b_IO_I4		1<<9		// И0 I>4
#define MB_b_IO_I5		1<<11		// И0 I>5
#define MB_b_IO_I6		1<<13		// И0 I>6
#define MB_b_IO_I7		1<<15		// И0 I>7
#define MB_b_IO_I8		1<<1		// И0 I>8

#define MB_offset_SRAB_I_1		0x04
#define MB_offset_SRAB_I_2		0x04
#define MB_offset_SRAB_I_3		0x04
#define MB_offset_SRAB_I_4		0x04
#define MB_offset_SRAB_I_5		0x04
#define MB_offset_SRAB_I_6		0x04
#define MB_offset_SRAB_I_7		0x05
#define MB_offset_SRAB_I_8		0x05
#define MB_b_SRAB_I1		1<<4		// СРАБ I>1
#define MB_b_SRAB_I2		1<<6		// СРАБ I>2
#define MB_b_SRAB_I3		1<<8		// СРАБ I>3
#define MB_b_SRAB_I4		1<<10		// СРАБ I>4
#define MB_b_SRAB_I5		1<<12		// СРАБ I>5
#define MB_b_SRAB_I6		1<<14		// СРАБ I>6
#define MB_b_SRAB_I7		1<<0		// СРАБ I>7
#define MB_b_SRAB_I8		1<<2		// СРАБ I>8

#define MB_offset_IO_Ig_1		0x05
#define MB_offset_IO_Ig_2		0x05
#define MB_offset_IO_Ig_3		0x05
#define MB_offset_IO_Ig_4		0x05
#define MB_offset_IO_Ig_5		0x05
#define MB_offset_IO_Ig_6		0x05
#define MB_b_IO_Ig1		1<<3		// И0 I*>1
#define MB_b_IO_Ig2		1<<5		// И0 I*>2
#define MB_b_IO_Ig3		1<<7		// И0 I*>3
#define MB_b_IO_Ig4		1<<9		// И0 I*>4
#define MB_b_IO_Ig5		1<<11		// И0 I*>5
#define MB_b_IO_Ig6		1<<13		// И0 I*>6
#define MB_offset_SRAB_Ig_1		0x05
#define MB_offset_SRAB_Ig_2		0x05
#define MB_offset_SRAB_Ig_3		0x05
#define MB_offset_SRAB_Ig_4		0x05
#define MB_offset_SRAB_Ig_5		0x05
#define MB_offset_SRAB_Ig_6		0x05
#define MB_b_SRAB_Ig1		1<<4		// СРАБ I*>1
#define MB_b_SRAB_Ig2		1<<6		// СРАБ I*>2
#define MB_b_SRAB_Ig3		1<<8		// СРАБ I*>3
#define MB_b_SRAB_Ig4		1<<10		// СРАБ I*>4
#define MB_b_SRAB_Ig5		1<<12		// СРАБ I*>5
#define MB_b_SRAB_Ig6		1<<14		// СРАБ I*>6

// ---------------------------------
#define MB_offsetPTOC_Ia_Side1	0x20		// направления мощности, ошибка направления мощности
#define MB_offsetPTOC_Ib_Side1	0x20
#define MB_offsetPTOC_Ic_Side1	0x20
#define MB_offsetPTOC_In_Side1	0x20
#define MB_offsetPTOC_I0_Side1	0x20
#define MB_offsetPTOC_I2_Side1	0x20

#define MB_offsetPTOC_In_Side2	0x20
#define MB_offsetPTOC_I2_Side2	0x20
#define MB_offsetPTOC_Ia_Side2	0x20
#define MB_offsetPTOC_Ib_Side2	0x21
#define MB_offsetPTOC_Ic_Side2	0x21
#define MB_offsetPTOC_I0_Side2	0x21

#define MB_offsetPTOC_Ia_Side3	0x21
#define MB_offsetPTOC_Ib_Side3	0x21
#define MB_offsetPTOC_Ic_Side3	0x21
#define MB_offsetPTOC_In_Side3	0x21

#define MB_offsetPTOC_I0_Side3	0x22
#define MB_offsetPTOC_I2_Side3	0x22
// биты направления и достоверности мощности
#define MB_b_direction_In_Side1		1<<0		// направления мощности
#define MB_b_direction_Ia_Side1		1<<2
#define MB_b_direction_Ib_Side1		1<<4
#define MB_b_direction_Ic_Side1		1<<6
#define MB_b_direction_I0_Side1		1<<8
#define MB_b_direction_I2_Side1		1<<10


#define MB_b_dirError_In_Side1		1<<1		// ошибка направления мощности
#define MB_b_dirError_Ia_Side1		1<<3
#define MB_b_dirError_Ib_Side1		1<<5
#define MB_b_dirError_Ic_Side1		1<<7
#define MB_b_dirError_I0_Side1		1<<9
#define MB_b_dirError_I2_Side1		1<<11
#define MB_b_dirError_In_Side2		1<<13

#define MB_b_direction_In_Side2		1<<12
#define MB_b_direction_Ia_Side2		1<<14
#define MB_b_direction_Ib_Side2		1<<0
#define MB_b_direction_Ic_Side2		1<<2
#define MB_b_direction_I0_Side2		1<<4
#define MB_b_direction_I2_Side2		1<<6


#define MB_b_dirError_Ia_Side2		1<<15		// ошибка направления мощности
#define MB_b_dirError_Ib_Side2		1<<1
#define MB_b_dirError_Ic_Side2		1<<3
#define MB_b_dirError_I0_Side2		1<<5
#define MB_b_dirError_I2_Side2		1<<7

#define MB_b_dirError_In_Side3		1<<9
#define MB_b_dirError_I0_Side3		1<<1
#define MB_b_dirError_I2_Side3		1<<3

#define MB_b_direction_In_Side3		1<<8
#define MB_b_direction_Ia_Side3		1<<10		// направления мощности
#define MB_b_direction_Ib_Side3		1<<12
#define MB_b_direction_Ic_Side3		1<<14
#define MB_b_direction_I0_Side3		1<<0
#define MB_b_direction_I2_Side3		1<<2

#define MB_b_dirError_Ia_Side3		1<<11		// ошибка направления мощности
#define MB_b_dirError_Ib_Side3		1<<13
#define MB_b_dirError_Ic_Side3		1<<35

// U
#define MB_offset_IO_Uup_1		0x05
#define MB_offset_IO_Uup_2		0x06
#define MB_offset_IO_Uup_3		0x06
#define MB_offset_IO_Uup_4		0x06
#define MB_offset_SRAB_Uup_1	0x06
#define MB_offset_SRAB_Uup_2	0x06
#define MB_offset_SRAB_Uup_3	0x06
#define MB_offset_SRAB_Uup_4	0x06

#define MB_offset_IO_Udn_1		0x06
#define MB_offset_IO_Udn_2		0x06
#define MB_offset_IO_Udn_3		0x06
#define MB_offset_IO_Udn_4		0x06
#define MB_offset_SRAB_Udn_1	0x06
#define MB_offset_SRAB_Udn_2	0x06
#define MB_offset_SRAB_Udn_3	0x06
#define MB_offset_SRAB_Udn_4	0x06

#define MB_b_IO_Uup1		1<<15		// И0 U>1
#define MB_b_IO_Uup2		1<<1		// И0 U>2
#define MB_b_IO_Uup3		1<<3		// И0 U>3
#define MB_b_IO_Uup4		1<<5		// И0 U>4

#define MB_b_SRAB_Uup1		1<<0		// СРАБ U>1
#define MB_b_SRAB_Uup2		1<<2		// СРАБ U>2
#define MB_b_SRAB_Uup3		1<<4		// СРАБ U>3
#define MB_b_SRAB_Uup4		1<<6		// СРАБ U>4

#define MB_b_IO_Udn1		1<<7		// И0 U<1
#define MB_b_IO_Udn2		1<<9		// И0 U<2
#define MB_b_IO_Udn3		1<<11		// И0 U<3
#define MB_b_IO_Udn4		1<<13		// И0 U<4

#define MB_b_SRAB_Udn1		1<<8		// СРАБ U<1
#define MB_b_SRAB_Udn2		1<<10		// СРАБ U<2
#define MB_b_SRAB_Udn3		1<<12		// СРАБ U<3
#define MB_b_SRAB_Udn4		1<<14		// СРАБ U<4

// F
#define MB_offset_IO_Fup_1		0x06
#define MB_offset_IO_Fup_2		0x07
#define MB_offset_IO_Fup_3		0x07
#define MB_offset_IO_Fup_4		0x07
#define MB_offset_SRAB_Fup_1	0x07
#define MB_offset_SRAB_Fup_2	0x07
#define MB_offset_SRAB_Fup_3	0x07
#define MB_offset_SRAB_Fup_4	0x07

#define MB_offset_IO_Fdn_1		0x07
#define MB_offset_IO_Fdn_2		0x07
#define MB_offset_IO_Fdn_3		0x07
#define MB_offset_IO_Fdn_4		0x07
#define MB_offset_SRAB_Fdn_1	0x07
#define MB_offset_SRAB_Fdn_2	0x07
#define MB_offset_SRAB_Fdn_3	0x07
#define MB_offset_SRAB_Fdn_4	0x07

#define MB_b_IO_Fup1		1<<15		// И0 F>1
#define MB_b_IO_Fup2		1<<1		// И0 F>2
#define MB_b_IO_Fup3		1<<3		// И0 F>3
#define MB_b_IO_Fup4		1<<5		// И0 F>4

#define MB_b_SRAB_Fup1		1<<0		// СРАБ F>1
#define MB_b_SRAB_Fup2		1<<2		// СРАБ F>2
#define MB_b_SRAB_Fup3		1<<4		// СРАБ F>3
#define MB_b_SRAB_Fup4		1<<6		// СРАБ F>4

#define MB_b_IO_Fdn1		1<<7		// И0 F<1
#define MB_b_IO_Fdn2		1<<9		// И0 F<2
#define MB_b_IO_Fdn3		1<<11		// И0 F<3
#define MB_b_IO_Fdn4		1<<13		// И0 F<4

#define MB_b_SRAB_Fdn1		1<<8		// СРАБ F<1
#define MB_b_SRAB_Fdn2		1<<10		// СРАБ F<2
#define MB_b_SRAB_Fdn3		1<<12		// СРАБ F<3
#define MB_b_SRAB_Fdn4		1<<14		// СРАБ F<4

// внешняя
#define MB_offset_SRAB_ext_1		0x08
#define MB_offset_SRAB_ext_2		0x08
#define MB_offset_SRAB_ext_3		0x08
#define MB_offset_SRAB_ext_4		0x08
#define MB_offset_SRAB_ext_5		0x08
#define MB_offset_SRAB_ext_6		0x08
#define MB_offset_SRAB_ext_7		0x08
#define MB_offset_SRAB_ext_8		0x08
#define MB_offset_SRAB_ext_9		0x08
#define MB_offset_SRAB_ext_10		0x08
#define MB_offset_SRAB_ext_11		0x08
#define MB_offset_SRAB_ext_12		0x08
#define MB_offset_SRAB_ext_13		0x08
#define MB_offset_SRAB_ext_14		0x09
#define MB_offset_SRAB_ext_15		0x09
#define MB_offset_SRAB_ext_16		0x09

#define MB_b_SRAB_ext_1			1<<3
#define MB_b_SRAB_ext_2			1<<4
#define MB_b_SRAB_ext_3			1<<5
#define MB_b_SRAB_ext_4			1<<6
#define MB_b_SRAB_ext_5			1<<7
#define MB_b_SRAB_ext_6			1<<8
#define MB_b_SRAB_ext_7			1<<9
#define MB_b_SRAB_ext_8			1<<10
#define MB_b_SRAB_ext_9			1<<11
#define MB_b_SRAB_ext_10		1<<12
#define MB_b_SRAB_ext_11		1<<13
#define MB_b_SRAB_ext_12		1<<14
#define MB_b_SRAB_ext_13		1<<15
#define MB_b_SRAB_ext_14		1<<0
#define MB_b_SRAB_ext_15		1<<1
#define MB_b_SRAB_ext_16		1<<2

// дифф
#define MB_offset_IO_Diffup_1		0x03
#define MB_offset_SRAB_Diffup_1		0x03
#define MB_offset_IO_Diffup_2		0x03
#define MB_offset_SRAB_Diffup_2		0x03
// дифф 0
#define MB_offset_IO_Diff0_1		0x03
#define MB_offset_SRAB_Diff0_1		0x03
#define MB_offset_IO_Diff0_2		0x03
#define MB_offset_SRAB_Diff0_2		0x04
#define MB_offset_IO_Diff0_3		0x04
#define MB_offset_SRAB_Diff0_3		0x04

#define MB_b_IO_Diffup_1			1<<11
#define MB_b_SRAB_Diffup_1			1<<12
#define MB_b_IO_Diffup_2			1<<9
#define MB_b_SRAB_Diffup_2			1<<10
#define MB_b_IO_Diff0_1				1<<13
#define MB_b_SRAB_Diff0_1			1<<14
#define MB_b_IO_Diff0_2				1<<15
#define MB_b_SRAB_Diff0_2			1<<0
#define MB_b_IO_Diff0_3				1<<1
#define MB_b_SRAB_Diff0_3			1<<2

#define MB_b_IO_Diffup_m			1<<8

// выключатель
#define MB_offset_SW_ctl			0x0B
#define MB_offset_SW_status			0x0E
#define MB_b_SW_ON					1<<9
#define MB_b_SW_OFF					1<<8
// АПВ
#define MB_offset_SW_ON_APW			0x0B
#define MB_b_SW_ON_APW				1<<15
//АВР
#define MB_offset_AWR				0x0B
#define MB_b_ON_AWR					1<<0x0A
#define MB_b_OFF_AWR				1<<0x0B
#define MB_b_Blok_AWR				1<<0x0C
//ЛЗШ
#define MB_offset_LZSH				0x0B
#define MB_b_Rab_LZSH				1<<0x0D
//УРОВ
#define MB_offset_UROV				0x0B
#define MB_b_Rab_UROV				1<<0x0E



// Z ----
#define MB_IO_offsetZ_1			0x06
#define MB_IO_offsetZ_2			0x07
#define MB_Z1_IO				1<<8
#define MB_Z1					1<<9
#define MB_Z2_IO				1<<10
#define MB_Z2					1<<11
#define MB_Z3_IO				1<<12
#define MB_Z3					1<<13
#define MB_Z4_IO				1<<14
#define MB_Z4					1<<15

#define MB_Z5_IO				1<<0
#define MB_Z5					1<<1
#define MB_Z6_IO				1<<2
#define MB_Z6					1<<3
#define MB_Z7_IO				1<<4
#define MB_Z7					1<<5
#define MB_Z8_IO				1<<6
#define MB_Z8					1<<7
#define MB_Z9_IO				1<<8
#define MB_Z9					1<<9
#define MB_Z10_IO				1<<10
#define MB_Z10					1<<11
// ------
#define MB_IO_offDirZ_1			0x26
#define MB_IO_offDirZ_2			0x27

#define MB_PTOC_In				1<<16
#define MB_error_In				1<<17
#define MB_PTOC_Ia				1<<6
#define MB_error_Ia				1<<7
#define MB_PTOC_Ib				1<<8
#define MB_error_Ib				1<<9
#define MB_PTOC_Ic				1<<10
#define MB_error_Ic				1<<11
#define MB_PTOC_I0				1<<12
#define MB_error_I0				1<<13
#define MB_PTOC_I2				1<<14
#define MB_error_I2				1<<15

#define MB_offset_errorM1		0x10
#define MB_offset_errorM2		0x10
#define MB_offset_errorM3		0x10
#define MB_offset_errorM4		0x10
#define MB_offset_errorM5		0x10
#define MB_errorM1				1<<7		// 11R
#define MB_errorM2				1<<8		// 8D 8R
#define MB_errorM3				1<<9		// 16D
#define MB_errorM4				1<<10		// 16D 16R
#define MB_errorM5				1<<11		// 4I 5U

// ----------------------------------------------------------------------------------------------
#define MB_StartAnalogINaddr   	0x0E00		// база данных аналогов
#define MB_NumbAnalog   		58			// 57 слов

#define MB_offset_Ia_Diff		0
#define MB_offset_Ib_Diff		1
#define MB_offset_Ic_Diff		2

#define MB_offset_I2a_Diff		3
#define MB_offset_I2b_Diff		4
#define MB_offset_I2c_Diff		5

#define MB_offset_I5a_Diff		6
#define MB_offset_I5b_Diff		7
#define MB_offset_I5c_Diff		8

#define MB_offset_Ita			9
#define MB_offset_Itb			10
#define MB_offset_Itc			11

#define MB_offset_Is1n			12
#define MB_offset_Is1a			13
#define MB_offset_Is1b			14
#define MB_offset_Is1c			15
#define MB_offset_Is1o			16
#define MB_offset_Is12			17

#define MB_offset_Is2n			20
#define MB_offset_Is2a			21
#define MB_offset_Is2b			22
#define MB_offset_Is2c			23
#define MB_offset_Is2o			24
#define MB_offset_Is22			25

#define MB_offset_Is3n			28
#define MB_offset_Is3a			29
#define MB_offset_Is3b			30
#define MB_offset_Is3c			31
#define MB_offset_Is3o			32
#define MB_offset_Is32			33


#define MB_offset_Un			36
#define MB_offset_Ua			37
#define MB_offset_Ub			38
#define MB_offset_Uc			39
#define MB_offset_Uab			40
#define MB_offset_Ubc			41
#define MB_offset_Ucd			42
#define MB_offset_U0			43
#define MB_offset_U2			44

#define MB_offset_Il1o			45
#define MB_offset_Il1a			46
#define MB_offset_Il1b			47
#define MB_offset_Il1c			48
#define MB_offset_Il2o			49
#define MB_offset_Il2a			50
#define MB_offset_Il2b			51
#define MB_offset_Il2c			52
#define MB_offset_Il3o			53
#define MB_offset_Il3a			54
#define MB_offset_Il3b			55
#define MB_offset_Il3c			56

#define MB_offset_Hz			57		// F

// --------------------------------------------------
#define MB_addr_SwOFF  			0x0D0B		//адрес выключеня off
#define MB_addr_SwON   			0x0D0C		//адрес включеня on
//#define MB_SwOFF  				0x0000		//off
#define MB_Sw   				0xFF00		//on

#define MB_NumbDate		   		7

#define MB_StartSW 				MB_StartConfig
#define MB_StartTransMeas		0x105C
// ----------------------------------------------------------------------------------------------
#define MB_StartDateNaddr   	0x0200
#define MB_NumbDate		   		7

#define MB_addr_SGroupe0		0x0D09
#define MB_addr_SGroupe1		0x0D0A

// ----------------------------------------------------------------------------------------------
#define MB_StartRevNaddr   		0x0500		// версия 17 слов
#define MB_NumbWordRev	   		17

#define MB_addr_SysNote_OFF		0x0D01
#define MB_addr_ErrorNote_OFF	0x0D02

#define MB_addr_Error_OFF		0x0D04
#define MB_addr_LEDS_OFF		0x0D05

#define MB_CTRL_OFF				0xFF00

// Параметры автоматики -------------------------------------------------------------------------
#define MB_StartAutomat			0x155C
#define MB_NumbAutomat			0x15BE - MB_StartAutomat + 1

// Параметры системы (они же IP адрес) -----------------------------------------------------------
#define MB_StartSystemCfg		0x15BE
#define MB_NumbSystemCfg		10
#define MB_offset_IP			4		// F

//#define MB_ConfigSystem	   		0x29E8			// Конфигурация системы
//#define MB_Size_ConfSysytem		121

// Только IP адрес  -----------------------------------------------------------------------------------
//#define MB_StartConfigNaddr   	0x05C0			// временно читаем только IP адрес учтройства. 0x05C0 - 2 слова
//#define MB_NumbConfigNaddr 		2




#define MB_PerForSynchClock		1				// период пересинхронизации часов
#define MB_PerForReadMODBUS		100				// период опроса модбас в мс	150

#endif
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
