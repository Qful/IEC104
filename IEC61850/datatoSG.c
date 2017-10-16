/*
 * datatoSG.c
 *
 *  Created on: 03.05.2017
 *      Author: sagok
 */

#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "modbus.h"

extern 	xQueueHandle 	Rd_SysNoteQueue;		// ������� ��� �������� ������� �������

/*******************************************************
 * MR801
 *******************************************************/
#if defined (MR801)
#include "static_model_MR801.h"

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint8_t				writeNmb;
extern uint8_t	  			writeNmbSG;			// ����� ������ �������.

/*******************************************************
 * Set_SG  �������� ������ �������
 *******************************************************/
void	Set_SG	(uint8_t num, uint64_t currentTime )
{

			uint8_t	currSG = 0;
			if (ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG0){ currSG = 1;}
			else
			if (ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG1){ currSG = 2;}

			if (currSG != IedServer_getActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0))) {
				IedServer_changeActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0),currSG );
//				USART_TRACE("���������� ������ �������. %u\n",iedModel_LD0_LLN0_sgcb0.actSG);
			}
			// -------------------- ���� �� ��������� � �������� ---------------------------
			if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote) {
				USART_TRACE("���������� �������.\n");
				writeNmb = 9;
				ucMDiscInBuf[MB_offset_Jurnals] ^= MB_bOffsetSysNote;
			}

}

#endif
/*******************************************************
 * MR901 MR902
 *******************************************************/
#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint8_t				writeNmb;
extern uint8_t	  			writeNmbSG;			// ����� ������ �������.

/*******************************************************
 * Set_SG  �������� ������ �������
 *******************************************************/
void	Set_SG	(uint8_t num, uint64_t currentTime )
{

			uint8_t	currSG = 0;
			if (ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG0){ currSG = 1;}
			else
			if (ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG1){ currSG = 2;}

			if (currSG != IedServer_getActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0))) {
				IedServer_changeActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0),currSG );
//				USART_TRACE("���������� ������ �������. %u\n",iedModel_LD0_LLN0_sgcb0.actSG);
			}
			// -------------------- ���� �� ��������� � �������� ---------------------------
			if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote) {
				USART_TRACE("���������� �������.\n");
				writeNmb = 9;
				ucMDiscInBuf[MB_offset_Jurnals] ^= MB_bOffsetSysNote;
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
extern uint16_t   ucSGBuf[MB_NumbSG];

extern uint8_t				writeNmb;


/*******************************************************
 * Set_SG  �������� ������ �������
 *******************************************************/
void	Set_SG	(uint8_t num, uint64_t currentTime )
{
	uint8_t	currSG = 0;

	//currSG = ucMAnalogInBuf[MB_offset_SG] + 1;
	currSG = ucSGBuf[0] + 1;

	if (currSG != IedServer_getActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0))) {
		IedServer_changeActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0),currSG );
				USART_TRACE("���������� ������ �������. %u\n",iedModel_LD0_LLN0_sgcb0.actSG);
	}
	// -------------------- ���� �� ��������� � �������� ---------------------------
	if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote) {
		USART_TRACE("����� ������ ������� �������.\n");
		writeNmb = 9;
		ucMDiscInBuf[MB_offset_Jurnals] ^= MB_bOffsetSysNote;
	}
}

#endif

/*******************************************************
 * MR851
 *******************************************************/
#if defined (MR851)
#include "static_model_MR851.h"

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint8_t				writeNmb;
extern uint8_t	  			writeNmbSG;			// ����� ������ �������.

/*******************************************************
 * Set_SG  �������� ������ �������
 *******************************************************/
void	Set_SG	(uint8_t num, uint64_t currentTime )
{
		// -------------------- ���� �� ��������� � �������� ---------------------------
		if (ucMDiscInBuf[MB_offset_NewJurnalMs] & MB_bOffseNewJurnalMs) {
			USART_TRACE("���������� �������.\n");
			writeNmb = 5;
			ucMDiscInBuf[MB_offset_NewJurnalMs] ^= MB_bOffseNewJurnalMs;
		}
}
#endif

/*******************************************************
 * MR5 PO70
 *******************************************************/
#if defined (MR5_700) || defined (MR5_500)

#if defined (MR5_700)
#include "static_model_MR5_700.h"
#endif

#if defined (MR5_500)
#include "static_model_MR5_500.h"
#endif

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint8_t	  writeNmb;
extern uint8_t	  writeNmbSG;			// ����� ������ �������.
extern bool		  Reset_SysNoteNow;

/*******************************************************
 * Set_SG  �������� ������ �������
 *******************************************************/
void	Set_SG	(uint8_t num, uint64_t currentTime )
{
	 // ��������� ������ �������
	    uint8_t	currSG = 1;
	    if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetSettingGr) currSG = 2;

		if (currSG != IedServer_getActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0))) {
			IedServer_changeActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0),currSG );
			USART_TRACE("���������� ������ �������. %u\n",iedModel_LD0_LLN0_sgcb0.actSG);
		}

		// -------------------- ���� �� ��������� � �������� ---------------------------
	    if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetSysNote) {
	    	// ���� ��������� �������. ����� �� ����������.
	    	USART_TRACE("����� ������ � ������� �������.\n");
	    	Reset_SysNoteNow = true;
	    	writeNmb = MB_Wr_Reset_SysNote;
	    	ucMDiscInBuf[MB_offset_adr0] ^= MB_bOffsetSysNote;
	    }

}
#endif

/*******************************************************
 * MR5 PO60
 *******************************************************/
#if defined (MR5_600)
#include "static_model_MR5_600.h"

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint8_t	  writeNmb;
extern uint8_t	  writeNmbSG;			// ����� ������ �������.
extern bool		  Reset_SysNoteNow;
extern uint16_t			GlobalAddrSysNote;
extern	uint16_t   usSysNoteStart;

/*******************************************************
 * Set_SG  �������� ������ �������
 *******************************************************/
void	Set_SG	(uint8_t num, uint64_t currentTime )
{
	 // ��������� ������ �������
	    uint8_t	currSG = 1;
	    if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetSettingGr) currSG = 2;

		if (currSG != IedServer_getActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0))) {
			IedServer_changeActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0),currSG );
			USART_TRACE("���������� ������ �������. %u\n",iedModel_LD0_LLN0_sgcb0.actSG);
		}

		// -------------------- ���� �� ��������� � �������� ---------------------------
	    if (ucMDiscInBuf[MB_offset_adr0] & MB_bOffsetSysNote) {
	    	// ���� ��������� �������. ����� �� ����������.
	    	USART_TRACE("����� ������ � ������� �������.\n");
	    	Reset_SysNoteNow = true;
	    	writeNmb = MB_Wr_Reset_SysNote;
	    	ucMDiscInBuf[MB_offset_adr0] ^= MB_bOffsetSysNote;

            AddToFileMessageWord(_SystemNote,NULL,0,FA_CREATE_ALWAYS | FA_WRITE);

			AddToQueueMB(Rd_SysNoteQueue, MB_Wrt_Reset_SysNote	,MB_Slaveaddr);

			usSysNoteStart = MB_StartSysNoteaddr;
			GlobalAddrSysNote = 0;
        	AddToQueueMB(Rd_SysNoteQueue, MB_Rd_SysNote			,MB_Slaveaddr);

	    }

}
#endif
