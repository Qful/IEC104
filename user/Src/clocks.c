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
/*
    sDate.WeekDay = RTC_WEEKDAY_FRIDAY;
    sDate.Month = RTC_MONTH_APRIL;
    sDate.Date = 29;
    sDate.Year = 16;								//от 2000 года 1970
    HAL_RTC_SetDate(&hrtc, &sDate, FORMAT_BIN);

    sTime.Hours = 0;
    sTime.Minutes = 0;
    sTime.Seconds = 0;
    sTime.SubSeconds = 0;
    sTime.TimeFormat = RTC_HOURFORMAT_24;
    sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
    sTime.StoreOperation = RTC_STOREOPERATION_RESET;
    HAL_RTC_SetTime(&hrtc, &sTime, FORMAT_BIN);

    HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, 0x32F2);
*/
    HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0, 0xFFFF);
}
