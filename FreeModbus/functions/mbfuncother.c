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
 * File: $Id: mbfuncother.c,v 1.8 2006/12/07 22:10:34 wolti Exp $
 */

/* ----------------------- System includes ----------------------------------*/
#include "stdlib.h"
#include "string.h"

/* ----------------------- Platform includes --------------------------------*/
#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "MBmaster.h"

#include "mb.h"
#include "mbcrc.h"
#include "mbframe.h"
#include "mbproto.h"
#include "mbconfig.h"

#include "libiec61850_platform_includes.h"

/***********************************************************************
 * eMBMasterReq1Fn_new
 * создаём запрос 1,2. с выделением памяти, не забывать освобождать после отработки.
 * owner		- владелец, кто запрашивает.
 * ucSndAddr 	- адрес устройства
 * usRegAddr 	- адрес памяти
 * usNRegs		- число слов в ответе
 ***********************************************************************/
MBMessageTransmit*		eMBMasterReq1Fn_new(MBMessageTransmit* TxMessage, ModbusOwnerType owner, uint8_t ucSndAddr, uint16_t usRegAddr, uint16_t usNRegs)
{
	uint16_t usCRC16;
//	MBMessageTransmit*	TxMessage = malloc(sizeof(MBMessageTransmit));
	if (TxMessage == NULL ) return	NULL;

	TxMessage->owner			= 0;
	TxMessage->SizeData			= MB_FUNCREQ_READ_COILS_SIZE;

	TxMessage->AddrDataReq		= usRegAddr;
	TxMessage->SizeDataReq		= usNRegs;

	TxMessage->ucData 			= GLOBAL_MALLOC(TxMessage->SizeData);				// не забудь освободить после получения ответа
	if (TxMessage->ucData == NULL ) {
//		free(TxMessage);
		return	NULL;
	}
	TxMessage->owner			= owner;

	TxMessage->ucData[0]		= ucSndAddr;
	TxMessage->ucData[1]		= MB_FUNC_READ_COILS;
	// адрес
	TxMessage->ucData[2]		= (uint8_t)(usRegAddr>>8);
	TxMessage->ucData[3]		= (uint8_t)(usRegAddr);
	// число слов
	TxMessage->ucData[4]		= (uint8_t)(usNRegs>>8);
	TxMessage->ucData[5]		= (uint8_t)(usNRegs);
    // считаем CRC16
    usCRC16 				= usMBCRC16( (UCHAR *) TxMessage->ucData, TxMessage->SizeData-2 );
	TxMessage->ucData[6]		= (uint8_t)(usCRC16 & 0xFF);
	TxMessage->ucData[7]		= (uint8_t)(usCRC16 >> 8);

return	TxMessage;
}

MBMessageTransmit*		eMBMasterReq2Fn_new(MBMessageTransmit* TxMessage, ModbusOwnerType owner, uint8_t ucSndAddr, uint16_t usRegAddr, uint16_t usNRegs)
{
	uint16_t usCRC16;
//	MBMessageTransmit*	TxMessage = malloc(sizeof(MBMessageTransmit));
	if (TxMessage == NULL ) return	NULL;

	TxMessage->owner			= 0;
	TxMessage->SizeData			= MB_FUNCREQ_READ_DISCRETE_INPUTS_SIZE;

	TxMessage->AddrDataReq		= usRegAddr;
	TxMessage->SizeDataReq		= usNRegs;

	TxMessage->ucData 			= GLOBAL_MALLOC(TxMessage->SizeData);				// не забудь освободить после получения ответа
	if (TxMessage->ucData == NULL ) {
//		free(TxMessage);
		return	NULL;
	}
	TxMessage->owner			= owner;

	TxMessage->ucData[0]		= ucSndAddr;
	TxMessage->ucData[1]		= MB_FUNC_READ_DISCRETE_INPUTS;
	// адрес
	TxMessage->ucData[2]		= (uint8_t)(usRegAddr>>8);
	TxMessage->ucData[3]		= (uint8_t)(usRegAddr);
	// число слов
	TxMessage->ucData[4]		= (uint8_t)(usNRegs>>8);
	TxMessage->ucData[5]		= (uint8_t)(usNRegs);
    // считаем CRC16
    usCRC16 					= usMBCRC16( (UCHAR *) TxMessage->ucData, TxMessage->SizeData-2 );
	TxMessage->ucData[6]		= (uint8_t)(usCRC16 & 0xFF);
	TxMessage->ucData[7]		= (uint8_t)(usCRC16 >> 8);

return	TxMessage;
}
/***********************************************************************
 * eMBMasterReq3Fn_new
 * создаём запрос 3,4. с выделением памяти, не забывать освобождать после отработки.
 * owner		- владелец, кто запрашивает.
 * ucSndAddr 	- адрес устройства
 * usRegAddr 	- адрес памяти
 * usNRegs		- число слов в ответе
 ***********************************************************************/
MBMessageTransmit*		eMBMasterReq3Fn_new(MBMessageTransmit* TxMessage, ModbusOwnerType owner, uint8_t ucSndAddr, uint16_t usRegAddr, uint16_t usNRegs)
{
	uint16_t usCRC16;
//	MBMessageTransmit*	TxMessage = malloc(sizeof(MBMessageTransmit));
	if (TxMessage == NULL ) return	NULL;

	TxMessage->owner			= 0;

	TxMessage->SizeData			= MB_FUNCREQ_READ_HOLDING_REGISTER_SIZE;

	TxMessage->AddrDataReq		= usRegAddr;
	TxMessage->SizeDataReq		= usNRegs;

	TxMessage->ucData 			= GLOBAL_MALLOC(TxMessage->SizeData);				// не забудь освободить после получения ответа
	if (TxMessage->ucData == NULL ) {
//		free(TxMessage);
		return	NULL;
	}
	TxMessage->owner			= owner;


	TxMessage->ucData[0]		= ucSndAddr;
	TxMessage->ucData[1]		= MB_FUNC_READ_HOLDING_REGISTER;
	// адрес
	TxMessage->ucData[2]		= (uint8_t)(usRegAddr>>8);
	TxMessage->ucData[3]		= (uint8_t)(usRegAddr);
	// число слов
	TxMessage->ucData[4]		= (uint8_t)(usNRegs>>8);
	TxMessage->ucData[5]		= (uint8_t)(usNRegs);
    // считаем CRC16
    usCRC16 					= usMBCRC16( (UCHAR *) TxMessage->ucData, TxMessage->SizeData-2 );
	TxMessage->ucData[6]		= (uint8_t)(usCRC16 & 0xFF);
	TxMessage->ucData[7]		= (uint8_t)(usCRC16 >> 8);

return	TxMessage;
}

MBMessageTransmit*		eMBMasterReq4Fn_new(MBMessageTransmit* TxMessage, ModbusOwnerType owner, uint8_t ucSndAddr, uint16_t usRegAddr, uint16_t usNRegs)
{
	uint16_t usCRC16;
//	MBMessageTransmit*	TxMessage = malloc(sizeof(MBMessageTransmit));
	if (TxMessage == NULL ) return	NULL;

	TxMessage->owner			= 0;
	TxMessage->SizeData			= MB_FUNCREQ_READ_INPUT_REGISTER_SIZE;

	TxMessage->AddrDataReq		= usRegAddr;
	TxMessage->SizeDataReq		= usNRegs;

	TxMessage->ucData 			= GLOBAL_MALLOC(TxMessage->SizeData);				// не забудь освободить после получения ответа
	if (TxMessage->ucData == NULL ) {
//		free(TxMessage);
		return	NULL;
	}
	TxMessage->owner			= owner;

	TxMessage->ucData[0]		= ucSndAddr;
	TxMessage->ucData[1]		= MB_FUNC_READ_INPUT_REGISTER;
	// адрес
	TxMessage->ucData[2]		= (uint8_t)(usRegAddr>>8);
	TxMessage->ucData[3]		= (uint8_t)(usRegAddr);
	// число слов
	TxMessage->ucData[4]		= (uint8_t)(usNRegs>>8);
	TxMessage->ucData[5]		= (uint8_t)(usNRegs);
    // считаем CRC16
    usCRC16 					= usMBCRC16( (UCHAR *) TxMessage->ucData, TxMessage->SizeData-2 );
	TxMessage->ucData[6]		= (uint8_t)(usCRC16 & 0xFF);
	TxMessage->ucData[7]		= (uint8_t)(usCRC16 >> 8);

return	TxMessage;
}
/***********************************************************************
 * eMBMasterReq5Fn_new
 * создаём запрос 5. с выделением памяти, не забывать освобождать после отработки.
 * owner		- владелец, кто запрашивает.
 * ucSndAddr 	- адрес устройства
 * usRegAddr 	- адрес памяти
 * usNRegs		- число слов в ответе
 ***********************************************************************/
MBMessageTransmit*		eMBMasterReq5Fn_new(MBMessageTransmit* TxMessage, ModbusOwnerType owner, uint8_t ucSndAddr, uint16_t usRegAddr, bool usReg)
{
	uint16_t usCRC16;
	uint8_t Reg = 0;

//	MBMessageTransmit*	TxMessage = malloc(sizeof(MBMessageTransmit));
	if (TxMessage == NULL ) return	NULL;

	if (usReg) Reg = 0xFF;

	TxMessage->owner			= 0;
	TxMessage->SizeData			= MB_FUNCREQ_WRITE_SINGLE_COIL_SIZE;

	TxMessage->AddrDataReq		= usRegAddr;
	TxMessage->SizeDataReq		= 1;

	TxMessage->ucData 			= GLOBAL_MALLOC(TxMessage->SizeData);				// не забудь освободить после получения ответа
	if (TxMessage->ucData == NULL ) {
//		free(TxMessage);
		return	NULL;
	}
	TxMessage->owner			= owner;

	TxMessage->ucData[0]		= ucSndAddr;
	TxMessage->ucData[1]		= MB_FUNC_WRITE_SINGLE_COIL;
	// адрес
	TxMessage->ucData[2]		= (uint8_t)(usRegAddr>>8);
	TxMessage->ucData[3]		= (uint8_t)(usRegAddr);
	// число слов
	TxMessage->ucData[4]		= (uint8_t)(Reg);
	TxMessage->ucData[5]		= (uint8_t)(0);
    // считаем CRC16
    usCRC16 					= usMBCRC16( (UCHAR *) TxMessage->ucData, TxMessage->SizeData-2 );
	TxMessage->ucData[6]		= (uint8_t)(usCRC16 & 0xFF);
	TxMessage->ucData[7]		= (uint8_t)(usCRC16 >> 8);

return	TxMessage;
}
/***********************************************************************
 * eMBMasterReq6Fn_new
 * создаём запрос 6. с выделением памяти, не забывать освобождать после отработки.
 * owner		- владелец, кто запрашивает.
 * ucSndAddr 	- адрес устройства
 * usRegAddr 	- адрес памяти
 * usNRegs		- число слов в ответе
 ***********************************************************************/
MBMessageTransmit*		eMBMasterReq6Fn_new(MBMessageTransmit* TxMessage, ModbusOwnerType owner, uint8_t ucSndAddr, uint16_t usRegAddr, uint16_t usReg)
{
	uint16_t usCRC16;

//	MBMessageTransmit*	TxMessage = malloc(sizeof(MBMessageTransmit));
	if (TxMessage == NULL ) return	NULL;

	TxMessage->owner			= 0;
	TxMessage->SizeData			= MB_FUNCREQ_WRITE_REGISTER_SIZE;

	TxMessage->AddrDataReq		= usRegAddr;
	TxMessage->SizeDataReq		= usReg;

	TxMessage->ucData 			= GLOBAL_MALLOC(TxMessage->SizeData);				// не забудь освободить после получения ответа
	if (TxMessage->ucData == NULL ) {
//		free(TxMessage);
		return	NULL;
	}
	TxMessage->owner			= owner;

	TxMessage->ucData[0]		= ucSndAddr;
	TxMessage->ucData[1]		= MB_FUNC_WRITE_REGISTER;
	// адрес
	TxMessage->ucData[2]		= (uint8_t)(usRegAddr>>8);
	TxMessage->ucData[3]		= (uint8_t)(usRegAddr);
	// число слов
	TxMessage->ucData[4]		= (uint8_t)(usReg>>8);
	TxMessage->ucData[5]		= (uint8_t)(usReg);
    // считаем CRC16
    usCRC16 					= usMBCRC16( (UCHAR *) TxMessage->ucData, TxMessage->SizeData-2 );
	TxMessage->ucData[6]		= (uint8_t)(usCRC16 & 0xFF);
	TxMessage->ucData[7]		= (uint8_t)(usCRC16 >> 8);

return	TxMessage;
}
/***********************************************************************
 * eMBMasterReq15Fn_new
 * создаём запрос 15. с выделением памяти, не забывать освобождать после отработки.
 * owner		- владелец, кто запрашивает.
 * ucSndAddr 	- адрес устройства
 * usRegAddr 	- адрес памяти
 * usNRegs		- число слов в ответе
 ***********************************************************************/
MBMessageTransmit*		eMBMasterReq15Fn_new(MBMessageTransmit* TxMessage, ModbusOwnerType owner, uint8_t ucSndAddr, uint16_t usAddr, uint16_t usNumb, uint8_t* usReg)
{
	uint16_t 	usCRC16;
	uint8_t		ucByteCount;
	uint16_t	RegIndex = 0;

//	MBMessageTransmit*	TxMessage = malloc(sizeof(MBMessageTransmit));
	if (TxMessage == NULL ) return	NULL;

	TxMessage->owner			= 0;

	ucByteCount 				= (uint8_t)( usNumb/8 );
	if((usNumb & 0x7)!=0)	ucByteCount++;


	TxMessage->SizeData			= MB_FUNCREQ_WRITE_MULTIPLE_COILS_SIZE + ucByteCount;

	TxMessage->AddrDataReq		= usAddr;
	TxMessage->SizeDataReq		= usNumb;

	TxMessage->ucData 			= GLOBAL_MALLOC(TxMessage->SizeData);				// не забудь освободить после получения ответа
	if (TxMessage->ucData == NULL ) {
//		free(TxMessage);
		return	NULL;
	}
	TxMessage->owner			= owner;

	TxMessage->ucData[0]		= ucSndAddr;
	TxMessage->ucData[1]		= MB_FUNC_WRITE_MULTIPLE_COILS;
	// адрес
	TxMessage->ucData[2]		= (uint8_t)(usAddr>>8);
	TxMessage->ucData[3]		= (uint8_t)(usAddr);
	// число слов
	TxMessage->ucData[4]		= (uint8_t)(usNumb>>8);
	TxMessage->ucData[5]		= (uint8_t)(usNumb);

	TxMessage->ucData[6]		= (uint8_t)(ucByteCount);

	for (RegIndex=0;RegIndex<ucByteCount;RegIndex++)
		TxMessage->ucData[7+RegIndex] = usReg[RegIndex];
	//	memcpy(&TxMessage->ucData[7],usReg,ucByteCount);

    // считаем CRC16
    usCRC16 				= usMBCRC16( (UCHAR *) TxMessage->ucData, TxMessage->SizeData-2 );
	TxMessage->ucData[TxMessage->SizeData-1]		= (uint8_t)(usCRC16 & 0xFF);
	TxMessage->ucData[TxMessage->SizeData]		= (uint8_t)(usCRC16 >> 8);

return	TxMessage;
}
/***********************************************************************
 * eMBMasterReq15Fn_new
 * создаём запрос 16. с выделением памяти, не забывать освобождать после отработки.
 * owner		- владелец, кто запрашивает.
 * ucSndAddr 	- адрес устройства
 * usRegAddr 	- адрес памяти
 * usNRegs		- число слов в ответе
 * 1-123 регистра (246байт данных)
 ***********************************************************************/
MBMessageTransmit*		eMBMasterReq16Fn_new(MBMessageTransmit* TxMessage, ModbusOwnerType owner, uint8_t ucSndAddr, uint16_t usAddr, uint16_t usNumb, uint8_t* usReg)
{
	uint16_t 	usCRC16;
	uint8_t		ucByteCount;
	uint16_t	RegIndex = 0;

//	MBMessageTransmit*	TxMessage = malloc(sizeof(MBMessageTransmit));
	if (TxMessage == NULL ) return	NULL;

	TxMessage->owner			= 0;

	ucByteCount 				= (uint8_t)(usNumb*2);

	TxMessage->SizeData			= MB_FUNCREQ_WRITE_MULTIPLE_REGISTERS_SIZE + ucByteCount;

	TxMessage->AddrDataReq		= usAddr;
	TxMessage->SizeDataReq		= usNumb;

	TxMessage->ucData 			= GLOBAL_MALLOC(TxMessage->SizeData);				// не забудь освободить после получения ответа
	if (TxMessage->ucData == NULL ) {
//		free(TxMessage);
		return	NULL;
	}
	TxMessage->owner			= owner;

	TxMessage->ucData[0]		= ucSndAddr;
	TxMessage->ucData[1]		= MB_FUNC_WRITE_MULTIPLE_REGISTERS;
	// адрес
	TxMessage->ucData[2]		= (uint8_t)(usAddr>>8);
	TxMessage->ucData[3]		= (uint8_t)(usAddr);
	// число слов
	TxMessage->ucData[4]		= (uint8_t)(usNumb>>8);
	TxMessage->ucData[5]		= (uint8_t)(usNumb);

	TxMessage->ucData[6]		= (uint8_t)(ucByteCount);

	for (RegIndex=0;RegIndex<ucByteCount;RegIndex++)
		TxMessage->ucData[7+RegIndex] = usReg[RegIndex];
	//	memcpy(&TxMessage->ucData[7],usReg,ucByteCount);

    // считаем CRC16
    usCRC16 				= usMBCRC16( (UCHAR *) TxMessage->ucData, TxMessage->SizeData-2 );
	TxMessage->ucData[TxMessage->SizeData-1]	= (uint8_t)(usCRC16 & 0xFF);
	TxMessage->ucData[TxMessage->SizeData]		= (uint8_t)(usCRC16 >> 8);

return	TxMessage;
}
/***********************************************************************
 * eMBMasterReq19Fn_new
 * создаём запрос 19. с выделением памяти, не забывать освобождать после отработки.
 * owner		- владелец, кто запрашивает.
 * ucSndAddr 	- адрес устройства
 * usRegAddr 	- адрес памяти
 * usNRegs		- число слов в ответе
 ***********************************************************************/
MBMessageTransmit*		eMBMasterReq19Fn_new(MBMessageTransmit* TxMessage, ModbusOwnerType owner, uint8_t ucSndAddr, uint16_t usRegAddr, uint16_t usNRegs)
{
	uint16_t usCRC16;
//	MBMessageTransmit*	TxMessage = malloc(sizeof(MBMessageTransmit));
	if (TxMessage == NULL ) return	NULL;

	TxMessage->owner			= 0;
	TxMessage->SizeData			= MB_FUNCREQ_READ_HOLDING_REGISTER_W_ADDR_SIZE;

	TxMessage->AddrDataReq		= usRegAddr;
	TxMessage->SizeDataReq		= usNRegs;

	TxMessage->ucData 			= GLOBAL_MALLOC(TxMessage->SizeData);				// не забудь освободить после получения ответа
	if (TxMessage->ucData == NULL ) {
//		free(TxMessage);
		return	NULL;
	}
	TxMessage->owner			= owner;

	TxMessage->ucData[0]		= ucSndAddr;
	TxMessage->ucData[1]		= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;
	// адрес
	TxMessage->ucData[2]		= (uint8_t)(usRegAddr>>8);
	TxMessage->ucData[3]		= (uint8_t)(usRegAddr);
	// число слов
	TxMessage->ucData[4]		= (uint8_t)(usNRegs>>8);
	TxMessage->ucData[5]		= (uint8_t)(usNRegs);
    // считаем CRC16
    usCRC16 				= usMBCRC16( (UCHAR *) TxMessage->ucData, TxMessage->SizeData-2 );
	TxMessage->ucData[6]		= (uint8_t)(usCRC16 & 0xFF);
	TxMessage->ucData[7]		= (uint8_t)(usCRC16 >> 8);

return	TxMessage;
}
/***********************************************************************
 * удаляем из памяти
 ***********************************************************************/
void	eMBMasterTxMessage_del(MBMessageTransmit* TxMessage)
{
	if (TxMessage != NULL){
		GLOBAL_FREEMEM(TxMessage);
		TxMessage = NULL;
	}
}
/***********************************************************************
 * удаляем из памяти только данные
 ***********************************************************************/
void	eMBMasterTxMessageData_del(MBMessageTransmit* TxMessage)
{
	if (TxMessage != NULL){
		if (TxMessage->ucData != NULL){
			GLOBAL_FREEMEM(TxMessage->ucData);
			TxMessage->ucData = NULL;
		}
	}

}
#if MB_FUNC_OTHER_REP_SLAVEID_ENABLED > 0

/* ----------------------- Static variables ---------------------------------*/
static UCHAR    ucMBSlaveID[MB_FUNC_OTHER_REP_SLAVEID_BUF];
static USHORT   usMBSlaveIDLen;

/* ----------------------- Start implementation -----------------------------*/

eMBErrorCode
eMBSetSlaveID( UCHAR ucSlaveID, BOOL xIsRunning,
               UCHAR const *pucAdditional, USHORT usAdditionalLen )
{
    eMBErrorCode    eStatus = MB_ENOERR;

    /* the first byte and second byte in the buffer is reserved for
     * the parameter ucSlaveID and the running flag. The rest of
     * the buffer is available for additional data. */
    if( usAdditionalLen + 2 < MB_FUNC_OTHER_REP_SLAVEID_BUF )
    {
        usMBSlaveIDLen = 0;
        ucMBSlaveID[usMBSlaveIDLen++] = ucSlaveID;
        ucMBSlaveID[usMBSlaveIDLen++] = ( UCHAR )( xIsRunning ? 0xFF : 0x00 );
        if( usAdditionalLen > 0 )
        {
            memcpy( &ucMBSlaveID[usMBSlaveIDLen], pucAdditional,
                    ( size_t )usAdditionalLen );
            usMBSlaveIDLen += usAdditionalLen;
        }
    }
    else
    {
        eStatus = MB_ENORES;
    }
    return eStatus;
}

eMBException
eMBFuncReportSlaveID( UCHAR * pucFrame, USHORT * usLen )
{
    memcpy( &pucFrame[MB_PDU_DATA_OFF], &ucMBSlaveID[0], ( size_t )usMBSlaveIDLen );
    *usLen = ( USHORT )( MB_PDU_DATA_OFF + usMBSlaveIDLen );
    return MB_EX_NONE;
}

#endif
