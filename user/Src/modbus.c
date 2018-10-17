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

#include "memcopy.h"		// копирование через ДМА

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

/* ----------------------- Time includes ----------------------------------*/
#include "sntpclient.h"
/* ----------------------- Defines ------------------------------------------*/
#if 0 //defined (MR5_700) || defined (MR5_600) || defined (MR5_500)
#define	RT_TICK_PER_SECOND		20000			//20КГц = 50мкс
#else
#define	RT_TICK_PER_SECOND		1000000			//1МГц = 1мкс
#endif

/* ----------------------- Variables ----------------------------------------*/
//extern osThreadId MBUSTaskHandle;
// константы во FLASH
//__attribute__((__section__(".eb0rodata"))) const
//extern	uint8_t userConfig[0x7FFC];// = {1,2,3,4,5,6,7,8,9,0};

extern uint16_t		GLOBAL_QUALITY;
extern uint16_t		TIMEOUT_MB_FOR_QUALITY;

extern	errMB_data	cntErrorMD;						// счетчик ошибок

extern 	RTC_HandleTypeDef hrtc;						// часы

extern UART_HandleTypeDef 	MODBUS;
extern UART_HandleTypeDef 	BOOT_UART;

uint8_t 	Modbus_DataRX[_SizeModbusRX]	__attribute__ ((section (".ramint")));						// буфер приёмника Modbus
static volatile uint16_t 	Modbus_SizeRX;			// размер ожидаемого ответа от MODBUS
static volatile uint16_t 	Modbus_AddrRX;			// адрес ожидаемого ответа от MODBUS

extern volatile uint16_t	xMasterOsEvent;			// хранилище событий порта MODBUS
extern volatile uint16_t	xMasterOsEventCnt;		// счетчик пропусков из-за ожидания ответа

static uint32_t usT35TimeOut;

/* Timer handler declaration */
TIM_HandleTypeDef    TimHandle;

#if defined (MR771) || \
	defined (MR761) || defined (MR762) || defined (MR763) || \
	defined (MR801) || \
	defined (MR901) || defined (MR902)|| \
	defined (MR851) ||\
	defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)

extern uint8_t	  writeNmbSG;			// номер группы уставок.

extern uint16_t   usErrorNoteStart;
extern uint16_t   usSysNoteStart;
extern uint16_t   usWrSysNoteStart;

extern uint16_t	GlobalAddrSysNote;
extern uint16_t	GlobalAddrErrorNote;
extern uint16_t	GlobalAddrOscNote;

// журнал осциллограмм -----------------------
extern uint16_t   usOscNoteStart;

extern uint16_t   usOscBlockStart;
extern uint16_t   ucCurrOscPage;				// текущая страница
extern uint16_t   ucCurrOscAddrOnPage;			// текущий адрес на странице
extern uint16_t   ucCurrOscSizeOnPage;			// размер на странице
//-------------------------------------

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigUstavkiStart;			// группа уставок
extern uint16_t   usConfigOtherUstavkiStart;	// группа общих уставок

extern uint16_t   usConfigAutomatStart;			// параметры автоматики
extern uint16_t   usSystemCfgStart;				// параметры системы
extern uint16_t   usConfigTRMeasStart;			// конфигурация измерительного транса
extern uint16_t   usSGStart;					// параметры группы уставок
extern uint16_t   usRPNStart;

extern uint16_t   usConfigOutStart;
extern uint16_t   usConfigStartExZ;
extern uint16_t   usConfigStartF;
extern uint16_t   usConfigStartU;
extern uint16_t   usConfigStartMTZ;
extern uint16_t   usConfigStartI2I1I0;


extern uint16_t   usConfigStartSW;			// конфигурация Выключателя
extern uint16_t   usConfigStartSWCrash;		// ресурс выключателя

extern uint16_t   usConfigAPWStart;			// конфигурация АПВ								801
extern uint16_t   usConfigAWRStart;			// конфигурация АВР								801
extern uint16_t   usConfigTRPWRStart;		// конфигурация силового транса					801
extern uint16_t   usConfigVLSInStart;		// конфигурация входных логических сигналов		801
extern uint16_t   usConfigVLSOutStart;		// конфигурация выходных логических сигналов	801

extern uint16_t   ucRPNBuf[MB_NumbRPN];
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucSGBuf[MB_NumbSG];
extern uint16_t   ucSWCrash[MB_Size_SWCrash];

extern uint16_t   usStartGoose;					// база гусов для отправки
extern uint16_t   ucGooseBufSent[MB_NumbGoose];
extern uint16_t   ucGooseBufDrop[MB_NumbGoose];

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
    	MODBUS.Init.OverSampling = UART_OVERSAMPLING_8;//UART_OVERSAMPLING_8;
 		HAL_UART_Init(&MODBUS);
/*
 		USART_TRACE_GREEN("---------------------------------------------\n");
 		USART_TRACE_GREEN("порт %u\n",ucPort);
 		USART_TRACE_GREEN("скорость BRR 0x%.4X\n",MODBUS.Instance->BRR);
 		USART_TRACE_GREEN("DIV_Mantissa %u\n",(MODBUS.Instance->BRR)>>4);
 		USART_TRACE_GREEN("DIV_Fraction %u\n",(MODBUS.Instance->BRR)&0x0F);
 		//USART_TRACE_GREEN("USARTDIV %u\n",0);
 		USART_TRACE_GREEN("---------------------------------------------\n");
*/
 		//UART_IT_IDLE нужно включить прерывание по паузе в данных. по входу в прерывание вычитать счетчик принятых данных из дма и вычитать данные если
 		// нет хвоста в заголовке посмотреть размер и дочитать хвост в нужный буфер

		HAL_UART_Receive_DMA(&MODBUS, Modbus_DataRX, _SizeModbusRX);			// запуск приёма в DMA
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
 *
 *     TIM2...TIM7,12,13,14 CLK = 2 * PCLK1 		= 84MHz
* 	   TIM1,8,9,10,11 CLK = 2 * PCLK2 				= 168MHz
 *
 *************************************************************************/
#if 0 //defined (MR5_700) || defined (MR5_600) || defined (MR5_500)
BOOL            xMBPortTimersInit( USHORT usTimeOut50us )
{

	uint32_t uwPrescalerValue = (uint32_t) ((SystemCoreClock /2) / RT_TICK_PER_SECOND) - 1;

	TimHandle.Instance 				 = TIM2;
	TimHandle.Init.Period            = ( (uint32_t) usTimeOut50us ) - 1;
	TimHandle.Init.Prescaler         = uwPrescalerValue;//4200 - 1;
	TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;//TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;//TIM_COUNTERMODE_UP;
	TimHandle.Init.RepetitionCounter = 0;
	HAL_TIM_Base_Init(&TimHandle);

	HAL_TIM_Base_Start_IT(&TimHandle);

return TRUE;
}
#else
BOOL            xMBPortTimersInit( uint32_t usTimeOut_ns )
{
	portDISABLE_INTERRUPTS();

//	Port_Off(LEDtst1);
	uint32_t uwPrescalerValue = (2*HAL_RCC_GetPCLK1Freq()/1000000) - 1;		// 83		// 1мкс импульс

	TimHandle.Instance 				 = TIM2;
	TimHandle.Init.Period            = (uint32_t) usTimeOut_ns/1000 + 1;
	TimHandle.Init.Prescaler         = uwPrescalerValue;			//делитель частоты. Задаёт частоту счётных импульсов. 84МГц/
	TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;		//TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;			//TIM_COUNTERMODE_UP;
//	TimHandle.Init.RepetitionCounter = 0;
	HAL_TIM_Base_Init(&TimHandle);
	HAL_TIM_Base_Start_IT(&TimHandle);
//	Port_On(LEDtst1);

	portENABLE_INTERRUPTS();

return TRUE;
}
#endif
/*************************************************************************
 * HAL_TIM_Base_MspInit
 *************************************************************************/
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
  __TIM2_CLK_ENABLE();
  HAL_NVIC_SetPriority(TIM2_IRQn, 7, 0);//7
  HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

/*************************************************************************
 * xMBMasterPortTimersInit
 * usTimeOut время в наносекундах
 *************************************************************************/
BOOL            xMBMasterPortTimersInit( USHORT usTimeOut )
{
    /* backup T35 ticks */
    usT35TimeOut = usTimeOut;
    xMBPortTimersInit(usTimeOut);
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
//	HAL_UART_DMAStop(&MODBUS);
}
/*************************************************************************
 * xMBMasterPortSerialGetBuf
 *************************************************************************/
BOOL     xMBMasterPortSerialGetBuf(UCHAR pos, CHAR * pucByte )
{
	*pucByte = Modbus_DataRX[pos];

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
			return TRUE;
	}
	else	return FALSE;
}
/*************************************************************************
 * vMBMasterPortTimersRespondTimeoutEnable
 * Время ожидания Slave ответа
 * тут только инит и запуск таймера.
 *************************************************************************/
void     vMBMasterPortTimersRespondTimeoutEnable( void )
{
	//Port_On(LEDtst2);
    vMBMasterSetCurTimerMode(MB_TMODE_RESPOND_TIMEOUT);
    xMBPortTimersInit(MB_MASTER_TIMEOUT_nS_RESPOND);
}
/*************************************************************************
 * vMBMasterPortTimersAfterRespondTimeoutEnable
 * Таймаут после ответа
 *************************************************************************/
void     vMBMasterPortTimersAfterRespondTimeoutEnable( void )
{
	vMBMasterSetCurTimerMode(MB_TMODE_AFTERRESPOND_TIMEOUT);
	xMBPortTimersInit((uint32_t)_delayAfterResponse*1000000);
}
/*************************************************************************
 * vMBMasterPortTimersDisable
 *************************************************************************/
void     vMBMasterPortTimersDisable( void )
{
    vMBMasterSetCurTimerMode(MB_TMODE_STOP);

	HAL_TIM_Base_Stop_IT(&TimHandle);
	HAL_TIM_Base_Stop(&TimHandle);

}
/*************************************************************************
 * xModbus_Set_Size
 * передача размера  ответа от слейва
 *************************************************************************/
BOOL            xModbus_Set_SizeAnswer( uint16_t Size, uint16_t Addr )
{
	if (!Size) return FALSE;
	Modbus_SizeRX = Size;
	Modbus_AddrRX = Addr;
	return TRUE;
}
/*************************************************************************
 * xModbus_Get_SizeAnswer
 * передача размера  ответа от слейва
 *************************************************************************/
uint16_t   xModbus_Get_SizeAnswer( uint16_t * Size )
{
uint16_t	SizeRX;

	SizeRX = Hal_get_SizeMessageFromMB((uint8_t *)Modbus_DataRX);

	if (Size) *Size = SizeRX;
	return	SizeRX;
/*
	if (Size) *Size = Modbus_SizeRX;
	return Modbus_SizeRX;
*/
}
/*************************************************************************
 * xModbus_Get_AddrAnswer
 * передача адреса ответа от слейва
 *************************************************************************/
BOOL            xModbus_Get_AddrAnswer( uint16_t * Addr )
{
	*Addr = Modbus_AddrRX;
	return TRUE;
}
/*************************************************************************
 * xMBMasterPortEventPost
 * передача события в объект события. Попробуем мспользовать семафор
 *************************************************************************/
BOOL            xMBMasterPortEventPost( eMBMasterEventType eEvent )
{
	portDISABLE_INTERRUPTS();
	xMasterOsEvent |= eEvent;
 //   rt_event_send(&xMasterOsEvent, eEvent);									// передача события в объект событий xMasterOsEvent
	portENABLE_INTERRUPTS();
	return TRUE;
}
/*************************************************************************
 * xMBMasterPortEventClear
 * Удаляем событие.
 *************************************************************************/
BOOL            xMBMasterPortEventClear( eMBMasterEventType eEvent )
{
	portDISABLE_INTERRUPTS();
	if (xMasterOsEvent & eEvent){
		xMasterOsEvent ^= eEvent;
	}
	portENABLE_INTERRUPTS();
     return TRUE;
}
/*************************************************************************
 * xMBMasterPortEventInit
 * инит события и включение контроля над ним.
 *************************************************************************/
BOOL            xMBMasterPortEventInit( void )
{
	portDISABLE_INTERRUPTS();
	xMasterOsEvent = 0;
	portENABLE_INTERRUPTS();
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
 * функция проверяет события в хранилище xMasterOsEvent
 * и возврашает в *eEvent самое приоритетное событие
 *
 * приоритеты: от высокого к низкому.
 * 0. EV_MASTER_FRAME_SENT 					- внеприоритетное только многозадачность шины
 *
 * 1. EV_MASTER_EXECUTE						- перекладываем из рабочего буфера(xMBMasterRTUReceiveFSM) в конкретные массивы. только после успешного (EV_MASTER_FRAME_RECEIVED)
 * 2. EV_MASTER_FRAME_RECEIVED				- БЫСТРО переписываем из буфера DMA(Modbus_DataRX) в рабочий буфер (xMBMasterRTUReceiveFSM)
 * 3. EV_MASTER_FRAME_SENT					- блокируется событием ожидания ответа (EV_MASTER_FRAME_RECEIVE_WAIT)
 * 4. EV_MASTER_READY						-
 * 5. EV_MASTER_ERROR_PROCESS				-
 *
 * возвращает TRUE если было хоть одно событие
 *************************************************************************/
BOOL   xMBMasterPortEventGet(  /*@out@ */ eMBMasterEventType * eEvent ){

    uint32_t 	recvedEvent = 0;
    BOOL		status = FALSE;
    uint32_t 	set=0;
    uint16_t	Event;

    // многозадачная реализация:
    // 1. если пришел ответ (EV_MASTER_FRAME_RECEIVE_WAIT == 0), и приёмник готов принимать, то отправляем новый запрос.
    // 2. приоритетная задача, EV_MASTER_EXECUTE. сначала перекинем уже принятое в нужный буфер.
    // 3. если больше ничего не надо EV_MASTER_FRAME_RECEIVED принятое перекинем в транзитный буфер.
    // 4. если ошибки то нужно обработать их сперва.
    // 5. ставим в состояние EV_MASTER_READY.
    // 6. если ничего нет, то выходим без выполнения.

#if ((defined (MR761) || defined (MR762) || defined	(MR763)) && (_REVISION_DEVICE >302)) || (defined	(MR771) && (_REVISION_DEVICE >106))
    // многозадачная реализация
     if (status == FALSE){
     		set = EV_MASTER_FRAME_SENT;
        	if (xMasterOsEvent & set) status = TRUE;
     }
     //! многозадачная реализация
#endif

    if (status == FALSE){
    	set = EV_MASTER_EXECUTE;
    	if (xMasterOsEvent & set) status = TRUE;
    }
    if (status == FALSE){
     	set = EV_MASTER_FRAME_RECEIVED;
    	if (xMasterOsEvent & set) status = TRUE;
     }

#if ((defined	(MR761) || defined	(MR762) || defined	(MR763)) && (_REVISION_DEVICE >302)) || (defined	(MR771) && (_REVISION_DEVICE >106))
    // многозадачная реализация
     //! многозадачная реализация
#else
	if (status == FALSE){
		if ((xMasterOsEvent & EV_MASTER_FRAME_RECEIVE_WAIT) == 0){	// если ждем ответа, то не вкоем случае не шлём новый запрос. Нету смысла
			set = EV_MASTER_FRAME_SENT;
	    	if (xMasterOsEvent & set) status = TRUE;
		}
	}
#endif

    if (status == FALSE){
    	set = EV_MASTER_READY;
    	if (xMasterOsEvent & set) status = TRUE;
    }

    if (status == FALSE){
    	set = EV_MASTER_ERROR_PROCESS;
    	if (xMasterOsEvent & set) status = TRUE;
    }

    if (status == TRUE){
		recvedEvent = set;
		portDISABLE_INTERRUPTS();
		xMasterOsEvent &= ~set;
		portENABLE_INTERRUPTS();
    }

    // проинформируем что ждём ответа
    if (status == FALSE){
    	set = EV_MASTER_FRAME_RECEIVE_WAIT;
    	if (xMasterOsEvent & set) {
    		if (MB_TMODE_STOP == vMBMasterGetCurTimerMode()){
				status = TRUE;
				recvedEvent = set;
    		}
    	}
    }
    switch (recvedEvent)
    {
        break;
    case EV_MASTER_FRAME_RECEIVE_WAIT:
        *eEvent = EV_MASTER_FRAME_RECEIVE_WAIT;
        break;
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
//error
    case EV_MASTER_ERROR_PROCESS:
        *eEvent = EV_MASTER_ERROR_PROCESS;
        break;
    }
    return status;
}
/*************************************************************************
 * vMBMasterCBRequestScuuess
 * приняли данные. обнулим ошибки и снимем ошибку качества
 *************************************************************************/
void            vMBMasterCBRequestScuuess( void )
{
	Port_On(LED_out_GREEN);
	Port_Off(LED_out_RED);
	TIMEOUT_MB_FOR_QUALITY = TIMEOUT_MB_Response;
	GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
	if (NULL == iedServer)
		osMutexRelease(xIEC850StartMutex);

}
/*************************************************************************
 * vMBMasterErrorCBExecuteFunction
 *************************************************************************/
void            vMBMasterErrorCBExecuteFunction( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{
	USART_TRACE_RED("------------------------------\n");
	USART_TRACE_RED("ERROR_EXECUTE_FUNCTION:\n");
}
/*************************************************************************
 * vMBMasterErrorCBRespondTimeout
 *************************************************************************/
void			vMBMasterErrorCBRespondTimeout( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{
	vMBMasterErrorCBIncCntErr(ucDestAddress,pucPDUData,ucPDULength);		// подсчёт ошибок
	xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );							// повторная отправка

	Port_On(LED_out_RED);													// признак качества от потери связи
	if 		(TIMEOUT_MB_FOR_QUALITY > 0)	{TIMEOUT_MB_FOR_QUALITY--;}
	else 	{
		TIMEOUT_MB_FOR_QUALITY = TIMEOUT_MB_Response;
		GLOBAL_QUALITY = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
	}

	USART_TRACE_RED("------------------------------\n");
	USART_TRACE_RED("EV_ERROR_RESPOND_TIMEOUT нужна перепостановка задачи.\n");

	USART_TRACE_RED("");
	uint8_t	i;
	for(i=0;i<ucPDULength;i++) USART_0TRACE("0x%.2X ",pucPDUData[i]);
	USART_0TRACE("\n\n");

	xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );			// разрешаем передачу

}
/*************************************************************************
 * vMBMasterErrorCBReceiveData
 *************************************************************************/
void            vMBMasterErrorCBReceiveData( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{
	vMBMasterErrorCBIncCntErr(ucDestAddress,pucPDUData,ucPDULength);		// подсчёт ошибок
	xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );							// повторная отправка

	USART_TRACE_RED("------------------------------\n");
	USART_TRACE_RED("ERROR_RECEIVE_DATA нужна перепостановка задачи.\n");

	USART_TRACE_RED("");
	uint8_t	i;
	for(i=0;i<ucPDULength;i++) USART_0TRACE("0x%.2X ",pucPDUData[i]);
	USART_0TRACE("\n\n");

	xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );			// разрешаем передачу
}
/*************************************************************************
 * vMBMasterErrorCBReceiveData
 *************************************************************************/
void            vMBMasterErrorCBSendData( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{
	USART_TRACE_RED("------------------------------\n");
	USART_TRACE_RED("ERROR_SEND_DATA нужен переинит порта и ДМА.\n");
}
/*************************************************************************
 * vMBMasterErrorCBIncCntErr
 * счетчик ошибок связи
 *************************************************************************/
void            vMBMasterErrorCBIncCntErr( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{
	uint16_t	adrAnsw = 0;

	adrAnsw |= (uint16_t) pucPDUData[1]<<8;
	adrAnsw |= (uint16_t) pucPDUData[2];
	if (adrAnsw == MB_StartAnalogINaddr) cntErrorMD.errAnalog++;
	if (adrAnsw == MB_StartDiscreetaddr) cntErrorMD.errDiscreet++;
	if ((adrAnsw >= MB_StartDUMP_Ustavki) && (adrAnsw<(MB_StartDUMP_Ustavki + MB_NumbDUMP_Ustavki))) cntErrorMD.errUstavki++;
	if ((adrAnsw >= MB_StartSysNoteaddr) && (adrAnsw<MB_EndSysNoteaddr)) 		cntErrorMD.errJurnal++;
	if ((adrAnsw >= MB_StartErrorNoteaddr) && (adrAnsw<MB_EndErrorNoteaddr)) 	cntErrorMD.errJurnal++;
	if ((adrAnsw >= MB_StartOscNoteaddr) && (adrAnsw<MB_EndOscNoteaddr)) 		cntErrorMD.errJurnal++;

}

/*************************************************************************
 * vMBMasterRunResRelease
 *************************************************************************/
void            vMBMasterRunResRelease( void )
{

}
/*************************************************************************
 * xMBMasterRunResTake
 *
 * EV_MASTER_FRAME_RECEIVE_WAIT снимается в прерывании и успевает не входя
 * в eMBMasterPoll готовит новые данные в буфер. А надо переотправить предыдущие.
 * нужно проверит флаги ошибок.
 *************************************************************************/
BOOL            xMBMasterRunResTake( int32_t time )
{
	uint16_t set;
    BOOL	status = TRUE;

    set = EV_MASTER_FRAME_RECEIVE_WAIT;		// пока слать нельзя.
    if ((xMasterOsEvent & set) != 0)  	status = FALSE;

    set = EV_MASTER_ERROR_PROCESS;		// пока слать нельзя.
    if ((xMasterOsEvent & set) != 0)  	status = FALSE;

    if (time == 0 ) status = TRUE;

return	status;
}
/*************************************************************************
 * eMBMasterWaitRequestFinish
 *************************************************************************/
eMBMasterReqErrCode eMBMasterWaitRequestFinish( void )
{

    eMBMasterReqErrCode    eErrStatus = MB_MRE_NO_ERR;
    /*
    BOOL	status = FALSE;
    uint16_t set = EV_MASTER_PROCESS_SUCESS;

    portDISABLE_INTERRUPTS();
     if (xMasterOsEvent & set)     status = TRUE;
     if (status) xMasterOsEvent &= ~set;

    portENABLE_INTERRUPTS();
*/
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
 * vMBMasterPortRecieverDMAStart
 * старт приёма ответа в DMA, заранее зная его размер
 *************************************************************************/
void            vMBMasterPortRecieverDMAStart( uint16_t		size){

}
/*************************************************************************
  * @brief  Tx Transfer completed callback
  * @param  huart: UART handle.
  * @retval None
 *************************************************************************/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart == &MODBUS) {
		pxMBMasterFrameCBTransmitterEmpty();						// скажем что закончили предачу (xMBMasterRTUTransmitFSM)
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
//	Port_Off(LEDtst1);
	if (pxMBMasterPortCBTimerExpired()){			// если изменилось состояние в xMasterOsEvent (хранилище событий порта MODBUS)

	}
}
void HAL_TIMEx_BreakCallback(TIM_HandleTypeDef* htim)
{
//	if (pxMBMasterPortCBTimerExpired()){			// если изменилось состояние в xMasterOsEvent (хранилище событий порта MODBUS)

//	}
}
/*************************************************************************
  * @brief  Rx Transfer completed callback
  * @param  huart: UART handle
  * @retval None
 *************************************************************************/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart == &MODBUS) {						// разблокировка MODBUS таска
//		Port_Off(LEDtst1);
//		if (pxMBMasterFrameCBByteReceived()){
//		}
//		Port_On(LEDtst1);

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

	USART_TRACE_RED("HAL_UART_ErrorCallback\n");
}
/*************************************************************************
  * @brief  UART IDLE callbacks
  * @param  huart: UART handle
  * @retval None
  * прерывание по тишине 2,5 символа после обмена.
 *************************************************************************/
void HAL_UART_IDLECallback(UART_HandleTypeDef *huart){

uint16_t	Datanumb;													// число принятых байт лежащих в DMA
uint16_t	SizeMessage;												// размер сообщения

	__HAL_UART_CLEAR_IDLEFLAG(huart);									// сбросим флаг
	Datanumb = HAL_UART_DataInDMA(huart);								// число принятых в DMA символов

	SizeMessage  = Hal_get_SizeMessageFromMB((uint8_t*)Modbus_DataRX);	// размер сообщения из самого сообщения.

	if (Datanumb >= SizeMessage){
		Port_On(LEDtst1);
		HAL_UART_DMARXStop(huart);
		pxMBMasterPortCBStartIdle();									// приняли и перешли в IDLE
		HAL_UART_Receive_DMA(huart, Modbus_DataRX, _SizeModbusRX);

		// запустим таймер постпаузы _delayAfterResponseнужно указать обработчику что делать
		vMBMasterPortTimersAfterRespondTimeoutEnable();

		Port_Off(LEDtst1);
	} else{																// если в буфере меньше чем указано в сообщении
		Port_On(LEDtst1);												// то возможно клиент замешкался, подождём ещё, может придёт остаток
//		 xMBMasterPortEventClear(EV_MASTER_FRAME_RECEIVE_WAIT);			// но обязательно запустить таймер таймаута, вдруг колизия была. Зависнем навсегда.
		Port_Off(LEDtst1);
	}
}

/*************************************************************************
  * @brief  HAL_UART_DataInDMA
  * сколько байт лежит в dma
 *************************************************************************/
int HAL_UART_DataInDMA(UART_HandleTypeDef *huart){
int		Datanumb;

Datanumb = huart->RxXferSize - huart->hdmarx->Instance->NDTR;
return	Datanumb;
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
 * Сохраняем принятый данные в буфер базы данных
************************************************************************************************/
eMBErrorCode eMBMasterToMemDB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, USHORT * pusRegHoldingBuf, USHORT BaseAddress, USHORT BaseNRegs )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    USHORT          iRegIndex;

    usAddress--;

    if ((usAddress >= BaseAddress) && (usAddress + usNRegs <= BaseAddress + BaseNRegs))
    {
        iRegIndex = usAddress - BaseAddress;

//		Port_On(LEDtst1);

        // перепишем данные в хранилище

		while (usNRegs > 0)
		{
			pusRegHoldingBuf[iRegIndex] = *pucRegBuffer++ << 8;
			pusRegHoldingBuf[iRegIndex] |= *pucRegBuffer++;
			iRegIndex++;
			usNRegs--;
		}

//		MEMDMACOPY((uint32_t)&pusRegHoldingBuf[iRegIndex],(uint32_t)pucRegBuffer,usNRegs*2,0);
        //memcpy(&pusRegHoldingBuf[iRegIndex],pucRegBuffer,usNRegs*2);

//		Port_Off(LEDtst1);
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
return MB_ENOERR;
}

eMBErrorCode eMBMasterRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode )
{
return MB_ENOERR;
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

	//sTime.TimeFormat = RTC_HOURFORMAT_24;
	hrtc.Init.HourFormat = RTC_HOURFORMAT_24;

	sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sTime.StoreOperation = RTC_STOREOPERATION_RESET;

	sTime.Hours =  	(uint8_t) MDateBuf[3];
	sTime.Minutes = (uint8_t) MDateBuf[4];
	sTime.Seconds = (uint8_t) MDateBuf[5];

	//sTime.SubSeconds = (1000 - MDateBuf[6]*10) * hrtc.Init.SynchPrediv / 1000;			// это не работает, нет смысла устанавливать

	HAL_RTC_SetTime(&hrtc, &sTime, FORMAT_BIN);

	sDate.Year = (uint8_t) MDateBuf[0];
	sDate.Month =(uint8_t) MDateBuf[1];
	sDate.Date = (uint8_t) MDateBuf[2];
	sDate.WeekDay = 0;				// рандомное число тут, уносит в ебеня год

	HAL_RTC_SetDate(&hrtc, &sDate, FORMAT_BIN);

	if 		(HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)    HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, 1);		// первое чтение. RTC_BKP_DR0 пишем 1
	else {
		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) + 1);						// если это уже не первый раз, пересинхронизация.
		USART_TRACE_BLUE("Взяли время из прибора. RTC_BKP_DR0: %u\n",HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0));
	}

	return	TRUE;
}
/********************************************************************************************************
 * Hal_Verify_Rev
 * проверка ревизии.
 *********************************************************************************************************/
int8_t	Hal_Verify_Rev( uint8_t * MDateBuf ){

	int ret = false;
	uint8_t* Revs = (uint8_t*)&_swREV;
	char *	st;

// MR5 версии
	if ((MDateBuf[0] == Revs[0]) && (MDateBuf[1] == Revs[1]) && (MDateBuf[3] == Revs[2])) {
		// найдём версию _swREVverify и проверим
		st = strstr((char *)MDateBuf,_swREVverify);
		if (st == NULL){
			USART_TRACE_RED("связной для:'%s %s' запускаем сервер для перепрошивки.\n",Revs,_swREVverify);
			ret = false;
		} else{
			ret = true;
		}
		return ret;
	}

// остальные версии с полным названием

	if ((MDateBuf[3] == Revs[2]) && (MDateBuf[4] == Revs[3]) && (MDateBuf[5] == Revs[4])) {
		ret = true;
	}else{
		USART_TRACE_RED("связной для:%s запускаем сервер для перепрошивки.\n",Revs);
	}
	return ret;
}
/********************************************************************************************************
 * Hal_setIPFromMB_Date
 * установка IP адреса из буфера MODBUS
 *********************************************************************************************************/
int8_t	Hal_setIPFromMB_Date( uint16_t * MDateBuf ){
extern uint8_t		IP_ADDR[4];


	if ((MDateBuf[0] == 0xffff && MDateBuf[1] == 0xffff) || (MDateBuf[0] == 0 && MDateBuf[1] == 0))	{
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

		// адресок то стрёмный, ставим дефолтный
		if ((IP_ADDR[0] == 0) || (IP_ADDR[1] == 0) || (IP_ADDR[0] == 0xFF) || (IP_ADDR[1] == 0xFF) || (IP_ADDR[2] == 0xFF)|| (IP_ADDR[3] == 0xFF)){
			  IP_ADDR[0] = 192;IP_ADDR[1] = 168;IP_ADDR[2] = 0;IP_ADDR[3] = 254;

			  memory_write_to_mem((uint8_t *)&IP_ADDR[0],_IfIPaddr,4);
			  USART_TRACE_BLUE("Установим дефолтный и сохраним во flash IP:%d.%d.%d.%d \n", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);

			  return	3;
		}

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

/*******************************************************
 * Hal_get_SizeMessageFromMB
 * получаем размер сообщения из самого сообщения
 *******************************************************/
uint16_t	Hal_get_SizeMessageFromMB( uint8_t * MDateBuf ){
	uint16_t	sz = 0;

	switch	(MDateBuf[0]){		// адрес
// запросы слейву
// --------------------------------------------------------
	case	MB_SlaveAddres:
		switch	(MDateBuf[MB_PDU_REQ_READ_ADDR_OFF]){		// команда модбаса 1

// ответ от слейва

// 1,2 команда
		case	MB_FUNC_READ_COILS:
		case	MB_FUNC_READ_DISCRETE_INPUTS:
			sz = MDateBuf[1 + MB_PDU_FUNC_READ_BYTECNT_OFF] + SizeAddr + SizeFunct + SizeNumbByte + SizeCRC;
			break;

// 3,4 команда
		case	MB_FUNC_READ_HOLDING_REGISTER:
		case	MB_FUNC_READ_INPUT_REGISTER:
//			sz = MDateBuf[1 + MB_PDU_FUNC_READ_VALUES_OFF] + SizeAddr + SizeFunct + SizeNumbByte + SizeCRC;
			sz = MDateBuf[1 + MB_PDU_FUNC_READ_BYTECNT_OFF] + SizeAddr + SizeFunct + SizeNumbByte + SizeCRC;
			break;
// 5,6 команда
		case	MB_FUNC_WRITE_SINGLE_COIL:
		case	MB_FUNC_WRITE_REGISTER:
			sz = 8; // всегда 8 фикс. ответ //SizeAddr + SizeFunct + SizeMemAddr + SizeNumbWord + SizeCRC;
			break;
// 19 (0x13) команда
		case	MB_FUNC_READ_HOLDING_REGISTER_W_ADDR:
			sz = ( USHORT )( MDateBuf[1 + MB_PDU_FUNC_READ_WORDCNT_OFF] << 8 );
			sz |= ( USHORT )(MDateBuf[1 + MB_PDU_FUNC_READ_WORDCNT_OFF + 1] );
			sz *= 2;
			sz += SizeAddr + SizeFunct + SizeNumbWord + SizeCRC;
			break;
// 16 команда
		case	MB_FUNC_WRITE_MULTIPLE_REGISTERS:
			sz = 8; // всегда 8 фикс. ответ //SizeAddr + SizeFunct + SizeMemAddr + SizeNumbWord + SizeCRC;
			break;
		}
	break;
// запорос от мастера
// --------------------------------------------------------
	case	MB_MasterAddres:
		switch	(MDateBuf[MB_PDU_REQ_WRITE_MUL_ADDR_OFF]){

		case	MB_FUNC_WRITE_MULTIPLE_REGISTERS:
			sz = ( USHORT )( MDateBuf[1 + MB_PDU_REQ_WRITE_MUL_REGCNT_OFF] << 8 );
			sz |= ( USHORT )(MDateBuf[1 + MB_PDU_REQ_WRITE_MUL_REGCNT_OFF + 1] );
			sz *= 2;
			sz += SizeAddr + SizeFunct + SizeMemAddr + SizeNumbWord+ SizeNumbByte + SizeCRC;
			break;
		}
	break;
	}

	return	sz;
}
/*******************************************************
 * AddToQueueMB
 * постановка задачи в очередь,
 * если размер запроса больше максимального пакета модбас (MaxSizeBlok)
 * то дробим запросы на куски.
 *******************************************************/
int8_t	AddToQueueMB(xQueueHandle SentQueue, uint16_t	MB_Rd_cmd, uint8_t	Slaveaddr){

uint16_t		num = 0;
uint16_t		i;
ModbusMessage 	Message, tmpMessage;
uint16_t		addr = 0,size = 0,end = 0;

extern uint16_t   ucMDateBuf[MB_NumbDate];

	switch	(MB_Rd_cmd){

	case	MB_Wrt_Set_Time:

		addr = MB_StartDateNaddr;

		Message.MBFunct 	= MB_FUNC_WRITE_MULTIPLE_REGISTERS;
		Message.MBSlaveAddr = Slaveaddr;
		Message.StartAddr = MB_StartDateNaddr;
		Message.SizeMessage = MB_NumbDate;

		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
		for (i = 0; i < MB_NumbDate; i++){
			Message.ucData[i] = ucMDateBuf[i];
		}
		xQueueSendToFront( SentQueue, ( void * )&Message, portMAX_DELAY);	// передача в очередь сообщения в начало
		return	0;
		break;

	case MB_Rd_Revision:
		addr = MB_StartRevNaddr;
		num = MB_NumbWordRev;
		num /= MaxSizeBlok;
		end = MB_NumbWordRev - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_Discreet:

		addr = usMDiscInStart;
		num = MB_NumbDiscreet;
		num /= MaxSizeBlok;
		end = MB_NumbDiscreet - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_Analog:

		addr = usMAnalogInStart;
		num = MB_NumbAnalog;
		num /= MaxSizeBlok;
		end = MB_NumbAnalog - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_AllUstavki:
		//usConfigOtherUstavkiStart
		addr = usConfigOtherUstavkiStart;
		num = MB_NumbOtherUstavki;
		num /= MaxSizeBlok;
		end = MB_NumbOtherUstavki - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_Get_Time:

		addr = MB_StartDateNaddr;
		num = MB_NumbDate;
		num /= MaxSizeBlok;					// количество блоков.
		end = MB_NumbDate - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_Syscfg:

		addr = MB_StartSystemCfg;
		num = MB_NumbSystemCfg;
		num /= MaxSizeBlok;
		end = MB_NumbSystemCfg - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_Ustavki:

		addr = usConfigUstavkiStart;//MB_StartConfig;				// бывает несколько групп уставок
		num = MB_NumbUstavki;
		num /= MaxSizeBlok;
		end = MB_NumbUstavki - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigSWCrash:
		//usConfigStartSWCrash,MB_NumbSWCrash,
		addr = usConfigStartSWCrash;//MB_StartSWCrash;
		num = MB_Size_SWCrash;
		num /= MaxSizeBlok;
		end = MB_Size_SWCrash - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigSW:
		//usConfigStartSW,MB_NumbConfigSW
		addr = usConfigStartSW;//MB_StartConfigSW;
		num = MB_NumbConfigSW;
		num /= MaxSizeBlok;
		end = MB_NumbConfigSW - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_NumbSG:
		addr = usSGStart;
		num = MB_NumbSG;
		num /= MaxSizeBlok;
		end = MB_NumbSG - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

		break;
/*
	case MB_Rd_ConfigOut:
		addr = usConfigOutStart;
		num = MB_NumbConfigOut;
		num /= MaxSizeBlok;
		end = MB_NumbConfigOut - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;
*/
	case MB_Rd_ConfigExZ:

		addr = usConfigStartExZ;
		num = MB_NumbConfigExZ;
		num /= MaxSizeBlok;
		end = MB_NumbConfigExZ - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

		break;
	case MB_Rd_ConfigF:

		addr = usConfigStartF;
		num = MB_NumbConfigF;
		num /= MaxSizeBlok;
		end = MB_NumbConfigF - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

		break;
	case MB_Rd_ConfigU:

		addr = usConfigStartU;
		num = MB_NumbConfigU;
		num /= MaxSizeBlok;
		end = MB_NumbConfigU - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigMTZ:
		//usConfigStartMTZ,MB_NumbConfigMTZ
		addr = usConfigStartMTZ;
		num = MB_NumbConfigMTZ;
		num /= MaxSizeBlok;
		end = MB_NumbConfigMTZ - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigI2I1I0:
		//usConfigStartI2I1I0,MB_NumbConfigI2I1I0
		addr = usConfigStartI2I1I0;
		num = MB_NumbConfigI2I1I0;
		num /= MaxSizeBlok;
		end = MB_NumbConfigI2I1I0 - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigAutomat:
		//usConfigAutomatStart,MB_NumbAutomat
		addr = usConfigAutomatStart;
		num = MB_NumbAutomat;
		num /= MaxSizeBlok;
		end = MB_NumbAutomat - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

/*
		MB_Rd_ConfigAPW			= 28,
		MB_Rd_ConfigAWR			= 29,
		MB_Rd_ConfigTRPWR		= 30,
		MB_Rd_ConfigTRMeas		= 31,
		MB_Rd_ConfigVLSIn		= 32,
		MB_Rd_ConfigVLSOut		= 33,
*/
	case MB_Rd_ConfigAPW:
		addr = usConfigAPWStart;
		num = MB_NumbConfigAPW;
		num /= MaxSizeBlok;
		end = MB_NumbConfigAPW - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigAWR:
		addr = usConfigAWRStart;
		num = MB_NumbConfigAWR;
		num /= MaxSizeBlok;
		end = MB_NumbConfigAWR - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigTRPWR:
		addr = usConfigTRPWRStart;
		num = MB_NumbConfigTRPWR;
		num /= MaxSizeBlok;
		end = MB_NumbConfigTRPWR - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigTRMeas:
		addr = usConfigTRMeasStart;
		num = MB_NumbConfigTRMeas;
		num /= MaxSizeBlok;
		end = MB_NumbConfigTRMeas - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigVLSIn:
		addr = usConfigVLSInStart;
		num = MB_NumbConfigVLSIn;
		num /= MaxSizeBlok;
		end = MB_NumbConfigVLSIn - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigVLSOut:
		addr = usConfigVLSOutStart;
		num = MB_NumbConfigVLSOut;
		num /= MaxSizeBlok;
		end = MB_NumbConfigVLSOut - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigRPN:
		//usRPNStart,MB_NumbRPN
		addr = usRPNStart;
		num = MB_NumbRPN;
		num /= MaxSizeBlok;
		end = MB_NumbRPN - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_SysNote:

		addr = usSysNoteStart;
		num = MB_NumbSysNote;
		num /= MaxSizeBlok;
		end = MB_NumbSysNote - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

//		USART_TRACE_BLUE("MB_Rd_SysNote addr:0x%.4X\n",addr);
		break;

	case MB_Rd_ErrorNote:

		addr = usErrorNoteStart;
		num = MB_NumbErrorNote;
		num /= MaxSizeBlok;
		end = MB_NumbErrorNote - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

//		USART_TRACE_BLUE("MB_Rd_ErrorNote addr:0x%.4X\n",addr);
		break;

	case MB_Rd_OscNote:

		addr = usOscNoteStart;
		num = MB_NumbOscNote;
		num /= MaxSizeBlok;
		end = MB_NumbOscNote - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

//		USART_TRACE_BLUE("MB_Rd_OscNote addr:0x%.4X\n",addr);
		break;

	case MB_Rd_OscMessage:

		addr = ucCurrOscAddrOnPage;
		num = ucCurrOscSizeOnPage;//MB_SizeOscBlock;
		num /= MaxSizeBlok;
		end = ucCurrOscSizeOnPage - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

		break;


// ------- WRITES --------------------------------------------------
//------------------------------------------------------------------
	case	MB_Wrt_OscMessageAdrPg:
		addr = usOscBlockStart;
		num = 0;
		end = 1;
		Message.ucData[0]	= ucCurrOscPage;
		Message.MBFunct 	= MB_FUNC_WRITE_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case	MB_Wrt_SysNoteAdr0:
	case	MB_Wrt_ErrorNoteAdr0:
	case	MB_Wrt_OscNoteAdr0:

		if (MB_Rd_cmd == MB_Wrt_SysNoteAdr0) 		{addr = usWrSysNoteStart;GlobalAddrSysNote = 0;}
		if (MB_Rd_cmd == MB_Wrt_ErrorNoteAdr0) 		{addr = usErrorNoteStart;GlobalAddrErrorNote = 0;}
		if (MB_Rd_cmd == MB_Wrt_OscNoteAdr0) 		{addr = usOscNoteStart;GlobalAddrOscNote = 0;}

		num = 0;
		end = 1;
		Message.ucData[0]	= 0;
#if defined (MR851) ||\
		defined (MR5_500) ||defined (MR5_600)||defined (MR5_700) || defined (MR741)
		Message.MBFunct 	= MB_FUNC_WRITE_REGISTER;
#else
		Message.MBFunct 	= MB_FUNC_WRITE_MULTIPLE_REGISTERS;
#endif
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case	MB_Wrt_Reset_LEDS:
	case	MB_Wrt_Reset_Error:
	case	MB_Wrt_Reset_OscNote:					// сброс записи в журнале осциллограмм
	case 	MB_Wrt_Reset_SysNote:
	case	MB_Wrt_Reset_ErrorNote:
	case	MB_Wrt_Reset_BLK:						// только 851
	case	MB_Wrt_Reset_Ustavki:					// сброс флага изменения уставок
	case	MB_Wrt_Set_ExtMode:
	case	MB_Wrt_Clr_ExtMode:
	case	MB_Wrt_DRIVE_UP:
	case	MB_Wrt_DRIVE_DWN:
	case	MB_Wrt_SwON:
	case	MB_Wrt_SwOFF:
	case	MB_Wrt_SG_set_0:						// для редких приборов
	case	MB_Wrt_SG_set_1:						// для редких приборов

		if (MB_Rd_cmd == MB_Wrt_Reset_LEDS) 		addr = MB_addr_LEDS_OFF;
		if (MB_Rd_cmd == MB_Wrt_Reset_Error) 		addr = MB_addr_Error_OFF;
		if (MB_Rd_cmd == MB_Wrt_Reset_OscNote) 		addr = MB_addr_OscNote_OFF;
		if (MB_Rd_cmd == MB_Wrt_Reset_SysNote) 		addr = MB_addr_SysNote_OFF;
		if (MB_Rd_cmd == MB_Wrt_Reset_ErrorNote) 	addr = MB_addr_ErrorNote_OFF;
		if (MB_Rd_cmd == MB_Wrt_Reset_BLK) 			addr = MB_addr_BLK_OFF;
		if (MB_Rd_cmd == MB_Wrt_Reset_Ustavki) 		addr = MB_addr_UstavkiModify;
		if (MB_Rd_cmd == MB_Wrt_Set_ExtMode) 		addr = MB_addr_Set_ExtMode;
		if (MB_Rd_cmd == MB_Wrt_Clr_ExtMode) 		addr = MB_addr_Clr_ExtMode;
		if (MB_Rd_cmd == MB_Wrt_DRIVE_UP) 			addr = MB_addr_DRIVE_UP;
		if (MB_Rd_cmd == MB_Wrt_DRIVE_DWN) 			addr = MB_addr_DRIVE_DWN;
		if (MB_Rd_cmd == MB_Wrt_SwON) 				addr = MB_addr_SwON;
		if (MB_Rd_cmd == MB_Wrt_SwOFF) 				addr = MB_addr_SwOFF;
		if (MB_Rd_cmd == MB_Wrt_SG_set_0) 			addr = MB_Startaddr_SG_set_0;
		if (MB_Rd_cmd == MB_Wrt_SG_set_1) 			addr = MB_Startaddr_SG_set_1;
		num = 0;
		end = 0;
		Message.ucData[0] 	= MB_CTRL_OFF;
		Message.MBFunct 	= MB_FUNC_WRITE_SINGLE_COIL;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case	MB_Wrt_SG_set_ManNumb:							// по отдельному адресу команды переключения
		addr = MB_Startaddr_SG;
		num = 0;
		end = 0;

		Message.ucData[0]	= writeNmbSG - 1;
		Message.MBFunct 	= MB_FUNC_WRITE_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

		break;

	case	MB_Wrt_Set_Goose:
		addr = MB_Startaddr_Goose;
		num = MB_NumbGoose;
		num /= MaxSizeBlok;
		end = MB_NumbGoose - (num * MaxSizeBlok);

		Message.ucData[0]	= 0x55AA;
		for(i=0;i<MB_NumbGoose;i++){
		 Message.ucData[1+i] = ucGooseBufSent[i] &	~ucGooseBufDrop[i];
		 //Message.ucData[1+i] = ucGooseBufSent[i];
		}
		Message.MBFunct 	= MB_FUNC_WRITE_MULTIPLE_REGISTERS;
		Message.MBSlaveAddr = Slaveaddr;
		break;
	}

	//------------------------------------------------------------------
	if (
			(Message.MBFunct == MB_FUNC_READ_HOLDING_REGISTER) &&
			(num == 0) &&
			(addr == 0) &&
			(end == 0)
		)
	{
		// пустой запрос
		return -1;
	}
//------------------------------------------------------------------
	if (num < uxQueueSpacesAvailable(SentQueue)) {							// если влазят в свободную область
		for (i=0;i<=num;i++){
			Message.StartAddr = addr + MaxSizeBlok*i;
			if (i == num) {
				Message.SizeMessage = end; 									// если в конце 0 читать не нужно
				if ((end == 0)&&(Message.MBFunct == MB_FUNC_READ_HOLDING_REGISTER)) continue;
			}
			else 		  {Message.SizeMessage = MaxSizeBlok;}

			if (uxQueueMessagesWaiting(SentQueue)){							// количество в очереди
				xQueuePeek(SentQueue,&tmpMessage, portMAX_DELAY);			// посмотрим последнее сообщение
				if (memcmp(&tmpMessage,&Message,7) == 0) {
					USART_TRACE_BLUE("есть запись(0x%X). addr:%.4X командаMB:%.3u\n",(unsigned int)SentQueue,(unsigned int)Message.StartAddr,(unsigned int)Message.MBFunct);
					continue;
				}
			}
			//USART_TRACE("В очередь N%.3u (0x%X) addr:0x%.4X командаMB:%.3u размер:%.3u Dat:0x%.4X свободно:%.2u ждут:%u\n",MB_Rd_cmd,SentQueue,Message.StartAddr,Message.MBFunct,Message.SizeMessage,Message.ucData[0],(unsigned int)uxQueueSpacesAvailable(SentQueue),(unsigned int)uxQueueMessagesWaiting(SentQueue));
			if( xQueueSend( SentQueue, ( void * )&Message, portMAX_DELAY ) != pdPASS ) // передача в очередь сообщения
			{
				USART_TRACE_RED("Ошибка постановки в очередь\n");
			}
		}
	}else{
		USART_TRACE_RED("Нет места (0x%X). addr:%.4X элем.%u свободно %u. нужно %u. ждут %u\n",SentQueue,addr,num,(unsigned int)uxQueueSpacesAvailable(SentQueue),num ,(unsigned int)uxQueueMessagesWaiting(SentQueue));
		return -1;
	}
return num;

err:
	USART_TRACE_RED("!!!!! Нет обработчика.\n");
return -1;
}

/*******************************************************
 * eMBMasterSendMessage
 * передача команды из структуры ModbusMessage
 * LONG lTimeOut RT_WAITING_FOREVER
 *******************************************************/
eMBMasterReqErrCode	eMBMasterSendMessage(ModbusMessage*	Message,LONG lTimeOut)
{
eMBMasterReqErrCode    eStatus = MB_MRE_NO_ERR;

	 switch	(Message->MBFunct){

//команда 3
	 case	MB_FUNC_READ_HOLDING_REGISTER:
#if (defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)) || \
	((defined	(MR761) || defined	(MR762) || defined	(MR763)) && (_REVISION_DEVICE <=302)) ||\
	(defined	(MR771) && (_REVISION_DEVICE <=106)) ||\
	(defined	(MR801) && (_REVISION_DEVICE <=207))||\
	((defined	(MR901) || defined	(MR902)) && (_REVISION_DEVICE <=206))||\
	(defined	(MR851) && (_REVISION_DEVICE <=202))

		 //команда 3
		 eStatus = eMBMasterReqReadHoldingRegister(Message->MBSlaveAddr,Message->StartAddr,Message->SizeMessage,lTimeOut);
#else
//команда 13
		 eStatus = eMBMasterReqReadHoldingRegisterWithAddres(Message->MBSlaveAddr,Message->StartAddr,Message->SizeMessage,lTimeOut);
#endif
   		break;
//команда 13
	 case	MB_FUNC_READ_HOLDING_REGISTER_W_ADDR:
		 eStatus = eMBMasterReqReadHoldingRegisterWithAddres(Message->MBSlaveAddr,Message->StartAddr,Message->SizeMessage,lTimeOut);
		break;

//команда 5
	 case	MB_FUNC_WRITE_SINGLE_COIL:
		 eStatus = eMBMasterReqWriteCoil(Message->MBSlaveAddr,Message->StartAddr,Message->ucData[0],lTimeOut);
		break;

//команда 6
	 case	MB_FUNC_WRITE_REGISTER:
		eStatus = eMBMasterReqWriteHoldingRegister(Message->MBSlaveAddr,Message->StartAddr,Message->ucData[0],lTimeOut);
		break;

//команда 16
	 case	MB_FUNC_WRITE_MULTIPLE_REGISTERS:
   		eStatus = eMBMasterReqWriteMultipleHoldingRegister(Message->MBSlaveAddr,Message->StartAddr,Message->SizeMessage, (USHORT *)&Message->ucData,lTimeOut);
   		break;
	 }

	return	 eStatus;
}

/*****************************************************************************************************
 * Get_AllUstavki
 * читаем все уставки. В некоторых приборах это несколько блоков
 *****************************************************************************************************/
int8_t	Get_AllUstavki(xQueueHandle SentQueue, uint8_t	Slaveaddr){

		changeAddrUstSG(0);

		AddToQueueMB(SentQueue, 	MB_Rd_Syscfg		,MB_Slaveaddr);		// конфигурацию и IP адрес

#if defined (MR801)
			AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,MB_Slaveaddr);			// ставим задачу вычитать новые уставки
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigSW		,MB_Slaveaddr);	// чтение конфигурации выключателя

			AddToQueueMB(SentQueue, 	MB_Rd_ConfigAPW		,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigAWR		,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigTRPWR	,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigTRMeas	,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigVLSIn	,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigVLSOut	,MB_Slaveaddr);

#endif

#if defined (MR851)
			AddToQueueMB(SentQueue, MB_Rd_Ustavki			,MB_Slaveaddr);			// ставим задачу вычитать новые уставки
			AddToQueueMB(SentQueue, MB_Rd_ConfigRPN			,MB_Slaveaddr);			// ставим задачу вычитать параметры привода РПН

#endif

#if defined	(MR771) || defined	(MR761) || defined	(MR762) || defined	(MR763)
			AddToQueueMB(SentQueue, MB_Rd_Ustavki		,MB_Slaveaddr);				// ставим задачу вычитать новые уставки
			AddToQueueMB(SentQueue, MB_Rd_AllUstavki	,Slaveaddr);				// и обшие уставки

#endif

#if defined (MR901) || defined (MR902)
			AddToQueueMB(SentQueue, MB_Rd_Ustavki			,MB_Slaveaddr);			// ставим задачу вычитать новые уставки
#endif

#if defined (MR5_500)
			AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,MB_Slaveaddr);			// ставим задачу вычитать новые уставки
//			AddToQueueMB(SentQueue, 	MB_Rd_ConfigOut		,MB_Slaveaddr);			// не использую
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigExZ		,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigMTZ		,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigI2I1I0	,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigSW		,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,MB_Slaveaddr);			// перенести в уставки
#endif

#if defined (MR5_600)
			AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,MB_Slaveaddr);			// ставим задачу вычитать новые уставки
//			AddToQueueMB(SentQueue, 	MB_Rd_ConfigOut		,MB_Slaveaddr);			// не использую
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigExZ		,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigF		,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigU		,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,MB_Slaveaddr);			// перенести в уставки

#endif

#if defined (MR5_700) || defined (MR741)
			AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,MB_Slaveaddr);			// ставим задачу вычитать новые уставки
//			AddToQueueMB(SentQueue, 	MB_Rd_ConfigOut		,MB_Slaveaddr);			// не использую
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigMTZ		,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigI2I1I0	,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigF		,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigU		,MB_Slaveaddr);
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigExZ		,MB_Slaveaddr);			// перенести в уставки
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigSW		,MB_Slaveaddr);			// перенести в уставки
			AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,MB_Slaveaddr);			// перенести в уставки

#endif

return	true;
}


int	changeAddrUstSG(int	SG){
	// уставки нужно читать только той группы по которой работаем, Выделить одну область памяти
#if defined (MR5_500)
	if (ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSettingGr){
		usConfigStartMTZ 	= MB_StartConfigMTZ_SG1;
		usConfigStartI2I1I0	= MB_StartConfigI2I1I0_SG1;
	}
	 else{
		usConfigStartMTZ 	= MB_StartConfigMTZ_SG0;
		usConfigStartI2I1I0	= MB_StartConfigI2I1I0_SG0;
	 }
#endif
#if defined (MR5_600)
	if (ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSettingGr){

		usConfigStartF		= MB_StartConfigF_SG1;
		usConfigStartU		= MB_StartConfigU_SG1;
		usConfigStartExZ	= MB_StartConfigExZ_SG1;
	}
	 else{
		usConfigStartF		= MB_StartConfigF_SG0;
		usConfigStartU		= MB_StartConfigU_SG0;
		usConfigStartExZ 	= MB_StartConfigExZ_SG0;
	 }
#endif
#if defined (MR5_700) || defined (MR741)
	// уставки нужно читать только той группы по которой работаем, Выделить одну область памяти
	if (ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSettingGr){
		usConfigStartMTZ 	= MB_StartConfigMTZ_SG1;
		usConfigStartI2I1I0	= MB_StartConfigI2I1I0_SG1;
		usConfigStartF		= MB_StartConfigF_SG1;
		usConfigStartU		= MB_StartConfigU_SG1;
	}
	 else{
		usConfigStartMTZ 	= MB_StartConfigMTZ_SG0;
		usConfigStartI2I1I0	= MB_StartConfigI2I1I0_SG0;
		usConfigStartF		= MB_StartConfigF_SG0;
		usConfigStartU		= MB_StartConfigU_SG0;
	 }
#endif
	return true;
}

/*******************************************************
 * AddToQueueMB
 * постановка задачи в очередь,
 * если размер запроса больше максимального пакета модбас (MaxSizeBlok)
 * то дробим запросы на куски.
 *******************************************************/
int8_t	AddToQueueMB_FS(const char* file, uint8_t* 	Data, uint16_t 	numb,uint8_t	mode, FSAfterHandler	handler, void*	parameter){

extern xQueueHandle 	FileSystemQueue;		// очередь для файлов

		FSQueueMessage 	FSMessage;

		FSMessage.file = file;
		FSMessage.Data = Data;
		FSMessage.numb = numb;
		FSMessage.mode = mode;
		FSMessage.handler = handler;
		FSMessage.parameter = parameter;
		if( xQueueSend(FileSystemQueue, ( void * )&FSMessage, portMAX_DELAY ) != pdPASS ) // передача в очередь сообщения
			USART_TRACE_RED("Ошибка постановки в очередь\n");


}
/*************************************************************************
 * QueueMB_GetPageOsc
 * задача чтения страницы осциллографа
 *************************************************************************/
void 	QueueMB_GetPageOsc(void* parameter){

extern  xQueueHandle 	Rd_OscNoteQueue;		// очередь для запросов журналу осциллографа

	AddToQueueMB(Rd_OscNoteQueue, MB_Wrt_OscMessageAdrPg	,MB_Slaveaddr);
	AddToQueueMB(Rd_OscNoteQueue, MB_Rd_OscMessage			,MB_Slaveaddr);
}
