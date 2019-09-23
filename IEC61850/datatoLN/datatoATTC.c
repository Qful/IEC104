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
#include "dataDbzeroDB.h"

/*******************************************************
 * MR851
 *******************************************************/
#if defined	(MR851)
#include "static_model_MR851.h"


extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];

#if defined (AN_PERV)
extern float   ucMAnalogInBuf[];
#else
	#if defined (AN_DUBLEDATA)
	extern	uint32_t   ucMAnalogInBuf[MB_Size_Analog/2];
	#else
	extern	uint16_t   ucMAnalogInBuf[MB_Size_Analog];
	#endif
#endif

extern uint16_t   ucMUstavkiInBuf[MB_Size_Ustavki];
extern uint16_t   ucRPNBuf[MB_Size_RPN];

/*******************************************************
 * Set_PDPR наполняем оперативными данными
 *******************************************************/
int	Set_ATCC	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	float		mag;
	float		K;
	float		diapazon;
	Quality 	quality;
	Quality 	quality1;
	uint32_t	Health;
	uint32_t	Mod;

	//Health
				Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1) 		{Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki) 	{Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_RPN_ATCC1_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_RPN_ATCC1_Health_t, currentTime);

	//  Mod Beh
				Mod = STVALINT32_ON;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_RPN_ATCC1_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_RPN_ATCC1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_RPN_ATCC1_Beh_stVal, Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_RPN_ATCC1_Beh_t, currentTime);
				}

	//  Quality (Mod Beh)
				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_Mod_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_Beh_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_RPN_ATCC1_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_RPN_ATCC1_Beh_t, currentTime);
				}


	// Loc
				bool	Loc;
				if ((ucMDiscInBuf[MB_offsetLocalCtrl] & MB_bOffsetLocal)&& !(ucMDiscInBuf[MB_offsetExtCtrl] & MB_bOffsetExt)) Loc = true; else Loc = false;

				ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_RPN_ATCC1_Loc_stVal, &iedModel_RPN_ATCC1_Loc_t, currentTime, Loc);

//				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_RPN_ATCC1_Loc_stVal,  Loc) > 0)			// И0 P>1
//					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_Loc_t, currentTime);

	// TapChg
				int8_t	posVal;
				quality = QUALITY_VALIDITY_GOOD;

				posVal = ucRPNBuf[MB_offset_CurrPosRPN];
				if (posVal > 40) quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OUT_OF_RANGE;
				if (ucMDiscInBuf[MB_offsetError_DriveRPN] & MB_bOffsetAllErrDriveRPN) {quality |= QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					if (IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_TapChg_q,quality)){
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_TapChg_t, currentTime);
					}

				ret |= IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_RPN_ATCC1_TapChg_valWTr_posVal, &iedModel_RPN_ATCC1_TapChg_t, currentTime, posVal);
//				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_RPN_ATCC1_TapChg_valWTr_posVal,posVal))
//				  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_TapChg_t, currentTime);

	// ParOp
				uint8_t	stVal = STVALCODEDENUM_BADSTATE;
				if(ucMDiscInBuf[MB_offsetExtCtrl] & MB_bOffsetExt) stVal = STVALCODEDENUM_OFF; else stVal = STVALCODEDENUM_ON;

				if (IedServer_updateBitStringAttributeValue(iedServer, &iedModel_RPN_ATCC1_ParOp_stVal, stVal))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_RPN_ATCC1_ParOp_t, currentTime);

	//  Quality (ParOp)
				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3b) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_ParOp_q,quality)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_RPN_ATCC1_ParOp_t, currentTime);
				}

	//  Quality (LodA1..8)
				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1b) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_LodA1_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_LodA2_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_LodA3_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_LodA4_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_LodA1_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_LodA2_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_LodA3_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_LodA4_t, currentTime);

				}

	//  Quality (CtlV1..8)
				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV1_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV2_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV3_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV4_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV5_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV6_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV7_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV8_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV1_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV2_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV3_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV4_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV5_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV6_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV7_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV8_t, currentTime);
				}

	// CtlV1
				diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_offset_Ktn1]);
				mag = GetRealU(ucMAnalogInBuf[MB_offset_Uab1],ucMUstavkiInBuf[MB_offset_Ktn1]);

				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_RPN_ATCC1_CtlV1_db,
						&iedModel_RPN_ATCC1_CtlV1_zeroDb,
						&iedModel_RPN_ATCC1_CtlV1_instMag_f,
						&iedModel_RPN_ATCC1_CtlV1_mag_f,
						&iedModel_RPN_ATCC1_CtlV1_t,
						currentTime);
	// CtlV2
				diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_offset_Ktnnp1]);
				mag = GetRealU(ucMAnalogInBuf[MB_offset_Ubc1Un1],ucMUstavkiInBuf[MB_offset_Ktnnp1]);

				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_RPN_ATCC1_CtlV2_db,
						&iedModel_RPN_ATCC1_CtlV2_zeroDb,
						&iedModel_RPN_ATCC1_CtlV2_instMag_f,
						&iedModel_RPN_ATCC1_CtlV2_mag_f,
						&iedModel_RPN_ATCC1_CtlV2_t,
						currentTime);

	// CtlV3
				diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_offset_Ktn1]);

				mag = GetRealU(ucMAnalogInBuf[MB_offset_U21],ucMUstavkiInBuf[MB_offset_Ktn1]);

				quality1 = quality;
				if (((ucMUstavkiInBuf[MB_offset_Config_Ktn1] & MB_bOffsetConfig) == 0) && (quality == QUALITY_VALIDITY_GOOD)){
					mag = 0;
					quality1 = QUALITY_VALIDITY_QUESTIONABLE | QUALITY_DETAIL_INCONSISTENT;
				}
				if (IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV3_q,quality1)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV3_t, currentTime);
				}

				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_RPN_ATCC1_CtlV3_db,
						&iedModel_RPN_ATCC1_CtlV3_zeroDb,
						&iedModel_RPN_ATCC1_CtlV3_instMag_f,
						&iedModel_RPN_ATCC1_CtlV3_mag_f,
						&iedModel_RPN_ATCC1_CtlV3_t,
						currentTime);


	// CtlV4
				diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_offset_Ktn1]);
				mag = GetRealU(ucMAnalogInBuf[MB_offset_Upp1],ucMUstavkiInBuf[MB_offset_Ktn1]);
				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_RPN_ATCC1_CtlV4_db,
						&iedModel_RPN_ATCC1_CtlV4_zeroDb,
						&iedModel_RPN_ATCC1_CtlV4_instMag_f,
						&iedModel_RPN_ATCC1_CtlV4_mag_f,
						&iedModel_RPN_ATCC1_CtlV4_t,
						currentTime);
	// CtlV5
				diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_offset_Ktn2]);
				mag = GetRealU(ucMAnalogInBuf[MB_offset_Uab2],ucMUstavkiInBuf[MB_offset_Ktn2]);
				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_RPN_ATCC1_CtlV5_db,
						&iedModel_RPN_ATCC1_CtlV5_zeroDb,
						&iedModel_RPN_ATCC1_CtlV5_instMag_f,
						&iedModel_RPN_ATCC1_CtlV5_mag_f,
						&iedModel_RPN_ATCC1_CtlV5_t,
						currentTime);
	// CtlV6
				diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_offset_Ktnnp2]);
				mag = GetRealU(ucMAnalogInBuf[MB_offset_Ubc2Un2],ucMUstavkiInBuf[MB_offset_Ktnnp2]);
				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_RPN_ATCC1_CtlV6_db,
						&iedModel_RPN_ATCC1_CtlV6_zeroDb,
						&iedModel_RPN_ATCC1_CtlV6_instMag_f,
						&iedModel_RPN_ATCC1_CtlV6_mag_f,
						&iedModel_RPN_ATCC1_CtlV6_t,
						currentTime);
	// CtlV7
				diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_offset_Ktn2]);
				mag = GetRealU(ucMAnalogInBuf[MB_offset_U22],ucMUstavkiInBuf[MB_offset_Ktn2]);

				quality1 = quality;
				if (((ucMUstavkiInBuf[MB_offset_Config_Ktn2] & MB_bOffsetConfig) == 0) && (quality == QUALITY_VALIDITY_GOOD)){
					mag = 0;
					quality1 = QUALITY_VALIDITY_QUESTIONABLE | QUALITY_DETAIL_INCONSISTENT;
				}
				if (IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV7_q,quality1)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV7_t, currentTime);
				}

				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_RPN_ATCC1_CtlV7_db,
						&iedModel_RPN_ATCC1_CtlV7_zeroDb,
						&iedModel_RPN_ATCC1_CtlV7_instMag_f,
						&iedModel_RPN_ATCC1_CtlV7_mag_f,
						&iedModel_RPN_ATCC1_CtlV7_t,
						currentTime);

	// CtlV8
				diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_offset_Ktn2]);
				mag = GetRealU(ucMAnalogInBuf[MB_offset_Upp2],ucMUstavkiInBuf[MB_offset_Ktn2]);
				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_RPN_ATCC1_CtlV8_db,
						&iedModel_RPN_ATCC1_CtlV8_zeroDb,
						&iedModel_RPN_ATCC1_CtlV8_instMag_f,
						&iedModel_RPN_ATCC1_CtlV8_mag_f,
						&iedModel_RPN_ATCC1_CtlV8_t,
						currentTime);

	// LodA1
				diapazon = (float)range_maxILod * (float)ucMUstavkiInBuf[MB_offset_Ittvv1];
				K = (float)5*(float)ucMUstavkiInBuf[MB_offset_Ittvv1]/(float)65536;
				mag = (float)ucMAnalogInBuf[MB_offset_Ivv1] * K;
				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_RPN_ATCC1_LodA1_db,
						&iedModel_RPN_ATCC1_LodA1_zeroDb,
						&iedModel_RPN_ATCC1_LodA1_instMag_f,
						&iedModel_RPN_ATCC1_LodA1_mag_f,
						&iedModel_RPN_ATCC1_LodA1_t,
						currentTime);
	// LodA2
				diapazon = (float)range_maxILod * (float)ucMUstavkiInBuf[MB_offset_Ittsv1];
				K = (float)5*(float)ucMUstavkiInBuf[MB_offset_Ittsv1]/(float)65536;
				mag = (float)ucMAnalogInBuf[MB_offset_Isv1] * K;
				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_RPN_ATCC1_LodA2_db,
						&iedModel_RPN_ATCC1_LodA2_zeroDb,
						&iedModel_RPN_ATCC1_LodA2_instMag_f,
						&iedModel_RPN_ATCC1_LodA2_mag_f,
						&iedModel_RPN_ATCC1_LodA2_t,
						currentTime);
	// LodA3
				diapazon = (float)range_maxILod * (float)ucMUstavkiInBuf[MB_offset_Ittvv2];
				K = (float)5*(float)ucMUstavkiInBuf[MB_offset_Ittvv2]/(float)65536;
				mag = (float)ucMAnalogInBuf[MB_offset_Ivv2] * K;
				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_RPN_ATCC1_LodA3_db,
						&iedModel_RPN_ATCC1_LodA3_zeroDb,
						&iedModel_RPN_ATCC1_LodA3_instMag_f,
						&iedModel_RPN_ATCC1_LodA3_mag_f,
						&iedModel_RPN_ATCC1_LodA3_t,
						currentTime);
	// LodA4
				diapazon = (float)range_maxILod * (float)ucMUstavkiInBuf[MB_offset_Ittsv2];
				K = (float)5*(float)ucMUstavkiInBuf[MB_offset_Ittsv2]/(float)65536;
				mag = (float)ucMAnalogInBuf[MB_offset_Isv2] * K;
				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_RPN_ATCC1_LodA4_db,
						&iedModel_RPN_ATCC1_LodA4_zeroDb,
						&iedModel_RPN_ATCC1_LodA4_instMag_f,
						&iedModel_RPN_ATCC1_LodA4_mag_f,
						&iedModel_RPN_ATCC1_LodA4_t,
						currentTime);


/*
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
					if (quality == QUALITY_VALIDITY_GOOD){
						mag = 0;
						if (IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV3_q,QUALITY_VALIDITY_QUESTIONABLE | QUALITY_DETAIL_INCONSISTENT)){
							IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV3_t, currentTime);
						}
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
					if (quality == QUALITY_VALIDITY_GOOD){
						mag = 0;
						if (IedServer_updateQuality(iedServer,&iedModel_RPN_ATCC1_CtlV7_q,QUALITY_VALIDITY_QUESTIONABLE | QUALITY_DETAIL_INCONSISTENT)){
							IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV7_t, currentTime);
						}
					}
				}
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_RPN_ATCC1_CtlV7_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV7_t, currentTime);
	// CtlV8
				mag = GetRealU(ucMAnalogInBuf[MB_offset_Upp2],ucMUstavkiInBuf[MB_offset_Ktn2]);

				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_RPN_ATCC1_CtlV8_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_RPN_ATCC1_CtlV8_t, currentTime);

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

*/
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

return ret;
}
#else
/*******************************************************
 * заглушки
 *******************************************************/
int		Set_ATCC	(uint16_t QTnum, uint64_t currentTime ){return false;}
#endif

