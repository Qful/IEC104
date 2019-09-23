/*
 * dataDbzeroDB.c
 *
 *  Created on: 18.01.2018
 *      Author: sagok
 */

#include "main.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "dataDbzeroDB.h"

#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"
#endif

#if defined	(MR771)
#include "static_model_MR771.h"
#endif

#if defined	(MR761) || defined	(MR762) || defined	(MR763)
#include "static_model_MR76x.h"
#endif

#if  defined (MR761OBR)
#include "static_model_MR761OBR.h"
#endif

#if defined	(MR801) && defined (OLD)
#include "static_model_MR801.h"
#endif

#if defined	(MR801) && defined (T12N5D58R51)
#include "static_model_MR801_T12N5D58R51.h"
#endif

#if defined	(MR851)
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


/*******************************************************
 *
 *******************************************************/
int	Set_Db_zeroDB_float(float mag, float diapazon, DataAttribute*	modelDb, DataAttribute*	modelzeroDb, DataAttribute*	modelinstMag, DataAttribute*	modelmag, DataAttribute*	modelT, uint64_t currentTime)
{
	int		ret = false;
	float	premag;
	float	level;
	float	K_dbLevel;
	float	dbLevel;
	float	zeroDbLevel;

	if (	(NULL == modelDb)		||\
			(NULL == modelzeroDb) 	||\
			(NULL == modelinstMag) 	||\
			(NULL == modelmag) 		||\
			(NULL == modelT) 		)
	{
		USART_TRACE_RED("Set_Db_zeroDB_float ERROR DataAttribute == NULL\n");
		return false;
	}

	K_dbLevel = (float)diapazon /(float)DbPercent;		// 0,00001%
	dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,modelDb)* K_dbLevel;
	zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,modelzeroDb)* K_dbLevel;

//	ret |=	IedServer_updateFloatAttributeValueWithTime(iedServer, modelinstMag, modelT, currentTime, mag);
	IedServer_updateFloatAttributeValue(iedServer,modelinstMag,mag);

	if (mag<zeroDbLevel) {
		ret |= IedServer_updateFloatAttributeValueWithTime(iedServer, modelmag, modelT, currentTime, 0);
	}else{
		premag = IedServer_getFloatAttributeValue(iedServer,modelmag);
		if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
		if (level > dbLevel) {ret |= IedServer_updateFloatAttributeValueWithTime(iedServer, modelmag, modelT, currentTime, mag);}

		//IedServer_updateFloatAttributeValue(iedServer,modelmag,mag);
	}

return ret;
}
/*******************************************************
 * диапазон симметрично вниз вверх от нуля. т.е.
 * -diapazon/2 .... diapazon/2
 *******************************************************/
int	Set_Db_zeroDB_Znak_float(float mag, float diapazon, DataAttribute*	modelDb, DataAttribute*	modelzeroDb, DataAttribute*	modelinstMag, DataAttribute*	modelmag, DataAttribute*	modelT, uint64_t currentTime)
{
	int		ret = false;
	float	premag;
	float	level;
	float	K_dbLevel;
	float	dbLevel;
	float	zeroDbLevel;

	if (	(NULL == modelDb)		||\
			(NULL == modelzeroDb) 	||\
			(NULL == modelinstMag) 	||\
			(NULL == modelmag) 		||\
			(NULL == modelT) 		)
	{
		USART_TRACE_RED("Set_Db_zeroDB_float ERROR DataAttribute == NULL\n");
		return false;
	}

	K_dbLevel 	= (float)diapazon /(float)DbPercent;		// 0,00001%
//	K_dbLevel  /= 2;
	dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,modelDb)* K_dbLevel;
	zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,modelzeroDb)* K_dbLevel;

	IedServer_updateFloatAttributeValue(iedServer,modelinstMag,mag);

	if ((mag>0)&&(mag<zeroDbLevel)) {
		ret |= IedServer_updateFloatAttributeValueWithTime(iedServer, modelmag, modelT, currentTime, 0);
	}else
	if ((mag<0)&&(mag>-zeroDbLevel)) {
		ret |= IedServer_updateFloatAttributeValueWithTime(iedServer, modelmag, modelT, currentTime, 0);
	}else
	{
		premag = IedServer_getFloatAttributeValue(iedServer,modelmag);				// предыдущее значение
		if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}	// ступенька
		if (level > dbLevel) {ret |= IedServer_updateFloatAttributeValueWithTime(iedServer, modelmag, modelT, currentTime, mag);}

	}

return ret;
}
/*******************************************************
 *
 *******************************************************/
int	Set_Db_zeroDB_Freq_float(float mag, float diapazon, DataAttribute*	modelDb, DataAttribute*	modelzeroDb, DataAttribute*	modelinstMag, DataAttribute*	modelmag, DataAttribute*	modelT, uint64_t currentTime)
{
	int		ret = false;
	float	premag;
	float	level;
	float	K_dbLevel;
	float	dbLevel;
	float	zeroDbLevel;

	if (	(NULL == modelDb)		||\
			(NULL == modelzeroDb) 	||\
			(NULL == modelinstMag) 	||\
			(NULL == modelmag) 		||\
			(NULL == modelT) 		)
	{
		USART_TRACE_RED("Set_Db_zeroDB_float ERROR DataAttribute == NULL\n");
		return false;
	}

	K_dbLevel = (float)diapazon /(float)DbPercent;		// 0,00001%
	dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,modelDb)* K_dbLevel;
	zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,modelzeroDb)* K_dbLevel;

//	ret |=	IedServer_updateFloatAttributeValueWithTime(iedServer, modelinstMag, modelT, currentTime, mag);
	IedServer_updateFloatAttributeValue(iedServer,modelinstMag,mag);

	if ( (mag > (50 - zeroDbLevel)) && (mag < (50 + zeroDbLevel)))
//	if (mag<zeroDbLevel)
	{
		ret |= IedServer_updateFloatAttributeValueWithTime(iedServer, modelmag, modelT, currentTime, 50);
	}else{
		premag = IedServer_getFloatAttributeValue(iedServer,modelmag);
		if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
		if (level > dbLevel) {ret |= IedServer_updateFloatAttributeValueWithTime(iedServer, modelmag, modelT, currentTime, mag);}

		//IedServer_updateFloatAttributeValue(iedServer,modelmag,mag);
	}

return ret;
}
