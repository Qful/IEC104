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
extern	xQueueHandle 	Rd_SysNoteQueue;		// ������� ��� �������� ������� �������
extern	xQueueHandle 	Rd_ErrorNoteQueue;		// ������� ��� �������� ������� ������


extern IedServer iedServer;
extern osThreadId IEC850TaskHandle;

extern uint16_t	GlobalAddrSysNote;
extern uint16_t	GlobalAddrErrorNote;
extern bool		getJurnals;
/*************************************************************************
 * MR771 MR761 MR762 MR763
 *************************************************************************/
#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763)
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
extern uint16_t   ucSWCNTBuf[MB_NumbSw_CNT];



extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usMConfigStartSW;
extern uint16_t   usConfigUstavkiStart;			// ������ �������
extern uint16_t   usConfigAutomatStart;			// ��������� ����������
extern uint16_t   usConfigVLSInStart;			// ������ ������������ ������� ���������� ��������
extern uint16_t   usConfigVLSOutStart;			// ������ ������������ �������� ���������� ��������
extern uint16_t   usConfigAPWStart;				// ������������ ���
extern uint16_t   usSystemCfgStart;				// ��������� �������
extern uint16_t   usConfigTRMeasStart;			// ������������ �������������� ������
extern uint16_t   usSGStart;
extern uint16_t   usConfigAutomatStart;
extern uint16_t   usSWCntStart;							// ������ �����������

#endif

/*************************************************************************
 * MR5_700
 *************************************************************************/
#if defined (MR5_700)

extern uint16_t   ucSysNoteBufPre[MB_NumbSysNote];				// ��������� ������
extern uint16_t   ucSysNoteBufNext[MB_NumbSysNote];
extern uint16_t   ucSysNoteBuf[MB_NumbSysNote];				// ����� ��� ��������

extern uint16_t   ucErrorNoteBufPre[MB_NumbSysNote];				// ��������� ������
extern uint16_t   ucErrorNoteBufNext[MB_NumbSysNote];
extern uint16_t   ucErrorNoteBuf[MB_NumbSysNote];				// ����� ��� ��������


extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucSWCrash[MB_NumbSWCrash];
extern uint16_t   ucConfigBufSW[MB_NumbConfigSW];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucAutomatBuf[MB_NumbAutomat];
extern uint16_t   ucOutSignalBuf[MB_NumbConfigOut];
extern uint16_t   ucSystemCfgBuf[MB_NumbSystemCfg];
extern uint16_t   ucConfigBufExZ[MB_NumbConfigExZ];
extern uint16_t   ucConfigBufMTZ[MB_NumbConfigMTZ];
extern uint16_t   ucConfigBufI2I1I0[MB_NumbConfigI2I1I0];
extern uint16_t   ucConfigBufF[MB_NumbConfigF];
extern uint16_t   ucConfigBufU[MB_NumbConfigU];

extern uint16_t   usSysNoteStart;
extern uint16_t   usErrorNoteStart;

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigStartSWCrash;	// ������ �����������
extern uint16_t   usConfigStartSW;			// ������������ �����������
extern uint16_t   usConfigUstavkiStart;		// ����� �������
extern uint16_t   usConfigAutomatStart;		// ��������� ����������
extern uint16_t   usConfigOutStart;			// ������ ������������ �������� ��������
extern uint16_t   usSystemCfgStart;			// ��������� �������
extern uint16_t   usConfigStartExZ;			// ������������ ������� �����
extern uint16_t   usConfigStartMTZ;			// ������������ ������� �����
extern uint16_t   usConfigStartI2I1I0;		// ������������ �������������� ������
extern uint16_t   usConfigStartF;			// ������������ ������ �� �������
extern uint16_t   usConfigStartU;			// ������������ ������ �� ����������


#endif
#if defined (MR5_600)

extern uint16_t   ucSysNoteBufPre[MB_NumbSysNote];				// ��������� ������
extern uint16_t   ucSysNoteBufNext[MB_NumbSysNote];
extern uint16_t   ucSysNoteBuf[MB_NumbSysNote];				// ����� ��� ��������

extern uint16_t   ucErrorNoteBufPre[MB_NumbSysNote];				// ��������� ������
extern uint16_t   ucErrorNoteBufNext[MB_NumbSysNote];
extern uint16_t   ucErrorNoteBuf[MB_NumbSysNote];				// ����� ��� ��������


extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucOutSignalBuf[MB_NumbConfigOut];
extern uint16_t   ucSystemCfgBuf[MB_NumbSystemCfg];
extern uint16_t   ucConfigBufExZ[MB_NumbConfigExZ];
extern uint16_t   ucConfigBufF[MB_NumbConfigF];
extern uint16_t   ucConfigBufU[MB_NumbConfigU];

extern uint16_t   usSysNoteStart;
extern uint16_t   usErrorNoteStart;

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigStartSWCrash;	// ������ �����������
extern uint16_t   usConfigStartSW;			// ������������ �����������
extern uint16_t   usConfigUstavkiStart;		// ����� �������
extern uint16_t   usConfigAutomatStart;		// ��������� ����������
extern uint16_t   usConfigOutStart;			// ������ ������������ �������� ��������
extern uint16_t   usSystemCfgStart;			// ��������� �������
extern uint16_t   usConfigStartExZ;			// ������������ ������� �����
extern uint16_t   usConfigStartMTZ;			// ������������ ������� �����
extern uint16_t   usConfigStartI2I1I0;		// ������������ �������������� ������
extern uint16_t   usConfigStartF;			// ������������ ������ �� �������
extern uint16_t   usConfigStartU;			// ������������ ������ �� ����������

#endif
#if defined (MR5_500)

extern uint16_t   ucSysNoteBufPre[MB_NumbSysNote];				// ��������� ������
extern uint16_t   ucSysNoteBufNext[MB_NumbSysNote];
extern uint16_t   ucSysNoteBuf[MB_NumbSysNote];				// ����� ��� ��������

extern uint16_t   ucErrorNoteBufPre[MB_NumbSysNote];				// ��������� ������
extern uint16_t   ucErrorNoteBufNext[MB_NumbSysNote];
extern uint16_t   ucErrorNoteBuf[MB_NumbSysNote];				// ����� ��� ��������


extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucSWCrash[MB_NumbSWCrash];
extern uint16_t   ucConfigBufSW[MB_NumbConfigSW];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucAutomatBuf[MB_NumbAutomat];
extern uint16_t   ucOutSignalBuf[MB_NumbConfigOut];
extern uint16_t   ucSystemCfgBuf[MB_NumbSystemCfg];
extern uint16_t   ucConfigBufExZ[MB_NumbConfigExZ];
extern uint16_t   ucConfigBufMTZ[MB_NumbConfigMTZ];
extern uint16_t   ucConfigBufI2I1I0[MB_NumbConfigI2I1I0];

extern uint16_t   usSysNoteStart;
extern uint16_t   usErrorNoteStart;

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigStartSWCrash;	// ������ �����������
extern uint16_t   usConfigStartSW;			// ������������ �����������
extern uint16_t   usConfigUstavkiStart;		// ����� �������
extern uint16_t   usConfigAutomatStart;		// ��������� ����������
extern uint16_t   usConfigOutStart;			// ������ ������������ �������� ��������
extern uint16_t   usSystemCfgStart;			// ��������� �������
extern uint16_t   usConfigStartExZ;			// ������������ ������� �����
extern uint16_t   usConfigStartMTZ;			// ������������ ������� �����
extern uint16_t   usConfigStartI2I1I0;		// ������������ �������������� ������
extern uint16_t   usConfigStartF;			// ������������ ������ �� �������
extern uint16_t   usConfigStartU;			// ������������ ������ �� ����������

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
extern uint16_t   ucSWCNTBuf[MB_NumbSw_CNT];

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usMConfigStartSW;
extern uint16_t   usConfigUstavkiStart;			// ������ �������
extern uint16_t   usConfigAutomatStart;			// ��������� ����������
extern uint16_t   usConfigVLSInStart;			// ������ ������������ ������� ���������� ��������
extern uint16_t   usConfigVLSOutStart;			// ������ ������������ �������� ���������� ��������
extern uint16_t   usConfigAPWStart;				// ������������ ���
extern uint16_t   usConfigAWRStart;				// ������������ ���
extern uint16_t   usSystemCfgStart;				// ��������� �������
extern uint16_t   usConfigTRMeasStart;			// ������������ �������������� ������
extern uint16_t   usConfigTRPWRStart;			// ������������ �������� ������
extern uint16_t   usSWCntStart;					// ������ �����������

#endif
/*************************************************************************
 * MR851
 *************************************************************************/
#if defined (MR851)

extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucSystemCfgBuf[MB_NumbSystemCfg];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucRPNBuf[MB_NumbRPN];

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigUstavkiStart;			// ������ �������
extern uint16_t   usSystemCfgStart;				// ��������� �������
extern uint16_t   usRPNStart;
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
extern uint16_t   ucSystemCfgBuf[MB_NumbSystemCfg];
extern uint16_t   ucConfigTRMeasBuf[MB_NumbConfigTRMeas];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucOtherUstavkiInBuf[MB_NumbOtherUstavki];

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigUstavkiStart;			// ������ �������
extern uint16_t   usConfigOtherUstavkiStart;	// ����� �������
extern uint16_t   usConfigAutomatStart;			// ��������� ����������
extern uint16_t   usConfigVLSInStart;			// ������ ������������ ������� ���������� ��������
extern uint16_t   usConfigVLSOutStart;			// ������ ������������ �������� ���������� ��������
extern uint16_t   usSystemCfgStart;				// ��������� �������
extern uint16_t   usConfigTRMeasStart;			// ������������ �������������� ������

#endif

//-------------------------------------------------------------------
extern	volatile uint8_t		ReadNmb;					// ������� ����� ����� ��� ������ �� ������
extern	uint16_t	NumbBlokReadMB;				// ������� ����� ����� ��� ������ �� ������

extern osMutexId 	xIEC850StartMutex;		// ������� ���������� � ������� TCP/IP
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
 * MR771 MR761 MR762 MR763
 ***********************************************************************************/
#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763)
eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
	extern uint64_t nextSynchTime;
	extern bool resynch;

    UCHAR          *ucMBFrame;
    uint16_t          usRegAddress;
    uint16_t          usRegCount;
    uint16_t		StartMemForSave;
    uint16_t		MemForSave;

    extern osMutexId 	xIEC850StartMutex;		// ������� ���������� � ������� TCP/IP
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
		vMBMasterGetPDUSndBuf(&ucMBFrame);											// ���� �� ����������� ������ ����� � ������ ����� ��������� ���� �������� � �������� ������
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

        //  �������� ���� ���������� ��������� �������� ��������������.
        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
        {
        	MemForSave = usRegAddress-1;// & 0xFF00;

//----------------------------------------------------------------
//- �������� � ����� ������� ������ ������ -----------------------
//----------------------------------------------------------------

// �������
        	if (usMRevStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, usMRevStart, MB_NumbWordRev );		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. ������: '%s'\n",ReadNmb,(char *)ucMRevBuf);
                	int8_t	Rev = Hal_Verify_Rev((uint8_t*)&ucMRevBuf[0]);
                	if (Rev == 0){
                		osMutexRelease(xIEC850StartMutex);			// �������� ���� ������ ��� ����, ��� �� ��� ������
                	}
                }else {
            		USART_TRACE_RED("������ ��������� ������ �� MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
                ReadNmb++;
        	}
// ��������
        	else if (usMDiscInStart== MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, usMDiscInStart, MB_NumbDiscreet );		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("�� ����������.\n");
                }
                ReadNmb++;
        	}
// �������
        	else if ( usMAnalogInStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, usMAnalogInStart, MB_NumbAnalog);		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("�� ��������.\n");
                }
                ReadNmb++;
        	}
//  ������������ �������
        	else if ( usSystemCfgStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucSystemCfgBuf, usSystemCfgStart, MB_NumbSystemCfg);
                if( eRegStatus == MB_ENOERR ){	// ������ IP �����
                	USART_TRACE_GREEN("%d. �������� ������ �������.\n",ReadNmb);

                	int8_t	resSetIP = Hal_setIPFromMB_Date((uint16_t*)&ucSystemCfgBuf[MB_offset_IP]);
                	if (resSetIP == 0){
                					// ���� �� ���� �� ����� �������� � ���������� �������� IP
                					USART_TRACE_GREEN("%d.�������� �� MODBUS IP:%d.%d.%d.%d \n",ReadNmb, IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					// ������������ ����
                					if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
                						ReStartIEC850_task();
                 					}

                					osMutexRelease(xIEC850StartMutex);
                	} else
                	if (resSetIP == -1){
                		USART_TRACE_RED("������ ��������� IP �� MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	} else
                	if (resSetIP == 2){	// ���������� � ������� ����������
                		USART_TRACE_GREEN("IP �� MODBUS ��������� � ����������.\n");
    					osMutexRelease(xIEC850StartMutex);

                	}
                }
                ReadNmb++;
        	}
// ������ �������� �������
        	else if ( usMDateStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, usMDateStart, MB_NumbDate);				// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	nextSynchTime = Hal_getTimeInMs() + msInDay;				// ��������� ����������������� �����
                	USART_TRACE_GREEN("%d. �������� �����:0x%X ��������� �������������:0x%X\n",ReadNmb,(unsigned int)Hal_getTimeInMs(),(unsigned int)nextSynchTime);
                	resynch = true;
                }
                ReadNmb++;
        	}
// ������ ������������ �����������
        	else if ( usMConfigStartSW == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBufSW, usMConfigStartSW, MB_Size_ConfSW);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. �������� ������ �����������.\n",ReadNmb);
                }
                ReadNmb++;
        	}
// ������ ������� �����������
			else if ( usSWCntStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucSWCNTBuf, usSWCntStart, MB_Size_ConfSW);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ������ �����������.\n",ReadNmb);
				}
				ReadNmb++;
			}

// ������ ������ ������ �������
        	else if ( usSGStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucSGBuf, MemForSave, MB_NumbSG);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ����� ������ �������. (%d)\n",ReadNmb,ucSGBuf[0]+1);
				}
				ReadNmb++;
			}
// ������ ������ �������
			else if (( usConfigUstavkiStart <= MemForSave) &&(MemForSave < (usConfigUstavkiStart+MB_NumbUstavki-1))){

				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucMUstavkiInBuf[MemForSave-usConfigUstavkiStart], MemForSave, SizeAnswer);

				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d-%d. �������� ������ �������.(0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
					NumbBlokReadMB++;
				}

			}
// ������ ���������� ����������
			else if (( usConfigAutomatStart <= MemForSave) &&(MemForSave < (usConfigAutomatStart+MB_NumbAutomat-1))){

				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucMAutomatBuf[MemForSave-usConfigAutomatStart], MemForSave, SizeAnswer);

				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d-%d. �������� ��������� ����������.(0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
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
 * MR5_700 || MR5_600 || MR5_500
 ***********************************************************************************/
#if defined (MR5_700) || defined (MR5_600) || defined (MR5_500)
eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
	extern uint64_t nextSynchTime;
	extern bool resynch;

    UCHAR          *ucMBFrame;
    uint16_t          usRegAddress;
    uint16_t          usRegCount;
    uint16_t		StartMemForSave;
    uint16_t		MemForSave;

    extern osMutexId 	xIEC850StartMutex;		// ������� ���������� � ������� TCP/IP
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
		vMBMasterGetPDUSndBuf(&ucMBFrame);											// ���� �� ����������� ������ ����� � ������ ����� ��������� ���� �������� � �������� ������
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

        //  �������� ���� ���������� ��������� �������� ��������������.
        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
        {
        	MemForSave = usRegAddress-1;// & 0xFF00;

//----------------------------------------------------------------
//- �������� � ����� ������� ������ ������ -----------------------
//----------------------------------------------------------------

// �������
			if (usMRevStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, usMRevStart, MB_NumbWordRev );		// ��������� ������ � ���������
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. ������: '%s'\n",ReadNmb,(char *)ucMRevBuf);
					int8_t	Rev = Hal_Verify_Rev((uint8_t*)&ucMRevBuf[0]);
					if (Rev == 0){
						osMutexRelease(xIEC850StartMutex);			// �������� ���� ������ ��� ����, ��� �� ��� ������
					}
				}else {
					USART_TRACE_RED("������ ��������� ������ �� MODBUS\n");
					eStatus = MB_EX_ILLEGAL_DATA_VALUE;
				}
				ReadNmb++;
			}
// ��������
			else if (usMDiscInStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, usMDiscInStart, MB_NumbDiscreet );		// ��������� ������ � ���������
				if( eRegStatus == MB_ENOERR ){
					//USART_TRACE_GREEN("�� ����������.\n");
				}
				ReadNmb++;
			}
// �������
			else if ( usMAnalogInStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, usMAnalogInStart, MB_NumbAnalog);		// ��������� ������ � ���������
				if( eRegStatus == MB_ENOERR ){
				//	USART_TRACE_GREEN("�� ��������.\n");
				}
				ReadNmb++;
			}
//  ������������ �������
			else if ( usSystemCfgStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucSystemCfgBuf, usSystemCfgStart, MB_NumbSystemCfg);
				if( eRegStatus == MB_ENOERR ){	// ������ IP �����
					USART_TRACE_GREEN("%d. �������� ������ �������.\n",ReadNmb);

					int8_t	resSetIP = Hal_setIPFromMB_Date((uint16_t*)&ucSystemCfgBuf[MB_offset_IP]);
					if (resSetIP == 0){
									// ���� �� ���� �� ����� �������� � ���������� �������� IP
									USART_TRACE_GREEN("%d.�������� �� MODBUS IP:%d.%d.%d.%d \n",ReadNmb, IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
									// ������������ ����
									if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
										ReStartIEC850_task();
									}

									osMutexRelease(xIEC850StartMutex);
					} else
					if (resSetIP == -1){
						USART_TRACE_RED("������ ��������� IP �� MODBUS\n");
						eStatus = MB_EX_ILLEGAL_DATA_VALUE;
					} else
					if (resSetIP == 2){	// ���������� � ������� ����������
						USART_TRACE_GREEN("IP �� MODBUS ��������� � ����������.\n");
						osMutexRelease(xIEC850StartMutex);

					}
				}
				ReadNmb++;
			}
// ������ �������� �������
			else if ( usMDateStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, usMDateStart, MB_NumbDate);				// ��������� ������ � ���������
				if( eRegStatus == MB_ENOERR ){
					Hal_setTimeFromMB_Date(ucMDateBuf);
					nextSynchTime = Hal_getTimeInMs() + msInDay;				// ��������� ����������������� �����
					USART_TRACE_GREEN("%d. �������� �����:0x%X ��������� �������������:0x%X\n",ReadNmb,(unsigned int)Hal_getTimeInMs(),(unsigned int)nextSynchTime);
					resynch = true;
				}
				ReadNmb++;
			}
// ������ �������
			else if (usConfigUstavkiStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucUstavkiInBuf, usConfigUstavkiStart, MB_NumbUstavki);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� �������.\n",ReadNmb);
				}
				ReadNmb++;
			}
#if !defined (MR5_600)
// ������ ������� �����������
			else if ( usConfigStartSWCrash  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucSWCrash, usConfigStartSWCrash, MB_NumbSWCrash);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ������ �����������.\n",ReadNmb);
				}
				ReadNmb++;
			}
// ������ ������������ �����������
			else if ( usConfigStartSW  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucConfigBufSW, usConfigStartSW, MB_NumbConfigSW);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ������������ �����������.\n",ReadNmb);
				}
				ReadNmb++;
			}
#endif
// ������ ������������ �������� ��������
			else if ( usConfigOutStart  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucOutSignalBuf, usConfigOutStart, MB_NumbConfigOut);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ������������ �������� ��������.\n",ReadNmb);
				}
				ReadNmb++;
			}
#if !defined (MR5_600)
// ������ ������������ ����������
			else if ( usConfigAutomatStart  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucAutomatBuf, usConfigAutomatStart, MB_NumbAutomat);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ������������ ����������.\n",ReadNmb);
				}
				ReadNmb++;
			}
#endif
// ������ ������������ ������� �����
			else if ( usConfigStartExZ  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucConfigBufExZ, usConfigStartExZ, MB_NumbConfigExZ);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ������������ ������� �����.\n",ReadNmb);
				}
				ReadNmb++;
			}
#if !defined (MR5_600)
// ������ ������������ ������� �����
			else if ( usConfigStartMTZ  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucConfigBufMTZ, usConfigStartMTZ, MB_NumbConfigMTZ);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ������������ ������� �����.\n",ReadNmb);
				}
				ReadNmb++;
			}
// ������ ������������ �������������� �����
			else if ( usConfigStartI2I1I0  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucConfigBufI2I1I0, usConfigStartI2I1I0, MB_NumbConfigI2I1I0);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ������������ �������������� �����.\n",ReadNmb);
				}
				ReadNmb++;
			}
#endif
#if !defined (MR5_500)
// ������ ������������ ������ �� �������
			else if ( usConfigStartF  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucConfigBufF, usConfigStartF, MB_NumbConfigF);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ������������ ������ �� �������.\n",ReadNmb);
				}
				ReadNmb++;
			}
#if !defined (MR5_600)
// ������ ������������ ������ �� ����������
			else if ( usConfigStartU  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucConfigBufU, usConfigStartU, MB_NumbConfigU);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ������������ ������ �� ����������.\n",ReadNmb);
				}
				ReadNmb++;
			}
#endif
#if defined (MR5_600)
// ������ ������������ ������ �� ����������
			else if (( usConfigStartU <= MemForSave) &&(MemForSave < (usConfigStartU+MB_NumbConfigU-1))){

				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
	            eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucConfigBufU[MemForSave-usConfigStartU], MemForSave, SizeAnswer);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d-%d. �������� ������������ ������ �� ����������.(0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
                	NumbBlokReadMB++;
                }
			}
#endif

#endif
/*
			else if ( usConfigStartU  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucConfigBufU, usConfigStartU, MB_NumbConfigU);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ������������ ������ �� ����������.\n",ReadNmb);
				}
				ReadNmb++;
			}
*/
// ������ ������ � ������� �������
			else if ( usSysNoteStart  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucSysNoteBuf, usSysNoteStart, MB_NumbSysNote);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ������ ������� �������. ���:%u\n",ReadNmb,ucSysNoteBuf[0]);
				}

				//������� � ���� ��������� �������, ���� ��� ����� ����������� � �������� ������ ������ GlobalAddrSysNote++;
                if (/*(memcmp(ucSysNoteBuf, ucSysNoteBufPre,MB_NumbSysNote*2) == 0) || */(ucSysNoteBuf[0] == 0)|| (GlobalAddrSysNote >= MB_SizeSysNote-1) ){
                	// ����� ���� ������, ����� ������ �������
                	if (getJurnals)	ReadNmb++;
                	else 			ReadNmb = MB_Rd_AllUstavki;
                	usSysNoteStart = MB_StartSysNoteaddr;
                	GlobalAddrSysNote = 0;		// ����� ����� �������
                	memcpy(ucSysNoteBufPre, ucSysNoteBufNext,MB_NumbSysNote*2);
                }
                else{

                    if (GlobalAddrSysNote == 0) 	memcpy(ucSysNoteBufNext, ucSysNoteBuf,MB_NumbSysNote*2);			// �������� ��������� ������ ��� ���������� ���������

                    AddToFileMessageWord(_SystemNote,(uint8_t*)ucSysNoteBuf,MB_NumbSysNote*2,FA_OPEN_APPEND | FA_WRITE);
                	// ����������� � �������� ������ ������
                	usSysNoteStart += MB_NumbSysNote+MB_NumbSysNoteASCII;
                	GlobalAddrSysNote++;		// ����� ����� �������
                	ReadNmb = MB_Rd_SysNote;	// ����� ������
                	AddToQueueMB(Rd_SysNoteQueue, 	MB_Rd_SysNote		,MB_Slaveaddr);

                }
			}
// ������ ������ � ������� ������
			else if ( usErrorNoteStart  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucErrorNoteBuf, usErrorNoteStart, MB_NumbErrorNote);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ������ ������� ������. ���:%u\n",ReadNmb,ucErrorNoteBuf[0]);
				}
				//������� � ���� ��������� �������, ���� ��� ����� ����������� � �������� ������ ������ GlobalAddrSysNote++;
				if (/*(memcmp(ucErrorNoteBuf, ucErrorNoteBufPre,MB_NumbErrorNoteTime*2) == 0) || */(ucErrorNoteBuf[0] == 0)|| (GlobalAddrErrorNote >= MB_SizeErrorNote-1) ){
					// ����� ���� ������, ����� ������ ������
                	//if (getJurnals)	ReadNmb++;
                	//else 			ReadNmb = MB_Rd_Discreet;;
					ReadNmb = MB_Rd_Discreet;
					getJurnals = false;
					usErrorNoteStart = MB_StartErrorNoteaddr;
					GlobalAddrErrorNote = 0;		// ����� ����� �������
					memcpy(ucErrorNoteBufPre, ucErrorNoteBufNext,MB_NumbErrorNoteTime*2);
				} else{
					if (GlobalAddrErrorNote == 0) 	memcpy(ucErrorNoteBufNext, ucErrorNoteBuf,MB_NumbErrorNoteTime*2);			// �������� ��������� ������ ��� ���������� ���������

					AddToFileMessageWord(_ErrorNote,(uint8_t*)ucErrorNoteBuf,MB_NumbErrorNote*2,FA_OPEN_APPEND | FA_WRITE);
					// ����������� � �������� ������ ������
					usErrorNoteStart += MB_NextErrorNote;//MB_NumbErrorNote+MB_NumbErrorNoteASCII;
					GlobalAddrErrorNote++;		// ����� ����� �������
					ReadNmb = MB_Rd_ErrorNote;	// ����� ������
					AddToQueueMB(Rd_ErrorNoteQueue, MB_Rd_ErrorNote		,MB_Slaveaddr);
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
 * MR5_600
 ***********************************************************************************/
#if defined (MR5_600_)
eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
	extern uint64_t nextSynchTime;
	extern bool resynch;

    UCHAR          *ucMBFrame;
    uint16_t          usRegAddress;
    uint16_t          usRegCount;
    uint16_t		StartMemForSave;
    uint16_t		MemForSave;

    extern osMutexId 	xIEC850StartMutex;		// ������� ���������� � ������� TCP/IP
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
		vMBMasterGetPDUSndBuf(&ucMBFrame);											// ���� �� ����������� ������ ����� � ������ ����� ��������� ���� �������� � �������� ������
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

        //  �������� ���� ���������� ��������� �������� ��������������.
        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
        {
        	MemForSave = usRegAddress-1;// & 0xFF00;
        	// �������� � ����� ������� ������ ������
        	switch (MemForSave) {

        	case	MB_StartRevNaddr:					// �������
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, MB_StartRevNaddr, MB_NumbWordRev );		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("������: '%s'\n",(char *)ucMRevBuf);
                }else {
            		USART_TRACE_RED("������ ��������� ������ �� MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
                break;
        	case	MB_StartDiscreetaddr:				// ��������
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, MB_StartDiscreetaddr, MB_NumbDiscreet );		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("�� ����������.\n");
                }
                break;
        	case	MB_StartAnalogINaddr:				// �������
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, MB_StartAnalogINaddr, MB_NumbAnalog);		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("�� ��������.\n");
                }
                break;

       	case	(MB_StartConfig + MB_offset_Ktn):	// �������
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&Ktn, MB_StartConfig + MB_offset_Ktn, 1);			// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("����������� ��: %u\n",Ktn);
                }
                break;

        	case	MB_StartConfigNaddr:		// ������� IP �����
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBuf, MB_StartConfigNaddr, MB_NumbConfig);			// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){	// ������ IP �����
                	if (Hal_setIPFromMB_Date(ucMConfigBuf) == 0){
                					// ���� �� ���� �� ����� �������� � ���������� �������� IP
                					USART_TRACE_BLUE("�������� �� MODBUS IP:%d.%d.%d.%d \n", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					// ������������ ����
                					if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
                						ReStartIEC850_task();
                 					}

                					osMutexRelease(xIEC850StartMutex);
                	} else
                	if (Hal_setIPFromMB_Date(ucMConfigBuf) == -1){
                		USART_TRACE_RED("������ ��������� IP �� MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	}
                }
                break;

        	case	MB_StartDateNaddr:		// ����
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, MB_StartDateNaddr, MB_NumbDate);				// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	USART_TRACE_GREEN("MB: �������� �����:0x%X\n",(unsigned int)Hal_getTimeInMs());
                	nextSynchTime = Hal_getTimeInMs() + msInDay;				// ��������� ����������������� �����
                	USART_TRACE_GREEN("MB: ��������� �������������:0x%X\n",(unsigned int)nextSynchTime);
                	resynch = true;

                }
                break;

        	case	MB_StartConfig:		// �������
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBufall, MB_StartConfig, MB_NumbConfigall);		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("�������� �������.\n");
                } else{
                	USART_TRACE_RED("�� �������� �������.\n");
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
#if defined (MR5_500_)
eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
	extern uint64_t nextSynchTime;
	extern bool resynch;

    UCHAR          *ucMBFrame;
    uint16_t          usRegAddress;
    uint16_t          usRegCount;
    uint16_t		StartMemForSave;
    uint16_t		MemForSave;

    extern osMutexId 	xIEC850StartMutex;		// ������� ���������� � ������� TCP/IP
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
		vMBMasterGetPDUSndBuf(&ucMBFrame);											// ���� �� ����������� ������ ����� � ������ ����� ��������� ���� �������� � �������� ������
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

        //  �������� ���� ���������� ��������� �������� ��������������.
        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
        {
        	MemForSave = usRegAddress-1;// & 0xFF00;
        	// �������� � ����� ������� ������ ������
        	switch (MemForSave) {

        	case	MB_StartRevNaddr:					// �������
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, MB_StartRevNaddr, MB_NumbWordRev );		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("������: '%s'\n",(char *)ucMRevBuf);
                }else {
            		USART_TRACE_RED("������ ��������� ������ �� MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
                break;
        	case	MB_StartDiscreetaddr:				// ��������
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, MB_StartDiscreetaddr, MB_NumbDiscreet );		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("�� ����������.\n");
                }
                break;
        	case	MB_StartAnalogINaddr:				// �������
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, MB_StartAnalogINaddr, MB_NumbAnalog);		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("�� ��������.\n");
                }
                break;

        	case	(MB_StartConfig + MB_offset_Ktt):	// �������
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&Ktt, MB_StartConfig + MB_offset_Ktt, 1);			// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("��������� ��� ��: %u\n",Ktt);
                }
                break;
        	case	(MB_StartConfig + MB_offset_Ktn):	// �������
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&Ktn, MB_StartConfig + MB_offset_Ktn, 1);			// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("����������� ��: %u\n",Ktn);
                }
                break;

        	case	MB_StartConfigNaddr:		// ������� IP �����
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBuf, MB_StartConfigNaddr, MB_NumbConfig);			// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){	// ������ IP �����
                	int8_t	resSetIP = Hal_setIPFromMB_Date(ucMConfigBuf);
                	if (resSetIP == 0){
                					// ���� �� ���� �� ����� �������� � ���������� �������� IP
                					USART_TRACE_BLUE("�������� �� MODBUS IP:%d.%d.%d.%d \n", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					// ������������ ����
                					if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
                						ReStartIEC850_task();
                 					}

                					osMutexRelease(xIEC850StartMutex);
                	} else
                	if (resSetIP == -1){
                		USART_TRACE_RED("������ ��������� IP �� MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	} else
                	if (resSetIP == 2){	// ���������� � ������� ����������
                		USART_TRACE_GREEN("IP �� MODBUS ��������� � ����������.\n");
    					osMutexRelease(xIEC850StartMutex);

                	}
                }
                break;

        	case	MB_StartDateNaddr:		// ����
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, MB_StartDateNaddr, MB_NumbDate);				// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	USART_TRACE_GREEN("�������� �����:0x%X\n",(unsigned int)Hal_getTimeInMs());
                	nextSynchTime = Hal_getTimeInMs() + msInDay;				// ��������� ����������������� �����
                	USART_TRACE_GREEN("��������� �������������:0x%X\n",(unsigned int)nextSynchTime);
                	resynch = true;

                }
                break;

        	case	MB_StartConfig:		// �������
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBufall, MB_StartConfig, MB_NumbConfigall);		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("�������� �������.\n");
                } else{
                	USART_TRACE_RED("�� �������� �������.\n");
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

    extern osMutexId 	xIEC850StartMutex;		// ������� ���������� � ������� TCP/IP
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
		vMBMasterGetPDUSndBuf(&ucMBFrame);											// ���� �� ����������� ������ ����� � ������ ����� ��������� ���� �������� � �������� ������
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

        //  �������� ���� ���������� ��������� �������� ��������������.
        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
        {
        	MemForSave = usRegAddress-1;// & 0xFF00;

//----------------------------------------------------------------
//- �������� � ����� ������� ������ ������ -----------------------
//----------------------------------------------------------------

// �������
        	if (usMRevStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, usMRevStart, MB_NumbWordRev );		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. ������: '%s'\n",ReadNmb,(char *)ucMRevBuf);
                	int8_t	Rev = Hal_Verify_Rev((uint8_t*)&ucMRevBuf[0]);
                	if (Rev == 0){
                		osMutexRelease(xIEC850StartMutex);			// �������� ���� ������ ��� ����, ��� �� ��� ������
                	}
                }else {
            		USART_TRACE_RED("������ ��������� ������ �� MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
                ReadNmb++;
        	}
// ��������
        	else if (usMDiscInStart== MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, usMDiscInStart, MB_NumbDiscreet );		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("�� ����������.\n");
                }
                ReadNmb++;
        	}
// �������
        	else if ( usMAnalogInStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, usMAnalogInStart, MB_NumbAnalog);		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("�� ��������.\n");
                }
                ReadNmb++;
        	}
//  ������������ �������
        	else if ( usSystemCfgStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucSystemCfgBuf, usSystemCfgStart, MB_NumbSystemCfg);
                if( eRegStatus == MB_ENOERR ){	// ������ IP �����
                	int8_t	resSetIP = Hal_setIPFromMB_Date((uint16_t*)&ucSystemCfgBuf[MB_offset_IP]);
                	if (resSetIP == 0){
                					// ���� �� ���� �� ����� �������� � ���������� �������� IP
                					USART_TRACE_GREEN("%d.�������� �� MODBUS IP:%d.%d.%d.%d \n",ReadNmb, IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					// ������������ ����
                					if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
                						ReStartIEC850_task();
                 					}

                					osMutexRelease(xIEC850StartMutex);
                	} else
                	if (resSetIP == -1){
                		USART_TRACE_RED("������ ��������� IP �� MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	} else
                	if (resSetIP == 2){	// ���������� � ������� ����������
                		USART_TRACE_GREEN("IP �� MODBUS ��������� � ����������.\n");
    					osMutexRelease(xIEC850StartMutex);

                	}
                }
                ReadNmb++;
        	}
// ������ �������� �������
        	else if ( usMDateStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, usMDateStart, MB_NumbDate);				// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	nextSynchTime = Hal_getTimeInMs() + msInDay;				// ��������� ����������������� �����
                	USART_TRACE_GREEN("%d. �������� �����:0x%X ��������� �������������:0x%X\n",ReadNmb,(unsigned int)Hal_getTimeInMs(),(unsigned int)nextSynchTime);
                	resynch = true;
                }
                ReadNmb++;
        	}
// ������ ������������ �����������
        	else if ( usMConfigStartSW == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigBufSW, usMConfigStartSW, MB_Size_ConfSW);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. �������� ������ �����������.\n",ReadNmb);
                }
                ReadNmb++;
        	}
// ������ ������� �����������
			else if ( usSWCntStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucSWCNTBuf, usSWCntStart, MB_Size_ConfSW);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. �������� ������ �����������.\n",ReadNmb);
				}
				ReadNmb++;
			}
// ������ ������������ ���
        	else if ( usConfigAPWStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigAPWBuf, usConfigAPWStart, MB_NumbConfigAPW);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. �������� ������ ���.\n",ReadNmb);
                }
                ReadNmb++;
        	}
// ������ ������������ ���+���
        	else if ( usConfigAWRStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigAWRBuf, usConfigAWRStart, MB_NumbConfigAWR);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. �������� ������ ���+���.\n",ReadNmb);
                	uint8_t	i;
                	for(i=0;i<MB_NumbConfigAWR;i++) USART_0TRACE("0x%.4X ",ucConfigAWRBuf[i]);
                	USART_0TRACE("\n");

                }
                ReadNmb++;
    		}
// ������ ���� ������� �������� ������
        	else if ( usConfigTRPWRStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigTRPWRBuf, usConfigTRPWRStart, MB_NumbConfigTRPWR);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. �������� ������� �������� ������.\n",ReadNmb);
                	uint8_t	i;
                	for(i=0;i<MB_NumbConfigTRPWR;i++) USART_0TRACE("0x%.4X ",ucConfigTRPWRBuf[i]);
                	USART_0TRACE("\n");

                }
                ReadNmb++;
			}
// ������ ���� ������� �������������� ������
        	else if ( usConfigTRMeasStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigTRMeasBuf, usConfigTRMeasStart, MB_NumbConfigTRMeas);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. �������� ������ �������������� ������.\n",ReadNmb);
                	uint8_t	i;
                	for(i=0;i<MB_NumbConfigTRMeas;i++) USART_0TRACE("0x%.4X ",ucConfigTRMeasBuf[i]);
                	USART_0TRACE("\n");
                }
                ReadNmb++;
        	}
// ������ ������������ ������� ���������� ��������
        	else if ( usConfigVLSInStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucVLSInBuf, usConfigVLSInStart, MB_NumbConfigVLSIn);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. �������� ������ ������� ���������� ��������.\n",ReadNmb);
                }
                NumbBlokReadMB=0;
                ReadNmb++;

                //ReadNmb++;
                //ReadNmb++;
        	}
// ������ ������������ �������� ���������� ��������
			else if ((MemForSave >= usConfigVLSOutStart) && (MemForSave < (usConfigVLSOutStart+MB_NumbConfigVLSOut-1))){
				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
	            eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucVLSOutBuf[MemForSave-usConfigVLSOutStart], MemForSave, SizeAnswer);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d-%d. �������� ������ �������� ���������� ��������. (0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
                	NumbBlokReadMB++;
                }
                //ReadNmb++;
			}
// ������ �������� ��� ��������� ������ �������
			else if (( usConfigUstavkiStart <= MemForSave) &&(MemForSave < (usConfigUstavkiStart+MB_NumbUstavki-1))){

				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
	            eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucMUstavkiInBuf[MemForSave-usConfigUstavkiStart], MemForSave, SizeAnswer);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d-%d. �������� ������ �������.(0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
                	NumbBlokReadMB++;
                }
                //ReadNmb++;
			}
// ������ ���������� ����������
			else if ( usConfigAutomatStart == MemForSave){

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. �������� ��������� ����������.\n",ReadNmb);
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

    extern osMutexId 	xIEC850StartMutex;		// ������� ���������� � ������� TCP/IP
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
		vMBMasterGetPDUSndBuf(&ucMBFrame);											// ���� �� ����������� ������ ����� � ������ ����� ��������� ���� �������� � �������� ������
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

        //  �������� ���� ���������� ��������� �������� ��������������.
        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
        {
        	MemForSave = usRegAddress-1;// & 0xFF00;

//----------------------------------------------------------------
//- �������� � ����� ������� ������ ������ -----------------------
//----------------------------------------------------------------

// �������
        	if (usMRevStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, usMRevStart, MB_NumbWordRev );		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. ������: '%s'\n",ReadNmb,(char *)ucMRevBuf);
                	int8_t	Rev = Hal_Verify_Rev((uint8_t*)&ucMRevBuf[0]);
                	if (Rev == 0){
                		osMutexRelease(xIEC850StartMutex);			// �������� ���� ������ ��� ����, ��� �� ��� ������
                	}
                }else {
            		USART_TRACE_RED("������ ��������� ������ �� MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
                ReadNmb++;
        	}
// ��������
        	else if (usMDiscInStart== MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, usMDiscInStart, MB_NumbDiscreet );		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("�� ����������.\n");
                }
                ReadNmb++;
        	}
// �������
        	else if ( usMAnalogInStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, usMAnalogInStart, MB_NumbAnalog);		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("�� ��������.\n");
                }
                ReadNmb++;
        	}
//  ������������ �������
        	else if ( usSystemCfgStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucSystemCfgBuf, usSystemCfgStart, MB_NumbSystemCfg);
                if( eRegStatus == MB_ENOERR ){	// ������ IP �����
                	int8_t	resSetIP = Hal_setIPFromMB_Date((uint16_t*)&ucSystemCfgBuf[MB_offset_IP]);
                	if (resSetIP == 0){
                					// ���� �� ���� �� ����� �������� � ���������� �������� IP
                					USART_TRACE_GREEN("%d.�������� �� MODBUS IP:%d.%d.%d.%d \n",ReadNmb, IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					// ������������ ����
                					if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
                						ReStartIEC850_task();
                 					}

                					osMutexRelease(xIEC850StartMutex);
                	} else
                	if (resSetIP == -1){
                		USART_TRACE_RED("������ ��������� IP �� MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	} else
                	if (resSetIP == 2){	// ���������� � ������� ����������
                		USART_TRACE_GREEN("IP �� MODBUS ��������� � ����������.\n");
    					osMutexRelease(xIEC850StartMutex);

                	}
                }
                ReadNmb++;
        	}
// ������ �������� �������
        	else if ( usMDateStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, usMDateStart, MB_NumbDate);				// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	nextSynchTime = Hal_getTimeInMs() + msInDay;				// ��������� ����������������� �����
                	USART_TRACE_GREEN("%d. �������� �����:0x%X ��������� �������������:0x%X\n",ReadNmb,(unsigned int)Hal_getTimeInMs(),(unsigned int)nextSynchTime);
                	resynch = true;
                }
                ReadNmb++;
        	}
// ������ ���� ������� �������������� ������
        	else if ( usConfigTRMeasStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucConfigTRMeasBuf, usConfigTRMeasStart, MB_NumbConfigTRMeas);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. �������� ������ �������������� ������.\n",ReadNmb);
                	uint8_t	i;
                	for(i=0;i<MB_NumbConfigTRMeas;i++) USART_0TRACE("0x%.4X ",ucConfigTRMeasBuf[i]);
                	USART_0TRACE("\n");
                }
                ReadNmb++;
        	}
// ������ ������������ ������� ���������� ��������
        	else if ( usConfigVLSInStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucVLSInBuf, usConfigVLSInStart, MB_NumbConfigVLSIn);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. �������� ������ ������� ���������� ��������.\n",ReadNmb);
                }
                NumbBlokReadMB=0;
                ReadNmb++;

                //ReadNmb++;
                //ReadNmb++;
        	}
// ������ ������������ �������� ���������� ��������
			else if ((MemForSave >= usConfigVLSOutStart) && (MemForSave < (usConfigVLSOutStart+MB_NumbConfigVLSOut-1))){
				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
	            eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucVLSOutBuf[MemForSave-usConfigVLSOutStart], MemForSave, SizeAnswer);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d-%d. �������� ������ �������� ���������� ��������. (0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
                	NumbBlokReadMB++;
                }
                //ReadNmb++;
			}
// ������ �������� ��� ��������� ������ �������
			else if (( usConfigUstavkiStart <= MemForSave) &&(MemForSave < (usConfigUstavkiStart+MB_NumbUstavki-1))){

				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
	            eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucMUstavkiInBuf[MemForSave-usConfigUstavkiStart], MemForSave, SizeAnswer);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d-%d. �������� ������ �������.(0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
                	NumbBlokReadMB++;
                }
			}
// ������ ����� �������
			else if (( usConfigOtherUstavkiStart <= MemForSave) &&(MemForSave < (usConfigOtherUstavkiStart+MB_NumbOtherUstavki-1))){

				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucOtherUstavkiInBuf[MemForSave-usConfigOtherUstavkiStart], MemForSave, SizeAnswer);

				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d-%d. �������� ����� �������.(0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
					NumbBlokReadMB++;
				}
			}

// ������ ���������� ����������
			else if ( usConfigAutomatStart == MemForSave){

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. �������� ��������� ����������.\n",ReadNmb);
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
 * MR851
 *************************************************************************/
#if defined (MR851)
eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
	extern uint64_t nextSynchTime;
	extern bool resynch;

    UCHAR          *ucMBFrame;
    uint16_t          usRegAddress;
    uint16_t          usRegCount;
    uint16_t		StartMemForSave;
    uint16_t		MemForSave;

    extern osMutexId 	xIEC850StartMutex;		// ������� ���������� � ������� TCP/IP
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
		vMBMasterGetPDUSndBuf(&ucMBFrame);											// ���� �� ����������� ������ ����� � ������ ����� ��������� ���� �������� � �������� ������
        usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
        usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
        usRegAddress++;

        usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
        usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

        //  �������� ���� ���������� ��������� �������� ��������������.
        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
        {
        	MemForSave = usRegAddress-1;// & 0xFF00;

//----------------------------------------------------------------
//- �������� � ����� ������� ������ ������ -----------------------
//----------------------------------------------------------------

// �������
        	if (usMRevStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, usMRevStart, MB_NumbWordRev );		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d. ������: '%s'\n",ReadNmb,(char *)ucMRevBuf);
                	int8_t	Rev = Hal_Verify_Rev((uint8_t*)&ucMRevBuf[0]);
                	if (Rev == 0){
                		osMutexRelease(xIEC850StartMutex);			// �������� ���� ������ ��� ����, ��� �� ��� ������
                	}
                }else {
            		USART_TRACE_RED("������ ��������� ������ �� MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
                ReadNmb++;
        	}
// ��������
        	else if (usMDiscInStart== MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, usMDiscInStart, MB_NumbDiscreet );		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("�� ����������.\n");
                }
                ReadNmb++;
        	}
// �������
        	else if ( usMAnalogInStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, usMAnalogInStart, MB_NumbAnalog);		// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("�� ��������.\n");
                }
                ReadNmb++;
        	}
// ������
			else if ( usRPNStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucRPNBuf, usRPNStart, MB_NumbRPN);
				if( eRegStatus == MB_ENOERR ){
				//	USART_TRACE_GREEN("�� �������.\n");
				}
				ReadNmb++;
			}
//  ������������ �������
        	else if ( usSystemCfgStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucSystemCfgBuf, usSystemCfgStart, MB_NumbSystemCfg);
                if( eRegStatus == MB_ENOERR ){	// ������ IP �����
                	int8_t	resSetIP = Hal_setIPFromMB_Date((uint16_t*)&ucSystemCfgBuf[MB_offset_IP]);
                	if (resSetIP == 0){
                					// ���� �� ���� �� ����� �������� � ���������� �������� IP
                					USART_TRACE_GREEN("%d.�������� �� MODBUS IP:%d.%d.%d.%d \n",ReadNmb, IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					// ������������ ����
                					if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
                						ReStartIEC850_task();
                 					}

                					osMutexRelease(xIEC850StartMutex);
                	} else
                	if (resSetIP == -1){
                		USART_TRACE_RED("������ ��������� IP �� MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	} else
                	if (resSetIP == 2){	// ���������� � ������� ����������
                		USART_TRACE_GREEN("IP �� MODBUS ��������� � ����������.\n");
    					osMutexRelease(xIEC850StartMutex);

                	}
                }
                ReadNmb++;
        	}
// ������ �������� �������
        	else if ( usMDateStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, usMDateStart, MB_NumbDate);				// ��������� ������ � ���������
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	nextSynchTime = Hal_getTimeInMs() + msInDay;				// ��������� ����������������� �����
                	USART_TRACE_GREEN("%d. �������� �����:0x%X ��������� �������������:0x%X\n",ReadNmb,(unsigned int)Hal_getTimeInMs(),(unsigned int)nextSynchTime);
                	resynch = true;
                }
                ReadNmb++;
        	}
// ������ �������� ��� ��������� ������ �������
			else if (( usConfigUstavkiStart <= MemForSave) &&(MemForSave < (usConfigUstavkiStart+MB_NumbUstavki-1))){

				uint8_t			SizeAnswer;
				xModbus_Get_SizeAnswer((uint8_t *)&SizeAnswer);
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
	            eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ucMUstavkiInBuf[MemForSave-usConfigUstavkiStart], MemForSave, SizeAnswer);

                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("%d-%d. �������� ������ �������.(0x%X)\n",ReadNmb,NumbBlokReadMB,MemForSave);
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

//--------------------------------
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

