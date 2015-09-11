/*
 * modbus.c
 *
 *  Created on: 25.08.2015
 *      Author: sagok
 */

/* ----------------------- FreeRTOS includes --------------------------------*/
#include "FreeRTOS.h"
#include "task.h"

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"
#include "stm32f4xx_it.h"
#include "main.h"
#include "modbus.h"
#include "usart.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbport.h"
#include "mbconfig.h"

/* ----------------------- Defines ------------------------------------------*/
#define MB_UART_DEV             ( UART0 )
#define MB_UART_RX_PORT         ( GPIO0 )
#define MB_UART_RX_PIN          ( 8 )
#define MB_UART_TX_PORT         ( GPIO0 )
#define MB_UART_TX_PIN          ( 9 )
#define MB_UART_IRQ_CH          ( UART0_IRQChannel )
#define MB_UART_TX_QUEUE_LEN    ( 8 )
#define MB_IRQ_PRIORITY         ( 1 )



/*************************************************************************
 * xMBMasterPortSerialInit
 *************************************************************************/
BOOL            xMBMasterPortSerialInit( UCHAR ucPort, ULONG ulBaudRate, UCHAR ucDataBits, eMBParity eParity )
{
    int8_t      		xResult = TRUE;
    uint32_t			eUARTParity = 0;
    uint32_t			eUARTMode;
    uint32_t			eUARTStopBits;
    USART_TypeDef*		UPort = USART1;
    UART_HandleTypeDef 	UARTPORT;

//	  MODBUS_Init(115200);					// настройка MODBUS интерфейса.
//	  USART_TRACE("MODBUS_Init.. ok\n");


	switch ( ucPort )
	{
	case 0:
        xResult = FALSE;
		break;
	case 1:
		UPort = USART1;
		break;
	case 2:
		UPort = USART2;
		break;
	case 3:
		UPort = USART3;
		break;
	case 4:
		UPort = UART4;
		break;
	case 5:
		UPort = UART5;
		break;
    default:
        xResult = FALSE;
        break;
	}

    switch ( eParity )
    {
    case MB_PAR_EVEN:
        eUARTParity = UART_PARITY_EVEN;
        break;
    case MB_PAR_ODD:
        eUARTParity = UART_PARITY_ODD;
        break;
    case MB_PAR_NONE:
        eUARTParity = UART_PARITY_NONE;
        break;
    }

    switch ( ucDataBits )
    {
    case 7:
            /* not supported by our hardware. */
            xResult = FALSE;
        break;
    case 8:
        if( eParity == MB_PAR_NONE )
        {
            eUARTMode = UART_WORDLENGTH_8B;
            eUARTStopBits = UART_STOPBITS_2;
        }
        else
        {
            eUARTMode = UART_WORDLENGTH_8B;
            eUARTStopBits = UART_STOPBITS_1;
        }
        break;
    default:
        xResult = FALSE;
        break;
    }

    if( xResult != FALSE )
    {
    	UARTPORT.Instance = UPort;
    	UARTPORT.Init.BaudRate = ulBaudRate;
    	UARTPORT.Init.WordLength = eUARTMode;
    	UARTPORT.Init.StopBits = eUARTStopBits;
    	UARTPORT.Init.Parity = eUARTParity;
    	UARTPORT.Init.Mode = UART_MODE_TX_RX;
    	UARTPORT.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    	UARTPORT.Init.OverSampling = UART_OVERSAMPLING_16;
		//  HAL_MultiProcessor_Init(&UARTPORT, 0, UART_WAKEUPMETHODE_IDLELINE);
		HAL_UART_Init(&UARTPORT);
    }
    return xResult;
}


/*************************************************************************
 * xMBPortSerialInit
 *************************************************************************/
BOOL            xMBPortTimersInit( USHORT usTimeOut50us )
{
	/*
    rt_timer_init(&timer, "slave timer",
                   timer_timeout_ind, // bind timeout callback function
                   RT_NULL,
                   (50*usTim1Timerout50us)/(1000*1000/RT_TICK_PER_SECOND),
                   RT_TIMER_FLAG_ONE_SHOT); // one shot
                   */

    return TRUE;
}
/*************************************************************************
 * xMBMasterPortTimersInit
 *************************************************************************/
BOOL            xMBMasterPortTimersInit( USHORT usTimeOut50us )
{

    return TRUE;
}
/*************************************************************************
 * vMBMasterPortSerialEnable
 *************************************************************************/
void            vMBMasterPortSerialEnable( BOOL xRxEnable, BOOL xTxEnable )
{

}
/*************************************************************************
 * vMBMasterPortTimersT35Enable
 *************************************************************************/
INLINE void     vMBMasterPortTimersT35Enable( void )
{

}
/*************************************************************************
 * vMBMasterPortTimersDisable
 *************************************************************************/
INLINE void     vMBMasterPortTimersDisable( void )
{

}
/*************************************************************************
 * xMBMasterPortSerialGetByte
 *************************************************************************/
INLINE BOOL     xMBMasterPortSerialGetByte( CHAR * pucByte )
{

    return TRUE;
}
/*************************************************************************
 * xMBMasterPortSerialPutByte
 *************************************************************************/
INLINE BOOL     xMBMasterPortSerialPutByte( CHAR ucByte )
{

}
/*************************************************************************
 * vMBMasterPortTimersConvertDelayEnable
 *************************************************************************/
INLINE void     vMBMasterPortTimersConvertDelayEnable( void )
{

}
/*************************************************************************
 * vMBMasterPortTimersRespondTimeoutEnable
 *************************************************************************/
INLINE void     vMBMasterPortTimersRespondTimeoutEnable( void )
{

}
/*************************************************************************
 * xMBMasterPortEventPost
 *************************************************************************/
BOOL            xMBMasterPortEventPost( eMBMasterEventType eEvent )
{

}
/*************************************************************************
 * xMBMasterPortEventInit
 *************************************************************************/
BOOL            xMBMasterPortEventInit( void )
{

}
/*************************************************************************
 * vMBMasterOsResInit
 *************************************************************************/
void            vMBMasterOsResInit( void )
{

}
/*************************************************************************
 * xMBMasterPortEventGet
 *************************************************************************/
BOOL            xMBMasterPortEventGet(  /*@out@ */ eMBMasterEventType * eEvent )
{

}
/*************************************************************************
 * vMBMasterCBRequestScuuess
 *************************************************************************/
void            vMBMasterCBRequestScuuess( void )
{

}
/*************************************************************************
 * vMBMasterErrorCBExecuteFunction
 *************************************************************************/
void            vMBMasterErrorCBExecuteFunction( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{

}
/*************************************************************************
 * vMBMasterErrorCBRespondTimeout
 *************************************************************************/
void            vMBMasterErrorCBRespondTimeout( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{

}
/*************************************************************************
 * vMBMasterErrorCBReceiveData
 *************************************************************************/
void            vMBMasterErrorCBReceiveData( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{

}
/*************************************************************************
 * vMBMasterRunResRelease
 *************************************************************************/
void            vMBMasterRunResRelease( void )
{

}
/*************************************************************************
 * xMBMasterRunResTake
 *************************************************************************/
BOOL            xMBMasterRunResTake( int32_t time )
{

}
/*************************************************************************
 * eMBMasterWaitRequestFinish
 *************************************************************************/
eMBMasterReqErrCode eMBMasterWaitRequestFinish( void )
{

}
/*************************************************************************
 * vMBPortTimersEnable
 *************************************************************************/
void vMBPortTimersEnable()
{

}
/*************************************************************************
 * vMBPortTimersDisable
 *************************************************************************/
void vMBPortTimersDisable()
{

}

void prvvTIMERExpiredISR(void)
{
    (void) pxMBPortCBTimerExpired();
}


