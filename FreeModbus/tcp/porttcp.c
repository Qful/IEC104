/*
 * FreeModbus Libary: lwIP Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id$
 */

/* ----------------------- System includes ----------------------------------*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "porttcp.h"

/* ----------------------- lwIP includes ------------------------------------*/
#include "lwip/api.h"
#include "lwip/tcp.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"

/* ----------------------- MBAP Header --------------------------------------*/
#define MB_TCP_UID          6
#define MB_TCP_LEN          4
#define MB_TCP_FUNC         7

/* ----------------------- Defines  -----------------------------------------*/
//#define MB_TCP_DEFAULT_PORT 502 		// TCP listening port.
//#define MB_TCP_BUF_SIZE     (256 + 7) 	// Must hold a complete Modbus TCP frame.

/* ----------------------- Prototypes ---------------------------------------*/
void            vMBPortEventClose( void );

#ifdef MB_TCP_DEBUG
void            vMBPortLog( eMBPortLogLevel eLevel, const CHAR * szModule, const CHAR * szFmt, ... );
#endif
/* ----------------------- Static variables ---------------------------------*/
static struct tcp_pcb *pxPCBListen;				// порт слушающий клиентов для соединения
static struct tcp_pcb *pxPCBClient;				// порт клиента

static UCHAR    aucTCPBuf[MB_TCP_BUF_SIZE];
static USHORT   usTCPBufPos;

static UCHAR   usTCPFuncReq;
static UCHAR   usTCPSizeReq;
static UCHAR   usTCPAddrReq;

/* ----------------------- Static functions ---------------------------------*/
static err_t    prvxMBTCPPortAccept( void *pvArg, struct tcp_pcb *pxPCB, err_t xErr );
static err_t    prvxMBTCPPortReceive( void *pvArg, struct tcp_pcb *pxPCB, struct pbuf *p, err_t xErr );
static void     prvvMBTCPPortError( void *pvArg, err_t xErr );


/********************************************************************************
 * xMBTCPPortInit конфигурация TCP порта
 ********************************************************************************/
BOOL	xMBTCPPortInit( USHORT usTCPPort )
{
    struct tcp_pcb *pxPCBListenNew, *pxPCBListenOld;
    BOOL            bOkay = FALSE;
    USHORT          usPort;

    if( usTCPPort == 0 )    usPort = MB_TCP_PORT_USE_DEFAULT;						// если не указан конкретный порт, открываем 502
    else        			usPort = (USHORT)usTCPPort;

    if( ( pxPCBListenNew = pxPCBListenOld = tcp_new() ) == NULL ){
        bOkay = FALSE;																// не получилось открыть порт
    }
    else
    if(tcp_bind(pxPCBListenNew, IP_ADDR_ANY, (u16_t)usPort ) != ERR_OK ){
        (void)tcp_close(pxPCBListenOld);        									// Ошибка привязки - возможно, неверное значение порта или используется.
        bOkay = FALSE;
    }
    else
    if((pxPCBListenNew = tcp_listen(pxPCBListenNew)) == NULL){
        (void)tcp_close(pxPCBListenOld);
        bOkay = FALSE;
    }
    else
    {
        tcp_accept(pxPCBListenNew, prvxMBTCPPortAccept);					// Регистрация колбэк функций для нового клиента.

        pxPCBListen = pxPCBListenNew;										// Все в порядке. Установим глобальную переменную.

		#ifdef MB_TCP_DEBUG
        vMBPortLog( MB_LOG_DEBUG, "MBTCP-ACCEPT", "Порт открыт и готов принимать.\r\n" );
		#endif
    }
    bOkay = TRUE;
return bOkay;
}

/********************************************************************************
 * prvvMBPortReleaseClient Закрываем соединение с клиентом
 ********************************************************************************/
void	prvvMBPortReleaseClient( struct tcp_pcb *pxPCB )
{
    if(pxPCB != NULL){
        if(tcp_close(pxPCB) != ERR_OK)
            tcp_abort(pxPCB);


        if( pxPCB == pxPCBClient ){
			#ifdef MB_TCP_DEBUG
            vMBPortLog( MB_LOG_DEBUG, "MBTCP-CLOSE", "Закрыто соединение с %d.%d.%d.%d.\r\n",
                        ip4_addr1( &( pxPCB->remote_ip ) ),
                        ip4_addr2( &( pxPCB->remote_ip ) ),
                        ip4_addr3( &( pxPCB->remote_ip ) ), ip4_addr4( &( pxPCB->remote_ip ) ) );
			#endif
            pxPCBClient = NULL;
        }

        if( pxPCB == pxPCBListen )	pxPCBListen = NULL;

    }
}

/********************************************************************************
 * vMBTCPPortClose Закрываем клиентский и слушающий порт
 ********************************************************************************/
void	vMBTCPPortClose(void)
{
    prvvMBPortReleaseClient(pxPCBClient);   	// Отключим открытый клиентский сокет.
    prvvMBPortReleaseClient(pxPCBListen);   	// Отключим открытый слушающий сокет.
    vMBPortEventClose();    					// Освободим ресурсы очереди событий.
}

/********************************************************************************
 * vMBTCPPortDisable Закрываем клиентский порт
 ********************************************************************************/
void	vMBTCPPortDisable( void )
{
    prvvMBPortReleaseClient(pxPCBClient);
}

/********************************************************************************
 * prvxMBTCPPortAccept принимаем новое (только одно) соединение
 ********************************************************************************/
err_t	prvxMBTCPPortAccept( void *pvArg, struct tcp_pcb *pxPCB, err_t xErr )
{
err_t	error;

    if( xErr != ERR_OK ) return xErr;

    if( pxPCBClient == NULL )						// Мы можем работать только с одним клиентом.
    {
        pxPCBClient = pxPCB;        				// регим клиента

        tcp_recv(pxPCB, prvxMBTCPPortReceive);		// привяжем функцию приёма данных prvxMBTCPPortReceive()
        tcp_err(pxPCB, prvvMBTCPPortError);			// привяжем функцию обработчика ошибок prvvMBTCPPortError()
        tcp_arg(pxPCB, pxPCB);						// укажем аргумент для передачи в функцию обработчика ошибок

        usTCPBufPos = 0;							// Сбросим буферы и переменные.

#ifdef MB_TCP_DEBUG
        vMBPortLog(MB_LOG_DEBUG, "MBTCP-ACCEPT", "Установлено соединение с %d.%d.%d.%d\r\n",
                    ip4_addr1(&(pxPCB->remote_ip)), ip4_addr2(&(pxPCB->remote_ip)),
                    ip4_addr3(&(pxPCB->remote_ip)), ip4_addr4(&(pxPCB->remote_ip)) );
#endif
        error = ERR_OK;
    }
    else{
        prvvMBPortReleaseClient(pxPCB);				// Мы можем работать только с одним клиентом.
        error = ERR_OK;
    }
return error;
}

/********************************************************************************
 * prvvMBTCPPortError  Вызывается в случае неустранимой ошибки.
 * В любом случае мы удаляем клиентское соединение.
 ********************************************************************************/
void	prvvMBTCPPortError( void *pvArg, err_t xErr )
{
struct tcp_pcb *pxPCB = pvArg;

    if( pxPCB != NULL )
    {
		#ifdef MB_TCP_DEBUG
        vMBPortLog( MB_LOG_DEBUG, "MBTCP-ERROR", "Ошибка соединения! Разрываем.\r\n" );
		#endif
        prvvMBPortReleaseClient(pxPCB);
    }
}

/********************************************************************************
 * prvxMBTCPPortReceive функция приёма из ether стека.
 ********************************************************************************/
err_t	prvxMBTCPPortReceive( void *pvArg, struct tcp_pcb *pxPCB, struct pbuf *p, err_t xErr ){

USHORT	usLength;
err_t	error;

    if(xErr != ERR_OK)   return xErr;

    if(p == NULL){							   					// Если pbuf равен NULL, то удаленный порт закрыл соединение.
        prvvMBPortReleaseClient(pxPCB);
        return ERR_OK;
    }

    tcp_recved(pxPCB, p->len);							    	// Подтверждаем, что мы получили данные.

    if((usTCPBufPos + p->len) >= MB_TCP_BUF_SIZE){		    	// Проверим переполнение внутреннего буфера. В случае ошибки сбросим клиента.
        prvvMBPortReleaseClient(pxPCB);
        error = ERR_OK;
    }
    else{
        memcpy( &aucTCPBuf[usTCPBufPos], p->payload, p->len );	// копируем принятые данные в буфер для дальнейшей обработки
        usTCPBufPos += p->len;

        if (usTCPBufPos>255){
			#ifdef MB_TCP_DEBUG
			vMBPortLog(MB_LOG_DEBUG, "MBTCP-ERROR", "usTCPBufPos += p->len > 255\r\n" );
			#endif
        }

        // Если мы получили  больше чем заголовок Modbus/TCP берём размер из заголовка. Если завершено, уведомить стек протоколов.
        if(usTCPBufPos >= MB_TCP_FUNC)
        {
            // Length это количество байтов Modbus PDU (код функции + данные) и идентификатор устройства.
            usLength = aucTCPBuf[MB_TCP_LEN] << 8U;
            usLength |= aucTCPBuf[MB_TCP_LEN + 1];

            // Фрейм принят ----------------------------------
            if(usTCPBufPos < (MB_TCP_UID + usLength)){
            	// меньше чем нужно
				#ifdef MB_TCP_DEBUG
				vMBPortLog(MB_LOG_DEBUG, "MBTCP-WARNING", "Приняли мало данных. ждём...\r\n" );
				#endif
            }else
            if( usTCPBufPos == (MB_TCP_UID + usLength) ){
            	// нужный размер
				#ifdef MB_TCP_DEBUG
                prvvMBTCPLogFrame("MBTCP-RECV", &aucTCPBuf[0], usTCPBufPos);
				#endif
                (void)xMBPortEventPost( EV_TCPMB_REQUEST_RECEIVED );
            }else
            {
            	// больше чем ожидаем. Этого не должно быть.
				#ifdef MB_TCP_DEBUG
                vMBPortLog(MB_LOG_DEBUG, "MBTCP-ERROR", "Приняли много данных! отключаем клиента.\r\n" );
				#endif
                prvvMBPortReleaseClient(pxPCB);               // закрываем соединение
            }
            //! Фрейм принят ----------------------------------
        }
    }
    pbuf_free(p);
    return error;
}

/********************************************************************************
 * xMBTCPPortGetRequest забираем запрос
 ********************************************************************************/
BOOL	xMBTCPPortGetRequest( UCHAR ** ppucMBTCPFrame, USHORT * usTCPLength )
{
    *ppucMBTCPFrame = &aucTCPBuf[0];
    *usTCPLength = usTCPBufPos;

    usTCPBufPos = 0;			// обнуляем счётчик принятых
return TRUE;
}

/********************************************************************************
 * xMBTCPPortGetRequestSize размер запроса
 ********************************************************************************/
USHORT	xMBTCPPortGetRequestSize(void)
{
    return usTCPBufPos;
}
/********************************************************************************
 * xMBTCPPortSetResponseSize указываем размер ответа
 ********************************************************************************/
void	xMBTCPPortSetResponseSize(USHORT usTCPLength )
{

    usTCPBufPos = usTCPLength;
    if (usTCPBufPos>255){

		#ifdef MB_TCP_DEBUG
		vMBPortLog(MB_LOG_DEBUG, "MBTCP-ERROR", "usTCPBufPos>255\r\n" );
		#endif
    }
}

/********************************************************************************
 * xMBTCPPortSendResponse указываем ответ
 ********************************************************************************/
BOOL	xMBTCPPortSendResponse( const UCHAR * pucMBTCPFrame, USHORT usTCPLength )
{
BOOL	bFrameSent = FALSE;

    if( pxPCBClient ){
        assert(tcp_sndbuf( pxPCBClient ) >= usTCPLength);        // мы можем отправить пакет ??

        if(tcp_write(pxPCBClient, pucMBTCPFrame,(u16_t)usTCPLength, NETCONN_COPY ) == ERR_OK)
        {
			#ifdef MB_TCP_DEBUG
            prvvMBTCPLogFrame("MBTCP-SENT", &aucTCPBuf[0], usTCPLength);
			#endif
            (void)tcp_output(pxPCBClient);            			// отправляем немедленно.
            bFrameSent = TRUE;
        }else
        {
            prvvMBPortReleaseClient(pxPCBClient);				// Отключим соединение в случае ошибки записи.
        }
    }
    return bFrameSent;
}
/*************************************************************************
 * xMBTCPPortGetBuff получаем указатель только на Modbus из буфера
 * начиная с &aucTCPBuf[7] пакет модбас без адреса устройства и без CRC
 *************************************************************************/
bool	xMBTCPPortGetBuff( UCHAR ** ppucMBTCPFrame, USHORT ** usTCPLength )
{
    *ppucMBTCPFrame = &aucTCPBuf[7];
    *usTCPLength = &usTCPBufPos;

    return TRUE;
}
/*************************************************************************
 * xMBTCPPortSetReq
 * запоминаем адрес команду и размер запроса
 *************************************************************************/
void	xMBTCPPortSetReq(UCHAR Addr, UCHAR Func, UCHAR Size )
{
	usTCPAddrReq = Addr;
	usTCPFuncReq = Func;
	usTCPSizeReq = Size;
}
/*************************************************************************
 * xMBTCPPortGetFuncReq
 * команда Modbus
 *************************************************************************/
UCHAR	xMBTCPPortGetFuncReq( void )
{
    return usTCPFuncReq;
}
/*************************************************************************
 * xMBTCPPortGetSizeReq
 * размер пакета Modbus
 *************************************************************************/
UCHAR	xMBTCPPortGetSizeReq( void )
{
    return usTCPSizeReq;
}
/*************************************************************************
 * xMBTCPPortGetSizeReq
 * адрес Modbus
 *************************************************************************/
UCHAR	xMBTCPPortGetAddrReq( void )
{
    return usTCPAddrReq;
}
