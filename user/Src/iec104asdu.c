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
#include <time.h>

#include "iec104.h"

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
	iecasdu_parse_type(obj,buf,buflen,str_ioa,iec_type101,type101);
}
int iecasdu_parse_type103(struct iec_object *obj, unsigned char *buf, size_t buflen, u_char *str_ioa)
{
	iecasdu_parse_type(obj,buf,buflen,str_ioa,iec_type103,type103);
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

void time_t_to_cp56time2a (cp56time2a *tm, time_t *timet)
{
	struct tm tml;

	tml = *localtime(timet);
	
	tm->msec = tml.tm_sec * 1000;
	tm->min  = tml.tm_min;
	tm->res1 = 0;
	tm->iv   = 0;
	tm->hour = tml.tm_hour;
	tm->res2 = 0;
	tm->su   = tml.tm_isdst;
	tm->mday = tml.tm_mday;
	tm->wday = 0;
	tm->month = tml.tm_mon+1;;
	tm->res3 = 0;
	tm->year = tml.tm_year - 100;
	tm->res4 = 0;
	
}

void current_cp56time2a (cp56time2a *tm)
{
	time_t timet;

	timet = time(NULL);
	time_t_to_cp56time2a(tm,&timet);
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
 */

void iecasdu_create_header_all (u_char *buf, size_t *buflen, u_char type, u_char num,
			   u_char sq, u_char cause, u_char t, u_char pn, u_char ma,
			   u_short ca)
{
	struct iec_unit_id unit;
	unit.type  = type;
	unit.num   = num;
	unit.sq    = sq;
	unit.cause = cause;
	unit.t	    = t;
	unit.pn    = pn;
	unit.ma    = ma;
	unit.ca    = ca;

	memcpy(buf, &unit, sizeof(struct iec_unit_id));
	*buflen += sizeof(struct iec_unit_id);
}

/*
 *  CREATE ASDU functions
 */
	
void iecasdu_create_type_100 (u_char *buf, size_t *buflen)
{
	struct iec_type100 type;
	u_short ioa  = 1;
	const u_char  ioa2 = 0;
	type.qoi = 20;
	
	memcpy(buf, &ioa, sizeof(u_short));
	memcpy(buf + sizeof(u_short), &ioa2, sizeof(u_char));
	memcpy(buf + sizeof(u_short) + sizeof(u_char), &type, sizeof(struct iec_type100));
	*buflen += sizeof(u_short) + sizeof(u_char) + sizeof(struct iec_type100);
}

void iecasdu_create_type_101 (u_char *buf, size_t *buflen)
{
	struct iec_type101 type;
	u_short ioa  = 1;
	const u_char  ioa2 = 0;
	type.rqt = 5;
	type.frz = 0;
	
	memcpy(buf, &ioa, sizeof(u_short));
	memcpy(buf + sizeof(u_short), &ioa2, sizeof(u_char));
	memcpy(buf + sizeof(u_short) + sizeof(u_char), &type, sizeof(struct iec_type101));
	*buflen += sizeof(u_short) + sizeof(u_char) + sizeof(struct iec_type101);
}

void iecasdu_create_type_103 (u_char *buf, size_t *buflen)
{
	struct iec_type103 type;
	u_short ioa = 1;
	const u_char ioa2 = 0;
	current_cp56time2a(&type.time);
	
	memcpy(buf, &ioa, sizeof(u_short));
	memcpy(buf + sizeof(u_short), &ioa2, sizeof(u_char));
	memcpy(buf + sizeof(u_short) + sizeof(u_char), &type, sizeof(struct iec_type103));
	*buflen += sizeof(u_short) + sizeof(u_char) + sizeof(struct iec_type103);
	
}

void iecasdu_create_type_36 (u_char *buf, size_t *buflen, int num, float *mv) {
	struct iec_type36 type;
	struct cp56time2a tm;
	u_short ioa  = 1;
	const u_char  ioa2 = 0;
	int i;
	size_t len;

	current_cp56time2a(&tm);
	len = sizeof(u_short)+sizeof(u_char)+sizeof(struct iec_type36);
	
	for (i=0; i < num; i++, mv++, ioa++) {
		type.mv = *mv;
		type.ov = 0;
		type.res = 0;
		type.bl=0;
		type.sb=0;
		type.nt=0;
		type.iv=0;
		type.time = tm;
		
		memcpy(buf + len*i, &ioa, sizeof(u_short));
		memcpy(buf + len*i + sizeof(u_short), &ioa2, sizeof(u_char));
		memcpy(buf + len*i + sizeof(u_short) + sizeof(u_char), &type,
			sizeof(struct iec_type36));
		*buflen += len;
	}
}
