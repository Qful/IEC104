/*
 * iec104.h
 *
 *  Created on: 25.06.2015
 *      Author: sagok
 */

#ifndef __IEC104_H
#define __IEC104_H

#ifndef __IEC104_TYPES_H
#include "iec104_types.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


#define IEC_OBJECT_MAX		127
#define IEC_TYPEID_LEN		3
#define IEC104_BUF_LEN		255

#define DEFAULT_W	8
#define DEFAULT_K	12
#define DEFAULT_T0	30
#define DEFAULT_T1	15
#define DEFAULT_T2	10
#define DEFAULT_T3	20
#define IEC_APDU_MAX	253
#define IEC_APDU_MIN	4

enum {
	IEC_SLAVE,
	IEC_MASTER
};

enum frame_type {
	FRAME_TYPE_I,
	FRAME_TYPE_S,
	FRAME_TYPE_U
};

/* Information object */
struct iec_object {
	u_short		ioa;	/* information object address */
	u_char		ioa2;	/* information object address */
	union {
		struct iec_type1	type1;			//M_SP_NA_1 - одноэлементная информация
		struct iec_type7	type7;			//M_BO_NA_1 - строка из 32 бит
		struct iec_type9	type9;			//M_ME_NA_1 - значение измеряемой величины, нормализованное значение
		struct iec_type11	type11;			//M_ME_NB_1 - значение измеряемой величины, масштабированное значение
		struct iec_type13	type13;			//M_ME_NC_1 - значение измеряемой величины, короткий формат с плав.запят.
		struct iec_type30	type30;			//M_SP_TB_1 - одноэлементная информация с меткой времени CP56Time2a
		struct iec_type33	type33;			//M_BO_TB_1 - строка из 32 бит с меткой времени CP56Time2a
		struct iec_type34	type34;			//M_ME_TD_1 - значение измеряемой величины, нормализованное значение с меткой времени CP56Time2a
		struct iec_type35	type35;			//M_ME_TE_1 - значение измеряемой величины, масштабированное значение с меткой времени CP56Time2a
		struct iec_type36	type36;			//M_ME_TF_1 - значение измеряемой величины, короткий формат с плав.запят. с меткой времени CP56Time2a
		struct iec_type37	type37;			//M_IT_TB_1 - интегральная сумма с меткой времени CP56Time2a
		struct iec_type100	type100;		//C_IC_NA_1 - команда опроса
		struct iec_type101	type101;		//C_CI_NA_1 - команда опроса счетчика
		struct iec_type103	type103;		//C_CS_NA_1 - команда синхронизации времени
	} o;	
}__attribute__((__packed__));


struct iec_buf {
//	TAILQ_ENTRY(iec_buf) head;
	u_char	data_len;	/* actual ASDU length */

	// ----- APCI -----------------------------
	struct iechdr {
		u_char	start;
		u_char	length;
		u_char	raw[0];
		union {
			struct iec_i {
				u_char	ft:1;
				u_short	ns:15;
				u_char	res:1;
				u_short	nr:15;
			} ic;
			struct iec_s {
				u_char	ft:1;
				u_short	res1:15;
				u_char	res2:1;
				u_short	nr:15;
			} sc;
			struct iec_u {
				u_char	ft:2;
				u_char	start_act:1;
				u_char	start_con:1;
				u_char	stop_act:1;
				u_char	stop_con:1;
				u_char	test_act:1;
				u_char	test_con:1;
				u_char	res1;
				u_short	res2;
			} uc;
		};
	} h;
	//! ----- APCI -----------------------------

	u_char	data[0];
} __attribute__((__packed__));

struct iecsock;

struct iechooks {
	void (*connect_indication)(struct iecsock *s);
	void (*activation_indication)(struct iecsock *s);
	void (*deactivation_indication)(struct iecsock *s);
	void (*disconnect_indication)(struct iecsock *s, short reason);
	void (*data_indication)(struct iecsock *s, struct iec_buf *b);
	void (*transmit_wakeup)(struct iecsock *s);
};

extern struct iechooks default_hooks;


struct iecsock {
	int					sock;						/* socket descriptor */
	uint8_t				buf[IEC104_BUF_LEN];
	uint16_t			len;
	uint8_t				left;
	uint8_t				type;
	uint8_t				stopdt:1;					/* monitor direction 0=active 1=inactive */
	uint8_t				testfr:1;					/* test function 1=active 0=inactive */
	u_short				w, k;						// w - число кадров без подтверждения
													// k - число принятых без получения подтверждения
													// внутренние счетчики:
	u_short				va, vr, vs, va_peer;		// va - число правильно APDU (I) фармата.
													// vr - переменная состояния приема.
													// vs - переменная состояния передачи.
													// va_peer -

	u_short				t0, t1, t2, t3;				// t0 - таймаут при установлении соединения.
													// t1 - таймаут при посылке или тестировании APDU.
													// t2 - таймаут подтверждения.
													// t3 - таймаут для посылки блоков тестирования в случае долгого простоя.
//	struct event		t0_timer;
//	struct event		t1_timer;
//	struct event		t2_timer;
//	struct event		t3_timer;
//	struct sockaddr_in 	addr;	/* socket address */
//	struct bufferevent *io;
//	struct iec_buf_queue write_q;	/* write queue */
//	struct iec_buf_queue ackw_q;	/* acknowledge wait queue */

	struct iechooks 	hooks;
//	struct event 		user;
//	void	(*usercb)(struct iecsock *s, void *arg);
//	void	*userarg;
	u_long 				recv_cnt, xmit_cnt;
};

enum uframe_func {
	STARTACT,
	STARTCON,
	STOPACT,
	STOPCON,
	TESTACT,
	TESTCON
};

struct iecsock_options {
	u_short		w;
	u_short		k;
	u_short		t0;
	u_short		t1;
	u_short		t2;
	u_short		t3;
};

int iecasdu_parse(struct iec_object *obj, u_char *type, u_short *com_addr, 
	int *cnt, u_char *cause, u_char *test, u_char *pn, u_char *str_ioa,
	u_char *buf, size_t buflen);

/*
 * New functions
 */
void time_t_to_cp56time2a (cp56time2a *tm, time_t *timet);
void current_cp56time2a (cp56time2a *tm);
time_t cp56time2a_to_tm (cp56time2a *tm);

void iecasdu_create_header_all (u_char *buf, size_t *buflen, u_char type, u_char num,
	u_char sq, u_char cause, u_char t, u_char pn, u_char ma, u_short ca );

#define iecasdu_create_header(buf, buflen, type, num, cause, ca) \
	iecasdu_create_header_all(buf, buflen, type, num, 0, cause, 0, 0, 0, ca);

void iecasdu_create_type_36 (u_char *buf, size_t *buflen, int num, float *mv);
void iecasdu_create_type_100 (u_char *buf, size_t *buflen);
void iecasdu_create_type_101 (u_char *buf, size_t *buflen);
void iecasdu_create_type_103 (u_char *buf, size_t *buflen);

/* end of New functions */

#ifdef __cplusplus
}
#endif

#endif	/* __IEC104_H */
