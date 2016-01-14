/*
 *  socket_linux.c
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


#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "queue.h"

#include "main.h"
#include "time.h"
#include "stdlib.h"
#include "string.h"

#include "ethernetif.h"
#include "lwip/tcpip.h"
#include "lwip/init.h"
#include "lwip/netif.h"
#include "lwip/api.h"
#include "lwip/sys.h"
#include "lwip/sockets.h"
#include "lwip/netdb.h"

#include "socket_lwIP.h"

#ifndef SOL_TCP
#define SOL_TCP IPPROTO_TCP
#endif

#include "stack_config.h"


struct sSocket {
    int fd;
};

struct sServerSocket {
    int fd;
    int backLog;
};

//TODO this is linux specific!
static void		activateKeepAlive(int sd)
{
    int optval;
    socklen_t optlen = sizeof(optval);

    optval = 1;
    setsockopt(sd, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen);

#if defined __linux__
    optval = CONFIG_TCP_KEEPALIVE_IDLE;
    setsockopt(sd, SOL_TCP, TCP_KEEPIDLE, &optval, optlen);

    optval = CONFIG_TCP_KEEPALIVE_INTERVAL;
    setsockopt(sd, SOL_TCP, TCP_KEEPINTVL, &optval, optlen);

    optval = CONFIG_TCP_KEEPALIVE_CNT;
    setsockopt(sd, SOL_TCP, TCP_KEEPCNT, &optval, optlen);
#endif
}
/*************************************************************************
 * TcpServerSocket_create
 *************************************************************************/
ServerSocket	TcpServerSocket_create(char* address, int port)
{
    ServerSocket serverSocket = NULL;

    int fd;

    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) >= 0) {
        struct sockaddr_in serverAddress;

        memset(&serverAddress, 0, sizeof(serverAddress));
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = htonl(INADDR_ANY );
        serverAddress.sin_port = htons(port);

        //TODO check if this works with BSD
        int optionReuseAddr = 1;
        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *) &optionReuseAddr, sizeof(int));

        if (bind(fd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) >= 0) {
            serverSocket = malloc(sizeof(struct sServerSocket));
            serverSocket->fd = fd;
            serverSocket->backLog = 0;
        }
        else {
            close(fd);
            return NULL ;
        }

#if (CONFIG_ACTIVATE_TCP_KEEPALIVE == 1)
        activateKeepAlive(fd);
#endif
    }

    return serverSocket;
}
/*************************************************************************
 * ServerSocket_listen
 *************************************************************************/
void	ServerSocket_listen(ServerSocket socket)
{
    listen(socket->fd, socket->backLog);
}
/*************************************************************************
 * ServerSocket_accept
 *************************************************************************/
Socket	ServerSocket_accept(ServerSocket socket)
{
    int fd;

    Socket conSocket = NULL;

    fd = accept(socket->fd, NULL, NULL );

    if (fd >= 0) {
        conSocket = TcpSocket_create();
        conSocket->fd = fd;
    }

    return conSocket;
}
/*************************************************************************
 * ServerSocket_setBacklog
 *************************************************************************/
void	ServerSocket_setBacklog(ServerSocket socket, int backlog)
{
    socket->backLog = backlog;
}
/*************************************************************************
 * closeAndShutdownSocket
 *************************************************************************/
static void	closeAndShutdownSocket(int socketFd)
{
    if (socketFd != -1) {
        // выключение требуется, чтобы разблокировать чтение или доступ в другом потоке!
        shutdown(socketFd, SHUT_RDWR);
        close(socketFd);
    }
}
/*************************************************************************
 * ServerSocket_destroy
 *************************************************************************/
void	ServerSocket_destroy(ServerSocket socket)
{
    closeAndShutdownSocket(socket->fd);

    free(socket);
}
/*************************************************************************
 * TcpSocket_create
 *************************************************************************/
Socket	TcpSocket_create()
{
    Socket socket = malloc(sizeof(struct sSocket));

    socket->fd = -1;

    return socket;
}
/*************************************************************************
 * Socket_connect
 *************************************************************************/
int	Socket_connect(Socket self, char* address, int port)
{
    struct hostent *server;
    struct sockaddr_in serverAddress;

    server = gethostbyname(address);

    memset((char *) &serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;

    memcpy((char *) &serverAddress.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    serverAddress.sin_port = htons(port);

    self->fd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(self->fd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0)
        return 0;
    else
        return 1;
}
/*************************************************************************
 * Socket_getPeerAddress
 *************************************************************************/
/*
char*	Socket_getPeerAddress(Socket self)
{
    struct sockaddr addr;				//sockaddr_storage
    int addrLen = sizeof(addr);

    getpeername(self->fd, &addr,(socklen_t *) &addrLen);

    char* addrString[INET_ADDRSTRLEN + 7];
    int port;

    if (addr.sa_family == AF_INET) {
        struct sockaddr_in* ipv4Addr = (struct sockaddr_in*) &addr;
        port = ntohs(ipv4Addr->sin_port);
        inet_ntop(AF_INET, &(ipv4Addr->sin_addr), addrString, INET_ADDRSTRLEN);
    }
    else
        return NULL ;

    char* clientConnection = malloc(strlen(addrString) + 8);

    sprintf(clientConnection, "%s[%i]", addrString, port);

    return clientConnection;
}
*/
int
Socket_read(Socket socket, uint8_t* buf, int size)
{
    return read(socket->fd, buf, size);
}

int
Socket_write(Socket socket, uint8_t* buf, int size)
{
    // MSG_NOSIGNAL - prevent send to signal SIGPIPE when peer unexpectedly closed the socket
    return send(socket->fd, buf, size, MSG_NOSIGNAL);
}

void
Socket_destroy(Socket socket)
{
    closeAndShutdownSocket(socket->fd);

    /* Wait for other threads to realize that the socket has been closed */
    //Thread_sleep(100);
    osDelay(100);

    free(socket);
}
