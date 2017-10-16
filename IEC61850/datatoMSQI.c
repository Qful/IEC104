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

#define _SeqT	0

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
void	Set_MSQI	(uint8_t num, uint64_t currentTime ){

	uint32_t	Mod;
	uint32_t	Health = STVALINT32_OK;

	// Health

		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MSQI1_Health_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI2_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MSQI2_Health_t, currentTime);

		Health = STVALINT32_OK;

		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI3_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MSQI3_Health_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI4_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MSQI4_Health_t, currentTime);


		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_SeqT, _SeqT);
		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI2_SeqA_SeqT, _SeqT);
		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI3_SeqA_SeqT, _SeqT);
		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI4_SeqU_SeqT, _SeqT);

/*************************************************************************
 * 4 аналоговый модуль модуль
 *************************************************************************/
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_errorM4){
			// токи
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_I0_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_I2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI2_SeqA_I0_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI2_SeqA_I2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		}
		else{
			float	mag;
			float	K;

// Ток на стороне 1
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_I0_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_I2_q,0);
//  Ток на стороне 2
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI2_SeqA_I0_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI2_SeqA_I2_q,0);

// Ток на стороне 1
			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_U_Obmotki]);
			mag = ucMAnalogInBuf[MB_offset_Is1o] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I0_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_I0_t, currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is12] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I2_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_I2_t, currentTime);

// Ток на стороне 2
			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS2 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS2 + MB_offset_U_Obmotki]);
			mag = ucMAnalogInBuf[MB_offset_Is2o] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI2_SeqA_I0_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI2_SeqA_I0_t, currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is22] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI2_SeqA_I2_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI2_SeqA_I2_t, currentTime);

		}

/*************************************************************************
 * 5 аналоговый модуль модуль
 *************************************************************************/
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_errorM5){
			// токи
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI3_SeqA_I0_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI3_SeqA_I2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		}
		else{
			float	mag;
			float	K;

// Ток на стороне 3
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI3_SeqA_I0_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI3_SeqA_I2_q,0);

// Ток на стороне 3
			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS3 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS3 + MB_offset_U_Obmotki]);
			mag = ucMAnalogInBuf[MB_offset_Is3o] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI3_SeqA_I0_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI3_SeqA_I0_t, currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is32] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI3_SeqA_I2_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI3_SeqA_I2_t, currentTime);

		}


// напряжения --------------------------
//MSQI4_SeqU
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_errorM5){
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI4_SeqU_U0_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI4_SeqU_U2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}
		else{
// напряжения
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI4_SeqU_U0_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI4_SeqU_U2_q,0);

			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI4_SeqU_U0_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_U0],ucConfigTRMeasBuf[MB_offset_KTHL])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI4_SeqU_U0_t, currentTime);

			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI4_SeqU_U2_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_U2],ucConfigTRMeasBuf[MB_offset_KTHL])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI4_SeqU_U2_t, currentTime);
		}


}

#endif
/*******************************************************
 * MR771 MR761 MR762 MR763
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
void	Set_MSQI	(uint8_t num, uint64_t currentTime ){


	uint32_t	Health = STVALINT32_OK;

	// Health

		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MSQI1_Health_t, currentTime);

		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_SeqT, _SeqT);


/*************************************************************************
 * 5 аналоговый модуль модуль
 *************************************************************************/
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5){
			// токи
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_I1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_I2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_3I0_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		}
		else{
			float	mag;
			float	K;

// Ток на стороне 1
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_I1_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_I2_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_3I0_q,0);

// Ток на стороне 1
			K = (40 * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf]) /  65535;
			mag = (float)ucMAnalogInBuf[MB_offset_I1] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I1_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_I1_t, currentTime);

			mag = (float)ucMAnalogInBuf[MB_offset_I2] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_I2_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_I2_t, currentTime);

			mag = (float)ucMAnalogInBuf[MB_offset_I3I0] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_3I0_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_3I0_t, currentTime);

		}

// напряжения --------------------------
//MSQI1_SeqU
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5){
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_U1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_U2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_U3U0_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}
		else{
// напряжения
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_U1_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_U2_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_U3U0_q,0);

			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U1_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_U1],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_U1_t, currentTime);

			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U2_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_U2],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_U2_t, currentTime);

			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_U3U0_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_U3U0],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_U3U0_t, currentTime);

		}

}

#endif

/*******************************************************
 * MR5_700
 *******************************************************/
#if defined	(MR5_700) || defined	(MR5_500)

#if defined	(MR5_700)
#include "static_model_MR5_700.h"
#endif

#if defined	(MR5_500)
#include "static_model_MR5_500.h"
#endif

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];


//	MSQI1  MB_bOffsetModule4
//	MSQI2  MB_bOffsetModule4
//	MSQI3  MB_bOffsetModule5
//	MSQI4  MB_bOffsetModule5

/*******************************************************
 * Set_MSQI наполняем оперативными данными
 *******************************************************/
void	Set_MSQI	(uint8_t num, uint64_t currentTime ){

	float	mag,premag,level,dbLevel=0,zeroDbLevel=0;
	float	K;
	uint32_t	Health = STVALINT32_OK;

	// Health

		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MSQI1_Health_t, currentTime);

		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_SeqT, _SeqT);


/*************************************************************************
 * аналоговый токовый модуль
 *************************************************************************/
		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1b){
			// токи
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}
		else{
// Ток
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c1_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c2_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqA_c3_q,0);


			K = (float)range_maxIphs * (float)ucUstavkiInBuf[MB_offset_Itt]/(float)65535;

			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c1_db)*(float)range_maxIphs * (float)ucUstavkiInBuf[MB_offset_Itt] /(float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c1_zeroDb)*(float)range_maxIphs * (float)ucUstavkiInBuf[MB_offset_Itt]  / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_NI1] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c1_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c1_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c1_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c1_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c1_cVal_mag_f,0);
			}

			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c2_db)*(float)range_maxIphs * (float)ucUstavkiInBuf[MB_offset_Itt] /(float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c2_zeroDb)*(float)range_maxIphs * (float)ucUstavkiInBuf[MB_offset_Itt]  / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_NI2] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c2_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c2_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c2_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c2_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c2_cVal_mag_f,0);
			}


			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c3_db)*(float)range_maxIphs * (float)ucUstavkiInBuf[MB_offset_Itt] /(float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c3_zeroDb)*(float)range_maxIphs * (float)ucUstavkiInBuf[MB_offset_Itt]  / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_NI0] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c3_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqA_c3_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c3_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c3_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqA_c3_cVal_mag_f,0);
			}

		}


#if defined	(MR5_700)
		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_SeqT, _SeqT);
/*************************************************************************
 * аналоговый модуль напряжений
 *************************************************************************/
		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a){
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}
		else{
// напряжения
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c1_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c2_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c3_q,0);

			mag = GetRealU(ucMAnalogInBuf[MB_offset_NU1],ucUstavkiInBuf[MB_offset_Ktn]);
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_c1_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c1_t, currentTime);

			mag = GetRealU(ucMAnalogInBuf[MB_offset_NU2],ucUstavkiInBuf[MB_offset_Ktn]);
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_c2_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c2_t, currentTime);

			mag = GetRealU(ucMAnalogInBuf[MB_offset_NU0],ucUstavkiInBuf[MB_offset_Ktn]);
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_c3_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c3_t, currentTime);
		}
#endif // defined(MR5_700) аналоговый модуль напряжений
}
#endif
/*******************************************************
 * MR5_600
 *******************************************************/
#if defined	(MR5_600)

#include "static_model_MR5_600.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];


//	MSQI1  MB_bOffsetModule4
//	MSQI2  MB_bOffsetModule4
//	MSQI3  MB_bOffsetModule5
//	MSQI4  MB_bOffsetModule5

/*******************************************************
 * Set_MSQI наполняем оперативными данными
 *******************************************************/
void	Set_MSQI	(uint8_t num, uint64_t currentTime ){

	float	mag,premag,level,dbLevel=0,zeroDbLevel=0;
	float	K;
	uint32_t	Health = STVALINT32_OK;

	// Health

		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MSQI1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MSQI1_Health_t, currentTime);

		IedServer_updateInt32AttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_SeqT, _SeqT);

/*************************************************************************
 * аналоговый модуль напряжений
 *************************************************************************/
		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a){
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}
		else{
// напряжения
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c1_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c2_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_SeqU_c3_q,0);

			mag = GetRealU(ucMAnalogInBuf[MB_offset_NU1],ucUstavkiInBuf[MB_offset_Ktn]);
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_c1_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c1_t, currentTime);

			mag = GetRealU(ucMAnalogInBuf[MB_offset_NU2],ucUstavkiInBuf[MB_offset_Ktn]);
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_c2_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c2_t, currentTime);

			mag = GetRealU(ucMAnalogInBuf[MB_offset_NU0],ucUstavkiInBuf[MB_offset_Ktn]);
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MSQI1_SeqU_c3_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_SeqU_c3_t, currentTime);
		}
}
#endif
