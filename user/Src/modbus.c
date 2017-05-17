/*
 * modbus.c
 *
 *  Created on: 25.08.2015
 *      Author: sagok
 */

/* ----------------------- FreeRTOS includes --------------------------------*/
/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "timers.h"

#include "cmsis_os.h"


#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"
#include "stm32f4xx_hal_tim.h"
#include "stm32f4xx_it.h"


#include "main.h"
#include "usart.h"

/* ----------------------- IEC 61850 ----------------------------------*/
#include "iec850.h"
#include "iec61850_server.h"
#include "static_model.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbport.h"
#include "mbconfig.h"

#include "mbrtu.h"

#include "modbus.h"

/* ----------------------- flash includes ----------------------------------*/
#include "inflash.h"
#include "ExtSPImem.h"

/* ----------------------- Defines ------------------------------------------*/
#define	RT_TICK_PER_SECOND		20000
/* ----------------------- Variables ----------------------------------------*/
// константы во FLASH
//__attribute__((__section__(".eb0rodata"))) const
extern	uint8_t userConfig[0x7FFC];// = {1,2,3,4,5,6,7,8,9,0};


extern 	RTC_HandleTypeDef hrtc;						// часы

extern UART_HandleTypeDef 	MODBUS;
extern UART_HandleTypeDef 	BOOT_UART;

uint8_t 	Modbus_DataRX[250];						// буфер приёмника Modbus
static volatile uint8_t 	Modbus_SizeRX;			// размер ожидаемого ответа от MODBUS


extern uint16_t	xMasterOsEvent;						// хранилище событий порта MODBUS

static USHORT usT35TimeOut50us;

/* Timer handler declaration */
TIM_HandleTypeDef    TimHandle;



#if defined (MR5_700)
extern uint16_t   usMDiscInStart;			// адрес
extern volatile uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern volatile uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
#endif
#if defined (MR5_600)
extern uint16_t   usMDiscInStart;			// адрес
extern volatile uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern volatile uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
#endif
#if defined (MR5_500)
extern uint16_t   usMDiscInStart;			// адрес
extern volatile uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern volatile uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
#endif
#if defined (MR771)
extern uint16_t   usMDiscInStart;			// адрес
extern volatile uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern volatile uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
#endif
#if defined (MR761) || defined (MR762) || defined (MR763)
extern uint16_t   usMDiscInStart;			// адрес
extern volatile uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern volatile uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
#endif
#if defined (MR801)
extern uint16_t   usMDiscInStart;			// адрес
extern volatile uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern volatile uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
#endif
#if defined (MR901) || defined (MR902)
extern uint16_t   usMDiscInStart;			// адрес
extern volatile uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern volatile uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
#endif

extern osMutexId 	xIEC850StartMutex;		// мьютекс готовности к запуску TCP/IP

/*************************************************************************
 * xMBMasterPortSerialInit
 *************************************************************************/
BOOL	xMBMasterPortSerialInit( UCHAR ucPort, ULONG ulBaudRate, UCHAR ucDataBits, eMBParity eParity )
{
    int8_t      		xResult = TRUE;
    uint32_t			eUARTParity = 0;
    uint32_t			eUARTMode;
    uint32_t			eUARTStopBits;
    USART_TypeDef*		UPort = USART1;


	switch ( ucPort )
	{
		default:    xResult = FALSE;    break;
		case 0:     xResult = FALSE;	break;
		case 1:		UPort = USART1;		break;
		case 2:		UPort = USART2;		break;
		case 3:		UPort = USART3;		break;
		case 4:		UPort = UART4;		break;
		case 5:		UPort = UART5;		break;
	}
    switch ( eParity )
    {
		case MB_PAR_EVEN:       eUARTParity = UART_PARITY_EVEN;      break;
		case MB_PAR_ODD:        eUARTParity = UART_PARITY_ODD;       break;
		case MB_PAR_NONE:       eUARTParity = UART_PARITY_NONE;      break;
    }
    switch ( ucDataBits )
    {
    default:        xResult = FALSE;        break;
    case 7:         xResult = FALSE;        break;
    case 8:
        if( eParity == MB_PAR_NONE )
        {
            eUARTMode = UART_WORDLENGTH_8B;
            eUARTStopBits = UART_STOPBITS_1;//UART_STOPBITS_2
        }
        else
        {
            eUARTMode = UART_WORDLENGTH_8B;
            eUARTStopBits = UART_STOPBITS_1;
        }
        break;
    }

    if( xResult != FALSE )
    {
    	MODBUS.Instance 		= UPort;
    	MODBUS.Init.BaudRate 	= ulBaudRate;
    	MODBUS.Init.WordLength 	= eUARTMode;
    	MODBUS.Init.StopBits 	= eUARTStopBits;
    	MODBUS.Init.Parity 		= eUARTParity;
    	MODBUS.Init.Mode 		= UART_MODE_TX_RX;
    	MODBUS.Init.HwFlowCtl 	= UART_HWCONTROL_NONE;
    	MODBUS.Init.OverSampling = UART_OVERSAMPLING_8;
 		HAL_UART_Init(&MODBUS);

		//HAL_UART_Receive_DMA(&MODBUS, &Modbus_DataRX[0], 6);			// запуск приёма по кольцу в DMA
    }
    return xResult;
}


/*************************************************************************
 * xMBPortTimersInit
 *     since APB1 prescaler is different from 1.
 *     TIM2CLK = 2 * PCLK1
 *     PCLK1 = HCLK / 4
 *     => TIM2CLK = HCLK / 2 = SystemCoreClock /2
 *
 * 	   counter clock at 20 KHz (50 мкс)
 *     Prescaler = (TIM2CLK / TIM2 counter clock) - 1
 *     Prescaler = ((SystemCoreClock /2) /20 KHz) - 1
 *************************************************************************/
BOOL            xMBPortTimersInit( USHORT usTimeOut50us )
{
	uint32_t uwPrescalerValue = (uint32_t) ((SystemCoreClock /2) / RT_TICK_PER_SECOND) - 1;

//	Port_On(LED2);

	TimHandle.Instance 				 = TIM2;
	TimHandle.Init.Period            = ( (uint32_t) usTimeOut50us ) - 1;
	TimHandle.Init.Prescaler         = uwPrescalerValue;//4200 - 1;
	TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;//TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;//TIM_COUNTERMODE_UP;
	TimHandle.Init.RepetitionCounter = 0;
	HAL_TIM_Base_Init(&TimHandle);
//	TimHandle.Instance->SR = 0;
	HAL_TIM_Base_Start_IT(&TimHandle);

return TRUE;
}

/*************************************************************************
 * HAL_TIM_Base_MspInit
 *************************************************************************/
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
  __TIM2_CLK_ENABLE();
  HAL_NVIC_SetPriority(TIM2_IRQn, 2, 1);
  HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

/*************************************************************************
 * xMBMasterPortTimersInit
 *************************************************************************/
BOOL            xMBMasterPortTimersInit( USHORT usTimeOut50us )
{
    /* backup T35 ticks */
    usT35TimeOut50us = usTimeOut50us;
    xMBPortTimersInit(usTimeOut50us);
    return TRUE;
}
/*************************************************************************
 * vMBMasterPortSerialEnable
 * Активация передачи и приёма в порт
 *************************************************************************/
//TODO: сделать переключение направления ПРИЕМ-ПЕРЕДАЧА. сигнал DE
void            vMBMasterPortSerialEnable( BOOL xRxEnable, BOOL xTxEnable )
{
	if( xRxEnable ){ }
	else  { }
	if ( xTxEnable ){ }
	else{}

}
/*************************************************************************
 * vMBMODBUSPortRxDisable
 * UART4_DMA_RX_IRQn
 *************************************************************************/
void     vMBMODBUSPortRxDisable( void )
{
	HAL_UART_DMAStop(&MODBUS);
}
/*************************************************************************
 * vMBMasterPortTimersT35Enable
 *************************************************************************/
void     vMBMasterPortTimersT35Enable( void )
{
//	 Port_On(LED2);
     vMBMasterSetCurTimerMode(MB_TMODE_T35);
     xMBPortTimersInit( (50 * usT35TimeOut50us) / (1000 * 1000 / RT_TICK_PER_SECOND) );
}
/*************************************************************************
 * vMBMasterPortTimersDisable
 *************************************************************************/
void     vMBMasterPortTimersDisable( void )
{
	HAL_TIM_Base_Stop_IT(&TimHandle);
}
/*************************************************************************
 * xMBMasterPortSerialGetBuf
 *************************************************************************/
BOOL     xMBMasterPortSerialGetBuf(UCHAR pos, CHAR * pucByte )
{
	*pucByte = Modbus_DataRX[pos];
	//HAL_UART_Receive(&MODBUS,(uint8_t *) pucByte, 1, 0xFFFF);
	//*pucByte = (CHAR) USART_ReceiveData( UART4 );
    return TRUE;
}
/*************************************************************************
 * xMBMasterPortSerialGetByte
 *************************************************************************/
BOOL     xMBMasterPortSerialGetByte( CHAR * pucByte )
{
	*pucByte = Modbus_DataRX[0];
	//HAL_UART_Receive(&MODBUS,(uint8_t *) pucByte, 1, 0xFFFF);
	//*pucByte = (CHAR) USART_ReceiveData( UART4 );
    return TRUE;
}
/*************************************************************************
 * xMBMasterPortSerialPutByte
 *************************************************************************/
BOOL     xMBMasterPortSerialPutByte( CHAR ucByte )
{
	HAL_UART_Transmit(&MODBUS, (uint8_t *)&ucByte, 1, 0xFFFF);
	//USART_SendData( UART4, (uint16_t) ucByte );
    return TRUE;
}
/*************************************************************************
 * xMBMasterPortSerialPutBUF
 *************************************************************************/
BOOL     xMBMasterPortSerialPutBUF( CHAR * putBuf, USHORT leng )
{
	if (HAL_UART_Transmit_DMA(&MODBUS, (uint8_t *)putBuf, leng) == HAL_OK){
		//USART_TRACE_RED("Transmit OK.\n");
			return TRUE;
	}
	else	return FALSE;
}
/*************************************************************************
 * vMBMasterPortTimersConvertDelayEnable
 * Таймаут для широковещательного пакета.
 * тут только инит и запуск таймера.
 *************************************************************************/
void     vMBMasterPortTimersConvertDelayEnable( void )
{
//	Port_On(LED2);
    vMBMasterSetCurTimerMode(MB_TMODE_CONVERT_DELAY);
    xMBPortTimersInit(MB_MASTER_DELAY_MS_CONVERT * RT_TICK_PER_SECOND / 1000);
}
/*************************************************************************
 * vMBMasterPortTimersRespondTimeoutEnable
 * Таймаут для не широковещательного пакета. Время ожидания Slave ответа
 * тут только инит и запуск таймера.
 *************************************************************************/
void     vMBMasterPortTimersRespondTimeoutEnable( void )
{
//	Port_On(LED2);
    vMBMasterSetCurTimerMode(MB_TMODE_RESPOND_TIMEOUT);
    xMBPortTimersInit(MB_MASTER_TIMEOUT_MS_RESPOND * RT_TICK_PER_SECOND / 1000);
}
/*************************************************************************
 * xModbus_Set_Size
 * передача размера  ответа от слейва
 *************************************************************************/
BOOL            xModbus_Set_SizeAnswer( uint8_t Size )
{
	if (!Size) return FALSE;
	Modbus_SizeRX = Size;
	return TRUE;
}
/*************************************************************************
 * xModbus_Get_Size
 * передача размера  ответа от слейва
 *************************************************************************/
BOOL            xModbus_Get_SizeAnswer( uint8_t * Size )
{
	*Size = Modbus_SizeRX;
	return TRUE;
}
/*************************************************************************
 * xMBMasterPortEventPost
 * передача события в объект события. Попробуем мспользовать семафор
 *************************************************************************/
BOOL            xMBMasterPortEventPost( eMBMasterEventType eEvent )
{
	xMasterOsEvent |= eEvent;
 //   rt_event_send(&xMasterOsEvent, eEvent);									// передача события в объект событий xMasterOsEvent
    return TRUE;
}
/*************************************************************************
 * xMBMasterPortEventInit
 * инит события и включение контроля над ним.
 *************************************************************************/
BOOL            xMBMasterPortEventInit( void )
{
	xMasterOsEvent = 0;
    return TRUE;
}
/*************************************************************************
 * vMBMasterOsResInit
 * Эта функция будет инициализировать семафор
 * и поставит его под контроль управления ресурсами.
 *************************************************************************/
void            vMBMasterOsResInit( void )
{

}
/*************************************************************************
 * xMBMasterPortEventGet
 * функция будет получать события из объекта события
 *************************************************************************/
BOOL            xMBMasterPortEventGet(  /*@out@ */ eMBMasterEventType * eEvent ){

    uint32_t recvedEvent;
    BOOL	status = FALSE;
    uint32_t set = EV_MASTER_READY | EV_MASTER_FRAME_RECEIVED | EV_MASTER_EXECUTE | EV_MASTER_FRAME_SENT | EV_MASTER_ERROR_PROCESS;

    if (xMasterOsEvent & set)     status = TRUE;

    recvedEvent = xMasterOsEvent;

     xMasterOsEvent &= ~set;

    /* the enum type couldn't convert to int type */
    switch (recvedEvent)
    {
    case EV_MASTER_READY:
        *eEvent = EV_MASTER_READY;
        break;
    case EV_MASTER_FRAME_RECEIVED:
        *eEvent = EV_MASTER_FRAME_RECEIVED;
        break;
    case EV_MASTER_EXECUTE:
        *eEvent = EV_MASTER_EXECUTE;
        break;
    case EV_MASTER_FRAME_SENT:
        *eEvent = EV_MASTER_FRAME_SENT;
        break;
    case EV_MASTER_ERROR_PROCESS:
        *eEvent = EV_MASTER_ERROR_PROCESS;
        break;
    }
    return status;
}
/*************************************************************************
 * vMBMasterCBRequestScuuess
 * функции будут блокировать Modbus Master опрос, а выполнить OS ожидания.
 *************************************************************************/
void            vMBMasterCBRequestScuuess( void )
{

}
/*************************************************************************
 * vMBMasterErrorCBExecuteFunction
 *************************************************************************/
void            vMBMasterErrorCBExecuteFunction( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{
//	eMBMasterRTUStart();
//	xMBMasterPortEventPost( EV_MASTER_READY );
}
/*************************************************************************
 * vMBMasterErrorCBRespondTimeout
 *************************************************************************/
void            vMBMasterErrorCBRespondTimeout( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{
	eMBMasterRTUStart();
	xMBMasterPortEventPost( EV_MASTER_READY );
}
/*************************************************************************
 * vMBMasterErrorCBReceiveData
 *************************************************************************/
void            vMBMasterErrorCBReceiveData( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{
	vMBMODBUSPortRxDisable();
	eMBMasterRTUStart();
	xMBMasterPortEventPost( EV_MASTER_READY );
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
    eMBMasterReqErrCode    eErrStatus = MB_MRE_NO_ERR;
    uint32_t recvedEvent;
    BOOL	status = FALSE;
    uint32_t set = EV_MASTER_PROCESS_SUCESS | EV_MASTER_ERROR_RESPOND_TIMEOUT | EV_MASTER_ERROR_RECEIVE_DATA | EV_MASTER_ERROR_EXECUTE_FUNCTION;

    if (xMasterOsEvent & set)     status = TRUE;

    recvedEvent = xMasterOsEvent;

     xMasterOsEvent &= ~set;

    /*
    // waiting for OS event
    rt_event_recv(&xMasterOsEvent,
            EV_MASTER_PROCESS_SUCESS | EV_MASTER_ERROR_RESPOND_TIMEOUT
                    | EV_MASTER_ERROR_RECEIVE_DATA
                    | EV_MASTER_ERROR_EXECUTE_FUNCTION,
            RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER,
            &recvedEvent);
 */
    switch (recvedEvent)
    {
    case EV_MASTER_PROCESS_SUCESS:
        break;
    case EV_MASTER_ERROR_RESPOND_TIMEOUT:
    {
        eErrStatus = MB_MRE_TIMEDOUT;
        break;
    }
    case EV_MASTER_ERROR_RECEIVE_DATA:
    {
        eErrStatus = MB_MRE_REV_DATA;
        break;
    }
    case EV_MASTER_ERROR_EXECUTE_FUNCTION:
    {
        eErrStatus = MB_MRE_EXE_FUN;
        break;
    }
    }
    return eErrStatus;
}
/*************************************************************************
 * vMBPortTimersEnable
 *************************************************************************/
void vMBPortTimersEnable()
{
	HAL_TIM_Base_Start_IT(&TimHandle);
}
/*************************************************************************
 * vMBPortTimersDisable
 *************************************************************************/
void vMBPortTimersDisable()
{
	HAL_TIM_Base_Stop_IT(&TimHandle);

}

/*************************************************************************
  * @brief  Tx Transfer completed callback
  * @param  huart: UART handle.
  * @retval None
 *************************************************************************/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
	uint8_t		size;

	if (huart == &MODBUS) {

			HAL_UART_DMAStop(huart);									// остановим DMA после передачи фрейма

			HAL_UART_Receive(huart,Modbus_DataRX,1,0);					// вычитаем из порта байт, который после запуска DMA попадал в него и смещал данные в буфере

			// Запускать на приём будем на заранее извесный размер буфера, т.к. в запросе уже есть инфа
			//  флаг готовности будет по заполнению всего пакета. Ответы об ошибках будем анализировать по таймауту
			//  на весь ответ. Размер буфера нужно вычислить в функциях подготовки запросов. Для каждого типа данных.
			Modbus_DataRX[0] = 0;
			Modbus_DataRX[1] = 0;
			xModbus_Get_SizeAnswer((uint8_t *)&size);
			HAL_UART_Receive_DMA(huart, Modbus_DataRX, size);		// запуск приёма  в DMA, укажем размер ожидаемых данных, получим колбэк по заполнению.

			pxMBMasterFrameCBTransmitterEmpty();						// скажем что закончили предачу
	} else
	if (huart == &BOOT_UART) {

		xDEBUGRTUTransmitFSM();
	}

}

/*************************************************************************
 * HAL_TIM_PeriodElapsedCallback
 * Отработали таймаут, после чего принимать уже не надо, пакет потерян. Или принят ответ об ошибке размером 2 байта.
 * перед приёмом они = 0.
 *
 * !!!!!! по таймауту нужно остановить прием. Т.к. уже может начаться приём пакета и сработать таймер
 * до окончания приёма, что вызовет прерываетие по приёму уже после таймера.
 *************************************************************************/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (pxMBMasterPortCBTimerExpired()){			// если изменилось состояние в xMasterOsEvent (хранилище событий порта MODBUS)

	}
}
/*************************************************************************
  * @brief  Rx Transfer completed callback
  * @param  huart: UART handle
  * @retval None
 *************************************************************************/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart == &MODBUS) {						// разблокировка MODBUS таска
		pxMBMasterFrameCBByteReceived();
	}
	if (huart == &BOOT_UART) {					// разблокировка таска по приёму из DEBUGUASRT
		xDEBUGRTUReceiveFSM();
	}
}
/*************************************************************************
  * @brief  Rx Transfer completed callback
  * @param  huart: UART handle
  * @retval None
 *************************************************************************/
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart) {

}
/*************************************************************************
  * @brief  UART error callbacks
  * @param  huart: UART handle
  * @retval None
 *************************************************************************/
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart){

}



/********************************************************************************************************************************
**MBSlave функции ***************************************************************************************************************
*********************************************************************************************************************************/

/*************************************************************************
* eMBRegInputCB - чтение значений из нескольких регистров ввода (0x04 Read Input Registers)
 *************************************************************************/
eMBErrorCode eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs ){

	return MB_ENOREG;
}
/*************************************************************************
* eMBRegHoldingCB - чтение значений из нескольких регистров хранения (0x03 Read Holding Registers)
 *************************************************************************/
eMBErrorCode eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode ){

	return MB_ENOREG;
}
/*************************************************************************
* eMBRegCoilsCB - чтение значений из нескольких регистров флагов (0x01 Read Coil Status)
 *************************************************************************/
eMBErrorCode eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils, eMBRegisterMode eMode ){

	return MB_ENOREG;
}
/*************************************************************************
* eMBRegDiscreteCB - чтение значений из нескольких дискретных входов (0x02 Read Discrete Inputs)
 *************************************************************************/
eMBErrorCode eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete ){

	return MB_ENOREG;
}
/********************************************************************************************************************************
**MBMaster функции **************************************************************************************************************
** см. user_md_app_m
*********************************************************************************************************************************/
/**
 * Modbus master input register callback function.
 *
 * @param pucRegBuffer input register buffer
 * @param usAddress input register address
 * @param usNRegs input register number
 *
 * @return result
 */
eMBErrorCode eMBMasterRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    USHORT          iRegIndex;
    USHORT *        pusRegInputBuf;
    USHORT          REG_INPUT_START;
    USHORT          REG_INPUT_NREGS;
    USHORT          usRegInStart;

    pusRegInputBuf = ucMDiscInBuf[ucMBMasterGetDestAddress() - 1];
    REG_INPUT_START = M_REG_INPUT_START;
    REG_INPUT_NREGS = M_REG_INPUT_NREGS;
    usRegInStart = usMDiscInStart;

    /* it already plus one in modbus function method. */
    usAddress--;

    if ((usAddress >= REG_INPUT_START)
            && (usAddress + usNRegs <= REG_INPUT_START + REG_INPUT_NREGS))
    {
        iRegIndex = usAddress - usRegInStart;
        while (usNRegs > 0)
        {
            pusRegInputBuf[iRegIndex] = *pucRegBuffer++ << 8;
            pusRegInputBuf[iRegIndex] |= *pucRegBuffer++;
            iRegIndex++;
            usNRegs--;
        }
    }
    else
    {
        eStatus = MB_ENOREG;
    }

    return eStatus;
}

/************************************************************************************************
 * Сохраняем принятый данные в буфер базы данных дискретов
************************************************************************************************/
eMBErrorCode eMBMasterToMemDB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, USHORT * pusRegHoldingBuf, USHORT BaseAddress, USHORT BaseNRegs )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    USHORT          iRegIndex;

    usAddress--;

    if ((usAddress >= BaseAddress) && (usAddress + usNRegs <= BaseAddress + BaseNRegs))
    {
        iRegIndex = usAddress - BaseAddress;

        // перепишем данные в хранилище
		while (usNRegs > 0)
		{
			pusRegHoldingBuf[iRegIndex] = *pucRegBuffer++ << 8;
			pusRegHoldingBuf[iRegIndex] |= *pucRegBuffer++;
			iRegIndex++;
			usNRegs--;
		}
    }
    else
    {
        eStatus = MB_ENOREG;
    }
    return eStatus;
}

/**
 * Modbus master coils callback function.
 *
 * @param pucRegBuffer coils buffer
 * @param usAddress coils address
 * @param usNCoils coils number
 * @param eMode read or write
 *
 * @return result
 */
eMBErrorCode eMBMasterRegCoilsCB(UCHAR * pucRegBuffer, USHORT usAddress,  USHORT usNCoils, eMBRegisterMode eMode)
{

}

eMBErrorCode eMBMasterRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode )
{

}
/********************************************************************************************************
 * Чтение базы данных дискрет( callback function)
 * @param pucRegBuffer discrete buffer
 * @param usAddress discrete address
 * @param usNDiscrete discrete number
 * @return result
 *********************************************************************************************************/
eMBErrorCode eMBMasterRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    USHORT          iRegIndex , iRegBitIndex , iNReg;
    UCHAR *         pucDiscreteInputBuf;
    USHORT          DISCRETE_INPUT_START;
    USHORT          DISCRETE_INPUT_NDISCRETES;
    USHORT          usDiscreteInputStart;
    iNReg =  		usNDiscrete / 8 + 1;

    pucDiscreteInputBuf = ucMDiscInBuf[ucMBMasterGetDestAddress() - 1];
    DISCRETE_INPUT_START = M_DISCRETE_INPUT_START;
    DISCRETE_INPUT_NDISCRETES = M_DISCRETE_INPUT_NDISCRETES;
    usDiscreteInputStart = usMDiscInStart;

    /* it already plus one in modbus function method. */
    usAddress--;

    if (/* (usAddress >= DISCRETE_INPUT_START) && */( (usAddress + usNDiscrete )<= (DISCRETE_INPUT_START + DISCRETE_INPUT_NDISCRETES) ) )
    {
        iRegIndex = (USHORT) (usAddress - usDiscreteInputStart) / 8;
        iRegBitIndex = (USHORT) (usAddress - usDiscreteInputStart) % 8;

        /* write current discrete values with new values from the protocol stack. */
        while (iNReg > 1)
        {
            xMBUtilSetBits(&pucDiscreteInputBuf[iRegIndex++], iRegBitIndex, 8, *pucRegBuffer++);
            iNReg--;
        }
        /* last discrete */
        usNDiscrete = usNDiscrete % 8;
        /* xMBUtilSetBits has bug when ucNBits is zero */
        if (usNDiscrete != 0)
        {
            xMBUtilSetBits(&pucDiscreteInputBuf[iRegIndex++], iRegBitIndex, usNDiscrete, *pucRegBuffer++);
        }
    }
    else
    {
        eStatus = MB_ENOREG;
    }

    return eStatus;
}

/********************************************************************************************************
 * Hal_setTimeFromMB_Date
 * установка времени часов из буфера MODBUS
 *********************************************************************************************************/
BOOL	Hal_setTimeFromMB_Date( uint16_t * MDateBuf ){

	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;

	sTime.TimeFormat = RTC_HOURFORMAT_24;
	sTime.Hours =  MDateBuf[3];
	sTime.Minutes =  MDateBuf[4];
	sTime.Seconds =  MDateBuf[5];
	// 	 ms = (1000 - (sTime.SubSeconds * 1000 / hrtc.Init.SynchPrediv));
	sTime.SubSeconds = (1000 - MDateBuf[6]*10) * hrtc.Init.SynchPrediv / 1000;
	//sTime.SubSeconds =  MDateBuf[6] * 1000;
	HAL_RTC_SetTime(&hrtc, &sTime, FORMAT_BIN);

	sDate.Year = MDateBuf[0];
	sDate.Month =  MDateBuf[1];
	sDate.Date =  MDateBuf[2];

	HAL_RTC_SetDate(&hrtc, &sDate, FORMAT_BIN);

	if 		(HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)    HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, 1);		// первое чтение. RTC_BKP_DR0 пишем 1
	else {
		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) + 1);						// если это уже не первый раз, пересинхронизация.
		USART_TRACE_RED("RTC_BKP_DR0: %u\n",HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0));
	}

	return	TRUE;
}
/********************************************************************************************************
 * Hal_setIPFromMB_Date
 * установка IP адреса из буфера MODBUS
 *********************************************************************************************************/
int8_t	Hal_setIPFromMB_Date( uint16_t * MDateBuf ){
extern uint8_t		IP_ADDR[4];


	if (	MDateBuf[0] == 0xffff && MDateBuf[1] == 0xffff)	{
		return	-1;
	}else
	if (	(IP_ADDR[3] == (MDateBuf[0] & 0xFF)) &&
			(IP_ADDR[2] == (MDateBuf[0]>>8 & 0xFF)) &&
			(IP_ADDR[1] == (MDateBuf[1] & 0xFF)) &&
			(IP_ADDR[0] == (MDateBuf[1]>>8 & 0xFF))
			)
	{
		return	2;
		}
	else
	{
		IP_ADDR[3] = MDateBuf[0] & 0xFF;
		IP_ADDR[2] = MDateBuf[0]>>8 & 0xFF;
		IP_ADDR[1] = MDateBuf[1] & 0xFF;
		IP_ADDR[0] = MDateBuf[1]>>8 & 0xFF;


		//Flash_Write((uint8_t *)&IP_ADDR[0],(uint8_t *)&userConfig[_IfIPaddr],4);	// Пишем IP во внутреннюю флэш
		memory_write_to_mem((uint8_t *)&IP_ADDR[0],_IfIPaddr,4);
		USART_TRACE_BLUE("сохраним во flash IP:%d.%d.%d.%d \n", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);


//		osMutexRelease(xIEC850StartMutex);
	}
	return	0;
}
/********************************************************************************************************
 * Hal_setConfSWFromMB_Date
 * установка конфига выключателя в нужных узлах
 *********************************************************************************************************/
#if defined (MR771) || defined (MR801)
BOOL	Hal_setConfSWFromMB_Date ( uint16_t * MDateBuf ){

	uint64_t currentTime;
	uint32_t	reg = 0;

	currentTime = Hal_getTimeInMs();

	if (MDateBuf[MB_rOffsetControlSW]<<MB_bControlSW_SDTU) {reg = STVALINT32_ON;} else
	{reg = STVALINT32_OFF;}

  	USART_TRACE_GREEN("stVal = %u\n",reg);


//CSWI1_Mod
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Mod_stVal, reg);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Mod_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Mod_t, currentTime);
//CSWI1_Beh
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Beh_stVal, reg);
	IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Beh_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Beh_t, currentTime);
	return	TRUE;
}
#endif
#if defined (MR5_700)

#endif
