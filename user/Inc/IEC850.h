/*
 * IEC850.h
 *
 *  Created on: 09.12.2015
 *      Author: sagok
 */

/******************************************************************************
 *
 * Server			- Виртуальное устройство (VMD)
 * logicalDevice 	- ДОМЕН
 * logicalNode		- Именованая Переменная
 * DataObject		- Именованая Переменная
 *
 ******************************************************************************/
// сервисы которые будем поддерживать
// смотри mms_server_conection.c
#ifndef IEC850_H_
#define IEC850_H_

#include "stack_config.h"

/* FatFs includes component */
#include "ff_gen_drv.h"
#include "sram_diskio.h"

#define RECEIVE_BUF_SIZE 	MMS_MAXIMUM_PDU_SIZE
#define SEND_BUF_SIZE 		MMS_MAXIMUM_PDU_SIZE

#define ISO_CON_STATE_RUNNING 1
#define ISO_CON_STATE_STOPPED 0



// QUALITY Definitions and functions related to data attribute quality
// Cтруктура типа данных Quality подразумевает наличие ряда атрибутов качества:

// Атрибут Validity может иметь значения: good, questionable, invalid
#define QUALITY_VALIDITY_GOOD 0			// Good: атрибуту Validity присваивается это значение, если не обнаружено в работе источника получаемой информации не обнаружено каких-либо неисправностей.
#define QUALITY_VALIDITY_INVALID 2		// Invalid: атрибуту Validity присваивается это значение, если обнаружена неисправность в работе источника информации. Значение invalid индицирует клиенту о том, что получаемая им информация неверна и ее нельзя использовать для каких-либо целей.
#define QUALITY_VALIDITY_RESERVED 1
#define QUALITY_VALIDITY_QUESTIONABLE 3	// Questionable: атрибуту Validity присваивается это значение, если функция самодиагностики обнаруживает ненормальное поведение сервера, хотя сама передаваемая информация может оставаться актуальной.

// Атрибуту Validity значения invalid и questionable присваиваются в зависимости от состояния перечисленных дополнительных идентификаторов качества атрибута detailQual.

#define QUALITY_DETAIL_OVERFLOW 4		// Overflow: активация этого идентификатора должна производиться в том случае, если соответствующее значение данных не может быть правильно представлено (только для измерений).Например превышать диапазон.
#define QUALITY_DETAIL_OUT_OF_RANGE 8	// OutOfRange: активация этого идентификатора должна производиться в том случае, если значение измеренной величины выходит за пределы предопределенного допустимого диапазона значений
#define QUALITY_DETAIL_BAD_REFERENCE 16	// BadReference: активация этого идентификатора должна производиться в том случае, если устройство потеряло калибровку.
#define QUALITY_DETAIL_OSCILLATORY 32	// Oscillatory: для предотвращения излишней перегрузки каналов передачи данных желательно подавлять частые изменения состояний дискретных входов. Если за заданное время сигнал дважды изменяет свое значение на одно и то же, тогда фиксируется дребезг и должен быть активирован идентификатор oscillatory.
#define QUALITY_DETAIL_FAILURE 64		// Failure: данный идентификатор должен активироваться, если функция самодиагностики устройства обнаружила внутреннюю или внешнюю неисправность.
#define QUALITY_DETAIL_OLD_DATA 128		// oldData: данный идентификатор должен активироваться, если соответствующие данные не обновлялись в течение определенного времени.
#define QUALITY_DETAIL_INCONSISTENT 256	// inconsistency: данный идентификатор должен активироваться, если функция самодиагностики обнаруживает несоответствие данных действительности.
#define QUALITY_DETAIL_INACCURATE 512	// inaccurate: данный идентификатор должен активироваться, если значение данных не соответствует требуемым точностным характеристикам. Например, значение коэффициента мощности может вычисляться с большой погрешностью при малых токах.
//
#define QUALITY_SOURCE_SUBSTITUTED 1024	// substituted: значение данных устанавливается пользователем.
//
#define QUALITY_TEST 2048				// Атрибут Test должен использоваться для идентификации того, что устройство находится в режиме тестирования и данные формируемые им не должны быть использованы.
//
#define QUALITY_OPERATOR_BLOCKED  4096	// operatorBlocked: атрибут должен становится активным, если обновление данных блокируется оператором. Данные должны сохранять то значение, которое имело место до момента блокировки. При активизации данного атрибута также должна производиться активизация идентификатора oldData атрибута DetailQual.
/*
 * Атрибуты Validity и Source имеют взаимосвязь. Если атрибут source имеет значение process, тогда атрибут Validity определяет качество данных процесса.
 * Если атрибут source имеет значение substituted, тогда атрибут Validity определяет качество установленных пользователем данных. Указанная особенность
 * важна, поскольку замена данных пользователем осуществляется для того, чтобы исключить недействительные (неверные) данные. Таким образом, установленные
 * пользователем данные могут использоваться клиентами как действительные (что соответствует значению  атрибута Validity=good).
 *
 */

// Атрибут STVALINT32 может иметь значения: ....
#define STVALINT32_ON 				1
#define STVALINT32_BLOCKED 			2
#define STVALINT32_TEST 			3
#define STVALINT32_TESTBLOCKED 		4
#define STVALINT32_OFF 				5

// Атрибут STVALINT32 может иметь значения: ....
#define STVALINT32_OK 				1
#define STVALINT32_Warning 			2
#define STVALINT32_Alarm 			3

// Атрибут STVALINT32 может иметь значения: ....
#define STVALCODEDENUM_INTERMEDIATE		0
#define STVALCODEDENUM_OFF 				1
#define STVALCODEDENUM_ON 				2
#define STVALCODEDENUM_BADSTATE			3

// Атрибут ctlModelENUM может иметь значения: ....
#define CTLMODELEDENUM_statusOnly						0
#define CTLMODELEDENUM_DirectWithNormalSecurity 		1
#define CTLMODELEDENUM_SboWithNormalSecurity 			2
#define CTLMODELEDENUM_DirectWithEnhancedSecurity		3
#define CTLMODELEDENUM_SboWithEnhancedSecurity			4

void 		ReStartIEC850_task(void);
void 		StartIEC850Task(void const * argument);
uint64_t 	Hal_getTimeInMs (void);


#endif /* IEC850_H_ */
