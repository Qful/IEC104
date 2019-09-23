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

#if defined	(MR801) && defined (OLD)
#include "static_model_MR801.h"
#endif

#if defined	(MR801) && defined (T12N5D58R51)
#include "static_model_MR801_T12N5D58R51.h"
#endif

extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];
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

				AddToQueueMB(ModbusSentQueue, 	MB_Rd_NumbSG		,MB_Slaveaddr);		// �������� ���������� ������. ���������
				Get_AllUstavki(ModbusSentQueue,MB_Slaveaddr);

				ret = true;
			}
			// -------------------- ���� �� ��������� ������� ������� ---------------------------
			if ((ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote)>0) {
				USART_TRACE("����� ������ ������� �������.\n");
				ucMDiscInBuf[MB_offset_Jurnals] ^= MB_bOffsetSysNote;


				AddToQueueMB(ModbusSentTime, 	MB_Wrt_Reset_SysNote	,MB_Slaveaddr);		// ������� ����
		    	AddToQueueMB(Rd_SysNoteQueue, 	MB_Wrt_SysNoteAdr0		,MB_Slaveaddr);	    // ��������� 0 �����
				AddToQueueMB(Rd_SysNoteQueue, 	MB_Rd_SysNote			,MB_Slaveaddr);	    // ��������� ������ �������

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

extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];
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
#if defined	(MR771) || defined	(MR761) || defined	(MR762) || defined	(MR763) || defined	(MR761OBR)

#if defined	(MR771)
#include "static_model_MR771.h"
#endif

#if defined	(MR761) || defined	(MR762) || defined	(MR763)
#include "static_model_MR76x.h"
#endif

#if  defined (MR761OBR)
#include "static_model_MR761OBR.h"
#endif

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
extern uint16_t   ucSGBuf[MB_Size_SG];
extern uint16_t   usConfigUstavkiStart;			// ������ �������

extern uint8_t				writeNmb;


/*******************************************************
 * Set_SG  �������� ������ �������
 *******************************************************/
int		Set_SG	(uint16_t QTnum, uint64_t currentTime )
{
	bool	ret = false;
	uint8_t	currSG = 0;

#if !defined (MR761OBR)
			if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG0)>0){ currSG = 1; usConfigUstavkiStart = MB_Addr_Ustavkiaddr0;}
	else	if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG1)>0){ currSG = 2; usConfigUstavkiStart = MB_StartUstavkiaddr1;}
	else	if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG2)>0){ currSG = 3; usConfigUstavkiStart = MB_StartUstavkiaddr2;}
	else	if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG3)>0){ currSG = 4; usConfigUstavkiStart = MB_StartUstavkiaddr3;}
	else	if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG4)>0){ currSG = 5; usConfigUstavkiStart = MB_StartUstavkiaddr4;}
	else	if ((ucMDiscInBuf[MB_offset_SG] & MB_bOffsetSG5)>0){ currSG = 6; usConfigUstavkiStart = MB_StartUstavkiaddr5;}

	ucSGBuf[0] = currSG;
#endif

#if defined (MR761OBR)
	currSG = ucSGBuf[0] + 1;

	// �������� ������ ������
	 {
		 uint16_t	adin = (uint16_t)MB_Size_Ustavki;					// ����� �������
		 adin = adin * ucSGBuf[0];
		 usConfigUstavkiStart = (uint16_t)MB_Addr_Ustavkiaddr0 + adin;
	 }

#endif


	if (currSG != IedServer_getActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0))) {
		IedServer_changeActiveSettingGroup(iedServer,LogicalDevice_getSettingGroupControlBlock(&iedModel_Generic_LD0),currSG );
			USART_TRACE("���������� ������ �������. %u\n",iedModel_LD0_LLN0_sgcb0.actSG);

// 18.03.2019 �������� �� �������������� ������� ��� ����� ������. ������� ������
//	    	AddToQueueMB(ModbusSentQueue, MB_Rd_Ustavki			,MB_Slaveaddr);		// ������ ������ �������� ����� �������
			AddToQueueMB(ModbusSentQueue, 	MB_Rd_NumbSG		,MB_Slaveaddr);		// �������� ���������� ������. ���������
			Get_AllUstavki(ModbusSentQueue,MB_Slaveaddr);

//	    	AddToQueueMB(ModbusSentQueue, MB_Rd_Ustavki			,MB_Slaveaddr);		// ������ ������ �������� ����� �������
//	    	AddToQueueMB(ModbusSentQueue, MB_Rd_ConfigSWCrash	,MB_Slaveaddr);
//	    	AddToQueueMB(ModbusSentQueue, MB_Rd_ConfigSW		,MB_Slaveaddr);
//	    	AddToQueueMB(ModbusSentQueue, MB_Rd_ConfigAutomat	,MB_Slaveaddr);

//			ReadAllUstavki(ModbusSentQueue, MB_Slaveaddr);						// ������ ���� �������

			ret = true;
	}
	// -------------------- ���� �� ���������  ---------------------------
	if ((ucMDiscInBuf[MB_offset_SysNote] & MB_bOffsetSysNote)>0) {
		USART_TRACE("����� ������ ������� �������.\n");
		writeNmb = 9;
		ucMDiscInBuf[MB_offset_SysNote] ^= MB_bOffsetSysNote;

		AddToQueueMB(ModbusSentTime, MB_Wrt_Reset_SysNote	,MB_Slaveaddr);		// ������� ����    ���� ModbusSentQueue
    	AddToQueueMB(Rd_SysNoteQueue, MB_Wrt_SysNoteAdr0	,MB_Slaveaddr);	    // ��������� 0 �����
		AddToQueueMB(Rd_SysNoteQueue, MB_Rd_SysNote			,MB_Slaveaddr);	    // ��������� ������ �������


#if ((defined	(MR761) || defined	(MR762) || defined	(MR763)) && (_REVISION_DEVICE <=303)) || (defined	(MR771) && (_REVISION_DEVICE <=106)) || defined	(MR761OBR)
		AddToQueueMB(ModbusSentQueue, 	MB_Rd_NumbSG		,MB_Slaveaddr);		// �������� ���������� ������. ���������
//		AddToQueueMB(ModbusSentQueue, 	MB_Rd_ConfigSW		,MB_Slaveaddr);		// � ������ �������
// ������� �������� � ������� ��������� ������ ������ �������
//		AddToQueueMB(ModbusSentQueue, MB_Rd_Ustavki			,MB_Slaveaddr);		// ������ ������ �������� ����� �������
#else
//TODO: ������ ������� ������� ������ �������. �� ������� �������. ���������� � 761 v3.04 �������� �������� "��������� ������".
/*
 * 0x200044D0 0x600B7476 [19.03.2019 14:53:26.925] DBG: �������� ������ �������.
0x200044D0 0x600B7476 [19.03.2019 14:53:26.926] DBG: IP �� MODBUS ��������� � ����������.
0x20004538 0x600B7476 [19.03.2019 14:53:26.937] DBG: ������ ��� cmd:19 addr:25A4 size:120 (err:0)
0x200044D0 0x600B7476 [19.03.2019 14:53:26.939] DBG: 0-121. �������� ������ �������.(0x25A4)
0x20004538 0x600B7476 [19.03.2019 14:53:26.949] DBG: ������ ��� cmd:19 addr:261C size:120 (err:0)
0x200044D0 0x600B7476 [19.03.2019 14:53:26.951] DBG: 120-241. �������� ������ �������.(0x261C)
0x20004538 0x600B7476 [19.03.2019 14:53:26.959] DBG: ������ ��� cmd:19 addr:2694 size:120 (err:0)
0x200044D0 0x600B7476 [19.03.2019 14:53:26.961] DBG: 240-361. �������� ������ �������.(0x2694)
0x20004538 0x600B7476 [19.03.2019 14:53:26.970] DBG: ������ ��� cmd:19 addr:270C size:120 (err:0)
0x20004538 0x600B7476 [19.03.2019 14:53:26.988] DBG: ������ ��� cmd:19 addr:2784 size:120 (err:0)
0x20004538 0x600B7476 [19.03.2019 14:53:26.999] DBG: ������ ��� cmd:19 addr:27FC size:120 (err:0)
0x20004538 0x600B7476 [19.03.2019 14:53:27.011] DBG: ������ ��� cmd:19 addr:2874 size:120 (err:0)
0x20004538 0x600B7476 [19.03.2019 14:53:27.028] DBG: ������ ��� cmd:19 addr:28EC size:120 (err:0)
0x20004538 0x600B7476 [19.03.2019 14:53:27.040] DBG: ������ ��� cmd:19 addr:2964 size:120 (err:0)
0x20004538 0x600B7476 [19.03.2019 14:53:27.050] DBG: ������ ��� cmd:19 addr:29DC size:28 (err:0)
0x20004538 0x600B7476 [19.03.2019 14:53:27.062] DBG: ������ ��� cmd:19 addr:29F8 size:120 (err:0)
0x200044D0 0x600B7476 [19.03.2019 14:53:27.067] DBG: 0-121. �������� ������ �������.(0x29F8)
0x20004538 0x600B7476 [19.03.2019 14:53:27.078] DBG: ������ ��� cmd:19 addr:2A70 size:120 (err:0)
0x200044D0 0x600B7476 [19.03.2019 14:53:27.080] DBG: 120-241. �������� ������ �������.(0x2A70)
0x20004538 0x600B7476 [19.03.2019 14:53:27.090] DBG: ������ ��� cmd:19 addr:2AE8 size:120 (err:0)
0x200044D0 0x600B7476 [19.03.2019 14:53:27.092] DBG: 240-361. �������� ������ �������.(0x2AE8)
0x20004538 0x600B7476 [19.03.2019 14:53:27.100] DBG: ������ ��� cmd:19 addr:2B60 size:59 (err:0)
0x200044D0 0x600B7476 [19.03.2019 14:53:27.102] DBG: 360-420. �������� ������ �������.(0x2B60)
 *
 */
		AddToQueueMB(ModbusSentQueue, 	MB_Rd_NumbSG		,MB_Slaveaddr);		// �������� ���������� ������. ���������
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
#if ((defined	(MR761) || defined	(MR762) || defined	(MR763)) && (_REVISION_DEVICE >303)) || (defined (MR771) && (_REVISION_DEVICE >106)) || defined	(MR761OBR)
	if ((ucMDiscInBuf[MB_offset_UstavkiModify] & MB_bOffset_errorUstavkiModify)>0) {
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

extern uint16_t   	ucMDiscInBuf[MB_Size_Discreet];
extern uint16_t   	ucSGBuf[MB_Size_SG];
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

extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];

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

