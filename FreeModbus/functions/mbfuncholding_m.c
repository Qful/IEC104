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
 * File: $Id: mbfuncholding_m.c,v 1.60 2013/09/02 14:13:40 Armink Add Master Functions  Exp $
 */

/* ----------------------- System includes ----------------------------------*/
#include "stdlib.h"
#include "string.h"

/* ----------------------- Platform includes --------------------------------*/
#include "port.h"

#include "main.h"

#include "iec850.h"
#include "iec61850_server.h"
#include "static_model.h"
/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbframe.h"
#include "mbproto.h"
#include "mbconfig.h"

#include "modbus.h"
/* ----------------------- external ------------------------------------------*/
extern IedServer iedServer;
extern osThreadId IEC850TaskHandle;

/*************************************************************************
 * MR771
 *************************************************************************/
#if defined (MR771)
extern uint16_t   ucVLSOutBuf[MB_NumbConfigVLSOut];
extern uint16_t   ucVLSInBuf[MB_NumbConfigVLSIn];
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMConfigBufSW[MB_Size_ConfSW];
extern uint16_t   ucSystemCfgBuf[MB_NumbSystemCfg];
extern uint16_t   ucConfigTRMeasBuf[MB_NumbConfigTRMeas];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucConfigAPWBuf[MB_NumbConfigAPW];
extern uint16_t   ucSGBuf[MB_NumbSG];
extern uint16_t   ucMAutomatBuf[MB_NumbAutomat];



extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usMConfigStartSW;
extern uint16_t   usConfigUstavkiStart;			// группа уставок
extern uint16_t   usConfigAutomatStart;			// параметры автоматики
extern uint16_t   usConfigVLSInStart;			// чтение конфигурации входных логических сигналов
extern uint16_t   usConfigVLSOutStart;			// чтение конфигурации выходных логических сигналов
extern uint16_t   usConfigAPWStart;				// конфигурация АПВ
extern uint16_t   usSystemCfgStart;				// параметры системы
extern uint16_t   usConfigTRMeasStart;			// конфигурация измерительного транса
extern uint16_t   usSGStart;
extern uint16_t   usConfigAutomatStart;
#endif
/*************************************************************************
 * MR761 MR762 MR763
 *************************************************************************/
#if defined (MR761) || defined (MR762) || defined (MR763)
extern uint16_t   ucVLSOutBuf[MB_NumbConfigVLSOut];
extern uint16_t   ucVLSInBuf[MB_NumbConfigVLSIn];
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMConfigBufSW[MB_Size_ConfSW];
extern uint16_t   ucSystemCfgBuf[MB_NumbSystemCfg];
extern uint16_t   ucConfigTRMeasBuf[MB_NumbConfigTRMeas];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucConfigAPWBuf[MB_NumbConfigAPW];

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usMConfigStartSW;
extern uint16_t   usConfigUstavkiStart;			// группа уставок
extern uint16_t   usConfigAutomatStart;			// параметры автоматики
extern uint16_t   usConfigVLSInStart;			// чтение конфигурации входных логических сигналов
extern uint16_t   usConfigVLSOutStart;			// чтение конфигурации выходных логических сигналов
extern uint16_t   usConfigAPWStart;				// конфигурация АПВ
extern uint16_t   usSystemCfgStart;				// параметры системы
extern uint16_t   usConfigTRMeasStart;			// конфигурация измерительного транса
#endif

/*************************************************************************
 * MR5_700
 *************************************************************************/
#if defined (MR5_700)

extern uint16_t   usMDateStart;
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   usMRevStart;
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   usMDiscInStart;
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   usMConfigStart;
extern uint16_t   ucMConfigBuf[MB_NumbConfig];
extern uint16_t   usMConfigStartall;
extern uint16_t   ucMConfigBufall[MB_NumbConfigall];
extern uint16_t   usMConfigStartSWCrash;
extern uint16_t   ucMSWCrash[MB_NumbSWCrash];

extern uint16_t	    Ktt,Ktn;
#endif
#if defined (MR5_600)

extern uint16_t   usMDateStart;
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   usMRevStart;
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   usMDiscInStart;
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   usMConfigStart;
extern uint16_t   ucMConfigBuf[MB_NumbConfig];
extern uint16_t   usMConfigStartall;
extern uint16_t   ucMConfigBufall[MB_NumbConfigall];
extern uint16_t   usMConfigStartSWCrash;
extern uint16_t   ucMSWCrash[MB_NumbSWCrash];

extern uint16_t	    Ktn;
#endif
#if defined (MR5_500)

extern uint16_t   usMDateStart;
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   usMRevStart;
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   usMDiscInStart;
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   usMConfigStart;
extern uint16_t   ucMConfigBuf[MB_NumbConfig];
extern uint16_t   usMConfigStartall;
extern uint16_t   ucMConfigBufall[MB_NumbConfigall];
extern uint16_t   usMConfigStartSWCrash;
extern uint16_t   ucMSWCrash[MB_NumbSWCrash];

extern uint16_t	    Ktt,Ktn;
#endif
/*************************************************************************
 * MR801
 *************************************************************************/
#if defined (MR801)
extern uint16_t   ucVLSOutBuf[MB_NumbConfigVLSOut];
extern uint16_t   ucVLSInBuf[MB_NumbConfigVLSIn];
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMConfigBufSW[MB_Size_ConfSW];
extern uint16_t   ucSystemCfgBuf[MB_NumbSystemCfg];
extern uint16_t   ucConfigTRMeasBuf[MB_NumbConfigTRMeas];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];

extern uint16_t   ucConfigAPWBuf[MB_NumbConfigAPW];
extern uint16_t   ucConfigAWRBuf[MB_NumbConfigAWR];
extern uint16_t   ucConfigTRPWRBuf[MB_NumbConfigTRPWR];

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usMConfigStartSW;
extern uint16_t   usConfigUstavkiStart;			// группа уставок
extern uint16_t   usConfigAutomatStart;			// параметры автоматики
extern uint16_t   usConfigVLSInStart;			// чтение конфигурации входных логических сигналов
extern uint16_t   usConfigVLSOutStart;			// чтение конфигурации выходных логических сигналов
extern uint16_t   usConfigAPWStart;				// конфигурация АПВ
extern uint16_t   usConfigAWRStart;				// конфигурация АВР
extern uint16_t   usSystemCfgStart;				// параметры системы
extern uint16_t   usConfigTRMeasStart;			// конфигурация измерительного транса
extern uint16_t   usConfigTRPWRStart;			// конфигурация силового транса

#endif
/*************************************************************************
 * MR901 902
 *************************************************************************/
#if defined (MR901) || defined (MR902)
extern uint16_t   ucVLSOutBuf[MB_NumbConfigVLSOut];
extern uint16_t   ucVLSInBuf[MB_NumbConfigVLSIn];
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMConfigBufSW[MB_Size_ConfSW];
extern uint16_t   ucSystemCfgBuf[MB_NumbSystemCfg];
extern uint16_t   ucConfigTRMeasBuf[MB_NumbConfigTRMeas];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];

extern uint16_t   ucConfigAPWBuf[MB_NumbConfigAPW];
extern uint16_t   ucConfigAWRBuf[MB_NumbConfigAWR];
extern uint16_t   ucConfigTRPWRBuf[MB_NumbConfigTRPWR];

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usMConfigStartSW;
extern uint16_t   usConfigUstavkiStart;			// группа уставок
extern uint16_t   usConfigAutomatStart;			// параметры автоматики
extern uint16_t   usConfigVLSInStart;			// чтение конфигурации входных логических сигналов
extern uint16_t   usConfigVLSOutStart;			// чтение конфигурации выходных логических сигналов
extern uint16_t   usConfigAPWStart;				// конфигурация АПВ
extern uint16_t   usConfigAWRStart;				// конфигурация АВР
extern uint16_t   usSystemCfgStart;				// параметры системы
extern uint16_t   usConfigTRMeasStart;			// конфигурация измерительного транса
extern uint16_t   usConfigTRPWRStart;			// конфигурация силового транса

#endif

//-------------------------------------------------------------------
extern	uint8_t		ReadNmb;					// текущий номер блока для чтения из модбас
extern	uint16_t	NumbBlokReadMB;				// текущий кусок блока для чтения из модбас

extern osMutexId 	xIEC850StartMutex;		// мьютекс готовности к запуску TCP/IP
extern uint8_t		IP_ADDR[4];
extern volatile uint8_t	MAC_ADDR[6];
/* ----------------------- Defines ------------------------------------------*/
#define MB_PDU_REQ_READ_ADDR_OFF                ( MB_PDU_DATA_OFF + 0 )
#define MB_PDU_REQ_READ_REGCNT_OFF              ( MB_PDU_DATA_OFF + 2 )
#define MB_PDU_REQ_READ_SIZE                    ( 4 )
#define MB_PDU_FUNC_READ_REGCNT_MAX             ( 0x007D )
#define MB_PDU_FUNC_READ_BYTECNT_OFF            ( MB_PDU_DATA_OFF + 0 )
#define MB_PDU_FUNC_READ_VALUES_OFF             ( MB_PDU_DATA_OFF + 1 )
#define MB_PDU_FUNC_READ_SIZE_MIN               ( 1 )

#define MB_PDU_REQ_WRITE_ADDR_OFF               ( MB_PDU_DATA_OFF + 0)
#define MB_PDU_REQ_WRITE_VALUE_OFF              ( MB_PDU_DATA_OFF + 2 )
#define MB_PDU_REQ_WRITE_SIZE                   ( 4 )
#define MB_PDU_FUNC_WRITE_ADDR_OFF              ( MB_PDU_DATA_OFF + 0)
#define MB_PDU_FUNC_WRITE_VALUE_OFF             ( MB_PDU_DATA_OFF + 2 )
#define MB_PDU_FUNC_WRITE_SIZE                  ( 4 )

#define MB_PDU_REQ_WRITE_MUL_ADDR_OFF           ( MB_PDU_DATA_OFF + 0 )
#define MB_PDU_REQ_WRITE_MUL_REGCNT_OFF         ( MB_PDU_DATA_OFF + 2 )
#define MB_PDU_REQ_WRITE_MUL_BYTECNT_OFF        ( MB_PDU_DATA_OFF + 4 )
#define MB_PDU_REQ_WRITE_MUL_VALUES_OFF         ( MB_PDU_DATA_OFF + 5 )
#define MB_PDU_REQ_WRITE_MUL_SIZE_MIN           ( 5 )
#define MB_PDU_REQ_WRITE_MUL_REGCNT_MAX         ( 0x0078 )
#define MB_PDU_FUNC_WRITE_MUL_ADDR_OFF          ( MB_PDU_DATA_OFF + 0 )
#define MB_PDU_FUNC_WRITE_MUL_REGCNT_OFF        ( MB_PDU_DATA_OFF + 2 )
#define MB_PDU_FUNC_WRITE_MUL_SIZE              ( 4 )

#define MB_PDU_REQ_READWRITE_READ_ADDR_OFF      ( MB_PDU_DATA_OFF + 0 )
#define MB_PDU_REQ_READWRITE_READ_REGCNT_OFF    ( MB_PDU_DATA_OFF + 2 )
#define MB_PDU_REQ_READWRITE_WRITE_ADDR_OFF     ( MB_PDU_DATA_OFF + 4 )
#define MB_PDU_REQ_READWRITE_WRITE_REGCNT_OFF   ( MB_PDU_DATA_OFF + 6 )
#define MB_PDU_REQ_READWRITE_WRITE_BYTECNT_OFF  ( MB_PDU_DATA_OFF + 8 )
#define MB_PDU_REQ_READWRITE_WRITE_VALUES_OFF   ( MB_PDU_DATA_OFF + 9 )
#define MB_PDU_REQ_READWRITE_SIZE_MIN           ( 9 )
#define MB_PDU_FUNC_READWRITE_READ_BYTECNT_OFF  ( MB_PDU_DATA_OFF + 0 )
#define MB_PDU_FUNC_READWRITE_READ_VALUES_OFF   ( MB_PDU_DATA_OFF + 1 )
#define MB_PDU_FUNC_READWRITE_SIZE_MIN          ( 1 )

/* ----------------------- Static functions ---------------------------------*/
eMBException    prveMBError2Exception( eMBErrorCode eErrorCode );

/* ----------------------- Start implementation -----------------------------*/
#if MB_MASTER_RTU_ENABLED > 0 || MB_MASTER_ASCII_ENABLED > 0
#if MB_FUNC_WRITE_HOLDING_ENABLED > 0

/**
 * This function will request write holding register.
 *
 * @param ucSndAddr salve address
 * @param usRegAddr register start address
 * @param usRegData register data to be written
 * @param lTimeOut timeout (-1 will waiting forever)
 *
 * @return error code
 */
eMBMasterReqErrCode
eMBMasterReqWriteHoldingRegister( UCHAR ucSndAddr, USHORT usRegAddr, USHORT usRegData, LONG lTimeOut )
{
    UCHAR                 *ucMBFrame;
    eMBMasterReqErrCode    eErrStatus = MB_MRE_NO_ERR;

    if ( ucSndAddr > MB_MASTER_TOTAL_SLAVE_NUM ) eErrStatus = MB_MRE_ILL_ARG;
    else if ( xMBMasterRunResTake( lTimeOut ) == FALSE ) eErrStatus = MB_MRE_MASTER_BUSY;
    else
    {
		vMBMasterGetPDUSndBuf(&ucMBFrame);
		vMBMasterSetDestAddress(ucSndAddr);
		ucMBFrame[MB_PDU_FUNC_OFF]                = MB_FUNC_WRITE_REGISTER;
		ucMBFrame[MB_PDU_REQ_WRITE_ADDR_OFF]      = usRegAddr >> 8;
		ucMBFrame[MB_PDU_REQ_WRITE_ADDR_OFF + 1]  = usRegAddr;
		ucMBFrame[MB_PDU_REQ_WRITE_VALUE_OFF]     = usRegData >> 8;
		ucMBFrame[MB_PDU_REQ_WRITE_VALUE_OFF + 1] = usRegData ;
		vMBMasterSetPDUSndLength( MB_PDU_SIZE_MIN + MB_PDU_REQ_WRITE_SIZE );
		( void ) xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );
		eErrStatus = eMBMasterWaitRequestFinish( );
    }
    return eErrStatus;
}

eMBException
eMBMasterFuncWriteHoldingRegister( UCHAR * pucFrame, USHORT * usLen )
{
    USHORT          usRegAddress;
    eMBException    eStatus = MB_EX_NONE;
    eMBErrorCode    eRegStatus;

    if( *usLen == ( MB_PDU_SIZE_MIN + MB_PDU_FUNC_WRITE_SIZE ) )
    {
        usRegAddress = ( USHORT )( pucFrame[MB_PDU_FUNC_WRITE_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( pucFrame[MB_PDU_FUNC_WRITE_ADDR_OFF + 1] );
        usRegAddress++;

        /* Make callback to update the value. */
        eRegStatus = eMBMasterRegHoldingCB( &pucFrame[MB_PDU_FUNC_WRITE_VALUE_OFF], usRegAddress, 1, MB_REG_WRITE );

        /* If an error occured convert it into a Modbus exception. */
        if( eRegStatus != MB_ENOERR )
        {
            eStatus = prveMBError2Exception( eRegStatus );
        }
    }
    else
    {
        /* Can't be a valid request because the length is incorrect. */
        eStatus = MB_EX_ILLEGAL_DATA_VALUE;
    }
    return eStatus;
}
#endif

#if MB_FUNC_WRITE_MULTIPLE_HOLDING_ENABLED > 0

/**
 * This function will request write multiple holding register.
 *
 * @param ucSndAddr salve address
 * @param usRegAddr register start address
 * @param usNRegs register total number
 * @param pusDataBuffer data to be written
 * @param lTimeOut timeout (-1 will waiting forever)
 *
 * @return error code
 */
eMBMasterReqErrCode
eMBMasterReqWriteMultipleHoldingRegister( UCHAR ucSndAddr,
		USHORT usRegAddr, USHORT usNRegs, USHORT * pusDataBuffer, LONG lTimeOut )
{
    UCHAR                 *ucMBFrame;
    USHORT                 usRegIndex = 0;
    eMBMasterReqErrCode    eErrStatus = MB_MRE_NO_ERR;

    if ( ucSndAddr > MB_MASTER_TOTAL_SLAVE_NUM ) eErrStatus = MB_MRE_ILL_ARG;
    else if ( xMBMasterRunResTake( lTimeOut ) == FALSE ) eErrStatus = MB_MRE_MASTER_BUSY;
    else
    {
		vMBMasterGetPDUSndBuf(&ucMBFrame);
		vMBMasterSetDestAddress(ucSndAddr);
		ucMBFrame[MB_PDU_FUNC_OFF]                     = MB_FUNC_WRITE_MULTIPLE_REGISTERS;
		ucMBFrame[MB_PDU_REQ_WRITE_MUL_ADDR_OFF]       = usRegAddr >> 8;
		ucMBFrame[MB_PDU_REQ_WRITE_MUL_ADDR_OFF + 1]   = usRegAddr;
		ucMBFrame[MB_PDU_REQ_WRITE_MUL_REGCNT_OFF]     = usNRegs >> 8;
		ucMBFrame[MB_PDU_REQ_WRITE_MUL_REGCNT_OFF + 1] = usNRegs ;
		ucMBFrame[MB_PDU_REQ_WRITE_MUL_BYTECNT_OFF]    = usNRegs * 2;
		ucMBFrame += MB_PDU_REQ_WRITE_MUL_VALUES_OFF;
		while( usNRegs > usRegIndex)
		{
			*ucMBFrame++ = pusDataBuffer[usRegIndex] >> 8;
			*ucMBFrame++ = pusDataBuffer[usRegIndex++] ;
		}
		vMBMasterSetPDUSndLength( MB_PDU_SIZE_MIN + MB_PDU_REQ_WRITE_MUL_SIZE_MIN + 2*usNRegs );
		( void ) xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );
		eErrStatus = eMBMasterWaitRequestFinish( );
    }
    return eErrStatus;
}

eMBException
eMBMasterFuncWriteMultipleHoldingRegister( UCHAR * pucFrame, USHORT * usLen )
{
    UCHAR          *ucMBFrame;
    USHORT          usRegAddress;
    USHORT          usRegCount;
    UCHAR           ucRegByteCount;

    eMBException    eStatus = MB_EX_NONE;
    eMBErrorCode    eRegStatus;

    /* If this request is broadcast, the *usLen is not need check. */
    if( ( *usLen == MB_PDU_SIZE_MIN + MB_PDU_FUNC_WRITE_MUL_SIZE ) || xMBMasterRequestIsBroadcast() )
    {
		vMBMasterGetPDUSndBuf(&ucMBFrame);
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_WRITE_MUL_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_WRITE_MUL_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_WRITE_MUL_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_WRITE_MUL_REGCNT_OFF + 1] );

        ucRegByteCount = ucMBFrame[MB_PDU_REQ_WRITE_MUL_BYTECNT_OFF];

        if( ucRegByteCount == 2 * usRegCount )
        {
            /* Make callback to update the register values. */
            eRegStatus =
                eMBMasterRegHoldingCB( &ucMBFrame[MB_PDU_REQ_WRITE_MUL_VALUES_OFF], usRegAddress, usRegCount, MB_REG_WRITE );

            /* If an error occured convert it into a Modbus exception. */
            if( eRegStatus != MB_ENOERR )
            {
                eStatus = prveMBError2Exception( eRegStatus );
            }
        }
        else
        {
            eStatus = MB_EX_ILLEGAL_DATA_VALUE;
        }
    }
    else
    {
        /* Can't be a valid request because the length is incorrect. */
        eStatus = MB_EX_ILLEGAL_DATA_VALUE;
    }
    return eStatus;
}
#endif

#if MB_FUNC_READ_HOLDING_ENABLED > 0

/**
 * This function will request read holding register.
 *
 * @param ucSndAddr salve address
 * @param usRegAddr register start address
 * @param usNRegs register total number
 * @param lTimeOut timeout (-1 will waiting forever)
 *
 * @return error code
 */
eMBMasterReqErrCode		eMBMasterReqReadHoldingRegister( UCHAR ucSndAddr, USHORT usRegAddr, USHORT usNRegs, LONG lTimeOut )
{
    UCHAR                 *ucMBFrame;
    uint8_t			SizeAnswer;
    uint8_t			SizeData;
    eMBMasterReqErrCode    eErrStatus = MB_MRE_NO_ERR;

    if ( ucSndAddr > MB_MASTER_TOTAL_SLAVE_NUM ) 			eErrStatus = MB_MRE_ILL_ARG;
    else if ( xMBMasterRunResTake( lTimeOut ) == FALSE ) 	eErrStatus = MB_MRE_MASTER_BUSY;
    else
    {
    	SizeData = usNRegs << 1;
    	SizeAnswer = SizeAddr+SizeFunct+1+SizeCRC+SizeData;

    	vMBMasterGetPDUSndBuf(&ucMBFrame);
		vMBMasterSetDestAddress(ucSndAddr);
		ucMBFrame[MB_PDU_FUNC_OFF]                = MB_FUNC_READ_HOLDING_REGISTER;
		ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF]       = usRegAddr >> 8;
		ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1]   = usRegAddr;
		ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF]     = usNRegs >> 8;
		ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] = usNRegs;
		vMBMasterSetPDUSndLength( MB_PDU_SIZE_MIN + MB_PDU_REQ_READ_SIZE );
		xModbus_Set_SizeAnswer(SizeAnswer);
		( void ) xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );
		eErrStatus = eMBMasterWaitRequestFinish( );
    }
    return eErrStatus;
}
/***********************************************************************************
 * MR771 eMBMasterFuncReadRegisters
 ***********************************************************************************/
#if defined (MR771)
eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
	extern uint64_t nextSynchTime;
	extern bool resynch;

    UCHAR          *ucMBFrame;
    uint16_t          usRegAddress;
    uint16_t          usRegCount;
    uint16_t		StartMemForSave;
    uint16_t		MemForSave;

    extern osMutexId 	xIEC850StartMutex;		// мьютекс готовности к запуску TCP/IP
    extern uint8_t		IP_ADDR[4];

    eMBException    eStatus = MB_EX_NONE;
    eMBErrorCode    eRegStatus;

    /* If this request is broadcast, and it's read mode. This request don't need execute. */
    if ( xMBMasterRequestIsBroadcast() )
    {
    	eStatus = MB_EX_NONE;
    }
    else if( *usLen >= MB_PDU_SIZE_MIN + MB_PDU_FUNC_READ_SIZE_MIN )
    {
		vMBMasterGetPDUSndBuf(&ucMBFrame);											// берём из передающего буфера адрес в памяти чтобы высчитать куда положить в принятую память
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

        //  Проверим если количество регистров является действительным.
        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
        {
        	MemForSave = usRegAddress-1;// & 0xFF00;

//----------------------------------------------------------------
//- проверим в какую область памяти писать -----------------------
//----------------------------------------------------------------

// ревизия
        	if (usMRevStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, usMRevStart, MB_NumbWordRev );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Версия: '%s'\n",ReadNmb,(char *)ucMRevBuf);
                }else {
            		USART_TRACE_RED("ошибка получения версии из MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
                ReadNmb++;
        	}
// дискреты
        	else if (usMDiscInStart== MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, usMDiscInStart, MB_NumbDiscreet );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД дискретных.\n");
                }
                ReadNmb++;
        	}
// аналоги
        	else if ( usMAnalogInStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, usMAnalogInStart, MB_NumbAnalog);		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД аналогов.\n");
                }
                ReadNmb++;
        	}
//  конфигурация системы
        	else if ( usSystemCfgStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucSystemCfgBuf, usSystemCfgStart, MB_NumbSystemCfg);
                if( eRegStatus == MB_ENOERR ){	// меняем IP адрес
                	USART_TRACE_GREEN("%d. Получили конфиг системы.\n",ReadNmb);

                	int8_t	resSetIP = Hal_setIPFromMB_Date((uint16_t*)&ucSystemCfgBuf[MB_offset_IP]);
                	if (resSetIP == 0){
                					// если всё норм то нужно сообщить о готовности работать IP
                					USART_TRACE_GREEN("%d.получили из MODBUS IP:%d.%d.%d.%d \n",ReadNmb, IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					// перезапустим таск
                					if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
                						ReStartIEC850_task();
                 					}

                					osMutexRelease(xIEC850StartMutex);
                	} else
                	if (resSetIP == -1){
                		USART_TRACE_RED("ошибка получения IP из MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	} else
                	if (resSetIP == 2){	// совпадение с прошлым включением
                		USART_TRACE_GREEN("IP из MODBUS совпадает с константой.\n");
    					osMutexRelease(xIEC850StartMutex);

                	}
                }
                ReadNmb++;
        	}
// чтение текущего времени
        	else if ( usMDateStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, usMDateStart, MB_NumbDate);				// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	nextSynchTime = Hal_getTimeInMs() + msInDay;				// следующая пересинхронизация часов
                	USART_TRACE_GREEN("%d. Получили время:0x%X следующая синхронизация:0x%X\n",ReadNmb,(unsigned int)Hal_getTimeInMs(),(unsigned int)nextSynchTime);
                	resynch = true;
                }
                ReadNmb++;
        	}
// чтение конфигурации выключателя
        	else if ( usMConfigStartSW == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBufSW, usMConfigStartSW, MB_Size_ConfSW);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг выключателя.\n",ReadNmb);
                }
                ReadNmb++;
        	}

// чтение номера группы уставок
        	else if ( usSGStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucSGBuf, MemForSave, MB_NumbSG);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. Получили номер группы уставок. (%d)\n",ReadNmb,ucSGBuf[0]+1);
				}
				ReadNmb++;
			}
// чтение группы уставок
			else if (( usConfigUstavkiStart <= MemForSave) &&(MemForSave < (usConfigUstavkiStart+MB_NumbUstavki-1))){

				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucMUstavkiInBuf[MemForSave-usConfigUstavkiStart], MemForSave, SizeAnswer);

				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d-%d. Получили группы уставок.(0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
					NumbBlokReadMB++;
				}

			}
// чтение параметров автоматики
			else if (( usConfigAutomatStart <= MemForSave) &&(MemForSave < (usConfigAutomatStart+MB_NumbAutomat-1))){

				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucMAutomatBuf[MemForSave-usConfigAutomatStart], MemForSave, SizeAnswer);

				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d-%d. Получили параметры автоматики.(0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
					NumbBlokReadMB++;
				}
			}

//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------

            if( eRegStatus != MB_ENOERR )
            {
                eStatus = prveMBError2Exception( eRegStatus );
            }
        }
        else
        {
            eStatus = MB_EX_ILLEGAL_DATA_VALUE;
        }
    }
    else
    {
        /* Can't be a valid request because the length is incorrect. */
        eStatus = MB_EX_ILLEGAL_DATA_VALUE;
    }
    return eStatus;
}
#endif

/***********************************************************************************
 * MR761 MR762 MR763
 ***********************************************************************************/
#if defined (MR761) || defined (MR762) || defined (MR763)
eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
	extern uint64_t nextSynchTime;
	extern bool resynch;

    UCHAR          *ucMBFrame;
    uint16_t          usRegAddress;
    uint16_t          usRegCount;
    uint16_t		StartMemForSave;
    uint16_t		MemForSave;

    extern osMutexId 	xIEC850StartMutex;		// мьютекс готовности к запуску TCP/IP
    extern uint8_t		IP_ADDR[4];

    eMBException    eStatus = MB_EX_NONE;
    eMBErrorCode    eRegStatus;

    /* If this request is broadcast, and it's read mode. This request don't need execute. */
    if ( xMBMasterRequestIsBroadcast() )
    {
    	eStatus = MB_EX_NONE;
    }
    else if( *usLen >= MB_PDU_SIZE_MIN + MB_PDU_FUNC_READ_SIZE_MIN )
    {
		vMBMasterGetPDUSndBuf(&ucMBFrame);											// берём из передающего буфера адрес в памяти чтобы высчитать куда положить в принятую память
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

        //  Проверим если количество регистров является действительным.
        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
        {
        	MemForSave = usRegAddress-1;// & 0xFF00;

//----------------------------------------------------------------
//- проверим в какую область памяти писать -----------------------
//----------------------------------------------------------------

// ревизия
        	if (usMRevStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, usMRevStart, MB_NumbWordRev );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Версия: '%s'\n",ReadNmb,(char *)ucMRevBuf);
                }else {
            		USART_TRACE_RED("ошибка получения версии из MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
                ReadNmb++;
        	}
// дискреты
        	else if (usMDiscInStart== MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, usMDiscInStart, MB_NumbDiscreet );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД дискретных.\n");
                }
                ReadNmb++;
        	}
// аналоги
        	else if ( usMAnalogInStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, usMAnalogInStart, MB_NumbAnalog);		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД аналогов.\n");
                }
                ReadNmb++;
        	}
//  конфигурация системы
        	else if ( usSystemCfgStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucSystemCfgBuf, usSystemCfgStart, MB_NumbSystemCfg);
                if( eRegStatus == MB_ENOERR ){	// меняем IP адрес
                	int8_t	resSetIP = Hal_setIPFromMB_Date((uint16_t*)&ucSystemCfgBuf[MB_offset_IP]);
                	if (resSetIP == 0){
                					// если всё норм то нужно сообщить о готовности работать IP
                					USART_TRACE_GREEN("%d.получили из MODBUS IP:%d.%d.%d.%d \n",ReadNmb, IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					// перезапустим таск
                					if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
                						ReStartIEC850_task();
                 					}

                					osMutexRelease(xIEC850StartMutex);
                	} else
                	if (resSetIP == -1){
                		USART_TRACE_RED("ошибка получения IP из MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	} else
                	if (resSetIP == 2){	// совпадение с прошлым включением
                		USART_TRACE_GREEN("IP из MODBUS совпадает с константой.\n");
    					osMutexRelease(xIEC850StartMutex);

                	}
                }
                ReadNmb++;
        	}
// чтение текущего времени
        	else if ( usMDateStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, usMDateStart, MB_NumbDate);				// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	nextSynchTime = Hal_getTimeInMs() + msInDay;				// следующая пересинхронизация часов
                	USART_TRACE_GREEN("%d. Получили время:0x%X следующая синхронизация:0x%X\n",ReadNmb,(unsigned int)Hal_getTimeInMs(),(unsigned int)nextSynchTime);
                	resynch = true;
                }
                ReadNmb++;
        	}
// чтение конфигурации выключателя
        	else if ( usMConfigStartSW == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBufSW, usMConfigStartSW, MB_Size_ConfSW);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг выключателя.\n",ReadNmb);
                }
                ReadNmb++;
        	}
// чтение конфигурации АПВ
        	else if ( usConfigAPWStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigAPWBuf, usConfigAPWStart, MB_NumbConfigAPW);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг АПВ.\n",ReadNmb);
                }
                ReadNmb++;
        	}

// чтение всех уставок измерительного транса
        	else if ( usConfigTRMeasStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigTRMeasBuf, usConfigTRMeasStart, MB_NumbConfigTRMeas);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг измерительного транса.\n",ReadNmb);
                }
                ReadNmb++;
        	}
// чтение конфигурации входных логических сигналов
        	else if ( usConfigVLSInStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucVLSInBuf, usConfigVLSInStart, MB_NumbConfigVLSIn);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг входных логических сигналов.\n",ReadNmb);
                }
                NumbBlokReadMB=0;
                ReadNmb++;

                //ReadNmb++;
                //ReadNmb++;
        	}
// чтение конфигурации выходных логических сигналов
			else if ((usConfigVLSOutStart <= MemForSave) && (MemForSave < (usConfigVLSOutStart+MB_NumbConfigVLSOut-1))){
				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
	            eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucVLSOutBuf[MemForSave-usConfigVLSOutStart], MemForSave, SizeAnswer);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг вЫходных логических сигналов. (0x%X)\n",ReadNmb,MemForSave);
                	NumbBlokReadMB++;
                }
                //ReadNmb++;
			}
// чтение основной или резервной группы уставок
			else if (( usConfigUstavkiStart <= MemForSave) &&(MemForSave < (usConfigUstavkiStart+MB_NumbUstavki-1))){

				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
	            eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucMUstavkiInBuf[MemForSave-usConfigUstavkiStart], MemForSave, SizeAnswer);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили группы уставок.(0x%X)\n",ReadNmb,MemForSave);
                	NumbBlokReadMB++;
                }
                //ReadNmb++;
			}
// чтение параметров автоматики
			else if ( usConfigAutomatStart == MemForSave){

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили параметры автоматики.\n",ReadNmb);
                }
                NumbBlokReadMB=0;
                ReadNmb++;
			}

//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------

            if( eRegStatus != MB_ENOERR )
            {
                eStatus = prveMBError2Exception( eRegStatus );
            }
        }
        else
        {
            eStatus = MB_EX_ILLEGAL_DATA_VALUE;
        }
    }
    else
    {
        /* Can't be a valid request because the length is incorrect. */
        eStatus = MB_EX_ILLEGAL_DATA_VALUE;
    }
    return eStatus;
}
#endif

/***********************************************************************************
 * MR5_700
 ***********************************************************************************/
#if defined (MR5_700)
eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
	extern uint64_t nextSynchTime;
	extern bool resynch;

    UCHAR          *ucMBFrame;
    uint16_t          usRegAddress;
    uint16_t          usRegCount;
    uint16_t		StartMemForSave;
    uint16_t		MemForSave;

    extern osMutexId 	xIEC850StartMutex;		// мьютекс готовности к запуску TCP/IP
    extern uint8_t		IP_ADDR[4];

    eMBException    eStatus = MB_EX_NONE;
    eMBErrorCode    eRegStatus;

    /* If this request is broadcast, and it's read mode. This request don't need execute. */
    if ( xMBMasterRequestIsBroadcast() )
    {
    	eStatus = MB_EX_NONE;
    }
    else if( *usLen >= MB_PDU_SIZE_MIN + MB_PDU_FUNC_READ_SIZE_MIN )
    {
		vMBMasterGetPDUSndBuf(&ucMBFrame);											// берём из передающего буфера адрес в памяти чтобы высчитать куда положить в принятую память
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

        //  Проверим если количество регистров является действительным.
        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
        {
        	MemForSave = usRegAddress-1;// & 0xFF00;
        	// проверим в какую область памяти писать
        	switch (MemForSave) {

        	case	MB_StartRevNaddr:					// ревизия
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, MB_StartRevNaddr, MB_NumbWordRev );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Версия: '%s'\n",(char *)ucMRevBuf);
                }else {
            		USART_TRACE_RED("ошибка получения версии из MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
                break;
        	case	MB_StartDiscreetaddr:				// дискреты
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, MB_StartDiscreetaddr, MB_NumbDiscreet );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД дискретных.\n");
                }
                break;
        	case	MB_StartAnalogINaddr:				// аналоги
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, MB_StartAnalogINaddr, MB_NumbAnalog);		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД аналогов.\n");
                }
                break;

        	case	(MB_StartConfig + MB_offset_Ktt):	// уставки
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&Ktt, MB_StartConfig + MB_offset_Ktt, 1);			// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Первичный ток ТТ: %u\n",Ktt);
                }
                break;
        	case	(MB_StartConfig + MB_offset_Ktn):	// уставки
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&Ktn, MB_StartConfig + MB_offset_Ktn, 1);			// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Коэффициент ТН: %u\n",Ktn);
                }
                break;

        	case	MB_StartConfigNaddr:		// уставки IP адрес
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBuf, MB_StartConfigNaddr, MB_NumbConfig);			// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){	// меняем IP адрес
                	int8_t	resSetIP = Hal_setIPFromMB_Date(ucMConfigBuf);
                	if (resSetIP == 0){
                					// если всё норм то нужно сообщить о готовности работать IP
                					USART_TRACE_BLUE("получили из MODBUS IP:%d.%d.%d.%d \n", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					// перезапустим таск
                					if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
                						ReStartIEC850_task();
                 					}

                					osMutexRelease(xIEC850StartMutex);
                	} else
                	if (resSetIP == -1){
                		USART_TRACE_RED("ошибка получения IP из MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	} else
                	if (resSetIP == 2){	// совпадение с прошлым включением
                		USART_TRACE_GREEN("IP из MODBUS совпадает с константой.\n");
    					osMutexRelease(xIEC850StartMutex);

                	}
                }
                break;

        	case	MB_StartDateNaddr:		// часы
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, MB_StartDateNaddr, MB_NumbDate);				// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	USART_TRACE_GREEN("Получили время:0x%X\n",(unsigned int)Hal_getTimeInMs());
                	nextSynchTime = Hal_getTimeInMs() + msInDay;				// следующая пересинхронизация часов
                	USART_TRACE_GREEN("следующая синхронизация:0x%X\n",(unsigned int)nextSynchTime);
                	resynch = true;

                }
                break;

        	case	MB_StartConfig:		// уставки
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBufall, MB_StartConfig, MB_NumbConfigall);		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Получили уставки.\n");
                } else{
                	USART_TRACE_RED("Не получили уставки.\n");
                }
                break;
        	}

            if( eRegStatus != MB_ENOERR )
            {
                eStatus = prveMBError2Exception( eRegStatus );
            }
        }
        else
        {
            eStatus = MB_EX_ILLEGAL_DATA_VALUE;
        }
    }
    else
    {
        /* Can't be a valid request because the length is incorrect. */
        eStatus = MB_EX_ILLEGAL_DATA_VALUE;
    }
    return eStatus;
}
#endif
/***********************************************************************************
 * MR5_600
 ***********************************************************************************/
#if defined (MR5_600)
eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
	extern uint64_t nextSynchTime;
	extern bool resynch;

    UCHAR          *ucMBFrame;
    uint16_t          usRegAddress;
    uint16_t          usRegCount;
    uint16_t		StartMemForSave;
    uint16_t		MemForSave;

    extern osMutexId 	xIEC850StartMutex;		// мьютекс готовности к запуску TCP/IP
    extern uint8_t		IP_ADDR[4];

    eMBException    eStatus = MB_EX_NONE;
    eMBErrorCode    eRegStatus;

    /* If this request is broadcast, and it's read mode. This request don't need execute. */
    if ( xMBMasterRequestIsBroadcast() )
    {
    	eStatus = MB_EX_NONE;
    }
    else if( *usLen >= MB_PDU_SIZE_MIN + MB_PDU_FUNC_READ_SIZE_MIN )
    {
		vMBMasterGetPDUSndBuf(&ucMBFrame);											// берём из передающего буфера адрес в памяти чтобы высчитать куда положить в принятую память
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

        //  Проверим если количество регистров является действительным.
        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
        {
        	MemForSave = usRegAddress-1;// & 0xFF00;
        	// проверим в какую область памяти писать
        	switch (MemForSave) {

        	case	MB_StartRevNaddr:					// ревизия
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, MB_StartRevNaddr, MB_NumbWordRev );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Версия: '%s'\n",(char *)ucMRevBuf);
                }else {
            		USART_TRACE_RED("ошибка получения версии из MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
                break;
        	case	MB_StartDiscreetaddr:				// дискреты
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, MB_StartDiscreetaddr, MB_NumbDiscreet );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД дискретных.\n");
                }
                break;
        	case	MB_StartAnalogINaddr:				// аналоги
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, MB_StartAnalogINaddr, MB_NumbAnalog);		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД аналогов.\n");
                }
                break;

       	case	(MB_StartConfig + MB_offset_Ktn):	// уставки
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&Ktn, MB_StartConfig + MB_offset_Ktn, 1);			// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Коэффициент ТН: %u\n",Ktn);
                }
                break;

        	case	MB_StartConfigNaddr:		// уставки IP адрес
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBuf, MB_StartConfigNaddr, MB_NumbConfig);			// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){	// меняем IP адрес
                	if (Hal_setIPFromMB_Date(ucMConfigBuf) == 0){
                					// если всё норм то нужно сообщить о готовности работать IP
                					USART_TRACE_BLUE("получили из MODBUS IP:%d.%d.%d.%d \n", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					// перезапустим таск
                					if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
                						ReStartIEC850_task();
                 					}

                					osMutexRelease(xIEC850StartMutex);
                	} else
                	if (Hal_setIPFromMB_Date(ucMConfigBuf) == -1){
                		USART_TRACE_RED("ошибка получения IP из MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	}
                }
                break;

        	case	MB_StartDateNaddr:		// часы
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, MB_StartDateNaddr, MB_NumbDate);				// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	USART_TRACE_GREEN("MB: Получили время:0x%X\n",(unsigned int)Hal_getTimeInMs());
                	nextSynchTime = Hal_getTimeInMs() + msInDay;				// следующая пересинхронизация часов
                	USART_TRACE_GREEN("MB: следующая синхронизация:0x%X\n",(unsigned int)nextSynchTime);
                	resynch = true;

                }
                break;

        	case	MB_StartConfig:		// уставки
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBufall, MB_StartConfig, MB_NumbConfigall);		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Получили уставки.\n");
                } else{
                	USART_TRACE_RED("Не получили уставки.\n");
                }
                break;
        	default:
        		eRegStatus = MB_ENOERR;
            break;
        	}

            if( eRegStatus != MB_ENOERR )
            {
                eStatus = prveMBError2Exception( eRegStatus );
            }
        }
        else
        {
            eStatus = MB_EX_ILLEGAL_DATA_VALUE;
        }
    }
    else
    {
        /* Can't be a valid request because the length is incorrect. */
        eStatus = MB_EX_ILLEGAL_DATA_VALUE;
    }
    return eStatus;
}
#endif // ! defined (MR5_xxx)
/***********************************************************************************
 * MR5_500
 ***********************************************************************************/
#if defined (MR5_500)
eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
	extern uint64_t nextSynchTime;
	extern bool resynch;

    UCHAR          *ucMBFrame;
    uint16_t          usRegAddress;
    uint16_t          usRegCount;
    uint16_t		StartMemForSave;
    uint16_t		MemForSave;

    extern osMutexId 	xIEC850StartMutex;		// мьютекс готовности к запуску TCP/IP
    extern uint8_t		IP_ADDR[4];

    eMBException    eStatus = MB_EX_NONE;
    eMBErrorCode    eRegStatus;

    /* If this request is broadcast, and it's read mode. This request don't need execute. */
    if ( xMBMasterRequestIsBroadcast() )
    {
    	eStatus = MB_EX_NONE;
    }
    else if( *usLen >= MB_PDU_SIZE_MIN + MB_PDU_FUNC_READ_SIZE_MIN )
    {
		vMBMasterGetPDUSndBuf(&ucMBFrame);											// берём из передающего буфера адрес в памяти чтобы высчитать куда положить в принятую память
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

        //  Проверим если количество регистров является действительным.
        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
        {
        	MemForSave = usRegAddress-1;// & 0xFF00;
        	// проверим в какую область памяти писать
        	switch (MemForSave) {

        	case	MB_StartRevNaddr:					// ревизия
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, MB_StartRevNaddr, MB_NumbWordRev );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Версия: '%s'\n",(char *)ucMRevBuf);
                }else {
            		USART_TRACE_RED("ошибка получения версии из MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
                break;
        	case	MB_StartDiscreetaddr:				// дискреты
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, MB_StartDiscreetaddr, MB_NumbDiscreet );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД дискретных.\n");
                }
                break;
        	case	MB_StartAnalogINaddr:				// аналоги
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, MB_StartAnalogINaddr, MB_NumbAnalog);		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД аналогов.\n");
                }
                break;

        	case	(MB_StartConfig + MB_offset_Ktt):	// уставки
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&Ktt, MB_StartConfig + MB_offset_Ktt, 1);			// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Первичный ток ТТ: %u\n",Ktt);
                }
                break;
        	case	(MB_StartConfig + MB_offset_Ktn):	// уставки
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&Ktn, MB_StartConfig + MB_offset_Ktn, 1);			// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Коэффициент ТН: %u\n",Ktn);
                }
                break;

        	case	MB_StartConfigNaddr:		// уставки IP адрес
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBuf, MB_StartConfigNaddr, MB_NumbConfig);			// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){	// меняем IP адрес
                	int8_t	resSetIP = Hal_setIPFromMB_Date(ucMConfigBuf);
                	if (resSetIP == 0){
                					// если всё норм то нужно сообщить о готовности работать IP
                					USART_TRACE_BLUE("получили из MODBUS IP:%d.%d.%d.%d \n", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					// перезапустим таск
                					if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
                						ReStartIEC850_task();
                 					}

                					osMutexRelease(xIEC850StartMutex);
                	} else
                	if (resSetIP == -1){
                		USART_TRACE_RED("ошибка получения IP из MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	} else
                	if (resSetIP == 2){	// совпадение с прошлым включением
                		USART_TRACE_GREEN("IP из MODBUS совпадает с константой.\n");
    					osMutexRelease(xIEC850StartMutex);

                	}
                }
                break;

        	case	MB_StartDateNaddr:		// часы
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, MB_StartDateNaddr, MB_NumbDate);				// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	USART_TRACE_GREEN("Получили время:0x%X\n",(unsigned int)Hal_getTimeInMs());
                	nextSynchTime = Hal_getTimeInMs() + msInDay;				// следующая пересинхронизация часов
                	USART_TRACE_GREEN("следующая синхронизация:0x%X\n",(unsigned int)nextSynchTime);
                	resynch = true;

                }
                break;

        	case	MB_StartConfig:		// уставки
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBufall, MB_StartConfig, MB_NumbConfigall);		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Получили уставки.\n");
                } else{
                	USART_TRACE_RED("Не получили уставки.\n");
                }
                break;
        	}

            if( eRegStatus != MB_ENOERR )
            {
                eStatus = prveMBError2Exception( eRegStatus );
            }
        }
        else
        {
            eStatus = MB_EX_ILLEGAL_DATA_VALUE;
        }
    }
    else
    {
        /* Can't be a valid request because the length is incorrect. */
        eStatus = MB_EX_ILLEGAL_DATA_VALUE;
    }
    return eStatus;
}
#endif

/*************************************************************************
 * MR801
 *************************************************************************/
#if defined (MR801)
eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
	extern uint64_t nextSynchTime;
	extern bool resynch;

    UCHAR          *ucMBFrame;
    uint16_t          usRegAddress;
    uint16_t          usRegCount;
    uint16_t		StartMemForSave;
    uint16_t		MemForSave;

    extern osMutexId 	xIEC850StartMutex;		// мьютекс готовности к запуску TCP/IP
    extern uint8_t		IP_ADDR[4];

    eMBException    eStatus = MB_EX_NONE;
    eMBErrorCode    eRegStatus;

    /* If this request is broadcast, and it's read mode. This request don't need execute. */
    if ( xMBMasterRequestIsBroadcast() )
    {
    	eStatus = MB_EX_NONE;
    }
    else if( *usLen >= MB_PDU_SIZE_MIN + MB_PDU_FUNC_READ_SIZE_MIN )
    {
		vMBMasterGetPDUSndBuf(&ucMBFrame);											// берём из передающего буфера адрес в памяти чтобы высчитать куда положить в принятую память
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

        //  Проверим если количество регистров является действительным.
        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
        {
        	MemForSave = usRegAddress-1;// & 0xFF00;

//----------------------------------------------------------------
//- проверим в какую область памяти писать -----------------------
//----------------------------------------------------------------

// ревизия
        	if (usMRevStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, usMRevStart, MB_NumbWordRev );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Версия: '%s'\n",ReadNmb,(char *)ucMRevBuf);
                }else {
            		USART_TRACE_RED("ошибка получения версии из MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
                ReadNmb++;
        	}
// дискреты
        	else if (usMDiscInStart== MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, usMDiscInStart, MB_NumbDiscreet );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД дискретных.\n");
                }
                ReadNmb++;
        	}
// аналоги
        	else if ( usMAnalogInStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, usMAnalogInStart, MB_NumbAnalog);		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД аналогов.\n");
                }
                ReadNmb++;
        	}
//  конфигурация системы
        	else if ( usSystemCfgStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucSystemCfgBuf, usSystemCfgStart, MB_NumbSystemCfg);
                if( eRegStatus == MB_ENOERR ){	// меняем IP адрес
                	int8_t	resSetIP = Hal_setIPFromMB_Date((uint16_t*)&ucSystemCfgBuf[MB_offset_IP]);
                	if (resSetIP == 0){
                					// если всё норм то нужно сообщить о готовности работать IP
                					USART_TRACE_GREEN("%d.получили из MODBUS IP:%d.%d.%d.%d \n",ReadNmb, IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					// перезапустим таск
                					if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
                						ReStartIEC850_task();
                 					}

                					osMutexRelease(xIEC850StartMutex);
                	} else
                	if (resSetIP == -1){
                		USART_TRACE_RED("ошибка получения IP из MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	} else
                	if (resSetIP == 2){	// совпадение с прошлым включением
                		USART_TRACE_GREEN("IP из MODBUS совпадает с константой.\n");
    					osMutexRelease(xIEC850StartMutex);

                	}
                }
                ReadNmb++;
        	}
// чтение текущего времени
        	else if ( usMDateStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, usMDateStart, MB_NumbDate);				// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	nextSynchTime = Hal_getTimeInMs() + msInDay;				// следующая пересинхронизация часов
                	USART_TRACE_GREEN("%d. Получили время:0x%X следующая синхронизация:0x%X\n",ReadNmb,(unsigned int)Hal_getTimeInMs(),(unsigned int)nextSynchTime);
                	resynch = true;
                }
                ReadNmb++;
        	}
// чтение конфигурации выключателя
        	else if ( usMConfigStartSW == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBufSW, usMConfigStartSW, MB_Size_ConfSW);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг выключателя.\n",ReadNmb);
                }
                ReadNmb++;
        	}
// чтение конфигурации АПВ
        	else if ( usConfigAPWStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigAPWBuf, usConfigAPWStart, MB_NumbConfigAPW);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг АПВ.\n",ReadNmb);
                }
                ReadNmb++;
        	}
// чтение конфигурации АВР+ЛЗШ
        	else if ( usConfigAWRStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigAWRBuf, usConfigAWRStart, MB_NumbConfigAWR);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг АВР+ЛЗШ.\n",ReadNmb);
                	uint8_t	i;
                	for(i=0;i<MB_NumbConfigAWR;i++) USART_0TRACE("0x%.4X ",ucConfigAWRBuf[i]);
                	USART_0TRACE("\n");

                }
                ReadNmb++;
    		}
// чтение всех уставок силового транса
        	else if ( usConfigTRPWRStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigTRPWRBuf, usConfigTRPWRStart, MB_NumbConfigTRPWR);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили уставки силового транса.\n",ReadNmb);
                	uint8_t	i;
                	for(i=0;i<MB_NumbConfigTRPWR;i++) USART_0TRACE("0x%.4X ",ucConfigTRPWRBuf[i]);
                	USART_0TRACE("\n");

                }
                ReadNmb++;
			}
// чтение всех уставок измерительного транса
        	else if ( usConfigTRMeasStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigTRMeasBuf, usConfigTRMeasStart, MB_NumbConfigTRMeas);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг измерительного транса.\n",ReadNmb);
                	uint8_t	i;
                	for(i=0;i<MB_NumbConfigTRMeas;i++) USART_0TRACE("0x%.4X ",ucConfigTRMeasBuf[i]);
                	USART_0TRACE("\n");
                }
                ReadNmb++;
        	}
// чтение конфигурации входных логических сигналов
        	else if ( usConfigVLSInStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucVLSInBuf, usConfigVLSInStart, MB_NumbConfigVLSIn);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг входных логических сигналов.\n",ReadNmb);
                }
                NumbBlokReadMB=0;
                ReadNmb++;

                //ReadNmb++;
                //ReadNmb++;
        	}
// чтение конфигурации выходных логических сигналов
			else if ((MemForSave >= usConfigVLSOutStart) && (MemForSave < (usConfigVLSOutStart+MB_NumbConfigVLSOut-1))){
				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
	            eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucVLSOutBuf[MemForSave-usConfigVLSOutStart], MemForSave, SizeAnswer);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d-%d. Получили конфиг вЫходных логических сигналов. (0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
                	NumbBlokReadMB++;
                }
                //ReadNmb++;
			}
// чтение основной или резервной группы уставок
			else if (( usConfigUstavkiStart <= MemForSave) &&(MemForSave < (usConfigUstavkiStart+MB_NumbUstavki-1))){

				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
	            eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucMUstavkiInBuf[MemForSave-usConfigUstavkiStart], MemForSave, SizeAnswer);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d-%d. Получили группы уставок.(0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
                	NumbBlokReadMB++;
                }
                //ReadNmb++;
			}
// чтение параметров автоматики
			else if ( usConfigAutomatStart == MemForSave){

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили параметры автоматики.\n",ReadNmb);
                }
                NumbBlokReadMB=0;
                ReadNmb++;
			}

//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------

            if( eRegStatus != MB_ENOERR )
            {
                eStatus = prveMBError2Exception( eRegStatus );
            }
        }
        else
        {
            eStatus = MB_EX_ILLEGAL_DATA_VALUE;
        }
    }
    else
    {
        /* Can't be a valid request because the length is incorrect. */
        eStatus = MB_EX_ILLEGAL_DATA_VALUE;
    }
    return eStatus;
}
#endif
/*************************************************************************
 * MR901 MR902
 *************************************************************************/
#if defined (MR901) || defined (MR902)
eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
	extern uint64_t nextSynchTime;
	extern bool resynch;

    UCHAR          *ucMBFrame;
    uint16_t          usRegAddress;
    uint16_t          usRegCount;
    uint16_t		StartMemForSave;
    uint16_t		MemForSave;

    extern osMutexId 	xIEC850StartMutex;		// мьютекс готовности к запуску TCP/IP
    extern uint8_t		IP_ADDR[4];

    eMBException    eStatus = MB_EX_NONE;
    eMBErrorCode    eRegStatus;

    /* If this request is broadcast, and it's read mode. This request don't need execute. */
    if ( xMBMasterRequestIsBroadcast() )
    {
    	eStatus = MB_EX_NONE;
    }
    else if( *usLen >= MB_PDU_SIZE_MIN + MB_PDU_FUNC_READ_SIZE_MIN )
    {
		vMBMasterGetPDUSndBuf(&ucMBFrame);											// берём из передающего буфера адрес в памяти чтобы высчитать куда положить в принятую память
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

        //  Проверим если количество регистров является действительным.
        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
        {
        	MemForSave = usRegAddress-1;// & 0xFF00;

//----------------------------------------------------------------
//- проверим в какую область памяти писать -----------------------
//----------------------------------------------------------------

// ревизия
        	if (usMRevStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, usMRevStart, MB_NumbWordRev );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Версия: '%s'\n",ReadNmb,(char *)ucMRevBuf);
                }else {
            		USART_TRACE_RED("ошибка получения версии из MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
                ReadNmb++;
        	}
// дискреты
        	else if (usMDiscInStart== MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, usMDiscInStart, MB_NumbDiscreet );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД дискретных.\n");
                }
                ReadNmb++;
        	}
// аналоги
        	else if ( usMAnalogInStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, usMAnalogInStart, MB_NumbAnalog);		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД аналогов.\n");
                }
                ReadNmb++;
        	}
//  конфигурация системы
        	else if ( usSystemCfgStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucSystemCfgBuf, usSystemCfgStart, MB_NumbSystemCfg);
                if( eRegStatus == MB_ENOERR ){	// меняем IP адрес
                	int8_t	resSetIP = Hal_setIPFromMB_Date((uint16_t*)&ucSystemCfgBuf[MB_offset_IP]);
                	if (resSetIP == 0){
                					// если всё норм то нужно сообщить о готовности работать IP
                					USART_TRACE_GREEN("%d.получили из MODBUS IP:%d.%d.%d.%d \n",ReadNmb, IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					// перезапустим таск
                					if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
                						ReStartIEC850_task();
                 					}

                					osMutexRelease(xIEC850StartMutex);
                	} else
                	if (resSetIP == -1){
                		USART_TRACE_RED("ошибка получения IP из MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	} else
                	if (resSetIP == 2){	// совпадение с прошлым включением
                		USART_TRACE_GREEN("IP из MODBUS совпадает с константой.\n");
    					osMutexRelease(xIEC850StartMutex);

                	}
                }
                ReadNmb++;
        	}
// чтение текущего времени
        	else if ( usMDateStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, usMDateStart, MB_NumbDate);				// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	nextSynchTime = Hal_getTimeInMs() + msInDay;				// следующая пересинхронизация часов
                	USART_TRACE_GREEN("%d. Получили время:0x%X следующая синхронизация:0x%X\n",ReadNmb,(unsigned int)Hal_getTimeInMs(),(unsigned int)nextSynchTime);
                	resynch = true;
                }
                ReadNmb++;
        	}
// чтение конфигурации выключателя
        	else if ( usMConfigStartSW == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBufSW, usMConfigStartSW, MB_Size_ConfSW);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг выключателя.\n",ReadNmb);
                }
                ReadNmb++;
        	}
// чтение конфигурации АПВ
        	else if ( usConfigAPWStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigAPWBuf, usConfigAPWStart, MB_NumbConfigAPW);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг АПВ.\n",ReadNmb);
                }
                ReadNmb++;
        	}
// чтение конфигурации АВР+ЛЗШ
        	else if ( usConfigAWRStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigAWRBuf, usConfigAWRStart, MB_NumbConfigAWR);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг АВР+ЛЗШ.\n",ReadNmb);
                	uint8_t	i;
                	for(i=0;i<MB_NumbConfigAWR;i++) USART_0TRACE("0x%.4X ",ucConfigAWRBuf[i]);
                	USART_0TRACE("\n");

                }
                ReadNmb++;
    		}
// чтение всех уставок силового транса
        	else if ( usConfigTRPWRStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigTRPWRBuf, usConfigTRPWRStart, MB_NumbConfigTRPWR);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили уставки силового транса.\n",ReadNmb);
                	uint8_t	i;
                	for(i=0;i<MB_NumbConfigTRPWR;i++) USART_0TRACE("0x%.4X ",ucConfigTRPWRBuf[i]);
                	USART_0TRACE("\n");

                }
                ReadNmb++;
			}
// чтение всех уставок измерительного транса
        	else if ( usConfigTRMeasStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigTRMeasBuf, usConfigTRMeasStart, MB_NumbConfigTRMeas);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг измерительного транса.\n",ReadNmb);
                	uint8_t	i;
                	for(i=0;i<MB_NumbConfigTRMeas;i++) USART_0TRACE("0x%.4X ",ucConfigTRMeasBuf[i]);
                	USART_0TRACE("\n");
                }
                ReadNmb++;
        	}
// чтение конфигурации входных логических сигналов
        	else if ( usConfigVLSInStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucVLSInBuf, usConfigVLSInStart, MB_NumbConfigVLSIn);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили конфиг входных логических сигналов.\n",ReadNmb);
                }
                NumbBlokReadMB=0;
                ReadNmb++;

                //ReadNmb++;
                //ReadNmb++;
        	}
// чтение конфигурации выходных логических сигналов
			else if ((MemForSave >= usConfigVLSOutStart) && (MemForSave < (usConfigVLSOutStart+MB_NumbConfigVLSOut-1))){
				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
	            eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucVLSOutBuf[MemForSave-usConfigVLSOutStart], MemForSave, SizeAnswer);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d-%d. Получили конфиг вЫходных логических сигналов. (0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
                	NumbBlokReadMB++;
                }
                //ReadNmb++;
			}
// чтение основной или резервной группы уставок
			else if (( usConfigUstavkiStart <= MemForSave) &&(MemForSave < (usConfigUstavkiStart+MB_NumbUstavki-1))){

				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
	            eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucMUstavkiInBuf[MemForSave-usConfigUstavkiStart], MemForSave, SizeAnswer);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d-%d. Получили группы уставок.(0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
                	NumbBlokReadMB++;
                }
                //ReadNmb++;
			}
// чтение параметров автоматики
			else if ( usConfigAutomatStart == MemForSave){

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. Получили параметры автоматики.\n",ReadNmb);
                }
                NumbBlokReadMB=0;
                ReadNmb++;
			}

//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------

            if( eRegStatus != MB_ENOERR )
            {
                eStatus = prveMBError2Exception( eRegStatus );
            }
        }
        else
        {
            eStatus = MB_EX_ILLEGAL_DATA_VALUE;
        }
    }
    else
    {
        /* Can't be a valid request because the length is incorrect. */
        eStatus = MB_EX_ILLEGAL_DATA_VALUE;
    }
    return eStatus;
}
#endif
#endif

#if MB_FUNC_READWRITE_HOLDING_ENABLED > 0

/**
 * This function will request read and write holding register.
 *
 * @param ucSndAddr salve address
 * @param usReadRegAddr read register start address
 * @param usNReadRegs read register total number
 * @param pusDataBuffer data to be written
 * @param usWriteRegAddr write register start address
 * @param usNWriteRegs write register total number
 * @param lTimeOut timeout (-1 will waiting forever)
 *
 * @return error code
 */
eMBMasterReqErrCode
eMBMasterReqReadWriteMultipleHoldingRegister( UCHAR ucSndAddr,
		USHORT usReadRegAddr, USHORT usNReadRegs, USHORT * pusDataBuffer,
		USHORT usWriteRegAddr, USHORT usNWriteRegs, LONG lTimeOut )
{
    UCHAR                 *ucMBFrame;
    USHORT                 usRegIndex = 0;
    eMBMasterReqErrCode    eErrStatus = MB_MRE_NO_ERR;

    if ( ucSndAddr > MB_MASTER_TOTAL_SLAVE_NUM ) eErrStatus = MB_MRE_ILL_ARG;
    else if ( xMBMasterRunResTake( lTimeOut ) == FALSE ) eErrStatus = MB_MRE_MASTER_BUSY;
    else
    {
		vMBMasterGetPDUSndBuf(&ucMBFrame);
		vMBMasterSetDestAddress(ucSndAddr);
		ucMBFrame[MB_PDU_FUNC_OFF]                           = MB_FUNC_READWRITE_MULTIPLE_REGISTERS;
		ucMBFrame[MB_PDU_REQ_READWRITE_READ_ADDR_OFF]        = usReadRegAddr >> 8;
		ucMBFrame[MB_PDU_REQ_READWRITE_READ_ADDR_OFF + 1]    = usReadRegAddr;
		ucMBFrame[MB_PDU_REQ_READWRITE_READ_REGCNT_OFF]      = usNReadRegs >> 8;
		ucMBFrame[MB_PDU_REQ_READWRITE_READ_REGCNT_OFF + 1]  = usNReadRegs ;
		ucMBFrame[MB_PDU_REQ_READWRITE_WRITE_ADDR_OFF]       = usWriteRegAddr >> 8;
		ucMBFrame[MB_PDU_REQ_READWRITE_WRITE_ADDR_OFF + 1]   = usWriteRegAddr;
		ucMBFrame[MB_PDU_REQ_READWRITE_WRITE_REGCNT_OFF]     = usNWriteRegs >> 8;
		ucMBFrame[MB_PDU_REQ_READWRITE_WRITE_REGCNT_OFF + 1] = usNWriteRegs ;
		ucMBFrame[MB_PDU_REQ_READWRITE_WRITE_BYTECNT_OFF]    = usNWriteRegs * 2;
		ucMBFrame += MB_PDU_REQ_READWRITE_WRITE_VALUES_OFF;
		while( usNWriteRegs > usRegIndex)
		{
			*ucMBFrame++ = pusDataBuffer[usRegIndex] >> 8;
			*ucMBFrame++ = pusDataBuffer[usRegIndex++] ;
		}
		vMBMasterSetPDUSndLength( MB_PDU_SIZE_MIN + MB_PDU_REQ_READWRITE_SIZE_MIN + 2*usNWriteRegs );
		( void ) xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );
		eErrStatus = eMBMasterWaitRequestFinish( );
    }
    return eErrStatus;
}

eMBException
eMBMasterFuncReadWriteMultipleHoldingRegister( UCHAR * pucFrame, USHORT * usLen )
{
    USHORT          usRegReadAddress;
    USHORT          usRegReadCount;
    USHORT          usRegWriteAddress;
    USHORT          usRegWriteCount;
    UCHAR          *ucMBFrame;

    eMBException    eStatus = MB_EX_NONE;
    eMBErrorCode    eRegStatus;

    /* If this request is broadcast, and it's read mode. This request don't need execute. */
    if ( xMBMasterRequestIsBroadcast() )
    {
    	eStatus = MB_EX_NONE;
    }
    else if( *usLen >= MB_PDU_SIZE_MIN + MB_PDU_FUNC_READWRITE_SIZE_MIN )
    {
    	vMBMasterGetPDUSndBuf(&ucMBFrame);
        usRegReadAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READWRITE_READ_ADDR_OFF] << 8U );
        usRegReadAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READWRITE_READ_ADDR_OFF + 1] );
        usRegReadAddress++;

        usRegReadCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READWRITE_READ_REGCNT_OFF] << 8U );
        usRegReadCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READWRITE_READ_REGCNT_OFF + 1] );

        usRegWriteAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READWRITE_WRITE_ADDR_OFF] << 8U );
        usRegWriteAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READWRITE_WRITE_ADDR_OFF + 1] );
        usRegWriteAddress++;

        usRegWriteCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READWRITE_WRITE_REGCNT_OFF] << 8U );
        usRegWriteCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READWRITE_WRITE_REGCNT_OFF + 1] );

        if( ( 2 * usRegReadCount ) == pucFrame[MB_PDU_FUNC_READWRITE_READ_BYTECNT_OFF] )
        {
            /* Make callback to update the register values. */
            eRegStatus = eMBMasterRegHoldingCB( &ucMBFrame[MB_PDU_REQ_READWRITE_WRITE_VALUES_OFF],
                                           usRegWriteAddress, usRegWriteCount, MB_REG_WRITE );

            if( eRegStatus == MB_ENOERR )
            {
                /* Make the read callback. */
				eRegStatus = eMBMasterRegHoldingCB(&pucFrame[MB_PDU_FUNC_READWRITE_READ_VALUES_OFF],
						                      usRegReadAddress, usRegReadCount, MB_REG_READ);
            }
            if( eRegStatus != MB_ENOERR )
            {
                eStatus = prveMBError2Exception( eRegStatus );
            }
        }
        else
        {
            eStatus = MB_EX_ILLEGAL_DATA_VALUE;
        }
    }
    return eStatus;
}

#endif
#endif

