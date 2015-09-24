/*
 * USART.h
 *
 *  Created on: 25.08.2015
 *      Author: sagok
 */
#ifndef __usart_H
#define __usart_H
#ifdef __cplusplus
 extern "C" {
#endif

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
