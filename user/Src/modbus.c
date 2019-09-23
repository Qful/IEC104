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

#include <stdbool.h>

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"
#include "stm32f4xx_hal_tim.h"
#include "stm32f4xx_it.h"

#include "MBTCP_main.h"
#include "main.h"
#include "usart.h"

#include "memcopy.h"		// ����������� ����� ���

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

#include "MBmaster.h"		// ����� ������
/* ----------------------- flash includes ----------------------------------*/
#include "inflash.h"
#include "ExtSPImem.h"

/* ----------------------- Time includes ----------------------------------*/
#include "sntpclient.h"
/* ----------------------- Defines ------------------------------------------*/
#if 0 //defined (MR5_700) || defined (MR5_600) || defined (MR5_500)
#define	RT_TICK_PER_SECOND		20000			//20��� = 50���
#else
#define	RT_TICK_PER_SECOND		1000000			//1��� = 1���
#endif

uint32_t	DataMBPersecondCount = 0;
uint32_t	DataMBPersecond = 0;
uint32_t	TimeStartCount = 0;
/* ----------------------- Variables ----------------------------------------*/
//extern osThreadId MBUSTaskHandle;
// ��������� �� FLASH
//__attribute__((__section__(".eb0rodata"))) const
//extern	uint8_t userConfig[0x7FFC];// = {1,2,3,4,5,6,7,8,9,0};

extern uint16_t		GLOBAL_QUALITY;
extern uint16_t		TIMEOUT_MB_FOR_QUALITY;

extern	errMB_data	cntErrorMD;						// ������� ������

extern 	RTC_HandleTypeDef hrtc;						// ����

extern UART_HandleTypeDef 	MODBUS;
extern UART_HandleTypeDef 	BOOT_UART;

uint8_t		ModbusBuffActive=0;
uint8_t 	Modbus_DataRX[_SizeModbusRX]	__attribute__ ((section (".ramint")));						// ����� �������� Modbus (DMA)
uint8_t 	Modbus_DataRXSlave[_SizeModbusRX]	__attribute__ ((section (".ramint")));					// ������ ����� �������� Modbus (DMA)

//uint8_t 	Modbus_DataTX[_SizeModbusTX]	__attribute__ ((section (".ramint")));						// ����� ����������� Modbus

static volatile uint16_t 	Modbus_SizeRX;			// ������ ���������� ������ �� MODBUS
static volatile uint16_t 	Modbus_AddrRX;			// ����� ���������� ������ �� MODBUS

extern volatile uint16_t	xMasterOsEvent;			// ��������� ������� ����� MODBUS
extern volatile uint16_t	xMasterOsEventCnt;		// ������� ��������� ��-�� �������� ������

static uint32_t usT35TimeOut;

/* Timer handler declaration */
TIM_HandleTypeDef    TimHandle;

#if defined (MR771) || \
	defined (MR761) || defined (MR762) || defined (MR763) || defined (MR761OBR) ||\
	defined (MR801) || \
	defined (MR901) || defined (MR902)|| \
	defined (MR851) ||\
	defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)

extern uint8_t	  writeNmbSG;		// ����� ������ �������.
extern uint8_t	  writeCMDNmb;		// ������� ��� 761���.

extern uint16_t   usErrorNoteStart;
extern uint16_t   usSysNoteStart;
extern uint16_t   usWrSysNoteStart;

extern uint16_t	GlobalAddrSysNote;
extern uint16_t	GlobalAddrErrorNote;
extern uint16_t	GlobalAddrOscNote;

// ������ ������������ -----------------------
extern uint16_t   usOscNoteStart;

extern uint16_t   usOscBlockStart;
extern uint16_t   ucCurrOscPage;				// ������� ��������
extern uint16_t   ucCurrOscAddrOnPage;			// ������� ����� �� ��������
extern uint16_t   ucCurrOscSizeOnPage;			// ������ �� ��������
//-------------------------------------

extern uint16_t   usMDateStart;
extern uint16_t   usMRevStart;
extern uint16_t   usMDiscInStart;
extern uint16_t   usMAnalogInStart;
extern uint16_t   usConfigUstavkiStart;			// ������ �������
extern uint16_t   usConfigOtherUstavkiStart;	// ������ ����� �������

extern uint16_t   usConfigAutomatStart;			// ��������� ����������
extern uint16_t   usSystemCfgStart;				// ��������� �������
extern uint16_t   usConfigTRMeasStart;			// ������������ �������������� ������
extern uint16_t   usSGStart;					// ��������� ������ �������
extern uint16_t   usRPNStart;

extern uint16_t   usConfigOutStart;
extern uint16_t   usConfigStartExZ;
extern uint16_t   usConfigStartF;
extern uint16_t   usConfigStartU;
extern uint16_t   usConfigStartMTZ;
extern uint16_t   usConfigStartI2I1I0;
extern uint16_t   usConfigUROVStart;

extern uint16_t   usConfigStartSW;			// ������������ �����������
extern uint16_t   usConfigStartSWCrash;		// ������ �����������

extern uint16_t   usConfigAPWStart;			// ������������ ���								801
extern uint16_t   usConfigAWRStart;			// ������������ ���								801
extern uint16_t   usConfigTRPWRStart;		// ������������ �������� ������					801
extern uint16_t   usConfigVLSInStart;		// ������������ ������� ���������� ��������		801
extern uint16_t   usConfigVLSOutStart;		// ������������ �������� ���������� ��������	801

extern uint16_t   ucRPNBuf[MB_Size_RPN];
extern uint16_t   ucMDateBuf[MB_Size_Date];
extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];
extern uint16_t   ucSGBuf[MB_Size_SG];
extern uint16_t   ucSWCrash[MB_Size_SWCrash];

extern uint16_t   usStartGoose;					// ���� ����� ��� ��������
extern uint16_t   ucGooseBufSent[MB_Size_Goose];
extern uint16_t   ucGooseBufDrop[MB_Size_Goose];

#endif

extern osMutexId 	xIEC850StartMutex;		// ������� ���������� � ������� TCP/IP

extern xQueueHandle 	FileSystemQueue;		// ������� ��� ������

extern xQueueHandle 	ModbusSentTime;		// ������� ��� �������� � ������
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
 		USART_TRACE_GREEN("���� %u\n",ucPort);
 		USART_TRACE_GREEN("�������� BRR 0x%.4X\n",MODBUS.Instance->BRR);
 		USART_TRACE_GREEN("DIV_Mantissa %u\n",(MODBUS.Instance->BRR)>>4);
 		USART_TRACE_GREEN("DIV_Fraction %u\n",(MODBUS.Instance->BRR)&0x0F);
 		//USART_TRACE_GREEN("USARTDIV %u\n",0);
 		USART_TRACE_GREEN("---------------------------------------------\n");
*/
 		//UART_IT_IDLE ����� �������� ���������� �� ����� � ������. �� ����� � ���������� �������� ������� �������� ������ �� ��� � �������� ������ ����
 		// ��� ������ � ��������� ���������� ������ � �������� ����� � ������ �����

		ModbusBuffActive = 0;
 		HAL_UART_Receive_DMA(&MODBUS, Modbus_DataRX, _SizeModbusRX);			// ������ ����� � DMA

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
 * 	   counter clock at 20 KHz (50 ���)
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
	HAL_StatusTypeDef ret=0;

	portDISABLE_INTERRUPTS();

	uint32_t uwPrescalerValue = (2*HAL_RCC_GetPCLK1Freq()/1000000) - 1;		// 83		// 1��� �������

	TimHandle.Instance 				 = TIM2;
	TimHandle.Init.Period            = (uint32_t) usTimeOut_ns/1000 + 1;
	TimHandle.Init.Prescaler         = uwPrescalerValue;			//�������� �������. ����� ������� ������� ���������. 84���/
	TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;		//TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;			//TIM_COUNTERMODE_UP;
//	TimHandle.Init.RepetitionCounter = 0;
	ret |= HAL_TIM_Base_Init(&TimHandle);
	ret |= HAL_TIM_Base_Start_IT(&TimHandle);

	portENABLE_INTERRUPTS();

	if (ret) USART_TRACE_RED("������ xMBPortTimersInit: %u\n",ret);

	if (ret) 	return false;
	else 		return true;
}
#endif
/*************************************************************************
 * HAL_TIM_Base_MspInit
 *************************************************************************/
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2){
	  __TIM2_CLK_ENABLE();
	  HAL_NVIC_SetPriority(TIM2_IRQn, 6, 0);//7
	  HAL_NVIC_EnableIRQ(TIM2_IRQn);
	}else{
//		Port_Toggle(LED_out_RED);
	}
}

/*************************************************************************
 * xMBMasterPortTimersInit
 * usTimeOut ����� � ������������
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
 * ��������� �������� � ����� � ����
 *************************************************************************/
//TODO: ������� ������������ ����������� �����-��������. ������ DE
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
//	*pucByte = Modbus_DataRX[pos];
	if (ModbusBuffActive == 0)	{*pucByte = Modbus_DataRX[pos];}
	else						{*pucByte = Modbus_DataRXSlave[pos];}

    return TRUE;
}
/*************************************************************************
 * xMBMasterPortSerialGetByte
 *************************************************************************/
BOOL     xMBMasterPortSerialGetByte( CHAR * pucByte )
{
//	*pucByte = Modbus_DataRX[0];
	if (ModbusBuffActive == 0)	{*pucByte = Modbus_DataRX[0];}
	else						{*pucByte = Modbus_DataRXSlave[0];}

    return TRUE;
}
/*************************************************************************
 * xMBMasterPortSerialPutByte
 *************************************************************************/
BOOL     xMBMasterPortSerialPutByte( CHAR ucByte )
{
	HAL_UART_Transmit(&MODBUS, (uint8_t *)&ucByte, 1, 0xFFFF);
    return TRUE;
}
/*************************************************************************
 * xMBMasterPortSerialPutBUF
 * ���� ����� usart �� ���������� HAL_BUSY.
 *************************************************************************/
BOOL     xMBMasterPortSerialPutBUF( CHAR * putBuf, USHORT leng )
{
	HAL_StatusTypeDef	ret;
	BOOL	rt=FALSE;

// �������� ����� ������ ��� ������ ��� �������� ������
//	HAL_UART_DMARXStop(&MODBUS);
//	HAL_UART_Receive_DMA(&MODBUS, Modbus_DataRX, _SizeModbusRX);

	ret = HAL_UART_Transmit_DMA(&MODBUS, (uint8_t *)putBuf, leng);
	if ( ret == HAL_OK){
		rt = TRUE;
	}
	return rt;
}
/*************************************************************************
 * vMBMasterPortTimersRespondTimeoutEnable
 * ����� �������� Slave ������
 * ��� ������ ���� � ������ �������.
 *************************************************************************/
void     vMBMasterPortTimersRespondTimeoutEnable( void )
{
	if (MB_TMODE_STOP == vMBMasterGetCurTimerMode()){
	portDISABLE_INTERRUPTS();
    xMBPortTimersInit(MB_MASTER_TIMEOUT_nS_RESPOND);
    vMBMasterSetCurTimerMode(MB_TMODE_RESPOND_TIMEOUT);
	portENABLE_INTERRUPTS();
	}
}
/*************************************************************************
 * vMBMasterPortTimersAfterRespondTimeoutEnable
 * ������� ����� ������
 *************************************************************************/
void     vMBMasterPortTimersAfterRespondTimeoutEnable( void )
{
	portDISABLE_INTERRUPTS();
	xMBPortTimersInit((uint32_t)_delayAfterResponse*1000000);
	vMBMasterSetCurTimerMode(MB_TMODE_AFTERRESPOND_TIMEOUT);
	portENABLE_INTERRUPTS();
}
/*************************************************************************
 * vMBMasterPortTimersDisable
 *************************************************************************/
void     vMBMasterPortTimersDisable( void )
{
	portDISABLE_INTERRUPTS();
	HAL_TIM_Base_Stop_IT(&TimHandle);
	HAL_TIM_Base_Stop(&TimHandle);
    vMBMasterSetCurTimerMode(MB_TMODE_STOP);
	portENABLE_INTERRUPTS();
}
/*************************************************************************
 * xModbus_Set_Size
 * �������� �������  ������ �� ������
 *************************************************************************/
BOOL            xModbus_Set_SizeAnswer( uint16_t Size, uint16_t Addr )
{
	if (!Size) return FALSE;
	Modbus_SizeRX = Size;
	Modbus_AddrRX = Addr;
	return TRUE;
}
/*************************************************************************
 * xModbus_Get_SizeWaitAnswer
 * ������ ���������� ������ �� �������
 *************************************************************************/
uint16_t   xModbus_Get_SizeWaitingAnswer( uint16_t * Size )
{
	if (Size) *Size = Modbus_SizeRX;
	return Modbus_SizeRX;
}
/*************************************************************************
 * xModbus_Get_SizeAnswer
 * �������� �������  ������ �� ������
 * ���� ������� ����������. >256 ���� ������
 * ����, ���� ������������� ����� ��������, ���� >0x7C �� MB_PDU_REQ_READ_ADDR_OFF
 * ����� �� 1 ���� � �����. ������ ����� ���� �� 2�����
 *************************************************************************/
uint16_t   xModbus_Get_SizeAnswer( uint16_t * Size )
{
uint16_t	SizeRX;

//	SizeRX = Hal_get_SizeMessageFromMB((uint8_t *)Modbus_DataRX);
	if (ModbusBuffActive == 0)	{SizeRX = Hal_get_SizeMessageFromMB((uint8_t *)Modbus_DataRX);}
	else						{SizeRX = Hal_get_SizeMessageFromMB((uint8_t *)Modbus_DataRXSlave);}

	if (Size) *Size = SizeRX;
	return	SizeRX;
}
/*************************************************************************
 * xModbus_Get_AddrAnswer
 * �������� ������ ������ �� ������
 *************************************************************************/
BOOL            xModbus_Get_AddrAnswer( uint16_t * Addr )
{
	*Addr = Modbus_AddrRX;
	return TRUE;
}
/*************************************************************************
 * xMBMasterPortEventPost
 * �������� ������� � ������ �������. ��������� ������������ �������
 *************************************************************************/
BOOL            xMBMasterPortEventPost( eMBMasterEventType eEvent )
{
	portDISABLE_INTERRUPTS();
	xMasterOsEvent |= eEvent;
 //   rt_event_send(&xMasterOsEvent, eEvent);									// �������� ������� � ������ ������� xMasterOsEvent
	portENABLE_INTERRUPTS();
	return TRUE;
}
/*************************************************************************
 * xMBMasterPortEventClear
 * ������� �������.
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
 * ���� ������� � ��������� �������� ��� ���.
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
 * ��� ������� ����� ���������������� �������
 * � �������� ��� ��� �������� ���������� ���������.
 *************************************************************************/
void            vMBMasterOsResInit( void )
{

}
/*************************************************************************
 * xMBMasterPortEventGet
 * ������� ��������� ������� � ��������� xMasterOsEvent
 * � ���������� � *eEvent ����� ������������ �������
 *
 * ����������: �� �������� � �������.
 * 0. EV_MASTER_FRAME_SENT 					- ��������������� ������ ��������������� ����
 *
 * 1. EV_MASTER_EXECUTE						- ������������� �� �������� ������(xMBMasterRTUReceiveFSM) � ���������� �������. ������ ����� ��������� (EV_MASTER_FRAME_RECEIVED)
 * 2. EV_MASTER_FRAME_RECEIVED				- ������ ������������ �� ������ DMA(Modbus_DataRX) � ������� ����� (xMBMasterRTUReceiveFSM)
 * 3. EV_MASTER_FRAME_SENT					- ����������� �������� �������� ������ (EV_MASTER_FRAME_RECEIVE_WAIT)
 * 4. EV_MASTER_READY						-
 * 5. EV_MASTER_ERROR_PROCESS				-
 *
 * ���������� TRUE ���� ���� ���� ���� �������
 *************************************************************************/
BOOL   xMBMasterPortEventGet(  /*@out@ */ eMBMasterEventType * eEvent ){

    uint32_t 	recvedEvent = 0;
    BOOL		status = FALSE;
    uint32_t 	set=0;
    uint16_t	Event;

    // ������������� ����������:
    // 1. ���� ������ ����� (EV_MASTER_FRAME_RECEIVE_WAIT == 0), � ������� ����� ���������, �� ���������� ����� ������.
    // 2. ������������ ������, EV_MASTER_EXECUTE. ������� ��������� ��� �������� � ������ �����.
    // 3. ���� ������ ������ �� ���� EV_MASTER_FRAME_RECEIVED �������� ��������� � ���������� �����.
    // 4. ���� ������ �� ����� ���������� �� ������.
    // 5. ������ � ��������� EV_MASTER_READY.
    // 6. ���� ������ ���, �� ������� ��� ����������.

   	if (WaitPreResponse != eMBTCPGetState())
    {

#if ((defined (MR761) || defined (MR762) || defined	(MR763)) && (_REVISION_DEVICE >303)) || (defined (MR771) && (_REVISION_DEVICE >106))
    // ������������� ����������
     if (status == FALSE){
     		set = EV_MASTER_FRAME_SENT;
        	if (xMasterOsEvent & set) status = TRUE;
     }
     //! ������������� ����������
#endif
    }

    if (status == FALSE){
    	set = EV_MASTER_EXECUTE;
    	if (xMasterOsEvent & set) status = TRUE;
    }
    if (status == FALSE){
     	set = EV_MASTER_FRAME_RECEIVED;
    	if (xMasterOsEvent & set) status = TRUE;
     }

#if ((defined	(MR761) || defined	(MR762) || defined	(MR763)) && (_REVISION_DEVICE >303)) || (defined	(MR771) && (_REVISION_DEVICE >106))
    // ������������� ����������
     //! ������������� ����������
#else
	if (status == FALSE){
		if ((xMasterOsEvent & EV_MASTER_FRAME_RECEIVE_WAIT) == 0){	// ���� ���� ������, �� �� ����� ������ �� ��� ����� ������. ���� ������
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

    // �������������� ��� ��� ������
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
 * ������� ������. ������� ������ � ������ ������ ��������
 *************************************************************************/
void            vMBMasterCBRequestScuuess( void )
{
	Port_On(LED_out_GREEN);
	Port_Off(LED_out_RED);
	TIMEOUT_MB_FOR_QUALITY = TIMEOUT_MB_Response;
//	GLOBAL_QUALITY = QUALITY_VALIDITY_GOOD;
	GLOBAL_QUALITY &= ~(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA | QUALITY_DETAIL_FAILURE);
	if (NULL == iedServer)
		osMutexRelease(xIEC850StartMutex);

}
/*************************************************************************
 * vMBMasterErrorCBExecuteFunction
 *************************************************************************/
void            vMBMasterErrorCBExecuteFunction( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{
	USART_TRACE_RED("------------------------------\n");
	USART_TRACE_RED("ERROR_EXECUTE_FUNCTION. Fnc:0x%.2X, addr:0x%.4X\n",pucPDUData[0],((uint16_t)pucPDUData[1]<<8 | (uint16_t)pucPDUData[2]));
}
/*************************************************************************
 * vMBMasterErrorCBRespondTimeout
 *************************************************************************/
void			vMBMasterErrorCBRespondTimeout( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{
	vMBMasterErrorCBIncCntErr(ucDestAddress,pucPDUData,ucPDULength);		// ������� ������
	xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );							// ��������� ��������

	Port_On(LED_out_RED);													// ������� �������� �� ������ �����
	if 		(TIMEOUT_MB_FOR_QUALITY > 0)	{TIMEOUT_MB_FOR_QUALITY--;}
	else 	{
		TIMEOUT_MB_FOR_QUALITY = TIMEOUT_MB_Response;
		GLOBAL_QUALITY |= QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA;
	}
if(0){
	USART_TRACE_RED("------------------------------\n");
	USART_TRACE_RED("EV_ERROR_RESPOND_TIMEOUT ����� �������������� ������.\n");
	USART_TRACE_RED("");
	uint8_t	i;
	for(i=0;i<ucPDULength;i++) USART_0TRACE("0x%.2X ",pucPDUData[i]);
	USART_0TRACE("\n\n");
}
	xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );			// ��������� ��������

}
/*************************************************************************
 * vMBMasterErrorCBReceiveData
 *************************************************************************/
void            vMBMasterErrorCBReceiveData( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{
	vMBMasterErrorCBIncCntErr(ucDestAddress,pucPDUData,ucPDULength);		// ������� ������
	xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );							// ��������� ��������

	USART_TRACE_RED("------------------------------\n");
	USART_TRACE_RED("ERROR_RECEIVE_DATA ����� �������������� ������.\n");

	USART_TRACE_RED("");
	uint8_t	i;
	for(i=0;i<ucPDULength;i++) USART_0TRACE("0x%.2X ",pucPDUData[i]);
	USART_0TRACE("\n\n");

	xMBMasterPortEventPost( EV_MASTER_FRAME_SENT );			// ��������� ��������
}
/*************************************************************************
 * vMBMasterErrorCBReceiveData
 *************************************************************************/
void		vMBMasterErrorCBSendData( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{
	USART_TRACE_RED("------------------------------\n");
	USART_TRACE_RED("ERROR_SEND_DATA ����� �������� ����� � ���.\n");
}
/*************************************************************************
 * vMBMasterErrorCBIncCntErr
 * ������� ������ �����
 *************************************************************************/
void		vMBMasterErrorCBIncCntErr( UCHAR ucDestAddress, const UCHAR* pucPDUData, USHORT ucPDULength )
{
	uint16_t	adrAnsw = 0;

	adrAnsw |= (uint16_t) pucPDUData[1]<<8;
	adrAnsw |= (uint16_t) pucPDUData[2];
	if (adrAnsw == MB_Addr_Analog) cntErrorMD.errAnalog++;
	if (adrAnsw == MB_Addr_Discreet) cntErrorMD.errDiscreet++;
	if ((adrAnsw >= MB_Addr_DUMP_Ustavki) && (adrAnsw<(MB_Addr_DUMP_Ustavki + MB_Size_DUMP_Ustavki))) cntErrorMD.errUstavki++;
	if ((adrAnsw >= MB_Addr_SysNote) && (adrAnsw<MB_EndSysNoteaddr)) 		cntErrorMD.errJurnal++;
	if ((adrAnsw >= MB_Addr_ErrorNote) && (adrAnsw<MB_EndErrorNoteaddr)) 	cntErrorMD.errJurnal++;
	if ((adrAnsw >= MB_Addr_OscNote) && (adrAnsw<MB_EndOscNoteaddr)) 		cntErrorMD.errJurnal++;

}

/*************************************************************************
 * vMBMasterRunResRelease
 * �������������� �������� ������ ����� ������
 *************************************************************************/
void		vMBMasterRunResRelease( void )
{
//	if (WaitPreResponse == eMBTCPGetState())	eMBTCPSetState(SendRequestWithWait);
}
/*************************************************************************
 * xMBMasterRunResTake
 *
 * EV_MASTER_FRAME_RECEIVE_WAIT ��������� � ���������� � �������� �� �����
 * � eMBMasterPoll ������� ����� ������ � �����. � ���� ������������� ����������.
 * ����� �������� ����� ������.
 *
 * ���� ������ ������������ � �������� �� �������� �� ��������, �� ����� �������� ����� ����������
 * � ���������� ������ � �� ������������� CRC
 *************************************************************************/
BOOL            xMBMasterRunResTake( int32_t time )
{
	uint16_t set;
    BOOL	status = TRUE;
    HAL_UART_StateTypeDef	ustate;

    ustate = HAL_UART_GetState(&MODBUS);
    if ((ustate == HAL_UART_STATE_BUSY_TX)||(ustate == HAL_UART_STATE_BUSY_TX_RX))
	{
										status = FALSE;
	}

    set = EV_MASTER_FRAME_RECEIVE_WAIT;		// ���� ����� ������.
    if ((xMasterOsEvent & set) != 0)  	status = FALSE;

    set = EV_MASTER_ERROR_PROCESS;		// ���� ����� ������.
    if ((xMasterOsEvent & set) != 0)  	status = FALSE;

    if (time == 0 ) 					status = TRUE;

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
 * ����� ����� ������ � DMA, ������� ���� ��� ������
 *************************************************************************/
void vMBMasterPortRecieverDMAStart( uint16_t		size){

}
/*************************************************************************
  * @brief  Tx Transfer completed callback
  * @param  huart: UART handle.
  * @retval None
 *************************************************************************/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart == &MODBUS) {
#if (NewModbusMaster)
		MbMaster_PortTransmitCplt(huart);
#else
		pxMBMasterFrameCBTransmitterEmpty();						// ������ ��� ��������� ������� (xMBMasterRTUTransmitFSM)
#endif
	} else
	if (huart == &BOOT_UART) {

		xDEBUGRTUTransmitFSM();
	}
}
/*************************************************************************
 * HAL_TIM_PeriodElapsedCallback
 * ���������� �������, ����� ���� ��������� ��� �� ����, ����� �������. ��� ������ ����� �� ������ �������� 2 �����.
 * ����� ������ ��� = 0.
 *
 * !!!!!! �� �������� ����� ���������� �����. �.�. ��� ����� �������� ���� ������ � ��������� ������
 * �� ��������� �����, ��� ������� ����������� �� ����� ��� ����� �������.
 *************************************************************************/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
#if (NewModbusMaster)
		MbMaster_TimerExpired();
#else
	if (pxMBMasterPortCBTimerExpired()){			// ���� ���������� ��������� � xMasterOsEvent (��������� ������� ����� MODBUS)

	}
#endif
}
void HAL_TIMEx_BreakCallback(TIM_HandleTypeDef* htim)
{
//	if (pxMBMasterPortCBTimerExpired()){			// ���� ���������� ��������� � xMasterOsEvent (��������� ������� ����� MODBUS)

//	}
}
/*************************************************************************
  * @brief  Rx Transfer completed callback
  * @param  huart: UART handle
  * @retval None
 *************************************************************************/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
/*
	if (huart == &MODBUS) {						// ������������� MODBUS �����
	}
	if (huart == &BOOT_UART) {					// ������������� ����� �� ����� �� DEBUGUASRT
		xDEBUGRTUReceiveFSM();
	}
*/
	USART_TRACE("HAL_UART_RxCpltCallback\n");	// �� ������ � �������
	HAL_UART_IDLECallback(huart);
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
  * ���������� �� ������ 2,5 ������� ����� ������.
 *************************************************************************/
void HAL_UART_IDLECallback(UART_HandleTypeDef *huart){
#if (NewModbusMaster)
// ����� ����� ----------------------------------------
	MbMaster_PortReceived(huart);
#else
uint16_t	Datanumb;													// ����� �������� ���� ������� � DMA
uint16_t	SizeMessage=0;												// ������ ���������

	__HAL_UART_CLEAR_IDLEFLAG(huart);									// ������� ����
	Datanumb = HAL_UART_DataInDMA(huart);								// ����� �������� � DMA ��������

//TODO: �������� ������ ��������������� � Modbus_DataRX ����� ������� HAL_UART_Receive_DMA. ���������� �������� � &huart
//	SizeMessage  = Hal_get_SizeMessageFromMB((uint8_t*)Modbus_DataRX);	// ������ ��������� �� ������ ���������.(���� ������ ��������� ������� 4�����)
	if (ModbusBuffActive == 0)	{SizeMessage  = Hal_get_SizeMessageFromMB((uint8_t*)Modbus_DataRX);}
	else						{SizeMessage  = Hal_get_SizeMessageFromMB((uint8_t*)Modbus_DataRXSlave);}

	if (Datanumb >= SizeMessage){

		HAL_UART_DMARXStop(huart);
		pxMBMasterPortCBStartIdle();									// ������� � ������� � IDLE

		if (ModbusBuffActive == 0){
//			ModbusBuffActive = 1;			// ���� ����� �������
			HAL_UART_Receive_DMA(huart, Modbus_DataRX, _SizeModbusRX);
		}
		else {
			ModbusBuffActive = 0;
			HAL_UART_Receive_DMA(huart, Modbus_DataRXSlave, _SizeModbusRX);
		}

		DataMBPersecondCount += Datanumb;									// ������� �������� ���� (�������� ������)
		if ((HAL_GetTick() - TimeStartCount) > 1000)
		{
			TimeStartCount = HAL_GetTick();
			DataMBPersecond =  DataMBPersecondCount;
			DataMBPersecondCount = 0;
		}
		// �������� ������ ��������� _delayAfterResponse����� ������� ����������� ��� ������
		vMBMasterPortTimersAfterRespondTimeoutEnable();
	}
#endif
}

/*************************************************************************
  * @brief  HAL_UART_DataInDMA
  * ������� ���� ����� � dma
 *************************************************************************/
uint32_t HAL_UART_DataInDMA(UART_HandleTypeDef *huart){
uint32_t	ret;

ret = (uint32_t)huart->RxXferSize - huart->hdmarx->Instance->NDTR;
return	ret;
}

/********************************************************************************************************************************
**MBSlave ������� ***************************************************************************************************************
*********************************************************************************************************************************/

/*************************************************************************
* eMBRegInputCB - ������ �������� �� ���������� ��������� ����� (0x04 Read Input Registers)
 *************************************************************************/
eMBErrorCode eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs ){

	return MB_ENOREG;
}
/*************************************************************************
* eMBRegHoldingCB - ������ �������� �� ���������� ��������� �������� (0x03 Read Holding Registers)
 *************************************************************************/
eMBErrorCode eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode ){

	return MB_ENOREG;
}
/*************************************************************************
* eMBRegCoilsCB - ������ �������� �� ���������� ��������� ������ (0x01 Read Coil Status)
 *************************************************************************/
eMBErrorCode eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils, eMBRegisterMode eMode ){

	return MB_ENOREG;
}
/*************************************************************************
* eMBRegDiscreteCB - ������ �������� �� ���������� ���������� ������ (0x02 Read Discrete Inputs)
 *************************************************************************/
eMBErrorCode eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete ){

	return MB_ENOREG;
}
/********************************************************************************************************************************
**MBMaster ������� **************************************************************************************************************
** ��. user_md_app_m
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
 * ��������� �������� ������ � ����� ���� ������
 * ��� ����� ��������, ��� 16 ��� � 32��� ������. ��� ���������� ��.
************************************************************************************************/
eMBErrorCode eMBMasterToMemDB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, USHORT * pusRegHoldingBuf, USHORT BaseAddress, USHORT BaseNRegs )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    USHORT          iRegIndex;

    usAddress--;

    if ((usAddress >= BaseAddress) && (usAddress + usNRegs <= BaseAddress + BaseNRegs))
    {
        iRegIndex = usAddress - BaseAddress;

        // ��������� ������ � ���������

		while (usNRegs > 0)
		{
			pusRegHoldingBuf[iRegIndex] = *pucRegBuffer++ << 8;
			pusRegHoldingBuf[iRegIndex] |= *pucRegBuffer++;
			iRegIndex++;
			usNRegs--;
		}

//		MEMDMACOPY((uint32_t)&pusRegHoldingBuf[iRegIndex],(uint32_t)pucRegBuffer,usNRegs*2,0);
        //memcpy(&pusRegHoldingBuf[iRegIndex],pucRegBuffer,usNRegs*2);

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
 * ������ ���� ������ �������( callback function)
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
 * ��������� ������� ����� �� ������ MODBUS
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

	//sTime.SubSeconds = (1000 - MDateBuf[6]*10) * hrtc.Init.SynchPrediv / 1000;			// ��� �� ��������, ��� ������ �������������

	HAL_RTC_SetTime(&hrtc, &sTime, FORMAT_BIN);

	sDate.Year = (uint8_t) MDateBuf[0];
	sDate.Month =(uint8_t) MDateBuf[1];
	sDate.Date = (uint8_t) MDateBuf[2];
	sDate.WeekDay = 0;				// ��������� ����� ���, ������ � ����� ���

	HAL_RTC_SetDate(&hrtc, &sDate, FORMAT_BIN);

	if 		(HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)    HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, 1);		// ������ ������. RTC_BKP_DR0 ����� 1
	else {
		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) + 1);						// ���� ��� ��� �� ������ ���, �����������������.
		USART_TRACE_BLUE("����� ����� �� �������. RTC_BKP_DR0: %u\n",HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0));
	}

	return	TRUE;
}
/********************************************************************************************************
 * Hal_Verify_Rev
 * �������� �������.
 *********************************************************************************************************/
int8_t	Hal_Verify_Rev( uint8_t * MDateBuf ){

	int ret = false;
	uint8_t* Revs = (uint8_t*)&_swREV;
	char *	st;

// MR5 ������
	if ((MDateBuf[0] == Revs[0]) && (MDateBuf[1] == Revs[1]) && (MDateBuf[3] == Revs[2])) {
		// ����� ������ _swREVverify � ��������
		st = strstr((char *)MDateBuf,_swREVverify);
		if (st == NULL){
			USART_TRACE_RED("������� ���:'%s %s' ��������� ������ ��� ������������.\n",Revs,_swREVverify);
			ret = false;
		} else{
			ret = true;
		}
		return ret;
	}

// ��������� ������ � ������ ���������

	if ((MDateBuf[3] == Revs[2]) && (MDateBuf[4] == Revs[3]) && (MDateBuf[5] == Revs[4])) {
		ret = true;
	}else{
		USART_TRACE_RED("������� ���:%s ��������� ������ ��� ������������.\n",Revs);
	}
	return ret;
}
/********************************************************************************************************
 * Hal_setIPFromMB_Date
 * ��������� IP ������ �� ������ MODBUS
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

		// ������� �� �������, ������ ���������
		if ((IP_ADDR[0] == 0) || (IP_ADDR[1] == 0) || (IP_ADDR[0] == 0xFF) || (IP_ADDR[1] == 0xFF) || (IP_ADDR[2] == 0xFF)|| (IP_ADDR[3] == 0xFF)){
			  IP_ADDR[0] = 192;IP_ADDR[1] = 168;IP_ADDR[2] = 0;IP_ADDR[3] = 254;

			  memory_write_to_mem((uint8_t *)&IP_ADDR[0],_IfIPaddr,4);
			  USART_TRACE_BLUE("��������� ��������� � �������� �� flash IP:%d.%d.%d.%d \n", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);

			  return	3;
		}

		//Flash_Write((uint8_t *)&IP_ADDR[0],(uint8_t *)&userConfig[_IfIPaddr],4);	// ����� IP �� ���������� ����
		memory_write_to_mem((uint8_t *)&IP_ADDR[0],_IfIPaddr,4);
		USART_TRACE_BLUE("�������� �� flash IP:%d.%d.%d.%d \n", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);


//		osMutexRelease(xIEC850StartMutex);
	}
	return	0;
}
/********************************************************************************************************
 * Hal_setConfSWFromMB_Date
 * ��������� ������� ����������� � ������ �����
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
 * �������� ������ ��������� �� ������ ���������
 *******************************************************/
uint16_t	Hal_get_SizeMessageFromMB( uint8_t * MDateBuf ){
	uint16_t	sz = 0;

// ���� � ������ ��� ������, �� ������ ����� 5 ����
	if (MDateBuf[MB_PDU_REQ_READ_ADDR_OFF]>=MB_FUNC_ERROR){
		sz = 5;
	}

	switch	(MDateBuf[0]){		// �����
// --------------------------------------------------------
// ������� ������
// --------------------------------------------------------
	case	MB_SlaveAddres:
		switch	(MDateBuf[MB_PDU_REQ_READ_ADDR_OFF]){		// ������� ������� 1

// ����� �� ������

// 1,2 �������
		case	MB_FUNC_READ_COILS:
		case	MB_FUNC_READ_DISCRETE_INPUTS:
			sz = MDateBuf[1 + MB_PDU_FUNC_READ_BYTECNT_OFF] + SizeAddr + SizeFunct + SizeNumbByte + SizeCRC;
			break;

// 3,4 �������
		case	MB_FUNC_READ_HOLDING_REGISTER:
		case	MB_FUNC_READ_INPUT_REGISTER:
//			sz = MDateBuf[1 + MB_PDU_FUNC_READ_VALUES_OFF] + SizeAddr + SizeFunct + SizeNumbByte + SizeCRC;
			sz = MDateBuf[1 + MB_PDU_FUNC_READ_BYTECNT_OFF] + SizeAddr + SizeFunct + SizeNumbByte + SizeCRC;
			break;
// 5,6 �������
		case	MB_FUNC_WRITE_SINGLE_COIL:
		case	MB_FUNC_WRITE_REGISTER:
			sz = 8; // ������ 8 ����. ����� //SizeAddr + SizeFunct + SizeMemAddr + SizeNumbWord + SizeCRC;
			break;
// 19 (0x13) �������
		case	MB_FUNC_READ_HOLDING_REGISTER_W_ADDR:
			sz = ( USHORT )( MDateBuf[1 + MB_PDU_FUNC_READ_WORDCNT_OFF] << 8 );
			sz |= ( USHORT )(MDateBuf[1 + MB_PDU_FUNC_READ_WORDCNT_OFF + 1] );
			sz *= 2;
			sz += SizeAddr + SizeFunct + SizeNumbWord + SizeCRC;
			break;
// 15, 16 �������
		case	MB_FUNC_WRITE_MULTIPLE_COILS:
		case	MB_FUNC_WRITE_MULTIPLE_REGISTERS:
			sz = 8; // ������ 8 ����. ����� //SizeAddr + SizeFunct + SizeMemAddr + SizeNumbWord + SizeCRC;
			break;
		}
	break;
// --------------------------------------------------------
// ������� �� �������
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
	}// !switch	(MDateBuf[0]){

	return	sz;
}
#if (NewModbusMaster)
/*******************************************************
 * AddToQueueMB
 * ���������� ������ � �������,
 * ���� ������ ������� ������ ������������� ������ ������ (MaxSizeBlok)
 * �� ������ ������� �� �����.
 *******************************************************/
typedef struct {
	ModbusOwnerType	 owner;		// �������� �������
	uint8_t  slaveaddr;			// ����� ����������
	uint8_t	 func;				// ������� (������� �������)
	uint16_t addr;				// ����� ������� � ����� ������ ����������
	uint8_t* uData;				// ������ ������ ��� �������� (������)

	uint16_t size;				// ����� ���� � ������� ������

	// ��� ����� ��� ������ ������� �������� ������, ������� ������� ������� � ����������� ������ (��������� �������).
	// �������� 1�� ����� ��������� 8� ������� (���� ������ = 124(0x7C)) num=7, end=32
	uint16_t num;				// ����� �������� (��������� ������� �������� �� ����������).
	uint16_t end;				// ������ ���������� ����� (������� �� ������� �� ������ �����)

} multiReq;

/*************************************************************************
 * RequestfromTCPMB
 * ���������� ����� ��������. ��� ������ ���� �� ���������
 *************************************************************************/
multiReq	RequestfromTCPMB(uint16_t	MB_Rd_cmd, uint8_t	Slaveaddr){
	multiReq blocks;

	UCHAR           *ucMBFrameIn;
	UCHAR           *ucMBFrame;
	USHORT   		usLength;

	uint16_t		SizeAnswer;
	uint16_t		SizeData;

	uint16_t		usNRegs;

    xMBTCPPortGetRequest(&ucMBFrameIn,&usLength);				// ��� �������� ����� � �������� �� TCPMB

	vMBMasterGetPDUSndBuf(&ucMBFrame);							// ��� �������� ����� ��� ��������
																// ����� �������� ��������� TCP/MODBUS � ������ ������
	memcpy(ucMBFrame,ucMBFrameIn+MB_SIZE_TCPMB_FRAME,usLength-MB_SIZE_TCPMB_FRAME);

	usLength = usLength - MB_SIZE_TCPMB_FRAME;					// ������� ����� modbus/TCP. �������� ������ ������ ������ ��� crc

// ��������� ������ ������ -------------------------
	switch (ucMBFrame[0]){
	case	1:
	case	2:
		usNRegs = (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF]<<8;
		usNRegs += (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1];
		SizeData = usNRegs/8;													// ������ �������� ������ � ������
		if(usNRegs%8>0) SizeData++;
		SizeAnswer = SizeAddr+SizeFunct+SizeNumbByte+SizeData+SizeCRC;			// ��������� ������ ������		SizeNumbByte/SizeNumbWord ?
		break;
	case	3:
	case	4:
		usNRegs = (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF]<<8;
		usNRegs += (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1];
		SizeData = usNRegs << 1;												// ������ �������� ������ � ������
		SizeAnswer = SizeAddr+SizeFunct+SizeNumbByte+SizeData+SizeCRC;			// ��������� ������ ������		SizeNumbByte/SizeNumbWord ?
		break;
	case	5:
	case	6:
	case	15:
	case	16:
		SizeData = 2;
		SizeAnswer = SizeAddr+SizeFunct+SizeNumbWord+SizeData+SizeCRC;
		break;
	case	19:
		usNRegs = (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF]<<8;
		usNRegs += (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1];
		SizeData = usNRegs << 1;												// ������ �������� ������ � ������
		SizeAnswer = SizeAddr+SizeFunct+SizeNumbWord+SizeData+SizeCRC;			// ��������� ������ ������
		break;
	}
// --------------------------------------------------
	blocks.owner		= MBOWNER_TCPMB;					// �������� �������

	blocks.slaveaddr	= Slaveaddr;						// ����� ����������
	blocks.func			= ucMBFrame[0];						// ������� (������� �������)
	blocks.addr 		= ucMBFrame[1]<<8 | ucMBFrame[2];	// ����� ���������

	blocks.uData		= &ucMBFrame[3];					// ������ ������ ��� ��������, ������� �� �������
	blocks.size			= usLength-3;						// ����� ���� � ������� ������

	blocks.num 			= 0;								// ������ ����� ������ (���� �� ������)
	blocks.end 			= ucMBFrame[3]<<8 | ucMBFrame[4];	// ���������� ���� ��� ���������� (������� ������)

return blocks;
}
/*************************************************************************
 * AddToQueueMB
 *************************************************************************/
int8_t	AddToQueueMB(xQueueHandle SentQueue, uint16_t	MB_Rd_cmd, uint8_t	Slaveaddr){

	int8_t		ret = 0;
	multiReq	blocks;

	MBMessageTransmit	TxMessage;

	blocks.func = 0;
	blocks.addr = 0;

	blocks.num = 0;
	blocks.end = 0;

	blocks.size = 0;
	blocks.uData = NULL;

	blocks.slaveaddr = Slaveaddr;

	switch	(MB_Rd_cmd){

// MB_Wrt_Set_Time -----------------------------------------
	case	MB_Wrt_Set_Time:
		Hal_setTimeToMB_Date(GetDateBuff());
		eMBMasterReq16Fn_new(&TxMessage, MBOWNER_MY, Slaveaddr, GetDateAddr(), GetDateSize(),(uint8_t*)GetDateBuff());
		xQueueSendToFront( SentQueue, (void *)&TxMessage, portMAX_DELAY);	// �������� � ������� ��������� � ������
		goto Qout;
		break;
// MB_Rd_Revision -----------------------------------------
	case MB_Rd_Revision:
		blocks.addr 		= GetRevAddr();
		blocks.num 			= GetRevSize()/GetMaxSizeBlockStandartMB();
		blocks.end 			= GetRevSize() - (blocks.num * GetMaxSizeBlockStandartMB());
		blocks.func			= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;
		blocks.owner		= MBOWNER_MY;
		break;
// MB_Rd_Discreet -----------------------------------------
	case MB_Rd_Discreet:
		blocks.addr 		= GetDiscreetAddr();
		blocks.num 			= GetDiscreetSize()/GetMaxSizeBlockStandartMB();
		blocks.end 			= GetDiscreetSize() - (blocks.num * GetMaxSizeBlockStandartMB());
		blocks.func			= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;
		blocks.owner		= MBOWNER_MY;
		break;
// MB_Rd_Analog -----------------------------------------
	case MB_Rd_Analog:
		blocks.addr 		= GetAnalogAddr();
		blocks.num 			= GetAnalogSize()/GetMaxSizeBlockStandartMB();
		blocks.end 			= GetAnalogSize() - (blocks.num * GetMaxSizeBlockStandartMB());
		blocks.func			= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;
		blocks.owner		= MBOWNER_MY;
		break;
// MB_RdWr_ForTCPMB -----------------------------------------
	case MB_RdWr_ForTCPMB:
		blocks 				= RequestfromTCPMB(MB_Rd_cmd,Slaveaddr);
		break;
// MB_Rd_AllUstavki -----------------------------------------
	case MB_Rd_AllUstavki:
		blocks.addr 		= GetOtherUstavkiAddr();
		blocks.num 			= GetOtherUstavkiSize()/GetMaxSizeBlockStandartMB();
		blocks.end 			= GetOtherUstavkiSize() - (blocks.num * GetMaxSizeBlockStandartMB());
		blocks.func			= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;
		blocks.owner		= MBOWNER_MY;
		break;
// MB_Rd_Get_Time -----------------------------------------
	case MB_Rd_Get_Time:
		blocks.addr 		= GetDateAddr();
		blocks.num 			= GetDateSize()/GetMaxSizeBlockStandartMB();
		blocks.end 			= GetDateSize() - (blocks.num * GetMaxSizeBlockStandartMB());
		blocks.func			= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;
		blocks.owner		= MBOWNER_MY;
		break;


// ������ -----------------------------------------
	default:

		break;

	}
//----------------------------------------------------------
// ������ ������ �� �����
//----------------------------------------------------------
	if (
			blocks.func == 0
/*
			((blocks.func == MB_FUNC_READ_HOLDING_REGISTER)||(blocks.func == MB_FUNC_READ_HOLDING_REGISTER_W_ADDR)) &&
			(blocks.num == 0) &&
			(blocks.addr == 0) &&
			(blocks.end == 0)
*/
		)
	{
		ret = -1;
	}else
	{
		uint8_t		i;
		uint16_t	currAddr;
		uint16_t	currSize;

		if (blocks.end == 0) {
			if (blocks.num) blocks.num--;
		}

		if (blocks.num < uxQueueSpacesAvailable(SentQueue)) {				// ���� ������ � ��������� �������
			for (i=0;i<=blocks.num;i++){									// ������ �� �����
				currAddr = blocks.addr + (GetMaxSizeBlockStandartMB() * i);	// ������� �����
				currSize = GetMaxSizeBlockStandartMB();						// ������� ������

				if ((blocks.end > 0) && (i == blocks.num)) {				// ���� ���� �����
					currSize = blocks.end;
				}

				switch (blocks.func){
				case MB_FUNC_READ_COILS:
					eMBMasterReq1Fn_new(&TxMessage, blocks.owner, blocks.slaveaddr, currAddr, blocks.size);
					break;
				case MB_FUNC_READ_DISCRETE_INPUTS:
					eMBMasterReq2Fn_new(&TxMessage, blocks.owner, blocks.slaveaddr, currAddr, blocks.size);
					break;
				case MB_FUNC_READ_HOLDING_REGISTER:
					eMBMasterReq3Fn_new(&TxMessage, blocks.owner, blocks.slaveaddr, currAddr, currSize);
					break;
				case MB_FUNC_READ_INPUT_REGISTER:
					eMBMasterReq4Fn_new(&TxMessage, blocks.owner, blocks.slaveaddr, currAddr, currSize);
					break;
				case MB_FUNC_WRITE_SINGLE_COIL://5
					eMBMasterReq5Fn_new(&TxMessage, blocks.owner, blocks.slaveaddr, currAddr, (bool)blocks.uData[0]);
					break;
				case MB_FUNC_WRITE_REGISTER:
					eMBMasterReq6Fn_new(&TxMessage, blocks.owner, blocks.slaveaddr, currAddr, blocks.uData[0]);
					break;
				case MB_FUNC_WRITE_MULTIPLE_COILS:
					eMBMasterReq15Fn_new(&TxMessage, blocks.owner, blocks.slaveaddr, currAddr, blocks.size, blocks.uData);
					break;
				case MB_FUNC_WRITE_MULTIPLE_REGISTERS:
					eMBMasterReq16Fn_new(&TxMessage, blocks.owner, blocks.slaveaddr, currAddr, blocks.size, blocks.uData);
					break;
				case MB_FUNC_READ_HOLDING_REGISTER_W_ADDR:
#if defined FUNC_READ_HOLDING_REGISTER_W_ADDR_ON			// ��������� 19 �������
					eMBMasterReq19Fn_new(&TxMessage, blocks.owner, blocks.slaveaddr, currAddr, currSize);
#else
					eMBMasterReq3Fn_new(&TxMessage, blocks.owner, blocks.slaveaddr, currAddr, currSize);
#endif
					break;
				}

				if( xQueueSend(SentQueue,(void *)&TxMessage, portMAX_DELAY) != pdPASS ){
					USART_TRACE_RED("������ ���������� � �������\n");
				}


			}//!for (i=0;i<=blocks.num;i++){
		}//!if (blocks.num <
		else
		{
			USART_TRACE_RED("��� �����(0x%X). addr:%.4X. ��������:%u. �����:%u. ����:%u\n",SentQueue,blocks.addr,(unsigned int)uxQueueSpacesAvailable(SentQueue),blocks.num ,(unsigned int)uxQueueMessagesWaiting(SentQueue));
		}
	}
//----------------------------------------------------------
// ������ ������ �� �����
//----------------------------------------------------------

Qout:
return ret;
}
#else
/*******************************************************
 * AddToQueueMB
 * ���������� ������ � �������,
 * ���� ������ ������� ������ ������������� ������ ������ (MaxSizeBlok)
 * �� ������ ������� �� �����.
 *******************************************************/
int8_t	AddToQueueMB(xQueueHandle SentQueue, uint16_t	MB_Rd_cmd, uint8_t	Slaveaddr){

uint16_t		num = 0;
uint16_t		i;
ModbusMessage 	Message, tmpMessage;
ModbusMessageFull	TCPMessage;
uint16_t		addr = 0,size = 0,end = 0;

	memset(Message.ucData,0,sizeof(Message.ucData)); //�������� ������ ����� ���������, �� ������

	Message.owner = MBOWNER_MY;						 //�������� � �������

	switch	(MB_Rd_cmd){

	case	MB_Wrt_Set_Time:

		addr = MB_Addr_Date;

		Message.MBFunct 	= MB_FUNC_WRITE_MULTIPLE_REGISTERS;
		Message.MBSlaveAddr = Slaveaddr;
		Message.StartAddr = MB_Addr_Date;
		Message.SizeMessage = MB_Size_Date;

		Hal_setTimeToMB_Date((uint16_t *)&ucMDateBuf);
		//memcpy(Message.ucData,ucMDateBuf,MB_Size_Date*2);				// ������� ����������� ������ �����������

		int j=0;
		for (i = 0; i < MB_Size_Date; i++){
			Message.ucData[j++] = (uint8_t)ucMDateBuf[i]>>8;
			Message.ucData[j++] = (uint8_t)ucMDateBuf[i];
		}

		xQueueSendToFront( SentQueue, ( void * )&Message, portMAX_DELAY);	// �������� � ������� ��������� � ������
		return	0;
		break;

	case MB_Rd_Revision:
		addr = MB_Addr_Rev;
		num = MB_Size_Rev;
		num /= MaxSizeBlok;
		end = MB_Size_Rev - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_Discreet:

		addr = usMDiscInStart;
		num = MB_Size_Discreet;
		num /= MaxSizeBlok;
		end = MB_Size_Discreet - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_Analog:

		addr = usMAnalogInStart;
		num = MB_Size_Analog;
		num /= MaxSizeBlok;
		end = MB_Size_Analog - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_RdWr_ForTCPMB:
		// ���������� ����� ��������.
		// ��� ������ ���� �� ���������
		{
		    UCHAR           *ucMBFrameIn;
		    UCHAR           *ucMBFrame;
		    USHORT   		usLength;

		    uint16_t		SizeAnswer;
		    uint16_t		SizeData;

		    uint16_t		usNRegs;

     	   xMBTCPPortGetRequest(&ucMBFrameIn,&usLength);	// ��� �������� ����� � �������� �� TCPMB

	    	vMBMasterGetPDUSndBuf(&ucMBFrame);				// ��� �������� ����� ��� ��������
	    	// ����� �������� ��������� TCP/MODBUS � ������ ������
			memcpy(ucMBFrame,ucMBFrameIn+MB_SIZE_TCPMB_FRAME,usLength-MB_SIZE_TCPMB_FRAME);
//			*ucMBFrame += MB_SIZE_TCPMB_FRAME;
			usLength = usLength - MB_SIZE_TCPMB_FRAME;		// ������� ����� modbus/TCP

			if (usLength-5 > MB_DATA_SIZE_FULL) {
				USART_TRACE_RED("���������� ������� ������ ������� TCPMB\n");
				return -1;
			}

		// ��������� ������ ������
				switch (ucMBFrame[0]){
				case	1:
				case	2:
					usNRegs = (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF]<<8;
					usNRegs += (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1];
					SizeData = usNRegs/8;													// ������ �������� ������ � ������
					if(usNRegs%8>0) SizeData++;
					SizeAnswer = SizeAddr+SizeFunct+SizeNumbByte+SizeData+SizeCRC;			// ��������� ������ ������		SizeNumbByte/SizeNumbWord ?
					break;
				case	3:
				case	4:
					usNRegs = (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF]<<8;
					usNRegs += (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1];
					SizeData = usNRegs << 1;												// ������ �������� ������ � ������
					SizeAnswer = SizeAddr+SizeFunct+SizeNumbByte+SizeData+SizeCRC;			// ��������� ������ ������		SizeNumbByte/SizeNumbWord ?
					break;
				case	5:
				case	6:
				case	15:
				case	16:
					SizeData = 2;
					SizeAnswer = SizeAddr+SizeFunct+SizeNumbWord+SizeData+SizeCRC;
					break;
				case	19:
					usNRegs = (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF]<<8;
					usNRegs += (uint16_t)ucMBFrame[MB_PDU_REQ_READ_REGCNT_OFF + 1];
					SizeData = usNRegs << 1;												// ������ �������� ������ � ������
					SizeAnswer = SizeAddr+SizeFunct+SizeNumbWord+SizeData+SizeCRC;			// ��������� ������ ������
					break;
				}
		// -------------------------
			TCPMessage.owner = MBOWNER_TCPMB;						 					//�������� � �������

			TCPMessage.MBSlaveAddr 	= Slaveaddr;
			TCPMessage.MBFunct 		= ucMBFrame[0];
			TCPMessage.StartAddr	= ucMBFrame[1]<<8 | ucMBFrame[2];					// ����� ���������
			// ������ �� �� ����������, 5,6 ������� �� ����� � ������� �������
			if ((TCPMessage.MBFunct == 5)||(TCPMessage.MBFunct==6)){
				TCPMessage.SizeMessage 	= ucMBFrame[3]<<8 | ucMBFrame[4];
				TCPMessage.ucData[0]	= ucMBFrame[3];
				TCPMessage.ucData[1]	= ucMBFrame[4];
			}else
			if ((TCPMessage.MBFunct == 15)||(TCPMessage.MBFunct==16)){

				TCPMessage.SizeMessage	= ucMBFrame[3]<<8 | ucMBFrame[4];				// ������ ���������, ������ � ������ ������������� ��� � ��������
				memcpy(TCPMessage.ucData,&ucMBFrame[6],usLength-5);

			}else{
				TCPMessage.SizeMessage	= ucMBFrame[3]<<8 | ucMBFrame[4];				// ������ ���������
				memcpy(TCPMessage.ucData,&ucMBFrame[5],usLength-5);
			}

			xQueueSend( SentQueue, ( void * )&TCPMessage, portMAX_DELAY);	// �������� � ������� ���������

			return	usLength;
		}
		break;

	case MB_Rd_AllUstavki:
		//usConfigOtherUstavkiStart
		addr = usConfigOtherUstavkiStart;
		num = (MB_Size_OtherUstavki) / (MaxSizeBlok);
		end = MB_Size_OtherUstavki - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_Get_Time:

		addr = MB_Addr_Date;
		num = MB_Size_Date;
		num /= MaxSizeBlok;					// ���������� ������.
		end = MB_Size_Date - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_Syscfg:

		addr = usSystemCfgStart;//MB_Addr_SystemCfg;
		num = MB_Size_SystemCfg;
		num /= MaxSizeBlok;
		end = MB_Size_SystemCfg - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_Ustavki:

		addr = usConfigUstavkiStart;//MB_StartConfig;				// ������ ��������� ����� �������
		num = MB_Size_Ustavki;
		num /= MaxSizeBlok;
		end = MB_Size_Ustavki - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigSWCrash:
		//usConfigStartSWCrash,MB_NumbSWCrash,
		addr = usConfigStartSWCrash;//MB_Addr_SWCrash;
		num = MB_Size_SWCrash;
		num /= MaxSizeBlok;
		end = MB_Size_SWCrash - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigSW:
		//usConfigStartSW,MB_Size_ConfigSW
		addr = usConfigStartSW;//MB_Addr_ConfigSW;
		num = MB_Size_ConfigSW;
		num /= MaxSizeBlok;
		end = MB_Size_ConfigSW - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_NumbSG:
		addr = usSGStart;
		num = MB_Size_SG;
		num /= MaxSizeBlok;
		end = MB_Size_SG - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

		break;
/*
	case MB_Rd_ConfigOut:
		addr = usConfigOutStart;
		num = MB_Size_ConfigOut;
		num /= MaxSizeBlok;
		end = MB_Size_ConfigOut - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;
*/
	case MB_Rd_ConfigExZ:

		addr = usConfigStartExZ;
		num = MB_NumbConfigExZ;
		num /= MaxSizeBlok;
		end = MB_NumbConfigExZ - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

		break;
	case MB_Rd_ConfigF:

		addr = usConfigStartF;
		num = MB_Size_ConfigF;
		num /= MaxSizeBlok;
		end = MB_Size_ConfigF - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

		break;
	case MB_Rd_ConfigU:

		addr = usConfigStartU;
		num = MB_Size_ConfigU;
		num /= MaxSizeBlok;
		end = MB_Size_ConfigU - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigMTZ:
		//usConfigStartMTZ,MB_NumbConfigMTZ
		addr = usConfigStartMTZ;
		num = MB_NumbConfigMTZ;
		num /= MaxSizeBlok;
		end = MB_NumbConfigMTZ - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigI2I1I0:
		//usConfigStartI2I1I0,MB_NumbConfigI2I1I0
		addr = usConfigStartI2I1I0;
		num = MB_NumbConfigI2I1I0;
		num /= MaxSizeBlok;
		end = MB_NumbConfigI2I1I0 - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigAutomat:
		//usConfigAutomatStart,MB_Size_Automat
		addr = usConfigAutomatStart;
		num = MB_Size_Automat;
		num /= MaxSizeBlok;
		end = MB_Size_Automat - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
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
		num = MB_Size_ConfigAPW;
		num /= MaxSizeBlok;
		end = MB_Size_ConfigAPW - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigAWR:
		addr = usConfigAWRStart;
		num = MB_Size_ConfigAWR;
		num /= MaxSizeBlok;
		end = MB_Size_ConfigAWR - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigTRPWR:
		addr = usConfigTRPWRStart;
		num = MB_Size_ConfigTRPWR;
		num /= MaxSizeBlok;
		end = MB_Size_ConfigTRPWR - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigTRMeas:
		addr = usConfigTRMeasStart;
		num = MB_NumbConfigTRMeas;
		num /= MaxSizeBlok;
		end = MB_NumbConfigTRMeas - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigVLSIn:
		addr = usConfigVLSInStart;
		num = MB_Size_ConfigVLSIn;
		num /= MaxSizeBlok;
		end = MB_Size_ConfigVLSIn - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigVLSOut:
		addr = usConfigVLSOutStart;
		num = MB_Size_ConfigVLSOut;
		num /= MaxSizeBlok;
		end = MB_Size_ConfigVLSOut - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigRPN:
		//usRPNStart,MB_Size_RPN
		addr = usRPNStart;
		num = MB_Size_RPN;
		num /= MaxSizeBlok;
		end = MB_Size_RPN - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_ConfigUROV:
		addr = usConfigUROVStart;
		num = MB_Size_ConfigUROV;
		num /= MaxSizeBlok;
		end = MB_Size_ConfigUROV - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case MB_Rd_SysNote:

		addr = usSysNoteStart;
		num = MB_Size_SysNote;
		num /= MaxSizeBlok;
		end = MB_Size_SysNote - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

//		USART_TRACE_BLUE("MB_Rd_SysNote addr:0x%.4X\n",addr);
		break;

	case MB_Rd_ErrorNote:

		addr = usErrorNoteStart;
		num = MB_Size_ErrorNote;
		num /= MaxSizeBlok;
		end = MB_Size_ErrorNote - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

//		USART_TRACE_BLUE("MB_Rd_ErrorNote addr:0x%.4X\n",addr);
		break;

	case MB_Rd_OscNote:

		addr = usOscNoteStart;
		num = MB_Size_OscNote;
		num /= MaxSizeBlok;
		end = MB_Size_OscNote - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

//		USART_TRACE_BLUE("MB_Rd_OscNote addr:0x%.4X\n",addr);
		break;

	case MB_Rd_OscMessage:

		addr = ucCurrOscAddrOnPage;
		num = ucCurrOscSizeOnPage;//MB_SizeOscBlock;
		num /= MaxSizeBlok;
		end = ucCurrOscSizeOnPage - (num * MaxSizeBlok);

		Message.MBFunct 	= MB_FUNC_READ_HOLDING_REGISTER_W_ADDR;//MB_FUNC_READ_HOLDING_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

		break;


// ------- WRITES --------------------------------------------------
//------------------------------------------------------------------
	case	MB_Wrt_OscMessageAdrPg:
		addr = usOscBlockStart;
		num = 0;
		end = 1;
		Message.ucData[0]	= (uint8_t)(ucCurrOscPage>>8);
		Message.ucData[1]	= (uint8_t)(ucCurrOscPage);
		//Message.SizeMessage	= ucCurrOscPage;

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
		Message.ucData[1]	= 0;
		//Message.SizeMessage	= 0;
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
	case	MB_Wrt_Reset_OscNote:					// ����� ������ � ������� ������������
	case 	MB_Wrt_Reset_SysNote:
	case	MB_Wrt_Reset_ErrorNote:
	case	MB_Wrt_Reset_BLK:						// ������ 851
	case	MB_Wrt_Reset_Ustavki:					// ����� ����� ��������� �������
	case	MB_Wrt_Set_ExtMode:
	case	MB_Wrt_Clr_ExtMode:
	case	MB_Wrt_DRIVE_UP:
	case	MB_Wrt_DRIVE_DWN:
	case	MB_Wrt_SwON:
	case	MB_Wrt_SwOFF:
	case	MB_Wrt_SG_set_0:						// ��� ������ ��������
	case	MB_Wrt_SG_set_1:						// ��� ������ ��������
	case	MB_Wrt_CMD_set_ManNumb:

		if (MB_Rd_cmd == MB_Wrt_Reset_LEDS) 		addr = MB_addr_LEDS_OFF;
		if (MB_Rd_cmd == MB_Wrt_Reset_Error) 		addr = MB_addr_Error_OFF;
		if (MB_Rd_cmd == MB_Wrt_Reset_OscNote) 		addr = MB_addr_OscNote_OFF;
		if (MB_Rd_cmd == MB_Wrt_Reset_SysNote) 		addr = MB_addr_SysNote_OFF;
		if (MB_Rd_cmd == MB_Wrt_Reset_ErrorNote) 	addr = MB_addr_ErrorNote_OFF;
		if (MB_Rd_cmd == MB_Wrt_Reset_BLK) 			addr = MB_addr_BLK_OFF;
		if (MB_Rd_cmd == MB_Wrt_Reset_Ustavki) 		addr = MB_Addr_UstavkiModify;
		if (MB_Rd_cmd == MB_Wrt_Set_ExtMode) 		addr = MB_addr_Set_ExtMode;
		if (MB_Rd_cmd == MB_Wrt_Clr_ExtMode) 		addr = MB_addr_Clr_ExtMode;
		if (MB_Rd_cmd == MB_Wrt_DRIVE_UP) 			addr = MB_addr_DRIVE_UP;
		if (MB_Rd_cmd == MB_Wrt_DRIVE_DWN) 			addr = MB_addr_DRIVE_DWN;
		if (MB_Rd_cmd == MB_Wrt_SwON) 				addr = MB_addr_SwON;
		if (MB_Rd_cmd == MB_Wrt_SwOFF) 				addr = MB_addr_SwOFF;
		if (MB_Rd_cmd == MB_Wrt_SG_set_0) 			addr = MB_Addr_SG_set_0;
		if (MB_Rd_cmd == MB_Wrt_SG_set_1) 			addr = MB_Addr_SG_set_1;
		if (MB_Rd_cmd == MB_Wrt_CMD_set_ManNumb)	addr = (MB_addr_CMD_1_OnOff + writeCMDNmb - 1);
		num = 0;
		end = 0;
		//Message.SizeMessage = MB_CTRL_OFF;
		Message.ucData[0]	= (uint8_t)(MB_CTRL_OFF>>8);
		Message.ucData[1]	= (uint8_t)(MB_CTRL_OFF);

		Message.MBFunct 	= MB_FUNC_WRITE_SINGLE_COIL;
		Message.MBSlaveAddr = Slaveaddr;
		break;

	case	MB_Wrt_SG_set_ManNumb:							// �� ���������� ������ ������� ������������
		addr = MB_Addr_SG;
		num = 0;
		end = 0;

		uint16_t NSG = writeNmbSG - 1;
		Message.ucData[0]	= (uint8_t)(NSG>>8);
		Message.ucData[1]	= (uint8_t)(NSG);
		//Message.SizeMessage	= writeNmbSG - 1;
		Message.MBFunct 	= MB_FUNC_WRITE_REGISTER;
		Message.MBSlaveAddr = Slaveaddr;

		break;

	case	MB_Wrt_Set_Goose:
		{
			int j;
			uint16_t GooseBf;

			addr = MB_Addr_Goose;
			num = MB_Size_Goose;
			num /= MaxSizeBlok;
			end = MB_Size_Goose - (num * MaxSizeBlok);

			if (ucGooseBufSent[0] & 1)	Port_On(LEDtst0);
			else						Port_Off(LEDtst0);

			//Message.ucData[0]	= 0xAA;	//0x55AA;				// �������� ������� �����������
			//Message.ucData[1]	= 0x55;
			Message.ucData[0]	= 0x55;
			Message.ucData[1]	= 0xAA;
			j = 2;
			for(i=0;i<MB_Size_Goose;i++){
			 GooseBf = (ucGooseBufSent[i] &	~ucGooseBufDrop[i]);
			 //Message.ucData[j++] = (uint8_t)(GooseBf);
			 //Message.ucData[j++] = (uint8_t)(GooseBf>>8);
			 Message.ucData[j++] = (uint8_t)(GooseBf>>8);
			 Message.ucData[j++] = (uint8_t)(GooseBf);

			}
			Message.MBFunct 	= MB_FUNC_WRITE_MULTIPLE_REGISTERS;
			Message.MBSlaveAddr = Slaveaddr;
		}
		break;
	}

	//------------------------------------------------------------------
	if (
			((Message.MBFunct == MB_FUNC_READ_HOLDING_REGISTER)||(Message.MBFunct == MB_FUNC_READ_HOLDING_REGISTER_W_ADDR)) &&
			(num == 0) &&
			(addr == 0) &&
			(end == 0)
		)
	{
		// ������ ������
		return -1;
	}
//------------------------------------------------------------------

//------------------------------------------------------------------
	if (num < uxQueueSpacesAvailable(SentQueue)) {							// ���� ������ � ��������� �������
		for (i=0;i<=num;i++){
			Message.StartAddr = addr + MaxSizeBlok*i;
			if (i == num) {
				Message.SizeMessage = end; 									// ���� � ����� 0 ������ �� �����
				if ((end == 0)&&(Message.MBFunct == MB_FUNC_READ_HOLDING_REGISTER)) continue;
				if ((end == 0)&&(Message.MBFunct == MB_FUNC_READ_HOLDING_REGISTER_W_ADDR)) continue;
			}
			else 		  {Message.SizeMessage = MaxSizeBlok;}

			if (uxQueueMessagesWaiting(SentQueue)){							// ���������� � �������
				xQueuePeek(SentQueue,&tmpMessage, portMAX_DELAY);			// ��������� ��������� ���������
				if (SentQueue != ModbusSentTime){
					if (memcmp(&tmpMessage,&Message,7) == 0) {
						USART_TRACE_BLUE("���� ������(0x%X). addr:%.4X �������MB:%.3u\n",(unsigned int)SentQueue,(unsigned int)Message.StartAddr,(unsigned int)Message.MBFunct);
						continue;
					}
				}
			}
			//USART_TRACE("� ������� N%.3u (0x%X) addr:0x%.4X �������MB:%.3u ������:%.3u Dat:0x%.4X ��������:%.2u ����:%u\n",MB_Rd_cmd,SentQueue,Message.StartAddr,Message.MBFunct,Message.SizeMessage,Message.ucData[0],(unsigned int)uxQueueSpacesAvailable(SentQueue),(unsigned int)uxQueueMessagesWaiting(SentQueue));
			if( xQueueSend( SentQueue, ( void * )&Message, portMAX_DELAY ) != pdPASS ) // �������� � ������� ���������
			{
				USART_TRACE_RED("������ ���������� � �������\n");
			}
/*			else{
				USART_TRACE_Yellow("����������:0x%.2X 0x%.2X 0x%.2X\n",Message.MBFunct,Message.StartAddr,Message.SizeMessage);

				// �������� ����� �� ���������� --------------------------
				if (MB_Limit_Ustavki < Message.StartAddr){
					USART_TRACE_RED("������ �� ��������� ������!\n");
				}
			}
*/
		}
	}else{
		USART_TRACE_RED("��� ����� (0x%X). addr:%.4X ����.%u �������� %u. ����� %u. ���� %u\n",SentQueue,addr,num,(unsigned int)uxQueueSpacesAvailable(SentQueue),num ,(unsigned int)uxQueueMessagesWaiting(SentQueue));
		return -1;
	}
return num;

err:
	USART_TRACE_RED("!!!!! ��� �����������.\n");
return -1;
}
#endif

/*******************************************************
 * eMBMasterSendMessage
 * �������� ������� �� ��������� ModbusMessage
 * LONG lTimeOut RT_WAITING_FOREVER
 *
 * ��� ������ �������� ��������� ����� ��� �� ������� ����������. � �������
 * ������ ������������� ���� ����� ������������ CRC � ���������. ��������
 * ��������� ��������� ����� � �� ����� CRC ����������.
 *
 * ����� ��������� ��������� DMA. ��������� ���� hdmatx->State != HAL_DMA_STATE_BUSY
 * HAL_DMA_GetState(&MODBUS);
 *******************************************************/
eMBMasterReqErrCode	eMBMasterSendMessage(ModbusMessageFull*	Message,LONG lTimeOut)
{
eMBMasterReqErrCode    eStatus = MB_MRE_NO_ERR;

USHORT usData;

usData = (USHORT)(Message->ucData[0]<<8) | (USHORT)(Message->ucData[1]);

switch	(Message->MBFunct){

//������� 3
	 case	MB_FUNC_READ_HOLDING_REGISTER:
		 eStatus = eMBMasterReqReadHoldingRegister(Message->MBSlaveAddr,Message->StartAddr,Message->SizeMessage,lTimeOut);
   		break;
//������� 4
	 case	MB_FUNC_READ_INPUT_REGISTER:
		 eStatus = eMBMasterReqReadInputRegister(Message->MBSlaveAddr, Message->StartAddr, Message->SizeMessage, lTimeOut );
		break;
//������� 5
	 case	MB_FUNC_WRITE_SINGLE_COIL:
#if (NewModbusMaster)
		 eStatus = eMBMasterReqWriteCoil(Message->MBSlaveAddr,Message->StartAddr,Message->SizeMessage,lTimeOut);// ����������
#else
		 eStatus = eMBMasterReqWriteCoil(Message->MBSlaveAddr,Message->StartAddr,usData,lTimeOut);
#endif
		break;
//������� 6
	 case	MB_FUNC_WRITE_REGISTER:
#if (NewModbusMaster)
		eStatus = eMBMasterReqWriteHoldingRegister(Message->MBSlaveAddr,Message->StartAddr,Message->SizeMessage,lTimeOut);// ����������
#else
		eStatus = eMBMasterReqWriteHoldingRegister(Message->MBSlaveAddr,Message->StartAddr,usData,lTimeOut);
#endif
		break;

//������� 13
	 case	MB_FUNC_READ_HOLDING_REGISTER_W_ADDR:
#if (defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)) || \
	((defined (MR761) || defined	(MR762) || defined	(MR763)) && (_REVISION_DEVICE <=303)) ||\
	(defined (MR771) && (_REVISION_DEVICE <=106)) ||\
	(defined (MR801) && (_REVISION_DEVICE <=299))||\
	((defined (MR901) || defined	(MR902)) && (_REVISION_DEVICE <=212))||\
	(defined (MR851) && (_REVISION_DEVICE <=202))
		 //������� 3 ������ 13
		 eStatus = eMBMasterReqReadHoldingRegister(Message->MBSlaveAddr,Message->StartAddr,Message->SizeMessage,lTimeOut);
#else
//(defined (MR761OBR))||
		 eStatus = eMBMasterReqReadHoldingRegisterWithAddres(Message->MBSlaveAddr,Message->StartAddr,Message->SizeMessage,lTimeOut);
#endif
		break;
//������� 15
	 case	MB_FUNC_WRITE_MULTIPLE_COILS:
		 eStatus = eMBMasterReqWriteMultipleCoils(Message->MBSlaveAddr, Message->StartAddr, Message->SizeMessage, (UCHAR *)Message->ucData,lTimeOut );
		break;
//������� 16
	 case	MB_FUNC_WRITE_MULTIPLE_REGISTERS:
   		eStatus = eMBMasterReqWriteMultipleHoldingRegister(Message->MBSlaveAddr,Message->StartAddr,Message->SizeMessage, (USHORT *)Message->ucData,lTimeOut);
   		break;
	 }
	return	 eStatus;
}

/*****************************************************************************************************
 * Get_AllUstavki
 * ������ ��� �������. � ��������� �������� ��� ��������� ������
 *****************************************************************************************************/
int8_t	Get_AllUstavki(xQueueHandle SentQueue, uint8_t	Slaveaddr){

		changeAddrUstSG(0);

		AddToQueueMB(SentQueue, 	MB_Rd_Syscfg		,Slaveaddr);		// ������������ � IP �����

#if defined (MR801) && defined (OLD)
		AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,Slaveaddr);			// ������ ������ �������� ����� �������
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigSW		,Slaveaddr);			// ������ ������������ �����������

		AddToQueueMB(SentQueue, 	MB_Rd_ConfigAPW		,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigAWR		,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigTRPWR	,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigTRMeas	,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigVLSIn	,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigVLSOut	,Slaveaddr);

#endif

#if defined (MR801) && defined (T12N5D58R51)
		AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,Slaveaddr);			// ������ ������ �������� ����� �������
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigSW		,Slaveaddr);			// ������ ������������ �����������

		AddToQueueMB(SentQueue, 	MB_Rd_ConfigTRMeas	,Slaveaddr);

		AddToQueueMB(SentQueue, 	MB_Rd_ConfigUROV	,Slaveaddr);

#endif

#if defined (MR851)
		AddToQueueMB(SentQueue, MB_Rd_Ustavki			,Slaveaddr);			// ������ ������ �������� ����� �������
		AddToQueueMB(SentQueue, MB_Rd_ConfigRPN			,Slaveaddr);			// ������ ������ �������� ��������� ������� ���

#endif

#if defined	(MR771) || defined	(MR761) || defined	(MR762) || defined	(MR763) || defined	(MR761OBR)
		AddToQueueMB(SentQueue, MB_Rd_Ustavki		,Slaveaddr);				// ������ ������ �������� ����� �������
		AddToQueueMB(SentQueue, MB_Rd_AllUstavki	,Slaveaddr);				// � ����� �������

#endif

#if defined (MR901) || defined (MR902)
		AddToQueueMB(SentQueue, MB_Rd_Ustavki			,Slaveaddr);			// ������ ������ �������� ����� �������
#endif

#if defined (MR5_500)
		AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,Slaveaddr);			// ������ ������ �������� ����� �������
//		AddToQueueMB(SentQueue, 	MB_Rd_ConfigOut		,Slaveaddr);			// �� ���������
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigExZ		,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigMTZ		,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigI2I1I0	,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigSW		,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,Slaveaddr);			// ��������� � �������
#endif

#if defined (MR5_600)
		AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,Slaveaddr);			// ������ ������ �������� ����� �������
//		AddToQueueMB(SentQueue, 	MB_Rd_ConfigOut		,Slaveaddr);			// �� ���������
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigExZ		,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigF		,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigU		,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,Slaveaddr);			// ��������� � �������

#endif

#if defined (MR5_700) || defined (MR741)
		AddToQueueMB(SentQueue, 	MB_Rd_Ustavki		,Slaveaddr);			// ������ ������ �������� ����� �������
//		AddToQueueMB(SentQueue, 	MB_Rd_ConfigOut		,Slaveaddr);			// �� ���������
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigMTZ		,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigI2I1I0	,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigF		,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigU		,Slaveaddr);
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigExZ		,Slaveaddr);			// ��������� � �������
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigSW		,Slaveaddr);			// ��������� � �������
		AddToQueueMB(SentQueue, 	MB_Rd_ConfigAutomat	,Slaveaddr);			// ��������� � �������

#endif

return	true;
}


int	changeAddrUstSG(int	SG){
	// ������� ����� ������ ������ ��� ������ �� ������� ��������, �������� ���� ������� ������
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
		usConfigStartF		= MB_Addr_ConfigF;
		usConfigStartU		= MB_Addr_ConfigU;
		usConfigStartExZ 	= MB_StartConfigExZ_SG0;
	 }
#endif
#if defined (MR5_700) || defined (MR741)
	// ������� ����� ������ ������ ��� ������ �� ������� ��������, �������� ���� ������� ������
	if (ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSettingGr){
		usConfigStartMTZ 	= MB_StartConfigMTZ_SG1;
		usConfigStartI2I1I0	= MB_StartConfigI2I1I0_SG1;
		usConfigStartF		= MB_StartConfigF_SG1;
		usConfigStartU		= MB_StartConfigU_SG1;
	}
	 else{
		usConfigStartMTZ 	= MB_StartConfigMTZ_SG0;
		usConfigStartI2I1I0	= MB_StartConfigI2I1I0_SG0;
		usConfigStartF		= MB_Addr_ConfigF;
		usConfigStartU		= MB_Addr_ConfigU;
	 }
#endif
	return true;
}

/*******************************************************
 * AddToQueueMB
 * ���������� ������ � �������,
 * ���� ������ ������� ������ ������������� ������ ������ (MaxSizeBlok)
 * �� ������ ������� �� �����.
 *******************************************************/
int8_t	AddToQueueMB_FS(const char* file, uint8_t* 	Data, uint16_t 	numb,uint8_t	mode, FSAfterHandler	handler, void*	parameter){

		FSQueueMessage 	FSMessage;

		FSMessage.file = file;
		FSMessage.Data = Data;
		FSMessage.numb = numb;
		FSMessage.mode = mode;
		FSMessage.handler = handler;
		FSMessage.parameter = parameter;
		if (FileSystemQueue != NULL){
			if( xQueueSend(FileSystemQueue, ( void * )&FSMessage, portMAX_DELAY ) != pdPASS ) // �������� � ������� ���������
				USART_TRACE_RED("������ ���������� � �������\n");
		}else{
			USART_TRACE_RED("������� FileSystemQueue �� �������.\n");
		}


}
/*************************************************************************
 * QueueMB_GetPageOsc
 * ������ ������ �������� ������������
 *************************************************************************/
void 	QueueMB_GetPageOsc(void* parameter){

extern  xQueueHandle 	Rd_OscNoteQueue;		// ������� ��� �������� ������� ������������

	AddToQueueMB(Rd_OscNoteQueue, MB_Wrt_OscMessageAdrPg	,MB_Slaveaddr);
	AddToQueueMB(Rd_OscNoteQueue, MB_Rd_OscMessage			,MB_Slaveaddr);
}
/*************************************************************************
 * GetMaxSizeBlockStandartMB
 *************************************************************************/
uint16_t	GetMaxSizeBlockStandartMB(void){
	return	MaxSizeBlok;
}

/*******************************************************
 * GetModbus_DataRX_Buf
 *******************************************************/
uint8_t*	GetModbus_DataRX_Buf(void){

	return Modbus_DataRX;
}
