/* 
 * FreeModbus Libary: A portable Modbus implementation for Modbus ASCII/RTU.
 * Copyright (c) 2006 Christian Walter <wolti@sil.at>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * File: $Id: mbport.h,v 1.17 2006/12/07 22:10:34 wolti Exp $
 *            mbport.h,v 1.60 2013/08/17 11:42:56 Armink Add Master Functions  $
 */

#ifndef _MB_PORT_H
#define _MB_PORT_H

#ifdef __cplusplus
PR_BEGIN_EXTERN_C
#endif

#include <stdint.h>
/* ----------------------- Defines ------------------------------------------*/

/* ----------------------- Type definitions ---------------------------------*/

typedef enum
{
    EV_READY            = 1<<0,         /*!< Startup finished. */
    EV_FRAME_RECEIVED   = 1<<1,         /*!< Frame received. */
    EV_EXECUTE          = 1<<2,         /*!< Execute function. */
    EV_FRAME_SENT       = 1<<3          /*!< Frame sent. */
} eMBEventType;

typedef enum
{
    EV_TCPMB_READY            	= 1<<0,         /*!< Startup finished. */
    EV_TCPMB_REQUEST_RECEIVED   = 1<<1,         /*!< ������� ������ �� TCP */
    EV_TCPMB_REQUEST_SENT   	= 1<<2,         /*!< ��������� ������ �� TCP � 485 */
    EV_TCPMB_EXECUTE          	= 1<<3,         /*!< ��������� ������ �� 485, ���������� ������ � TCP */
    EV_TCPMB_RESPONSE_SENT     	= 1<<4          /*!< �������� ������ � TCP */
} eMBTCPEventType;

typedef enum
{
    EV_MASTER_READY                    = 1<<0,  /*!< Startup finished. */
    EV_MASTER_FRAME_RECEIVED           = 1<<1,  /*!< Frame received. */			// ����� ��������� ����� EV_MASTER_EXECUTE. �.�. ������ ��� ����� � ��.
    EV_MASTER_EXECUTE                  = 1<<2,  /*!< Execute function. */		//
    EV_MASTER_FRAME_SENT               = 1<<3,  /*!< Frame sent. */
    EV_MASTER_ERROR_PROCESS            = 1<<4,  /*!< Frame error process. */
//    EV_MASTER_PROCESS_SUCESS           = 1<<5,  /*!< Request process success. */
//    EV_MASTER_FRAME_SENT_WAIT	   	   = 1<<5, // ������� ��������� �������� ������. ������ ����� ����� ������.
    EV_MASTER_FRAME_RECEIVE_WAIT	   = 1<<6, // ������� ������ �� ������. ������ ����� ����� ������.
    EV_MASTER_FRAME_SENT_AFTER_WAIT	   = 1<<7, // ������ � ��������������� ��������� ������.
// ������� ������ � ������ ������. � ������ �������
//    EV_SLAVE_FRAME_RECEIVED           = 1<<7,
//    EV_SLAVE_EXECUTE                  = 1<<8,

} eMBMasterEventType;


typedef enum
{
    EV_ERROR_RESPOND_TIMEOUT,       // Slave respond timeout.
    EV_ERROR_RECEIVE_DATA,          // Receive frame data error.
    EV_ERROR_EXECUTE_FUNCTION,      // Execute function error.
    EV_ERROR_SENT_DATA,				// ������ �������� ���������. ����� ����������� ���� ����������
} eMBMasterErrorEventType;

/*! \ingroup modbus
 * \brief Parity used for characters in serial mode.
 *
 * The parity which should be applied to the characters sent over the serial
 * link. Please note that this values are actually passed to the porting
 * layer and therefore not all parity modes might be available.
 */
typedef enum
{
    MB_PAR_NONE,                /*!< No parity. */
    MB_PAR_ODD,                 /*!< Odd parity. */
    MB_PAR_EVEN                 /*!< Even parity. */
} eMBParity;

/* ----------------------- Supporting functions -----------------------------*/
BOOL            xMBPortEventInit( void );

BOOL            xMBPortEventPost( eMBTCPEventType eEvent );

BOOL            xMBPortEventGet(  /*@out@ */ eMBTCPEventType * eEvent );

BOOL            xMBMasterPortEventInit( void );

BOOL            xMBMasterPortEventPost( eMBMasterEventType eEvent );

BOOL            xMBMasterPortEventClear( eMBMasterEventType eEvent );

BOOL            xMBMasterPortEventGet(  /*@out@ */ eMBMasterEventType * eEvent );

void            vMBMasterOsResInit( void );

BOOL            xMBMasterRunResTake( int32_t time );

void            vMBMasterRunResRelease( void );

/* ----------------------- Serial port functions ----------------------------*/

BOOL            xMBPortSerialInit( UCHAR ucPort, ULONG ulBaudRate,
                                   UCHAR ucDataBits, eMBParity eParity );

void            vMBPortClose( void );

void            xMBPortSerialClose( void );

void            vMBPortSerialEnable( BOOL xRxEnable, BOOL xTxEnable );

INLINE BOOL     xMBPortSerialGetByte( CHAR * pucByte );

INLINE BOOL     xMBPortSerialPutByte( CHAR ucByte );

BOOL            xMBMasterPortSerialInit( UCHAR ucPort, ULONG ulBaudRate,
                                   UCHAR ucDataBits, eMBParity eParity );

void            vMBMasterPortClose( void );

void            xMBMasterPortSerialClose( void );

void            vMBMasterPortSerialEnable( BOOL xRxEnable, BOOL xTxEnable );

BOOL     xMBMasterPortSerialGetByte( CHAR * pucByte );

BOOL     xMBMasterPortSerialPutByte( CHAR ucByte );

BOOL     xMBMasterPortSerialPutBUF( CHAR * putBuf, USHORT leng );

BOOL     xMBMasterPortSerialGetBuf(UCHAR pos, CHAR * pucByte );

/* ----------------------- Timers functions ---------------------------------*/
BOOL            xMBPortTimersInit( uint32_t usTimeOut_ns);
void            xMBPortTimersClose( void );

void     vMBPortTimersEnable( void );
void     vMBPortTimersDisable( void );

BOOL     	xMBMasterPortTimersInit( USHORT usTimeOut50us );
void     	xMBMasterPortTimersClose( void );

void     vMBMasterPortTimersRespondTimeoutEnable( void );
void     vMBMasterPortTimersAfterRespondTimeoutEnable( void );

void     vMBMasterPortTimersDisable( void );

/* ----------------- Callback for the master error process ------------------*/
void            vMBMasterErrorCBRespondTimeout( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength );
void            vMBMasterErrorCBReceiveData( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength );
void            vMBMasterErrorCBSendData( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength );
void            vMBMasterErrorCBExecuteFunction( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength );

void			vMBMasterErrorCBIncCntErr( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength );


void            vMBMasterCBRequestScuuess( void );

/* ----------------------- Callback for the protocol stack ------------------*/

/*!
 * \brief Callback function for the porting layer when a new byte is
 *   available.
 *
 * Depending upon the mode this callback function is used by the RTU or
 * ASCII transmission layers. In any case a call to xMBPortSerialGetByte()
 * must immediately return a new character.
 *
 * \return <code>TRUE</code> if a event was posted to the queue because
 *   a new byte was received. The port implementation should wake up the
 *   tasks which are currently blocked on the eventqueue.
 */
extern          BOOL( *pxMBFrameCBByteReceived ) ( void );

extern          BOOL( *pxMBFrameCBTransmitterEmpty ) ( void );

extern          BOOL( *pxMBPortCBTimerExpired ) ( void );

extern          BOOL( *pxMBMasterFrameCBByteReceived ) ( void );

extern          BOOL( *pxMBMasterFrameCBTransmitterEmpty ) ( void );

extern          BOOL( *pxMBMasterPortCBTimerExpired ) ( void );

extern			BOOL( *pxMBMasterPortCBStartIdle ) ( void );


/* ----------------------- TCP port functions -------------------------------*/
BOOL            xMBTCPPortInit( USHORT usTCPPort );

void            vMBTCPPortClose( void );

void            vMBTCPPortDisable( void );

BOOL            xMBTCPPortGetRequest( UCHAR **ppucMBTCPFrame, USHORT * usTCPLength );

USHORT			xMBTCPPortGetRequestSize(void);

void			xMBTCPPortSetResponseSize(USHORT usTCPLength );

BOOL            xMBTCPPortSendResponse( const UCHAR *pucMBTCPFrame, USHORT usTCPLength );

#ifdef __cplusplus
PR_END_EXTERN_C
#endif
#endif
