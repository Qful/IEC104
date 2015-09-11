/**
  ******************************************************************************
  * File Name          : USART.c
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

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

#include "usart.h"
#include "gpio.h"


extern UART_HandleTypeDef MODBUS;				//UART4
extern UART_HandleTypeDef BOOT_UART;			//USART1
extern UART_HandleTypeDef RS485_1;				//USART2
extern UART_HandleTypeDef RS485_2;				//USART3

/**************************************
* MODBUS init function
* inpit: скорость.
***************************************/
void MODBUS_Init(uint32_t BaudRate)
{

  MODBUS.Instance = UART4;
  MODBUS.Init.BaudRate = BaudRate;
  MODBUS.Init.WordLength = UART_WORDLENGTH_8B;
  MODBUS.Init.StopBits = UART_STOPBITS_1;
  MODBUS.Init.Parity = UART_PARITY_NONE;
  MODBUS.Init.Mode = UART_MODE_TX_RX;
  MODBUS.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  MODBUS.Init.OverSampling = UART_OVERSAMPLING_16;
//  HAL_MultiProcessor_Init(&MODBUS, 0, UART_WAKEUPMETHODE_IDLELINE);
  HAL_UART_Init(&MODBUS);
}
/* USART1 init function */

void BOOT_UART_Init(uint32_t BaudRate)
{

  BOOT_UART.Instance = USART1;
  BOOT_UART.Init.BaudRate = BaudRate;
  BOOT_UART.Init.WordLength = UART_WORDLENGTH_8B;
  BOOT_UART.Init.StopBits = UART_STOPBITS_1;
  BOOT_UART.Init.Parity = UART_PARITY_NONE;
  BOOT_UART.Init.Mode = UART_MODE_TX;
  BOOT_UART.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  BOOT_UART.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&BOOT_UART);

}
/**************************************
* RS485_1 init function
* inpit: скорость.
***************************************/
void RS485_1_UART_Init(uint32_t BaudRate)
{

  RS485_1.Instance = USART2;
  RS485_1.Init.BaudRate = BaudRate;
  RS485_1.Init.WordLength = UART_WORDLENGTH_8B;
  RS485_1.Init.StopBits = UART_STOPBITS_1;
  RS485_1.Init.Parity = UART_PARITY_NONE;
  RS485_1.Init.Mode = UART_MODE_TX_RX;//UART_MODE_TX_RX;
  RS485_1.Init.HwFlowCtl = UART_HWCONTROL_NONE;//UART_HWCONTROL_RTS;
  RS485_1.Init.OverSampling = UART_OVERSAMPLING_8;//UART_OVERSAMPLING_16;
  HAL_UART_Init(&RS485_1);

//  HAL_UART_Transmit_DMA(&RS485_1, (uint8_t *)aTxRS485_1_Buffer, TXBUFFERSIZE_RS485_1);

}
/**************************************
* RS485_2 init function
* inpit: скорость.
***************************************/
void RS485_2_UART_Init(uint32_t BaudRate)
{

  RS485_2.Instance = USART3;
  RS485_2.Init.BaudRate = BaudRate;
  RS485_2.Init.WordLength = UART_WORDLENGTH_8B;
  RS485_2.Init.StopBits = UART_STOPBITS_1;
  RS485_2.Init.Parity = UART_PARITY_NONE;
  RS485_2.Init.Mode = UART_MODE_TX_RX;
  RS485_2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  RS485_2.Init.OverSampling = UART_OVERSAMPLING_8;
  HAL_UART_Init(&RS485_2);

}
/**************************************
* HAL_UART_MspInit
***************************************/
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  static DMA_HandleTypeDef hdma_tx;
  static DMA_HandleTypeDef hdma_rx;


  if(huart->Instance==UART4)
  {

	__GPIOC_CLK_ENABLE();

    /* Peripheral clock enable */
    __UART4_CLK_ENABLE();
  
    __DMA1_CLK_ENABLE();

    /**UART4 GPIO Configuration    
    PC10     ------> UART4_TX
    PC11     ------> UART4_RX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART4;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    // Configure the DMA handler for Transmission process
    hdma_tx.Instance                 = UART4_TX_DMA_STREAM;
    hdma_tx.Init.Channel             = UART4_TX_DMA_CHANNEL;
    hdma_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_tx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_tx.Init.Mode                = DMA_NORMAL;//DMA_NORMAL;
    hdma_tx.Init.Priority            = DMA_PRIORITY_LOW;//DMA_PRIORITY_LOW;
    hdma_tx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;//DMA_FIFOMODE_DISABLE;
    hdma_tx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_tx.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_tx.Init.PeriphBurst         = DMA_PBURST_INC4;
    HAL_DMA_Init(&hdma_tx);

    // Associate the initialized DMA handle to the UART handle
    __HAL_LINKDMA(huart, hdmatx, hdma_tx);

    // Configure the DMA handler for reception process
    hdma_rx.Instance                 = UART4_RX_DMA_STREAM;
    hdma_rx.Init.Channel             = UART4_RX_DMA_CHANNEL;
    hdma_rx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
    hdma_rx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_rx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_rx.Init.Mode                = DMA_NORMAL;
    hdma_rx.Init.Priority            = DMA_PRIORITY_HIGH;
    hdma_rx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_rx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_rx.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_rx.Init.PeriphBurst         = DMA_PBURST_INC4;
    HAL_DMA_Init(&hdma_rx);

    // Associate the initialized DMA handle to the UART handle
    __HAL_LINKDMA(huart, hdmatx, hdma_tx);

    // NVIC configuration for DMA transfer complete interrupt (USARTx_TX)
    HAL_NVIC_SetPriority(UART4_DMA_TX_IRQn, 0, 1);	//0,1
    HAL_NVIC_EnableIRQ(UART4_DMA_TX_IRQn);

    HAL_NVIC_SetPriority(UART4_DMA_RX_IRQn, 0, 0);	//0,0
    HAL_NVIC_EnableIRQ(UART4_DMA_RX_IRQn);

    HAL_NVIC_SetPriority(UART4_IRQn, 0, 1);
    HAL_NVIC_EnableIRQ(UART4_IRQn);
  }
  else if(huart->Instance==USART1)
  {

	/* Enable GPIO TX/RX clock */
	__GPIOA_CLK_ENABLE();
    /* Peripheral clock enable */
    __USART1_CLK_ENABLE();
    /* Enable DMA1 clock */
    __DMA2_CLK_ENABLE();

    /**USART1 GPIO Configuration    
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // Configure the DMA handler for Transmission process
    hdma_tx.Instance                 = USART1_TX_DMA_STREAM;
    hdma_tx.Init.Channel             = USART1_TX_DMA_CHANNEL;
    hdma_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_tx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_tx.Init.Mode                = DMA_NORMAL;//DMA_NORMAL;
    hdma_tx.Init.Priority            = DMA_PRIORITY_LOW;//DMA_PRIORITY_LOW;
    hdma_tx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;//DMA_FIFOMODE_DISABLE;
    hdma_tx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_tx.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_tx.Init.PeriphBurst         = DMA_PBURST_INC4;
    HAL_DMA_Init(&hdma_tx);
    // Associate the initialized DMA handle to the UART handle
    __HAL_LINKDMA(huart, hdmatx, hdma_tx);

    // NVIC configuration for DMA transfer complete interrupt (USARTx_TX)
    HAL_NVIC_SetPriority(USART1_DMA_TX_IRQn, 0, 1);	//0,1
    HAL_NVIC_EnableIRQ(USART1_DMA_TX_IRQn);

    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);

  }
  else if(huart->Instance==USART2)
  {

	/* Enable GPIO TX/RX clock */
	__GPIOD_CLK_ENABLE();

    /* Peripheral clock enable */
    __USART2_CLK_ENABLE();

    /* Enable DMA1 clock */
    __DMA1_CLK_ENABLE();
    /**USART2 GPIO Configuration    
    PD4     ------> USART2_RTS
    PD5     ------> USART2_TX
    PD6     ------> USART2_RX 
    */
/*
    GPIO_InitStruct.Pin = GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
*/
    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    // Configure the DMA handler for Transmission process
    hdma_tx.Instance                 = USART2_TX_DMA_STREAM;
    hdma_tx.Init.Channel             = USART2_TX_DMA_CHANNEL;
    hdma_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_tx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_tx.Init.Mode                = DMA_NORMAL;//DMA_NORMAL;
    hdma_tx.Init.Priority            = DMA_PRIORITY_LOW;//DMA_PRIORITY_LOW;
    hdma_tx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;//DMA_FIFOMODE_DISABLE;
    hdma_tx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_tx.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_tx.Init.PeriphBurst         = DMA_PBURST_INC4;
    HAL_DMA_Init(&hdma_tx);
    // Associate the initialized DMA handle to the UART handle
    __HAL_LINKDMA(huart, hdmatx, hdma_tx);

    // Configure the DMA handler for reception process
    hdma_rx.Instance                 = USART2_RX_DMA_STREAM;
    hdma_rx.Init.Channel             = USART2_RX_DMA_CHANNEL;
    hdma_rx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
    hdma_rx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_rx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_rx.Init.Mode                = DMA_NORMAL;
    hdma_rx.Init.Priority            = DMA_PRIORITY_HIGH;
    hdma_rx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_rx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_rx.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_rx.Init.PeriphBurst         = DMA_PBURST_INC4;
    HAL_DMA_Init(&hdma_rx);
    // Associate the initialized DMA handle to the the UART handle
    __HAL_LINKDMA(huart, hdmarx, hdma_rx);

    // NVIC configuration for DMA transfer complete interrupt (USARTx_TX)
    HAL_NVIC_SetPriority(USART2_DMA_TX_IRQn, 0, 1);	//0,1
    HAL_NVIC_EnableIRQ(USART2_DMA_TX_IRQn);
    // NVIC configuration for DMA transfer complete interrupt (USARTx_RX)
    HAL_NVIC_SetPriority(USART2_DMA_RX_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART2_DMA_RX_IRQn);
    /* NVIC configuration for USART TC interrupt */
    HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);

  }
  else if(huart->Instance==USART3)
  {

	/* Enable GPIO TX/RX clock */
	__GPIOD_CLK_ENABLE();
    /* Peripheral clock enable */
    __USART3_CLK_ENABLE();
    /* Enable DMA1 clock */
    __DMA1_CLK_ENABLE();

    /**USART3 GPIO Configuration    
    PD8     ------> USART3_TX
    PD9     ------> USART3_RX
    PD12     ------> USART3_RTS 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    // Configure the DMA handler for Transmission process
    hdma_tx.Instance                 = USART3_TX_DMA_STREAM;
    hdma_tx.Init.Channel             = USART3_TX_DMA_CHANNEL;
    hdma_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_tx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_tx.Init.Mode                = DMA_NORMAL;//DMA_NORMAL;
    hdma_tx.Init.Priority            = DMA_PRIORITY_LOW;//DMA_PRIORITY_LOW;
    hdma_tx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;//DMA_FIFOMODE_DISABLE;
    hdma_tx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_tx.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_tx.Init.PeriphBurst         = DMA_PBURST_INC4;
    HAL_DMA_Init(&hdma_tx);
    // Associate the initialized DMA handle to the UART handle
    __HAL_LINKDMA(huart, hdmatx, hdma_tx);

    // Configure the DMA handler for reception process
    hdma_rx.Instance                 = USART3_RX_DMA_STREAM;
    hdma_rx.Init.Channel             = USART3_RX_DMA_CHANNEL;
    hdma_rx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
    hdma_rx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_rx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_rx.Init.Mode                = DMA_NORMAL;
    hdma_rx.Init.Priority            = DMA_PRIORITY_HIGH;
    hdma_rx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_rx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_rx.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_rx.Init.PeriphBurst         = DMA_PBURST_INC4;
    HAL_DMA_Init(&hdma_rx);
    // Associate the initialized DMA handle to the the UART handle
    __HAL_LINKDMA(huart, hdmarx, hdma_rx);

    // NVIC configuration for DMA transfer complete interrupt (USARTx_TX)
    HAL_NVIC_SetPriority(USART3_DMA_TX_IRQn, 0, 1);	//0,1
    HAL_NVIC_EnableIRQ(USART3_DMA_TX_IRQn);
    // NVIC configuration for DMA transfer complete interrupt (USARTx_RX)
    HAL_NVIC_SetPriority(USART3_DMA_RX_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART3_DMA_RX_IRQn);
    /* NVIC configuration for USART TC interrupt */
    HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);


  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{

  if(huart->Instance==UART4)
  {

    __UART4_CLK_DISABLE();
    /**UART4 GPIO Configuration    
    PC10     ------> UART4_TX
    PC11     ------> UART4_RX 
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_10|GPIO_PIN_11);

  }
  else if(huart->Instance==USART1)
  {
    /* Peripheral clock disable */
    __USART1_CLK_DISABLE();
  
    /**USART1 GPIO Configuration    
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX 
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

  }
  else if(huart->Instance==USART2)
  {
    /* Peripheral clock disable */
    __USART2_CLK_DISABLE();
  
    /**USART2 GPIO Configuration    
    PD4     ------> USART2_RTS
    PD5     ------> USART2_TX
    PD6     ------> USART2_RX 
    */
    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6);

  }
  else if(huart->Instance==USART3)
  {
    /* Peripheral clock disable */
    __USART3_CLK_DISABLE();
  
    /**USART3 GPIO Configuration    
    PD8     ------> USART3_TX
    PD9     ------> USART3_RX
    PD12     ------> USART3_RTS 
    */
    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_12);

  }
} 



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
