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


//#include <pthread.h>
//#include <semaphore.h>
#include <stdlib.h>
#include "thread.h"

struct sThread {
	ThreadExecutionFunction function;
	void* parameter;
	//pthread_t pthread;
	int state;
	bool autodestroy;
};
/*
 * Создаём семафор
 *
 */
Semaphore	Semaphore_create(int initialValue)
{
	Semaphore self = NULL;
//    Semaphore self = malloc(sizeof(sem_t));
//    sem_init((sem_t*) self, 0, initialValue);
    return self;
}

/* Wait until semaphore value is more than zero. Then decrease the semaphore value. */
void
Semaphore_wait(Semaphore self)
{

}

void
Semaphore_post(Semaphore self)
{

}

void
Semaphore_destroy(Semaphore self)
{

}

Thread
Thread_create(ThreadExecutionFunction function, void* parameter, bool autodestroy)
{


	return 0;
}

static void*
destroyAutomaticThread(Thread thread)
{

}

void
Thread_start(Thread thread)
{

}

void
Thread_destroy(Thread thread)
{

}

void
Thread_sleep(int millies)
{
//	usleep(millies * 1000);
}

