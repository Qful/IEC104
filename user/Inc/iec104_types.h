/*
 * iec104_type.h
 *
 *  Created on: 25.06.2015
 *      Author: sagok
 */

#ifndef __IEC104_TYPES_H
#define __IEC104_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif
 
#define M_SP_NA_1	1
#define M_BO_NA_1	7
#define M_ME_NA_1	9
#define M_ME_NB_1	11
#define M_ME_NC_1	13
#define M_SP_TB_1	30
#define M_BO_TB_1	33
#define M_ME_TD_1	34
#define M_ME_TE_1	35
#define M_ME_TF_1	36
#define	M_IT_TB_1	37
#define C_IC_NA_1	100
#define C_CI_NA_1	101
#define C_CS_NA_1	103

/* cause of transmition (standard) */
#define	CYCLIC		1
#define BGSCAN		2
#define SPONTANEOUS	3
#define REQUEST		5
#define ACTIVATION	6
#define ACTCONFIRM	7
#define DEACTIVATION	8
#define ACTTERM		10

/* 32-bit string state and change data unit */
struct iec_stcd {
	u_short		st[0];
	u_char		st1	:1;
	u_char		st2	:1;
	u_char		st3	:1;
	u_char		st4	:1;
	u_char		st5	:1;
	u_char		st6	:1;
	u_char		st7	:1;
	u_char		st8	:1;
	u_char		st9	:1;
	u_char		st10	:1;
	u_char		st11	:1;
	u_char		st12	:1;
	u_char		st13	:1;
	u_char		st14	:1;
	u_char		st15	:1;
	u_char		st16	:1;
	u_short		cd[0];
	u_char		cd1	:1;
	u_char		cd2	:1;
	u_char		cd3	:1;
	u_char		cd4	:1;
	u_char		cd5	:1;
	u_char		cd6	:1;
	u_char		cd7	:1;
	u_char		cd8	:1;
	u_char		cd9	:1;
	u_char		cd10	:1;
	u_char		cd11	:1;
	u_char		cd12	:1;
	u_char		cd13	:1;
	u_char		cd14	:1;
	u_char		cd15	:1;
	u_char		cd16	:1;
}__attribute__((__packed__));

/* CP56Time2a timestamp */
struct cp56time2a {
	u_short		msec;
	u_char		min		:6;
	u_char		res1	:1;
	u_char		iv		:1;
	u_char		hour	:5;
	u_char		res2	:2;
	u_char		su		:1;
	u_char		mday	:5;
	u_char		wday	:3;
	u_char		month	:4;
	u_char		res3	:4;
	u_char		year	:7;
	u_char		res4	:1;	
} __attribute__((__packed__));

typedef struct cp56time2a cp56time2a;

/* M_SP_NA_1 - single point information with quality description */
struct iec_type1 {
	u_char		sp	:1; /* single point information */
	u_char		res	:3;
	u_char		bl	:1; /* <блокировка/нет блокировки - значение блокировано для передачи, остаётся в состоянии которое было до блокировки*/
	u_char		sb	:1; /* замещение/нет замещения - значение поступает или от диспетчера или от автоматического источника*/
	u_char		nt	:1; /* неактуальное/актуальное - Актуально если большенство опросов успешно. Неактуально, если не обновлялось или было недоступно*/
	u_char		iv	:1; /* действительное/не действительное - действ. если правильно получено. Недейств. используется для указания получателю, что значение не правильное или нельзя пользоваться*/
} __attribute__((__packed__));

/* M_BO_NA_1 - state and change information bit string */
struct iec_type7 {
	struct iec_stcd	stcd;
	u_char		ov	:1; /* переполнение/нет переполнения */
	u_char		res	:3;
	u_char		bl	:1; /* блокировка/нет блокировки */
	u_char		sb	:1; /* замещение/нет замещения */
	u_char		nt	:1; /* неактуальное/актуальное */
	u_char		iv	:1; /* действительное/не действительное */
}__attribute__((__packed__));

/* M_ME_NA_1 - normalized measured value */
struct iec_type9 {
	u_short		mv;	/* normalized value */
	u_char		ov	:1; /* переполнение/нет переполнения */
	u_char		res	:3;
	u_char		bl	:1; /* блокировка/нет блокировки */
	u_char		sb	:1; /* замещение/нет замещения */
	u_char		nt	:1; /* неактуальное/актуальное */
	u_char		iv	:1; /* действительное/не действительное */
}__attribute__((__packed__));

/* M_ME_NB_1 - scaled measured value */
struct iec_type11 {
	u_short		mv;	/* scaled value */
	u_char		ov	:1; /* переполнение/нет переполнения */
	u_char		res	:3;
	u_char		bl	:1; /* блокировка/нет блокировки */
	u_char		sb	:1; /* замещение/нет замещения */
	u_char		nt	:1; /* неактуальное/актуальное */
	u_char		iv	:1; /* действительное/не действительное */
}__attribute__((__packed__));

/* M_ME_NC_1 - short floating point measured value */
struct iec_type13 {
	float		mv;
	u_char		ov	:1; /* переполнение/нет переполнения */
	u_char		res	:3;
	u_char		bl	:1; /* блокировка/нет блокировки */
	u_char		sb	:1; /* замещение/нет замещения */
	u_char		nt	:1; /* неактуальное/актуальное */
	u_char		iv	:1; /* действительное/не действительное */
}__attribute__((__packed__));

/* M_SP_TB_1 - single point information with quality description and time tag */
struct iec_type30 {
	u_char		sp	:1; /* single point information */
	u_char		res	:3;
	u_char		bl	:1; /* блокировка/нет блокировки */
	u_char		sb	:1; /* замещение/нет замещения */
	u_char		nt	:1; /* неактуальное/актуальное */
	u_char		iv	:1; /* действительное/не действительное */
	cp56time2a	time;
} __attribute__((__packed__));

/* M_BO_TB_1 - state and change information bit string and time tag  */
struct iec_type33 {
	struct iec_stcd	stcd;
	u_char		ov	:1; /* переполнение/нет переполнения */
	u_char		res	:3;
	u_char		bl	:1; /* блокировка/нет блокировки */
	u_char		sb	:1; /* замещение/нет замещения */
	u_char		nt	:1; /* неактуальное/актуальное */
	u_char		iv	:1; /* действительное/не действительное */
	cp56time2a	time;
}__attribute__((__packed__));

/* M_ME_TD_1 - scaled measured value with time tag */
struct iec_type34 {
	u_short		mv;	/* scaled value */
	u_char		ov	:1; /* переполнение/нет переполнения */
	u_char		res	:3;
	u_char		bl	:1; /* блокировка/нет блокировки */
	u_char		sb	:1; /* замещение/нет замещения */
	u_char		nt	:1; /* неактуальное/актуальное */
	u_char		iv	:1; /* действительное/не действительное */
	cp56time2a	time;
}__attribute__((__packed__));

/* M_ME_TE_1 - scaled measured value with time tag*/
struct iec_type35 {
	u_short		mv;	/* scaled value */
	u_char		ov	:1; /* переполнение/нет переполнения */
	u_char		res	:3;
	u_char		bl	:1; /* блокировка/нет блокировки */
	u_char		sb	:1; /* замещение/нет замещения */
	u_char		nt	:1; /* неактуальное/актуальное */
	u_char		iv	:1; /*  действительное/не действительное */
	cp56time2a	time;
}__attribute__((__packed__));

/* M_ME_TF_1 - short floating point measurement value and time tag */
struct iec_type36 {
	float		mv;
	u_char		ov	:1; /* переполнение/нет переполнения */
	u_char		res	:3;
	u_char		bl	:1; /* блокировка/нет блокировки */
	u_char		sb	:1; /* замещение/нет замещения */
	u_char		nt	:1; /* неактуальное/актуальное */
	u_char		iv	:1; /*  действительное/не действительное */
	cp56time2a	time;
}__attribute__((__packed__));

/* M_IT_TB_1 */
struct iec_type37 {
	int32_t		bcr;
	u_char		sq	:5;
	u_char		cy	:1;
	u_char		ca	:1;
	u_char		iv	:1;
	cp56time2a	time;
}__attribute__((__packed__));

struct iec_type100 {
	u_char		qoi;	/* pointer of interrogation */
}__attribute__((__packed__));

struct iec_type101 {
	u_char		rqt	:6; /* request */
	u_char		frz	:2; /* freeze  */
}__attribute__((__packed__));

struct iec_type103 {
	cp56time2a	time;
}__attribute__((__packed__));

/* Data unit identifier block - ASDU header */
struct iec_unit_id {
	u_char		type;	/* type identification - идентификатор типа*/
	u_char		num		:7; /* number of information objects - классификатор переменной структуры (0-ASDU не содержит информацииб 1..127 - число объектов )*/
	u_char		sq		:1; /* sequenced/not sequenced address - последовательность или одиночный */
	u_char		cause	:6; /* cause of transmission  - причина передачи*/
	u_char		t		:1; /* test - */
	u_char		pn		:1; /* positive/negative app. confirmation - положительное или отрицательное подтверждение активации */
	u_char		ma;		/* master address - общий адрес*/
	u_short		ca;		/* common address of ASDU  - адрес объекта*/
}__attribute__((__packed__));

#ifdef __cplusplus
}
#endif

#endif	/* __IEC104_TYPES_H */
