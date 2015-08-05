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
#define M_DP_NA_1	3
#define M_ST_NA_1	5
#define M_BO_NA_1	7
#define M_ME_NA_1	9
#define M_ME_NB_1	11
#define M_ME_NC_1	13
#define	M_IT_NA_1	15
#define M_SP_TB_1	30
#define M_DP_TB_1	31
#define M_ST_TB_1	32
#define M_BO_TB_1	33
#define M_ME_TD_1	34
#define M_ME_TE_1	35
#define M_ME_TF_1	36
#define	M_IT_TB_1	37
#define	M_EP_TD_1	38
#define	M_EP_TE_1	39
#define	M_EP_TF_1	40

#define C_IC_NA_1	100
#define C_CI_NA_1	101
#define C_RD_NA_1	102
#define C_CS_NA_1	103
//#define C_TS_NA_1	104
#define C_RP_NA_1	105
#define C_TS_TA_1	107


/* cause of transmition (standard) */
#define	CYCLIC			1
#define BGSCAN			2
#define SPONTANEOUS		3
#define REQUEST			5
#define ACTIVATION		6
#define ACTCONFIRM		7
#define DEACTIVATION	8
#define ACTTERM			10

/* ASDU header (full version) */
#define TEST			1
#define NOTTEST			0
#define SINGLE			0
#define SERIAL			1

#define ACTIVATIONOK 	0
#define NOTACTIVATION 	1

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


struct iec_type3 {
} __attribute__((__packed__));

struct iec_type5 {
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

struct iec_type15 {
} __attribute__((__packed__));


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

struct iec_type31 {
} __attribute__((__packed__));

struct iec_type32 {
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

struct iec_type38 {
} __attribute__((__packed__));

struct iec_type39 {
} __attribute__((__packed__));

struct iec_type40 {
} __attribute__((__packed__));


struct iec_type100 {
	u_char		qoi;	/* pointer of interrogation */	//
}__attribute__((__packed__));

struct iec_type101 {
	u_char		rqt	:6; /* request */
	u_char		frz	:2; /* freeze  */
}__attribute__((__packed__));

struct iec_type102 {	// команда чтения
}__attribute__((__packed__));

struct iec_type103 {
	cp56time2a	time;
}__attribute__((__packed__));

//TODO: iec_type104, iec_type105, iec_type107
struct iec_type104 {
	u_char		res;
}__attribute__((__packed__));

struct iec_type105 {
	u_char		res;
}__attribute__((__packed__));

struct iec_type107 {
	u_char		res;
}__attribute__((__packed__));

/* Data unit identifier block - ASDU header */
struct iec_unit_id {
	uint8_t		type;			/* type identification - идентификатор типа*/
	uint8_t		num		:7; 	/* number of information objects - (0-ASDU не содержит информацииб 1..127 - число объектов )*/
	uint8_t		sq		:1; 	/* sequenced/not sequenced address - классификатор переменной структуры - последовательность или одиночный */

	uint8_t		cause	:6; 	/* cause of transmission  - причина передачи 1 байта*/
	uint8_t		pn		:1; 	/* positive/negative app. confirmation - положительное или отрицательное подтверждение активации */
	uint8_t		t		:1; 	/* test - */

	uint8_t		initaddr ; 	/* инициирующий адрес 1 байт*/

	uint16_t	ma;				/* master address - общий адрес 2 байта*/
	uint32_t	ca		:24;		/* common address of ASDU  - адрес объекта 3 байта*/
}__attribute__((__packed__));

#ifdef __cplusplus
}
#endif

#endif	/* __IEC104_TYPES_H */
