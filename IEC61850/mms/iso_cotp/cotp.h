/*
 *  cotp.h
 *
 *  Copyright 2013 Michael Zillgith
 *
 *  This file is part of libIEC61850.
 *
 *  libIEC61850 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libIEC61850 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libIEC61850.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  See COPYING file for the complete license text.
 */

#ifndef COTP_H_
#define COTP_H_

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "byte_buffer.h"
#include "byte_stream.h"
//#include "socket.h"

/** Opaque reference for a client or connection socket instance */
typedef struct netconn* Socket;

typedef struct {
    int32_t tsap_id_src;
    int32_t tsap_id_dst;
    uint8_t tpdu_size;
} CotpOptions;

typedef struct {
    int 		state;
    int 		srcRef;
    int 		dstRef;
    int 		class;
    CotpOptions options;
    uint8_t 	eot;
    ByteBuffer* payload;				// буфер принятых данных без COTP
    ByteBuffer* readBuffer;				// принятые данные
    ByteBuffer* writeBuffer;			// данные для передачи(ответа)
} CotpConnection;

typedef enum {
    OK, ERR, CONNECT_INDICATION, DATA_INDICATION, DISCONNECT_INDICATION
} CotpIndication;

int  /* in byte */
CotpConnection_getTpduSize(CotpConnection* self);

void
CotpConnection_setTpduSize(CotpConnection* self, int tpduSize /* in byte */);

void	CotpConnection_init(CotpConnection* self, ByteBuffer* payloadBuffer);

void	CotpConnection_destroy(CotpConnection* self);

//void	ByteStream_setWriteBuffer(ByteStream self, ByteBuffer* writeBuffer);

CotpIndication
CotpConnection_parseIncomingMessage(CotpConnection* self);

CotpIndication
CotpConnection_sendConnectionRequestMessage(CotpConnection* self);					// отправка запроса соединения

CotpIndication
CotpConnection_sendConnectionResponseMessage(CotpConnection* self);					// отправка ответа на соединение

CotpIndication
CotpConnection_sendDataMessage(CotpConnection* self, ByteBuffer* writeBuffer);

ByteBuffer*		CotpConnection_getreadBuffer(CotpConnection* self);
ByteBuffer*		CotpConnection_getPayload(CotpConnection* self);
#endif /* COTP_H_ */
