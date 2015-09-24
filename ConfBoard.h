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
#ifndef __STM324xG_EVAL_H
#define __STM324xG_EVAL_H

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
  RS485_1_DEn = 4,
  RS485_2_DEn = 5,
  MODBUS_DEn = 6,
}Port_TypeDef;

// ----------------------------------------------------------------------------------------------------
#define PORTn                             7


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

#define RS485_1_DE                       GPIO_PIN_4
#define RS485_1_DE_GPIO_PORT             GPIOD
#define RS485_1_DE_GPIO_CLK_ENABLE()     __GPIOD_CLK_ENABLE()
#define RS485_1_DE_GPIO_CLK_DISABLE()    __GPIOD_CLK_DISABLE()

#define RS485_2_DE                       GPIO_PIN_12
#define RS485_2_DE_GPIO_PORT             GPIOD
#define RS485_2_DE_GPIO_CLK_ENABLE()     __GPIOD_CLK_ENABLE()
#define RS485_2_DE_GPIO_CLK_DISABLE()    __GPIOD_CLK_DISABLE()

#define MODBUS_DE                       GPIO_PIN_0					// не использовать
#define MODBUS_DE_GPIO_PORT             GPIOC
#define MODBUS_DE_GPIO_CLK_ENABLE()     __GPIOC_CLK_ENABLE()
#define MODBUS_DE_GPIO_CLK_DISABLE()    __GPIOC_CLK_DISABLE()

#define PORTx_GPIO_CLK_ENABLE(__INDEX__)  do{if((__INDEX__) == 0) LED1_GPIO_CLK_ENABLE(); else \
                                            if((__INDEX__) == 1) LED2_GPIO_CLK_ENABLE(); else \
                                            if((__INDEX__) == 2) LED3_GPIO_CLK_ENABLE(); else \
                                            if((__INDEX__) == 3) LED4_GPIO_CLK_ENABLE(); else \
                                            if((__INDEX__) == 4) RS485_1_DE_GPIO_CLK_ENABLE(); else \
											if((__INDEX__) == 5) RS485_2_DE_GPIO_CLK_ENABLE(); else \
											if((__INDEX__) == 6) MODBUS_DE_GPIO_CLK_ENABLE();\
                                            }while(0)

#define PORTx_GPIO_CLK_DISABLE(__INDEX__) do{if((__INDEX__) == 0) LED1_GPIO_CLK_DISABLE(); else \
                                            if((__INDEX__) == 1) LED2_GPIO_CLK_DISABLE(); else \
                                            if((__INDEX__) == 2) LED3_GPIO_CLK_DISABLE(); else \
                                            if((__INDEX__) == 3) LED4_GPIO_CLK_DISABLE(); else \
                                            if((__INDEX__) == 4) RS485_1_DE_GPIO_CLK_DISABLE(); else \
											if((__INDEX__) == 5) RS485_2_DE_GPIO_CLK_DISABLE(); else \
											if((__INDEX__) == 6) MODBUS_DE_GPIO_CLK_DISABLE(); \
                                            }while(0)

#ifdef __cplusplus
}
#endif

#endif /* __STM324xG_EVAL_H */
 
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
