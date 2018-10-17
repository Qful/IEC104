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
 * создаём семафор
 *************************************************************************/
Semaphore	Semaphore_create(int initialValue)
{
static	xSemaphoreHandle xIEC850Mutex = NULL;			// мьютекс доступа в TCP/IP буфер и стек
//extern xSemaphoreHandle xIEC850Mutex;

//	Semaphore self = NULL;
//    Semaphore self = malloc(sizeof(sem_t));
//    sem_init((sem_t*) self, 0, initialValue);

	//xIEC850Mutex = xSemaphoreCreateMutex();
taskENTER_CRITICAL();
	vSemaphoreCreateBinary( xIEC850Mutex);
taskEXIT_CRITICAL();
	USART_TRACE_RED("Создали семафор %X\n",(unsigned int)xIEC850Mutex);

    return xIEC850Mutex;
}

/* Wait until semaphore value is more than zero. Then decrease the semaphore value. */
/*************************************************************************
 * Semaphore_wait
 * захватываем семафор как только он освободится.
 *************************************************************************/
void		Semaphore_wait(Semaphore xMutex)
{
	//	USART_TRACE_RED("забираем семафор %X\n",xMutex);
//	taskENTER_CRITICAL();
	if (xMutex) xSemaphoreTake( xMutex, portMAX_DELAY); 								// подождем семафор освобождения порта portMAX_DELAY portTICK_RATE_MS
//	taskEXIT_CRITICAL();
}
/*************************************************************************
 * Semaphore_post
 * отдаём семафор
 *************************************************************************/
void	Semaphore_post(Semaphore xMutex)
{
	//	USART_TRACE_RED("вернули семафор %X\n",xMutex);
//	taskENTER_CRITICAL();
	if (xMutex) xSemaphoreGive( xMutex );
//	taskEXIT_CRITICAL();
}
/*************************************************************************
 * Semaphore_destroy
 * удаляем семафор
 *************************************************************************/
void	Semaphore_destroy(Semaphore xMutex)
{
	USART_TRACE_RED("Удалили семафор %X\n",(unsigned int)xMutex);
//	taskENTER_CRITICAL();
	if (xMutex) vSemaphoreDelete(xMutex);
//	taskEXIT_CRITICAL();
}

/*********************************************************************************************
 * заменим потоки на таски.
 * osThreadDef(USER_Thread, StartThread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE);
 * osThreadId ThreadId = osThreadCreate (osThread(USER_Thread), NULL);
 *
 * osThreadTerminate (ThreadId);
 *
 *********************************************************************************************/

/*************************************************************************
 * Thread_create
 * создаём (конфигурим) поток
 * создается таск для обработки.
 *************************************************************************/
Thread	Thread_create(ThreadExecutionFunction function, void* parameter, bool autodestroy)
{
	   Thread thread = (Thread) GLOBAL_MALLOC(sizeof(struct sThread));

   if (thread != NULL) {
		thread->parameter = parameter;			// параметры для функции
		thread->function = function;			// функция выполняемая в (потоке)таске
		thread->state = 0;
		thread->autodestroy = autodestroy;		// автозавершение потока.
   }
   return thread;
}

/*************************************************************************
 * destroyAutomaticThread
 * запускаем поток, выполняем функцию и завершаем поток.
 *************************************************************************/
static void	destroyAutomaticThread(void const *parameter)
{
   Thread 		thread = (Thread) parameter;

   thread->function(thread->parameter);				// выполняем функцию

   GLOBAL_FREEMEM(thread);

   osThreadTerminate(osThreadGetId());				// завершаем текущий поток
}
/*************************************************************************
 * Thread_start
 * запускаем поток
 *************************************************************************/
void	Thread_start(Thread thread, osPriority	prior, uint16_t		STACK_SIZE, char* name)
{
	  TaskHandle_t handle;

	  //osThreadId osThreadCreate (const osThreadDef_t *thread_def, void *argument){
	  //if (xTaskCreate((TaskFunction_t)thread_def->pthread,(const portCHAR *)thread_def->name,thread_def->stacksize, argument, makeFreeRtosPriority(thread_def->tpriority),&handle) != pdPASS)

	// создаём и запускаем таск который сам удалится
	if (thread->autodestroy == true) {

		xTaskCreate((TaskFunction_t)destroyAutomaticThread, name, STACK_SIZE, ( void * ) thread, prior - osPriorityIdle, &handle );
		thread->pthread = handle;
	//	osThreadDef(GooseRe, destroyAutomaticThread, prior, 0, STACK_SIZE);		//osPriorityNormal
	//	thread->pthread = osThreadCreate (osThread(GooseRe), thread);
	}
	else {
		xTaskCreate((TaskFunction_t)thread->function, name, STACK_SIZE, ( void * ) thread->parameter, prior - osPriorityIdle, &handle );
		thread->pthread = handle;
	//	osThreadDef(GooseRe, thread->function, prior, 0, STACK_SIZE);			//osPriorityNormal
	//	thread->pthread = osThreadCreate (osThread(GooseRe), thread->parameter);
	}

	thread->state = 1;
}
/*************************************************************************
 * Thread_destroy
 * Приостанавливаем свой поток, пока thread->pthread не завершиться.
 *
 * Функция pthread_join() приостанавливает вызывающий поток до тех пор, пока указанный первым аргументом поток не завершится (если он уже не завершен).
 * Далее, pthread_join() освобождает описатель завершившегося потока и по адресу, указанному вторым аргументом (если он не равен NULL), заносит статус завершения потока.
 *
 *************************************************************************/
void	Thread_destroy(Thread thread)
{
	osStatus	osRet;
   if (thread->state == 1) {

	   //Функция pthread_join() используется для ожидания завершения потока:
	   //pthread_join(thread->pthread, NULL);

	   osRet = osThreadTerminate (thread->pthread);			// удаляем поток
	   if(osRet != osOK){
		   USART_TRACE_RED("Ошибка завершения потока:%i \n",osRet);
	   }

   }

   GLOBAL_FREEMEM(thread);
}

void	Thread_sleep(int millies)
{
	osDelay(millies);
//	usleep(millies * 1000);
}

