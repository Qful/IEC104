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
    IsoServerState state;
    ConnectionIndicationHandler connectionHandler;
    void* connectionHandlerParameter;
    AcseAuthenticationParameter authParameter;
    Thread serverThread;
    Socket serverSocket;
    int tcpPort;
};


static void		isoServerThread(void* isoServerParam)
{

}

IsoServer	IsoServer_create()
{

}

void
IsoServer_setTcpPort(IsoServer self, int port)
{
    self->tcpPort = port;
}

IsoServerState
IsoServer_getState(IsoServer self)
{

}

void
IsoServer_setAuthenticationParameter(IsoServer self, AcseAuthenticationParameter authParameter)
{
;
}

AcseAuthenticationParameter
IsoServer_getAuthenticationParameter(IsoServer self)
{

}

void
IsoServer_startListening(IsoServer self)
{

}

void
IsoServer_stopListening(IsoServer self)
{

}

void
IsoServer_closeConnection(IsoServer self, IsoConnection isoConnection)
{
    self->connectionHandler(ISO_CONNECTION_CLOSED, self->connectionHandlerParameter,
            isoConnection);

    //IsoConnection_close(isoConnection);
    //IsoConnection_destroy(isoConnection);
}

void
IsoServer_setConnectionHandler(IsoServer self, ConnectionIndicationHandler handler, void* parameter)
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

