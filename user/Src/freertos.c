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
#include "port.h"
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
#include "usart.h"

// IEC 61850
#include "iec850.h"
#include "iec61850_server.h"
#include "static_model.h"


/*Modbus includes ------------------------------------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbport.h"
#include "modbus.h"

/*память SPI -----------------------------------------------------------------*/
#include "ExtSPImem.h"

/*консольный дебагер на USART ------------------------------------------------*/
#include "DebugConsole.h"


/* define --------------------------------------------------------------------*/
#define DEBUG_CONSOLE_STACK_SIZE		( configMINIMAL_STACK_SIZE * 4 )		// configMINIMAL_STACK_SIZE * 4 * N = 3072байта			// * 4 потому как 32 бита ядро  было 5 11.07.2016
#define DEBUG_CONSOLE_TASK_PRIORITY		osPriorityNormal

#define IEC850_STACK_SIZE				( configMINIMAL_STACK_SIZE * 10 )		// 3072байта			configMINIMAL_STACK_SIZE * 7		8- 05122016
#define IEC850Task__PRIORITY			osPriorityAboveNormal

#define	MODBUSTask_STACK_SIZE			( configMINIMAL_STACK_SIZE * 3 )		// 1024байта			onfigMINIMAL_STACK_SIZE * 2
#define MODBUSTask__PRIORITY			osPriorityNormal

/* Variables -----------------------------------------------------------------*/

// мьютексы -----------------------------
static xSemaphoreHandle xConsoleMutex = NULL;			// мьютекс печати в консоль

osMutexId xIEC850StartMutex;		// мьютекс готовности к запуску TCP/IP
osMutexDef(xIEC850StartMutex);

osMutexId xIEC850ServerStartMutex;		// мьютекс готовности к запуску TCP/IP
osMutexDef(xIEC850ServerStartMutex);


extern IedServer iedServer;

// переделать структуру под формат данных запроса MODBUS
	typedef struct					// для передачи через очереди структур.
	{
	  MBFrame	MBData;
	  uint8_t 	Source;
	} xData;

osThreadId defaultTaskHandle;
osThreadId IEC850TaskHandle;
osThreadId MBUSTaskHandle;
osThreadId CONSOLETaskHandle;


extern osMessageQId xQueueMODBUSHandle;

extern 	RTC_HandleTypeDef hrtc;

//  --------------------------------------------------------------------------------
//временно
uint8_t				writeNmb;

//Master mode: База данных
//Master mode: База данных конфигурации системы
#if defined (MR771)
extern uint16_t   usMConfigSystem;
extern uint16_t   ucMConfigSystemBuf[MB_Size_ConfSysytem];	// буфер для хранения конфигурации системы
extern uint16_t   usMConfigSW;
extern uint16_t   ucMConfigSWBuf[MB_Size_ConfSW];			// буфер для хранения конфигурации Выключателя


extern uint16_t   usMDateStart;
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   usMRevStart;
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   usMDiscInStart;
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];

extern uint16_t   usMConfigStartTrans;
extern uint16_t   ucMConfigBufTrans[MB_Size_ConfTrans];

extern uint16_t   usMConfigStartNaddr;
extern uint16_t   ucMConfigNaddrBuf[MB_NumbConfigNaddr];

extern uint16_t	    Ktt,Ktn;
extern uint16_t		ConfigOffset;			// смещение группы уставок
#elif defined (MR5_700)

extern uint16_t   usMDateStart;
extern uint16_t   ucMDateBuf[MB_NumbDate];
extern uint16_t   usMRevStart;
extern uint16_t   ucMRevBuf[MB_NumbWordRev];
extern uint16_t   usMDiscInStart;
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   usMAnalogInStart;
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   usMConfigStart;
extern uint16_t   ucMConfigBuf[MB_NumbConfig];
extern uint16_t   usMConfigStartall;
extern uint16_t   ucMConfigBufall[MB_NumbConfigall];
extern uint16_t   usMConfigStartSWCrash;
extern uint16_t   ucMSWCrash[MB_NumbSWCrash];

extern uint16_t	    Ktt,Ktn;

#endif
/*
//Master mode: хранилище дискретных входов
extern USHORT   usMDiscInStart;
#if      M_DISCRETE_INPUT_NDISCRETES%8
extern UCHAR    ucMDiscInBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_DISCRETE_INPUT_NDISCRETES/8+1];
#else
extern UCHAR    ucMDiscInBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_DISCRETE_INPUT_NDISCRETES/8];
#endif
//Master mode:Coils variables
extern USHORT   usMCoilStart;
#if      M_COIL_NCOILS%8
extern UCHAR    ucMCoilBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_COIL_NCOILS/8+1];
#else
extern UCHAR    ucMCoilBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_COIL_NCOILS/8];
#endif
//Master mode: хранилище входных регистров
extern USHORT   usMRegInStart;
extern USHORT   usMRegInBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_INPUT_NREGS];
//Master mode:хранилище выходных регистров
extern USHORT   usMRegHoldStart;
extern USHORT   usMRegHoldBuf[MB_MASTER_TOTAL_SLAVE_NUM][M_REG_HOLDING_NREGS];
*/
//  --------------------------------------------------------------------------------

struct netconn *conn, *newconn;
struct netconn *conn850,*newconn850;

struct netif 	first_gnetif,second_gnetif,gnetif;
struct ip_addr 	first_ipaddr,second_ipaddr;
struct ip_addr 	netmask;
struct ip_addr 	gw;

/* Semaphore to signal Ethernet Link state update */
osSemaphoreId Netif_LinkSemaphore = NULL;
/* Ethernet link thread Argument */
struct link_str link_arg;

struct iechooks default_hooks;
struct iecsock 	*s;

uint8_t *outbuf;
size_t  outbufLen;

/* Function prototypes -------------------------------------------------------*/
int16_t		GetDirGeneral(uint16_t	Currdata);
float		GetRealU(uint16_t	Currdata, uint16_t	ktn);
float		GetRealP(float	Currdata, uint16_t	ktn,  uint16_t	Ittf);

void StartIEC104Task(void const * argument);
void StartTimersTask(void const * argument);
void StartMODBUSTask(void const * argument);

static int iec104_iframe_recv(struct netconn *newconn, struct iecsock *s, struct iec_buf *buf);
static int iec104_sframe_recv(struct iecsock *s, struct iec_buf *buf);
static int iec104_uframe_recv(struct netconn *newconn, struct iecsock *s, struct iec_buf *buf);

//static void iec104_uframe_send(struct iecsock *s, enum uframe_func func);
//static void iec104_sframe_send(struct iecsock *s);
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


static inline char * uframe_func_to_string(enum uframe_func func);


//extern void MX_LWIP_Init(void);
//extern void tcpecho_init(void);
//extern void udpecho_init(void);

void FREERTOS_Init(void);

extern void vRegisterDEBUGCommands( void );

/* Hook prototypes */


/*************************************************************************
 * FREERTOS_Init
 *************************************************************************/
void FREERTOS_Init(void) {
 size_t	fre,fre_pr;

 /* BEGIN RTOS_MUTEX */
	// Создадим мьютекс для блокировки доступа к консоли
	xConsoleMutex = osMutexCreate(NULL);

	// Создадим мьютекс для блокировки доступа к TCP/IP таску
	xIEC850StartMutex = osMutexCreate(NULL);
	// Создадим мьютекс для блокировки доступа к данным сервера
	xIEC850ServerStartMutex = osMutexCreate(NULL);

	osMutexWait(xIEC850StartMutex,0);						// забрали семафор
	osMutexWait(xIEC850ServerStartMutex,0);				// забрали семафор

  /* END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
//	vSemaphoreCreateBinary( xBinarySemaphore );			//создается двоичный семафор
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */



	fre = xPortGetFreeHeapSize();			// размер кучи
	fre_pr = fre;
	USART_TRACE("размер кучи:%u байт\n",fre);

	osThreadDef(MBUS, StartMODBUSTask, MODBUSTask__PRIORITY ,0, MODBUSTask_STACK_SIZE);//256
	MBUSTaskHandle = osThreadCreate(osThread(MBUS), NULL);

	osThreadDef(IEC850, StartIEC850Task,IEC850Task__PRIORITY,0, IEC850_STACK_SIZE);//1024		//1500 работало IEC850Task__PRIORITY
	IEC850TaskHandle = osThreadCreate(osThread(IEC850), NULL);

 //  fre = xPortGetFreeHeapSize();
 //  USART_TRACE("стек IEC850:%u байт\n",fre_pr - fre);
 //  fre_pr = fre;

/*
  osThreadDef(IEC104, StartIEC104Task, osPriorityAboveNormal,0, 640);//1024
  defaultTaskHandle = osThreadCreate(osThread(IEC104), NULL);
  fre = xPortGetFreeHeapSize();
  USART_TRACE("FreeHeap(IEC104):%u\n",fre);

  // создадим таск только после IEC104. Таймера нужны только там
  if (defaultTaskHandle)
  {
	  osThreadDef(Timers, StartTimersTask, osPriorityNormal,0, 128);//128
	  defaultTaskHandle = osThreadCreate(osThread(Timers), NULL);

	  fre = xPortGetFreeHeapSize();
	  USART_TRACE("FreeHeap(Timers):%u\n",fre);
  }
*/

//  fre = xPortGetFreeHeapSize();
//  USART_TRACE("стек MBUS:%u байт\n",fre_pr - fre);
//  fre_pr = fre;

  // Создаём задачу, которая реализует консоль с помощью USART порта.
//   osThreadDef(CONSOLE, DEBUGConsoleTask, DEBUG_CONSOLE_TASK_PRIORITY ,0, DEBUG_CONSOLE_STACK_SIZE);//256
//   CONSOLETaskHandle = osThreadCreate(osThread(CONSOLE), NULL);
   // регистрируем команды консоли
//   vRegisterDEBUGCommands();
//   fre = xPortGetFreeHeapSize();			// размер кучи
//   USART_TRACE("стек CONSOLE:%u байт\n",fre_pr - fre);
//   fre_pr = fre;

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
//   xQueueMODBUS = xQueueCreate( 3, sizeof(xData) );

  /* definition and creation of xQueueMODBUS */
//  osMessageQDef(xQueueMODBUS, 3, sizeof(xData));
//  xQueueMODBUSHandle = osMessageCreate(osMessageQ(xQueueMODBUS), NULL);

   fre = xPortGetFreeHeapSize();
   USART_TRACE("осталось %u байт\n",fre);

  /* USER CODE END RTOS_QUEUES */
}

#ifdef	IEC104Task
/*************************************************************************
 * StartIEC104Task
 *************************************************************************/
void StartIEC104Task(void const * argument)
{
	 err_t err, accept_err;
	 struct netbuf *buf;
	 struct iechdr *h;
	 struct iec_buf *bufIEC;

	 uint16_t len;
	 uint8_t *data;
	 int ret = 0;

	//	MX_LWIP_Init();		// инит. LWIP

		tcpip_init( NULL, NULL );
		// устанавливаем IP параметры для первичного IP соединения, всегда сервер
		IP4_ADDR(&first_ipaddr, first_IP_ADDR0, first_IP_ADDR1, first_IP_ADDR2, first_IP_ADDR3);
		// устанавливаем IP параметры для вторичного IP соединения, всегда хост
		IP4_ADDR(&second_ipaddr, second_IP_ADDR0, second_IP_ADDR1, second_IP_ADDR2, second_IP_ADDR3);
		// устанавливаем маску подсети.
		IP4_ADDR(&netmask, NETMASK_ADDR0, NETMASK_ADDR1 , NETMASK_ADDR2, NETMASK_ADDR3);
		// устанавливаем адрес шлюза.
		IP4_ADDR(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);

		// добавим  и регистрируем NETWORK интерфейс
		netif_add(&first_gnetif, &first_ipaddr, &netmask, &gw, NULL, &ethernetif_init, &tcpip_input);
		netif_set_default(&first_gnetif);

		if (netif_is_link_up(&first_gnetif))	netif_set_up(&first_gnetif);		// When the netif is fully configured this function must be called
		else									netif_set_down(&first_gnetif);		// When the netif link is down this function must be called
		//dhcp_start(&first_gnetif);		// автоматическое получение IP

		default_hooks.disconnect_indication = disconnect_hook;						// disconnect_indication - called when link layer connection terminates.
		default_hooks.connect_indication = connect_hook;							// connect_indication - called when link layer connection is established.
		default_hooks.data_indication = data_received_hook;							// data_activation - called when ASDU was received, buf points to allocated structure. It is user responsibility to free allocated resources.
		default_hooks.activation_indication = activation_hook;						// activation_indication - called when monitor direction activates with  STARTACT/STARTCON S-frames.
	//	default_hooks.deactivation_indication = deactivation_hook;					// deactivation_indication - called when monitor direction deactivates  with STOPACT/STOPCON S-frames.
	//	default_hooks.transmit_wakeup = transmit_wakeup;							// transmit_wakeup - called when all frames from transmition queue were sent, acknowledged and iecsock can accept more.

		s = calloc(1, sizeof(struct iecsock));

		if (!s)		{USART_TRACE("Ошибка выделения памяти для s при ините.\n");}
		else		{USART_TRACE("Выделено памяти для s: %u байт.\n",sizeof(struct iecsock));}

		iec104_set_defaults(s);														// установка таймаутов 104 по умолчанию и отправка s фрейма.
		s->type = IEC_SLAVE;
		s->stopdt = 1;

		for(;;) {
		conn = netconn_new(NETCONN_TCP);											// создадим новое соединение

		if (conn!=NULL){
			USART_TRACE("netconn_new TCP ... \n");
			err = netconn_bind(conn, &first_ipaddr, IEC104_Port);					// привяжем соединение на IP и порт IEC 60870-5-104 (IEC104_Port)
//TODO: Разобраться с etconn_delete(newconn); почему newconn ????
			if (err != ERR_OK) 		netconn_delete(conn);						//
		    else
		    {
				USART_TRACE("netconn_listen ... \n");
		        netconn_listen(conn);												// переводим соединение в режим прослушивания
		        while (1)															// далее слушаем и  захватываем соединение
		        {
		             accept_err = netconn_accept(conn, &newconn);					// принимаем соединение
		             if (accept_err == ERR_OK)										// если приняли, то обработаем его
		             {
		     			USART_TRACE("netconn_accept ... ok \n");
		                 while (netconn_recv(newconn, &buf) == ERR_OK)				// принимаем данные в буфер
		                 {
		                	 Port_On(LED1);
		                     do
		                     {
		                        netbuf_data(buf,(void *)&data, &len);				// указатель получил адрес вх. данных
		                   	    h = (struct iechdr *) &data[0];

		    	     			bufIEC = calloc(1,len + sizeof(struct iec_buf) - sizeof(struct iechdr));		// выделяем блок памяти для bufIEC

		                   		t3_timer_stop(s);
		                   		t3_timer_start(s);

		                   		memcpy(&s->buf[0], h, len);
		                   		memcpy(&bufIEC->h, h, len);
		                   		s->len = len;										// размер принятого пакета.

		                   		// ---------------------------------------------------
								switch (frame104_type(h)) {	                   		// определяем тип фрейма.
									case FRAME_TYPE_I:								// функция передачи информации с нумерацией.
										if (s->type == IEC_SLAVE && s->stopdt) 	break;
										ret = iec104_iframe_recv(newconn, s, bufIEC);
									break;
									case FRAME_TYPE_S:								// функция контроля с нумерацией.
										ret = iec104_sframe_recv(s, bufIEC);
									break;
									case FRAME_TYPE_U:								// функция управления без нумерации.
										ret = iec104_uframe_recv(newconn, s, bufIEC);
									break;
								}
								if (ret) {											// если обработчик функции вернул ошибку
									s->vr = 0;
									s->vs = 0;
									s->va = 0;
									USART_TRACE("active close TCP/IP\n");
									netbuf_delete(buf);
									free(bufIEC);
				                    goto TCPCLOSE;
								}
								// ---------------------------------------------------
								free(bufIEC);
	    	     				USART_TRACE("освободил память после bufIEC.\n");
		                     }
		                     while (netbuf_next(buf) >= 0);
		                     netbuf_delete(buf);

		  		           Port_Off(LED1);
		                 }
		         TCPCLOSE:
		         	 	 USART_TRACE("netconn_close TCPCLOSE:\n");
		                 netconn_close(newconn);									// закрываем и освобождаем соединение
		                 netconn_delete(newconn);
		                 t1_timer_stop(s);
		                 t2_timer_stop(s);
		                 t3_timer_stop(s);
		             } else 	USART_TRACE("netconn_accept error: %d\n", accept_err);
		        }//! while (1)
		    }
		  } //! if (conn!=NULL)
	  }
}
/*************************************************************************
 * StartTimersTask
 * обработчик таймаутов 104 протокола.
 *************************************************************************/
void StartTimersTask(void const * argument)
{
	  t0_timer_stop(s);
	  t1_timer_stop(s);
	  t2_timer_stop(s);
	  t3_timer_stop(s);

	  for(;;)
	  {
        if (s->t1.evnt) t1_timer_run(s);		// проверка событий срабатывания таймеров.
        if (s->t2.evnt) t2_timer_run(s);
        if (s->t3.evnt) t3_timer_run(s);
        taskYIELD();							// отпустим задачу.
	  }
}
#endif
/*************************************************************************
 * StartMODBUSTask
 *************************************************************************/
#if defined	(MR771)
void StartMODBUSTask(void const * argument)
{
	uint32_t			TimerReadMB;
	uint8_t				ReadNmb=0;
//	uint8_t				writeNmb=0;
	eMBErrorCode		errorType;
	uint8_t				i;
	RTC_TimeTypeDef 	Time;
	uint8_t  			PerForSynch;
	extern const uint8_t userConfig[];
	uint64_t currentTime;

//	osMutexWait(xIEC850StartMutex, osWaitForever);				// забрали мьютекс для блокировки TCP пока не получим настройки IP
//	USART_TRACE_BLUE("MODBUS забрал мьютекс IEC850Start\n");

//	usMDiscInStart = MB_StartDiscreetaddr;

	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();

	writeNmb = 0;

	TimerReadMB = HAL_GetTick();
	for(;;)
	{

		if ((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS){					// периодический опрос MODBUS с периодом MB_PerForReadMODBUS(мс)
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>15) {				// лимит опроса.
				ReadNmb = 1;
			}

			if (ReadNmb>2 && ReadNmb<10) {	// периодический опрос.
				ReadNmb = 1;

//				uint16_t* tstAdr = malloc(1);
//			    USART_TRACE_MAGENTA("адрес:0x%X \n",(unsigned int)tstAdr);
//			    free(tstAdr);
			}

			//--------------- синхронизация часов ------------------------------------
			if ((ReadNmb == 1) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = 10;			// первый раз

			HAL_RTC_GetTime(&hrtc, &Time, FORMAT_BIN);
			if (Time.Hours > ucMDateBuf[3]){
				PerForSynch = Time.Hours - ucMDateBuf[3];
			}else{
				PerForSynch = ucMDateBuf[3] - Time.Hours;
			}

/*
			if (PerForSynch > (MB_PerForSynchClock-1)) {					//если прошел час то делаем синхронизацию снова
				ReadNmb = 10;
				USART_TRACE_BLUE("Пересинхронизация часов. время:%u последняя синхронизация:%u\n",Time.Hours,ucMDateBuf[3]);
			}
*/
			//--------------- синхронизация часов ------------------------------------


			//--------------- Выключатель ------------------------------------
	   	   	if (writeNmb == 1) {
	   	   		USART_TRACE_GREEN("Выключатель ON\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwON,MB_SwON,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 2) {
	   	   		USART_TRACE_RED("Выключатель OFF\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwOFF,MB_SwON,RT_WAITING_FOREVER);
	   	   	}

			//--------------- База чтения ------------------------------------
	   	   	if (writeNmb == 0){	// запись без очереди выполним.

	   	   	// чтение ревизии устройства
	   	   	if (ReadNmb==0)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);

	   	   	// периодическое чтение
	   	   	if (ReadNmb==1)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);
	   		if (ReadNmb==2)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);

	   		// однократное чтение
	   	   	if (ReadNmb==10) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);							// чтение текущего времени
	   	   	if (ReadNmb==11) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigStartNaddr,MB_NumbConfigNaddr,RT_WAITING_FOREVER);			// чтение  IP адреса
	   	   	if (ReadNmb==12) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_NOfConfig,1,RT_WAITING_FOREVER);									// чтение номера группы уставок
	   	   	if (ReadNmb==13) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigStartTrans,MB_Size_ConfTrans,RT_WAITING_FOREVER);			// чтение группы уставок транса
	   	  // 	if (ReadNmb==13) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfig+ConfigOffset+MB_offset_ConfTrans,MB_Size_ConfTrans,RT_WAITING_FOREVER);		// чтение уставок из нужной группы уставок
	   	  // 	if (ReadNmb==14) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfig+ConfigOffset+MB_offset_Ktn,1,RT_WAITING_FOREVER);		// чтение уставок из нужной группы уставок
	   	   	if (ReadNmb==14) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigSW,MB_Size_ConfSW,RT_WAITING_FOREVER);						// чтение конфигурации выключателя
	   	   	if (ReadNmb==15) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigSystem,MB_Size_ConfSysytem,RT_WAITING_FOREVER);				// чтение конфигурации системы

	   	   	ReadNmb++;
	   	   	} else{
	   	   		writeNmb = 0;
	   	   	}


//+++++++++++++++++++
//		    osStatus status = osMutexWait(xIEC850ServerStartMutex,0);			// не блокируемся но ждем готовности сервера
//		    if (status == osOK)
//if(IEC850TaskHandle)
{
	   		currentTime = Hal_getTimeInMs();
            IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом


if (ucMDiscInBuf[MB_offsetError] & MB_errorM1){	// 11R
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

}else{
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO1_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO2_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO3_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO4_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO5_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO6_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO7_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO8_q,0);

			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<0));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<1));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<2));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<3));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<4));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<5));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<6));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<7));
}
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO1_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO2_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO3_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO4_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO5_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO6_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO7_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO8_t, currentTime);

if (ucMDiscInBuf[MB_offsetError] & MB_errorM2){	// 8D
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
} else
{
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind1_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind2_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind3_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind4_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind5_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind6_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind7_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind8_q,0 | 0);

            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<0));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<1));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<2));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<3));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<4));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<5));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<6));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<7));
}
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind1_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind2_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind3_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind4_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind5_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind6_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind7_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind8_t, currentTime);

if (ucMDiscInBuf[MB_offsetError] & MB_errorM3){	// 16D
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind17_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind18_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind19_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind20_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind21_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind22_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind23_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind24_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

} else{
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind9_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind10_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind11_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind12_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind13_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind14_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind15_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind16_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind17_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind18_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind19_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind20_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind21_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind22_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind23_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind24_q,0 | 0);

            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<8));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<9));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<10));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<11));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<12));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<13));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<14));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<15));

            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind17_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<0));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind18_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<1));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind19_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<2));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind20_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<3));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind21_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<4));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind22_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<5));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind23_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<6));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind24_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<7));

}
   	   	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind9_t, currentTime);
      	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind10_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind11_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind12_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind13_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind14_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind15_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind16_t, currentTime);
   	   	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind17_t, currentTime);
      	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind18_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind19_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind20_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind21_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind22_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind23_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind24_t, currentTime);


if (ucMDiscInBuf[MB_offsetError] & MB_errorM4){ //D16
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind25_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind26_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind27_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind28_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind28_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind30_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind31_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind32_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind33_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind34_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind35_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind36_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind37_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind38_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind39_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind40_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
}else{
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind25_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind26_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind27_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind28_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind28_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind30_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind31_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind32_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind33_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind34_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind35_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind36_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind37_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind38_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind39_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind40_q,0);

			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind25_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<8));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind26_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<9));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind27_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<10));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind28_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<11));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind29_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<12));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind30_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<13));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind31_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<14));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind32_stVal,  ucMDiscInBuf[MB_offsetDiscreet1] & (1<<15));

			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind33_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<0));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind34_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<1));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind35_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<2));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind36_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<3));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind37_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<4));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind38_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<5));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind39_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<6));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind40_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<7));
}
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind25_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind26_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind27_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind28_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind29_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind30_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind31_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind32_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind33_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind34_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind35_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind36_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind37_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind38_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind39_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind40_t, currentTime);

//GGIO2
//--------------------------------
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<8));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<9));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<10));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<11));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<12));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<13));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<14));
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetDiscreet2] & (1<<15));

			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO1_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO2_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO3_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO4_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO5_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO6_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO7_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_INGGIO1_SPCSO8_q,0);

			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO1_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO2_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO3_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO4_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO5_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO6_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO7_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_INGGIO1_SPCSO8_t, currentTime);
//CSWI
//--------------------------------
			{
			uint8_t	res=STVALCODEDENUM_INTERMEDIATE;
			if (ucMDiscInBuf[MB_offsetDiscreet14] & MB_offsetSW_OFF) {res |= STVALCODEDENUM_OFF;}
			if (ucMDiscInBuf[MB_offsetDiscreet14] & MB_offsetSW_ON)  {res |= STVALCODEDENUM_ON;} 			//2 - STATE_ON ? 1- STATE_OFF ? 0 -  STATE_INTERMEDIATE

			IedServer_updateBitStrinAttributeValue(iedServer, IEDMODEL_CTRL_CSWI1_Pos_stVal, res);
			IedServer_updateQuality(iedServer,IEDMODEL_CTRL_CSWI1_Pos_q,0);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_CSWI1_Pos_t, currentTime);

			uint32_t	res32 = STVALINT32_OK;
			if (ucMDiscInBuf[MB_rOffsetDiscreet16] & MB_bOffsetErrorSW) 	{res32 |= STVALINT32_Alarm;}
			if (ucMDiscInBuf[MB_rOffsetDiscreet17] & MB_bOffsetExtErrorSW) 	{res32 |= STVALINT32_Alarm;}
			if (ucMDiscInBuf[MB_rOffsetDiscreet17] & MB_bOffsetErrorSWCtrl) {res32 |= STVALINT32_Alarm;}
			if (ucMDiscInBuf[MB_rOffsetDiscreet17] & MB_bOffsetErrorSWCO) 	{res32 |= STVALINT32_Alarm;}
			if (ucMDiscInBuf[MB_rOffsetDiscreet17] & MB_bOffsetErrorSWFail) {res32 |= STVALINT32_Alarm;}
			if (ucMDiscInBuf[MB_rOffsetDiscreet17] & MB_bOffsetErrorSWLon) 	{res32 |= STVALINT32_Alarm;}
			if (ucMDiscInBuf[MB_rOffsetDiscreet17] & MB_bOffsetErrorSWLoff) {res32 |= STVALINT32_Alarm;}
			IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_CTRL_CSWI1_Health_stVal, res32);
			IedServer_updateQuality(iedServer,IEDMODEL_CTRL_CSWI1_Health_q,0);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_CSWI1_Health_t, currentTime);

			}
//XCBR
//--------------------------------
			{
			//Pos
			uint8_t	res=STVALCODEDENUM_INTERMEDIATE;
			if (ucMDiscInBuf[MB_offsetDiscreet14] & MB_offsetSW_OFF) {res |= STVALCODEDENUM_OFF;}
			if (ucMDiscInBuf[MB_offsetDiscreet14] & MB_offsetSW_ON)  {res |= STVALCODEDENUM_ON;} 			//2 - STATE_ON ? 1- STATE_OFF ? 0 -  STATE_INTERMEDIATE

			IedServer_updateBitStrinAttributeValue(iedServer, IEDMODEL_CTRL_XCBR1_Pos_stVal, res);
			IedServer_updateQuality(iedServer,IEDMODEL_CTRL_XCBR1_Pos_q,0);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_XCBR1_Pos_t, currentTime);

			//Loc
			IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_CTRL_XCBR1_Loc_stVal, 0);
			IedServer_updateQuality(iedServer,IEDMODEL_CTRL_XCBR1_Loc_q,0);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_XCBR1_Loc_t, currentTime);
			}
//PTOC
//--------------------------------
    IedServer_updateInt32AttributeValue(iedServer,IEDMODEL_PROT_PTOC1_Health_stVal,(ucMDiscInBuf[MB_offsetError] & MB_errorM5));
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Health_t, currentTime);
	IedServer_updateQuality(iedServer,IEDMODEL_PROT_PTOC1_Health_q,0);
	// Str_general
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Str_general,  ucMDiscInBuf[MB_offset_I_IO] & MB_I_IO_I1);

//	int16_t		Valtmp = GetDirGeneral((ucMDiscInBuf[MB_offsetPTOC] >> 6) & 0b111111);
//	int16_t		Valtmp = ucMDiscInBuf[MB_offsetDirGeneral] & 0b11;
	MmsValue* 	ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneral((ucMDiscInBuf[MB_offsetPTOC] >> 6) & 0b111111));

	IedServer_updateAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Str_dirGeneral, ValMMS);
	IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Str_t, currentTime);

	if (ucMDiscInBuf[MB_offsetError] & MB_errorM5){
		IedServer_updateQuality(iedServer,IEDMODEL_PROT_PTOC1_Str_q, QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	} else{
		IedServer_updateQuality(iedServer,IEDMODEL_PROT_PTOC1_Str_q,0);
	}
	MmsValue_delete(ValMMS);
	// Op_general
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Op_general,  ucMDiscInBuf[MB_offset_I_IO] & (MB_I_IO_I1<<1));
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Op_t, currentTime);
	IedServer_updateQuality(iedServer,IEDMODEL_PROT_PTOC1_Op_q,0);

//PDIS

	// Str
	int16_t	Zsel = GetDirGeneral(
										((ucMDiscInBuf[MB_IO_offDirZ_1]<<2)&0b11100) |
										((ucMDiscInBuf[MB_IO_offDirZ_2]>>13)&0b11)
									);
	MmsValue* 	dirGen = MmsValue_newIntegerFromInt16(Zsel);
	IedServer_updateAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS1_Str_dirGeneral, dirGen);
	IedServer_updateAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS2_Str_dirGeneral, dirGen);
	IedServer_updateAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS3_Str_dirGeneral, dirGen);
	MmsValue_delete(dirGen);

	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS1_Str_general,  ucMDiscInBuf[MB_IO_offsetZ_1] & MB_Z1_IO);
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS2_Str_general,  ucMDiscInBuf[MB_IO_offsetZ_1] & MB_Z2_IO);
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS3_Str_general,  ucMDiscInBuf[MB_IO_offsetZ_1] & MB_Z3_IO);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS1_Str_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS2_Str_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS3_Str_t, currentTime);
	IedServer_updateQuality(iedServer,IEDMODEL_GenericIO_PDIS1_Str_q,0);
	IedServer_updateQuality(iedServer,IEDMODEL_GenericIO_PDIS2_Str_q,0);
	IedServer_updateQuality(iedServer,IEDMODEL_GenericIO_PDIS3_Str_q,0);
	// Op
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS1_Op_general,  ucMDiscInBuf[MB_IO_offsetZ_1] & MB_Z1);
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS2_Op_general,  ucMDiscInBuf[MB_IO_offsetZ_1] & MB_Z2);
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS2_Op_general,  ucMDiscInBuf[MB_IO_offsetZ_1] & MB_Z3);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS1_Op_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS2_Op_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GenericIO_PDIS3_Op_t, currentTime);
	IedServer_updateQuality(iedServer,IEDMODEL_GenericIO_PDIS1_Op_q,0);
	IedServer_updateQuality(iedServer,IEDMODEL_GenericIO_PDIS2_Op_q,0);
	IedServer_updateQuality(iedServer,IEDMODEL_GenericIO_PDIS3_Op_q,0);

//MMXU1_PPV
	if (ucMDiscInBuf[MB_offsetError] & MB_errorM5){
		// напряжения
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_PPV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_PPV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_PPV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_phV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_phV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_phV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_Hz_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

	}
	else{
		// напряжения
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_PPV_phsA_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_PPV_phsB_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_PPV_phsC_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_phV_phsA_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_phV_phsB_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_phV_phsC_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_Hz_q,0);

		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_PPV_phsA_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Uab],ucMConfigBufTrans[MB_offset_Ktnf]));
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_PPV_phsB_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ubc],ucMConfigBufTrans[MB_offset_Ktnf]));
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_PPV_phsC_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ucd],ucMConfigBufTrans[MB_offset_Ktnf]));

		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_phV_phsA_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ua],ucMConfigBufTrans[MB_offset_Ktnf]));
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_phV_phsB_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ub],ucMConfigBufTrans[MB_offset_Ktnf]));
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_phV_phsC_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Uc],ucMConfigBufTrans[MB_offset_Ktnf]));
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_Hz_mag_f,(float)ucMAnalogInBuf[MB_offset_Hz]/256);

	}
	IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_PPV_phsA_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_PPV_phsB_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_PPV_phsC_t, currentTime);

	IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_phV_phsA_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_phV_phsB_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_phV_phsC_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_Hz_t, currentTime);

// Аналоговые токовые данные
	if (ucMDiscInBuf[MB_offsetError] & MB_errorM5){
		// токи
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	}
	else{
		// токи
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_A_phsA_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_A_phsB_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_A_phsC_q,0);

		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_A_phsA_cVal_mag_f,(float)(ucMAnalogInBuf[MB_offset_Ia] * 40)/65535 * ucMConfigBufTrans[MB_offset_Kttf]);
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_A_phsB_cVal_mag_f,(float)(ucMAnalogInBuf[MB_offset_Ib] * 40)/65535 * ucMConfigBufTrans[MB_offset_Kttf]);
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_A_phsC_cVal_mag_f,(float)(ucMAnalogInBuf[MB_offset_Ic] * 40)/65535 * ucMConfigBufTrans[MB_offset_Kttf]);

	}
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_A_phsA_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_A_phsB_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_A_phsC_t, currentTime);

    //мощность ----------------------------------------------------
	if ((ucMDiscInBuf[MB_offsetError] & MB_errorM5)){

		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totW_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totVAr_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totPF_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	}else{
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totW_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totVAr_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totPF_q,0);



		float 	totW = (float)(int32_t)(((uint32_t)ucMAnalogInBuf[MB_offset_TotW+1]<<16) + (uint32_t)ucMAnalogInBuf[MB_offset_TotW]);
		float 	TotVAr = (float)(int32_t)(((uint32_t)ucMAnalogInBuf[MB_offset_TotVAr+1]<<16) + (uint32_t)ucMAnalogInBuf[MB_offset_TotVAr]);

		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_totW_mag_f,GetRealP(totW,ucMConfigBufTrans[MB_offset_Ktnf],ucMConfigBufTrans[MB_offset_Kttf]));
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_totVAr_mag_f,GetRealP(TotVAr,ucMConfigBufTrans[MB_offset_Ktnf],ucMConfigBufTrans[MB_offset_Kttf]));
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_totPF_mag_f,(float)(int16_t)ucMAnalogInBuf[MB_offset_TotPF]/256);

	}
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_totW_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_totVAr_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_totPF_t, currentTime);

// !!Аналоговые токовые данные

    // остальные узлыузлы
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_LLN0_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_LLN0_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_LLN0_Mod_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_LPHD1_Proxy_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_LPHD1_PhyHealth_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Mod_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_Mod_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Mod_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Str_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Op_t, currentTime);

    IedServer_unlockDataModel(iedServer);																// отдаём управление mmsServer'ом
}
//+++++++++++++++++++
		}

		errorType = eMBMasterPoll();						// мониторим события от MODBUS.
		if (errorType == MB_ETIMEDOUT){
//			ReadNmb--;
    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
		}

		taskYIELD();										// отпустим задачу.
	}
}

#elif defined (MR5_700)
void StartMODBUSTask(void const * argument)
{
	uint32_t			TimerReadMB;
	uint8_t				ReadNmb=0;
	eMBErrorCode		errorType;
	uint8_t				i;
	RTC_TimeTypeDef 	Time;
	uint8_t  			PerForSynch;
	extern const uint8_t userConfig[];

//	osMutexWait(xIEC850StartMutex, osWaitForever);				// забрали мьютекс для блокировки TCP пока не получим настройки IP
//	USART_TRACE_BLUE("MODBUS забрал мьютекс IEC850Start\n");

//	usMDiscInStart = MB_StartDiscreetaddr;

	eMBMasterInit(MB_RTU, 4, MB_Speed,  MB_PAR_NONE);
	eMBMasterEnable();

//	ReadNmb = userConfig[4];			// чтение из flash.

	Port_On(LED1);

	TimerReadMB = HAL_GetTick();
	for(;;)
	{
 //		IedServer_setControlHandler(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO1, (ControlHandler)controlListener, IEDMODEL_GGIO_OUTGGIO1_SPCSO1);

		if ((HAL_GetTick()-TimerReadMB)>MB_PerForReadMODBUS){					// периодический опрос MODBUS с периодом MB_PerForReadMODBUS(мс)
			TimerReadMB = HAL_GetTick();

			if (ReadNmb>14) {ReadNmb = 1;}
			if (ReadNmb>2 && ReadNmb<10) ReadNmb = 1;

			//--------------- синхронизация часов ------------------------------------
			if ((ReadNmb == 1) && HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) == 0xFFFF)	ReadNmb = 10;			// первый раз

			HAL_RTC_GetTime(&hrtc, &Time, FORMAT_BIN);
			if (Time.Hours > ucMDateBuf[3]){
				PerForSynch = Time.Hours - ucMDateBuf[3];
			}else{
				PerForSynch = ucMDateBuf[3] - Time.Hours;
			}

			if (PerForSynch > (MB_PerForSynchClock-1)) {					//если прошел час то делаем синхронизацию снова
//				ReadNmb = 10;
//				USART_TRACE_BLUE("Пересинхронизация часов. время:%u последняя синхронизация:%u\n",Time.Hours,ucMDateBuf[3]);
			}
			//--------------- синхронизация часов ------------------------------------


			//--------------- Выключатель ------------------------------------
	   	   	if (writeNmb == 1) {
	   	   		USART_TRACE_GREEN("Выключатель ON\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwON,MB_SwON,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 2) {
	   	   		USART_TRACE_RED("Выключатель OFF\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SwOFF,MB_SwON,RT_WAITING_FOREVER);
	   	   	}

	   	   	if (writeNmb == 3) {
	   	   		USART_TRACE_RED("сброс индикации\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_LEDS_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 4) {
	   	   		USART_TRACE_RED("сброс новой неисправности\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_Error_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 5) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале системы \n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_SysNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}
	   	   	if (writeNmb == 6) {
	   	   		USART_TRACE_RED("Сброс флага новой записи в журнале аварий\n");
	   	   		eMBMasterReqWriteCoil(MB_Slaveaddr,MB_addr_ErrorNote_OFF,MB_CTRL_OFF,RT_WAITING_FOREVER);
	   	   	}

			//--------------- База чтения ------------------------------------
	   	   	if (writeNmb == 0){	// запись без очереди выполним.
			// периодическое чтение
	   	   	if (ReadNmb==0)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMRevStart,MB_NumbWordRev,RT_WAITING_FOREVER);		// чтение ревизии устройства
	   		if (ReadNmb==1)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDiscInStart,MB_NumbDiscreet,RT_WAITING_FOREVER);
	   		if (ReadNmb==2)  eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMAnalogInStart,MB_NumbAnalog,RT_WAITING_FOREVER);

	   		// однократное чтение
	   	   	if (ReadNmb==10) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMDateStart,MB_NumbDate,RT_WAITING_FOREVER);				// чтение текущего времени
	   	   	if (ReadNmb==11) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,usMConfigStart,MB_NumbConfig,RT_WAITING_FOREVER);			// чтение уставок(только IP адрес)
	   	   	if (ReadNmb==12) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfig+MB_offset_Ktt,1,RT_WAITING_FOREVER);		// чтение уставок
	   	   	if (ReadNmb==13) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfig+MB_offset_Ktn,1,RT_WAITING_FOREVER);		// чтение уставок
	   	   	if (ReadNmb==14) eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartConfig,MB_NumbConfigall,RT_WAITING_FOREVER);		// чтение всех уставок
	   	   	ReadNmb++;
	   	   	} else{
	   	   		writeNmb = 0;
	   	   	}
//+++++++++++++++++++


//+++++++++++++++++++
if(IEC850TaskHandle){

	   		uint64_t currentTime = Hal_getTimeInMs();
            IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

if (ucMDiscInBuf[MB_offsetError] & MB_errorMSD1){
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
    	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
} else
{
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind1_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind2_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind3_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind4_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind5_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind6_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind7_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind8_q,0 | 0);

            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<0));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<1));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<2));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<3));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<4));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<5));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<6));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<7));
}
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind1_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind2_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind3_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind4_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind5_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind6_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind7_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind8_t, currentTime);

if (ucMDiscInBuf[MB_offsetError] & MB_errorMSD2){
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
} else{
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind9_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind10_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind11_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind12_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind13_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind14_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind15_q,0 | 0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_Ind16_q,0 | 0);

            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<8));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<9));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<10));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<11));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<12));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<13));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<14));
            IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetDiscreet] & (1<<15));

}
   	   	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind9_t, currentTime);
      	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind10_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind11_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind12_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind13_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind14_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind15_t, currentTime);
       	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Ind16_t, currentTime);

if (ucMDiscInBuf[MB_offsetError] & MB_errorMRV1){
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
}else{
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO1_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO2_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO3_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO4_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO5_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO6_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO7_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_GGIO_OUTGGIO1_SPCSO8_q,0);

          	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<0));
       	    IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<1));
      	    IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<2));
      	    IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<3));
      	    IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<4));
      	    IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<5));
      	    IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<6));
      	    IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay] & (1<<7));
}
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
    	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
     	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
    	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
    	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_SPCSO8_t, currentTime);

//PTOC

    IedServer_updateInt32AttributeValue(iedServer,IEDMODEL_PROT_PTOC1_Health_stVal,(ucMDiscInBuf[MB_offsetError] & (MB_errorMSAI | MB_errorMSAU)));
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Health_t, currentTime);
	IedServer_updateQuality(iedServer,IEDMODEL_PROT_PTOC1_Health_q,0);


	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Str_general,  ucMDiscInBuf[MB_offset_I_IO] & (1<<0));

//	int16_t		Valtmp = GetDirGeneral((ucMDiscInBuf[MB_offsetPTOC] >> 2) & 0b111111);
	int16_t		Valtmp = ucMDiscInBuf[MB_offsetDirGeneral] & 0b11;
	MmsValue* ValMMS = MmsValue_newIntegerFromInt16(Valtmp);

	IedServer_updateAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Str_dirGeneral, ValMMS);
	IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Str_t, currentTime);

	if (ucMDiscInBuf[MB_offsetError] & MB_errorMSAI){
		IedServer_updateQuality(iedServer,IEDMODEL_PROT_PTOC1_Str_q, QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	} else{
		IedServer_updateQuality(iedServer,IEDMODEL_PROT_PTOC1_Str_q,0);
	}
	MmsValue_delete(ValMMS);

	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Op_general,  ucMDiscInBuf[MB_offset_I_IO] & (1<<1));
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Op_t, currentTime);
	IedServer_updateQuality(iedServer,IEDMODEL_PROT_PTOC1_Op_q,0);


	if (ucMDiscInBuf[MB_offsetError] & MB_errorMSAU){
		// напряжения
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_phV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_phV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_phV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_Hz_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

	}
	else{
		// напряжения
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_phV_phsA_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_phV_phsB_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_phV_phsC_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_Hz_q,0);

		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_phV_phsA_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ua],Ktn));
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_phV_phsB_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ub],Ktn));
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_phV_phsC_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Uc],Ktn));
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_Hz_mag_f,(float)ucMAnalogInBuf[MB_offset_Hz]/256);

	}
	IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_phV_phsA_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_phV_phsB_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_phV_phsC_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_Hz_t, currentTime);

// Аналоговые токовые данные
	if (ucMDiscInBuf[MB_offsetError] & MB_errorMSAI){
		// токи
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	}
	else{
		// токи
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_A_phsA_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_A_phsB_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_A_phsC_q,0);

		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_A_phsA_cVal_mag_f,(float)(ucMAnalogInBuf[MB_offset_Ia] * 40)/65536 * Ktt);
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_A_phsB_cVal_mag_f,(float)(ucMAnalogInBuf[MB_offset_Ib] * 40)/65536 * Ktt);
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_A_phsC_cVal_mag_f,(float)(ucMAnalogInBuf[MB_offset_Ic] * 40)/65536 * Ktt);

	}
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_A_phsA_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_A_phsB_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_A_phsC_t, currentTime);

    //мощность ----------------------------------------------------
	if ((ucMDiscInBuf[MB_offsetError] & MB_errorMSAU) || (ucMDiscInBuf[MB_offsetError] & MB_errorMSAI)){

		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totW_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totVAr_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totPF_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	}else{
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totW_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totVAr_q,0);
		IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totPF_q,0);

		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_totW_mag_f,(float)(ucMAnalogInBuf[MB_offset_TotW]));
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_totVAr_mag_f,(float)(ucMAnalogInBuf[MB_offset_TotVAr]));
		IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_totPF_mag_f,(float)ucMAnalogInBuf[MB_offset_TotPF]/256);

	}
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_totW_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_totVAr_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_totPF_t, currentTime);

// !!Аналоговые токовые данные


//CSWI
//-------------------------------

	{
	uint8_t	res=STVALCODEDENUM_INTERMEDIATE;
	if (ucMDiscInBuf[MB_offsetDiscreet8] & MB_offsetSW_OFF) {res |= STVALCODEDENUM_OFF;}
	if (ucMDiscInBuf[MB_offsetDiscreet8] & MB_offsetSW_ON)  {res |= STVALCODEDENUM_ON;} 			//2 - STATE_ON ? 1- STATE_OFF ? 0 -  STATE_INTERMEDIATE

	IedServer_updateBitStrinAttributeValue(iedServer, IEDMODEL_CTRL_CSWI1_Pos_stVal, res);
	IedServer_updateQuality(iedServer,IEDMODEL_CTRL_CSWI1_Pos_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_CSWI1_Pos_t, currentTime);

#define MB_bOffsetErrorHard		1<<0
#define MB_bOffsetErrorLogic	1<<1
#define MB_bOffsetErrorData		1<<2

	uint32_t	res32 = STVALINT32_OK;
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorHard) 	{res32 |= STVALINT32_Alarm;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorLogic) 	{res32 |= STVALINT32_Alarm;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorData) 	{res32 |= STVALINT32_Alarm;}
	if (ucMDiscInBuf[MB_offsetDiscreet4] & MB_bOffsetErrorSW) 		{res32 |= STVALINT32_Alarm;}
	IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_CTRL_CSWI1_Health_stVal, res32);
	IedServer_updateQuality(iedServer,IEDMODEL_CTRL_CSWI1_Health_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_CSWI1_Health_t, currentTime);

	}
//XCBR
//--------------------------------
	{
	//Pos
	uint8_t	res=STVALCODEDENUM_INTERMEDIATE;
	if (ucMDiscInBuf[MB_offset_adr0] & MB_offsetSW_OFF) {res |= STVALCODEDENUM_OFF;}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_offsetSW_ON)  {res |= STVALCODEDENUM_ON;} 			//2 - STATE_ON ? 1- STATE_OFF ? 0 -  STATE_INTERMEDIATE

	IedServer_updateBitStrinAttributeValue(iedServer, IEDMODEL_CTRL_XCBR1_Pos_stVal, res);
	IedServer_updateQuality(iedServer,IEDMODEL_CTRL_XCBR1_Pos_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_XCBR1_Pos_t, currentTime);

	//Loc
	bool XCBR1_Loc=0;
	if (ucMConfigBufall[MB_offset_BlockSDTU]) {XCBR1_Loc = 1;}
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_CTRL_XCBR1_Loc_stVal, XCBR1_Loc);
	IedServer_updateQuality(iedServer,IEDMODEL_CTRL_XCBR1_Loc_q,0);
	IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_XCBR1_Loc_t, currentTime);
	}

//	IedServer_updateInt32AttributeValue(iedServer, iedModel_CTRL_XCBR1_OpCnt_stVal,(ucMConfigBufall[MB_offset_BlockSDTU]);

	//--------------------------------

//LEDGGIO1
//--------------------------------
 	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<8));
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<9));
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<10));
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<11));
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<12));
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<13));
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<14));
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<15));
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<4));
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<5));
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<6));
	IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLED] & (1<<7));

	// статус сброса нидикаторов
	if (ucMDiscInBuf[MB_offsetLED] & 0xFF00){
		IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_SPCSO1_stVal,  1);
	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_SPCSO1_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_SPCSO1_stVal,  0);
	    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_SPCSO1_t, currentTime);

	}


    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind1_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind2_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind3_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind4_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind5_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind6_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind7_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind8_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind9_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind10_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind11_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Ind12_t, currentTime);


    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Ind1_q,0);
    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Ind2_q,0);
    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Ind3_q,0);
    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Ind4_q,0);
    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Ind5_q,0);
    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Ind6_q,0);
    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Ind7_q,0);
    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Ind8_q,0);
    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Ind9_q,0);
    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Ind10_q,0);
    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Ind11_q,0);
    IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Ind12_q,0);

//--------------------------------
// сброс флагов

	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetError){
		IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO1_stVal,  1);
	    IedServer_updateQuality(iedServer,IEDMODEL_CTRL_GGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO1_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO1_stVal,  0);
	    IedServer_updateQuality(iedServer,IEDMODEL_CTRL_GGIO1_SPCSO1_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO1_t, currentTime);
	}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetSysNote){
		IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO2_stVal,  1);
	    IedServer_updateQuality(iedServer,IEDMODEL_CTRL_GGIO1_SPCSO2_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO2_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO2_stVal,  0);
	    IedServer_updateQuality(iedServer,IEDMODEL_CTRL_GGIO1_SPCSO2_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO2_t, currentTime);
	}
	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetErrorNote){
		IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO3_stVal,  1);
	    IedServer_updateQuality(iedServer,IEDMODEL_CTRL_GGIO1_SPCSO3_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO3_t, currentTime);

	} else{
		IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO3_stVal,  0);
	    IedServer_updateQuality(iedServer,IEDMODEL_CTRL_GGIO1_SPCSO3_q,0);
	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO3_t, currentTime);
	}

//--------------------------------
// MSQI1
	int32_t MSQI_stval = 0;

	if (ucMDiscInBuf[MB_offsetError] & (MB_errorMRV1|MB_errorMSAI)) {
		MSQI_stval = 2;
	} else		MSQI_stval = 1;

	IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_MES_MSQI1_Health_stVal,  MSQI_stval);
    IedServer_updateQuality(iedServer,IEDMODEL_MES_MSQI1_Health_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MSQI1_Health_t, currentTime);

// SeqA
    float	cXtmp = (float)ucMAnalogInBuf[MB_offset_NI1] * 40 * Ktt / 65536;
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_MES_MSQI1_SeqA_c1_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,IEDMODEL_MES_MSQI1_SeqA_c1_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MSQI1_SeqA_c1_t, currentTime);

    cXtmp = (float)ucMAnalogInBuf[MB_offset_NI2] * 40 * Ktt / 65536;
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_MES_MSQI1_SeqA_c2_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,IEDMODEL_MES_MSQI1_SeqA_c2_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MSQI1_SeqA_c2_t, currentTime);

    cXtmp = (float)ucMAnalogInBuf[MB_offset_NI0] * 40 * Ktt / 65536;
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_MES_MSQI1_SeqA_c3_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,IEDMODEL_MES_MSQI1_SeqA_c3_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MSQI1_SeqA_c3_t, currentTime);

// SeqU
    cXtmp = (float)GetRealU(ucMAnalogInBuf[MB_offset_NU1],Ktn);
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_MES_MSQI1_SeqU_c1_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,IEDMODEL_MES_MSQI1_SeqU_c1_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MSQI1_SeqU_c1_t, currentTime);

    cXtmp = (float)GetRealU(ucMAnalogInBuf[MB_offset_NU2],Ktn);
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_MES_MSQI1_SeqU_c2_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,IEDMODEL_MES_MSQI1_SeqU_c2_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MSQI1_SeqU_c2_t, currentTime);

    cXtmp = (float)GetRealU(ucMAnalogInBuf[MB_offset_NU0],Ktn);
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_MES_MSQI1_SeqU_c3_cVal_mag_f,  cXtmp);
    IedServer_updateQuality(iedServer,IEDMODEL_MES_MSQI1_SeqU_c3_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MSQI1_SeqU_c3_t, currentTime);

//--------------------------------

//--------------------------------
// RFLO
	uint32_t	OMP;
	if (ucMConfigBufall[MB_offset_OMP] & 1){OMP=0;}	else{OMP=5;}
	IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_MES_RFLO1_Mod_stVal,  OMP);
	IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_MES_RFLO1_Beh_stVal,  OMP);

    IedServer_updateQuality(iedServer,IEDMODEL_MES_RFLO1_Mod_q,0);
    IedServer_updateQuality(iedServer,IEDMODEL_MES_RFLO1_Beh_q,0);

    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_RFLO1_Mod_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_RFLO1_Beh_t, currentTime);

	uint32_t	err;
	if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetError){err=1;}	else{err=5;}
	IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_MES_RFLO1_Health_stVal,  err);
    IedServer_updateQuality(iedServer,IEDMODEL_MES_RFLO1_Health_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_RFLO1_Health_t, currentTime);


    float	fltz = (float)ucMAnalogInBuf[MB_offset_OMPLkz] * (float)ucMConfigBufall[MB_offset_OMP] / 256000;
	IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_MES_RFLO1_Fltz_mag_f,  (float)fltz);
    IedServer_updateQuality(iedServer,IEDMODEL_MES_RFLO1_Fltz_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_RFLO1_Fltz_t, currentTime);

    fltz = (float)ucMAnalogInBuf[MB_offset_OMPLkz]/256;
	IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_MES_RFLO1_FltDiskm_mag_f, fltz);
//	IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_MES_RFLO1_FltDiskm_mag_f,(float)(ucMAnalogInBuf[MB_offset_OMPLkz-1] /256));
    IedServer_updateQuality(iedServer,IEDMODEL_MES_RFLO1_FltDiskm_q,0);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_RFLO1_FltDiskm_t, currentTime);


//--------------------------------
    // остальные узлыузлы
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_LLN0_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_LLN0_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_LLN0_Mod_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_LPHD1_Proxy_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_LPHD1_PhyHealth_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_OUTGGIO1_Mod_t, currentTime);
//LEDGGIO1
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Mod_t, currentTime);


    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_Mod_t, currentTime);

    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Mod_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Beh_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Health_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Str_t, currentTime);
    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_PROT_PTOC1_Op_t, currentTime);

/*
	if (ucMDiscInBuf[MB_bOffsetSettingGr]) {
		iedModel_LD0_LLN0_sgcb0.actSG = 2;
	} else{
		iedModel_LD0_LLN0_sgcb0.actSG = 1;
	}
*/
    IedServer_unlockDataModel(iedServer);																// отдаём управление mmsServer'ом
}
//+++++++++++++++++++
		}

		errorType = eMBMasterPoll();						// мониторим события от MODBUS.
		if (errorType == MB_ETIMEDOUT){
//			ReadNmb--;
    		USART_TRACE_RED("ReadNmb: %u\n",ReadNmb);
    	Port_Off(LED1);
		}

		taskYIELD();										// отпустим задачу.
	}
}



#endif
/*************************************************************************
 * GetDirGeneral
 * функция получения направления тока
 * прямое, оба, обратное, неизвестное
 *************************************************************************/
int16_t		GetDirGeneral(uint16_t	Currdata){
bool	a,b,c,d,e,f;
bool	g,h;
bool	i,j,k,l;
int16_t	DirOut = 0;

	a = Currdata & 1;
	b = Currdata & 1<<1;
	c = Currdata & 1<<2;
	d = Currdata & 1<<3;
	e = Currdata & 1<<4;
	f = Currdata & 1<<5;

	g = (~a && ~b) || (~c && ~d) || (~e && ~f);
	h = (a && ~b) || (c && ~d) || (e && ~f);

	i = g && ~h;
	j = g && h;
	k = ~g && h;
	l = b && d && e;

		 if (i) DirOut = 0;
	else if (j) DirOut = 1;
	else if (k) DirOut = 2;
	else if (l) DirOut = 3;

return	DirOut;
}

/*************************************************************************
 * GetRealU
 * ktn - коэффициент ТН прочитанные из таблицы уставок 0x1009
 *************************************************************************/
float		GetRealU(uint16_t	Currdata, uint16_t	ktn){

float	DirOut = 0;
float	K;

	if(ktn & 1<<15){
		K = ( ((float)ktn - (float)32768)* (float)1000) /(float)256;
	} else{
		K = (float)ktn/(float)256;
	}
	DirOut = ((float)Currdata * K)/(float)256;

return	DirOut;
}
/*************************************************************************
 * GetRealP
 * ktn - коэффициент ТН прочитанные из таблицы уставок 0x1009
 *************************************************************************/
float		GetRealP(float	Currdata, uint16_t	ktn,  uint16_t	Ittf){

float	realP = 0;
float	K;

	if(ktn & 1<<15){
		K = ( ((float)ktn - (float)32768)* (float)1000) /(float)256;
	} else{
		K = (float)ktn/(float)256;
	}
	realP = (float)Currdata/65536*Ittf*K*1.25;

return	realP;
}

#ifdef	IEC104Task
/*************************************************************************
 * iecsock_iframe_recv
 *************************************************************************/
static int iec104_iframe_recv(struct netconn *newconn, struct iecsock *s, struct iec_buf *buf)
{
	struct iechdr *h;
	h = &buf->h;
	buf->data_len = h->length ;										// дополним реальным размером ASDU

	if (!check_nr(s, h->ic.nr))	{									// проверим принимаемый порядковый номер
		USART_TRACE("not check_nr. s->vs:%d h->ic.nr:%d\n",s->vs, h->ic.nr);
		return -1;
	}

	s->va = h->ic.nr;
	if (s->va == s->vs)		t1_timer_stop(s);						// если номер передающего совпал с принятым.

	t2_timer_stop(s);												// таймаут подтверждения.
	t2_timer_start(s);

	if (!check_ns(s, h->ic.ns)) {
		USART_TRACE("not check_ns: s->vr:%i h->ic.ns:%i\n",s->vr,h->ic.ns );
		return -1;													// проверим передаваемый порядковый номер
	}
	s->vr = (s->vr + 1) % 32767;									// инкрементим номер принятого

	if ((s->vr - s->va_peer + 32767) % 32767 == s->w) {				// отошлем Sframe каждые "w" принятых пакетов
		iec104_sframe_send(s);
		s->va_peer = s->vr;
	}

	if (s->hooks.data_indication)				s->hooks.data_indication(s, buf);			//расшифровываем ASDU
	else if (default_hooks.data_indication)		default_hooks.data_indication(s, buf);

	return 0;
}
/*************************************************************************
 * iecsock_sframe_recv
 *************************************************************************/
static int iec104_sframe_recv(struct iecsock *s, struct iec_buf *buf)
{
	struct iechdr *h;
	h = &buf->h;
	buf->data_len = h->length - 2;

	if (!check_nr(s, h->ic.nr))	return -1;

	s->va = h->ic.nr;
	if (s->va == s->vs) {
		t1_timer_stop(s);																	// таймаут при посылке или тестировании APDU.
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
			s->vs = 0;
			s->vr = 0;
			s->va_peer= 0;
			iec104_uframe_send(s, STARTCON);

			if (s->hooks.activation_indication)					s->hooks.activation_indication(s);
			else if (default_hooks.activation_indication)		default_hooks.activation_indication(s);

		break;
		case STARTCON:
			if (s->type != IEC_MASTER)	return -1;

			t1_timer_stop(s);
			s->stopdt = 0;

			if (s->hooks.activation_indication)					s->hooks.activation_indication(s);
			else if (default_hooks.activation_indication)		default_hooks.activation_indication(s);
		break;

		case STOPACT:
			if (s->type != IEC_SLAVE)	return -1;

			s->stopdt = 1;
			iec104_uframe_send(s, STOPCON);

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
			iec104_uframe_send(s, TESTCON);

			if (s->type == IEC_SLAVE && !s->testfr)		t3_timer_stop(s);
		break;

		case TESTCON:
			if (!s->testfr)		return -1;
			t1_timer_stop(s);
			s->testfr = 0;
		break;

	}
	return 0;
}
/*************************************************************************
 * iec104_uframe_send
 *************************************************************************/
void iec104_uframe_send(struct iecsock *s, enum uframe_func func)
{
	struct iechdr h;
	memset(&h, 0, sizeof(struct iechdr));				// обнулим h

	USART_TRACE("TX U %s stopdt:%i \n", uframe_func_to_string(func), s->stopdt);

	h.start = 0x68;
	h.length = sizeof(struct iec_u);
	h.uc.ft = 3;

	if (func == STARTACT)			h.uc.start_act = 1;
	else if (func == STARTCON)		h.uc.start_con = 1;
	else if (func == STOPACT)		h.uc.stop_act = 1;
	else if (func == STOPCON)		h.uc.stop_con = 1;
	else if (func == TESTACT)		h.uc.test_act = 1;
	else if (func == TESTCON)		h.uc.test_con = 1;

	netconn_write(newconn, &h, sizeof(h), NETCONN_COPY);
	s->xmit_cnt++;
}
/*************************************************************************
 * iec104_sframe_send
 *************************************************************************/
void iec104_sframe_send(struct iecsock *s)
{
	struct iechdr h;
	memset(&h, 0, sizeof(h));

	USART_TRACE("TX S N(r)=%i \n", s->vr);

	h.start = 0x68;
	h.length = sizeof(struct iec_s);
	h.sc.res1 = 0;
	h.sc.res2 = 0;
	h.sc.ft = 1;
	h.sc.nr = s->vr;

    netconn_write(newconn, &h, sizeof(h), NETCONN_COPY);
	s->xmit_cnt++;
}
/*************************************************************************
 * iec104_prepare_iframe
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

	USART_TRACE("send_base_request...\n");
	send_base_request(s,NULL);

}
/*************************************************************************
 * send_base_request
 *************************************************************************/
void send_base_request(struct iecsock *s, void *arg)
{
/*	struct timeval tv; */
	u_char *bufreq;
	size_t buflen = 0;

	bufreq = calloc(1,sizeof(struct iec_buf) + 249);
	if (!bufreq)	return;

	buflen+=sizeof(struct iechdr);
	iecasdu_create_header_all(bufreq+buflen, &buflen, C_IC_NA_1,1,SINGLE,ACTIVATION,NOTTEST,ACTIVATIONOK,0,0,0);
	iecasdu_create_type_100(bufreq+buflen,&buflen);									// 100
	iec_send_frame(s,bufreq,&buflen);

	free(bufreq);


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
	//TAILQ_INSERT_TAIL(&s->write_q, b, head);
	iec104_run_write_queue(s);

	free(b);
}
/*************************************************************************
 * iec104_run_write_queue
 *************************************************************************/
void iec104_run_write_queue(struct iecsock *s)
{
	struct iechdr *h;
	struct iec_buf *b;

	if (s->type == IEC_SLAVE && s->stopdt)	return;

	// далее по циклу выдаём все ответы из стека(которого нет)

	h = &b->h;
	h->ic.res = 0;
	h->ic.nr = s->vr;
	h->ic.ns = s->vs;

	USART_TRACE("TX I V(s)=%d V(a)=%d N(s)=%d N(r)=%d \n", s->vs, s->va, h->ic.ns, h->ic.nr);

	if (t1_timer_pending(s))	t1_timer_stop(s);
	t1_timer_start(s);

    netconn_write(newconn, &h, sizeof(struct iechdr), NETCONN_COPY);

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

//	USART_TRACE(stderr, "%s: Sucess 0x%lu\n", __FUNCTION__, (unsigned long) s);

}
/*************************************************************************
 * disconnect_hook
 * Отключение TCP
 *************************************************************************/
void disconnect_hook(struct iecsock *s, short reason)
{
	//USART_TRACE("%s: what=0x%02x\n", __FUNCTION__, reason);
	return;
}
/*************************************************************************
 * data_received_hook
 *  приём данных
 *************************************************************************/
void data_received_hook(struct iecsock *s, struct iec_buf *b)
{
	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;

//	struct netconn *newconn;
	struct iec_object obj[IEC_OBJECT_MAX];
	int ret, n, i;
	u_short caddr;
	u_char cause, test, pn, t, str_ioa;

	struct iechdr *h;
	uint8_t apcibuf[6];

	eMBMasterReqErrCode    errorCode = MB_MRE_NO_ERR;


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

//				   	   	   errorCode = eMBMasterReqReadHoldingRegister(MB_Slaveaddr,MB_StartAnalogINaddr,MB_NumbAnalogIN,RT_WAITING_FOREVER);


   	   	   	   	   	   	    outbuf = calloc(1,sizeof(struct iec_buf) + 249);
							if (!outbuf) {
								USART_TRACE("Ошибка выделения памяти outbuf в C_IC_NA_1 запросе.\n");
								return;
							} else{
								USART_TRACE("Выделено памяти outbuf в C_IC_NA_1: %u байт.\n",sizeof(struct iec_buf) + 249);
							}
							outbufLen = 0;


							// нету APCI
							outbufLen+=sizeof(struct iechdr);
							//iecasdu_create_header_all(outbuf+outbufLen, &outbufLen, C_IC_NA_1,1,SINGLE,ACTCONFIRM,NOTTEST,ACTIVATIONOK,0,5,2);
   	   	   	   	   	   	    //iecasdu_create_type_100(outbuf+outbufLen,&outbufLen);									// 100

//							iecasdu_create_header_all(outbuf+outbufLen, &outbufLen, M_ME_NA_1,1,SINGLE,ACTCONFIRM,NOTTEST,ACTIVATIONOK,0,5,2);

//							iecasdu_create_header_all(outbuf+outbufLen, &outbufLen, M_ME_NA_1,MB_NumbAnalogIN,SERIAL,ACTCONFIRM,NOTTEST,ACTIVATIONOK,0,5,0);
//							for (i=MB_StartAnalogINaddr;i<(MB_StartAnalogINaddr+MB_NumbAnalogIN);i++){
//								iecasdu_create_type_9(outbuf+outbufLen,&outbufLen, usMRegInBuf[0][i]); //M_ME_NA_1 - значение измеряемой величины, нормализованное значение
//							}


							iecasdu_create_header_all(outbuf+outbufLen, &outbufLen, M_ME_NA_1,MB_NumbAnalog,SERIAL,ACTCONFIRM,NOTTEST,ACTIVATIONOK,0,MB_Slaveaddr,MB_StartAnalogINaddr);
							for (i=0;i<MB_NumbAnalog;i++){
								iecasdu_create_type_9(outbuf+outbufLen,&outbufLen, ucMAnalogInBuf[i]); //M_ME_NA_1 - значение измеряемой величины, нормализованное значение
							}
							//iecasdu_create_header(outbuf+outbufLen, &outbufLen, M_SP_NA_1, 1, 20, 1);		// заголовок ASDU по адрес абъекта
   	   	   	   	   	   	    //iecasdu_create_type_1(outbuf+outbufLen,&outbufLen);										// 1
   	   	   	   	   	   	    // ------------- APCI -------------------
   	   	   	   	   	   	    iecasdu_add_APCI(outbuf, outbufLen);
   	   	   	   	   	   	    /*
							h->start = 0x68;
							h->length = outbufLen-2;
							h->ic.ft = 0;
							h->ic.ns = s->vs;
							h->ic.nr = s->vr;
							h->ic.res = 0;
							memcpy(outbuf, h, sizeof(struct iechdr));
							*/

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
							USART_TRACE("освободил память outbuf в C_IC_NA_1\n");


							USART_TRACE("| 100 C_IC_NA_1: IDX:%i qoi:0x%02x\n",obj[0].ioa, obj[0].o.type100.qoi);
						   break;
		   case C_CI_NA_1: /* 101 */		//ASDU Type ID 101 : C_CI_NA_1 - Counter Interrogation Command



//			   	   	   	   errorCode = eMBMasterReqReadCoils(MB_Slaveaddr,MB_StartDiscreetaddr,MB_NumbDiscreet,RT_WAITING_FOREVER);		// указываем время ожидания ответа от менеджера событий

	  	   	   	   	   	    outbuf = calloc(1,sizeof(struct iec_buf) + 249);//249
							if (!outbuf) {
								USART_TRACE("Ошибка выделения outbuf в C_CI_NA_1 запросе.\n");
								return;
							}

							outbufLen = 0;
							// нету APCI
							outbufLen+=sizeof(struct iechdr);
							iecasdu_create_header_all(outbuf+outbufLen, &outbufLen, M_SP_NA_1,MB_NumbDiscreet,SERIAL,ACTCONFIRM,NOTTEST,ACTIVATIONOK,0,MB_Slaveaddr,MB_StartDiscreetaddr);

							for (i=0;i<1+MB_NumbDiscreet/8;i++){
								for (n=0;n<8;n++){
									if (ucMDiscInBuf[i]&(1<<n))  iecasdu_create_type_1(outbuf+outbufLen,&outbufLen,1);
											else 				  iecasdu_create_type_1(outbuf+outbufLen,&outbufLen,0);
								}
							}

  	   	   	   	   	   	    // ------------- APCI -------------------
   	   	   	   	   	   	    iecasdu_add_APCI(outbuf, outbufLen);
   	   	   	   	   	   	    /*
							h->start = 0x68;
							h->length = outbufLen-2;
							h->ic.ft = 0;
							h->ic.ns = s->vs;
							h->ic.nr = s->vr;
							h->ic.res = 0;
							memcpy(outbuf, h, sizeof(struct iechdr));
							*/
							// !------------ APCI -------------------
							netconn_write(newconn, outbuf , outbufLen, NETCONN_COPY);

							s->vs = (s->vs + 1) % 32767;			// счетчик переданных
							s->xmit_cnt++;

							free(outbuf);
							USART_TRACE("освободил память outbuf в C_CI_NA_1\n");

							USART_TRACE("| 101 C_CI_NA_1: IDX:%i rqt:0x%02x frz:0x%02x\n",obj[0].ioa, obj[0].o.type101.rqt, obj[0].o.type101.frz);

						   break;

		   case C_RD_NA_1: /* 102 */		//ASDU Type ID 102 : C_RD_NA_1 - команда чтения
			   	   	   	   USART_TRACE("| 101 C_CI_NA_1: IDX:%i \n",obj[0].ioa);
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
							if (!outbuf) {
								USART_TRACE("Ошибка выделения памяти outbuf в C_CS_NA_1 запросе.\n");
								return;
							} else{
								USART_TRACE("Выделено памяти outbuf в C_CS_NA_1: %u байт.\n",sizeof(struct iec_buf) + 249);
							}

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
							USART_TRACE("освободил память outbuf в C_CS_NA_1\n");


							USART_TRACE("| 103 C_CS_NA_1: IDX:%i hour:%02d min:%02d\n",obj[0].ioa, obj[0].o.type103.time.hour, obj[0].o.type103.time.min);

						   break;
//		   case C_TS_NA_1: /* 104 */		//ASDU Type ID 104: C_TS_NA_1 - тестовая команда				не используется в 104 стандарте
//	   	   	   	   	   	   USART_TRACE("| 104 C_TS_NA_1: IDX:%i qoi:0x%02x\n",obj[0].ioa, obj[0].o.type104.res);
						   break;
		   case C_RP_NA_1: /* 105 */		//ASDU Type ID 105: C_RP_NA_1 - Reset Process Command
			   	   	   	   USART_TRACE("| 105 C_RP_NA_1: IDX:%i qoi:0x%02x\n",obj[0].ioa, obj[0].o.type105.res);
						   break;
		   case C_TS_TA_1: /* 107 */		//ASDU Type ID 107 : C_TS_TA_1 - тестовая команда с меткой времени CP56Время2а
			   	   	   	   USART_TRACE("| 107 C_TS_TA_1: IDX:%i qoi:0x%02x\n",obj[0].ioa, obj[0].o.type107.res);
						   break;
	   }
   }

}
/*************************************************************************
 * iecsock_set_options
 * счет идёт в мс
 *************************************************************************/
void iec104_set_options(struct iecsock *s, struct iecsock_options *opt)
{
	s->t0.cntdest = opt->t0*1000;
	s->t1.cntdest = opt->t1*1000;
	s->t2.cntdest = opt->t2*1000;
	s->t3.cntdest = opt->t3*1000;
	s->w = opt->w;
	s->k = opt->k;
}
/*************************************************************************
 * iecsock_set_defaults
 * t0_timer	- тайм-аут при установлении соединения
 * t1_timer	- тайм-аут при посылке или тестировании
 * t2_timer	- тайм-аут для подтверждения в случае отсутствия сообщения с данными
 * t3_timer	- тайм-аут для посылки блоков тестирования в случае долгого простоя
 *************************************************************************/
static void iec104_set_defaults(struct iecsock *s)
{
	s->t0.cntdest	= DEFAULT_T0*1000;
	s->t1.cntdest	= DEFAULT_T1*1000;
	s->t2.cntdest	= DEFAULT_T2*1000;
	s->t3.cntdest	= DEFAULT_T3*1000;
	s->w 	= DEFAULT_W;
	s->k	= DEFAULT_K;

	iec104_sframe_send(s);					// передача s фрейма после инита
	s->va_peer = s->vr;
}

/*************************************************************************
 * uframe_func_to_string
 *************************************************************************/
static inline char * uframe_func_to_string(enum uframe_func func)
{
	switch (func) {
	case STARTACT:
		return "STARTACT";
	case STARTCON:
		return "STARTCON";
	case STOPACT:
		return "STOPACT";
	case STOPCON:
		return "STOPCON";
	case TESTACT:
		return "TESTACT";
	case TESTCON:
		return "TESTCON";
	default:
		return "UNKNOWN";
	}
}

/*************************************************************************
 *
 *************************************************************************/
#endif

/*************************************************************************
 * Управление выключателем
 *************************************************************************/
void	CSWI_Pos_Oper_Set(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_CSWI1_Pos_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_CTRL_CSWI1_Pos_Oper_ctlVal, newState);
    if (newState) writeNmb = 1; else writeNmb = 2;

}

/*************************************************************************
 * Команды сброса флагов и индикации
 *************************************************************************/
void	GGIO_LEDGGIO1_SPCSO1_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_SPCSO1_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_SPCSO1_Oper_ctlVal, 0);
    if (newState) writeNmb = 3; //else writeNmb = 2;

}

void	GGIO_SPCSO1_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO1_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO1_Oper_ctlVal, 0);
    if (newState) writeNmb = 4; //else writeNmb = 2;

}
void	GGIO_SPCSO2_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO2_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO2_Oper_ctlVal, 0);
    if (newState) writeNmb = 5; //else writeNmb = 2;

}
void	GGIO_SPCSO3_Oper(bool newState, uint64_t timeStamp){

    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO3_Oper_T, timeStamp);
    IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_CTRL_GGIO1_SPCSO3_Oper_ctlVal, 0);
    if (newState) writeNmb = 6; //else writeNmb = 2;

}
