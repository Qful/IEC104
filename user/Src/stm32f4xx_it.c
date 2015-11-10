/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2015 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "cmsis_os.h"
#include "iec104.h"

#include "usart.h"
/* External variables --------------------------------------------------------*/
//extern void xPortSysTickHandler(void);
extern ETH_HandleTypeDef heth;

extern	TIM_HandleTypeDef    TimHandle;	// Timer handler declaration для таймаутов MODBUS

extern UART_HandleTypeDef BOOT_UART;
extern UART_HandleTypeDef MODBUS;
extern UART_HandleTypeDef RS485_1;
extern UART_HandleTypeDef RS485_2;

extern struct iecsock 	*s;
/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles System tick timer. 1 ms
*/
void SysTick_Handler(void)
{
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
  IEC104_IncTimers(s);
  osSystickHandler();

}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
* @brief This function handles Ethernet global interrupt.
*/
void ETH_IRQHandler(void)
{
  HAL_ETH_IRQHandler(&heth);
}
/******************************************************************************
 * USART1
 ******************************************************************************/
void USART1_DMA_TX_IRQHandler(void)
{
  HAL_DMA_IRQHandler(BOOT_UART.hdmatx);
}

void USART1_DMA_RX_IRQHandler(void)
{
  HAL_DMA_IRQHandler(BOOT_UART.hdmarx);
}

void USART1_IRQHandler(void)
{
  HAL_UART_IRQHandler(&BOOT_UART);
}
/******************************************************************************
 * USART2
 ******************************************************************************/
void USART2_DMA_TX_IRQHandler(void)
{
  HAL_DMA_IRQHandler(RS485_1.hdmatx);
}

void USART2_DMA_RX_IRQHandler(void)
{
  HAL_DMA_IRQHandler(RS485_1.hdmarx);
}

void USART2_IRQHandler(void)
{
  HAL_UART_IRQHandler(&RS485_1);
}

/******************************************************************************
 * USART3
 ******************************************************************************/
void USART3_DMA_RX_IRQHandler(void)
{
	  HAL_DMA_IRQHandler(RS485_2.hdmarx);
}
void USART3_DMA_TX_IRQHandler(void)
{
	  HAL_DMA_IRQHandler(RS485_2.hdmatx);
}
void USART3_IRQHandler(void)
{
	  HAL_UART_IRQHandler(&RS485_2);
}
/******************************************************************************
 * UART4
 ******************************************************************************/
void UART4_DMA_RX_IRQHandler(void)
{
	Port_On(LED2);
	if (MODBUS.hdmarx->XferCpltCallback == 0xa5a5a5a5){
		Port_On(LED2);
		MODBUS.hdmarx->XferCpltCallback = 0x0800a785;
		MODBUS.hdmarx->XferHalfCpltCallback = 0x0800a7b9;
	}
	  HAL_DMA_IRQHandler(MODBUS.hdmarx);
	Port_Off(LED2);
}
void UART4_DMA_TX_IRQHandler(void)
{
	  HAL_DMA_IRQHandler(MODBUS.hdmatx);
}
void UART4_IRQHandler(void)
{
	  HAL_UART_IRQHandler(&MODBUS);
}

/******************************************************************************
 * USARTx_IRQHandler
 ******************************************************************************/
void WWDG_IRQHandler(void)
{
 // HAL_WWDG_IRQHandler();
}

/******************************************************************************
 * TIM2_IRQHandler
 ******************************************************************************/
void TIM2_IRQHandler( void )
{
//	 Port_On(LED1);
	 HAL_TIM_IRQHandler(&TimHandle);
//	 Port_Off(LED1);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
