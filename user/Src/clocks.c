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

RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;
RTC_HandleTypeDef hrtc;


void Clocks_Init(void)
{
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;

    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
//TODO: на реальном приборе кварц не 8 а 25 ћ√ц. исправить делитель
#ifdef STM32F407xx
    PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_HSE_DIV8;		// RTCCLK = 1MHz
#endif
#ifdef STM32F417xx			// HSE = 25MHz
    PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_HSE_DIV25;		// RTCCLK = 1MHz
#endif

    HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);

    __HAL_RCC_RTC_ENABLE();

    hrtc.Instance = RTC;
    hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
    hrtc.Init.AsynchPrediv = 124;
    hrtc.Init.SynchPrediv = 7999;
    hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
    hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
    hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
    HAL_RTC_Init(&hrtc);

    sTime.Hours = 1;
    sTime.Minutes = 1;
    sTime.Seconds = 1;
    sTime.SubSeconds = 0;
    sTime.TimeFormat = RTC_HOURFORMAT_24;
    sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
    sTime.StoreOperation = RTC_STOREOPERATION_RESET;
    HAL_RTC_SetTime(&hrtc, &sTime, FORMAT_BCD);

    sDate.WeekDay = RTC_WEEKDAY_MONDAY;
    sDate.Month = RTC_MONTH_JANUARY;
    sDate.Date = 1;
    sDate.Year = 0;
    HAL_RTC_SetDate(&hrtc, &sDate, FORMAT_BCD);
}
