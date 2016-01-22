/*
 * main.h
 *
 *  Created on: 16.06.2015
 *      Author: sagok
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "stdint.h"

// Enable/Disable tracing using LED outputs
#define LED_TRACE_ENABLE            1
// Enable/Disable tracing using USART outputs
#define USART_TRACE_ENABLE          1

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
#if (USART_TRACE_ENABLE)

#define  USART_TRACE(...)   printf("\033[1;mDBG: ") ;\
                            printf(__VA_ARGS__);
                            //printf("\n");

#define  USART_TRACE_RED(...)   printf("\033[1;31mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");

#define  USART_TRACE_GREEN(...)   printf("\033[1;32mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");

#define  USART_TRACE_BLUE(...)   printf("\033[1;34mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");

#define  USART_TRACE_MAGENTA(...)   printf("\033[1;35mDBG: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\033[1;m");
#define  USART_0TRACE(...)  printf(__VA_ARGS__);

#else
#define USART_TRACE(...)
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


/*MAC ADDRESS */
#define MAC_ADDR0   01
#define MAC_ADDR1   02
#define MAC_ADDR2   03
#define MAC_ADDR3   04
#define MAC_ADDR4   05
#define MAC_ADDR5   06

/*Static IP ADDRESS for first*/
#define first_IP_ADDR0   192
#define first_IP_ADDR1   168
#define first_IP_ADDR2   0
#define first_IP_ADDR3   254
/*Static IP ADDRESS*/
#define second_IP_ADDR0   192
#define second_IP_ADDR1   168
#define second_IP_ADDR2   0
#define second_IP_ADDR3   253
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

/*Modbus */
#define MB_Slaveaddr   			1
#define MB_StartDiscreetaddr   	0x0D00
#define MB_NumbDiscreet   		40

#define MB_StartAnalogINaddr   	0x0E00
#define MB_NumbAnalogIN   		57

#define MB_StartDateNaddr   	0x0200
#define MB_NumbDate		   		7

#include "ConfBoard.h"

extern void Port_Init(Port_TypeDef Port,uint32_t mode);
extern void Port_On(Port_TypeDef Port);
extern void Port_Off(Port_TypeDef Port);
extern void Port_Toggle(Port_TypeDef Port);

#endif /* MAIN_H_ */
