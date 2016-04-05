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
#include "at45db161d.h"


#include "iec61850_server.h"
#include "iec850.h"

// карта памяти Устройства -----------
USHORT		Memory_00[1];
USHORT		Memory_02[7];

USHORT		Memory_05[17];
USHORT		Memory_06[0xFF];
USHORT		Memory_07[0xFF];

// 0x08- 0x0C - Осциллограф
USHORT		Memory_0D[0xFF];
USHORT		Memory_0E[0xFF];
USHORT		Memory_10[0xFF];

// ----------------------------------
FATFS 	SPIFatFs;  					// File system object for SD card logical drive
FIL 	SPIFile;     				// File object
char 	SPIPath[4]; 				// логический путь диска SPI памяти

IedServer iedServer = NULL;

RTC_HandleTypeDef 	hrtc;

// Светодиоды
GPIO_TypeDef* GPIO_PORT[PORTn] = {LED1_GPIO_PORT, LED2_GPIO_PORT, LED3_GPIO_PORT, LED4_GPIO_PORT, RS485_1_DE_GPIO_PORT, RS485_2_DE_GPIO_PORT, MODBUS_DE_GPIO_PORT};
const uint16_t GPIO_PIN[PORTn] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, RS485_1_DE, RS485_2_DE, MODBUS_DE};

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

extern UART_HandleTypeDef BOOT_UART;

volatile UART_HandleTypeDef MODBUS;				//UART4
volatile UART_HandleTypeDef RS485_1;			//USART2
volatile UART_HandleTypeDef RS485_2;			//USART3

volatile SPI_HandleTypeDef SpiHandle;			// память на шине SPI

volatile uint16_t	xMasterOsEvent;				// хранилище событий порта MODBUS

osMessageQId xQueueMODBUSHandle;
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void FREERTOS_Init(void);

/***********************************************************************
 *
 ***********************************************************************/
FRESULT scan_files (char* path)        /* Start node to be scanned (also used as work area) */
{
    FRESULT res;
    FILINFO fno;
    DIR dir;
    int i;
    char *fn;   /* This function is assuming non-Unicode cfg. */
	FILINFO FileInfo;


#if _USE_LFN
    static char lfn[_MAX_LFN + 1];   /* Buffer to store the LFN */
    fno.lfname = lfn;
    fno.lfsize = sizeof lfn;
#endif


    res = f_opendir(&dir, path);                       /* Open the directory */
    if (res == FR_OK) {
        i = strlen(path);
        for (;;) {
            res = f_readdir(&dir, &fno);                   /* Read a directory item */
            if (res != FR_OK || fno.fname[0] == 0) break;  /* Break on error or end of dir */
            if (fno.fname[0] == '.') continue;             /* Ignore dot entry */
#if _USE_LFN
            fn = *fno.lfname ? fno.lfname : fno.fname;
#else
            fn = fno.fname;
#endif
            if (fno.fattrib & AM_DIR) {                    /* It is a directory */
                sprintf(&path[i], "/%s", fn);
                res = scan_files(path);
                if (res != FR_OK) {
                	USART_TRACE_RED("Проблемы при сканировании папки:%u\n",res);
                	break;
                }
                path[i] = 0;
            } else {                                       /* It is a file. */
			    f_stat (fn,&FileInfo);					/* Get file status */

		//	    fno.fdate = (WORD)(((year - 1980) * 512U) | month * 32U | mday);
		//	    fno.ftime = (WORD)(hour * 2048U | min * 32U | sec / 2U);

			    USART_TRACE("%s%s    Size:%u	%02d:%02d:%u %02d.%02d.%02d \n", path, FileInfo.fname , FileInfo.fsize, FileInfo.fdate & 0x1F,(FileInfo.fdate>>5) & 0x0F, 1980+((FileInfo.fdate>>9) & 0x7F), (FileInfo.ftime>>11) & 0x1F ,(FileInfo.ftime>>5) & 0x3F ,FileInfo.ftime & 0x1F);
            }
        }
        f_closedir(&dir);
    }

    return res;
}
/***********************************************************************
 * main
 ***********************************************************************/
int main(void) {

	FRESULT		resFile;


	  HAL_Init();						// инит. Flash и Systick.
	  SystemClock_Config();				// когфиг осциллятора.
	  GPIO_Init();						// конфиг портов.
	  Clocks_Init();					// конфиг часов.

	  BOOT_UART_Init(115200);			// настройка BOOT интерфейса.
//	  USART_0TRACE("\033[0;0H");

	  USART_0TRACE("\033[2J\033[1;1H");
	  USART_TRACE("------------------------------------\n");
	  USART_TRACE("BOOT_Init.. ok\n");

	  RS485_1_UART_Init(115200);		// настройка RS485 1 канала.
	  USART_TRACE("RS485_1_UART_Init.. ok\n");

  	  RS485_2_UART_Init(115200);		// настройка RS485 2 канала.
  	  USART_TRACE("RS485_2_UART_Init.. ok\n");

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
  	    	 		//if(!f_chdir("/folder2")) USART_TRACE("перешли в папку /folder2\n");

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


#ifdef STM32F407xx
	  Port_Init(LED1,GPIO_MODE_OUTPUT_PP);
	  Port_Init(LED2,GPIO_MODE_OUTPUT_PP);
	  Port_Init(LED3,GPIO_MODE_OUTPUT_PP);
	  Port_Init(LED4,GPIO_MODE_OUTPUT_PP);
	  Port_Off(LED1);
#elif STM32F417xx
	  Port_Init(LED1,GPIO_MODE_OUTPUT_OD);
#endif
	  Port_Init(MODBUS_DEn,GPIO_MODE_INPUT);			// пока не используем


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
	( void ) pxTask;
	( void ) pcTaskName;
	for( ;; );
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

  HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSE, RCC_MCODIV_1);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

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
  HAL_GPIO_WritePin(GPIO_PORT[Port], GPIO_PIN[Port], GPIO_PIN_SET);
}
/*************************************************************************
 * Port_Off
 *************************************************************************/
void Port_Off(Port_TypeDef Port)
{
  HAL_GPIO_WritePin(GPIO_PORT[Port], GPIO_PIN[Port], GPIO_PIN_RESET);
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
//HAL_UART_Transmit_DMA(&BOOT_UART, (uint8_t *)ptr, len);

HAL_UART_Transmit(&BOOT_UART, (uint8_t *)ptr, len, 0xFFFF);
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
