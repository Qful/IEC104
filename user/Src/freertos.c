/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  *
  * COPYRIGHT(c) 2015 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "queue.h"

#include "main.h"
#include "time.h"
#include "stdlib.h"
#include "string.h"

#include "ethernetif.h"
#include "lwip/tcpip.h"
#include "lwip/init.h"
#include "lwip/netif.h"
#include "lwip/api.h"
#include "lwip/sys.h"

// IEC 60870-5-104
#include "iec104.h"



/* Variables -----------------------------------------------------------------*/
osThreadId defaultTaskHandle;

struct netif 	first_gnetif,second_gnetif;
struct ip_addr 	first_ipaddr,second_ipaddr;
struct ip_addr 	netmask;
struct ip_addr 	gw;

struct iechooks default_hooks;
struct iecsock 	*s;

/* Function prototypes -------------------------------------------------------*/
void StartIEC104Task(void const * argument);
void StartLEDTask(void const * argument);

static int iec104_iframe_recv(struct netconn *newconn, struct iecsock *s, struct iec_buf *buf);
static int iec104_sframe_recv(struct iecsock *s, struct iec_buf *buf);
static int iec104_uframe_recv(struct netconn *newconn, struct iecsock *s, struct iec_buf *buf);

static void iec104_uframe_send(struct iecsock *s, enum uframe_func func);
static void iec104_sframe_send(struct iecsock *s);
void iec104_prepare_iframe(struct iec_buf *buf);

static inline enum frame_type frame104_type(struct iechdr *h);
static inline enum uframe_func uframe_func(struct iechdr *h);

static inline int check_nr(struct iecsock *s, unsigned short nr);
static inline int check_ns(struct iecsock *s, unsigned short ns);

void activation_hook(struct iecsock *s);
void connect_hook(struct iecsock *s);
void disconnect_hook(struct iecsock *s, short reason);
void data_received_hook(struct iecsock *s, struct iec_buf *b);

void iec104_set_options(struct iecsock *s, struct iecsock_options *opt);
static void iec104_set_defaults(struct iecsock *s);

void send_base_request(struct iecsock *s, void *arg);
void iec_send_frame(struct iecsock *s, u_char *buf, size_t *buflen);
void iec104_run_write_queue(struct iecsock *s);
size_t iec104_can_queue(struct iecsock *s);



//extern void MX_LWIP_Init(void);
//extern void tcpecho_init(void);
//extern void udpecho_init(void);

void FREERTOS_Init(void);


/* Hook prototypes */


/*************************************************************************
 * FREERTOS_Init
 *************************************************************************/
void FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(IEC104, StartIEC104Task, osPriorityNormal,0, 700);
  defaultTaskHandle = osThreadCreate(osThread(IEC104), NULL);

  osThreadDef(LED, StartLEDTask, osPriorityNormal,0, 128);
  defaultTaskHandle = osThreadCreate(osThread(LED), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
}

/*************************************************************************
 * StartIEC104Task
 *************************************************************************/
void StartIEC104Task(void const * argument)
{
 struct netconn *conn, *newconn;
 err_t err, accept_err;
 struct netbuf *buf;
 uint16_t len;
 uint8_t *data;
// uint8_t datTmp;

 struct iechdr *h;
 struct iec_buf *bufIEC;

 err_t reterror = ERR_OK;
 int ret = 0;

// struct iec_object obj[IEC_OBJECT_MAX];
// int ret, n;
// uint8_t cause, test, pn, *cp, t, str_ioa;
// u_short caddr;

//	MX_LWIP_Init();		// инит. LWIP

	tcpip_init( NULL, NULL );

	// устанавливаем IP параметры для первичного IP соединения, всегда сервер
	IP4_ADDR(&first_ipaddr, first_IP_ADDR0, first_IP_ADDR1, first_IP_ADDR2, first_IP_ADDR3);
	// устанавливаем IP параметры для вторичного IP соединения, всегда хост
	IP4_ADDR(&second_ipaddr, second_IP_ADDR0, second_IP_ADDR1, second_IP_ADDR2, second_IP_ADDR3);

	IP4_ADDR(&netmask, NETMASK_ADDR0, NETMASK_ADDR1 , NETMASK_ADDR2, NETMASK_ADDR3);
	IP4_ADDR(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);


	// добавим  и регистрируем NETWORK интерфейс
	netif_add(&first_gnetif, &first_ipaddr, &netmask, &gw, NULL, &ethernetif_init, &tcpip_input);
	netif_set_default(&first_gnetif);

	if (netif_is_link_up(&first_gnetif))
		netif_set_up(&first_gnetif);		// When the netif is fully configured this function must be called
	else
		netif_set_down(&first_gnetif);		// When the netif link is down this function must be called

	//dhcp_start(&first_gnetif);		// автоматическое получение IP


	default_hooks.disconnect_indication = disconnect_hook;						// disconnect_indication - called when link layer connection terminates.
	default_hooks.connect_indication = connect_hook;							// connect_indication - called when link layer connection is established.
	default_hooks.data_indication = data_received_hook;							// data_activation - called when ASDU was received, buf points to allocated structure. It is user responsibility to free allocated resources.
	default_hooks.activation_indication = activation_hook;						// activation_indication - called when monitor direction activates with  STARTACT/STARTCON S-frames.
//	default_hooks.deactivation_indication = deactivation_hook;					// deactivation_indication - called when monitor direction deactivates  with STOPACT/STOPCON S-frames.
//	default_hooks.transmit_wakeup = transmit_wakeup;							// transmit_wakeup - called when all frames from transmition queue were sent, acknowledged and iecsock can accept more.

	s = calloc(1, sizeof(struct iecsock));

	iec104_set_defaults(s);
	s->type = IEC_SLAVE;
	s->stopdt = 1;
  for(;;)
  {

	conn = netconn_new(NETCONN_TCP);											// создадим новое соединение
	  if (conn!=NULL){
		err = netconn_bind(conn, &first_ipaddr, IEC104_Port);					// привяжем соединение на IP и порт IEC 60870-5-104 (IEC104_Port)
	    if (err == ERR_OK)
	    {
	        netconn_listen(conn);												// переводим соединение в режим прослушивания
	        while (1)															// далее слушаем и  захватываем соединение
	        {
	             accept_err = netconn_accept(conn, &newconn);					// принимаем соединение
	             if (accept_err == ERR_OK)										// если приняли, то обработаем его
	             {
		        	 LED_On(LED2);
	                 while (netconn_recv(newconn, &buf) == ERR_OK)				// принимаем данные в буфер
	                 {
	                	 LED_On(LED1);
	                     do
	                     {
	                        netbuf_data(buf,(void *)&data, &len);					// указатель получил адрес вх. данных
	                   	    h = (struct iechdr *) &data[0];

	                   	    bufIEC = calloc(1,len + sizeof(struct iec_buf) - sizeof(struct iechdr));		// выделяем блок памяти для массива
// TODO: запустить таймер
	                   		//t3_timer_stop(s);
	                   		//t3_timer_start(s);

	                   		memcpy(&s->buf[0], h, len);
	                   		memcpy(&bufIEC->h, h, len);
	                   		s->len = len;

							switch (frame104_type(h)) {

								case FRAME_TYPE_I:
									if (s->type == IEC_SLAVE && s->stopdt) {
										free(buf);
										break;
									}
									ret = iec104_iframe_recv(newconn, s, bufIEC);
								break;

								case FRAME_TYPE_S:
									ret = iec104_sframe_recv(s, bufIEC);
									free(bufIEC);
								break;

								case FRAME_TYPE_U:
									ret = iec104_uframe_recv(newconn, s, bufIEC);
									free(bufIEC);
								break;

							}

//	                       netconn_write(newconn, data, len, NETCONN_COPY);		// отправляем данные по протоколу TCP
	//                 	   printf("%d\n",len);
	                     }
	                     while (netbuf_next(buf) >= 0);
	                     netbuf_delete(buf);
	  		           LED_Off(LED1);
	                 }
	                 netconn_close(newconn);									// закрываем и освобождаем соединение
	                 netconn_delete(newconn);
		           LED_Off(LED2);
	             }
	        }
	    }
	    else      netconn_delete(newconn);
	  }
//    osDelay(1);
  }

}
/*************************************************************************
 * StartLEDTask
 *************************************************************************/
void StartLEDTask(void const * argument)
{


	  for(;;)
	  {
      	LED_Toggle(LED4);
      	osDelay(500);
	  }
}

/*************************************************************************
 * iecsock_iframe_recv
 *************************************************************************/
static int iec104_iframe_recv(struct netconn *newconn, struct iecsock *s, struct iec_buf *buf)
{
	struct iechdr *h;
	h = &buf->h;
	buf->data_len = h->length - 2;			// дополним реальным размером ASDU

	if (!check_nr(s, h->ic.nr))	return -1;	// проверим принимаемый порядковый номер

	s->va = h->ic.nr;
	if (s->va == s->vs) {
// TODO: таймера нужно починить.
	//	t1_timer_stop(s);					// таймаут при посылке или тестировании APDU.
	//if (s->hooks.transmit_wakeup)				s->hooks.transmit_wakeup(s);					// пока нету передачи пробуждения
	//else if (default_hooks.transmit_wakeup)		default_hooks.transmit_wakeup(s);
	}
// TODO: таймера нужно починить.
	//t2_timer_stop(s);						// таймаут подтверждения.
	//t2_timer_start(s);

	if (!check_ns(s, h->ic.ns)) return -1;	// проверим передаваемый порядковый номер

	s->vr = (s->vr + 1) % 32767;
	if ((s->vr - s->va_peer + 32767) % 32767 == s->w) {			// отошлем Sframe

		h->start = 0x68;
		h->length = sizeof(struct iec_s);
		h->sc.res1 = 0;
		h->sc.res2 = 0;
		h->sc.ft = 1;
		h->sc.nr = s->vr;
	    netconn_write(newconn, h, sizeof(struct iechdr), NETCONN_COPY);

		s->xmit_cnt++;
		s->va_peer = s->vr;
	}

	if (s->hooks.data_indication)				s->hooks.data_indication(s, buf);			//расшифровываем ASDU
	else if (default_hooks.data_indication)		default_hooks.data_indication(s, buf);
	else free(buf);

	return 0;
}
/*************************************************************************
 * iecsock_sframe_recv
 *************************************************************************/
static int iec104_sframe_recv(struct iecsock *s, struct iec_buf *buf)
{
	struct iec_buf *b, *tmp;

	struct iechdr *h;
	h = &buf->h;
	buf->data_len = h->length - 2;

	if (!check_nr(s, h->ic.nr))	return -1;

//TODO: разобраться с этим, что она делает
//	iecsock_run_ackw_queue(s, h->ic.nr);

	s->va = h->ic.nr;
	if (s->va == s->vs) {
// TODO: таймера нужно починить.
		//t1_timer_stop(s);																	// таймаут при посылке или тестировании APDU.
		//if (s->hooks.transmit_wakeup)				s->hooks.transmit_wakeup(s);			// пока нету передачи пробуждения
		//else if (default_hooks.transmit_wakeup)		default_hooks.transmit_wakeup(s);
	}

	return 0;
}
/*************************************************************************
 * iecsock_uframe_recv
 *************************************************************************/
static int iec104_uframe_recv(struct netconn *newconn, struct iecsock *s, struct iec_buf *buf)
{
	struct iechdr *h;
	h = &buf->h;

	switch(uframe_func(h)) {
		case STARTACT:
			if (s->type != IEC_SLAVE)	return -1;

			s->stopdt = 0;
			h->start = 0x68;
			h->length = sizeof(struct iec_u);
			h->uc.res1 = 0;
			h->uc.res2 = 0;
			h->uc.ft = 3;
			h->uc.start_act = 0;
			h->uc.start_con = 1;

		    netconn_write(newconn, h, sizeof(struct iechdr), NETCONN_COPY);
			s->xmit_cnt++;

// TODO: разобраться с iecsock_run_write_queue что она делает.
			//iecsock_run_write_queue(s);

			// принимаеи и парсим данные для дальнейшей обработки
			if (s->hooks.activation_indication)					s->hooks.activation_indication(s);
			else if (default_hooks.activation_indication)		default_hooks.activation_indication(s);

		break;
		case STARTCON:
			if (s->type != IEC_MASTER)	return -1;
// TODO: таймера нужно починить.
			//t1_timer_stop(s);
			s->stopdt = 0;

			if (s->hooks.activation_indication)					s->hooks.activation_indication(s);
			else if (default_hooks.activation_indication)		default_hooks.activation_indication(s);

		break;
		case STOPACT:
			if (s->type != IEC_SLAVE)	return -1;

			s->stopdt = 1;

			h->start = 0x68;
			h->length = sizeof(struct iec_u);
			h->uc.res1 = 0;
			h->uc.res2 = 0;
			h->uc.ft = 3;
			h->uc.stop_act = 0;
			h->uc.stop_con = 1;

		    netconn_write(newconn, h, sizeof(struct iechdr), NETCONN_COPY);
			s->xmit_cnt++;

			if (s->hooks.activation_indication)					s->hooks.activation_indication(s);
			else if (default_hooks.activation_indication)		default_hooks.activation_indication(s);

		break;
		case STOPCON:
			if (s->type != IEC_MASTER)	return -1;

			s->stopdt = 1;

			if (s->hooks.activation_indication)					s->hooks.activation_indication(s);
			else if (default_hooks.activation_indication)		default_hooks.activation_indication(s);

		break;
		case TESTACT:
			h->start = 0x68;
			h->length = sizeof(struct iec_u);
			h->uc.res1 = 0;
			h->uc.res2 = 0;
			h->uc.ft = 3;
			h->uc.test_act = 0;
			h->uc.test_con = 1;

		    netconn_write(newconn, h, sizeof(struct iechdr), NETCONN_COPY);
			s->xmit_cnt++;

			/* SLAVE must not send TESTFR while recieving them from MASTER */
			if (s->type == IEC_SLAVE && !s->testfr){
// TODO: таймера нужно починить.
			//t3_timer_stop(s);
			}
		break;
		case TESTCON:
			if (!s->testfr)		return -1;
// TODO: таймера нужно починить.
			//t1_timer_stop(s);
			s->testfr = 0;

		break;
	}
	return 0;
}
/*************************************************************************
 * iecsock_uframe_send
 *************************************************************************/
static void iec104_uframe_send(struct iecsock *s, enum uframe_func func)
{
	struct iechdr h;
	memset(&h, 0, sizeof(struct iechdr));

	h.start = 0x68;
	h.length = sizeof(struct iec_u);
	h.uc.ft = 3;

	if (func == STARTACT)			h.uc.start_act = 1;
	else if (func == STARTCON)		h.uc.start_con = 1;
	else if (func == STOPACT)		h.uc.stop_act = 1;
	else if (func == STOPCON)		h.uc.stop_con = 1;
	else if (func == TESTACT)		h.uc.test_act = 1;
	else if (func == TESTCON)		h.uc.test_con = 1;

//	bufferevent_write(s->io, &h, sizeof(h));
	s->xmit_cnt++;
}
/*************************************************************************
 * iecsock_sframe_send
 *************************************************************************/
static void iec104_sframe_send(struct iecsock *s)
{
	struct iechdr h;
	memset(&h, 0, sizeof(h));

//	printf("TX S N(r)=%i", s->vr);					// дебаг мод.

	h.start = 0x68;
	h.length = sizeof(struct iec_s);
	h.sc.ft = 1;
	h.sc.nr = s->vr;
//    netconn_write(newconn, &h, sizeof(h), NETCONN_COPY);		// отправляем данные по протоколу TCP
	s->xmit_cnt++;
}
/*************************************************************************
 * iecsock_prepare_iframe
 *************************************************************************/
void iec104_prepare_iframe(struct iec_buf *buf)
{
	struct iechdr *h;

	h = &buf->h;
	h->start = 0x68;
	h->length = buf->data_len + sizeof(struct iec_i);

	h->ic.res = 0;
	h->ic.ns = 0;
	h->ic.nr = 0;

	h->ic.ft = 0;

}
/*************************************************************************
 * frame104_type
 *************************************************************************/
static inline enum frame_type frame104_type(struct iechdr *h)
{
	if (!(h->raw[0] & 0x1))			return FRAME_TYPE_I;
	else if (!(h->raw[0] & 0x2))	return FRAME_TYPE_S;
	else							return FRAME_TYPE_U;
}
/*************************************************************************
 * uframe_func
 *************************************************************************/
static inline enum uframe_func uframe_func(struct iechdr *h)
{
	if (h->raw[0] & 0x4)			return STARTACT;
	else if (h->raw[0] & 0x8)		return STARTCON;
	else if (h->raw[0] & 0x10)		return STOPACT;
	else if (h->raw[0] & 0x20)		return STOPCON;
	else if (h->raw[0] & 0x40)		return TESTACT;
	else							return TESTCON;
}
/*************************************************************************
 * check_nr
 * Проверка порядкового номера принятого блока.
 *************************************************************************/
static inline int check_nr(struct iecsock *s, unsigned short nr)
{
	return ((nr - s->va + 32767) % 32767 <= (s->vs - s->va + 32767) % 32767);
}
/*************************************************************************
 * check_ns
 * Проверка порядкового номера передаваемого блока.
 *************************************************************************/
static inline int check_ns(struct iecsock *s, unsigned short ns)
{
	return (ns == s->vr);
}
/*************************************************************************
 * activation_hook
 *************************************************************************/
void activation_hook(struct iecsock *s)
{
//	struct timeval tv;
//	tv.tv_sec  = 1;
//	tv.tv_usec = 0;

/*	iecsock_user_timer_set(s, timer_send_frame, NULL); */
	send_base_request(s,NULL);

}
/*************************************************************************
 * send_base_request
 *************************************************************************/
void send_base_request(struct iecsock *s, void *arg)
{
/*	struct timeval tv; */
	u_char *buf;
	size_t buflen = 0;

	buf = calloc(1,sizeof(struct iec_buf) + 249);
	if (!buf)	return;

//	iecasdu_create_header(buf, &buflen, C_IC_NA_1, 1, ACTIVATION, ASDU_ADDR);
	iecasdu_create_type_100(buf + buflen, &buflen);
	iec_send_frame(s,buf,&buflen);

/*	tv.tv_sec = 0;
	tv.tv_usec = 1000;
	iecsock_user_timer_start(s, &tv); */
}
/*************************************************************************
 * iec_send_frame
 *************************************************************************/
void iec_send_frame(struct iecsock *s, u_char *buf, size_t *buflen){

	struct iec_buf *b;

	if (! iec104_can_queue(s))	return;

	b = calloc(1, sizeof(struct iec_buf) + *buflen);
	if (!b)	return;

	b->data_len = *buflen;

	memcpy(b->data, buf, *buflen );

	iec104_prepare_iframe(b);

//TODO:   TAILQ_INSERT_TAIL ?????
//	TAILQ_INSERT_TAIL(&s->write_q, b, head);
//	fprintf(stderr, "packet added to queue\n");

	iec104_run_write_queue(s);
}
/*************************************************************************
 * iec104_run_write_queue
 *************************************************************************/
void iec104_run_write_queue(struct iecsock *s)
{
	struct iechdr *h;
	struct iec_buf *b;

	if (s->type == IEC_SLAVE && s->stopdt)	return;

	h = &b->h;
	h->ic.res = 0;
	h->ic.nr = s->vr;
	h->ic.ns = s->vs;

	//if (t1_timer_pending(s))	t1_timer_stop(s);
	//t1_timer_start(s);

  //  netconn_write(newconn, h, sizeof(struct iechdr), NETCONN_COPY);

	s->vs = (s->vs + 1) % 32767;
	s->xmit_cnt++;

/*
	while ( !(TAILQ_EMPTY(&s->write_q)) && (s->vs != (s->va + s->k) % 32767) ) {

		b = TAILQ_FIRST(&s->write_q);
		TAILQ_REMOVE(&s->write_q, b, head);

		h = &b->h;
		h->ic.nr = s->vr;
		h->ic.ns = s->vs;

		if (t1_timer_pending(s))	t1_timer_stop(s);
		t1_timer_start(s);

		bufferevent_write(s->io, h, h->length + 2);
		TAILQ_INSERT_TAIL(&s->ackw_q, b, head);

		s->vs = (s->vs + 1) % 32767;
		s->xmit_cnt++;
	}
*/
}
/*************************************************************************
 * iec104_can_queue
 *************************************************************************/
size_t iec104_can_queue(struct iecsock *s)
{
	return (s->k - ((s->vs - s->va + 32767) % 32767));
}
/*************************************************************************
 * connect_hook
 *************************************************************************/
void connect_hook(struct iecsock *s)
{
	struct iecsock_options opt;
	opt.w	= 1;
	opt.k	= 3;
	opt.t0	= 30;
	opt.t1  = 15;
	opt.t2  = 10;
	opt.t3  = 20;
	iec104_set_options(s,&opt);

//	printf(stderr, "%s: Sucess 0x%lu\n", __FUNCTION__, (unsigned long) s);

}
/*************************************************************************
 * disconnect_hook
 *************************************************************************/
void disconnect_hook(struct iecsock *s, short reason)
{
	//fprintf(stderr, "%s: what=0x%02x\n", __FUNCTION__, reason);
	return;
}
/*************************************************************************
 * data_received_hook
 *************************************************************************/
void data_received_hook(struct iecsock *s, struct iec_buf *b)
{

	struct iec_object obj[IEC_OBJECT_MAX];
	int ret, n, i;
	u_short caddr;
	u_char cause, test, pn, t, str_ioa;

	// парсим содержимое ASDU
   ret = iecasdu_parse(obj, &t, &caddr, &n, &cause, &test, &pn, &str_ioa, b->data, b->data_len);
   if (!ret){
	   switch(t) {
		   case M_SP_NA_1: /* 1 */

						   break;
		   case C_IC_NA_1: /* 100 */

						   break;
		   case C_CI_NA_1: /* 101 */

						   break;
		   case C_CS_NA_1: /* 103 */

						   break;
	   }
   }

}
/*************************************************************************
 * iecsock_set_options
 *************************************************************************/
void iec104_set_options(struct iecsock *s, struct iecsock_options *opt)
{
	s->t0 = opt->t0;
	s->t1 = opt->t1;
	s->t2 = opt->t2;
	s->t3 = opt->t3;
	s->w = opt->w;
	s->k = opt->k;
}
/*************************************************************************
 * iecsock_set_defaults
 *************************************************************************/
static void iec104_set_defaults(struct iecsock *s)
{
	s->t0	= DEFAULT_T0;
	s->t1	= DEFAULT_T1;
	s->t2	= DEFAULT_T2;
	s->t3	= DEFAULT_T3;
	s->w 	= DEFAULT_W;
	s->k	= DEFAULT_K;
//	TAILQ_INIT(&s->write_q);
//	TAILQ_INIT(&s->ackw_q);
//	evtimer_set(&s->t1_timer, t1_timer_run, s);
//	evtimer_set(&s->t2_timer, t2_timer_run, s);
//	evtimer_set(&s->t3_timer, t3_timer_run, s);
}
/*
Макрос TAILQ_ENTRY объявляет структуру, связывающую элементы в хвостовой очереди.
Макрос TAILQ_INIT инициализирует хвостовую очередь, на которую ссылается Fa head .
Макрос TAILQ_INSERT_HEAD вставляет новый элемент Fa elm в начало хвостовой очереди.
Макрос TAILQ_INSERT_TAIL вставляет новый элемент Fa elm в конец хвостовой очереди.
Макрос TAILQ_INSERT_AFTER вставляет новый элемент Fa elm после элемента Fa listelm .
Макрос TAILQ_REMOVE удаляет элемент Fa elm из хвостовой очереди.
*/
