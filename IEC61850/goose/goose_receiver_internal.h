/*
 *  goose_receiver_internal.h
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

#ifndef GOOSE_RECEIVER_INTERNAL_H_
#define GOOSE_RECEIVER_INTERNAL_H_


#define ETH_BUFFER_LENGTH 1518

#define ETH_P_GOOSE 0x88b8

#ifndef DEBUG_GOOSE_SUBSCRIBER
#define DEBUG_GOOSE_SUBSCRIBER 		0
#endif

typedef struct sGooseReceiverCfg 	GooseReceiverCfg;
typedef struct sGooseReceiverMAC	GooseReceiverMAC;

// список MAC адресов
typedef struct sGooseReceiverMAC {
	uint8_t MAC[6];
	struct sGooseReceiverMAC* sibling;
};

// список ссылок гусов (устройства)
typedef struct sGooseReceiverGocbRef {
	uint16_t	numbGocbRef;						// номер записи			в файле конфига
	char*		gocbRef;							// гусс запись			в файле конфига
    uint16_t 	AppId;								// AppId для записи		в файле конфига
    uint32_t 	confRev;							// conRev				в файле конфига
	struct sGooseReceiverGocbRef* sibling;			// следующая запись
};

// таблица соответствия
struct sGooseReceiverCfg {
	uint16_t 			nGocbRef;					// отправитель гуса
	uint8_t 			nDataSetGoEntries;			// номер записи в датасете гуса
	uint8_t 			nGoEntries;					// номер дискрета для текущей записи
	bool	 			AddAllowedToLiveStatus;		// подмешивать потерю связи
	GooseReceiverCfg* 	sibling;					// следующий элемент
};

struct sGooseReceiverFile {
	GooseReceiverMAC*		GooseMACs;
	GooseReceiverGocbRef*	GocbRefs;
	GooseReceiverCfg*		GooseMatrix;
};

struct sGooseSubscriber {
	uint16_t 	NumGocbRef;			// номер гуса в списке, для быстрого поиска
    char* 		goCBRef;
    int 		goCBRefLen;
    uint32_t 	timeAllowedToLive;
    bool		lostGooseMessage;
    uint32_t 	stNum;
    uint32_t 	sqNum;
    uint32_t 	confRev;
    MmsValue* 	timestamp;
    bool 		simulation;
    bool 		ndsCom;

    uint64_t 	invalidityTime;
    bool 		stateValid;

    int32_t appId; /* APPID or -1 if APPID should be ignored */

    MmsValue* dataSetValues;
    bool dataSetValuesSelfAllocated;

    GooseListener listener;
    void* listenerParameter;

//    uint8_t destMAC[6];
};



#endif /* GOOSE_RECEIVER_INTERNAL_H_ */
