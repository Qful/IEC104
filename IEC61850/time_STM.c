/*
 *  time.c
 *
 *  Copyright 2013, 2014 Michael Zillgith
 *
 *  This file is part of libIEC61850.
 *
 *  libIEC61850 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libIEC61850 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libIEC61850.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  See COPYING file for the complete license text.
 */


#include "libiec61850_platform_includes.h"

#include "stack_config.h"
#include "stm32f4xx_hal.h"

#include "main.h"

#include <stdint.h>

#include <time.h>

extern 	RTC_HandleTypeDef hrtc;

#ifdef CONFIG_SYSTEM_HAS_CLOCK_GETTIME
uint64_t
Hal_getTimeInMs()
{
	struct timespec tp;

	clock_gettime(CLOCK_REALTIME, &tp);

	return ((uint64_t) tp.tv_sec) * 1000LL + (tp.tv_nsec / 1000000);
}
#else

//#include <sys/time.h>

/*
uint64_t
Hal_getTimeInMs()
{
    struct timeval now;

    gettimeofday(&now, NULL);

    return ((uint64_t) now.tv_sec * 1000LL) + (now.tv_usec / 1000);
}
*/
/*************************************************************************
 * Hal_getTimeInMs
 * Получаем от часов время в ms от лохматого 70-го года.
 * БЕЗ УЧЕТА ВИСОКОСНОСТИ.... чистые секунды .
 * Субсекундных зависит от значений "prescaler". RTC STM32F4 имеет 2 значения predivision:
 * ASYNC: 7-bit asynchronous prescaler
 * Max value can be 0x7F
 * SYNC: 15-bit synchronous prescaler
 * Max value can be 0x7FFF
 *************************************************************************/

uint64_t 	Hal_getTimeInMs (void){

	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;
	uint64_t	sectmp,den;

	HAL_RTC_GetTime(&hrtc, &sTime, FORMAT_BIN);			// Читаем время
	HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);			// читаем дату

	den 	= (30+sDate.Year) * 365 + (30+sDate.Year+2)/4 - 2;

	switch(sDate.Month) {
	    case 2 : den +=31; break;	//31	31
	    case 3 : den +=59; break;	//59	28
	    case 4 : den +=90; break;	//90	31
	    case 5 : den +=120; break;	//120	30
	    case 6 : den +=151; break;	//151	31
	    case 7 : den +=181; break;	//181	30
	    case 8 : den +=212; break;	//212	31
	    case 9 : den +=243; break;	//243	31
	    case 10 : den +=273; break;	//273	30
	    case 11 : den +=304; break;	//304	31
	    case 12 : den +=334; break;	//334	30
	   };

	if (!((30+sDate.Year+2)%4) && sDate.Month>2) den++;

	 den += sDate.Date;

	 sectmp = den * 86400;
	 sectmp += sTime.Hours * 3600;
	 sectmp += sTime.Minutes * 60;
	 sectmp += sTime.Seconds;

	 sectmp -= Timezone*60*60;			//отнимем часовой пояс, для получения отсчетов UTC стандарта.

	 // число милисекунд = 1000ms – (subseconds * 1000 / SYNC)     1000 – (subseconds * 1000 / hrtc.Init.SynchPrediv)
	// hrtc.Init.SynchPrediv
	 sectmp *= 1000;
	 // субсекунды
	 //sectmp += sTime.SubSeconds/10;
	 // правильно рассчитаные милисекунды
	 sectmp += (1000 - (sTime.SubSeconds * 1000 / hrtc.Init.SynchPrediv));

	return sectmp;
}


#endif
