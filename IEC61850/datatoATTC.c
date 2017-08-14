/*
 * datatoATTC.c
 *
 *  Created on: 19.06.2017
 *      Author: sagok
 */


#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "datatoATTC.h"
#include "datatoMMXU.h"

/*******************************************************
 * MR851
 *******************************************************/
#if defined	(MR851)
#include "static_model_MR851.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucRPNBuf[MB_NumbRPN];

/*******************************************************
 * Set_PDPR наполн€ем оперативными данными
 *******************************************************/
void	Set_ATCC	(uint8_t num, uint64_t currentTime )
{
	float	mag;
	float	K;

	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_RPN_ATCC1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_RPN_ATCC1_Health_t, currentTime);


	//  Mod Beh
				uint32_t	Mod = STVALINT32_ON;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_RPN_ATCC1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_RPN_ATCC1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_RPN_ATCC1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_RPN_ATCC1_Beh_t, currentTime);


	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_Health_q,Qual);


	// Loc
				bool	Loc;
				if ((ucMDiscInBuf[MB_offsetLocalCtrl] & MB_bOffsetLocal)&& !(ucMDiscInBuf[MB_offsetExtCtrl] & MB_bOffsetExt)) Loc = true; else Loc = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_RPN_ATCC1_Loc_stVal,  Loc) > 0)			// »0 P>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_Loc_t, currentTime);

	// TapChg
				int8_t	posVal;
				Qual = QUALITY_VALIDITY_GOOD;

				posVal = ucRPNBuf[MB_offset_CurrPosRPN];
				if (posVal > 40) Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OUT_OF_RANGE;
				if (ucMDiscInBuf[MB_offsetError_DriveRPN] & MB_bOffsetAllErrDriveRPN) {Qual |= QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_TapChg_q,Qual);

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_RPN_ATCC1_TapChg_valWTr_posVal,posVal))
				  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_TapChg_t, currentTime);

	// ParOp
				uint8_t	stVal = STVALCODEDENUM_BADSTATE;
				if(ucMDiscInBuf[MB_offsetExtCtrl] & MB_bOffsetExt) stVal = STVALCODEDENUM_OFF; else stVal = STVALCODEDENUM_ON;
				if (IedServer_updateBitStringAttributeValue(iedServer, &iedModel_RPN_ATCC1_ParOp_stVal, stVal))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_RPN_ATCC1_ParOp_t, currentTime);
	//  Quality (ParOp)
				Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3b) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_ParOp_q,Qual);

	//  Quality (CtlV1..8)
				Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV1_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV2_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV3_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV4_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV5_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV6_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV7_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV8_q,Qual);


	// CtlV1
				mag = GetRealU(ucMAnalogInBuf[MB_offset_Uab1],ucMUstavkiInBuf[MB_offset_Ktn1]);

				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_RPN_ATCC1_CtlV1_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV1_t, currentTime);

	// CtlV2
				mag = GetRealU(ucMAnalogInBuf[MB_offset_Ubc1Un1],ucMUstavkiInBuf[MB_offset_Ktnnp1]);

				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_RPN_ATCC1_CtlV2_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV2_t, currentTime);

	// CtlV3

				mag = GetRealU(ucMAnalogInBuf[MB_offset_U21],ucMUstavkiInBuf[MB_offset_Ktn1]);

				if (ucMUstavkiInBuf[MB_offset_Config_Ktn1] & MB_bOffsetConfig){
				} else{
					if (Qual == QUALITY_VALIDITY_GOOD){
						mag = 0;
						IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV3_q,QUALITY_VALIDITY_QUESTIONABLE | QUALITY_DETAIL_INCONSISTENT);
					}
				}
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_RPN_ATCC1_CtlV3_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV3_t, currentTime);
	// CtlV4
				mag = GetRealU(ucMAnalogInBuf[MB_offset_Upp1],ucMUstavkiInBuf[MB_offset_Ktn1]);

				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_RPN_ATCC1_CtlV4_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV4_t, currentTime);

	// CtlV5
				mag = GetRealU(ucMAnalogInBuf[MB_offset_Uab2],ucMUstavkiInBuf[MB_offset_Ktn2]);

				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_RPN_ATCC1_CtlV5_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV5_t, currentTime);

	// CtlV6
				mag = GetRealU(ucMAnalogInBuf[MB_offset_Ubc2Un2],ucMUstavkiInBuf[MB_offset_Ktnnp2]);

				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_RPN_ATCC1_CtlV6_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV6_t, currentTime);

	// CtlV7
				mag = GetRealU(ucMAnalogInBuf[MB_offset_U22],ucMUstavkiInBuf[MB_offset_Ktn2]);

				if (ucMUstavkiInBuf[MB_offset_Config_Ktn2] & MB_bOffsetConfig){
				} else{
					if (Qual == QUALITY_VALIDITY_GOOD){
						mag = 0;
						IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV7_q,QUALITY_VALIDITY_QUESTIONABLE | QUALITY_DETAIL_INCONSISTENT);
					}
				}
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_RPN_ATCC1_CtlV7_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV7_t, currentTime);
	// CtlV8
				mag = GetRealU(ucMAnalogInBuf[MB_offset_Upp2],ucMUstavkiInBuf[MB_offset_Ktn2]);

				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_RPN_ATCC1_CtlV8_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV8_t, currentTime);

	//  Quality (LodA1..8)
				Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1b) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_LodA1_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_LodA2_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_LodA3_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_LodA4_q,Qual);

	// LodA1
				K = (float)5*(float)ucMUstavkiInBuf[MB_offset_Ittvv1]/(float)65536;
				mag = (float)ucMAnalogInBuf[MB_offset_Ivv1] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_RPN_ATCC1_LodA1_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_LodA1_t, currentTime);
	// LodA2
				K = (float)5*(float)ucMUstavkiInBuf[MB_offset_Ittsv1]/(float)65536;
				mag = (float)ucMAnalogInBuf[MB_offset_Isv1] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_RPN_ATCC1_LodA2_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_LodA2_t, currentTime);
	// LodA3
				K = (float)5*(float)ucMUstavkiInBuf[MB_offset_Ittvv2]/(float)65536;
				mag = (float)ucMAnalogInBuf[MB_offset_Ivv2] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_RPN_ATCC1_LodA3_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_LodA3_t, currentTime);
	// LodA4
				K = (float)5*(float)ucMUstavkiInBuf[MB_offset_Ittsv2]/(float)65536;
				mag = (float)ucMAnalogInBuf[MB_offset_Isv2] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_RPN_ATCC1_LodA4_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_LodA4_t, currentTime);


	// описание узлов
				if (ucMUstavkiInBuf[MB_offset_Config_Ktn1] & MB_bOffsetConfig){
					IedServer_updateMMSStringAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV2_dU,"Ubc. Section 1");
				} else{
					IedServer_updateMMSStringAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV2_dU,"Un. Section 1");
				}

				if (ucMUstavkiInBuf[MB_offset_Config_Ktn2] & MB_bOffsetConfig){
					IedServer_updateMMSStringAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV6_dU,"Ubc. Section 2");
				} else{
					IedServer_updateMMSStringAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV6_dU,"Un. Section 2");
				}


}

#endif

