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

#if defined (MR771)
//Master mode: База данных конфигурации системы
extern uint16_t   usMConfigSystem;
extern uint16_t   ucMConfigSystemBuf[MB_Size_ConfSysytem];

//Master mode: База данных конфигурации Выключателя
extern uint16_t   usMConfigSW;
extern uint16_t   ucMConfigSWBuf[MB_Size_ConfSW];

//Master mode: База данных Версии
extern uint16_t   usMRevStart;
extern uint16_t   ucMRevBuf[MB_NumbWordRev];

//Master mode: База данных часов
extern	uint16_t   usMDateStart;
extern	uint16_t   ucMDateBuf[MB_NumbDate];

//Master mode: База данных дискретных сигналов
extern	uint16_t   usMDiscInStart;
extern	uint16_t   ucMDiscInBuf[MB_NumbDiscreet];

//Master mode: База данных аналоговых сигналов
extern	uint16_t   usMAnalogInStart;
extern	uint16_t   ucMAnalogInBuf[MB_NumbAnalog];

//Master mode: База уставок
extern uint16_t   usMConfigStartTrans;
extern uint16_t    ucMConfigBufTrans[MB_Size_ConfTrans];

//Master mode: Настройки сети
extern uint16_t   usMConfigStartNaddr;
extern uint16_t   ucMConfigNaddrBuf[MB_NumbConfigNaddr];

extern uint16_t		Ktt,Ktn;
extern uint16_t		ConfigOffset;			// смещение группы уставок
#elif defined (MR5_700)

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

extern osMutexId 	xIEC850StartMutex;		// мьютекс готовности к запуску TCP/IP
extern uint8_t		IP_ADDR[4];
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
 * чтение регистров из MB
 ***********************************************************************************/
#if defined (MR771)
eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
    UCHAR          *ucMBFrame;
    uint16_t          usRegAddress;
    uint16_t          usRegCount;
    uint16_t		StartMemForSave;
    uint16_t		MemForSave;
//    extern osMutexId xIEC850ServerStartMutex;

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

        	if (MemForSave == MB_StartRevNaddr){		// ревизия
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMRevBuf, MB_StartRevNaddr, MB_NumbWordRev );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                    IedServer_lockDataModel(iedServer);
                    IedServer_updateVisibleStringAttributeValue(iedServer, IEDMODEL_GenericIO_LLN0_NamPlt_swRev, (char *)&ucMRevBuf[8]);
                    IedServer_updateVisibleStringAttributeValue(iedServer, IEDMODEL_GenericIO_LLN0_NamPlt_d,(char *)ucMRevBuf);
                    IedServer_updateVisibleStringAttributeValue(iedServer, IEDMODEL_GenericIO_LLN0_NamPlt_configRev,(char *)"1");
                    IedServer_unlockDataModel(iedServer);

                	USART_TRACE_GREEN("Версия: '%s'\n",(char *)ucMRevBuf);
                }else {
            		USART_TRACE_RED("ошибка получения версии из MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
        	}else
        	if (MemForSave == MB_StartDiscreetaddr){	// дискреты
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDiscInBuf, MB_StartDiscreetaddr, MB_NumbDiscreet );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД дискретных.\n");
                }
        	}else
            if (MemForSave == MB_StartAnalogINaddr){	// аналоги
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMAnalogInBuf, MB_StartAnalogINaddr, MB_NumbAnalog);		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД аналогов.\n");
                }
        	}else
            if (MemForSave == MB_NOfConfig){			// смещение активных уставок
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&ConfigOffset,MB_NOfConfig, 1);				// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Группа уставок: %u\n",ConfigOffset+1);
                	usMConfigStartTrans = MB_StartConfig + MB_offset_ConfTrans + (ConfigOffset * MB_IncNumbOfConfig);		// адрес уставок транса
                	USART_TRACE_GREEN("адрес группы: 0x%.4X\n",usMConfigStartTrans);
                }
        	}else
        	if (MemForSave == usMConfigStartTrans){
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,ucMConfigBufTrans,usMConfigStartTrans, MB_Size_ConfTrans);						// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Получили конфигурацию измерительного трансформатора.\n");
                	USART_TRACE("Канал тока:       ");
                	uint8_t i;
                	for(i=0;i<MB_Size_ConfTrans/2;i++){
                		USART_0TRACE("0x%.4X ",ucMConfigBufTrans[i]);
                	}
            		USART_0TRACE("\n");
                	USART_TRACE("Канал напряжения: ");
                	for(i=MB_Size_ConfTrans/2;i<MB_Size_ConfTrans;i++){
                		USART_0TRACE("0x%.4X ",ucMConfigBufTrans[i]);
                	}
            		USART_0TRACE("\n");
            	} else{
            		USART_TRACE_RED("ошибка получения конфигурации измерительного трансформатора.\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
            	}
            }else
        		/*
            if (MemForSave == (MB_StartConfig+ConfigOffset+MB_offset_Ktt)){
        	//case	(MB_StartConfig+ConfigOffset+MB_offset_Ktt):	// уставки
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&Ktt, MB_StartConfig + ConfigOffset + MB_offset_Ktt, 1);		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Первичный ток ТТ: %u адрес: 0x%X\n",Ktt,(MB_StartConfig + ConfigOffset + MB_offset_Ktt));
                }
            //    break;
            }else
            if (MemForSave == (MB_StartConfig+ConfigOffset+MB_offset_Ktn)){
        	//case	(MB_StartConfig+ConfigOffset+MB_offset_Ktn):	// уставки
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount,(USHORT *)&Ktn, MB_StartConfig + ConfigOffset + MB_offset_Ktn, 1);		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Коэффициент ТН: %u адрес: 0x%X\n",Ktn,(MB_StartConfig + ConfigOffset + MB_offset_Ktn));
                }
            //    break;
            }else
            	*/
            if (MemForSave == MB_StartConfigNaddr){		// уставки IP адрес
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigNaddrBuf, MB_StartConfigNaddr, MB_NumbConfigNaddr);			// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){	// меняем IP адрес
                	if (Hal_setIPFromMB_Date(ucMConfigNaddrBuf)){
                					// если всё норм то нужно сообщить о готовности работать IP
                					// USART_TRACE_GREEN("получили IP:%d %d %d %d \n", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					//osMutexRelease(xIEC850StartMutex);
                	} else{
                		USART_TRACE_RED("ошибка получения IP из MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	}
                }
            }else
            if (MemForSave == MB_StartDateNaddr){		// часы
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, MB_StartDateNaddr, MB_NumbDate);
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	USART_TRACE_GREEN("Получили время.\n");
                }
            }else
			if (MemForSave == usMConfigSW){	// конфигурация выключателя
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigSWBuf, usMConfigSW, MB_Size_ConfSW);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Получили конфигурацию выключателя.\n");
                	Hal_setConfSWFromMB_Date(ucMConfigSWBuf);
                }
			}else
			if (MemForSave == usMConfigSystem){	// конфигурация системы
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMConfigSystemBuf, usMConfigSystem, MB_Size_ConfSysytem);
                if( eRegStatus == MB_ENOERR ){
//                	osMutexRelease(xIEC850ServerStartMutex);
                	USART_TRACE_GREEN("Получили конфигурацию системы.\n");
                }
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
#elif defined (MR5_700)
eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
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
                	if (Hal_setIPFromMB_Date(ucMConfigBuf)){
                					// если всё норм то нужно сообщить о готовности работать IP
                					//USART_TRACE_BLUE("получили из MODBUS IP:%d.%d.%d.%d \n", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					//osMutexRelease(xIEC850StartMutex);
                	} else{
                		USART_TRACE_RED("ошибка получения IP из MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	}
                }
                break;

        	case	MB_StartDateNaddr:		// часы
                eRegStatus = eMBMasterToMemDB( &pucFrame[MB_PDU_FUNC_READ_VALUES_OFF], usRegAddress, usRegCount, ucMDateBuf, MB_StartDateNaddr, MB_NumbDate);				// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	Hal_setTimeFromMB_Date(ucMDateBuf);
                	USART_TRACE_GREEN("Получили время.\n");
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

