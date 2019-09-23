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

#include "modbus.h"

#if (defined (MR801) && defined (OLD))
extern  uint16_t   ucMDiscInBuf[MB_Size_Discreet];
#endif
#if (defined (MR801) && defined (T12N5D58R51))
#include "static_model_MR801_T12N5D58R51.h"

extern uint16_t   		ucMDiscInBuf[MB_Size_Discreet];
extern xQueueHandle 	ModbusSentQueue;		// очередь для отправки в модбас
extern uint8_t	  		writeCMDNmb;


/*******************************************************
 * CMDGGIO
 *******************************************************/
uint16_t CMDBuf[MB_MaxNumbCommand][2] ={
		MB_offsetCommand_1,		MB_bOffset_Command_1,
		MB_offsetCommand_2,		MB_bOffset_Command_2,
		MB_offsetCommand_3,		MB_bOffset_Command_3,
		MB_offsetCommand_4,		MB_bOffset_Command_4,
		MB_offsetCommand_5,		MB_bOffset_Command_5,
		MB_offsetCommand_6,		MB_bOffset_Command_6,
		MB_offsetCommand_7,		MB_bOffset_Command_7,
		MB_offsetCommand_8,		MB_bOffset_Command_8,
		MB_offsetCommand_9,		MB_bOffset_Command_9,
		MB_offsetCommand_10,	MB_bOffset_Command_10,
		MB_offsetCommand_11,	MB_bOffset_Command_11,
		MB_offsetCommand_12,	MB_bOffset_Command_12,
		MB_offsetCommand_13,	MB_bOffset_Command_13,
		MB_offsetCommand_14,	MB_bOffset_Command_14,
		MB_offsetCommand_15,	MB_bOffset_Command_15,
		MB_offsetCommand_16,	MB_bOffset_Command_16,
		MB_offsetCommand_17,	MB_bOffset_Command_17,
		MB_offsetCommand_18,	MB_bOffset_Command_18,
		MB_offsetCommand_19,	MB_bOffset_Command_19,
		MB_offsetCommand_20,	MB_bOffset_Command_20,
		MB_offsetCommand_21,	MB_bOffset_Command_21,
		MB_offsetCommand_22,	MB_bOffset_Command_22,
		MB_offsetCommand_23,	MB_bOffset_Command_23,
		MB_offsetCommand_24,	MB_bOffset_Command_24,
};

DataAttribute* iedModel_CTRL_CMD24GGIO1_SPCSO_q[MB_MaxNumbCommand] = {
		&iedModel_CTRL_CMD24GGIO1_SPCSO1_q,		&iedModel_CTRL_CMD24GGIO1_SPCSO2_q,
		&iedModel_CTRL_CMD24GGIO1_SPCSO3_q,		&iedModel_CTRL_CMD24GGIO1_SPCSO4_q,
		&iedModel_CTRL_CMD24GGIO1_SPCSO5_q,		&iedModel_CTRL_CMD24GGIO1_SPCSO6_q,
		&iedModel_CTRL_CMD24GGIO1_SPCSO7_q,		&iedModel_CTRL_CMD24GGIO1_SPCSO8_q,
		&iedModel_CTRL_CMD24GGIO1_SPCSO9_q,		&iedModel_CTRL_CMD24GGIO1_SPCSO10_q,
		&iedModel_CTRL_CMD24GGIO1_SPCSO11_q,	&iedModel_CTRL_CMD24GGIO1_SPCSO12_q,
		&iedModel_CTRL_CMD24GGIO1_SPCSO13_q,	&iedModel_CTRL_CMD24GGIO1_SPCSO14_q,
		&iedModel_CTRL_CMD24GGIO1_SPCSO15_q,	&iedModel_CTRL_CMD24GGIO1_SPCSO16_q,
		&iedModel_CTRL_CMD24GGIO1_SPCSO17_q,	&iedModel_CTRL_CMD24GGIO1_SPCSO18_q,
		&iedModel_CTRL_CMD24GGIO1_SPCSO19_q,	&iedModel_CTRL_CMD24GGIO1_SPCSO20_q,
		&iedModel_CTRL_CMD24GGIO1_SPCSO21_q,	&iedModel_CTRL_CMD24GGIO1_SPCSO22_q,
		&iedModel_CTRL_CMD24GGIO1_SPCSO23_q,	&iedModel_CTRL_CMD24GGIO1_SPCSO24_q,

};

DataAttribute* iedModel_CTRL_CMD24GGIO1_SPCSO_t[MB_MaxNumbCommand] = {
		&iedModel_CTRL_CMD24GGIO1_SPCSO1_t,		&iedModel_CTRL_CMD24GGIO1_SPCSO2_t,
		&iedModel_CTRL_CMD24GGIO1_SPCSO3_t,		&iedModel_CTRL_CMD24GGIO1_SPCSO4_t,
		&iedModel_CTRL_CMD24GGIO1_SPCSO5_t,		&iedModel_CTRL_CMD24GGIO1_SPCSO6_t,
		&iedModel_CTRL_CMD24GGIO1_SPCSO7_t,		&iedModel_CTRL_CMD24GGIO1_SPCSO8_t,
		&iedModel_CTRL_CMD24GGIO1_SPCSO9_t,		&iedModel_CTRL_CMD24GGIO1_SPCSO10_t,
		&iedModel_CTRL_CMD24GGIO1_SPCSO11_t,	&iedModel_CTRL_CMD24GGIO1_SPCSO12_t,
		&iedModel_CTRL_CMD24GGIO1_SPCSO13_t,	&iedModel_CTRL_CMD24GGIO1_SPCSO14_t,
		&iedModel_CTRL_CMD24GGIO1_SPCSO15_t,	&iedModel_CTRL_CMD24GGIO1_SPCSO16_t,
		&iedModel_CTRL_CMD24GGIO1_SPCSO17_t,	&iedModel_CTRL_CMD24GGIO1_SPCSO18_t,
		&iedModel_CTRL_CMD24GGIO1_SPCSO19_t,	&iedModel_CTRL_CMD24GGIO1_SPCSO20_t,
		&iedModel_CTRL_CMD24GGIO1_SPCSO21_t,	&iedModel_CTRL_CMD24GGIO1_SPCSO22_t,
		&iedModel_CTRL_CMD24GGIO1_SPCSO23_t,	&iedModel_CTRL_CMD24GGIO1_SPCSO24_t,

};

DataAttribute* iedModel_CTRL_CMD24GGIO1_SPCSO_stVal[MB_MaxNumbCommand] = {
		&iedModel_CTRL_CMD24GGIO1_SPCSO1_stVal,	&iedModel_CTRL_CMD24GGIO1_SPCSO2_stVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO3_stVal,	&iedModel_CTRL_CMD24GGIO1_SPCSO4_stVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO5_stVal,	&iedModel_CTRL_CMD24GGIO1_SPCSO6_stVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO7_stVal,	&iedModel_CTRL_CMD24GGIO1_SPCSO8_stVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO9_stVal,	&iedModel_CTRL_CMD24GGIO1_SPCSO10_stVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO11_stVal,&iedModel_CTRL_CMD24GGIO1_SPCSO12_stVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO13_stVal,&iedModel_CTRL_CMD24GGIO1_SPCSO14_stVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO15_stVal,&iedModel_CTRL_CMD24GGIO1_SPCSO16_stVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO17_stVal,&iedModel_CTRL_CMD24GGIO1_SPCSO18_stVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO19_stVal,&iedModel_CTRL_CMD24GGIO1_SPCSO20_stVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO21_stVal,&iedModel_CTRL_CMD24GGIO1_SPCSO22_stVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO23_stVal,&iedModel_CTRL_CMD24GGIO1_SPCSO24_stVal,
};

DataAttribute* iedModel_CTRL_CMD24GGIO1_SPCSO_Oper_T[MB_MaxNumbCommand] = {
		&iedModel_CTRL_CMD24GGIO1_SPCSO1_Oper_T,&iedModel_CTRL_CMD24GGIO1_SPCSO2_Oper_T,
		&iedModel_CTRL_CMD24GGIO1_SPCSO3_Oper_T,&iedModel_CTRL_CMD24GGIO1_SPCSO4_Oper_T,
		&iedModel_CTRL_CMD24GGIO1_SPCSO5_Oper_T,&iedModel_CTRL_CMD24GGIO1_SPCSO6_Oper_T,
		&iedModel_CTRL_CMD24GGIO1_SPCSO7_Oper_T,&iedModel_CTRL_CMD24GGIO1_SPCSO8_Oper_T,
		&iedModel_CTRL_CMD24GGIO1_SPCSO9_Oper_T,&iedModel_CTRL_CMD24GGIO1_SPCSO10_Oper_T,
		&iedModel_CTRL_CMD24GGIO1_SPCSO11_Oper_T,&iedModel_CTRL_CMD24GGIO1_SPCSO12_Oper_T,
		&iedModel_CTRL_CMD24GGIO1_SPCSO13_Oper_T,&iedModel_CTRL_CMD24GGIO1_SPCSO14_Oper_T,
		&iedModel_CTRL_CMD24GGIO1_SPCSO15_Oper_T,&iedModel_CTRL_CMD24GGIO1_SPCSO16_Oper_T,
		&iedModel_CTRL_CMD24GGIO1_SPCSO17_Oper_T,&iedModel_CTRL_CMD24GGIO1_SPCSO18_Oper_T,
		&iedModel_CTRL_CMD24GGIO1_SPCSO19_Oper_T,&iedModel_CTRL_CMD24GGIO1_SPCSO20_Oper_T,
		&iedModel_CTRL_CMD24GGIO1_SPCSO21_Oper_T,&iedModel_CTRL_CMD24GGIO1_SPCSO22_Oper_T,
		&iedModel_CTRL_CMD24GGIO1_SPCSO23_Oper_T,&iedModel_CTRL_CMD24GGIO1_SPCSO24_Oper_T,
};

DataAttribute* iedModel_CTRL_CMD24GGIO1_SPCSO_Oper_ctlVal[MB_MaxNumbCommand] = {
		&iedModel_CTRL_CMD24GGIO1_SPCSO1_Oper_ctlVal,&iedModel_CTRL_CMD24GGIO1_SPCSO2_Oper_ctlVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO3_Oper_ctlVal,&iedModel_CTRL_CMD24GGIO1_SPCSO4_Oper_ctlVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO5_Oper_ctlVal,&iedModel_CTRL_CMD24GGIO1_SPCSO6_Oper_ctlVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO7_Oper_ctlVal,&iedModel_CTRL_CMD24GGIO1_SPCSO8_Oper_ctlVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO9_Oper_ctlVal,&iedModel_CTRL_CMD24GGIO1_SPCSO10_Oper_ctlVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO11_Oper_ctlVal,&iedModel_CTRL_CMD24GGIO1_SPCSO12_Oper_ctlVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO13_Oper_ctlVal,&iedModel_CTRL_CMD24GGIO1_SPCSO14_Oper_ctlVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO15_Oper_ctlVal,&iedModel_CTRL_CMD24GGIO1_SPCSO16_Oper_ctlVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO17_Oper_ctlVal,&iedModel_CTRL_CMD24GGIO1_SPCSO18_Oper_ctlVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO19_Oper_ctlVal,&iedModel_CTRL_CMD24GGIO1_SPCSO20_Oper_ctlVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO21_Oper_ctlVal,&iedModel_CTRL_CMD24GGIO1_SPCSO22_Oper_ctlVal,
		&iedModel_CTRL_CMD24GGIO1_SPCSO23_Oper_ctlVal,&iedModel_CTRL_CMD24GGIO1_SPCSO24_Oper_ctlVal,
};
#endif

extern bool		NewSysNoteMessage;
extern bool		NewErrorNoteMessage;

/*******************************************************
 * MR5_500 MR5_600 MR5_700
 *******************************************************/
#if defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)

extern  uint16_t   ucMDiscInBuf[MB_Size_Discreet];

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
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
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

extern  uint16_t   ucMDiscInBuf[MB_Size_Discreet];
/*******************************************************
 * Set_SPCSO
 *******************************************************/
int		Set_SPCSO		(uint16_t QTnum, uint64_t currentTime ){

	int	ret = false;
	bool		Val;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
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
 * MR801-T12N5D58R51
 *******************************************************/
#if (defined (MR801) && defined (T12N5D58R51))
#include "static_model_MR801_T12N5D58R51.h"

/*******************************************************
 * Set_SPCSO
 *******************************************************/
int		Set_SPCSO		(uint16_t QTnum, uint64_t currentTime ){

	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	uint8_t		i;

	int	ret = false;
	bool		Val;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время

// -----------------------------------------------------------------------------
	if (num == 0 || num == 1){
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetError)	 Val = true; else Val = false;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  Val)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			ret = true;
		}
	}
// -----------------------------------------------------------------------------
	if (num == 0 || num == 2){
		Val = NewSysNoteMessage;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  Val)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			ret = true;
		}
	}
// -----------------------------------------------------------------------------
	if (num == 0 || num == 3){
		Val = NewErrorNoteMessage;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  Val)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			ret = true;
		}
	}
// -----------------------------------------------------------------------------
	if (num == 0 || num == 4){
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
				(ucMDiscInBuf[MB_offsetLED_1r]  & MB_bOffset_LED_1r) ||
				(ucMDiscInBuf[MB_offsetLED_2r]  & MB_bOffset_LED_2r) ||
				(ucMDiscInBuf[MB_offsetLED_3r]  & MB_bOffset_LED_3r) ||
				(ucMDiscInBuf[MB_offsetLED_4r]  & MB_bOffset_LED_4r) ||
				(ucMDiscInBuf[MB_offsetLED_5r]  & MB_bOffset_LED_5r) ||
				(ucMDiscInBuf[MB_offsetLED_6r]  & MB_bOffset_LED_6r) ||
				(ucMDiscInBuf[MB_offsetLED_7r]  & MB_bOffset_LED_7r) ||
				(ucMDiscInBuf[MB_offsetLED_8r]  & MB_bOffset_LED_8r) ||
				(ucMDiscInBuf[MB_offsetLED_9r]  & MB_bOffset_LED_9r) ||
				(ucMDiscInBuf[MB_offsetLED_10r] & MB_bOffset_LED_10r)||
				(ucMDiscInBuf[MB_offsetLED_11r] & MB_bOffset_LED_11r)||
				(ucMDiscInBuf[MB_offsetLED_12r] & MB_bOffset_LED_12r)
				)
		{
			Val = 1;
		} else{
			Val = 0;
		}

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  Val)){
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			ret = true;
		}
		//if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);
	}

// -----------------------------------------------------------------------------

// CMD ----------------------------------------------------------------------------------
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CMD24GGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_CMD24GGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CMD24GGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_CMD24GGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CMD24GGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_CMD24GGIO1_Beh_t, currentTime);
	}

	for (i = 0; i < MB_MaxNumbCommand; i++) {
		if (num == 0 || num == i+5){
			bool value = false;
			if ((ucMDiscInBuf[CMDBuf[i][0]] & CMDBuf[i][1]) > 0) value = true;

			if (Q){
				//if (i>=_begin_Relay_M1 && i<=_end_Relay_M1) quality = qualityM1;
				if (T) {ret |= IedServer_updateQualityWithTime	(iedServer, iedModel_CTRL_CMD24GGIO1_SPCSO_q[i], iedModel_CTRL_CMD24GGIO1_SPCSO_t[i], currentTime, quality);}
				else   {ret |= IedServer_updateQuality			(iedServer, iedModel_CTRL_CMD24GGIO1_SPCSO_q[i], quality);}
			}

			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_CTRL_CMD24GGIO1_SPCSO_stVal[i], iedModel_CTRL_CMD24GGIO1_SPCSO_t[i], currentTime, value);}
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_CTRL_CMD24GGIO1_SPCSO_stVal[i], value);}

		}
	}//!for (i...
// --------------------------------------------------------------------------------------

return ret;
}

#endif
/*******************************************************
 * MR771 MR761 MR762 MR763
 *******************************************************/
#if defined	(MR771) || defined	(MR761) || defined	(MR762) || defined	(MR763) || defined	(MR761OBR)

extern  uint16_t   ucMDiscInBuf[MB_Size_Discreet];

#if defined	(MR771)
#include "static_model_MR771.h"
#endif

#if defined	(MR761) || defined	(MR762) || defined	(MR763)
#include "static_model_MR76x.h"
#endif

#if  defined (MR761OBR)
#include "static_model_MR761OBR.h"
#endif


/*******************************************************
 * Set_SPCSO
 *******************************************************/
int		Set_SPCSO		(uint16_t QTnum, uint64_t currentTime ){

	int	ret = false;
	bool		Val;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
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
			(ucMDiscInBuf[MB_offsetLED_1r]  & MB_bOffset_LED_1r) ||
			(ucMDiscInBuf[MB_offsetLED_2r]  & MB_bOffset_LED_2r) ||
			(ucMDiscInBuf[MB_offsetLED_3r]  & MB_bOffset_LED_3r) ||
			(ucMDiscInBuf[MB_offsetLED_4r]  & MB_bOffset_LED_4r) ||
			(ucMDiscInBuf[MB_offsetLED_5r]  & MB_bOffset_LED_5r) ||
			(ucMDiscInBuf[MB_offsetLED_6r]  & MB_bOffset_LED_6r) ||
			(ucMDiscInBuf[MB_offsetLED_7r]  & MB_bOffset_LED_7r) ||
			(ucMDiscInBuf[MB_offsetLED_8r]  & MB_bOffset_LED_8r) ||
			(ucMDiscInBuf[MB_offsetLED_9r]  & MB_bOffset_LED_9r) ||
			(ucMDiscInBuf[MB_offsetLED_10r] & MB_bOffset_LED_10r)||
			(ucMDiscInBuf[MB_offsetLED_11r] & MB_bOffset_LED_11r)||
			(ucMDiscInBuf[MB_offsetLED_12r] & MB_bOffset_LED_12r)
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

#if  defined (MR761OBR)
		// iedModel_CTRL_GGIO2_SPCSOx_stVal		появляется в импульсном режиме. пока нет смысла его отображать
#endif

return ret;
}

#endif
/*******************************************************
 * MR801 MR901 MR902
 *******************************************************/
#if (defined (MR801) && defined (OLD)) || defined (MR901) || defined (MR902)

#if (defined (MR801) && defined (OLD))
#include "static_model_MR801.h"
#endif

#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"
extern  uint16_t   ucMDiscInBuf[MB_Size_Discreet];

#endif



/*******************************************************
 * Set_SPCSO
 *******************************************************/
int		Set_SPCSO		(uint16_t QTnum, uint64_t currentTime ){

	int	ret = false;
	bool		Val;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
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


#if  defined (MR761OBR)

extern uint8_t	  			writeCMDNmb;		// команды для 761ОБР.
extern 	xQueueHandle 	ModbusSentQueue;		// очередь для отправки в модбас


void	GGIO2_SPCSOx_Oper(uint8_t numb, bool newState, uint64_t timeStamp);

/*************************************************************************
 * controlHandlerForBinaryOutput
 *  Функция контроля над бинарным объектом. После изменения этих данных от
 *  клиента, будет вызываться эта функция.
 *************************************************************************/
void	controlHandlerFor_GGIO2_SPCSOx(void* parameter, MmsValue* value, bool test){

	MmsType		TypeCMD;
	bool 		newState = false;
	uint16_t 	newStateBitstr = 0;
	uint8_t		num=0;
	uint64_t timeStamp;

//	USART_TRACE_GREEN("controlHandlerFor_GGIO2_SPCSOx MMS_BOOLEAN:\n");

	TypeCMD = MmsValue_getType(value);
	switch(TypeCMD){

	case	MMS_BOOLEAN:
						  newState = MmsValue_getBoolean(value);
		break;
	case	MMS_BIT_STRING:
						 newStateBitstr = MmsValue_getBitStringAsInteger(value);
		break;
	default:
		 USART_TRACE_RED("команда не опознана\n");
		break;
	}

	timeStamp = Hal_getTimeInMs();

	if (parameter == &iedModel_CTRL_GGIO2_SPCSO1_Oper)	num = 1;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO2_Oper)	num = 2;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO3_Oper)	num = 3;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO4_Oper)	num = 4;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO5_Oper)	num = 5;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO6_Oper)	num = 6;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO7_Oper)	num = 7;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO8_Oper)	num = 8;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO9_Oper)	num = 9;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO10_Oper)	num = 10;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO11_Oper)	num = 11;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO12_Oper)	num = 12;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO13_Oper)	num = 13;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO14_Oper)	num = 14;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO15_Oper)	num = 15;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO16_Oper)	num = 16;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO17_Oper)	num = 17;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO18_Oper)	num = 18;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO19_Oper)	num = 19;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO20_Oper)	num = 20;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO21_Oper)	num = 21;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO22_Oper)	num = 22;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO23_Oper)	num = 23;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO24_Oper)	num = 24;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO25_Oper)	num = 25;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO26_Oper)	num = 26;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO27_Oper)	num = 27;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO28_Oper)	num = 28;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO29_Oper)	num = 29;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO30_Oper)	num = 30;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO31_Oper)	num = 31;
	if (parameter == &iedModel_CTRL_GGIO2_SPCSO32_Oper)	num = 32;

	GGIO2_SPCSOx_Oper(num, newState, timeStamp);
	 if (newState)	{USART_TRACE_GREEN("команда GGIO2_SPCSO%u on\n",num);}
	 else  			{USART_TRACE_RED("команда GGIO2_SPCSO%u off\n",num);}


}

/*******************************************************
 * GGIO2_SPCSOx_Oper
 *******************************************************/
void	setControlGGIO2_SPCSOx(IedServer self){

	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO1, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO1_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO2, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO2_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO3, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO3_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO4, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO4_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO5, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO5_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO6, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO6_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO7, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO7_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO8, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO8_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO9, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO9_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO10,(ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO10_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO11, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO11_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO12, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO12_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO13, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO13_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO14, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO14_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO15, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO15_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO16, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO16_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO17, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO17_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO18, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO18_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO19, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO19_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO20, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO20_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO21, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO21_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO22, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO22_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO23, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO23_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO24, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO24_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO25, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO25_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO26, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO26_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO27, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO27_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO28, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO28_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO29, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO29_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO30, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO30_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO31, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO31_Oper);
	IedServer_setControlHandler(self, &iedModel_CTRL_GGIO2_SPCSO32, (ControlHandler) controlHandlerFor_GGIO2_SPCSOx,&iedModel_CTRL_GGIO2_SPCSO32_Oper);
}

/*******************************************************
 * GGIO2_SPCSOx_Oper
 *******************************************************/
void	GGIO2_SPCSOx_Oper(uint8_t numb, bool newState, uint64_t timeStamp)
{
	switch (numb){
	case 1:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO1_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO1_Oper_ctlVal, 0);
	break;
	case 2:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO2_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO2_Oper_ctlVal, 0);
	break;
	case 3:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO3_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO3_Oper_ctlVal, 0);
	break;
	case 4:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO4_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO4_Oper_ctlVal, 0);
	break;
	case 5:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO5_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO5_Oper_ctlVal, 0);
	break;
	case 6:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO6_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO6_Oper_ctlVal, 0);
	break;
	case 7:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO7_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO7_Oper_ctlVal, 0);
	break;
	case 8:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO8_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO8_Oper_ctlVal, 0);
	break;
	case 9:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO9_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO9_Oper_ctlVal, 0);
	break;
	case 10:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO10_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO10_Oper_ctlVal, 0);
	break;
	case 11:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO11_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO11_Oper_ctlVal, 0);
	break;
	case 12:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO12_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO12_Oper_ctlVal, 0);
	break;
	case 13:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO13_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO13_Oper_ctlVal, 0);
	break;
	case 14:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO14_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO14_Oper_ctlVal, 0);
	break;
	case 15:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO15_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO15_Oper_ctlVal, 0);
	break;
	case 16:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO16_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO16_Oper_ctlVal, 0);
	break;
	case 17:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO17_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO17_Oper_ctlVal, 0);
	break;
	case 18:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO18_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO18_Oper_ctlVal, 0);
	break;
	case 19:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO19_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO19_Oper_ctlVal, 0);
	break;
	case 20:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO20_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO20_Oper_ctlVal, 0);
	break;
	case 21:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO21_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO21_Oper_ctlVal, 0);
	break;
	case 22:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO22_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO22_Oper_ctlVal, 0);
	break;
	case 23:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO23_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO23_Oper_ctlVal, 0);
	break;
	case 24:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO24_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO24_Oper_ctlVal, 0);
	break;
	case 25:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO25_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO25_Oper_ctlVal, 0);
	break;
	case 26:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO26_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO26_Oper_ctlVal, 0);
	break;
	case 27:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO27_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO27_Oper_ctlVal, 0);
	break;
	case 28:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO28_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO28_Oper_ctlVal, 0);
	break;
	case 29:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO29_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO29_Oper_ctlVal, 0);
	break;
	case 30:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO30_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO30_Oper_ctlVal, 0);
	break;
	case 31:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO31_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO31_Oper_ctlVal, 0);
	break;
	case 32:
	    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO32_Oper_T, timeStamp);
	    IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO2_SPCSO32_Oper_ctlVal, 0);
	break;

default:
	break;
	}
     if (newState) {
    	writeCMDNmb = numb;
    	AddToQueueMB(ModbusSentQueue, MB_Wrt_CMD_set_ManNumb			,MB_Slaveaddr);
    }
}
#endif

#if (defined (MR801) && defined (T12N5D58R51))
#include "static_model_MR801_T12N5D58R51.h"

/*************************************************************************
 * controlHandlerFor_CMDGGIO
 *************************************************************************/
void	controlHandlerFor_CMDGGIO(void* parameter, MmsValue* value, bool test)
{
	if (value == NULL) return;

	MmsType		TypeCMD = MmsValue_getType(value);
	if (TypeCMD != MMS_BOOLEAN)	return;				//если не бинарное управление то выходим

    uint64_t timeStamp = Hal_getTimeInMs();

	USART_TRACE("управление MMS_BOOLEAN: ");
	if (MmsValue_getBoolean(value))	{USART_0TRACE("on\n");}
	else  							{USART_0TRACE("off\n");}

	bool newState = MmsValue_getBoolean(value);

	writeCMDNmb = (uint8_t)parameter;
	AddToQueueMB(ModbusSentQueue, MB_Wrt_CMD_set_ManNumb ,MB_Slaveaddr);

	IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_CTRL_CMD24GGIO1_SPCSO_Oper_T[writeCMDNmb], timeStamp);
	IedServer_updateBooleanAttributeValue(iedServer, iedModel_CTRL_CMD24GGIO1_SPCSO_Oper_ctlVal[writeCMDNmb], newState);

}
#endif
