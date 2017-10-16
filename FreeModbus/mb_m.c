/* 
 * FreeModbus Libary: A portable Modbus implementation for Modbus ASCII/RTU.
 * Copyright (C) 2013 Armink <armink.ztl@gmail.com>
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
 * File: $Id: mbrtu_m.c,v 1.60 2013/08/20 11:18:10 Armink Add Master Functions $
 */

/* ----------------------- System includes ----------------------------------*/
#include "stdlib.h"
#include "string.h"

//#include "queue.h"
/* ----------------------- Platform includes --------------------------------*/
#include "port.h"
#include "main.h"
/* ----------------------- Modbus includes ----------------------------------*/

#include "mb.h"
#include "mb_m.h"
#include "mbconfig.h"
#include "mbframe.h"
#include "mbproto.h"
#include "mbfunc.h"

#include "mbport.h"
#if MB_MASTER_RTU_ENABLED == 1
#include "mbrtu.h"
#endif
#if MB_MASTER_ASCII_ENABLED == 1
#include "mbascii.h"
#endif
#if MB_MASTER_TCP_ENABLED == 1
#include "mbtcp.h"
#endif

#include "modbus.h"

extern uint8_t		writeNmb;

#if MB_MASTER_RTU_ENABLED > 0 || MB_MASTER_ASCII_ENABLED > 0

#ifndef MB_PORT_HAS_CLOSE
#define MB_PORT_HAS_CLOSE 0
#endif

/* ----------------------- Static variables ---------------------------------*/

static UCHAR    				ucMBMasterDestAddress;
static BOOL     				xMBRunInMasterMode = FALSE;
static eMBMasterErrorEventType 	eMBMasterCurErrorType;

static enum
{
    STATE_ENABLED,
    STATE_DISABLED,
    STATE_NOT_INITIALIZED
} eMBState = STATE_NOT_INITIALIZED;

/* Functions pointer which are initialized in eMBInit( ). Depending on the
 * mode (RTU or ASCII) the are set to the correct implementations.
 * Using for Modbus Master,Add by Armink 20130813
 */
static peMBFrameSend peMBMasterFrameSendCur;
static pvMBFrameStart pvMBMasterFrameStartCur;
static pvMBFrameStop pvMBMasterFrameStopCur;
static peMBFrameReceive peMBMasterFrameReceiveCur;
static pvMBFrameClose pvMBMasterFrameCloseCur;

/* Callback functions required by the porting layer. They are called when
 * an external event has happend which includes a timeout or the reception
 * or transmission of a character.
 * Using for Modbus Master,Add by Armink 20130813
 */
BOOL( *pxMBMasterFrameCBByteReceived ) ( void );
BOOL( *pxMBMasterFrameCBTransmitterEmpty ) ( void );
BOOL( *pxMBMasterPortCBTimerExpired ) ( void );

BOOL( *pxMBMasterFrameCBReceiveFSMCur ) ( void );
BOOL( *pxMBMasterFrameCBTransmitFSMCur ) ( void );


// --------------------- ����������� MODBUS ������� --------------------------
//TODO Add Master function define

static xMBFunctionHandler xMasterFuncHandlers[MB_FUNC_HANDLERS_MAX] = {
#if MB_FUNC_OTHER_REP_SLAVEID_ENABLED > 0
    {MB_FUNC_OTHER_REPORT_SLAVEID, eMBFuncReportSlaveID},
#endif
#if MB_FUNC_READ_INPUT_ENABLED > 0
    {MB_FUNC_READ_INPUT_REGISTER, eMBMasterFuncReadInputRegister},
#endif
#if MB_FUNC_READ_HOLDING_ENABLED > 0
    {MB_FUNC_READ_HOLDING_REGISTER, eMBMasterFuncReadRegisters},							// ������ ������ ������ �� ����������
#endif
#if MB_FUNC_WRITE_MULTIPLE_HOLDING_ENABLED > 0
    {MB_FUNC_WRITE_MULTIPLE_REGISTERS, eMBMasterFuncWriteMultipleHoldingRegister},
#endif
#if MB_FUNC_WRITE_HOLDING_ENABLED > 0
    {MB_FUNC_WRITE_REGISTER, eMBMasterFuncWriteHoldingRegister},
#endif
#if MB_FUNC_READWRITE_HOLDING_ENABLED > 0
    {MB_FUNC_READWRITE_MULTIPLE_REGISTERS, eMBMasterFuncReadWriteMultipleHoldingRegister},
#endif
#if MB_FUNC_READ_COILS_ENABLED > 0
    {MB_FUNC_READ_COILS, eMBMasterFuncReadCoils},
#endif
#if MB_FUNC_WRITE_COIL_ENABLED > 0
    {MB_FUNC_WRITE_SINGLE_COIL, eMBMasterFuncWriteCoil},
#endif
#if MB_FUNC_WRITE_MULTIPLE_COILS_ENABLED > 0
    {MB_FUNC_WRITE_MULTIPLE_COILS, eMBMasterFuncWriteMultipleCoils},
#endif
#if MB_FUNC_READ_DISCRETE_INPUTS_ENABLED > 0
    {MB_FUNC_READ_DISCRETE_INPUTS, eMBMasterFuncReadDiscreteInputs},
#endif
};

/* ----------------------- Start implementation -----------------------------*/
eMBErrorCode
eMBMasterInit( eMBMode eMode, UCHAR ucPort, ULONG ulBaudRate, eMBParity eParity )
{
    eMBErrorCode    eStatus = MB_ENOERR;

	switch (eMode)
	{
#if MB_MASTER_RTU_ENABLED > 0
	case MB_RTU:
		pvMBMasterFrameStartCur = eMBMasterRTUStart;								// �������� ��� ������ t3.5 ������� ����� �� ������ ����� ��� ������.
		pvMBMasterFrameStopCur = eMBMasterRTUStop;									// ��������� ���������� MODBUS.
		peMBMasterFrameSendCur = eMBMasterRTUSend;									// �������� ������ � MODBUS.
		peMBMasterFrameReceiveCur = eMBMasterRTUReceive;							// ������� �������� ���������� �������� ������.
		pvMBMasterFrameCloseCur = MB_PORT_HAS_CLOSE ? vMBMasterPortClose : NULL;	// NULL
		pxMBMasterFrameCBByteReceived = xMBMasterRTUReceiveFSM;						// ������� ����� ������ �� MODBUS.
		pxMBMasterFrameCBTransmitterEmpty = xMBMasterRTUTransmitFSM;				// ������� ��������� �������� ������.
		pxMBMasterPortCBTimerExpired = xMBMasterRTUTimerExpired;					// ���������� ��������� �������

		eStatus = eMBMasterRTUInit(ucPort, ulBaudRate, eParity);
		break;
#endif
#if MB_MASTER_ASCII_ENABLED > 0
		case MB_ASCII:
		pvMBMasterFrameStartCur = eMBMasterASCIIStart;
		pvMBMasterFrameStopCur = eMBMasterASCIIStop;
		peMBMasterFrameSendCur = eMBMasterASCIISend;
		peMBMasterFrameReceiveCur = eMBMasterASCIIReceive;
		pvMBMasterFrameCloseCur = MB_PORT_HAS_CLOSE ? vMBMasterPortClose : NULL;
		pxMBMasterFrameCBByteReceived = xMBMasterASCIIReceiveFSM;
		pxMBMasterFrameCBTransmitterEmpty = xMBMasterASCIITransmitFSM;
		pxMBMasterPortCBTimerExpired = xMBMasterASCIITimerT1SExpired;

		eStatus = eMBMasterASCIIInit(ucPort, ulBaudRate, eParity );
		break;
#endif
	default:
		eStatus = MB_EINVAL;
		break;
	}

	if (eStatus == MB_ENOERR)
	{
		if (!xMBMasterPortEventInit())
		{
			/* port dependent event module initalization failed. */
			eStatus = MB_EPORTERR;
		}
		else
		{
			eMBState = STATE_DISABLED;
		}
		/* initialize the OS resource for modbus master. */
		vMBMasterOsResInit();
	}
	return eStatus;
}

eMBErrorCode
eMBMasterClose( void )
{
    eMBErrorCode    eStatus = MB_ENOERR;

    if( eMBState == STATE_DISABLED )
    {
        if( pvMBMasterFrameCloseCur != NULL )
        {
            pvMBMasterFrameCloseCur(  );
        }
    }
    else
    {
        eStatus = MB_EILLSTATE;
    }
    return eStatus;
}
/*************************************************************************
 * eMBMasterEnable
 * ����� MODBUS
 *************************************************************************/
eMBErrorCode
eMBMasterEnable( void )
{
    eMBErrorCode    eStatus = MB_ENOERR;

    if( eMBState == STATE_DISABLED )
    {
        /* Activate the protocol stack. */
        pvMBMasterFrameStartCur(  );			// �������� MODBUS � ����� �����.
        eMBState = STATE_ENABLED;
    }
    else
    {
        eStatus = MB_EILLSTATE;
    }
    return eStatus;
}
/*************************************************************************
 * eMBMasterEnable
 * ���� MODBUS
 *************************************************************************/
eMBErrorCode
eMBMasterDisable( void )
{
    eMBErrorCode    eStatus;

    if( eMBState == STATE_ENABLED )
    {
        pvMBMasterFrameStopCur(  );
        eMBState = STATE_DISABLED;
        eStatus = MB_ENOERR;
    }
    else if( eMBState == STATE_DISABLED )
    {
        eStatus = MB_ENOERR;
    }
    else
    {
        eStatus = MB_EILLSTATE;
    }
    return eStatus;
}

/*************************************************************************
 * eMBMasterPoll
 * ��� ������� ������ ���� ������� ������������. �������� ������� �� ����-���� Modbus Slave ����������.
 * ������ �������� ������� xMBMasterPortEventGet() � ���� ������� �� ����������� ��� ��������.
 *
 *************************************************************************/
eMBErrorCode
eMBMasterPoll( void )
{
    static UCHAR   		*ucMBFrame;
    static UCHAR    	ucRcvAddress;
    UCHAR    			ucFunctionCode;
    static USHORT   	usLength;
    static eMBException eException;

    int             			i , j;
    eMBErrorCode    			eStatus = MB_ENOERR;
    eMBMasterEventType    		eEvent = 0;
    eMBMasterErrorEventType 	errorType;

    if( eMBState != STATE_ENABLED )        return MB_EILLSTATE;	 	// ��������, ����� �� ������ ��� ������


    // ����� ������������ ��� ������� ���� �� ���������
//    if( xMBMasterPortEventGet( &eEvent ) == TRUE )					// �������� ���� �� ���� ���� ������� �� ����� ������ �������� ��� �����������
    while(xMBMasterPortEventGet( &eEvent ) == TRUE)
    {
        switch ( eEvent )
        {
        case EV_MASTER_ERROR_RESPOND_TIMEOUT:
			USART_TRACE_RED("EV_MASTER_ERROR_RESPOND_TIMEOUT\n");
        	break;
        case EV_MASTER_PROCESS_SUCESS:
			USART_TRACE_RED("EV_MASTER_PROCESS_SUCESS\n");
            break;
        case EV_MASTER_ERROR_EXECUTE_FUNCTION:
			USART_TRACE_RED("EV_MASTER_ERROR_EXECUTE_FUNCTION\n");
            break;
        case EV_MASTER_ERROR_RECEIVE_DATA:
			USART_TRACE_RED("EV_MASTER_PROCESS_SUCESS\n");
        	break;
        case EV_MASTER_READY:
			USART_TRACE_GREEN("MODBUS_EV_MASTER_READY\n");
            break;

        case EV_MASTER_FRAME_RECEIVED:															// ������� �����, �������� �� ����������� � ����������
			eStatus = peMBMasterFrameReceiveCur( &ucRcvAddress, &ucMBFrame, &usLength );
			Port_On(LED1);

			 xMBMasterPortEventClear(EV_MASTER_FRAME_RECEIVE_WAIT);

			if ( ( eStatus == MB_ERECV ) && ( ucRcvAddress == ucMBMasterGetDestAddress() ) )	// ��������, ��� �� ����� � ������ ��� ������.
			{
				( void ) xMBMasterPortEventPost( EV_MASTER_EXECUTE );							// ���� ���, �� ��������� � ���������� ������ � �������.
			}
			else
			{
//				eStatus = MB_ERECVDATAERROR;
				vMBMasterSetErrorType(EV_ERROR_RECEIVE_DATA);									// ���� �� ��� ��� ������ �� ��� � ���������� ������.
				( void ) xMBMasterPortEventPost( EV_MASTER_ERROR_PROCESS );
			}
			break;

        case EV_MASTER_EXECUTE:																	// ������� ���������� �����, ������������ ���. ��� ��������
 //       	USART_TRACE_GREEN("EXECUTE\n");

        	ucFunctionCode = ucMBFrame[MB_PDU_FUNC_OFF];										// ���� �� ������ ��� �������
            eException = MB_EX_ILLEGAL_FUNCTION;

            if(ucFunctionCode >> 7) {															// ������� ��� ��������� �� ����� �� ������.
            	eException = (eMBException)ucMBFrame[MB_PDU_DATA_OFF];
            }
			else																				// ���������� ����� ������.
			{
				for (i = 0; i < MB_FUNC_HANDLERS_MAX; i++)										// ���� ������� ����������
				{
					if (xMasterFuncHandlers[i].ucFunctionCode == 0)		break;					// ������ ��� ������������ �������, ������� �� ������ �����������.


					else if (xMasterFuncHandlers[i].ucFunctionCode == ucFunctionCode) {			// ��������� ���� �� ��� ������ ���� ������� ����������
						vMBMasterSetCBRunInMasterMode(TRUE);

						// ----------------------------------------------------------------------------------------------
						//  xMasterFuncHandlers[i].pxHandler(ucMBFrame, &usLength);	// ���������� ��� ���������� �������.
						//  ���������� � ����������� ��
						// ----------------------------------------------------------------------------------------------
						eStatus = MB_ERECVDATA;		//������� � ���������� ��������� ����� ������
//						xMBMasterPortEventClear(EV_MASTER_FRAME_RECEIVE_WAIT);

						// If master request is broadcast, the master need execute function for all slave.
						if ( xMBMasterRequestIsBroadcast() ) {
							usLength = usMBMasterGetPDUSndLength();
							for(j = 1; j <= MB_MASTER_TOTAL_SLAVE_NUM; j++){
								vMBMasterSetDestAddress(j);
								eException = xMasterFuncHandlers[i].pxHandler(ucMBFrame, &usLength);
							}
						}
						else {
							eException = xMasterFuncHandlers[i].pxHandler(ucMBFrame, &usLength);	// ���������� ��� ���������� �������.
						}
						vMBMasterSetCBRunInMasterMode(FALSE);
						break;
					}
				}

			}
            /* If master has exception ,Master will send error process.Otherwise the Master is idle.*/
            if (eException != MB_EX_NONE) {
            	vMBMasterSetErrorType(EV_ERROR_EXECUTE_FUNCTION);
            	( void ) xMBMasterPortEventPost( EV_MASTER_ERROR_PROCESS );
            }
            else {
            	vMBMasterCBRequestScuuess( );
            	vMBMasterRunResRelease( );
            }
            break;

        case EV_MASTER_FRAME_SENT:																						// �������� � ����
        	vMBMasterGetPDUSndBuf( &ucMBFrame );																		//ucMBFrame - ����� ��� �������� � MODBUS
        	while(eStatus != MB_ESENT){
        		eStatus = peMBMasterFrameSendCur( ucMBMasterGetDestAddress(), ucMBFrame, usMBMasterGetPDUSndLength() );		//���������� ������ � ��������� ��������.
        	}
			if (eStatus == MB_EIO ){
	        	USART_TRACE_RED("MODBUS ERROR_SENT_DATA I/O.\n");        												// ������ �������� ������. �� ������ ��� ������������ ���������� �����.
	        	return eStatus;
			} else{
			    ( void ) xMBMasterPortEventPost( EV_MASTER_FRAME_RECEIVE_WAIT );										// ���� �������� ������, ������ ����� ��������
			}
             break;

        case EV_MASTER_ERROR_PROCESS:			// ������� �� �������.

//        	Port_On(LED1);
			errorType = eMBMasterGetErrorType();
			vMBMasterGetPDUSndBuf( &ucMBFrame );
			switch (errorType) {
			case EV_ERROR_RESPOND_TIMEOUT:
	        	USART_TRACE_RED("MODBUS ERROR_RESPOND_TIMEOUT\n");
				vMBMasterErrorCBRespondTimeout(ucMBMasterGetDestAddress(),	ucMBFrame, usMBMasterGetPDUSndLength());
			    return	MB_ETIMEDOUT;
				break;
			case EV_ERROR_RECEIVE_DATA:
	        	USART_TRACE_RED("MODBUS ERROR_RECEIVE_DATA\n");
				vMBMasterErrorCBReceiveData(ucMBMasterGetDestAddress(),	ucMBFrame, usMBMasterGetPDUSndLength());
				break;
			case EV_ERROR_EXECUTE_FUNCTION:
	        	USART_TRACE_RED("MODBUS ERROR_EXECUTE_FUNCTION:\n");
				vMBMasterErrorCBExecuteFunction(ucMBMasterGetDestAddress(),	ucMBFrame, usMBMasterGetPDUSndLength());
				break;
			}
			vMBMasterRunResRelease();
        	break;
        }
    }
    /*
    else{
    	return MB_NOTASK;
    }
    */
//    eStatus = MB_NOTASK;
    return eStatus;
}

/* Get whether the Modbus Master is run in master mode.*/
BOOL xMBMasterGetCBRunInMasterMode( void )
{
	return xMBRunInMasterMode;
}
/* Set whether the Modbus Master is run in master mode.*/
void vMBMasterSetCBRunInMasterMode( BOOL IsMasterMode )
{
	xMBRunInMasterMode = IsMasterMode;
}
/* Get Modbus Master send destination address. */
UCHAR ucMBMasterGetDestAddress( void )
{
	return ucMBMasterDestAddress;
}
// Set Modbus Master send destination address. ����� ���������� '1'
void vMBMasterSetDestAddress( UCHAR Address )
{
	ucMBMasterDestAddress = Address;
}
/* Get Modbus Master current error event type. */
eMBMasterErrorEventType eMBMasterGetErrorType( void )
{
	return eMBMasterCurErrorType;
}
/* Set Modbus Master current error event type. */
void vMBMasterSetErrorType( eMBMasterErrorEventType errorType )
{
	eMBMasterCurErrorType = errorType;
}


#endif
