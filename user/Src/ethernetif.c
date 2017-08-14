/**
  ******************************************************************************
  * File Name          : ethernetif.c
  * Description        : This file provides code for the configuration
  *                      of the ethernetif.c MiddleWare.
  ******************************************************************************
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
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
//#include "stm32f4xx_hal_conf.h"
#include "lwip/opt.h"

#include "lwip/lwip_timers.h"
#include "netif/etharp.h"
#include "ethernetif.h"
#include <string.h>
#include "cmsis_os.h"

#include "main.h"
#include "ConfBoard.h"

/* Within 'USER CODE' section, code will be kept by default at each generation */
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* Private define ------------------------------------------------------------*/
/* The time to block waiting for input. */
#define TIME_WAITING_FOR_INPUT ( 100 )
/* Stack size of the interface thread */
#define INTERFACE_THREAD_STACK_SIZE ( 350 )

/* Network interface name */
#define IFNAME0 's'
#define IFNAME1 't'

/* USER CODE BEGIN 1 */
extern uint8_t	MAC_ADDR[6];
/* USER CODE END 1 */

/* Private variables ---------------------------------------------------------*/
#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
#endif
__ALIGN_BEGIN ETH_DMADescTypeDef  DMARxDscrTab[ETH_RXBUFNB] __ALIGN_END;/* Ethernet Rx MA Descriptor */

#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
#endif
__ALIGN_BEGIN ETH_DMADescTypeDef  DMATxDscrTab[ETH_TXBUFNB] __ALIGN_END;/* Ethernet Tx DMA Descriptor */

#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
#endif
__ALIGN_BEGIN uint8_t Rx_Buff[ETH_RXBUFNB][ETH_RX_BUF_SIZE] __ALIGN_END; /* Ethernet Receive Buffer */

#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
#endif
__ALIGN_BEGIN uint8_t Tx_Buff[ETH_TXBUFNB][ETH_TX_BUF_SIZE] __ALIGN_END; /* Ethernet Transmit Buffer */

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

/* Semaphore to signal incoming packets */
osSemaphoreId s_xSemaphore = NULL;

/* Global Ethernet handle*/
ETH_HandleTypeDef heth;

/* USER CODE BEGIN 3 */

/* USER CODE END 3 */

/*************************************************************************
 * Port_On
 *************************************************************************/
void PHY_PowerON(void)
{
  HAL_GPIO_WritePin(PHY_PWRDN_GPIO_PORT, PHY_PWRDN, GPIO_PIN_SET);
}
/*************************************************************************
 * Port_Off
 *************************************************************************/
void PHY_PowerOFF(void)
{
  HAL_GPIO_WritePin(PHY_PWRDN_GPIO_PORT, PHY_PWRDN, GPIO_PIN_RESET);
}

/* Private functions ---------------------------------------------------------*/

void HAL_ETH_MspInit(ETH_HandleTypeDef* heth)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  if(heth->Instance==ETH)
  {

    /* Peripheral clock enable */
    __ETH_CLK_ENABLE();
  
    /**ETH GPIO Configuration    
    PC1     ------> ETH_MDC
    PC2     ------> ETH_TXD2
    PC3     ------> ETH_TX_CLK
    PC4     ------> ETH_RXD0
    PC5     ------> ETH_RXD1

    PA0-WKUP------> ETH_CRS
    PA1     ------> ETH_RX_CLK
    PA2     ------> ETH_MDIO
    PA3     ------> ETH_COL
    PA7     ------> ETH_RX_DV					PU

    PB0     ------> ETH_RXD2
    PB1     ------> ETH_RXD3
    PB10    ------> ETH_RX_ER
    PB11    ------> ETH_TX_EN
    PB12    ------> ETH_TXD0
    PB13    ------> ETH_TXD1
    PB8     ------> ETH_TXD3 
    */

    GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_3;							// GPIO_PULLDOWN
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


    GPIO_InitStruct.Pin = GPIO_PIN_7;							// GPIO_PULLUP
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_12|GPIO_PIN_13;	// GPIO_PULLUP
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_1;							// GPIO_PULLDOWN
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_11| GPIO_PIN_8;				// GPIO_NOPULL
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

#ifndef KSZ8873
    //Configure GPIO pin : PA8
    GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

#else
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    //Configure GPIO pin : PA8
    GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
   // GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    PHY_PowerOFF();
    HAL_Delay(PHY_RESET_DELAY*2);
    PHY_PowerON();
#endif
    /* Peripheral interrupt init*/
    HAL_NVIC_SetPriority(ETH_IRQn, 12, 0);		//5
    HAL_NVIC_EnableIRQ(ETH_IRQn);
  }

}
/*******************************************************************************
 * HAL_ETH_MspDeInit
*******************************************************************************/
void HAL_ETH_MspDeInit(ETH_HandleTypeDef* heth)
{
  if(heth->Instance==ETH)
  {
    /* Peripheral clock disable */
    __ETH_CLK_DISABLE();

    /**ETH GPIO Configuration    
    PC1     ------> ETH_MDC
    PC2     ------> ETH_TXD2
    PC3     ------> ETH_TX_CLK
    PA0-WKUP     ------> ETH_CRS
    PA1     ------> ETH_RX_CLK
    PA2     ------> ETH_MDIO
    PA3     ------> ETH_COL
    PA7     ------> ETH_RX_DV
    PC4     ------> ETH_RXD0
    PC5     ------> ETH_RXD1
    PB0     ------> ETH_RXD2
    PB1     ------> ETH_RXD3
    PB10     ------> ETH_RX_ER
    PB11     ------> ETH_TX_EN
    PB12     ------> ETH_TXD0
    PB13     ------> ETH_TXD1
    PB8     ------> ETH_TXD3 
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5);
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_7);
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_8);
    /* Peripheral interrupt Deinit*/
    HAL_NVIC_DisableIRQ(ETH_IRQn);
  }
}

/*******************************************************************************
* @brief  Ethernet Rx Transfer completed callback
* @param  heth: ETH handle
* @retval None
*******************************************************************************/
void HAL_ETH_RxCpltCallback(ETH_HandleTypeDef *heth)
{
	//приняли данные от ETH. Семафорим об этом таску.

//	NVIC_SystemReset();

    osSemaphoreRelease(s_xSemaphore);
}
/*******************************************************************************
                       LL Driver Interface ( LwIP stack --> ETH) 
*******************************************************************************/
/**
 * In this function, the hardware should be initialized.
 * Called from ethernetif_init().
 *
 * @param netif the already initialized lwip network interface structure
 *        for this ethernetif
 */
static void low_level_init(struct netif *netif)
{ 
  uint32_t regvalue = 0;
  HAL_StatusTypeDef hal_eth_init_status;
  
// Init ETH

  heth.Instance = ETH;
  heth.Init.AutoNegotiation = ETH_AUTONEGOTIATION_ENABLE;
  heth.Init.Speed = ETH_SPEED_100M;
  heth.Init.DuplexMode = ETH_MODE_FULLDUPLEX;
  heth.Init.PhyAddress = 1;
  heth.Init.MACAddr = &MAC_ADDR[0];
  heth.Init.RxMode = ETH_RXINTERRUPT_MODE;
  heth.Init.ChecksumMode = ETH_CHECKSUM_BY_HARDWARE;
  heth.Init.MediaInterface = ETH_MEDIA_INTERFACE_MII;//ETH_MEDIA_INTERFACE_MII;

  hal_eth_init_status = HAL_ETH_Init(&heth);

  if (hal_eth_init_status == HAL_OK)
  {
    /* Set netif link flag */  
    netif->flags |= NETIF_FLAG_LINK_UP;
    USART_TRACE_MAGENTA("HAL_ETH_Init:%u\n",hal_eth_init_status);
  } else{
	USART_TRACE_RED("HAL_ETH_Init error:%u\n",hal_eth_init_status);

  }

  // Initialize Tx Descriptors list: Chain Mode
  HAL_ETH_DMATxDescListInit(&heth, DMATxDscrTab, &Tx_Buff[0][0], ETH_TXBUFNB);
     
  // Initialize Rx Descriptors list: Chain Mode
  HAL_ETH_DMARxDescListInit(&heth, DMARxDscrTab, &Rx_Buff[0][0], ETH_RXBUFNB);
 
#if LWIP_ARP || LWIP_ETHERNET 
  // set MAC hardware address length
  netif->hwaddr_len = ETHARP_HWADDR_LEN;
  
  // set MAC hardware address
  netif->hwaddr[0] =  heth.Init.MACAddr[0];
  netif->hwaddr[1] =  heth.Init.MACAddr[1];
  netif->hwaddr[2] =  heth.Init.MACAddr[2];
  netif->hwaddr[3] =  heth.Init.MACAddr[3];
  netif->hwaddr[4] =  heth.Init.MACAddr[4];
  netif->hwaddr[5] =  heth.Init.MACAddr[5];
  
  /* maximum transfer unit */
  netif->mtu = 1500;
  
  /* Accept broadcast address and ARP traffic */
  /* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
  #if LWIP_ARP
    netif->flags |= NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP;
  #else 
    netif->flags |= NETIF_FLAG_BROADCAST;
  #endif /* LWIP_ARP */

#if LWIP_IGMP
  netif->flags |= NETIF_FLAG_IGMP;
#endif /* LWIP_IGMP */

/* create a binary semaphore used for informing ethernetif of frame reception */
  osSemaphoreDef(SEM);
  s_xSemaphore = osSemaphoreCreate(osSemaphore(SEM) , 1 );

  USART_TRACE_MAGENTA("Создали семафор для EthIf :0x%X\n",s_xSemaphore);
  USART_TRACE_MAGENTA("запускаем таск который будет принимать данные из ETH_MAC\n");
// запускаем таск который будет принимать данные через семафор из прерывания ETH_MAC
  osThreadDef(EthIf, ethernetif_input, osPriorityRealtime, 0, INTERFACE_THREAD_STACK_SIZE);
  osThreadCreate (osThread(EthIf), netif);
 
  /* Enable MAC and DMA transmission and reception */
  HAL_ETH_Start(&heth);
  
#ifndef KSZ8873
  /**** Configure PHY to generate an interrupt when Eth Link state changes ****/
  /* Read Register Configuration */
  HAL_ETH_ReadPHYRegister(&heth, PHY_MICR, &regvalue);
  
  regvalue |= (PHY_MICR_INT_EN | PHY_MICR_INT_OE);

  /* Enable Interrupts */
  HAL_ETH_WritePHYRegister(&heth, PHY_MICR, regvalue );
  
  /* Read Register Configuration */
  HAL_ETH_ReadPHYRegister(&heth, PHY_MISR, &regvalue);
  
  regvalue |= PHY_MISR_LINK_INT_EN;
    
  /* Enable Interrupt on change of link status */
  HAL_ETH_WritePHYRegister(&heth, PHY_MISR, regvalue);
#endif

#endif /* LWIP_ARP || LWIP_ETHERNET */
}

/**
  * @brief This function should do the actual transmission of the packet. The packet is
  * contained in the pbuf that is passed to the function. This pbuf
  * might be chained.
  *
  * @param netif the lwip network interface structure for this ethernetif
  * @param p the MAC packet to send (e.g. IP packet including MAC addresses and type)
  * @return ERR_OK if the packet could be sent
  *         an err_t value if the packet couldn't be sent
  *
  * @note Returning ERR_MEM here if a DMA queue of your MAC is full can lead to
  *       strange results. You might consider waiting for space in the DMA queue
  *       to become available since the stack doesn't retry to send a packet
  *       dropped because of memory failure (except for the TCP timers).
  */
static err_t low_level_output(struct netif *netif, struct pbuf *p)
{
  err_t errval;
  struct pbuf *q;
  uint8_t *buffer = (uint8_t *)(heth.TxDesc->Buffer1Addr);
  __IO ETH_DMADescTypeDef *DmaTxDesc;
  uint32_t framelength = 0;
  uint32_t bufferoffset = 0;
  uint32_t byteslefttocopy = 0;
  uint32_t payloadoffset = 0;

  DmaTxDesc = heth.TxDesc;
  bufferoffset = 0;
  
  /* copy frame from pbufs to driver buffers */
  for(q = p; q != NULL; q = q->next)
  {
    /* Is this buffer available? If not, goto error */
    if((DmaTxDesc->Status & ETH_DMATXDESC_OWN) != (uint32_t)RESET)
    {
      errval = ERR_USE;
      goto error;
    }

    /* Get bytes in current lwIP buffer */
    byteslefttocopy = q->len;
    payloadoffset = 0;

    /* Check if the length of data to copy is bigger than Tx buffer size*/
    while( (byteslefttocopy + bufferoffset) > ETH_TX_BUF_SIZE )
    {
      /* Copy data to Tx buffer*/
      memcpy( (uint8_t*)((uint8_t*)buffer + bufferoffset), (uint8_t*)((uint8_t*)q->payload + payloadoffset), (ETH_TX_BUF_SIZE - bufferoffset) );

      /* Point to next descriptor */
      DmaTxDesc = (ETH_DMADescTypeDef *)(DmaTxDesc->Buffer2NextDescAddr);

      /* Check if the buffer is available */
      if((DmaTxDesc->Status & ETH_DMATXDESC_OWN) != (uint32_t)RESET)
      {
        errval = ERR_USE;
        goto error;
      }
      
      buffer = (uint8_t *)(DmaTxDesc->Buffer1Addr);
      
      byteslefttocopy = byteslefttocopy - (ETH_TX_BUF_SIZE - bufferoffset);
      payloadoffset = payloadoffset + (ETH_TX_BUF_SIZE - bufferoffset);
      framelength = framelength + (ETH_TX_BUF_SIZE - bufferoffset);
      bufferoffset = 0;
    }
    
    /* Copy the remaining bytes */
    memcpy( (uint8_t*)((uint8_t*)buffer + bufferoffset), (uint8_t*)((uint8_t*)q->payload + payloadoffset), byteslefttocopy );
    bufferoffset = bufferoffset + byteslefttocopy;
    framelength = framelength + byteslefttocopy;
  }
  
  /* Prepare transmit descriptors to give to DMA */ 
  HAL_ETH_TransmitFrame(&heth, framelength);
  
  errval = ERR_OK;
  
error:
  
  /* When Transmit Underflow flag is set, clear it and issue a Transmit Poll Demand to resume transmission */
  if ((heth.Instance->DMASR & ETH_DMASR_TUS) != (uint32_t)RESET)
  {
    /* Clear TUS ETHERNET DMA flag */
    heth.Instance->DMASR = ETH_DMASR_TUS;

    /* Resume DMA transmission*/
    heth.Instance->DMATPDR = 0;
  }
  return errval;
}

/**
  * @brief Should allocate a pbuf and transfer the bytes of the incoming
  * packet from the interface into the pbuf.
  *
  * @param netif the lwip network interface structure for this ethernetif
  * @return a pbuf filled with the received packet (including MAC header)
  *         NULL on memory error
  */
static struct pbuf * low_level_input(struct netif *netif)
{
  struct pbuf *p = NULL, *q = NULL;
  uint16_t len = 0;
  uint8_t *buffer;
  __IO ETH_DMADescTypeDef *dmarxdesc;
  uint32_t bufferoffset = 0;
  uint32_t payloadoffset = 0;
  uint32_t byteslefttocopy = 0;
  uint32_t i=0;
  
  /* get received frame */
  if(HAL_ETH_GetReceivedFrame_IT(&heth) != HAL_OK)
    return NULL;
  
  /* Obtain the size of the packet and put it into the "len" variable. */
  len = heth.RxFrameInfos.length;
  buffer = (uint8_t *)heth.RxFrameInfos.buffer;
  
  if (len > 0)
  {
    /* We allocate a pbuf chain of pbufs from the Lwip buffer pool */
    p = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);
  }
  
  if (p != NULL)
  {
    dmarxdesc = heth.RxFrameInfos.FSRxDesc;
    bufferoffset = 0;

    for(q = p; q != NULL; q = q->next)
    {
      byteslefttocopy = q->len;
      payloadoffset = 0;
      
      /* Check if the length of bytes to copy in current pbuf is bigger than Rx buffer size */
      while( (byteslefttocopy + bufferoffset) > ETH_RX_BUF_SIZE )
      {
        /* Copy data to pbuf */
        memcpy( (uint8_t*)((uint8_t*)q->payload + payloadoffset), (uint8_t*)((uint8_t*)buffer + bufferoffset), (ETH_RX_BUF_SIZE - bufferoffset));
        
        /* Point to next descriptor */
        dmarxdesc = (ETH_DMADescTypeDef *)(dmarxdesc->Buffer2NextDescAddr);
        buffer = (uint8_t *)(dmarxdesc->Buffer1Addr);
        
        byteslefttocopy = byteslefttocopy - (ETH_RX_BUF_SIZE - bufferoffset);
        payloadoffset = payloadoffset + (ETH_RX_BUF_SIZE - bufferoffset);
        bufferoffset = 0;
      }

      /* Copy remaining data in pbuf */
      memcpy( (uint8_t*)((uint8_t*)q->payload + payloadoffset), (uint8_t*)((uint8_t*)buffer + bufferoffset), byteslefttocopy);
      bufferoffset = bufferoffset + byteslefttocopy;
    }
  }
    
  /* Release descriptors to DMA */
  /* Point to first descriptor */
  dmarxdesc = heth.RxFrameInfos.FSRxDesc;
  /* Set Own bit in Rx descriptors: gives the buffers back to DMA */
  for (i=0; i< heth.RxFrameInfos.SegCount; i++)
  {
    dmarxdesc->Status |= ETH_DMARXDESC_OWN;
    dmarxdesc = (ETH_DMADescTypeDef *)(dmarxdesc->Buffer2NextDescAddr);
  }

  /* Clear Segment_Count */
  heth.RxFrameInfos.SegCount =0;
  
  /* When Rx Buffer unavailable flag is set: clear it and resume reception */
  if ((heth.Instance->DMASR & ETH_DMASR_RBUS) != (uint32_t)RESET)
  {
    /* Clear RBUS ETHERNET DMA flag */
    heth.Instance->DMASR = ETH_DMASR_RBUS;
    /* Resume DMA reception */
    heth.Instance->DMARPDR = 0;
  }
  return p;
}

/**
 * This function should be called when a packet is ready to be read
 * from the interface. It uses the function low_level_input() that
 * should handle the actual reception of bytes from the network
 * interface. Then the type of the received packet is determined and
 * the appropriate input function is called.
 *
 * @param netif the lwip network interface structure for this ethernetif
 *
 * Прием данных из ETH через семафор, выставленный в прерывании
 */
void ethernetif_input( void const * argument ) 
 
{
 
  struct pbuf *p;
  struct netif *netif = (struct netif *) argument;
  
  err_t	ret_error;

  for( ;; )
  {
    if (osSemaphoreWait( s_xSemaphore, TIME_WAITING_FOR_INPUT)==osOK)		// ждем данных от ETH
    {
      do
      {   
        p = low_level_input( netif );										// принимаем данные в P.
        if   (p != NULL)
        {
        	ret_error = netif->input( p, netif);
          if (ret_error != ERR_OK )							// вызываем функцию приема данных она же: (err_t)tcpip_input(struct pbuf *p, struct netif *inp)
          {
        	  printf("ethernetif input ERROR : %i \n", ret_error);
              pbuf_free(p);
          }else{
//              printf("tcpip_input no error. pbuf: 0x%x\n",(unsigned int)p);
          }
        }
      } while(p!=NULL);
    }
 
  }
}

#if !LWIP_ARP
/**
 * This function has to be completed by user in case of ARP OFF.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return ERR_OK if ...
 */
static err_t low_level_output_arp_off(struct netif *netif, struct pbuf *q, ip_addr_t *ipaddr)
{  
  err_t errval;
  errval = ERR_OK;
    
/* USER CODE BEGIN 5 */ 
    
/* USER CODE END 5 */  
    
  return errval;
  
}
#endif /* LWIP_ARP */ 

/**
 * Should be called at the beginning of the program to set up the
 * network interface. It calls the function low_level_init() to do the
 * actual setup of the hardware.
 *
 * This function should be passed as a parameter to netif_add().
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return ERR_OK if the loopif is initialized
 *         ERR_MEM if private data couldn't be allocated
 *         any other err_t on error
 */
err_t ethernetif_init(struct netif *netif)
{
  LWIP_ASSERT("netif != NULL", (netif != NULL));
  
  USART_TRACE_GREEN("ethernetif_init.\n");


#if LWIP_NETIF_HOSTNAME
  /* Initialize interface hostname */
  netif->hostname = "lwip";
#endif /* LWIP_NETIF_HOSTNAME */

  netif->name[0] = IFNAME0;
  netif->name[1] = IFNAME1;
  /* We directly use etharp_output() here to save a function call.
   * You can instead declare your own function an call etharp_output()
   * from it if you have to do some checks before sending (e.g. if link
   * is available...) */
#if LWIP_ARP || LWIP_ETHERNET
#if LWIP_ARP
  netif->output = etharp_output;
#else
  /* The user should write ist own code in low_level_output_arp_off function */
  netif->output = low_level_output_arp_off;
#endif /* LWIP_ARP */ 
#endif  /* LWIP_ARP || LWIP_ETHERNET */
  netif->linkoutput = low_level_output;

  /* initialize the hardware */
  low_level_init(netif);

  return ERR_OK;
}

/* USER CODE BEGIN 6 */

/**
* @brief  Returns the current time in milliseconds
*         when LWIP_TIMERS == 1 and NO_SYS == 1
* @param  None
* @retval Time
*/
u32_t sys_jiffies(void)
{
  return HAL_GetTick();
}

/**
* @brief  Returns the current time in milliseconds
*         when LWIP_TIMERS == 1 and NO_SYS == 1
* @param  None
* @retval Time
*/
u32_t sys_now(void)
{
  return HAL_GetTick();
}

/* USER CODE END 6 */

/**
  * @brief  This function sets the netif link status.
  * @param  netif: the network interface
  * @retval None
  */
void ethernetif_set_link(void const *argument)
{
  uint32_t regvalue = 0;
  struct link_str *link_arg = (struct link_str *)argument;
#ifndef	KSZ8873
  for(;;)
  {
    if (osSemaphoreWait( link_arg->semaphore, 100)== osOK)
    {
      /* Read PHY_MISR читаем PHY control регистр*/
      HAL_ETH_ReadPHYRegister(&heth, PHY_MISR, &regvalue);
      
      /* Check whether the link interrupt has occurred or not */
      // проверяем произошло ли прерывание LINK
      if((regvalue & PHY_LINK_INTERRUPT) != (uint16_t)RESET)
      {
        /* Read PHY_SR читаем PHY статус регистр */
        HAL_ETH_ReadPHYRegister(&heth, PHY_SR, &regvalue);

        /* Check whether the link is up or down*/
        // проверяем LINK статус.
        if((regvalue & PHY_LINK_STATUS)!= (uint16_t)RESET)
        {
          netif_set_link_up(link_arg->netif);
        }
        else
        {
          netif_set_link_down(link_arg->netif);
        }
        /*! Check whether the link is up or down*/
      }
    }
  }
#else
  for(;;)
   {
     if (osSemaphoreWait( link_arg->semaphore, 100)== osOK)
     {
       /* Read PHY_MISR читаем PHY control регистр*/
//       HAL_ETH_ReadPHYRegister(&heth, PHY_MISR, &regvalue);

       /* Check whether the link interrupt has occurred or not */
       // проверяем произошло ли прерывание LINK
//       if((regvalue & PHY_LINK_INTERRUPT) != (uint16_t)RESET)
       {
         /* Read PHY_SR читаем PHY статус регистр */
         HAL_ETH_ReadPHYRegister(&heth, PHY_BSR, &regvalue);

         /* Check whether the link is up or down*/
         // проверяем LINK статус.
         if((regvalue & PHY_LINKED_STATUS)!= (uint16_t)RESET)
         {
        	 USART_TRACE_BLUE("netif_set_link_up....\n");

           netif_set_link_up(link_arg->netif);
         }
         else
         {
           	 USART_TRACE_BLUE("netif_set_link_down....\n");

           netif_set_link_down(link_arg->netif);
         }
         /*! Check whether the link is up or down*/
       }
     }
   }
#endif
}

/* USER CODE BEGIN 7 */

/* USER CODE END 7 */

#if LWIP_NETIF_LINK_CALLBACK
/**
  * @brief  Link callback function, this function is called on change of link status
  *         to update low level driver configuration.
* @param  netif: The network interface
  * @retval None
  */
void ethernetif_update_config(struct netif *netif)
{
  __IO uint32_t tickstart = 0;
  uint32_t regvalue = 0;
  
  USART_TRACE_GREEN("ethernetif_update_config.\n");

/*
  if(netif_is_link_up(netif))
  { 
    // Restart the auto-negotiation
    if(heth.Init.AutoNegotiation != ETH_AUTONEGOTIATION_DISABLE)
    {
      HAL_ETH_WritePHYRegister(&heth, PHY_BCR, PHY_AUTONEGOTIATION);					// Enable Auto-Negotiation

      // Get tick
      tickstart = HAL_GetTick();

      // Wait until the auto-negotiation will be completed
		do
		{
		  HAL_ETH_ReadPHYRegister(&heth, PHY_BSR, &regvalue);

		  // Check for the Timeout ( 1s )
		  if((HAL_GetTick() - tickstart ) > 1000)
		  {
			// In case of timeout
			goto error;
		  }
		} while (((regvalue & PHY_AUTONEGO_COMPLETE) != PHY_AUTONEGO_COMPLETE));


      // Read the result of the auto-negotiation
      HAL_ETH_ReadPHYRegister(&heth, PHY_ANLPA, &regvalue);
    	  // проверка состояния 0x5 адреса на возможности партнера
       if((regvalue & Partner_FULLDUPLEX_100M) != (uint32_t)RESET)
       {
    	   heth.Init.DuplexMode = ETH_MODE_FULLDUPLEX;
    	   heth.Init.Speed = ETH_SPEED_100M;
       }
       else
       if((regvalue & Partner_HALFDUPLEX_100M) != (uint32_t)RESET)
       {
    	   heth.Init.DuplexMode = ETH_MODE_HALFDUPLEX;
    	   heth.Init.Speed = ETH_SPEED_100M;
       }
       else
       if((regvalue & Partner_FULLDUPLEX_10M) != (uint32_t)RESET)
       {
    	   heth.Init.DuplexMode = ETH_MODE_FULLDUPLEX;
    	   heth.Init.Speed = ETH_SPEED_10M;
       }
       else
       if((regvalue & Partner_HALFDUPLEX_10M) != (uint32_t)RESET)
       {
    	   heth.Init.DuplexMode = ETH_MODE_HALFDUPLEX;
    	   heth.Init.Speed = ETH_SPEED_10M;
       }
       else

       {
       // зафиксируем без вариантов скорость и направление
       heth.Init.DuplexMode = ETH_MODE_FULLDUPLEX;
       heth.Init.Speed = ETH_SPEED_100M;
       }

      assert_param(IS_ETH_SPEED(heth->Init.Speed));
      assert_param(IS_ETH_DUPLEX_MODE(heth->Init.DuplexMode));

      HAL_ETH_WritePHYRegister(&heth, PHY_BCR, ((uint16_t)(heth.Init.DuplexMode >> 3) | (uint16_t)(heth.Init.Speed >> 1)));

      HAL_Delay(PHY_CONFIG_DELAY);
    }
    else // AutoNegotiation Disable
    {
    error :
      assert_param(IS_ETH_SPEED(heth.Init.Speed));
      assert_param(IS_ETH_DUPLEX_MODE(heth.Init.DuplexMode));
      
      HAL_ETH_WritePHYRegister(&heth, PHY_BCR, ((uint16_t)(heth.Init.DuplexMode >> 3) | (uint16_t)(heth.Init.Speed >> 1)));
    }

    HAL_ETH_ConfigMAC(&heth, (ETH_MACInitTypeDef *) NULL);
    HAL_ETH_Start(&heth);
  }
  else
  {
    // Stop MAC interface
    HAL_ETH_Stop(&heth);
  }
*/
  ethernetif_notify_conn_changed(netif);
}

/* USER CODE BEGIN 8 */
/**
  * @brief  This function notify user about link status changement.
  * @param  netif: the network interface
  * @retval None
  */
__weak void ethernetif_notify_conn_changed(struct netif *netif)
{
  /* NOTE : This is function could be implemented in user file 
            when the callback is needed,
  */

}
/* USER CODE END 8 */ 
#endif /* LWIP_NETIF_LINK_CALLBACK */

/* USER CODE BEGIN 9 */

/* USER CODE END 9 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

