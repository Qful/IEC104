/*
 *  thread_linux.c
 *
 *  Copyright 2013 Michael Zillgith
 *
 *	This file is part of libIEC61850.
 *
 *	libIEC61850 is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	libIEC61850 is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with libIEC61850.  If not, see <http://www.gnu.org/licenses/>.
 *
 *	See COPYING file for the complete license text.
 */


#include "libiec61850_platform_includes.h"


//#include <pthread.h>
//#include <semaphore.h>
#include <stdlib.h>
//#include <unistd.h>
#include "hal_thread.h"
#include "main.h"

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "port.h"
#include "cmsis_os.h"
#include "queue.h"

struct sThread {
   ThreadExecutionFunction function;
   void* 		parameter;
   osThreadId	pthread;
   int 			state;
   bool 		autodestroy;
};


/*************************************************************************
 * Semaphore_create
 * ������ �������
 *************************************************************************/
Semaphore	Semaphore_create(int initialValue)
{
static	xSemaphoreHandle xIEC850Mutex = NULL;			// ������� ������� � TCP/IP ����� � ����
//extern xSemaphoreHandle xIEC850Mutex;

//	Semaphore self = NULL;
//    Semaphore self = malloc(sizeof(sem_t));
//    sem_init((sem_t*) self, 0, initialValue);

	//xIEC850Mutex = xSemaphoreCreateMutex();
	vSemaphoreCreateBinary( xIEC850Mutex);

	USART_TRACE_RED("������� ������� %X\n",(unsigned int)xIEC850Mutex);

    return xIEC850Mutex;
}

/* Wait until semaphore value is more than zero. Then decrease the semaphore value. */
/*************************************************************************
 * Semaphore_wait
 * ����������� ������� ��� ������ �� �����������.
 *************************************************************************/
void		Semaphore_wait(Semaphore xMutex)
{
//	USART_TRACE_RED("�������� ������� %X\n",xMutex);
	xSemaphoreTake( xMutex, portMAX_DELAY); 								// �������� ������� ������������ ����� portMAX_DELAY portTICK_RATE_MS

}
/*************************************************************************
 * Semaphore_post
 * ����� �������
 *************************************************************************/
void	Semaphore_post(Semaphore xMutex)
{
//	USART_TRACE_RED("������� ������� %X\n",xMutex);
	xSemaphoreGive( xMutex );
}
/*************************************************************************
 * Semaphore_destroy
 * ������� �������
 *************************************************************************/
void	Semaphore_destroy(Semaphore xMutex)
{
	USART_TRACE_RED("������� ������� %X\n",(unsigned int)xMutex);
	vSemaphoreDelete(xMutex);
}

/*********************************************************************************************
 * ������� ������ �� �����.
 * osThreadDef(USER_Thread, StartThread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE);
 * osThreadId ThreadId = osThreadCreate (osThread(USER_Thread), NULL);
 *
 * osThreadTerminate (ThreadId);
 *
 *********************************************************************************************/

/*************************************************************************
 * Thread_create
 * ������ (����������) �����
 * ��������� ���� ��� ���������.
 *************************************************************************/
Thread	Thread_create(ThreadExecutionFunction function, void* parameter, bool autodestroy)
{
	   Thread thread = (Thread) GLOBAL_MALLOC(sizeof(struct sThread));

   if (thread != NULL) {
		thread->parameter = parameter;			// ��������� ��� �������
		thread->function = function;			// ������� ����������� � (������)�����
		thread->state = 0;
		thread->autodestroy = autodestroy;		// �������������� ������.
   }
   return thread;
}

/*************************************************************************
 * destroyAutomaticThread
 * ��������� �����, ��������� ������� � ��������� �����.
 *************************************************************************/
static void	destroyAutomaticThread(void const *parameter)
{
    Thread 		thread = (Thread) parameter;
//    osThreadId	ThreadId = thread->pthread;

   thread->function(thread->parameter);				// ��������� �������

   GLOBAL_FREEMEM(thread);

   //osThreadTerminate(ThreadId);					// ��������� �����
   osThreadTerminate(osThreadGetId());				// ��������� ������� �����
}
/*************************************************************************
 * Thread_start
 * ��������� �����
 *************************************************************************/
void	Thread_start(Thread thread)
{
	// ������ � ��������� ���� ���� ���, � ����� �� �������.
	if (thread->autodestroy == true) {
		//pthread_create(&thread->pthread, NULL, destroyAutomaticThread, thread);
		//pthread_detach(thread->pthread);
		osThreadDef(GooseRe, destroyAutomaticThread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE*8);
		thread->pthread = osThreadCreate (osThread(GooseRe), thread);

	}
	// ������ � ��������� ����.
	else {
		//pthread_create(&thread->pthread, NULL, thread->function, thread->parameter);
		osThreadDef(GooseRe, thread->function, osPriorityNormal, 0, configMINIMAL_STACK_SIZE*8);
		thread->pthread = osThreadCreate (osThread(GooseRe), thread->parameter);
	}

	thread->state = 1;
}
/*************************************************************************
 * Thread_destroy
 * ���������������� ���� �����, ���� thread->pthread �� �����������.
 *
 * ������� pthread_join() ���������������� ���������� ����� �� ��� ���, ���� ��������� ������ ���������� ����� �� ���������� (���� �� ��� �� ��������).
 * �����, pthread_join() ����������� ��������� �������������� ������ � �� ������, ���������� ������ ���������� (���� �� �� ����� NULL), ������� ������ ���������� ������.
 *
 *************************************************************************/
void	Thread_destroy(Thread thread)
{
	osStatus	osRet;
   if (thread->state == 1) {

	   //������� pthread_join() ������������ ��� �������� ���������� ������:
	   //pthread_join(thread->pthread, NULL);

	   osRet = osThreadTerminate (thread->pthread);			// ������� �����
	   if(osRet != osOK){
		   USART_TRACE_RED("������ ���������� ������:%i \n",osRet);
	   }

   }

   GLOBAL_FREEMEM(thread);
}

void	Thread_sleep(int millies)
{
	osDelay(millies);
//	usleep(millies * 1000);
}

