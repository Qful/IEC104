/*
 * iec104asdu.c
 *
 *  Created on: 25.06.2015
 *      Author: sagok
 */
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

#include "stm32f4xx_hal.h"

#include "iec104.h"

#ifdef	IEC104Task
/* 
 * iecasdu_parse_type() - Preprocessor macros for common parse procedure of ASDU
 */

#define iecasdu_parse_type(obj, buf, buflen, str_ioa, iec_type_name, struct_name)	\
																					\
	int i;																			\
	int step = 0;																	\
	struct iec_unit_id *unitp;														\
	struct iec_type_name *typep;													\
	u_short *addr, addr_cur;														\
	u_char  *addr2;																	\
																					\
	unitp = (struct iec_unit_id *) buf;												\
																					\
	if (unitp->sq == 0) {															\
		step = sizeof(u_short)+sizeof(u_char)+sizeof(struct iec_type_name);			\
		if ( (step * unitp->num + sizeof(struct iec_unit_id)) > buflen )			\
			return 1;																\
		for (i=0; i < unitp->num; i++, obj++){										\
			addr  = (u_short *) (buf + sizeof(struct iec_unit_id) + i*step);		\
			addr2 = (u_char *) (buf + sizeof(struct iec_unit_id) + 					\
				sizeof(u_short) + i*step);											\
			typep = (struct iec_type_name *) (buf + 								\
				sizeof(struct iec_unit_id) + sizeof(u_short) +						\
				sizeof(u_char) + i*step);											\
			if (*str_ioa) {															\
				obj->ioa = *addr;													\
				obj->ioa2  = *addr2;												\
			} else {																\
				obj->ioa  = *addr & 0xFFF;											\
				obj->ioa2 = 0;														\
			}																		\
			obj->o.struct_name = *typep;											\
		}																			\
	} else {																		\
		if ( sizeof(struct iec_type_name) * unitp->num +							\
		     sizeof(struct iec_unit_id) > buflen )									\
			return 1;																\
		addr  = (u_short *) (buf + sizeof(struct iec_unit_id));						\
		addr2 = (u_char *) (buf + sizeof(struct iec_unit_id) + sizeof(u_short));	\
		typep = (struct iec_type_name *) (buf + sizeof(struct iec_unit_id) + 		\
				sizeof(u_short) + sizeof(u_char));									\
		addr_cur = *addr;															\
																					\
		for (i=0; i < unitp->num; i++, obj++, typep++, addr_cur++){					\
			if (*str_ioa) {															\
				obj->ioa = addr_cur;												\
				obj->ioa2  = *addr2;												\
			} else {																\
				obj->ioa  = addr_cur & 0xFFF;										\
				obj->ioa2 = 0;														\
			}																		\
			obj->o.struct_name = *typep;											\
		}																			\
	}																				\
	return 0;

/* parse functions */

int iecasdu_parse_type1(struct iec_object *obj, unsigned char *buf, size_t buflen, u_char *str_ioa)
{
	iecasdu_parse_type(obj,buf,buflen,str_ioa,iec_type1,type1);
}
int iecasdu_parse_type13(struct iec_object *obj, unsigned char *buf, size_t buflen, u_char *str_ioa)
{
	iecasdu_parse_type(obj,buf,buflen,str_ioa,iec_type13,type13);
}
int iecasdu_parse_type30(struct iec_object *obj, unsigned char *buf, size_t buflen, u_char *str_ioa)
{
	iecasdu_parse_type(obj,buf,buflen,str_ioa,iec_type30,type30);
}
int iecasdu_parse_type36(struct iec_object *obj, unsigned char *buf, size_t buflen, u_char *str_ioa)
{
	iecasdu_parse_type(obj,buf,buflen,str_ioa,iec_type36,type36);
}
int iecasdu_parse_type37(struct iec_object *obj, unsigned char *buf, size_t buflen, u_char *str_ioa)
{
	iecasdu_parse_type(obj,buf,buflen,str_ioa,iec_type37,type37);
}
int iecasdu_parse_type100(struct iec_object *obj, unsigned char *buf, size_t buflen, u_char *str_ioa)
{
	iecasdu_parse_type(obj,buf,buflen,str_ioa,iec_type100,type100);
}
int iecasdu_parse_type101(struct iec_object *obj, unsigned char *buf, size_t buflen, u_char *str_ioa)
{
//	iecasdu_parse_type(obj,buf,buflen,str_ioa,iec_type101,type101);

	int i;
	int step = 0;
	struct iec_unit_id *unitp;
	struct iec_type101 *typep;
	u_short *addr, addr_cur;
	u_char  *addr2;

	unitp = (struct iec_unit_id *) buf;

	if (unitp->sq == 0) {
		step = sizeof(u_short)+sizeof(u_char)+sizeof(struct iec_type101);
		if ( (step * unitp->num + sizeof(struct iec_unit_id)) > buflen )
			return 1;

		for (i=0; i < unitp->num; i++, obj++){
			addr  = (u_short *) (buf + sizeof(struct iec_unit_id)-5 + i*step);
			addr2 = (u_char *) (buf + sizeof(struct iec_unit_id)-3 + i*step);
			typep = (struct iec_type101 *) (buf + sizeof(struct iec_unit_id) + i*step);

			if (*str_ioa) {
				obj->ioa = *addr;
				obj->ioa2  = *addr2;
			} else {
				obj->ioa  = *addr & 0xFFF;
				obj->ioa2 = 0;
			}
			obj->o.type101 = *typep;
		}
	} else {
//TODO: надо дописать если sq == 1
	}
	return 0;

}
int iecasdu_parse_type103(struct iec_object *obj, unsigned char *buf, size_t buflen, u_char *str_ioa)
{
//	iecasdu_parse_type(obj,buf,buflen,str_ioa,iec_type103,type103);

		int i;
		int step = 0;
		struct iec_unit_id *unitp;
		struct iec_type103 *typep;
		u_short *addr, addr_cur;
		u_char  *addr2;

		unitp = (struct iec_unit_id *) buf;

		if (unitp->sq == 0) {
			step = sizeof(u_short)+sizeof(u_char)+sizeof(struct iec_type103);
			if ( (step * unitp->num + sizeof(struct iec_unit_id)) > buflen )
				return 1;

			for (i=0; i < unitp->num; i++, obj++){
				addr  = (u_short *) (buf + sizeof(struct iec_unit_id)-5 + i*step);
				addr2 = (u_char *) (buf + sizeof(struct iec_unit_id)-3 + i*step);
				typep = (struct iec_type103 *) (buf + sizeof(struct iec_unit_id) + i*step);

				if (*str_ioa) {
					obj->ioa = *addr;
					obj->ioa2  = *addr2;
				} else {
					obj->ioa  = *addr & 0xFFF;
					obj->ioa2 = 0;
				}
				obj->o.type103 = *typep;
			}
		} else {
			if ( sizeof(struct iec_type103) * unitp->num + sizeof(struct iec_unit_id) > buflen )
				return 1;

			addr  = (u_short *) (buf + sizeof(struct iec_unit_id));
			addr2 = (u_char *) (buf + sizeof(struct iec_unit_id) + sizeof(u_short));
			typep = (struct iec_type103 *) (buf + sizeof(struct iec_unit_id) + sizeof(u_short) + sizeof(u_char));
			addr_cur = *addr;

			for (i=0; i < unitp->num; i++, obj++, typep++, addr_cur++){
				if (*str_ioa) {
					obj->ioa = addr_cur;
					obj->ioa2  = *addr2;
				} else {
					obj->ioa  = addr_cur & 0xFFF;
					obj->ioa2 = 0;
				}
				obj->o.type103 = *typep;
			}
		}
		return 0;

}

/*******************************************************************************************
 * type -   тип ASDU
 * *funcp - функция распаковки пакета ASDU
 *******************************************************************************************/
struct {
	char type;
	int (*funcp)();
} iecasdu_parse_tab[] = {
	{  1,	&iecasdu_parse_type1	},
	{ 13,	&iecasdu_parse_type13	},
	{ 30,	&iecasdu_parse_type30	},
	{ 36,	&iecasdu_parse_type36	},
	{ 37,	&iecasdu_parse_type37	},
	{100,	&iecasdu_parse_type100	},
	{101,	&iecasdu_parse_type101	},
	{103,	&iecasdu_parse_type103	},
	{  0,	NULL			}
};

/**
 * iecasdu_parse - parse ASDU unit
 * @param obj : 		array of information objects, MUST be at least IEC_OBJECT_MAX
 * @param type : 		returned type identifier (1-127)
 * @param com_addr : 	returned common address of ASDU
 * @param cnt : 		returned number of information objects in obj array
 * @param cause : 		returned cause identifier (0-63)
 * @param test : 		returned test bit (1=test, 0=not test)
 * @param pn : 			returned P/N bit (0=positive confirm, 1=negative confirm)
 * @param str_ioa : 	structured / not structured information object address
 * @param buf : 		buffer which contains unparsed ASDU
 * @param buflen : 		ASDU length
 * @return : 0 - success, 1 - incorrect ASDU, 2 - unknown ASDU type
 */
int iecasdu_parse(struct iec_object *obj, u_char *type, u_short *com_addr,
		int *cnt, u_char *cause, u_char *test, u_char *pn,
		u_char *str_ioa, u_char *buf, size_t buflen)
{
	int i;
	int ret = 2;
	struct iec_unit_id *unitp;
	
	unitp	= (struct iec_unit_id *) buf;
	*cnt	= unitp->num;
	*cause	= unitp->cause;
	*test	= unitp->t;
	*pn	= unitp->pn;
	*com_addr = unitp->ca;
	*type   = unitp->type;

	for (i=0; iecasdu_parse_tab[i].type != 0 ; i++){
		if ( iecasdu_parse_tab[i].type == unitp->type ) {
			ret = (*iecasdu_parse_tab[i].funcp)(obj,buf,buflen,str_ioa);
			break;
                }
        } 
	return ret;
}

void time_t_to_cp56time2a (cp56time2a *tm)
{
	extern RTC_HandleTypeDef hrtc;
	RTC_TimeTypeDef sTimeg;
	RTC_DateTypeDef sDateg;

	HAL_RTC_GetTime(&hrtc, &sTimeg, FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDateg, FORMAT_BIN);

	tm->msec = sTimeg.Seconds * 1000;
	tm->min  = sTimeg.Minutes;
	tm->res1 = 0;
	tm->iv   = 0;
	tm->hour = sTimeg.Hours;
	tm->res2 = 0;
	tm->su   = 0;						// перевод зима-лето
	tm->mday = sDateg.Date;
	tm->wday = 0;
	tm->month =sDateg.Month;
	tm->res3 = 0;
	tm->year = sDateg.Year-20;
	tm->res4 = 0;
}

/*
 * cp56time2a_to_tm() - return time as time_t structure from cp56time2a structure
 */
time_t cp56time2a_to_tm (cp56time2a *tm)
{
	struct tm tml;

	tml.tm_sec = (int) (tm->msec / 1000);
	tml.tm_min = tm->min;
	tml.tm_hour = tm->hour;
	tml.tm_isdst = tm->su;
	tml.tm_mday = tm->mday;
	tml.tm_mon = tm->month - 1;
	tml.tm_year = tm->year + 100;
	
	return mktime(&tml);	
}

/*
 *  iecasdu_create_header_all - create ASDU header (full version)
 *  buf, buflen,
 *  type(идентификатор типа)
 *  num(число объектов)
 *  sq(классификатор переменной структуры - последовательность(1) или одиночный(0))
 *  cause(причина)
 *  t(тест)
 *  pn(подтверждение активации)
 *  ma(общий адрес)
 *  ca(адрес объекта)
 *
 */
void iecasdu_create_header_all (uint8_t *buf, size_t *buflen, uint8_t type, uint8_t num,
		uint8_t sq, uint8_t cause, uint8_t t, uint8_t pn, uint8_t initaddr, uint16_t ma, uint32_t ca)
{
	struct iec_unit_id unit;
	unit.type  = type;
	unit.num   = num;
	unit.sq    = sq;
	unit.cause = cause;
	unit.t	    = t;
	unit.pn    = pn;
	unit.initaddr = initaddr;
	unit.ma    = ma;
	unit.ca    = ca;

	memcpy(buf, &unit, sizeof(struct iec_unit_id));
	*buflen += sizeof(struct iec_unit_id);
}

void iecasdu_add_APCI(u_char *buf, size_t buflen){

struct iechdr *h;
extern struct iecsock 	*s;

	h = calloc(1, sizeof(struct iechdr));

	h->start = 0x68;
	h->length = buflen-2;
	h->ic.ft = 0;
	h->ic.ns = s->vs;
	h->ic.nr = s->vr;
	h->ic.res = 0;
	memcpy(buf, h, sizeof(struct iechdr));

	free(h);

}

/*
 *  CREATE ASDU functions
 */
	
void iecasdu_create_type_1 (u_char *buf, size_t *buflen, uint8_t sp)
{
	struct iec_type1 type;
	u_short ioa  = 1;
	const u_char  ioa2 = 0;
	type.sp = sp & 1;
	type.res = 0;
	type.bl = 0; /* <блокировка/нет блокировки - значение блокировано для передачи, остаётся в состоянии которое было до блокировки*/
	type.sb = 0; /* замещение/нет замещения - значение поступает или от диспетчера или от автоматического источника*/
	type.nt = 0; /* неактуальное/актуальное - Актуально если большенство опросов успешно. Неактуально, если не обновлялось или было недоступно*/
	type.iv = 0; /* действительное/не действительное - действ. если правильно получено. Недейств. используется для указания получателю, что значение не правильное или нельзя пользоваться*/


	//memcpy(buf, &ioa, sizeof(u_short));
	//memcpy(buf + sizeof(u_short), &ioa2, sizeof(u_char));
	//memcpy(buf + sizeof(u_short) + sizeof(u_char), &type, sizeof(struct iec_type1));
	//*buflen += sizeof(u_short) + sizeof(u_char) + sizeof(struct iec_type1);

	memcpy(buf, &type, sizeof(struct iec_type1));
	*buflen += sizeof(struct iec_type1);
}

void iecasdu_create_type_9 (u_char *buf, size_t *buflen,u_short mv)
{
	struct iec_type9 type;
	//u_short ioa  = 1;
	//const u_char  ioa2 = 0;

	type.ov = 0; /* переполнение/нет переполнения(0) */
	type.res = 0;
	type.bl = 0; /* <блокировка/нет блокировки(0) - значение блокировано для передачи, остаётся в состоянии которое было до блокировки*/
	type.sb = 0; /* замещение/нет замещения(0) - значение поступает или от диспетчера или от автоматического источника*/
	type.nt = 0; /* неактуальное/актуальное(0) - Актуально если большенство опросов успешно. Неактуально, если не обновлялось или было недоступно*/
	type.iv = 0; /* действительное(0)/не действительное - действ. если правильно получено. Недейств. используется для указания получателю, что значение не правильное или нельзя пользоваться*/

	type.mv = mv;	/* normalized value */


//	memcpy(buf, &ioa, sizeof(u_short));
//	memcpy(buf + sizeof(u_short), &ioa2, sizeof(u_char));
//	memcpy(buf + sizeof(u_short) + sizeof(u_char), &type, sizeof(struct iec_type9));
//	*buflen += sizeof(u_short) + sizeof(u_char) + sizeof(struct iec_type9);
	// адреса устанавливаются при формировании "головы"
	memcpy(buf, &type, sizeof(struct iec_type9));
	*buflen += sizeof(struct iec_type9);
}



void iecasdu_create_type_100 (u_char *buf, size_t *buflen)
{
	struct iec_type100 type;
	u_short ioa  = 1;
	const u_char  ioa2 = 0;

	type.qoi = 20;
	
	//memcpy(buf, &ioa, sizeof(u_short));
	//memcpy(buf + sizeof(u_short), &ioa2, sizeof(u_char));
	//memcpy(buf + sizeof(u_short) + sizeof(u_char), &type, sizeof(struct iec_type100));
	//*buflen += sizeof(u_short) + sizeof(u_char) + sizeof(struct iec_type100);
	memcpy(buf, &type, sizeof(struct iec_type100));
	*buflen += sizeof(struct iec_type100);
}

void iecasdu_create_type_101 (u_char *buf, size_t *buflen)
{
	struct iec_type101 type;
	u_short ioa  = 1;
	const u_char  ioa2 = 0;

	type.rqt = 5;
	type.frz = 0;
	
	//memcpy(buf, &ioa, sizeof(u_short));
	//memcpy(buf + sizeof(u_short), &ioa2, sizeof(u_char));
	//memcpy(buf + sizeof(u_short) + sizeof(u_char), &type, sizeof(struct iec_type101));
	//*buflen += sizeof(u_short) + sizeof(u_char) + sizeof(struct iec_type101);

	memcpy(buf, &type, sizeof(struct iec_type101));
	*buflen += sizeof(struct iec_type101);

}

/*************************************************************************
 * iecasdu_create_type_103
 *************************************************************************/
void iecasdu_create_type_103 (u_char *buf, size_t *buflen)
{
	struct iec_type103 type;

	time_t_to_cp56time2a(&type.time);

	//current_cp56time2a(&type.time);
	//memcpy(buf, &ioa, sizeof(u_short));
	//memcpy(buf + sizeof(u_short), &ioa2, sizeof(u_char));
	//memcpy(buf + sizeof(u_short) + sizeof(u_char), &type, sizeof(struct iec_type103));
	//*buflen += sizeof(u_short) + sizeof(u_char) + sizeof(struct iec_type103);

	memcpy(buf, &type, sizeof(struct iec_type103));
	*buflen += sizeof(struct iec_type103);
}
/*************************************************************************
 * iecasdu_create_type_36
 *************************************************************************/
void iecasdu_create_type_36 (u_char *buf, size_t *buflen, int num, float *mv) {
	struct iec_type36 type;
	struct cp56time2a tm;
	u_short ioa  = 1;
	const u_char  ioa2 = 0;
	int i;
	size_t len;

	time_t_to_cp56time2a(&tm);
//	current_cp56time2a(&tm);
//	len = sizeof(u_short)+sizeof(u_char)+sizeof(struct iec_type36);
	
	for (i=0; i < num; i++, mv++, ioa++) {
		type.mv = *mv;
		type.ov = 0;
		type.res = 0;
		type.bl=0;
		type.sb=0;
		type.nt=0;
		type.iv=0;
		type.time = tm;
		
//		memcpy(buf + len*i, &ioa, sizeof(u_short));
//		memcpy(buf + len*i + sizeof(u_short), &ioa2, sizeof(u_char));
//		memcpy(buf + len*i + sizeof(u_short) + sizeof(u_char), &type,sizeof(struct iec_type36));
//		*buflen += len;
		memcpy(buf, &type, sizeof(struct iec_type36));
		*buflen += sizeof(struct iec_type36);
	}
}

/*************************************************************************
 * IEC104_IncTimers
 *************************************************************************/
void IEC104_IncTimers(struct iecsock *s){

	if (s->t0.run) {			// раборта таймера t0
		s->t0.cntcurr++;
		if (s->t0.cntdest <= s->t0.cntcurr){
			s->t0.cntcurr = 0;
			s->t0.evnt = 1;
			s->t0.run = 0;
		}
	}
	if (s->t1.run) {			// раборта таймера t1
		s->t1.cntcurr++;
		if (s->t1.cntdest <= s->t1.cntcurr){
			s->t1.cntcurr = 0;
			s->t1.evnt = 1;
			s->t1.run = 0;
		}
	}
	if (s->t2.run) {			// раборта таймера t2
		s->t2.cntcurr++;
		if (s->t2.cntdest <= s->t2.cntcurr){
			s->t2.cntcurr = 0;
			s->t2.evnt = 1;
			s->t2.run = 0;
		}
	}
	if (s->t3.run) {			// раборта таймера t3
		s->t3.cntcurr++;
		if (s->t3.cntdest <= s->t3.cntcurr){
			s->t3.cntcurr = 0;
			s->t3.evnt = 1;
			s->t3.run = 0;
		}
	}

}

/*************************************************************************
 * t0_timer
 *************************************************************************/
void t0_timer_start(struct iecsock *s){
	s->t0.evnt = 0;
	s->t0.run = 1;
	USART_TRACE("t0 start.\n");
}

void t0_timer_stop( struct iecsock *s){
	s->t0.cntcurr = 0;
	s->t0.evnt = 0;
	s->t0.run = 0;
	USART_TRACE("t0 stop.\n");
}
/*************************************************************************
 * t1_timer
 * тайм-аут при посылке или тестировании
 *************************************************************************/
void t1_timer_start( struct iecsock *s){
	s->t1.evnt = 0;
	s->t1.run = 1;
	USART_TRACE("t1 start.\n");
}
/*************************************************************************
 * тайм-аут при посылке или тестировании
 *************************************************************************/
void t1_timer_stop( struct iecsock *s){
	s->t1.cntcurr = 0;
	s->t1.evnt = 0;
	s->t1.run = 0;
	USART_TRACE("t1 stop.\n");
}
/*************************************************************************
 * t2_timer
 * тайм-аут для подтверждения в случае отсутствия сообщения с данными
 * по истечении этого времени нужно передать обязательно S фрейм
 *************************************************************************/
void t2_timer_start( struct iecsock *s){
	s->t2.evnt = 0;
	s->t2.run = 1;
	USART_TRACE("t2 start.\n");
}
/*************************************************************************
 * тайм-аут для подтверждения в случае отсутствия сообщения с данными
 *************************************************************************/
void t2_timer_stop( struct iecsock *s){
	s->t2.cntcurr = 0;
	s->t2.evnt = 0;
	s->t2.run = 0;
	USART_TRACE("t2 stop.\n");
}
/*************************************************************************
 * t3_timer
 * тайм-аут для посылки блоков тестирования в случае долгого простоя.
 *************************************************************************/
void t3_timer_start( struct iecsock *s){
	s->t3.evnt = 0;
	s->t3.run = 1;
	USART_TRACE("t3 start.\n");
}

void t3_timer_stop( struct iecsock *s){
	s->t3.cntcurr = 0;
	s->t3.evnt = 0;
	s->t3.run = 0;
	USART_TRACE("t3 stop.\n");
}
/*************************************************************************
 * t0_timer_pending
 *************************************************************************/
int8_t t0_timer_pending ( struct iecsock *s){

	return s->t0.evnt;
}
/*************************************************************************
 * t1_timer_pending
 *************************************************************************/
int8_t t1_timer_pending ( struct iecsock *s){

	return s->t1.evnt;
}
/*************************************************************************
 * t2_timer_pending
 *************************************************************************/
int8_t t2_timer_pending ( struct iecsock *s){

	return s->t2.evnt;
}
/*************************************************************************
 * t3_timer_pending
 *************************************************************************/
int8_t t3_timer_pending ( struct iecsock *s){

	return s->t3.evnt;
}

/*************************************************************************
 * t1_timer_run
 *************************************************************************/
void t1_timer_run(struct iecsock *s)
{
	extern struct netconn *newconn;
	USART_TRACE("!!! нужно активное закрытие соединения таймаут t1 !!!\n");
	s->t1.evnt = 0;
	s->t1.run = 0;

	// попробуем закрыть
	s->vr = 0;
	s->vs = 0;
	s->va = 0;
	USART_TRACE("active close TCP/IP\n");
    netconn_close(newconn);									// закрываем и освобождаем соединение
    netconn_delete(newconn);

}
/*************************************************************************
 * t2_timer_run
 *************************************************************************/
void t2_timer_run(struct iecsock *s)
{
	iec104_sframe_send(s);
	s->va_peer = s->vr;
	s->t2.evnt = 0;
	s->t2.run = 0;
}
/*************************************************************************
 * t3_timer_run
 *************************************************************************/
void t3_timer_run(struct iecsock *s)
{
	t1_timer_start(s);
	s->testfr = 1;
	iec104_uframe_send(s, TESTACT);
	s->t3.evnt = 0;
	s->t3.run = 0;
}

#endif
