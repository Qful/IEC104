/*
 * datatoSG.c
 *
 *  Created on: 03.05.2017
 *      Author: sagok
 */

#include "main.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "modbus.h"

// -------------------- ������� -----------------
extern 	xQueueHandle 	Rd_SysNoteQueue;		// ������� ��� �������� ������� �������
extern	xQueueHandle 	Rd_ErrorNoteQueue;		// ������� ��� �������� ������� ������
extern  xQueueHandle 	Rd_OscNoteQueue;		// ������� ��� �������� ������� ������������

extern 	xQueueHandle 	ModbusSentQueue;		// ������� ��� �������� � ������
extern  xQueueHandle 	ModbusSentTime;			// ������� ������� ��� �������� � ������

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
int		Set_SG	(uint16_t QTnum, uint64_t currentTime )
{

	int	ret = false;

			uint8_t	currSG = 0;
			if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG0)>0){ currSG = 1;}
			else
			if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG1)>0){ currSG = 2;}

			if (currSG != IedServer_getActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0))) {
				IedServer_changeActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0),currSG );
				USART_TRACE("���������� ������ �������. %u\n",iedModel_LD0_LLN0_sgcb0.actSG);
				ret = true;
			}
			// -------------------- ���� �� ��������� ������� ������� ---------------------------
			if ((ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote)>0) {
				USART_TRACE("����� ������ ������� �������.\n");
				ucMDiscInBuf[MB_offset_Jurnals] ^= MB_bOffsetSysNote;


				AddToQueueMB(ModbusSentTime, 	MB_Wrt_Reset_SysNote	,MB_Slaveaddr);		// ������� ����    ���� ModbusSentQueue
		    	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // ��������� 0 �����
				AddToQueueMB(Rd_SysNoteQueue, 	MB_Rd_SysNote			,MB_Slaveaddr);	    // ��������� ������ �������

//				AddToQueueMB(ModbusSentQueue, 	MB_Wrt_OscNoteAdr0		,MB_Slaveaddr);		// ������ ������ ������ ������
//				AddToQueueMB(Rd_SysNoteQueue, 	MB_Rd_OscNote			,MB_Slaveaddr);		// ������ ������ ������ ������� ������.

				AddToQueueMB(ModbusSentQueue, 	MB_Rd_NumbSG			,MB_Slaveaddr);		// �������� ���������� ������. ���������
				AddToQueueMB(ModbusSentQueue, 	MB_Rd_ConfigSW			,MB_Slaveaddr);		// � ����������� ���� ��������� ����� ����

			}
			// -------------------- ���� �� ������ � ������� ������ -------------------------
		    if ((ucMDiscInBuf[MB_offset_ErrorNote] & MB_bOffsetErrorNote)>0) {

		    	USART_TRACE("����� ������ � ������� ������.\n");
		    	ucMDiscInBuf[MB_offset_ErrorNote] ^= MB_bOffsetErrorNote;

				AddToQueueMB(ModbusSentTime, 	MB_Wrt_Reset_ErrorNote	,MB_Slaveaddr);		// ������� ����
		    	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����
		    	AddToQueueMB(Rd_ErrorNoteQueue, MB_Rd_ErrorNote			,MB_Slaveaddr);	    // ��������� ������ �������

		    }

return	ret;
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
int		Set_SG	(uint16_t QTnum, uint64_t currentTime )
{

			uint8_t	currSG = 0;
			if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG0)>0){ currSG = 1;}
			else
			if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG1)>0){ currSG = 2;}

			if (currSG != IedServer_getActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0))) {
				IedServer_changeActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0),currSG );
//				USART_TRACE("���������� ������ �������. %u\n",iedModel_LD0_LLN0_sgcb0.actSG);
			}
			// -------------------- ���� �� ��������� � �������� ---------------------------
			if ((ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote)>0) {
				USART_TRACE("����� ������ � ������� �������.\n");
				writeNmb = 9;
				ucMDiscInBuf[MB_offset_Jurnals] ^= MB_bOffsetSysNote;

				AddToQueueMB(ModbusSentTime, MB_Wrt_Reset_SysNote	,MB_Slaveaddr);		// ������� ����    ���� ModbusSentQueue
		    	AddToQueueMB(Rd_SysNoteQueue, MB_Wrt_SysNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����
				AddToQueueMB(Rd_SysNoteQueue, MB_Rd_SysNote			,MB_Slaveaddr);	    // ��������� ������ �������

				AddToQueueMB(ModbusSentQueue, 	MB_Rd_NumbSG		,MB_Slaveaddr);		// �������� ���������� ������. ���������
				AddToQueueMB(ModbusSentQueue, 	MB_Rd_AllUstavki	,MB_Slaveaddr);		// ������ ����� �������

			}

			// -------------------- ���� �� ������ � ������� ������ -------------------------
		    if ((ucMDiscInBuf[MB_offset_ErrorNote] & MB_bOffsetErrorNote)>0) {

		    	USART_TRACE("����� ������ � ������� ������.\n");
		    	ucMDiscInBuf[MB_offset_ErrorNote] ^= MB_bOffsetErrorNote;

				AddToQueueMB(ModbusSentTime, 	MB_Wrt_Reset_ErrorNote	,MB_Slaveaddr);		// ������� ����
		    	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����
		    	AddToQueueMB(Rd_ErrorNoteQueue, MB_Rd_ErrorNote			,MB_Slaveaddr);	    // ��������� ������ �������

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
extern uint16_t   usConfigUstavkiStart;			// ������ �������

extern uint8_t				writeNmb;


/*******************************************************
 * Set_SG  �������� ������ �������
 *******************************************************/
int		Set_SG	(uint16_t QTnum, uint64_t currentTime )
{
	bool	ret = false;
	uint8_t	currSG = 0;

	//currSG = ucMAnalogInBuf[MB_offset_SG] + 1;
	currSG = ucSGBuf[0] + 1;

	// �������� ������ ������
	 {
		 uint16_t	adin = (uint16_t)MB_NumbUstavki;
		 adin = adin * ucSGBuf[0];
		 usConfigUstavkiStart = (uint16_t)MB_StartUstavkiaddr0 + adin;
	 }


	if (currSG != IedServer_getActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0))) {
		IedServer_changeActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0),currSG );
			USART_TRACE("���������� ������ �������. %u\n",iedModel_LD0_LLN0_sgcb0.actSG);

//	    	AddToQueueMB(ModbusSentQueue, MB_Rd_Ustavki			,MB_Slaveaddr);		// ������ ������ �������� ����� �������
//	    	AddToQueueMB(ModbusSentQueue, MB_Rd_ConfigSWCrash	,MB_Slaveaddr);
//	    	AddToQueueMB(ModbusSentQueue, MB_Rd_ConfigSW		,MB_Slaveaddr);
//	    	AddToQueueMB(ModbusSentQueue, MB_Rd_ConfigAutomat	,MB_Slaveaddr);

//			ReadAllUstavki(ModbusSentQueue, MB_Slaveaddr);						// ������ ���� �������

			ret = true;
	}
	// -------------------- ���� �� ���������  ---------------------------
	if ((ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote)>0) {
		USART_TRACE("����� ������ ������� �������.\n");
		writeNmb = 9;
		ucMDiscInBuf[MB_offset_Jurnals] ^= MB_bOffsetSysNote;

		AddToQueueMB(ModbusSentTime, MB_Wrt_Reset_SysNote	,MB_Slaveaddr);		// ������� ����    ���� ModbusSentQueue
    	AddToQueueMB(Rd_SysNoteQueue, MB_Wrt_SysNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����
		AddToQueueMB(Rd_SysNoteQueue, MB_Rd_SysNote			,MB_Slaveaddr);	    // ��������� ������ �������


#if ((defined	(MR761) || defined	(MR762) || defined	(MR763)) && (_REVISION_DEVICE <=302)) || (defined	(MR771) && (_REVISION_DEVICE <=106))
		AddToQueueMB(ModbusSentQueue, 	MB_Rd_NumbSG		,MB_Slaveaddr);		// �������� ���������� ������. ���������
//		AddToQueueMB(ModbusSentQueue, 	MB_Rd_ConfigSW		,MB_Slaveaddr);		// � ������ �������
// ������� �������� � ������� ��������� ������ ������ �������
//		AddToQueueMB(ModbusSentQueue, MB_Rd_Ustavki			,MB_Slaveaddr);		// ������ ������ �������� ����� �������
#endif
	}


	// -------------------- ���� �� ������ � ������� ������ -------------------------
    if ((ucMDiscInBuf[MB_offset_ErrorNote] & MB_bOffsetErrorNote)>0) {

    	USART_TRACE("����� ������ � ������� ������.\n");
    	ucMDiscInBuf[MB_offset_ErrorNote] ^= MB_bOffsetErrorNote;

		AddToQueueMB(ModbusSentTime, 	MB_Wrt_Reset_ErrorNote	,MB_Slaveaddr);		// ������� ����
    	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����
    	AddToQueueMB(Rd_ErrorNoteQueue, MB_Rd_ErrorNote			,MB_Slaveaddr);	    // ��������� ������ �������

    }

	// -------------------- ���� �� ��������� � �������� ---------------------------
	// ������� � ������� 1.07(MR771), ��� 303(MR761,MR762,MR763)
#if ((defined	(MR761) || defined	(MR762) || defined	(MR763)) && (_REVISION_DEVICE >302)) || (defined	(MR771) && (_REVISION_DEVICE >106))
	if ((ucMDiscInBuf[MB_offset_UstavkiModify] & MB_bOffsetUstavkiModify)>0) {
		USART_TRACE("���� ��������� � ��������\n");
		AddToQueueMB(ModbusSentQueue, MB_Wrt_Reset_Ustavki	,MB_Slaveaddr);		// ������� ���� ��������� �������
    	AddToQueueMB(ModbusSentQueue, MB_Rd_Ustavki			,MB_Slaveaddr);		// ������ ������ �������� ����� �������
		AddToQueueMB(ModbusSentQueue, 	MB_Rd_NumbSG		,MB_Slaveaddr);		// �������� ���������� ������. ���������

//		ReadAllUstavki(ModbusSentQueue, MB_Slaveaddr);							// ������ ���� �������
	}
#else

#endif
/*
	// -------------------- ���� �� ������ � ������� ������������ ------------------------- � ���� RDRE
    if (ucMDiscInBuf[MB_offset_OscNote] & MB_bOffsetOscNote) {
    	USART_TRACE("����� ������ � ������� ������������.\n");
    	ucMDiscInBuf[MB_offset_OscNote] ^= MB_bOffsetOscNote;
		AddToQueueMB(ModbusSentTime,  MB_Wrt_Reset_OscNote		,MB_Slaveaddr);		// ������� ����
		AddToQueueMB(Rd_SysNoteQueue, MB_Wrt_OscNoteAdr0		,MB_Slaveaddr);		// ������ ������ ������ ������
		AddToQueueMB(Rd_SysNoteQueue, MB_Rd_OscNote				,MB_Slaveaddr);	    // ��������� ������ ������� ������������
    }
*/
return	ret;
}

#endif

/*******************************************************
 * MR851
 *******************************************************/
#if defined (MR851)
#include "static_model_MR851.h"

extern uint16_t   	ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   	ucSGBuf[MB_NumbSG];
extern uint16_t   	usConfigUstavkiStart;			// ������ �������
extern uint8_t		writeNmb;



/*******************************************************
 * Set_SG  ���� ������ �������
 *******************************************************/
int		Set_SG	(uint16_t QTnum, uint64_t currentTime )
{
	bool		ret = false;
	uint8_t		currSG = 0;
	uint16_t	adrin;

	// -------------------- ���� �� ��������� ������� ������� ---------------------------
	if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote) {
		USART_TRACE("����� ������ ������� �������.\n");
		writeNmb = 5;
		ucMDiscInBuf[MB_offset_Jurnals] ^= MB_bOffsetSysNote;

		AddToQueueMB(ModbusSentQueue, 	MB_Rd_Ustavki		,MB_Slaveaddr);		// ������ ����� �������
		//AddToQueueMB(ModbusSentQueue, 	MB_Rd_NumbSG		,MB_Slaveaddr);		// �������� ���������� ������. ���������
		AddToQueueMB(ModbusSentQueue, MB_Rd_ConfigRPN		,MB_Slaveaddr);			// ������ ������ �������� ��������� ������� ���


		AddToQueueMB(ModbusSentTime, MB_Wrt_Reset_SysNote	,MB_Slaveaddr);		// ������� ����    ���� ModbusSentQueue
		AddToQueueMB(Rd_SysNoteQueue, MB_Wrt_SysNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����
		AddToQueueMB(Rd_SysNoteQueue, MB_Rd_SysNote			,MB_Slaveaddr);	    // ��������� ������ �������

	}
return	ret;
}
#endif

/*******************************************************
 * MR5
 *******************************************************/
#if defined (MR5_700) || defined (MR5_500) || defined (MR5_600) || defined (MR741)

#if defined (MR5_700)
#include "static_model_MR5_700.h"

extern uint16_t   usConfigStartMTZ;			// ������������ ������� �����
extern uint16_t   usConfigStartI2I1I0;		// ������������ �������������� ������
extern uint16_t   usConfigStartF;			// ������������ ������ �� �������
extern uint16_t   usConfigStartU;			// ������������ ������ �� ����������
#endif
#if defined (MR741)
#include "static_model_MR741.h"

extern uint16_t   usConfigStartMTZ;			// ������������ ������� �����
extern uint16_t   usConfigStartI2I1I0;		// ������������ �������������� ������
extern uint16_t   usConfigStartF;			// ������������ ������ �� �������
extern uint16_t   usConfigStartU;			// ������������ ������ �� ����������
#endif
#if defined (MR5_600)
#include "static_model_MR5_600.h"

extern uint16_t   usConfigStartF;		// ������������ ������ �� �������
extern uint16_t   usConfigStartU;		// ������������ ������ �� ����������
extern uint16_t   usConfigStartExZ;		// ������������ ������� �����
#endif

#if defined (MR5_500)
#include "static_model_MR5_500.h"

extern uint16_t   usConfigStartMTZ;		// ������������ ������� �����
extern uint16_t   usConfigStartI2I1I0;	// ������������ �������������� ������


#endif

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];

/*******************************************************
 * Set_SG  �������� ������ �������
 *******************************************************/
int		Set_SG	(uint16_t QTnum, uint64_t currentTime )
{
uint8_t	currSG = 1;

		// ��������� ������ �������
	    if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSettingGr)>0) currSG = 2;

		// ������� ����� ������ ������ ��� ������ �� ������� ��������, �������� ���� ������� ������
	    changeAddrUstSG(0);

		if (currSG != IedServer_getActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0))) {
			IedServer_changeActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0),currSG );
			USART_TRACE("���������� ������ �������. %u\n",iedModel_LD0_LLN0_sgcb0.actSG);

			// ��� ��������� ������ ������� ������ ���� ������ � �������. ����� ������ ������� �� ������ � ������� ����. � ������� �� ����� ��������� � ��������

#if defined (MR5_500)
	   		AddToQueueMB(ModbusSentQueue, 	MB_Rd_NumbSG		,MB_Slaveaddr);		// �������� ���������� ������. ���������
#endif
#if defined (MR5_600)
	   		AddToQueueMB(ModbusSentQueue, 	MB_Rd_NumbSG		,MB_Slaveaddr);		// �������� ���������� ������. ���������
#endif
#if defined (MR5_700) || defined (MR741)
	   		AddToQueueMB(ModbusSentQueue, 	MB_Rd_NumbSG		,MB_Slaveaddr);		// �������� ���������� ������. ���������
#endif

		}
		// -------------------- ���� �� ��������� � ������� ������� ---------------------------
	    if ((ucMDiscInBuf[MB_offset_SysNote] & MB_bOffsetSysNote)>0) {
	    	// ���� ��������� �������. ����� �� ����������.
	    	USART_TRACE("����� ������ � ������� �������.\n");
	    	ucMDiscInBuf[MB_offset_SysNote] ^= MB_bOffsetSysNote;

        	// ���� �� ���������� � ������� ���� �� ������������
//        	ReadAllUstavki(ModbusSentQueue, MB_Slaveaddr);							// ������ ���� �������
	   		AddToQueueMB(ModbusSentQueue, 	MB_Rd_NumbSG		,MB_Slaveaddr);		// �������� ���������� ������. ���������

	   		ResetAddrSysNote();

			AddToQueueMB(ModbusSentTime, MB_Wrt_Reset_SysNote	,MB_Slaveaddr);		// ������� ����
//		   	AddToQueueMB(Rd_SysNoteQueue, MB_Wrt_SysNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����
        	AddToQueueMB(Rd_SysNoteQueue, MB_Rd_SysNote			,MB_Slaveaddr);	    // ��������� ������ �������

	    }

		// -------------------- ���� �� ������ � ������� ������ -------------------------
	    if ((ucMDiscInBuf[MB_offset_ErrorNote] & MB_bOffsetErrorNote)>0) {

	    	USART_TRACE("����� ������ � ������� ������.\n");
	    	ucMDiscInBuf[MB_offset_ErrorNote] ^= MB_bOffsetErrorNote;

	    	ResetAddrErrorNote();

			AddToQueueMB(ModbusSentTime, 	MB_Wrt_Reset_ErrorNote	,MB_Slaveaddr);		// ������� ����
//		   	AddToQueueMB(Rd_ErrorNoteQueue,	MB_Wrt_ErrorNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����
        	AddToQueueMB(Rd_ErrorNoteQueue, MB_Rd_ErrorNote			,MB_Slaveaddr);	    // ��������� ������ �������

	    }
}
#endif

