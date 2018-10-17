/**
 ******************************************************************************
  * File Name          : ethernetif.h
  * Description        : This file provides initialization code for LWIP
  *                      middleWare.
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
  

#ifndef __ETHERNETIF_H__
#define __ETHERNETIF_H__

#include "lwip/err.h"
#include "lwip/netif.h"
#include "cmsis_os.h"

/* Exported types ------------------------------------------------------------*/
/* Structure that include link thread parameters */
struct link_str {
  struct netif *netif;
  osSemaphoreId semaphore;
};


/* Exported functions ------------------------------------------------------- */
err_t ethernetif_init(struct netif *netif);
void ethernetif_input( void const * argument ); 
 

void ethernetif_set_link(void const *argument);
void ethernetif_update_config(struct netif *netif);
void ethernetif_notify_conn_changed(struct netif *netif);

void		PHY_setSwitchMode(void* self);

uint16_t 	PHY_ReadStaticMACTable(uint8_t * addr);
uint16_t 	PHY_WriteStaticMACTable(uint16_t	addr, uint8_t * MAC);			// записываем MAC в стат. таблицу для фильтрации
uint16_t 	PHY_ReadDynamicMACTable(uint8_t * addr);
int 		PHY_SetPortsStaticMAC(char*	port1, char*	port2);						// статические одреса портам

int 		PHY_SetPortsHSRMode(char*	MAC);
int 		PHY_SetPortsPRPMode(void);
int 		PHY_SetPortsNormalMode(void);


int 		PHY_Port1TxOff(uint16_t param);
int 		PHY_Port1TxOn(uint16_t param);
int 		PHY_Port2TxOff(uint16_t param);
int 		PHY_Port2TxOn(uint16_t param);

int 		PHY_SetMACFilter(PHY_PortNumber	port);								// пропускаем MAC из таблицы только в один порт
void 		PHY_PowerOFF(void);
void 		PHY_PowerON(void);


#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
