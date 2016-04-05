/*
 *  iec61850_common.h
 *
 *  Copyright 2013 Michael Zillgith
 *
 *  This file is part of libIEC61850.
 *
 *  libIEC61850 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libIEC61850 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libIEC61850.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  See COPYING file for the complete license text.
 */

#ifndef IEC61850_COMMON_H_
#define IEC61850_COMMON_H_

/*
 * Функциональная связь (FC) должна быть свойством атрибута данных DataAttribute,
 * характеризующим конкретное использование DataAttribute. Функциональная связь (FC)
 * использована в определении данных DATA (содержащихся в логических узлах LN) и
 * в различных блоках управления (например, BRCB).
 */

// Функциональные связи (Functional constraints)
typedef enum eFunctionalConstraint {
    // FCs according to IEC 61850-7-2:
    ST, /** Status information */						// Информация о состоянии							ТОЛЬКО ЧТЕНИЕ
    MX, /** Measurands - analog values */				// Измеряемые величины (аналоговые значения)		ТОЛЬКО ЧТЕНИЕ
    SP, /** Setpoint */									// Уставка											МОЖЕТ БЫТЬ ЗАПИСАНО И СЧИТАНО
    SV, /** Substitution */								// Подстановка										МОЖЕТ БЫТЬ ЗАПИСАНО И СЧИТАНО
    CF, /** Configuration */							// Конфигурация										МОЖЕТ БЫТЬ ЗАПИСАНО И СЧИТАНО
    DC, /** Description */								// Описание											МОЖЕТ БЫТЬ ЗАПИСАНО И СЧИТАНО
    SG, /** Setting group */							// Группа настроек									НЕ ПЕРЕЗАПИСЫВАЕМОЕ
    SE, /** Setting group editable */					// Редактируемая группа настроек					МОЖЕТ БЫТЬ ИЗМЕНЁМ СЕРВИСАМИ SGCB
    SR, /** Service response / Service tracking */
    OR, /** Operate received */
    BL, /** Blocking */									// Блокировка
    EX, /** Extended definition */						// Расширенное определение							НЕ ПЕРЕЗАПИСЫВАЕМОЕ
    CO  /** Control */									// Управление										МОЖЕТ БЫТЬ СЧИТАНО
} FunctionalConstraint;

char*
FunctionalConstrained_toString(FunctionalConstraint fc);

#endif /* IEC61850_COMMON_H_ */
