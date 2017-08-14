/*
 * sntpclient.h
 *
 *  Created on: 28.02.2017
 *      Author: sagok
 */

#ifndef SNTPCLIENT_H_
#define SNTPCLIENT_H_

#include <port.h>

#define CorrectTrewel	165			// корректировка времени установки часов в самом приборе после модбас передаче

#define base1970	0x83AA7E80
#define base1ms		4294968

typedef enum
{
	Write = 1,
	Read = 0
} SNTP_RW_Indication;

int sntp_client_serve(Socket self, const char* address, int port, int sent);
BOOL		Hal_setTimeToMB_Date( uint16_t * MDateBuf );

#endif /* SNTPCLIENT_H_ */
