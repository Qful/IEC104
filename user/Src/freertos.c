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

uint8_t sentTEST = 0;				// временно, удалить потом.
u_short nm1;						// временно, удалить потом.

osThreadId defaultTaskHandle;

extern RTC_HandleTypeDef hrtc;
extern RTC_TimeTypeDef sTime;
extern RTC_DateTypeDef sDate;



struct netconn *conn, *newconn;

struct netif 	first_gnetif,second_gnetif;
struct ip_addr 	first_ipaddr,second_ipaddr;
struct ip_addr 	netmask;
struct ip_addr 	gw;

struct iechooks default_hooks;
struct iecsock 	*s;

uint8_t *outbuf;
size_t  outbufLen;

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
  osThreadDef(IEC104, StartIEC104Task, osPriorityNormal,0, 700);//700
  defaultTaskHandle = osThreadCreate(osThread(IEC104), NULL);

  osThreadDef(LED, StartLEDTask, osPriorityNormal,0, 256);//256
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
// struct netconn *conn, *newconn;
 err_t err, accept_err;
 struct netbuf *buf;
 uint16_t len,i;
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
	        	sentTEST = 1;
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

							for (i=0;i<h->length;i++)
								//printf("0x%02x ",s->buf[i]);
								printf("0x%02x ",h->raw[i]);
								printf("\n");

							switch (frame104_type(h)) {

								case FRAME_TYPE_I:
									printf("FRAME_TYPE_I\n");
									if (s->type == IEC_SLAVE && s->stopdt) {
										printf("-- iframe: free(buf);\n");
										free(buf);
										break;
									}
									ret = iec104_iframe_recv(newconn, s, bufIEC);
								break;

								case FRAME_TYPE_S:
									printf("FRAME_TYPE_S\n");
									ret = iec104_sframe_recv(s, bufIEC);
									free(bufIEC);
								break;

								case FRAME_TYPE_U:
									printf("FRAME_TYPE_U\n");
									ret = iec104_uframe_recv(newconn, s, bufIEC);
									free(bufIEC);
								break;

							}

							if (ret) {
								s->vr = 0;
								s->vs = 0;
								s->va = 0;
								printf("active close TCP/IP\n");
								netbuf_delete(buf);
			                    goto TCPCLOSE;
							}
//	                       netconn_write(newconn, data, len, NETCONN_COPY);		// отправляем данные по протоколу TCP
	//                 	   printf("%d\n",len);
	                     }
	                     while (netbuf_next(buf) >= 0);
	                     netbuf_delete(buf);

	  		           LED_Off(LED1);
	                 }
	         TCPCLOSE:
					 printf("netconn_close\n");
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

	  RTC_DateTypeDef sdatestructureget;
	  RTC_TimeTypeDef stimestructureget;

	  for(;;)
	  {
      	LED_Toggle(LED4);

        HAL_RTC_GetTime(&hrtc, &stimestructureget, RTC_FORMAT_BIN);
        HAL_RTC_GetDate(&hrtc, &sdatestructureget, RTC_FORMAT_BIN);

 //   	printf("\n%1.4u-%1.2d-%1.2d ",1980+(uint16_t)sdatestructureget.Year,sdatestructureget.Month,sdatestructureget.Date);
 //   	printf("\n%1.2d:%1.2d:%1.2d> ",stimestructureget.Hours,stimestructureget.Minutes,stimestructureget.Seconds);

      	osDelay(1000);
	  }
}

/*************************************************************************
 * iecsock_iframe_recv
 *************************************************************************/
static int iec104_iframe_recv(struct netconn *newconn, struct iecsock *s, struct iec_buf *buf)
{
	struct iechdr *h;
	h = &buf->h;
	buf->data_len = h->length ;//- 2;								// дополним реальным размером ASDU

	if (!check_nr(s, h->ic.nr))	{
		printf("not check_nr\n");
		return -1;						// проверим принимаемый порядковый номер
	}

	s->va = h->ic.nr;
	if (s->va == s->vs) {
   	 	   printf("--- iframe: va==vs\n");

// TODO: таймера нужно починить.
	//	t1_timer_stop(s);										// таймаут при посылке или тестировании APDU.
	//if (s->hooks.transmit_wakeup)				s->hooks.transmit_wakeup(s);					// пока нету передачи пробуждения
	//else if (default_hooks.transmit_wakeup)		default_hooks.transmit_wakeup(s);
	}
// TODO: таймера нужно починить.
	//t2_timer_stop(s);											// таймаут подтверждения.
	//t2_timer_start(s);

	if (!check_ns(s, h->ic.ns)) {
		printf("not check_ns: s->vr:%i h->ic.ns:%i\n",s->vr,h->ic.ns );
		return -1;						// проверим передаваемый порядковый номер
	}

	s->vr = (s->vr + 1) % 32767;

	printf("--- iframe: s->vr:%i s->va:%i s->va_peer:%i s->vs:%i\n",s->vr, s->va,s->va_peer, s->vs);


	if ((s->vr - s->va_peer + 32767) % 32767 == s->w) {			// отошлем Sframe

		h->start = 0x68;
		h->length = sizeof(struct iec_s);
		h->sc.res1 = 0;
		h->sc.res2 = 0;
		h->sc.ft = 1;
		h->sc.nr = s->vr;
	    netconn_write(newconn, h, sizeof(struct iechdr), NETCONN_NOCOPY);//NETCONN_COPY

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

			s->vs = 0;

			s->vr = 0;
			s->va_peer= 0;

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
//	struct netconn *newconn;
	struct iec_object obj[IEC_OBJECT_MAX];
	int ret, n, i;
	u_short caddr;
	u_char cause, test, pn, t, str_ioa;


	struct iechdr *h;
	uint8_t apcibuf[6];
//	uint8_t	*sa;
	h = (struct iechdr *)&apcibuf;
	// парсим содержимое ASDU
   ret = iecasdu_parse(obj, &t, &caddr, &n, &cause, &test, &pn, &str_ioa, b->data, b->data_len);
   if (!ret){
	   switch(t) {
	   //--------- M -------------
		   case M_SP_NA_1: /* 1 */			// одноэлементная информация

						   break;
		   case M_DP_NA_1: /* 3 */			// двухэлементная информация

						   break;
		   case M_ST_NA_1: /* 5 */			// информация о положении отпаек

						   break;
		   case M_BO_NA_1: /* 7 */			// строка из 32 бит

						   break;
		   case M_ME_NA_1: /* 9 */			// значение измеряемой величины, нормализованное значение

						   break;
		   case M_ME_NB_1: /* 11 */			// значение измеряемой величины, масштабированное значение

						   break;
		   case M_ME_NC_1: /* 13 */			// значение измеряемой величины, короткий формат с плав.запят.

						   break;
		   case M_SP_TB_1: /* 30 */			// одноэлементная информация с меткой времени CP56Время2а

						   break;
		   case M_BO_TB_1: /* 33 */			// строка из 32 бит с меткой времени CP56Time2a

						   break;
		   case M_ME_TD_1: /* 34 */			// значение измеряемой величины, нормализованное значение с меткой времени CP56Time2a

						   break;
		   case M_ME_TE_1: /* 35 */			// значение измеряемой величины, масштабированное значение с меткой времени CP56Time2a

						   break;
		   case M_ME_TF_1: /* 36 */			// значение измеряемой величины, короткий формат с плавающей запятой с меткой времени CP56Время2а

						   break;
		   case M_IT_TB_1: /* 37 */			// интегральная сумма с меткой времени CP56Time2a

						   break;
		   case M_EP_TD_1: /* 38 */			// действие устройств защиты с меткой времени CP56Time2a

						   break;
		   case M_EP_TE_1: /* 39 */			// упакованная информация о срабатывании пусковых органов защиты с меткой времени CP56Time2a

						   break;
		   case M_EP_TF_1: /* 40 */			// упакованная информация о срабатывании выходных цепей устройств защиты с меткой времени CP56Time2a

						   break;
						   //--------- C -------------
		   case C_IC_NA_1: /* 100 */		//ASDU Type ID 100 : C_IC_NA_1 - команда опроса
   	   	   	   	   	   	    outbuf = calloc(1,sizeof(struct iec_buf) + 249);
							if (!outbuf) return;
							outbufLen = 0;


							// нету APCI
							outbufLen+=sizeof(struct iechdr);
//						    iecasdu_create_header(outbuf+outbufLen, &outbufLen, C_IC_NA_1, 1, ACTCONFIRM, 0);		// заголовок ASDU по адрес абъекта
							iecasdu_create_header_all(outbuf+outbufLen, &outbufLen, C_IC_NA_1,1,SINGLE,ACTCONFIRM,NOTTEST,ACTIVATIONOK,0,0,0);
   	   	   	   	   	   	    iecasdu_create_type_100(outbuf+outbufLen,&outbufLen);									// 100

							//iecasdu_create_header(outbuf+outbufLen, &outbufLen, M_SP_NA_1, 1, 20, 1);		// заголовок ASDU по адрес абъекта
   	   	   	   	   	   	    //iecasdu_create_type_1(outbuf+outbufLen,&outbufLen);										// 1
   	   	   	   	   	   	    // ------------- APCI -------------------
							h->start = 0x68;
							h->length = outbufLen-2;
							h->ic.ft = 0;
							h->ic.ns = s->vs;
							h->ic.nr = s->vr;
							h->ic.res = 0;
							memcpy(outbuf, h, sizeof(struct iechdr));
							// !------------ APCI -------------------
							/*
							sa = outbuf--;
							printf("netconn_write...\n");
							for (i=0;i<outbufLen;i++){
								//printf("0x%02x ",s->buf[i]);
								printf("0x%02x ",*sa);
								sa++;
							}
								printf("\n");
*/

							netconn_write(newconn, outbuf , outbufLen, NETCONN_COPY);

							s->vs = (s->vs + 1) % 32767;			// счетчик переданных
							s->xmit_cnt++;

							free(outbuf);

	   	   	   	   	   	    printf("| 100 C_IC_NA_1: IDX:%i qoi:0x%02x\n",obj[0].ioa, obj[0].o.type100.qoi);
						   break;
		   case C_CI_NA_1: /* 101 */		//ASDU Type ID 101 : C_CI_NA_1 - Counter Interrogation Command


	  	   	   	   	   	    outbuf = calloc(1,sizeof(struct iec_buf) + 249);
							if (!outbuf) return;
							outbufLen = 0;
							// нету APCI
							outbufLen+=sizeof(struct iechdr);
							iecasdu_create_header_all(outbuf+outbufLen, &outbufLen, M_ME_NA_1,1,SINGLE,ACTCONFIRM,NOTTEST,ACTIVATIONOK,0,5,2);
							iecasdu_create_type_9(outbuf+outbufLen,&outbufLen, nm1++); //M_ME_NA_1 - значение измеряемой величины, нормализованное значение
   	   	   	   	   	   	    // ------------- APCI -------------------
							h->start = 0x68;
							h->length = outbufLen-2;
							h->ic.ft = 0;
							h->ic.ns = s->vs;
							h->ic.nr = s->vr;
							h->ic.res = 0;
							memcpy(outbuf, h, sizeof(struct iechdr));
							// !------------ APCI -------------------
							netconn_write(newconn, outbuf , outbufLen, NETCONN_COPY);

							s->vs = (s->vs + 1) % 32767;			// счетчик переданных
							s->xmit_cnt++;

							free(outbuf);

				   	   	   	printf("| 101 C_CI_NA_1: IDX:%i rqt:0x%02x frz:0x%02x\n",obj[0].ioa, obj[0].o.type101.rqt, obj[0].o.type101.frz);

						   break;

		   case C_RD_NA_1: /* 102 */		//ASDU Type ID 102 : C_RD_NA_1 - команда чтения
			   	   	   	   printf("| 101 C_CI_NA_1: IDX:%i \n",obj[0].ioa);
						   break;

		   case C_CS_NA_1: /* 103 */		//ASDU Type ID 103 : C_CS_NA_1 - команда синхронизации времени


			   	   	   	   sTime.Hours = obj[0].o.type103.time.hour;
			   	   	   	   sTime.Minutes = obj[0].o.type103.time.min;
			   	   	   	   sTime.Seconds = obj[0].o.type103.time.msec/1000;
			   	   	   	   //sTime.SubSeconds = (obj[0].o.type103.time.msec*60)/1000;
			    		   HAL_RTC_SetTime(&hrtc, &sTime, FORMAT_BIN);

			    		   sDate.Date = obj[0].o.type103.time.mday;
			    		   sDate.Month = obj[0].o.type103.time.month;
			    		   sDate.Year = obj[0].o.type103.time.year + 20;
			    		   sDate.WeekDay = obj[0].o.type103.time.wday;
			    		   HAL_RTC_SetDate(&hrtc, &sDate, FORMAT_BIN);


							outbuf = calloc(1,sizeof(struct iec_buf) + 249);
							if (!outbuf) return;
							outbufLen = 0;

							// нету APCI
							outbufLen+=sizeof(struct iechdr);
							// buf, buflen, type(идентификатор типа), num(число объектов), sq(последовательность или одиночный), cause(причина), t(тест), pn(подтверждение активации), ma(общий адрес), ca(адрес объекта)
							iecasdu_create_header_all(outbuf+outbufLen, &outbufLen, C_CS_NA_1,1,SINGLE,ACTCONFIRM,NOTTEST,ACTIVATIONOK,0,0,1);
							iecasdu_create_type_103(outbuf+outbufLen,&outbufLen);
							// ------------- APCI -------------------
							h->start = 0x68;
							h->length = outbufLen-2;
							h->ic.ft = 0;
							h->ic.ns = s->vs;
							h->ic.nr = s->vr;
							h->ic.res = 0;
							memcpy(outbuf, h, sizeof(struct iechdr));
							// !------------ APCI -------------------
							netconn_write(newconn, outbuf , outbufLen, NETCONN_COPY);

							s->vs = (s->vs + 1) % 32767;			// счетчик переданных
							s->xmit_cnt++;

							free(outbuf);


			   	   	   	   printf("| 103 C_CS_NA_1: IDX:%i hour:%02d min:%02d\n",obj[0].ioa, obj[0].o.type103.time.hour, obj[0].o.type103.time.min);

						   break;
//		   case C_TS_NA_1: /* 104 */		//ASDU Type ID 104: C_TS_NA_1 - тестовая команда				не используется в 104 стандарте
//	   	   	   	   	   	   printf("| 104 C_TS_NA_1: IDX:%i qoi:0x%02x\n",obj[0].ioa, obj[0].o.type104.res);
						   break;
		   case C_RP_NA_1: /* 105 */		//ASDU Type ID 105: C_RP_NA_1 - Reset Process Command
  	   	   	   	   	   	   printf("| 105 C_RP_NA_1: IDX:%i qoi:0x%02x\n",obj[0].ioa, obj[0].o.type105.res);
						   break;
		   case C_TS_TA_1: /* 107 */		//ASDU Type ID 107 : C_TS_TA_1 - тестовая команда с меткой времени CP56Время2а
	   	   	   	   	   	   printf("| 107 C_TS_TA_1: IDX:%i qoi:0x%02x\n",obj[0].ioa, obj[0].o.type107.res);
						   break;
	   }
		free(b);
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

// t0_timer	- тайм-аут при установлении соединения
// t1_timer	- тайм-аут при посылке или тестировании
// t2_timer	- тайм-аут для подтверждения в случае отсутствия сообщения с данными
// t3_timer	- тайм-аут для посылки блоков тестирования в случае долгого простоя


t3_timer_start(){

}

t3_timer_stop(){

}
