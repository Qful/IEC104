/**
  ******************************************************************************
  * @file    stm324xg_eval.h
  * @author  MCD Application Team
  * @version V2.0.5
  * @date    02-March-2015
  * @brief   This file contains definitions for STM324xG_EVAL's LEDs, 
  *          push-buttons and COM ports hardware resources.
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
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CONFBOARD_H
#define __CONFBOARD_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

 typedef enum
 {
   LED1 = 0,
   LED2 = 1,
   LED3 = 2,
   LED4 = 3,
   LEDtst0 = 4,
   LEDtst1 = 5,
   LEDtst2 = 6,
   RS485_1_DEn = 7,
   RS485_2_DEn = 8,
   MODBUS_DEn = 9,
   LED_out_RED = 10,
   LED_out_GREEN = 11,
 }Port_TypeDef;


// ----------------------------------------------------------------------------------------------------
//#define 	KSZ8873
// ----------------------------------------------------------------------------------------------------
#define PORTn                             12

#ifdef STM32F407xx

#define LED1_PIN                         GPIO_PIN_12
#define LED1_GPIO_PORT                   GPIOD
#define LED1_GPIO_CLK_ENABLE()           __GPIOD_CLK_ENABLE()
#define LED1_GPIO_CLK_DISABLE()          __GPIOD_CLK_DISABLE()

#define LED2_PIN                         GPIO_PIN_13
#define LED2_GPIO_PORT                   GPIOD
#define LED2_GPIO_CLK_ENABLE()           __GPIOD_CLK_ENABLE()
#define LED2_GPIO_CLK_DISABLE()          __GPIOD_CLK_DISABLE()
  
#define LED3_PIN                         GPIO_PIN_14
#define LED3_GPIO_PORT                   GPIOD
#define LED3_GPIO_CLK_ENABLE()           __GPIOD_CLK_ENABLE()
#define LED3_GPIO_CLK_DISABLE()          __GPIOD_CLK_DISABLE()
  
#define LED4_PIN                         GPIO_PIN_15
#define LED4_GPIO_PORT                   GPIOD
#define LED4_GPIO_CLK_ENABLE()           __GPIOD_CLK_ENABLE()
#define LED4_GPIO_CLK_DISABLE()          __GPIOD_CLK_DISABLE()

#else

#define LED1_PIN                         GPIO_PIN_11					//GPIO_PIN_12		//GPIO_PIN_6 - для боевого борда
#define LED1_GPIO_PORT                   GPIOA						//GPIOD			//GPIOC
#define LED1_GPIO_CLK_ENABLE()           __GPIOA_CLK_ENABLE()		//__GPIOD_CLK_ENABLE()
#define LED1_GPIO_CLK_DISABLE()          __GPIOA_CLK_DISABLE()

#define LED2_PIN                         GPIO_PIN_11
#define LED2_GPIO_PORT                   GPIOA
#define LED2_GPIO_CLK_ENABLE()           __GPIOA_CLK_ENABLE()
#define LED2_GPIO_CLK_DISABLE()          __GPIOA_CLK_DISABLE()

#define LED3_PIN                         GPIO_PIN_11
#define LED3_GPIO_PORT                   GPIOA
#define LED3_GPIO_CLK_ENABLE()           __GPIOA_CLK_ENABLE()
#define LED3_GPIO_CLK_DISABLE()          __GPIOA_CLK_DISABLE()

#define LED4_PIN                         GPIO_PIN_2
#define LED4_GPIO_PORT                   GPIOE
#define LED4_GPIO_CLK_ENABLE()           __GPIOE_CLK_ENABLE()
#define LED4_GPIO_CLK_DISABLE()          __GPIOE_CLK_DISABLE()

#define LEDtst0_PIN                      GPIO_PIN_10
#define LEDtst0_GPIO_PORT                GPIOG
#define LEDtst0_GPIO_CLK_ENABLE()        __GPIOG_CLK_ENABLE()
#define LEDtst0_GPIO_CLK_DISABLE()       __GPIOG_CLK_DISABLE()

#define LEDtst1_PIN                      GPIO_PIN_11
#define LEDtst1_GPIO_PORT                GPIOG
#define LEDtst1_GPIO_CLK_ENABLE()        __GPIOG_CLK_ENABLE()
#define LEDtst1_GPIO_CLK_DISABLE()       __GPIOG_CLK_DISABLE()

#define LEDtst2_PIN                      GPIO_PIN_12
#define LEDtst2_GPIO_PORT                GPIOG
#define LEDtst2_GPIO_CLK_ENABLE()        __GPIOG_CLK_ENABLE()
#define LEDtst2_GPIO_CLK_DISABLE()       __GPIOG_CLK_DISABLE()


#endif

#define LED_OUT_RED_PIN                 GPIO_PIN_14					// RED
#define LED_OUT_RED_PORT                GPIOE						//
#define LED_OUT_RED_CLK_ENABLE()        __GPIOE_CLK_ENABLE()		//
#define LED_OUT_RED_CLK_DISABLE()       __GPIOE_CLK_DISABLE()

#define LED_OUT_GREEN_PIN               GPIO_PIN_15					// GREEN
#define LED_OUT_GREEN_PORT              GPIOE
#define LED_OUT_GREEN_CLK_ENABLE()      __GPIOE_CLK_ENABLE()
#define LED_OUT_GREEN_CLK_DISABLE()     __GPIOE_CLK_DISABLE()

#define PHY_PWRDN                        GPIO_PIN_8
#define PHY_PWRDN_GPIO_PORT              GPIOA
#define PHY_PWRDN_GPIO_CLK_ENABLE()      __GPIOA_CLK_ENABLE()
#define PHY_PWRDN_GPIO_CLK_DISABLE()     __GPIOA_CLK_DISABLE()

#define RS485_1_DE                       GPIO_PIN_4
#define RS485_1_DE_GPIO_PORT             GPIOD
#define RS485_1_DE_GPIO_CLK_ENABLE()     __GPIOD_CLK_ENABLE()
#define RS485_1_DE_GPIO_CLK_DISABLE()    __GPIOD_CLK_DISABLE()

#define RS485_2_DE                       GPIO_PIN_12
#define RS485_2_DE_GPIO_PORT             GPIOD
#define RS485_2_DE_GPIO_CLK_ENABLE()     __GPIOD_CLK_ENABLE()
#define RS485_2_DE_GPIO_CLK_DISABLE()    __GPIOD_CLK_DISABLE()

#define MODBUS_DE                        GPIO_PIN_0					// не использовать
#define MODBUS_DE_GPIO_PORT              GPIOC
#define MODBUS_DE_GPIO_CLK_ENABLE()      __GPIOC_CLK_ENABLE()
#define MODBUS_DE_GPIO_CLK_DISABLE()     __GPIOC_CLK_DISABLE()

#define db161d_CS_PIN                    GPIO_PIN_4
#define db161d_CS_GPIO_PORT              GPIOA
#define db161d_CS_GPIO_CLK_ENABLE()      __GPIOA_CLK_ENABLE()
#define db161d_CS_GPIO_CLK_DISABLE()     __GPIOA_CLK_DISABLE()

#define PORTx_GPIO_CLK_ENABLE(__INDEX__)  do{if((__INDEX__) == 0) LED1_GPIO_CLK_ENABLE(); else \
                                            if((__INDEX__) == 1) LED2_GPIO_CLK_ENABLE(); else \
                                            if((__INDEX__) == 2) LED3_GPIO_CLK_ENABLE(); else \
                                            if((__INDEX__) == 3) LED4_GPIO_CLK_ENABLE(); else \
                                            if((__INDEX__) == 4) LEDtst0_GPIO_CLK_ENABLE(); else \
                                            if((__INDEX__) == 5) LEDtst1_GPIO_CLK_ENABLE(); else \
                                            if((__INDEX__) == 6) LEDtst2_GPIO_CLK_ENABLE(); else \
                                            if((__INDEX__) == 7) RS485_1_DE_GPIO_CLK_ENABLE(); else \
											if((__INDEX__) == 8) RS485_2_DE_GPIO_CLK_ENABLE(); else \
											if((__INDEX__) == 9) MODBUS_DE_GPIO_CLK_ENABLE();\
                                            }while(0)

#define PORTx_GPIO_CLK_DISABLE(__INDEX__) do{if((__INDEX__) == 0) LED1_GPIO_CLK_DISABLE(); else \
                                            if((__INDEX__) == 1) LED2_GPIO_CLK_DISABLE(); else \
                                            if((__INDEX__) == 2) LED3_GPIO_CLK_DISABLE(); else \
                                            if((__INDEX__) == 3) LED4_GPIO_CLK_DISABLE(); else \
                                            if((__INDEX__) == 4) LEDtst0_GPIO_CLK_DISABLE(); else \
                                            if((__INDEX__) == 5) LEDtst1_GPIO_CLK_DISABLE(); else \
                                            if((__INDEX__) == 6) LEDtst2_GPIO_CLK_DISABLE(); else \
                                            if((__INDEX__) == 7) RS485_1_DE_GPIO_CLK_DISABLE(); else \
											if((__INDEX__) == 8) RS485_2_DE_GPIO_CLK_DISABLE(); else \
											if((__INDEX__) == 9) MODBUS_DE_GPIO_CLK_DISABLE(); \
                                            }while(0)


#define SRAMn                             32
//  GPIO_Init_Structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_7 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
#define SRAM_L0    						GPIO_PIN_0
#define SRAM_L0_PORT					GPIOD
#define SRAM_L1    						GPIO_PIN_1
#define SRAM_L1_PORT					GPIOD
#define SRAM_L2    						GPIO_PIN_4
#define SRAM_L2_PORT					GPIOD
#define SRAM_L3    						GPIO_PIN_5
#define SRAM_L3_PORT					GPIOD
#define SRAM_L4    						GPIO_PIN_7
#define SRAM_L4_PORT					GPIOD
#define SRAM_L5    						GPIO_PIN_11
#define SRAM_L5_PORT					GPIOD
#define SRAM_L6    						GPIO_PIN_12
#define SRAM_L6_PORT					GPIOD
#define SRAM_L7    						GPIO_PIN_13
#define SRAM_L7_PORT					GPIOD
#define SRAM_L8    						GPIO_PIN_14
#define SRAM_L8_PORT					GPIOD
#define SRAM_L9    						GPIO_PIN_15
#define SRAM_L9_PORT					GPIOD

//GPIO_Init_Structure.Pin   = GPIO_PIN_3| GPIO_PIN_4 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
#define SRAM_L10   						GPIO_PIN_3
#define SRAM_L10_PORT					GPIOE
#define SRAM_L11   						GPIO_PIN_4
#define SRAM_L11_PORT					GPIOE
#define SRAM_L12   						GPIO_PIN_7
#define SRAM_L12_PORT					GPIOE
#define SRAM_L13   						GPIO_PIN_8
#define SRAM_L13_PORT					GPIOE
#define SRAM_L14   						GPIO_PIN_9
#define SRAM_L14_PORT					GPIOE
#define SRAM_L15   						GPIO_PIN_10
#define SRAM_L15_PORT					GPIOE

//  GPIO_Init_Structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2| GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
#define SRAM_L16   						GPIO_PIN_0
#define SRAM_L16_PORT					GPIOF
#define SRAM_L17   						GPIO_PIN_1
#define SRAM_L17_PORT					GPIOF
#define SRAM_L18   						GPIO_PIN_2
#define SRAM_L18_PORT					GPIOF
#define SRAM_L19   						GPIO_PIN_3
#define SRAM_L19_PORT					GPIOF
#define SRAM_L20   						GPIO_PIN_4
#define SRAM_L20_PORT					GPIOF
#define SRAM_L21   						GPIO_PIN_5
#define SRAM_L21_PORT					GPIOF
#define SRAM_L22   						GPIO_PIN_12
#define SRAM_L22_PORT					GPIOF
#define SRAM_L23   						GPIO_PIN_13
#define SRAM_L23_PORT					GPIOF
#define SRAM_L24   						GPIO_PIN_14
#define SRAM_L24_PORT					GPIOF
#define SRAM_L25   						GPIO_PIN_15
#define SRAM_L25_PORT					GPIOF

//  GPIO_Init_Structure.Pin   = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2| GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5;
#define SRAM_L26   						GPIO_PIN_0
#define SRAM_L26_PORT					GPIOG
#define SRAM_L27   						GPIO_PIN_1
#define SRAM_L27_PORT					GPIOG
#define SRAM_L28   						GPIO_PIN_2
#define SRAM_L28_PORT					GPIOG
#define SRAM_L29   						GPIO_PIN_3
#define SRAM_L29_PORT					GPIOG
#define SRAM_L30   						GPIO_PIN_4
#define SRAM_L30_PORT					GPIOG
#define SRAM_L31   						GPIO_PIN_5
#define SRAM_L31_PORT					GPIOG


#ifdef __cplusplus
}
#endif

#endif /* __STM324xG_EVAL_H */
 
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
