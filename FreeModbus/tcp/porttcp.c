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
static struct tcp_pcb *pxPCBListen;				// ���� ��������� �������� ��� ����������
static struct tcp_pcb *pxPCBClient;				// ���� �������

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
 * xMBTCPPortInit ������������ TCP �����
 ********************************************************************************/
BOOL	xMBTCPPortInit( USHORT usTCPPort )
{
    struct tcp_pcb *pxPCBListenNew, *pxPCBListenOld;
    BOOL            bOkay = FALSE;
    USHORT          usPort;

    if( usTCPPort == 0 )    usPort = MB_TCP_PORT_USE_DEFAULT;						// ���� �� ������ ���������� ����, ��������� 502
    else        			usPort = (USHORT)usTCPPort;

    if( ( pxPCBListenNew = pxPCBListenOld = tcp_new() ) == NULL ){
        bOkay = FALSE;																// �� ���������� ������� ����
    }
    else
    if(tcp_bind(pxPCBListenNew, IP_ADDR_ANY, (u16_t)usPort ) != ERR_OK ){
        (void)tcp_close(pxPCBListenOld);        									// ������ �������� - ��������, �������� �������� ����� ��� ������������.
        bOkay = FALSE;
    }
    else
    if((pxPCBListenNew = tcp_listen(pxPCBListenNew)) == NULL){
        (void)tcp_close(pxPCBListenOld);
        bOkay = FALSE;
    }
    else
    {
        tcp_accept(pxPCBListenNew, prvxMBTCPPortAccept);					// ����������� ������ ������� ��� ������ �������.

        pxPCBListen = pxPCBListenNew;										// ��� � �������. ��������� ���������� ����������.

		#ifdef MB_TCP_DEBUG
        vMBPortLog( MB_LOG_DEBUG, "MBTCP-ACCEPT", "���� ������ � ����� ���������.\r\n" );
		#endif
    }
    bOkay = TRUE;
return bOkay;
}

/********************************************************************************
 * prvvMBPortReleaseClient ��������� ���������� � ��������
 ********************************************************************************/
void	prvvMBPortReleaseClient( struct tcp_pcb *pxPCB )
{
    if(pxPCB != NULL){
        if(tcp_close(pxPCB) != ERR_OK)
            tcp_abort(pxPCB);


        if( pxPCB == pxPCBClient ){
			#ifdef MB_TCP_DEBUG
            vMBPortLog( MB_LOG_DEBUG, "MBTCP-CLOSE", "������� ���������� � %d.%d.%d.%d.\r\n",
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
 * vMBTCPPortClose ��������� ���������� � ��������� ����
 ********************************************************************************/
void	vMBTCPPortClose(void)
{
    prvvMBPortReleaseClient(pxPCBClient);   	// �������� �������� ���������� �����.
    prvvMBPortReleaseClient(pxPCBListen);   	// �������� �������� ��������� �����.
    vMBPortEventClose();    					// ��������� ������� ������� �������.
}

/********************************************************************************
 * vMBTCPPortDisable ��������� ���������� ����
 ********************************************************************************/
void	vMBTCPPortDisable( void )
{
    prvvMBPortReleaseClient(pxPCBClient);
}

/********************************************************************************
 * prvxMBTCPPortAccept ��������� ����� (������ ����) ����������
 ********************************************************************************/
err_t	prvxMBTCPPortAccept( void *pvArg, struct tcp_pcb *pxPCB, err_t xErr )
{
err_t	error;

    if( xErr != ERR_OK ) return xErr;

    if( pxPCBClient == NULL )						// �� ����� �������� ������ � ����� ��������.
    {
        pxPCBClient = pxPCB;        				// ����� �������

        tcp_recv(pxPCB, prvxMBTCPPortReceive);		// �������� ������� ����� ������ prvxMBTCPPortReceive()
        tcp_err(pxPCB, prvvMBTCPPortError);			// �������� ������� ����������� ������ prvvMBTCPPortError()
        tcp_arg(pxPCB, pxPCB);						// ������ �������� ��� �������� � ������� ����������� ������

        usTCPBufPos = 0;							// ������� ������ � ����������.

#ifdef MB_TCP_DEBUG
        vMBPortLog(MB_LOG_DEBUG, "MBTCP-ACCEPT", "����������� ���������� � %d.%d.%d.%d\r\n",
                    ip4_addr1(&(pxPCB->remote_ip)), ip4_addr2(&(pxPCB->remote_ip)),
                    ip4_addr3(&(pxPCB->remote_ip)), ip4_addr4(&(pxPCB->remote_ip)) );
#endif
        error = ERR_OK;
    }
    else{
        prvvMBPortReleaseClient(pxPCB);				// �� ����� �������� ������ � ����� ��������.
        error = ERR_OK;
    }
return error;
}

/********************************************************************************
 * prvvMBTCPPortError  ���������� � ������ ������������ ������.
 * � ����� ������ �� ������� ���������� ����������.
 ********************************************************************************/
void	prvvMBTCPPortError( void *pvArg, err_t xErr )
{
struct tcp_pcb *pxPCB = pvArg;

    if( pxPCB != NULL )
    {
		#ifdef MB_TCP_DEBUG
        vMBPortLog( MB_LOG_DEBUG, "MBTCP-ERROR", "������ ����������! ���������.\r\n" );
		#endif
        prvvMBPortReleaseClient(pxPCB);
    }
}

/********************************************************************************
 * prvxMBTCPPortReceive ������� ����� �� ether �����.
 ********************************************************************************/
err_t	prvxMBTCPPortReceive( void *pvArg, struct tcp_pcb *pxPCB, struct pbuf *p, err_t xErr ){

USHORT	usLength;
err_t	error;

    if(xErr != ERR_OK)   return xErr;

    if(p == NULL){							   					// ���� pbuf ����� NULL, �� ��������� ���� ������ ����������.
        prvvMBPortReleaseClient(pxPCB);
        return ERR_OK;
    }

    tcp_recved(pxPCB, p->len);							    	// ������������, ��� �� �������� ������.

    if((usTCPBufPos + p->len) >= MB_TCP_BUF_SIZE){		    	// �������� ������������ ����������� ������. � ������ ������ ������� �������.
        prvvMBPortReleaseClient(pxPCB);
        error = ERR_OK;
    }
    else{
        memcpy( &aucTCPBuf[usTCPBufPos], p->payload, p->len );	// �������� �������� ������ � ����� ��� ���������� ���������
        usTCPBufPos += p->len;

        if (usTCPBufPos>255){
			#ifdef MB_TCP_DEBUG
			vMBPortLog(MB_LOG_DEBUG, "MBTCP-ERROR", "usTCPBufPos += p->len > 255\r\n" );
			#endif
        }

        // ���� �� ��������  ������ ��� ��������� Modbus/TCP ���� ������ �� ���������. ���� ���������, ��������� ���� ����������.
        if(usTCPBufPos >= MB_TCP_FUNC)
        {
            // Length ��� ���������� ������ Modbus PDU (��� ������� + ������) � ������������� ����������.
            usLength = aucTCPBuf[MB_TCP_LEN] << 8U;
            usLength |= aucTCPBuf[MB_TCP_LEN + 1];

            // ����� ������ ----------------------------------
            if(usTCPBufPos < (MB_TCP_UID + usLength)){
            	// ������ ��� �����
				#ifdef MB_TCP_DEBUG
				vMBPortLog(MB_LOG_DEBUG, "MBTCP-WARNING", "������� ���� ������. ���...\r\n" );
				#endif
            }else
            if( usTCPBufPos == (MB_TCP_UID + usLength) ){
            	// ������ ������
				#ifdef MB_TCP_DEBUG
                prvvMBTCPLogFrame("MBTCP-RECV", &aucTCPBuf[0], usTCPBufPos);
				#endif
                (void)xMBPortEventPost( EV_TCPMB_REQUEST_RECEIVED );
            }else
            {
            	// ������ ��� �������. ����� �� ������ ����.
				#ifdef MB_TCP_DEBUG
                vMBPortLog(MB_LOG_DEBUG, "MBTCP-ERROR", "������� ����� ������! ��������� �������.\r\n" );
				#endif
                prvvMBPortReleaseClient(pxPCB);               // ��������� ����������
            }
            //! ����� ������ ----------------------------------
        }
    }
    pbuf_free(p);
    return error;
}

/********************************************************************************
 * xMBTCPPortGetRequest �������� ������
 ********************************************************************************/
BOOL	xMBTCPPortGetRequest( UCHAR ** ppucMBTCPFrame, USHORT * usTCPLength )
{
    *ppucMBTCPFrame = &aucTCPBuf[0];
    *usTCPLength = usTCPBufPos;

    usTCPBufPos = 0;			// �������� ������� ��������
return TRUE;
}

/********************************************************************************
 * xMBTCPPortGetRequestSize ������ �������
 ********************************************************************************/
USHORT	xMBTCPPortGetRequestSize(void)
{
    return usTCPBufPos;
}
/********************************************************************************
 * xMBTCPPortSetResponseSize ��������� ������ ������
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
 * xMBTCPPortSendResponse ��������� �����
 ********************************************************************************/
BOOL	xMBTCPPortSendResponse( const UCHAR * pucMBTCPFrame, USHORT usTCPLength )
{
BOOL	bFrameSent = FALSE;

    if( pxPCBClient ){
        assert(tcp_sndbuf( pxPCBClient ) >= usTCPLength);        // �� ����� ��������� ����� ??

        if(tcp_write(pxPCBClient, pucMBTCPFrame,(u16_t)usTCPLength, NETCONN_COPY ) == ERR_OK)
        {
			#ifdef MB_TCP_DEBUG
            prvvMBTCPLogFrame("MBTCP-SENT", &aucTCPBuf[0], usTCPLength);
			#endif
            (void)tcp_output(pxPCBClient);            			// ���������� ����������.
            bFrameSent = TRUE;
        }else
        {
            prvvMBPortReleaseClient(pxPCBClient);				// �������� ���������� � ������ ������ ������.
        }
    }
    return bFrameSent;
}
/*************************************************************************
 * xMBTCPPortGetBuff �������� ��������� ������ �� Modbus �� ������
 * ������� � &aucTCPBuf[7] ����� ������ ��� ������ ���������� � ��� CRC
 *************************************************************************/
bool	xMBTCPPortGetBuff( UCHAR ** ppucMBTCPFrame, USHORT ** usTCPLength )
{
    *ppucMBTCPFrame = &aucTCPBuf[7];
    *usTCPLength = &usTCPBufPos;

    return TRUE;
}
/*************************************************************************
 * xMBTCPPortSetReq
 * ���������� ����� ������� � ������ �������
 *************************************************************************/
void	xMBTCPPortSetReq(UCHAR Addr, UCHAR Func, UCHAR Size )
{
	usTCPAddrReq = Addr;
	usTCPFuncReq = Func;
	usTCPSizeReq = Size;
}
/*************************************************************************
 * xMBTCPPortGetFuncReq
 * ������� Modbus
 *************************************************************************/
UCHAR	xMBTCPPortGetFuncReq( void )
{
    return usTCPFuncReq;
}
/*************************************************************************
 * xMBTCPPortGetSizeReq
 * ������ ������ Modbus
 *************************************************************************/
UCHAR	xMBTCPPortGetSizeReq( void )
{
    return usTCPSizeReq;
}
/*************************************************************************
 * xMBTCPPortGetSizeReq
 * ����� Modbus
 *************************************************************************/
UCHAR	xMBTCPPortGetAddrReq( void )
{
    return usTCPAddrReq;
}
