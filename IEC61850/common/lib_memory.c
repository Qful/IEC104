/*
 *  lib_memory.c
 *
 *  Copyright 2014 Michael Zillgith
 *
 *  This file is part of libIEC61850.
 *
 *  libIEC61850 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libIEC61850 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libIEC61850.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  See COPYING file for the complete license text.
 */

#include "libiec61850_platform_includes.h"

uint32_t	GLOBALMemoryUsedLim = 0;							//максимально использованной памяти
uint32_t	GLOBALMemoryUsedCurr = 0;							//текущее выделение


static MemoryExceptionHandler exceptionHandler = NULL;
static void* exceptionHandlerParameter = NULL;

static void
noMemoryAvailableHandler(void)
{
    if (exceptionHandler != NULL)
        exceptionHandler(exceptionHandlerParameter);
}

void
Memory_installExceptionHandler(MemoryExceptionHandler handler, void* parameter)
{
    exceptionHandler = handler;
    exceptionHandlerParameter = parameter;
}

void*
Memory_malloc(size_t size)
{
	portENTER_CRITICAL();
	//taskENTER_CRITICAL();
    void* memory = malloc(size);
    //taskEXIT_CRITICAL();
    portEXIT_CRITICAL();
//    printf("Memory_malloc 0x%x:%u\n", memory,size);

    if (memory == NULL){
        noMemoryAvailableHandler();
    } else{
    	uint32_t	tmp = (uint32_t)memory + (uint32_t)size;
    	if (GLOBALMemoryUsedLim<tmp) GLOBALMemoryUsedLim = tmp;
    }

    return memory;
}


void*
Memory_calloc(size_t nmemb, size_t size)
{
	portENTER_CRITICAL();
	//taskENTER_CRITICAL();
    void* memory = calloc(nmemb, size);
    //taskEXIT_CRITICAL();
    portEXIT_CRITICAL();

//    printf("Memory_calloc 0x%x:%u\n", memory,size);

    if (memory == NULL){
        noMemoryAvailableHandler();
    }else{
    	GLOBALMemoryUsedCurr = (uint32_t)memory + (uint32_t)size*(uint32_t)nmemb;
    	if (GLOBALMemoryUsedLim<GLOBALMemoryUsedCurr) GLOBALMemoryUsedLim = GLOBALMemoryUsedCurr;
    }

    return memory;
}


void *
Memory_realloc(void *ptr, size_t size)
{

	portENTER_CRITICAL();
	//taskENTER_CRITICAL();
    void* memory = realloc(ptr, size);
    //taskEXIT_CRITICAL();
    portEXIT_CRITICAL();
//    printf("Memory_realloc 0x%x:%u\n", memory,size);

    if (memory == NULL){
        noMemoryAvailableHandler();
    }else{
    	GLOBALMemoryUsedCurr = (uint32_t)memory + (uint32_t)size;
    	if (GLOBALMemoryUsedLim<GLOBALMemoryUsedCurr) GLOBALMemoryUsedLim = GLOBALMemoryUsedCurr;
    }

    return memory;
}

void
Memory_free(void* memb)
{
	portENTER_CRITICAL();
	//taskENTER_CRITICAL();
    free(memb);
    //taskEXIT_CRITICAL();
    portEXIT_CRITICAL();


//    printf("Memory_free 0x%x\n",memb);

}

