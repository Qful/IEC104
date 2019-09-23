/*
 * tftpServer.h
 *
 *  Created on: 04.01.2018
 *      Author: sagok
 */

#ifndef FTPSERVER_H_
#define FTPSERVER_H_

#include "lwip/mem.h"
#include "lwip/udp.h"

#define FTP_fifo_Size		2000

#define BACKLOG 			5				// ожидающие подключение.  похоже можно только = 1 в lwIP

#define		_10min			100 * 600 *10	// лимит сеанса SSH
#define		_60min			(100 * 600 *60)	// лимит сеанса SSH

/* The address used as the root by the HTTP server. */
#define configHTTP_ROOT "/websrv"

void StartFTPTask(void const * argument);


#endif /* TFTPSERVER_H_ */
