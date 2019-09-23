/* 
 * FreeModbus Libary: A portable Modbus implementation for Modbus ASCII/RTU.
 * Copyright (c) 2013 China Beijing Armink <armink.ztl@gmail.com>
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
 * File: $Id: mbrtu_m.c,v 1.60 2013/08/17 11:42:56 Armink Add Master Functions $
 */

/* ----------------------- System includes ----------------------------------*/
#include "stdlib.h"
#include "string.h"

/* ----------------------- Platform includes --------------------------------*/
#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbrtu.h"
#include "mbframe.h"

#include "mbcrc.h"
#include "mbport.h"

#include "modbus.h"

#include "main.h"

#if MB_MASTER_RTU_ENABLED > 0
/* ----------------------- Defines ------------------------------------------*/
#if defined (MR5_700) || defined (MR5_600) || defined (MR5_500) || defined (MR741)
#define MB_SER_PDU_SIZE_MIN     4       /*!< Minimum size of a Modbus RTU frame. */
#define MB_SER_PDU_SIZE_MAX     256     /*!< Maximum size of a Modbus RTU frame. */
#define MB_SER_PDU_SIZE_CRC     2       /*!< Size of CRC field in PDU. */
#define MB_SER_PDU_SIZE_MEMADDR 0       //

#define MB_SER_PDU_ADDR_OFF     0       /*!< Offset of slave address in Ser-PDU. */
#define MB_SER_PDU_PDU_OFF      1       /*!< Offset of Modbus-PDU in Ser-PDU. */
#else
#define MB_SER_PDU_SIZE_MIN     4       /*!< Minimum size of a Modbus RTU frame. */
#define MB_SER_PDU_SIZE_MAX     256     /*!< Maximum size of a Modbus RTU frame. */
#define MB_SER_PDU_SIZE_CRC     2       /*!< Size of CRC field in PDU. */

#define MB_SER_PDU_SIZE_MEMADDR 2       //

#define MB_SER_PDU_ADDR_OFF     0       /*!< Offset of slave address in Ser-PDU. */
#define MB_SER_PDU_PDU_OFF      1       /*!< Offset of Modbus-PDU in Ser-PDU. */

#endif
/* ----------------------- Type definitions ---------------------------------*/
typedef enum
{
    STATE_M_RX_INIT,              /*!< 0 �������� � ������ �������������. */
    STATE_M_RX_IDLE,              /*!< 1 �������� ��������� � ��������� ��������. */
    STATE_M_RX_RCV,               /*!< 2 ����� ������. */
    STATE_M_RX_SPEED_RCV,         /*!< 3 ������� ����� ������. */
    STATE_M_RX_WAIT_IDLE,         /*!< 4 �������� ��������� � ��������� �������� ������ �� ����. */
    STATE_M_RX_ERROR,             /*!< 5 �������� �����. */
} eMBMasterRcvState;

typedef enum
{
    STATE_M_TX_IDLE,              /*!< 0 ���������� ��������� � ��������� ��������. */
    STATE_M_TX_XMIT,              /*!< 1 ���������� ��������� � ������ ��������. */
    STATE_M_TX_XFWR,              /*!< 2 ���������� �������� �������� � ������� ������ ������. */
} eMBMasterSndState;

uint16_t SizePreMessage;
/* ----------------------- Static variables ---------------------------------*/
volatile eMBMasterSndState eSndState;
volatile eMBMasterRcvState eRcvState;

static volatile UCHAR  ucMasterRTUSndBuf[MB_PDU_SIZE_MAX]		__attribute__ ((section (".ramint")));			// ����� ��� �������� � MODBUS
static volatile UCHAR  ucMasterRTURcvBuf[_SizeModbusRX]			__attribute__ ((section (".ramint")));			// ����� ��� ����� �� MODBUS c��� ������������ �� ���
static volatile USHORT usMasterSendPDULength;							// ����� ������ �������� ��� ��������

static volatile UCHAR *pucMasterSndBufferCur;
static volatile USHORT usMasterSndBufferCount;

static volatile USHORT usMasterRcvBufferPos;
static volatile BOOL   xFrameIsBroadcast = FALSE;						// ������� ������������������ ������

static volatile eMBMasterTimerMode eMasterCurTimerMode;
//eMBMasterTimerMode eMasterCurTimerMode;

//extern 	xQueueHandle 		ModbusResponseQueue;						// ������� ��� �������� �� ������

extern uint8_t		ModbusBuffActive;
extern uint8_t 		Modbus_DataRX[_SizeModbusRX];			// ����� �������� Modbus
extern uint8_t 		Modbus_DataRXSlave[_SizeModbusRX];		// 2����� �������� Modbus
//extern 	uint8_t 			Modbus_DataTX[_SizeModbusTX];

extern 	UART_HandleTypeDef 	MODBUS;
extern	errMB_data			cntErrorMD;
/* ----------------------- Start implementation -----------------------------*/
eMBErrorCode
eMBMasterRTUInit(UCHAR ucPort, ULONG ulBaudRate, eMBParity eParity )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    ULONG           usTimerT35;

//    ENTER_CRITICAL_SECTION(  );

    if( xMBMasterPortSerialInit( ucPort, ulBaudRate, 8, eParity ) != TRUE )
    {
        eStatus = MB_EPORTERR;
    }
    else
    {
#if defined (MR5_700) || defined (MR5_600) || defined (MR5_500) || defined (MR741)
    	// ���� �������� ���� 19200 �� ���������� ������������� t3.5 = 1750us
        if( ulBaudRate > 19200 )    usTimerT35 = 35;       /* 1800us. */
        else	usTimerT35 = ( 7UL * 220000UL ) / ( 2UL * ulBaudRate );
#else
        // 35 �������� �����
        usTimerT35  =  (350000000UL)/ulBaudRate;			// 100 000 000/ulBaudRate - ����� � ������������� �������
#endif
         eRcvState = STATE_M_RX_INIT;
        vMBMasterSetCurTimerMode(MB_TMODE_T35);
        xMBMasterPortTimersInit( ( USHORT ) usTimerT35 );
    }
//    EXIT_CRITICAL_SECTION(  );

    return eStatus;
}

/*************************************************************************
 * eMBMasterRTUStart
 * ���������� �������� � ��������� STATE_M_RX_INIT. ��������� ������ �� t3.5
 * ���� ������ �� �������, �� ��������� �������� � STATE_M_RX_IDLE.
 * ������������� ���� �� ������ ������ ������(t3.5) �� ������ �������� ������.
 *************************************************************************/
void
eMBMasterRTUStart( void )
{
//    ENTER_CRITICAL_SECTION(  );
//    eRcvState = STATE_M_RX_INIT;//STATE_M_RX_IDLE;//STATE_M_RX_INIT;
//    vMBMasterPortSerialEnable( TRUE, FALSE );			// ����� �����
//    EXIT_CRITICAL_SECTION(  );
}
/*************************************************************************
 * eMBMasterRTUStop
 * ��������� � ���������� ����� � �������� MODBUS � ���������� �������.
 *************************************************************************/
void
eMBMasterRTUStop( void )
{
//    ENTER_CRITICAL_SECTION(  );
    vMBMasterPortSerialEnable( FALSE, FALSE );
    vMBMasterPortTimersDisable(  );
//    EXIT_CRITICAL_SECTION(  );
}
/*************************************************************************
 * eMBMasterRTUReceive
 * ������� ����� ������ � �������� �� ����������.
 *************************************************************************/
eMBErrorCode		eMBMasterRTUReceive( UCHAR * pucRcvAddress, UCHAR ** pucFrame, USHORT * pusLength )
{
    eMBErrorCode    eStatus = MB_ERECV;

//    ENTER_CRITICAL_SECTION(  );
//    assert_param( usMasterRcvBufferPos < MB_SER_PDU_SIZE_MAX );

    // �������� ������ ������
    if( usMasterRcvBufferPos < MB_SER_PDU_SIZE_MIN ){
        eStatus = MB_ERECVDATAERROR;
//        EXIT_CRITICAL_SECTION(  );
        return eStatus;
    }
    // �������� CRC
    if( usMBCRC16( ( UCHAR * ) ucMasterRTURcvBuf, usMasterRcvBufferPos ) == 0 )
    {
        // ����� ���������� ���������.
        *pucRcvAddress = ucMasterRTURcvBuf[MB_SER_PDU_ADDR_OFF];

        // ����� ����� ������(Modbus-PDU) ��� ���� ������ � CRC.
        *pusLength = ( USHORT )( usMasterRcvBufferPos - MB_SER_PDU_PDU_OFF - MB_SER_PDU_SIZE_CRC );

        // ����� ������ ������(Modbus-PDU)
        *pucFrame = ( UCHAR * ) & ucMasterRTURcvBuf[MB_SER_PDU_PDU_OFF];
    }
    else
    {
    	// �� ������� CRC ��� �������� ���������
        eStatus = MB_CRCERR_Rx;
    }

//    EXIT_CRITICAL_SECTION(  );
    return eStatus;
}
/*************************************************************************
 * eMBMasterRTUSend
 * �������� ������ � MODBUS
 * ����� ���������� ����� �.�. ���� ����� ���� ��������� ��������� �����, � ����������
 * ����� ��� ��������� �������� ���� ���� ������
 * ������ � ������ ������ ����� ����� �������. ����� ������� �������� �� ��������� �� ������ ������ � ������.
 *************************************************************************/
eMBErrorCode
eMBMasterRTUSend( UCHAR ucSlaveAddress, const UCHAR * pucFrame, USHORT usLength )
{
    eMBErrorCode    eStatus = MB_ESENT;
    USHORT          usCRC16;
    BOOL 		retPut = FALSE;

    if ( ucSlaveAddress > MB_MASTER_TOTAL_SLAVE_NUM ) return MB_EINVAL;

//    ENTER_CRITICAL_SECTION(  );
       // ������ ����  �� PDU ��� slave address.
        pucMasterSndBufferCur = ( UCHAR * ) pucFrame - 1;
        usMasterSndBufferCount = 1;
        // ��������� � ������ SlaveAddress
        pucMasterSndBufferCur[MB_SER_PDU_ADDR_OFF] = ucSlaveAddress;
        usMasterSndBufferCount += usLength;
        // ������� CRC16
        usCRC16 = usMBCRC16( ( UCHAR * ) pucMasterSndBufferCur, usMasterSndBufferCount );
        ucMasterRTUSndBuf[usMasterSndBufferCount++] = ( UCHAR )( usCRC16 & 0xFF );
        ucMasterRTUSndBuf[usMasterSndBufferCount++] = ( UCHAR )( usCRC16 >> 8 );

/*
        // ��������� ����� � ������, ���� ����� ����� ������.
        memcpy(Modbus_DataTX,(const void*)pucMasterSndBufferCur,usMasterSndBufferCount);
// ������� �������� ------------------
        {
			uint8_t		reSend = 10;	// ������� ��������. ������ ����� ������ �� HAL_UART_Transmit_DMA)
			while(retPut != true){
				reSend --; if (reSend == 0) break;
		        retPut = xMBMasterPortSerialPutBUF(( CHAR *)Modbus_DataTX,usMasterSndBufferCount);
			}
        }
// -----------------------------------
*/
        // ����� �������.
        retPut = xMBMasterPortSerialPutBUF(( CHAR *)pucMasterSndBufferCur,usMasterSndBufferCount);
        if (retPut == TRUE){					// ��������� � ���� ���� ���� �����
        	eSndState = STATE_M_TX_XMIT;

        	xMBMasterPortEventPost( EV_MASTER_FRAME_RECEIVE_WAIT );		// ��� ����� ���� �� ��������� ������, �� �� ���������� ����� �������� ����� �� ������

        }else{
        	// ��� �� ���������� ��� ������, ����� ������� ���������
        	eStatus = MB_EIO_Tx;
        }
//    EXIT_CRITICAL_SECTION(  );
    return eStatus;
}
/*************************************************************************
 * xMBMasterRTUReceiveFSM
 * ������������ �� ��� ������ � ������� ����� (ucMasterRTURcvBuf)
 * ���������� �� ����������. ���������� ������.
 *
 * ��� ����������� ����� ������������ DMA mem to mem
 *************************************************************************/
BOOL	xMBMasterRTUReceiveFSM( void )
{
	uint16_t szWait;

	vMBMasterPortTimersDisable( );
	xModbus_Get_SizeWaitingAnswer(&szWait);
	xModbus_Get_SizeAnswer((uint16_t *) &usMasterRcvBufferPos);

    if (usMasterRcvBufferPos == 0){						// ������� ���������� ������, ���� ������� ����������. >256 ���� ������
    		SizePreMessage = 0;							// ������� ������� ����. ������ ��������
        	return false;
    }

//    memcpy((void *)ucMasterRTURcvBuf,Modbus_DataRX,usMasterRcvBufferPos);
	if (ModbusBuffActive == 0)	{memcpy((void *)ucMasterRTURcvBuf,Modbus_DataRX,usMasterRcvBufferPos);}
	else						{memcpy((void *)ucMasterRTURcvBuf,Modbus_DataRXSlave,usMasterRcvBufferPos);}


	xMBMasterPortEventPost(EV_MASTER_FRAME_RECEIVED);

	SizePreMessage = 0;		// ������� ������� ����. ������ ��������

    return true;
}
/*************************************************************************
 * xMBMasterRTUTransmitFSM
 * ���������� �� ����������. ���������� ������.
 *
 * ���������� ���������� �� ��������� �������� ������
 * 1. ����� ��������� ��������    3,5 ������� �����
 * 2. �������� ���� ������.
 *
 *************************************************************************/
BOOL
xMBMasterRTUTransmitFSM( void )
{
    BOOL            xNeedPoll = FALSE;

    assert_param( eRcvState == STATE_M_RX_IDLE );

//	 vMBMasterPortSerialEnable( TRUE, FALSE );		// ��������� �� ���� enable receiver/disable transmitter.
	 eSndState = STATE_M_TX_XFWR;
	 xMBMasterPortEventPost( EV_MASTER_FRAME_RECEIVE_WAIT );	// ��� �����

	 vMBMasterPortTimersRespondTimeoutEnable( );

    return xNeedPoll;
}

/*************************************************************************
 * xMBMasterRTUStartIdle
 *
 *************************************************************************/
BOOL xMBMasterRTUStartIdle(void)
{
	BOOL xNeedPoll = FALSE;

	switch (eRcvState)
	{
	case STATE_M_RX_INIT:							// ���� �������������, ��������� ������ �� ����
		vMBMasterPortTimersDisable();
		xMBMasterPortEventPost(EV_MASTER_READY);	// Startup ��������. MASTER ����� � ������.
		eRcvState = STATE_M_RX_IDLE;
		break;

	case  STATE_M_RX_IDLE:

		xMBMasterRTUReceiveFSM();					// ��������� ������ �� Modbus_DataRX � ������� ����� ucMasterRTURcvBuf
		eSndState = STATE_M_TX_IDLE;
		break;

	default:															// �������������� ��������� �������.
		assert_param(
				( eRcvState == STATE_M_RX_RCV ) ||
				( eRcvState == STATE_M_RX_ERROR )
				);
		break;

	}

	return xNeedPoll;
}
/*************************************************************************
 * xMBMasterRTUTimerExpired
 * ���������� ��������� �������
 *************************************************************************/
BOOL
xMBMasterRTUTimerExpired(void)
{
	uint16_t		Readbuffcurr;
	BOOL xNeedPoll = FALSE;
	eMBMasterTimerMode	TimerMode;

	TimerMode = vMBMasterGetCurTimerMode();
	// �������� ����� ��������� ������� ����� �������, ���� ��� ����������� �� ..... ������� ��� ������������� ������ ���� ��������
	vMBMasterPortTimersDisable( );

// ����� --------------------------------------------------------------
	switch (eRcvState)
	{
	case STATE_M_RX_INIT:												// ����� t3.5 �������.
		xNeedPoll = xMBMasterPortEventPost(EV_MASTER_READY);			// Startup ��������. MASTER ����� � ������.
		eRcvState = STATE_M_RX_IDLE;
		return xNeedPoll;
		break;

	default:															// �������������� ��������� �������.
		assert_param(
				( eRcvState == STATE_M_RX_INIT ) || ( eRcvState == STATE_M_RX_RCV ) ||
				( eRcvState == STATE_M_RX_ERROR ) || ( eRcvState == STATE_M_RX_IDLE ));
		break;
	}
	eRcvState = STATE_M_RX_IDLE;

// �������� -----------------------------------------------------------
	switch (eSndState)
	{

	case STATE_M_TX_XMIT:		// ����� ��������, �� �������� �� ��������(��� ���������� �� ��������� �������).
		xMBMasterPortEventClear(EV_MASTER_FRAME_RECEIVE_WAIT);					// �� � �����, ����� ������.

		xNeedPoll = xMBMasterPortEventPost(EV_MASTER_ERROR_PROCESS);
		vMBMasterSetErrorType(EV_ERROR_SENT_DATA);

		cntErrorMD.errTx++;

		eSndState = STATE_M_TX_IDLE;
		break;

	case STATE_M_TX_XFWR:														// ������� � �������� �������
		Readbuffcurr = HAL_UART_DataInDMA(&MODBUS);
		if (Readbuffcurr == 0){													// ����� ����
				xMBMasterPortEventClear(EV_MASTER_FRAME_RECEIVE_WAIT);			// �� � �����, ����� ������.

				xNeedPoll = xMBMasterPortEventPost(EV_MASTER_ERROR_PROCESS);
				vMBMasterSetErrorType(EV_ERROR_RESPOND_TIMEOUT);				// �������, �� ��� �������� ������ �����, ������ ��� ������ �������.
				cntErrorMD.errTimeOut++;

				//USART_TRACE_BLUE("�������,����� ���� ... (Tmode:%u)\n",TimerMode);

				eSndState = STATE_M_TX_IDLE;
		}else{
				// ���� ����� ���� � ������ �������, �� ����� ��������� ������ �����. �� ������ ���� ������ ������ �� �����.
				// ���� � ������� �������� ������ �� ������ (� ������ ����� �������� �������) ��� ��������� �����.
				uint16_t SizeMessage;
				//SizeMessage  = Hal_get_SizeMessageFromMB((uint8_t*)Modbus_DataRX);	// ������ ��������� �� ������ ���������.
             	if (ModbusBuffActive == 0)	{SizeMessage  = Hal_get_SizeMessageFromMB((uint8_t*)Modbus_DataRX);}
            	else						{SizeMessage  = Hal_get_SizeMessageFromMB((uint8_t*)Modbus_DataRXSlave);}

             	if (SizeMessage <= Readbuffcurr) {	//���� ������ >= ���������� �����������

             		//USART_TRACE_BLUE("���� ����... (%u �� %u)\n",Readbuffcurr,SizeMessage);		// ����� �� �������� � ������ ��������� �����
             		//xMBMasterRTUReceiveFSM();
             		//xMBMasterPortEventClear(EV_MASTER_FRAME_RECEIVE_WAIT);
        			//eSndState = STATE_M_TX_IDLE;

             	}else{
             		if (SizePreMessage != Readbuffcurr){	//���� ������ � ������ ���������� �� ��� �����
                 		// ������ � �������� ������
                      	//USART_TRACE_BLUE("�������:%u, �� ����� ���������... (%u � %u)\n",TimerMode,SizePreMessage,Readbuffcurr);

             			SizePreMessage = Readbuffcurr;
                      	vMBMasterPortTimersRespondTimeoutEnable( );

             		}else{
             			// � ��� ������ ������, ����� ������.
                 		xMBMasterPortEventClear(EV_MASTER_FRAME_RECEIVE_WAIT);
        				xNeedPoll = xMBMasterPortEventPost(EV_MASTER_ERROR_PROCESS);
        				vMBMasterSetErrorType(EV_ERROR_RESPOND_TIMEOUT);				// �������, �� ��� �������� ������ �����, ������ ��� ������ �������.
        				cntErrorMD.errTimeOut++;

            			eSndState = STATE_M_TX_IDLE;
                      	//USART_TRACE_BLUE("�������:%u, ����� ��� ����������... (%u � %u)\n",TimerMode,SizePreMessage,Readbuffcurr);
             			SizePreMessage = 0;
             		}
             	}
		}
		// � ��� ���� ��� �� ����� ������ �� ������ �� IDLE
		//	eSndState = STATE_M_TX_IDLE;
		break;
// ����� ��������. ����� �������� ���������� ������� ���� �����
// TimerMode == MB_TMODE_AFTERRESPOND_TIMEOUT ������ ����
	case STATE_M_TX_IDLE:
			xMBMasterPortEventClear(EV_MASTER_FRAME_RECEIVE_WAIT);			// �� � �����, ����� ������.
			if (TimerMode != MB_TMODE_AFTERRESPOND_TIMEOUT){

				xNeedPoll = xMBMasterPortEventPost(EV_MASTER_ERROR_PROCESS);
				vMBMasterSetErrorType(EV_ERROR_RESPOND_TIMEOUT);
				//USART_TRACE_BLUE("TX_IDLE �������... (Tmode:%u)\n",TimerMode);
				cntErrorMD.errTimeOut++;
			}else{
//				vMBMasterSetErrorType(EV_ERROR_RESPOND_TIMEOUT);
			}
		break;

	default:															// �������������� ��������� �������.
		assert_param(
				( eSndState == STATE_M_TX_XFWR ) || ( eSndState == STATE_M_TX_IDLE ));
		break;
	}

	return xNeedPoll;
}

/* Get Modbus Master send RTU's buffer address pointer.*/
void vMBMasterGetRTUSndBuf( UCHAR ** pucFrame )
{
	*pucFrame = ( UCHAR * ) ucMasterRTUSndBuf;
}

/* Get Modbus Master send PDU's buffer address pointer.*/
void vMBMasterGetPDUSndBuf( UCHAR ** pucFrame )
{
	*pucFrame = ( UCHAR * ) &ucMasterRTUSndBuf[MB_SER_PDU_PDU_OFF];
}

/* Set Modbus Master send PDU's buffer length.*/
void vMBMasterSetPDUSndLength( USHORT SendPDULength )
{
	usMasterSendPDULength = SendPDULength;
}

/* Get Modbus Master send PDU's buffer length.*/
USHORT usMBMasterGetPDUSndLength( void )
{
	return usMasterSendPDULength;
}

/* Set Modbus Master current timer mode.*/
void vMBMasterSetCurTimerMode( eMBMasterTimerMode eMBTimerMode )
{
	eMasterCurTimerMode = eMBTimerMode;
}

eMBMasterTimerMode 	vMBMasterGetCurTimerMode( void ){

	return eMasterCurTimerMode;
}

/* The master request is broadcast? */
BOOL xMBMasterRequestIsBroadcast( void ){
	return xFrameIsBroadcast;
}
#endif

