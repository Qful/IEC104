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


#include "lwip/api.h"
#include "lwip/sys.h"

//#include "ethernetif.h"
//#include "lwip/tcpip.h"
//#include "lwip/netif.h"

/* Variables -----------------------------------------------------------------*/
osThreadId defaultTaskHandle;


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
 err_t err,recv_err, accept_err;;
 struct netbuf *buf;
 struct ip_addr *addr;
 unsigned short port;
 uint16_t len;
 void *data;

	MX_LWIP_Init();		// инит. LWIP

	// нужно делать 2 независимых таска

	/* Initialize tcp echo server создаётся таск!!!!*/
	//tcpecho_init();
	/* Initialize udp echo server создаётся таск!!!!*/
	//udpecho_init();

  for(;;)
  {

  /* Create a new connection identifier. */
	conn = netconn_new(NETCONN_UDP);
	  if (conn!= NULL) {
			err = netconn_bind(conn, IP_ADDR_ANY, 7);
			if (err == ERR_OK){
				while (1)
				  {
					recv_err = netconn_recv(conn, &buf);

					if (recv_err == ERR_OK){
					  addr = netbuf_fromaddr(buf);
					  port = netbuf_fromport(buf);
					  netconn_connect(conn, addr, port);
					  buf->addr.addr = 0;
					  netconn_send(conn,buf);
					  netbuf_delete(buf);
					}
				  }
			}
			else	netconn_delete(conn);
	  }

  /* Create a new connection identifier. */
	conn = netconn_new(NETCONN_TCP);
	  if (conn!=NULL){
		/* Bind connection to well known port number 7. */
		err = netconn_bind(conn, NULL, 7);
	    if (err == ERR_OK)
	    {
	        /* Tell connection to go into listening mode. */
	        netconn_listen(conn);
// !!!!!! переделать, объединив с  UDP циклом
	        while (1)
	        {
	            /* Grab new connection. */
	             accept_err = netconn_accept(conn, &newconn);
	             /* Process the new connection. */
	             if (accept_err == ERR_OK)
	             {
	                 while (netconn_recv(newconn, &buf) == ERR_OK)
	                 {
	                     do
	                     {
	                       netbuf_data(buf, &data, &len);
	                       netconn_write(newconn, data, len, NETCONN_COPY);

	                     }
	                     while (netbuf_next(buf) >= 0);
	                     netbuf_delete(buf);
	                 }
	                 /* Close connection and discard connection identifier. */
	                 netconn_close(newconn);
	                 netconn_delete(newconn);
	             }
	        }
	    }
	    else      netconn_delete(newconn);
	  }

    osDelay(1);
  }
}

