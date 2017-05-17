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
