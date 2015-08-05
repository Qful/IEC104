/*
 * main.h
 *
 *  Created on: 16.06.2015
 *      Author: sagok
 */

#ifndef MAIN_H_
#define MAIN_H_

#define ECHO_Port		7			/* 7 ECHO — предназначен для тестирования связи путём отправки данных на сервер и получения от него их же в неизменном виде*/
#define TFTP_Port		69			/* 69 тривиальный FTP применяется при установке операционной системы, у нас бутлодер */
#define HTTP_Port		80			/* 80 is the port used for HTTP protocol */
#define FTP_Port		21			/* 21 для передачи команд FTP */
#define IEC104_Port		2404		/* 2404 is the port used for IEC 60870-5-104 protocol */


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

#include "stm324xg_eval.h"

extern void LED_On(Led_TypeDef Led);
extern void LED_Off(Led_TypeDef Led);
extern void LED_Toggle(Led_TypeDef Led);

#endif /* MAIN_H_ */
