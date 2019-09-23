/*
 * datatoPTOC.c
 *
 *  Created on: 18.04.2017
 *      Author: sagok
 */

#include "main.h"
#include "IEC850.h"
#include "iec61850_server.h"


int16_t		GetDirGeneral(uint8_t	Currdata);
#if defined	(MR771) ||  defined	(MR761) || defined	(MR762) || defined	(MR763)

int			GetDirGeneralUnknoun(uint16_t	g_Icfg, uint16_t* Valtmp1);
#endif
#if defined (MR801)
int			GetSidebleDirGeneralUnknoun(uint8_t side, uint16_t	g_Icfg,uint16_t* Valtmp1);
#endif
//uint8_t		GetDirGeneralInSide(uint8_t		Side);
//uint8_t		GetDirGeneralInSideLogic(uint8_t		Side, uint8_t		Logic);

/*******************************************************
 * MR5_600
 *******************************************************/
#if defined (MR5_600)
#include "static_model_MR5_600.h"

/*******************************************************
 * заглушки
 *******************************************************/
int			Set_IPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IPTUC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I2PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I0PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I20PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_INPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IGPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I2I1PTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_LZSHPTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IARCPTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR851
 *******************************************************/
#if defined (MR851)
#include "static_model_MR851.h"

/*******************************************************
 * заглушки
 *******************************************************/
int			Set_IPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IPTUC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I2PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I0PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I20PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_INPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IGPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I2I1PTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_LZSHPTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IARCPTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif

/*******************************************************
 * MR801 T12N5D58R51
 *******************************************************/
#if defined (MR801) && defined (T12N5D58R51)
#include "static_model_MR801_T12N5D58R51.h"

extern uint16_t   ucConfigAWRBuf[MB_Size_ConfigAWR];
extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];
extern uint16_t   ucMUstavkiInBuf[MB_Size_Ustavki];

/*******************************************************
 * заглушки
 *******************************************************/

int			Set_I2PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I0PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_INPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IGPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_LZSHPTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}

/*******************************************************
 * получаем направление UNKNOWN в зависимости от стороны
 *******************************************************/
bool		getUNKNOWN_SidebldirIPTOC	(uint8_t side )
{
	bool ret = false;
	switch (side){
	case 0 :
		if ( (ucMDiscInBuf[MB_offset_dirPTOC_Side1_Ia] & MB_b_dirError_Side1_Ia) &&
			 (ucMDiscInBuf[MB_offset_dirPTOC_Side1_Ib] & MB_b_dirError_Side1_Ib) &&
			 (ucMDiscInBuf[MB_offset_dirPTOC_Side1_Ic] & MB_b_dirError_Side1_Ic) ) {
				 ret = true;
			}
		break;
	case 1 :
		if ( (ucMDiscInBuf[MB_offset_dirPTOC_Side2_Ia] & MB_b_dirError_Side2_Ia) &&
			 (ucMDiscInBuf[MB_offset_dirPTOC_Side2_Ib] & MB_b_dirError_Side2_Ib) &&
			 (ucMDiscInBuf[MB_offset_dirPTOC_Side2_Ic] & MB_b_dirError_Side2_Ic) ) {
				 ret = true;
			}
		break;
	case 2 :
		if ( (ucMDiscInBuf[MB_offset_dirPTOC_Side3_Ia] & MB_b_dirError_Side3_Ia) &&
			 (ucMDiscInBuf[MB_offset_dirPTOC_Side3_Ib] & MB_b_dirError_Side3_Ib) &&
			 (ucMDiscInBuf[MB_offset_dirPTOC_Side3_Ic] & MB_b_dirError_Side3_Ic) ) {
				 ret = true;
			}
		break;
	}
return ret;
}
/*******************************************************
 * получаем качество в зависимости от Health
 *******************************************************/
Quality getQualityFromHealth(uint32_t Health){

Quality quality = QUALITY_VALIDITY_GOOD;
	if (Health != STVALINT32_OK) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
return quality;
}
/*******************************************************
 * получаем качество по флагам уставок
 *******************************************************/
Quality getQualityFromFlagsMB(uint16_t flags){

Quality quality = QUALITY_VALIDITY_GOOD;
	if ((flags)> 0) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
return quality;
}
/*******************************************************
 * getABC_NumbInIPTOC
 * получаем номера входов ABC зависимости от стороны
 *******************************************************/
uint32_t getABC_HealthIn(uint8_t Side){

uint32_t 	Health = STVALINT32_OK;
uint8_t 	A=0,B=0,C=0;			// номер входа

	switch (Side){
		case 0:
			A = ucMUstavkiInBuf[MB_offset_ConfigS1 + MB_offset_NumbIn_Ia];
			B = ucMUstavkiInBuf[MB_offset_ConfigS1 + MB_offset_NumbIn_Ib];
			C = ucMUstavkiInBuf[MB_offset_ConfigS1 + MB_offset_NumbIn_Ic];
			break;
		case 1:
			A = ucMUstavkiInBuf[MB_offset_ConfigS2 + MB_offset_NumbIn_Ia];
			B = ucMUstavkiInBuf[MB_offset_ConfigS2 + MB_offset_NumbIn_Ib];
			C = ucMUstavkiInBuf[MB_offset_ConfigS2 + MB_offset_NumbIn_Ic];
			break;
		case 2:
			A = ucMUstavkiInBuf[MB_offset_ConfigS3 + MB_offset_NumbIn_Ia];
			B = ucMUstavkiInBuf[MB_offset_ConfigS3 + MB_offset_NumbIn_Ib];
			C = ucMUstavkiInBuf[MB_offset_ConfigS3 + MB_offset_NumbIn_Ic];
			break;
		case 3:
			A = ucMUstavkiInBuf[MB_offset_ConfigS4 + MB_offset_NumbIn_Ia];
			B = ucMUstavkiInBuf[MB_offset_ConfigS4 + MB_offset_NumbIn_Ib];
			C = ucMUstavkiInBuf[MB_offset_ConfigS4 + MB_offset_NumbIn_Ic];
			break;
	}

	if ((A==0)||(B==0)||(C==0))	{
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0) 	{Health = STVALINT32_Warning;}
	}
	if ((A>=1 && A<=8)||(B>=1 && B<=8)||(C>=1 && C<=8))	{
		if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0)				{Health = STVALINT32_Warning;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0) 	{Health = STVALINT32_Warning;}
	}
	if ((A>=9 && A<=12)||(B>=9 && B<=12)||(C>=9 && C<=12))	{
		if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0)				{Health = STVALINT32_Warning;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0) 	{Health = STVALINT32_Warning;}
	}
return Health;
}
/*******************************************************
 * Set_IPTOC наполняем оперативными данными узлы IPTOC1...8
 *******************************************************/
int		Set_IPTOC	(uint16_t QTnum, uint64_t currentTime ){
	int	ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
//	uint16_t	num;
//	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
// -----------------------------------------------------------------------------
	int16_t	Valtmp1=0;
	int16_t	Valtmp2=0;
	int16_t	Valtmp3=0;
	int16_t	Valtmp4=0;
	int16_t	Valtmp5=0;
	int16_t	Valtmp6=0;

	uint8_t		Side;

	uint32_t	Health1 = STVALINT32_OK;
	uint32_t	Health2 = STVALINT32_OK;
	uint32_t	Health3 = STVALINT32_OK;
	uint32_t	Health4 = STVALINT32_OK;
	uint32_t	Health5 = STVALINT32_OK;
	uint32_t	Health6 = STVALINT32_OK;

//Health
			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_MTZ_I);
			Health1 = getABC_HealthIn(Side);
			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_MTZ_I);
			Health2 = getABC_HealthIn(Side);
			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_MTZ_I);
			Health3 = getABC_HealthIn(Side);
			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_MTZ_I);
			Health4 = getABC_HealthIn(Side);
			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_MTZ_I);
			Health5 = getABC_HealthIn(Side);
			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_MTZ_I);
			Health6 = getABC_HealthIn(Side);

			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Health_stVal, Health1))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Health_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Health_stVal, Health2))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Health_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Health_stVal, Health3))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Health_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Health_stVal, Health4))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Health_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Health_stVal, Health5))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Health_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Health_stVal, Health6))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Health_t, currentTime);


//  Mod Beh
			uint32_t	IPTOC_Mod;
			if ((ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Mod_stVal, IPTOC_Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Beh_stVal, IPTOC_Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Mod_stVal, IPTOC_Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Beh_stVal, IPTOC_Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Mod_stVal, IPTOC_Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Beh_stVal, IPTOC_Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Mod_stVal, IPTOC_Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Beh_stVal, IPTOC_Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Mod_stVal, IPTOC_Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Beh_stVal, IPTOC_Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Mod_stVal, IPTOC_Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Beh_stVal, IPTOC_Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Beh_t, currentTime);
			}

//  Quality (Mod Beh)
			quality = QUALITY_VALIDITY_GOOD;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Mod_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Beh_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Beh_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Beh_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Beh_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Beh_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Beh_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Beh_t, currentTime);
			}

// Str_general

			IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC1_Str_general,&iedModel_PROT_IPTOC1_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I1] & MB_b_IO_I1)>0);
			IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC2_Str_general,&iedModel_PROT_IPTOC2_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I2] & MB_b_IO_I2)>0);
			IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC3_Str_general,&iedModel_PROT_IPTOC3_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I3] & MB_b_IO_I3)>0);
			IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC4_Str_general,&iedModel_PROT_IPTOC4_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I4] & MB_b_IO_I4)>0);
			IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC5_Str_general,&iedModel_PROT_IPTOC5_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I5] & MB_b_IO_I5)>0);
			IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC6_Str_general,&iedModel_PROT_IPTOC6_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I6] & MB_b_IO_I6)>0);

// Op_general
			IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC1_Op_general,&iedModel_PROT_IPTOC1_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I1] & MB_b_SRAB_I1)>0);
			IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC2_Op_general,&iedModel_PROT_IPTOC2_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I2] & MB_b_SRAB_I2)>0);
			IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC3_Op_general,&iedModel_PROT_IPTOC3_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I3] & MB_b_SRAB_I3)>0);
			IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC4_Op_general,&iedModel_PROT_IPTOC4_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I4] & MB_b_SRAB_I4)>0);
			IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC5_Op_general,&iedModel_PROT_IPTOC5_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I5] & MB_b_SRAB_I5)>0);
			IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC6_Op_general,&iedModel_PROT_IPTOC6_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I6] & MB_b_SRAB_I6)>0);

// Str_dir_general				в зависимости от стороны

// IPTOC1
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_MTZ_I;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp1 = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I1] & MB_b_IO_I1)>0){
					 if((   ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp1 = STVALCODEDENUM_FORWARD;
				else if((   ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp1 = STVALCODEDENUM_BACKWARD;
				else Valtmp1 = STVALCODEDENUM_UNKNOWN;
			} else Valtmp1 = STVALCODEDENUM_UNKNOWN;
		}

// IPTOC2
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_MTZ_I;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp2 = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I2] & MB_b_IO_I2)>0){
					 if((   ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp2 = STVALCODEDENUM_FORWARD;
				else if((   ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp2 = STVALCODEDENUM_BACKWARD;
				else Valtmp2 = STVALCODEDENUM_UNKNOWN;
			} else Valtmp2 = STVALCODEDENUM_UNKNOWN;
		}

// IPTOC3
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_MTZ_I;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp3 = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I3] & MB_b_IO_I3)>0){
					 if((   ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp3 = STVALCODEDENUM_FORWARD;
				else if((   ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp3 = STVALCODEDENUM_BACKWARD;
				else Valtmp3 = STVALCODEDENUM_UNKNOWN;
			} else Valtmp3 = STVALCODEDENUM_UNKNOWN;
		}

// IPTOC4
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_MTZ_I;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp4 = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I4] & MB_b_IO_I4)>0){
					 if((ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp4 = STVALCODEDENUM_FORWARD;
				else if((ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp4 = STVALCODEDENUM_BACKWARD;
				else Valtmp4 = STVALCODEDENUM_UNKNOWN;
			} else Valtmp4 = STVALCODEDENUM_UNKNOWN;
		}

// IPTOC5
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_MTZ_I;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp5 = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I5] & MB_b_IO_I5)>0){
					 if((ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp5 = STVALCODEDENUM_FORWARD;
				else if((ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp5 = STVALCODEDENUM_BACKWARD;
				else Valtmp5 = STVALCODEDENUM_UNKNOWN;
			} else Valtmp5 = STVALCODEDENUM_UNKNOWN;
		}

// IPTOC6
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_MTZ_I;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp6 = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I6] & MB_b_IO_I6)>0){
					 if((ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp6 = STVALCODEDENUM_FORWARD;
				else if((ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp6 = STVALCODEDENUM_BACKWARD;
				else Valtmp6 = STVALCODEDENUM_UNKNOWN;
			} else Valtmp6 = STVALCODEDENUM_UNKNOWN;
		}

		if (T) {
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC1_Str_dirGeneral,&iedModel_PROT_IPTOC1_Str_t,currentTime, Valtmp1);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC2_Str_dirGeneral,&iedModel_PROT_IPTOC2_Str_t,currentTime, Valtmp2);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC3_Str_dirGeneral,&iedModel_PROT_IPTOC3_Str_t,currentTime, Valtmp3);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC4_Str_dirGeneral,&iedModel_PROT_IPTOC4_Str_t,currentTime, Valtmp4);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC5_Str_dirGeneral,&iedModel_PROT_IPTOC5_Str_t,currentTime, Valtmp5);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC6_Str_dirGeneral,&iedModel_PROT_IPTOC6_Str_t,currentTime, Valtmp6);

		}else{
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_dirGeneral, Valtmp1))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_dirGeneral, Valtmp2))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_dirGeneral, Valtmp3))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_dirGeneral, Valtmp4))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_dirGeneral, Valtmp5))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_dirGeneral, Valtmp6))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_t, currentTime);
		}

		quality = getQualityFromHealth(Health1);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_t, currentTime);
		}
		quality = getQualityFromHealth(Health2);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Op_t, currentTime);
		}
		quality = getQualityFromHealth(Health3);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Op_t, currentTime);
		}
		quality = getQualityFromHealth(Health4);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Op_t, currentTime);
		}
		quality = getQualityFromHealth(Health5);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Op_t, currentTime);
		}
		quality = getQualityFromHealth(Health6);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Op_t, currentTime);
		}

/*
		quality = QUALITY_VALIDITY_GOOD;
		if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0)			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0)  			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Str_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Op_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Str_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Op_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Str_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Op_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Str_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Op_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Str_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Op_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Str_q,quality);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_t, currentTime);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Op_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Op_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Op_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Op_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Op_t, currentTime);
		}
*/
return ret;
}

/*******************************************************
 * Set_IPTUC наполняем оперативными данными узлы IPTUC1
 *******************************************************/
int		Set_IPTUC		(uint16_t QTnum, uint64_t currentTime ){
	int	ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
//	uint16_t	num;
//	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
// -----------------------------------------------------------------------------
	int16_t	Valtmp=0;

	uint8_t		Side;

//Health
			uint32_t	Health = STVALINT32_OK;

			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_MTZ_I);
			Health = getABC_HealthIn(Side);

			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTUC1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTUC1_Health_t, currentTime);

//  Mod Beh
			uint32_t	IPTOC_Mod;

			if ((ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTUC1_Mod_stVal, IPTOC_Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTUC1_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTUC1_Beh_stVal, IPTOC_Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTUC1_Beh_t, currentTime);
			}

//  Quality (Mod Beh)
			quality = QUALITY_VALIDITY_GOOD;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTUC1_Mod_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTUC1_Beh_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTUC1_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTUC1_Beh_t, currentTime);
			}

// Str_general
// Op_general
			IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTUC1_Str_general,&iedModel_PROT_IPTUC1_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I7] & MB_b_IO_I7)>0);
			IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTUC1_Op_general,&iedModel_PROT_IPTUC1_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I7] & MB_b_SRAB_I7)>0);

// Str_dir_general				в зависимости от стороны

// IPTUC1
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_MTZ_I;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I7] & MB_b_IO_I7)>0){
					 if((ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp = STVALCODEDENUM_FORWARD;
				else if((ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp = STVALCODEDENUM_BACKWARD;
				else Valtmp = STVALCODEDENUM_UNKNOWN;
			} else Valtmp = STVALCODEDENUM_UNKNOWN;
		}

		if (T) {
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTUC1_Str_dirGeneral,&iedModel_PROT_IPTUC1_Str_t,currentTime, Valtmp);
		}else{
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTUC1_Str_dirGeneral, Valtmp))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTUC1_Str_t, currentTime);
		}

		quality = getQualityFromHealth(Health);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTUC1_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTUC1_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTUC1_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTUC1_Op_t, currentTime);
		}
/*
		quality = QUALITY_VALIDITY_GOOD;
		if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0)			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0)  			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTUC1_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_IPTUC1_Str_q,quality);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTUC1_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTUC1_Op_t, currentTime);
		}
*/
return ret;
}

/*******************************************************
 * Set_I20PTOC наполняем оперативными данными узлы
 *******************************************************/
int		Set_I20PTOC		(uint16_t QTnum, uint64_t currentTime ){
	int			ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
//	uint16_t	num;
//	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
// -----------------------------------------------------------------------------
	uint16_t	Valtmp1=0;
	uint16_t	Valtmp2=0;
	uint16_t	Valtmp3=0;
	uint16_t	Valtmp4=0;
	uint16_t	Valtmp5=0;
	uint16_t	Valtmp6=0;
	uint16_t	Valtmp7=0;
	uint16_t	Valtmp8=0;

	uint16_t	g_Icfg;
	uint8_t		Side;

	uint32_t	Health1 = STVALINT32_OK;
	uint32_t	Health2 = STVALINT32_OK;
	uint32_t	Health3 = STVALINT32_OK;
	uint32_t	Health4 = STVALINT32_OK;
	uint32_t	Health5 = STVALINT32_OK;
	uint32_t	Health6 = STVALINT32_OK;
	uint32_t	Health7 = STVALINT32_OK;
	uint32_t	Health8 = STVALINT32_OK;

//Health
			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> MB_bOffset_Ig_I_Config_Side);
			Health1 = getABC_HealthIn(Side);
			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> MB_bOffset_Ig_I_Config_Side);
			Health2 = getABC_HealthIn(Side);
			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> MB_bOffset_Ig_I_Config_Side);
			Health3 = getABC_HealthIn(Side);
			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> MB_bOffset_Ig_I_Config_Side);
			Health4 = getABC_HealthIn(Side);
			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> MB_bOffset_Ig_I_Config_Side);
			Health5 = getABC_HealthIn(Side);
			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> MB_bOffset_Ig_I_Config_Side);
			Health6 = getABC_HealthIn(Side);
			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_Ig_I7 + MB_offset_Ig_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> MB_bOffset_Ig_I_Config_Side);
			Health7 = getABC_HealthIn(Side);
			Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_offset_Ig_I8 + MB_offset_Ig_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> MB_bOffset_Ig_I_Config_Side);
			Health8 = getABC_HealthIn(Side);

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Health_stVal, Health1))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Health_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Health_stVal, Health2))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Health_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Health_stVal, Health3))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Health_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Health_stVal, Health4))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Health_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Health_stVal, Health5))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Health_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Health_stVal, Health6))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Health_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Health_stVal, Health7))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC7_Health_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Health_stVal, Health8))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC8_Health_t, currentTime);


//  Mod Beh
		uint32_t	IPTOC_Mod;
		if ((ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Mod_stVal, IPTOC_Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Beh_stVal, IPTOC_Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Beh_t, currentTime);
		}

		if ((ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Mod_stVal, IPTOC_Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Beh_stVal, IPTOC_Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Beh_t, currentTime);
		}

		if ((ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Mod_stVal, IPTOC_Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Beh_stVal, IPTOC_Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Beh_t, currentTime);
		}

		if ((ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Mod_stVal, IPTOC_Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Beh_stVal, IPTOC_Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Beh_t, currentTime);
		}

		if ((ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Mod_stVal, IPTOC_Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Beh_stVal, IPTOC_Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Beh_t, currentTime);
		}

		if ((ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Mod_stVal, IPTOC_Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Beh_stVal, IPTOC_Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Beh_t, currentTime);
		}

		if ((ucMUstavkiInBuf[MB_offset_Ig_I7 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Mod_stVal, IPTOC_Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC7_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Beh_stVal, IPTOC_Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC7_Beh_t, currentTime);
		}

		if ((ucMUstavkiInBuf[MB_offset_Ig_I8 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Mod_stVal, IPTOC_Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC8_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Beh_stVal, IPTOC_Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC8_Beh_t, currentTime);
		}


//  Quality (Mod Beh)
		quality = QUALITY_VALIDITY_GOOD;
		if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorUstavki)>0) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Mod_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Beh_q,quality);


			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Mod_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Beh_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Mod_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Beh_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Mod_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Beh_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Mod_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Beh_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Mod_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Beh_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Mod_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Beh_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC7_Mod_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC7_Beh_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC8_Mod_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC8_Beh_t,currentTime);

		}

		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC1_Str_general,&iedModel_PROT_I20PTOC1_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_Ig1] & MB_b_IO_Ig1)>0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC2_Str_general,&iedModel_PROT_I20PTOC2_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_Ig2] & MB_b_IO_Ig2)>0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC3_Str_general,&iedModel_PROT_I20PTOC3_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_Ig3] & MB_b_IO_Ig3)>0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC4_Str_general,&iedModel_PROT_I20PTOC4_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_Ig4] & MB_b_IO_Ig4)>0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC5_Str_general,&iedModel_PROT_I20PTOC5_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_Ig5] & MB_b_IO_Ig5)>0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC6_Str_general,&iedModel_PROT_I20PTOC6_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_Ig6] & MB_b_IO_Ig6)>0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC7_Str_general,&iedModel_PROT_I20PTOC7_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_Ig7] & MB_b_IO_Ig7)>0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC8_Str_general,&iedModel_PROT_I20PTOC8_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_Ig8] & MB_b_IO_Ig8)>0);


		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC1_Op_general,&iedModel_PROT_I20PTOC1_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_Ig1] & MB_b_SRAB_Ig1)>0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC2_Op_general,&iedModel_PROT_I20PTOC2_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_Ig2] & MB_b_SRAB_Ig2)>0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC3_Op_general,&iedModel_PROT_I20PTOC3_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_Ig3] & MB_b_SRAB_Ig3)>0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC4_Op_general,&iedModel_PROT_I20PTOC4_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_Ig4] & MB_b_SRAB_Ig4)>0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC5_Op_general,&iedModel_PROT_I20PTOC5_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_Ig5] & MB_b_SRAB_Ig5)>0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC6_Op_general,&iedModel_PROT_I20PTOC6_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_Ig6] & MB_b_SRAB_Ig6)>0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC7_Op_general,&iedModel_PROT_I20PTOC7_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_Ig7] & MB_b_SRAB_Ig7)>0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC8_Op_general,&iedModel_PROT_I20PTOC8_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_Ig8] & MB_b_SRAB_Ig8)>0);


// Str_dir_general				в зависимости от стороны
		// I20PTOC1 -----------------------------------------
		Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset_Ig_I;
		if ((ucMDiscInBuf[MB_offset_IO_Ig1] & MB_b_IO_Ig1)>0){
				 if((ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up)>0) Valtmp1 = STVALCODEDENUM_FORWARD;
			else if((ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn)>0) Valtmp1 = STVALCODEDENUM_BACKWARD;
			else Valtmp1 = STVALCODEDENUM_UNKNOWN;
		} else Valtmp1 = STVALCODEDENUM_UNKNOWN;
		g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
		GetSidebleDirGeneralUnknoun(Side,g_Icfg,&Valtmp1);

		// I20PTOC2 -----------------------------------------
		Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset_Ig_I;
		if ((ucMDiscInBuf[MB_offset_IO_Ig2] & MB_b_IO_Ig2)>0){
				 if((ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up)>0) Valtmp2 = STVALCODEDENUM_FORWARD;
			else if((ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn)>0) Valtmp2 = STVALCODEDENUM_BACKWARD;
			else Valtmp2 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
		} else Valtmp2 = STVALCODEDENUM_UNKNOWN;
		g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
		GetSidebleDirGeneralUnknoun(Side,g_Icfg,&Valtmp2);
		// I20PTOC3
		Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset_Ig_I;
		if ((ucMDiscInBuf[MB_offset_IO_Ig3] & MB_b_IO_Ig3)>0){
				 if((ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up)>0) Valtmp3 = STVALCODEDENUM_FORWARD;
			else if((ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn)>0) Valtmp3 = STVALCODEDENUM_BACKWARD;
			else Valtmp3 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
		} else Valtmp3 = STVALCODEDENUM_UNKNOWN;
		g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
		GetSidebleDirGeneralUnknoun(Side,g_Icfg,&Valtmp3);
		// I20PTOC4
		Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset_Ig_I;
		if ((ucMDiscInBuf[MB_offset_IO_Ig4] & MB_b_IO_Ig4)>0){
				 if((ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up)>0) Valtmp4 = STVALCODEDENUM_FORWARD;
			else if((ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn)>0) Valtmp4 = STVALCODEDENUM_BACKWARD;
			else Valtmp4 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
		} else Valtmp4 = STVALCODEDENUM_UNKNOWN;
		g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
		GetSidebleDirGeneralUnknoun(Side,g_Icfg,&Valtmp4);
		// I20PTOC5
		Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset_Ig_I;
		if ((ucMDiscInBuf[MB_offset_IO_Ig5] & MB_b_IO_Ig5)>0){
				 if((ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up)>0) Valtmp5 = STVALCODEDENUM_FORWARD;
			else if((ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn)>0) Valtmp5 = STVALCODEDENUM_BACKWARD;
			else Valtmp5 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
		} else Valtmp5 = STVALCODEDENUM_UNKNOWN;
		g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
		GetSidebleDirGeneralUnknoun(Side,g_Icfg,&Valtmp5);
		// I20PTOC6
		Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset_Ig_I;
		if ((ucMDiscInBuf[MB_offset_IO_Ig6] & MB_b_IO_Ig6)>0){
				 if((ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up)>0) Valtmp6 = STVALCODEDENUM_FORWARD;
			else if((ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn)>0) Valtmp6 = STVALCODEDENUM_BACKWARD;
			else Valtmp6 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
		} else Valtmp6 = STVALCODEDENUM_UNKNOWN;
		g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
		GetSidebleDirGeneralUnknoun(Side,g_Icfg,&Valtmp6);
		// I20PTOC7
		Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I7 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset_Ig_I;
		if ((ucMDiscInBuf[MB_offset_IO_Ig7] & MB_b_IO_Ig7)>0){
				 if((ucMUstavkiInBuf[MB_offset_Ig_I7 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up)>0) Valtmp7 = STVALCODEDENUM_FORWARD;
			else if((ucMUstavkiInBuf[MB_offset_Ig_I7 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn)>0) Valtmp7 = STVALCODEDENUM_BACKWARD;
			else Valtmp7 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
		} else Valtmp7 = STVALCODEDENUM_UNKNOWN;
		g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I7 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
		GetSidebleDirGeneralUnknoun(Side,g_Icfg,&Valtmp7);
		// I20PTOC8
		Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I8 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset_Ig_I;
		if ((ucMDiscInBuf[MB_offset_IO_Ig8] & MB_b_IO_Ig8)>0){
				 if((ucMUstavkiInBuf[MB_offset_Ig_I8 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up)>0) Valtmp8 = STVALCODEDENUM_FORWARD;
			else if((ucMUstavkiInBuf[MB_offset_Ig_I8 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn)>0) Valtmp8 = STVALCODEDENUM_BACKWARD;
			else Valtmp8 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
		} else Valtmp8 = STVALCODEDENUM_UNKNOWN;
		g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I8 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
		GetSidebleDirGeneralUnknoun(Side,g_Icfg,&Valtmp8);


		if (T) {
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC1_Str_dirGeneral,&iedModel_PROT_I20PTOC1_Str_t,currentTime, Valtmp1);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC2_Str_dirGeneral,&iedModel_PROT_I20PTOC2_Str_t,currentTime, Valtmp2);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC3_Str_dirGeneral,&iedModel_PROT_I20PTOC3_Str_t,currentTime, Valtmp3);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC4_Str_dirGeneral,&iedModel_PROT_I20PTOC4_Str_t,currentTime, Valtmp4);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC5_Str_dirGeneral,&iedModel_PROT_I20PTOC5_Str_t,currentTime, Valtmp5);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC6_Str_dirGeneral,&iedModel_PROT_I20PTOC6_Str_t,currentTime, Valtmp6);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC7_Str_dirGeneral,&iedModel_PROT_I20PTOC7_Str_t,currentTime, Valtmp7);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC8_Str_dirGeneral,&iedModel_PROT_I20PTOC8_Str_t,currentTime, Valtmp8);

		}else{
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_dirGeneral, Valtmp1))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_dirGeneral, Valtmp2))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_dirGeneral, Valtmp3))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_dirGeneral, Valtmp4))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_dirGeneral, Valtmp5))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_dirGeneral, Valtmp6))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Str_dirGeneral, Valtmp7))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Str_dirGeneral, Valtmp8))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Str_t, currentTime);

		}

		quality = getQualityFromHealth(Health1);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Op_t, currentTime);
		}
		quality = getQualityFromHealth(Health2);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Op_t, currentTime);
		}
		quality = getQualityFromHealth(Health3);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Op_t, currentTime);
		}
		quality = getQualityFromHealth(Health4);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Op_t, currentTime);
		}
		quality = getQualityFromHealth(Health5);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Op_t, currentTime);
		}
		quality = getQualityFromHealth(Health6);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Op_t, currentTime);
		}
		quality = getQualityFromHealth(Health7);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Op_t, currentTime);
		}
		quality = getQualityFromHealth(Health8);
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Str_q,quality);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Str_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Op_t, currentTime);
		}

/*
		quality = QUALITY_VALIDITY_GOOD;
		if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0)			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Op_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Str_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Op_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Str_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Op_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Str_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Op_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Str_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Op_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Str_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Op_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Str_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Op_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Str_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Op_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Str_q,quality);

			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Op_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Str_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Op_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Str_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Op_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Str_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Op_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Str_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Op_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Str_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Op_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Str_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC7_Op_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC7_Str_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC8_Op_t,currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC8_Str_t,currentTime);
		}
*/
return ret;
}

/*******************************************************
 * Set_I2I1PTOC наполняем оперативными данными узлы
 *******************************************************/
int		Set_I2I1PTOC	(uint16_t QTnum, uint64_t currentTime ){

	int			ret = false;
	Quality 	quality;
	uint32_t	Health;
	uint32_t	Mod;
	uint8_t 	Side;

//Health
	Health = STVALINT32_OK;

	Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_Addr_ConfigI2I1 + MB_offset_I2I1_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset_I2I1);
	Health = getABC_HealthIn(Side);

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Health_stVal, Health))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2I1PTOC1_Health_t, currentTime);

//Mod Beh
	if ((ucMUstavkiInBuf[MB_Addr_ConfigI2I1] & MB_bOffset_I2I1_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2I1PTOC1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2I1PTOC1_Beh_t, currentTime);
	}

//quality Mod Beh
	quality = getQualityFromFlagsMB(ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorUstavki);
	if (IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC1_Mod_q,quality)){
		IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC1_Beh_q,quality);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Mod_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Beh_t, currentTime);
	}

//Op Str
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I2I1PTOC1_Str_general,&iedModel_PROT_I2I1PTOC1_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_I2I1] & MB_b_IO_I2I1);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I2I1PTOC1_Op_general,&iedModel_PROT_I2I1PTOC1_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_I2I1] & MB_b_SRAB_I2I1);

//quality Op Str
	quality = getQualityFromHealth(Health);
	if (IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC1_Op_q,quality)){
		IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC1_Str_q,quality);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Str_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Op_t, currentTime);
	}

/*
	quality = QUALITY_VALIDITY_GOOD;
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}
	IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC1_Op_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC1_Str_q,quality);
*/
return ret;
}

/*******************************************************
 * пуск дуговой
 * Set_IARCPTOC наполняем оперативными данными узлы Set_IARCPTOC
 *******************************************************/
int		Set_IARCPTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Mod;
	uint32_t	Health;
	Quality 	quality;
	uint8_t 	Side;

//Health
	Health = STVALINT32_OK;
	Side = 0x3 & (uint8_t)((ucMUstavkiInBuf[MB_Addr_ConfigARC + MB_offset_ARC_Config] & MB_bOffset_ARC_Config_Side) >> _bSideOffset_ARC);
	Health = getABC_HealthIn(Side);

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IARCPTOC_Health_stVal, Health))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IARCPTOC_Health_t, currentTime);

//Mod Beh
	if (ucMUstavkiInBuf[MB_Addr_ConfigARC] & MB_bOffset_ARC_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IARCPTOC_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IARCPTOC_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IARCPTOC_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IARCPTOC_Beh_t, currentTime);
	}

//quality (Mod Beh)
	quality = getQualityFromFlagsMB(ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki);
	if (IedServer_updateQuality(iedServer,&iedModel_PROT_IARCPTOC_Mod_q,quality)){
		IedServer_updateQuality(iedServer,&iedModel_PROT_IARCPTOC_Beh_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IARCPTOC_Mod_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IARCPTOC_Beh_t, currentTime);
	}

//Op Str
	bool dat = false;
	if ((ucMDiscInBuf[MB_offset_Pusk_ARC] & MB_b_Pusk_ARC) > 0) dat = true; else dat = false;
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IARCPTOC_Str_general,&iedModel_PROT_IARCPTOC_Str_t, currentTime, dat);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IARCPTOC_Op_general,&iedModel_PROT_IARCPTOC_Op_t, currentTime, dat);

//quality Op Str
	quality = getQualityFromHealth(Health);
	if (IedServer_updateQuality(iedServer,&iedModel_PROT_IARCPTOC_Op_q,quality)){
		IedServer_updateQuality(iedServer,&iedModel_PROT_IARCPTOC_Str_q,quality);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IARCPTOC_Op_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IARCPTOC_Str_t, currentTime);
	}
/*
	Quality quality = QUALITY_VALIDITY_GOOD;
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}
	IedServer_updateQuality(iedServer,&iedModel_PROT_IARCPTOC_Str_q,quality);
	IedServer_updateQuality(iedServer,&iedModel_PROT_IARCPTOC_Op_q,quality);
*/
return	ret;
}

#endif
/*******************************************************
 * MR801 OLD
 *******************************************************/
#if defined (MR801) && defined (OLD)
#include "static_model_MR801.h"

extern uint16_t   ucConfigAWRBuf[MB_Size_ConfigAWR];
extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];
extern uint16_t   ucMUstavkiInBuf[MB_Size_Ustavki];

/*******************************************************
 * заглушки
 *******************************************************/

int			Set_IPTUC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IARCPTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I2PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I0PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_INPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IGPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I2I1PTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}

/*******************************************************
 * получаем направление UNKNOWN в зависимости от стороны
 *******************************************************/
bool		getUNKNOWN_SidebldirIPTOC	(uint8_t side )
{
	bool ret = false;
	switch (side){
	case 0 :
		if ( (ucMDiscInBuf[MB_offset_dirPTOC_Side1_Ia] & MB_b_dirError_Side1_Ia) &&
			 (ucMDiscInBuf[MB_offset_dirPTOC_Side1_Ib] & MB_b_dirError_Side1_Ib) &&
			 (ucMDiscInBuf[MB_offset_dirPTOC_Side1_Ic] & MB_b_dirError_Side1_Ic) ) {
				 ret = true;
			}
		break;
	case 1 :
		if ( (ucMDiscInBuf[MB_offset_dirPTOC_Side2_Ia] & MB_b_dirError_Side2_Ia) &&
			 (ucMDiscInBuf[MB_offset_dirPTOC_Side2_Ib] & MB_b_dirError_Side2_Ib) &&
			 (ucMDiscInBuf[MB_offset_dirPTOC_Side2_Ic] & MB_b_dirError_Side2_Ic) ) {
				 ret = true;
			}
		break;
	case 2 :
		if ( (ucMDiscInBuf[MB_offset_dirPTOC_Side3_Ia] & MB_b_dirError_Side3_Ia) &&
			 (ucMDiscInBuf[MB_offset_dirPTOC_Side3_Ib] & MB_b_dirError_Side3_Ib) &&
			 (ucMDiscInBuf[MB_offset_dirPTOC_Side3_Ic] & MB_b_dirError_Side3_Ic) ) {
				 ret = true;
			}
		break;
	}
return ret;
}
/*******************************************************
 * Set_IPTOC наполняем оперативными данными узлы IPTOC1...8
 *******************************************************/
int		Set_IPTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
//	uint16_t	num;
//	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
// -----------------------------------------------------------------------------
	int16_t	Valtmp1=0;
	int16_t	Valtmp2=0;
	int16_t	Valtmp3=0;
	int16_t	Valtmp4=0;
	int16_t	Valtmp5=0;
	int16_t	Valtmp6=0;
	int16_t	Valtmp7=0;
	int16_t	Valtmp8=0;

	uint8_t		Side;

	//Health
					uint32_t	Health = STVALINT32_OK;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM4)>0)	{Health = STVALINT32_Warning;}
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM5)>0)  {Health = STVALINT32_Warning;}
					if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}

					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Health_stVal, Health)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC7_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC7_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC8_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC8_Health_t, currentTime);
					}
		//  Mod Beh
					uint32_t	IPTOC_Mod;
					if ((ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Beh_t, currentTime);
					}

					if ((ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Beh_t, currentTime);
					}

					if ((ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Beh_t, currentTime);
					}

					if ((ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Beh_t, currentTime);
					}

					if ((ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Beh_t, currentTime);
					}

					if ((ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Beh_t, currentTime);
					}

					if ((ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC7_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC7_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC7_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC7_Beh_t, currentTime);
					}

					if ((ucMUstavkiInBuf[MB_offset_MTZ_I8 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC8_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC8_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC8_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC8_Beh_t, currentTime);
					}

		//  Quality (Mod Beh)
					quality = QUALITY_VALIDITY_GOOD;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorUstavki)>0) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Mod_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Beh_q,quality);
					}

		// Str_general

					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC1_Str_general,&iedModel_PROT_IPTOC1_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I1] & MB_b_IO_I1)>0);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC2_Str_general,&iedModel_PROT_IPTOC2_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I2] & MB_b_IO_I2)>0);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC3_Str_general,&iedModel_PROT_IPTOC3_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I3] & MB_b_IO_I3)>0);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC4_Str_general,&iedModel_PROT_IPTOC4_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I4] & MB_b_IO_I4)>0);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC5_Str_general,&iedModel_PROT_IPTOC5_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I5] & MB_b_IO_I5)>0);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC6_Str_general,&iedModel_PROT_IPTOC6_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I6] & MB_b_IO_I6)>0);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC7_Str_general,&iedModel_PROT_IPTOC7_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I7] & MB_b_IO_I7)>0);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC8_Str_general,&iedModel_PROT_IPTOC8_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_I8] & MB_b_IO_I8)>0);

		// Op_general
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC1_Op_general,&iedModel_PROT_IPTOC1_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I1] & MB_b_SRAB_I1)>0);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC2_Op_general,&iedModel_PROT_IPTOC2_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I2] & MB_b_SRAB_I2)>0);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC3_Op_general,&iedModel_PROT_IPTOC3_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I3] & MB_b_SRAB_I3)>0);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC4_Op_general,&iedModel_PROT_IPTOC4_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I4] & MB_b_SRAB_I4)>0);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC5_Op_general,&iedModel_PROT_IPTOC5_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I5] & MB_b_SRAB_I5)>0);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC6_Op_general,&iedModel_PROT_IPTOC6_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I6] & MB_b_SRAB_I6)>0);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC7_Op_general,&iedModel_PROT_IPTOC7_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I7] & MB_b_SRAB_I7)>0);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC8_Op_general,&iedModel_PROT_IPTOC8_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_I8] & MB_b_SRAB_I8)>0);

		// Str_dir_general				в зависимости от стороны

// IPTOC1
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp1 = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I1] & MB_b_IO_I1)>0){
					 if((   ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp1 = STVALCODEDENUM_FORWARD;
				else if((   ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp1 = STVALCODEDENUM_BACKWARD;
				else Valtmp1 = STVALCODEDENUM_UNKNOWN;
			} else Valtmp1 = STVALCODEDENUM_UNKNOWN;
		}

// IPTOC2
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp2 = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I2] & MB_b_IO_I2)>0){
					 if((   ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp2 = STVALCODEDENUM_FORWARD;
				else if((   ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp2 = STVALCODEDENUM_BACKWARD;
				else Valtmp2 = STVALCODEDENUM_UNKNOWN;
			} else Valtmp2 = STVALCODEDENUM_UNKNOWN;
		}

// IPTOC3
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp3 = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I3] & MB_b_IO_I3)>0){
					 if((   ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp3 = STVALCODEDENUM_FORWARD;
				else if((   ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp3 = STVALCODEDENUM_BACKWARD;
				else Valtmp3 = STVALCODEDENUM_UNKNOWN;
			} else Valtmp3 = STVALCODEDENUM_UNKNOWN;
		}

// IPTOC4
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp4 = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I4] & MB_b_IO_I4)>0){
					 if((ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp4 = STVALCODEDENUM_FORWARD;
				else if((ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp4 = STVALCODEDENUM_BACKWARD;
				else Valtmp4 = STVALCODEDENUM_UNKNOWN;
			} else Valtmp4 = STVALCODEDENUM_UNKNOWN;
		}

// IPTOC5
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp5 = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I5] & MB_b_IO_I5)>0){
					 if((ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp5 = STVALCODEDENUM_FORWARD;
				else if((ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp5 = STVALCODEDENUM_BACKWARD;
				else Valtmp5 = STVALCODEDENUM_UNKNOWN;
			} else Valtmp5 = STVALCODEDENUM_UNKNOWN;
		}

// IPTOC6
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp6 = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I6] & MB_b_IO_I6)>0){
					 if((ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp6 = STVALCODEDENUM_FORWARD;
				else if((ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp6 = STVALCODEDENUM_BACKWARD;
				else Valtmp6 = STVALCODEDENUM_UNKNOWN;
			} else Valtmp6 = STVALCODEDENUM_UNKNOWN;
		}
// IPTOC7
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp7 = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I7] & MB_b_IO_I7)>0){
					 if((ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp7 = STVALCODEDENUM_FORWARD;
				else if((ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp7 = STVALCODEDENUM_BACKWARD;
				else Valtmp7 = STVALCODEDENUM_UNKNOWN;
			} else Valtmp7 = STVALCODEDENUM_UNKNOWN;
		}
// IPTOC8
		Side = (ucMUstavkiInBuf[MB_offset_MTZ_I8 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
		if (getUNKNOWN_SidebldirIPTOC(Side)){
			Valtmp8 = STVALCODEDENUM_UNKNOWN;
		}else{
			if ((ucMDiscInBuf[MB_offset_IO_I8] & MB_b_IO_I8)>0){
					 if((ucMUstavkiInBuf[MB_offset_MTZ_I8 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp8 = STVALCODEDENUM_FORWARD;
				else if((ucMUstavkiInBuf[MB_offset_MTZ_I8 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp8 = STVALCODEDENUM_BACKWARD;
				else Valtmp8 = STVALCODEDENUM_UNKNOWN;
			} else Valtmp8 = STVALCODEDENUM_UNKNOWN;
		}

		if (T) {
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC1_Str_dirGeneral,&iedModel_PROT_IPTOC1_Str_t,currentTime, Valtmp1);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC2_Str_dirGeneral,&iedModel_PROT_IPTOC2_Str_t,currentTime, Valtmp2);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC3_Str_dirGeneral,&iedModel_PROT_IPTOC3_Str_t,currentTime, Valtmp3);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC4_Str_dirGeneral,&iedModel_PROT_IPTOC4_Str_t,currentTime, Valtmp4);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC5_Str_dirGeneral,&iedModel_PROT_IPTOC5_Str_t,currentTime, Valtmp5);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC6_Str_dirGeneral,&iedModel_PROT_IPTOC6_Str_t,currentTime, Valtmp6);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC7_Str_dirGeneral,&iedModel_PROT_IPTOC7_Str_t,currentTime, Valtmp7);
			IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC8_Str_dirGeneral,&iedModel_PROT_IPTOC8_Str_t,currentTime, Valtmp8);
		}else{
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_dirGeneral, Valtmp1))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_dirGeneral, Valtmp2))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_dirGeneral, Valtmp3))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_dirGeneral, Valtmp4))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_dirGeneral, Valtmp5))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_dirGeneral, Valtmp6))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC7_Str_dirGeneral, Valtmp7))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC7_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC8_Str_dirGeneral, Valtmp8))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC8_Str_t, currentTime);
		}

/*
					MmsValue* 	ValMMS;		//-----------
					uint8_t		Side;
					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC7_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I8 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC8_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);
*/
					quality = QUALITY_VALIDITY_GOOD;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM4)>0)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM5)>0)  {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Str_q,quality);

						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC7_Str_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC8_Str_t, currentTime);

						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Op_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Op_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Op_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Op_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Op_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC7_Op_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC8_Op_t, currentTime);
					}
return ret;
}

/*******************************************************
 * Set_I20PTOC наполняем оперативными данными узлы
 *******************************************************/
int		Set_I20PTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
//	uint16_t	num;
//	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
// -----------------------------------------------------------------------------
	uint16_t	Valtmp1=0;
	uint16_t	Valtmp2=0;
	uint16_t	Valtmp3=0;
	uint16_t	Valtmp4=0;
	uint16_t	Valtmp5=0;
	uint16_t	Valtmp6=0;

	uint16_t	g_Icfg;
	uint8_t		Side;
		//Health
					uint32_t	Health = STVALINT32_OK;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM4)>0) {Health = STVALINT32_Warning;}
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM5)>0) {Health = STVALINT32_Warning;}
					if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}

					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Health_stVal, Health)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Health_t, currentTime);
					}

		//  Mod Beh
					uint32_t	IPTOC_Mod;
					if ((ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Mod_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Beh_t, currentTime);
					}

					if ((ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Mod_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Beh_t, currentTime);
					}

					if ((ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Mod_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Beh_t, currentTime);
					}

					if ((ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Mod_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Beh_t, currentTime);
					}

					if ((ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Mod_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Beh_t, currentTime);
					}

					if ((ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Mod_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Beh_t, currentTime);
					}


		//  Quality (Mod Beh)
					quality = QUALITY_VALIDITY_GOOD;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorUstavki)>0) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					if (IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Mod_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Beh_q,quality);

						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Mod_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Beh_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Mod_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Beh_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Mod_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Beh_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Mod_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Beh_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Mod_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Beh_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Mod_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Beh_t,currentTime);

					}


					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC1_Str_general,&iedModel_PROT_I20PTOC1_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_Ig1] & MB_b_IO_Ig1)>0);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC2_Str_general,&iedModel_PROT_I20PTOC2_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_Ig2] & MB_b_IO_Ig2)>0);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC3_Str_general,&iedModel_PROT_I20PTOC3_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_Ig3] & MB_b_IO_Ig3)>0);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC4_Str_general,&iedModel_PROT_I20PTOC4_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_Ig4] & MB_b_IO_Ig4)>0);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC5_Str_general,&iedModel_PROT_I20PTOC5_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_Ig5] & MB_b_IO_Ig5)>0);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC6_Str_general,&iedModel_PROT_I20PTOC6_Str_t, currentTime,  (ucMDiscInBuf[MB_offset_IO_Ig6] & MB_b_IO_Ig6)>0);

					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC1_Op_general,&iedModel_PROT_I20PTOC1_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_Ig1] & MB_b_SRAB_Ig1)>0);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC2_Op_general,&iedModel_PROT_I20PTOC2_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_Ig2] & MB_b_SRAB_Ig2)>0);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC3_Op_general,&iedModel_PROT_I20PTOC3_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_Ig3] & MB_b_SRAB_Ig3)>0);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC4_Op_general,&iedModel_PROT_I20PTOC4_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_Ig4] & MB_b_SRAB_Ig4)>0);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC5_Op_general,&iedModel_PROT_I20PTOC5_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_Ig5] & MB_b_SRAB_Ig5)>0);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC6_Op_general,&iedModel_PROT_I20PTOC6_Op_t, currentTime,  (ucMDiscInBuf[MB_offset_SRAB_Ig6] & MB_b_SRAB_Ig6)>0);

/*
		// Str_general
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_1] & MB_b_IO_Ig1) > 0)			// И0 I>1
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_2] & MB_b_IO_Ig2) > 0)			// И0 I>2
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_3] & MB_b_IO_Ig3) > 0)			// И0 I>3
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_4] & MB_b_IO_Ig4) > 0)			// И0 I>4
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_5] & MB_b_IO_Ig5) > 0)			// И0 I>5
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_6] & MB_b_IO_Ig6) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_t, currentTime);

		// Op_general
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_1] & MB_b_SRAB_Ig1) > 0)		// СРАБ I>1
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_2] & MB_b_SRAB_Ig2) > 0)		// СРАБ I>2
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_3] & MB_b_SRAB_Ig3) > 0)		// СРАБ I>3
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_4] & MB_b_SRAB_Ig4) > 0)		// СРАБ I>4
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_5] & MB_b_SRAB_Ig5) > 0)		// СРАБ I>5
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_6] & MB_b_SRAB_Ig6) > 0)		// СРАБ I>6
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Op_t, currentTime);
*/
// Str_dir_general				в зависимости от стороны
					// I20PTOC1 -----------------------------------------
					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					if ((ucMDiscInBuf[MB_offset_IO_Ig1] & MB_b_IO_Ig1)>0){
							 if((ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up)>0) Valtmp1 = STVALCODEDENUM_FORWARD;
						else if((ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn)>0) Valtmp1 = STVALCODEDENUM_BACKWARD;
						else Valtmp1 = STVALCODEDENUM_UNKNOWN;
					} else Valtmp1 = STVALCODEDENUM_UNKNOWN;
					g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
					GetSidebleDirGeneralUnknoun(Side,g_Icfg,&Valtmp1);

					// I20PTOC2 -----------------------------------------
					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					if ((ucMDiscInBuf[MB_offset_IO_Ig2] & MB_b_IO_Ig2)>0){
							 if((ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up)>0) Valtmp2 = STVALCODEDENUM_FORWARD;
						else if((ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn)>0) Valtmp2 = STVALCODEDENUM_BACKWARD;
						else Valtmp2 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp2 = STVALCODEDENUM_UNKNOWN;
					g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
					GetSidebleDirGeneralUnknoun(Side,g_Icfg,&Valtmp2);
					// I20PTOC3
					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					if ((ucMDiscInBuf[MB_offset_IO_Ig3] & MB_b_IO_Ig3)>0){
							 if((ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up)>0) Valtmp3 = STVALCODEDENUM_FORWARD;
						else if((ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn)>0) Valtmp3 = STVALCODEDENUM_BACKWARD;
						else Valtmp3 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp3 = STVALCODEDENUM_UNKNOWN;
					g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
					GetSidebleDirGeneralUnknoun(Side,g_Icfg,&Valtmp3);
					// I20PTOC4
					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					if ((ucMDiscInBuf[MB_offset_IO_Ig4] & MB_b_IO_Ig4)>0){
							 if((ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up)>0) Valtmp4 = STVALCODEDENUM_FORWARD;
						else if((ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn)>0) Valtmp4 = STVALCODEDENUM_BACKWARD;
						else Valtmp4 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp4 = STVALCODEDENUM_UNKNOWN;
					g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
					GetSidebleDirGeneralUnknoun(Side,g_Icfg,&Valtmp4);
					// I20PTOC5
					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					if ((ucMDiscInBuf[MB_offset_IO_Ig5] & MB_b_IO_Ig5)>0){
							 if((ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up)>0) Valtmp5 = STVALCODEDENUM_FORWARD;
						else if((ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn)>0) Valtmp5 = STVALCODEDENUM_BACKWARD;
						else Valtmp5 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp5 = STVALCODEDENUM_UNKNOWN;
					g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
					GetSidebleDirGeneralUnknoun(Side,g_Icfg,&Valtmp5);
					// I20PTOC6
					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					if ((ucMDiscInBuf[MB_offset_IO_Ig6] & MB_b_IO_Ig6)>0){
							 if((ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up)>0) Valtmp6 = STVALCODEDENUM_FORWARD;
						else if((ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn)>0) Valtmp6 = STVALCODEDENUM_BACKWARD;
						else Valtmp6 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp6 = STVALCODEDENUM_UNKNOWN;
					g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
					GetSidebleDirGeneralUnknoun(Side,g_Icfg,&Valtmp6);


					if (T) {
						IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC1_Str_dirGeneral,&iedModel_PROT_I20PTOC1_Str_t,currentTime, Valtmp1);
						IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC2_Str_dirGeneral,&iedModel_PROT_I20PTOC2_Str_t,currentTime, Valtmp2);
						IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC3_Str_dirGeneral,&iedModel_PROT_I20PTOC3_Str_t,currentTime, Valtmp3);
						IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC4_Str_dirGeneral,&iedModel_PROT_I20PTOC4_Str_t,currentTime, Valtmp4);
						IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC5_Str_dirGeneral,&iedModel_PROT_I20PTOC5_Str_t,currentTime, Valtmp5);
						IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC6_Str_dirGeneral,&iedModel_PROT_I20PTOC6_Str_t,currentTime, Valtmp6);

					}else{
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_dirGeneral, Valtmp1))
						  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_dirGeneral, Valtmp2))
						  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_dirGeneral, Valtmp3))
						  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_dirGeneral, Valtmp4))
						  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_dirGeneral, Valtmp5))
						  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_dirGeneral, Valtmp6))
						  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_t, currentTime);
					}
/*
					MmsValue* 	ValMMS;		//-----------
					uint8_t		Side,Logic;
					uint8_t		DirGeneral;

					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					Logic		= (ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Logic) >> _bLogicOffset;
					DirGeneral	= GetDirGeneralInSideLogic(Side,Logic);
					ValMMS = MmsValue_newIntegerFromInt16(DirGeneral);
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					Logic		= (ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Logic) >> _bLogicOffset;
					DirGeneral	= GetDirGeneralInSideLogic(Side,Logic);
					ValMMS = MmsValue_newIntegerFromInt16(DirGeneral);
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					Logic		= (ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Logic) >> _bLogicOffset;
					DirGeneral	= GetDirGeneralInSideLogic(Side,Logic);
					ValMMS = MmsValue_newIntegerFromInt16(DirGeneral);
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					Logic		= (ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Logic) >> _bLogicOffset;
					DirGeneral	= GetDirGeneralInSideLogic(Side,Logic);
					ValMMS = MmsValue_newIntegerFromInt16(DirGeneral);
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					Logic		= (ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Logic) >> _bLogicOffset;
					DirGeneral	= GetDirGeneralInSideLogic(Side,Logic);
					ValMMS = MmsValue_newIntegerFromInt16(DirGeneral);
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					Logic		= (ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Logic) >> _bLogicOffset;
					DirGeneral	= GetDirGeneralInSideLogic(Side,Logic);
					ValMMS = MmsValue_newIntegerFromInt16(DirGeneral);
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);
*/

					quality = QUALITY_VALIDITY_GOOD;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM4)>0)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM5)>0)  {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					if (IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Str_q,quality);

						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Op_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Str_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Op_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Str_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Op_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Str_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Op_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Str_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Op_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Str_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Op_t,currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Str_t,currentTime);
					}
return ret;
}

/*******************************************************
 * Set_LZSHPTOC наполняем оперативными данными
 *******************************************************/
int		Set_LZSHPTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int		ret = false;
	uint32_t	Mod;
	Quality 	quality;
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM4) 		{Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM5) 		{Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LZSHPTOC_Health_t, currentTime);

	//  Mod Beh
				if ((ucConfigAWRBuf[MB_offset_ConfLZSHAWR] & MB_bOffset_LZSH_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LZSHPTOC_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LZSHPTOC_Beh_t, currentTime);
				}

	//  Quality (Mod Beh)
				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_LZSHPTOC_Mod_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_LZSHPTOC_Beh_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Mod_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Beh_t, currentTime);
				}

	// Str_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Str_general,  ucMDiscInBuf[MB_offset_LZSH] & MB_b_Rab_LZSH))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Str_t, currentTime);

	// Op_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Op_general,  ucMDiscInBuf[MB_offset_LZSH] & MB_b_Rab_LZSH))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Op_t, currentTime);

				quality = QUALITY_VALIDITY_GOOD;
				if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM4)>0)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM5)>0)  {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_LZSHPTOC_Op_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_LZSHPTOC_Str_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Op_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Str_t, currentTime);
				}
return ret;
}
#endif
/*******************************************************
 * MR761OBR
 *******************************************************/
#if defined (MR761OBR)
/*******************************************************
 * заглушки
 *******************************************************/
int			Set_IPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IPTUC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I2PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I0PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I20PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_INPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IGPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I2I1PTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_LZSHPTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IARCPTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}

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

extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];
extern uint16_t   ucMUstavkiInBuf[MB_Size_Ustavki];


/*******************************************************
 * заглушки
 *******************************************************/
#if defined	(MR771)
int			Set_IARCPTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}
#endif

int			Set_I2PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I0PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_INPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IGPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_LZSHPTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}


/*******************************************************
 * Set_IPTOC наполняем оперативными данными узлы IPTOC1...8
 *******************************************************/
int		Set_IPTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
//	if(num > MB_MaxNumbVZ)	return ret;
// -----------------------------------------------------------------------------
	int16_t	Valtmp1=0;
	int16_t	Valtmp2=0;
	int16_t	Valtmp3=0;
	int16_t	Valtmp4=0;
	int16_t	Valtmp5=0;
	int16_t	Valtmp6=0;


		//Health
					uint32_t	Health = STVALINT32_OK;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM5)) {Health = STVALINT32_Warning;}
					if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}

					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Health_stVal, Health)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Health_t, currentTime);
					}

		//  Mod Beh
					uint32_t	IPTOC_Mod;
					if (ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Mod_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Beh_stVal, IPTOC_Mod))
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Mod_stVal, IPTOC_Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Mod_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Beh_stVal, IPTOC_Mod))
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Beh_t, currentTime);
					}


		//  Quality (Mod Beh)
					quality = QUALITY_VALIDITY_GOOD;
					if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					if(IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Mod_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Beh_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Mod_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Beh_q,quality);
					}


		// Str_general

					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC1_Str_general,&iedModel_PROT_IPTOC1_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_I_1] & MB_b_IO_I1);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC2_Str_general,&iedModel_PROT_IPTOC2_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_I_2] & MB_b_IO_I2);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC3_Str_general,&iedModel_PROT_IPTOC3_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_I_3] & MB_b_IO_I3);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC4_Str_general,&iedModel_PROT_IPTOC4_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_I_4] & MB_b_IO_I4);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC5_Str_general,&iedModel_PROT_IPTOC5_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_I_5] & MB_b_IO_I5);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC6_Str_general,&iedModel_PROT_IPTOC6_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_I_6] & MB_b_IO_I6);
		// Op_general

					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC1_Op_general,&iedModel_PROT_IPTOC1_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_I_1] & MB_b_SRAB_I1);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC2_Op_general,&iedModel_PROT_IPTOC2_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_I_2] & MB_b_SRAB_I2);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC3_Op_general,&iedModel_PROT_IPTOC3_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_I_3] & MB_b_SRAB_I3);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC4_Op_general,&iedModel_PROT_IPTOC4_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_I_4] & MB_b_SRAB_I4);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC5_Op_general,&iedModel_PROT_IPTOC5_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_I_5] & MB_b_SRAB_I5);
					IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC6_Op_general,&iedModel_PROT_IPTOC6_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_I_6] & MB_b_SRAB_I6);

		// Str_dir_general
					{

					if ( (ucMDiscInBuf[MB_offset_dirPTOC_Ia] & MB_b_dirError_Ia) &&
						 (ucMDiscInBuf[MB_offset_dirPTOC_Ib] & MB_b_dirError_Ib) &&
						 (ucMDiscInBuf[MB_offset_dirPTOC_Ic] & MB_b_dirError_Ic) ) {
						Valtmp1 = STVALCODEDENUM_UNKNOWN;
						Valtmp2 = STVALCODEDENUM_UNKNOWN;
						Valtmp3 = STVALCODEDENUM_UNKNOWN;
						Valtmp4 = STVALCODEDENUM_UNKNOWN;
						Valtmp5 = STVALCODEDENUM_UNKNOWN;
						Valtmp6 = STVALCODEDENUM_UNKNOWN;
					}
					else {
						// IPTOC1
						if (ucMDiscInBuf[MB_offset_IO_I_1] & MB_b_IO_I1){
							if(   ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up) Valtmp1 = STVALCODEDENUM_FORWARD;
							else if(   ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn) Valtmp1 = STVALCODEDENUM_BACKWARD;
							else Valtmp1 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
						} else Valtmp1 = STVALCODEDENUM_UNKNOWN;
						// IPTOC2
						if (ucMDiscInBuf[MB_offset_IO_I_2] & MB_b_IO_I2){
							if(   ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up) Valtmp2 = STVALCODEDENUM_FORWARD;
							else if(   ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn) Valtmp2 = STVALCODEDENUM_BACKWARD;
							else Valtmp2 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
						} else Valtmp2 = STVALCODEDENUM_UNKNOWN;
						// IPTOC3
						if (ucMDiscInBuf[MB_offset_IO_I_3] & MB_b_IO_I3){
							if(   ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up) Valtmp3 = STVALCODEDENUM_FORWARD;
							else if(   ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn) Valtmp3 = STVALCODEDENUM_BACKWARD;
							else Valtmp3 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
						} else Valtmp3 = STVALCODEDENUM_UNKNOWN;
						// IPTOC4
						if (ucMDiscInBuf[MB_offset_IO_I_4] & MB_b_IO_I4){
							if(   ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up) Valtmp4 = STVALCODEDENUM_FORWARD;
							else if(   ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn) Valtmp4 = STVALCODEDENUM_BACKWARD;
							else Valtmp4 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
						} else Valtmp4 = STVALCODEDENUM_UNKNOWN;
						// IPTOC5
						if (ucMDiscInBuf[MB_offset_IO_I_5] & MB_b_IO_I5){
							if(   ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up) Valtmp5 = STVALCODEDENUM_FORWARD;
							else if(   ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn) Valtmp5 = STVALCODEDENUM_BACKWARD;
							else Valtmp5 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
						} else Valtmp5 = STVALCODEDENUM_UNKNOWN;
						// IPTOC6
						if (ucMDiscInBuf[MB_offset_IO_I_6] & MB_b_IO_I6){
							if(   ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up) Valtmp6 = STVALCODEDENUM_FORWARD;
							else if(   ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn) Valtmp6 = STVALCODEDENUM_BACKWARD;
							else Valtmp6 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
						} else Valtmp6 = STVALCODEDENUM_UNKNOWN;
					}

						if (T) {
							IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC1_Str_dirGeneral,&iedModel_PROT_IPTOC1_Str_t,currentTime, Valtmp1);
							IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC2_Str_dirGeneral,&iedModel_PROT_IPTOC2_Str_t,currentTime, Valtmp2);
							IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC3_Str_dirGeneral,&iedModel_PROT_IPTOC3_Str_t,currentTime, Valtmp3);
							IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC4_Str_dirGeneral,&iedModel_PROT_IPTOC4_Str_t,currentTime, Valtmp4);
							IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC5_Str_dirGeneral,&iedModel_PROT_IPTOC5_Str_t,currentTime, Valtmp5);
							IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_IPTOC6_Str_dirGeneral,&iedModel_PROT_IPTOC6_Str_t,currentTime, Valtmp6);
						}else{
							if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_dirGeneral, Valtmp1))
							  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);
							if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_dirGeneral, Valtmp2))
							  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_t, currentTime);
							if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_dirGeneral, Valtmp3))
							  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_t, currentTime);
							if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_dirGeneral, Valtmp4))
							  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_t, currentTime);
							if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_dirGeneral, Valtmp5))
							  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_t, currentTime);
							if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_dirGeneral, Valtmp6))
							  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_t, currentTime);
						}
					}

					if (Health == STVALINT32_Warning){
						quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
					}

					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Str_q,quality);

						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_t, currentTime);

						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Op_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Op_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Op_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Op_t, currentTime);
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Op_t, currentTime);

					}


}

/*******************************************************
 * Set_I20PTOC наполняем оперативными данными узлы IPTOC1...8
 *******************************************************/
int		Set_I20PTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
	uint16_t	Valtmp1=0;
	uint16_t	Valtmp2=0;
	uint16_t	Valtmp3=0;
	uint16_t	Valtmp4=0;
	uint16_t	Valtmp5=0;
	uint16_t	Valtmp6=0;
	uint16_t	Valtmp7=0;
	uint16_t	Valtmp8=0;

	uint16_t	g_Icfg;
		//Health
					uint32_t	Health = STVALINT32_OK;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM5)) {Health = STVALINT32_Warning;}
					if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki) {Health = STVALINT32_Warning;}

					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Health_stVal, Health)){

						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Health_stVal, Health))
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Health_stVal, Health))
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Health_stVal, Health))
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Health_stVal, Health))
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Health_stVal, Health))
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Health_stVal, Health))
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC7_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Health_stVal, Health))
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC8_Health_t, currentTime);
					}
		//  Mod Beh
					uint32_t	IPTOC_Mod;
					if (ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_Ig_I7 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC7_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC7_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_Ig_I8 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC8_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC8_Beh_t, currentTime);
					}



		//  Quality (Mod Beh)

					int	Qual = QUALITY_VALIDITY_GOOD;
					if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Beh_q,Qual);
					//IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Beh_q,Qual);
					//IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Beh_q,Qual);
					//IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Beh_q,Qual);
					//IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Beh_q,Qual);
					//IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Beh_q,Qual);
					//IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Beh_q,Qual);
					//IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Beh_q,Qual);
					//IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Health_q,Qual);

// Str_general

					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC1_Str_general,&iedModel_PROT_I20PTOC1_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_Ig_1] & MB_b_IO_Ig1);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC2_Str_general,&iedModel_PROT_I20PTOC2_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_Ig_2] & MB_b_IO_Ig2);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC3_Str_general,&iedModel_PROT_I20PTOC3_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_Ig_3] & MB_b_IO_Ig3);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC4_Str_general,&iedModel_PROT_I20PTOC4_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_Ig_4] & MB_b_IO_Ig4);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC5_Str_general,&iedModel_PROT_I20PTOC5_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_Ig_5] & MB_b_IO_Ig5);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC6_Str_general,&iedModel_PROT_I20PTOC6_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_Ig_6] & MB_b_IO_Ig6);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC7_Str_general,&iedModel_PROT_I20PTOC7_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_Ig_7] & MB_b_IO_Ig7);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC8_Str_general,&iedModel_PROT_I20PTOC8_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_Ig_8] & MB_b_IO_Ig8);

					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC1_Op_general,&iedModel_PROT_I20PTOC1_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_Ig_1] & MB_b_SRAB_Ig1);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC2_Op_general,&iedModel_PROT_I20PTOC2_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_Ig_2] & MB_b_SRAB_Ig2);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC3_Op_general,&iedModel_PROT_I20PTOC3_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_Ig_3] & MB_b_SRAB_Ig3);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC4_Op_general,&iedModel_PROT_I20PTOC4_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_Ig_4] & MB_b_SRAB_Ig4);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC5_Op_general,&iedModel_PROT_I20PTOC5_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_Ig_5] & MB_b_SRAB_Ig5);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC6_Op_general,&iedModel_PROT_I20PTOC6_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_Ig_6] & MB_b_SRAB_Ig6);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC7_Op_general,&iedModel_PROT_I20PTOC7_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_Ig_7] & MB_b_SRAB_Ig7);
					ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC8_Op_general,&iedModel_PROT_I20PTOC8_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_Ig_8] & MB_b_SRAB_Ig8);

/*

					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_1] & MB_b_IO_Ig1) > 0)			// И0 I>1
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_2] & MB_b_IO_Ig2) > 0)			// И0 I>2
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_3] & MB_b_IO_Ig3) > 0)			// И0 I>3
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_4] & MB_b_IO_Ig4) > 0)			// И0 I>4
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_5] & MB_b_IO_Ig5) > 0)			// И0 I>5
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_6] & MB_b_IO_Ig6) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_7] & MB_b_IO_Ig7) > 0)			// И0 I>7
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_8] & MB_b_IO_Ig8) > 0)			// И0 I>8
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Str_t, currentTime);

		// Op_general
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_1] & MB_b_SRAB_Ig1) > 0)		// СРАБ I>1
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_2] & MB_b_SRAB_Ig2) > 0)		// СРАБ I>2
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_3] & MB_b_SRAB_Ig3) > 0)		// СРАБ I>3
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_4] & MB_b_SRAB_Ig4) > 0)		// СРАБ I>4
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_5] & MB_b_SRAB_Ig5) > 0)		// СРАБ I>5
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_6] & MB_b_SRAB_Ig6) > 0)		// СРАБ I>6
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_7] & MB_b_SRAB_Ig7) > 0)		// СРАБ I>6
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_8] & MB_b_SRAB_Ig8) > 0)		// СРАБ I>6
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Op_t, currentTime);
*/
		// Str_dir_general
					{

					// I20PTOC1 -----------------------------------------
					if (ucMDiscInBuf[MB_offset_IO_Ig_1] & MB_b_IO_Ig1){
						if(   ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp1 = STVALCODEDENUM_FORWARD;
						else if(   ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp1 = STVALCODEDENUM_BACKWARD;
						else Valtmp1 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp1 = STVALCODEDENUM_UNKNOWN;
					g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
					GetDirGeneralUnknoun(g_Icfg,&Valtmp1);
					/*
					if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_I2){
						if (ucMDiscInBuf[MB_offset_dirErrorPTOC_I2] & MB_b_dirError_I2)	Valtmp1 = STVALCODEDENUM_UNKNOWN;
					}else
					if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_I0){
						if (ucMDiscInBuf[MB_offset_dirErrorPTOC_I0] & MB_b_dirError_I0)	Valtmp1 = STVALCODEDENUM_UNKNOWN;
					}else
					if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_In){
						if (ucMDiscInBuf[MB_offset_dirErrorPTOC_In] & MB_b_dirError_In)	Valtmp1 = STVALCODEDENUM_UNKNOWN;
					}else
					if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_Ig){
						Valtmp1 = STVALCODEDENUM_UNKNOWN;
					}
					*/
					// I20PTOC2 -----------------------------------------
					if (ucMDiscInBuf[MB_offset_IO_Ig_2] & MB_b_IO_Ig2){
						if(   ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp2 = STVALCODEDENUM_FORWARD;
						else if(   ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp2 = STVALCODEDENUM_BACKWARD;
						else Valtmp2 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp2 = STVALCODEDENUM_UNKNOWN;
					g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
					GetDirGeneralUnknoun(g_Icfg,&Valtmp2);
					// I20PTOC3
					if (ucMDiscInBuf[MB_offset_IO_Ig_3] & MB_b_IO_Ig3){
						if(   ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp3 = STVALCODEDENUM_FORWARD;
						else if(   ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp3 = STVALCODEDENUM_BACKWARD;
						else Valtmp3 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp3 = STVALCODEDENUM_UNKNOWN;
					g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
					GetDirGeneralUnknoun(g_Icfg,&Valtmp3);
					// I20PTOC4
					if (ucMDiscInBuf[MB_offset_IO_Ig_4] & MB_b_IO_Ig4){
						if(   ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp4 = STVALCODEDENUM_FORWARD;
						else if(   ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp4 = STVALCODEDENUM_BACKWARD;
						else Valtmp4 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp4 = STVALCODEDENUM_UNKNOWN;
					g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
					GetDirGeneralUnknoun(g_Icfg,&Valtmp4);
					// I20PTOC5
					if (ucMDiscInBuf[MB_offset_IO_Ig_5] & MB_b_IO_Ig5){
						if(   ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp5 = STVALCODEDENUM_FORWARD;
						else if(   ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp5 = STVALCODEDENUM_BACKWARD;
						else Valtmp5 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp5 = STVALCODEDENUM_UNKNOWN;
					g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
					GetDirGeneralUnknoun(g_Icfg,&Valtmp5);
					// I20PTOC6
					if (ucMDiscInBuf[MB_offset_IO_Ig_6] & MB_b_IO_Ig6){
						if(   ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp6 = STVALCODEDENUM_FORWARD;
						else if(   ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp6 = STVALCODEDENUM_BACKWARD;
						else Valtmp6 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp6 = STVALCODEDENUM_UNKNOWN;
					g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
					GetDirGeneralUnknoun(g_Icfg,&Valtmp6);
					// I20PTOC7
					if (ucMDiscInBuf[MB_offset_IO_Ig_7] & MB_b_IO_Ig7){
						if(   ucMUstavkiInBuf[MB_offset_Ig_I7 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp7 = STVALCODEDENUM_FORWARD;
						else if(   ucMUstavkiInBuf[MB_offset_Ig_I7 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp7 = STVALCODEDENUM_BACKWARD;
						else Valtmp7 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp7 = STVALCODEDENUM_UNKNOWN;
					g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I7 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
					GetDirGeneralUnknoun(g_Icfg,&Valtmp7);
					// I20PTOC6
					if (ucMDiscInBuf[MB_offset_IO_Ig_8] & MB_b_IO_Ig8){
						if(   ucMUstavkiInBuf[MB_offset_Ig_I8 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp8 = STVALCODEDENUM_FORWARD;
						else if(   ucMUstavkiInBuf[MB_offset_Ig_I8 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp8 = STVALCODEDENUM_BACKWARD;
						else Valtmp8 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp8 = STVALCODEDENUM_UNKNOWN;
					g_Icfg = ((ucMUstavkiInBuf[MB_offset_Ig_I8 + MB_offset_Ig_I_Config] >> MB_bOffset_Ig_I_Config_src_move) & 0b11);
					GetDirGeneralUnknoun(g_Icfg,&Valtmp8);

/*
					if ( (ucMDiscInBuf[MB_offset_dirPTOC_Ia] & MB_b_dirError_Ia) &&
						 (ucMDiscInBuf[MB_offset_dirPTOC_Ib] & MB_b_dirError_Ib) &&
						 (ucMDiscInBuf[MB_offset_dirPTOC_Ic] & MB_b_dirError_Ic) ) {
						Valtmp1 = STVALCODEDENUM_UNKNOWN;
						Valtmp2 = STVALCODEDENUM_UNKNOWN;
						Valtmp3 = STVALCODEDENUM_UNKNOWN;
						Valtmp4 = STVALCODEDENUM_UNKNOWN;
						Valtmp5 = STVALCODEDENUM_UNKNOWN;
						Valtmp6 = STVALCODEDENUM_UNKNOWN;
						Valtmp7 = STVALCODEDENUM_UNKNOWN;
						Valtmp8 = STVALCODEDENUM_UNKNOWN;
					}
					else {
						// I20PTOC1
						if (ucMDiscInBuf[MB_offset_IO_Ig_1] & MB_b_IO_Ig1){
							if(   ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp1 = STVALCODEDENUM_FORWARD;
							else if(   ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp1 = STVALCODEDENUM_BACKWARD;
							else Valtmp1 = STVALCODEDENUM_BOTH;
						} else Valtmp1 = STVALCODEDENUM_UNKNOWN;
						// I20PTOC2
						if (ucMDiscInBuf[MB_offset_IO_Ig_2] & MB_b_IO_Ig2){
							if(   ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp2 = STVALCODEDENUM_FORWARD;
							else if(   ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp2 = STVALCODEDENUM_BACKWARD;
							else Valtmp2 = STVALCODEDENUM_BOTH;
						} else Valtmp2 = STVALCODEDENUM_UNKNOWN;
						// I20PTOC3
						if (ucMDiscInBuf[MB_offset_IO_Ig_3] & MB_b_IO_Ig3){
							if(   ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp3 = STVALCODEDENUM_FORWARD;
							else if(   ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp3 = STVALCODEDENUM_BACKWARD;
							else Valtmp3 = STVALCODEDENUM_BOTH;
						} else Valtmp3 = STVALCODEDENUM_UNKNOWN;
						// I20PTOC4
						if (ucMDiscInBuf[MB_offset_IO_Ig_4] & MB_b_IO_Ig4){
							if(   ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp4 = STVALCODEDENUM_FORWARD;
							else if(   ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp4 = STVALCODEDENUM_BACKWARD;
							else Valtmp4 = STVALCODEDENUM_BOTH;
						} else Valtmp4 = STVALCODEDENUM_UNKNOWN;
						// I20PTOC5
						if (ucMDiscInBuf[MB_offset_IO_Ig_5] & MB_b_IO_Ig5){
							if(   ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp5 = STVALCODEDENUM_FORWARD;
							else if(   ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp5 = STVALCODEDENUM_BACKWARD;
							else Valtmp5 = STVALCODEDENUM_BOTH;
						} else Valtmp5 = STVALCODEDENUM_UNKNOWN;
						// I20PTOC6
						if (ucMDiscInBuf[MB_offset_IO_Ig_6] & MB_b_IO_Ig6){
							if(   ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp6 = STVALCODEDENUM_FORWARD;
							else if(   ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp6 = STVALCODEDENUM_BACKWARD;
							else Valtmp6 = STVALCODEDENUM_BOTH;
						} else Valtmp6 = STVALCODEDENUM_UNKNOWN;
						// I20PTOC7
						if (ucMDiscInBuf[MB_offset_IO_Ig_7] & MB_b_IO_Ig7){
							if(   ucMUstavkiInBuf[MB_offset_Ig_I7 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp7 = STVALCODEDENUM_FORWARD;
							else if(   ucMUstavkiInBuf[MB_offset_Ig_I7 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp7 = STVALCODEDENUM_BACKWARD;
							else Valtmp7 = STVALCODEDENUM_BOTH;
						} else Valtmp7 = STVALCODEDENUM_UNKNOWN;
						// I20PTOC6
						if (ucMDiscInBuf[MB_offset_IO_Ig_8] & MB_b_IO_Ig8){
							if(   ucMUstavkiInBuf[MB_offset_Ig_I8 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_up) Valtmp8 = STVALCODEDENUM_FORWARD;
							else if(   ucMUstavkiInBuf[MB_offset_Ig_I8 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Napravl_dn) Valtmp8 = STVALCODEDENUM_BACKWARD;
							else Valtmp8 = STVALCODEDENUM_BOTH;
						} else Valtmp8 = STVALCODEDENUM_UNKNOWN;
					}
*/

//					ret |= IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_PROT_I20PTOC1_Str_dirGeneral,&iedModel_PROT_I20PTOC1_Str_t, currentTime,Valtmp1);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_dirGeneral, Valtmp1))
					  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_dirGeneral, Valtmp2))
					  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_dirGeneral, Valtmp3))
					  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_dirGeneral, Valtmp4))
					  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_dirGeneral, Valtmp5))
					  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_dirGeneral, Valtmp6))
					  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Str_dirGeneral, Valtmp7))
					  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Str_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Str_dirGeneral, Valtmp8))
					  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Str_t, currentTime);
					}


					Quality quality = QUALITY_VALIDITY_GOOD;
					if (Health == STVALINT32_Warning){
						quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
					}

					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Str_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Str_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Str_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Str_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Str_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Str_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Str_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Str_q,quality);
}
/*******************************************************
 * Set_IPTUC наполняем оперативными данными узлы IPTUC1
 *******************************************************/
int		Set_IPTUC	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
	//Health
				uint32_t	Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM5)) {Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTUC1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTUC1_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTUC1_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTUC1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTUC1_Beh_stVal, Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTUC1_Beh_t, currentTime);
				}

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTUC1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTUC1_Beh_q,Qual);

	// Str_general	// Op_general
				ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTUC1_Str_general,&iedModel_PROT_IPTUC1_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_I_7] & MB_b_IO_I7);
				ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IPTUC1_Op_general,&iedModel_PROT_IPTUC1_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_I_7] & MB_b_SRAB_I7);

				/*
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTUC1_Str_general,  (ucMDiscInBuf[MB_offset_IO_I_7] & MB_b_IO_I7)>0)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTUC1_Str_t, currentTime);
					ret = true;
				}
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTUC1_Op_general,  (ucMDiscInBuf[MB_offset_SRAB_I_7] & MB_b_SRAB_I7)>0)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTUC1_Op_t, currentTime);
					ret = true;
				}
*/
				Quality quality = QUALITY_VALIDITY_GOOD;
				if (Health == STVALINT32_Warning){
					quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
				}
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTUC1_Str_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTUC1_Op_q,quality);

return	ret;
}
/*******************************************************
 * Set_I2I1PTOC наполняем оперативными данными узлы Set_I2I1PTOC
 *******************************************************/
int		Set_I2I1PTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
	//Health
				uint32_t	Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)) {Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2I1PTOC1_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_StartConfigI2I1] & MB_bOffset_I2I1_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2I1PTOC1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2I1PTOC1_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC1_Beh_q,Qual);

				ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I2I1PTOC1_Str_general,&iedModel_PROT_I2I1PTOC1_Str_t, currentTime,  ucMDiscInBuf[MB_offset_IO_I2I1] & MB_b_IO_I2I1);
				ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_I2I1PTOC1_Op_general,&iedModel_PROT_I2I1PTOC1_Op_t, currentTime,  ucMDiscInBuf[MB_offset_SRAB_I2I1] & MB_b_SRAB_I2I1);
/*
// Str_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Str_general,  (ucMDiscInBuf[MB_offset_IO_I2I1] & MB_b_IO_I2I1)>0)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Str_t, currentTime);
					ret = true;
				}
	// Op_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Op_general,  (ucMDiscInBuf[MB_offset_SRAB_I2I1] & MB_b_SRAB_I2I1)>0)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Op_t, currentTime);
					ret = true;
				}
*/
				Quality quality = QUALITY_VALIDITY_GOOD;
				if (Health == STVALINT32_Warning){
					quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
				}

				IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC1_Op_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC1_Str_q,quality);

return ret;
}
#if defined	(MR761) || defined	(MR762) || defined	(MR763)
/*******************************************************
 * пуск дуговой
 * Set_IARCPTOC наполняем оперативными данными узлы Set_IARCPTOC
 *******************************************************/
int		Set_IARCPTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
	//Health
				uint32_t	Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)) {Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IARCPTOC_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IARCPTOC_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_StartConfigARC] & MB_bOffset_ARC_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IARCPTOC_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IARCPTOC_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IARCPTOC_Beh_stVal, Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IARCPTOC_Beh_t, currentTime);
				}

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_IARCPTOC_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IARCPTOC_Beh_q,Qual);

	// Str_general
				bool dat = false;
					if ((ucMDiscInBuf[MB_offset_Pusk_ARC] & MB_b_Pusk_ARC) > 0) dat = true; else dat = false;

				ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IARCPTOC_Str_general,&iedModel_PROT_IARCPTOC_Str_t, currentTime, dat);
				ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_PROT_IARCPTOC_Op_general,&iedModel_PROT_IARCPTOC_Op_t, currentTime, dat);

/*
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IARCPTOC_Str_general,  dat)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IARCPTOC_Str_t, currentTime);
					ret = true;
				}
	// Op_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IARCPTOC_Op_general,  dat)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IARCPTOC_Op_t, currentTime);
					ret = true;
				}
*/
				Quality quality = QUALITY_VALIDITY_GOOD;
				if (Health == STVALINT32_Warning){
					quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
				}
				IedServer_updateQuality(iedServer,&iedModel_PROT_IARCPTOC_Str_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IARCPTOC_Op_q,quality);

return	ret;
}
#endif

#endif

/*************************************************************************
 * GetDirGeneral
 * функция получения направления тока
 * прямое, оба, обратное, неизвестное
 * Currdata:
 * 	bit0 - Направление мощности по каналу Iа
 * 	bit1 - Ошибка направления мощности по каналу Ia
 * 	bit2 - Направление мощности по каналу Ib
 * 	bit3 - Ошибка направления мощности по каналу Ib
 * 	bit4 - Направление мощности по каналу Iс
 * 	bit5 - Ошибка направления мощности по каналу Iс
 *
 * 	return:
 * 	 0 - прямое
 * 	 1 - Оба
 * 	 2 - Обратное
 * 	 3 - Неизвестное
 *
 *************************************************************************/
int16_t		GetDirGeneral(uint8_t	Currdata){
bool	a,b,c,d,e,f;
bool	g = false,h = false;
bool	i,j,k,l;
int16_t	DirOut = 0;

	a = (bool)(Currdata & 1);
	b = (bool)(Currdata>>1 & 1);
	c = (bool)(Currdata>>2 & 1);
	d = (bool)(Currdata>>3 & 1);
	e = (bool)(Currdata>>4 & 1);
	f = (bool)(Currdata>>5 & 1);
/*
	USART_TRACE_BLUE("a: %d \n", a);
	USART_TRACE_BLUE("b: %d \n", b);
	USART_TRACE_BLUE("c: %d \n", c);
	USART_TRACE_BLUE("d: %d \n", d);
	USART_TRACE_BLUE("e: %d \n", e);
	USART_TRACE_BLUE("f: %d \n", f);
*/
	if ((!a && !b) || (!c && !d) || (!e && !f)) g = true; else g = false;
	if ((a && !b) || (c && !d) || (e && !f)) 	h = true; else h = false;
/*
	USART_TRACE_BLUE("g: %d \n", g);
	USART_TRACE_BLUE("h: %d \n", h);
*/
	if (g && !h) 		i = true; else  i = false;
	if (g && h) 		j = true; else  j = false;
	if (!g && h) 		k = true; else  k = false;
	if (b && d && f)	l = true; else  l = false;
/*
	USART_TRACE_BLUE("i: %d \n", i);
	USART_TRACE_BLUE("j: %d \n", j);
	USART_TRACE_BLUE("k: %d \n", k);
	USART_TRACE_BLUE("l: %d \n", l);
*/
		 if (i) DirOut = 0;
	else if (j) DirOut = 1;
	else if (k) DirOut = 2;
	else if (l) DirOut = 3;

return	DirOut;
}

#if defined	(MR771) ||  defined	(MR761) || defined	(MR762) || defined	(MR763)
/*************************************************************************
 * GetDirGeneral
 * функция получения ошибки направления тока
 * только UNKNOWN состояние
 *************************************************************************/
int	GetDirGeneralUnknoun(uint16_t	g_Icfg,uint16_t* Valtmp1){

	if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_I2){
		if (ucMDiscInBuf[MB_offset_dirErrorPTOC_I2] & MB_b_dirError_I2)	*Valtmp1 = STVALCODEDENUM_UNKNOWN;
	}else
	if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_I0){
		if (ucMDiscInBuf[MB_offset_dirErrorPTOC_I0] & MB_b_dirError_I0)	*Valtmp1 = STVALCODEDENUM_UNKNOWN;
	}else
	if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_In){
		if (ucMDiscInBuf[MB_offset_dirErrorPTOC_In] & MB_b_dirError_In)	*Valtmp1 = STVALCODEDENUM_UNKNOWN;
	}else
	if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_Ig){
		*Valtmp1 = STVALCODEDENUM_UNKNOWN;
	}
return	0;
}
#endif

#if defined (MR801)
/*************************************************************************
 * GetDirGeneral
 * функция получения ошибки направления тока
 * только UNKNOWN состояние
 *************************************************************************/
int	GetSidebleDirGeneralUnknoun(uint8_t side, uint16_t	g_Icfg,uint16_t* Valtmp1){

switch (side){

	case 0:
		if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_I2){
			if ((ucMDiscInBuf[MB_offset_dirErrorPTOC_Side1_I2] & MB_b_dirError_Side1_I2)>0)	*Valtmp1 = STVALCODEDENUM_UNKNOWN;
		}else
		if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_I0){
			if ((ucMDiscInBuf[MB_offset_dirErrorPTOC_Side1_I0] & MB_b_dirError_Side1_I0)>0)	*Valtmp1 = STVALCODEDENUM_UNKNOWN;
		}else
		if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_In){
			if ((ucMDiscInBuf[MB_offset_dirErrorPTOC_Side1_In] & MB_b_dirError_Side1_In)>0)	*Valtmp1 = STVALCODEDENUM_UNKNOWN;
		}
		break;
	case 1:
		if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_I2){
			if ((ucMDiscInBuf[MB_offset_dirErrorPTOC_Side2_I2] & MB_b_dirError_Side2_I2)>0)	*Valtmp1 = STVALCODEDENUM_UNKNOWN;
		}else
		if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_I0){
			if ((ucMDiscInBuf[MB_offset_dirErrorPTOC_Side2_I0] & MB_b_dirError_Side2_I0)>0)	*Valtmp1 = STVALCODEDENUM_UNKNOWN;
		}else
		if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_In){
			if ((ucMDiscInBuf[MB_offset_dirErrorPTOC_Side2_In] & MB_b_dirError_Side2_In)>0)	*Valtmp1 = STVALCODEDENUM_UNKNOWN;
		}
		break;
	case 2:
		if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_I2){
			if ((ucMDiscInBuf[MB_offset_dirErrorPTOC_Side3_I2] & MB_b_dirError_Side3_I2)>0)	*Valtmp1 = STVALCODEDENUM_UNKNOWN;
		}else
		if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_I0){
			if ((ucMDiscInBuf[MB_offset_dirErrorPTOC_Side3_I0] & MB_b_dirError_Side3_I0)>0)	*Valtmp1 = STVALCODEDENUM_UNKNOWN;
		}else
		if(g_Icfg == (uint16_t)MB_bOffset_Ig_I_Config_src_In){
			if ((ucMDiscInBuf[MB_offset_dirErrorPTOC_Side3_In] & MB_b_dirError_Side3_In)>0)	*Valtmp1 = STVALCODEDENUM_UNKNOWN;
		}
		break;


}
return	0;
}
#endif

/*******************************************************
 * MR901
 *******************************************************/
#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"


extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];
extern uint16_t   ucMUstavkiInBuf[MB_Size_Ustavki];

/*******************************************************
 * заглушки
 *******************************************************/

int			Set_IPTUC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I2PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I0PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I20PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_INPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IGPTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I2I1PTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_LZSHPTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IARCPTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}


/*******************************************************
 * Set_IPTOC наполняем оперативными данными узлы IPTOC1...8
 *******************************************************/
int		Set_IPTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	Quality 	quality,prequality;
	uint32_t	Health = STVALINT32_OK;
	uint8_t		EventOff;

	/*
	//Health
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM4)>0) 		{Health = STVALINT32_Warning;}
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM5)>0) 		{Health = STVALINT32_Warning;}
					if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0)		{Health = STVALINT32_Warning;}
					if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0) 	{Health = STVALINT32_Warning;}

					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Health_stVal, Health)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC7_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC7_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC8_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC8_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC9_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC9_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC10_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC10_Health_t, currentTime);

						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC11_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC11_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC12_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC12_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC13_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC13_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC14_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC14_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC15_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC15_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC16_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC16_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC17_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC17_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC18_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC18_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC19_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC19_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC20_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC20_Health_t, currentTime);

						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC21_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC21_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC22_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC22_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC23_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC23_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC24_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC24_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC25_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC25_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC26_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC26_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC27_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC27_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC28_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC28_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC29_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC29_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC30_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC30_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC31_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC31_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC32_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC32_Health_t, currentTime);
					}
*/
		//  Mod Beh
					uint32_t	IPTOC_Mod;
					if (ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC7_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC7_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC7_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC7_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I8 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC8_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC8_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC8_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC8_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I9 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC9_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC9_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC9_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC9_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I10 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC10_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC10_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC10_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC10_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I11 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC11_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC11_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC11_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC11_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I12 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC12_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC12_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC12_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC12_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I13 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC13_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC13_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC13_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC13_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I14 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC14_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC14_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC14_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC14_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I15 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC15_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC15_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC15_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC15_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I16 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC16_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC16_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC16_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC16_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I17 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC17_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC17_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC17_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC17_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I18 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC18_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC18_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC18_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC18_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I19 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC19_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC19_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC19_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC19_Beh_t, currentTime);
					}


					if (ucMUstavkiInBuf[MB_offset_MTZ_I20 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC20_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC20_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC20_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC20_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I21 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC21_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC21_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC21_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC21_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I22 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC22_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC22_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC22_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC22_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I23 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC23_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC23_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC23_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC23_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I24 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC24_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC24_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC24_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC24_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I25 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC25_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC25_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC25_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC25_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I26 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC26_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC26_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC26_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC26_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I27 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC27_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC27_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC27_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC27_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I28 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC28_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC28_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC28_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC28_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I29 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC29_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC29_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC29_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC29_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I30 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC30_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC30_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC30_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC30_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I31 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC31_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC31_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC31_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC31_Beh_t, currentTime);
					}

					if (ucMUstavkiInBuf[MB_offset_MTZ_I32 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC32_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC32_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC32_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC32_Beh_t, currentTime);
					}


		//  Quality (Mod Beh)
					int	Qual = QUALITY_VALIDITY_GOOD;
					if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Mod_q,Qual)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC9_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC9_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC10_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC10_Beh_q,Qual);

						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC11_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC11_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC12_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC12_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC13_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC13_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC14_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC14_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC15_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC15_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC16_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC16_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC17_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC17_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC18_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC18_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC19_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC19_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC20_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC20_Beh_q,Qual);

						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC21_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC21_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC22_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC22_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC23_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC23_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC24_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC24_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC25_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC25_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC26_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC26_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC27_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC27_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC28_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC28_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC29_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC29_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC30_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC30_Beh_q,Qual);

						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC31_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC31_Beh_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC32_Mod_q,Qual);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC32_Beh_q,Qual);
					}

		// Str_general
					if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_general,  ucMDiscInBuf[MB_offset_IO_I_1] & MB_b_IO_I1) > 0)				// И0 I>1
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_general,  ucMDiscInBuf[MB_offset_IO_I_2] & MB_b_IO_I2) > 0)			// И0 I>2
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_general,  ucMDiscInBuf[MB_offset_IO_I_3] & MB_b_IO_I3) > 0)			// И0 I>3
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_general,  ucMDiscInBuf[MB_offset_IO_I_4] & MB_b_IO_I4) > 0)			// И0 I>4
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_general,  ucMDiscInBuf[MB_offset_IO_I_5] & MB_b_IO_I5) > 0)			// И0 I>5
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_general,  ucMDiscInBuf[MB_offset_IO_I_6] & MB_b_IO_I6) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC7_Str_general,  ucMDiscInBuf[MB_offset_IO_I_7] & MB_b_IO_I7) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC7_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC8_Str_general,  ucMDiscInBuf[MB_offset_IO_I_8] & MB_b_IO_I8) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC8_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC9_Str_general,  ucMDiscInBuf[MB_offset_IO_I_9] & MB_b_IO_I9) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC9_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC10_Str_general,  ucMDiscInBuf[MB_offset_IO_I_10] & MB_b_IO_I10) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC10_Str_t, currentTime);
					if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC11_Str_general,  ucMDiscInBuf[MB_offset_IO_I_11] & MB_b_IO_I11) > 0)				// И0 I>1
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC11_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC12_Str_general,  ucMDiscInBuf[MB_offset_IO_I_12] & MB_b_IO_I12) > 0)			// И0 I>2
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC12_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC13_Str_general,  ucMDiscInBuf[MB_offset_IO_I_13] & MB_b_IO_I13) > 0)			// И0 I>3
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC13_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC14_Str_general,  ucMDiscInBuf[MB_offset_IO_I_14] & MB_b_IO_I14) > 0)			// И0 I>4
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC14_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC15_Str_general,  ucMDiscInBuf[MB_offset_IO_I_15] & MB_b_IO_I15) > 0)			// И0 I>5
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC15_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC16_Str_general,  ucMDiscInBuf[MB_offset_IO_I_16] & MB_b_IO_I16) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC16_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC17_Str_general,  ucMDiscInBuf[MB_offset_IO_I_17] & MB_b_IO_I17) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC17_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC18_Str_general,  ucMDiscInBuf[MB_offset_IO_I_18] & MB_b_IO_I18) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC18_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC19_Str_general,  ucMDiscInBuf[MB_offset_IO_I_19] & MB_b_IO_I19) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC19_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC20_Str_general,  ucMDiscInBuf[MB_offset_IO_I_20] & MB_b_IO_I20) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC20_Str_t, currentTime);
					if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC21_Str_general,  ucMDiscInBuf[MB_offset_IO_I_21] & MB_b_IO_I21) > 0)				// И0 I>1
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC21_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC22_Str_general,  ucMDiscInBuf[MB_offset_IO_I_22] & MB_b_IO_I22) > 0)			// И0 I>2
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC22_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC23_Str_general,  ucMDiscInBuf[MB_offset_IO_I_23] & MB_b_IO_I23) > 0)			// И0 I>3
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC23_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC24_Str_general,  ucMDiscInBuf[MB_offset_IO_I_24] & MB_b_IO_I24) > 0)			// И0 I>4
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC24_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC25_Str_general,  ucMDiscInBuf[MB_offset_IO_I_25] & MB_b_IO_I25) > 0)			// И0 I>5
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC25_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC26_Str_general,  ucMDiscInBuf[MB_offset_IO_I_26] & MB_b_IO_I26) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC26_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC27_Str_general,  ucMDiscInBuf[MB_offset_IO_I_27] & MB_b_IO_I27) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC27_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC28_Str_general,  ucMDiscInBuf[MB_offset_IO_I_28] & MB_b_IO_I28) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC28_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC29_Str_general,  ucMDiscInBuf[MB_offset_IO_I_29] & MB_b_IO_I29) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC29_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC30_Str_general,  ucMDiscInBuf[MB_offset_IO_I_30] & MB_b_IO_I30) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC30_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC31_Str_general,  ucMDiscInBuf[MB_offset_IO_I_31] & MB_b_IO_I31) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC31_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC32_Str_general,  ucMDiscInBuf[MB_offset_IO_I_32] & MB_b_IO_I32) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC32_Str_t, currentTime);

		// Op_general
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_1] & MB_b_SRAB_I1) > 0)		// СРАБ I>1
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_2] & MB_b_SRAB_I2) > 0)		// СРАБ I>2
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_3] & MB_b_SRAB_I3) > 0)		// СРАБ I>3
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_4] & MB_b_SRAB_I4) > 0)		// СРАБ I>4
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_5] & MB_b_SRAB_I5) > 0)		// СРАБ I>5
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_6] & MB_b_SRAB_I6) > 0)		// СРАБ I>6
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC7_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_7] & MB_b_SRAB_I7) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC7_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC8_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_8] & MB_b_SRAB_I8) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC8_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC9_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_9] & MB_b_SRAB_I9) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC9_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC10_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_10] & MB_b_SRAB_I10) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC10_Op_t, currentTime);
					if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC11_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_11] & MB_b_SRAB_I11) > 0)				// И0 I>1
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC11_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC12_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_12] & MB_b_SRAB_I12) > 0)			// И0 I>2
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC12_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC13_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_13] & MB_b_SRAB_I13) > 0)			// И0 I>3
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC13_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC14_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_14] & MB_b_SRAB_I14) > 0)			// И0 I>4
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC14_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC15_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_15] & MB_b_SRAB_I15) > 0)			// И0 I>5
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC15_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC16_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_16] & MB_b_SRAB_I16) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC16_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC17_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_17] & MB_b_SRAB_I17) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC17_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC18_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_18] & MB_b_SRAB_I18) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC18_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC19_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_19] & MB_b_SRAB_I19) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC19_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC20_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_20] & MB_b_SRAB_I20) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC20_Op_t, currentTime);
					if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC21_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_21] & MB_b_SRAB_I21) > 0)				// И0 I>1
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC21_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC22_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_22] & MB_b_SRAB_I22) > 0)			// И0 I>2
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC22_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC23_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_23] & MB_b_SRAB_I23) > 0)			// И0 I>3
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC23_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC24_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_24] & MB_b_SRAB_I24) > 0)			// И0 I>4
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC24_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC25_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_25] & MB_b_SRAB_I25) > 0)			// И0 I>5
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC25_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC26_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_26] & MB_b_SRAB_I26) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC26_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC27_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_27] & MB_b_SRAB_I27) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC27_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC28_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_28] & MB_b_SRAB_I28) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC28_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC29_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_29] & MB_b_SRAB_I29) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC29_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC30_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_30] & MB_b_SRAB_I30) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC30_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC31_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_31] & MB_b_SRAB_I31) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC31_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC32_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_32] & MB_b_SRAB_I32) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC32_Op_t, currentTime);
/*
					quality = QUALITY_VALIDITY_GOOD;
					if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;} else {quality = QUALITY_VALIDITY_GOOD;}
*/
// При неисправности  4го модуля и действии на отключение 1-8, формировать значение warning для атрибута health, и invalid для q (в атрибутах Op и Str).
//     Аналогично для 5го модуля И действии на отключение 9-16 присоединения,
//                    6го модуля И действии на отключение 17-24.

					if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0)	{prequality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;} else {prequality = QUALITY_VALIDITY_GOOD;}

					// IPTOC1
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Health_t, currentTime);
					}
					// IPTOC2
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Health_t, currentTime);
					}
					// IPTOC3
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Health_t, currentTime);
					}
					// IPTOC4
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Health_t, currentTime);
					}
					// IPTOC5
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Health_t, currentTime);
					}
					// IPTOC6
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Health_t, currentTime);
					}
					// IPTOC7
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC7_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC7_Health_t, currentTime);
					}
					// IPTOC8
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I8 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC8_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC8_Health_t, currentTime);
					}
					// IPTOC9
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I9 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC9_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC9_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC9_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC9_Health_t, currentTime);
					}
					// IPTOC10
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I10 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC10_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC10_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC10_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC10_Health_t, currentTime);
					}
					// IPTOC11
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I11 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC11_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC11_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC11_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC11_Health_t, currentTime);
					}
					// IPTOC12
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I12 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC12_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC12_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC12_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC12_Health_t, currentTime);
					}
					// IPTOC13
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I13 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC13_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC13_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC13_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC13_Health_t, currentTime);
					}
					// IPTOC14
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I14 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC14_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC14_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC14_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC14_Health_t, currentTime);
					}
					// IPTOC15
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I15 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC15_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC15_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC15_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC15_Health_t, currentTime);
					}
					// IPTOC16
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I16 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC16_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC16_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC16_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC16_Health_t, currentTime);
					}
					// IPTOC17
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I17 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC17_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC17_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC17_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC17_Health_t, currentTime);
					}
					// IPTOC18
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I18 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC18_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC18_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC18_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC18_Health_t, currentTime);
					}
					// IPTOC19
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I19 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC19_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC19_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC19_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC19_Health_t, currentTime);
					}
					// IPTOC20
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I20 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC20_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC20_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC20_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC20_Health_t, currentTime);
					}
					// IPTOC21
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I21 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC21_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC21_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC21_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC21_Health_t, currentTime);
					}
					// IPTOC22
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I22 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC22_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC22_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC22_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC22_Health_t, currentTime);
					}
					// IPTOC23
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I23 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC23_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC23_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC23_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC23_Health_t, currentTime);
					}
					// IPTOC24
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I24 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC24_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC24_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC24_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC24_Health_t, currentTime);
					}
					// IPTOC25
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I25 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC25_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC25_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC25_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC25_Health_t, currentTime);
					}
					// IPTOC26
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I26 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC26_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC26_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC26_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC26_Health_t, currentTime);
					}
					// IPTOC27
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I27 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC27_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC27_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC27_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC27_Health_t, currentTime);
					}
					// IPTOC28
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I28 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC28_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC28_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC28_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC28_Health_t, currentTime);
					}
					// IPTOC29
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I29 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC29_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC29_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC29_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC29_Health_t, currentTime);
					}
					// IPTOC30
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I30 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC30_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC30_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC30_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC30_Health_t, currentTime);
					}
					// IPTOC31
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I31 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC31_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC31_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC31_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC31_Health_t, currentTime);
					}
					// IPTOC32
					quality = prequality;
					EventOff = (ucMUstavkiInBuf[MB_offset_MTZ_I32 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_EventOff) >> MB_bOffset_MTZ_I_Config_EventOff_MOV;
					if (EventOff>=0 && EventOff<8)  if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=8 && EventOff<16) if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (EventOff>=16 && EventOff<24) if ((ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC32_Op_q,quality)){
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC32_Str_q,quality);
						if  (quality == QUALITY_VALIDITY_GOOD) Health = STVALINT32_OK; else Health = STVALINT32_Warning;
							IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC32_Health_stVal, Health);
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC32_Health_t, currentTime);
					}

/*
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC9_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC9_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC10_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC10_Str_q,quality);

						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC11_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC11_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC12_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC12_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC13_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC13_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC14_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC14_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC15_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC15_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC16_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC16_Str_q,quality);

						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC17_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC17_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC18_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC18_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC19_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC19_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC20_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC20_Str_q,quality);

						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC21_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC21_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC22_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC22_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC23_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC23_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC24_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC24_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC25_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC25_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC26_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC26_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC27_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC27_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC28_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC28_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC29_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC29_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC30_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC30_Str_q,quality);

						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC31_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC31_Str_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC32_Op_q,quality);
						IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC32_Str_q,quality);
*/

}
#endif

/*******************************************************
 * MR5 PO70, PO50
 *******************************************************/
#if defined (MR5_700) || defined (MR5_500) || defined (MR741)

#if defined (MR5_700)
#include "static_model_MR5_700.h"
#endif
#if defined (MR5_500)
#include "static_model_MR5_500.h"
#endif
#if defined (MR741)
#include "static_model_MR741.h"
#endif
extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];
extern uint16_t   ucConfigBufMTZ[MB_NumbConfigMTZ];
extern uint16_t   ucMAutomatBuf[MB_Size_Automat];
extern uint16_t   ucConfigBufI2I1I0[MB_NumbConfigI2I1I0];

/*******************************************************
 * заглушки
 *******************************************************/
int			Set_IPTUC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_I20PTOC		(uint16_t QTnum, uint64_t currentTime ){return false;}
int			Set_IARCPTOC	(uint16_t QTnum, uint64_t currentTime ){return false;}

/*******************************************************
 * Set_LZSHPTOC наполняем оперативными данными
 *******************************************************/
int		Set_LZSHPTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Health;
	Quality 	quality;
	uint32_t	Mod;
	//Health
				Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1b) 		{Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki) 	{Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LZSHPTOC_Health_t, currentTime);

	//  Mod Beh

				if ((ucMAutomatBuf[MB_offset_ConfLZSHAWR] & MB_bOffset_LZSH_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Mod_stVal, Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LZSHPTOC_Mod_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Beh_stVal, Mod))
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LZSHPTOC_Beh_t, currentTime);
				}

	//  Quality (Mod Beh)
				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_LZSHPTOC_Mod_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_LZSHPTOC_Beh_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Mod_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Beh_t, currentTime);
				}

	// Str_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Str_general,  ucMDiscInBuf[MB_offset_LZSH] & MB_b_Rab_LZSH))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Str_t, currentTime);

	// Op_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Op_general,  ucMDiscInBuf[MB_offset_LZSH] & MB_b_Rab_LZSH))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Op_t, currentTime);

				quality = QUALITY_VALIDITY_GOOD;
				if (Health == STVALINT32_Warning) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_LZSHPTOC_Str_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_LZSHPTOC_Op_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Str_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Op_t, currentTime);
				}
return ret;
}
/*******************************************************
 * Set_IPTOC наполняем оперативными данными узлы IPTOC1...8
 *******************************************************/
int		Set_IPTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Health;
	uint32_t	Mod;
	Quality 	quality;
	int16_t		Valtmp1=STVALCODEDENUM_UNKNOWN;
	int16_t		Valtmp2=STVALCODEDENUM_UNKNOWN;
	int16_t		Valtmp3=STVALCODEDENUM_UNKNOWN;
	int16_t		Valtmp4=STVALCODEDENUM_UNKNOWN;

//Health
			Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1))		{Health = STVALINT32_Warning;}
			if (ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki) 	{Health = STVALINT32_Warning;}

			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Health_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Health_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Health_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Health_t, currentTime);
			}

//  Mod Beh
			if ((ucConfigBufMTZ[MB_offset_MTZ_Iup + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Beh_t, currentTime);
			}

			if ((ucConfigBufMTZ[MB_offset_MTZ_Iup2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Beh_t, currentTime);
			}

			if ((ucConfigBufMTZ[MB_offset_MTZ_Iup3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Beh_t, currentTime);
			}

			if ((ucConfigBufMTZ[MB_offset_MTZ_Iup4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Beh_t, currentTime);
			}


//  Quality (Mod Beh)
			quality = QUALITY_VALIDITY_GOOD;
			if ((ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Mod_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Beh_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Beh_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Beh_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Beh_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Beh_t, currentTime);
			}

// Str_general
			if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_general,  ucMDiscInBuf[MB_offset_IO_I_1] & MB_b_IO_I1) > 0)			// И0 I>1
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);
			if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_general,  ucMDiscInBuf[MB_offset_IO_I_2] & MB_b_IO_I2) > 0)			// И0 I>2
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_t, currentTime);
			if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_general,  ucMDiscInBuf[MB_offset_IO_I_3] & MB_b_IO_I3) > 0)			// И0 I>3
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_t, currentTime);
			if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_general,  ucMDiscInBuf[MB_offset_IO_I_4] & MB_b_IO_I4) > 0)			// И0 I>4
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_t, currentTime);

// Op_general
			if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_1] & MB_b_SRAB_I1) > 0)		// СРАБ I>1
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_t, currentTime);
			if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_2] & MB_b_SRAB_I2) > 0)		// СРАБ I>2
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Op_t, currentTime);
			if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_3] & MB_b_SRAB_I3) > 0)		// СРАБ I>3
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Op_t, currentTime);
			if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_4] & MB_b_SRAB_I4) > 0)		// СРАБ I>4
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Op_t, currentTime);

// Str_dir_general
			{

			if ( ((ucMDiscInBuf[MB_offset_dirPTOC_Ia] & MB_b_dirError_Ia)>0) &&
				 ((ucMDiscInBuf[MB_offset_dirPTOC_Ib] & MB_b_dirError_Ib)>0) &&
				 ((ucMDiscInBuf[MB_offset_dirPTOC_Ic] & MB_b_dirError_Ic)>0)
			   ) {
				Valtmp1 = STVALCODEDENUM_UNKNOWN;
				Valtmp2 = STVALCODEDENUM_UNKNOWN;
				Valtmp3 = STVALCODEDENUM_UNKNOWN;
				Valtmp4 = STVALCODEDENUM_UNKNOWN;
			}
			else {
				// IPTOC1
				if ((ucMDiscInBuf[MB_offset_IO_I_1] & MB_b_IO_I1) > 0){
					if		( (ucConfigBufMTZ[MB_offset_MTZ_Iup + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up) > 0) Valtmp1 = STVALCODEDENUM_FORWARD;
					else if	( (ucConfigBufMTZ[MB_offset_MTZ_Iup + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn) > 0) Valtmp1 = STVALCODEDENUM_BACKWARD;
					else Valtmp1 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
				} else Valtmp1 = STVALCODEDENUM_UNKNOWN;
				// IPTOC2
				if ((ucMDiscInBuf[MB_offset_IO_I_2] & MB_b_IO_I2) > 0){
					if		( (ucConfigBufMTZ[MB_offset_MTZ_Iup2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up) > 0) Valtmp2 = STVALCODEDENUM_FORWARD;
					else if	( (ucConfigBufMTZ[MB_offset_MTZ_Iup2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn) > 0) Valtmp2 = STVALCODEDENUM_BACKWARD;
					else Valtmp2 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
				} else Valtmp2 = STVALCODEDENUM_UNKNOWN;
				// IPTOC3
				if ((ucMDiscInBuf[MB_offset_IO_I_3] & MB_b_IO_I3) > 0){
					if		( (ucConfigBufMTZ[MB_offset_MTZ_Iup3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up) > 0) Valtmp3 = STVALCODEDENUM_FORWARD;
					else if	( (ucConfigBufMTZ[MB_offset_MTZ_Iup3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn) > 0) Valtmp3 = STVALCODEDENUM_BACKWARD;
					else Valtmp3 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
				} else Valtmp3 = STVALCODEDENUM_UNKNOWN;
				// IPTOC4
				if ((ucMDiscInBuf[MB_offset_IO_I_4] & MB_b_IO_I4) > 0){
					if		( (ucConfigBufMTZ[MB_offset_MTZ_Iup4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up) > 0) Valtmp4 = STVALCODEDENUM_FORWARD;
					else if	( (ucConfigBufMTZ[MB_offset_MTZ_Iup4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn) > 0) Valtmp4 = STVALCODEDENUM_BACKWARD;
					else Valtmp4 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
				} else Valtmp4 = STVALCODEDENUM_UNKNOWN;
			}

			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_dirGeneral, Valtmp1))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_dirGeneral, Valtmp2))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_dirGeneral, Valtmp3))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_dirGeneral, Valtmp4))
			  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_t, currentTime);
			}

			quality = QUALITY_VALIDITY_GOOD;
			if (Health == STVALINT32_Warning) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Op_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Str_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Op_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Str_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Op_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Str_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Op_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Str_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Op_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Op_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Op_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_t, currentTime);

			}
return ret;
}
/*******************************************************
 * Set_I2I1PTOC наполняем оперативными данными узлы
 *******************************************************/
int		Set_I2I1PTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Health;
	uint32_t	Mod;
	Quality		quality;
	//Health
				Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1b)>0) 		{Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)>0) 	{Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2I1PTOC_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2I1PTOC_Health_t, currentTime);

	//  Mod Beh

				if ((ucConfigBufI2I1I0[MB_offset_ConfI2I1] & MB_bOffset_I2I1_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2I1PTOC_Mod_stVal, Mod)){
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2I1PTOC_Mod_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2I1PTOC_Beh_stVal, Mod))
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2I1PTOC_Beh_t, currentTime);
				}

	//  Quality (Mod Beh)
				quality = QUALITY_VALIDITY_GOOD;
				if ((ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC_Mod_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC_Beh_q,quality);
				}

	// Str_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC_Str_general,  (ucMDiscInBuf[MB_offset_IO_I2I1] & MB_b_IO_I2I1)>0))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC_Str_t, currentTime);
	// Op_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC_Op_general,  (ucMDiscInBuf[MB_offset_SRAB_I2I1] & MB_b_SRAB_I2I1)>0))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC_Op_t, currentTime);

				quality = QUALITY_VALIDITY_GOOD;
				if (Health == STVALINT32_Warning) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC_Str_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC_Op_q,quality);
				}
return ret;
}
/*******************************************************
 * Set_I2PTOC наполняем оперативными данными узлы IPTOC1...8
 *******************************************************/
int		Set_I2PTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Health;
	Quality 	quality;
	int16_t		Valtmp1=0;
	int16_t		Valtmp2=0;

	//Health
				Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1)>0)  		{Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)>0) 	{Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2PTOC1_Health_stVal, Health)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2PTOC1_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2PTOC2_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2PTOC2_Health_t, currentTime);
				}

	//  Mod Beh
				uint32_t	IPTOC_Mod;
				if ((ucConfigBufMTZ[MB_offset_MTZ_I2up + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2PTOC1_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2PTOC1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2PTOC1_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2PTOC1_Beh_t, currentTime);
				}

				if ((ucConfigBufMTZ[MB_offset_MTZ_I2up2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2PTOC2_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2PTOC2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2PTOC2_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2PTOC2_Beh_t, currentTime);
				}

	//  Quality (Mod Beh)
				quality = QUALITY_VALIDITY_GOOD;
				if ((ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_I2PTOC1_Mod_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_I2PTOC1_Beh_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I2PTOC2_Mod_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I2PTOC2_Beh_q,quality);
				}

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I2PTOC1_Str_general,  ucMDiscInBuf[MB_offset_IO_I2up] & MB_b_IO_I2up) > 0)			// И0 I>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2PTOC1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I2PTOC2_Str_general,  ucMDiscInBuf[MB_offset_IO_I2up2] & MB_b_IO_I2up2) > 0)			// И0 I>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2PTOC2_Str_t, currentTime);
	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I2PTOC1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I2up] & MB_b_SRAB_I2up) > 0)		// СРАБ I>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2PTOC1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I2PTOC2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I2up2] & MB_b_SRAB_I2up2) > 0)		// СРАБ I>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2PTOC2_Op_t, currentTime);

	// Str_dir_general
				{
				//int16_t	 Valtmp = GetDirGeneral((uint8_t)(ucMDiscInBuf[MB_offset_dirPTOC_Ia]) & 0b00101010);

					if ((ucMDiscInBuf[MB_offset_dirErrorPTOC_I2] & MB_b_dirError_I2)>0) {
					Valtmp1 = STVALCODEDENUM_UNKNOWN;
					Valtmp2 = STVALCODEDENUM_UNKNOWN;
				}
				else {
					// I2PTOC1
					if ((ucMDiscInBuf[MB_offset_IO_I2up] & MB_b_IO_I2up)>0){
						if		((ucConfigBufMTZ[MB_offset_MTZ_I2up + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp1 = STVALCODEDENUM_FORWARD;
						else if	((ucConfigBufMTZ[MB_offset_MTZ_I2up + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp1 = STVALCODEDENUM_BACKWARD;
						else Valtmp1 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp1 = STVALCODEDENUM_UNKNOWN;
					// I2PTOC2
					if ((ucMDiscInBuf[MB_offset_IO_I2up2] & MB_b_IO_I2up2)>0){
						if		((ucConfigBufMTZ[MB_offset_MTZ_I2up2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp2 = STVALCODEDENUM_FORWARD;
						else if	((ucConfigBufMTZ[MB_offset_MTZ_I2up2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp2 = STVALCODEDENUM_BACKWARD;
						else Valtmp2 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp2 = STVALCODEDENUM_UNKNOWN;
				}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2PTOC1_Str_dirGeneral, Valtmp1))
				  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2PTOC1_Str_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2PTOC2_Str_dirGeneral, Valtmp2))
				  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2PTOC2_Str_t, currentTime);

				}
				quality = QUALITY_VALIDITY_GOOD;
				if (Health == STVALINT32_Warning) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_I2PTOC1_Op_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_I2PTOC1_Str_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I2PTOC2_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I2PTOC2_Str_q,quality);
				}
return ret;
}
/*******************************************************
 * Set_I0PTOC наполняем оперативными данными узлы
 *******************************************************/
int		Set_I0PTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Health;
	Quality 	quality;
	int16_t	Valtmp1=0;
	int16_t	Valtmp2=0;

	//Health
				Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1)>0)  		{Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)>0) 	{Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I0PTOC1_Health_stVal, Health)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I0PTOC1_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I0PTOC2_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I0PTOC2_Health_t, currentTime);
				}

	//  Mod Beh
				uint32_t	IPTOC_Mod;
				if ((ucConfigBufMTZ[MB_offset_MTZ_I0up + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I0PTOC1_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I0PTOC1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I0PTOC1_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I0PTOC1_Beh_t, currentTime);
				}

				if ((ucConfigBufMTZ[MB_offset_MTZ_I0up2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I0PTOC2_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I0PTOC2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I0PTOC2_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I0PTOC2_Beh_t, currentTime);
				}

	//  Quality (Mod Beh)
				quality = QUALITY_VALIDITY_GOOD;
				if ((ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_I0PTOC1_Mod_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_I0PTOC1_Beh_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I0PTOC2_Mod_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I0PTOC2_Beh_q,quality);
				}

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I0PTOC1_Str_general,  ucMDiscInBuf[MB_offset_IO_I0up] & MB_b_IO_I0up) > 0)			// И0 I>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I0PTOC1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I0PTOC2_Str_general,  ucMDiscInBuf[MB_offset_IO_I0up2] & MB_b_IO_I0up2) > 0)			// И0 I>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I0PTOC2_Str_t, currentTime);
	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I0PTOC1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I0up] & MB_b_SRAB_I0up) > 0)		// СРАБ I>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I0PTOC1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I0PTOC2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I0up2] & MB_b_SRAB_I0up2) > 0)		// СРАБ I>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I0PTOC2_Op_t, currentTime);

	// Str_dir_general
				{
				//int16_t	 Valtmp = GetDirGeneral((uint8_t)(ucMDiscInBuf[MB_offset_dirPTOC_Ia]) & 0b00101010);

				if ((ucMDiscInBuf[MB_offset_dirErrorPTOC_I0] & MB_b_dirError_I0)>0) {
					Valtmp1 = STVALCODEDENUM_UNKNOWN;
					Valtmp2 = STVALCODEDENUM_UNKNOWN;
				}
				else {
					// I0PTOC1
					if ((ucMDiscInBuf[MB_offset_IO_I0up] & MB_b_IO_I0up)>0){
						if		((ucConfigBufMTZ[MB_offset_MTZ_I0up + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp1 = STVALCODEDENUM_FORWARD;
						else if	((ucConfigBufMTZ[MB_offset_MTZ_I0up + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp1 = STVALCODEDENUM_BACKWARD;
						else Valtmp1 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp1 = STVALCODEDENUM_UNKNOWN;
					// I0PTOC2
					if ((ucMDiscInBuf[MB_offset_IO_I0up2] & MB_b_IO_I0up2)>0){
						if		((ucConfigBufMTZ[MB_offset_MTZ_I0up2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp2 = STVALCODEDENUM_FORWARD;
						else if	((ucConfigBufMTZ[MB_offset_MTZ_I0up2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp2 = STVALCODEDENUM_BACKWARD;
						else Valtmp2 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp2 = STVALCODEDENUM_UNKNOWN;
				}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I0PTOC1_Str_dirGeneral, Valtmp1))
				  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I0PTOC1_Str_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I0PTOC2_Str_dirGeneral, Valtmp2))
				  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I0PTOC2_Str_t, currentTime);

				}

				quality = QUALITY_VALIDITY_GOOD;
				if (Health == STVALINT32_Warning) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_I0PTOC1_Op_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_I0PTOC1_Str_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I0PTOC2_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I0PTOC2_Str_q,quality);
				}
return ret;
}
/*******************************************************
 * Set_INPTOC наполняем оперативными данными узлы
 *******************************************************/
int		Set_INPTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Health;
	Quality 	quality;
	int16_t		Valtmp1=0;
	int16_t		Valtmp2=0;

	//Health
				Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1)>0)  		{Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)>0) 	{Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_INPTOC1_Health_stVal, Health)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_INPTOC1_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_INPTOC2_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_INPTOC2_Health_t, currentTime);
				}

	//  Mod Beh
				uint32_t	IPTOC_Mod;
				if ((ucConfigBufMTZ[MB_offset_MTZ_INup + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_INPTOC1_Mod_stVal, IPTOC_Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_INPTOC1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_INPTOC1_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_INPTOC1_Beh_t, currentTime);
				}


				if ((ucConfigBufMTZ[MB_offset_MTZ_INup2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat)>0) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_INPTOC2_Mod_stVal, IPTOC_Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_INPTOC2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_INPTOC2_Beh_stVal, IPTOC_Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_INPTOC2_Beh_t, currentTime);
				}

	//  Quality (Mod Beh)
				quality = QUALITY_VALIDITY_GOOD;
				if ((ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_INPTOC1_Mod_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_INPTOC1_Beh_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_INPTOC2_Mod_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_INPTOC2_Beh_q,quality);
				}

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_INPTOC1_Str_general,  ucMDiscInBuf[MB_offset_IO_INup] & MB_b_IO_INup) > 0)			// И0 I>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_INPTOC1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_INPTOC2_Str_general,  ucMDiscInBuf[MB_offset_IO_INup2] & MB_b_IO_INup2) > 0)			// И0 I>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_INPTOC2_Str_t, currentTime);
	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_INPTOC1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_INup] & MB_b_SRAB_INup) > 0)		// СРАБ I>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_INPTOC1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_INPTOC2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_INup2] & MB_b_SRAB_INup2) > 0)		// СРАБ I>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_INPTOC2_Op_t, currentTime);

	// Str_dir_general
				{
				//int16_t	 Valtmp = GetDirGeneral((uint8_t)(ucMDiscInBuf[MB_offset_dirPTOC_Ia]) & 0b00101010);

				if ((ucMDiscInBuf[MB_offset_dirErrorPTOC_In] & MB_b_dirError_In)>0) {
					Valtmp1 = STVALCODEDENUM_UNKNOWN;
					Valtmp2 = STVALCODEDENUM_UNKNOWN;
				}
				else {
					// INPTOC1
					if ((ucMDiscInBuf[MB_offset_IO_INup] & MB_b_IO_INup)>0){
						if		((ucConfigBufMTZ[MB_offset_MTZ_INup + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp1 = STVALCODEDENUM_FORWARD;
						else if	((ucConfigBufMTZ[MB_offset_MTZ_INup + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp1 = STVALCODEDENUM_BACKWARD;
						else Valtmp1 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp1 = STVALCODEDENUM_UNKNOWN;
					// INPTOC2
					if ((ucMDiscInBuf[MB_offset_IO_INup2] & MB_b_IO_INup2)>0){
						if		((ucConfigBufMTZ[MB_offset_MTZ_INup2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_up)>0) Valtmp2 = STVALCODEDENUM_FORWARD;
						else if	((ucConfigBufMTZ[MB_offset_MTZ_INup2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Napravl_dn)>0) Valtmp2 = STVALCODEDENUM_BACKWARD;
						else Valtmp2 = STVALCODEDENUM_UNKNOWN;//STVALCODEDENUM_BOTH;
					} else Valtmp2 = STVALCODEDENUM_UNKNOWN;
				}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_INPTOC1_Str_dirGeneral, Valtmp1))
				  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_INPTOC1_Str_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_INPTOC2_Str_dirGeneral, Valtmp2))
				  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_INPTOC2_Str_t, currentTime);

				}

				quality = QUALITY_VALIDITY_GOOD;
				if (Health == STVALINT32_Warning) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_INPTOC1_Op_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_INPTOC1_Str_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_INPTOC2_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_INPTOC2_Str_q,quality);
				}
return ret;
}
/*******************************************************
 * Set_IGPTOC наполняем оперативными данными узлы
 *******************************************************/
int		Set_IGPTOC	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Health;
	uint32_t	Mod;
	Quality 	quality;

	//Health
				Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1)>0)  		{Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)>0) 	{Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IGPTOC_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IGPTOC_Health_t, currentTime);

	//  Mod Beh
				if ((ucConfigBufI2I1I0[MB_offset_MTZ_IGup + MB_offset_ConfIGup_Config] & MB_bOffset_IGup_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IGPTOC_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IGPTOC_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IGPTOC_Beh_stVal, Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IGPTOC_Beh_t, currentTime);
				}

	//  Quality (Mod Beh)
				quality = QUALITY_VALIDITY_GOOD;
				if ((ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)>0) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IGPTOC_Mod_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_IGPTOC_Beh_q,quality);
				}

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IGPTOC_Str_general,  ucMDiscInBuf[MB_offset_IO_IGup] & MB_b_IO_IGup) > 0)			// И0 I>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IGPTOC_Str_t, currentTime);
	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IGPTOC_Op_general,  ucMDiscInBuf[MB_offset_SRAB_IGup] & MB_b_SRAB_IGup) > 0)		// СРАБ I>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IGPTOC_Op_t, currentTime);

				quality = QUALITY_VALIDITY_GOOD;
				if (Health == STVALINT32_Warning) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_IGPTOC_Op_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IGPTOC_Str_q,quality);

return ret;
}
#endif
