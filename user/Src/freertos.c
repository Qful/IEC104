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

#include "main.h"

#include "lwip.h"
#include "lwip/init.h"
#include "lwip/netif.h"

#include "lwip/api.h"
#include "lwip/sys.h"

//#include "ethernetif.h"
//#include "lwip/tcpip.h"
//#include "lwip/netif.h"

/* Variables -----------------------------------------------------------------*/
osThreadId defaultTaskHandle;

struct netif 	first_gnetif,second_gnetif;
struct ip_addr 	first_ipaddr,second_ipaddr;
struct ip_addr 	netmask;
struct ip_addr 	gw;

/* Function prototypes -------------------------------------------------------*/
void StartIEC104Task(void const * argument);

extern void MX_LWIP_Init(void);
extern void tcpecho_init(void);
extern void udpecho_init(void);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/* Hook prototypes */


/*************************************************************************
 * FREERTOS_Init
 *************************************************************************/
void MX_FREERTOS_Init(void) {
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
  osThreadDef(IEC104, StartIEC104Task, osPriorityNormal,0, 128);
  defaultTaskHandle = osThreadCreate(osThread(IEC104), NULL);

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
 void *data;

//	MX_LWIP_Init();		// инит. LWIP

	tcpip_init( NULL, NULL );

	// устанавливаем IP параметры для первичного IP соединения, всегда сервер
	IP4_ADDR(&first_ipaddr, first_IP_ADDR0, first_IP_ADDR1, first_IP_ADDR2, first_IP_ADDR3);
	// устанавливаем IP параметры для вторичного IP соединения, всегда хост
	IP4_ADDR(&second_ipaddr, second_IP_ADDR0, second_IP_ADDR1, second_IP_ADDR2, second_IP_ADDR3);

	IP4_ADDR(&netmask, NETMASK_ADDR0, NETMASK_ADDR1 , NETMASK_ADDR2, NETMASK_ADDR3);
	IP4_ADDR(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);

// для автоматического получения IP
// first_ipaddr.addr = 0;
//netmask.addr = 0;
//gw.addr = 0;

	// добавим  и регистрируем NETWORK интерфейс
	netif_add(&first_gnetif, &first_ipaddr, &netmask, &gw, NULL, &ethernetif_init, &tcpip_input);
	netif_set_default(&first_gnetif);

	if (netif_is_link_up(&first_gnetif))
		netif_set_up(&first_gnetif);		// When the netif is fully configured this function must be called
	else
		netif_set_down(&first_gnetif);		// When the netif link is down this function must be called

	//dhcp_start(&first_gnetif);		// автоматическое получение IP

  for(;;)
  {


	conn = netconn_new(NETCONN_TCP);											// создадим новое соединение
	  if (conn!=NULL){
		err = netconn_bind(conn, &first_ipaddr, ECHO_Port);						// привяжем соединение на IP и порт IEC 60870-5-104 (IEC104_Port)
	    if (err == ERR_OK)
	    {
	        netconn_listen(conn);												// переводим соединение в режим прослушивания
	        while (1)															// далее слушаем и  захватываем соединение
	        {
	             accept_err = netconn_accept(conn, &newconn);					// принимаем соединение
	             if (accept_err == ERR_OK)										// если приняли, то обработаем его
	             {
	                 while (netconn_recv(newconn, &buf) == ERR_OK)				// принимаем данные в буфер
	                 {
	                     do
	                     {
	                       netbuf_data(buf, &data, &len);
	                       netconn_write(newconn, data, len, NETCONN_COPY);		// отправляем данные по протоколу TCP

	                     }
	                     while (netbuf_next(buf) >= 0);
	                     netbuf_delete(buf);
	                 }
	                 netconn_close(newconn);									// закрываем и освобождаем соединение
	                 netconn_delete(newconn);
	             }
	        }
	    }
	    else      netconn_delete(newconn);
	  }

    osDelay(1);
  }
}

