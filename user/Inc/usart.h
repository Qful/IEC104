/**
  ******************************************************************************
  * File Name          : USART.h
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __usart_H
#define __usart_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#define COUNTOF(__BUFFER__)   (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))

 /* Size of Trasmission buffer */
 #define TXBUFFERSIZE_RS485_1			(COUNTOF(aTxRS485_1_Buffer) - 1)
 #define RXBUFFERSIZE_RS485_1			10

 /* Definition for USART's DMA */
 #define USART1_TX_DMA_CHANNEL             DMA_CHANNEL_4
 #define USART1_TX_DMA_STREAM              DMA2_Stream7
 #define USART1_RX_DMA_CHANNEL             DMA_CHANNEL_4
 #define USART1_RX_DMA_STREAM              DMA2_Stream5

 #define USART2_TX_DMA_CHANNEL             DMA_CHANNEL_4
 #define USART2_TX_DMA_STREAM              DMA1_Stream6
 #define USART2_RX_DMA_CHANNEL             DMA_CHANNEL_4
 #define USART2_RX_DMA_STREAM              DMA1_Stream5

 #define USART3_TX_DMA_CHANNEL             DMA_CHANNEL_4
 #define USART3_TX_DMA_STREAM              DMA1_Stream3
 #define USART3_RX_DMA_CHANNEL             DMA_CHANNEL_4
 #define USART3_RX_DMA_STREAM              DMA1_Stream1

 #define UART4_TX_DMA_CHANNEL              DMA_CHANNEL_4
 #define UART4_TX_DMA_STREAM               DMA1_Stream4
 #define UART4_RX_DMA_CHANNEL              DMA_CHANNEL_4
 #define UART4_RX_DMA_STREAM               DMA1_Stream2

 /* Definition for USART's NVIC */
 #define USART1_DMA_TX_IRQn                DMA2_Stream7_IRQn
 #define USART1_DMA_RX_IRQn                DMA2_Stream5_IRQn
 #define USART1_DMA_TX_IRQHandler          DMA2_Stream7_IRQHandler
 #define USART1_DMA_RX_IRQHandler          DMA2_Stream5_IRQHandler
 #define USART1_IRQn                       USART1_IRQn
 #define USART1_IRQHandler                 USART1_IRQHandler

 #define USART2_DMA_TX_IRQn                DMA1_Stream6_IRQn
 #define USART2_DMA_RX_IRQn                DMA1_Stream5_IRQn
 #define USART2_DMA_TX_IRQHandler          DMA1_Stream6_IRQHandler
 #define USART2_DMA_RX_IRQHandler          DMA1_Stream5_IRQHandler
 #define USART2_IRQn                       USART2_IRQn
 #define USART2_IRQHandler                 USART2_IRQHandler

 #define USART3_DMA_TX_IRQn                DMA1_Stream3_IRQn
 #define USART3_DMA_RX_IRQn                DMA1_Stream1_IRQn
 #define USART3_DMA_TX_IRQHandler          DMA1_Stream3_IRQHandler
 #define USART3_DMA_RX_IRQHandler          DMA1_Stream1_IRQHandler
 #define USART3_IRQn                       USART3_IRQn
 #define USART3_IRQHandler                 USART3_IRQHandler

 #define UART4_DMA_TX_IRQn                 DMA1_Stream4_IRQn
 #define UART4_DMA_RX_IRQn                 DMA1_Stream2_IRQn
 #define UART4_DMA_TX_IRQHandler           DMA1_Stream4_IRQHandler
 #define UART4_DMA_RX_IRQHandler           DMA1_Stream2_IRQHandler
 #define UART4_IRQn                        UART4_IRQn
 #define UART4_IRQHandler                  UART4_IRQHandler


//extern UART_HandleTypeDef MODBUS;
//extern UART_HandleTypeDef BOOT_UART;
//extern UART_HandleTypeDef RS485_1;
//extern UART_HandleTypeDef RS485_2;

void MODBUS_Init(uint32_t BaudRate);
void BOOT_UART_Init(uint32_t BaudRate);
void RS485_1_UART_Init(uint32_t BaudRate);
void RS485_2_UART_Init(uint32_t BaudRate);

#ifdef __cplusplus
}
#endif
#endif /*__ usart_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
