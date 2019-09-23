/*
 * httpServer.h
 *
 *  Created on: 14.01.2017
 *      Author: sagok
 */

#ifndef HTTPSERVER_H_
#define HTTPSERVER_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "hal_socket.h"
#include "lwip/def.h"
#include "fsdata.h"
#include "lwip/tcp.h"

//#include "fs.h"

#define HTTP_fifo_Size		100//2000


struct fs_file {
  char *data;
  int len;
};

int fs_open(char *name, struct fs_file *file);

void IAP_httpd_init(void);

void StartHTTPTask(void const * argument);
void http_server_serve(Socket self);
void SSH_Transmit(Socket self, uint8_t *pData, uint16_t Size);

void GetRunTimeStats( char *pcWriteBuffer );

void SetNTPconfig(char *inbuff);

void http_init(void);
void send_http(struct tcp_pcb *pcb, char *msg, int len);

#ifdef __cplusplus
}
#endif

#endif /* HTTPSERVER_H_ */
