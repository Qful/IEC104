/*
 * main.c
 *
 *  Created on: 08.08.2014
 *      Author: sagok
 */


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
#include "stm32f4xx_hal_pwr.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_spi.h"
#include "stm32f4xx_it.h"

#include "main.h"
//#include "iwdg.h"
//#include "lwip.h"
#include "ethernetif.h"
#include "usart.h"
#include "clocks.h"
#include "gpio.h"

#include "ConfBoard.h"
#include "modbus.h"

// память SPI
#include "ExtSPImem.h"

// Файловая система
#include "ff.h"

#include "iec61850_server.h"
#include "iec850.h"


//__IO uint32_t MSPValue = 0;

// константы во FLASH
//__attribute__((__section__(".eb0rodata"))) const uint8_t userConfig[0x7FFC] = {1,2,3,4,5,6,7,8,9,0};

__attribute__((__section__(".eb0rodata"))) const uint8_t userConfig[0x7FFC];// = {1,2,3,4,5,6,7,8,9,0};
//__attribute__((__section__(".eb0rodata"))) const  uint8_t aTxBuffer[] = " ****UART_TwoBoards communication based on DMA****  ****UART_TwoBoards communication based on DMA****  ****UART_TwoBoards communication based on DMA**** ";


// карта памяти Устройства -----------
//USHORT		Memory_00[1];
//USHORT		Memory_02[7];

//USHORT		Memory_05[17];
//USHORT		Memory_06[0xFF];
//USHORT		Memory_07[0xFF];

// 0x08- 0x0C - Осциллограф
//USHORT		Memory_0D[0xFF];
//USHORT		Memory_0E[0xFF];
//USHORT		Memory_10[0xFF];

// ----------------------------------
//FATFS 	SPIFatFs;  					// File system object for SD card logical drive
//FIL 	SPIFile;     				// File object
//char 	SPIPath[4]; 				// логический путь диска SPI памяти

//static	IedServer iedServer = NULL;

volatile RTC_HandleTypeDef 	hrtc;

// Светодиоды
GPIO_TypeDef* GPIO_PORT[PORTn] = {LED1_GPIO_PORT, LED2_GPIO_PORT, LED3_GPIO_PORT, LED4_GPIO_PORT, RS485_1_DE_GPIO_PORT, RS485_2_DE_GPIO_PORT, MODBUS_DE_GPIO_PORT};
const uint16_t GPIO_PIN[PORTn] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, RS485_1_DE, RS485_2_DE, MODBUS_DE};

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

volatile uint8_t	MAC_ADDR[6]		= {MAC_ADDR0,MAC_ADDR1,MAC_ADDR2,MAC_ADDR3,MAC_ADDR4,MAC_ADDR5};
volatile uint8_t	IP_ADDR[4] 		= {255,255,255,255};//{192,168,0,254};{192,168,0,252};
volatile uint8_t	NETMASK_ADDR[4]	= {255,255,255,0};
volatile uint8_t	GW_ADDR[4]		= {192,168,0,1};

#if defined (MR771)
//Master mode: База данных конфигурации системы
uint16_t   usMConfigSystem = MB_ConfigSystem;		// адрес
uint16_t   ucMConfigSystemBuf[MB_Size_ConfSysytem];	// буфер для хранения конфигурации системы

//Master mode: База данных конфигурации Выключателя
uint16_t   usMConfigSW = MB_ConfigSW;
uint16_t   ucMConfigSWBuf[MB_Size_ConfSW];			// буфер для хранения конфигурации Выключателя


//Master mode: База данных часов
uint16_t   usMDateStart = MB_StartDateNaddr;		// адрес
uint16_t   ucMDateBuf[MB_NumbDate];					// буфер для хранения

//Master mode: База данных Версии
uint16_t   usMRevStart = MB_StartRevNaddr;
uint16_t   ucMRevBuf[MB_NumbWordRev];

//Master mode: База данных дискретных сигналов
uint16_t   usMDiscInStart = MB_StartDiscreetaddr;
uint16_t   ucMDiscInBuf[MB_NumbDiscreet];

//Master mode: База данных аналоговых сигналов
uint16_t   usMAnalogInStart = MB_StartAnalogINaddr;
uint16_t   ucMAnalogInBuf[MB_NumbAnalog];

//Master mode: База уставок транса
uint16_t   usMConfigStartTrans = MB_StartConfig + MB_offset_ConfTrans;
uint16_t   ucMConfigBufTrans[MB_Size_ConfTrans];

//Master mode: Настройки сети
uint16_t   usMConfigStartNaddr = MB_StartConfigNaddr;
uint16_t   ucMConfigNaddrBuf[MB_NumbConfigNaddr];
#elif defined (MR5_700)

uint16_t   usMDateStart = MB_StartDateNaddr;		// адрес
uint16_t   ucMDateBuf[MB_NumbDate];					// буфер для хранения

//Master mode: База данных Версии
uint16_t   usMRevStart = MB_StartRevNaddr;
uint16_t   ucMRevBuf[MB_NumbWordRev];

//Master mode: База данных дискретных сигналов
uint16_t   usMDiscInStart = MB_StartDiscreetaddr;
uint16_t   ucMDiscInBuf[MB_NumbDiscreet];

//Master mode: База данных аналоговых сигналов
uint16_t   usMAnalogInStart = MB_StartAnalogINaddr;
uint16_t   ucMAnalogInBuf[MB_NumbAnalog];

//Master mode: База уставок
uint16_t   usMConfigStart = MB_StartConfigNaddr;
uint16_t   ucMConfigBuf[MB_NumbConfig];

//Master mode: База уставок
uint16_t   usMConfigStartall = MB_StartConfig;
uint16_t   ucMConfigBufall[MB_NumbConfigall];

uint16_t   usMConfigStartSWCrash = MB_StartSWCrash;
uint16_t   ucMSWCrash[MB_NumbSWCrash];


#endif

uint16_t	Ktt,Ktn;
uint16_t	ConfigOffset=0;			// смещение группы уставок
/*
//Master mode: хранилище дискретных входов
USHORT   usMDiscInStart                             = M_DISCRETE_INPUT_START;
#if      M_DISCRETE_INPUT_NDISCRETES%8
UCHAR    ucMDiscInBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_DISCRETE_INPUT_NDISCRETES/8+1];
#else
UCHAR    ucMDiscInBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_DISCRETE_INPUT_NDISCRETES/8];
#endif
//Master mode:Coils variables
USHORT   usMCoilStart                               = M_COIL_START;
#if      M_COIL_NCOILS%8
UCHAR    ucMCoilBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_COIL_NCOILS/8+1];
#else
UCHAR    ucMCoilBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_COIL_NCOILS/8];
#endif
//Master mode: хранилище входных регистров
USHORT   usMRegInStart                              = M_REG_INPUT_START;
USHORT   usMRegInBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_INPUT_NREGS];
//Master mode:хранилище выходных регистров
USHORT   usMRegHoldStart                            = M_REG_HOLDING_START;
USHORT   usMRegHoldBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_HOLDING_NREGS];
*/
/******************************************************************************************
 *
 ******************************************************************************************/
extern UART_HandleTypeDef BOOT_UART;

volatile UART_HandleTypeDef MODBUS;				//UART4
volatile UART_HandleTypeDef RS485_1;			//USART2
volatile UART_HandleTypeDef RS485_2;			//USART3

volatile SPI_HandleTypeDef SpiHandle;			// память на шине SPI

volatile uint16_t	xMasterOsEvent;				// хранилище событий порта MODBUS

extern osThreadId IEC850TaskHandle;
extern osThreadId MBUSTaskHandle;
extern osThreadId CONSOLETaskHandle;

osMessageQId xQueueMODBUSHandle;
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void FREERTOS_Init(void);

int8_t ExtMEM_Test(void);
uint32_t	readAddrLine(void);
int8_t ExtMEM_Init(void);
void LED_Init(void);
/***********************************************************************
 *
 ***********************************************************************/
/*
FRESULT scan_files (char* path)        // Start node to be scanned (also used as work area)
{
    FRESULT res;
    FILINFO fno;
    DIR dir;
    int i;
    char *fn;   // This function is assuming non-Unicode cfg.
	FILINFO FileInfo;


#if _USE_LFN
    static char lfn[_MAX_LFN + 1];   // Buffer to store the LFN
    fno.lfname = lfn;
    fno.lfsize = sizeof lfn;
#endif


    res = f_opendir(&dir, path);                       // Open the directory
    if (res == FR_OK) {
        i = strlen(path);
        for (;;) {
            res = f_readdir(&dir, &fno);                   // Read a directory item
            if (res != FR_OK || fno.fname[0] == 0) break;  // Break on error or end of dir
            if (fno.fname[0] == '.') continue;             // Ignore dot entry
#if _USE_LFN
            fn = *fno.lfname ? fno.lfname : fno.fname;
#else
            fn = fno.fname;
#endif
            if (fno.fattrib & AM_DIR) {                    // It is a directory
                sprintf(&path[i], "/%s", fn);
                res = scan_files(path);
                if (res != FR_OK) {
                	USART_TRACE_RED("Проблемы при сканировании папки:%u\n",res);
                	break;
                }
                path[i] = 0;
            } else {                                       // It is a file.
			    f_stat (fn,&FileInfo);					// Get file status

		//	    fno.fdate = (WORD)(((year - 1980) * 512U) | month * 32U | mday);
		//	    fno.ftime = (WORD)(hour * 2048U | min * 32U | sec / 2U);

			    USART_TRACE("%s%s    Size:%u	%02d:%02d:%u %02d.%02d.%02d \n", path, FileInfo.fname , FileInfo.fsize, FileInfo.fdate & 0x1F,(FileInfo.fdate>>5) & 0x0F, 1980+((FileInfo.fdate>>9) & 0x7F), (FileInfo.ftime>>11) & 0x1F ,(FileInfo.ftime>>5) & 0x3F ,FileInfo.ftime & 0x1F);
            }
        }
        f_closedir(&dir);
    }

    return res;
}
*/

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

/***********************************************************************
 * main
 ***********************************************************************/
int main(void) {

		// запись в FLASH
	//   HAL_FLASH_Unlock();
	//   HAL_FLASH_Program(TYPEPROGRAM_WORD,(uint32_t)&userConfig[0], 100);
	//   HAL_FLASH_Lock();

	  HAL_Init();						// инит. Flash и Systick.
	  SystemClock_Config();				// когфиг осциллятора.
	  GPIO_Init();						// конфиг портов.
	  Clocks_Init();					// конфиг часов.

	  BOOT_UART_Init(921600);			// настройка BOOT интерфейса.
	  USART_0TRACE("\033[2J\033[1;1H");
	  USART_TRACE("------------------------------------\n");
	  USART_TRACE("BOOT_Init.. ok\n");

	  Port_Init(MODBUS_DEn,GPIO_MODE_INPUT);			// пока не используем

	  LED_Init();						// конфиг светодиодов

#ifdef	memtest
	  // ------------------------------------------------------------------------
	  // тест памяти в рабочей версии не будет работать
	  if (ExtMEM_Init()){
		  USART_TRACE_RED("SRAM запаяна с дефектом. Остановка запуска.\n");
		  Port_On(LED1);
		  for(;;){}
	  } else{
		  USART_TRACE_GREEN("SRAM запаяна правильно.\n");
		  for(;;){
		  Port_Toggle(LED1);
		  HAL_Delay(500);
		  }
	  }
#endif


//	  uint16_t* slf = malloc(10);
//	  USART_TRACE_MAGENTA("calloc размер:%d адрес:%X \n",10,(unsigned int)slf);
//	  free(slf);

//	  RS485_1_UART_Init(115200);		// настройка RS485 1 канала.
//	  USART_TRACE("RS485_1_UART_Init.. ok\n");

//  	  RS485_2_UART_Init(115200);		// настройка RS485 2 канала.
//  	  USART_TRACE("RS485_2_UART_Init.. ok\n");

/*
  	  if(FATFS_LinkDriver(&SPIDISK_Driver, SPIPath) == 0){				// линкуем драйвер
  	    if(f_mount(&SPIFatFs, (TCHAR const*)SPIPath, 0) != FR_OK){		// монтируем в устройство
  	    	USART_TRACE("ошибка монтирования диска.\n");
  	    }else{
  	    	USART_TRACE("удачно смонтировали.\n");
  	    	if(0){
  	    	 //if(f_mkfs((TCHAR const*)SPIPath, 0, 0) != FR_OK){			// форматируем
  	    		USART_TRACE("ошибка форматирования диска.\n");
  	    	      }else{
  	    	    	  	   //удачно смонтировали и отформатировали диск
  	    	 		//vOutputDEBUG("отформатировали диск: %s\n",SPIPath);
  	    	 		//if(!f_mkdir("folder1")) USART_TRACE("Создали папку /folder1\n");
  	    	 		//if(!f_mkdir("folder2")) USART_TRACE("Создали папку /folder2\n");
  	    	 		//f_mkdir("sub1/sub2/sub3");
  	    	 		//if(!f_chdir("/folder2
  	    	 		 * ")) USART_TRACE("перешли в папку /folder2\n");

    	    	 	scan_files(SPIPath);

  	    	 		resFile = f_open(&SPIFile, "Health", FA_CREATE_ALWAYS | FA_WRITE);
					f_close(&SPIFile);
 	    	    	resFile = f_open(&SPIFile, "Beh", FA_CREATE_ALWAYS | FA_WRITE);
					f_close(&SPIFile);

	    	 		  if(resFile == FR_OK){
	    	 			 USART_TRACE("Создали файл\n");
						  f_write(&SPIFile, "Проверка записи файла.", sizeof("Проверка записи файла."), NULL);
						  USART_TRACE("записали в него.\n");
						  f_close(&SPIFile);
	    	 		  }
  	    	 		scan_files(SPIPath);
  	    	    	// Vendor

  	    	    	resFile = f_open(&SPIFile, "NamPlt", FA_CREATE_ALWAYS | FA_WRITE);

  	    	 		  if(resFile == FR_OK){
  	    	 			USART_TRACE("Создали файл\n");
						  f_write(&SPIFile, "Проверка записи файла.", sizeof("Проверка записи файла."), NULL);
						  USART_TRACE("записали в него.\n");
						  f_close(&SPIFile);
						  USART_TRACE("Закрыли файл\n");
					  }else
					  if(resFile == FR_INVALID_NAME){
						  USART_TRACE("ошибка создания файла, не правильное имя или путь.\n");
					  }else
					  if(resFile == FR_NO_FILESYSTEM){
						  USART_TRACE("ошибка создания файла, нету FAT\n");
					  }else
					  if(resFile == FR_DENIED){
						  USART_TRACE("ошибка создания файла, Доступ запрещен или каталога полный\n");
					  }else
					  {
						  USART_TRACE("- ошибка создания файла\n");
					  }
  	    	 		scan_files("");

  	    	      }
  	    }
  	  }else{
  		USART_TRACE("ошибка подключения драйвера SPI памяти.\n");
  	  }
*/
	  // тут нужно получить параметры системы от головного(MODBUS) скорости, адреса, порты....

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
	static UBaseType_t WaterMark;
	( void ) pxTask;
	( void ) pcTaskName;

	Port_On(LED1);
	Port_On(LED2);
	Port_On(LED3);
	Port_On(LED4);
//	WaterMark = uxTaskGetStackHighWaterMark(IEC850TaskHandle);
//	WaterMark = uxTaskGetStackHighWaterMark(MBUSTaskHandle);
//	WaterMark = uxTaskGetStackHighWaterMark(CONSOLETaskHandle);
//	   USART_TRACE_RED("стек переполнен !!!\n");
//	USART_TRACE_RED("стек переполнен на  %s !!!\n",(char *)WaterMark);
	while (1) {
		NVIC_SystemReset();
		Port_Toggle(LED1);
	}

}
/*************************************************************************
 * vApplicationIdleHook
 *************************************************************************/
extern void vApplicationIdleHook(void)
{
	const TickType_t xToggleRate = pdMS_TO_TICKS( 1000UL );
	static TickType_t xLastToggle = 0, xTimeNow;

		xTimeNow = xTaskGetTickCount();

		/* As there is not Timer task, toggle the LED 'manually'.  Doing this from	the Idle task will also provide visual feedback of the processor load. */
		if( ( xTimeNow - xLastToggle ) >= xToggleRate )
		{
			Port_Toggle(LED4);
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

#ifdef STM32F407xx
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;								//5
  RCC_OscInitStruct.PLL.PLLN = 336;								//210
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;					//RCC_PLLP_DIV2
  RCC_OscInitStruct.PLL.PLLQ = 7;								// 7
  HAL_RCC_OscConfig(&RCC_OscInitStruct);
#endif
#ifdef STM32F417xx			// HSE = 25MHz
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
#endif

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

#ifdef STM32F407xx
  HAL_GPIO_WritePin(GPIO_PORT[Port], GPIO_PIN[Port], GPIO_PIN_SET);
#else
 #ifdef STM32F417xx
  HAL_GPIO_WritePin(GPIO_PORT[Port], GPIO_PIN[Port], GPIO_PIN_RESET);
 #endif
#endif
}
/*************************************************************************
 * Port_Off
 *************************************************************************/
void Port_Off(Port_TypeDef Port)
{
#ifdef STM32F407xx
  HAL_GPIO_WritePin(GPIO_PORT[Port], GPIO_PIN[Port], GPIO_PIN_RESET);
#else
#ifdef STM32F417xx
  HAL_GPIO_WritePin(GPIO_PORT[Port], GPIO_PIN[Port], GPIO_PIN_SET);
#endif
#endif
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
  HAL_UART_Transmit(&BOOT_UART, (uint8_t *)&ch, 1, 0xFFFF);
  return ch;
}
int __io_putstrDMA(char *ptr, int len)
{
	static	Boot_Ready;


	if((HAL_UART_GetState(&BOOT_UART) == HAL_UART_STATE_READY) &&(Boot_Ready == 0)){

//		HAL_UART_Transmit_DMA(&BOOT_UART, (uint8_t *)ptr, len);
		Boot_Ready = 1;
		HAL_UART_Transmit(&BOOT_UART, (uint8_t *)ptr, len, 0xFFFF);
		Boot_Ready = 0;
	}

  return len;
}

/*************************************************************************
 * xGetRunTimeCounterValue
 *************************************************************************/
uint32_t xGetRunTimeCounterValue( void )
{
//static uint64_t ullHiresTime = 0; /* Is always 0? */

	return ( uint32_t ) (Hal_getTimeInMs());
}

/*************************************************************************
 * xGetRunTimeCounterValue
 *************************************************************************/
void 	printfTime (void){
	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;
	char WriteBuffer[16];

		HAL_RTC_GetTime((RTC_HandleTypeDef *)&hrtc, &sTime, FORMAT_BIN);			// Читаем время
		HAL_RTC_GetDate((RTC_HandleTypeDef *)&hrtc, &sDate, FORMAT_BIN);			// читаем дату

//		char* WriteBuffer = pvPortMalloc(16);

		sprintf( WriteBuffer, "[%02d.%02d.%02d.%04u] ",sTime.Hours,sTime.Minutes,sTime.Seconds,(uint16_t)(3999-sTime.SubSeconds/2) );
		USART_0TRACE(WriteBuffer);

//		vPortFree(WriteBuffer);

}
#ifdef	memtest
/*************************************************************************
 *
 * @return
 *************************************************************************/
uint32_t	readAddrLine(void){
	uint32_t	AddrBUS = 0;
	uint8_t		i,j;
	GPIO_PinState	readpin;
	GPIO_InitTypeDef GPIO_Init_Structure;

	/* Enable GPIOs clock */
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	/* Common GPIO configuration */

	// переводим все порты на вход
	for (i=0;i<SRAMn;i++){
		GPIO_Init_Structure.Pin = SRAM_PIN[i];
		GPIO_Init_Structure.Mode = GPIO_MODE_INPUT;
		GPIO_Init_Structure.Pull = GPIO_PULLUP;
		GPIO_Init_Structure.Speed = GPIO_SPEED_FAST;
		HAL_GPIO_Init(SRAM_PORT[i], &GPIO_Init_Structure);
	}
	// сканируем....
	for (i=0;i<SRAMn;i++){
		GPIO_Init_Structure.Pin = SRAM_PIN[i];
		GPIO_Init_Structure.Mode = GPIO_MODE_OUTPUT_OD;
		GPIO_Init_Structure.Pull = GPIO_NOPULL;
		GPIO_Init_Structure.Speed = GPIO_SPEED_FAST;
		HAL_GPIO_Init(SRAM_PORT[i], &GPIO_Init_Structure);				// переводим на выход
		HAL_GPIO_WritePin(SRAM_PORT[i], SRAM_PIN[i], GPIO_PIN_RESET);	// выводим '1'

		for (j=0;j<SRAMn;j++){
			readpin = HAL_GPIO_ReadPin(SRAM_PORT[j], SRAM_PIN[j]);
			if (readpin == GPIO_PIN_RESET){
				if (i==j) continue;
				else AddrBUS |= (uint32_t)1<<j;
			}
		}

		GPIO_Init_Structure.Pin = SRAM_PIN[i];
		GPIO_Init_Structure.Mode = GPIO_MODE_INPUT;
		GPIO_Init_Structure.Pull = GPIO_PULLUP;
		GPIO_Init_Structure.Speed = GPIO_SPEED_FAST;
		HAL_GPIO_Init(SRAM_PORT[i], &GPIO_Init_Structure);				// переводим на выход

	}
	// если AddrBUS != 0 то закоротка
	return	AddrBUS;
}
/*************************************************************************
 * ExtMEM_Init
 *************************************************************************/
int8_t ExtMEM_Init(void){

		int8_t						ret = false;
		uint32_t					koza;
static	SRAM_HandleTypeDef 			hsram;
static	FSMC_NORSRAM_TimingTypeDef 	SRAM_Timing;

	  //--------------  тест шины адреса памяти на закоротки ----------------------------------------
		koza = readAddrLine();
	  if (koza){
		  USART_TRACE_RED("Замыкание между выводами памяти: 0x%X\n",(unsigned int)koza);
		  ret = true;
	  }

	  /*##-1- Configure the SRAM device ##########################################*/
	  /* SRAM device configuration */
	  hsram.Instance  = FSMC_NORSRAM_DEVICE;
	  hsram.Extended  = FSMC_NORSRAM_EXTENDED_DEVICE;

	  // число HCLK циклов
	  SRAM_Timing.AddressSetupTime       = 5;//2
	  SRAM_Timing.AddressHoldTime        = 1;
	  SRAM_Timing.DataSetupTime          = 5;//2
	  SRAM_Timing.BusTurnAroundDuration  = 1;
	  SRAM_Timing.CLKDivision            = 2;
	  SRAM_Timing.DataLatency            = 2;
	  SRAM_Timing.AccessMode             = FSMC_ACCESS_MODE_A;

	  hsram.Init.NSBank             = FSMC_NORSRAM_BANK1;
	  hsram.Init.DataAddressMux     = FSMC_DATA_ADDRESS_MUX_DISABLE;
	  hsram.Init.MemoryType         = FSMC_MEMORY_TYPE_SRAM;
	  hsram.Init.MemoryDataWidth    = FSMC_NORSRAM_MEM_BUS_WIDTH_8;					// 8 бит шина данных
	  hsram.Init.BurstAccessMode    = FSMC_BURST_ACCESS_MODE_DISABLE;
	  hsram.Init.WaitSignalPolarity = FSMC_WAIT_SIGNAL_POLARITY_LOW;
	  hsram.Init.WrapMode           = FSMC_WRAP_MODE_DISABLE;
	  hsram.Init.WaitSignalActive   = FSMC_WAIT_TIMING_BEFORE_WS;
	  hsram.Init.WriteOperation     = FSMC_WRITE_OPERATION_ENABLE;
	  hsram.Init.WaitSignal         = FSMC_WAIT_SIGNAL_DISABLE;
	  hsram.Init.ExtendedMode       = FSMC_EXTENDED_MODE_DISABLE;
	  hsram.Init.AsynchronousWait   = FSMC_ASYNCHRONOUS_WAIT_DISABLE;
	  hsram.Init.WriteBurst         = FSMC_WRITE_BURST_DISABLE;

	  /* Initialize the SRAM controller */
	  if(HAL_SRAM_Init(&hsram, &SRAM_Timing, &SRAM_Timing) != HAL_OK)
	  {
		  USART_TRACE_RED("SRAM_Init error.\n");
		  //Port_On(LED1);
		  ret = true;
	  } else{
		  USART_TRACE("SRAM_Init OK.. ok\n");
		  if (ExtMEM_Test()) ret = true;					// тест SRAM.
	  }

return ret;
}
#endif

/*************************************************************************
 * LED_Init
 *************************************************************************/
void LED_Init(void){
#ifdef STM32F407xx
	  Port_Init(LED1,GPIO_MODE_OUTPUT_PP);
	  Port_Init(LED2,GPIO_MODE_OUTPUT_PP);
	  Port_Init(LED3,GPIO_MODE_OUTPUT_PP);
	  Port_Init(LED4,GPIO_MODE_OUTPUT_PP);
	  Port_Off(LED1);
#else
	  Port_Init(LED1,GPIO_MODE_OUTPUT_OD);
	  Port_Off(LED1);
#endif
	  USART_TRACE("LED_Init.. ok\n");
}
#ifdef	memtest
/*************************************************************************
 * Buffercmp and Fill_Buffer
 *************************************************************************/
static bool Buffercmp(uint16_t* pBuffer1, uint16_t* pBuffer2, uint16_t BufferLength)
{
  while (BufferLength--)
  {
    if (*pBuffer1 != *pBuffer2)
    {
      return false;
    }

    pBuffer1++;
    pBuffer2++;
  }

  return true;
}
static void Fill_Buffer(uint16_t *pBuffer, uint32_t uwBufferLenght, uint16_t uwOffset)
{
  uint16_t tmpIndex = 0;

  /* Put in global buffer different values */
  for (tmpIndex = 0; tmpIndex < uwBufferLenght; tmpIndex++ )
  {
    pBuffer[tmpIndex] = tmpIndex + uwOffset;
  }
}
/*************************************************************************
 * ExtMEM_Test
 *************************************************************************/
#define BUFFER_SIZE         ((uint32_t)0x0100)
#define WRITE_READ_ADDR     ((uint32_t)0x0800)
#define SRAM_BANK_ADDR      ((uint32_t)0x60000000) //0x64000000

int8_t ExtMEM_Test(void){
	int8_t ret = false,ret1 = false;
	uint16_t	i;
	/* Read/Write Buffers */
	uint16_t aTxBuffer[BUFFER_SIZE];
	uint16_t aRxBuffer[BUFFER_SIZE];
	/* Counter index */
	uint32_t uwIndex = 0;
	/* Status variables */
	__IO uint32_t uwWriteReadStatus = 0;

	  USART_TRACE("SRAM memory read/write test start.\n");

	 /*##-2- SRAM memory read/write access ######################################*/
	  /* Fill the buffer to write */
	  Fill_Buffer(aTxBuffer, BUFFER_SIZE, 0xC20F);
	  USART_TRACE("SRAM Fill_Buffer...\n");

	  /* Write data to the SRAM memory */
	  for (uwIndex = 0; uwIndex < BUFFER_SIZE; uwIndex++)
	  {
	    *(__IO uint16_t*) (SRAM_BANK_ADDR + WRITE_READ_ADDR + 2*uwIndex) = aTxBuffer[uwIndex];
	  }
	  USART_TRACE("Write data to the SRAM memory...\n");


	  /* Read back data from the SRAM memory */
	  for (uwIndex = 0; uwIndex < BUFFER_SIZE; uwIndex++)
	  {
	    aRxBuffer[uwIndex] = *(__IO uint16_t*) (SRAM_BANK_ADDR + WRITE_READ_ADDR + 2*uwIndex);
	  }
	  USART_TRACE("Read back data from the SRAM memory...\n");

	  /*##-3- Checking data integrity ############################################*/
	  uwWriteReadStatus = Buffercmp(aTxBuffer, aRxBuffer, BUFFER_SIZE);
	  USART_TRACE("Checking data integrity...\n");

	  if (uwWriteReadStatus != true)
	  {
	    /* KO */
		  USART_TRACE_RED("Checking data error.\n");
		  //Port_On(LED1);
		  ret = true;
	  }
	  else
	  {
	    /* OK */
//		  USART_TRACE_GREEN("Checking data OK.\n");
		  //Port_Off(LED1);
	  }

	  for(i=0;i<20;i++){
//		  if (i==14) i++;
	    *(__IO uint8_t*) (SRAM_BANK_ADDR + (1<<i)) = 0x55;
	    *(__IO uint8_t*) (SRAM_BANK_ADDR) = 0xAA;
	    aRxBuffer[0] = *(__IO uint8_t*) (SRAM_BANK_ADDR + (1<<i));
	    aRxBuffer[1] = *(__IO uint8_t*) (SRAM_BANK_ADDR);

	    *(__IO uint8_t*) (SRAM_BANK_ADDR) = 0x55;
	    *(__IO uint8_t*) (SRAM_BANK_ADDR + (1<<i)) = 0xAA;
	    aRxBuffer[2] = *(__IO uint8_t*) (SRAM_BANK_ADDR);
	    aRxBuffer[3] = *(__IO uint8_t*) (SRAM_BANK_ADDR + (1<<i));

	    if (aRxBuffer[0] != 0x55)	{ret1 = true;ret=true;}
	    if (aRxBuffer[1] != 0xAA)	{ret1 = true;ret=true;}
	    if (aRxBuffer[2] != 0x55)	{ret1 = true;ret=true;}
	    if (aRxBuffer[3] != 0xAA)	{ret1 = true;ret=true;}

	    if (ret1 == true){
	    	ret1=false;
	    	USART_TRACE_RED("Непропай по линии адреса: A%u\n", i);
	    }
	  }
return ret;
}
#endif

