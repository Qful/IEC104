/*
 *  ied_server.c
 *
 *  Copyright 2013-2016 Michael Zillgith
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

#include "iec61850_server.h"
#include "mms_mapping.h"
#include "mms_mapping_internal.h"
#include "mms_value_internal.h"
#include "control.h"
#include "stack_config.h"
#include "ied_server_private.h"
#include "hal_thread.h"
#include "reporting.h"

#include "libiec61850_platform_includes.h"
#include "mms_sv.h"
#include "mms_goose.h"

#include "main.h"
#include "lwip/ip_addr.h"

#include "filesystem.h"

#include "dataUpdateFromBase.h"

#include "hsr_prp_main.h"

#if defined	(MR801) && defined (OLD)
#include "static_model_MR801.h"
#endif

#if defined	(MR801) && defined (T12N5D58R51)
#include "static_model_MR801_T12N5D58R51.h"
#endif

#if defined (MR771)
#include "static_model_MR771.h"
#endif

#if defined	(MR761) || defined	(MR762) || defined	(MR763)
#include "static_model_MR76x.h"
#endif
#if  defined (MR761OBR)
#include "static_model_MR761OBR.h"
#endif
#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"
#endif

#if defined (MR851)
#include "static_model_MR851.h"
#endif

#if defined (MR5_700)
#include "static_model_MR5_700.h"
#endif
#if defined (MR5_600)
#include "static_model_MR5_600.h"
#endif
#if defined (MR5_500)
#include "static_model_MR5_500.h"
#endif
#if defined	(MR741)
#include "static_model_MR741.h"
#endif
extern uint32_t	GLOBALMemoryUsedLim;							//максимально использованной памяти
extern uint16_t	GLOBAL_QUALITY;

#ifndef DEBUG_IED_SERVER
#define DEBUG_IED_SERVER 0
#endif

#if (CONFIG_IEC61850_CONTROL_SERVICE == 1)
static bool
createControlObjects(IedServer self, MmsDomain* domain, char* lnName, MmsVariableSpecification* typeSpec, char* namePrefix)
{
    MmsMapping* mapping = self->mmsMapping;

    bool success = false;

    if (typeSpec->type == MMS_STRUCTURE) {
        int coCount = typeSpec->typeSpec.structure.elementCount;
        int i;
        for (i = 0; i < coCount; i++) {

            char objectName[65];
            objectName[0] = 0;

            if (namePrefix != NULL) {
                strcat(objectName, namePrefix);
                strcat(objectName, "$");
            }

            bool isControlObject = false;
            bool hasCancel = false;
            int cancelIndex = 0;
            bool hasSBOw = false;
            int sBOwIndex = 0;
            int operIndex = 0;

            MmsVariableSpecification* coSpec = typeSpec->typeSpec.structure.elements[i];

            if (coSpec->type == MMS_STRUCTURE) {

                int coElementCount = coSpec->typeSpec.structure.elementCount;

                int j;
                for (j = 0; j < coElementCount; j++) {
                    MmsVariableSpecification* coElementSpec = coSpec->typeSpec.structure.elements[j];

                    if (strcmp(coElementSpec->name, "Oper") == 0) {
                        isControlObject = true;
                        operIndex = j;
                    }
                    else if (strcmp(coElementSpec->name, "Cancel") == 0) {
                        hasCancel = true;
                        cancelIndex = j;
                    }
                    else if (strcmp(coElementSpec->name, "SBOw") == 0) {
                        hasSBOw = true;
                        sBOwIndex = j;
                    }
                    else if (!(strcmp(coElementSpec->name, "SBO") == 0)) {
                        if (DEBUG_IED_SERVER)
                            printf("IED_SERVER: createControlObjects: Unknown element in CO: %s! --> seems not to be a control object\n", coElementSpec->name);

                        break;
                    }
                }

                if (isControlObject) {

                    strcat(objectName, coSpec->name);

                    if (DEBUG_IED_SERVER)
                        printf("IED_SERVER: create control object LN:%s DO:%s\n", lnName, objectName);

                    ControlObject* controlObject = ControlObject_create(self, domain, lnName, objectName);

                    if (controlObject == NULL)
                        goto exit_function;

                    MmsValue* structure = MmsValue_newDefaultValue(coSpec);

                    if (structure == NULL) {
                        ControlObject_destroy(controlObject);
                        goto exit_function;
                    }

                    ControlObject_setMmsValue(controlObject, structure);

                    ControlObject_setTypeSpec(controlObject, coSpec);

                    MmsValue* operVal = MmsValue_getElement(structure, operIndex);
                    ControlObject_setOper(controlObject, operVal);

                    if  (hasCancel) {
                        MmsValue* cancelVal = MmsValue_getElement(structure, cancelIndex);
                        ControlObject_setCancel(controlObject, cancelVal);
                    }

                    if (hasSBOw) {
                        MmsValue* sbowVal = MmsValue_getElement(structure, sBOwIndex);
                        ControlObject_setSBOw(controlObject, sbowVal);
                    }

                    MmsMapping_addControlObject(mapping, controlObject);
                }
                else {
                    strcat(objectName, coSpec->name);

                    if (createControlObjects(self, domain, lnName, coSpec, objectName) == false)
                        goto exit_function;
                }
            }
        }
    }

    success = true;

exit_function:
    return success;
}
#endif /* (CONFIG_IEC61850_CONTROL_SERVICE == 1) */

static bool
createMmsServerCache(IedServer self)
{
    assert(self != NULL);

    bool success = false;

    int domain = 0;

    for (domain = 0; domain < self->mmsDevice->domainCount; domain++) {

        /* Install all top level MMS named variables (=Logical nodes) in the MMS server cache */
        MmsDomain* logicalDevice = self->mmsDevice->domains[domain];

        int i;

        for (i = 0; i < logicalDevice->namedVariablesCount; i++) {
            char* lnName = logicalDevice->namedVariables[i]->name;

            if (DEBUG_IED_SERVER)
                printf("IED_SERVER: Insert into cache %s - %s\n", logicalDevice->domainName, lnName);

            int fcCount = logicalDevice->namedVariables[i]->typeSpec.structure.elementCount;
            int j;

            for (j = 0; j < fcCount; j++) {
                MmsVariableSpecification* fcSpec = logicalDevice->namedVariables[i]->typeSpec.structure.elements[j];

                char* fcName = fcSpec->name;

#if (CONFIG_IEC61850_CONTROL_SERVICE == 1)
                if (strcmp(fcName, "CO") == 0) {
                    createControlObjects(self, logicalDevice, lnName, fcSpec, NULL);
                }
                else
#endif /* (CONFIG_IEC61850_CONTROL_SERVICE == 1) */

                if ((strcmp(fcName, "BR") != 0) && (strcmp(fcName, "RP") != 0)

#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
                        && (strcmp(fcName, "GO") != 0)
#endif

#if (CONFIG_IEC61850_SAMPLED_VALUES_SUPPORT == 1)
                        && (strcmp(fcName, "MS") != 0) && (strcmp(fcName, "US") != 0)
#endif

#if (CONFIG_IEC61850_LOG_SERVICE == 1)
                        && (strcmp(fcName, "LG") != 0)
#endif

                   )
                {
                    char* variableName = createString(3, lnName, "$", fcName);

                    if (variableName == NULL) goto exit_function;

                    MmsValue* defaultValue = MmsValue_newDefaultValue(fcSpec);

                    if (defaultValue == NULL) {
                        GLOBAL_FREEMEM(variableName);
                        goto exit_function;
                    }

                    if (DEBUG_IED_SERVER)
                        printf("ied_server.c: Insert into cache %s - %s\n", logicalDevice->domainName, variableName);

                    MmsServer_insertIntoCache(self->mmsServer, logicalDevice, variableName, defaultValue);

                    GLOBAL_FREEMEM(variableName);
                }
            }
        }
    }

    success = true;

exit_function:
    return success;
}

static void
installDefaultValuesForDataAttribute(IedServer self, DataAttribute* dataAttribute, char* objectReference, int position)
{
	MmsValue* cacheValue;
	DataAttribute* subDataAttribute;

    sprintf(objectReference + position, ".%s", dataAttribute->name);
//    if (DEBUG_IED_SERVER)
//    	printf("dataAttribute: .%s\n", dataAttribute->name);


    char mmsVariableName[65]; /* maximum size is 64 according to 61850-8-1 */

    MmsValue* value = dataAttribute->mmsValue;

    MmsMapping_createMmsVariableNameFromObjectReference(objectReference, dataAttribute->fc, mmsVariableName);

    char domainName[65];

    strncpy(domainName, self->model->name, 64);

    MmsMapping_getMmsDomainFromObjectReference(objectReference, domainName + strlen(domainName));

    MmsDomain* domain = MmsDevice_getDomain(self->mmsDevice, domainName);

    if (domain == NULL) {
        if (DEBUG_IED_SERVER)
            printf("Error domain (%s) not found for %s!\n", domainName, objectReference);
        return;
    }

    cacheValue = MmsServer_getValueFromCache(self->mmsServer, domain, mmsVariableName);

    dataAttribute->mmsValue = cacheValue;

    if (value != NULL) {						// удаляем еслм

        if (cacheValue != NULL)
            MmsValue_update(cacheValue, value);	//перекинем из value в cacheValue
        if (cacheValue == NULL) {
        	USART_TRACE_RED("IED_SERVER: exception:invalid initializer for %s. value:0x%X cacheValue:0x%X domain:0x%X\n",
        			mmsVariableName,
        			value,
        			cacheValue,
        			domain);
        }

        #if (DEBUG_ISO_SERVER_MY == 1)
            if (cacheValue == NULL) {
                printf("IED_SERVER: exception:invalid initializer for %s\n", mmsVariableName);
                exit(-1);

                //TODO else call exception handler
            }
        #endif

        MmsValue_delete(value);
    }

    int childPosition = strlen(objectReference);
    subDataAttribute = (DataAttribute*) dataAttribute->firstChild;

    while (subDataAttribute != NULL) {
        installDefaultValuesForDataAttribute(self, subDataAttribute, objectReference, childPosition);

        subDataAttribute = (DataAttribute*) subDataAttribute->sibling;
    }
}

static void
installDefaultValuesForDataObject(IedServer self, DataObject* dataObject,
        char* objectReference, int position)
{
    if (dataObject->elementCount > 0) {
        if (DEBUG_IED_SERVER)
            printf("IED_SERVER: DataObject is an array. Skip installing default values in cache\n");

        return;
    }

    sprintf(objectReference + position, ".%s", dataObject->name);
    if (DEBUG_IED_SERVER){
    	printf("0x%X dataObject: .%s\n",(unsigned int)GLOBALMemoryUsedLim ,dataObject->name);

    }

    ModelNode* childNode = dataObject->firstChild;

    int childPosition = strlen(objectReference);

    while (childNode != NULL) {
        if (childNode->modelType == DataObjectModelType) {
            installDefaultValuesForDataObject(self, (DataObject*) childNode, objectReference, childPosition);
        }
        else if (childNode->modelType == DataAttributeModelType) {
            installDefaultValuesForDataAttribute(self, (DataAttribute*) childNode, objectReference, childPosition);
        }

        childNode = childNode->sibling;
    }
}

static void
installDefaultValuesInCache(IedServer self)
{
    IedModel* model = self->model;

    char objectReference[130];

    LogicalDevice* logicalDevice = model->firstChild;

    while (logicalDevice != NULL) {
        sprintf(objectReference, "%s", logicalDevice->name);
        if (DEBUG_IED_SERVER)
        	USART_TRACE("logicalDevice: %s\n", logicalDevice->name);

        LogicalNode* logicalNode = (LogicalNode*) logicalDevice->firstChild;

        char* nodeReference = objectReference + strlen(objectReference);

        while (logicalNode != NULL) {
            sprintf(nodeReference, "/%s", logicalNode->name);
            if (DEBUG_IED_SERVER)
            	USART_TRACE("0x%X logicalNode: /%s\n",(unsigned int)GLOBALMemoryUsedLim, logicalNode->name);

            DataObject* dataObject = (DataObject*) logicalNode->firstChild;

            int refPosition = strlen(objectReference);

            while (dataObject != NULL) {
                installDefaultValuesForDataObject(self, dataObject, objectReference, refPosition);

                dataObject = (DataObject*) dataObject->sibling;
            }

            logicalNode = (LogicalNode*) logicalNode->sibling;
        }

        logicalDevice = (LogicalDevice*) logicalDevice->sibling;
    }
}

static void
updateDataSetsWithCachedValues(IedServer self)
{
    DataSet* dataSet = self->model->dataSets;				// Вот они датасеты. В статической модели.

    int iedNameLength = strlen(self->model->name);

    if (iedNameLength <= 64) {

        while (dataSet != NULL) {

            DataSetEntry* dataSetEntry = dataSet->fcdas;

            while (dataSetEntry != NULL) {

                char domainName[65];

                strncpy(domainName, self->model->name, 64);
                strncat(domainName, dataSetEntry->logicalDeviceName, 64 - iedNameLength);

                MmsDomain* domain = MmsDevice_getDomain(self->mmsDevice, domainName);

                MmsValue* value = MmsServer_getValueFromCache(self->mmsServer, domain, dataSetEntry->variableName);

                if (value == NULL) {
                    if (DEBUG_IED_SERVER) {
                        printf("0x%X LD: %s dataset: %s : error cannot get value from cache for %s -> %s!\n",(unsigned int)GLOBALMemoryUsedLim,

                                dataSet->logicalDeviceName, dataSet->name,
                                dataSetEntry->logicalDeviceName,
                                dataSetEntry->variableName);
                    }
                }
                else{
                    dataSetEntry->value = value;
                    if (DEBUG_IED_SERVER) {
                    printf("0x%X LD: %s dataset: %s : value from cache for %s -> %s!\n",(unsigned int)GLOBALMemoryUsedLim,
                            dataSet->logicalDeviceName, dataSet->name,
                            dataSetEntry->logicalDeviceName,
                            dataSetEntry->variableName);
                    }
                }

                dataSetEntry = dataSetEntry->sibling;
            }

            dataSet = dataSet->sibling;
        }
    }
}
/*************************************************************************
 * IedServer_create
 * надо иметь уникальное имя модели. будем добавлять к текущему [numb], последнее число IP адреса
 *************************************************************************/
IedServer
IedServer_create(IedModel* iedModel, uint16_t	numb)
{

    IedServer self = (IedServer) GLOBAL_CALLOC(1, sizeof(struct sIedServer));

    self->model = iedModel;
// -----------------------------------------------------------------------------
// тут ещё можно в модель чтото добавлять, дальше модель перетянется в структуру MMS и всё.
// -----------------------------------------------------------------------------
// добавим гусы из файла в модель
// -----------------------------------------------------------------------------
		if (GoosePublishing_ParseConfigFile(self, _GooseTRcfg) == true){
			USART_TRACE_GREEN("добавили гусы из '%s' в модель\n",_GooseTRcfg);
		}
// -----------------------------------------------------------------------------
// добавим блоки управления отчётами
// -----------------------------------------------------------------------------
		if (filesystem_Read_RCBs(self, _xRCBcfg) == true){
			USART_TRACE_GREEN("добавили xRCB из '%s' в модель\n",_xRCBcfg);
		}
// -----------------------------------------------------------------------------
// добавим датасеты
// -----------------------------------------------------------------------------
		if (filesystem_Read_NamedVariableListRequest(self, _Datasetscfg) == true){
			USART_TRACE_GREEN("добавили Datasets из '%s' в модель\n",_Datasetscfg);
		}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

    // self->running = false; /* not required due to CALLOC */

	// забирает 200Кб оперативы
	USART_TRACE("MmsMapping_create start. (~200Кб RAM)\n");
    self->mmsMapping = MmsMapping_create(iedModel);							// тут перетянули из IED модели в MMs структуры. Дальше добавление в iedModel бессмысленно

    self->mmsDevice = MmsMapping_getMmsDeviceModel(self->mmsMapping);

    // забирает <1Кб оперативы
	USART_TRACE("IsoServer_create start\n");
    self->isoServer = IsoServer_create();

    // забирает 17Кб оперативы
	USART_TRACE("MmsServer_create start\n");
    self->mmsServer = MmsServer_create(self->isoServer, self->mmsDevice);

    MmsMapping_setMmsServer(self->mmsMapping, self->mmsServer);

	USART_TRACE("MmsMapping_installHandlers start\n");
    MmsMapping_installHandlers(self->mmsMapping);

    MmsMapping_setIedServer(self->mmsMapping, self);

	// забирает 215Кб оперативы
	USART_TRACE("createMmsServerCache start\n");
    createMmsServerCache(self);

	// забирает 35Кб оперативы
	USART_TRACE("iedModel->initializer start\n");
	iedModel->initializer();
	USART_TRACE("iedModel->initializer.. ok\n");

	USART_TRACE("installDefaultValuesInCache start\n");
	// 5 сек выполняется
    installDefaultValuesInCache(self); 						// This will also connect cached MmsValues to DataAttributes
	USART_TRACE("installDefaultValuesInCache.. ok\n");

	USART_TRACE("updateDataSetsWithCachedValues start\n");
    updateDataSetsWithCachedValues(self);
	USART_TRACE("updateDataSetsWithCachedValues.. ok\n");

    self->clientConnections = LinkedList_create();
	USART_TRACE("clientConnections create.. ok\n");

    /* default write access policy allows access to SP, SE and SV FCDAs but denies access to DC and CF FCDAs */
	// функциональные связи, которым разрешена запись из MMS
    self->writeAccessPolicies = ALLOW_WRITE_ACCESS_SP | ALLOW_WRITE_ACCESS_SV | ALLOW_WRITE_ACCESS_SE | ALLOW_WRITE_ACCESS_CF;

#if (CONFIG_IEC61850_REPORT_SERVICE == 1)
    Reporting_activateBufferedReports(self->mmsMapping);
	USART_TRACE("Reporting_activateBufferedReports.. ok\n");

#endif

#if (CONFIG_IEC61850_SETTING_GROUPS == 1)
    MmsMapping_configureSettingGroups(self->mmsMapping);
#endif

//    uint32_t	IPAddr = (u32_t)0xC0A800FCUL;
    IsoServer_setLocalIpAddress(self->isoServer,"127.0.0.1");
//      IsoServer_setLocalIpAddress(self->isoServer,"252.0.168.192");

    // нужно перед createDataSets
//    filesystem_Read_NamedVariableListRequest(self->mmsDevice, iedModel);

    // добавляем датасеты в модель (mmsDevice->mmsDomain->MmsNamedVariableList) из статической структуры iedModel
    createDataSets(self->mmsDevice, iedModel);
    //USART_TRACE_BLUE("создали не удаляемые DataSets из стат. модели\n");

    filesystem_Read_DataOfVariableList(self->mmsServer, self->mmsDevice,_DataListWrites);

    return self;
}

void
IedServer_destroy(IedServer self)
{

    /* Stop server if running */
    if (self->running) {
#if (CONFIG_MMS_THREADLESS_STACK == 1)
        IedServer_stopThreadless(self);
#else
        IedServer_stop(self);
#endif
    }

    MmsServer_destroy(self->mmsServer);
    IsoServer_destroy(self->isoServer);

#if ((CONFIG_MMS_SINGLE_THREADED == 1) && (CONFIG_MMS_THREADLESS_STACK == 0))

    /* trigger stopping background task thread */
    if (self->mmsMapping->reportThreadRunning) {
        self->mmsMapping->reportThreadRunning = false;

        /* waiting for thread to finish */
        while (self->mmsMapping->reportThreadFinished == false) {
            Thread_sleep(10);
        }
    }

#endif

    MmsMapping_destroy(self->mmsMapping);

    LinkedList_destroyDeep(self->clientConnections, (LinkedListValueDeleteFunction) private_ClientConnection_destroy);
    GLOBAL_FREEMEM(self);
}

void
IedServer_setAuthenticator(IedServer self, AcseAuthenticator authenticator, void* authenticatorParameter)
{
    MmsServer_setClientAuthenticator(self->mmsServer, authenticator, authenticatorParameter);
}

MmsServer
IedServer_getMmsServer(IedServer self)
{
    return self->mmsServer;
}

IsoServer
IedServer_getIsoServer(IedServer self)
{
    return self->isoServer;
}

#if (CONFIG_MMS_THREADLESS_STACK != 1)
#if (CONFIG_MMS_SINGLE_THREADED == 1)
static void
singleThreadedServerThread(void* parameter)
{
    IedServer self = (IedServer) parameter;

    MmsMapping* mmsMapping = self->mmsMapping;

    bool running = true;

    mmsMapping->reportThreadFinished = false;
    mmsMapping->reportThreadRunning = true;

    if (DEBUG_IED_SERVER)
        printf("IED_SERVER: server thread started!\n");

    while (running) {

        if (IedServer_waitReady(self, 25) > 0)
            MmsServer_handleIncomingMessages(self->mmsServer);

        IedServer_performPeriodicTasks(self);

        Thread_sleep(1);

        running = mmsMapping->reportThreadRunning;
    }

    if (DEBUG_IED_SERVER)
        printf("IED_SERVER: server thread finished!\n");

    mmsMapping->reportThreadFinished = true;
}
#endif /* (CONFIG_MMS_SINGLE_THREADED == 1) */
#endif /* (CONFIG_MMS_THREADLESS_STACK != 1) */

#if (CONFIG_MMS_THREADLESS_STACK != 1)
void
IedServer_start(IedServer self, int tcpPort)
{
    if (self->running == false) {

#if (CONFIG_MMS_SINGLE_THREADED == 1)
        MmsServer_startListeningThreadless(self->mmsServer, tcpPort);

        Thread serverThread = Thread_create((ThreadExecutionFunction) singleThreadedServerThread, (void*) self, true);

        Thread_start(serverThread);
#else

        MmsServer_startListening(self->mmsServer, tcpPort);
        MmsMapping_startEventWorkerThread(self->mmsMapping);
#endif

        self->running = true;
    }
}
#endif

bool
IedServer_isRunning(IedServer self)
{
    if (IsoServer_getState(self->isoServer) == ISO_SVR_STATE_RUNNING)
        return true;
    else
        return false;
}

IedModel*
IedServer_getDataModel(IedServer self)
{
    return self->model;
}

MmsDevice*
IedServer_getMmsDevice(IedServer self){
    return self->mmsDevice;
}


#if (CONFIG_MMS_THREADLESS_STACK != 1)
void
IedServer_stop(IedServer self)
{
    if (self->running) {
        self->running = false;

        MmsMapping_stopEventWorkerThread(self->mmsMapping);

#if (CONFIG_MMS_SINGLE_THREADED == 1)
        MmsServer_stopListeningThreadless(self->mmsServer);
#else
        MmsServer_stopListening(self->mmsServer);
#endif
    }
}
#endif /* (CONFIG_MMS_THREADLESS_STACK != 1) */


void
IedServer_startThreadless(IedServer self, int tcpPort)
{
    if (self->running == false) {
        MmsServer_startListeningThreadless(self->mmsServer, tcpPort);
        self->running = true;
    }
}

int
IedServer_waitReady(IedServer self, unsigned int timeoutMs)
{
   return MmsServer_waitReady(self->mmsServer, timeoutMs);
}

void
IedServer_processIncomingData(IedServer self)
{
    MmsServer_handleIncomingMessages(self->mmsServer);
}

void
IedServer_getClientconections(uint8_t *pcWriteBuffer, IedServer self)
{
	MmsServer_GetClientList(pcWriteBuffer, self->mmsServer);
}

void
IedServer_stopThreadless(IedServer self)
{
    if (self->running) {
        self->running = false;

        MmsServer_stopListeningThreadless(self->mmsServer);
    }
}

void
IedServer_lockDataModel(IedServer self)
{
    MmsServer_lockModel(self->mmsServer);
}

void
IedServer_unlockDataModel(IedServer self)
{
    MmsServer_unlockModel(self->mmsServer);
}

#if (CONFIG_IEC61850_CONTROL_SERVICE == 1)
static ControlObject*
lookupControlObject(IedServer self, DataObject* node)
{
    char objectReference[130];

    ModelNode_getObjectReference((ModelNode*) node, objectReference);

    char* separator = strchr(objectReference, '/');

    *separator = 0;

    MmsDomain* domain = MmsDevice_getDomain(self->mmsDevice, objectReference);

    char* lnName = separator + 1;

    separator = strchr(lnName, '.');

    assert(separator != NULL);

    *separator = 0;

    char* objectName = separator + 1;

    StringUtils_replace(objectName, '.', '$');

    if (DEBUG_IED_SERVER)
        printf("IED_SERVER: looking for control object: %s\n", objectName);

    ControlObject* controlObject = MmsMapping_getControlObject(self->mmsMapping, domain,
            lnName, objectName);

    return controlObject;
}

void
IedServer_setControlHandler(
        IedServer self,
        DataObject* node,
        ControlHandler listener,
        void* parameter)
{
    ControlObject* controlObject = lookupControlObject(self, node);

    if (controlObject != NULL) {
        ControlObject_installListener(controlObject, listener, parameter);
        if (DEBUG_IED_SERVER)
            printf("IED_SERVER: Installed control handler for %s!\n", node->name);
    }
    else
        if (DEBUG_IED_SERVER)
            printf("IED_SERVER: Failed to install control handler!\n");
}

void
IedServer_setPerformCheckHandler(IedServer self, DataObject* node, ControlPerformCheckHandler handler, void* parameter)
{
    ControlObject* controlObject = lookupControlObject(self, node);

    if (controlObject != NULL)
        ControlObject_installCheckHandler(controlObject, handler, parameter);
}

void
IedServer_setWaitForExecutionHandler(IedServer self, DataObject* node, ControlWaitForExecutionHandler handler,
        void* parameter)
{
    ControlObject* controlObject = lookupControlObject(self, node);

    if (controlObject != NULL)
        ControlObject_installWaitForExecutionHandler(controlObject, handler, parameter);
}
#endif /* (CONFIG_IEC61850_CONTROL_SERVICE == 1) */

#if (CONFIG_IEC61850_SAMPLED_VALUES_SUPPORT == 1)

void
IedServer_setSVCBHandler(IedServer self, SVControlBlock* svcb, SVCBEventHandler handler, void* parameter)
{
    LIBIEC61850_SV_setSVCBHandler(self->mmsMapping, svcb, handler, parameter);
}

#endif /* (CONFIG_IEC61850_SAMPLED_VALUES_SUPPORT == 1) */

MmsValue*
IedServer_getAttributeValue(IedServer self, DataAttribute* dataAttribute)
{
    return dataAttribute->mmsValue;
}

bool
IedServer_getBooleanAttributeValue(IedServer self, const DataAttribute* dataAttribute)
{
    assert(self != NULL);
    assert(dataAttribute != NULL);
    assert(dataAttribute->mmsValue != NULL);
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_BOOLEAN);

    return MmsValue_getBoolean(dataAttribute->mmsValue);
}

int32_t
IedServer_getInt32AttributeValue(IedServer self, const DataAttribute* dataAttribute)
{
    assert(self != NULL);
    assert(dataAttribute != NULL);
    assert(dataAttribute->mmsValue != NULL);
    assert((MmsValue_getType(dataAttribute->mmsValue) == MMS_INTEGER) ||
            (MmsValue_getType(dataAttribute->mmsValue) == MMS_UNSIGNED));

    return MmsValue_toInt32(dataAttribute->mmsValue);
}

int64_t
IedServer_getInt64AttributeValue(IedServer self, const DataAttribute* dataAttribute)
{
    assert(self != NULL);
    assert(dataAttribute != NULL);
    assert(dataAttribute->mmsValue != NULL);
    assert((MmsValue_getType(dataAttribute->mmsValue) == MMS_INTEGER) ||
            (MmsValue_getType(dataAttribute->mmsValue) == MMS_UNSIGNED));

    return MmsValue_toInt64(dataAttribute->mmsValue);
}

uint32_t
IedServer_getUInt32AttributeValue(IedServer self, const DataAttribute* dataAttribute)
{
    assert(self != NULL);
    assert(dataAttribute != NULL);
    assert(dataAttribute->mmsValue != NULL);
    assert((MmsValue_getType(dataAttribute->mmsValue) == MMS_INTEGER) ||
            (MmsValue_getType(dataAttribute->mmsValue) == MMS_UNSIGNED));

    return MmsValue_toUint32(dataAttribute->mmsValue);
}

float
IedServer_getFloatAttributeValue(IedServer self, const DataAttribute* dataAttribute)
{
    assert(self != NULL);
    assert(dataAttribute != NULL);
    assert(dataAttribute->mmsValue != NULL);
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_FLOAT);

    return MmsValue_toFloat(dataAttribute->mmsValue);
}

uint64_t
IedServer_getUTCTimeAttributeValue(IedServer self, const DataAttribute* dataAttribute)
{
    assert(self != NULL);
    assert(dataAttribute != NULL);
    assert(dataAttribute->mmsValue != NULL);
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_UTC_TIME);

    return MmsValue_getUtcTimeInMs(dataAttribute->mmsValue);
}

uint32_t
IedServer_getBitStringAttributeValue(IedServer self, const DataAttribute* dataAttribute)
{
    assert(self != NULL);
    assert(dataAttribute != NULL);
    assert(dataAttribute->mmsValue != NULL);
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_BIT_STRING);
    assert(MmsValue_getBitStringSize(dataAttribute->mmsValue) < 33);

    return MmsValue_getBitStringAsInteger(dataAttribute->mmsValue);
}

const char*
IedServer_getStringAttributeValue(IedServer self, const DataAttribute* dataAttribute)
{
    assert(self != NULL);
    assert(dataAttribute != NULL);
    assert(dataAttribute->mmsValue != NULL);
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_VISIBLE_STRING);

    return MmsValue_toString(dataAttribute->mmsValue);
}

static inline void
checkForUpdateTrigger(IedServer self, DataAttribute* dataAttribute)
{
#if ((CONFIG_IEC61850_REPORT_SERVICE == 1) || (CONFIG_IEC61850_LOG_SERVICE == 1))
	if (dataAttribute->triggerOptions & TRG_OPT_DATA_UPDATE) {

#if (CONFIG_IEC61850_REPORT_SERVICE == 1)
        MmsMapping_triggerReportObservers(self->mmsMapping, dataAttribute->mmsValue, REPORT_CONTROL_VALUE_UPDATE);
#endif

#if (CONFIG_IEC61850_LOG_SERVICE == 1)
        MmsMapping_triggerLogging(self->mmsMapping, dataAttribute->mmsValue, LOG_CONTROL_VALUE_UPDATE);
#endif


    }
#endif /* ((CONFIG_IEC61850_REPORT_SERVICE == 1) || (CONFIG_IEC61850_LOG_SERVICE == 1)) */
}
/*******************************************************
 * checkForChangedTriggers
 * отправка гусов и отчетов если эта функция активна для данного атрибута данных
 *
 * проверка triggerOptions разрешён ли тригер
 * 			TRG_OPT_DATA_CHANGED
 * 			TRG_OPT_QUALITY_CHANGED
 *
 *******************************************************/
static inline void
checkForChangedTriggers(IedServer self, DataAttribute* dataAttribute)
{
#if (CONFIG_IEC61850_REPORT_SERVICE == 1) || (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)

if (dataAttribute->triggerOptions & TRG_OPT_DATA_CHANGED) {

#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
        MmsMapping_triggerGooseObservers(self->mmsMapping, dataAttribute->mmsValue);
#endif

#if (CONFIG_IEC61850_REPORT_SERVICE == 1)
        MmsMapping_triggerReportObservers(self->mmsMapping, dataAttribute->mmsValue, REPORT_CONTROL_VALUE_CHANGED);
#endif

#if (CONFIG_IEC61850_LOG_SERVICE == 1)
        MmsMapping_triggerLogging(self->mmsMapping, dataAttribute->mmsValue,
                LOG_CONTROL_VALUE_CHANGED);
#endif
    }

else if (dataAttribute->triggerOptions & TRG_OPT_QUALITY_CHANGED) {

#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
        MmsMapping_triggerGooseObservers(self->mmsMapping, dataAttribute->mmsValue);
#endif

#if (CONFIG_IEC61850_REPORT_SERVICE == 1)
        MmsMapping_triggerReportObservers(self->mmsMapping, dataAttribute->mmsValue, REPORT_CONTROL_QUALITY_CHANGED);
#endif

#if (CONFIG_IEC61850_LOG_SERVICE == 1)
        MmsMapping_triggerLogging(self->mmsMapping, dataAttribute->mmsValue,
                LOG_CONTROL_QUALITY_CHANGED);
#endif

    }
#endif /* (CONFIG_IEC61850_REPORT_SERVICE== 1) || (CONFIG_INCLUDE_GOOSE_SUPPORT == 1) */


}

//void
int
IedServer_updateAttributeValue(IedServer self, DataAttribute* dataAttribute, MmsValue* value)
{
	int	ret = 0;
    assert(self != NULL);
    assert(dataAttribute != NULL);
    assert(MmsValue_getType(dataAttribute->mmsValue) == MmsValue_getType(value));

    if (MmsValue_equals(dataAttribute->mmsValue, value))
        checkForUpdateTrigger(self, dataAttribute);
    else {
        MmsValue_update(dataAttribute->mmsValue, value);
        checkForChangedTriggers(self, dataAttribute);
        ret = true;
    }
    return	ret;
}

//void
int
IedServer_updateFloatAttributeValue(IedServer self, DataAttribute* dataAttribute, float value)
{
	int	ret = 0;
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_FLOAT);
    assert(dataAttribute != NULL);
    assert(self != NULL);

    float currentValue = MmsValue_toFloat(dataAttribute->mmsValue);

    if (currentValue == value) {
        checkForUpdateTrigger(self, dataAttribute);
    }
    else {
        MmsValue_setFloat(dataAttribute->mmsValue, value);
        checkForChangedTriggers(self, dataAttribute);
        ret = true;
    }
    return	ret;
}
//--------------------------------------------------------------------------------------------------
int	IedServer_updateFloatAttributeValueWithTime(IedServer self, DataAttribute* dataAttribute,DataAttribute* dataAttributeTime, uint64_t time, float value){

	int	ret = false;

    assert(self != NULL);
    assert(dataAttribute != NULL);
    assert(dataAttributeTime != NULL);
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_FLOAT);

    float currentValue = MmsValue_toFloat(dataAttribute->mmsValue);

    if (currentValue == value) {
        checkForUpdateTrigger(self, dataAttribute);
    }
    else
    {
    	IedServer_updateUTCTimeAttributeValue(iedServer, dataAttributeTime, time);		// обновим время

    	MmsValue_setFloat(dataAttribute->mmsValue, value);
        checkForChangedTriggers(self, dataAttribute);
        ret = true;

    }
    return	ret;
}
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//void
int
IedServer_updateInt32AttributeValue(IedServer self, DataAttribute* dataAttribute, int32_t value)
{
	int	ret = 0;

    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_INTEGER);
    assert(dataAttribute != NULL);
    assert(self != NULL);

    int32_t currentValue = MmsValue_toInt32(dataAttribute->mmsValue);

    if (currentValue == value) {
        checkForUpdateTrigger(self, dataAttribute);
    }
    else {
        MmsValue_setInt32(dataAttribute->mmsValue, value);

        checkForChangedTriggers(self, dataAttribute);
        ret = true;
    }
    return	ret;
}
//--------------------------------------------------------------------------------------------------
int	IedServer_updateInt32AttributeValueWithTime(IedServer self, DataAttribute* dataAttribute,DataAttribute* dataAttributeTime, uint64_t time, int32_t value){

	int	ret = false;

    assert(self != NULL);
    assert(dataAttribute != NULL);
    assert(dataAttributeTime != NULL);
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_INTEGER);

    int32_t currentValue = MmsValue_toInt32(dataAttribute->mmsValue);

    if (currentValue == value) {
          checkForUpdateTrigger(self, dataAttribute);
      }
      else {
      	  IedServer_updateUTCTimeAttributeValue(iedServer, dataAttributeTime, time);		// обновим время

      	  MmsValue_setInt32(dataAttribute->mmsValue, value);
          checkForChangedTriggers(self, dataAttribute);
          ret = true;

      }
      return	ret;
}
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//void
int
IedServer_updateInt64AttributeValue(IedServer self, DataAttribute* dataAttribute, int64_t value)
{
	int	ret = 0;

    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_INTEGER);
    assert(dataAttribute != NULL);
    assert(self != NULL);

    int64_t currentValue = MmsValue_toInt64(dataAttribute->mmsValue);

    if (currentValue == value) {
        checkForUpdateTrigger(self, dataAttribute);
    }
    else {
        MmsValue_setInt64(dataAttribute->mmsValue, value);

        checkForChangedTriggers(self, dataAttribute);
        ret = true;
    }
    return	ret;
}

//void
int
IedServer_updateUnsignedAttributeValue(IedServer self, DataAttribute* dataAttribute, uint32_t value)
{
	int	ret = 0;

	assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_UNSIGNED);
    assert(dataAttribute != NULL);
    assert(self != NULL);

    uint32_t currentValue = MmsValue_toUint32(dataAttribute->mmsValue);

    if (currentValue == value) {
        checkForUpdateTrigger(self, dataAttribute);
    }
    else {
        MmsValue_setUint32(dataAttribute->mmsValue, value);
        checkForChangedTriggers(self, dataAttribute);
    	ret = true;
    }
    return	ret;
}

//void
int
IedServer_updateBitStringAttributeValue(IedServer self, DataAttribute* dataAttribute, uint32_t value)
{
	int	ret = 0;

    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_BIT_STRING);
    assert(dataAttribute != NULL);
    assert(self != NULL);

    uint32_t currentValue = MmsValue_getBitStringAsInteger(dataAttribute->mmsValue);

    if (currentValue == value) {
        checkForUpdateTrigger(self, dataAttribute);
    }
    else {
        MmsValue_setBitStringFromInteger(dataAttribute->mmsValue, value);
        checkForChangedTriggers(self, dataAttribute);
    	ret = true;
    }

    return	ret;
}
// -------------------------------------------------------------------------------
int	IedServer_updateBitStringAttributeValueWithTime(IedServer self, DataAttribute* dataAttribute,DataAttribute* dataAttributeTime, uint64_t time, uint32_t value)
{
	int	ret = 0;
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_BIT_STRING);
    assert(dataAttribute != NULL);
    assert(self != NULL);

    uint32_t currentValue = MmsValue_getBitStringAsInteger(dataAttribute->mmsValue);

    if (currentValue == value) {
        checkForUpdateTrigger(self, dataAttribute);
    }
    else {
    	IedServer_updateUTCTimeAttributeValue(iedServer, dataAttributeTime, time);		// обновим время

    	MmsValue_setBitStringFromInteger(dataAttribute->mmsValue, value);
        checkForChangedTriggers(self, dataAttribute);
    	ret = true;

    }
    return	ret;
}
//void
// возврвщает true если были изменения в данных
int
IedServer_updateBooleanAttributeValue(IedServer self, DataAttribute* dataAttribute, bool value)
{
	int	ret = 0;

    assert(self != NULL);
    assert(dataAttribute != NULL);
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_BOOLEAN);

    bool currentValue = MmsValue_getBoolean(dataAttribute->mmsValue);

    if (currentValue == value) {

        checkForUpdateTrigger(self, dataAttribute);
    }
    else {
    	ret = true;
        MmsValue_setBoolean(dataAttribute->mmsValue, value);

        checkForChangedTriggers(self, dataAttribute);
    }
    return	ret;
}
//--------------------------------------------------------------------------------------------------
int	IedServer_updateBooleanAttributeValueWithTime(IedServer self, DataAttribute* dataAttribute,DataAttribute* dataAttributeTime, uint64_t time, bool value){

	int	ret = false;

    assert(self != NULL);
    assert(dataAttribute != NULL);
    assert(dataAttributeTime != NULL);
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_BOOLEAN);

    bool currentValue = MmsValue_getBoolean(dataAttribute->mmsValue);

    if (currentValue == value) {

        checkForUpdateTrigger(self, dataAttribute);
    }else {
    	IedServer_updateUTCTimeAttributeValue(iedServer, dataAttributeTime, time);		// обновим время

        MmsValue_setBoolean(dataAttribute->mmsValue, value);
        checkForChangedTriggers(self, dataAttribute);
    	ret = true;


    }
    return	ret;
}
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
void
IedServer_updateVisibleStringAttributeValue(IedServer self, DataAttribute* dataAttribute, char *value)
{
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_VISIBLE_STRING);
    assert(dataAttribute != NULL);
    assert(self != NULL);

    const char *currentValue = MmsValue_toString(dataAttribute->mmsValue);

    if (!strcmp(currentValue ,value)) {
        checkForUpdateTrigger(self, dataAttribute);
    }
    else {
        MmsValue_setVisibleString(dataAttribute->mmsValue, value);

        checkForChangedTriggers(self, dataAttribute);
    }
}

void
IedServer_updateMMSStringAttributeValue(IedServer self, DataAttribute* dataAttribute, char *value)
{
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_STRING);
    assert(dataAttribute != NULL);
    assert(self != NULL);

    const char *currentValue = MmsValue_toString(dataAttribute->mmsValue);

    if (!strcmp(currentValue ,value)) {
//        checkForUpdateTrigger(self, dataAttribute);
    }
    else {
    	MmsValue_setMmsString(dataAttribute->mmsValue, value);

//        checkForChangedTriggers(self, dataAttribute);
    }
}



void
IedServer_updateUTCTimeAttributeValue(IedServer self, DataAttribute* dataAttribute, uint64_t value)
{
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_UTC_TIME);
    assert(dataAttribute != NULL);
    assert(self != NULL);

    if (self==NULL) return;

    uint64_t currentValue = MmsValue_getUtcTimeInMs(dataAttribute->mmsValue);

    if (currentValue == value) {
        checkForUpdateTrigger(self, dataAttribute);
    }
    else {
        MmsValue_setUtcTimeMs(dataAttribute->mmsValue, value);

        checkForChangedTriggers(self, dataAttribute);
    }

}

void
IedServer_updateTimestampAttributeValue(IedServer self, DataAttribute* dataAttribute, Timestamp* timestamp)
{
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_UTC_TIME);
    assert(dataAttribute != NULL);
    assert(self != NULL);

    if (memcmp(dataAttribute->mmsValue->value.utcTime, timestamp->val, 8) == 0) {
        checkForUpdateTrigger(self, dataAttribute);
    }
    else {
        MmsValue_setUtcTimeByBuffer(dataAttribute->mmsValue, timestamp->val);

        checkForChangedTriggers(self, dataAttribute);
    }
}

// ----------------------------------------------------------------------------------------
Quality	IedServer_GetQuality(DataAttribute* dataAttribute)
{
	Quality qual;
    qual = MmsValue_getBitStringAsInteger(dataAttribute->mmsValue);

return qual;
}
// ----------------------------------------------------------------------------------------
int
IedServer_updateQuality(IedServer self, DataAttribute* dataAttribute, Quality quality)
{
	int	ret = false;

	Quality qual = quality | GLOBAL_QUALITY;
    assert(strcmp(dataAttribute->name, "q") == 0);
    assert(MmsValue_getType(dataAttribute->mmsValue) == MMS_BIT_STRING);
    assert(MmsValue_getBitStringSize(dataAttribute->mmsValue) >= 12);
    assert(MmsValue_getBitStringSize(dataAttribute->mmsValue) <= 15);

    uint32_t oldQuality = MmsValue_getBitStringAsInteger(dataAttribute->mmsValue);

    if (oldQuality != (uint32_t) qual) {
        MmsValue_setBitStringFromInteger(dataAttribute->mmsValue, (uint32_t) qual);

#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
        MmsMapping_triggerGooseObservers(self->mmsMapping, dataAttribute->mmsValue);
#endif

#if (CONFIG_IEC61850_REPORT_SERVICE == 1)
        if (dataAttribute->triggerOptions & TRG_OPT_QUALITY_CHANGED)
            MmsMapping_triggerReportObservers(self->mmsMapping, dataAttribute->mmsValue, REPORT_CONTROL_QUALITY_CHANGED);
#endif

#if (CONFIG_IEC61850_LOG_SERVICE == 1)
        if (dataAttribute->triggerOptions & TRG_OPT_QUALITY_CHANGED)
            MmsMapping_triggerLogging(self->mmsMapping, dataAttribute->mmsValue, LOG_CONTROL_QUALITY_CHANGED);
#endif

        	ret = true;
    }

return ret;
}
// ----------------------------------------------------------------------------------------
int	IedServer_updateQualityWithTime(IedServer self, DataAttribute* dataAttribute, DataAttribute* dataAttributeTime, uint64_t time, Quality quality){

int ret = false;
Quality qual = quality | GLOBAL_QUALITY;

uint32_t oldQuality = MmsValue_getBitStringAsInteger(dataAttribute->mmsValue);

if (oldQuality != (uint32_t) qual) {
   	IedServer_updateUTCTimeAttributeValue(iedServer, dataAttributeTime, time);		// сначала обновим время
	IedServer_updateQuality(self, dataAttribute, quality);
	ret = true;
}
return ret;
}

// ----------------------------------------------------------------------------------------

void
IedServer_enableGoosePublishing(IedServer self)
{
#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
	if (self == NULL) return;
    MmsMapping_enableGoosePublishing(self->mmsMapping);
#endif /* (CONFIG_INCLUDE_GOOSE_SUPPORT == 1) */
}

void
IedServer_enableGooseSimulation(IedServer self)
{
	if (self == NULL)	return;
#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
    MmsMapping_enableGooseSimulation(self->mmsMapping);
#endif /* (CONFIG_INCLUDE_GOOSE_SUPPORT == 1) */
}

void
IedServer_disableGooseSimulation(IedServer self)
{
	if (self == NULL)	return;
#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
    MmsMapping_disableGooseSimulation(self->mmsMapping);
#endif /* (CONFIG_INCLUDE_GOOSE_SUPPORT == 1) */
}

void
IedServer_disableGoosePublishing(IedServer self)
{
#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
	if (self == NULL) return;
    MmsMapping_disableGoosePublishing(self->mmsMapping);
#endif /* (CONFIG_INCLUDE_GOOSE_SUPPORT == 1) */
}

void
IedServer_observeDataAttribute(IedServer self, DataAttribute* dataAttribute,
        AttributeChangedHandler handler)
{
    MmsMapping_addObservedAttribute(self->mmsMapping, dataAttribute, handler);
}

void
IedServer_setWriteAccessPolicy(IedServer self, FunctionalConstraint fc, AccessPolicy policy)
{
    if (policy == ACCESS_POLICY_ALLOW) {
        switch (fc) {
        case IEC61850_FC_DC:
            self->writeAccessPolicies |= ALLOW_WRITE_ACCESS_DC;
            break;
        case IEC61850_FC_CF:
            self->writeAccessPolicies |= ALLOW_WRITE_ACCESS_CF;
            break;
        case IEC61850_FC_SP:
            self->writeAccessPolicies |= ALLOW_WRITE_ACCESS_SP;
            break;
        case IEC61850_FC_SV:
            self->writeAccessPolicies |= ALLOW_WRITE_ACCESS_SV;
            break;
        case IEC61850_FC_SE:
            self->writeAccessPolicies |= ALLOW_WRITE_ACCESS_SE;
            break;
        default: /* ignore - request is invalid */
            break;
        }
    }
    else {
        switch (fc) {
        case IEC61850_FC_DC:
            self->writeAccessPolicies &= ~ALLOW_WRITE_ACCESS_DC;
            break;
        case IEC61850_FC_CF:
            self->writeAccessPolicies &= ~ALLOW_WRITE_ACCESS_CF;
            break;
        case IEC61850_FC_SP:
            self->writeAccessPolicies &= ~ALLOW_WRITE_ACCESS_SP;
            break;
        case IEC61850_FC_SV:
            self->writeAccessPolicies &= ~ALLOW_WRITE_ACCESS_SV;
            break;
        case IEC61850_FC_SE:
            self->writeAccessPolicies &= ALLOW_WRITE_ACCESS_SE;
            break;
        default: /* ignore - request is invalid */
            break;
        }
    }
}

void
IedServer_handleWriteAccess(IedServer self, DataAttribute* dataAttribute, WriteAccessHandler handler, void* parameter)
{
    if (dataAttribute == NULL)
        *((int*) NULL) = 1;

    MmsMapping_installWriteAccessHandler(self->mmsMapping, dataAttribute, handler, parameter);
}

void
IedServer_setConnectionIndicationHandler(IedServer self, IedConnectionIndicationHandler handler, void* parameter)
{
    MmsMapping_setConnectionIndicationHandler(self->mmsMapping, handler, parameter);
}

MmsValue*
IedServer_getFunctionalConstrainedData(IedServer self, DataObject* dataObject, FunctionalConstraint fc)
{
    char buffer[128]; /* buffer for variable name string */
    char* currentStart = buffer + 127;
    currentStart[0] = 0;
    MmsValue* value = NULL;

    int nameLen;

    while (dataObject->modelType == DataObjectModelType) {
        nameLen = strlen(dataObject->name);
        currentStart -= nameLen;
        memcpy(currentStart, dataObject->name, nameLen);
        currentStart--;
        *currentStart = '$';

        if (dataObject->parent->modelType == DataObjectModelType)
            dataObject = (DataObject*) dataObject->parent;
        else
            break;
    }

    char* fcString = FunctionalConstraint_toString(fc);

    currentStart--;
    *currentStart = fcString[1];
    currentStart--;
    *currentStart = fcString[0];
    currentStart--;
    *currentStart = '$';

    LogicalNode* ln = (LogicalNode*) dataObject->parent;

    nameLen = strlen(ln->name);

    currentStart -= nameLen;
    memcpy(currentStart, ln->name, nameLen);

    LogicalDevice* ld = (LogicalDevice*) ln->parent;

    char domainName[65];

    if ((strlen(self->model->name) + strlen(ld->name)) > 64)
        goto exit_function; // TODO call exception handler!

    strncpy(domainName, self->model->name, 64);
    strncat(domainName, ld->name, 64);

    MmsDomain* domain = MmsDevice_getDomain(self->mmsDevice, domainName);

    if (domain == NULL)
        goto exit_function; // TODO call exception handler!

    value = MmsServer_getValueFromCache(self->mmsServer, domain, currentStart);

exit_function:
    return value;
}

void
IedServer_changeActiveSettingGroup(IedServer self, SettingGroupControlBlock* sgcb, uint8_t newActiveSg)
{
#if (CONFIG_IEC61850_SETTING_GROUPS == 1)
    MmsMapping_changeActiveSettingGroup(self->mmsMapping, sgcb, newActiveSg);
#endif
}

uint8_t
IedServer_getActiveSettingGroup(IedServer self, SettingGroupControlBlock* sgcb)
{
    return sgcb->actSG;
}

void
IedServer_setActiveSettingGroupChangedHandler(IedServer self, SettingGroupControlBlock* sgcb,
        ActiveSettingGroupChangedHandler handler, void* parameter)
{
#if (CONFIG_IEC61850_SETTING_GROUPS == 1)
    MmsMapping_setSgChangedHandler(self->mmsMapping, sgcb, handler, parameter);
#endif
}

void
IedServer_setEditSettingGroupChangedHandler(IedServer self, SettingGroupControlBlock* sgcb,
        EditSettingGroupChangedHandler handler, void* parameter)
{
#if (CONFIG_IEC61850_SETTING_GROUPS == 1)
    MmsMapping_setEditSgChangedHandler(self->mmsMapping, sgcb, handler, parameter);
#endif
}

void
IedServer_setEditSettingGroupConfirmationHandler(IedServer self, SettingGroupControlBlock* sgcb,
        EditSettingGroupConfirmationHandler handler, void* parameter)
{
#if (CONFIG_IEC61850_SETTING_GROUPS == 1)
    MmsMapping_setConfirmEditSgHandler(self->mmsMapping, sgcb, handler, parameter);
#endif
}

void
IedServer_setLogStorage(IedServer self, const char* logRef, LogStorage logStorage)
{
#if (CONFIG_IEC61850_LOG_SERVICE == 1)
    MmsMapping_setLogStorage(self->mmsMapping, logRef, logStorage);
#endif
}

ClientConnection
private_IedServer_getClientConnectionByHandle(IedServer self, void* serverConnectionHandle)
{
    LinkedList element = LinkedList_getNext(self->clientConnections);
    ClientConnection matchingConnection = NULL;

    while (element != NULL) {
        ClientConnection connection = (ClientConnection) element->data;

        if (private_ClientConnection_getServerConnectionHandle(connection) == serverConnectionHandle) {
            matchingConnection = connection;
            break;
        }

        element = LinkedList_getNext(element);
    }

    return matchingConnection;
}

void
private_IedServer_addNewClientConnection(IedServer self, ClientConnection newClientConnection)
{
    LinkedList_add(self->clientConnections, (void*) newClientConnection);
}

void
private_IedServer_removeClientConnection(IedServer self, ClientConnection clientConnection)
{
    LinkedList_remove(self->clientConnections, clientConnection);
}


void
IedServer_setGooseInterfaceId(IedServer self, const char* interfaceId)
{
#if (CONFIG_INCLUDE_GOOSE_SUPPORT == 1)
    self->mmsMapping->gooseInterfaceId = interfaceId;
#endif
}


/*******************************************************
 * MmsMapping_DataUpdateInGoosesDatasets
 * обновим данные в датасетах прописаных в гусах
 *******************************************************/
int	IedServer_DataUpdateInGoosesDatasets(IedServer self)
{
	uint16_t 	FunctionCode;
	uint16_t	num;
	int			RetifDataUpdated = 0;

	MmsMapping* MmsMap = self->mmsMapping;
    LinkedList element = MmsMap->gseControls;

    while ((element = LinkedList_getNext(element)) != NULL) {				// берём все гусы(gseControls) по списку.
        MmsGooseControlBlock gcb = (MmsGooseControlBlock) element->data;

        if (MmsGooseControlBlock_isEnabled(gcb)) {							// если этот гус активен
            DataSet* dataSet = MmsGooseControlBlock_getDataSet(gcb);		// берём датасет из БУ гуса

            RetifDataUpdated = 0;

            MmsGooses_PAUSEMode(self);
           //-------
            DataSetEntry* dataSetEntry = dataSet->fcdas;					// элементы датасета
            while (dataSetEntry != NULL) {									// пробежим по всем элементам

                MmsValue* dataSetValue = dataSetEntry->value;
                if (dataSetValue != NULL) {
                	MmsValue_getFunctionDataUpdate(dataSetValue, &FunctionCode ,&num);
                	RetifDataUpdated |= IedDataUpdateFuncRun(FunctionCode, num);
                }

                dataSetEntry = dataSetEntry->sibling;

            }// !while (dataSetEntry != NULL)
            //-------
        	MmsGooses_RUNMode(self);
			//для каждого гуса будем решать надо отправка или нет
			if (RetifDataUpdated) {

				MmsGooseControlBlock_observedObjectChanged(gcb);
			}
        }
    }
    return	0;
}

// режим проверки данных в надобности отправки гусов
void	MmsGooses_RUNMode(IedServer self){
	MmsMapping* MmsMap = self->mmsMapping;
	MmsMap->goosesCurrentMode = GOOSE_READY;
}
				// пропускаем проверку на изменение данных в DS гусов
void	MmsGooses_PAUSEMode(IedServer self){

	MmsMapping* MmsMap = self->mmsMapping;
	MmsMap->goosesCurrentMode = GOOSE_PAUSE;
}
/*******************************************************
 * IedServer_NumPltUpdate_swRev
 * обновим данные
 *******************************************************/
int	IedServer_NumPltUpdate_swRev(IedServer self, char*	swrev){
int	ret = 0;

   	USART_TRACE_GREEN("NamPlt_swRev:'%s'\n",(char *)swrev);
	    if (self){
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_LD0_LLN0_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LLN0_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_LLN0_NamPlt_swRev , swrev);

#if defined (MR851)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_RPN_LLN0_NamPlt_swRev , swrev);
#else
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_LLN0_NamPlt_swRev , swrev);
#if		!defined (MR761OBR)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_LLN0_NamPlt_swRev , swrev);
#endif

#endif

//PROT
#if defined (MR5_700) || defined (MR5_500) || defined (MR741)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC4_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I2PTOC1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I2PTOC2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I0PTOC1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I0PTOC2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_INPTOC1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_INPTOC2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IGPTOC_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I2I1PTOC_NamPlt_swRev , swrev);
#endif
#if defined (MR5_700) || defined (MR5_600) || defined (MR741)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTUV1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTUV2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTOV1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTOV2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_U2PTOV1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_U2PTOV2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_U0PTOV1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_U0PTOV2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTUF1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTUF2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTOF1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTOF2_NamPlt_swRev , swrev);
#endif
#if defined (MR5_600)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTUV3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTUV4_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTOV3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTOV4_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_U0PTOV3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_U0PTOV4_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_U1PTUV1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_U1PTUV2_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTUF3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTUF4_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTOF3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTOF4_NamPlt_swRev , swrev);

#endif
#if defined (MR5_700) || defined (MR5_500) || defined (MR741)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_LZSHPTOC_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_RREC_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_RBRF_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_NamPlt_swRev , swrev);
#endif

#if defined (MR5_700) || defined (MR5_600) || defined (MR5_500) || defined (MR741)

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_NamPlt_swRev , swrev);

#endif

#if defined	(MR801) && defined (OLD)

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_LD0_RDRE1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IDPDIF_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IDDPDIF_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IDDMPDIF_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_ID0PDIF1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_ID0PDIF2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_ID0PDIF3_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC4_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC5_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC6_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC7_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC8_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTUF1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTUF2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTUF3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTUF4_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTOF1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTOF2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTOF3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTOF4_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTUV1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTUV2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTUV3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTUV4_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTOV1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTOV2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTOV3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTOV4_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_LZSHPTOC_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_RREC_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_RBRF_NamPlt_swRev , swrev);

#endif

#if defined	(MR801) && defined (T12N5D58R51)



#endif

//PROT
#if defined (MR761) || defined (MR762) || defined (MR763)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_LD0_RDRE1_NamPlt_swRev , swrev);

			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC1_NamPlt_swRev , swrev);
			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC2_NamPlt_swRev , swrev);
			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC3_NamPlt_swRev , swrev);
			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC4_NamPlt_swRev , swrev);
			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC5_NamPlt_swRev , swrev);
			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTOC6_NamPlt_swRev , swrev);

			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IPTUC1_NamPlt_swRev , swrev);

			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_NamPlt_swRev , swrev);
			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_NamPlt_swRev , swrev);
			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_NamPlt_swRev , swrev);
			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_NamPlt_swRev , swrev);
			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_NamPlt_swRev , swrev);
			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_NamPlt_swRev , swrev);
			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I20PTOC7_NamPlt_swRev , swrev);
			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I20PTOC8_NamPlt_swRev , swrev);

			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_I2I1PTOC1_NamPlt_swRev , swrev);

			IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_IARCPTOC_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTUF1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTUF2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTUF3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTUF4_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTOF1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTOF2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTOF3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PTOF4_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTUV1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTUV2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTUV3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTUV4_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTOV1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTOV2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTOV3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_UPTOV4_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PDPR1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PDPR2_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_BLKPTTR1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_QPTTR2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_QPTTR1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_RREC1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_RPSB1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_RSYN1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_RBRF1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_NBLKGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PDIS1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PDIS2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PDIS3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PDIS4_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PDIS5_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_PDIS6_NamPlt_swRev , swrev);

#endif

#if defined (MR761OBR)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_NamPlt_swRev , swrev);
#endif

// MES --------------------------------------------------------------------------------------------------
// GGIO -------------------------------------------------------------------------------------------------
// CTRL -------------------------------------------------------------------------------------------------

#if defined (MR5_500)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MSQI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MMXU1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_GGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_PTRC_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_CSWI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_XCBR1_NamPlt_swRev , swrev);

#endif
#if defined (MR5_600)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MSQI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MMXU1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_GGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_PTRC_NamPlt_swRev , swrev);

#endif
#if defined (MR5_700)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MSQI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MMXU1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_RFLO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_GGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_PTRC_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_CSWI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_XCBR1_NamPlt_swRev , swrev);

#endif
#if defined (MR741)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MSQI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MMXU1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_RFLO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_GGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_PTRC_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_CSWI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_XCBR1_NamPlt_swRev , swrev);

#endif
#if defined (MR761) || defined (MR762) || defined (MR763)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MSQI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MMXU1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_RFLO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_GGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_PTRC_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_CSWI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_XCBR1_NamPlt_swRev , swrev);

#endif
#if defined (MR761OBR)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_GGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_PTRC_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_CSWI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_XCBR1_NamPlt_swRev , swrev);

#endif
#if defined (MR801) && defined (OLD)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MSQI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MMXU1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_GGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_PTRC_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_CSWI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_XCBR1_NamPlt_swRev , swrev);

#endif
#if defined	(MR801) && defined (T12N5D58R51)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_S1MMXU1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_S2MMXU1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_S1MSQI1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_GGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_PTRC_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_CSWI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_XCBR1_NamPlt_swRev , swrev);

#endif
#if defined (MR851)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_NamPlt_swRev , swrev);

#endif
#if defined (MR901) || defined (MR902)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_NamPlt_swRev , swrev);

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_GGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_PTRC_NamPlt_swRev , swrev);

#endif
/*
#if !defined (MR5_600) && !defined (MR5_500) &&\
	!defined (MR801) &&\
	!defined (MR901) && !defined (MR902) &&\
	!defined (MR851) &&\
	!defined (MR761OBR)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_RFLO1_NamPlt_swRev , swrev);
#endif

#if	!defined (MR901) && !defined (MR902) &&\
	!defined (MR851) &&\
	!defined (MR761OBR)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MSQI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MMXU1_NamPlt_swRev , swrev);
#endif
*/
/*	    	//GGIO
#if	!defined (MR851)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_NamPlt_swRev , swrev);
#endif

	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_NamPlt_swRev , swrev);

	    	//CTRL
#if !defined (MR5_600) &&\
		!defined (MR901) && !defined (MR902)&&\
		!defined (MR851)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_CSWI1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_XCBR1_NamPlt_swRev , swrev);
#endif

#if !defined (MR851)
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_GGIO1_NamPlt_swRev , swrev);
	    	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_CTRL_PTRC_NamPlt_swRev , swrev);
#endif
*/
	    	ret = true;
	    }

 return	ret;
}

