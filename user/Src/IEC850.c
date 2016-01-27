/*
 * IEC850.c
 *
 *  Created on: 09.12.2015
 *      Author: sagok
 */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "queue.h"
#include "signal.h"

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


/*iec850 includes ------------------------------------------------------------*/
#include "iec850.h"

#include "byte_stream.h"
#include "cotp.h"
#include "iso_session.h"
#include "iso_presentation.h"
#include "acse.h"
#include "iso_server.h"
#include "iec61850_server.h"
#include "static_model.h"

#include "mms_server_connection.h"

//#include "MmsPdu.h"

/*Modbus includes ------------------------------------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbport.h"
#include "modbus.h"


/* Variables -----------------------------------------------------------------*/
/* import IEC 61850 device model created from SCL-File */
extern IedModel iedModel;

static IedServer iedServer = NULL;

typedef void* Semaphore;

extern struct netconn *conn850,*newconn850;

extern struct netif 	first_gnetif;
extern struct ip_addr 	first_ipaddr;
extern struct ip_addr 	netmask;
extern struct ip_addr 	gw;


osThreadId defaultTaskHandle;

/*  -----------------------------------------------------------------*/
struct sIsoConnection {
    uint8_t* 		receive_buf;					// буфер принятых данных
    uint8_t* 		send_buf_1;						// буфер для передачи
    uint8_t* 		send_buf_2;
    Socket			socket;
    MessageReceivedHandler msgRcvdHandler;
    IsoServer 		isoServer;
    void* 			msgRcvdHandlerParameter;
    int 			state;							// статус разобранного сообщения		ISO_CON_STATE_STOPPED/ISO_CON_STATE_RUNNING
    IsoSession* 	session;
    IsoPresentation* presentation;
    CotpConnection* cotpConnection;					// COTP
    char* 			clientAddress;					// // адрес клиента в виде строки 24 символа "Адрес[порт]"
};

typedef struct sIsoConnection* IsoConnection;


IsoConnection	Connection_create(struct netconn *conn,IsoConnection self,uint8_t* Inbuffer);
char*			Socket_getPeerAddress(struct netconn *conn);
void			observerCallback(DataAttribute* dataAttribute);

void 			sigint_handler(int signalId);
/*************************************************************************
 * StartIEC850Task
 *************************************************************************/
void StartIEC850Task(void const * argument){


	struct netbuf *buf850;
	err_t accept_err850;
	uint16_t len;
	uint8_t *data;
	AcseConnection 	acseConnection;
	CotpIndication 	cotpIndication;

	IsoConnection self = calloc(1, sizeof(struct sIsoConnection));

    ByteBuffer responseBuffer;

	tcpip_init( NULL, NULL );
	USART_TRACE_BLUE("MAC:%.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n",MAC_ADDR0, MAC_ADDR1, MAC_ADDR2, MAC_ADDR3,MAC_ADDR4,MAC_ADDR5);

	// устанавливаем IP параметры для первичного IP соединения, всегда сервер
	IP4_ADDR(&first_ipaddr, first_IP_ADDR0, first_IP_ADDR1, first_IP_ADDR2, first_IP_ADDR3);
	USART_TRACE_BLUE("IP:%d.%d.%d.%d \n",first_IP_ADDR0, first_IP_ADDR1, first_IP_ADDR2, first_IP_ADDR3);
	// устанавливаем маску подсети.
	IP4_ADDR(&netmask, NETMASK_ADDR0, NETMASK_ADDR1 , NETMASK_ADDR2, NETMASK_ADDR3);
	USART_TRACE_BLUE("MASK:%d.%d.%d.%d \n",NETMASK_ADDR0, NETMASK_ADDR1 , NETMASK_ADDR2, NETMASK_ADDR3);
	// устанавливаем адрес шлюза.
	IP4_ADDR(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);
	USART_TRACE_BLUE("Gateway:%d.%d.%d.%d \n",GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);

	// добавим  и регистрируем NETWORK интерфейс
	netif_add(&first_gnetif, &first_ipaddr, &netmask, &gw, NULL, &ethernetif_init, &tcpip_input);
	netif_set_default(&first_gnetif);
	if (netif_is_link_up(&first_gnetif))	netif_set_up(&first_gnetif);		// When the netif is fully configured this function must be called
	else									netif_set_down(&first_gnetif);		// When the netif link is down this function must be called


	for(;;) {
		// привяжем порт к интерфейсу и включим не прием
		conn850 = netconn_new(NETCONN_TCP);										// создадим новое соединение 61850, возвращает структуру
		if (conn850!=NULL){														// если удалось создать
			USART_TRACE("Create NETCONN_TCP\n");
			int8_t ready850 = netconn_bind(conn850, &first_ipaddr, IEC850_Port);		// привяжем соединение на IP и порт IEC 61850 (IEC850_Port)
		    if (ready850 != ERR_OK)	{netconn_delete(conn850);USART_TRACE("Create NETCONN_TCP ERROR!!!\n");}
		    else	{netconn_listen(conn850);USART_TRACE("Open port: %d\n",IEC850_Port);}		// переводим соединение в режим прослушивания
		}
		// -------------------------------------------------------------------------------------------------------------------
		// -------------------------------------------------------------------------------------------------------------------
		// -------------------------------------------------------------------------------------------------------------------
		//iedServer = IedServer_create(&iedModel);								// создадим IED электронное устройство

		//IedServer_observeDataAttribute(iedServer, IEDMODEL_GenericIO_GGIO1_NamPlt_vendor,observerCallback);

		// временно чтобы понять как анализировать
		iedServer = IedServer_create(&iedModel);



		// включаем парольный доступ
		//AcseAuthenticationParameter auth = calloc(1, sizeof(struct sAcseAuthenticationParameter));
		//auth->mechanism = AUTH_PASSWORD;	// 0x52 0x03 0x01 см. acse.с auth_mech_password_oid[]
		//auth->value.password.string = "testpw";						//пароль
		IsoServer isoServer = IedServer_getIsoServer(iedServer);
		//IsoServer_setAuthenticationParameter(isoServer, auth);
		//USART_TRACE("включили парольный доступ, пароль: %s механизм: 0x52, 0x03, 0x01 \n",auth->value.password.string);

		// MMS сервер начинает слушать клиентов
		IedServer_start(iedServer, 102);			// функция не нужна, сервер запускаю отдельно САМ
		// -------------------------------------------------------------------------------------------------------------------
		// -------------------------------------------------------------------------------------------------------------------
		// -------------------------------------------------------------------------------------------------------------------

		// далее приём данных и обработка в цикле
        while (1){																	// далее слушаем и  захватываем соединение
        	accept_err850 = netconn_accept(conn850, &newconn850);
        	if (accept_err850 == ERR_OK){											// если приняли, то обработаем его
        		USART_TRACE("a new connection has been received...\n");

        		Port_On(LED1);

        		Connection_create(newconn850,self,data);							// настроим структуру для работы
        		AcseConnection_init(&acseConnection);
        		AcseConnection_setAuthenticationParameter(&acseConnection, IsoServer_getAuthenticationParameter(isoServer));

        		MmsServerConnection* mmsCon = MmsServerConnection_init(0,IedServer_getMmsServer(iedServer), self);



        		while (netconn_recv(newconn850, &buf850) == ERR_OK)					// принимаем данные в буфер
                {
                    USART_TRACE_GREEN(" ---------------------- netbuf Receive data ---------------------- \n");
                    do
                    {
                    netbuf_data(buf850,(void *)&data, &len);						// указатель получил адрес вх. данных и его размер
                    self->cotpConnection->readBuffer->buffer = data;
                    self->cotpConnection->readBuffer->maxSize = len;

                    USART_TRACE("Receive data from a netconn. %u bytes \n",len);

                    ByteBuffer_wrap(&responseBuffer, self->send_buf_1, 0, SEND_BUF_SIZE);	// буфер подготовки данных для передачи в TCP/IP

                    // Юзер данные перекладываем в Payload буфер
                    cotpIndication = CotpConnection_parseIncomingMessage(self->cotpConnection);	// парсим пакет и возвращаем тип соединения, Юзер данные перекладываем в Payload буфер
                    switch (cotpIndication) {
                        case CONNECT_INDICATION:
                        	USART_TRACE("ISO 8073 COTP connection indication\n");
                        	CotpConnection_sendConnectionResponseMessage(self->cotpConnection);
                        break;

                        case DATA_INDICATION:
                        {
                    		Port_On(LED2);
                        	USART_TRACE("ISO 8073 COTP data indication\n");

                            ByteBuffer* 			cotpPayload = CotpConnection_getPayload(self->cotpConnection);		// получаем адрес сообщения
                            IsoSessionIndication	sIndication = IsoSession_parseMessage(self->session, cotpPayload);	// парсим Session сообщение
                            ByteBuffer*				sessionUserData = IsoSession_getUserData(self->session);			// iso8823 OSI Presentation protocol в sessionUserData находится всё начиная с ISO 8823

                            switch (sIndication) {
                            IsoPresentationIndication 	pIndication;

                        		case SESSION_OK:
                        			USART_TRACE("iso_connection: session ok\n");
                        			break;

                            	case SESSION_CONNECT:
                            		USART_TRACE("iso_connection: session connect indication\n");
                            		pIndication = IsoPresentation_parseConnect(self->presentation, sessionUserData);	// парсим Presentation сообщение
                            		// далее в self->presentation-nextPayload данные начиная с ISO 8650-1 (AARP) сообщения запроса от клиента.

                            		if (pIndication == PRESENTATION_OK) {
                                        ByteBuffer* 	acseBuffer;
                                        AcseIndication 	aIndication;
                                        ByteBuffer 		mmsRequest;

                            			USART_TRACE("iso_connection: presentation ok\n");

                            			acseBuffer = &(self->presentation->nextPayload);								// берём указатель на входящий ISO 8650-1 (AARP) и парсим
                            			aIndication = AcseConnection_parseMessage(&acseConnection, acseBuffer);			// возвращаем указатель на юзерданные в acseConnection->userDataBuffer

                            			if (aIndication == ACSE_ASSOCIATE) {
                            				USART_TRACE("cotp_server: acse associate\n");

                            				ByteBuffer_wrap(&mmsRequest, acseConnection.userDataBuffer,acseConnection.userDataBufferSize, acseConnection.userDataBufferSize);

                            				// Получили запрос Request, нужно его проанализировать и сформировать ответ Response
//TODO: Нужна функция анализа Request и формирования Response.

                            				//MmsServerConnection	mmsServercon;
                            				//iedServer->mmsServer->isoServer->connectionHandler(iedServer->mmsServer->isoServer->connectionHandlerParameter);

                            				//isoConnectionIndicationHandler();

                            				ByteBuffer_setcurrPos(&responseBuffer,0);
                                        	MmsServerConnection_parseMessage(mmsCon,  &mmsRequest, &responseBuffer);

                            				//mmsRequest.buffer[0]++;	//ответим response


                            				if (responseBuffer.currPos > 0) {
                            					USART_TRACE("iso_connection: application payload size: %i\n", responseBuffer.currPos);


                            					// пишем в writeBuffer заголовок ISO 8650-1 (AARQ 24 байта) + содержимое mmsRequest (user infirmation = MMS)
                            					AcseConnection_createAssociateResponseMessage(&acseConnection,ACSE_RESULT_ACCEPT, self->cotpConnection->writeBuffer, &responseBuffer);
                            					USART_TRACE("add ISO 8650-1(AARQ) total size: %i\n", self->cotpConnection->writeBuffer->currPos);

                            					//  пишем в payload ISO 8823 + содержимое writeBuffer (AARQ + user infirmation)
                            					ByteBuffer_setcurrPos(self->cotpConnection->payload,0);
                            					IsoPresentation_createCpaMessage(self->presentation, self->cotpConnection->payload,self->cotpConnection->writeBuffer);
                            					USART_TRACE("add ISO 8823(ANS.1) total size: %i\n", self->cotpConnection->payload->currPos);

                            					// с этого момента в payload->buffer с лежит блок: ISO 8823 + ISO 8650-1 + MMS
                            					// до TCP уровня осталось ISO 8327-1 (SPDU), ISO 8073 (COTP), TPKT

                            					ByteBuffer_setcurrPos(self->cotpConnection->writeBuffer,0);		// обнулим укозатель для формирования хвоста начиная с ISO 8327-1
                            					ByteBuffer_setcurrPos(&responseBuffer,0);

                            					// формитуем в буфере writeBuffer конструкцию AcceptSpdu ( ISO 8327-1 OSI Session protocol )
                            					IsoSession_createAcceptSpdu(self->session,&responseBuffer,self->cotpConnection->payload->currPos);
                            					USART_TRACE_MAGENTA("create new buffer ISO 8327-1(SPDU) total size: %i\n", responseBuffer.currPos);

                            					// дополняем его буфером payload->buffer (ISO 8823 + ISO 8650-1 + MMS)
                            					ByteBuffer_append(&responseBuffer, self->cotpConnection->payload->buffer,self->cotpConnection->payload->currPos);
                            					USART_TRACE_MAGENTA("add ISO 8823 + ISO 8650-1 + ISO 9506 (MMS) total size: %i\n", responseBuffer.currPos);

                            					// добавляем TPKT и ISO 8073 (COTP) и отправляем всё в стек TCP/IP
                            					CotpConnection_sendDataMessage(self->cotpConnection, &responseBuffer);
                            					USART_TRACE_MAGENTA("add TPKT & ISO 8073 (COTP) total size: %i\n", self->cotpConnection->writeBuffer->currPos);

                            				}
                            				else {
                            					USART_TRACE_RED("iso_connection: association error. No response from application!\n");
                            				}
                            			}
                            			else {
                            				USART_TRACE_RED("iso_connection: acse association failed\n");
                                            self->state = ISO_CON_STATE_STOPPED;
                            			}
                            		}
                            		break;

                            	case SESSION_DATA:
                            		USART_TRACE("iso_connection: session data indication\n");

                            		pIndication = IsoPresentation_parseUserData(self->presentation, sessionUserData);
                                    if (pIndication == PRESENTATION_ERROR) {
                                        USART_TRACE_RED("cotp_server: presentation error\n");
                                        self->state = ISO_CON_STATE_STOPPED;
                                        break;
                                    }

                                    if (self->presentation->nextContextId == 3) {
                                    	ByteBuffer* mmsRequest;

                                    	USART_TRACE("iso_connection: mms message\n");

                                    	mmsRequest = &(self->presentation->nextPayload);
                                    	ByteBuffer_setcurrPos(self->cotpConnection->writeBuffer,0);

                        				// Получили запрос Request, нужно его проанализировать и сформировать ответ Response
//TODO: Нужна функция анализа Request и формирования Response.

                            			ByteBuffer_setcurrPos(&responseBuffer,0);
                                        MmsServerConnection_parseMessage(mmsCon,  mmsRequest, &responseBuffer);


                                    	// создадим MMS сообщение в буфере writeBuffer с юзерданными из payload
                                    	IsoPresentation_createUserData(self->presentation,self->cotpConnection->writeBuffer, &responseBuffer);

                                    	ByteBuffer_setcurrPos(&responseBuffer,0);						// обнулим укозатель для формирования

                                    	// добавим GiveToken Data SPDU в оконечный буфер для отправки
                                    	IsoSession_createDataSpdu(self->session, &responseBuffer);
                                    	USART_TRACE_MAGENTA("create new buffer ISO 8327-1(SPDU) total size: %i\n", responseBuffer.currPos);

                                    	// дополняем его буфером writeBuffer->buffer (ISO 8823 + ISO 8650-1 + MMS)
                                    	ByteBuffer_append(&responseBuffer, self->cotpConnection->writeBuffer->buffer,self->cotpConnection->writeBuffer->currPos);
                                    	USART_TRACE_MAGENTA("add ISO 8823 + ISO 8650-1 + ISO 9506 (MMS) total size: %i\n", responseBuffer.currPos);

                                    	ByteBuffer_setcurrPos(self->cotpConnection->writeBuffer,0);

                    					// добавляем TPKT и ISO 8073 (COTP) и отправляем всё в стек TCP/IP
                                    	CotpConnection_sendDataMessage(self->cotpConnection, &responseBuffer);
                                    	USART_TRACE_MAGENTA("add TPKT & ISO 8073 (COTP) total size: %i\n", self->cotpConnection->writeBuffer->currPos);

                                    }else{
                                    	USART_TRACE_RED(" iso_connection: unknown presentation layer context!\n");
                                    }
                            		break;

                            	case SESSION_GIVE_TOKEN:
                            		USART_TRACE("iso_connection: session give token\n");
                            		USART_TRACE_RED("TODO: iso_connection: session give token\n");
                            		break;

                            	case SESSION_ERROR:
                            		Port_On(LED4);
                            		USART_TRACE_RED("iso_connection: session error\n");
                            		self->state = ISO_CON_STATE_STOPPED;
                            		break;

                            }// switch (sIndication)
                    	Port_Off(LED2);
                        }// DATA_INDICATION
                        break;

                        case ERR:
                        	USART_TRACE_RED("ISO 8073 COTP protocol error\n");
                        	self->state = ISO_CON_STATE_STOPPED;
                        break;

                        default:
                        	USART_TRACE_RED("COTP Unknown Indication: %i\n", cotpIndication);
                            self->state = ISO_CON_STATE_STOPPED;
                        break;
                    }

                    }while (netbuf_next(buf850) >= 0);

                    //free(self->send_buf_1);										// освободим память
                    //USART_TRACE_RED("free(self->send_buf_1)\n");

                netbuf_delete(buf850);
                USART_TRACE_GREEN("netbuf_delete ...\n");
                }
        	Port_Off(LED1);
            }
        	USART_TRACE_GREEN("Close netconn connection ...\n");
            netconn_close(newconn850);											// закрываем соединение
            netconn_delete(newconn850);											// освобождаем память
        }
		//! приём данных и обработка
	}
}

/*************************************************************************
 * ByteBuffer_send(ByteBuffer* self)
 * передача
 *************************************************************************/
int		ByteBuffer_send(ByteBuffer* self)
{

	if (ERR_OK == netconn_write(newconn850, self->buffer, (size_t)self->currPos, NETCONN_COPY))
		return 1;
    else
        return -1;

}

/*************************************************************************
 * Connection_create
 *
 *************************************************************************/
IsoConnection	Connection_create(struct netconn *conn, IsoConnection self, uint8_t* Inbuffer)
{

	self->cotpConnection = calloc(1, sizeof(CotpConnection));
	self->cotpConnection->readBuffer = ByteBuffer_create(NULL,RECEIVE_BUF_SIZE);
   	self->cotpConnection->payload = ByteBuffer_create(NULL,SEND_BUF_SIZE);

   	self->socket = conn;

    self->session = calloc(1, sizeof(IsoSession));
    IsoSession_init(self->session);

    self->presentation = calloc(1, sizeof(IsoPresentation));
    IsoPresentation_init(self->presentation);

	self->receive_buf = Inbuffer;
	self->send_buf_1 = malloc(SEND_BUF_SIZE);
	self->send_buf_2 = NULL;

	self->msgRcvdHandler = NULL;
	self->msgRcvdHandlerParameter = NULL;

	self->state = ISO_CON_STATE_RUNNING;
	self->clientAddress = Socket_getPeerAddress(conn);							// адрес клиента

	USART_TRACE("new iso connection thread started\n");

	return self;
}
/*************************************************************************
 * Socket_getPeerAddress
 *
 *************************************************************************/
char*	Socket_getPeerAddress(struct netconn *conn)
{
    //struct sockaddr_storage addr;
    ip_addr_t 	addr;
    uint16_t	port;
    uint8_t		ip0,ip1,ip2,ip3;

    char* clientConnection = malloc(24);

    netconn_peer(conn,&addr,&port);

    ip0 = addr.addr & 0xff;
    ip1 = (addr.addr>>8) & 0xff;
    ip2 = (addr.addr>>16) & 0xff;
    ip3 = (addr.addr>>24) & 0xff;

    sprintf(clientConnection, "%d.%d.%d.%d[%i]",ip0, ip1, ip2, ip3, port);
    USART_TRACE("PeerAddress: IP:%d.%d.%d.%d[%i]\n",ip0, ip1, ip2, ip3,port);

   return clientConnection;
}
/*************************************************************************
 * observerCallback
 * колбэк монитора за атрибутами
 *************************************************************************/
void	observerCallback(DataAttribute* dataAttribute){
    if (dataAttribute == IEDMODEL_GenericIO_GGIO1_NamPlt_vendor) {
 //   	USART_TRACE("GGIO.NamPlt.vendor changed to %s\n", MmsValue_toString(dataAttribute->mmsValue));
    }
    else if (dataAttribute == IEDMODEL_GenericIO_GGIO1_NamPlt_swRev) {
 //   	USART_TRACE("GGIO.NamPlt.swRef changed to %s\n", MmsValue_toString(dataAttribute->mmsValue));
    }
}
/*************************************************************************
 * Hal_getTimeInMs
 *
 *************************************************************************/
void sigint_handler(int signalId)
{

}
/*************************************************************************
 * Hal_getTimeInMs
 *
 *************************************************************************/
uint64_t 	Hal_getTimeInMs (void){

	   return 0;
}
