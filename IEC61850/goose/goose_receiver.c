/*
 *  goose_receiver.c
 *
 *  Copyright 2014, 2015 Michael Zillgith
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

#include "hal_ethernet.h"
#include "hal_thread.h"

#include "ber_decode.h"

#include "mms_value.h"
#include "mms_value_internal.h"
#include "linked_list.h"

#include "lwipopts.h"
#include "lwip/opt.h"

#include "goose_subscriber.h"
#include "goose_receiver.h"
#include "goose_receiver_internal.h"
#include "goose_config.h"

#include "modbus.h"

#ifndef DEBUG_GOOSE_SUBSCRIBER
#define DEBUG_GOOSE_SUBSCRIBER 0
#endif

#define ETH_BUFFER_LENGTH 1518

#define ETH_P_GOOSE 0x88b8

//-------------------------------------------------------------------
extern xQueueHandle 	ModbusSentTime;		// очередь для отправки в модбас
extern xQueueHandle 	ModbusSentQueue;	// очередь для отправки в модбас

extern uint16_t   		ucGooseBufSent[MB_Size_Goose];
extern uint16_t   		ucGooseBufDrop[MB_Size_Goose];
//-------------------------------------------------------------------
// флаги новой записи в журнале
extern bool		NewSysNoteMessage;
extern bool		NewErrorNoteMessage;
//-------------------------------------------------------------------

bool		GooseDataModify = false;
//-------------------------------------------------------------------
//-------------------------------------------------------------------

struct sGooseReceiver {
    bool 				running;
    bool 				stopped;
    char* 				interfaceId;
    uint8_t* 			buffer;
    EthernetSocket 		ethSocket;
    GooseReceiverCfg*	GooseMatrix;
    GooseReceiverMAC*	GooseMACs;
    LinkedList 			subscriberList;
};
/*************************************************************************
 * gooseListener
 * смотрим что там пришло
 * parameter - matrix сама матрица из файла конфига на что настроен приём.
 *
 *
 * записи в конфиге начинаются не с '0'
 * PosBitinDB - 1
 * i+1
 *************************************************************************/
void	gooseListener(GooseSubscriber subscriber, void* parameter)
{
	bool		res[10];
	uint8_t		sizeRes=0;
	uint8_t		i,j;
	uint32_t	nEntries;
	uint8_t		nDBword;
	uint8_t		nDBbit;
	uint8_t		PosBitinDB;

	GooseReceiverCfg* element;

    MmsValue* values = GooseSubscriber_getDataSetValues(subscriber);

    nEntries = MmsValue_getArraySize(values);													// число элементов  в самом вызове
    uint32_t	NumGocbRef = GooseSubscriber_getNumGoose(subscriber);							// отправитель гуса в самом вызове
    uint32_t	GocbConfRev = GooseSubscriber_getConfRev(subscriber);							// confRev в принятом гусе

    GooseDataModify = false;

    for (i=0; i < nEntries;i++)																// номер записи в датасете гуса
    {
    	// ищем номер бита DB по номеру записи DS гуса
    	    PosBitinDB = 0;
    	    element = (GooseReceiverCfg*)parameter;

    	    while (element != NULL) {

    	      if(element->nGocbRef == NumGocbRef)
    	    	if (element->nDataSetGoEntries == i+1) {										// номер записи в датасете гуса
    	    		PosBitinDB = element->nGoEntries - 1;										// номер дискрета для текущей записи

    	    	   	   MmsValue* valueElemen = MmsValue_getElement(values,i);
    	    	    	    switch (MmsValue_getType(valueElemen)) {
    	    	    	    case MMS_BIT_STRING:
    	    	    	    	if (MmsValue_getBitStringSize(valueElemen) == 2){
    	    	    	    		res[0] = MmsValue_getBitStringBit(valueElemen,0);
    	    	    	    		res[1] = MmsValue_getBitStringBit(valueElemen,1);
    	    	    	    		sizeRes = 2;
    	    	    	    	}else{
	    	    	    			portENTER_CRITICAL();
    	    	    	    		// это кволити
    	    	    	    		res[0] = !MmsValue_getAllBitStringBits(valueElemen);				// прямое качество из гус сообщения (0-good)
	    	    	    			sizeRes = 1;
	    	    	    			portEXIT_CRITICAL();
    	    	    	    	}
    	    	    	        break;
    	    	    	    case MMS_BOOLEAN:
    	    	    	    		res[0] = MmsValue_getBoolean(valueElemen);
    	    	    	    		sizeRes = 1;
    	    	    	        break;
    	    	    	    default:
    	    	    	        break;
    	    	    	    }

    	    	    	    nDBword = PosBitinDB / 16;
    	    	    		nDBbit = (PosBitinDB % 16);
    	    				for(j=0;j<sizeRes;j++){
    	    					// проверим, изменились ли данные, если да, то шлем в МБ
    	    					portDISABLE_INTERRUPTS();
    	    					if (res[j] != (bool)(ucGooseBufSent[nDBword] & (1 << (nDBbit+j)))){

//TODO: только для отладки. убрать в рабочей прошивке
#if (0)
								{
    	    					uint32_t stnum = GooseSubscriber_getStNum(subscriber);
    	    					uint32_t sqnum = GooseSubscriber_getSqNum(subscriber);
   	    						USART_TRACE_RED("отправитель %u, stnum:%u sqnum:%u Изменение в %u записи. Бит MB:%u \n",NumGocbRef,stnum,sqnum,i+1,PosBitinDB+1);
								}
#endif

    	    						GooseDataModify = true;
    	    					}
    	    					if (res[j] == true )	ucGooseBufSent[nDBword] |= (1 << (nDBbit+j));		// добавим прямые данные в буфер отправки МБ
    	    					else					ucGooseBufSent[nDBword] &= ~(1 << (nDBbit+j));
    	    					portENABLE_INTERRUPTS();
    	    	    		}

    	    	}// !if (element->nGoEntries ==
    	        element = element->sibling;		// следующий
    	    }
	}
    //--------------------------------------------------------------------
    // нужно передать сразу
#if ((defined	(MR761) || defined	(MR762) || defined	(MR763)) && (_REVISION_DEVICE <=303)) || (defined	(MR771) && (_REVISION_DEVICE <=106)) ||\
	(defined	(MR801) && (_REVISION_DEVICE <=299)) ||\
	((defined	(MR901) || defined	(MR902)) && (_REVISION_DEVICE <=212)) ||\
	(defined	(MR851) && (_REVISION_DEVICE <=202))
//			старые приборы не шлём гус
	USART_TRACE_RED("прибор не поддерживает передачу goose\n");

#elif ((defined (MR5_500) || defined (MR5_600) || defined (MR5_700)) || defined (MR741))
    //		в этих приборах шлём команды вместо GoIN
	if (GooseDataModify == true)
    {
		// прогоним все биты и отправим команды
		int i;
		int off = 0;
		for (i=0;i<MB_NumbCMDGoose;i++) {
			if ((ucGooseBufSent[0] & (1<<i))>0){

		    	eMBMasterReqErrCode		errorSent 	 = MB_MRE_ILL_ARG;
		    	ModbusMessage 			pxTxMessage;

				// команды -------
				switch(i){
				case 0:	AddToQueueMB(ModbusSentTime, MB_Wrt_Reset_LEDS		,MB_Slaveaddr); 	break;
				case 1:	AddToQueueMB(ModbusSentTime, MB_Wrt_Reset_Error		,MB_Slaveaddr); 	break;
				case 2:	AddToQueueMB(ModbusSentTime, MB_Wrt_Reset_SysNote	,MB_Slaveaddr); NewSysNoteMessage = false; 		break;
				case 3:	AddToQueueMB(ModbusSentTime, MB_Wrt_Reset_ErrorNote	,MB_Slaveaddr); NewErrorNoteMessage = false; 	break;
#if !defined (MR5_600)
				case 4:	AddToQueueMB(ModbusSentTime, MB_Wrt_SwOFF			,MB_Slaveaddr); off = 1;	break;
				case 5:
						if (off == 0){
							AddToQueueMB(ModbusSentTime, MB_Wrt_SwON			,MB_Slaveaddr);
						}
					break;
#endif
				}


				if( xQueueReceive( ModbusSentTime, &(pxTxMessage),( TickType_t ) 0 ) )
				{
					errorSent = eMBMasterSendMessage(&pxTxMessage,RT_WAITING_NO);

					if (errorSent == MB_MRE_NO_ERR) {
						eMBMasterPoll();	// шлём сразу.
					} else{
						USART_TRACE_RED("Ошибка отправки команды гуса\n");
						xQueueSendToFront( ModbusSentTime, ( void * )&pxTxMessage, portMAX_DELAY);
					}
				}//!if(
			}
		}
    }//!if (GooseDataModify == true)

#else
// тут бывает только когда есть приём гуса.

	if (GooseDataModify == true)
    {
		AddToQueueMB(ModbusSentTime, MB_Wrt_Set_Goose	,MB_Slaveaddr);
		AddToQueueMB(ModbusSentTime, MB_Wrt_Set_Goose	,MB_Slaveaddr);

    	eMBMasterReqErrCode		errorSent 	 = MB_MRE_ILL_ARG;
    	ModbusMessage 			pxTxMessage;

		if( xQueueReceive( ModbusSentTime, &(pxTxMessage),( TickType_t ) 0 ) )
		{
			errorSent = eMBMasterSendMessage(&pxTxMessage,RT_WAITING_NO);

			if (errorSent == MB_MRE_NO_ERR) {
				eMBMasterPoll();	// шлём сразу.
			} else{
				USART_TRACE_GREEN("Ошибка отправки гуса\n");
				xQueueSendToFront( ModbusSentTime, ( void * )&pxTxMessage, portMAX_DELAY);	// не получилось сразу, передача в очередь сообщения в начало
			}
		}
    }//!if (GooseDataModify == true)

#endif
}
/*****************************************************************************************************
 * GooseReceiver_getConfigFile
 * конфигурация приёмника гусов из (структуры)файла
 *****************************************************************************************************/
void	GooseReceiver_addSubscriberFromConfigFile(GooseReceiver self, GooseReceiverFile* cfgFile)
{
	GooseSubscriber			subscriber;
	GooseReceiverGocbRef*	gocbRefs;

	if (self == NULL)		return;
	if (cfgFile == NULL)	return;

	gocbRefs = cfgFile->GocbRefs;

	self->GooseMatrix = cfgFile->GooseMatrix;								// добавим матрицу для расшифровки
	self->GooseMACs = cfgFile->GooseMACs;									// добавим список MAC адресов гусов

    while (gocbRefs != NULL) {

    	subscriber = GooseSubscriber_create(gocbRefs, NULL);						// подписываемся на гус.
    	GooseSubscriber_setAppId(subscriber,gocbRefs->AppId);						//конфигурим AppId
	    GooseSubscriber_setListener(subscriber, gooseListener,self->GooseMatrix);	// функция для обработки конкретного принятого гуса
	    GooseReceiver_addSubscriber(self, subscriber);
//		USART_TRACE("gooseListener:%s, AppId:%u\n",gocbRefs->gocbRef,gocbRefs->AppId);

	    gocbRefs = gocbRefs->sibling;									// следующий элемент
	}
}
/*****************************************************************************************************
 *GooseReceiver_ConfigCreate
 *****************************************************************************************************/
GooseReceiverFile*	GooseReceiver_ConfigCreate(){

	GooseReceiverFile*	self = (GooseReceiverFile*) GLOBAL_MALLOC(sizeof(struct sGooseReceiverFile));

	if (self != NULL) {
		//self->GooseMACs   = NULL;
		//self->GocbRefs    = NULL;
		//self->GooseMatrix = NULL;
	        self->GooseMACs = GooseReceiverMAC_create();
	        self->GocbRefs = GooseReceiverGocbRef_create();
	        self->GooseMatrix = GooseReceiverCfg_create();
	    }
    return self;
}

/*****************************************************************************************************
 *GooseReceiver_ConfigDestroy
 *****************************************************************************************************/
void	GooseReceiver_ConfigDestroy(GooseReceiverFile* self)
{

    if (self->GooseMACs)   GLOBAL_FREEMEM(self->GooseMACs);
    if (self->GocbRefs)    GLOBAL_FREEMEM(self->GocbRefs);
    if (self->GooseMatrix) GLOBAL_FREEMEM(self->GooseMatrix);
    if (self) GLOBAL_FREEMEM(self);
}
/*****************************************************************************************************
 * newStringwithSize
 * GooseReceiverMAC
 *****************************************************************************************************/
char*	newStringwithSize(const char* string, int size)
{
	int	i;
	char* self = (char*) GLOBAL_CALLOC(1, size+1);

    if (self == NULL) return self;

    for(i=0;i<size;i++){
    	self[i] = string[i];
    }
    self[size] = 0;
//    memcpy (self,string,(size_t)size);
//    strncpy (self,string,(size_t)size);			// почемуто не правильный размер копирует иногда

    return self;
}
/*****************************************************************************************************
 * GooseReceiverMAC_create
 * GooseReceiverMAC
 *****************************************************************************************************/
GooseReceiverMAC*	GooseReceiverMAC_create(void)
{
	GooseReceiverMAC* newElement;
	newElement = (GooseReceiverMAC*) GLOBAL_MALLOC(sizeof(struct sGooseReceiverMAC));
	int var;
	for (var = 0; var < 6; ++var)
		newElement->MAC[var]=0;

	newElement->sibling = NULL;
    return newElement;
}

/*****************************************************************************************************
 * GooseReceiverGocbRef_add
 * GooseReceiverGocbRef
 *****************************************************************************************************/
GooseReceiverMAC*	GooseReceiverMAC_add(GooseReceiverMAC* Cfg)
{
	GooseReceiverMAC* newElement = GooseReceiverMAC_create();
	while (Cfg->sibling){
		Cfg = Cfg->sibling;
	}
	Cfg->sibling = newElement;

return 	newElement;
}
/*****************************************************************************************************
 * GooseReceiverGocbRef_create
 * GooseReceiverGocbRef
 *****************************************************************************************************/
GooseReceiverGocbRef*	GooseReceiverGocbRef_create()
{
	GooseReceiverGocbRef* newElement;
	newElement = (GooseReceiverGocbRef*) GLOBAL_MALLOC(sizeof(struct sGooseReceiverGocbRef));
	newElement->gocbRef = NULL;
	newElement->numbGocbRef = 0;
	newElement->AppId = 0;
	newElement->confRev = 0;
	newElement->sibling = NULL;
    return newElement;
}
/*****************************************************************************************************
 * GooseReceiverGocbRef_add
 * GooseReceiverGocbRef
 *****************************************************************************************************/
GooseReceiverGocbRef*	GooseReceiverGocbRef_add(GooseReceiverGocbRef* Cfg)
{
	GooseReceiverGocbRef* newElement = GooseReceiverGocbRef_create();
	while (Cfg->sibling){
		Cfg = Cfg->sibling;
	}
	Cfg->sibling = newElement;
return 	newElement;
}
/*****************************************************************************************************
 * GooseReceiverCfg_create
 *****************************************************************************************************/
GooseReceiverCfg*	GooseReceiverCfg_create()
{
	GooseReceiverCfg* newElement;

	newElement = (GooseReceiverCfg*) GLOBAL_MALLOC(sizeof(struct sGooseReceiverCfg));
	newElement->AddAllowedToLiveStatus = false;
	newElement->nDataSetGoEntries = 0;
	newElement->nGoEntries = 0;
	newElement->nGocbRef = 0;
	newElement->sibling = NULL;
    return newElement;
}
/*****************************************************************************************************
 * GooseReceiverCfg_add
 *****************************************************************************************************/
GooseReceiverCfg*	GooseReceiverCfg_add(GooseReceiverCfg* Cfg)
{
	GooseReceiverCfg* newElement = GooseReceiverCfg_create();
	while (Cfg->sibling){
		Cfg = Cfg->sibling;
	}
	Cfg->sibling = newElement;
return 	newElement;
}
/*****************************************************************************************************
 *GooseReceiver_create
 *****************************************************************************************************/
GooseReceiver	GooseReceiver_create()
{
    GooseReceiver self = (GooseReceiver) GLOBAL_MALLOC(sizeof(struct sGooseReceiver));

    if (self != NULL) {
        self->running = false;
        self->interfaceId = NULL;
        self->buffer = (uint8_t*) GLOBAL_MALLOC(ETH_BUFFER_LENGTH);			// буфер для приёма
        self->ethSocket = NULL;												// сокет для приёма
        self->subscriberList = LinkedList_create();							// список MAC адресов для приёма гусов
    }

    return self;
}

void
GooseReceiver_addSubscriber(GooseReceiver self, GooseSubscriber subscriber)
{
    LinkedList_add(self->subscriberList, (void*) subscriber);
}

void
GooseReceiver_removeSubscriber(GooseReceiver self, GooseSubscriber subscriber)
{
    LinkedList_remove(self->subscriberList, (void*) subscriber);
}


void
GooseReceiver_setInterfaceId(GooseReceiver self, const char* interfaceId)
{
    if (self->interfaceId != NULL)
        GLOBAL_FREEMEM(self->interfaceId);

    self->interfaceId = copyString(interfaceId);
}

static void
createNewStringFromBufferElement(MmsValue* value, uint8_t* bufferSrc, int elementLength)
{
    value->value.visibleString.buf = (char*) GLOBAL_MALLOC(elementLength + 1);
    memcpy(value->value.visibleString.buf, bufferSrc, elementLength);
    value->value.visibleString.buf[elementLength] = 0;
    value->value.visibleString.size = elementLength;
}

static int
parseAllData(uint8_t* buffer, int allDataLength, MmsValue* dataSetValues)
{
    int bufPos = 0;
    int elementLength = 0;

    int elementIndex = 0;

    int maxIndex = MmsValue_getArraySize(dataSetValues) - 1;

    while (bufPos < allDataLength) {
        uint8_t tag = buffer[bufPos++];

        if (elementIndex > maxIndex) {
            if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER: Malformed message: too much elements!\n");
            return 0;
        }

        MmsValue* value = MmsValue_getElement(dataSetValues, elementIndex);

        bufPos = BerDecoder_decodeLength(buffer, &elementLength, bufPos, allDataLength);

        if (bufPos + elementLength > allDataLength) {
            if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER: Malformed message: sub element is too large!\n");
            return 0;
        }

        switch (tag) {
        case 0x80: /* reserved for access result */
            printf("GOOSE_SUBSCRIBER:    found reserved value (tag 0x80)!\n");
            break;
        case 0xa1: /* array */
            if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:    found array\n");
            if (MmsValue_getType(value) == MMS_ARRAY) {
                if (!parseAllData(buffer + bufPos, elementLength, value))
                    return -1;
            }
            break;
        case 0xa2: /* structure */
            if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:    found structure\n");
            if (MmsValue_getType(value) == MMS_STRUCTURE) {
                if (!parseAllData(buffer + bufPos, elementLength, value))
                    return -1;
            }
            break;
        case 0x83: /* boolean */
            if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:    found boolean\n");

            if (MmsValue_getType(value) == MMS_BOOLEAN) {
                MmsValue_setBoolean(value, BerDecoder_decodeBoolean(buffer, bufPos));
            }
            else
                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:      message contains value of wrong type!\n");

            break;

        case 0x84: /* BIT STRING */
            if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:    found bitstring\n");

            if (MmsValue_getType(value) == MMS_BIT_STRING) {
                int padding = buffer[bufPos];
                int bitStringLength = (8 * (elementLength - 1)) - padding;
                if (bitStringLength == value->value.bitString.size) {
                    memcpy(value->value.bitString.buf, buffer + bufPos + 1,
                            elementLength - 1);
                }
                else
                    if (DEBUG_GOOSE_SUBSCRIBER)
                        printf("bit-string is of wrong size");
            }
            break;
        case 0x85: /* integer */
            if (MmsValue_getType(value) == MMS_INTEGER) {
                if (elementLength <= value->value.integer->maxSize) {
                    value->value.integer->size = elementLength;
                    memcpy(value->value.integer->octets, buffer + bufPos, elementLength);
                }
            }
            break;
        case 0x86: /* unsigned integer */
            if (MmsValue_getType(value) == MMS_UNSIGNED) {
                if (elementLength <= value->value.integer->maxSize) {
                    value->value.integer->size = elementLength;
                    memcpy(value->value.integer->octets, buffer + bufPos, elementLength);
                }
            }
            break;
        case 0x87: /* Float */
            if (MmsValue_getType(value) == MMS_FLOAT) {
                if (elementLength == 9) {
                    MmsValue_setDouble(value, BerDecoder_decodeDouble(buffer, bufPos));
                }
                else if (elementLength == 5) {
                    MmsValue_setFloat(value, BerDecoder_decodeFloat(buffer, bufPos));
                }
            }
            break;

        case 0x89: /* octet string */
            if (MmsValue_getType(value) == MMS_OCTET_STRING) {
                if (elementLength <= value->value.octetString.maxSize) {
                    value->value.octetString.size = elementLength;
                    memcpy(value->value.octetString.buf, buffer + bufPos, elementLength);
                }
            }
            break;
        case 0x8a: /* visible string */
            if (MmsValue_getType(value) == MMS_VISIBLE_STRING) {

                if (value->value.visibleString.buf != NULL) {
                    if ((int32_t) value->value.visibleString.size >= elementLength) {
                        memcpy(value->value.visibleString.buf, buffer + bufPos, elementLength);
                        value->value.visibleString.buf[elementLength] = 0;
                    }
                    else {
                        GLOBAL_FREEMEM(value->value.visibleString.buf);

                        createNewStringFromBufferElement(value, buffer + bufPos, elementLength);
                    }
                }
                else
                    createNewStringFromBufferElement(value, buffer + bufPos, elementLength);

            }
            break;
        case 0x8c: /* binary time */
            if (MmsValue_getType(value) == MMS_BINARY_TIME) {
                if ((elementLength == 4) || (elementLength == 6)) {
                    memcpy(value->value.binaryTime.buf, buffer + bufPos, elementLength);
                }
            }
            break;
        case 0x91: /* Utctime */
            if (elementLength == 8) {
                if (MmsValue_getType(value) == MMS_UTC_TIME) {
                    MmsValue_setUtcTimeByBuffer(value, buffer + bufPos);
                }
                else
                    if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:      message contains value of wrong type!\n");
            }
            else
                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:      UTCTime element is of wrong size!\n");
            break;
        default:
            if (DEBUG_GOOSE_SUBSCRIBER)
                printf("GOOSE_SUBSCRIBER:    found unkown tag %02x\n", tag);
            break;
        }

        bufPos += elementLength;

        elementIndex++;
    }

    return 1;
}

static MmsValue*
parseAllDataUnknownValue(GooseSubscriber self, uint8_t* buffer, int allDataLength, bool isStructure)
{
    int bufPos = 0;
    int elementLength = 0;

    int elementIndex = 0;

    MmsValue* dataSetValues = NULL;

    while (bufPos < allDataLength) {
        uint8_t tag = buffer[bufPos++];

        bufPos = BerDecoder_decodeLength(buffer, &elementLength, bufPos, allDataLength);

        if (bufPos + elementLength > allDataLength) {
            if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER: Malformed message: sub element is too large!\n");
            goto exit_with_error;
        }

        switch (tag) {
        case 0x80: /* reserved for access result */
            break;
        case 0xa1: /* array */
            break;
        case 0xa2: /* structure */
            break;
        case 0x83: /* boolean */
            break;
        case 0x84: /* BIT STRING */
            break;
        case 0x85: /* integer */
            break;
        case 0x86: /* unsigned integer */
            break;
        case 0x87: /* Float */
            break;
        case 0x89: /* octet string */
            break;
        case 0x8a: /* visible string */
            break;
        case 0x8c: /* binary time */
            break;
        case 0x91: /* Utctime */
            break;
        default:
            if (DEBUG_GOOSE_SUBSCRIBER)
                printf("GOOSE_SUBSCRIBER:    found unknown tag %02x\n", tag);
            goto exit_with_error;
        }

        bufPos += elementLength;

        elementIndex++;
    }

    if (isStructure)
        dataSetValues = MmsValue_createEmptyStructure(elementIndex);
    else
        dataSetValues = MmsValue_createEmptyArray(elementIndex);

    elementIndex = 0;
    bufPos = 0;

    while (bufPos < allDataLength) {
        uint8_t tag = buffer[bufPos++];

        bufPos = BerDecoder_decodeLength(buffer, &elementLength, bufPos, allDataLength);

        if (bufPos + elementLength > allDataLength) {
            if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER: Malformed message: sub element is too large!\n");
            goto exit_with_error;
        }

        MmsValue* value = NULL;

        switch (tag) {
        case 0xa1: /* array */
            if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:    found array\n");

            value = parseAllDataUnknownValue(self, buffer + bufPos, elementLength, false);

            if (value == NULL)
                goto exit_with_error;

            break;
        case 0xa2: /* structure */
            if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:    found structure\n");

            value = parseAllDataUnknownValue(self, buffer + bufPos, elementLength, true);

            if (value == NULL)
                goto exit_with_error;

            break;
        case 0x83: /* boolean */
            if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:    found boolean\n");
            value = MmsValue_newBoolean(BerDecoder_decodeBoolean(buffer, bufPos));

            break;

        case 0x84: /* BIT STRING */
            {
                int padding = buffer[bufPos];
                int bitStringLength = (8 * (elementLength - 1)) - padding;
                value = MmsValue_newBitString(bitStringLength);
                memcpy(value->value.bitString.buf, buffer + bufPos + 1, elementLength - 1);

            }
            break;
        case 0x85: /* integer */
            value = MmsValue_newInteger(elementLength * 8);
            memcpy(value->value.integer->octets, buffer + bufPos, elementLength);
            value->value.integer->size = elementLength;
            break;
        case 0x86: /* unsigned integer */
            value = MmsValue_newUnsigned(elementLength * 8);
            memcpy(value->value.integer->octets, buffer + bufPos, elementLength);
            value->value.integer->size = elementLength;
            break;
        case 0x87: /* Float */
                if (elementLength == 9)
                    value = MmsValue_newDouble(BerDecoder_decodeDouble(buffer, bufPos));
                else if (elementLength == 5)
                    value = MmsValue_newFloat(BerDecoder_decodeFloat(buffer, bufPos));
            break;

        case 0x89: /* octet string */
            value = MmsValue_newOctetString(elementLength, elementLength);
            memcpy(value->value.octetString.buf, buffer + bufPos, elementLength);
            break;
        case 0x8a: /* visible string */
            value = MmsValue_newVisibleStringFromByteArray(buffer + bufPos, elementLength);
            break;
        case 0x8c: /* binary time */
            if (elementLength == 4)
                value = MmsValue_newBinaryTime(true);
            else if (elementLength == 6)
                value = MmsValue_newBinaryTime(false);

            if ((elementLength == 4) || (elementLength == 6))
                memcpy(value->value.binaryTime.buf, buffer + bufPos, elementLength);

            break;
        case 0x91: /* Utctime */
            if (elementLength == 8) {
                value = MmsValue_newUtcTime(0);
                MmsValue_setUtcTimeByBuffer(value, buffer + bufPos);
            }
            else
                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:      UTCTime element is of wrong size!\n");
            break;
        default:
            if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:    found unkown tag %02x\n", tag);
            goto exit_with_error;
        }

        bufPos += elementLength;

        if (value != NULL) {
            MmsValue_setElement(dataSetValues, elementIndex, value);
            elementIndex++;
        }
    }

    self->dataSetValuesSelfAllocated = true;

    return dataSetValues;

exit_with_error:

    if (dataSetValues != NULL)
        MmsValue_delete(dataSetValues);

    return NULL;
}

/***************************************
 * parseGoosePayload
 * парсим гусс пакет и вызываем функцию обработчик
 ***************************************/
static int	parseGoosePayload(GooseReceiver self, uint8_t* buffer, int apduLength)
{
    int bufPos = 0;
    uint32_t timeAllowedToLive = 0;
    uint32_t stNum = 0;
    uint32_t sqNum = 0;
    uint32_t confRev;
    bool simulation = false;
    bool ndsCom = false;
    GooseSubscriber matchingSubscriber = NULL;
    uint8_t* timestampBufPos = NULL;
    uint8_t* dataSetBufferAddress = NULL;
    int dataSetBufferLength = 0;

    uint32_t numberOfDatSetEntries = 0;

    if (buffer[bufPos++] == 0x61) {
        int gooseLength;
        bufPos = BerDecoder_decodeLength(buffer, &gooseLength, bufPos, apduLength);

        int gooseEnd = bufPos + gooseLength;

        while (bufPos < gooseEnd) {
            int elementLength;

            uint8_t tag = buffer[bufPos++];
            bufPos = BerDecoder_decodeLength(buffer, &elementLength, bufPos, apduLength);

            if (bufPos + elementLength > apduLength) {
                if (DEBUG_GOOSE_SUBSCRIBER)
                    printf("GOOSE_SUBSCRIBER: Malformed message: sub element is too large!\n");

                goto exit_with_fault;
            }

            if (bufPos == -1)
                goto exit_with_fault;

            switch(tag) {
            case 0x80: /* gocbRef */
                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   Found gocbRef\n");

                {
                    LinkedList element = LinkedList_getNext(self->subscriberList);

                    while (element != NULL) {  // посмотрим по списку есть ли на приёме такой гус
                        GooseSubscriber subscriber = (GooseSubscriber) LinkedList_getData(element);

                        if (subscriber->goCBRefLen == elementLength) {

                        	//portDISABLE_INTERRUPTS();

                            if (memcmp(subscriber->goCBRef, buffer + bufPos, elementLength) == 0) {
                               	if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   gocbRef is matching!\n");
                               	matchingSubscriber = subscriber;
                                break;
                            }else{
                               	if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   Error, gocbRef mismatch!!!\n");
                            }

                        	//portENABLE_INTERRUPTS();
                        }else{
                        	if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   Error, gocbRef Len error!!!\n");
                        }

                        element = LinkedList_getNext(element);
                    }

                    if (matchingSubscriber == NULL)
                        return 0;
                }

                break;

            case 0x81: /* timeAllowedToLive */

                timeAllowedToLive = BerDecoder_decodeUint32(buffer, elementLength, bufPos);

                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   Found timeAllowedToLive %u\n", timeAllowedToLive);

                break;

            case 0x82:
                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   Found dataSet\n");
                break;

            case 0x83:
                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   Found goId\n");
                break;

            case 0x84:
                timestampBufPos = buffer + bufPos;
                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   Found timestamp\n");
                break;

            case 0x85:
                stNum = BerDecoder_decodeUint32(buffer, elementLength, bufPos);
                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   Found stNum: %u\n", stNum);
                break;

            case 0x86:
                sqNum = BerDecoder_decodeUint32(buffer, elementLength, bufPos);
                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   Found sqNum: %u\n", sqNum);
                break;

            case 0x87:
                simulation = BerDecoder_decodeBoolean(buffer, bufPos);
                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   Found simulation: %i\n", simulation);
                break;

            case 0x88:
                confRev = BerDecoder_decodeUint32(buffer, elementLength, bufPos);
                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   Found confRev: %u\n", confRev);
                break;

            case 0x89:
                ndsCom = BerDecoder_decodeBoolean(buffer, bufPos);
                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   Found ndsCom: %i\n", ndsCom);
                break;

            case 0x8a:
                numberOfDatSetEntries = BerDecoder_decodeUint32(buffer, elementLength, bufPos);
                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   Found number of entries: %u\n", numberOfDatSetEntries);
                break;

            case 0xab:
                if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER:   Found all data with length: %i\n", elementLength);
                dataSetBufferAddress = buffer + bufPos;
                dataSetBufferLength = elementLength;
                break;

            default:
                if (DEBUG_GOOSE_SUBSCRIBER)  printf("GOOSE_SUBSCRIBER:   Unknown tag %02x\n", tag);
                break;
            }

            bufPos += elementLength;
        }

        if (matchingSubscriber != NULL) {

//TODO: надо проверить все параметры на которые настроен гус. и только тогда вызывать обработчик.
//иначе както сообщить об ошибке гуса
			{
				uint32_t	REconfRev = matchingSubscriber->confRev;
				if (REconfRev != confRev){
					USART_TRACE_RED("Goose принят confRev:%u отличается от настроек:%u\n",(unsigned int)confRev,(unsigned int)REconfRev);
					return 0;
				}
			}


            matchingSubscriber->timeAllowedToLive = timeAllowedToLive;
            //matchingSubscriber->confRev = confRev;		// присваивать нельзя, мы же сравниваем его с тем, что пришло
            matchingSubscriber->ndsCom = ndsCom;			// needs commission
            matchingSubscriber->simulation = simulation;
            MmsValue_setUtcTimeByBuffer(matchingSubscriber->timestamp, timestampBufPos);

            if (matchingSubscriber->dataSetValues == NULL)
                matchingSubscriber->dataSetValues = parseAllDataUnknownValue(matchingSubscriber, dataSetBufferAddress, dataSetBufferLength, false);
            else
                parseAllData(dataSetBufferAddress, dataSetBufferLength, matchingSubscriber->dataSetValues);

            bool isValid = true;

            if (matchingSubscriber->stNum == stNum) {
            		// иногда приборы шлют 2 одинаковых пакета (двойной инкремент stNum. пропуск потом 2 одинаковых).
            		//из-за этого ошибка по валидити падает. временно  >= поменяем на ==. для обнаружения дубликатов
                //if (matchingSubscriber->sqNum >= sqNum) {
            	if (matchingSubscriber->sqNum > sqNum) {
               		USART_TRACE_CYAN("Goose потеря NumGo:%u sqNum:%u\n",(unsigned int)matchingSubscriber->NumGocbRef,sqNum);
                    //isValid = false;
                }
            	if (matchingSubscriber->sqNum == sqNum) {
               		USART_TRACE_CYAN("Goose Дубликат:NumGo%u sqNum:%u\n",(unsigned int)matchingSubscriber->NumGocbRef,sqNum);
                    //isValid = false;
            	}
            }

            matchingSubscriber->stateValid = isValid;

            matchingSubscriber->stNum = stNum;
            matchingSubscriber->sqNum = sqNum;

            {
            portDISABLE_INTERRUPTS();
//было:
            //matchingSubscriber->invalidityTime = Hal_getTimeInMs() + (uint64_t)timeAllowedToLive;
//стало:
            uint64_t	nextinvalidityTime = Hal_getTimeInMs() + (uint64_t)timeAllowedToLive;
            if (nextinvalidityTime > matchingSubscriber->invalidityTime){
            	matchingSubscriber->invalidityTime = nextinvalidityTime;
            }
            else
            if ((matchingSubscriber->invalidityTime-nextinvalidityTime)>nextinvalidityTime) {
               	matchingSubscriber->invalidityTime = nextinvalidityTime;
            }
            portENABLE_INTERRUPTS();
            }

//            USART_TRACE_Yellow("Goose update invalidityTime:%u, 0x%X\n",(unsigned int)matchingSubscriber->NumGocbRef,(unsigned int)matchingSubscriber->invalidityTime);

            if (matchingSubscriber->listener != NULL){
                matchingSubscriber->listener(matchingSubscriber, matchingSubscriber->listenerParameter);
            }

            return 1;
        }

        return 0;
    }

exit_with_fault:
    if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER: Invalid goose payload\n");
    return -1;
}

/***************************************
 * parseGooseMessage
 * парсим пакет из сети
 ***************************************/
static void		parseGooseMessage(GooseReceiver self, int numbytes)
{
    int bufPos;
    bool subscriberFound = false;
    uint8_t* buffer = self->buffer;

    if (numbytes < 22) return;

    // пропустим адрес ethernet
    bufPos = 12;
    int headerLength = 14;

//---------------------------------------------------
// проверить тег VLAN
#if ETHARP_SUPPORT_VLAN
    if ((buffer[bufPos] == 0x81) && (buffer[bufPos + 1] == 0x00)) {
        bufPos += 4;		// пропустим тег VLAN
        headerLength += 4;
    }
#endif
//---------------------------------------------------
// проверить тег HSR
#if ETHARP_SUPPORT_HSR
    if ((buffer[bufPos] == 0x89) && (buffer[bufPos + 1] == 0x2F)) {
        bufPos += 6;		// пропустим тег HSR
        headerLength += 6;
    }
#endif
//---------------------------------------------------

    /* check for GOOSE Ethertype */
    if (buffer[bufPos++] != 0x88)
        return;
    if (buffer[bufPos++] != 0xb8)
        return;

    uint16_t appId;

    appId = buffer[bufPos++] * 0x100;
    appId += buffer[bufPos++];

    uint16_t length;

    length = buffer[bufPos++] * 0x100;
    length += buffer[bufPos++];

    /* skip reserved fields */
    bufPos += 4;

    int apduLength = length - 8;

    if (numbytes < length + headerLength) {
        if (DEBUG_GOOSE_SUBSCRIBER)
            printf("GOOSE_SUBSCRIBER: Invalid PDU size\n");
        return;
    }

    if (DEBUG_GOOSE_SUBSCRIBER) {
        printf("GOOSE_SUBSCRIBER: GOOSE message:\nGOOSE_SUBSCRIBER: ----------------\n");
        printf("GOOSE_SUBSCRIBER:   APPID: %u\n", appId);
        printf("GOOSE_SUBSCRIBER:   LENGTH: %u\n", length);
        printf("GOOSE_SUBSCRIBER:   APDU length: %i\n", apduLength);
    }

    // check if there is an interested subscriber
    LinkedList element = LinkedList_getNext(self->subscriberList);

    // порылись в списке элементов и нашли такой appId
    while (element != NULL) {
        GooseSubscriber subscriber = (GooseSubscriber) LinkedList_getData(element);

        if (subscriber->appId == appId) {
            subscriberFound = true;
            break;
        }

        element = LinkedList_getNext(element);
    }

    if (subscriberFound){
        parseGoosePayload(self, buffer + bufPos, apduLength);

//        USART_TRACE_CYAN("GOOSE_SUBSCRIBER: GOOSE message. APPID: %u, LENGTH: %u, APDU length: %i\n",appId,length,apduLength);

        if (DEBUG_GOOSE_SUBSCRIBER)
            printf("GOOSE_SUBSCRIBER: GOOSE message parse OK.\n");

    }
    else {
        if (DEBUG_GOOSE_SUBSCRIBER)
            printf("GOOSE_SUBSCRIBER: GOOSE message ignored due to unknown APPID value\n");
    }
}

/*********************************************************************
 * gooseReceiverDropMonitor
 * ТАСК мониторит потери гусов
 * нужно изменять данные ucGooseBufSent только когда gooseListener не работает
 * иначе портятся данные нафиг.
 * gooseListener и gooseReceiverDropMonitor имеют общие данные для отправки, нужно их семафорить както.
 * Работают они с этими данными долго по времени. делая паузы. Нужно потери связи держать отдельно, и только перед отправкой их суммировать.
 *
 *********************************************************************/
static void		gooseReceiverDropMonitor(void* threadParameter)
{
	bool		DataDropModify;
	uint8_t 	nDBword;
	uint8_t 	nDBbit;
	uint8_t 	PosBitinDB;

    GooseReceiver 		self 		= (GooseReceiver) threadParameter;

    while (self->running) {

    	UBaseType_t WaterMark = uxTaskGetStackHighWaterMark(NULL);
    		if (WaterMark<20){
				USART_TRACE_RED("память стека задачи осталось: %u  \n",(unsigned int)WaterMark);
    		}

		DataDropModify = false;
		// проверим на пропажу посылок от серверов отправителей
		LinkedList element = LinkedList_getNext(self->subscriberList);

		while (element != NULL) {
			GooseSubscriber subscriber = (GooseSubscriber) LinkedList_getData(element);

			uint32_t	NumGocbRef = GooseSubscriber_getNumGoose(subscriber);	// номер гуса
				if (GooseSubscriber_isValid(subscriber) == false){				// валидность
																				// вот она, была потеря. Нужно выставить везде флаги.

					if (GooseSubscriber_isLostGooseMessage(subscriber)!=true) 		// гус уже помечен что потеря
					{
					GooseSubscriber_setLostGooseMessage(subscriber,true);					// пометим что нет связи

						PosBitinDB = 0;
						GooseReceiverCfg* elementMatrix = self->GooseMatrix;
						while (elementMatrix != NULL) {

						//+++++++
						if (elementMatrix->AddAllowedToLiveStatus == true)			// если нужно подмешивать потерю связи к этой записи
						  if(elementMatrix->nGocbRef == NumGocbRef){				// сравним отправителя гуса
								PosBitinDB = elementMatrix->nGoEntries-1;			// номера дискрета в конфиге начинаются с '1'
								nDBword = PosBitinDB / 16;
								nDBbit = (PosBitinDB % 16);

								// проверим надо ли слать пакет. (если в нужной позиции "1" и потеря связи то ставим "0" и шлём)
								// предотвращает повторную отправку
								//if ((ucGooseBufSent[nDBword] & (1 << (nDBbit))) > 0){
								//	DataDropModify = true;
								//}
								//ucGooseBufSent[nDBword] &= ~(1 << (nDBbit));			// активный 0 ставим в нужные позиции и шлём в МБ

								portDISABLE_INTERRUPTS();
								ucGooseBufDrop[nDBword] |= (1 << (nDBbit));
								portENABLE_INTERRUPTS();

								DataDropModify = true;

								//if (DataDropModify)
								USART_TRACE_RED("Потеря связи %u, бит MB:%u \n",(unsigned int)NumGocbRef,(unsigned int)PosBitinDB+1);

							}
						//+++++++

							elementMatrix = elementMatrix->sibling;		// следующий
					      	taskYIELD();							// отпустим задачу.
//							vTaskDelay(2);


						}//!while (elementMatrix != NULL)
					}//!if (GooseSubscriber_isLostGooseMessage(subscriber)!=true)
				} else{
					if (GooseSubscriber_isLostGooseMessage(subscriber)==true){
					// снимаем валидность

						PosBitinDB = 0;
						GooseReceiverCfg* elementMatrix = self->GooseMatrix;
						while (elementMatrix != NULL) {

							if (elementMatrix->AddAllowedToLiveStatus == true)
							  if(elementMatrix->nGocbRef == NumGocbRef){
									PosBitinDB = elementMatrix->nGoEntries-1;			// номера дискрета в конфиге начинаются с '1'
									nDBword = PosBitinDB / 16;
									nDBbit = (PosBitinDB % 16);

									portDISABLE_INTERRUPTS();
									ucGooseBufDrop[nDBword] &= ~(1 << (nDBbit));
									portENABLE_INTERRUPTS();

									DataDropModify = true;

									USART_TRACE_GREEN("Возврат связи %u, бит MB:%u \n",(unsigned int)NumGocbRef,(unsigned int)PosBitinDB+1);

							  }

							elementMatrix = elementMatrix->sibling;		// следующий
					      	taskYIELD();							// отпустим задачу.
						}

					}
					GooseSubscriber_setLostGooseMessage(subscriber,false);
				}

			element = LinkedList_getNext(element);
		}
		// ----------------------------------------------------------------
#if ((defined	(MR761) || defined	(MR762) || defined	(MR763)) && (_REVISION_DEVICE <=303)) || (defined	(MR771) && (_REVISION_DEVICE <=106)) ||\
	(defined	(MR801) && (_REVISION_DEVICE <=299)) ||\
	((defined	(MR901) || defined	(MR902)) && (_REVISION_DEVICE <=212)) ||\
	(defined	(MR851) && (_REVISION_DEVICE <=202))

//			старые приборы не шлём гус
		USART_TRACE_RED("прибор не поддерживает приём goose\n");

#elif ((defined (MR5_500) || defined (MR5_600) || defined (MR5_700)) || defined (MR741))
		// в этих приборах идут команды на выключатель

#else
// тут мы бываем очень часто до 3мс
		if (DataDropModify == true)		 {
			AddToQueueMB(ModbusSentTime, MB_Wrt_Set_Goose	,MB_Slaveaddr);
			AddToQueueMB(ModbusSentTime, MB_Wrt_Set_Goose	,MB_Slaveaddr);
		}

#endif

    }
}

/*********************************************************************
 * gooseReceiverLoop
 * ТАСК мониторит приём гусов
 * обрабатывающий принятые сообщения гусов
 *********************************************************************/
static void		gooseReceiverLoop(void* threadParameter)
{

     GooseReceiver 		self 		= (GooseReceiver) threadParameter;

    self->running = true;
    self->stopped = false;

    // конфигурим приёмник VLAN сообщений, на прием гусов с нужными нам MAC фильтрами
    // нужно закинуть конфиг в свич
    GooseReceiver_startThreadless(self);

    while (self->running) {

        if (GooseReceiver_tick(self) == true){
     //   	taskYIELD();							// отпустим задачу.
        }else{
		UBaseType_t WaterMark = uxTaskGetStackHighWaterMark(NULL);
			if (WaterMark<20){
				USART_TRACE_RED("память задачи осталось: %u \n",WaterMark);
			}

        }
      	taskYIELD();							// отпустим задачу.
//        vTaskDelay(2);
    }

   GooseReceiver_stopThreadless(self);

   self->stopped = true;
}


// start GOOSE receiver in a separate thread
void
GooseReceiver_start(GooseReceiver self)
{

    Thread thread = Thread_create((ThreadExecutionFunction) gooseReceiverLoop, (void*) self, true);				// автоматически закрываем поток.

    if (thread != NULL) {
//        if (DEBUG_GOOSE_SUBSCRIBER) printf("GOOSE_SUBSCRIBER: GOOSE receiver started for interface %s\n", self->interfaceId);
        Thread_start(thread,GooseTask__PRIORITY,GooseTask_STACK_SIZE,"gseRe");
    }
    else {
        if (DEBUG_GOOSE_SUBSCRIBER)  printf("GOOSE_SUBSCRIBER: Starting GOOSE receiver failed for interface %s\n", self->interfaceId);
    }
// таск монитора потери связи с подписанными устройствами
    thread = Thread_create((ThreadExecutionFunction) gooseReceiverDropMonitor, (void*) self, true);				// автоматически закрываем поток.
    if (thread != NULL) {
        Thread_start(thread,GooseTask__PRIORITY,GooseDropTask_STACK_SIZE,"gseMon");
    }
    else {
        if (DEBUG_GOOSE_SUBSCRIBER)  printf("GOOSE_SUBSCRIBER: Starting GOOSE receiver drop Monitor failed for interface %s\n", self->interfaceId);
    }

}

void
GooseReceiver_stop(GooseReceiver self)
{
    self->running = false;

    while (self->stopped == false)
        Thread_sleep(1);
}

void
GooseReceiver_destroy(GooseReceiver self)
{
    LinkedList_destroyDeep(self->subscriberList,
            (LinkedListValueDeleteFunction) GooseSubscriber_destroy);

    GLOBAL_FREEMEM(self->buffer);
    GLOBAL_FREEMEM(self);
}

/***************************************
 * Functions for non-threaded operation
 ***************************************/
void
GooseReceiver_startThreadless(GooseReceiver self)
{
    if (self->interfaceId == NULL)
        self->ethSocket = Ethernet_createSocket(CONFIG_ETHERNET_INTERFACE_ID, NULL);
    else
        self->ethSocket = Ethernet_createSocket(self->interfaceId, NULL);

    Ethernet_setProtocolFilter(self->ethSocket, ETH_P_GOOSE);

    self->running = true;
}

void
GooseReceiver_stopThreadless(GooseReceiver self)
{
    Ethernet_destroySocket(self->ethSocket);

    self->running = false;
}

/***************************************
 * GooseReceiver_tick
 * проверяем есть ли сообщения, если есть обрабатываем их
 ***************************************/
bool	GooseReceiver_tick(GooseReceiver self)
{
    int packetSize = Ethernet_receivePacket(self->ethSocket, self->buffer, ETH_BUFFER_LENGTH);
    if (packetSize > 0) {

        parseGooseMessage(self, packetSize);

        return true;
    }
    else
        return false;
}
