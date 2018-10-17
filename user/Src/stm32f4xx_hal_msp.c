/**
  ******************************************************************************
  * @file    stm32f4xx_hal_msp_template.c
  * @author  MCD Application Team
  * @version V1.3.0
  * @date    09-March-2015
  * @brief   This file contains the HAL System and Peripheral (PPP) MSP initialization
  *          and de-initialization functions.
  *          It should be copied to the application folder and renamed into 'stm32f4xx_hal_msp.c'.           
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
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

#include "ExtSPImem.h"
#include "ConfBoard.h"
#include <main.h>
/** @addtogroup STM32F4xx_HAL_Driver
  * @{
  */

/** @defgroup HAL_MSP HAL MSP
  * @brief HAL MSP module.
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief RTC MSP Initialization
  *        This function configures the hardware resources used in this example
  * @param hrtc: RTC handle pointer
  *
  * @note  Care must be taken when HAL_RCCEx_PeriphCLKConfig() is used to select
  *        the RTC clock source; in this case the Backup domain will be reset in
  *        order to modify the RTC Clock source, as consequence RTC registers (including
  *        the backup registers) and RCC_BDCR register are set to their reset values.
  *
  * @retval None
  */
void HAL_RTC_MspInit(RTC_HandleTypeDef *hrtc)
{

  RCC_OscInitTypeDef        RCC_OscInitStruct;
  RCC_PeriphCLKInitTypeDef  PeriphClkInitStruct;


  __HAL_RCC_PWR_CLK_ENABLE();
  HAL_PWR_EnableBkUpAccess();

  /*##-2- Configure LSE as RTC clock source ###################################*/
  //RCC_OscInitStruct.OscillatorType =  RCC_OSCILLATORTYPE_LSI;
  //RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  //RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  //HAL_RCC_OscConfig(&RCC_OscInitStruct);


  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
//TODO: на реальном приборе кварц не 8 а 25 ћ√ц. исправить делитель
#ifdef STM32F407xx
  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_HSE_DIV8;//RCC_RTCCLKSOURCE_HSE_DIV8;		// RTCCLK = 1MHz
#endif
#ifdef STM32F417xx			// HSE = 25MHz
  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_HSE_DIV25;//RCC_RTCCLKSOURCE_HSE_DIV25;		// RTCCLK = 1MHz
#endif
  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);

  __HAL_RCC_RTC_ENABLE();

}

/**
  * @brief RTC MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  * @param hrtc: RTC handle pointer
  * @retval None
  */
void HAL_RTC_MspDeInit(RTC_HandleTypeDef *hrtc)
{
  /*##-1- Reset peripherals ##################################################*/
  __HAL_RCC_RTC_DISABLE();

  /*##-2- Disables the PWR Clock and Disables access to the backup domain ###################################*/
  HAL_PWR_DisableBkUpAccess();
  __HAL_RCC_PWR_CLK_DISABLE();

}


/**
  * @brief SPI MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  *           - DMA configuration for transmission request by peripheral
  *           - NVIC configuration for DMA interrupt request enable
  * @param hspi: SPI handle pointer
  * @retval None
  */

void HAL_SPI_MspInit(SPI_HandleTypeDef* hspi)
{
	GPIO_InitTypeDef GPIO_InitStruct;
static  DMA_HandleTypeDef hdma_spi1_rx;
static  DMA_HandleTypeDef hdma_spi1_tx;

db161d_CS_GPIO_CLK_ENABLE();

GPIO_InitStruct.Pin = db161d_CS_PIN;
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
GPIO_InitStruct.Pull = GPIO_PULLUP;
GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

HAL_GPIO_Init(db161d_CS_GPIO_PORT, &GPIO_InitStruct);

MEM_Chipselect(GPIO_PIN_SET);


  if(hspi->Instance==SPI1)
  {
	  /* Enable GPIO TX/RX clock */
	  SPIx_SCK_GPIO_CLK_ENABLE();
	  SPIx_MISO_GPIO_CLK_ENABLE();
	  SPIx_MOSI_GPIO_CLK_ENABLE();

	  /* Enable SPI1 clock */
	  SPIx_CLK_ENABLE();
	  /* Enable DMA2 clock */
	  DMAx_CLK_ENABLE();

    /**SPI1 GPIO Configuration
    PA4     ------> SPI1_NSS
    PA5     ------> SPI1_SCK
    PA6     ------> SPI1_MISO
    PB5     ------> SPI1_MOSI
    */
    GPIO_InitStruct.Pin = /*GPIO_PIN_4|*/GPIO_PIN_5|GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;//GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;//GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Peripheral DMA init*/

    hdma_spi1_rx.Instance = SPIx_RX_DMA_STREAM;
    hdma_spi1_rx.Init.Channel = SPIx_RX_DMA_CHANNEL;
    hdma_spi1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_spi1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi1_rx.Init.Mode = DMA_NORMAL;
    hdma_spi1_rx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_spi1_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    HAL_DMA_Init(&hdma_spi1_rx);

    __HAL_LINKDMA(hspi,hdmarx,hdma_spi1_rx);

    hdma_spi1_tx.Instance = SPIx_TX_DMA_STREAM;
    hdma_spi1_tx.Init.Channel = SPIx_TX_DMA_CHANNEL;
    hdma_spi1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_spi1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi1_tx.Init.Mode = DMA_NORMAL;
    hdma_spi1_tx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_spi1_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    HAL_DMA_Init(&hdma_spi1_tx);

    __HAL_LINKDMA(hspi,hdmatx,hdma_spi1_tx);


    /* NVIC configuration for DMA transfer complete interrupt (SPI1_TX) */
    HAL_NVIC_SetPriority(SPIx_DMA_TX_IRQn, 4, 0);
    HAL_NVIC_EnableIRQ(SPIx_DMA_TX_IRQn);

    /* NVIC configuration for DMA transfer complete interrupt (SPI1_RX) */
    HAL_NVIC_SetPriority(SPIx_DMA_RX_IRQn, 4, 0);
    HAL_NVIC_EnableIRQ(SPIx_DMA_RX_IRQn);

  /* USER CODE END SPI1_MspInit 1 */
  }

}

void HAL_SPI_MspDeInit(SPI_HandleTypeDef* hspi)
{

  if(hspi->Instance==SPI1)
  {

    /* Peripheral clock disable */
    __SPI1_CLK_DISABLE();

    /**SPI1 GPIO Configuration
    PA4     ------> SPI1_NSS
    PA5     ------> SPI1_SCK
    PA6     ------> SPI1_MISO
    PB5     ------> SPI1_MOSI
    */
    HAL_GPIO_DeInit(GPIOA, /*GPIO_PIN_4|*/GPIO_PIN_5|GPIO_PIN_6);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_5);

    /* Peripheral DMA DeInit*/
    HAL_DMA_DeInit(hspi->hdmarx);
    HAL_DMA_DeInit(hspi->hdmatx);

    /* Peripheral interrupt DeInit*/
    HAL_NVIC_DisableIRQ(SPIx_DMA_RX_IRQn);
    HAL_NVIC_DisableIRQ(SPIx_DMA_TX_IRQn);

  }

}
void HAL_SRAM_MspInit(SRAM_HandleTypeDef *hsram)
{
  GPIO_InitTypeDef GPIO_Init_Structure;

  /* Enable FSMC clock */
  __HAL_RCC_FSMC_CLK_ENABLE();

  /* Enable GPIOs clock */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /* Common GPIO configuration */
  GPIO_Init_Structure.Mode      = GPIO_MODE_AF_PP;
  GPIO_Init_Structure.Pull      = GPIO_PULLUP;
  GPIO_Init_Structure.Speed     = GPIO_SPEED_HIGH;
  GPIO_Init_Structure.Alternate = GPIO_AF12_FSMC;

  /* GPIOD configuration  D2 D3 OE WE CE(NE1) A16 A17 A18 D1 D0 */
  GPIO_Init_Structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_7 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
  HAL_GPIO_Init(GPIOD, &GPIO_Init_Structure);

  /* GPIOE configuration A19 A20 D4-D7*/
  GPIO_Init_Structure.Pin   = GPIO_PIN_3| GPIO_PIN_4 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
  HAL_GPIO_Init(GPIOE, &GPIO_Init_Structure);

  /* GPIOF configuration A0-A9 */
  GPIO_Init_Structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2| GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
  HAL_GPIO_Init(GPIOF, &GPIO_Init_Structure);

  /* GPIOG configuration A10-A15*/
  GPIO_Init_Structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2| GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5;
  HAL_GPIO_Init(GPIOG, &GPIO_Init_Structure);

}

/**
  * @brief SRAM MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO configuration to their default state
  * @param hsram: SRAM handle pointer
  * @retval None
  */
void HAL_SRAM_MspDeInit(SRAM_HandleTypeDef *hsram)
{

  /*## Disable peripherals and GPIO Clocks ###################################*/
  /* Configure FSMC as alternate function  */
  HAL_GPIO_DeInit(GPIOD, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_7 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15);
  HAL_GPIO_DeInit(GPIOE, GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10);
  HAL_GPIO_DeInit(GPIOF, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15);
  HAL_GPIO_DeInit(GPIOG, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5);
}

void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
//	MEM_Chipselect(GPIO_PIN_SET);				// выключим CS
//	USART_0TRACE("\n");
//	USART_TRACE_BLUE("int---HAL_SPI_RxCpltCallback---\n");
}
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
//	MEM_Chipselect(GPIO_PIN_SET);				// выключим CS
//	USART_0TRACE("\n");
//	USART_TRACE_BLUE("int---HAL_SPI_TxCpltCallback---\n");
}
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{

}

 void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi)
{
//	USART_0TRACE("\n");
//	USART_TRACE_RED("int---HAL_SPI_ErrorCallback---\n");

}



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
