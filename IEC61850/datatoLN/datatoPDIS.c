/*
 * datatoPDIS.c
 *
 *  Created on: 23.05.2017
 *      Author: sagok
 */


#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "datatoPDIS.h"
#include "datatoPTOC.h"

/*******************************************************
 * MR5_500 MR5_600 MR5_700
 *******************************************************/
#if defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)
#if defined (MR5_700)
#include "static_model_MR5_700.h"
#endif
#if defined (MR5_600)
#include "static_model_MR5_600.h"
#endif
#if defined (MR5_500)
#include "static_model_MR5_500.h"
#endif
#if defined (MR741)
#include "static_model_MR741.h"
#endif
/*******************************************************
 * заглушки
 *******************************************************/
int		Set_PDIS		(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR851
 *******************************************************/
#if defined (MR851)
#include "static_model_MR851.h"

/*******************************************************
 * заглушки
 *******************************************************/
int		Set_PDIS		(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR901 MR902
 *******************************************************/
#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"
/*******************************************************
 * заглушки
 *******************************************************/
int		Set_PDIS		(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR801
 *******************************************************/
#if defined	(MR801)

/*******************************************************
 * заглушки
 *******************************************************/

int		Set_PDIS		(uint16_t QTnum, uint64_t currentTime ){return false;}

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

//	MMXU1  MB_bOffsetModule4
//	MMXU2  MB_bOffsetModule4
//	MMXU3  MB_bOffsetModule5
//	MMXU4  MB_bOffsetModule5

/*******************************************************
 * Set_MMXU наполняем оперативными данными
 *******************************************************/
int		Set_PDIS	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Health;
	uint32_t	Mod;
	int16_t		Zsel;
	//Health
				Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5)) {Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}

				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS1_Health_stVal, Health)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS1_Health_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS2_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS2_Health_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS3_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS3_Health_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS4_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS4_Health_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS5_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS5_Health_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS6_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS6_Health_t, currentTime);
#if defined	(MR771)
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS7_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS7_Health_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS8_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS8_Health_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS9_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS9_Health_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS10_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS10_Health_t, currentTime);
#endif
				}
	//  Mod Beh
				//PDIS1
				if (ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z1_Conf] & MB_bOffset_Z_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS1_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS1_Mod_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS1_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS1_Beh_t, currentTime);
				}

				//PDIS2
				if (ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z2_Conf] & MB_bOffset_Z_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS2_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS2_Mod_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS2_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS2_Beh_t, currentTime);
				}
				//PDIS3
				if (ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z3_Conf] & MB_bOffset_Z_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS3_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS3_Mod_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS3_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS3_Beh_t, currentTime);
				}
				//PDIS4
				if (ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z4_Conf] & MB_bOffset_Z_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS4_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS4_Mod_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS4_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS4_Beh_t, currentTime);
				}
				//PDIS5
				if (ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z5_Conf] & MB_bOffset_Z_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS5_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS5_Mod_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS5_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS5_Beh_t, currentTime);
				}
				//PDIS6
				if (ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z6_Conf] & MB_bOffset_Z_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS6_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS6_Mod_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS6_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS6_Beh_t, currentTime);
				}
#if defined	(MR771)
				//PDIS7
				if (ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z7_Conf] & MB_bOffset_Z_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS7_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS7_Mod_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS7_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS7_Beh_t, currentTime);
				}
				//PDIS8
				if (ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z8_Conf] & MB_bOffset_Z_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS8_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS8_Mod_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS8_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS8_Beh_t, currentTime);
				}
				//PDIS9
				if (ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z9_Conf] & MB_bOffset_Z_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS9_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS9_Mod_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS9_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS9_Beh_t, currentTime);
				}
				//PDIS10
				if (ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z10_Conf] & MB_bOffset_Z_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS10_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS10_Mod_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS10_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDIS10_Beh_t, currentTime);
				}
#endif
	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS5_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS6_Mod_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS5_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS6_Beh_q,Qual);

#if defined	(MR771)
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS7_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS8_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS9_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS10_Mod_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS7_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS8_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS9_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS10_Beh_q,Qual);

#endif


	// Str_general
				IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_PDIS1_Str_general, &iedModel_PROT_PDIS1_Str_t, currentTime,  ucMDiscInBuf[MB_IO_offsetZ_1] & MB_Z1_IO);
				IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_PDIS2_Str_general, &iedModel_PROT_PDIS2_Str_t, currentTime,  ucMDiscInBuf[MB_IO_offsetZ_2] & MB_Z2_IO);
				IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_PDIS3_Str_general, &iedModel_PROT_PDIS3_Str_t, currentTime,  ucMDiscInBuf[MB_IO_offsetZ_3] & MB_Z3_IO);
				IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_PDIS4_Str_general, &iedModel_PROT_PDIS4_Str_t, currentTime,  ucMDiscInBuf[MB_IO_offsetZ_4] & MB_Z4_IO);
				IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_PDIS5_Str_general, &iedModel_PROT_PDIS5_Str_t, currentTime,  ucMDiscInBuf[MB_IO_offsetZ_5] & MB_Z5_IO);
				IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_PDIS6_Str_general, &iedModel_PROT_PDIS6_Str_t, currentTime,  ucMDiscInBuf[MB_IO_offsetZ_6] & MB_Z6_IO);
#if defined	(MR771)
				IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_PDIS7_Str_general, &iedModel_PROT_PDIS7_Str_t, currentTime,  ucMDiscInBuf[MB_IO_offsetZ_7] & MB_Z7_IO);
				IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_PDIS8_Str_general, &iedModel_PROT_PDIS8_Str_t, currentTime,  ucMDiscInBuf[MB_IO_offsetZ_8] & MB_Z8_IO);
				IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_PDIS9_Str_general, &iedModel_PROT_PDIS9_Str_t, currentTime,  ucMDiscInBuf[MB_IO_offsetZ_9] & MB_Z9_IO);
				IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_PDIS10_Str_general, &iedModel_PROT_PDIS10_Str_t, currentTime, ucMDiscInBuf[MB_IO_offsetZ_10] & MB_Z10_IO);
#endif

				/*
				 * STVALCODEDENUM_UNKNOWN:
				 * 11B4 Биты 8,9,10 == 0 и 1:если StrGen==true и 0D27/3 & 0D27/5 & 0D27/7 == 0 		2:если StrGen==false
				 * 11B4 Биты 8,9,10 != 0 и 1:если StrGen==true и 0D26/13 & 0D26/15 & 0D27/1 == 0) 	2:если StrGen==false
				 */

				bool dirError_Z = 1;
				if ( (0 == (ucMDiscInBuf[MB_offset_dirErrorPTOC_Za] & MB_b_dirError_Za)) &&
					 (0 == (ucMDiscInBuf[MB_offset_dirErrorPTOC_Zb] & MB_b_dirError_Zb)) &&
					 (0 == (ucMDiscInBuf[MB_offset_dirErrorPTOC_Zc] & MB_b_dirError_Zc)) ) {
					dirError_Z = 0;
				}
				bool dirError_Za = 1;

				if ( (0 == (ucMDiscInBuf[MB_offset_dirErrorPTOC_Zab] & MB_b_dirError_Zab)) &&
					 (0 == (ucMDiscInBuf[MB_offset_dirErrorPTOC_Zbc] & MB_b_dirError_Zbc)) &&
					 (0 == (ucMDiscInBuf[MB_offset_dirErrorPTOC_Zca] & MB_b_dirError_Zca)) ) {
					dirError_Za = 0;
				}

//-------------
				// PDIS1
				if ( ucMDiscInBuf[MB_IO_offsetZ_1] & MB_Z1_IO) {
						 if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z1_Conf] & MB_bOffset_Z_Config_Napravl_up) Zsel = STVALCODEDENUM_FORWARD;
					else if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z1_Conf] & MB_bOffset_Z_Config_Napravl_dn) Zsel = STVALCODEDENUM_BACKWARD;
					else Zsel = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
				}   else Zsel = STVALCODEDENUM_UNKNOWN;

/*
				if ((ucMDiscInBuf[MB_IO_offsetZ_1] & MB_Z1_IO) == 0){ //StrGen == 0?
					Zsel = STVALCODEDENUM_UNKNOWN;
				} else{												  //StrGen != 0?
					if(ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z1_Conf] & MB_bOffset_Z_Config_kontur){//Биты 8,9,10 != 0
						if (dirError_Z  == 0) Zsel = STVALCODEDENUM_UNKNOWN;
					}else{
						if (dirError_Za == 0) Zsel = STVALCODEDENUM_UNKNOWN;
					}
				}
*/
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS1_Str_dirGeneral, Zsel))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS1_Str_t, currentTime);
//-------------
				// PDIS2
				if ( ucMDiscInBuf[MB_IO_offsetZ_2] & MB_Z2_IO) {
					 if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z2_Conf] & MB_bOffset_Z_Config_Napravl_up) Zsel = STVALCODEDENUM_FORWARD;
				else if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z2_Conf] & MB_bOffset_Z_Config_Napravl_dn) Zsel = STVALCODEDENUM_BACKWARD;
				else Zsel = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
				} else	Zsel = STVALCODEDENUM_UNKNOWN;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS2_Str_dirGeneral, Zsel))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS2_Str_t, currentTime);

				// PDIS3
				if ( ucMDiscInBuf[MB_IO_offsetZ_3] & MB_Z3_IO) {
					 if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z3_Conf] & MB_bOffset_Z_Config_Napravl_up) Zsel = STVALCODEDENUM_FORWARD;
				else if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z3_Conf] & MB_bOffset_Z_Config_Napravl_dn) Zsel = STVALCODEDENUM_BACKWARD;
				else Zsel = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
				} else Zsel = STVALCODEDENUM_UNKNOWN;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS3_Str_dirGeneral, Zsel))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS3_Str_t, currentTime);

				// PDIS4
				if ( ucMDiscInBuf[MB_IO_offsetZ_4] & MB_Z4_IO) {
					 if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z4_Conf] & MB_bOffset_Z_Config_Napravl_up) Zsel = STVALCODEDENUM_FORWARD;
				else if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z4_Conf] & MB_bOffset_Z_Config_Napravl_dn) Zsel = STVALCODEDENUM_BACKWARD;
				else Zsel = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
				} else Zsel = STVALCODEDENUM_UNKNOWN;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS4_Str_dirGeneral, Zsel))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS4_Str_t, currentTime);

				// PDIS5
				if ( ucMDiscInBuf[MB_IO_offsetZ_5] & MB_Z5_IO) {
					 if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z5_Conf] & MB_bOffset_Z_Config_Napravl_up) Zsel = STVALCODEDENUM_FORWARD;
				else if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z5_Conf] & MB_bOffset_Z_Config_Napravl_dn) Zsel = STVALCODEDENUM_BACKWARD;
				else Zsel = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
				} else Zsel = STVALCODEDENUM_UNKNOWN;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS5_Str_dirGeneral, Zsel))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS5_Str_t, currentTime);

				// PDIS6
				if ( ucMDiscInBuf[MB_IO_offsetZ_6] & MB_Z6_IO) {
					 if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z6_Conf] & MB_bOffset_Z_Config_Napravl_up) Zsel = STVALCODEDENUM_FORWARD;
				else if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z6_Conf] & MB_bOffset_Z_Config_Napravl_dn) Zsel = STVALCODEDENUM_BACKWARD;
				else Zsel = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
				} else Zsel = STVALCODEDENUM_UNKNOWN;


				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS6_Str_dirGeneral, Zsel))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS6_Str_t, currentTime);

#if defined	(MR771)
				// PDIS7
				if ( ucMDiscInBuf[MB_IO_offsetZ_7] & MB_Z7_IO) {
					 if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z7_Conf] & MB_bOffset_Z_Config_Napravl_up) Zsel = STVALCODEDENUM_FORWARD;
				else if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z7_Conf] & MB_bOffset_Z_Config_Napravl_dn) Zsel = STVALCODEDENUM_BACKWARD;
				else Zsel = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
				} else Zsel = STVALCODEDENUM_UNKNOWN;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS7_Str_dirGeneral, Zsel))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS7_Str_t, currentTime);

				// PDIS8
				if ( ucMDiscInBuf[MB_IO_offsetZ_8] & MB_Z8_IO) {
					 if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z8_Conf] & MB_bOffset_Z_Config_Napravl_up) Zsel = STVALCODEDENUM_FORWARD;
				else if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z8_Conf] & MB_bOffset_Z_Config_Napravl_dn) Zsel = STVALCODEDENUM_BACKWARD;
				else Zsel = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
				} else Zsel = STVALCODEDENUM_UNKNOWN;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS8_Str_dirGeneral, Zsel))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS8_Str_t, currentTime);
				// PDIS9
				if ( ucMDiscInBuf[MB_IO_offsetZ_9] & MB_Z9_IO) {
					if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z9_Conf] & MB_bOffset_Z_Config_Napravl_up) Zsel = STVALCODEDENUM_FORWARD;
				else if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z9_Conf] & MB_bOffset_Z_Config_Napravl_dn) Zsel = STVALCODEDENUM_BACKWARD;
				else Zsel = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
				} else Zsel = STVALCODEDENUM_UNKNOWN;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS9_Str_dirGeneral, Zsel))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS9_Str_t, currentTime);

				// PDIS10
				if ( ucMDiscInBuf[MB_IO_offsetZ_10] & MB_Z10_IO) {
					if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z10_Conf] & MB_bOffset_Z_Config_Napravl_up) Zsel = STVALCODEDENUM_FORWARD;
				else if(   ucMUstavkiInBuf[MB_StartConfig_Z + MB_offset_Z10_Conf] & MB_bOffset_Z_Config_Napravl_dn) Zsel = STVALCODEDENUM_BACKWARD;
				else Zsel = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
				} else Zsel = STVALCODEDENUM_UNKNOWN;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDIS10_Str_dirGeneral, Zsel))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS10_Str_t, currentTime);
#endif

	Quality quality = QUALITY_VALIDITY_GOOD;
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS1_Str_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS2_Str_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS3_Str_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS4_Str_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS5_Str_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS6_Str_q,quality);
#if defined	(MR771)
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS7_Str_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS8_Str_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS9_Str_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS10_Str_q,quality);
#endif

	// Op
	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PDIS1_Op_general,  ucMDiscInBuf[MB_IO_offsetZ_1] & MB_Z1))
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS1_Op_t, currentTime);

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PDIS2_Op_general,  ucMDiscInBuf[MB_IO_offsetZ_2] & MB_Z2))
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS2_Op_t, currentTime);

    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PDIS3_Op_general,  ucMDiscInBuf[MB_IO_offsetZ_3] & MB_Z3))
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS3_Op_t, currentTime);

    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PDIS4_Op_general,  ucMDiscInBuf[MB_IO_offsetZ_4] & MB_Z4))
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS4_Op_t, currentTime);

    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PDIS5_Op_general,  ucMDiscInBuf[MB_IO_offsetZ_5] & MB_Z5))
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS5_Op_t, currentTime);

    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PDIS6_Op_general,  ucMDiscInBuf[MB_IO_offsetZ_6] & MB_Z6))
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS6_Op_t, currentTime);
#if defined	(MR771)
    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PDIS7_Op_general,  ucMDiscInBuf[MB_IO_offsetZ_7] & MB_Z7))
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS7_Op_t, currentTime);

    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PDIS8_Op_general,  ucMDiscInBuf[MB_IO_offsetZ_8] & MB_Z8))
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS8_Op_t, currentTime);

    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PDIS9_Op_general,  ucMDiscInBuf[MB_IO_offsetZ_9] & MB_Z9))
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS9_Op_t, currentTime);

    if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PDIS10_Op_general,  ucMDiscInBuf[MB_IO_offsetZ_10] & MB_Z10))
    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDIS10_Op_t, currentTime);
#endif

	quality = QUALITY_VALIDITY_GOOD;
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS1_Op_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS2_Op_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS3_Op_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS4_Op_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS5_Op_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS6_Op_q,quality);
#if defined	(MR771)
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS7_Op_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS8_Op_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS9_Op_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_PDIS10_Op_q,quality);
#endif
}

#endif
