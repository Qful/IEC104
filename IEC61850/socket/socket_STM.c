/*
 *  socket_linux.c
 *
 *  Copyright 2013, 2014 Michael Zillgith
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

#include "hal_socket.h"

#include <lwip/sockets.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <lwip/netdb.h>

#include <errno.h>
#include <main.h>
#include <stack_config.h>

#include <lwip/tcp.h> // required for TCP keepalive

#include "libiec61850_platform_includes.h"

#include "iso_server.h"
#include "iec61850_server.h"
#include "PrpHsr_value.h"

extern IedServer iedServer;

#define INET6_ADDRSTRLEN	24
#define INET_ADDRSTRLEN		24


#ifndef DEBUG_SOCKET
#define DEBUG_SOCKET 0
#endif

struct sHandleSet {
   fd_set handles;
   int maxHandle;
};

struct sServerSocket {
    int fd;
    int backLog;
};

struct sSocket {
    int fd;
//    uint32_t connectTimeout;
};

struct udp_pcb *upcb;

/*************************************************************************
 * inet_ntop4
 *************************************************************************/
#define MAX_IPv4_STR_LEN             16

static const char *
inet_ntop4(const struct in_addr *addr, char *buf, socklen_t len)
{
	const uint8_t *ap = (const uint8_t *)&addr->s_addr;
	char tmp[MAX_IPv4_STR_LEN]; /* max length of ipv4 addr string */
	int fulllen;

	/*
	 * snprintf returns number of bytes printed (not including NULL) or
	 * number of bytes that would have been printed if more than would
	 * fit
	 */
	fulllen = snprintf(tmp, sizeof(tmp), "%d.%d.%d.%d",	 ap[0], ap[1], ap[2], ap[3]);
	if (fulllen >= (int)len) {
		return NULL;
	}

	bcopy(tmp, buf, fulllen + 1);

	return buf;
}

/*************************************************************************
 * inet_ntop
 *************************************************************************/
const char * inet_ntop(int af, const void *addr, char *buf, socklen_t len){

	return inet_ntop4(addr, buf, len);
}
/*************************************************************************
 * Handleset_addSocket
 * �����, ���� ����� ����� �����.
 *************************************************************************/
int
Handleset_waitReady(HandleSet self, unsigned int timeoutMs)
{
   int result;

   if ((self != NULL) && (self->maxHandle >= 0)) {
       struct timeval timeout;

       timeout.tv_sec = timeoutMs / 1000;
       timeout.tv_usec = (timeoutMs % 1000) * 1000;
       /*
        * ��� ������� ��������� ��-����������� ������� ����� ��������������� �������� select.
        * ������� select() �������� ��������� ��������� ���������� ������������ ������� (��� ������) �����.
        *
        * 1 �������� - ���������� ����������� ������������.
        * 2, 3 � 4   - ��������� ������� ������������ ����� ������ ������������, ������� ������� ���������,
        * ��������������, �� ���������� � [������, ������ � �� ������� �������������� ��������].
        * ���� ������� select() � �����������, ��� ���������� ����������, ���� ���� �� ���� �� ����������� �������
        * ����� � ���������� ��������������� ��������. � �������� ���������� ��������� ������� select() ����� ������� �������� �������,
        * �� ���������� �������� ��� ������ ���������� � ����� ������.
        *
        *
        *  select(����������, ������, ������, �������������� ��������, &timeout);
        */
       result = select(self->maxHandle + 1, &self->handles, NULL, NULL, &timeout);
   } else {
       result = -1;
   }

   return result;
}
/*************************************************************************
 * Socket_getPeerAddressStatic
 *
 *************************************************************************/
char*	Socket_getPeerAddressStatic(Socket self, char* peerAddressString)
{
    struct sockaddr_storage addr;
    socklen_t addrLen = sizeof(addr);

    getpeername(self->fd, (struct sockaddr*) &addr, &addrLen);

    char addrString[INET6_ADDRSTRLEN + 7];
    int port;

    bool isIPv6;

    if (addr.ss_family == AF_INET) {
        struct sockaddr_in* ipv4Addr = (struct sockaddr_in*) &addr;
        port = ntohs(ipv4Addr->sin_port);
        inet_ntop(AF_INET, &(ipv4Addr->sin_addr), addrString, INET_ADDRSTRLEN);
        isIPv6 = false;
    }
/*
    else if (addr.ss_family == AF_INET6) {
        struct sockaddr_in6* ipv6Addr = (struct sockaddr_in6*) &addr;
        port = ntohs(ipv6Addr->sin6_port);
        inet_ntop(AF_INET6, &(ipv6Addr->sin6_addr), addrString, INET6_ADDRSTRLEN);
        isIPv6 = true;
    }
*/
    else
        return NULL ;

    if (isIPv6)
        sprintf(peerAddressString, "[%s]:%i", addrString, port);
    else
        sprintf(peerAddressString, "%s:%i", addrString, port);

    return peerAddressString;
}
/*************************************************************************
 * Handleset_reset
 *
 *************************************************************************/
void	Handleset_reset(HandleSet self)
{
    FD_ZERO(&self->handles);
    self->maxHandle = -1;
}
/*************************************************************************
 * Handleset_addSocket
 * �������� ����� � ������������� ������ HandleSet
 *************************************************************************/
void
Handleset_addSocket(HandleSet self, const Socket sock)
{
   if (self != NULL && sock != NULL && sock->fd != -1) {
       FD_SET(sock->fd, &self->handles);			// ������� sock->fd � self->handles ��� ��������.
       if (sock->fd > self->maxHandle) {
           self->maxHandle = sock->fd;
       }
   }
}
/*************************************************************************
 * ServerSocket_accept
 *************************************************************************/
Socket
TcpSocket_create()
{
    Socket self = GLOBAL_MALLOC(sizeof(struct sSocket));

//   	USART_TRACE_GREEN("������� ������ ��� Socket: 0x%x\n",self);

    self->fd = -1;
//    self->connectTimeout = 5000;

    return self;
}
/*************************************************************************
 * activateTcpNoDelay
 * ������ � �������
 *************************************************************************/
static void	activateTcpNoDelay(Socket self)
{
    /* activate TCP_NODELAY option - packets will be sent immediately */
	// TCP_NODELAY - �� ����������� �������� ������. ���� ������ �������� ����������, �� ����������� �������� �����������. �������� ����� ���������� ��������.
    int flag = 1;
    setsockopt(self->fd, IPPROTO_TCP, TCP_NODELAY, (char *) &flag, sizeof(int));
}
/*************************************************************************
 * ServerSocket_accept
 * ���������, ���� �� ����������� � �������.
 *************************************************************************/
/* CHANGED TO MAKE NON-BLOCKING --> RETURNS NULL IF NO CONNECTION IS PENDING */
Socket	ServerSocket_accept(ServerSocket self)
{
    int fd;
    struct sockaddr_in remotehost;
    int  size;

    size = sizeof(remotehost);

    Socket conSocket = NULL;
//    fd = accept(self->fd, NULL, NULL );			// �������, ��������� �� �����������. alloc_socket() ������� � ���������� ����� ������ � ������� �������.
    fd = accept(self->fd,(struct sockaddr *)&remotehost, (socklen_t *)&size);

    if (lwip_getSocketErr(self->fd)>0){
    	// ������ ������
    }
    else
    if (fd >= 0) {								// ���� ���� �����������
    	USART_TRACE_GREEN("�����. c����:%u ������:0x%X->%u\n",fd,remotehost.sin_addr.s_addr,remotehost.sin_port);

        conSocket = TcpSocket_create();			// ������� ������
        conSocket->fd = fd;						// ������ �����

        activateTcpNoDelay(conSocket);			// ��������� ���������� ������ - TCP_NODELAY (�� ����������� �������� ������.)
    }

    return conSocket;							// ������ ���� �� �����������
}
/*************************************************************************
 * Handleset_new
 *************************************************************************/
HandleSet
Handleset_new(void)
{
   HandleSet result = (HandleSet) GLOBAL_MALLOC(sizeof(struct sHandleSet));

   if (result != NULL) {
       FD_ZERO(&result->handles);
       result->maxHandle = -1;
   }
   return result;
}
/*************************************************************************
 * Handleset_destroy
 *************************************************************************/
void
Handleset_destroy(HandleSet self)
{
   GLOBAL_FREEMEM(self);
}
/*************************************************************************
 * ServerSocket_listen
 * ������� �������� �����������
 * backLog = ������ ������� ������������ _���������_ ����������� � ������,
 * �� ���� �������������� (SYN - SYN,ACK - ACK),
 * �� ��� �� �������� �������� (established)
 *************************************************************************/
void
ServerSocket_listen(ServerSocket self)
{
    listen(self->fd, self->backLog);
}
/*************************************************************************
 * ServerSocket_setBacklog
 * ������ ������� ������������ _���������_ ����������� � ������
 *************************************************************************/
void
ServerSocket_setBacklog(ServerSocket self, int backlog)
{
    self->backLog = backlog;
}
/*************************************************************************
 * Socket_read
 * ����� recv() ���������� 0... ��� ����� �� ������, ��� ���� ������� 0 ����. ��� ��������, ��� ���������� �������.
 *
 * ��� ���� ��������� �������� ������ ������. recv() ��������� ���������� �� ������������ � ����� �������� �� ������������� �������� �������.
 *  �.�. ���� �������� � �������� �������� ��������� ��������, �������, ��� ����������� ����� ������,
 *  �� ������ ����� �� ������� Segmentation Fault. ���� ���� ����� �� ��������, �� � ��� � ���������
 *  �������� ������ ������������ ���������, ������� ���� ��� ������ ���������.
 *************************************************************************/
int
Socket_read(Socket self, uint8_t* buf, int size)
{
    assert(self != NULL);

    if (self->fd == -1)
        return -1;

    int read_bytes = recv(self->fd, buf, size, MSG_DONTWAIT);

    if (read_bytes == 0){
//		USART_TRACE_RED("���������� �������.\n");
        return -2;
    }else
    if (read_bytes < 0) {//(read_bytes == -1) {

        int error = errno;

    	USART_TRACE_RED("������ ������ �� ������ %i errno:%i\n",self->fd,error);


       switch (error) {

            case EAGAIN:		// EAGAIN	������ �������� ����������. ����� ����������� ��������� �����
                return 0;
            case EBADF:			// EBADF	������������ ���������� ����� ��� ������ WSAENOTSOCK
                return -1;

            default:
                return -1;
        }
    }else{

    	//		USART_TRACE_GREEN("�������� ������: %i\n",read_bytes);
    }

    return read_bytes;
}
/*************************************************************************
 * Socket_write
 *
 *  ���� ��������� ���, ��� send() ������� ����� �������, ��� len, �� ��� ���� ����� ������� send()
 *  ������� � �������� ������� ��������� ��������� �� ���������� ����� ������ � ��������������� �������
 *  ������� len. � ��� �� ��� ���, ���� ��� ������ �� ����� ������������ �������� � ��������� �������.
 *************************************************************************/
int
Socket_write(Socket self, uint8_t* buf, int size)
{
    if (self->fd == -1)
        return -1;

    int n = 0;
    while (n < size)
    {
      int sent = send(self->fd, buf + n, size - n, MSG_NOSIGNAL); // client? ��������, �� �� �������! :)
      if (sent < 0)
    	  return -1;	       // ���� ��������� ������, ����� �� ������ �������� ���������� �����
      n += sent;
    }

    return size;
    // MSG_NOSIGNAL - prevent send to signal SIGPIPE when peer unexpectedly closed the socket
//    return send(self->fd, buf, size, MSG_NOSIGNAL);
}
/*************************************************************************
 * Socket_write_PRPHSR
 * �������� ������ � ���������������.
 * ��������� PRP/HSR ����� �����.
 * PRP ������. � ����� ������� 6 ����
 * HSR �������. �������� ������� ������ ������ ����� ������� HSR �����
 * ������ ������������ ������ ��������� � ��� ���������
 *************************************************************************/
int	Socket_write_PRPHSR(Socket self, uint8_t* buf, int size)
{
	 int n=0;

    if (self->fd == -1) return -1;

#if defined (UseHSR_)
	uint8_t* selfBuf = GLOBAL_CALLOC(1,size + 6 );
	int globalN = 0;

	memcpy(selfBuf+globalN,buf,12);
	globalN +=12;

	IsoServer IsoServ = IedServer_getIsoServer(iedServer);

	if(IsoServer_getAppendHSR(IsoServ)){
		 Port_Toggle(LEDtst2);
		 PHY_Port2TxOff(ReseiveENABLE | LearningENABLE);
		 {
			uint8_t	buffer[6];

		 // ������������� � ��������
			HSRParameters 	HSRparam;
			HSRparam.hsrHead = HSRsuffix;
			HSRparam.hsrIdNet = LAN_Addr_0;

		    n = 0;
			buffer[n++] = HSRparam.hsrHead / 256;
			buffer[n++] = HSRparam.hsrHead % 256;

		    // ������ ������
			HSRparam.hsrSize = size - 12; //self->payloadStart + gooseLength - 22;

			uint16_t Netid = HSRparam.hsrIdNet<<12;
			Netid += HSRparam.hsrSize & 0xb111111111111;

			buffer[n++] = Netid / 256;
			buffer[n++] = Netid % 256;

			IsoServer_HSRSeqNum_increase(IsoServ);
			HSRparam.hsrSeqNum =  IsoServer_gethsrSeqNum(IsoServ);

			buffer[n++] = HSRparam.hsrSeqNum / 256;
			buffer[n++] = HSRparam.hsrSeqNum % 256;

			memcpy(selfBuf + globalN, buffer, 6);
			globalN +=6;

			memcpy(selfBuf + globalN, buf+12, size-12);

			n = 0;
			int selfsize = size + 6;
		    while (n < selfsize)
		    {
		    	int sent = send(self->fd, selfBuf + n, selfsize - n, MSG_NOSIGNAL); 	// client? ��������, �� �� �������! :)
		    	if (sent < 0)	{ GLOBAL_FREEMEM(selfBuf); return -1;	}       // ���� ��������� ������, ����� �� ������ �������� ���������� �����
			 	n += sent;
		    }

		 }
		 vTaskDelay(1);
		 Port_Toggle(LEDtst2);
	     PHY_Port2TxOn(ReseiveENABLE | LearningENABLE);
		 PHY_Port1TxOff(ReseiveENABLE | LearningENABLE);
/*
		 // ������������� � ��������
		 out[_Addr_IdNet] =  out[_Addr_IdNet] & 0x0F;
		 out[_Addr_IdNet] |= LAN_Addr_1;
		 Goose_output(out, packetSize);
*/
		 vTaskDelay(1);
		 Port_Toggle(LEDtst2);
	     PHY_Port1TxOn(ReseiveENABLE | LearningENABLE);

	}
    GLOBAL_FREEMEM(selfBuf);
#endif

#if defined (UsePRP)
	IsoServer IsoServ = IedServer_getIsoServer(iedServer);

	if(IsoServer_getAppendPRP(IsoServ)){
		 int	packetSize = size;
		 char* out = buf;
		 int IdNetPRP = packetSize + _Addr_IdNetPRP;

		 Port_Toggle(LEDtst2);
		 PHY_Port2TxOff(ReseiveDISABLE | LearningENABLE);
//		 IsoServer_setPHYTransmitport(PHY_PORT_1);
		 out[IdNetPRP] =  out[IdNetPRP] & 0x0F;
		 out[IdNetPRP] |= LAN_Addr_0;
		 Goose_output(out, packetSize);
		 vTaskDelay(1);
		 Port_Toggle(LEDtst2);
	     PHY_Port2TxOn(ReseiveDISABLE | LearningENABLE);
		 PHY_Port1TxOff(ReseiveDISABLE | LearningENABLE);
		 out[IdNetPRP] =  out[IdNetPRP] & 0x0F;
		 out[IdNetPRP] |= LAN_Addr_1;
		 Goose_output(out, packetSize);
		 vTaskDelay(1);
		 Port_Toggle(LEDtst2);
	     PHY_Port1TxOn(ReseiveDISABLE | LearningENABLE);

    }
#endif

#if !defined (UsePRP) && !defined (UseHSR)
    while (n < size)
    {
      int sent = send(self->fd, buf + n, size - n, MSG_NOSIGNAL); // client? ��������, �� �� �������! :)
      if (sent < 0)	return -1;	       // ���� ��������� ������, ����� �� ������ �������� ���������� �����
      n += sent;
    }
#endif
    return size;
}
/*************************************************************************
 * Socket_getPeerAddress
 * ������� ����� ��� �������� � ��������� ���� IP � ���� �������.
 *************************************************************************/
char*	Socket_getPeerAddress(Socket self){

//    struct sockaddr_storage addr;
	struct sockaddr addr;
    socklen_t addrLen = sizeof(addr);

    getpeername(self->fd, (struct sockaddr*) &addr, &addrLen);

    char addrString[INET6_ADDRSTRLEN + 7];
    int port;

    bool isIPv6;

//    if (addr.ss_family == AF_INET) {
    if (addr.sa_family == AF_INET) {
        struct sockaddr_in* ipv4Addr = (struct sockaddr_in*) &addr;
        port = ntohs(ipv4Addr->sin_port);
        inet_ntop(AF_INET, &(ipv4Addr->sin_addr), addrString, INET_ADDRSTRLEN);
        isIPv6 = false;
    }
    else
        return NULL ;

    char* clientConnection = GLOBAL_MALLOC(strlen(addrString) + 9);


    if (isIPv6)
        sprintf(clientConnection, "[%s]:%i", addrString, port);
    else
        sprintf(clientConnection, "%s:%i", addrString, port);

    return clientConnection;
}

/*************************************************************************
 * prepareServerAddress
 *************************************************************************/
bool
prepareServerAddress(const char* address, int port, struct sockaddr_in* sockaddr)
{

	memset((char *) sockaddr , 0, sizeof(struct sockaddr_in));

	if (address != NULL) {
		struct hostent *server;
		server = gethostbyname(address);

		if (server == NULL) return false;

		memcpy((char *) &sockaddr->sin_addr.s_addr, (char *) server->h_addr, server->h_length);
	}
	else
		sockaddr->sin_addr.s_addr = htonl(INADDR_ANY);

    sockaddr->sin_family = AF_INET;
    sockaddr->sin_port = htons(port);

    return true;
}

/*************************************************************************
 * setSocketNonBlocking
 *************************************************************************/
static void	setSocketNonBlocking(Socket self)
{
    int flags = fcntl(self->fd, F_GETFL, 0);
    fcntl(self->fd, F_SETFL, flags | O_NONBLOCK);
}
/*************************************************************************
 * activateKeepAlive
 * ������������� ����������� ���������� ����������
 *************************************************************************/
//TODO: ����������� ������.
static void	activateKeepAlive(int sd)
{
 int ret=0;
#if defined SO_KEEPALIVE
    int optval;
    socklen_t optlen = sizeof(optval);

    optval = CONFIG_TCP_KEEPALIVE_IDLE;
    ret = setsockopt(sd, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen);
//    USART_TRACE_Yellow("SOL_SOCKET SO_KEEPALIVE: %u\n",ret);

    ret = 0;
    optval = 1;
    ret = setsockopt(sd, SOL_SOCKET, SO_NOSIGPIPE, &optval, optlen);						// ��� �����������
//    USART_TRACE_Yellow("SOL_SOCKET SO_NOSIGPIPE: %u\n",ret);

#if defined TCP_KEEPCNT
    ret = 0;
    optval = CONFIG_TCP_KEEPALIVE_INTERVAL;
    ret = setsockopt(sd, IPPROTO_TCP, TCP_KEEPINTVL, &optval, optlen);
//    USART_TRACE_Yellow("IPPROTO_TCP TCP_KEEPINTVL: %u\n",ret);

    ret = 0;
    optval = CONFIG_TCP_KEEPALIVE_CNT;
    ret = setsockopt(sd, IPPROTO_TCP, TCP_KEEPCNT, &optval, optlen);
//    USART_TRACE_Yellow("IPPROTO_TCP TCP_KEEPCNT: %u\n",ret);

#endif // TCP_KEEPCNT

#endif // SO_KEEPALIVE
}
/*************************************************************************
 * TcpServerSocket_create
 * ������� TCP �����, �������� ����. �� ���� �� ����� �������.
 *************************************************************************/
ServerSocket		TcpServerSocket_create(const char* address, int port)
{
    ServerSocket serverSocket = NULL;

    int fd;


    // �������� TCP �����, ���� �� �������� ������ 0
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) >= 0) {
        struct sockaddr_in serverAddress,serverAddressHTTP;

        if (!prepareServerAddress(address, port, &serverAddress)) {
            close(fd);
            return NULL;
        }

        int optionReuseAddr = 1;
        // SO_REUSEADDR - ��������� ��������� ������������� ��������� ������� (���� ������ ����������� �������������� ������������ ����������). �������� ����� ���������� ��������.
        // ��� ���������� ��������� �� ������ ���������� �������, ��������� level ������������� �������� SOL_SOCKET.
        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *) &optionReuseAddr, sizeof(int));

        int optionTimeOut = sockTimeOut;
        setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (char *) &optionTimeOut, sizeof(int));		// ������� ��� netconn


        if (bind(fd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) >= 0) {		// �������� ���� � ������

			serverSocket = GLOBAL_MALLOC(sizeof(struct sServerSocket));
            serverSocket->fd = fd;
            serverSocket->backLog = 0;
        }
        else {
        	USART_TRACE_RED("������ �������� �����.\n");
            close(fd);
            return NULL ;
        }

#if CONFIG_ACTIVATE_TCP_KEEPALIVE == 1
        activateKeepAlive(fd);								// ������������� ����������� ���������� ����������
#endif

 //       setSocketNonBlocking((Socket) serverSocket);		// �� ����������� �����
    }

    return serverSocket;
}
/*************************************************************************
 * UDPServerSocket_create
 * ������� UDP �����, �������� ����.
 *************************************************************************/
ServerSocket	UDPServerSocket_create(const char* address, int port)
{
    ServerSocket serverSocket = NULL;

    int fd;

    // �������� �����, ���� �� �������� ������ 0
    if ((fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) >= 0) {
        struct sockaddr_in serverAddress;
        if (!prepareServerAddress(address, port, &serverAddress)) {
            close(fd);
            return NULL;
        }

        if (bind(fd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) >= 0) {		// �������� ���� � ������

			serverSocket = GLOBAL_MALLOC(sizeof(struct sServerSocket));
            serverSocket->fd = fd;
            serverSocket->backLog = 0;
        }
        else {
        	USART_TRACE_RED("������ �������� �����.\n");
            close(fd);
            return NULL ;
        }

        int optionReuseAddr = 1;

        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *) &optionReuseAddr, sizeof(int));
        int optionTimeOut = sockTimeOut;
        setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (char *) &optionTimeOut, sizeof(int));		// ������� ��� netconn

    }

    return serverSocket;
}
/*************************************************************************
 * UDPClientSocket_create
 * ������� UDP �����, �������� ����.
 *************************************************************************/
ServerSocket	UDPClientSocket_create(const char* address, int port)
{
    ServerSocket serverSocket = NULL;

    int fd;

    // �������� �����, ���� �� �������� ������ 0
    if ((fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) >= 0) {
        struct sockaddr_in serverAddress;
        if (!prepareServerAddress(address, port, &serverAddress)) {
            close(fd);
            return NULL;
        }

        if (bind(fd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) >= 0) {		// �������� ���� � ������

			serverSocket = GLOBAL_MALLOC(sizeof(struct sServerSocket));
            serverSocket->fd = fd;
            serverSocket->backLog = 0;
        }
        else {
        	USART_TRACE_RED("������ �������� �����.\n");
            close(fd);
            return NULL ;
        }

        int optionReuseAddr = 1;

        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *) &optionReuseAddr, sizeof(int));
        int optionTimeOut = sockTimeOut;
        setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (char *) &optionTimeOut, sizeof(int));		// ������� ��� netconn

    }

    return serverSocket;
}
/*************************************************************************
 * closeAndShutdownSocket
 *************************************************************************/
static void
closeAndShutdownSocket(int socketFd)
{
    if (socketFd != -1) {

        if (DEBUG_SOCKET){
        	USART_TRACE_BLUE("call shutdown for socket: %i\n\n", socketFd);
        }

        // shutdown is required to unblock read or accept in another thread!
        shutdown(socketFd, SHUT_RDWR);					// shutdown �� ����������� ����������, � ������ ��������������

        close(socketFd);
    }
}
/*************************************************************************
 * ServerSocket_destroy
 *************************************************************************/
void
ServerSocket_destroy(ServerSocket self)
{
	if (self == NULL)	return;

    int fd = self->fd;
    self->fd = -1;
    closeAndShutdownSocket(fd);

    GLOBAL_FREEMEM(self);
}
/*************************************************************************
 * Socket_destroy
 *************************************************************************/
void
Socket_destroy(Socket self)
{
    int fd = self->fd;

   	USART_TRACE_BLUE("ISO_SERVER: ������� Socket:%u (0x%x)\n",fd,self);

    self->fd = -1;

    closeAndShutdownSocket(fd);		//

    //Thread_sleep(10);				// ����� ����� �� ����

    GLOBAL_FREEMEM(self);
}

/*************************************************************************
 * GetSocket_num
 *************************************************************************/
int	GetSocket_num(Socket self)
{
    return self->fd;
}
