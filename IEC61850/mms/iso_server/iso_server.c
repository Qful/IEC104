/*
 *  iso_server.c
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

#include "libiec61850_platform_includes.h"

#include "stack_config.h"

#include "main.h"

#include "httpServer.h"
#include "hal_socket.h"

#ifndef DEBUG_ISO_SERVER
#ifdef DEBUG
#define DEBUG_ISO_SERVER 1
#else
#define DEBUG_ISO_SERVER 0
#endif /*DEBUG */
#endif /* DEBUG_ISO_SERVER */

#include "mms_server_connection.h"

#include "hal_thread.h"

#include "iso_server.h"

#include "iso_server_private.h"

#include "sntpclient.h"

#include "modbus.h"

#ifndef CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS
#define CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS 5
#endif

#define SSH_PORT			SSH_Port
#define HTTP_PORT			HTTP_Port
#define TCP_PORT 			IEC850_Port
#define SECURE_TCP_PORT 	3782
#define BACKLOG 			5			// ожидающие подключение.  похоже можно только = 1 в lwIP

extern uint8_t		SNTP_IP_ADDR[4];
extern int16_t		SNTP_Period;

Socket 				connectionSocket,connectionSocketHTTP,connectionSocketSSH=0;
extern 	Socket		SocketSSH;
uint64_t 			SSHTimer;				// таймер отладочного порта
#define				_10min			100 * 600 *10

extern 	xQueueHandle 	Rd_SysNoteQueue;		// очередь для запросов журналу системы
uint64_t 	lastSynchTimeNTP = 0;
bool 		resynchNTP_ready = true;

struct sIsoServer {
    IsoServerState state;
    ConnectionIndicationHandler connectionHandler;
    void* connectionHandlerParameter;

    AcseAuthenticator authenticator;
    void* authenticatorParameter;

#if (CONFIG_MMS_THREADLESS_STACK != 1)
    Thread serverThread;
#endif

    PhyPortsMode 			PHYPortsMode;			// режим работы порта
    PhyPortsForTransmit		PHYTransmitport;		// текущие открытые порты для передачи. Нужны для резервирования и фитрации

    bool 					AppendPRP;			// добавлять резервирование PRP
    uint16_t 				prpSeqNum;			//

    bool 					AppendHSR;			// добавлять резервирование HSR
    uint16_t 				hsrSeqNum;


    Socket 			NTPSocket;
    int 			NTPPort;
    uint64_t 		NTPPeriod;

    ServerSocket	HTTPserverSocket;
    int 			HTTPPort;

    ServerSocket 	SSHserverSocket;
    int 			SSHPort;
    bool			SSHConnect;				// статус подключения на порт

    ServerSocket 	TFTPserverSocket;
    int 			TFTPPort;

    ServerSocket 	FTPserverSocket;
    int 			FTPPort;

    ServerSocket	serverSocket;
    int 			tcpPort;

    char* 		localIpAddress;
    char* 		netMask;
    char* 		gateway;

#if (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1)
    LinkedList openClientConnections;
#else
    IsoConnection* openClientConnections;
#endif /* (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1) */

#if (CONFIG_MMS_THREADLESS_STACK != 1)
    Semaphore userLock;
#endif

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    Semaphore openClientConnectionsMutex; /* mutex for openClientConnections list */
    Semaphore connectionCounterMutex;
#endif

    int connectionCounter;
};

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
static inline void
lockClientConnections(IsoServer self)
{
    Semaphore_wait(self->openClientConnectionsMutex);
}

static inline void
unlockClientConnections(IsoServer self)
{
    Semaphore_post(self->openClientConnectionsMutex);
}
#endif /* (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1) */

static void
addClientConnection(IsoServer self, IsoConnection connection)
{

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    Semaphore_wait(self->connectionCounterMutex);
#endif

    self->connectionCounter++;
    if (DEBUG_ISO_SERVER) {
    	USART_TRACE_GREEN("IsoServer: Инкрементим счетчик клиентов до %i!\n", self->connectionCounter);
    }

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    lockClientConnections(self);
#endif

#if (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1)
    LinkedList_add(self->openClientConnections, connection);
#else
    int i;

    for (i = 0; i < CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS; i++) {
        if (self->openClientConnections[i] == NULL) {
            self->openClientConnections[i] = connection;

            if (DEBUG_ISO_SERVER){
            	USART_TRACE_GREEN("ISO_SERVER: добавили соединение (%p) self->openClientConnections[%i]\n", connection, i);
            }

            break;
        }
    }
#endif

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    unlockClientConnections(self);
#endif

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    Semaphore_post(self->connectionCounterMutex);
#endif

}

/*****************************************************************************
 *
 * @param self
 * @param connection
 */
static void
removeClientConnection(IsoServer self, IsoConnection connection)
{

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    lockClientConnections(self);
#endif

#if (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1)


#if (CONFIG_MMS_SINGLE_THREADED == 0)

    LinkedList_remove(self->openClientConnections, connection);

#endif /* (CONFIG_MMS_SINGLE_THREADED == 0) */


#else

    int i;

    for (i = 0; i < CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS; i++) {
        if (self->openClientConnections[i] == connection) {

            if (DEBUG_ISO_SERVER){
            	USART_TRACE_BLUE("ISO_SERVER: removed connection (%p) index:%i\n", connection, i);
            }

            self->openClientConnections[i] = NULL;
            break;
        }
    }
#endif /* (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1) */

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    unlockClientConnections(self);
#endif
}

static void
closeAllOpenClientConnections(IsoServer self)
{

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    lockClientConnections(self);
#endif

#if (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1)

    LinkedList openConnection = LinkedList_getNext(self->openClientConnections);
    while (openConnection != NULL) {
        IsoConnection isoConnection = (IsoConnection) openConnection->data;

        IsoConnection_close(isoConnection);

#if (CONFIG_MMS_SINGLE_THREADED == 1)
            /* if CONFIG_MMS_SINGLE_THREADED == 0 connection instance will be destroyed by connection thread. */
        IsoConnection_destroy(isoConnection);
#endif

        openConnection = LinkedList_getNext(openConnection);
    }

#if (CONFIG_MMS_SINGLE_THREADED == 1)
    LinkedList_destroyStatic(self->openClientConnections);
    self->openClientConnections = NULL;
#endif

#else
    int i;

    for (i = 0; i < CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS; i++) {
        if (self->openClientConnections[i] != NULL) {

            IsoConnection_close(self->openClientConnections[i]);

#if (CONFIG_MMS_SINGLE_THREADED == 1)
            /* if CONFIG_MMS_SINGLE_THREADED == 0 connection instance will be destroyed by connection thread. */
            IsoConnection_destroy(self->openClientConnections[i]);
#endif

        }
    }
#endif /* (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1) */

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    unlockClientConnections(self);
#endif

}

static void
handleClientConnections(IsoServer self)
{
#if (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1)

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    lockClientConnections(self);
#endif

    LinkedList openConnection = LinkedList_getNext(self->openClientConnections);
    LinkedList lastConnection = self->openClientConnections;

    while (openConnection != NULL) {
        IsoConnection isoConnection = (IsoConnection) openConnection->data;

        if (IsoConnection_isRunning(isoConnection))
            IsoConnection_handleTcpConnection(isoConnection);
        else {
            IsoConnection_destroy(isoConnection);

            lastConnection->next = openConnection->next;

            GLOBAL_FREEMEM(openConnection);
        }

        openConnection = LinkedList_getNext(openConnection);
    }

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    unlockClientConnections(self);
#endif

#else

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    lockClientConnections(self);
#endif

    int i;

    for (i = 0; i < CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS; i++) {
        if (self->openClientConnections[i] != NULL) {
            if (IsoConnection_isRunning(self->openClientConnections[i])) {

                IsoConnection_handleTcpConnection(self->openClientConnections[i]);			// если это соединение уже открыто, то парсим и отвечаем. Сюда надо попадать не только когда коннектится новый клиент.
            }
            else {
            	USART_TRACE_RED("handleClientConnections:IsoConnection_destroy: %u\n",i);
                IsoConnection_destroy(self->openClientConnections[i]);						// иначе закрываем
                self->openClientConnections[i] = NULL;
            }

        }
    }

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    unlockClientConnections(self);
#endif

#endif /* (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1) */
}
/*****************************************************************************************************
 * setupIsoServer
 * настройка и запуск сервера
 *****************************************************************************************************/
static bool		setupIsoServer(IsoServer self)
{
    bool success = true;

    self->serverSocket = (ServerSocket) TcpServerSocket_create(self->localIpAddress, self->tcpPort);			// создали TCP сокет назначили IP и открыли порт
  	USART_TRACE_GREEN("ISO_SERVER: localIpAddress: %s tcpPort: %u\n", self->localIpAddress,(int)self->tcpPort);
    if (self->serverSocket == NULL) {
        self->state = ISO_SVR_STATE_ERROR;
        success = false;
        goto exit_function;
    }
    ServerSocket_setBacklog((ServerSocket) self->serverSocket, BACKLOG);			// установим очередь ожидающих
    ServerSocket_listen((ServerSocket) self->serverSocket);							// Начинаем слушать входящие подключения

    //---------
/*
    self->HTTPserverSocket = (Socket) TcpServerSocket_create(self->localIpAddress, HTTP_PORT);	//self->SecurePort
   	USART_TRACE_GREEN("ISO_SERVER: localIpAddress: %s tcpPort: %u\n", self->localIpAddress,(int)HTTP_PORT);
    ServerSocket_setBacklog((ServerSocket) self->HTTPserverSocket, BACKLOG);		// установим очередь ожидающих
    ServerSocket_listen((ServerSocket) self->HTTPserverSocket);					// Начинаем слушать входящие подключения
*/
    //---------
/*
    self->SSHserverSocket = (ServerSocket) TcpServerSocket_create(self->localIpAddress, SSH_PORT);	//self->SecurePort
   	USART_TRACE_GREEN("ISO_SERVER: localIpAddress: %s SSHPort: %u\n", self->localIpAddress,(int)SSH_PORT);
    ServerSocket_setBacklog((ServerSocket) self->SSHserverSocket, BACKLOG);		// установим очередь ожидающих
    ServerSocket_listen((ServerSocket) self->SSHserverSocket);					// Начинаем слушать входящие подключения
*/
    //---------


    self->state = ISO_SVR_STATE_RUNNING;


	if (lastSynchTimeNTP == 0) lastSynchTimeNTP = Hal_getTimeInMs();		// если первый заход, то засинронизируем часы

    self->NTPPeriod = stNTPPeriod;
    self->NTPPort = NTP_PORT;
    self->NTPSocket = (Socket) UDPClientSocket_create (self->localIpAddress, 0);	// открываем порт для приема NTP пакетов от сервера NTP

//   	USART_TRACE_GREEN("ISO_SERVER: SNTPServer: %s Port: %u\n", &NTP_IP,(int)NTP_PORT);

#if (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS != -1)

    	USART_TRACE_BLUE("ISO_SERVER: Предел сервера %i соединения.\n", (int) CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS);
#endif

exit_function:
    return success;
}


#if (CONFIG_MMS_THREADLESS_STACK == 0)
// used by single and multi-threaded versions
static void
handleIsoConnections(IsoServer self)
{
    Socket connectionSocket;

    if ((connectionSocket = ServerSocket_accept((ServerSocket) self->serverSocket)) != NULL) {

#if (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS != -1)
        if (private_IsoServer_getConnectionCounter(self) >= CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS) {
            if (DEBUG_ISO_SERVER)
                printf("ISO_SERVER: maximum number of connections reached -> reject connection attempt.\n");

            Socket_destroy(connectionSocket);

#if (CONFIG_MMS_SINGLE_THREADED == 1)
            handleClientConnections(self);
#endif

            return;
        }
#endif

        IsoConnection isoConnection = IsoConnection_create(connectionSocket, self);

        addClientConnection(self, isoConnection);

        self->connectionHandler(ISO_CONNECTION_OPENED, self->connectionHandlerParameter, isoConnection);

    }

#if (CONFIG_MMS_SINGLE_THREADED == 1)
    handleClientConnections(self);
#endif
}
#endif /* (CONFIG_MMS_THREADLESS_STACK == 0) */

/**********************************************************************************************
 *
 * used by non-threaded version
 ***********************************************************************************************/
static void		handleIsoConnectionsThreadless(IsoServer self)
{
    if ((connectionSocket = ServerSocket_accept((ServerSocket) self->serverSocket)) != NULL) {				// было ли подключение к серверу? если да то вернем сокет для текущего подключения

    	USART_TRACE_GREEN("соединение на 102 порт.\n");

#if (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS != -1)
        if (private_IsoServer_getConnectionCounter(self) >= CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS) {		// если число клиентов превышает. то закроем соединение сразу.
            USART_TRACE_RED("ISO_SERVER: максимум клиентов, отключаем.\n");

            Socket_destroy(connectionSocket);
            handleClientConnections(self);
            return;
        }
#endif
        IsoConnection isoConnection = IsoConnection_create(connectionSocket, self);								// создаем Iso соединение к серверу.
        if (isoConnection) {
        	addClientConnection(self, isoConnection);															// инкрементим счетчик подключений self->connectionCounter++;
        	self->connectionHandler(ISO_CONNECTION_OPENED, self->connectionHandlerParameter, isoConnection);	// Вызываем isoConnectionIndicationHandler(); для Iso соединения
        }																										// isoConnectionIndicationHandler(IsoConnectionIndication indication, void* parameter, IsoConnection connection);
    }
    handleClientConnections(self);				// Парсим если открыто. тут же даёт ответ в порт, если сюда не попали то и ответа не будет.
}
/**********************************************************************************************
 *
 * @param self
 ***********************************************************************************************/
void		handleNTPConnectionsThreadless(IsoServer self)
{
    //++Клиент NTP++++++++++++++++++++++++++++++++++++++++++++++
    // делаем запрос с нужной периодичностью.
    if(SNTP_Period){
		uint64_t currentTime = Hal_getTimeInMs();
		portCHAR NTP_IP[16];
		sprintf(NTP_IP,"%d.%d.%d.%d",SNTP_IP_ADDR[0],SNTP_IP_ADDR[1],SNTP_IP_ADDR[2],SNTP_IP_ADDR[3]);
//		if (currentTime > nextSynchTimeNTP) {
		if (abs(currentTime-lastSynchTimeNTP) > SNTP_Period*60*1000) {
			int ret = sntp_client_serve(self->NTPSocket,(const char*)&NTP_IP,self->NTPPort,Write);
			lastSynchTimeNTP = Hal_getTimeInMs();// + SNTP_Period*60*1000;//*60*1000;								// следующая пересинхронизация через 5 секунд если не пришел ответ
			if (ret == 0) resynchNTP_ready = false;

			Print_Sockets();

			AddToQueueMB(Rd_SysNoteQueue, MB_Wrt_OscNoteAdr0		,MB_Slaveaddr);		// ставим задачу сброса записи
			AddToQueueMB(Rd_SysNoteQueue, MB_Rd_OscNote				,MB_Slaveaddr);		// ставим задачу чтения журнала осцилл.


		}//else{
			if (resynchNTP_ready == false){
				resynchNTP_ready = (bool)sntp_client_serve(self->NTPSocket,(const char*)&NTP_IP,self->NTPPort,Read);
				if (resynchNTP_ready){
					lastSynchTimeNTP = Hal_getTimeInMs();// + SNTP_Period*60*1000;//*60*1000;		// следующая пересинхронизация
				}
			}
		//}
	}
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}
#if (CONFIG_MMS_THREADLESS_STACK != 1)
// only required for multi-threaded server!
static void
isoServerThread(void* isoServerParam)
{
    IsoServer self = (IsoServer) isoServerParam;

    if (!setupIsoServer(self)) {
        if (DEBUG_ISO_SERVER)
            printf("ISO_SERVER: starting server failed!\n");

        goto cleanUp;
    }

    if (DEBUG_ISO_SERVER)
        printf("ISO_SERVER: isoServerThread %p started\n", &isoServerParam);

    while (self->state == ISO_SVR_STATE_RUNNING)
    {
        handleIsoConnections(self);

        Thread_sleep(1);
    }

    self->state = ISO_SVR_STATE_STOPPED;

    cleanUp:
    self->serverSocket = NULL;

    if (DEBUG_ISO_SERVER)
           printf("ISO_SERVER: isoServerThread %p stopped\n", &isoServerParam);

}
#endif

IsoServer
IsoServer_create()
{
    IsoServer self = (IsoServer) GLOBAL_CALLOC(1, sizeof(struct sIsoServer));

    self->state = ISO_SVR_STATE_IDLE;
    self->tcpPort = TCP_PORT;

#if (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1)
    self->openClientConnections = LinkedList_create();
#else
    self->openClientConnections = (IsoConnection*)
            GLOBAL_CALLOC(CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS, sizeof(IsoConnection));
#endif

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    self->connectionCounterMutex = Semaphore_create(1);
    self->openClientConnectionsMutex = Semaphore_create(1);
#endif /* (CONFIG_MMS_THREADLESS_STACK != 1) */

    self->connectionCounter = 0;

    return self;
}

void
IsoServer_setTcpPort(IsoServer self, int port)
{
    self->tcpPort = port;
}
// ----- TFTP  ----------------------------------------------------------
void		IsoServer_SetTFTPort(IsoServer self, int	port){
    self->TFTPPort = port;
}
void		IsoServer_SetTFTPServerSocket(IsoServer self, ServerSocket	Socket){
    self->TFTPserverSocket = Socket;
}

ServerSocket		IsoServer_GetTFTPServerSocket(IsoServer self){
	return	self->TFTPserverSocket;
}

int	IsoServer_GetTFTPort(IsoServer self){
	return self->TFTPPort;
}
// ----- FTP  ----------------------------------------------------------
void			IsoServer_SetFTPServerSocket(IsoServer self, ServerSocket	Socket){
    self->FTPserverSocket = Socket;
}
ServerSocket	IsoServer_GetFTPServerSocket(IsoServer self){
	return	self->FTPserverSocket;
}
void			IsoServer_SetFTPPort(IsoServer self, int	port){
    self->FTPPort = port;
}
int				IsoServer_GetFTPPort(IsoServer self){
	return self->FTPPort;
}
// ----- HTTP  ----------------------------------------------------------
void			IsoServer_SetHTTPServerSocket(IsoServer self, ServerSocket	Socket){
    self->HTTPserverSocket = Socket;
}
ServerSocket	IsoServer_GetHTTPServerSocket(IsoServer self){
	return	self->HTTPserverSocket;
}
void			IsoServer_SetHTTPPort(IsoServer self, int	port){
    self->HTTPPort = port;
}
int				IsoServer_GetHTTPPort(IsoServer self){
	return self->HTTPPort;
}
// ----- SSH  -----------------------------------------------------------
void			IsoServer_SetSSHServerSocket(IsoServer self, ServerSocket	Socket){
    self->SSHserverSocket = Socket;
}
ServerSocket	IsoServer_GetSSHServerSocket(IsoServer self){
	return	self->SSHserverSocket;
}
void			IsoServer_SetSSHPort(IsoServer self, int	port){
    self->SSHPort = port;
}
int				IsoServer_GetSSHPort(IsoServer self){
	return self->SSHPort;
}
void			IsoServer_SetSSHConnect(IsoServer self){
    self->SSHConnect = true;
}
void			IsoServer_ClrSSHConnect(IsoServer self){
    self->SSHConnect = false;
}
bool			IsoServer_GetSSHConnect(IsoServer self){
	return self->SSHConnect;
}
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
void
IsoServer_setEthernetParam(IsoServer self, char* ipAddress, char* mask, char* gateway)
{

	static	uint8_t	IPBuffer[16];
	static	uint8_t	MaskPBuffer[16];
	static	uint8_t	GWBuffer[16];


	sprintf((char *)IPBuffer,"%u.%u.%u.%u",ipAddress[0], ipAddress[1], ipAddress[2], ipAddress[3]);
	sprintf((char *)MaskPBuffer,"%u.%u.%u.%u",mask[0], mask[1], mask[2], mask[3]);
	sprintf((char *)GWBuffer,"%u.%u.%u.%u",gateway[0], gateway[1], gateway[2], gateway[3]);

	self->localIpAddress = (char *)IPBuffer;
	self->netMask = (char *)MaskPBuffer;
	self->gateway = (char *)GWBuffer;
	self->PHYPortsMode =  PHY_SWITCH_DEFAULT;
	self->PHYTransmitport = PHY_PORT_1_2;
}

void
IsoServer_setLocalIpAddress(IsoServer self, char* ipAddress)
{
	self->localIpAddress = ipAddress;
}
char*
IsoServer_getLocalIpAddress(IsoServer self)
{
	return self->localIpAddress;
}
void
IsoServer_setGatewayAddress(IsoServer self, char* gateway)
{
	self->gateway = gateway;
}
char*
IsoServer_getGatewayAddress(IsoServer self)
{
	return self->gateway;
}
void
IsoServer_setMaskAddress(IsoServer self, char* mask)
{
	self->netMask = mask;
}
char*
IsoServer_getMaskAddress(IsoServer self)
{
	return self->netMask;
}


IsoServerState
IsoServer_getState(IsoServer self)
{
    return self->state;
}

PhyPortsForTransmit
IsoServer_getPHYTransmitport(IsoServer self)
{
    return self->PHYTransmitport;
}
/************************************************************************
 */

void	IsoServer_PRP_on(IsoServer self){
    self->AppendPRP = true;
}
void	IsoServer_PRP_off(IsoServer self){
    self->AppendPRP = false;
}
void	IsoServer_PRPSeqNum_increase(IsoServer self){
     self->prpSeqNum++;
}

void	IsoServer_PRPSeqNum_reset(IsoServer self){
    self->prpSeqNum = 0;
}


bool
IsoServer_getAppendPRP(IsoServer self)
{
    return self->AppendPRP;
}

uint16_t
IsoServer_getprpSeqNum(IsoServer self)
{
    return self->prpSeqNum;
}
/************************************************************************
 */
void	IsoServer_HSR_on(IsoServer self){
    self->AppendHSR = true;
}
void	IsoServer_HSR_off(IsoServer self){
    self->AppendHSR = false;
}
void	IsoServer_HSRSeqNum_increase(IsoServer self){
     self->hsrSeqNum++;
}

void	IsoServer_HSRSeqNum_reset(IsoServer self){
    self->hsrSeqNum = 0;
}

bool
IsoServer_getAppendHSR(IsoServer self)
{
    return self->AppendHSR;
}
uint16_t
IsoServer_gethsrSeqNum(IsoServer self)
{
    return self->hsrSeqNum;
}
/************************************************************************
 *
 * @param self
 * @param ports
 */
void
IsoServer_setPHYTransmitport(IsoServer self, PhyPortsForTransmit ports)
{
	self->PHYTransmitport = ports;
}

void
IsoServer_setAuthenticator(IsoServer self, AcseAuthenticator authenticator, void* authenticatorParameter)
{
    self->authenticator = authenticator;
    self->authenticatorParameter = authenticatorParameter;
}

AcseAuthenticator
IsoServer_getAuthenticator(IsoServer self)
{
    return self->authenticator;
}

void*
IsoServer_getAuthenticatorParameter(IsoServer self)
{
    return self->authenticatorParameter;
}

#if (CONFIG_MMS_THREADLESS_STACK != 1)
void
IsoServer_startListening(IsoServer self)
{
    if (self->state == ISO_SVR_STATE_RUNNING) {
        if (DEBUG_ISO_SERVER)
                printf("ISO_SERVER: server already in RUNNING state!\n");

        goto exit_function;
    }

    self->state = ISO_SVR_STATE_IDLE;

    self->serverThread = Thread_create((ThreadExecutionFunction) isoServerThread, self, false);				// создаем и запускаем

    Thread_start(self->serverThread);

    /* wait until server is up */
    while (self->state == ISO_SVR_STATE_IDLE)
        Thread_sleep(1);

    if (DEBUG_ISO_SERVER)
        printf("ISO_SERVER: new iso server thread started\n");

exit_function:
    return;
}
#endif /* (CONFIG_MMS_THREADLESS_STACK != 1) */

/*****************************************************************************************************
 * IsoServer_startListeningThreadless
 * Настройка и старт прослушивания сокета.
 *****************************************************************************************************/
void
IsoServer_startListeningThreadless(IsoServer self)
{
    if (!setupIsoServer(self)) {
        if (DEBUG_ISO_SERVER){
        	USART_TRACE_RED("ISO_SERVER: starting server failed!\n");
        }
        self->serverSocket = NULL;
    }
    else {
        self->state = ISO_SVR_STATE_RUNNING;

        if (DEBUG_ISO_SERVER){
        	USART_TRACE_GREEN("ISO_SERVER: new iso server (threadless) started\n");
        }
    }
}

/*****************************************************************************************************
 * IsoServer_waitReady
 * проверяем состояние всех активных сокетов
 *****************************************************************************************************/
int		IsoServer_waitReady(IsoServer self, unsigned int timeoutMs)
{
   int result;

   if (self->state == ISO_SVR_STATE_RUNNING) {
       HandleSet handles;

       handles = Handleset_new();
       if (handles != NULL) {

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
           lockClientConnections(self);
#endif

#if (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1)

           LinkedList openConnection = LinkedList_getNext(self->openClientConnections);
           LinkedList lastConnection = self->openClientConnections;

           while (openConnection != NULL) {
               IsoConnection isoConnection = (IsoConnection) openConnection->data;

               if (IsoConnection_isRunning(isoConnection)) {
                   IsoConnection_addHandleSet(isoConnection, handles);
                   openConnection = LinkedList_getNext(openConnection);
               } else {
                   IsoConnection_destroy(isoConnection);
                   lastConnection->next = openConnection->next;
                   GLOBAL_FREEMEM(openConnection);
                   openConnection = lastConnection->next;
               }

               lastConnection = lastConnection->next;
           }

#else
           int i;

           for (i = 0; i < CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS; i++) {						// добавим все активные сокеты для проверки select() на наличие принятых данных
               if (self->openClientConnections[i] != NULL) {
                   if (IsoConnection_isRunning(self->openClientConnections[i])) {				// если клиент есть
                       IsoConnection_addHandleSet(self->openClientConnections[i], handles);		// добавим его для проверки
                   }
                   else {
#if ((CONFIG_MMS_SINGLE_THREADED == 1) || (CONFIG_MMS_THREADLESS_STACK == 1))
                	   USART_TRACE_RED("waitReady:IsoConnection_destroy: %u\n",i);
                       IsoConnection_destroy(self->openClientConnections[i]);
#endif
                       self->openClientConnections[i] = NULL;
                   }
               }
           }

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
           unlockClientConnections(self);
#endif

#endif /* (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1) */
           Handleset_addSocket(handles, self->serverSocket);
           result = Handleset_waitReady(handles, timeoutMs);			// проверка состояния сокетов
           Handleset_destroy(handles);									// очистим
       } else {
           result = -1;
       }
   } else {
       result = -1;
   }

   return result;
}
/*****************************************************************************************************
 * IsoServer_OnewaitReady
 * проверяем состояние одного активного сокета
 *****************************************************************************************************/
int		IsoServer_OnewaitReady(IsoServer self, int num, unsigned int timeoutMs)
{
   int result;

   if (self->state == ISO_SVR_STATE_RUNNING) {
       HandleSet handles;

       handles = Handleset_new();
       if (handles != NULL) {

           int i;

           for (i = 0; i < CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS; i++) {						// добавим все активные сокеты для проверки select() на наличие принятых данных
               if (self->openClientConnections[i] != NULL) {
                   if (IsoConnection_isRunning(self->openClientConnections[i])) {				// если клиент есть


                	   if (num == IsoConnection_getSocketFd(self->openClientConnections[i])){
                		   IsoConnection_addHandleSet(self->openClientConnections[i], handles);		// добавим его для проверки
                	   }
                   }
                   else {
                	   USART_TRACE_RED("waitReady:IsoConnection_destroy: %u\n",i);
                       IsoConnection_destroy(self->openClientConnections[i]);
                       self->openClientConnections[i] = NULL;
                   }
               }
           }

           Handleset_addSocket(handles, self->serverSocket);
           result = Handleset_waitReady(handles, timeoutMs);			// проверка состояния сокетов
           Handleset_destroy(handles);									// очистим
       } else {
           result = -1;
       }
   } else {
       result = -1;
   }

   return result;
}


void
IsoServer_processIncomingMessages(IsoServer self)
{
    if (self->state == ISO_SVR_STATE_RUNNING)
        handleIsoConnectionsThreadless(self);
}

void
IsoServer_processGetClientList(uint8_t *pcWriteBuffer,IsoServer self)
{
	   int i;
		*pcWriteBuffer = 0x00;

	    for (i = 0; i < CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS; i++) {
	        if (self->openClientConnections[i] != NULL) {
	    		sprintf((char *)pcWriteBuffer,"<table border=2 align=center>");
	    		pcWriteBuffer += strlen((char *)pcWriteBuffer );
	    		sprintf((char *)pcWriteBuffer,"<tr><th>номер</th><th>адрес</th></tr>");
	    		pcWriteBuffer += strlen((char *)pcWriteBuffer );
	    		break;
	        }
	    }

	    for (i = 0; i < CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS; i++) {
	        if (self->openClientConnections[i] != NULL) {

				sprintf((char *)pcWriteBuffer, "<tr><th>%i</th><th align=left>%s</th></tr>",i+1,IsoConnection_getPeerAddress(self->openClientConnections[i]));
				pcWriteBuffer += strlen((char *)pcWriteBuffer );

	        }
	    }

	    for (i = 0; i < CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS; i++) {
	        if (self->openClientConnections[i] != NULL) {
	    		sprintf((char *)pcWriteBuffer,"</table>");	pcWriteBuffer += strlen((char *)pcWriteBuffer );
	    		break;
	        }
	    }
}

static void
stopListening(IsoServer self)
{
    self->state = ISO_SVR_STATE_STOPPED;
    if (self->serverSocket != NULL) {
        ServerSocket_destroy((ServerSocket) self->serverSocket);
        self->serverSocket = NULL;
    }
}

void
IsoServer_stopListeningThreadless(IsoServer self)
{
    stopListening(self);

    closeAllOpenClientConnections(self);

    if (DEBUG_ISO_SERVER)
        printf("ISO_SERVER: IsoServer_stopListeningThreadless finished!\n");
}

#if (CONFIG_MMS_THREADLESS_STACK != 1)
void
IsoServer_stopListening(IsoServer self)
{
    stopListening(self);

    if (self->serverThread != NULL)
        Thread_destroy(self->serverThread);

    closeAllOpenClientConnections(self);

    /* Wait for connection threads to finish */
    while (private_IsoServer_getConnectionCounter(self) > 0)
        Thread_sleep(10);

    if (DEBUG_ISO_SERVER)
        printf("ISO_SERVER: IsoServer_stopListening finished!\n");
}
#endif

void
IsoServer_closeConnection(IsoServer self, IsoConnection isoConnection)
{
    if (self->state != ISO_SVR_STATE_IDLE) {
        self->connectionHandler(ISO_CONNECTION_CLOSED, self->connectionHandlerParameter,
                isoConnection);
    }

    removeClientConnection(self, isoConnection);
}

void
IsoServer_setConnectionHandler(IsoServer self, ConnectionIndicationHandler handler,
        void* parameter)
{
    self->connectionHandler = handler;
    self->connectionHandlerParameter = parameter;
}

void
IsoServer_destroy(IsoServer self)
{

#if (CONFIG_MMS_THREADLESS_STACK != 1)
    if (self->state == ISO_SVR_STATE_RUNNING)
        IsoServer_stopListening(self);
#endif

#if (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1)

#if (CONFIG_MMS_SINGLE_THREADED == 1)
    if (self->openClientConnections != NULL)
        LinkedList_destroy(self->openClientConnections);
#else
    if (self->openClientConnections != NULL)
        LinkedList_destroyStatic(self->openClientConnections);
#endif /* (CONFIG_MMS_SINGLE_THREADED == 1) */

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    lockClientConnections(self);
#endif

#else
    GLOBAL_FREEMEM(self->openClientConnections);
#endif /* (CONFIG_MAXIMUM_TCP_CLIENT_CONNECTIONS == -1) */

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    Semaphore_destroy(self->connectionCounterMutex);
    Semaphore_destroy(self->openClientConnectionsMutex);
#endif

    GLOBAL_FREEMEM(self);
}

void
private_IsoServer_decreaseConnectionCounter(IsoServer self)
{
#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    Semaphore_wait(self->connectionCounterMutex);
#endif

    self->connectionCounter--;

    USART_TRACE_BLUE("Осталось подключений: %i\n", self->connectionCounter);

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    Semaphore_post(self->connectionCounterMutex);
#endif
}

int
private_IsoServer_getConnectionCounter(IsoServer self)
{
    int connectionCounter;

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    Semaphore_wait(self->connectionCounterMutex);
#endif

    connectionCounter = self->connectionCounter;

#if (CONFIG_MMS_THREADLESS_STACK != 1) && (CONFIG_MMS_SINGLE_THREADED == 0)
    Semaphore_post(self->connectionCounterMutex);
#endif

    return connectionCounter;
}

#if (CONFIG_MMS_THREADLESS_STACK != 1)
void
IsoServer_setUserLock(IsoServer self, Semaphore userLock)
{
    self->userLock = userLock;
}

void
IsoServer_userLock(IsoServer self)
{
    if (self->userLock != NULL)
        Semaphore_wait(self->userLock);
}

void
IsoServer_userUnlock(IsoServer self)
{
    if (self->userLock != NULL)
        Semaphore_post(self->userLock);
}
#endif
