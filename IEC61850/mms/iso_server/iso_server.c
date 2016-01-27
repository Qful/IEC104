/*
 *  iso_server.c
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
#include "mms_server_connection.h"

#include "thread.h"

#include "iso_server.h"
#include "main.h"

#define TCP_PORT 	IEC850_Port
#define BACKLOG 	10

struct sIsoServer {
    IsoServerState 					state;							// статус работы сервера ISO  (	ISO_SVR_STATE_IDLE,ISO_SVR_STATE_RUNNING,ISO_SVR_STATE_STOPPED,ISO_SVR_STATE_ERROR)
    ConnectionIndicationHandler 	connectionHandler;
    void* 							connectionHandlerParameter;
    AcseAuthenticationParameter 	authParameter;					// параметры парольного доступа к серверу
    Thread 							serverThread;
    Socket 							serverSocket;					// TCP/IP стек
    int 							tcpPort;						// порт сервера
};


static void		isoServerThread(void* isoServerParam)
{

}
/*************************************************************************
 * IsoServer_create
 * state = ISO_SVR_STATE_IDLE
 * tcpPort = TCP_PORT
 *************************************************************************/
IsoServer	IsoServer_create()
{
    IsoServer self = calloc(1, sizeof(struct sIsoServer));

    self->state = ISO_SVR_STATE_IDLE;
    self->tcpPort = TCP_PORT;

    return self;
}

/*************************************************************************
 * IsoServer_setTcpPort
 *
 *************************************************************************/
void	IsoServer_setTcpPort(IsoServer self, int port)
{
    self->tcpPort = port;
}

IsoServerState	IsoServer_getState(IsoServer self)
{
    return self->state;
}
/*************************************************************************
 * IsoServer_setAuthenticationParameter
 * включаем парольный доступ к серверу
 *************************************************************************/
void	IsoServer_setAuthenticationParameter(IsoServer self, AcseAuthenticationParameter authParameter)
{
    self->authParameter = authParameter;
}
/*************************************************************************
 * IsoServer_getAuthenticationParameter
 * узнаем парольный ли доступ к серверу ??
 *************************************************************************/
AcseAuthenticationParameter		IsoServer_getAuthenticationParameter(IsoServer self)
{
    return self->authParameter;
}

/*************************************************************************
 * IsoServer_startListening
 * не рабоча€ функци€
 *************************************************************************/
void	IsoServer_startListening(IsoServer self)
{
	// Thread пустые функции
    self->serverThread = Thread_create(isoServerThread, self, false);

    Thread_start(self->serverThread);

    while (self->state == ISO_SVR_STATE_IDLE)	Thread_sleep(1);

    USART_TRACE("IsoServer_startListening не работает, нужно дописать старт сервера.\n");

}
/*************************************************************************
 * IsoServer_stopListening
 *
 *************************************************************************/
void	IsoServer_stopListening(IsoServer self)
{
    self->state = ISO_SVR_STATE_STOPPED;
}

void
IsoServer_closeConnection(IsoServer self, IsoConnection isoConnection)
{
    self->connectionHandler(ISO_CONNECTION_CLOSED, self->connectionHandlerParameter, isoConnection);

    //IsoConnection_close(isoConnection);
    //IsoConnection_destroy(isoConnection);
}

/*************************************************************************
 * IsoServer_setConnectionHandler
 *
 *************************************************************************/
void	IsoServer_setConnectionHandler(IsoServer self, ConnectionIndicationHandler handler, void* parameter)
{
    self->connectionHandler = handler;
    self->connectionHandlerParameter = parameter;
}

void
IsoServer_destroy(IsoServer self)
{
    if (self->state == ISO_SVR_STATE_RUNNING)
        IsoServer_stopListening(self);

    free(self);
}

