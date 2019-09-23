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

// очереди -----------------------------
extern	xQueueHandle 	ModbusSentTime;			// очередь для отправки срочных сообщений модбас
extern	xQueueHandle 	ModbusSentQueue;		// очередь для отправки в модбас
extern	xQueueHandle 	ModbusSentQueueFromTCPMB;		// очередь запросов из TCP/MB
//extern	xQueueHandle 	ModbusResponseQueue;	// очередь для ожидания ответов
extern	xQueueHandle 	Rd_SysNoteQueue;		// очередь для запросов журналу системы
extern	xQueueHandle 	Rd_ErrorNoteQueue;		// очередь для запросов журналу аварий
extern	xQueueHandle 	Rd_OscNoteQueue;		// очередь для запросов журналу осциллографа
extern	xQueueHandle 	Rd_FileQueue;			// очередь для запросов файлов
//extern	xQueueHandle 	Rd_UstavkiQueue;		// очередь для запросов уставок
extern	xQueueHandle	Wr_GooseQueue;			// очередь гусов
extern	xQueueHandle	xDebugUsartOut;			// очередь для отправки в юсартдебаг

extern TIM_HandleTypeDef   TimHandle;	// Timer handler declaration для таймаутов MODBUS


extern	errMB_data	cntErrorMD;
extern  uint32_t	cntMBmessage;					// счетчик пакетов с MB.

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

// --------------------- Исполнители MODBUS функций --------------------------
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
    {MB_FUNC_READ_HOLDING_REGISTER, eMBMasterFuncReadRegisters},							// чнение блоком памяти из устройства
#endif
#if MB_FUNC_READ_HOLDING_W_ADDR_ENABLED > 0
    {MB_FUNC_READ_HOLDING_REGISTER_W_ADDR, eMBMasterFuncReadRegisters},						// чнение блоком памяти из устройства
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
		pvMBMasterFrameStartCur = eMBMasterRTUStart;								// Ожидание при старте t3.5 символа чтобы не ловить мусор при старте.
		pvMBMasterFrameStopCur = eMBMasterRTUStop;									// Остановка интерфейса MODBUS.
		peMBMasterFrameSendCur = eMBMasterRTUSend;									// Отправка пакета в MODBUS.
		peMBMasterFrameReceiveCur = eMBMasterRTUReceive;							// Функция проверки целосности принятых данных.
		pvMBMasterFrameCloseCur = MB_PORT_HAS_CLOSE ? vMBMasterPortClose : NULL;	// NULL
		pxMBMasterFrameCBByteReceived = xMBMasterRTUReceiveFSM;						// Функция приёма данных из MODBUS.
		pxMBMasterFrameCBTransmitterEmpty = xMBMasterRTUTransmitFSM;				// Функция окончания передачи Фрейма.
		pxMBMasterPortCBTimerExpired = xMBMasterRTUTimerExpired;					// Обработчик таймаутов таймера
		pxMBMasterPortCBStartIdle = xMBMasterRTUStartIdle;							// Обработчик окончания приёма, или пауз в приёмном потоке

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
 * старт MODBUS
 *************************************************************************/
eMBErrorCode
eMBMasterEnable( void )
{
    eMBErrorCode    eStatus = MB_ENOERR;

    if( eMBState == STATE_DISABLED )
    {
        pvMBMasterFrameStartCur(  );			// стартуем MODBUS в режим приёма.
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
 * стоп MODBUS
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
 * функция обрабатывает события в хранилище xMasterOsEvent до конца.
 *
 * повторная отправка если была ошибка получения ответа
 * при повторной отправке выходит из функции. Есть вероятность что данные для отправки будут изменены.
 *
 * если состояние eMBMasterEventType == EV_MASTER_FRAME_RECEIVE_WAIT нужно проверить режим таймера таймаута
 * если таймер не запущен или остановлен то ВИСЯК. нужно перезапустить таймер или разрешить отправку следующего запроса
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


    if( eMBState != STATE_ENABLED )        return MB_EILLSTATE;	 	// проверим, готов ли модбас для работы

restart:

    // будем отрабатывать все события пока не опустошим
    while(xMBMasterPortEventGet( &eEvent ) == TRUE)
    {
        switch ( eEvent )
        {
/*********************************************************************************
 * закончили инициализацию Модбас
 *********************************************************************************/
		case EV_MASTER_READY:
			break;
/*********************************************************************************
 * ждём ответа от клиента
 *********************************************************************************/
        case EV_MASTER_FRAME_RECEIVE_WAIT:
        	if (vMBMasterGetCurTimerMode()== MB_TMODE_STOP){
				xMBMasterPortEventClear(EV_MASTER_FRAME_RECEIVE_WAIT);
        	}
			break;
/*********************************************************************************
 * проверка принятых данных на целостность
 * принимаем все адреса устройств.
 *********************************************************************************/
        case EV_MASTER_FRAME_RECEIVED:															// Приняли фрейм, проверим на целостность и обработаем

			// для TCP/Modbus нужна отдельная функция обработки. И соответственно не лазим по списку функций
// ---------------------------------------------------
// запрос TCP modbus
			if (SendRequestWithWait == eMBTCPGetState())
			{
				eMBTCPSetState(Stopped);
	    		  // нужно переписать принятые данные минуя заголовок TCP/Modbus
	    		  xMBTCPPortGetBuff(&ucMBTCPFrame, &usTCPLength);
	    		  // теперь копируем по адресу ucMBFrame размером не важно
	    		  eStatus = peMBMasterFrameReceiveCur( &ucRcvAddress, &ucMBFrame, usTCPLength );		// получили параметры пакета. Address, Length, Frame
	    		  if ((eStatus == MB_ERECV )&&(*usTCPLength < MB_TCP_BUF_SIZE)){

		    	    memcpy(ucMBTCPFrame,ucMBFrame,*usTCPLength);
	            	eStatus = MB_ENOERR;			// так как EXECUTE не вызываем снимем статус, иначе вернётся из функции с указанием ошибки

	    		  } else{
						USART_TRACE_RED("EV_MASTER_FRAME_RECEIVED - %u\n",eStatus);
						vMBMasterSetErrorType( EV_ERROR_RECEIVE_DATA);
						xMBMasterPortEventPost( EV_MASTER_ERROR_PROCESS );

						if (  eStatus == MB_CRCERR_Rx ) 	cntErrorMD.errALLCRC++;
	    		  }

	              ( void )xMBPortEventPost( EV_TCPMB_EXECUTE );									// переводим в режим отправки ответа

			}else{
// ---------------------------------------------------
// обычный режим работы
			eStatus = peMBMasterFrameReceiveCur( &ucRcvAddress, &ucMBFrame, &usLength );			// получили параметры пакета. Address, Length, Frame

				if ( eStatus == MB_ERECV  )
				{
					cntMBmessage++; 																// подсчитаем число ответов
					xMBMasterPortEventPost( EV_MASTER_EXECUTE );									// если нам, то переходим к дальнейшей работе с данными.
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
 * обработка принятых данных
 * переложим его в нужные буфера.
 *********************************************************************************/
        case EV_MASTER_EXECUTE:
        	ucFunctionCode = ucMBFrame[MB_PDU_FUNC_OFF];										// берём из принятых данных код функции
            eException = MB_EX_ILLEGAL_FUNCTION;

            if(ucFunctionCode >> 7) {															// Старший бит указывает на ответ об ошибке.
            	eException = (eMBException)ucMBFrame[MB_PDU_DATA_OFF];
            }
			else																				// нормальный пакет принят.
			{
// ----------------------------------------------------------------------------
// функции обработчики команд от слейва
// MASTER MODE
// ----------------------------------------------------------------------------
				if (ucRcvAddress == MB_SlaveAddres){
					for (i = 0; i < MB_FUNC_HANDLERS_MAX; i++)										// ищем функцию обработчик
					{
						if (xMasterFuncHandlers[i].ucFunctionCode == 0)		break;					// дальше нет обработчиков функций, выходим из поиска обработчика.
						else if (xMasterFuncHandlers[i].ucFunctionCode == ucFunctionCode)
						{
							eException = xMasterFuncHandlers[i].pxHandler(ucMBFrame, &usLength);	// обработчик для конкретной функции.
							break;
						}
					}
				}
// ----------------------------------------------------------------------------
// функции обработчики команд от мастера
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
					// тут нужно мастеру отправить подтверждение приёма. или ответ с ошибкой если нет команды, адреса, обработчика
					// скорее всего ставить в начало очереди срочных.
				}
// ----------------------------------------------------------------------------
// !!
// ----------------------------------------------------------------------------
			}
            // выставим ошибку:
            // 1 - Если нет обработчика команды.
            // 2 - Если пришел ответ с информацией об ошибке.
            if (eException != MB_EX_NONE) {
            	vMBMasterSetErrorType(EV_ERROR_EXECUTE_FUNCTION);
            	xMBMasterPortEventPost( EV_MASTER_ERROR_PROCESS );
            }
            else {
            // если успешно обработали
            	eStatus = MB_ENOERR;
            	vMBMasterCBRequestScuuess();
            	//eStatus = MB_ERECVDATA;
            }
            break;
/*********************************************************************************
 * отправка подготовленных данных (ucMasterRTUSndBuf)
 * если удачно, то выставляем событие ожидания(EV_MASTER_FRAME_RECEIVE_WAIT)
 *********************************************************************************/
        case EV_MASTER_FRAME_SENT:

        	vMBMasterGetPDUSndBuf( &ucMBFrame );
        	{
				uint8_t		reSend = 50;	// попыток отправки. ошибка может только из HAL_UART_Transmit_DMA)
				while(eStatus != MB_ESENT){
					reSend --; if (reSend == 0) break;
					// может быть такая ситуация что данные отправляются в данный момент. Повторная отправка имеет смысл после принятия ответа или таймаута без ответа.
					// -------------------------------------------------------
					uint16_t	Len = usMBMasterGetPDUSndLength();
					uint8_t		adr =  ucMBMasterGetDestAddress();
					if (adr == 0) adr = 1;
					if (Len == 0) {Len = 5;
						USART_0TRACE("fsl:%u|%u|0x%X\n",Len,adr,ucMBFrame);
					}
					eStatus = peMBMasterFrameSendCur( adr, ucMBFrame, Len );
					if (eStatus != MB_ESENT){
						USART_TRACE_RED("MB_EIO_Tx: %u попыток отправки. eStatus:%u\n",50-reSend,eStatus);
						vTaskDelay(1);		// немного подождём
					}
				}
        	}
			if (eStatus == MB_ESENT){
			    // надо перенести в прерывание по окончанию передачи. иначе бывают задержки и запускается когда уже поздно
			    //xMBMasterPortEventPost( EV_MASTER_FRAME_RECEIVE_WAIT );	// ждём окончания отправки
				//vMBMasterPortTimersRespondTimeoutEnable( );				// на случай проблем запустим таймер

			    // сменим статус на MB_ENOERR. выше уровнем пока не нужен статус MB_ESENT. Возможно для очереди ответов он понадобится
			    eStatus = MB_ENOERR;
			}
        	// ошибка отправки пакета. не принят или отправляется предыдущий пакет.
        	if (eStatus == MB_EIO_Tx){
	        	USART_TRACE_RED("MODBUS MB_EIO_Tx\n");
	        	xMBMasterPortEventPost(EV_MASTER_ERROR_PROCESS);		// Серьёзная ошибка отправки. Нужно переинит всего юсарта и дма
            	vMBMasterSetErrorType(EV_ERROR_SENT_DATA);

        	}
             break;
/*********************************************************************************
 * колбэки по ошибкам.
 *
 * 	EV_ERROR_RESPOND_TIMEOUT	- не дождались ответа
 *  EV_ERROR_RECEIVE_DATA		- приняли с ошибкой
 *  EV_ERROR_EXECUTE_FUNCTION	- не удалось переложить принятые данные
 *********************************************************************************/
        case EV_MASTER_ERROR_PROCESS:
			errorType = eMBMasterGetErrorType();			// тип ошибки
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
    // обработали все события. Можно отослать запрос TCP в модбас линию
   	if (WaitPreResponse == eMBTCPGetState())	{
   		eMBTCPSetState(SendRequestWithWait);
   		// нужно вернуться, иначе вывалиться и может запустить иной запрос.
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
// Set Modbus Master send destination address. адрес устройства '1'
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
