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

#if MB_MASTER_RTU_ENABLED > 0
/* ----------------------- Defines ------------------------------------------*/
#define MB_SER_PDU_SIZE_MIN     4       /*!< Minimum size of a Modbus RTU frame. */
#define MB_SER_PDU_SIZE_MAX     256     /*!< Maximum size of a Modbus RTU frame. */
#define MB_SER_PDU_SIZE_CRC     2       /*!< Size of CRC field in PDU. */
#define MB_SER_PDU_ADDR_OFF     0       /*!< Offset of slave address in Ser-PDU. */
#define MB_SER_PDU_PDU_OFF      1       /*!< Offset of Modbus-PDU in Ser-PDU. */

/* ----------------------- Type definitions ---------------------------------*/
typedef enum
{
    STATE_M_RX_INIT,              /*!< Приемник в режиме инициализации. */
    STATE_M_RX_IDLE,              /*!< Приемник находится в состоянии ожидания. */
    STATE_M_RX_RCV,               /*!< Фрейм принят. */
    STATE_M_RX_ERROR,              /*!< Неверный фрейм. */
} eMBMasterRcvState;

typedef enum
{
    STATE_M_TX_IDLE,              /*!< Передатчик находится в состоянии ожидания. */
    STATE_M_TX_XMIT,              /*!< Передатчик находится в режиме передачи. */
    STATE_M_TX_XFWR,              /*!< Передатчик закончил передачу и ожидает режима приема. */
} eMBMasterSndState;

/* ----------------------- Static variables ---------------------------------*/
static volatile eMBMasterSndState eSndState;
static volatile eMBMasterRcvState eRcvState;

static volatile UCHAR  ucMasterRTUSndBuf[MB_PDU_SIZE_MAX];				// буфер для передачи в MODBUS
static volatile UCHAR  ucMasterRTURcvBuf[MB_SER_PDU_SIZE_MAX];			// буфер для приёма из MODBUS
static volatile USHORT usMasterSendPDULength;							// длина фрейма готового для передачи

static volatile UCHAR *pucMasterSndBufferCur;
static volatile USHORT usMasterSndBufferCount;

static volatile USHORT usMasterRcvBufferPos;
static volatile BOOL   xFrameIsBroadcast = FALSE;						// признак широковешательного пакета

static volatile eMBMasterTimerMode eMasterCurTimerMode;

/* ----------------------- Start implementation -----------------------------*/
eMBErrorCode
eMBMasterRTUInit(UCHAR ucPort, ULONG ulBaudRate, eMBParity eParity )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    ULONG           usTimerT35_50us;

    ENTER_CRITICAL_SECTION(  );

    // инит USART порта 8бит режиме для MODBUS
    if( xMBMasterPortSerialInit( ucPort, ulBaudRate, 8, eParity ) != TRUE )
    {
        eStatus = MB_EPORTERR;
    }
    else
    {
    	// если скорость выше 19200 то используем фиксированную t3.5 = 1750us
        if( ulBaudRate > 19200 )
        {
            usTimerT35_50us = 35;       /* 1800us. */
        }
        else
        {
            /* The timer reload value for a character is given by:
             *
             * ChTimeValue = Ticks_per_1s / ( Baudrate / 11 )
             *             = 11 * Ticks_per_1s / Baudrate
             *             = 220000 / Baudrate
             * The reload for t3.5 is 1.5 times this value and similary
             * for t3.5.
             */
            usTimerT35_50us = ( 7UL * 220000UL ) / ( 2UL * ulBaudRate );
        }
        // инит таймера тля отсчета t3.5
        if( xMBMasterPortTimersInit( ( USHORT ) usTimerT35_50us ) != TRUE )
        {
            eStatus = MB_EPORTERR;
        }
    }
    EXIT_CRITICAL_SECTION(  );

    return eStatus;
}

/*************************************************************************
 * eMBMasterRTUStart
 * Изначально приемник в состоянии STATE_M_RX_INIT. Запускаем таймер на t3.5
 * Если символ не получен, то переводим приемник в STATE_M_RX_IDLE.
 * гарантировано пока не увидим начало фрейма(t3.5) не примем никакого мусора.
 *************************************************************************/
void
eMBMasterRTUStart( void )
{
    ENTER_CRITICAL_SECTION(  );

    eRcvState = STATE_M_RX_INIT;
 //   vMBMasterPortSerialEnable( TRUE, FALSE );			// Режим приёма
    vMBMasterPortTimersT35Enable(  );					// Старт таймера t3.5 символа

    EXIT_CRITICAL_SECTION(  );
}
/*************************************************************************
 * eMBMasterRTUStop
 * Остановка и выключение приёма и передачи MODBUS с сотановкой таймера.
 *************************************************************************/
void
eMBMasterRTUStop( void )
{
    ENTER_CRITICAL_SECTION(  );
    vMBMasterPortSerialEnable( FALSE, FALSE );
    vMBMasterPortTimersDisable(  );
    EXIT_CRITICAL_SECTION(  );
}
/*************************************************************************
 * eMBMasterRTUReceive
 * Функция приёма данных и проверка их целосности.
 *************************************************************************/
eMBErrorCode
eMBMasterRTUReceive( UCHAR * pucRcvAddress, UCHAR ** pucFrame, USHORT * pusLength )
{
    eMBErrorCode    eStatus = MB_ENOERR;

    ENTER_CRITICAL_SECTION(  );
    assert_param( usMasterRcvBufferPos < MB_SER_PDU_SIZE_MAX );

    // Проверка длинны пакета и его CRC
    if( ( usMasterRcvBufferPos >= MB_SER_PDU_SIZE_MIN )
        && ( usMBCRC16( ( UCHAR * ) ucMasterRTURcvBuf, usMasterRcvBufferPos ) == 0 ) )
    {
        // Save the address field. All frames are passed to the upper layed and the decision if a frame is used is done there.
        *pucRcvAddress = ucMasterRTURcvBuf[MB_SER_PDU_ADDR_OFF];

        // Общая длина данных(Modbus-PDU) без поля адреса и CRC.
        *pusLength = ( USHORT )( usMasterRcvBufferPos - MB_SER_PDU_PDU_OFF - MB_SER_PDU_SIZE_CRC );

        // Адрес начала данных(Modbus-PDU)
        *pucFrame = ( UCHAR * ) & ucMasterRTURcvBuf[MB_SER_PDU_PDU_OFF];
    }
    else
    {
        eStatus = MB_EIO;
    }

    EXIT_CRITICAL_SECTION(  );
    return eStatus;
}
/*************************************************************************
 * eMBMasterRTUSend
 * отправка пакета в MODBUS
 *************************************************************************/
eMBErrorCode
eMBMasterRTUSend( UCHAR ucSlaveAddress, const UCHAR * pucFrame, USHORT usLength )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    USHORT          usCRC16;

    if ( ucSlaveAddress > MB_MASTER_TOTAL_SLAVE_NUM ) return MB_EINVAL;

    ENTER_CRITICAL_SECTION(  );

    // Если приемник в режиме ожидания.
    if( eRcvState == STATE_M_RX_IDLE && eSndState == STATE_M_TX_IDLE)		//&& eSndState == STATE_M_TX_IDLE добавил т.к. возможна передача до таймаута ответа
    {
        // Первый байт  до PDU это slave address.
        pucMasterSndBufferCur = ( UCHAR * ) pucFrame - 1;
        usMasterSndBufferCount = 1;

        // Добавляем к пакету SlaveAddress
        pucMasterSndBufferCur[MB_SER_PDU_ADDR_OFF] = ucSlaveAddress;
        usMasterSndBufferCount += usLength;

        // считаем CRC16
        usCRC16 = usMBCRC16( ( UCHAR * ) pucMasterSndBufferCur, usMasterSndBufferCount );
        ucMasterRTUSndBuf[usMasterSndBufferCount++] = ( UCHAR )( usCRC16 & 0xFF );
        ucMasterRTUSndBuf[usMasterSndBufferCount++] = ( UCHAR )( usCRC16 >> 8 );

        // Режим предачи.
        eSndState = STATE_M_TX_XMIT;
        xMBMasterPortSerialPutBUF(( CHAR *)pucMasterSndBufferCur,usMasterSndBufferCount);						// передадим в порт весь блок сразу
        xFrameIsBroadcast = ( ucMasterRTUSndBuf[MB_SER_PDU_ADDR_OFF] == MB_ADDRESS_BROADCAST ) ? TRUE : FALSE;	// определяем широковещательный ли ?

    }
    else
    {
        eStatus = MB_EIO;					// I/O ошибка.
    }
    EXIT_CRITICAL_SECTION(  );
    return eStatus;
}
/*************************************************************************
 * xMBMasterRTUReceiveFSM
 * приёмник Фрейма
 *************************************************************************/
BOOL
xMBMasterRTUReceiveFSM( void )
{
    BOOL            xTaskNeedSwitch = FALSE;
    UCHAR           ucByte;

	Port_Off(LED3);

    // чтение CHAR из порта.
    //( void )xMBMasterPortSerialGetByte( ( CHAR * ) & ucByte );
    xModbus_Get_SizeAnswer((uint8_t *) &usMasterRcvBufferPos);

    // переложили в рабочий буфер из приёмника
    for (ucByte = 0;ucByte < usMasterRcvBufferPos;ucByte++){
    	( void )xMBMasterPortSerialGetBuf(ucByte, ( CHAR * ) & ucMasterRTURcvBuf[ucByte]);
    }

    switch ( eRcvState )
    {

    case STATE_M_RX_INIT:							// Если получили фрейм в состоянии инициализации порта, то нужно ждать конца фрейма.
    	// Используя DMA с настроеным размером такой ситуации не может возникнуть.
    	vMBMasterPortTimersT35Enable( );
        break;
    case STATE_M_RX_ERROR:							// В состоянии ошибки приема ждем пока весь мусор не передастся.
    	vMBMasterPortTimersT35Enable( );
        break;

    case STATE_M_RX_IDLE:
    	eSndState = STATE_M_TX_IDLE;
        if(usMasterRcvBufferPos < MB_SER_PDU_SIZE_MAX )	eRcvState = STATE_M_RX_RCV;			// приняли фрейм.
        else    										eRcvState = STATE_M_RX_ERROR;		// Если символов больше чем макс. возможный размер фрейма, то ошибка фрейма.

        break;

    }
    return xTaskNeedSwitch;
}
/*************************************************************************
 * xMBMasterRTUTransmitFSM
 * обработчик прерывания по окончанию передачи фрейма
 *************************************************************************/
BOOL
xMBMasterRTUTransmitFSM( void )
{
    BOOL            xNeedPoll = FALSE;

    assert_param( eRcvState == STATE_M_RX_IDLE );

    switch ( eSndState )
    {

    case STATE_M_TX_XMIT:												// Передатчик находится в режиме передачи.
		eSndState = STATE_M_TX_XFWR;									// Передатчик закончил передачу.
		xNeedPoll = TRUE;

 		// тут только запуск таймера
		if ( xFrameIsBroadcast == TRUE )
				vMBMasterPortTimersConvertDelayEnable( );				// Таймаут для широковещательного пакета.
		else   	vMBMasterPortTimersRespondTimeoutEnable( );				// Таймаут для не широковещательного пакета.

        break;

// эти состояния не могут возникнуть. Прерывания возникают только в режиме STATE_M_TX_XMIT
    case STATE_M_TX_IDLE:  												// состояние ожидания.
    		// если нужно то переводим в режим приёма (для управляемых RS485)
        break;
    case   STATE_M_TX_XFWR:
        break;
    }

    return xNeedPoll;
}
/*************************************************************************
 * xMBMasterRTUTimerExpired
 * обработчик таймаутов таймера
 *************************************************************************/
BOOL
xMBMasterRTUTimerExpired(void)
{
	BOOL xNeedPoll = FALSE;

	// Прием
	switch (eRcvState)
	{
	case STATE_M_RX_INIT:												// Время t3.5 истекло. Начало финишной фазы.
		xNeedPoll = xMBMasterPortEventPost(EV_MASTER_READY);			// Startup закончен. MASTER готов к работе.
		break;
	case STATE_M_RX_IDLE:												// фрейм не получили а таймаут отработал.
		if (eSndState == STATE_M_TX_XFWR)
			vMBMODBUSPortRxDisable();
		eRcvState = STATE_M_RX_IDLE;
		break;
	case STATE_M_RX_RCV:												// Был получен фрейм и таймаут t3.5 истек. Сообщаем слушателю, что был получен новый фрейм .
		xNeedPoll = xMBMasterPortEventPost(EV_MASTER_FRAME_RECEIVED);	// фрейм принят.
		break;

	case STATE_M_RX_ERROR:												// Ошибка при получении фрейма.
		vMBMasterSetErrorType(EV_ERROR_RECEIVE_DATA);
		xNeedPoll = xMBMasterPortEventPost( EV_MASTER_ERROR_PROCESS );	// Ошибка при получении фрейма.EV_MASTER_ERROR_PROCESS
		break;

	default:															// Несуществующее состояние функции.
		assert_param(
				( eRcvState == STATE_M_RX_INIT ) || ( eRcvState == STATE_M_RX_RCV ) ||
				( eRcvState == STATE_M_RX_ERROR ) || ( eRcvState == STATE_M_RX_IDLE ));
		break;
	}
	eRcvState = STATE_M_RX_IDLE;

	// Передача
	switch (eSndState)
	{
	case STATE_M_TX_XFWR:												//  Передатчик закончил передачу. Если фрейм не пришел в течении времени ожидания сообщаем об ошибке.
		if ( xFrameIsBroadcast == FALSE ) {
			vMBMasterSetErrorType(EV_ERROR_RESPOND_TIMEOUT);
			xNeedPoll = xMBMasterPortEventPost(EV_MASTER_ERROR_PROCESS);
		}
		break;
	default:															// Несуществующее состояние функции.
		assert_param(
				( eSndState == STATE_M_TX_XFWR ) || ( eSndState == STATE_M_TX_IDLE ));
		break;
	}
	eSndState = STATE_M_TX_IDLE;


	vMBMasterPortTimersDisable( );										// Останавливаем таймер.
	/* If timer mode is convert delay, the master event then turns EV_MASTER_EXECUTE status. */
	if (eMasterCurTimerMode == MB_TMODE_CONVERT_DELAY) {
		xNeedPoll = xMBMasterPortEventPost( EV_MASTER_EXECUTE );
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

/* The master request is broadcast? */
BOOL xMBMasterRequestIsBroadcast( void ){
	return xFrameIsBroadcast;
}
#endif

