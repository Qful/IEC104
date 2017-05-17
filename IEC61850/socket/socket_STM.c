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
 * ждать, пока сокет будет готов.
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
        * Для поверки состояния не-блокирующих сокетов можно воспользоваться функцией select.
        * Функция select() способна проверять состояние нескольких дескрипторов сокетов (или файлов) сразу.
        *
        * 1 параметр - количество проверяемых дескрипторов.
        * 2, 3 и 4   - параметры функции представляют собой наборы дескрипторов, которые следует проверять,
        * соответственно, на готовность к [чтению, записи и на наличие исключительных ситуаций].
        * Сама функция select() – блокирующая, она возвращает управление, если хотя бы один из проверяемых сокетов
        * готов к выполнению соответствующей операции. В качестве последнего параметра функции select() можно указать интервал времени,
        * по прошествии которого она вернет управление в любом случае.
        *
        *
        *  select(количество, чтению, записи, исключительных ситуаций, &timeout);
        */
       result = select(self->maxHandle + 1, &self->handles, NULL, NULL, &timeout);
   } else {
       result = -1;
   }

   return result;
}
/*************************************************************************
 * Handleset_addSocket
 * добавить сокет к существующему набору HandleSet
 *************************************************************************/
void
Handleset_addSocket(HandleSet self, const Socket sock)
{
   if (self != NULL && sock != NULL && sock->fd != -1) {
       FD_SET(sock->fd, &self->handles);			// добавим sock->fd в self->handles для проверки.
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

//   	USART_TRACE_GREEN("Выделил память для Socket: 0x%x\n",self);

    self->fd = -1;
//    self->connectTimeout = 5000;

    return self;
}
/*************************************************************************
 * activateTcpNoDelay
 * только в линуксе
 *************************************************************************/
static void	activateTcpNoDelay(Socket self)
{
    /* activate TCP_NODELAY option - packets will be sent immediately */
	// TCP_NODELAY - Не задерживать отправку данных. Если данный параметр установлен, то отключается алгоритм буферизации. Параметр имеет логическое значение.
    int flag = 1;
    setsockopt(self->fd, IPPROTO_TCP, TCP_NODELAY, (char *) &flag, sizeof(int));
}
/*************************************************************************
 * ServerSocket_accept
 * проверяем, было ли подключение к серверу.
 *************************************************************************/
/* CHANGED TO MAKE NON-BLOCKING --> RETURNS NULL IF NO CONNECTION IS PENDING */
Socket	ServerSocket_accept(ServerSocket self)
{
    int fd;
    struct sockaddr_in remotehost;
    int  size;

    size = sizeof(remotehost);

    Socket conSocket = NULL;
//    fd = accept(self->fd, NULL, NULL );			// Смотрим, произошло ли подключение. alloc_socket() создает и возвращает номер сокета в массиве сокетов.
    fd = accept(self->fd,(struct sockaddr *)&remotehost, (socklen_t *)&size);

    if (fd >= 0) {								// если было подключение
    	USART_TRACE_GREEN("Подключение к серверу. Сокет: %u\n",fd);

        conSocket = TcpSocket_create();			// выделим память
        conSocket->fd = fd;						// укажем номер

        activateTcpNoDelay(conSocket);			// Установка параметров сокета - TCP_NODELAY (Не задерживать отправку данных.)
    }

    return conSocket;							// вернем инфу по подключении
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
 * Слушаем входящие подключения
 * backLog = размер очереди одновременно _ожидающих_ подключений к сокету,
 * то есть инициированных (SYN - SYN,ACK - ACK),
 * но еще не принятых сервером (established)
 *************************************************************************/
void
ServerSocket_listen(ServerSocket self)
{
    listen(self->fd, self->backLog);
}
/*************************************************************************
 * ServerSocket_setBacklog
 * размер очереди одновременно _ожидающих_ подключений к сокету
 *************************************************************************/
void
ServerSocket_setBacklog(ServerSocket self, int backlog)
{
    self->backLog = backlog;
}
/*************************************************************************
 * Socket_read
 * когда recv() возвращает 0... Это вовсе не значит, что было принято 0 байт. Это означает, что соединение закрыто.
 *
 * Еще одно замечание касается буфера приема. recv() полностью полагается на программиста в части слежения за правильностью размеров буферов.
 *  Т.е. если передать в качестве третьего параметра значение, большее, чем фактическая длина буфера,
 *  то скорее всего мы получим Segmentation Fault. Даже если этого не случится, то у нас в программе
 *  появится «бомба замедленного действия», которая рано или поздно «бабахнет».
 *************************************************************************/
int
Socket_read(Socket self, uint8_t* buf, int size)
{
    assert(self != NULL);

    if (self->fd == -1)
        return -1;

    int read_bytes = recv(self->fd, buf, size, MSG_DONTWAIT);

    if (read_bytes == 0){
//		USART_TRACE_RED("Соединение закрыто.\n");
        return -2;
    }else
    if (read_bytes < 0) {//(read_bytes == -1) {

        int error = errno;

    	USART_TRACE_RED("ошибка чтения из сокета %i errno:%i\n",self->fd,error);


       switch (error) {

            case EAGAIN:		// EAGAIN	Ресурс временно недоступен. Можно попробовать повторить вызов
                return 0;
            case EBADF:			// EBADF	Неправильный дескриптор файла это аналог WSAENOTSOCK
                return -1;

            default:
                return -1;
        }
    }else{

    	//		USART_TRACE_GREEN("прочитал данные: %i\n",read_bytes);
    }

    return read_bytes;
}
/*************************************************************************
 * Socket_write
 *
 *  Если случилось так, что send() вернула число меньшее, чем len, то нам надо снова вызвать send()
 *  передав в качестве второго параметра указатель на оставшуюся часть данных и соответствующим образом
 *  изменив len. И так до тех пор, пока все данные не будут благополучно помещены в исходящую очередь.
 *************************************************************************/
int
Socket_write(Socket self, uint8_t* buf, int size)
{
    if (self->fd == -1)
        return -1;

    int n = 0;
    while (n < size)
    {
      int sent = send(self->fd, buf + n, size - n, MSG_NOSIGNAL); // client? допустим, мы на сервере! :)
      if (sent < 0)
    	  return -1;	       // если произошла ошибка, здесь мы должны прервать выполнение цикла
      n += sent;
    }

    return size;
    // MSG_NOSIGNAL - prevent send to signal SIGPIPE when peer unexpectedly closed the socket
//    return send(self->fd, buf, size, MSG_NOSIGNAL);
}

/*************************************************************************
 * Socket_getPeerAddress
 * создает буфер для хранения в строковом виде IP и порт клиента.
 *************************************************************************/
#define INET6_ADDRSTRLEN	24
#define INET_ADDRSTRLEN		24
/*char*	Socket_getPeerAddress(struct netconn *conn)
{
    //struct sockaddr_storage addr;
    ip_addr_t 	addr;
    uint16_t	port;
    uint8_t		ip0,ip1,ip2,ip3;

#ifdef	UseOSmem
    char* clientConnection = pvPortMalloc(24);
#else
    char* clientConnection = malloc(24);
#endif
    USART_TRACE_MAGENTA("Socket_getPeerAddress адрес:%X размер 24b\n",(unsigned int)clientConnection);

    netconn_peer(conn,&addr,&port);

    ip0 = addr.addr & 0xff;
    ip1 = (addr.addr>>8) & 0xff;
    ip2 = (addr.addr>>16) & 0xff;
    ip3 = (addr.addr>>24) & 0xff;

    sprintf(clientConnection, "%d.%d.%d.%d[%i]",ip0, ip1, ip2, ip3, port);
    USART_TRACE("PeerAddress: IP:%d.%d.%d.%d[%i]\n",ip0, ip1, ip2, ip3,port);

   return clientConnection;
}
*/
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
 * искусственное поддержание активности соединения
 *************************************************************************/
//TODO: реализовать фунцию.
static void	activateKeepAlive(int sd)
{

#if defined SO_KEEPALIVE
    int optval;
    socklen_t optlen = sizeof(optval);

    optval = CONFIG_TCP_KEEPALIVE_IDLE;
    setsockopt(sd, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen);
    optval = 1;
    setsockopt(sd, SOL_SOCKET, SO_NOSIGPIPE, &optval, optlen);						// нет обработчика

#if defined TCP_KEEPCNT
    optval = CONFIG_TCP_KEEPALIVE_INTERVAL;
    setsockopt(sd, IPPROTO_TCP, TCP_KEEPINTVL, &optval, optlen);

    optval = CONFIG_TCP_KEEPALIVE_CNT;
    setsockopt(sd, IPPROTO_TCP, TCP_KEEPCNT, &optval, optlen);
#endif // TCP_KEEPCNT

#endif // SO_KEEPALIVE
}
/*************************************************************************
 * TcpServerSocket_create
 * Создаем TCP сокет, настроим порт. Но пока не будем слушать.
 *************************************************************************/
ServerSocket		TcpServerSocket_create(const char* address, int port)
{
    ServerSocket serverSocket = NULL;

    int fd;


    // создадим TCP сокет, если не создался вернем 0
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) >= 0) {
        struct sockaddr_in serverAddress,serverAddressHTTP;

        if (!prepareServerAddress(address, port, &serverAddress)) {
            close(fd);
            return NULL;
        }

        int optionReuseAddr = 1;
        // SO_REUSEADDR - Разрешает повторное использование локальных адресов (если данная возможность поддерживается используемым протоколом). Параметр имеет логическое значение.
        // Для присвоения параметра на уровне библиотеки сокетов, аргументу level присваивается значение SOL_SOCKET.
        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *) &optionReuseAddr, sizeof(int));

        int optionTimeOut = sockTimeOut;
        setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (char *) &optionTimeOut, sizeof(int));		// таймаут для netconn


        if (bind(fd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) >= 0) {		// привяжем порт к адресу

			serverSocket = GLOBAL_MALLOC(sizeof(struct sServerSocket));
            serverSocket->fd = fd;
            serverSocket->backLog = 0;
        }
        else {
        	USART_TRACE_RED("ошибка открытия порта.\n");
            close(fd);
            return NULL ;
        }

#if CONFIG_ACTIVATE_TCP_KEEPALIVE == 1
        activateKeepAlive(fd);								// искусственное поддержание активности соединения
#endif

 //       setSocketNonBlocking((Socket) serverSocket);		// не блокировать сокет
    }

    return serverSocket;
}

/*************************************************************************
 * UDPClientSocket_create
 * Создаем UDP сокет, настроим порт.
 *************************************************************************/
ServerSocket	UDPClientSocket_create(const char* address, int port)
{
    ServerSocket serverSocket = NULL;

    int fd;

    // создадим сокет, если не создался вернем 0
    if ((fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) >= 0) {
        struct sockaddr_in serverAddress;
        if (!prepareServerAddress(address, port, &serverAddress)) {
            close(fd);
            return NULL;
        }

        if (bind(fd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) >= 0) {		// привяжем порт к адресу

			serverSocket = GLOBAL_MALLOC(sizeof(struct sServerSocket));
            serverSocket->fd = fd;
            serverSocket->backLog = 0;
        }
        else {
        	USART_TRACE_RED("ошибка открытия порта.\n");
            close(fd);
            return NULL ;
        }

        int optionReuseAddr = 1;

        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *) &optionReuseAddr, sizeof(int));
        int optionTimeOut = sockTimeOut;
        setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (char *) &optionTimeOut, sizeof(int));		// таймаут для netconn

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
        shutdown(socketFd, SHUT_RDWR);					// shutdown не освобождает дескриптор, а только перекомфигурит

        close(socketFd);
    }
}
/*************************************************************************
 * ServerSocket_destroy
 *************************************************************************/
void
ServerSocket_destroy(ServerSocket self)
{
    int fd = self->fd;

 //  	USART_TRACE_BLUE("ISO_SERVER: Закрыли ServerSocket:%u (0x%x)\n",fd,self);

    self->fd = -1;

    closeAndShutdownSocket(fd);

//    Thread_sleep(10);

    GLOBAL_FREEMEM(self);
}
/*************************************************************************
 * Socket_destroy
 *************************************************************************/
void
Socket_destroy(Socket self)
{
    int fd = self->fd;

   	USART_TRACE_BLUE("ISO_SERVER: Закрыли Socket:%u (0x%x)\n",fd,self);

    self->fd = -1;

    closeAndShutdownSocket(fd);

 //   Thread_sleep(10);				// зачем пауза не знаю

    GLOBAL_FREEMEM(self);
}

/*************************************************************************
 * GetSocket_num
 *************************************************************************/
int	GetSocket_num(Socket self)
{
    return self->fd;
}
