/*
 * datatoMSQI.c
 *
 *  Created on: 05.05.2017
 *      Author: sagok
 */


#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "datatoMMXU.h"
#include "dataDbzeroDB.h"

#define _SeqT	0
/*******************************************************
 * MR851
 *******************************************************/
#if defined (MR851)
#include "static_model_MR851.h"

/*******************************************************
 * заглушки
 *******************************************************/
int		Set_MSQI	(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR901 MR902
 *******************************************************/
#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"
/*******************************************************
 * заглушки
 *******************************************************/
int		Set_MSQI	(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR801
 *******************************************************/
#if defined (MR801)
#include "static_model_MR801.h"

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucConfigTRMeasBuf[MB_NumbConfigTRMeas];
extern uint16_t   ucConfigTRPWRBuf[MB_NumbConfigTRPWR];


//	MSQI1  MB_bOffsetModule4
//	MSQI2  MB_bOffsetModule4
//	MSQI3  MB_bOffsetModule5
//	MSQI4  MB_bOffsetModule5

/*******************************************************
 * Set_MSQI наполняем оперативными данными
 *******************************************************/
int		Set_MSQI	(uint16_t QTnum, uint64_t currentTime ){

	int			ret = false;
	uint32_t	Mod;
	uint32_t	Health1,Health2,Health3,Health4;
	float		mag;
	float		K;
	float		diapazon;
	Quality 	quality;
	bool		Em4=0,Ek1=0,Ek2=0,Ek3=0,Em5=0,Eust=0;

// Health
	Eust=0; if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)>0) 		{Eust=1;}
	Em4=0; if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4)>0) 			{Em4=1;}
	Em5=0; if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5)>0) 			{Em5=1;}

// MSQI1 ---------------------------------------------------
	Ek1=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH1] & MB_bOffset_SideTT) == 1)	{Ek1=1;}
	Ek2=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH2] & MB_bOffset_SideTT) == 1)	{Ek2=1;}
	Ek3=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH3] & MB_bOffset_SideTT) == 1)	{Ek3=1;}
	Health1 = STVALINT32_OK;
	if (Eust) 					{Health1 = STVALINT32_Warning;}
	if (Em4 && (Ek1 || Ek2))	{Health1 = STVALINT32_Warning;}
	if (Em5 && Ek3)				{Health1 = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI1_Health_stVal, Health1))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MSQI1_Health_t, currentTime);
// MSQI2 ---------------------------------------------------
	Ek1=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH1] & MB_bOffset_SideTT) == 2)	{Ek1=1;}
	Ek2=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH2] & MB_bOffset_SideTT) == 2)	{Ek2=1;}
	Ek3=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH3] & MB_bOffset_SideTT) == 2)	{Ek3=1;}
	Health2 = STVALINT32_OK;
	if (Eust) 					{Health2 = STVALINT32_Warning;}
	if (Em4 && (Ek1 || Ek2))	{Health2 = STVALINT32_Warning;}
	if (Em5 && Ek3)				{Health2 = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI2_Health_stVal, Health2))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MSQI2_Health_t, currentTime);
// MSQI3 ---------------------------------------------------
	Ek1=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH1] & MB_bOffset_SideTT) == 3)	{Ek1=1;}
	Ek2=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH2] & MB_bOffset_SideTT) == 3)	{Ek2=1;}
	Ek3=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH3] & MB_bOffset_SideTT) == 3)	{Ek3=1;}
	Health3 = STVALINT32_OK;
	if (Eust) 					{Health3 = STVALINT32_Warning;}
	if (Em4 && (Ek1 || Ek2))	{Health3 = STVALINT32_Warning;}
	if (Em5 && Ek3)				{Health3 = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI3_Health_stVal, Health3))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MSQI3_Health_t, currentTime);
// MSQI4 ---------------------------------------------------
	Health4 = STVALINT32_OK;
	if (Eust) 					{Health4 = STVALINT32_Warning;}
	if (Em5)					{Health4 = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI4_Health_stVal, Health4))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MSQI4_Health_t, currentTime);
/*
		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_SeqT, _SeqT);
		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI2_SeqA_SeqT, _SeqT);
		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI3_SeqA_SeqT, _SeqT);
		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI4_SeqU_SeqT, _SeqT);
*/
/*************************************************************************
 * quality
 *************************************************************************/
		quality = QUALITY_VALIDITY_GOOD;
		if (Health1 == STVALINT32_Warning) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if( IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_I0_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_I2_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_I0_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_I2_t, currentTime);
		}
		quality = QUALITY_VALIDITY_GOOD;
		if (Health2 == STVALINT32_Warning) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if(	IedServer_updateQuality(iedServer,&iedModel_MES_MSQI2_SeqA_I0_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI2_SeqA_I2_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI2_SeqA_I0_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI2_SeqA_I2_t, currentTime);
		}
		quality = QUALITY_VALIDITY_GOOD;
		if (Health3 == STVALINT32_Warning) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (IedServer_updateQuality(iedServer,&iedModel_MES_MSQI3_SeqA_I0_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI3_SeqA_I2_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI3_SeqA_I0_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI3_SeqA_I2_t, currentTime);
		}
		quality = QUALITY_VALIDITY_GOOD;
		if (Health4 == STVALINT32_Warning) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (IedServer_updateQuality(iedServer,&iedModel_MES_MSQI4_SeqU_U0_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI4_SeqU_U2_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI4_SeqU_U0_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI4_SeqU_U2_t, currentTime);
		}

/*************************************************************************
 * 4 аналоговый модуль модуль
 *************************************************************************/
			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_U_Obmotki]);
			diapazon = K * 65535;
// Ток на стороне 1
			mag = ucMAnalogInBuf[MB_offset_Is1o] * K;
			ret |= Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MSQI1_SeqA_I0_db,
					&iedModel_MES_MSQI1_SeqA_I0_zeroDb,
					&iedModel_MES_MSQI1_SeqA_I0_instCVal_mag_f,
					&iedModel_MES_MSQI1_SeqA_I0_cVal_mag_f,
					&iedModel_MES_MSQI1_SeqA_I0_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is12] * K;
			ret |= Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MSQI1_SeqA_I2_db,
					&iedModel_MES_MSQI1_SeqA_I2_zeroDb,
					&iedModel_MES_MSQI1_SeqA_I2_instCVal_mag_f,
					&iedModel_MES_MSQI1_SeqA_I2_cVal_mag_f,
					&iedModel_MES_MSQI1_SeqA_I2_t,
					currentTime);
// Ток на стороне 2
			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS2 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS2 + MB_offset_U_Obmotki]);
			diapazon = K * 65535;

			mag = ucMAnalogInBuf[MB_offset_Is2o] * K;
			ret |= Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MSQI2_SeqA_I0_db,
					&iedModel_MES_MSQI2_SeqA_I0_zeroDb,
					&iedModel_MES_MSQI2_SeqA_I0_instCVal_mag_f,
					&iedModel_MES_MSQI2_SeqA_I0_cVal_mag_f,
					&iedModel_MES_MSQI2_SeqA_I0_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is22] * K;
			ret |= Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MSQI2_SeqA_I2_db,
					&iedModel_MES_MSQI2_SeqA_I2_zeroDb,
					&iedModel_MES_MSQI2_SeqA_I2_instCVal_mag_f,
					&iedModel_MES_MSQI2_SeqA_I2_cVal_mag_f,
					&iedModel_MES_MSQI2_SeqA_I2_t,
					currentTime);

/*************************************************************************
 * 5 аналоговый модуль модуль
 *************************************************************************/
			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS3 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS3 + MB_offset_U_Obmotki]);
			diapazon = K * 65535;
// Ток на стороне 1
			mag = ucMAnalogInBuf[MB_offset_Is3o] * K;
			ret |= Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MSQI3_SeqA_I0_db,
					&iedModel_MES_MSQI3_SeqA_I0_zeroDb,
					&iedModel_MES_MSQI3_SeqA_I0_instCVal_mag_f,
					&iedModel_MES_MSQI3_SeqA_I0_cVal_mag_f,
					&iedModel_MES_MSQI3_SeqA_I0_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is32] * K;
			ret |= Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MSQI3_SeqA_I2_db,
					&iedModel_MES_MSQI3_SeqA_I2_zeroDb,
					&iedModel_MES_MSQI3_SeqA_I2_instCVal_mag_f,
					&iedModel_MES_MSQI3_SeqA_I2_cVal_mag_f,
					&iedModel_MES_MSQI3_SeqA_I2_t,
					currentTime);

			diapazon = (float)range_maxU * GetRealU(256,ucConfigTRMeasBuf[MB_offset_KTHL]);

			mag = GetRealU(ucMAnalogInBuf[MB_offset_U0],ucConfigTRMeasBuf[MB_offset_KTHL]);
			ret |= Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MSQI4_SeqU_U0_db,
					&iedModel_MES_MSQI4_SeqU_U0_zeroDb,
					&iedModel_MES_MSQI4_SeqU_U0_instCVal_mag_f,
					&iedModel_MES_MSQI4_SeqU_U0_cVal_mag_f,
					&iedModel_MES_MSQI4_SeqU_U0_t,
					currentTime);

			mag = GetRealU(ucMAnalogInBuf[MB_offset_U2],ucConfigTRMeasBuf[MB_offset_KTHL]);
			ret |= Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MSQI4_SeqU_U2_db,
					&iedModel_MES_MSQI4_SeqU_U2_zeroDb,
					&iedModel_MES_MSQI4_SeqU_U2_instCVal_mag_f,
					&iedModel_MES_MSQI4_SeqU_U2_cVal_mag_f,
					&iedModel_MES_MSQI4_SeqU_U2_t,
					currentTime);

return ret;
}

#endif
/*******************************************************
 * MR771 MR761 MR762 MR763
 *
 * узел проверен.(Ломан)
 * MR761	-	12.01.2018
 * MSQI (проверка без db) - ок
 * переключение уставок - ок
 *
 *******************************************************/
#if defined	(MR771) || defined	(MR761) || defined	(MR762) || defined	(MR763)

#if defined	(MR771)
#include "static_model_MR771.h"
#endif

#if defined	(MR761) || defined	(MR762) || defined	(MR763)
#include "static_model_MR76x.h"
#endif

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];


//	MSQI1  MB_bOffsetModule4
//	MSQI2  MB_bOffsetModule4
//	MSQI3  MB_bOffsetModule5
//	MSQI4  MB_bOffsetModule5

/*******************************************************
 * Set_MSQI наполняем оперативными данными
 *******************************************************/
int		Set_MSQI	(uint16_t QTnum, uint64_t currentTime ){

	int	ret = false;
	float	mag,premag,level,dbLevel=0,zeroDbLevel=0;
	float	K;
	uint32_t	Health = STVALINT32_OK;
	Quality quality = QUALITY_VALIDITY_GOOD;


	// Health

		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MSQI1_Health_t, currentTime);

		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_SeqT, _SeqT);

// ------------------------------------------------------
		if (Health == STVALINT32_Warning){
			quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		}

		IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_I1_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_I2_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_3I0_q,quality);

		IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_U1_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_U2_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_U3U0_q,quality);

/*************************************************************************
 * 5 аналоговый модуль модуль
 *************************************************************************/
		if (Health == STVALINT32_OK){
// Ток на стороне 1
			K = (float)range_maxIphs * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf]/(float)65535;

//I1
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I1_db)*(float)range_maxIphs * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf] /(float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I1_zeroDb)*(float)range_maxIphs * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf]  / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_I1] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I1_instCVal_mag_f,mag)){
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_I1_t, currentTime);
				ret = true;
			}
			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I1_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I1_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I1_cVal_mag_f,0);
			}
//I2
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I2_db)*(float)range_maxIphs * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf] /(float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I2_zeroDb)*(float)range_maxIphs * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf]  / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_I2] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I2_instCVal_mag_f,mag)){
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_I2_t, currentTime);
				ret = true;
			}
			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I2_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I2_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I2_cVal_mag_f,0);
			}
//3I0
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_3I0_db)*(float)range_maxIphs * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf] /(float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_3I0_zeroDb)*(float)range_maxIphs * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf]  / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_I3I0] * K / 3;		// делим на 3 чтобы привести к стандарту узел
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_3I0_instCVal_mag_f,mag)){
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_3I0_t, currentTime);
				ret = true;
			}
			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_3I0_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_3I0_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_3I0_cVal_mag_f,0);
			}

		}

// напряжения --------------------------
//MSQI1_SeqU
		if (Health == STVALINT32_OK){
// напряжения
// U1 --------------
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U1_db)*(float)range_maxU * GetRealU(range_maxU,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U1_zeroDb)*(float)range_maxU * GetRealU(range_maxU,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])  / (float)DbPercent;

			mag = GetRealU(ucMAnalogInBuf[MB_offset_U1],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U1_instCVal_mag_f,mag)){	//instCVal мгновенное значение
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_U1_t, currentTime);
				ret = true;
			}
			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U1_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U1_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U1_cVal_mag_f,0);
			}

// U2 --------------
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U2_db)*(float)range_maxU * GetRealU(range_maxU,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U2_zeroDb)*(float)range_maxU * GetRealU(range_maxU,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])  / (float)DbPercent;

			mag = GetRealU(ucMAnalogInBuf[MB_offset_U2],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U2_instCVal_mag_f,mag)){	//instCVal мгновенное значение
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_U2_t, currentTime);
				ret = true;
			}
			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U2_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U2_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U2_cVal_mag_f,0);
			}
// 3U0 --------------
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U3U0_db)*(float)range_maxU * GetRealU(range_maxU,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U3U0_zeroDb)*(float)range_maxU * GetRealU(range_maxU,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])  / (float)DbPercent;

			mag = GetRealU(ucMAnalogInBuf[MB_offset_U3U0],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf]);
			mag = mag / 3;		// делим на 3 чтобы привести к стандарту узел
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U3U0_instCVal_mag_f,mag)){	//instCVal мгновенное значение
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_U3U0_t, currentTime);
				ret = true;
			}
			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U3U0_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U3U0_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U3U0_cVal_mag_f,0);
			}

		}
	return	ret;
}
#endif

/*******************************************************
 * MR5_700
 *******************************************************/
#if defined	(MR5_700) || defined (MR5_600) || defined (MR5_500) ||  defined (MR741)

#if defined	(MR5_700)
#include "static_model_MR5_700.h"
#endif

#if defined	(MR5_500)
#include "static_model_MR5_500.h"
#endif

#if defined	(MR5_600)
#include "static_model_MR5_600.h"
#endif

#if defined	(MR741)
#include "static_model_MR741.h"
#endif

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];


//	MSQI1  MB_bOffsetModule4
//	MSQI2  MB_bOffsetModule4
//	MSQI3  MB_bOffsetModule5
//	MSQI4  MB_bOffsetModule5

/*******************************************************
 * Set_MSQI наполняем оперативными данными
 *******************************************************/
int		Set_MSQI	(uint16_t QTnum, uint64_t currentTime ){

	int 	ret = false;
	float	mag,premag,level,dbLevel=0,zeroDbLevel=0;
	float	K;
	float	diapazon;
	Quality quality = QUALITY_VALIDITY_GOOD;
	uint32_t	Health = STVALINT32_OK;

	// Health

		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1) 		{Health = STVALINT32_Warning;}
		if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{Health = STVALINT32_Warning;}
		IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_MES_MSQI1_Health_stVal,&iedModel_MES_MSQI1_Health_t,currentTime,Health);
/*
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI1_Health_stVal, Health)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MSQI1_Health_t, currentTime);
		}
*/
/*************************************************************************
 * аналоговый токовый модуль
 *************************************************************************/
#if defined	(MR5_700) || defined (MR5_500) ||  defined (MR741)

		quality = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1b)		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MSQI1_SeqA_c1_q,&iedModel_MES_MSQI1_SeqA_c1_t,currentTime,quality)){
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MSQI1_SeqA_c2_q,&iedModel_MES_MSQI1_SeqA_c2_t,currentTime,quality);
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MSQI1_SeqA_c3_q,&iedModel_MES_MSQI1_SeqA_c3_t,currentTime,quality);
		}
/*
		if (IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c1_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c2_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c3_q,quality);
		}
*/
		K = (float)range_maxIphs * (float)ucMUstavkiInBuf[MB_offset_Itt]/(float)65535;
		diapazon = (float)range_maxIphs * (float)ucMUstavkiInBuf[MB_offset_Itt];

//NI1 -------------
		mag = (float)ucMAnalogInBuf[MB_offset_NI1] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MSQI1_SeqA_c1_db,
				&iedModel_MES_MSQI1_SeqA_c1_zeroDb,
				&iedModel_MES_MSQI1_SeqA_c1_instCVal_mag_f,
				&iedModel_MES_MSQI1_SeqA_c1_cVal_mag_f,
				&iedModel_MES_MSQI1_SeqA_c1_t,
				currentTime);
//NI1 -------------
		mag = (float)ucMAnalogInBuf[MB_offset_NI2] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MSQI1_SeqA_c2_db,
				&iedModel_MES_MSQI1_SeqA_c2_zeroDb,
				&iedModel_MES_MSQI1_SeqA_c2_instCVal_mag_f,
				&iedModel_MES_MSQI1_SeqA_c2_cVal_mag_f,
				&iedModel_MES_MSQI1_SeqA_c2_t,
				currentTime);
//NI0 -------------
		mag = (float)ucMAnalogInBuf[MB_offset_NI0] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MSQI1_SeqA_c3_db,
				&iedModel_MES_MSQI1_SeqA_c3_zeroDb,
				&iedModel_MES_MSQI1_SeqA_c3_instCVal_mag_f,
				&iedModel_MES_MSQI1_SeqA_c3_cVal_mag_f,
				&iedModel_MES_MSQI1_SeqA_c3_t,
				currentTime);

		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_SeqT, _SeqT);

#endif

/*************************************************************************
 * аналоговый модуль напряжений
 *************************************************************************/
#if defined	(MR5_700) || defined (MR5_600) || defined (MR741)

		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a)		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE; }
		if (ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MSQI1_SeqU_c1_q,&iedModel_MES_MSQI1_SeqU_c1_t,currentTime,quality)){
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MSQI1_SeqU_c2_q,&iedModel_MES_MSQI1_SeqU_c2_t,currentTime,quality);
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MSQI1_SeqU_c3_q,&iedModel_MES_MSQI1_SeqU_c3_t,currentTime,quality);
		}
/*
 		if (IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c1_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c2_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c3_q,quality);
		}
*/
		diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_offset_Ktn]);
// NU1
		mag = GetRealU(ucMAnalogInBuf[MB_offset_NU1],ucMUstavkiInBuf[MB_offset_Ktn]);
		ret |= Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MSQI1_SeqU_c1_db,
				&iedModel_MES_MSQI1_SeqU_c1_zeroDb,
				&iedModel_MES_MSQI1_SeqU_c1_instCVal_mag_f,
				&iedModel_MES_MSQI1_SeqU_c1_cVal_mag_f,
				&iedModel_MES_MSQI1_SeqU_c1_t,
				currentTime);
// NU2
		mag = GetRealU(ucMAnalogInBuf[MB_offset_NU2],ucMUstavkiInBuf[MB_offset_Ktn]);
		ret |= Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MSQI1_SeqU_c2_db,
				&iedModel_MES_MSQI1_SeqU_c2_zeroDb,
				&iedModel_MES_MSQI1_SeqU_c2_instCVal_mag_f,
				&iedModel_MES_MSQI1_SeqU_c2_cVal_mag_f,
				&iedModel_MES_MSQI1_SeqU_c2_t,
				currentTime);
// NU0
		mag = GetRealU(ucMAnalogInBuf[MB_offset_NU0],ucMUstavkiInBuf[MB_offset_Ktn]);
		ret |= Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MSQI1_SeqU_c3_db,
				&iedModel_MES_MSQI1_SeqU_c3_zeroDb,
				&iedModel_MES_MSQI1_SeqU_c3_instCVal_mag_f,
				&iedModel_MES_MSQI1_SeqU_c3_cVal_mag_f,
				&iedModel_MES_MSQI1_SeqU_c3_t,
				currentTime);

		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_SeqT, _SeqT);

#endif

return ret;
}
#endif

