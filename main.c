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
#include "queue.h"
#include "semphr.h"
#include "timers.h"

#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
//#include "iwdg.h"
#include "lwip.h"
#include "usart.h"
#include "gpio.h"


/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);

int main(void) {


	  HAL_Init();				// инит. Flash и Systick.
	  SystemClock_Config();		// когфиг осциллятора.
	  MX_GPIO_Init();			// конфиг портов.

	  MX_MODBUS_Init(115200);	// настройка MODBUS интерфейса.
	  MX_BOOT_UART_Init();		// настройка BOOT интерфейса.
	  MX_RS485_1_UART_Init();	// настройка RS485 1 канала.
	  MX_RS485_2_UART_Init();	// настройка RS485 2 канала.


	  MX_FREERTOS_Init();		// инит. FREERTOS.

	  osKernelStart();			// Старт планировщика

	while (1) {
	}

	return 0;
}

/*************************************************************************
 * vApplicationStackOverflowHook
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

}

/*************************************************************************
* System Clock Configuration
 *************************************************************************/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

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

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
                              |RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

  HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSE, RCC_MCODIV_1);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
}
