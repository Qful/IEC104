/*
 *  goose_subscriber.c
 *
 *  Copyright 2013, 2014 Michael Zillgith
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

#include "stack_config.h"
#include "goose_subscriber.h"
#include "hal_ethernet.h"
#include "hal_thread.h"

#include "ber_decode.h"

#include "mms_value.h"
#include "mms_value_internal.h"

#include "goose_receiver_internal.h"

GooseSubscriber
GooseSubscriber_create(GooseReceiverGocbRef* goCbRef, MmsValue* dataSetValues)
{
    GooseSubscriber self = (GooseSubscriber) GLOBAL_CALLOC(1, sizeof(struct sGooseSubscriber));

 //   if (MAC != NULL)
 //   	memcpy(self->destMAC,MAC,6);

    self->confRev 		= goCbRef->confRev;
    self->NumGocbRef 	= goCbRef->numbGocbRef;
    self->goCBRef 		= copyString(goCbRef->gocbRef);
    self->goCBRefLen 	= strlen(goCbRef->gocbRef);
    self->timestamp 	= MmsValue_newUtcTime(0);
    self->dataSetValues = dataSetValues;

    if (dataSetValues != NULL)
        self->dataSetValuesSelfAllocated = false;

    self->appId = -1;

    return self;
}
/*************************************************************************
 * GooseSubscriber_isValid
 * проверка на провалы в обменах(пропуск 3-х кратного максимального времени)
 *************************************************************************/
bool	GooseSubscriber_isValid(GooseSubscriber self)
{
	bool ret = true;
	uint64_t	tim=Hal_getTimeInMs();
	uint64_t    itim = self->invalidityTime;

    if (tim > itim)   ret = false;
//    if ((ret == false)&&(itim>0)) USART_TRACE_RED("stateValid false:%u 0x%X > 0x%X\n",self->NumGocbRef,(unsigned int)tim,(unsigned int)itim);
    if (self->stateValid == false)    ret = false;

    return ret;
}

void
GooseSubscriber_setAppId(GooseSubscriber self, uint16_t appId)
{
    self->appId = (int32_t) appId;
}

void
GooseSubscriber_destroy(GooseSubscriber self)
{
    GLOBAL_FREEMEM(self->goCBRef);

    MmsValue_delete(self->timestamp);

    if (self->dataSetValuesSelfAllocated)
        MmsValue_delete(self->dataSetValues);

    GLOBAL_FREEMEM(self);
}

void
GooseSubscriber_setListener(GooseSubscriber self, GooseListener listener, void* parameter)
{
    self->listener = listener;
    self->listenerParameter = parameter;
}

uint32_t
GooseSubscriber_getStNum(GooseSubscriber self)
{
    return self->stNum;
}

uint32_t
GooseSubscriber_getSqNum(GooseSubscriber self)
{
    return self->sqNum;
}

bool
GooseSubscriber_isTest(GooseSubscriber self)
{
    return self->simulation;
}

uint32_t
GooseSubscriber_getConfRev(GooseSubscriber self)
{
    return self->confRev;
}

bool
GooseSubscriber_needsCommission(GooseSubscriber self)
{
    return self->ndsCom;
}

uint32_t
GooseSubscriber_getTimeAllowedToLive(GooseSubscriber self)
{
    return self->timeAllowedToLive;
}

uint64_t
GooseSubscriber_getTimestamp(GooseSubscriber self)
{
    return MmsValue_getUtcTimeInMs(self->timestamp);
}

MmsValue*
GooseSubscriber_getDataSetValues(GooseSubscriber self)
{
    return self->dataSetValues;
}

char*
GooseSubscriber_getGoCBRef(GooseSubscriber self)
{
    return self->goCBRef;
}

uint32_t
GooseSubscriber_getNumGoose(GooseSubscriber self)
{
    return self->NumGocbRef;
}

bool
GooseSubscriber_isLostGooseMessage(GooseSubscriber self)
{
    return self->lostGooseMessage;
}

void
GooseSubscriber_setLostGooseMessage(GooseSubscriber self, bool dat)
{
    self->lostGooseMessage = dat;
}






