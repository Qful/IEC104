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
#include "cotp.h"
#include "acse.h"
#include "iso_session.h"
#include "iso_presentation.h"
/*Modbus includes ------------------------------------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbport.h"
#include "modbus.h"


/* Variables -----------------------------------------------------------------*/
typedef void* Semaphore;


//extern struct netconn *conn, *newconn;
extern struct netconn *conn850,*newconn850;

extern struct netif 	first_gnetif;
extern struct ip_addr 	first_ipaddr;
extern struct ip_addr 	netmask;
extern struct ip_addr 	gw;


osThreadId defaultTaskHandle;

/*  -----------------------------------------------------------------*/
struct sIsoConnection {
    uint8_t* 		receive_buf;					// буфер прин€тых данных
    uint8_t* 		send_buf_1;						// буфер дл€ передачи
    uint8_t* 		send_buf_2;
    int 			state;							// статус разобранного сообщени€		ISO_CON_STATE_STOPPED/ISO_CON_STATE_RUNNING
    IsoSession* 	session;
    IsoPresentation* presentation;
    CotpConnection* cotpConnection;					// COTP
    char* 			clientAddress;					// // адрес клиента в виде строки 24 символа "јдрес[порт]"
};

typedef struct sIsoConnection* IsoConnection;


IsoConnection	IsoConnection_create(struct netconn *conn,IsoConnection self,uint8_t* Inbuffer);
char*	Socket_getPeerAddress(struct netconn *conn);


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


// TODO: нужно создать функции подготовки буферов (инита каждого )
//	self = calloc(1, sizeof(struct sIsoConnection));
//	self->cotpConnection = calloc(1, sizeof(CotpConnection));
//	self->cotpConnection->readBuffer = ByteBuffer_create(NULL,sizeof(ByteBuffer));
//   	self->cotpConnection->payload = ByteBuffer_create(NULL,sizeof(ByteBuffer));


	tcpip_init( NULL, NULL );
	USART_TRACE_BLUE("MAC:%.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n",MAC_ADDR0, MAC_ADDR1, MAC_ADDR2, MAC_ADDR3,MAC_ADDR4,MAC_ADDR5);

	// устанавливаем IP параметры дл€ первичного IP соединени€, всегда сервер
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
		// прив€жем порт к интерфейсу и включим не прием
		conn850 = netconn_new(NETCONN_TCP);										// создадим новое соединение 61850, возвращает структуру
		if (conn850!=NULL){														// если удалось создать
			USART_TRACE("Create NETCONN_TCP\n");
			int8_t ready850 = netconn_bind(conn850, &first_ipaddr, IEC850_Port);		// прив€жем соединение на IP и порт IEC 61850 (IEC850_Port)
		    if (ready850 != ERR_OK)	{netconn_delete(conn850);USART_TRACE("Create NETCONN_TCP ERROR!!!\n");}
		    else	{netconn_listen(conn850);USART_TRACE("Open port: %d\n",IEC850_Port);}		// переводим соединение в режим прослушивани€
		}
		// далее приЄм данных и обработка в цикле
        while (1){																	// далее слушаем и  захватываем соединение
        	accept_err850 = netconn_accept(conn850, &newconn850);
        	if (accept_err850 == ERR_OK){											// если прин€ли, то обработаем его
        		USART_TRACE("a new connection has been received...\n");

        		IsoConnection_create(newconn850,self,data);							// настроим структуру дл€ работы

        		AcseConnection_init(&acseConnection);
        	    //AcseConnection_setAuthenticationParameter(&acseConnection,IsoServer_getAuthenticationParameter(self->isoServer));


        		while (netconn_recv(newconn850, &buf850) == ERR_OK)					// принимаем данные в буфер
                {
                    do
                    {

                    netbuf_data(buf850,(void *)&data, &len);						// указатель получил адрес вх. данных и его размер
                    self->cotpConnection->readBuffer->buffer = data;
                    self->cotpConnection->readBuffer->maxSize = len;

                    ByteBuffer_wrap(&responseBuffer, self->send_buf_1, 0, SEND_BUF_SIZE);	// буфер подготовки данных дл€ передачи в TCP/IP

                    // ёзер данные перекладываем в Payload буфер
                    cotpIndication = CotpConnection_parseIncomingMessage(self->cotpConnection);	// парсим пакет и возвращаем тип соединени€, ёзер данные перекладываем в Payload буфер
                    switch (cotpIndication) {
                        case CONNECT_INDICATION:
                        	USART_TRACE("ISO 8073 COTP connection indication\n");
                        	CotpConnection_sendConnectionResponseMessage(self->cotpConnection);
                        break;

                        case DATA_INDICATION:
                        {
                        	USART_TRACE("ISO 8073 COTP data indication\n");

                            ByteBuffer* 			cotpPayload = CotpConnection_getPayload(self->cotpConnection);		// получаем адрес сообщени€
                            IsoSessionIndication	sIndication = IsoSession_parseMessage(self->session, cotpPayload);	// парсим Session сообщение
                            ByteBuffer*				sessionUserData = IsoSession_getUserData(self->session);			// iso8823 OSI Presentation protocol

                            switch (sIndication) {
                            IsoPresentationIndication 	pIndication;

                        		case SESSION_OK:
                        			USART_TRACE("iso_connection: session ok\n");
                        			break;

                            	case SESSION_CONNECT:
                            		USART_TRACE("iso_connection: session connect indication\n");
                            		pIndication = IsoPresentation_parseConnect(self->presentation, sessionUserData);	// парсим Presentation сообщение
                            		if (pIndication == PRESENTATION_OK) {
                                        ByteBuffer* 	acseBuffer;
                                        AcseIndication 	aIndication;
                                        ByteBuffer 		mmsRequest;

                            			USART_TRACE("iso_connection: presentation ok\n");
                            			acseBuffer = &(self->presentation->nextPayload);
                            			aIndication = AcseConnection_parseMessage(&acseConnection, acseBuffer);
                            			if (aIndication == ACSE_ASSOCIATE) {
                            				USART_TRACE("cotp_server: acse associate\n");

                            				ByteBuffer_wrap(&mmsRequest, acseConnection.userDataBuffer,acseConnection.userDataBufferSize, acseConnection.userDataBufferSize);

                            				if (self->cotpConnection->payload->currPos > 0) {
                            					USART_TRACE("iso_connection: application payload size: %i\n", self->cotpConnection->payload->currPos);

                            					// пишем в writeBuffer заголовок ISO 8650-1 (AARQ 24 байта) + содержимое payload (user infirmation)
                            					AcseConnection_createAssociateResponseMessage(&acseConnection,ACSE_RESULT_ACCEPT, self->cotpConnection->writeBuffer, self->cotpConnection->payload);
                            					self->cotpConnection->payload->currPos = 0;
                            					//  пишем в payload ISO 8823 + содержимое writeBuffer (AARQ + user infirmation)
                            					IsoPresentation_createCpaMessage(self->presentation, self->cotpConnection->payload,self->cotpConnection->writeBuffer);
                            					// с этого момента в payload->buffer с лежит блок: ISO 8823 + ISO 8650-1 + MMS
                            					// до TCP уровн€ осталось ISO 8327-1 (SPDU), ISO 8073 (COTP), TPKT

                            					self->cotpConnection->writeBuffer->currPos = 0;							// обнулим укозатель дл€ формировани€ хвоста начина€ с ISO 8327-1
                            					responseBuffer.currPos = 0;

                            					// формитуем в буфере writeBuffer конструкцию AcceptSpdu ( ISO 8327-1 OSI Session protocol )
                            					//IsoSession_createAcceptSpdu(self->session, self->cotpConnection->writeBuffer,self->cotpConnection->payload->currPos);
                            					IsoSession_createAcceptSpdu(self->session,&responseBuffer,self->cotpConnection->payload->currPos);

                            					// дополн€ем его буфером payload->buffer (ISO 8823 + ISO 8650-1 + MMS)
                            					//ByteBuffer_append(self->cotpConnection->writeBuffer, self->cotpConnection->payload->buffer,self->cotpConnection->payload->currPos);
                            					ByteBuffer_append(&responseBuffer, self->cotpConnection->payload->buffer,self->cotpConnection->payload->currPos);

                            					// добавл€ем TPKT и ISO 8073 (COTP) и отправл€ем всЄ в стек TCP/IP
                            					//CotpConnection_sendDataMessage(self->cotpConnection, self->cotpConnection->writeBuffer);
                            					CotpConnection_sendDataMessage(self->cotpConnection, &responseBuffer);
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
                            		USART_TRACE_RED("TODO: iso_connection: session data indication\n");
                            		break;

                            	case SESSION_GIVE_TOKEN:
                            		USART_TRACE("iso_connection: session give token\n");
                            		USART_TRACE_RED("TODO: iso_connection: session give token\n");
                            		break;

                            	case SESSION_ERROR:
                            		USART_TRACE_RED("iso_connection: session error\n");
                            		self->state = ISO_CON_STATE_STOPPED;
                            		break;

                            }// switch (sIndication)
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

                    USART_TRACE("Receive data from a netconn. %u bytes \n",len);

                	Port_Toggle(LED1);
                    }while (netbuf_next(buf850) >= 0);

                    //free(self->send_buf_1);										// освободим пам€ть
                    //USART_TRACE_RED("free(self->send_buf_1)\n");

                netbuf_delete(buf850);
                USART_TRACE_GREEN("netbuf_delete ...\n");
                }
            }
        	USART_TRACE_GREEN("Close netconn connection ...\n");
            netconn_close(newconn850);											// закрываем соединение
            netconn_delete(newconn850);											// освобождаем пам€ть
        }
		//! приЄм данных и обработка
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
 * IsoConnection_create
 *
 *************************************************************************/
IsoConnection	IsoConnection_create(struct netconn *conn, IsoConnection self, uint8_t* Inbuffer)
{

	self->cotpConnection = calloc(1, sizeof(CotpConnection));
	self->cotpConnection->readBuffer = ByteBuffer_create(NULL,RECEIVE_BUF_SIZE);
   	self->cotpConnection->payload = ByteBuffer_create(NULL,SEND_BUF_SIZE);

    self->session = calloc(1, sizeof(IsoSession));
    IsoSession_init(self->session);

    self->presentation = calloc(1, sizeof(IsoPresentation));
    IsoPresentation_init(self->presentation);

	self->receive_buf = Inbuffer;
	self->send_buf_1 = malloc(SEND_BUF_SIZE);
	self->send_buf_2 = NULL;
	self->state = ISO_CON_STATE_RUNNING;
	self->clientAddress = Socket_getPeerAddress(newconn850);							// адрес клиента

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
}
