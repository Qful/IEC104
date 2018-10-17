/*
 * datatoSPCS.c
 *
 *  Created on: 30.11.2017
 *      Author: sagok
 */

#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

extern  uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern bool		NewSysNoteMessage;
extern bool		NewErrorNoteMessage;

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
 * Set_SPCSO
 *******************************************************/
int		Set_SPCSO		(uint16_t QTnum, uint64_t currentTime ){

	int	ret = false;
	bool		Val;
//  ачество и врем€ мен€ем по надобности ---------------------------------------
	Quality		quality;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// мен€ть ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// мен€ть ли врем€
//	if(num > MB_MaxNumbLED)	return;
// -----------------------------------------------------------------------------

	if (num == 0 || num == 1){
		if (ucMDiscInBuf[MB_offset_ErrorSDTU] & MB_bOffsetErrorSDTU)	 Val = true; else Val = false;
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,&iedModel_CTRL_GGIO1_SPCSO1_t,currentTime, Val);
	}
	if (num == 0 || num == 2){
//		if (ucMDiscInBuf[MB_offset_SysNote] & MB_bOffsetSysNote)	 Val = true; else Val = false;
		Val = NewSysNoteMessage;
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,&iedModel_CTRL_GGIO1_SPCSO2_t,currentTime, Val);
	}
	if (num == 0 || num == 3){
//		if (ucMDiscInBuf[MB_offset_ErrorNote] & MB_bOffsetErrorNote)	 Val = true; else Val = false;
		Val = NewErrorNoteMessage;
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,&iedModel_CTRL_GGIO1_SPCSO3_t,currentTime, Val);
	}
	if (num == 0 || num == 4){
		// все индикаторы
		if ((ucMDiscInBuf[MB_offset_AllLEDs] & MB_bOffsetLedsStats)>0)	 Val = true; else Val = false;
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,&iedModel_CTRL_GGIO1_SPCSO4_t,currentTime, Val);

	}
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);
return ret;
}
#endif
/*******************************************************
 * MR851
 *******************************************************/
#if defined (MR851)
#include "static_model_MR851.h"

/*******************************************************
 * Set_SPCSO
 *******************************************************/
int		Set_SPCSO		(uint16_t QTnum, uint64_t currentTime ){

	int	ret = false;
	bool		Val;
//  ачество и врем€ мен€ем по надобности ---------------------------------------
	Quality		quality;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// мен€ть ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// мен€ть ли врем€
//	if(num > MB_MaxNumbLED)	return;
// -----------------------------------------------------------------------------

	if (num == 0 || num == 1){
		if (ucMDiscInBuf[MB_offset_ErrorSDTU] & MB_bOffsetErrorSDTU)	 Val = true; else Val = false;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  Val)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			ret = true;
		}
	}
	if (num == 0 || num == 2){
//		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote)	 Val = true; else Val = false;
		Val = NewSysNoteMessage;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  Val)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			ret = true;
		}
	}
	if (num == 0 || num == 3){
		if (ucMDiscInBuf[MB_offset_BLK] & MB_bOffsetDriveDNTMove)	 Val = true; else Val = false;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  Val)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			ret = true;
		}
	}
	if (num == 0 || num == 4){
		if (ucMDiscInBuf[MB_offset_NewMsJurnalError] & MB_bOffseNewMsJurnalError)	 Val = true; else Val = false;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  Val)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			ret = true;
		}
	}
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);
return ret;
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

/*******************************************************
 * Set_SPCSO
 *******************************************************/
int		Set_SPCSO		(uint16_t QTnum, uint64_t currentTime ){

	int	ret = false;
	bool		Val;
//  ачество и врем€ мен€ем по надобности ---------------------------------------
	Quality		quality;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// мен€ть ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// мен€ть ли врем€
//	if(num > MB_MaxNumbLED)	return;
// -----------------------------------------------------------------------------

	if (num == 0 || num == 1){
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetError)	 Val = true; else Val = false;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  Val)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			ret = true;
		}
	}
	if (num == 0 || num == 2){
//		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote)	 Val = true; else Val = false;
		Val = NewSysNoteMessage;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  Val)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			ret = true;
		}
	}
	if (num == 0 || num == 3){
//		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetErrorNote)	 Val = true; else Val = false;
		Val = NewErrorNoteMessage;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  Val)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			ret = true;
		}
	}
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);

	if (
			(ucMDiscInBuf[MB_offsetLED_1g]  & MB_bOffset_LED_1g) ||
			(ucMDiscInBuf[MB_offsetLED_2g]  & MB_bOffset_LED_2g) ||
			(ucMDiscInBuf[MB_offsetLED_3g]  & MB_bOffset_LED_3g) ||
			(ucMDiscInBuf[MB_offsetLED_4g]  & MB_bOffset_LED_4g) ||
			(ucMDiscInBuf[MB_offsetLED_5g]  & MB_bOffset_LED_5g) ||
			(ucMDiscInBuf[MB_offsetLED_6g]  & MB_bOffset_LED_6g) ||
			(ucMDiscInBuf[MB_offsetLED_7g]  & MB_bOffset_LED_7g) ||
			(ucMDiscInBuf[MB_offsetLED_8g]  & MB_bOffset_LED_8g) ||
			(ucMDiscInBuf[MB_offsetLED_9g]  & MB_bOffset_LED_9g) ||
			(ucMDiscInBuf[MB_offsetLED_10g] & MB_bOffset_LED_10g)||
			(ucMDiscInBuf[MB_offsetLED_11g] & MB_bOffset_LED_11g)||
			(ucMDiscInBuf[MB_offsetLED_12g] & MB_bOffset_LED_12g)||
			(ucMDiscInBuf[MB_offsetLED_1r]  & MB_bOffset_LED_1g) ||
			(ucMDiscInBuf[MB_offsetLED_2r]  & MB_bOffset_LED_2g) ||
			(ucMDiscInBuf[MB_offsetLED_3r]  & MB_bOffset_LED_3g) ||
			(ucMDiscInBuf[MB_offsetLED_4r]  & MB_bOffset_LED_4g) ||
			(ucMDiscInBuf[MB_offsetLED_5r]  & MB_bOffset_LED_5g) ||
			(ucMDiscInBuf[MB_offsetLED_6r]  & MB_bOffset_LED_6g) ||
			(ucMDiscInBuf[MB_offsetLED_7r]  & MB_bOffset_LED_7g) ||
			(ucMDiscInBuf[MB_offsetLED_8r]  & MB_bOffset_LED_8g) ||
			(ucMDiscInBuf[MB_offsetLED_9r]  & MB_bOffset_LED_9g) ||
			(ucMDiscInBuf[MB_offsetLED_10r] & MB_bOffset_LED_10g)||
			(ucMDiscInBuf[MB_offsetLED_11r] & MB_bOffset_LED_11g)||
			(ucMDiscInBuf[MB_offsetLED_12r] & MB_bOffset_LED_12g)
			)
	{
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  1)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			ret = true;
		}

	} else{
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  0)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			ret = true;
		}
	}
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);
return ret;
}

#endif
/*******************************************************
 * MR801 MR901 MR902
 *******************************************************/
#if defined	(MR801) || defined	(MR901) || defined	(MR902)

#if defined	(MR801)
#include "static_model_MR801.h"
#endif

#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"
#endif

extern  uint16_t   ucMDiscInBuf[MB_NumbDiscreet];

/*******************************************************
 * Set_SPCSO
 *******************************************************/
int		Set_SPCSO		(uint16_t QTnum, uint64_t currentTime ){

	int	ret = false;
	bool		Val;
//  ачество и врем€ мен€ем по надобности ---------------------------------------
	Quality		quality;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// мен€ть ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// мен€ть ли врем€
//	if(num > MB_MaxNumbLED)	return;
// -----------------------------------------------------------------------------

	if (num == 0 || num == 1){
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetError)	 Val = true; else Val = false;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  Val)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			ret = true;
		}
	}
	if (num == 0 || num == 2){
//		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote)	 Val = true; else Val = false;
		Val = NewSysNoteMessage;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  Val)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			ret = true;
		}
	}
	if (num == 0 || num == 3){
//		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetErrorNote)	 Val = true; else Val = false;
		Val = NewErrorNoteMessage;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  Val)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			ret = true;
		}
	}
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);

	if (
			(ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1) ||
			(ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2) ||
			(ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3) ||
			(ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4) ||
			(ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5) ||
			(ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6) ||
			(ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7) ||
			(ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8) ||
			(ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9) ||
			(ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10) ||
			(ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11) ||
			(ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12)
			)

	{
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  1)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			ret = true;
		}

	} else{
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  0)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			ret = true;
		}
	}
	//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);
return	ret;
}

#endif
