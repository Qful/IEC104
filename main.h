/*
 * main.h
 *
 *  Created on: 16.06.2015
 *      Author: sagok
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "stdint.h"
#include "clocks.h"

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

#define	IEC850_SECURE_PORT		3782
// часовой пояс для временных данных по UTC
#define	Timezone	+3

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
#define MAC_ADDR0   0x01
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


#if defined (MR771)
//Modbus  MR771
#define MB_Speed				115200
#define MB_Slaveaddr   			1

#define MB_StartConfig		   	0x1000			// уставки 4 группы, нужно узнать в какой группе сидим
#define MB_NOfConfig		   	0x0400			// группа уставок 00-05 : 1-6 группа
#define MB_IncNumbOfConfig		0x428

#define MB_Config0		   		0x1000			// группа уставок 1
#define MB_Config1		   		0x1428			// группа уставок 2
#define MB_Config2		   		0x1850			// группа уставок 3
#define MB_Config3		   		0x1C78			// группа уставок 4
#define MB_Config4		   		0x20A0			// группа уставок 5
#define MB_Config5		   		0x24C8			// группа уставок 6

#define MB_offset_ConfTrans		0x0278			// Уставки трансформатора
#define MB_Size_ConfTrans		16				// размер блока уставок трансформаторы.

#define MB_offset_Kttf			0				// Ittф
#define MB_offset_Kttn			1				// Ittn
#define MB_offset_Ktnf			8				// ТТНП
#define MB_offset_Ktnn			9				// ТТНHП


#define MB_ConfigSW		   		0x28F0			// конфигурация Выключателя
#define MB_Size_ConfSW			16

#define	MB_rOffsetControlSW		0				// управление выключателем
#define	MB_bControlSW_Button	1<<0
#define	MB_bControlSW_Switch	1<<1
#define	MB_bControlSW_Extern	1<<2
#define	MB_bControlSW_SDTU		1<<3
#define	MB_bControlSW_CmdOFF	1<<4

#define MB_ConfigDiscr	   		0x2900			// Конфигурация входных сигналов
#define MB_Size_ConfDiscr		8

#define MB_ConfigSystem	   		0x29E8			// Конфигурация системы
#define MB_Size_ConfSysytem		121

//#define MB_offsetIP				0x0272
//#define MB_NumbIP		   		2

#define MB_StartConfigNaddr   	0x05C0			// временно читаем только IP адрес учтройства. 0x05C0 - 2 слова
#define MB_NumbConfigNaddr 		2

// ----------------------------------------------------------------------------------------------
#define MB_StartDiscreetaddr   	0x0D00			// адрес и размер для комманд чтения (3,4)
#define MB_NumbDiscreet   		0x28			// перечисления в словах а ответ в байтах
#define MB_offsetRelay			0x10
#define MB_offsetError			0x16			// неисправности модулей
#define MB_offsetDiscreet		0x00
#define MB_offsetDiscreet1		0x01
#define MB_offsetDiscreet2		0x02
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


#define MB_offsetLogic			0x00
#define MB_offset_I_IO			0x07			// И0 I>1

#define MB_offsetPTOC			0x16
#define MB_offsetDirGeneral		0x00

#define MB_I_IO_I1				1<<12
#define MB_I_IO_I2				1<<14
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

#define MB_errorM1				1<<7		// 11R
#define MB_errorM2				1<<8		// 8D 8R
#define MB_errorM3				1<<9		// 16D
#define MB_errorM4				1<<10		// 16D 16R
#define MB_errorM5				1<<11		// 4I 5U

// ----------------------------------------------------------------------------------------------
#define MB_StartAnalogINaddr   	0x0E00
#define MB_NumbAnalog   		96

#define MB_offset_In			6
#define MB_offset_Ia			0
#define MB_offset_Ib			1
#define MB_offset_Ic			2

#define MB_offset_Un			14
#define MB_offset_Un1			15
#define MB_offset_Ua			11
#define MB_offset_Ub			12
#define MB_offset_Uc			13

#define MB_offset_Uab			16
#define MB_offset_Ubc			17
#define MB_offset_Ucd			18

#define MB_offset_Hz			24		// F
#define MB_offset_TotW			26		// P 2слова
#define MB_offset_TotVAr		28		// Q 2слова
#define MB_offset_TotPF			30		// cos

#define MB_addr_SwOFF  			0x0D08		//адрес выключеня off
#define MB_addr_SwON   			0x0D09		//адрес включеня on
#define MB_SwOFF  				0x0000		//off
#define MB_SwON   				0xFF00		//on

#define MB_NumbDate		   		7


#define MB_StartDateNaddr   	0x0200
#define MB_NumbDate		   		7

#define MB_StartRevNaddr   		0x0500
#define MB_NumbWordRev	   		16


#define MB_PerForSynchClock		1				// период пересинхронизации часов
#define MB_PerForReadMODBUS		150				// период опроса модбас в мс

#elif defined (MR5_700)
//Modbus  MR5-ПО70
#define MB_Speed				115200
#define MB_Slaveaddr   			1

#define MB_StartConfig		   	0x1000			// уставки
#define MB_NumbConfigall   		0x274
#define MB_offset_OMP			0x0D
#define MB_offset_BlockSDTU		0x17


#define MB_offset_Ktt			0x0001			//.
#define MB_offset_Ktn			0x0009			//.

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

#define MB_offsetSW_OFF			1<<0
#define MB_offsetSW_ON			1<<1

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

#define MB_offset_NU0			16
#define MB_offset_NU1			17
#define MB_offset_NU2			18


#define MB_offset_Hz			18
#define MB_offset_TotPF			19
#define MB_offset_TotW			20
#define MB_offset_TotVAr		21
#define MB_offset_OMPLkz		22

#define MB_StartDateNaddr   	0x0200
#define MB_NumbDate		   		7

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

// размер буфера для работы DEBUG USART
#define		BOOT_BUF_MAX_OUTPUT_SIZE		250//150


/* Converts a time in milliseconds to a time in ticks. */
#define pdMS_TO_TICKS( xTimeInMs ) ( ( TickType_t ) ( ( ( TickType_t ) ( xTimeInMs ) * ( TickType_t ) configTICK_RATE_HZ ) / ( TickType_t ) 1000 ) )


#include "ConfBoard.h"

/* FatFs includes component */
#include "ff_gen_drv.h"
#include "spimem_diskio.h"

extern void Port_Init(Port_TypeDef Port,uint32_t mode);
extern void Port_On(Port_TypeDef Port);
extern void Port_Off(Port_TypeDef Port);
extern void Port_Toggle(Port_TypeDef Port);

void vOutputDEBUG( char *pcMessage );

#endif /* MAIN_H_ */
