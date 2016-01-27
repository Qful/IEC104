/*
 *  model.h
 *
 *  Copyright 2013 Michael Zillgith
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

#ifndef MODEL_H_
#define MODEL_H_

#include "libiec61850_platform_includes.h"

#include "mms_value.h"
#include "iec61850_common.h"

typedef struct sModelNode ModelNode;
typedef struct sLogicalNode LogicalNode;
typedef struct sDataObject DataObject;
typedef struct sDataAttribute DataAttribute;
typedef struct sLogicalDevice LogicalDevice;
typedef struct sIedModel IedModel;


typedef enum eDataAttributeType {
	BOOLEAN,/* int */
	INT8,   /* int8_t */
	INT16,  /* int16_t */
	INT32,  /* int32_t */
	INT64,  /* int64_t */
	INT8U,  /* uint8_t */
	INT16U, /* uint16_t */
	INT24U, /* uint32_t */
	INT32U, /* uint32_t */
	FLOAT32, /* float */
	FLOAT64, /* double */
	ENUMERATED,
	OCTET_STRING_64,
	OCTET_STRING_6,
	OCTET_STRING_8,
	VISIBLE_STRING_32,
	VISIBLE_STRING_64,
	VISIBLE_STRING_65,
	VISIBLE_STRING_129,
	VISIBLE_STRING_255,
	UNICODE_STRING_255,
	TIMESTAMP,
	QUALITY,
	CHECK,
	CODEDENUM,
	GENERIC_BITSTRING,
	CONSTRUCTED,
	ENTRY_TIME,
	PHYCOMADDR
} DataAttributeType;

typedef enum {
	LogicalNodeModelType,
	DataObjectModelType,
	DataAttributeModelType,
} ModelNodeType;

typedef struct DataSet* DataSetPtr;
typedef struct ReportControlBlock* ReportControlBlockPtr;
typedef struct GSEControlBlock* GSEControBlockPtr;

// модель IED (intellegent electronic device) электронное устройство
struct sIedModel {
	char* 					name;					// им€ электронного устройства
	LogicalDevice* 			firstChild;				// первое логическое устройство LD в реальном IED
	DataSetPtr* 			dataSets;
	ReportControlBlockPtr* 	rcbs;
	GSEControBlockPtr* 		gseCBs;
	void (*initializer) ();
};
// модель LD (logical device) логическое устройство
struct sLogicalDevice {
	char* name;								// им€ устройства
	LogicalDevice* sibling;					// одноранговый следующий узел
	LogicalNode* firstChild;				// первый LN(логический узел)
	MmsDomain* mmsDomain;
};
// модель LN (logical node) логического узла
struct sModelNode {
	ModelNodeType modelType;
	char* name;
	ModelNode* parent;
	ModelNode* sibling;
	ModelNode* firstChild;
};
// модель LN (logical node) логического узла
struct sLogicalNode {
	ModelNodeType modelType;			// тип : LogicalNode,DataObject,DataAttribute
	char* name;							// им€ узла
	LogicalDevice* parent;				// родитель узла (LD (logical device))
	ModelNode* sibling;					// одноранговый следующий узел
	ModelNode* firstChild;				// первый наследник
};

struct sDataObject {
	ModelNodeType modelType;			// тип : LogicalNode,DataObject,DataAttribute
	char* name;							// им€ узла
	ModelNode* parent;					// родитель  LN
	ModelNode* sibling;					// одноранговый следующий узел
	ModelNode* firstChild;				// первый наследник

	int observerCount; 					// количество наблюдателей в текущий момент смотр€т за этим узлом
	int elementCount;  					// если > 0 если массив

	//MmsTypeSpecification* typeSpec;
	//MmsValue* mmsValue;
};

struct sDataAttribute {
	ModelNodeType modelType;			// тип модели (LogicalNode,DataObject,DataAttribute)
	char* name;							// им€
	ModelNode* parent;					// родитель
	ModelNode* sibling;					// одноранговый
	ModelNode* firstChild;				// первый наследник

	int observerCount; 					// количество наблюдателей в текущий момент смотр€т за этим узлом
	int elementCount;  					// если > 0 если массив

	FunctionalConstraint fc;			// ‘ункциональные св€зи
	DataAttributeType type;				// тип переменной

	//MmsTypeSpecification* typeSpec;
	MmsValue* mmsValue;					//
};

typedef struct {
	char* logicalDeviceName;
	char* variableName;
	int index;
	char* componentName;
	MmsValue* value;
} DataSetEntry;

typedef struct {
	char* logicalDeviceName;
	char* name; /* eg. MMXU1$dataset1 */
	int elementCount;
	DataSetEntry** fcda;
} DataSet;

// ћодель класса REPORTCONTROLBLOCK
typedef struct {
	LogicalNode* parent;
	char* name;							// 14.2.2.2 им€	блока буферизованного управлени€ отчетом
	char* rptId;						// 14.2.2.4 јтрибут RptID идентификатор	отчета
	bool buffered;						// BUFFEREDREPORTCONTROLBLOCK(BRCB) или UNBUFFEREDREPORTCONTROLBLOCK(URCB)
	char* dataSetName; 					// 14.2.2.6 јтрибут DatSet ссылка набора данных /* pre loaded with relative name in logical node */

	uint32_t confRef;    				// 14.2.2.7 јтрибут ConfRev ревизи€ конфигурации /* ConfRef - configuration revision */
	uint8_t trgOps;      				/* TrgOps - trigger conditions */
	uint8_t options;     				// 14.2.2.8 јтрибут OptFlds опциональные пол€, включаемые в отчет /* OptFlds */
	uint32_t bufferTime; 				// 14.2.2.9 јтрибут BufTm буферное врем€ /* BufTm - time to buffer events until a report is generated */
	uint32_t intPeriod;  				/* IntPrd - период целостности */

	//char* owner;
} ReportControlBlock;

typedef struct {
    uint8_t vlanPriority;
    uint16_t vlanId;
    uint16_t appId;
    uint8_t dstAddress[6];
} PhyComAddress;

typedef struct {
    LogicalNode* parent;
    char* name;
    char* appId;
    char* dataSetName; /* pre loaded with relative name in logical node */
    uint32_t confRef;  /* ConfRef - configuration revision */
    bool fixedOffs;    /* fixed offsets */
    PhyComAddress* address; /* GSE communication parameters */
} GSEControlBlock;


LogicalDevice*
IedModel_getDevice(IedModel* model, char* deviceName);

/*
 *  \param dataSetReference MMS mapping object reference! e.g. ied1Inverter/LLN0$dataset1
 */
DataSet*
IedModel_lookupDataSet(IedModel* model, char* dataSetReference);

int
IedModel_getLogicalDeviceCount(IedModel* iedModel);

LogicalNode*
LogicalDevice_getLogicalNode(LogicalDevice* device, char* nodeName);

int
LogicalDevice_getLogicalNodeCount(LogicalDevice* logicalDevice);

bool
LogicalNode_hasFCData(LogicalNode* node, FunctionalConstraint fc);

bool
LogicalNode_hasBufferedReports(LogicalNode* node);

bool
LogicalNode_hasUnbufferedReports(LogicalNode* node);

bool
DataObject_hasFCData(DataObject* dataObject, FunctionalConstraint fc);

int
ModelNode_getChildCount(ModelNode* modelNode);

char*
ModelNode_getObjectReference(ModelNode* node, char* objectReference);

#endif /* MODEL_H_ */
