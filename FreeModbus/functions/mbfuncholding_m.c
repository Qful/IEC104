/* 
 * Modbus ASCII/RTU.
 */

/* ----------------------- System includes ----------------------------------*/
#include "stdlib.h"
#include "string.h"
#include <stdbool.h>
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

/* ----------------------- работа БД -> структура----------------------------*/
#include "dataUpdateFromBase.h"
/* ----------------------- работа с журналом---------------------------------*/
#include "ExtSPImem.h"
#include "jurnals.h"
#include "filesystem.h"

#include "fsdata.h"
/* ----------------------- режим Ethernet ---------------------------------*/
#include "ethernetif.h"
#include "lwip/prphsr.h"
/* ----------------------- external -----------------------------------------*/

extern	xQueueHandle 	Rd_SysNoteQueue;		// очередь для запросов журналу системы
extern	xQueueHandle 	Rd_ErrorNoteQueue;		// очередь для запросов журналу аварий
extern	xQueueHandle 	ModbusSentQueue;		// очередь для отправки в модбас
extern  xQueueHandle 	Rd_OscNoteQueue;		// очередь для запросов журналу осциллографа

//extern  xQueueHandle 	ModbusResponseQueue;	// очередь для ожидания из модбас

extern	xQueueHandle 	FileSystemQueue;		// очередь для файлов

extern uint16_t			GLOBAL_QUALITY;

extern uint64_t 		nextSynchTime;
//extern uint32_t 		nextSynchTime;
extern bool 			resynch;


extern IedServer 		iedServer;
extern osThreadId 		IEC850TaskHandle;

extern uint16_t			GlobalAddrSysNote;
extern uint16_t			GlobalAddrErrorNote;
extern uint16_t			GlobalAddrOscNote;

extern uint32_t   		ucOscMessSize;					// размер осциллограммы
extern uint32_t   		ucOscMessStart;					// адрес осциллограммы
extern uint16_t   		ucCurrOscPage;					// текущая страница
extern uint16_t   		ucCurrOscAddrOnPage;			// текущий адрес на странице
extern uint16_t   		ucCurrOscSizeOnPage;			// размер на странице

extern bool				NextPacketIgnor;

extern RedModeType 		RedMode;

extern UART_HandleTypeDef 	MODBUS;
/*************************************************************************
 * MR771 MR761 MR762 MR763
 *************************************************************************/
#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763) || defined (MR761OBR) ||\
	defined (MR801) ||\
	defined (MR901) || defined (MR902) ||\
	defined (MR851) ||\
	defined (MR5_500) || defined (MR5_600) || defined (MR5_700) ||\
	defined (MR741)


extern uint16_t   ucMDateBuf[];
extern uint16_t   ucMRevBuf[];

extern uint16_t   ucMDiscInBuf[];
#if defined (AN_PERV)
extern float   ucMAnalogInBuf[];
#else
	#if defined (AN_DUBLEDATA)
	extern	uint32_t   ucMAnalogInBuf[];
	#else
	extern	uint16_t   ucMAnalogInBuf[];
	#endif
#endif

extern uint16_t   ucSystemCfgBuf[MB_Size_SystemCfg];

extern uint16_t   ucMUstavkiInBuf[MB_Size_Ustavki];
extern uint16_t   ucOtherUstavkiInBuf[MB_Size_OtherUstavki];

extern uint16_t   ucConfigAPWBuf[MB_Size_ConfigAPW];
extern uint16_t   ucConfigAWRBuf[MB_Size_ConfigAWR];

extern uint16_t   usConfigUROVStart;
extern uint16_t   ucConfigUROVBuf[MB_Size_ConfigUROV];

extern uint16_t   ucConfigTRPWRBuf[MB_Size_ConfigTRPWR];
extern uint16_t   ucConfigTRMeasBuf[MB_NumbConfigTRMeas];

extern uint16_t   ucVLSOutBuf[MB_Size_ConfigVLSOut];
extern uint16_t   ucVLSInBuf[MB_Size_ConfigVLSIn];

extern uint16_t   ucSGBuf[MB_Size_SG];

extern uint16_t   ucMAutomatBuf[MB_Size_Automat];

// MR5
extern uint16_t   ucConfigBufMTZ[MB_NumbConfigMTZ];
extern uint16_t   ucConfigBufExZ[MB_NumbConfigExZ];
extern uint16_t   ucConfigBufF[MB_Size_ConfigF];
extern uint16_t   ucConfigBufU[MB_Size_ConfigU];
extern uint16_t   ucOutSignalBuf[MB_Size_ConfigOut];
extern uint16_t   ucConfigBufI2I1I0[MB_NumbConfigI2I1I0];
// !MR5

extern uint16_t   ucConfigBufSW[MB_Size_ConfigSW];
extern uint16_t   ucSWCrash[MB_Size_SWCrash];

extern uint16_t   ucRPNBuf[MB_Size_RPN];

// журнал системы -----------------------
extern uint16_t   ucSysNoteBuf[MB_Size_SysNote];
extern uint16_t   ucSysNoteBufPre[MB_Size_SysNote];							// последняя запись для поиска
extern uint16_t   ucSysNoteBufNext[MB_Size_SysNote];							// последняя запись
// журнал аварий -----------------------
extern uint16_t   ucErrorNoteBuf[MB_Size_ErrorNote];
extern uint16_t   ucErrorNoteBufPre[MB_Size_ErrorNoteTime];
extern uint16_t   ucErrorNoteBufNext[MB_Size_ErrorNoteTime];
// журнал осциллограмм -----------------------
extern uint16_t   ucOscNoteBuf[MB_Size_OscNote];
extern uint16_t   ucOscNoteBufPre[MB_Size_OscNoteTime];
extern uint16_t   ucOscNoteCurrNumb;										// текущее число осциллограмм
// осциллограмы -----------------------
extern uint16_t   usOscBlockStart;
extern uint16_t   ucOscBlockBuf[MB_SizeOscBlock];

extern uint16_t   usSysNoteStart;
extern uint16_t   usErrorNoteStart;
extern uint16_t   usOscNoteStart;

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigUstavkiStart;			// группа уставок
extern uint16_t   usConfigOtherUstavkiStart;	// группа общих уставок
extern uint16_t   usConfigAutomatStart;			// параметры автоматики
extern uint16_t   usConfigVLSInStart;			// чтение конфигурации входных логических сигналов
extern uint16_t   usConfigVLSOutStart;			// чтение конфигурации выходных логических сигналов
extern uint16_t   usConfigAPWStart;				// конфигурация АПВ
extern uint16_t   usConfigAWRStart;				// конфигурация АВР
extern uint16_t   usConfigTRMeasStart;			// конфигурация измерительного транса
extern uint16_t   usConfigTRPWRStart;			// конфигурация силового транса

// MR5
extern uint16_t   usConfigStartExZ;				// конфигурация внешних защит
extern uint16_t   usConfigStartMTZ;				// конфигурация токовых защит
extern uint16_t   usConfigStartI2I1I0;			// конфигурация Дополнительные защиты
extern uint16_t   usConfigOutStart;				// чтение конфигурации выходных сигналов
extern uint16_t   usConfigStartF;				// конфигурация защиты по частоте
extern uint16_t   usConfigStartU;				// конфигурация защиты по напряжению

// !MR5
extern uint16_t   usSystemCfgStart;				// параметры системы
extern uint16_t   usSGStart;
extern uint16_t   usRPNStart;

extern uint16_t   usConfigStartSW;
extern uint16_t   usConfigStartSWCrash;			// ресурс выключателя

#endif

//-------------------------------------------------------------------
// флаги новой записи в журнале
extern bool		NewSysNoteMessage;
extern bool		NewErrorNoteMessage;

//-------------------------------------------------------------------

extern osMutexId 			xIEC850StartMutex;		// мьютекс готовности к запуску TCP/IP
extern uint8_t				IP_ADDR[4];
extern volatile uint8_t		MAC_ADDR[6];
extern char					NamPlt_swRev[32];

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
	uint16_t				SizeAnswer;

    UCHAR                 *ucMBFrame;
    eMBMasterReqErrCode    eErrStatus = MB_MRE_NO_ERR;

    if 		( ucSndAddr > MB_MASTER_TOTAL_SLAVE_NUM ) 		eErrStatus = MB_MRE_ILL_ARG;
    else if ( xMBMasterRunResTake( lTimeOut ) == FALSE ) 	eErrStatus = MB_MRE_MASTER_BUSY;
    else
    {
      	SizeAnswer = SizeAddr + SizeFunct + 2 + SizeCRC + 2;		// 8 байт ответ
		xModbus_Set_SizeAnswer(SizeAnswer,usRegAddr);

		vMBMasterSetDestAddress(ucSndAddr);
		vMBMasterSetPDUSndLength( MB_PDU_SIZE_MIN + MB_PDU_REQ_WRITE_SIZE );

		vMBMasterGetPDUSndBuf(&ucMBFrame);

		ucMBFrame[MB_PDU_FUNC_OFF]                = MB_FUNC_WRITE_REGISTER;
		ucMBFrame[MB_PDU_REQ_WRITE_ADDR_OFF]      = usRegAddr >> 8;
		ucMBFrame[MB_PDU_REQ_WRITE_ADDR_OFF + 1]  = usRegAddr;
		ucMBFrame[MB_PDU_REQ_WRITE_VALUE_OFF]     = usRegData >> 8;
		ucMBFrame[MB_PDU_REQ_WRITE_VALUE_OFF + 1] = usRegData ;


		( void ) xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );
//		eErrStatus = eMBMasterWaitRequestFinish( );
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
	uint16_t				SizeAnswer;

    UCHAR                 *ucMBFrame;
    USHORT                 usRegIndex = 0;
    eMBMasterReqErrCode    eErrStatus = MB_MRE_NO_ERR;

    if 		( ucSndAddr > MB_MASTER_TOTAL_SLAVE_NUM ) 		eErrStatus = MB_MRE_ILL_ARG;
    else if ( xMBMasterRunResTake( lTimeOut ) == FALSE ) 	eErrStatus = MB_MRE_MASTER_BUSY;
    else
    {

       	SizeAnswer = SizeAddr + SizeFunct + 2 + SizeCRC + 2;		// 8 байт ответ
		xModbus_Set_SizeAnswer(SizeAnswer,usRegAddr);

		vMBMasterSetDestAddress(ucSndAddr);

		vMBMasterGetPDUSndBuf(&ucMBFrame);

		ucMBFrame[MB_PDU_FUNC_OFF]                     = MB_FUNC_WRITE_MULTIPLE_REGISTERS;
		ucMBFrame[MB_PDU_REQ_WRITE_MUL_ADDR_OFF]       = usRegAddr >> 8;
		ucMBFrame[MB_PDU_REQ_WRITE_MUL_ADDR_OFF + 1]   = usRegAddr;
		ucMBFrame[MB_PDU_REQ_WRITE_MUL_REGCNT_OFF]     = usNRegs >> 8;
		ucMBFrame[MB_PDU_REQ_WRITE_MUL_REGCNT_OFF + 1] = usNRegs ;
		ucMBFrame[MB_PDU_REQ_WRITE_MUL_BYTECNT_OFF]    = (uint8_t)usNRegs * 2;
		ucMBFrame += MB_PDU_REQ_WRITE_MUL_VALUES_OFF;
		while( usNRegs > usRegIndex)
		{
//			*ucMBFrame++ = pusDataBuffer[usRegIndex] >> 8;				// для TCP/MB так не подходит. надо менять полубайты
//			*ucMBFrame++ = pusDataBuffer[usRegIndex++] ;
			*ucMBFrame++ = pusDataBuffer[usRegIndex];
			*ucMBFrame++ = pusDataBuffer[usRegIndex++] >> 8;

		}
		vMBMasterSetPDUSndLength( MB_PDU_SIZE_MIN + MB_PDU_REQ_WRITE_MUL_SIZE_MIN + 2*usNRegs );

		( void ) xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );
//		eErrStatus = eMBMasterWaitRequestFinish( );
    }
    return eErrStatus;
}

eMBException
eMBMasterFuncWriteMultipleHoldingRegister( UCHAR * pucFrame, USHORT * usLen )
{
    eMBException    eStatus = MB_EX_NONE;
    return eStatus;
}
/*
// обработчик подтверждения принятой команды записи
eMBException
eMBMasterFuncWriteMultipleHoldingRegister( UCHAR * pucFrame, USHORT * usLen )
{
    UCHAR          *ucMBFrame;
    USHORT          usRegAddress;
    USHORT          usRegCount;
    UCHAR           ucRegByteCount;

    eMBException    eStatus = MB_EX_NONE;
    eMBErrorCode    eRegStatus;

    // If this request is broadcast, the *usLen is not need check.
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
            // Make callback to update the register values.
            eRegStatus =
                eMBMasterRegHoldingCB( &ucMBFrame[MB_PDU_REQ_WRITE_MUL_VALUES_OFF], usRegAddress, usRegCount, MB_REG_WRITE );

            // If an error occured convert it into a Modbus exception.
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
        // Can't be a valid request because the length is incorrect.
        eStatus = MB_EX_ILLEGAL_DATA_VALUE;
    }
    return eStatus;
}
*/
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
    UCHAR                	*ucMBFrame;
    uint16_t				SizeAnswer;
    uint16_t				SizeData = usNRegs << 1;
    eMBMasterReqErrCode    	eErrStatus = MB_MRE_NO_ERR;


	if 		(SizeData > (MaxSizeBlok_3_4*2)) 				eErrStatus = MB_MRE_ILL_ARG;		// недопустимый размер запроса для текущей функции
	else if ( ucSndAddr > MB_MASTER_TOTAL_SLAVE_NUM ) 		eErrStatus = MB_MRE_ILL_ARG;		// недопустимый адрес запроса
    else if ( xMBMasterRunResTake( lTimeOut ) == FALSE ) 	eErrStatus = MB_MRE_MASTER_BUSY;	// ожидаем ответа, нельзя слать
    else
    {

 //   	SizeData = usNRegs << 1;
    	SizeAnswer = SizeAddr+SizeFunct+SizeNumbByte+SizeData+SizeCRC;							// размер ожидаемого ответа
		xModbus_Set_SizeAnswer(SizeAnswer,usRegAddr);											// запоминаем для приёмника

		vMBMasterSetDestAddress(ucSndAddr);														// запомнили МБСлейв адрес получателя
		vMBMasterSetPDUSndLength( MB_PDU_SIZE_MIN + MB_PDU_REQ_READ_SIZE );						// запомнили размер сообщения

    	vMBMasterGetPDUSndBuf(&ucMBFrame);														// получаем буфер для передачи

		ucMBFrame[MB_PDU_FUNC_OFF]                = MB_FUNC_READ_HOLDING_REGISTER;				// заполнили буфер для отправки
		ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF]       = usRegAddr >> 8;
		ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1]   = usRegAddr;
		ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF]     = usNRegs >> 8;
		ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] = usNRegs;

		( void ) xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );								// переключили режим в отправку
//		eErrStatus = eMBMasterWaitRequestFinish( );												// пустая не работает
    }

    return eErrStatus;
}
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
eMBMasterReqErrCode		eMBMasterReqReadHoldingRegisterWithAddres( UCHAR ucSndAddr, USHORT usRegAddr, USHORT usNRegs, LONG lTimeOut )
{
    UCHAR                 *ucMBFrame;
    uint16_t			SizeAnswer;
    uint16_t			SizeData = usNRegs << 1;
    eMBMasterReqErrCode    eErrStatus = MB_MRE_NO_ERR;

    if 		( ucSndAddr > MB_MASTER_TOTAL_SLAVE_NUM ) 			eErrStatus = MB_MRE_ILL_ARG;
    else if ( xMBMasterRunResTake( lTimeOut ) == FALSE ) 		eErrStatus = MB_MRE_MASTER_BUSY;
    else
    {
    	SizeAnswer = SizeAddr+SizeFunct+SizeNumbWord+SizeData+SizeCRC;
		xModbus_Set_SizeAnswer(SizeAnswer,usRegAddr);

		vMBMasterSetDestAddress(ucSndAddr);
		vMBMasterSetPDUSndLength( MB_PDU_SIZE_MIN + MB_PDU_REQ_READ_SIZE );

    	vMBMasterGetPDUSndBuf(&ucMBFrame);


		ucMBFrame[MB_PDU_FUNC_OFF]                = MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;
		ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF]       = usRegAddr >> 8;
		ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1]   = usRegAddr;
		ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF]     = usNRegs >> 8;
		ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] = usNRegs;

		( void ) xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );
//		eErrStatus = eMBMasterWaitRequestFinish( );
    }
    return eErrStatus;
}
/***********************************************************************************
 * MR771 MR761 MR762 MR763 MR801
 ***********************************************************************************/
#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763) || defined (MR761OBR) ||\
	defined (MR801) ||\
	defined (MR901) || defined (MR902) ||\
	defined (MR851) ||\
	defined (MR5_500) || defined (MR5_600) || defined (MR5_700) ||\
	defined (MR741)

eMBException	eMBMasterFuncReadRegisters( UCHAR * pucFrame, USHORT * usLen )
{
//	ModbusHead 	   *pxMessage;

	UCHAR          *ucMBFrame;
    uint16_t        usRegAddress;
    uint8_t         usRegDataOffs;
    uint8_t         usRegCodeFunc = 0;
    uint16_t        usRegCount = 0;
//    uint16_t		StartMemForSave;
    uint16_t		MemForSave;

    eMBException    eStatus = MB_EX_NONE;
    eMBErrorCode    eRegStatus = 0;

    /* If this request is broadcast, and it's read mode. This request don't need execute. */
    if ( xMBMasterRequestIsBroadcast() )
    {
    	eStatus = MB_EX_NONE;
    }
    else if( *usLen >= MB_PDU_SIZE_MIN + MB_PDU_FUNC_READ_SIZE_MIN )
    {

/*
    	if (xQueueReceive( ModbusResponseQueue,( void * ) &pxMessage,( TickType_t ) 0 )){
            usRegAddress = ( USHORT )( pxMessage->ucData[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
            usRegAddress |= ( USHORT )( pxMessage->ucData[MB_PDU_REQ_READ_ADDR_OFF + 1] );
            usRegAddress++;
            usRegCount = ( USHORT )( pxMessage->ucData[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
            usRegCount |= ( USHORT )( pxMessage->ucData[MB_PDU_REQ_READ_REGCNT_OFF + 1] );
    	} else{
    		// нету ничего в очереди.
//    		USART_TRACE_RED("нету ничего в очереди. размер данных:%u\n",pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF]);
            eStatus = MB_EX_ILLEGAL_DATA_VALUE;
        return eStatus;
    	}
*/
    	usRegCodeFunc 	= (uint8_t)pucFrame[MB_PDU_FUNC_OFF];

       	if (usRegCodeFunc == MB_FUNC_READ_HOLDING_REGISTER_W_ADDR){
// 0x13 функция.

        	usRegAddress = (uint16_t)pucFrame[MB_PDU_FUNC_READ_MEMADDR_OFF] << 8;
        	usRegAddress |= (uint16_t)pucFrame[MB_PDU_FUNC_READ_MEMADDR_OFF+1];
            usRegAddress++;

            usRegCount = (uint16_t)pucFrame[MB_PDU_FUNC_READ_WORDCNT_OFF] << 8;
            usRegCount |= (uint16_t)pucFrame[MB_PDU_FUNC_READ_WORDCNT_OFF + 1];
           	usRegCount 	-=  1;// отнимем слово с адресом SizeMemAddr;

       		usRegDataOffs = MB_PDU_FUNC_READ_VALUES_W_MEM_OFF;
       	}else
        if (usRegCodeFunc == MB_FUNC_READ_HOLDING_REGISTER){
// 3 функция.
        	vMBMasterGetPDUSndBuf(&ucMBFrame);											// берём из передающего буфера адрес в памяти чтобы высчитать куда положить в принятую память
            usRegAddress = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF] << 8 );
            usRegAddress |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_ADDR_OFF + 1] );
            usRegAddress++;

            usRegCount = ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF] << 8 );
            usRegCount |= ( USHORT )( ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1] );

       		usRegDataOffs = MB_PDU_FUNC_READ_VALUES_OFF;
       	}

//        if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )
       	if( usRegCount >= 1 )
        {
        	MemForSave = usRegAddress-1;

//----------------------------------------------------------------
//- проверим в какую область памяти писать -----------------------
//----------------------------------------------------------------

// ревизия
        	if (usMRevStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount, ucMRevBuf, usMRevStart, MB_Size_Rev );		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("Версия: '%s'\n",(char *)ucMRevBuf);
                	int8_t	Rev = Hal_Verify_Rev((uint8_t *)ucMRevBuf);
                	if (Rev == 0){
                		osMutexRelease(xIEC850StartMutex);			// запустим таск потому как хана, там не тот прибор
                	}else{
                 	}
                	ucMRevBuf[15] = 0;//0x1e1e;
               		sprintf(NamPlt_swRev,"%s %s",(char *)_swREV,(char *)ucMRevBuf + MB_offset_VersionDev);
               		//NamPlt_swRev[32] = ' ';
					    if (iedServer){
					    	// при старте точно этого не может быть. Модель не факт что активна
					    	IedServer_NumPltUpdate_swRev(iedServer,NamPlt_swRev);
					    }

                }else {
            		USART_TRACE_RED("ошибка версии из MODBUS\n");
            		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                }
        	}
// дискреты
        	else if (usMDiscInStart== MemForSave){
        		if (NextPacketIgnor == false) {
					eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount, ucMDiscInBuf, usMDiscInStart, MB_Size_Discreet );		// сохраняем данные в хранилище
					if( eRegStatus == MB_ENOERR ){
					    if (iedServer){
							IedServer_DataUpdateInGoosesDatasets(iedServer);
					    }
					}
        		} else {
        			NextPacketIgnor = false;
        			eRegStatus = MB_ENOERR;
        		}
        	}
// аналоги
// старый вариант, ответ в одну транзакцию.
/*
        	else if ( usMAnalogInStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount, ucMAnalogInBuf, usMAnalogInStart, MB_Size_Analog);		// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){
                //	USART_TRACE_GREEN("БД аналогов.\n");
                }
        	}
*/
// новый вариант, ответ в несколько транзакций.
			else if ((MemForSave >= usMAnalogInStart) && (MemForSave < (usMAnalogInStart+MB_Size_Analog-1))){

				uint16_t		SizeAnswer;
				uint16_t		Size;
				xModbus_Get_SizeAnswer((uint16_t *)&Size);
				SizeAnswer = Size;

				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,(USHORT *)&ucMAnalogInBuf[MemForSave-usMAnalogInStart], MemForSave, SizeAnswer);
			}
//  конфигурация системы
        	else if ( usSystemCfgStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount, ucSystemCfgBuf, usSystemCfgStart, MB_Size_SystemCfg);
                if( eRegStatus == MB_ENOERR ){	// меняем IP адрес
                	USART_TRACE_GREEN("Получили конфиг системы.\n");

#if defined(MB_offset_Q_TestMode)
                	// режим симуляции гусов
                	{
                		// тестирование
                		if ((ucSystemCfgBuf[MB_offset_Q_TestMode] & MB_bOffset_Q_TestMode) > 2){//!= 0
                			//IedServer_enableGooseSimulation(iedServer);		// это симуляция гусов
                			GLOBAL_QUALITY |= QUALITY_TEST;
                			USART_TRACE("QUALITY_TEST on.\n");
                		}else{
                			//IedServer_disableGooseSimulation(iedServer);		// это симуляция гусов
                			GLOBAL_QUALITY &= ~QUALITY_TEST;
                			USART_TRACE("QUALITY_TEST off.\n");
                		}
#if defined(MB_offset_CONFIG)
                		// резервирование
                		RedModeType mode = (ucSystemCfgBuf[MB_offset_CONFIG]>>_bRedundnacyOffset) & MB_bMask_Redundnacy;
						uint8_t rdmod;
						memory_read((uint8_t *)&rdmod,_IfRedundancyMode,1);
						if (rdmod != mode){		// рапомним режим для будущего. нужен в загрузчике
							memory_write_to_mem((uint8_t *)&mode,_IfRedundancyMode,1);
							RedMode = mode;
							SetRedundansyMode(RedMode);

							vTaskDelay(100);
							NVIC_SystemReset();
#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
        					IedServer_disableGoosePublishing(iedServer);
        					IedServer_enableGoosePublishing(iedServer);
#endif//!CONFIG_INCLUDE_GOOSE_SUPPORT
						}
#endif//!MB_offset_CONFIG
                	}
#endif//!MB_offset_Q_TestMode

                	int8_t	resSetIP = Hal_setIPFromMB_Date((uint16_t*)&ucSystemCfgBuf[MB_offset_IP]);
                	if (resSetIP == 0){
                					// если всё норм то нужно сообщить о готовности работать IP
                					USART_TRACE_GREEN("получили из MODBUS IP:%d.%d.%d.%d \n", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
                					// перезапустим таск
                					if (MAC_ADDR[0] && MAC_ADDR[1] && MAC_ADDR[2]){
                						ReStartIEC850_task();
                 					}

                					osMutexRelease(xIEC850StartMutex);
                	} else
                	if (resSetIP == -1){
                		USART_TRACE_Yellow("не допустимый IP из MODBUS\n");
                		eStatus = MB_EX_ILLEGAL_DATA_VALUE;
                	} else
                	if (resSetIP == 2){	// совпадение с прошлым включением
                		USART_TRACE_GREEN("IP из MODBUS совпадает с константой.\n");
    					osMutexRelease(xIEC850StartMutex);

                	}
                }
        	}
// чтение текущего времени
        	else if ( usMDateStart == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount, ucMDateBuf, usMDateStart, MB_Size_Date);				// сохраняем данные в хранилище
                if( eRegStatus == MB_ENOERR ){

                 	USART_TRACE_GREEN("время из прибора:%.2d.%.2d.%.4d %.2d:%.2d:%.2d\n", ucMDateBuf[2], ucMDateBuf[1],2000 + ucMDateBuf[0], ucMDateBuf[3], ucMDateBuf[4], ucMDateBuf[5]);
                	if (ucMDateBuf[2] && ucMDateBuf[3]){
						Hal_setTimeFromMB_Date(ucMDateBuf);
						nextSynchTime = Hal_getTimeInMs() + msInDay;				// следующая пересинхронизация часов
	//                	nextSynchTime = HAL_GetTick() + msInDay;				// следующая пересинхронизация часов
						USART_TRACE_GREEN("время:0x%X следующая синхронизация:0x%X\n",(unsigned int)Hal_getTimeInMs(),(unsigned int)nextSynchTime);
						resynch = true;
                	}
                }
        	}
// чтение конфигурации АПВ
			else if ( usConfigAPWStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount, ucConfigAPWBuf, usConfigAPWStart, MB_Size_ConfigAPW);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("конфиг АПВ.(0x%X)\n",MemForSave);
				}else{
					USART_TRACE_RED("ошибка конфиг АПВ.(0x%X)\n",MemForSave);
				}
			}
// чтение конфигурации АВР+ЛЗШ
			else if ( usConfigAWRStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount, ucConfigAWRBuf, usConfigAWRStart, MB_Size_ConfigAWR);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("конфиг АВР+ЛЗШ.(0x%X)\n",MemForSave);
					/*
					uint8_t	i;
					for(i=0;i<MB_Size_ConfigAWR;i++) USART_0TRACE("0x%.4X ",ucConfigAWRBuf[i]);
					USART_0TRACE("\n");
					*/
				}else{
					USART_TRACE_RED("ошибка конфиг АВР+ЛЗШ.(0x%X)\n",MemForSave);
				}
			}
// чтение всех уставок силового транса
			else if ( usConfigTRPWRStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount, ucConfigTRPWRBuf, usConfigTRPWRStart, MB_Size_ConfigTRPWR);

				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("уставки силового транс.(0x%X)\n",MemForSave);
					/*
					uint8_t	i;
					for(i=0;i<MB_Size_ConfigTRPWR;i++) USART_0TRACE("0x%.4X ",ucConfigTRPWRBuf[i]);
					USART_0TRACE("\n");
					*/
				}else{
					USART_TRACE_RED("ошибка силового транс.(0x%X)\n",MemForSave);
				}
			}
// чтение всех уставок измерительного транса
			else if ( usConfigTRMeasStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount, ucConfigTRMeasBuf, usConfigTRMeasStart, MB_NumbConfigTRMeas);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("конфиг измерит. транс.(0x%X)\n",MemForSave);
					/*
					uint8_t	i;
					for(i=0;i<MB_NumbConfigTRMeas;i++) USART_0TRACE("0x%.4X ",ucConfigTRMeasBuf[i]);
					USART_0TRACE("\n");
					*/
				}else{
					USART_TRACE_RED("ошибка измерит. транс.(0x%X)\n",MemForSave);
				}
			}
// чтение конфигурации входных логических сигналов
			else if ((MemForSave >= usConfigVLSInStart) && (MemForSave < (usConfigVLSInStart+MB_Size_ConfigVLSIn-1))){

				uint16_t		SizeAnswer;
				uint16_t		Size;
				xModbus_Get_SizeAnswer((uint16_t *)&Size);
				SizeAnswer = Size;

				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,(USHORT *)&ucVLSInBuf[MemForSave-usConfigVLSInStart], MemForSave, SizeAnswer);

				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%.4d-%.4d(0x%X) конфиг ВхЛС\n",MemForSave-usConfigVLSInStart,(MemForSave-usConfigVLSInStart)+SizeAnswer,MemForSave);

				}else{
					USART_TRACE_RED("%.4d-%.4d(0x%X) ошибка ВхЛС\n",MemForSave-usConfigVLSInStart,MemForSave-usConfigVLSInStart+SizeAnswer,MemForSave);
				}
			}
// чтение конфигурации выходных логических сигналов
			else if ((MemForSave >= usConfigVLSOutStart) && (MemForSave < (usConfigVLSOutStart+MB_Size_ConfigVLSOut-1))){

				uint16_t		SizeAnswer;
				uint16_t		Size;
				xModbus_Get_SizeAnswer((uint16_t *)&Size);
				SizeAnswer = Size;

				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,(USHORT *)&ucVLSOutBuf[MemForSave-usConfigVLSOutStart], MemForSave, SizeAnswer);

				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%.4d-%.4d(0x%X) конфиг ВыЛС\n",MemForSave-usConfigVLSOutStart,MemForSave-usConfigVLSOutStart+SizeAnswer,MemForSave);

				}else{
					USART_TRACE_RED("%.4d-%.4d(0x%X) ошибка ВыЛС\n",MemForSave-usConfigVLSOutStart,MemForSave-usConfigVLSOutStart+SizeAnswer,MemForSave);
				}
			}
// чтение конфигурации выходных сигналов
			else if ( usConfigOutStart  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,ucOutSignalBuf, usConfigOutStart, MB_Size_ConfigOut);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("конфиг. выходных сигналов.(0x%x)\n",MemForSave);
				}
			}
// чтение конфигурации выключателя
        	else if ( usConfigStartSW == MemForSave){
                eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount, ucConfigBufSW, usConfigStartSW, MB_Size_ConfigSW);
                if( eRegStatus == MB_ENOERR ){
                	USART_TRACE_GREEN("конфиг выключателя. (0x%x)\n",MemForSave);
                	AddToQueueMB(ModbusSentQueue, 	MB_Rd_ConfigSWCrash	,MB_Slaveaddr);	// чтение ресурса выключателя
                }else{
					USART_TRACE_RED("ошибка конфиг. выключателя.(0x%X)\n",MemForSave);
				}
        	}
// чтение ресурса выключателя
			else if ( usConfigStartSWCrash == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount, ucSWCrash, usConfigStartSWCrash, MB_Size_SWCrash);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("ресурс выключателя. (0x%.4X)\n",MemForSave);
					/*
					uint8_t	i;
					for(i=0;i<MB_Size_SWCrash;i++) USART_0TRACE("0x%.4X ",ucSWCrash[i]);
					USART_0TRACE("\n");
					*/
				}else{
					USART_TRACE_RED("ошибка ресурса выключателя.(0x%X)\n",MemForSave);
				}
			}
// привод РПН
			else if ( usRPNStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount, ucRPNBuf, usRPNStart, MB_Size_RPN);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("ресурс привода РПН. (0x%.4X)\n",MemForSave);
					/*
					uint8_t	i;
					for(i=0;i<MB_Size_RPN;i++) USART_0TRACE("0x%.4X ",ucRPNBuf[i]);
					USART_0TRACE("\n");
					*/
				}else{
					USART_TRACE_RED("ошибка ресурса привода РПН.(0x%X)\n",MemForSave);
				}
			}
// чтение номера группы уставок
        	else if ( usSGStart == MemForSave){
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,ucSGBuf, MemForSave, MB_Size_SG);
				if( eRegStatus == MB_ENOERR ){
					// выбираем нужную группу
					 {
						 uint16_t	adin = (uint16_t)MB_Size_Ustavki;
						 adin = adin * ucSGBuf[0];
#if defined (MR5_700) ||  defined (MR5_600) ||  defined (MR5_500) || defined (MR741)
						 adin = 0;
#endif
						 // если изменилась группа
						 //if (usConfigUstavkiStart != (uint16_t)MB_Addr_Ustavkiaddr0 + adin){
						 //	 usConfigUstavkiStart = (uint16_t)MB_Addr_Ustavkiaddr0 + adin;
						 //}

						 usConfigUstavkiStart = (uint16_t)MB_Addr_Ustavkiaddr0 + adin;
						 Get_AllUstavki(ModbusSentQueue,MB_Slaveaddr);
					 }
				USART_TRACE_GREEN("номер группы.(0x%x) (%d) addr:0x%X\n",MemForSave,ucSGBuf[0]+1,usConfigUstavkiStart);
				}else{
					USART_TRACE_RED("ошибка номера группы.(0x%x) (%d) addr:0x%X\n",MemForSave,ucSGBuf[0]+1,usConfigUstavkiStart);
				}
			}
// чтение группы уставок
			else if (( usConfigUstavkiStart <= MemForSave) &&(MemForSave < (usConfigUstavkiStart+MB_Size_Ustavki-1))){

				uint16_t		SizeAnswer;
				uint16_t		Size;
				xModbus_Get_SizeAnswer((uint16_t *)&Size);
				SizeAnswer = Size;
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,(USHORT *)&ucMUstavkiInBuf[MemForSave-usConfigUstavkiStart], MemForSave, SizeAnswer);

				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%.4d-%.4d(0x%X) группы уставок\n",MemForSave-usConfigUstavkiStart,MemForSave-usConfigUstavkiStart+SizeAnswer,MemForSave);

				}else{
					USART_TRACE_RED("%.4d-%.4d(0x%X) ошибка группы уставок\n",MemForSave-usConfigUstavkiStart,MemForSave-usConfigUstavkiStart+SizeAnswer,MemForSave);
				}

			}
// чтение общих уставок
			else if (( usConfigOtherUstavkiStart <= MemForSave) &&(MemForSave < (usConfigOtherUstavkiStart+MB_Size_OtherUstavki-1))){

				uint16_t		SizeAnswer;
				uint16_t		Size;
				xModbus_Get_SizeAnswer((uint16_t *)&Size);
				SizeAnswer = Size;
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,(USHORT *)&ucOtherUstavkiInBuf[MemForSave-usConfigOtherUstavkiStart], MemForSave, SizeAnswer);

				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%.4d-%.4d(0x%X) общие уставки\n",MemForSave-usConfigOtherUstavkiStart,MemForSave-usConfigOtherUstavkiStart+SizeAnswer,MemForSave);

				}else{
					USART_TRACE_RED("%.4d-%.4d(0x%X) ошибка общих уставок\n",MemForSave-usConfigOtherUstavkiStart,MemForSave-usConfigOtherUstavkiStart+SizeAnswer,MemForSave);
				}
			}
// чтение параметров автоматики
			else if (( usConfigAutomatStart <= MemForSave) &&(MemForSave < (usConfigAutomatStart+MB_Size_Automat-1))){

				uint16_t		SizeAnswer;
				uint16_t		Size;
				xModbus_Get_SizeAnswer((uint16_t *)&Size);
				SizeAnswer = Size;
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,(USHORT *)&ucMAutomatBuf[MemForSave-usConfigAutomatStart], MemForSave, SizeAnswer);

				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%.4d-%.4d(0x%X) Парам.автоматики\n",MemForSave-usConfigAutomatStart,MemForSave-usConfigAutomatStart+SizeAnswer,MemForSave);
				}else{
					USART_TRACE_RED("%.4d-%.4d(0x%X) ошибка Парам.автоматики\n",MemForSave-usConfigAutomatStart,MemForSave-usConfigAutomatStart+SizeAnswer,MemForSave);
				}
			}
// чтение конфигурации УРОВ
			else if (( MB_Addr_ConfigUROV <= MemForSave) &&(MemForSave < (MB_Addr_ConfigUROV+MB_Size_ConfigUROV))){

				uint16_t		SizeAnswer;
				uint16_t		Size;
				xModbus_Get_SizeAnswer((uint16_t *)&Size);
				SizeAnswer = Size;
				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,(USHORT *)&ucConfigUROVBuf[MemForSave-MB_Addr_ConfigUROV], MemForSave, SizeAnswer);

				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%.4d-%.4d(0x%X) Конфиг.УРОВ\n",MemForSave-MB_Addr_ConfigUROV,MemForSave-MB_Addr_ConfigUROV+SizeAnswer,MemForSave);

				}else{
					USART_TRACE_RED("%.4d-%.4d(0x%X) ошибка Конфиг.УРОВ\n",MemForSave-MB_Addr_ConfigUROV,MemForSave-MB_Addr_ConfigUROV+SizeAnswer,MemForSave);
				}
			}
//++++++++++++++++++++++++++++++++++++++++++++++++++++
// чтение конфигурации внешних защит
			else if (( usConfigStartExZ <= MemForSave) &&(MemForSave < (usConfigStartExZ+MB_NumbConfigExZ-1))){
				uint16_t		SizeAnswer;
				uint16_t		Size;
				xModbus_Get_SizeAnswer((uint16_t *)&Size);
				SizeAnswer = Size;

				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;

				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,(USHORT *)&ucConfigBufExZ[MemForSave-usConfigStartExZ], MemForSave, SizeAnswer);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%.4d-%.4d(0x%X) Конфиг. внешних защит\n",MemForSave-usConfigStartExZ,MemForSave-usConfigStartExZ+SizeAnswer,MemForSave);
				}else{
					USART_TRACE_RED("%.4d-%.4d(0x%X) ошибка Конфиг. внешних защит\n",MemForSave-usConfigStartExZ,MemForSave-usConfigStartExZ+SizeAnswer,MemForSave);
				}
			}
#if !defined (MR5_600)
// чтение конфигурации токовых защит
			else if (( usConfigStartMTZ <= MemForSave) &&(MemForSave < (usConfigStartMTZ+MB_NumbConfigMTZ-1))){

				uint16_t		SizeAnswer;
				uint16_t		Size;
				xModbus_Get_SizeAnswer((uint16_t *)&Size);
				SizeAnswer = Size;

				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;

				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,(USHORT *)&ucConfigBufMTZ[MemForSave-usConfigStartMTZ], MemForSave, SizeAnswer);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%.4d-%.4d(0x%X) Конфиг. токовых защит\n",MemForSave-usConfigStartMTZ,MemForSave-usConfigStartMTZ+SizeAnswer,MemForSave);
				}else{
					USART_TRACE_RED("%.4d-%.4d(0x%X) ошибка Конфиг. токовых защит\n",MemForSave-usConfigStartMTZ,MemForSave-usConfigStartMTZ+SizeAnswer,MemForSave);
				}
			}
// чтение конфигурации дополнительных защит
			else if (( usConfigStartI2I1I0 <= MemForSave) &&(MemForSave < (usConfigStartI2I1I0+MB_NumbConfigI2I1I0-1))){

				uint16_t		SizeAnswer;
				uint16_t		Size;
				xModbus_Get_SizeAnswer((uint16_t *)&Size);
				SizeAnswer = Size;

				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;

				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,(USHORT *)&ucConfigBufI2I1I0[MemForSave-usConfigStartI2I1I0], MemForSave, SizeAnswer);
//				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,ucConfigBufI2I1I0, usConfigStartI2I1I0, MB_NumbConfigI2I1I0);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%.4d-%.4d(0x%X) Конфиг. доп. защит\n",MemForSave-usConfigStartI2I1I0,MemForSave-usConfigStartI2I1I0+MB_NumbConfigI2I1I0,MemForSave);
				}else{
					USART_TRACE_RED("%.4d-%.4d(0x%X) ошибка Конфиг.доп. защит\n",MemForSave-usConfigStartI2I1I0,MemForSave-usConfigStartI2I1I0+SizeAnswer,MemForSave);
				}
			}
#endif
#if !defined (MR5_500)
// чтение конфигурации защиты по частоте
			else if (( usConfigStartF <= MemForSave) &&(MemForSave < (usConfigStartF+MB_Size_ConfigF-1))){

				uint16_t		SizeAnswer;
				uint16_t		Size;
				xModbus_Get_SizeAnswer((uint16_t *)&Size);
				SizeAnswer = Size;

				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;

				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,(USHORT *)&ucConfigBufF[MemForSave-usConfigStartF], MemForSave, SizeAnswer);
//				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,ucConfigBufF, usConfigStartF, MB_Size_ConfigF);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%.4d-%.4d(0x%X) Конфиг. защиты по частоте.(0x%X)\n",MemForSave-usConfigStartF,MemForSave);
				}else{
					USART_TRACE_RED("%.4d-%.4d(0x%X) ошибка Конфиг. защиты по частоте.(0x%X)\n",MemForSave-usConfigStartF,MemForSave);
				}
			}
#if !defined (MR5_600)
// чтение конфигурации защиты по напряжению
			else if ( usConfigStartU  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,ucConfigBufU, usConfigStartU, MB_Size_ConfigU);
				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%d. Конфиг. защиты по напряжению.(0x%X)\n",MemForSave-usConfigStartU,MemForSave);
				}else{
					USART_TRACE_RED("%d. ошибка Конфиг. защиты по напряжению.(0x%X)\n",MemForSave-usConfigStartU,MemForSave);
				}
			}
#endif
#if defined (MR5_600)
// чтение конфигурации защиты по напряжению
			else if (( usConfigStartU <= MemForSave) &&(MemForSave < (usConfigStartU+MB_Size_ConfigU-1))){

				uint16_t		SizeAnswer;
				uint16_t		Size;
				xModbus_Get_SizeAnswer((uint16_t *)&Size);
				SizeAnswer = Size;

				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;

				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,(USHORT *)&ucConfigBufU[MemForSave-usConfigStartU], MemForSave, SizeAnswer);

				if( eRegStatus == MB_ENOERR ){
					USART_TRACE_GREEN("%.4d-%.4d(0x%X) Конфиг. защиты по напряжению\n",MemForSave-usConfigStartU,MemForSave-usConfigStartU+SizeAnswer,MemForSave);
				}else{
					USART_TRACE_RED("%.4d-%.4d(0x%X) ошибка Конфиг. защиты по напряжению\n",MemForSave-usConfigStartU,MemForSave-usConfigStartU+SizeAnswer,MemForSave);
				}
			}
#endif

#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++
// чтение записи в журнале системы
			else if ( usSysNoteStart  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,ucSysNoteBuf, usSysNoteStart, MB_Size_SysNote);
				if( eRegStatus == MB_ENOERR ){
					//USART_TRACE_GREEN("Получили %u записи журнала системы. addr:0x%.4X код:%u время: %.2u:%.2u:%.2u.%.3u \n", GlobalAddrSysNote, usRegAddress-1, ucSysNoteBuf[MB_OffsetSysNoteMessage],ucSysNoteBuf[3],ucSysNoteBuf[4],ucSysNoteBuf[5],ucSysNoteBuf[6]);
				}else{
					USART_TRACE_RED("ошибка журнала системы.(0x%X)\n",MemForSave);
				}
// читаем весь журнал не зависимо сколько новых записей
				// если пришло последнее сообщение код = 0 или число записей достигло максимума
				if ( 	(ucSysNoteBuf[MB_OffsetSysNoteMessage] == MB_Code_SysNoteEndJurnal) || (GlobalAddrSysNote >= MB_SizeSysNote-1) )
				{
					// последнюю запись сохраним
					if (GlobalAddrSysNote >= MB_SizeSysNote-1){
						AddToFileMessageWord(_SystemNoteTmp,(uint8_t*)ucSysNoteBuf,MB_Size_SysNote*2,MB_SizeSysNote,FA_OPEN_APPEND | FA_WRITE);
						// перепишем файл из временной папки в рабочую
						//f_unlink(_SystemNoteTmp);
					}
					f_rename(_SystemNoteTmp,_SystemNote);
					ResetAddrSysNote();
					NewSysNoteMessage = true;

					AddToQueueMB(Rd_OscNoteQueue, MB_Wrt_OscNoteAdr0		,MB_Slaveaddr);			// ставим задачу сброса записи
					AddToQueueMB(Rd_OscNoteQueue, MB_Rd_OscNote				,MB_Slaveaddr);			// ставим задачу чтения журнала осцилл.

				}else
				{
					if (GlobalAddrSysNote == 0){			// первое сообщение. очистим файл
						f_unlink(_SystemNote);
						AddToFileMessageWord(_SystemNoteTmp,(uint8_t*)ucSysNoteBuf,MB_Size_SysNote*2,MB_SizeSysNote,FA_CREATE_ALWAYS | FA_WRITE);
					}else{
						AddToFileMessageWord(_SystemNoteTmp,(uint8_t*)ucSysNoteBuf,MB_Size_SysNote*2,MB_SizeSysNote,FA_OPEN_APPEND | FA_WRITE);
					}

					GlobalAddrSysNote++;
#if	defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)
					// инкрементим и покатили дальше читать
					usSysNoteStart += MB_Size_SysNote+MB_Size_SysNoteASCII;		// не нужно инкрементить адрес
#endif
#if	defined (MR851)
					// инкрементим и покатили дальше читать
					// GlobalAddrSysNote
#endif
					AddToQueueMB(Rd_SysNoteQueue, MB_Rd_SysNote			,MB_Slaveaddr);
				}
			}
// чтение записи в журнале аварий
			else if ( usErrorNoteStart  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,ucErrorNoteBuf, usErrorNoteStart, MB_Size_ErrorNote);
				if( eRegStatus == MB_ENOERR ){
					//USART_TRACE_BLUE("Получили %u записи журнала аварий. addr:0x%.4X код:%u\n", GlobalAddrErrorNote, usRegAddress-1,ucErrorNoteBuf[MB_OffsetErrorNoteMessage]);
				}else{
					USART_TRACE_RED("ошибка записи журнала аварий.(0x%X)\n",MemForSave);
				}
// читаем весь журнал не зависимо сколько новых записей

				if ( (ucErrorNoteBuf[MB_OffsetErrorNoteMessage] == MB_Code_ErrorNoteEndJurnal) || (GlobalAddrErrorNote >= MB_SizeErrorNote-1) ){

					// последнюю запись сохраним
					if (GlobalAddrErrorNote >= MB_SizeErrorNote-1){
						AddToFileMessageWord(_ErrorNoteTmp,(uint8_t*)ucErrorNoteBuf,MB_Size_ErrorNote*2,MB_SizeErrorNote,FA_OPEN_APPEND | FA_WRITE);
					}
					// допишем в конце уставки для расшифровки записей.
					AddToFileUstavkiForJA(_ErrorNoteTmp,FA_OPEN_APPEND | FA_WRITE);
					// ---------------------------------------
					f_rename(_ErrorNoteTmp,_ErrorNote);

					ResetAddrErrorNote();
					NewErrorNoteMessage = true;
				}else{

					if (GlobalAddrErrorNote == 0){			// первое сообщение. очистим файл
						f_unlink(_ErrorNote);
						AddToFileMessageWord(_ErrorNoteTmp,(uint8_t*)ucErrorNoteBuf,MB_Size_ErrorNote*2,MB_SizeErrorNote,FA_CREATE_ALWAYS | FA_WRITE);
					}else{
						AddToFileMessageWord(_ErrorNoteTmp,(uint8_t*)ucErrorNoteBuf,MB_Size_ErrorNote*2,MB_SizeErrorNote,FA_OPEN_APPEND | FA_WRITE);
					}
#if	defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)
					// инкрементим и покатили дальше читать
					usErrorNoteStart += MB_NextErrorNote;
#endif
					GlobalAddrErrorNote++;
					AddToQueueMB(Rd_ErrorNoteQueue, MB_Rd_ErrorNote		,MB_Slaveaddr);
				}
			}
// чтение записи в журнале осциллограмм
			else if ( usOscNoteStart  == MemForSave) {
				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,ucOscNoteBuf, usOscNoteStart, MB_Size_OscNote);
				if( eRegStatus == MB_ENOERR ){
					uint32_t   ucOscMessStarttmp = ucOscNoteBuf[MB_Osc_POINT+1]<<16 | ucOscNoteBuf[MB_Osc_POINT];
					uint32_t   ucOscMessSizetmp = (ucOscNoteBuf[MB_Osc_LEN+1]<<16 | ucOscNoteBuf[MB_Osc_LEN]) * 18;

					//USART_TRACE_CYAN("Получили %u записи журнала осциллографа.addr:0x%.4X (0x%X) код:%u готов:%u Start:0x%.8X Size:0x%.8X\n", GlobalAddrOscNote, usRegAddress-1, MemForSave, ucOscNoteBuf[MB_OffsetOscNoteMessage],ucOscNoteBuf[MB_Code_OscNoteREADY], ucOscMessStarttmp, ucOscMessSizetmp);
				}else{
					USART_TRACE_RED("ошибка записи журнала осциллографа.(0x%X)\n",MemForSave);
				}
				// берём только первую осциллограмму
				if ((0 == GlobalAddrOscNote)&&(ucOscNoteBuf[MB_OffsetOscNoteMessage]>0)){
#if defined (MB_Addr_Osc)

					// 1. нужно проверять время создания
					// 2. Переписывать в файл в отдельном таске, чтоб не тормозил основную функцию
					// 3. Не разрешать дальнейшее чтение осциллограмм пока не запишется сектор в файл.

					if(memcmp(ucOscNoteBuf,ucOscNoteBufPre,MB_Size_OscNoteTime)!=0){
						memcpy(ucOscNoteBufPre,ucOscNoteBuf,MB_Size_OscNoteTime);

						ucOscMessStart = ucOscNoteBuf[MB_Osc_POINT+1]<<16 | ucOscNoteBuf[MB_Osc_POINT];
						ucOscMessSize = (ucOscNoteBuf[MB_Osc_LEN+1]<<16 | ucOscNoteBuf[MB_Osc_LEN]) * 18;// размер в словах

						ucCurrOscPage = (uint16_t)(ucOscMessStart/(uint32_t)MB_SizeOscBlock);	// текущая страница
						ucCurrOscAddrOnPage = MB_Addr_Osc;									// текущий адрес на странице

						ucCurrOscSizeOnPage = MB_SizeOscBlock;
// временно не читаем осциллограмму
//						AddToQueueMB_FS(_OneOscTmp,(uint8_t*)ucOscBlockBuf,0,FA_CREATE_ALWAYS | FA_WRITE, QueueMB_GetPageOsc, NULL);
					}
#endif
				}

				if ( (ucOscNoteBuf[MB_OffsetOscNoteMessage] == MB_Code_OscNoteEndJurnal) || (GlobalAddrOscNote >= MB_SizeOscNote-1) ){

					ucOscNoteCurrNumb = GlobalAddrOscNote;
					usOscNoteStart = MB_Addr_OscNote;		// обнулим указатель и
					GlobalAddrOscNote = 0;						// число новых записей
				}else{
					GlobalAddrOscNote++;
					AddToQueueMB(Rd_SysNoteQueue, MB_Rd_OscNote		,MB_Slaveaddr);//Rd_OscNoteQueue
				}
			}
// чтение самой осциллограммы
#if defined (MB_Addr_Osc)
			else if (( usOscBlockStart <= MemForSave) &&(MemForSave < (usOscBlockStart+MB_SizeAllOsc-1))){

				uint16_t		SizeAnswer;
				uint16_t		Size;
				xModbus_Get_SizeAnswer((uint16_t *)&Size);
				SizeAnswer = Size;

				SizeAnswer -= SizeAddr+SizeFunct+1+SizeCRC;
				SizeAnswer = SizeAnswer>>1;

				eRegStatus = eMBMasterToMemDB( &pucFrame[usRegDataOffs], usRegAddress, usRegCount,(USHORT *)&ucOscBlockBuf[MemForSave-usOscBlockStart], MemForSave, SizeAnswer);
				if( eRegStatus == MB_ENOERR ){
//					USART_TRACE_GREEN("%.4d-%.4d. Получили блок осциллографа.(0x%X)\n",MemForSave-usOscBlockStart,MemForSave-usOscBlockStart+SizeAnswer,MemForSave);

					// если дочитали страницу, перепишем в файл и проинкрементим
					if ((MemForSave + SizeAnswer) >= (MB_Addr_Osc + ucCurrOscSizeOnPage)){

						 uint32_t  sz,end,start;
						//ucOscMessSize - размер в отсчётах. 1 отчет = 18словам
						 sz = (uint32_t)(ucOscMessSize/(uint32_t)MB_SizeOscBlock);		// размер в страницах
						 end = (uint32_t)(ucOscMessSize%(uint32_t)MB_SizeOscBlock);		// размер хвоста
						 start = (uint32_t)(ucOscMessStart/(uint32_t)MB_SizeOscBlock);	// cтраница начала


//			  			 AddToFileMessageWord(_OneOscTmp,(uint8_t*)ucOscBlockBuf,(uint16_t)ucCurrOscSizeOnPage*2,0,FA_OPEN_APPEND | FA_WRITE);
						 USART_TRACE_Yellow("задача записи в файл '%s'. стр.0x%.4X из 0x%.4X размер:%u\n",_OneOscTmp,ucCurrOscPage,(start+sz),ucCurrOscSizeOnPage*2);

						if (ucCurrOscPage < (start+sz)){
							AddToQueueMB_FS(_OneOscTmp,(uint8_t*)ucOscBlockBuf,(uint16_t)ucCurrOscSizeOnPage*2,FA_OPEN_APPEND | FA_WRITE, QueueMB_GetPageOsc, NULL);
//							USART_TRACE_GREEN("страница осциллографа. 0x%.4X : 0x%.4X хвост %u\n",ucCurrOscPage,(start+sz),end);
							ucCurrOscPage++;													// текущая страница
							ucCurrOscAddrOnPage = MB_Addr_Osc;								// текущий адрес на странице
							ucCurrOscSizeOnPage = MB_SizeOscBlock;								// размер блока
							// если это последняя страница то размер хвоста
							if ((end>0)&&(ucCurrOscPage >= (start+sz)))
							{
								ucCurrOscSizeOnPage = end;
							}

							//AddToQueueMB(Rd_OscNoteQueue, MB_Wrt_OscMessageAdrPg	,MB_Slaveaddr);			// cтавим страницу  ModbusSentQueue
							//AddToQueueMB(Rd_OscNoteQueue, MB_Rd_OscMessage		,MB_Slaveaddr);
						} else{
							AddToQueueMB_FS(_OneOscTmp,(uint8_t*)ucOscBlockBuf,(uint16_t)ucCurrOscSizeOnPage*2,FA_OPEN_APPEND | FA_WRITE, NULL, NULL);
						}
					}

				}else{
					USART_TRACE_RED("%.4d-%.4d. ошибка блока осциллограммы.(0x%X)\n",MemForSave-usOscBlockStart,MemForSave-usOscBlockStart+SizeAnswer,MemForSave);
				}
			}
#endif
//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------

            if( eRegStatus != MB_ENOERR )
            {
                eStatus = prveMBError2Exception( eRegStatus );
        		USART_TRACE_RED("eRegStatus:%u\n",eRegStatus);

            }
        }
        else
        {
            //if( ( usRegCount >= 1 ) && ( 2 * usRegCount == pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF] ) )

    		USART_TRACE_RED("MB_EX_ILLEGAL_DATA_VALUE: размер IN:%u OUT:%u\n",2*usRegCount,pucFrame[MB_PDU_FUNC_READ_BYTECNT_OFF]);
            eStatus = MB_EX_ILLEGAL_DATA_VALUE;
        }
    }
    else
    {
        /* Can't be a valid request because the length is incorrect. */
		USART_TRACE_RED("MB_EX_ILLEGAL_DATA_VALUE: мал размер сообщения %u\n",*usLen);

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
/**
 * функция передачи в модбас абсолютно любых данных.
 * SendBuff	: буфер для передачи
 * size		: размер всей части запроса. Нужно откинуть заголовок TCP/MODBUS
 * lTimeOut	: ждать ответа или нет
 *
 * нужно из самого пакета взять Команду, найти размер ожидаемого ответа, и указать приёмнику сколько будет данных
 */
eMBMasterReqErrCode		eMBMasterSendAnyMessage(UCHAR ucSndAddr, UCHAR *SendBuff, uint16_t	sizeBuf, LONG lTimeOut )
{
    UCHAR           *ucMBFrame;
    uint16_t			SizeAnswer;
    uint16_t		SizeData;

    uint16_t		usNRegs;// = SendBuff[MB_PDU_REQ_READ_SIZE];
    uint16_t		usRegAddr = 0;												// адрес регистра в памяти устройства. пока не исползую

    eMBMasterReqErrCode    eErrStatus = MB_MRE_NO_ERR;


    if ( ucSndAddr > MB_MASTER_TOTAL_SLAVE_NUM ) 			eErrStatus = MB_MRE_ILL_ARG;
    else if ( xMBMasterRunResTake( lTimeOut ) == FALSE ) 	eErrStatus = MB_MRE_MASTER_BUSY;
    else
    {
    	vMBMasterGetPDUSndBuf(&ucMBFrame);
    	// нужно откинуть заголовок TCP/MODBUS и отнять размер
		memcpy(ucMBFrame,SendBuff+MB_SIZE_TCPMB_FRAME,sizeBuf-MB_SIZE_TCPMB_FRAME);

// определим размер ответа
		switch (ucMBFrame[0]){
		case	1:
		case	2:
			usNRegs = (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF]<<8;
			usNRegs += (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1];
			SizeData = usNRegs/8;													// размер полезных данных в байтах
			if(usNRegs%8>0) SizeData++;
			SizeAnswer = SizeAddr+SizeFunct+SizeNumbWord+SizeData+SizeCRC;			// ожидаемый размер ответа

			break;
		case	3:
		case	4:
			usNRegs = (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF]<<8;
			usNRegs += (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1];
			SizeData = usNRegs << 1;												// размер полезных данных в байтах
			SizeAnswer = SizeAddr+SizeFunct+SizeNumbWord+SizeData+SizeCRC;			// ожидаемый размер ответа
			break;
		case	5:
		case	6:
		case	15:
		case	16:
			SizeData = 2;
			SizeAnswer = SizeAddr+SizeFunct+SizeNumbWord+SizeData+SizeCRC;
			break;
		}
// -------------------------

		vMBMasterSetDestAddress(ucSndAddr);										// адрес для отправки

		vMBMasterSetPDUSndLength( sizeBuf-MB_SIZE_TCPMB_FRAME );				// размер пакета для отправки
		xModbus_Set_SizeAnswer(SizeAnswer,usRegAddr);
		( void ) xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );
		eErrStatus = eMBMasterWaitRequestFinish( );
    }
    return eErrStatus;
}
/**
 * функция передачи в TCP Modbus ответов.
 * pucFrame	: буфер для передачи
 * usLen	: размер всей части запроса. Нужно откинуть заголовок TCP/MODBUS
 */

eMBException		eMBTCPPackResponse( UCHAR * pucFrame, USHORT * usLen )
{
	USHORT	Sz;
    eMBMasterReqErrCode    eErrStatus = MB_MRE_NO_ERR;

    Sz = *usLen + 1;
    pucFrame[4] = (UCHAR)(Sz>>8);
    pucFrame[5] = (UCHAR)(Sz&0xFF);

    *usLen += 7;

/*
    Sz = ((USHORT)pucFrame[10]*2) + 2;
    pucFrame[4] = (UCHAR)(Sz>>8);
    pucFrame[5] = (UCHAR)(Sz&0xFF);
*/

    return eErrStatus;
}
#endif


