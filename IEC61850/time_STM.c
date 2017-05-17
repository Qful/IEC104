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

extern	int16_t		ppm;
extern int8_t		TimeZone_my;
extern 	RTC_HandleTypeDef hrtc;

/** Структура данных ПИ-регулятора.  Она содержит настройки
(коэффициент усиления, интегральная часть, а также конечный делитель),
выходные пределы, и аккумулятор интегральной части. */
struct PIControl
{
   int kp;              /**Коэф-т усиления*/
   int ki;              /** Интегральная составляющая*/
   unsigned char shift; /**Сдвиг вправо*/
   int16_t max;             /** Максимальное значение */
   int16_t min;             /** Минимальное значение */
   long i;              /** Текущее значение интегральной части */
};


struct PIControl	PISt;

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
 * ASYNC: 7-bit asynchronous prescaler
 * Max value can be 0x7F
 * SYNC: 15-bit synchronous prescaler
 * Max value can be 0x7FFF
 *************************************************************************/
uint64_t 	Hal_getTimeInMs (void){

	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;
	uint64_t	sectmp,den;

	HAL_RTC_GetTime(&hrtc, &sTime, FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);

	den 	= (30+sDate.Year) * 365 + (30+sDate.Year+2)/4 - 1;

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

//	if (!((30+sDate.Year+2)%4) && sDate.Month>2) den++;
	if (((30+sDate.Year+2)%4) == 0){
		if (sDate.Month < 3) den--;
	}

	 den += sDate.Date;

	 sectmp = den * 86400;
	 sectmp += sTime.Hours * 3600;
	 sectmp += sTime.Minutes * 60;
	 sectmp += sTime.Seconds;

	 sectmp -= TimeZone_my*60*60;

	 sectmp *= 1000;

	 sectmp += (1000 - (sTime.SubSeconds * 1000 / hrtc.Init.SynchPrediv));

	return sectmp;
}
/*************************************************************************
 * Hal_setTimeInMs
 *************************************************************************/
#define JD0 2451911 // РґРЅРµР№ РґРѕ 01 СЏРЅРІ 2001 РџРќ

void 	Hal_setTimeInMs (uint64_t timeinms){

	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;

	uint64_t 	timeinTimeZone = timeinms;// + Timezone*60*60*1000;

	uint64_t 	timeinsec;
	uint64_t	tim,t1;
	uint64_t	jd,jdn;
//	uint8_t		msec;

	uint8_t		wday,mday,mon;
	uint16_t	year;

	uint64_t a;
	uint64_t b;
	uint64_t c;
	uint64_t d;
	uint64_t e;
	uint64_t m;

	timeinsec = timeinms/1000; //timeinTimeZone/1000;
//	msec = (uint8_t)timeinms%1000;//	msec = (uint8_t)(timeinTimeZone - timeinsec*1000);

	tim = timeinsec;   t1 = tim/60;   sTime.Seconds  = tim - t1*60;
	tim = t1;         t1 = tim/60;    sTime.Minutes  = tim - t1*60;
	tim = t1;         t1 = tim/24;    sTime.Hours = (uint8_t)(tim - t1*24);

//	sTime.SubSeconds 	= (1000-msec)*hrtc.Init.SynchPrediv/1000;		РЅРµ РєРѕСЂСЂРµРєС‚РёСЂСѓРµС‚
	sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sTime.TimeFormat = RTC_HOURFORMAT_24;
	sTime.StoreOperation = 0;
	HAL_RTC_SetTime(&hrtc, &sTime, FORMAT_BIN);

//	USART_TRACE("Hal_setTimeInMs %u.%u.%u\n",sTime.Hours,sTime.Minutes,sTime.Seconds);

//	HAL_RTC_SetTime(&hrtc, &sTime, FORMAT_BIN);

	jd  = ((timeinsec+43200)/(86400>>1)) + (2440587<<1) + 1;
	jdn = jd>>1;

	wday = jdn%7;

	a = jdn + 32044;
	b = (4*a+3)/146097;
	c = a - (146097*b)/4;
	d = (4*c+3)/1461;
	e = c - (1461*d)/4;
	m = (5*e+2)/153;

	mday = e - (153*m+2)/5 + 1;
	mon  = m + 3 - 12*(m/10);
	year = 100*b + d - 4800 + (m/10);


	sDate.Date 		= mday;
	sDate.Month		= mon;
	sDate.Year		= year - 2000;
	sDate.WeekDay	= wday+1;


	HAL_RTC_SetDate(&hrtc, &sDate, FORMAT_BIN);

}

/*************************************************************************
  * Пропорционально-интегральный (ПИ) регулятор.
  *
  * Этот модуль реализует простой ПИ-регулятор:
  *
  *   u = [ kp * e + ki * sum(e) ] >> shift
  *
  * shift как параметр, задающий число бит, на которое
  * будет сдвинут вправо результат, чтобы обеспечить необходимую точность.
  *
  * Предотвращение насыщения:
  * - Высчитывается новое выходное значение.
  * - Если оно превышает предел, и последнее изменение постоянной времени
  *   интегратора имеет то же направление (на увеличение или на уменьшение),
  *   то новое значение постоянной времени не сохраняется.
  * - Иначе, это значение сохраняется.

 *************************************************************************/
/*
int pi_control (struct PIControl *p, int e)
{
   bool int_ok;      // определяет, должна ли интегральная составляющая обновляться
   long new_i;       // новое значение интегральной составляющей
   long u;           // выходная величина

   // Считаем новую интегральную составляющую и выходную величину
   new_i = p->i + e;
   u = (p->kp * (long)e + p->ki * new_i) >> p->shift;

   // Проверяем на насыщение.
   int_ok = true;

   // Оно положительное?
   if (u > p->max)
   {
     u = p->max;
     // Тот же знак? Запрет интегрирования.
     if (e > 0)
     {
       int_ok = false;
     }
   }

   // То же самое для отрицательного значения
   else if (u < p->min)
   {
     u = p->min;

     if (e < 0)
     {
       int_ok = false;
     }
   }

   // Если разрешено, то обновляем интегральную составляющую
   if (int_ok)
   {
     p->i = new_i;
   }

	USART_TRACE("вход ПИ:%i Выход ПИ:%i\n",e,u);

   return (int)u;
}
*/
/**
  * Инициализация ПИ-регулятора.
  *
  * Эта функция сбрасывает ПИ-регулятор в ноль..
  *
  */
/*
void pi_control_init (struct PIControl *p)
{
   p->i = 0L;
}
*/
/*************************************************************************
* KalmanFilter: (https://habrahabr.ru/post/140274/)
*
* F — переменная описывающая динамику системы, в случае с топливом — это может быть коэффициент определяющий расход топлива на холостых оборотах за время дискретизации (время между шагами алгоритма). Однако помимо расхода топлива, существуют ещё и заправки… поэтому для простоты примем эту переменную равную 1 (то есть мы указываем, что предсказываемое значение будет равно предыдущему состоянию).
* B — переменная определяющая применение управляющего воздействия. Если бы у нас были дополнительная информация об оборотах двигателя или степени нажатия на педаль акселератора, то этот параметр бы определял как изменится расход топлива за время дискретизации. Так как управляющих воздействий в нашей модели нет (нет информации о них), то принимаем B = 0.
* H — матрица определяющая отношение между измерениями и состоянием системы, пока без объяснений примем эту переменную также равную 1.
*
* Определение сглаживающих свойств
* R — ошибка измерения может быть определена испытанием измерительных приборов и определением погрешности их измерения.
* Q — определение шума процесса является более сложной задачей, так как требуется определить дисперсию процесса, что не всегда возможно. В любом случае, можно подобрать этот параметр для обеспечения требуемого уровня фильтрации.
*************************************************************************/
#define F	1
#define Q	1.0
#define H	1.0
#define R	2.0//15.0


static int16_t	State = 0;
static int16_t	Covariance = 0.1;

int16_t	KalmanFilter(int16_t newdata){

int32_t	X0,P0;
int32_t	K;
float	Kk;

	X0 = F * State;
	P0 = F * Covariance * F + Q;

	K = H * P0 * H + R;
	Kk =(float)H * (float)P0 / (float)K;
//	K = P0 / K;
//	K = H * K;

	State = X0 + (float)Kk * (float)((int32_t)newdata - H * X0);
	//Covariance = (1 - K * H) * P0;
	Covariance = P0 - Kk * (float)H * (float)P0;

	USART_TRACE("Оценка Калмана:%i ошибка ковариации:%i\n",State,Covariance);

	return State;
}
/*************************************************************************
 * Hal_setCalibrTime
 * period - РїРµСЂРёРѕРґ РѕР±РЅРѕРІР»РµРЅРёСЏ РІ СЃРµРєСѓРЅРґР°С….
 * timeCal - РІСЂРµРјСЏ СѓС…РѕРґР° С‡Р°СЃРѕРІ Р·Р° РїРµСЂРёРѕРґ РІ РјСЃ.
 *
 * HAL_RTCEx_SetCoarseCalib:
 * value of coarse calibration expressed in ppm (coded on 5 bits).		DC[4:0]
 * This Calibration value should be between 0 and 63 when using negative sign with a 2-ppm step.
 * This Calibration value should be between 0 and 126 when using positive sign with a 4-ppm step.
 *  1РјСЃ РІ РјРёРЅСѓС‚Сѓ = 16ppm
 * РєРѕСЂСЂРµРєС‚РёСЂРѕРІРєСѓ РЅСѓР¶РЅРѕ РёРЅРєСЂРµРјРµРЅС‚РёС‚СЊ РґРѕ РґРѕСЃС‚РёР¶РµРЅРёСЏ 0
 *
 *************************************************************************/
void 	Hal_setCalibrTime (uint16_t period, int16_t timeCal){

	uint32_t 	calib;
//	int16_t		ppm;
	uint32_t	periodms = period*60*1000;//*60*1000;
	static 	int16_t	correct = 0;

	// РїРѕСЃС‡РёС‚Р°РµРј РІ ppm РёР· РјСЃ	ppm = period/(timeCal*100)		ppm = (timeCal * 1 000 000) / period

	ppm = (timeCal * 100/6) / period;	//4-ppm step					//ppm = (periodms/(-timeCal)/100)/2;	//4-ppm step
	if ((ppm >1000) || (ppm<-1000)) ppm = 0;

	correct = correct + ppm/2;

	// Без фильтра минимальный период опроса NTP = 16минут lkz gjkexty
//	if (ppm>0) 		{USART_TRACE("часы отстают на %i,ppm:%i\n",timeCal,ppm);}
//	else if (ppm<0) {USART_TRACE("часы спешат на %i,ppm:%i\n",timeCal,ppm);}
//	PISt.kp = 1;
//	PISt.ki = 1;
//	PISt.max = 127;
//	PISt.min = -63;
//	PISt.shift = 0;
//	correct = pi_control(&PISt,correct);

//	correct = KalmanFilter(correct);


	if (correct>127) correct = 127;
	if (correct<-63) correct = -63;
//	USART_TRACE("ppm:%i correct%i\n",ppm,correct);

	if (correct < 0 && (ppm !=0)){
		calib = -correct/2;
		HAL_RTCEx_SetCoarseCalib(&hrtc,RTC_CALIBSIGN_NEGATIVE,calib);
		USART_TRACE("calibr:-%u\n",calib);
	} else
	if (correct > 0 && (ppm !=0))
	{
		calib = correct/4;
		HAL_RTCEx_SetCoarseCalib(&hrtc,RTC_CALIBSIGN_POSITIVE,calib);
		USART_TRACE("calibr:+%u\n",calib);
	}

}

#endif
