/*
 *  mms_access_result.c
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

#include "libiec61850_platform_includes.h"
//#include "mms_access_result.h"
#include "mms_server_internal.h"
#include "mms_value_internal.h"

#include "main.h"

typedef struct sMmsValue MmsValue;

/*************************************************************************
 * encodeArrayAccessResult
 *************************************************************************/
static int	encodeArrayAccessResult(MmsValue* value, uint8_t* buffer, int bufPos, bool encode)
{
    if (value == NULL) // TODO report internal error
        return 0;

    int elementsSize = 0;
    int i;
    int size;

    int arraySize = MmsValue_getArraySize(value);

    for (i = 0; i < arraySize; i++) {
        MmsValue* element = MmsValue_getElement(value, i);

        elementsSize += MmsValue_encodeMmsData(element, NULL, 0, false);
    }

    if (encode) {
        buffer[bufPos++] = 0xa1; /* tag for array */
        bufPos = BerEncoder_encodeLength(elementsSize, buffer, bufPos);

        for (i = 0; i < arraySize; i++) {
            MmsValue* element = MmsValue_getElement(value, i);

            bufPos = MmsValue_encodeMmsData(element, buffer, bufPos, true);
        }

        size = bufPos;
    }
    else {
        size = 1 + elementsSize + BerEncoder_determineLengthSize(elementsSize);
    }

    return size;
}
/*************************************************************************
 * encodeStructuredAccessResult
 *************************************************************************/
static int	encodeStructuredAccessResult(MmsValue* value, uint8_t* buffer, int bufPos, bool encode)
{
    int componentsSize = 0;
    int i;
    int size;

    int componentCount = value->value.structure.size;

    MmsValue** components = value->value.structure.components;

    for (i = 0; i < componentCount; i++)
        componentsSize += MmsValue_encodeMmsData(components[i], NULL, 0, false);

    if (encode) {
        buffer[bufPos++] = 0xa2; /* tag for structure */
        bufPos = BerEncoder_encodeLength(componentsSize, buffer, bufPos);

        for (i = 0; i < componentCount; i++)
            bufPos = MmsValue_encodeMmsData(components[i], buffer, bufPos, true);

        size = bufPos;
    }
    else
        size = 1 + componentsSize + BerEncoder_determineLengthSize(componentsSize);

    return size;
}

/*************************************************************************
 * MmsValue_encodeMmsData
 *************************************************************************/
int	MmsValue_encodeMmsData(MmsValue* self, uint8_t* buffer, int bufPos, bool encode)
{
    int size;

    switch (self->type) {
    case MMS_BOOLEAN:
        if (encode)
            bufPos = BerEncoder_encodeBoolean(0x83, self->value.boolean, buffer, bufPos);
        else
            size = 3;
        break;

    case MMS_STRUCTURE:
        if (encode)
            bufPos = encodeStructuredAccessResult(self, buffer, bufPos, true);
        else
            size = encodeStructuredAccessResult(self, buffer, bufPos, false);

        break;

    case MMS_ARRAY:
        if (encode)
            bufPos = encodeArrayAccessResult(self, buffer, bufPos, true);
        else
            size = encodeArrayAccessResult(self, buffer, bufPos, false);
        break;

    case MMS_DATA_ACCESS_ERROR:
        if (encode) {
            int length = BerEncoder_UInt32determineEncodedSize((uint32_t) self->value.dataAccessError);

            bufPos = BerEncoder_encodeTL(0x80, length, buffer, bufPos);
            bufPos = BerEncoder_encodeUInt32((uint32_t) self->value.dataAccessError, buffer, bufPos);
        }
        else
            size = 2 + BerEncoder_UInt32determineEncodedSize((uint32_t) self->value.dataAccessError);
        break;

    case MMS_VISIBLE_STRING:
        if (encode)
            bufPos = BerEncoder_encodeStringWithTag(0x8a, self->value.visibleString.buf, buffer, bufPos);
        else
            size = BerEncoder_determineEncodedStringSize(self->value.visibleString.buf);
        break;
    case MMS_UNSIGNED:
        if (encode)
            bufPos = BerEncoder_encodeAsn1PrimitiveValue(0x86, self->value.integer, buffer, bufPos);
        else
            size = 2 + self->value.integer->size;
        break;
    case MMS_INTEGER:
        if (encode)
            bufPos = BerEncoder_encodeAsn1PrimitiveValue(0x85, self->value.integer, buffer, bufPos);
        else
            size = 2 + self->value.integer->size;
        break;
    case MMS_UTC_TIME:
        if (encode)
            bufPos = BerEncoder_encodeOctetString(0x91, self->value.utcTime, 8, buffer, bufPos);
        else
            size = 10;
        break;
    case MMS_BIT_STRING:
        if (encode)
            bufPos = BerEncoder_encodeBitString(0x84, self->value.bitString.size,
                    self->value.bitString.buf, buffer, bufPos);
        else
            size = BerEncoder_determineEncodedBitStringSize(self->value.bitString.size);
        break;

    case MMS_BINARY_TIME:
        if (encode)
            bufPos = BerEncoder_encodeOctetString(0x8c, self->value.binaryTime.buf,
                    self->value.binaryTime.size, buffer, bufPos);
        else
            size = 2 + self->value.binaryTime.size;
        break;
    case MMS_OCTET_STRING:
        if (encode)
            bufPos = BerEncoder_encodeOctetString(0x89, self->value.octetString.buf,
                    self->value.octetString.size, buffer, bufPos);
        else
            size = 1 + BerEncoder_determineLengthSize(self->value.octetString.size)
                        + self->value.octetString.size;
        break;

    case MMS_FLOAT:
        {
            int floatSize = (self->value.floatingPoint.formatWidth / 8) + 1;

            if (encode) {
                bufPos = BerEncoder_encodeTL(0x87, floatSize, buffer, bufPos);
                bufPos = BerEncoder_encodeFloat(self->value.floatingPoint.buf,
                        self->value.floatingPoint.formatWidth,
                        self->value.floatingPoint.exponentWidth,
                        buffer, bufPos);
            }
            else
                size = floatSize + 2; /* 2 for tag and length */
        }
        break;
    case MMS_STRING:
        if (encode)
            bufPos = BerEncoder_encodeStringWithTag(0x90, self->value.visibleString.buf, buffer, bufPos);
        else
            size = BerEncoder_determineEncodedStringSize(self->value.visibleString.buf);
        break;
    default:
    	USART_TRACE_RED("encodeAccessResult: error unsupported type!\n");
        size = 0;
        break;
    }

    if (encode)
        return bufPos;
    else
        return size;
}
