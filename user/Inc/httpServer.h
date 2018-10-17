/*
 * httpServer.h
 *
 *  Created on: 14.01.2017
 *      Author: sagok
 */

#ifndef HTTPSERVER_H_
#define HTTPSERVER_H_

#include "hal_socket.h"

#include "lwip/def.h"
#include "fsdata.h"

#ifdef __cplusplus
extern "C" {
#endif

struct fs_file {
  char *data;
  int len;
};

void IAP_httpd_init(void);

void StartHTTPTask(void const * argument);
void http_server_serve(Socket self);
void SSH_server_serve(Socket self);
void SSH_Transmit(Socket self, uint8_t *pData, uint16_t Size);

void GetRunTimeStats( char *pcWriteBuffer );

#ifdef __cplusplus
}
#endif

#endif /* HTTPSERVER_H_ */
