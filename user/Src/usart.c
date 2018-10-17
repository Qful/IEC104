/*
 * USART.c
 *
 *  Created on: 25.08.2015
 *      Author: sagok
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

#include "ConfBoard.h"
#include "usart.h"
#include "gpio.h"

extern UART_HandleTypeDef BOOT_UART;			//USART1
extern UART_HandleTypeDef RS485_1;				//USART2
extern UART_HandleTypeDef RS485_2;				//USART3

/*************************************************************************
* BOOT_UART_Init init function
* BaudRate: скорость.
**************************************************************************/
void BOOT_UART_Init(uint32_t BaudRate)
{

  BOOT_UART.Instance = USART1;
  BOOT_UART.Init.BaudRate = BaudRate;
  BOOT_UART.Init.WordLength = UART_WORDLENGTH_8B;
  BOOT_UART.Init.StopBits = UART_STOPBITS_1;
  BOOT_UART.Init.Parity = UART_PARITY_NONE;
  BOOT_UART.Init.Mode = UART_MODE_TX_RX;
  BOOT_UART.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  BOOT_UART.Init.OverSampling = UART_OVERSAMPLING_8;
  HAL_UART_Init(&BOOT_UART);

}
/*************************************************************************
* RS485_1 init function
* inpit: скорость.
**************************************************************************/
void RS485_1_UART_Init(uint32_t BaudRate)
{
  Port_On(RS485_1_DEn);
  Port_Init(RS485_1_DEn,GPIO_MODE_OUTPUT_OD);

  RS485_1.Instance = USART2;
  RS485_1.Init.BaudRate = BaudRate;
  RS485_1.Init.WordLength = UART_WORDLENGTH_8B;
  RS485_1.Init.StopBits = UART_STOPBITS_1;
  RS485_1.Init.Parity = UART_PARITY_NONE;
  RS485_1.Init.Mode = UART_MODE_TX_RX;
  RS485_1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  RS485_1.Init.OverSampling = UART_OVERSAMPLING_8;
  HAL_UART_Init(&RS485_1);

}
/*************************************************************************
* RS485_2 init function
* inpit: скорость.
**************************************************************************/
void RS485_2_UART_Init(uint32_t BaudRate)
{
  Port_On(RS485_2_DEn);
  Port_Init(RS485_2_DEn,GPIO_MODE_OUTPUT_OD);

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
/*************************************************************************
* HAL_UART_MspInit
**************************************************************************/
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct;
static  DMA_HandleTypeDef hdma_rx_MODBUS;
static  DMA_HandleTypeDef hdma_tx_MODBUS;

static  DMA_HandleTypeDef hdma_rx_DEBUG;
static  DMA_HandleTypeDef hdma_tx_DEBUG;

static  DMA_HandleTypeDef hdma_rx_RS485_1;
static  DMA_HandleTypeDef hdma_tx_RS485_1;

static  DMA_HandleTypeDef hdma_rx_RS485_2;
static  DMA_HandleTypeDef hdma_tx_RS485_2;


  // ---------------------------- MODBUS ---------------------------------
  if(huart->Instance==UART4)
  {
	__GPIOC_CLK_ENABLE();
    __UART4_CLK_ENABLE();
    __DMA1_CLK_ENABLE();

    // PC10     ------> UART4_TX
    // PC11     ------> UART4_RX
    GPIO_InitStruct.Pin = GPIO_PIN_10 | GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART4;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /*##-3- Configure the NVIC for UART ########################################*/
    HAL_NVIC_SetPriority(UART4_IRQn, 6, 0);		//0

    /* Enable the UART Data Register not empty Interrupt */
    __HAL_UART_ENABLE_IT(huart, UART_IT_IDLE);

    HAL_NVIC_EnableIRQ(UART4_IRQn);

    // Configure the DMA handler for Transmission process
    hdma_tx_MODBUS.Instance                 = UART4_TX_DMA_STREAM;

    hdma_tx_MODBUS.Init.Channel             = UART4_TX_DMA_CHANNEL;
    hdma_tx_MODBUS.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_tx_MODBUS.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_tx_MODBUS.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_tx_MODBUS.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_tx_MODBUS.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_tx_MODBUS.Init.Mode                = DMA_NORMAL;
    hdma_tx_MODBUS.Init.Priority            = DMA_PRIORITY_MEDIUM;
    hdma_tx_MODBUS.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_tx_MODBUS.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_tx_MODBUS.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_tx_MODBUS.Init.PeriphBurst         = DMA_PBURST_INC4;
    HAL_DMA_Init(&hdma_tx_MODBUS);
    // Associate the initialized DMA handle to the UART handle
    __HAL_LINKDMA(huart, hdmatx, hdma_tx_MODBUS);

    // Configure the DMA handler for reception process
    hdma_rx_MODBUS.Instance                 = UART4_RX_DMA_STREAM;

    hdma_rx_MODBUS.Init.Channel             = UART4_RX_DMA_CHANNEL;
    hdma_rx_MODBUS.Init.Direction           = DMA_PERIPH_TO_MEMORY;
    hdma_rx_MODBUS.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_rx_MODBUS.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_rx_MODBUS.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_rx_MODBUS.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_rx_MODBUS.Init.Mode                = DMA_CIRCULAR;//DMA_CIRCULAR;//DMA_NORMAL;
    hdma_rx_MODBUS.Init.Priority            = DMA_PRIORITY_VERY_HIGH;//DMA_PRIORITY_MEDIUM;
    hdma_rx_MODBUS.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_rx_MODBUS.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_rx_MODBUS.Init.MemBurst            = DMA_MBURST_SINGLE;//DMA_MBURST_INC4;
    hdma_rx_MODBUS.Init.PeriphBurst         = DMA_MBURST_SINGLE;//DMA_PBURST_INC4;

    HAL_DMA_Init(&hdma_rx_MODBUS);
    // Associate the initialized DMA handle to the UART handle
    __HAL_LINKDMA(huart, hdmarx, hdma_rx_MODBUS);

    HAL_NVIC_SetPriority(UART4_DMA_TX_IRQn, 6, 0);	//0,1
    HAL_NVIC_EnableIRQ(UART4_DMA_TX_IRQn);

    HAL_NVIC_SetPriority(UART4_DMA_RX_IRQn, 6, 0);	//0,0
    HAL_NVIC_EnableIRQ(UART4_DMA_RX_IRQn);

  }
  // ---------------------------- DEBUG ----------------------------------
  else if(huart->Instance==USART1)
  {

	__GPIOA_CLK_ENABLE();
    __USART1_CLK_ENABLE();
    __DMA2_CLK_ENABLE();

    // PA9     ------> USART1_TX
    // PA10     ------> USART1_RX
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // Configure the DMA handler for Transmission process
    hdma_tx_DEBUG.Instance                 = USART1_TX_DMA_STREAM;
    hdma_tx_DEBUG.Init.Channel             = USART1_TX_DMA_CHANNEL;
    hdma_tx_DEBUG.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_tx_DEBUG.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_tx_DEBUG.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_tx_DEBUG.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_tx_DEBUG.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_tx_DEBUG.Init.Mode                = DMA_NORMAL;
    hdma_tx_DEBUG.Init.Priority            = DMA_PRIORITY_LOW;
    hdma_tx_DEBUG.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_tx_DEBUG.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_tx_DEBUG.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_tx_DEBUG.Init.PeriphBurst         = DMA_PBURST_INC4;
    // Associate the initialized DMA handle to the UART handle
    __HAL_LINKDMA(huart, hdmatx, hdma_tx_DEBUG);

    HAL_DMA_DeInit(&hdma_tx_DEBUG);
    HAL_DMA_Init(&hdma_tx_DEBUG);

    // Configure the DMA handler for reception process
    hdma_rx_DEBUG.Instance                 = USART1_RX_DMA_STREAM;
    hdma_rx_DEBUG.Init.Channel             = USART1_RX_DMA_CHANNEL;
    hdma_rx_DEBUG.Init.Direction           = DMA_PERIPH_TO_MEMORY;
    hdma_rx_DEBUG.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_rx_DEBUG.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_rx_DEBUG.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_rx_DEBUG.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_rx_DEBUG.Init.Mode                = DMA_NORMAL;//DMA_CIRCULAR;//DMA_NORMAL;
    hdma_rx_DEBUG.Init.Priority            = DMA_PRIORITY_MEDIUM;
    hdma_rx_DEBUG.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_rx_DEBUG.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_rx_DEBUG.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_rx_DEBUG.Init.PeriphBurst         = DMA_PBURST_INC4;

    // Associate the initialized DMA handle to the UART handle
    __HAL_LINKDMA(huart, hdmarx, hdma_rx_DEBUG);

    HAL_DMA_DeInit(&hdma_rx_DEBUG);
    HAL_DMA_Init(&hdma_rx_DEBUG);

    // NVIC configuration for DMA transfer complete interrupt (USARTx_TX)
    HAL_NVIC_SetPriority(USART1_DMA_TX_IRQn, 5, 0);	//6
    HAL_NVIC_EnableIRQ(USART1_DMA_TX_IRQn);

    HAL_NVIC_SetPriority(USART1_DMA_RX_IRQn, 5, 0);	//6
    HAL_NVIC_EnableIRQ(USART1_DMA_RX_IRQn);

    HAL_NVIC_SetPriority(USART1_IRQn, 5, 0);		//6
    HAL_NVIC_EnableIRQ(USART1_IRQn);

  }
  // ---------------------------- RS485_1 ---------------------------------
  else if(huart->Instance==USART2)
  {

	__GPIOD_CLK_ENABLE();
    __USART2_CLK_ENABLE();
    __DMA1_CLK_ENABLE();

    //PD4     ------> USART2_RTS
    //PD5     ------> USART2_TX
    //PD6     ------> USART2_RX

    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    // Configure the DMA handler for Transmission process
    hdma_tx_RS485_1.Instance                 = USART2_TX_DMA_STREAM;
    hdma_tx_RS485_1.Init.Channel             = USART2_TX_DMA_CHANNEL;
    hdma_tx_RS485_1.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_tx_RS485_1.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_tx_RS485_1.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_tx_RS485_1.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_tx_RS485_1.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_tx_RS485_1.Init.Mode                = DMA_NORMAL;//DMA_NORMAL;
    hdma_tx_RS485_1.Init.Priority            = DMA_PRIORITY_LOW;//DMA_PRIORITY_LOW;
    hdma_tx_RS485_1.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;//DMA_FIFOMODE_DISABLE;
    hdma_tx_RS485_1.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_tx_RS485_1.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_tx_RS485_1.Init.PeriphBurst         = DMA_PBURST_INC4;
    HAL_DMA_Init(&hdma_tx_RS485_1);
    // Associate the initialized DMA handle to the UART handle
    __HAL_LINKDMA(huart, hdmatx, hdma_tx_RS485_1);

    // Configure the DMA handler for reception process
    hdma_rx_RS485_1.Instance                 = USART2_RX_DMA_STREAM;
    hdma_rx_RS485_1.Init.Channel             = USART2_RX_DMA_CHANNEL;
    hdma_rx_RS485_1.Init.Direction           = DMA_PERIPH_TO_MEMORY;
    hdma_rx_RS485_1.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_rx_RS485_1.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_rx_RS485_1.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_rx_RS485_1.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_rx_RS485_1.Init.Mode                = DMA_NORMAL;
    hdma_rx_RS485_1.Init.Priority            = DMA_PRIORITY_HIGH;
    hdma_rx_RS485_1.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_rx_RS485_1.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_rx_RS485_1.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_rx_RS485_1.Init.PeriphBurst         = DMA_PBURST_INC4;
    HAL_DMA_Init(&hdma_rx_RS485_1);
    // Associate the initialized DMA handle to the the UART handle
    __HAL_LINKDMA(huart, hdmarx, hdma_rx_RS485_1);

    // NVIC configuration for DMA transfer complete interrupt (USARTx_TX)
    HAL_NVIC_SetPriority(USART2_DMA_TX_IRQn, 6, 0);
//    HAL_NVIC_EnableIRQ(USART2_DMA_TX_IRQn);
    // NVIC configuration for DMA transfer complete interrupt (USARTx_RX)
    HAL_NVIC_SetPriority(USART2_DMA_RX_IRQn, 6, 0);
 //   HAL_NVIC_EnableIRQ(USART2_DMA_RX_IRQn);
    /* NVIC configuration for USART TC interrupt */
    HAL_NVIC_SetPriority(USART2_IRQn, 6, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);

  }
  // ---------------------------- RS485_2 ---------------------------------
  else if(huart->Instance==UART5)
  {
	__GPIOD_CLK_ENABLE();
     __UART5_CLK_ENABLE();
    __DMA1_CLK_ENABLE();

    //PC12     ------> USART5_TX
    //PD2     ------> USART5_RX
    //PD3     ------> USART5_RTS

    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART5;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART5;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    // Configure the DMA handler for Transmission process
    hdma_tx_RS485_2.Instance                 = USART3_TX_DMA_STREAM;
    hdma_tx_RS485_2.Init.Channel             = USART3_TX_DMA_CHANNEL;
    hdma_tx_RS485_2.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_tx_RS485_2.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_tx_RS485_2.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_tx_RS485_2.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_tx_RS485_2.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_tx_RS485_2.Init.Mode                = DMA_NORMAL;//DMA_NORMAL;
    hdma_tx_RS485_2.Init.Priority            = DMA_PRIORITY_LOW;//DMA_PRIORITY_LOW;
    hdma_tx_RS485_2.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;//DMA_FIFOMODE_DISABLE;
    hdma_tx_RS485_2.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_tx_RS485_2.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_tx_RS485_2.Init.PeriphBurst         = DMA_PBURST_INC4;
    HAL_DMA_Init(&hdma_tx_RS485_2);
    // Associate the initialized DMA handle to the UART handle
    __HAL_LINKDMA(huart, hdmatx, hdma_tx_RS485_2);

    // Configure the DMA handler for reception process
    hdma_rx_RS485_2.Instance                 = USART3_RX_DMA_STREAM;
    hdma_rx_RS485_2.Init.Channel             = USART3_RX_DMA_CHANNEL;
    hdma_rx_RS485_2.Init.Direction           = DMA_PERIPH_TO_MEMORY;
    hdma_rx_RS485_2.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_rx_RS485_2.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_rx_RS485_2.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_rx_RS485_2.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_rx_RS485_2.Init.Mode                = DMA_NORMAL;
    hdma_rx_RS485_2.Init.Priority            = DMA_PRIORITY_HIGH;
    hdma_rx_RS485_2.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_rx_RS485_2.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_rx_RS485_2.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_rx_RS485_2.Init.PeriphBurst         = DMA_PBURST_INC4;
    HAL_DMA_Init(&hdma_rx_RS485_2);
    // Associate the initialized DMA handle to the the UART handle
    __HAL_LINKDMA(huart, hdmarx, hdma_rx_RS485_2);


    HAL_NVIC_SetPriority(USART3_DMA_TX_IRQn, 6, 0);
  //  HAL_NVIC_EnableIRQ(USART3_DMA_TX_IRQn);

    HAL_NVIC_SetPriority(USART3_DMA_RX_IRQn, 6, 0);
  //  HAL_NVIC_EnableIRQ(USART3_DMA_RX_IRQn);
    /* NVIC configuration for USART TC interrupt */
    HAL_NVIC_SetPriority(USART3_IRQn, 6, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);


  }
}
/*************************************************************************
* HAL_UART_MspDeInit
**************************************************************************/
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
	static  DMA_HandleTypeDef hdma_rx_MODBUS;
	static  DMA_HandleTypeDef hdma_tx_MODBUS;

	static  DMA_HandleTypeDef hdma_rx_DEBUG;
	static  DMA_HandleTypeDef hdma_tx_DEBUG;

	static  DMA_HandleTypeDef hdma_rx_RS485_1;
	static  DMA_HandleTypeDef hdma_tx_RS485_1;

	static  DMA_HandleTypeDef hdma_rx_RS485_2;
	static  DMA_HandleTypeDef hdma_tx_RS485_2;

  if(huart->Instance==UART4)
  {

    __UART4_CLK_DISABLE();
    /**UART4 GPIO Configuration    
    PC10     ------> UART4_TX
    PC11     ------> UART4_RX 
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_10|GPIO_PIN_11);

    HAL_DMA_DeInit(&hdma_tx_MODBUS);
    HAL_DMA_DeInit(&hdma_rx_MODBUS);
    HAL_NVIC_DisableIRQ(UART4_DMA_TX_IRQn);
    HAL_NVIC_DisableIRQ(UART4_DMA_RX_IRQn);
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

    HAL_DMA_DeInit(&hdma_tx_DEBUG);
    HAL_DMA_DeInit(&hdma_rx_DEBUG);
    HAL_NVIC_DisableIRQ(UART4_DMA_TX_IRQn);
    HAL_NVIC_DisableIRQ(UART4_DMA_RX_IRQn);

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
    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_5|GPIO_PIN_6);

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
    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_8|GPIO_PIN_9);

  }
} 



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
