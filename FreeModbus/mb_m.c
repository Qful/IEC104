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

#include "iec61850_server.h"

#include "MBTCP_main.h"
#include "MBmaster.h"

// ������� -----------------------------
extern	xQueueHandle 	ModbusSentTime;			// ������� ��� �������� ������� ��������� ������
extern	xQueueHandle 	ModbusSentQueue;		// ������� ��� �������� � ������
extern	xQueueHandle 	ModbusSentQueueFromTCPMB;		// ������� �������� �� TCP/MB
//extern	xQueueHandle 	ModbusResponseQueue;	// ������� ��� �������� �������
extern	xQueueHandle 	Rd_SysNoteQueue;		// ������� ��� �������� ������� �������
extern	xQueueHandle 	Rd_ErrorNoteQueue;		// ������� ��� �������� ������� ������
extern	xQueueHandle 	Rd_OscNoteQueue;		// ������� ��� �������� ������� ������������
extern	xQueueHandle 	Rd_FileQueue;			// ������� ��� �������� ������
//extern	xQueueHandle 	Rd_UstavkiQueue;		// ������� ��� �������� �������
extern	xQueueHandle	Wr_GooseQueue;			// ������� �����
extern	xQueueHandle	xDebugUsartOut;			// ������� ��� �������� � ����������

extern TIM_HandleTypeDef   TimHandle;	// Timer handler declaration ��� ��������� MODBUS


extern	errMB_data	cntErrorMD;
extern  uint32_t	cntMBmessage;					// ������� ������� � MB.

#if MB_MASTER_RTU_ENABLED > 0 || MB_MASTER_ASCII_ENABLED > 0

#ifndef MB_PORT_HAS_CLOSE
#define MB_PORT_HAS_CLOSE 0
#endif

/* ----------------------- Static variables ---------------------------------*/

static UCHAR    				ucMBMasterDestAddress;
static BOOL     				xMBRunInMasterMode = FALSE;
static eMBMasterErrorEventType 	eMBMasterCurErrorType;

static UCHAR    				ucMBAddress;
static eMBMode  				eMBCurrentMode;

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
static peMBFrameSend 	peMBMasterFrameSendCur;
static pvMBFrameStart 	pvMBMasterFrameStartCur;
static pvMBFrameStop 	pvMBMasterFrameStopCur;
static peMBFrameReceive peMBMasterFrameReceiveCur;
static pvMBFrameClose 	pvMBMasterFrameCloseCur;

static peMBFrameSend 	peMBFrameSendCur;
static pvMBFrameStart 	pvMBFrameStartCur;
static pvMBFrameStop 	pvMBFrameStopCur;
static peMBFrameReceive peMBFrameReceiveCur;
static pvMBFrameClose 	pvMBFrameCloseCur;

/* Callback functions required by the porting layer. They are called when
 * an external event has happend which includes a timeout or the reception
 * or transmission of a character.
 * Using for Modbus Master,Add by Armink 20130813
 */
BOOL( *pxMBMasterFrameCBByteReceived ) ( void );
BOOL( *pxMBMasterFrameCBTransmitterEmpty ) ( void );
BOOL( *pxMBMasterPortCBTimerExpired ) ( void );
BOOL( *pxMBMasterPortCBStartIdle ) ( void );

BOOL( *pxMBMasterFrameCBReceiveFSMCur ) ( void );
BOOL( *pxMBMasterFrameCBTransmitFSMCur ) ( void );


BOOL( *pxMBFrameCBByteReceived ) ( void );
BOOL( *pxMBFrameCBTransmitterEmpty ) ( void );
BOOL( *pxMBPortCBTimerExpired ) ( void );

BOOL( *pxMBFrameCBReceiveFSMCur ) ( void );
BOOL( *pxMBFrameCBTransmitFSMCur ) ( void );

// --------------------- ����������� MODBUS ������� --------------------------
/*******************************************************************
 * MASTER
 *******************************************************************/
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
#if MB_FUNC_READ_HOLDING_W_ADDR_ENABLED > 0
    {MB_FUNC_READ_HOLDING_REGISTER_W_ADDR, eMBMasterFuncReadRegisters},						// ������ ������ ������ �� ����������
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
/*******************************************************************
 * SLAVE
 *******************************************************************/
static xMBFunctionHandler xFuncHandlers[MB_FUNC_HANDLERS_MAX] = {
#if MB_FUNC_OTHER_REP_SLAVEID_ENABLED > 0
    {MB_FUNC_OTHER_REPORT_SLAVEID, eMBFuncReportSlaveID},
#endif
#if MB_FUNC_READ_INPUT_ENABLED > 0
    {MB_FUNC_READ_INPUT_REGISTER, eMBFuncReadInputRegister},
#endif
#if MB_FUNC_READ_HOLDING_ENABLED > 0
    {MB_FUNC_READ_HOLDING_REGISTER, eMBFuncReadHoldingRegister},
#endif
#if MB_FUNC_WRITE_MULTIPLE_HOLDING_ENABLED > 0
    {MB_FUNC_WRITE_MULTIPLE_REGISTERS, eMBFuncWriteMultipleHoldingRegister},
#endif
#if MB_FUNC_WRITE_HOLDING_ENABLED > 0
    {MB_FUNC_WRITE_REGISTER, eMBFuncWriteHoldingRegister},
#endif
#if MB_FUNC_READWRITE_HOLDING_ENABLED > 0
    {MB_FUNC_READWRITE_MULTIPLE_REGISTERS, eMBFuncReadWriteMultipleHoldingRegister},
#endif
#if MB_FUNC_READ_COILS_ENABLED > 0
    {MB_FUNC_READ_COILS, eMBFuncReadCoils},
#endif
#if MB_FUNC_WRITE_COIL_ENABLED > 0
    {MB_FUNC_WRITE_SINGLE_COIL, eMBFuncWriteCoil},
#endif
#if MB_FUNC_WRITE_MULTIPLE_COILS_ENABLED > 0
    {MB_FUNC_WRITE_MULTIPLE_COILS, eMBFuncWriteMultipleCoils},
#endif
#if MB_FUNC_READ_DISCRETE_INPUTS_ENABLED > 0
    {MB_FUNC_READ_DISCRETE_INPUTS, eMBFuncReadDiscreteInputs},
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
		pxMBMasterPortCBStartIdle = xMBMasterRTUStartIdle;							// ���������� ��������� �����, ��� ���� � ������� ������

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
 * ������� ������������ ������� � ��������� xMasterOsEvent �� �����.
 *
 * ��������� �������� ���� ���� ������ ��������� ������
 * ��� ��������� �������� ������� �� �������. ���� ����������� ��� ������ ��� �������� ����� ��������.
 *
 * ���� ��������� eMBMasterEventType == EV_MASTER_FRAME_RECEIVE_WAIT ����� ��������� ����� ������� ��������
 * ���� ������ �� ������� ��� ���������� �� �����. ����� ������������� ������ ��� ��������� �������� ���������� �������
 *************************************************************************/
eMBErrorCode
eMBMasterPoll( void )
{
    UCHAR   					*ucMBFrame;
    UCHAR    					ucRcvAddress;
    UCHAR    					ucFunctionCode;
    USHORT   					usLength;
    eMBException 				eException;

    UCHAR   					*ucMBTCPFrame;
    USHORT   					*usTCPLength;

    int             			i;
    eMBErrorCode    			eStatus = MB_ENOERR;
    eMBMasterEventType    		eEvent = 0;
    eMBMasterErrorEventType 	errorType;


    if( eMBState != STATE_ENABLED )        return MB_EILLSTATE;	 	// ��������, ����� �� ������ ��� ������

restart:

    // ����� ������������ ��� ������� ���� �� ���������
    while(xMBMasterPortEventGet( &eEvent ) == TRUE)
    {
        switch ( eEvent )
        {
/*********************************************************************************
 * ��������� ������������� ������
 *********************************************************************************/
		case EV_MASTER_READY:
			break;
/*********************************************************************************
 * ��� ������ �� �������
 *********************************************************************************/
        case EV_MASTER_FRAME_RECEIVE_WAIT:
        	if (vMBMasterGetCurTimerMode()== MB_TMODE_STOP){
				xMBMasterPortEventClear(EV_MASTER_FRAME_RECEIVE_WAIT);
        	}
			break;
/*********************************************************************************
 * �������� �������� ������ �� �����������
 * ��������� ��� ������ ���������.
 *********************************************************************************/
        case EV_MASTER_FRAME_RECEIVED:															// ������� �����, �������� �� ����������� � ����������

			// ��� TCP/Modbus ����� ��������� ������� ���������. � �������������� �� ����� �� ������ �������
// ---------------------------------------------------
// ������ TCP modbus
			if (SendRequestWithWait == eMBTCPGetState())
			{
				eMBTCPSetState(Stopped);
	    		  // ����� ���������� �������� ������ ����� ��������� TCP/Modbus
	    		  xMBTCPPortGetBuff(&ucMBTCPFrame, &usTCPLength);
	    		  // ������ �������� �� ������ ucMBFrame �������� �� �����
	    		  eStatus = peMBMasterFrameReceiveCur( &ucRcvAddress, &ucMBFrame, usTCPLength );		// �������� ��������� ������. Address, Length, Frame
	    		  if ((eStatus == MB_ERECV )&&(*usTCPLength < MB_TCP_BUF_SIZE)){

		    	    memcpy(ucMBTCPFrame,ucMBFrame,*usTCPLength);
	            	eStatus = MB_ENOERR;			// ��� ��� EXECUTE �� �������� ������ ������, ����� ������� �� ������� � ��������� ������

	    		  } else{
						USART_TRACE_RED("EV_MASTER_FRAME_RECEIVED - %u\n",eStatus);
						vMBMasterSetErrorType( EV_ERROR_RECEIVE_DATA);
						xMBMasterPortEventPost( EV_MASTER_ERROR_PROCESS );

						if (  eStatus == MB_CRCERR_Rx ) 	cntErrorMD.errALLCRC++;
	    		  }

	              ( void )xMBPortEventPost( EV_TCPMB_EXECUTE );									// ��������� � ����� �������� ������

			}else{
// ---------------------------------------------------
// ������� ����� ������
			eStatus = peMBMasterFrameReceiveCur( &ucRcvAddress, &ucMBFrame, &usLength );			// �������� ��������� ������. Address, Length, Frame

				if ( eStatus == MB_ERECV  )
				{
					cntMBmessage++; 																// ���������� ����� �������
					xMBMasterPortEventPost( EV_MASTER_EXECUTE );									// ���� ���, �� ��������� � ���������� ������ � �������.
				}
				else{
					USART_TRACE_RED("EV_MASTER_FRAME_RECEIVED - %u\n",eStatus);
					vMBMasterSetErrorType( EV_ERROR_RECEIVE_DATA);
					xMBMasterPortEventPost( EV_MASTER_ERROR_PROCESS );

					if (  eStatus == MB_CRCERR_Rx ) 	cntErrorMD.errALLCRC++;
				}
			}
// ---------------------------------------------------
			//if (WaitPreResponse == eMBTCPGetState())  eMBTCPSetState(SendRequestWithWait);

			break;
/*********************************************************************************
 * ��������� �������� ������
 * ��������� ��� � ������ ������.
 *********************************************************************************/
        case EV_MASTER_EXECUTE:
        	ucFunctionCode = ucMBFrame[MB_PDU_FUNC_OFF];										// ���� �� �������� ������ ��� �������
            eException = MB_EX_ILLEGAL_FUNCTION;

            if(ucFunctionCode >> 7) {															// ������� ��� ��������� �� ����� �� ������.
            	eException = (eMBException)ucMBFrame[MB_PDU_DATA_OFF];
            }
			else																				// ���������� ����� ������.
			{
// ----------------------------------------------------------------------------
// ������� ����������� ������ �� ������
// MASTER MODE
// ----------------------------------------------------------------------------
				if (ucRcvAddress == MB_SlaveAddres){
					for (i = 0; i < MB_FUNC_HANDLERS_MAX; i++)										// ���� ������� ����������
					{
						if (xMasterFuncHandlers[i].ucFunctionCode == 0)		break;					// ������ ��� ������������ �������, ������� �� ������ �����������.
						else if (xMasterFuncHandlers[i].ucFunctionCode == ucFunctionCode)
						{
							eException = xMasterFuncHandlers[i].pxHandler(ucMBFrame, &usLength);	// ���������� ��� ���������� �������.
							break;
						}
					}
				}
// ----------------------------------------------------------------------------
// ������� ����������� ������ �� �������
// SLAVE MODE
// ----------------------------------------------------------------------------
				if (ucRcvAddress == MB_MasterAddres){
					for( i = 0; i < MB_FUNC_HANDLERS_MAX; i++ )
					{
						if( xFuncHandlers[i].ucFunctionCode == 0 )	break;
						else if( xFuncHandlers[i].ucFunctionCode == ucFunctionCode )
						{
							eException = xFuncHandlers[i].pxHandler( ucMBFrame, &usLength );
							break;
						}
					}
					// ��� ����� ������� ��������� ������������� �����. ��� ����� � ������� ���� ��� �������, ������, �����������
					// ������ ����� ������� � ������ ������� �������.
				}
// ----------------------------------------------------------------------------
// !!
// ----------------------------------------------------------------------------
			}
            // �������� ������:
            // 1 - ���� ��� ����������� �������.
            // 2 - ���� ������ ����� � ����������� �� ������.
            if (eException != MB_EX_NONE) {
            	vMBMasterSetErrorType(EV_ERROR_EXECUTE_FUNCTION);
            	xMBMasterPortEventPost( EV_MASTER_ERROR_PROCESS );
            }
            else {
            // ���� ������� ����������
            	eStatus = MB_ENOERR;
            	vMBMasterCBRequestScuuess();
            	//eStatus = MB_ERECVDATA;
            }
            break;
/*********************************************************************************
 * �������� �������������� ������ (ucMasterRTUSndBuf)
 * ���� ������, �� ���������� ������� ��������(EV_MASTER_FRAME_RECEIVE_WAIT)
 *********************************************************************************/
        case EV_MASTER_FRAME_SENT:

        	vMBMasterGetPDUSndBuf( &ucMBFrame );
        	{
				uint8_t		reSend = 50;	// ������� ��������. ������ ����� ������ �� HAL_UART_Transmit_DMA)
				while(eStatus != MB_ESENT){
					reSend --; if (reSend == 0) break;
					// ����� ���� ����� �������� ��� ������ ������������ � ������ ������. ��������� �������� ����� ����� ����� �������� ������ ��� �������� ��� ������.
					// -------------------------------------------------------
					uint16_t	Len = usMBMasterGetPDUSndLength();
					uint8_t		adr =  ucMBMasterGetDestAddress();
					if (adr == 0) adr = 1;
					if (Len == 0) {Len = 5;
						USART_0TRACE("fsl:%u|%u|0x%X\n",Len,adr,ucMBFrame);
					}
					eStatus = peMBMasterFrameSendCur( adr, ucMBFrame, Len );
					if (eStatus != MB_ESENT){
						USART_TRACE_RED("MB_EIO_Tx: %u ������� ��������. eStatus:%u\n",50-reSend,eStatus);
						vTaskDelay(1);		// ������� �������
					}
				}
        	}
			if (eStatus == MB_ESENT){
			    // ���� ��������� � ���������� �� ��������� ��������. ����� ������ �������� � ����������� ����� ��� ������
			    //xMBMasterPortEventPost( EV_MASTER_FRAME_RECEIVE_WAIT );	// ��� ��������� ��������
				//vMBMasterPortTimersRespondTimeoutEnable( );				// �� ������ ������� �������� ������

			    // ������ ������ �� MB_ENOERR. ���� ������� ���� �� ����� ������ MB_ESENT. �������� ��� ������� ������� �� �����������
			    eStatus = MB_ENOERR;
			}
        	// ������ �������� ������. �� ������ ��� ������������ ���������� �����.
        	if (eStatus == MB_EIO_Tx){
	        	USART_TRACE_RED("MODBUS MB_EIO_Tx\n");
	        	xMBMasterPortEventPost(EV_MASTER_ERROR_PROCESS);		// ��������� ������ ��������. ����� �������� ����� ������ � ���
            	vMBMasterSetErrorType(EV_ERROR_SENT_DATA);

        	}
             break;
/*********************************************************************************
 * ������� �� �������.
 *
 * 	EV_ERROR_RESPOND_TIMEOUT	- �� ��������� ������
 *  EV_ERROR_RECEIVE_DATA		- ������� � �������
 *  EV_ERROR_EXECUTE_FUNCTION	- �� ������� ���������� �������� ������
 *********************************************************************************/
        case EV_MASTER_ERROR_PROCESS:
			errorType = eMBMasterGetErrorType();			// ��� ������
			vMBMasterGetPDUSndBuf( &ucMBFrame );
			switch (errorType) {
			case EV_ERROR_RESPOND_TIMEOUT:
				vMBMasterErrorCBRespondTimeout(ucMBMasterGetDestAddress(),	ucMBFrame, usMBMasterGetPDUSndLength());
				break;
			case EV_ERROR_RECEIVE_DATA:
				vMBMasterErrorCBReceiveData(ucMBMasterGetDestAddress(),	ucMBFrame, usMBMasterGetPDUSndLength());
				break;
			case EV_ERROR_SENT_DATA:
				vMBMasterErrorCBSendData(ucMBMasterGetDestAddress(),	ucMBFrame, usMBMasterGetPDUSndLength());
				break;
			case EV_ERROR_EXECUTE_FUNCTION:
				vMBMasterErrorCBExecuteFunction(ucMBMasterGetDestAddress(),	ucMBFrame, usMBMasterGetPDUSndLength());
				break;
			}
			vMBMasterRunResRelease();
        	break;
// -------------------------------------------------------------------------------
        }
    }
    // ���������� ��� �������. ����� �������� ������ TCP � ������ �����
   	if (WaitPreResponse == eMBTCPGetState())	{
   		eMBTCPSetState(SendRequestWithWait);
   		// ����� ���������, ����� ���������� � ����� ��������� ���� ������.
   		goto restart;
   	}

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
