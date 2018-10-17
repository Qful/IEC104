/*
 * IEC850.h
 *
 *  Created on: 09.12.2015
 *      Author: sagok
 */

/******************************************************************************
 *
 * Server			- ����������� ���������� (VMD)
 * logicalDevice 	- �����
 * logicalNode		- ���������� ����������
 * DataObject		- ���������� ����������
 *
 ******************************************************************************/
// ������� ������� ����� ������������
// ������ mms_server_conection.c
#ifndef IEC850_H_
#define IEC850_H_

#include "stack_config.h"

/* FatFs includes component */
#include "ff_gen_drv.h"
#include "sram_diskio.h"
#include "spi_diskio.h"


#define RECEIVE_BUF_SIZE 	MMS_MAXIMUM_PDU_SIZE
#define SEND_BUF_SIZE 		MMS_MAXIMUM_PDU_SIZE

#define ISO_CON_STATE_RUNNING 1
#define ISO_CON_STATE_STOPPED 0



// QUALITY Definitions and functions related to data attribute quality
// C�������� ���� ������ Quality ������������� ������� ���� ��������� ��������:

// ������� Validity ����� ����� ��������: good, questionable, invalid
#define QUALITY_VALIDITY_GOOD 0			// Good: �������� Validity ������������� ��� ��������, ���� �� ���������� � ������ ��������� ���������� ���������� �� ���������� �����-���� ��������������.
#define QUALITY_VALIDITY_INVALID 2		// Invalid: �������� Validity ������������� ��� ��������, ���� ���������� ������������� � ������ ��������� ����������. �������� invalid ���������� ������� � ���, ��� ���������� �� ���������� ������� � �� ������ ������������ ��� �����-���� �����.
#define QUALITY_VALIDITY_RESERVED 1
#define QUALITY_VALIDITY_QUESTIONABLE 3	// Questionable: �������� Validity ������������� ��� ��������, ���� ������� ��������������� ������������ ������������ ��������� �������, ���� ���� ������������ ���������� ����� ���������� ����������.

// �������� Validity �������� invalid � questionable ������������� � ����������� �� ��������� ������������� �������������� ��������������� �������� �������� detailQual.

#define QUALITY_DETAIL_OVERFLOW 4		// Overflow: 		���� ��������������� �������� ������ �� ����� ���� ��������� ������������ (������ ��� ���������).�������� ��������� ��������.
#define QUALITY_DETAIL_OUT_OF_RANGE 8	// OutOfRange: 		���� �������� ���������� �������� ������� �� ������� ����������������� ����������� ��������� ��������
#define QUALITY_DETAIL_BAD_REFERENCE 16	// BadReference: 	���� ���������� �������� ����������.
#define QUALITY_DETAIL_OSCILLATORY 32	// Oscillatory: 	��� �������������� �������� ���������� ������� �������� ������ ���������� ��������� ������ ��������� ��������� ���������� ������. ���� �� �������� ����� ������ ������ �������� ���� �������� �� ���� � �� ��, ����� ����������� ������� � ������ ���� ����������� ������������� oscillatory.
#define QUALITY_DETAIL_FAILURE 64		// Failure: 		���� ������� ��������������� ���������� ���������� ���������� ��� ������� �������������.
#define QUALITY_DETAIL_OLD_DATA 128		// oldData: 		���� ��������������� ������ �� ����������� � ������� ������������� �������.
#define QUALITY_DETAIL_INCONSISTENT 256	// inconsistency: 	���� ������� ��������������� ������������ �������������� ������ ����������������.
#define QUALITY_DETAIL_INACCURATE 512	// inaccurate:  	���� �������� ������ �� ������������� ��������� ���������� ���������������. ��������, �������� ������������ �������� ����� ����������� � ������� ������������ ��� ����� �����.
//
#define QUALITY_SOURCE_SUBSTITUTED 1024	// substituted: �������� ������ ��������������� �������������.
//
#define QUALITY_TEST 2048				// ������� Test ������ �������������� ��� ������������� ����, ��� ���������� ��������� � ������ ������������ � ������ ����������� �� �� ������ ���� ������������.
//
#define QUALITY_OPERATOR_BLOCKED  4096	// operatorBlocked: ������� ������ ���������� ��������, ���� ���������� ������ ����������� ����������. ������ ������ ��������� �� ��������, ������� ����� ����� �� ������� ����������. ��� ����������� ������� �������� ����� ������ ������������� ����������� �������������� oldData �������� DetailQual.
/*
 * �������� Validity � Source ����� �����������. ���� ������� source ����� �������� process, ����� ������� Validity ���������� �������� ������ ��������.
 * ���� ������� source ����� �������� substituted, ����� ������� Validity ���������� �������� ������������� ������������� ������. ��������� �����������
 * �����, ��������� ������ ������ ������������� �������������� ��� ����, ����� ��������� ���������������� (��������) ������. ����� �������, �������������
 * ������������� ������ ����� �������������� ��������� ��� �������������� (��� ������������� ��������  �������� Validity=good).
 *
 */

// ������� STVALINT32 ����� ����� ��������: ....
// MOD BEH
#define STVALINT32_ON 				1
#define STVALINT32_BLOCKED 			2
#define STVALINT32_TEST 			3
#define STVALINT32_TESTBLOCKED 		4
#define STVALINT32_OFF 				5

// ������� STVALINT32 ����� ����� ��������: ....
// HEALTH
#define STVALINT32_OK 				1
#define STVALINT32_Warning 			2
#define STVALINT32_Alarm 			3

// ������� STVALINT32 ����� ����� ��������: ....
#define STVALCODEDENUM_INTERMEDIATE		0
#define STVALCODEDENUM_OFF 				1
#define STVALCODEDENUM_ON 				2
#define STVALCODEDENUM_BADSTATE			3

// ������� STVALINT32 ����� ����� ��������: ....
#define STVALCODEDENUM_UNKNOWN			0
#define STVALCODEDENUM_FORWARD			1
#define STVALCODEDENUM_BACKWARD			2
#define STVALCODEDENUM_BOTH				3

// ������� STVALINT32 ����� ����� ��������: ....
#define STVALBITSTRING_STOP				0
#define STVALBITSTRING_HIGHER			1
#define STVALBITSTRING_LOWER			2
#define STVALBITSTRING_RESERVED			3


// ������� STVALINT32 ����� ����� ��������: ....
#define STVALCODEDENUM_POS_NEG_ZERO		0
#define STVALCODEDENUM_DIR_QUAD_ZERO	1


// ������� ctlModelENUM ����� ����� ��������: ....
#define CTLMODELEDENUM_statusOnly						0
#define CTLMODELEDENUM_DirectWithNormalSecurity 		1
#define CTLMODELEDENUM_SboWithNormalSecurity 			2
#define CTLMODELEDENUM_DirectWithEnhancedSecurity		3
#define CTLMODELEDENUM_SboWithEnhancedSecurity			4



// ����� Q T ��� ������� ��������� ������ � ���������
//#define QUALITY_mask 	0x8000
//#define TIME_mask 		0x4000
typedef enum
{
	QUALITY_mask = 0x8000,
	TIME_mask = 0x4000,
} QT_mask;

void 		ReStartIEC850_task(void);
void 		StartIEC850Task(void const * argument);
uint64_t 	Hal_getTimeInMs (void);

#endif /* IEC850_H_ */
