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

#include "main.h"

#include "ExtSPImem.h"


#include "core_cm4.h"
/* External variables --------------------------------------------------------*/
//extern void xPortSysTickHandler(void);
extern ETH_HandleTypeDef heth;

extern TIM_HandleTypeDef   TimHandle;	// Timer handler declaration для таймаутов MODBUS
extern DMA_HandleTypeDef   DmaHandle;

extern UART_HandleTypeDef BOOT_UART;
extern UART_HandleTypeDef MODBUS;
extern UART_HandleTypeDef RS485_1;
extern UART_HandleTypeDef RS485_2;

extern SPI_HandleTypeDef SpiHandle;

extern struct iecsock 	*s;

extern RTC_HandleTypeDef 	hrtc;			// часы и бэкап регистр

SCB_Type HFSR_reg;
/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

void NMI_Handler(void) {

	USART_TRACE_RED("NMI_Handler.. ok\n");
	NVIC_SystemReset();
	  while(1);
}
void HardFault_Handler(void) {

	 __asm volatile
	    (
	        " tst lr, #4                                                \n"
	        " ite eq                                                    \n"
	        " mrseq r0, msp                                             \n"
	        " mrsne r0, psp                                             \n"
	        " ldr r1, [r0, #24]                                         \n"
	        " ldr r2, handler2_address_const                            \n"
	        " bx r2                                                     \n"
	        " handler2_address_const: .word prvGetRegistersFromStack    \n"
	    );
}

void prvGetRegistersFromStack( uint32_t *hardfault_args )
{
	  unsigned int stacked_r0;
	  unsigned int stacked_r1;
	  unsigned int stacked_r2;
	  unsigned int stacked_r3;
	  unsigned int stacked_r12;
	  unsigned int stacked_lr;
	  unsigned int stacked_pc;
	  unsigned int stacked_psr;

	  stacked_r0 = ((unsigned long) hardfault_args[0]);
	  stacked_r1 = ((unsigned long) hardfault_args[1]);
	  stacked_r2 = ((unsigned long) hardfault_args[2]);
	  stacked_r3 = ((unsigned long) hardfault_args[3]);

	  stacked_r12 = ((unsigned long) hardfault_args[4]);
	  stacked_lr = ((unsigned long) hardfault_args[5]);
	  stacked_pc = ((unsigned long) hardfault_args[6]);
	  stacked_psr = ((unsigned long) hardfault_args[7]);

	  //USART_TRACE_RED
	  printf ("[Hard fault handler - all numbers in hex]\n");
	  printf ("R0 = 0x%x\n", stacked_r0);
	  printf ("R1 = 0x%x\n", stacked_r1);
	  printf ("R2 = 0x%x\n", stacked_r2);
	  printf ("R3 = 0x%x\n", stacked_r3);
	  printf ("R12 = 0x%x\n", stacked_r12);
	  printf ("LR [R14] = 0x%x  subroutine call return address\n", stacked_lr);
	  printf ("PC [R15] = 0x%x  program counter\n", stacked_pc);
	  printf ("PSR = 0x%x\n", stacked_psr);
	  printf ("BFAR = 0x%x\n", (*((volatile unsigned long *)(0xE000ED38))));//Bus fault address register
	  printf ("CFSR = 0x%x\n", (*((volatile unsigned long *)(0xE000ED28))));
	  printf ("HFSR = 0x%x\n", (*((volatile unsigned long *)(0xE000ED2C))));//Hard fault status register 
	  printf ("DFSR = 0x%x\n", (*((volatile unsigned long *)(0xE000ED30))));
	  printf ("AFSR = 0x%x\n", (*((volatile unsigned long *)(0xE000ED3C))));//Auxiliary fault status register
	  printf ("SCB_SHCSR = 0x%x\n", SCB->SHCSR);
	NVIC_SystemReset();
	  while(1);
}
void MemManage_Handler(void) {

	USART_TRACE_RED("MemManage_Handler.\n");
	NVIC_SystemReset();
	  while(1);
}
void BusFault_Handler(void) {

	USART_TRACE_RED("BusFault_Handler.\n");
	NVIC_SystemReset();
	  while(1);
}
void UsageFault_Handler(void) {

	USART_TRACE_RED("UsageFault_Handler.\n");
	NVIC_SystemReset();
	  while(1);
}
/*
void Default_Handler(void) {

	USART_TRACE_RED("Default_Handler.. ok\n");
	  while(1);
}
*/
void DebugMon_Handler(void) {

	USART_TRACE_RED("DebugMon_Handler.. ok\n");
	NVIC_SystemReset();
	  while(1);
}

/**
* @brief This function handles System tick timer. 1 ms
*/

void SysTick_Handler(void)
{
  HAL_IncTick();
//  HAL_SYSTICK_IRQHandler();
#ifdef	IEC104Task
  IEC104_IncTimers(s);
#endif
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
 * EXTI15_10_IRQHandler
 ******************************************************************************/
void EXTI15_10_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
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
	  HAL_DMA_IRQHandler(MODBUS.hdmarx);
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
/******************************************************************************
 * SPIx_DMA_RX_IRQHandler
 ******************************************************************************/
void DMA2_Stream0_IRQHandler(void)
{
  HAL_DMA_IRQHandler(SpiHandle.hdmarx);
}

/******************************************************************************
 * SPIx_DMA_TX_IRQHandler
 ******************************************************************************/
void DMA2_Stream3_IRQHandler(void)
{
  HAL_DMA_IRQHandler(SpiHandle.hdmatx);
}

/******************************************************************************
 * DMA_STREAM_IRQHANDLER
 ******************************************************************************/
void DMA_STREAM_IRQHANDLER(void)
{
    /* Check the interrupt and clear flag */
    HAL_DMA_IRQHandler(&DmaHandle);
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
