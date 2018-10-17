/*
 * main.c
 *
 *  Created on: 08.08.2014
 *      Author: sagok
 */

//#define _RELEASE_BUILD_NUMBER_ ${build_number}
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "port.h"
#include "queue.h"
#include "semphr.h"
#include "timers.h"
#include "cmsis_os.h"

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_pwr.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_spi.h"
#include "stm32f4xx_it.h"

#include "hal_socket.h"
#include "httpServer.h"

#include "main.h"
//#include "iwdg.h"
//#include "lwip.h"
#include "ethernetif.h"
#include "usart.h"
#include "clocks.h"
#include "gpio.h"

#include "ConfBoard.h"
#include "modbus.h"

// копирование памяти через DMA
#include "memcopy.h"

// память SPI
#include "ExtSPImem.h"
// работа с внутренним флэшем
#include "inflash.h"

// Файловая система
#include "ff.h"

#include "iec61850_server.h"
#include "iec850.h"
#include "lib_memory.h"

/******************************************************************************************
 * глобальный счетчик для измерения загрузки проца
 ******************************************************************************************/
//uint32_t ullHiresTime = 0; /* Is always 0? */
/******************************************************************************************
 ******************************************************************************************/
extern 	IedServer 	iedServer;
extern	Socket		SocketSSH;
extern 	uint32_t	GLOBALMemoryUsedLim;							//максимально использованной памяти
extern	uint32_t	GLOBALMemoryUsedCurr;							//текущее выделение

extern xQueueHandle		xDebugUsartOut;			// очередь бля отправки в юсартдебаг

bool	NextPacketIgnor = false;

// переменные для бутлоадера. Используем память в начале для кода бутлоадера.
uint32_t 		JumpAddress;
pFunction 		Jump_To_Application;

// качаство для всех данных при потере связи МБ
uint16_t		GLOBAL_QUALITY = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
uint16_t		TIMEOUT_MB_FOR_QUALITY = TIMEOUT_MB_Response;

// Часы
RTC_HandleTypeDef 	hrtc;
RTC_TimeTypeDef StartsTime;
RTC_DateTypeDef StartsDate;

// Светодиоды
GPIO_TypeDef* GPIO_PORT[PORTn] = { LED1_GPIO_PORT, LED2_GPIO_PORT, LED3_GPIO_PORT, LED4_GPIO_PORT, LEDtst0_GPIO_PORT, LEDtst1_GPIO_PORT, LEDtst2_GPIO_PORT, RS485_1_DE_GPIO_PORT, RS485_2_DE_GPIO_PORT, MODBUS_DE_GPIO_PORT,LED_OUT_RED_PORT,LED_OUT_GREEN_PORT};
const uint16_t GPIO_PIN[PORTn] = { LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LEDtst0_PIN, LEDtst1_PIN, LEDtst2_PIN, RS485_1_DE, RS485_2_DE, MODBUS_DE,LED_OUT_RED_PIN,LED_OUT_GREEN_PIN};
// шина памяти
GPIO_TypeDef* SRAM_PORT[SRAMn] = {	SRAM_L0_PORT, SRAM_L1_PORT, SRAM_L2_PORT, SRAM_L3_PORT, SRAM_L4_PORT, SRAM_L5_PORT, SRAM_L6_PORT, SRAM_L7_PORT, SRAM_L8_PORT, SRAM_L9_PORT,\
									SRAM_L10_PORT, SRAM_L11_PORT, SRAM_L12_PORT, SRAM_L13_PORT, SRAM_L14_PORT, SRAM_L15_PORT, SRAM_L16_PORT, SRAM_L17_PORT, SRAM_L18_PORT, SRAM_L19_PORT, SRAM_L20_PORT,\
									SRAM_L21_PORT, SRAM_L22_PORT, SRAM_L23_PORT, SRAM_L24_PORT, SRAM_L25_PORT, SRAM_L26_PORT, SRAM_L27_PORT, SRAM_L28_PORT, SRAM_L29_PORT, SRAM_L30_PORT, SRAM_L31_PORT};

const uint16_t SRAM_PIN[SRAMn] = {    SRAM_L0, SRAM_L1, SRAM_L2, SRAM_L3, SRAM_L4, SRAM_L5, SRAM_L6, SRAM_L7, SRAM_L8, SRAM_L9, SRAM_L10\
									, SRAM_L11, SRAM_L12, SRAM_L13, SRAM_L14, SRAM_L15, SRAM_L16, SRAM_L17, SRAM_L18, SRAM_L19, SRAM_L20\
									, SRAM_L21, SRAM_L22, SRAM_L23, SRAM_L24, SRAM_L25, SRAM_L26, SRAM_L27, SRAM_L28, SRAM_L29, SRAM_L30, SRAM_L31};

/******************************************************************************************
 *
 ******************************************************************************************/
char	NamPlt_swRev[32];
volatile uint8_t	MAC_ADDR[6]		= {0,0,0,0,0,0};	//{MAC_ADDR0,MAC_ADDR1,MAC_ADDR2,MAC_ADDR3,MAC_ADDR4,MAC_ADDR5};
volatile uint8_t	IP_ADDR[4] 		= {255,255,255,255};//{192,168,0,254};{192,168,0,252};
volatile uint8_t	NETMASK_ADDR[4]	= {255,255,255,0};
volatile uint8_t	GW_ADDR[4]		= {192,168,0,1};

// SNTP клиент
volatile uint8_t	SNTP_IP_ADDR[4] = {192,168,0,122};	//адрес SNTPсервера
volatile uint16_t	SNTP_Period		= 0;
volatile int8_t		TimeZone_my		= +3;
RTC_TimeTypeDef 	lastSynchTime;						// время последней синхронизации
RTC_DateTypeDef 	lastSynchDate;						// дата последней синхронизации

int16_t				ppm;
int16_t				lostSNTPPackets = 0;
uint8_t				NTP_IP[16];				// = "192.168.000.122";

/*************************************************************************
 * ALL
 *************************************************************************/
#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763) ||\
	defined (MR901) || defined (MR902) ||\
	defined (MR801) ||\
	defined (MR851) ||\
	defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)

//Master mode: База данных часов
uint16_t   usMDateStart = MB_StartDateNaddr;		// адрес
uint16_t   ucMDateBuf[MB_NumbDate];					// буфер для хранения

//Master mode: База данных Версии
uint16_t   usMRevStart = MB_StartRevNaddr;
uint16_t   ucMRevBuf[MB_NumbWordRev];

//Master mode: База данных дискретных сигналов
uint16_t   usMDiscInStart = MB_StartDiscreetaddr;
uint16_t   ucMDiscInBuf[MB_NumbDiscreet]  __attribute__ ((section (".ramint")));

//Master mode: База данных аналоговых сигналов
uint16_t   usMAnalogInStart = MB_StartAnalogINaddr;
uint16_t   ucMAnalogInBuf[MB_NumbAnalog]  __attribute__ ((section (".ramint")));

// журнал системы -----------------------
uint16_t   usWrSysNoteStart = MB_WriteSysNoteaddr;
uint16_t   usSysNoteStart = MB_StartSysNoteaddr;
uint16_t   ucSysNoteBuf[MB_NumbSysNote];
uint16_t   ucSysNoteBufPre[MB_NumbSysNote];								// последняя запись для поиска
uint16_t   ucSysNoteBufNext[MB_NumbSysNote];							// последняя запись

// журнал аварий -----------------------
uint16_t   usErrorNoteStart = MB_StartErrorNoteaddr;
uint16_t   ucErrorNoteBuf[MB_NumbErrorNote];
uint16_t   ucErrorNoteBufPre[MB_NumbErrorNoteTime];
uint16_t   ucErrorNoteBufNext[MB_NumbErrorNoteTime];

// журнал осциллограмм -----------------------
uint16_t   usOscNoteStart = MB_StartOscNoteaddr;
uint16_t   ucOscNoteBuf[MB_NumbOscNote];
uint16_t   ucOscNoteBufPre[MB_NumbOscNoteTime];						// последняя запись для поиска

uint16_t   ucOscNoteCurrNumb = 0;								// текущее число осциллограмм

// осциллограмы -----------------------
// нужно сложить в структуру
uint16_t   usOscBlockStart = MB_StartOscaddr;
uint16_t   ucOscBlockBuf[MB_SizeOscBlock];
uint32_t   ucOscMessSize = 0xFFFFFFFF;							// размер осциллограммы
uint32_t   ucOscMessStart = 0xFFFFFFFF;							// адрес осциллограммы
uint16_t   ucCurrOscPage = 0;									// текущая страница
uint16_t   ucCurrOscAddrOnPage = 0;								// текущий адрес на странице
uint16_t   ucCurrOscSizeOnPage = 0;								// размер на странице

//--------------------------------------

uint16_t   usConfigUstavkiStart = 0xFF;//MB_StartUstavkiaddr0;		// группа уставок
uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];

uint16_t   usConfigOtherUstavkiStart = MB_StartOtherUstavkiaddr;	// прочие общие уставки
uint16_t   ucOtherUstavkiInBuf[MB_NumbOtherUstavki];

uint16_t   usConfigTRPWRStart = MB_StartConfigTRPWR;				// конфигурация силового транса
uint16_t   ucConfigTRPWRBuf[MB_NumbConfigTRPWR];

uint16_t   usConfigTRMeasStart = MB_StartConfigTRMeas;			// конфигурация измерительного транса
uint16_t   ucConfigTRMeasBuf[MB_NumbConfigTRMeas];

uint16_t   usConfigAutomatStart = MB_StartAutomat;				// параметры автоматики
uint16_t   ucMAutomatBuf[MB_NumbAutomat];

uint16_t   usConfigVLSInStart = MB_StartConfigVLSIn;			// чтение конфигурации входных логических сигналов
uint16_t   ucVLSInBuf[MB_NumbConfigVLSIn];

uint16_t   usConfigVLSOutStart = MB_StartConfigVLSOut;			// чтение конфигурации выходных логических сигналов
uint16_t   ucVLSOutBuf[MB_NumbConfigVLSOut];

uint16_t   usConfigStartMTZ = MB_StartConfigMTZ_SG0;		// конфигурация токовых защит
uint16_t   ucConfigBufMTZ[MB_NumbConfigMTZ];

uint16_t   usConfigStartExZ = MB_StartConfigExZ_SG0;		// конфигурация внешних защит
uint16_t   ucConfigBufExZ[MB_NumbConfigExZ];

uint16_t   usConfigStartSWCrash = MB_StartSWCrash;			// ресурс выключателя
uint16_t   ucSWCrash[MB_Size_SWCrash];

uint16_t   usConfigStartSW = MB_StartConfigSW;				// конфигурация Выключателя
uint16_t   ucConfigBufSW[MB_NumbConfigSW];

uint16_t   usSystemCfgStart = MB_StartSystemCfg;			// параметры системы
uint16_t   ucSystemCfgBuf[MB_NumbSystemCfg];

uint16_t   usStartGoose = MB_Startaddr_Goose;				// база гусов для отправки
uint16_t   ucGooseBufSent[MB_NumbGoose];
uint16_t   ucGooseBufDrop[MB_NumbGoose];

uint16_t   usSGStart = MB_Startaddr_SG;						// параметры группы уставок
uint16_t   ucSGBuf[MB_NumbSG];

uint16_t   usConfigAPWStart	= MB_StartConfigAPW;			// конфигурация АПВ
uint16_t   ucConfigAPWBuf[MB_NumbConfigAPW];

uint16_t   usConfigAWRStart = MB_StartConfigAWR;			// конфигурация АВР
uint16_t   ucConfigAWRBuf[MB_NumbConfigAWR];

uint16_t   usRPNStart = MB_StartRPNaddr;
uint16_t   ucRPNBuf[MB_NumbRPN];

uint16_t   usConfigStartF = MB_StartConfigF_SG0;			// конфигурация защиты по частоте
uint16_t   ucConfigBufF[MB_NumbConfigF];

uint16_t   usConfigStartU = MB_StartConfigU_SG0;			// конфигурация защиты по напряжению
uint16_t   ucConfigBufU[MB_NumbConfigU];

uint16_t   usConfigOutStart = MB_StartConfigOut;			// чтение конфигурации выходных сигналов
uint16_t   ucOutSignalBuf[MB_NumbConfigOut];

uint16_t   usConfigStartI2I1I0 = MB_StartConfigI2I1I0_SG0;	// конфигурация Дополнительные защиты
uint16_t   ucConfigBufI2I1I0[MB_NumbConfigI2I1I0];

#endif

/******************************************************************************************
 *
 ******************************************************************************************/
extern  UART_HandleTypeDef  BOOT_UART;

volatile UART_HandleTypeDef MODBUS;				//UART4
volatile UART_HandleTypeDef RS485_1;			//USART2
volatile UART_HandleTypeDef RS485_2;			//USART3

volatile SPI_HandleTypeDef SpiHandle;			// память на шине SPI

volatile uint16_t	xMasterOsEvent;				// хранилище событий порта MODBUS
volatile uint16_t	xMasterOsEventCnt = 0;		// счетчик пропусков из-за ожидания ответа

osMessageQId 		xQueueMODBUSHandle;

/* Private function prototypes -----------------------------------------------*/
void 		FREERTOS_Init(void);
void 		SystemClock_Config(void);
void 		LED_Init(void);
void 		NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);
static void	MemoryException ( void);
/***********************************************************************
 * boot
 ***********************************************************************/
// указание в какой адрес ложить функцию
//__attribute__((__section__(".boot")))
//void boot(void) {
//	static const char boot[] = {};
//}
/***********************************************************************
 * reset
 ***********************************************************************/
void reset(void) {
	NVIC_SystemReset();
}
/***********************************************************************
 * exit
 ***********************************************************************/
void exit(int reason) {

	USART_TRACE_RED("exit.. ok\n");
	  while(1);
}

#define NVIC_VectTab_FLASH           0x08000000
/***********************************************************************
 * main
 * загрузчик проверяет вектора (размер STAM) прошивки и не запустит другой код, не подходящий.
 ***********************************************************************/
int main(void) {

	// временно, для выяснения причины HardFault_Handler
	// закоментить в рабочем коде после выяснения
//	SCnSCB->ACTLR = SCnSCB_ACTLR_DISDEFWBUF_Msk;

	__set_PRIMASK(1);//отключить все прерывания
	    NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x20000); 						//Адрес таблицы относительно начала Flash
	__set_PRIMASK(0);//включить все прерывания

	  HAL_Init();						// инит. Flash и Systick.
	  SystemClock_Config();				// когфиг осциллятора.
	  GPIO_Init();						// конфиг портов.
	  Clocks_Init();					// конфиг часов.

//	  MEMCOPY_DMA_Config();				// инит. ДМА для копирования память-память
	  AT45DB161D_spi_init();			// инит внешней флэшки

	  uint8_t	resetpage;								// ставим признак готовности к работе проги. (0)
	  memory_read((uint8_t *)&resetpage,_Ifboot,1);
	  if (resetpage !=0xFF){
		  memory_write_to_mem((uint8_t *)&resetpage,_Ifboot,1);
//		  USART_TRACE_BLUE("cтавим признак готовности к работе: %u\n",resetpage);
	  }

	  BOOT_UART_Init(2000000);			// настройка BOOT интерфейса.
	  USART_0TRACE("\033[2J\033[1;1H");
	  USART_TRACE("------------------------------------\n");
	  USART_TRACE("%s: %s\n",_swREV,_SWRevision);
	  USART_TRACE("MBspeed: %u\n",MB_Speed);

	  memory_read((uint8_t *)&IP_ADDR[0],_IfIPaddr,4);							// читаем IP из внешней флэшки
	  USART_TRACE_BLUE("flash IP:%d.%d.%d.%d \n", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);

	  if ((IP_ADDR[0] == 0) || (IP_ADDR[1] == 0) || (IP_ADDR[0] == 0xFF) || (IP_ADDR[1] == 0xFF) || (IP_ADDR[2] == 0xFF)|| (IP_ADDR[3] == 0xFF)){
		  IP_ADDR[0] = 192;IP_ADDR[1] = 168;IP_ADDR[2] = 0;IP_ADDR[3] = 254;

			int8_t res = memory_write_to_mem((uint8_t *)&IP_ADDR[0],_IfIPaddr,4);
			if (res == false){
				USART_TRACE_RED("ошибка записи во flash \n");
			}
			USART_TRACE_BLUE("сохраним во flash IP:%d.%d.%d.%d \n", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);
	  }else{
		  // получили вполне реальный адрес но часы будут кривые
	  }

	  memory_read((uint8_t *)&SNTP_IP_ADDR[0],_IfNTP_IP,4);							// читаем SNTP IP из внешней флэшки
	  USART_TRACE_BLUE("flash SNTP IP:%d.%d.%d.%d \n", SNTP_IP_ADDR[0], SNTP_IP_ADDR[1], SNTP_IP_ADDR[2], SNTP_IP_ADDR[3]);
	  sprintf((char *)&NTP_IP,"%d.%d.%d.%d", SNTP_IP_ADDR[0], SNTP_IP_ADDR[1], SNTP_IP_ADDR[2], SNTP_IP_ADDR[3]);

	  memory_read((uint8_t *)&SNTP_Period,_IfNTP_Period,2);
	  USART_TRACE_BLUE("flash SNTP Period :%u \n", SNTP_Period);

	  memory_read((uint8_t *)&TimeZone_my,_IfNTP_TimeZone,1);
	  USART_TRACE_BLUE("flash Часовой пояс:%i \n", TimeZone_my);

	  Port_Init(MODBUS_DEn,GPIO_MODE_INPUT);			// пока не используем

	  LED_Init();										// конфиг светодиодов
	  Port_On(LED_out_RED);

	  Memory_installExceptionHandler((MemoryExceptionHandler)MemoryException,NULL);

	  FREERTOS_Init();					// инит. FREERTOS.
	  osKernelStart();					// Старт планировщика

	while (1) {
	}
	return 0;
}
/*************************************************************************
 * vApplicationStackOverflowHook
 * в случае переполнения стека вызывается.
 *************************************************************************/
void vApplicationStackOverflowHook( xTaskHandle pxTask, signed char *pcTaskName )
{
//	static UBaseType_t WaterMark;
	( void ) pxTask;
	( void ) pcTaskName;

	Port_On(LED1);
	Port_On(LED2);
	Port_On(LED3);
	Port_On(LED4);

    printf("стек переполнен !!!, '%s'\n",pcTaskName);

	while (1) {
		NVIC_SystemReset();
//		Port_Toggle(LED1);
	}

}
/*************************************************************************
 * vApplicationIdleHook
 * ничегонеделанье
 *************************************************************************/
extern void vApplicationIdleHook(void)
{

	const TickType_t xToggleRate = pdMS_TO_TICKS( 1000UL );
	static TickType_t xLastToggle = 0, xTimeNow;

		xTimeNow = xTaskGetTickCount();

		if( ( xTimeNow - xLastToggle ) >= xToggleRate )
		{
			xLastToggle += xToggleRate;
		}
}
/*************************************************************************
 * vApplicationMallocFailedHook
 *************************************************************************/
void vApplicationMallocFailedHook(void)
{
	NVIC_SystemReset();
	for( ;; );
}
/*************************************************************************
* System Clock Configuration
* HSE 8MHz : PLLM = 8 PLLN = 336 PLLP = /2 PLLQ = 7 => HCLK = 168 MHz
* 				APB1 = /4 => PCLK1 							= 42MHz
* 				APB2 = /2 => PCLK1 							= 84MHz
*
* 				TIM2...TIM7,12,13,14 CLK = 2 * PCLK1 		= 84MHz
* 				TIM1,8,9,10,11 CLK = 2 * PCLK2 				= 168MHz
* 				Systick										= 21MHz
*
 *************************************************************************/
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;

  __PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);

#ifndef KSZ8873
  HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSE, RCC_MCODIV_1);
#else
#endif

  // Output HSE divided by 1 on MCO2 pin(PC9)  проверка точности кварца 25MHz + тактовая для ETHERNET контроллера
  HAL_RCC_MCOConfig(RCC_MCO2, RCC_MCO2SOURCE_HSE, RCC_MCODIV_1);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* STM32F405x/407x/415x/417x Revision Z devices: prefetch is supported  */
  if (HAL_GetREVID() == 0x1001)  {
    __HAL_FLASH_PREFETCH_BUFFER_ENABLE();/* Enable the Flash prefetch */
  }
}
/*************************************************************************
 * Port_Init
 *************************************************************************/
void Port_Init(Port_TypeDef Port,uint32_t mode)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  PORTx_GPIO_CLK_ENABLE(Port);

  GPIO_InitStruct.Pin = GPIO_PIN[Port];
  GPIO_InitStruct.Mode = mode;// GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;

  HAL_GPIO_Init(GPIO_PORT[Port], &GPIO_InitStruct);
}
/*************************************************************************
 * Port_On
 *************************************************************************/
void Port_On(Port_TypeDef Port)
{
  HAL_GPIO_WritePin(GPIO_PORT[Port], GPIO_PIN[Port], GPIO_PIN_RESET);
}
/*************************************************************************
 * Port_Off
 *************************************************************************/
void Port_Off(Port_TypeDef Port)
{
  HAL_GPIO_WritePin(GPIO_PORT[Port], GPIO_PIN[Port], GPIO_PIN_SET);
}
/*************************************************************************
 * Port_Toggle
 *************************************************************************/
void Port_Toggle(Port_TypeDef Port)
{
  HAL_GPIO_TogglePin(GPIO_PORT[Port], GPIO_PIN[Port]);
}

/*************************************************************************
 * PUTCHAR_PROTOTYPE
 *************************************************************************/
int __io_putchar(int ch)
{
	if( xQueueSend( xDebugUsartOut, ( void * ) &ch, ( TickType_t ) 10 ) != pdPASS )//portMAX_DELAY
	{
		  return 0;
	}
  return ch;
}
//________________________________________________________
int __io_putfromTask(char *ptr, int len)
{
	if( xQueueSend( xDebugUsartOut, ( void * ) ptr, ( TickType_t ) 10 ) != pdPASS )//portMAX_DELAY
	{
		  return 0;
	}
  return len;
}
//________________________________________________________
int __io_putstrDMA(char *ptr, int len)
{
	if(
		(HAL_UART_GetState(&BOOT_UART) == HAL_UART_STATE_READY)
	)
		{
//		HAL_UART_Transmit_DMA(&BOOT_UART, (uint8_t *)ptr, len);
		HAL_UART_Transmit(&BOOT_UART, (uint8_t *)ptr, len, 0xFFFF);
	}

	// выводим в терминалку
	IsoServer isoServer = (IsoServer)IedServer_getIsoServer(iedServer);
	if (IsoServer_GetSSHConnect(isoServer)){
	 SSH_Transmit(SocketSSH,(uint8_t *)ptr, len);
	}

  return len;
}

/*************************************************************************
 * xGetRunTimeCounterValue
 *************************************************************************/
uint32_t xGetRunTimeCounterValue( void )
{
	return 	( uint32_t ) HAL_GetTick();
}

/*************************************************************************
 * xGetRunTimeCounterValue
 *************************************************************************/
void 	printfTime (void){
	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;
	char WriteBuffer[60];

		HAL_RTC_GetTime((RTC_HandleTypeDef *)&hrtc, &sTime, FORMAT_BIN);			// Читаем время
		HAL_RTC_GetDate((RTC_HandleTypeDef *)&hrtc, &sDate, FORMAT_BIN);			// читаем дату

		uint16_t mst = (999 - (sTime.SubSeconds * 999 / hrtc.Init.SynchPrediv));
																					//GLOBALMemoryUsedLim
		sprintf( WriteBuffer,"0x%.8X 0x%.8X [%02d.%02d.%04d %02d(%02d):%02d:%02d.%03u] ",(unsigned int)&WriteBuffer+50,GLOBALMemoryUsedLim,sDate.Date,sDate.Month,2000+sDate.Year,sTime.Hours,sTime.TimeFormat,sTime.Minutes,sTime.Seconds,(uint16_t)mst);
		USART_0TRACE(WriteBuffer);

}

/*************************************************************************
 * LED_Init
 *************************************************************************/
void LED_Init(void){

	  Port_Init(LED1,GPIO_MODE_OUTPUT_OD);
	  Port_Off(LED1);
	  Port_Init(LED_out_RED,GPIO_MODE_OUTPUT_OD);
	  Port_Off(LED_out_RED);
	  Port_Init(LED_out_GREEN,GPIO_MODE_OUTPUT_OD);
	  Port_Off(LED_out_GREEN);

	  Port_Init(LEDtst0,GPIO_MODE_OUTPUT_PP);
	  Port_Off(LEDtst0);
	  Port_Init(LEDtst1,GPIO_MODE_OUTPUT_PP);
	  Port_Off(LEDtst1);
	  Port_Init(LEDtst2,GPIO_MODE_OUTPUT_PP);
	  Port_Off(LEDtst2);
}

/**
  * @brief  Sets the vector table location and Offset.
  * @param  NVIC_VectTab: specifies if the vector table is in RAM or FLASH memory.
  *   This parameter can be one of the following values:
  *     @arg NVIC_VectTab_RAM
  *     @arg NVIC_VectTab_FLASH
  * @param  Offset: Vector Table base offset field. This value must be a multiple of 0x100.
  * @retval None
  */
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset)
{
  /* Check the parameters */
  assert_param(IS_NVIC_VECTTAB(NVIC_VectTab));
  assert_param(IS_NVIC_OFFSET(Offset));

  SCB->VTOR = NVIC_VectTab | (Offset & (uint32_t)0x1FFFFF80);
}

/*************************************************************************
 * MemoryException
 *************************************************************************/
static void	MemoryException (void)
{
	  USART_TRACE_RED("------------------------\n");
	  USART_TRACE_RED("Ошибка выделения памяти.\n");
	  USART_TRACE_RED("занято до 0x%X\n",(unsigned int)GLOBALMemoryUsedLim);
	  USART_TRACE_RED("------------------------\n");
		while (1) {
			NVIC_SystemReset();
		}
}
