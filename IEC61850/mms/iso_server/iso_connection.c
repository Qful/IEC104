/*
 *  iso_connection.c
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

#include "libiec61850_platform_includes.h"

#include "stack_config.h"
#include "byte_stream.h"
#include "cotp.h"
#include "iso_session.h"
#include "iso_presentation.h"
#include "acse.h"
#include "iso_server.h"
//#include "socket.h"
#include "thread.h"

#define RECEIVE_BUF_SIZE MMS_MAXIMUM_PDU_SIZE
#define SEND_BUF_SIZE MMS_MAXIMUM_PDU_SIZE

#define ISO_CON_STATE_RUNNING 1
#define ISO_CON_STATE_STOPPED 0

struct sIsoConnection {
    uint8_t* receive_buf;
    uint8_t* send_buf_1;
    uint8_t* send_buf_2;
    MessageReceivedHandler msgRcvdHandler;
    IsoServer isoServer;
    void* msgRcvdHandlerParameter;
    Socket socket;
    int state;
    IsoSession* session;
    IsoPresentation* presentation;
    CotpConnection* cotpConnection;
    char* clientAddress;
    Thread thread;
    Semaphore conMutex;
};


static void
handleTcpConnection(IsoConnection self){
}

IsoConnection	IsoConnection_create(Socket socket, IsoServer isoServer)
{

}

char*
IsoConnection_getPeerAddress(IsoConnection self)
{
	return self->clientAddress;
}


void
IsoConnection_sendMessage(IsoConnection self, ByteBuffer* message)
{
	ByteBuffer presWriteBuffer;
	ByteBuffer sessionWriteBuffer;

    Semaphore_wait(self->conMutex);

	ByteBuffer_wrap(&presWriteBuffer, self->send_buf_1, 0, SEND_BUF_SIZE);
	ByteBuffer_wrap(&sessionWriteBuffer, self->send_buf_2, 0, SEND_BUF_SIZE);

	IsoPresentation_createUserData(self->presentation,
								&presWriteBuffer, message);

	IsoSession_createDataSpdu(self->session, &sessionWriteBuffer);

	ByteBuffer_append(&sessionWriteBuffer, presWriteBuffer.buffer,
								presWriteBuffer.currPos);

	CotpConnection_sendDataMessage(self->cotpConnection, &sessionWriteBuffer);

	Semaphore_post(self->conMutex);
}

void
IsoConnection_close(IsoConnection self)
{
	if (self->state != ISO_CON_STATE_STOPPED) {
	    self->state = ISO_CON_STATE_STOPPED;
	}
}

void
IsoConnection_installListener(IsoConnection self, MessageReceivedHandler handler,
		void* parameter)
{
	self->msgRcvdHandler = handler;
	self->msgRcvdHandlerParameter = parameter;
}


