/*
 * clocks.c
 *
 *  Created on: 14.07.2015
 *      Author: sagok
 */


#include "main.h"
#include "clocks.h"
#include "cmsis_os.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_rcc_ex.h"


extern RTC_HandleTypeDef 	hrtc;

void Clocks_Init(void)
{
	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;

    hrtc.Instance = RTC;
    hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
    //#define RTC_ASYNCH_PREDIV    0x7F				LSI
	//#define RTC_SYNCH_PREDIV     0x0130

    hrtc.Init.AsynchPrediv = 124;
    hrtc.Init.SynchPrediv = 7999;
    hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
    hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
    hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
    HAL_RTC_Init(&hrtc);

    HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, 0xFFFF);
}
