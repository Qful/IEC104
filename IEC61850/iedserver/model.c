/*
 *  model.c
 *
 *  Copyright 2013 Michael Zillgith
 *
 *	This file is part of libIEC61850.
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


#include "model.h"

/*************************************************************************
 * IedModel_getLogicalDeviceCount
 * получим количество LD логических устройств в нашем IED реальном электронное устройство
 *************************************************************************/
int	IedModel_getLogicalDeviceCount(IedModel* iedModel)
{
	if (iedModel->firstChild == NULL)	return 0;

	LogicalDevice* logicalDevice = iedModel->firstChild;		// первое логическое устройство LD

	int ldCount = 1;

	while (logicalDevice->sibling != NULL) {					// посчитаем все наследуемые LD
		logicalDevice = logicalDevice->sibling;
		ldCount++;
	}
	return ldCount;												// вернем чило
}

DataSet*
IedModel_lookupDataSet(IedModel* model, char* dataSetReference  /* e.g. ied1Inverter/LLN0$dataset1 */)
{
	DataSet* dataSet = model->dataSets[0];

	char* separator = strchr(dataSetReference, '/');

	if (separator == NULL)
		return NULL;

	int ldNameLen = separator - dataSetReference;

	int i = 0;
	while (dataSet != NULL) {
		if (strncmp(dataSet->logicalDeviceName, dataSetReference, ldNameLen) == 0) {
			if (strcmp(dataSet->name, separator + 1) == 0) {
				return dataSet;
			}
		}

		i++;
		dataSet = model->dataSets[i];
	}

	return NULL;
}

/*************************************************************************
 * DataObject_hasFCData
 *
 *************************************************************************/
bool	DataObject_hasFCData(DataObject* dataObject, FunctionalConstraint fc)
{
	ModelNode* modelNode = dataObject->firstChild;

	while (modelNode != NULL) {

		if (modelNode->modelType == DataAttributeModelType) {				// если тип modelType == DataAttribute
			DataAttribute* dataAttribute = (DataAttribute*) modelNode;

			if (dataAttribute ->fc == fc)									// то присвоим ‘ункциональную св€зь
				return true;												// и вернЄмс€
		}
		else if (modelNode->modelType == DataObjectModelType) {				// если тип modelType == DataObject
			DataObject* dataObject = (DataObject*) modelNode;

			if (DataObject_hasFCData(dataObject, fc))
				return true;
		}

		modelNode = modelNode->sibling;										// следующий
	}

	return false;
}

/*************************************************************************
 * LogicalNode_hasFCData
 *
 *************************************************************************/
bool		LogicalNode_hasFCData(LogicalNode* node, FunctionalConstraint fc)
{
	DataObject* dataObject = node->firstChild;

	while (dataObject != NULL) {
		if (DataObject_hasFCData(dataObject, fc))
			return true;

		dataObject = dataObject->sibling;
	}

	return false;
}

/*************************************************************************
 * LogicalDevice_getLogicalNodeCount
 * сосчитаем число логических узлов LN в LD лог. устройстве
 *************************************************************************/
int	LogicalDevice_getLogicalNodeCount(LogicalDevice* logicalDevice)
{
	int lnCount = 0;

	LogicalNode* logicalNode = logicalDevice->firstChild;

	while (logicalNode != NULL) {
		logicalNode = (LogicalNode*) logicalNode->sibling;
		lnCount++;
	}

	return lnCount;
}

//ModelNode_getObjectReference

static int
createObjectReference(ModelNode* node, char* objectReference)
{
    ModelNodeType type;

    int bufPos;

    if (node->modelType != LogicalNodeModelType) {
        bufPos = createObjectReference(node->parent, objectReference);

        objectReference[bufPos++] = '.';
    }
    else {
        LogicalNode* lNode = (LogicalNode*) node;

        LogicalDevice* lDevice = lNode->parent;

        bufPos = 0;

        int nameLength = strlen(lDevice->name);

        int i;
        for (i = 0; i < nameLength; i++) {
            objectReference[bufPos++] = lDevice->name[i];
        }

        objectReference[bufPos++] = '/';
    }

    /* append own name */
    int nameLength = strlen(node->name);

    int i;
    for (i = 0; i < nameLength; i++) {
        objectReference[bufPos++] = node->name[i];
    }

    return bufPos;
}

char*
ModelNode_getObjectReference(ModelNode* node, char* objectReference)
{
    if (objectReference == NULL)
        objectReference = malloc(130);

    int bufPos = createObjectReference(node, objectReference);

    objectReference[bufPos] = 0;

    return objectReference;
}

int
ModelNode_getChildCount(ModelNode* modelNode) {
	int childCount = 0;

	ModelNode* child = modelNode->firstChild;

	while (child != NULL) {
		childCount++;
		child = child->sibling;
	}

	return childCount;
}

