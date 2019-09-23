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
#include "port.h"

#include "main.h"
#include "ConfBoard.h"

#include "ksz8873.h"

#include "iso_server.h"

#include "hsr_prp_main.h"
#include "lib_memory.h"
/* Private define ------------------------------------------------------------*/
RedModeType 	RedMode;

struct prp_rct	PRP_Traler;
struct hsr_tag	HSR_Tag;

/* The time to block waiting for input. */
#define TIME_WAITING_FOR_INPUT ( 100 )
/* Stack size of the interface thread */
//#define INTERFACE_THREAD_STACK_SIZE ( 350 )

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
__ALIGN_BEGIN ETH_DMADescTypeDef  DMARxDscrTab[ETH_RXBUFNB] __ALIGN_END;/* Ethernet Rx DMA Descriptor */

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

extern osSemaphoreId Netif_LinkSemaphore;
/*************************************************************************
 * SetRedundansyMode
 * вызавается после инита ETHERNET
 *************************************************************************/
void 		SetRedundansyMode(RedModeType RedMode){

	switch (RedMode){
		case RM_OFF:
			PHY_SetPortsNormalMode();
			set_redundancyMode(RM_OFF);
			set_HardwareCRCMode(HardwareCRC);
			break;

		case RM_HSR_V1:
			PHY_SetPortsHSRMode((char*)&MAC_ADDR);
			set_redundancyMode(RM_HSR_V1);
			set_HardwareCRCMode(SoftwareCRC);
			break;

		case RM_PRP_V1:
			PHY_SetPortsPRPMode();
			set_redundancyMode(RM_PRP_V1);
			set_HardwareCRCMode(HardwareCRC);
		break;
	}

    USART_TRACE_BLUE("режим резервирования:%i \n", RedMode);
}
/*************************************************************************
 *
 *************************************************************************/
uint16_t PHY_ReadStaticMACTable(uint8_t * addr)
{
	uint8_t		MACrd[9];
	uint16_t	numb = 0,i,j;
	uint8_t		port;
	uint8_t		cmd;

	if(addr){
		char* prt;
		port = HAL_ETH_SoftSMIRead(14) & 0b111;
		if (port == 6)	 prt = "1"; else
		if (port == 5)	 prt = "2"; else
		if (port == 4)	 prt = "1,2"; else
		if (port == 3)	 prt = "3"; else
		if (port == 2)	 prt = "1,3"; else
		if (port == 1)	 prt = "2,3"; else
		prt = "1,2,3";

		sprintf((char *)addr,"<table border=1 align=center>");
		addr += strlen((char *)addr );
		sprintf((char *)addr,"<tr><th>разрешенные MAC для портов: %s</th></tr>",prt);
		addr += strlen((char *)addr );
	}

	USART_0TRACE("StaticMACTable\n");

	for(i=0;i<8;i++){

		cmd = (uint8_t)ReadMAC | (uint8_t)StaticMAC_Sel | (uint8_t)((i>>8) & 0b11);		// режим записи
		HAL_ETH_SoftSMIWrite(121,cmd);
		cmd = (uint8_t)(i & 0xFF);						//	номер записи
		HAL_ETH_SoftSMIWrite(122,cmd);

	   // настроим статические адреса
		MACrd[0] = (uint8_t)HAL_ETH_SoftSMIRead(123);	//57,56bits
		MACrd[1] = (uint8_t)HAL_ETH_SoftSMIRead(124);	//55-48 bits
		MACrd[2] = (uint8_t)HAL_ETH_SoftSMIRead(125);	//MAC HB
		MACrd[3] = (uint8_t)HAL_ETH_SoftSMIRead(126);	//MAC
		MACrd[4] = (uint8_t)HAL_ETH_SoftSMIRead(127);	//MAC
		MACrd[5] = (uint8_t)HAL_ETH_SoftSMIRead(128);	//MAC
		MACrd[6] = (uint8_t)HAL_ETH_SoftSMIRead(129);	//MAC
		MACrd[7] = (uint8_t)HAL_ETH_SoftSMIRead(130);	//MAC LB
		MACrd[8] = (uint8_t)HAL_ETH_SoftSMIRead(131);	//MAC LB

		if(addr){
			if (MACrd[2] & 0b1<<3){
				sprintf((char *)addr, "<tr><th>0x%.2X-0x%.2X-0x%.2X-0x%.2X-0x%.2X-0x%.2X</th></tr>",MACrd[3],MACrd[4],MACrd[5],MACrd[6],MACrd[7],MACrd[8]);
				addr += strlen((char *)addr );
			}
		}

	    USART_0TRACE("%.4u: ",i);

	    if ((MACrd[3] == 0x02)&&(MACrd[4] == 0x02))printf("\033[1;31m");
	    {

			port = ((MACrd[2]) & 0b111);
			USART_0TRACE("forvarding Port %u, ",port);
		    if (MACrd[2] & 0b1<<3){USART_0TRACE("   Valid, ");}
		    else {USART_0TRACE("notValid, ");}
		    if (MACrd[2] & 0b1<<4){USART_0TRACE("  Override, ");}
		    else {USART_0TRACE("noOverride, ");}

			for(j=3;j<9;j++){
				USART_0TRACE("0x%.2X ",MACrd[j]);
			}
			USART_0TRACE("\r\n");
	    }
	    if ((MACrd[3] == 0x02)&&(MACrd[4] == 0x02))printf("\033[1;m");
	}

	if(addr){
		sprintf((char *)addr,"</table>");	addr += strlen((char *)addr );
	}
return	numb;
}
/*************************************************************************
 * PHY_WriteStaticMACTable добавление в статическую таблицу записи.
 * addr		: номер записи (максимум 8 записей. 0...7)
 * MAC		: MAC адрес записи
 * forvard	: порт в который пропускать адрес
 *
 * 57-54	FID				VLAN ID идентификатор
 * 53		UseFID			использовать FID
 * 52		Override		игнорировать порт (выкл приём и передачу)
 * 51		Valid			достоверность записи. (использовать или нет)
 * 50-48	Forvarding		проброс записи:
 * 			Ports							000 - никуда
 * 											001 - в 1 порт
 * 											010 - в 2 порт
 * 											100 - в 3 порт
 * 											011 - в 1,2 порты
 * 											110 - в 2,3 порты
 * 											101 - в 1,3 порты
 * 											111 - во все порты
 * 47-0		MAC addres		MAC адрес для проброса.
 *
 * предварительно очистить функцией PHY_SetMACFilter
 *************************************************************************/
uint16_t PHY_WriteStaticMACTable(uint16_t	addr, uint8_t * MAC, uint8_t	forvard)
{

    // настроим статические адреса
    HAL_ETH_SoftSMIWrite(124,0);						//57,56bits
    //HAL_ETH_SoftSMIWrite(125,Forvard_to_Port1 | Forvard_to_Port2 | Forvard_to_Port3);	//55-48 bits
    HAL_ETH_SoftSMIWrite(125,Override_ON | Valid_ON | (forvard&0b111));//Valid_ON
    HAL_ETH_SoftSMIWrite(126,MAC[0]);					//MAC HB
    HAL_ETH_SoftSMIWrite(127,MAC[1]);					//MAC
    HAL_ETH_SoftSMIWrite(128,MAC[2]);					//MAC
    HAL_ETH_SoftSMIWrite(129,MAC[3]);					//MAC
    HAL_ETH_SoftSMIWrite(130,MAC[4]);					//MAC
    HAL_ETH_SoftSMIWrite(131,MAC[5]);					//MAC LB

	HAL_ETH_SoftSMIWrite(121,WriteMAC | StaticMAC_Sel | (uint8_t)((addr>>8) & 0b11));
	HAL_ETH_SoftSMIWrite(122,(uint8_t)(addr & 0xFF));

return	0;
}
/*************************************************************************
 *
 *************************************************************************/
uint16_t PHY_ReadDynamicMACTable(uint8_t * addr)
{
	uint8_t		MACrd[9];
	uint16_t	numb = 2000,i,j;
	uint8_t		port;

	if(addr){
		sprintf((char *)addr,"<table border=1 align=center>");
		addr += strlen((char *)addr );
		sprintf((char *)addr,"<tr><th>PHY порт</th><th>MAC адрес</th></tr>");
		addr += strlen((char *)addr );
	}

	for(i=0;i<1024;i++){

		HAL_ETH_SoftSMIWrite(121,ReadMAC | DynamicMAC_Sel | (uint8_t)((i>>8) & 0b11));		// режим записи
		HAL_ETH_SoftSMIWrite(122,(uint8_t)(i & 0xFF));		//	номер записи

	   // настроим статические адреса
		MACrd[0] = (uint8_t)HAL_ETH_SoftSMIRead(123);	//57,56bits
		MACrd[1] = (uint8_t)HAL_ETH_SoftSMIRead(124);	//55-48 bits
		MACrd[2] = (uint8_t)HAL_ETH_SoftSMIRead(125);	//MAC HB
		MACrd[3] = (uint8_t)HAL_ETH_SoftSMIRead(126);	//MAC
		MACrd[4] = (uint8_t)HAL_ETH_SoftSMIRead(127);	//MAC
		MACrd[5] = (uint8_t)HAL_ETH_SoftSMIRead(128);	//MAC
		MACrd[6] = (uint8_t)HAL_ETH_SoftSMIRead(129);	//MAC
		MACrd[7] = (uint8_t)HAL_ETH_SoftSMIRead(130);	//MAC LB
		MACrd[8] = (uint8_t)HAL_ETH_SoftSMIRead(131);	//MAC LB

		port = ((MACrd[2]>>4) & 0b11) + 1;

		if(addr){
			if((MACrd[3] == MAC_ADDR[0]) && (MACrd[4] == MAC_ADDR[1]) && (MACrd[5] == MAC_ADDR[2]) && (MACrd[6] == MAC_ADDR[3])){
				//sprintf((char *)addr, "PHY Порт:%i MAC:0x%.2X-0x%.2X-0x%.2X-0x%.2X-0x%.2X-0x%.2X<br>",port,MACrd[3],MACrd[4],MACrd[5],MACrd[6],MACrd[7],MACrd[8]);
				sprintf((char *)addr, "<tr><th>%i</th><th>0x%.2X-0x%.2X-0x%.2X-0x%.2X-0x%.2X-0x%.2X(%.3D)</th></tr>",port,MACrd[3],MACrd[4],MACrd[5],MACrd[6],MACrd[7],MACrd[8],MACrd[8]);

				addr += strlen((char *)addr );
			}
		}

	    USART_0TRACE("%.4u: ",i);
	    if ((MACrd[3] == MAC_ADDR[0])&&(MACrd[4] == MAC_ADDR[1])){USART_0TRACE("\033[1;31m");}
	    {
	    	if (MACrd[0] & MAC_Empty){	USART_0TRACE("Пустой, ");}
	    	  	else{USART_0TRACE("      , ")}
	    	numb = (uint16_t)(MACrd[0]&0b11)<<8 | (uint16_t)MACrd[1];
	    	USART_0TRACE("%.4u, ",numb);
	    	USART_0TRACE("FID %.2u, ",MACrd[2]&0b1111);

			USART_0TRACE("Port %u, ",port);

			for(j=3;j<9;j++){
				USART_0TRACE("0x%.2X ",MACrd[j]);
			}
			USART_0TRACE("\r\n");
	    }
	    if ((MACrd[3] == 0x02)&&(MACrd[4] == 0x02)){USART_0TRACE("\033[1;m");}

	    if (i>=numb) break;
	}

	if(addr){
		sprintf((char *)addr,"</table>");	addr += strlen((char *)addr );
	}
return	numb;
}
/*************************************************************************
 * Упрвление передачей для кождого порта
 *************************************************************************/
int 		PHY_Port1TxOff(uint16_t param){
//	HAL_ETH_WritePHYRegister(&heth, PHY_BCR, PHY_AN_ENABLE | PHY_DISABLE_TRANSMIT,0);
    HAL_ETH_SoftSMIWrite(18,TransmitDISABLE | param);	// откл обучения из 1-го порта
	return 0;
}
int 		PHY_Port1TxOn(uint16_t param){
//	HAL_ETH_WritePHYRegister(&heth, PHY_BCR, PHY_AN_ENABLE | PHY_ENABLE_TRANSMIT,0);
    HAL_ETH_SoftSMIWrite(18,TransmitENABLE | param);	// откл обучения из 1-го порта
	return 0;
}
int 		PHY_Port2TxOff(uint16_t param){
//	HAL_ETH_WritePHYRegister(&heth, PHY_BCR, PHY_AN_ENABLE | PHY_DISABLE_TRANSMIT,1);
	HAL_ETH_SoftSMIWrite(34,TransmitDISABLE | param);	// откл обучения из 2-го порта	T:R:L
	return 0;
}
int 		PHY_Port2TxOn(uint16_t param){
//	HAL_ETH_WritePHYRegister(&heth, PHY_BCR, PHY_AN_ENABLE | PHY_ENABLE_TRANSMIT,1);
	HAL_ETH_SoftSMIWrite(34,TransmitENABLE | param);	// откл обучения из 2-го порта	T:R:L
	return 0;
}

/*************************************************************************
*  PHY_SetPortsHSRMode
*
*   HSR работает аналогично PRP но без изоляции портов. KSZ8863 разрывает кольцо для своих пакетов из 3-го порта автоматически.
*   отправка делается аналогично PRP. Обучение свича нужно отключить, чтобы не отбрасывал чужие пакеты  с одинаковыми MAC
*   пришедшие на оба порта
*	1. Отключаем обучение свича с портов 1,2.				Reg 18 bit0 = 1, Reg 34 bit0 = 1.
*	2. все неизвесные нам пакеты прокидываем в 1,2 порт.	Reg 14 bit2..0 = 011, Reg 14 bit7 = 1
*	3. при передаче пакетов отключаем ненужный нам порт.	Reg 18 bit2 = 0, Reg 34 bit2 = 0. или MIIM Reg 1 bit1 = 1,Reg 2 bit1 = 1
*
*	p.s. нужно предусмотреть защиту от broadcast storm, при отключении ненужного нам порта отключится и передача в него, возможна потеря пакетов.
*
 *************************************************************************/
int 		PHY_SetPortsHSRMode(char*	MAC){

    HAL_ETH_SoftSMIWrite(18,TransmitENABLE | ReseiveENABLE | LearningDISABLE);//LearningENABLE
    HAL_ETH_SoftSMIWrite(34,TransmitENABLE | ReseiveENABLE | LearningDISABLE);//LearningENABLE
    HAL_ETH_SoftSMIWrite(14,UnknownPacketEnable | DriveStrength16mA | UnknownPacketPort_1 | UnknownPacketPort_2 | UnknownPacketPort_3);			// проброс неизвестных пакетов  | UnknownPacketPort_1 | UnknownPacketPort_2 | UnknownPacketPort_3

    // эти MAC адреса не будут ретранслироваться свичем. Считает их локальными
    // 142 - 147 MACA1
    HAL_ETH_SoftSMIWrite(142,MAC[5]);
    HAL_ETH_SoftSMIWrite(143,MAC[4]);
    HAL_ETH_SoftSMIWrite(144,MAC[3]);
    HAL_ETH_SoftSMIWrite(145,MAC[2]);
    HAL_ETH_SoftSMIWrite(146,MAC[1]);
    HAL_ETH_SoftSMIWrite(147,MAC[0]);

	HAL_ETH_SoftSMIWrite(21,SelfAddressFilteringEnableMACA1);		// включения MAC фильтра на порт 1
	HAL_ETH_SoftSMIWrite(37,SelfAddressFilteringEnableMACA1);		// включения MAC фильтра на порт 2

	HAL_ETH_SoftSMIWrite(2,DynamicMAC_flush);

	USART_TRACE_BLUE("HSRMode:%.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n",MAC[0], MAC[1], MAC[2], MAC[3],MAC[4],MAC[5]);	// временно чтобы отличались устройства

	return 0;
}
/*************************************************************************
*  PHY_SetPortsPRPMode
 *************************************************************************/
int 		PHY_SetPortsPRPMode(void){
// изоляция портов для PRP работает. Передача ведётся в оба порта, для выбора направления, нужно отключать не нужный порт.

	// -------------------------------------------------------------------
	// режим без связи между port1 и port2. весь трафик идёт в port3.
	// передача только от port3 в те порты, которые TransmitENABLE

		HAL_ETH_SoftSMIWrite(49,1<<7 | 0b111);		// снифер порт
		HAL_ETH_SoftSMIWrite(17,1<<6 | 0b111);		// слушаем порт
		HAL_ETH_SoftSMIWrite(33,1<<6 | 0b111);		// слушаем порт

		HAL_ETH_SoftSMIWrite(18,TransmitENABLE | ReseiveDISABLE | LearningENABLE);
		HAL_ETH_SoftSMIWrite(34,TransmitENABLE | ReseiveDISABLE | LearningENABLE);
		HAL_ETH_SoftSMIWrite(14,UnknownPacketEnable | DriveStrength16mA | UnknownPacketPort_1 | UnknownPacketPort_2 | UnknownPacketPort_3);			// проброс неизвестных пакетов  | UnknownPacketPort_1 | UnknownPacketPort_2 | UnknownPacketPort_3
	// -------------------------------------------------------------------
}
/*************************************************************************
*  PHY_SetPortsNormalMode
*  обычный режим работы свича.
*  todo: если выключить Learning возможно получится резервирование в обычном режиме.
*  Свич будет пропускать через себя все пакеты без MAC маршрутов.
 *************************************************************************/
int 		PHY_SetPortsNormalMode(void){

	HAL_ETH_SoftSMIWrite(49,0b111);
	HAL_ETH_SoftSMIWrite(17,0b111);
	HAL_ETH_SoftSMIWrite(33,0b111);

	HAL_ETH_SoftSMIWrite(14, DriveStrength16mA | UnknownPacketPort_1 | UnknownPacketPort_2 | UnknownPacketPort_3);
	HAL_ETH_SoftSMIWrite(18,TransmitENABLE | ReseiveENABLE | LearningENABLE);//LearningENABLE
	HAL_ETH_SoftSMIWrite(34,TransmitENABLE | ReseiveENABLE | LearningENABLE);//LearningENABLE

	HAL_ETH_SoftSMIWrite(21,0);
	HAL_ETH_SoftSMIWrite(37,0);

	USART_TRACE("PHY_SetPortsNormalMode\n");

    return	0;
}
/*************************************************************************
 * PHY_SetPortsMode
 *************************************************************************/
int 		PHY_SetPortsMode(void){
	SetRedundansyMode(RedMode);
}
/*************************************************************************
 * PHY_SetPortsStaticMAC
 * port1,port2 - MAC адреса
 *************************************************************************/
int PHY_SetPortsStaticMAC(char*	port1, char*	port2)
{

    return	-1;
}
/*************************************************************************
 * PHY_DebugOutMode
 *************************************************************************/
void PHY_DebugOutMode(void){
uint16_t tmp;

	USART_TRACE_BLUE("KSZ8873 config ------------\n");
	tmp = HAL_ETH_SoftSMIRead(0x00);
	USART_TRACE_BLUE("Chip ID0: 0x%.2X\n",tmp);
	tmp = HAL_ETH_SoftSMIRead(0x01);
	USART_TRACE_BLUE("Chip ID1: 0x%.2X\n",tmp);
	tmp = HAL_ETH_SoftSMIRead(0x04);
	USART_TRACE_BLUE("Global Control 2: 0x%.2X\n",tmp);
	tmp = HAL_ETH_SoftSMIRead(0x06);
	USART_TRACE_BLUE("Global Control 4(Port3): 0x%.2X\n",tmp);
	tmp = HAL_ETH_SoftSMIRead(0x07);
	USART_TRACE_BLUE("Broadcast Storm Protection Rate: 0x%.2X\n",tmp);
	tmp = HAL_ETH_SoftSMIRead(0x1C);
	USART_TRACE_BLUE("Port 1 Control 12: 0x%.2X\n",tmp);
	tmp = HAL_ETH_SoftSMIRead(0x2C);
	USART_TRACE_BLUE("Port 2 Control 12: 0x%.2X\n",tmp);
	tmp = HAL_ETH_SoftSMIRead(0x1F);
	USART_TRACE_BLUE("Port 1 Status 1: 0x%.2X\n",tmp);
	tmp = HAL_ETH_SoftSMIRead(0x2F);
	USART_TRACE_BLUE("Port 2 Status 1: 0x%.2X\n",tmp);
	tmp = HAL_ETH_SoftSMIRead(0x3F);
	USART_TRACE_BLUE("Port 3 Status 1: 0x%.2X\n",tmp);
	USART_TRACE_BLUE("---------------------------\n");

}
/*************************************************************************
 * PHY_SetMACFilter
 * 8 мак адресов всего, по адресу 122 указать номер записи.
 * 124-131 - сама запись полезных 57 бит. 131 младшие биты.
 *
 * 57-54	FID				VLAN ID идентификатор
 * 53		UseFID			использовать FID
 * 52		Override		игнорировать порт (выкл приём и передачу)
 * 51		Valid			достоверность записи. (использовать или нет)
 * 50-48	Forvarding		проброс записи:
 * 			Ports							000 - никуда
 * 											001 - в 1 порт
 * 											010 - в 2 порт
 * 											100 - в 3 порт
 * 											011 - в 1,2 порты
 * 											110 - в 2,3 порты
 * 											101 - в 1,3 порты
 * 											111 - во все порты
 * 47-0		MAC addres		MAC адрес для проброса.
 *
 * 1. отключаем обучения из x-го порта.							18reg
 * 2. чистим таблицу DynamicMAC_flush							 2reg
 * 3. отключаем проброс неизвестных MAC в интересующий порт.  	14reg
 * 4. после этого MAC адрес из статической таблицы будет направлен
 *     в соответствии с указаным в записи маршрутом. и если там указан
 *     порт с фильтром то он будет проброшен туда. Иначе будет полная
 *     изуляция порта.
 *
 *     PHYReg14 можно заменить на HAL_ETH_SoftSMIRead(14); читать из чипа.
 *************************************************************************/
int PHY_SetMACFilter(PHY_PortNumber	port, uint8_t	mode)
{
	static uint8_t	PHYReg14=0b11000111;
	uint8_t		reg,regLearn,regPort;

	if (port > PHY_Port3) return -1;

	PHYReg14 = HAL_ETH_SoftSMIRead(14);

	switch(port){
	case	PHY_Port1:	regLearn = 18;	regPort = UnknownPacketPort_1;	break;
	case	PHY_Port2:	regLearn = 32;	regPort = UnknownPacketPort_2;	break;
	case	PHY_Port3:	regLearn = 50;	regPort = UnknownPacketPort_3;	break;
	}

    if (mode) {
	    HAL_ETH_SoftSMIWrite(regLearn,TransmitENABLE | ReseiveENABLE | LearningDISABLE);
	    HAL_ETH_SoftSMIWrite(2,DynamicMAC_flush);
    	reg = PHYReg14 & ~regPort;
    }
    else {
	    HAL_ETH_SoftSMIWrite(regLearn,TransmitENABLE | ReseiveENABLE | LearningENABLE);
    	reg = PHYReg14 | regPort;
    }

    HAL_ETH_SoftSMIWrite(14,reg);											// все порты проброс в остальные порты.
    PHYReg14 = reg;
    //USART_TRACE("PHY_Port%u filter:0x%.2x\n",port+1,reg);
  return 0;
}
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

    PA0-WKUP------> ETH_CRS					// этот оторвали, перестала читаться модель.
    PA1     ------> ETH_RX_CLK
    PA2     ------> ETH_MDIO
    PA3     ------> ETH_COL					// на нём ничего нет, можно не использовать
    PA7     ------> ETH_RX_DV				PU

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

    GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_11;				// GPIO_NOPULL
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP ;
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

//    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 6, 0);
//    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

    /* Peripheral interrupt init*/
    HAL_NVIC_SetPriority(ETH_IRQn, 6, 0);		//12 -  18.12.2017
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
    osSemaphoreRelease(s_xSemaphore);
}
/*******************************************************************************
* @brief  HAL_GPIO_EXTI_Callback
*******************************************************************************/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == GPIO_PIN_11)
  {
	osSemaphoreRelease(Netif_LinkSemaphore);
  }
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
 //if ((RM_HSR_V0 == get_redundancyMode())||(RM_HSR_V1 == get_redundancyMode()))
 if(get_HardwareCRCMode() == HardwareCRC)
 {
	 heth.Init.ChecksumMode = ETH_CHECKSUM_BY_HARDWARE;
 }else{
	 heth.Init.ChecksumMode = ETH_CHECKSUM_BY_SOFTWARE;
 }
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
  HAL_ETH_DMATxDescListInit(&heth, DMATxDscrTab, &Tx_Buff[0][0], ETH_TXBUFNB);			//
     
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

// запускаем таск который будет принимать данные через семафор из прерывания ETH_MAC
  osThreadDef(EthInt, ethernetif_input, osPriorityRealtime, 0, INTERFACE_THREAD_STACK_SIZE);
  osThreadCreate (osThread(EthInt), netif);
 
  /* Enable Interrupt */
//   __HAL_ETH_DMA_ENABLE_IT((&heth),ETH_DMA_IT_T);			// прерывание по окончанию передачи в ETH
//   __HAL_ETH_DMATXDESC_ENABLE_IT(&heth);

  /* Enable MAC and DMA transmission and reception */
  HAL_ETH_Start(&heth);
  
#endif /* LWIP_ARP || LWIP_ETHERNET */
}

/**
  * @brief This function should do the actual transmission of the packet. The packet is
  * contained in the pbuf that is passed to the function. This pbuf
  * might be chained.
  *
  * Эта функция должна выполнять фактическую передачу пакета. Пакет содержится в pbuf, который передается функции.
  *
  * netif - структура сетевого интерфейса.
  *
  * @param netif the lwip network interface structure for this ethernetif
  * @param p the MAC packet to send (e.g. IP packet including MAC addresses and type)
  * @return ERR_OK if the packet could be sent an err_t value if the packet couldn't be sent
  *
  * @note Returning ERR_MEM here if a DMA queue of your MAC is full can lead to
  *       strange results. You might consider waiting for space in the DMA queue
  *       to become available since the stack doesn't retry to send a packet
  *       dropped because of memory failure (except for the TCP timers).
  *
  *
  * HSR/PRP - можно попробовать в этом месте добавить, но размер сообщения придётся пересчитывать.
  * 		проще на стадии свертывания стека. Но это будет для каждого типа протокола отдельно.
  *
  */
#if !defined (HSR_Debug_Mode) && !defined (PRP_Debug_Mode)
static err_t low_level_output(struct netif *netif, struct pbuf *p)
{
  err_t errval;
  struct pbuf *q;	// временный указатель на буфер
  uint8_t *buffer = (uint8_t *)(heth.TxDesc->Buffer1Addr);		// берём буфер текущего свободного дескриптора
  __IO ETH_DMADescTypeDef *DmaTxDesc;
  uint32_t framelength = 0;
  uint32_t bufferoffset = 0;
  uint32_t byteslefttocopy = 0;
  uint32_t payloadoffset = 0;

//  addprpTag(p);
  uint16_t totalSize = p->tot_len;

  DmaTxDesc = heth.TxDesc;						// текущий дескриптор
  bufferoffset = 0;

  // copy frame from pbufs to driver buffers
  for(q = p; q != NULL; q = q->next)
  {
    // Is this buffer available? If not, goto error
	// доступен этот буфер? нет, то выходим с ошибкой
    if((DmaTxDesc->Status & ETH_DMATXDESC_OWN) != (uint32_t)RESET)
    {
      errval = ERR_USE;
      goto error;
    }

    // Get bytes in current lwIP buffer
    // размер текущего буфера lwIP
    byteslefttocopy = q->len;
/*
#if ETHARP_SUPPORT_HSR
    if ((RM_HSR_V0 == get_redundancyMode())||(RM_HSR_V1 == get_redundancyMode())){
    	if (totalSize<66) byteslefttocopy = 66;
    }
#endif
*/
    payloadoffset = 0;

    // Check if the length of data to copy is bigger than Tx buffer size
    // превышает ли длина данных, размер буфера Tx. Пока превышает перекладываем частями в нужное количество буферов дескрипторов
    while( (byteslefttocopy + bufferoffset) > ETH_TX_BUF_SIZE )
    {
      // Copy data to Tx buffer
      // копируем данные в Tx буфер
      memcpy( (uint8_t*)((uint8_t*)buffer + bufferoffset), (uint8_t*)((uint8_t*)q->payload + payloadoffset), (ETH_TX_BUF_SIZE - bufferoffset) );

      // Point to next descriptor
      // укажем на следующиий дескриптор
      DmaTxDesc = (ETH_DMADescTypeDef *)(DmaTxDesc->Buffer2NextDescAddr);

      // Check if the buffer is available
      // доступен этот буфер? нет, то выходим с ошибкой
      if((DmaTxDesc->Status & ETH_DMATXDESC_OWN) != (uint32_t)RESET)
      {
        errval = ERR_USE;
        goto error;
      }

      buffer = (uint8_t *)(DmaTxDesc->Buffer1Addr);

      byteslefttocopy = byteslefttocopy - (ETH_TX_BUF_SIZE - bufferoffset);			// размер оставшихся данных
      payloadoffset = payloadoffset + (ETH_TX_BUF_SIZE - bufferoffset);				// адрес след. куска в pbuf
      framelength = framelength + (ETH_TX_BUF_SIZE - bufferoffset);					// общий размер фрейма в отпр. буфере (ETH)
      bufferoffset = 0;																// размер после последнего куска (ненужный хвост).
    }

    // Copy the remaining bytes
    // Скопируйте оставшиеся байты
    memcpy( (uint8_t*)((uint8_t*)buffer + bufferoffset), (uint8_t*)((uint8_t*)q->payload + payloadoffset), byteslefttocopy );
    bufferoffset = bufferoffset + byteslefttocopy;
    framelength = framelength + byteslefttocopy;
  }

#if ETHARP_SUPPORT_PRP
  	if (RM_PRP_V1 == get_redundancyMode()){

  		struct eth_prp_hdr  prphdr;
  		uint16_t 			length;

  		length = totalSize - SIZEOF_ETH_HDR;
#if ETHARP_SUPPORT_VLAN
  		if (Vlan_ON == get_VlanMode()){
  			length -= SIZEOF_VLAN_HDR;
  		}
#endif

  	    PrpSetTpid(PP_HTONS(ETHTYPE_PRP));
  	    length += SIZEOF_PRP_HDR;
  		PrpSetLSDUsize(length);
  		PrpSetLanA();
  		GetPrpTagPostInc(&prphdr);

  	    memcpy( (uint8_t*)((uint8_t*)buffer + bufferoffset), (uint8_t*)&prphdr, SIZEOF_PRP_HDR );
  	    bufferoffset = bufferoffset + SIZEOF_PRP_HDR;
  	    framelength = framelength + SIZEOF_PRP_HDR;
  	}
#endif

#if ETHARP_SUPPORT_HSR
    if ((RM_HSR_V0 == get_redundancyMode())||(RM_HSR_V1 == get_redundancyMode())){
    	if (framelength<66) framelength = 66;
    }
#endif

#if ETHARP_SUPPORT_PRP
    if (RM_PRP_V1 == get_redundancyMode()){
   if (framelength<66) {
	   framelength = 66;
   }
    }
#endif

  // Prepare transmit descriptors to give to DMA
  if (HAL_ETH_TransmitFrame(&heth, framelength) != HAL_OK){
	  USART_TRACE_RED("HAL_ETH_TransmitFrame error\n");
  }

  errval = ERR_OK;

error:

  // When Transmit Underflow flag is set, clear it and issue a Transmit Poll Demand to resume transmission
  if ((heth.Instance->DMASR & ETH_DMASR_TUS) != (uint32_t)RESET)
  {
    // Clear TUS ETHERNET DMA flag
    heth.Instance->DMASR = ETH_DMASR_TUS;

    // Resume DMA transmission
    heth.Instance->DMATPDR = 0;
  }
  return errval;
}
#endif

#if defined (HSR_Debug_Mode) || defined (PRP_Debug_Mode)
/*****************************************************************
 * low_level_output в зависимости от режима HSR/PRP будем подставлять нужные данные.
 * Пересоберём пакет в зависимости от режима резервирования. Если это PRP то просто добавим в конец трейлер PRP
 *
 *****************************************************************/
static err_t low_level_output(struct netif *netif, struct pbuf *p)
{
  err_t errval;
  struct pbuf *q;												// временный указатель на буфер
  uint8_t *buffer = (uint8_t *)(heth.TxDesc->Buffer1Addr);		// берём буфер текущего свободного дескриптора
  __IO ETH_DMADescTypeDef *DmaTxDesc;
  uint32_t framelength = 0;
  uint32_t bufferoffset = 0;
  uint32_t byteslefttocopy = 0;
  uint32_t payloadoffset = 0;
  uint16_t AddSize = 0;					// размер для увеличения буфера на HSR/PRP трейлеры
  uint8_t *my_p = NULL;
//-----------------------------------------------------
// перепакуем буфер в 2 разных с разными данными для отправки
// 1. выделим память под буфер.
// 2. перепишем данные со вставкой нужных данных HSR/PRP
// 3. отправим в буфер интерфейса

//-----------------------------------------------------

  DmaTxDesc = heth.TxDesc;										// текущий дескриптор
  bufferoffset = 0;
  
  // copy frame from pbufs to driver buffers
  for(q = p; q != NULL; q = q->next)
  {
// -----------
// поменяем указатель на наш буфер.
// q = my_p;
// в буфере my_p заменим размеры данных и перепакуем ->payload
#if defined (PRP_Debug_Mode)
	AddSize = sizeof(struct prp_rct);
#endif
#if defined (HSR_Debug_Mode)
	AddSize = sizeof(struct hsr_tag);
#endif

	if(my_p != NULL) GLOBAL_FREEMEM(my_p);

	my_p = GLOBAL_MALLOC((q->len) + AddSize);
	if(my_p != NULL) {

// в режиме PRP нужен хвост
#if defined (PRP_Debug_Mode)
		memcpy(my_p,q->payload,q->len);

		{
			uint16_t  sz = q->len - 14 + AddSize;
			uint16_t typeP = (uint16_t)my_p[12]<<8 | (uint16_t)my_p[13];
			if (ETHTYPE_VLAN == typeP) sz -= 4;

			PRP_Traler.lan_id_and_LSDU_size = htons((uint16_t)LAN_Addr_0 << 8 | (sz & 0xfff));//(q->len - 0*12)
		}

		// теперь нужно добавить трейлет PRP
		PRP_Traler.sequence_nr = htons(htons(PRP_Traler.sequence_nr)+1);
		PRP_Traler.PRP_suffix = htons(PRPsuffix);

		memcpy(my_p+(q->len),&PRP_Traler,AddSize);

#endif
	}//!if(q != NULL) {
	// переписали повально всё. Но нам нужны заголовки
// -----------

    // Is this buffer available? If not, goto error
	// доступен этот буфер? нет, то выходим с ошибкой
    if((DmaTxDesc->Status & ETH_DMATXDESC_OWN) != (uint32_t)RESET)
    {
      errval = ERR_USE;
      goto error;
    }

    // Get bytes in current lwIP buffer
    // размер текущего буфера lwIP
    byteslefttocopy = q->len + AddSize;
    payloadoffset = 0;

    // Check if the length of data to copy is bigger than Tx buffer size
    // превышает ли длина данных, размер буфера Tx. Пока превышает перекладываем частями в нужное количество буферов дескрипторов
    while( (byteslefttocopy + bufferoffset) > ETH_TX_BUF_SIZE )
    {
      // Copy data to Tx buffer
      // копируем данные в Tx буфер
      memcpy( (uint8_t*)((uint8_t*)buffer + bufferoffset), (uint8_t*)((uint8_t*)my_p + payloadoffset), (ETH_TX_BUF_SIZE - bufferoffset) );

      // Point to next descriptor
      // укажем на следующиий дескриптор
      DmaTxDesc = (ETH_DMADescTypeDef *)(DmaTxDesc->Buffer2NextDescAddr);

      // Check if the buffer is available
      // доступен этот буфер? нет, то выходим с ошибкой
      if((DmaTxDesc->Status & ETH_DMATXDESC_OWN) != (uint32_t)RESET)
      {
        errval = ERR_USE;
        goto error;
      }
      
      buffer = (uint8_t *)(DmaTxDesc->Buffer1Addr);									// берём указатель на буфер
      
      byteslefttocopy = byteslefttocopy - (ETH_TX_BUF_SIZE - bufferoffset);			// размер оставшихся данных
      payloadoffset = payloadoffset + (ETH_TX_BUF_SIZE - bufferoffset);				// адрес след. куска в pbuf
      framelength = framelength + (ETH_TX_BUF_SIZE - bufferoffset);					// общий размер фрейма в отпр. буфере (ETH)
      bufferoffset = 0;																// размер после последнего куска (ненужный хвост).
    }
    
    // Copy the remaining bytes
    // Скопируйте оставшиеся байты
    memcpy( (uint8_t*)((uint8_t*)buffer + bufferoffset), (uint8_t*)((uint8_t*)my_p + payloadoffset), byteslefttocopy );
    bufferoffset = bufferoffset + byteslefttocopy;
    framelength = framelength + byteslefttocopy;
  }
  
  // Prepare transmit descriptors to give to DMA
  HAL_ETH_TransmitFrame(&heth, framelength);
  
  errval = ERR_OK;
  
error:
  
  // When Transmit Underflow flag is set, clear it and issue a Transmit Poll Demand to resume transmission
  if ((heth.Instance->DMASR & ETH_DMASR_TUS) != (uint32_t)RESET)
  {
    // Clear TUS ETHERNET DMA flag
    heth.Instance->DMASR = ETH_DMASR_TUS;

    // Resume DMA transmission
    heth.Instance->DMATPDR = 0;
  }

  if(my_p != NULL) GLOBAL_FREEMEM(my_p);

  return errval;
}
#endif
/**
  * Должен выделить pbuf и передать байты входящего пакета из интерфейса в pbuf.
  *
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
  }else{
	  // не выделил память
	  USART_TRACE_RED("low_level_input ERROR\n");

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
        	ret_error = netif->input( p, netif);			// вызываем функцию приема данных она же: (err_t)tcpip_input(struct pbuf *p, struct netif *inp)
          if (ret_error != ERR_OK )
          {
        	  // из-за нехватки памяти попадает сюда и циклиться. нужно както это решить
        	  USART_TRACE_RED("ethernetif_input ERROR: %s\n",lwip_strerr(ret_error));
        	  Port_On(LED1);
        	  Port_On(LED_out_RED);
              pbuf_free(p);
//              vTaskDelay(100);
              // перезапустимся временно, пока не знаю как решить эту беду. Нужно FTP переносить переменные во внешнюю память
              NVIC_SystemReset();
          }else{
        	  Port_Off(LED1);
        	  Port_Off(LED_out_RED);
//  			Port_On(LED1);
//             printf("tcpip_input no error. pbuf: 0x%x\n",(unsigned int)p);
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

/***************************************************************
 * ethernetif_set_link
 * проверяем линк статус интерфейса и вызываем от состояния:
 * netif_set_link_up  	подымаем
 * netif_set_link_down 	или сбрасываем
 **************************************************************/
void ethernetif_set_link(void const *argument)
{
  uint32_t regvalue = 0, regvalue1 = 0;
  struct link_str *link_arg = (struct link_str *)argument;

  for(;;)
   {
	  /*
			void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
			{
			  if (GPIO_Pin == GPIO_PIN_12)
			  {
				osSemaphoreRelease(Netif_LinkSemaphore);
			  }
			}
	   */
	 // семафор управляется по прерыванию от лапки. нужно сконфигурить эу лапку правильно PA12 вход прерывания
     if (osSemaphoreWait( link_arg->semaphore, 100)== osOK)
     {
       /* Read MII Basic Status регистр*/
       HAL_ETH_ReadPHYRegister(&heth, PHY_BSR, &regvalue, 0);
       HAL_ETH_ReadPHYRegister(&heth, PHY_BSR, &regvalue1,1);

       /* Check whether the link interrupt has occurred or not */
       // проверяем произошло ли прерывание LINK
//       if((regvalue & PHY_LINK_INTERRUPT) != (uint16_t)RESET)
       {
         /* Read PHY_SR читаем PHY статус регистр */
//         HAL_ETH_ReadPHYRegister(&heth, PHY_BSR, &regvalue, 0);
//         HAL_ETH_ReadPHYRegister(&heth, PHY_BSR, &regvalue1, 0);

         // проверяем LINK статус.
         if(
        	((regvalue & PHY_LINKED_STATUS) == (uint16_t)RESET) ||
        	((regvalue1 & PHY_LINKED_STATUS) == (uint16_t)RESET)
         )
         {
		 if (link_arg->netif->flags & NETIF_FLAG_LINK_UP) {
			 printf("PHY STATUS 0: %u PHY STATUS 1: %u\n",(unsigned int)regvalue,(unsigned int)regvalue1);
		 	 }
           netif_set_link_down(link_arg->netif);
         }
         else
         {
           netif_set_link_up(link_arg->netif);
         }

       }//!if((regvalue
     }
   }

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
  
  printf("ethernetif_update_config.\n");

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

