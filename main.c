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

#include "stm32f4xx_it.h"
#include "main.h"
//#include "iwdg.h"
//#include "lwip.h"
#include "ethernetif.h"
#include "usart.h"
#include "clocks.h"
#include "gpio.h"

#include "stm324xg_eval.h"


/* Private variables ---------------------------------------------------------*/
GPIO_TypeDef* GPIO_PORT[LEDn] = {LED1_GPIO_PORT,
                                 LED2_GPIO_PORT,
                                 LED3_GPIO_PORT,
                                 LED4_GPIO_PORT};

const uint16_t GPIO_PIN[LEDn] = {LED1_PIN,
                                 LED2_PIN,
                                 LED3_PIN,
                                 LED4_PIN};

extern uint8_t aTxRS485_1_Buffer[];
extern UART_HandleTypeDef huart2;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void NVIC_Configuration(void);
void FREERTOS_Init(void);

void DebugOut(UART_HandleTypeDef *huart, char *ptr);
void LED_Init(Led_TypeDef Led);

int main(void) {


	  HAL_Init();				// инит. Flash и Systick.
	  SystemClock_Config();		// когфиг осциллятора.
//	  NVIC_Configuration();
	  GPIO_Init();				// конфиг портов.
	  Clocks_Init();

//	  MODBUS_Init(115200);		// настройка MODBUS интерфейса.
//	  BOOT_UART_Init();			// настройка BOOT интерфейса.
	  RS485_1_UART_Init(115200);// настройка RS485 1 канала.
//	  RS485_2_UART_Init();		// настройка RS485 2 канала.

	  printf("RS485_1_UART_Init.. ok\n");

	  LED_Init(LED1);
	  LED_Init(LED2);
	  LED_Init(LED3);
	  LED_Init(LED4);

	  FREERTOS_Init();			// инит. FREERTOS.

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
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 210;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

  HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSE, RCC_MCODIV_1);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

}

/*************************************************************************
 * NVIC_Configuration
 *************************************************************************/
void NVIC_Configuration(void)
    {

	  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);			//NVIC_PRIORITYGROUP_1
	  HAL_NVIC_SetPriority(RCC_IRQn,(uint8_t)(configKERNEL_INTERRUPT_PRIORITY >> 4),0);

    }
/*************************************************************************
 * LED_Init
 *************************************************************************/
void LED_Init(Led_TypeDef Led)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  /* Enable the GPIO_LED clock */
  LEDx_GPIO_CLK_ENABLE(Led);

  /* Configure the GPIO_LED pin */
  GPIO_InitStruct.Pin = GPIO_PIN[Led];
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;

  HAL_GPIO_Init(GPIO_PORT[Led], &GPIO_InitStruct);
}

/*************************************************************************
 *
 *************************************************************************/
void LED_On(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(GPIO_PORT[Led], GPIO_PIN[Led], GPIO_PIN_SET);
}

/*************************************************************************
 *
 *************************************************************************/
void LED_Off(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(GPIO_PORT[Led], GPIO_PIN[Led], GPIO_PIN_RESET);
}

/*************************************************************************
 *
 *************************************************************************/
void LED_Toggle(Led_TypeDef Led)
{
  HAL_GPIO_TogglePin(GPIO_PORT[Led], GPIO_PIN[Led]);
}

/*************************************************************************
 * PUTCHAR_PROTOTYPE
 *************************************************************************/
int __io_putchar(int ch){
//  HAL_UART_Transmit_DMA(&huart2, (uint8_t *)&ch, 1);
//  HAL_UART_Transmit_DMA(&huart2, (uint8_t *)&ch, 1);

  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);
  return ch;
}

/*************************************************************************
  * @brief  Tx Transfer completed callback
  * @param  huart: UART handle.
  * @retval None
 *************************************************************************/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {

	LED_Toggle(LED4);
}

/*************************************************************************
  * @brief  Rx Transfer completed callback
  * @param  huart: UART handle
  * @retval None
 *************************************************************************/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

	LED_Toggle(LED4);
}

/*************************************************************************
  * @brief  UART error callbacks
  * @param  huart: UART handle
  * @retval None
 *************************************************************************/
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{

	LED_Toggle(LED3);
}

void DebugOut(UART_HandleTypeDef *huart, char *ptr){
uint8_t	len=255,index;


for(index=0; index<=len; index++)
{
	if (ptr[index] == 0){
		len = index;
		break;
	}
}
	  HAL_UART_Transmit(&huart2, (uint8_t *)ptr, len, 0xFFFF);
}
