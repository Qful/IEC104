/*
 *  byte_stream.h
 *
 *  Copyright 2013 Michael Zillgith
 *
 *	This file is part of libIEC61850.
 *
 *	libIEC61850 is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	libIEC61850 is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with libIEC61850.  If not, see <http://www.gnu.org/licenses/>.
 *
 *	See COPYING file for the complete license text.
 */

#ifndef BYTE_STREAM_H_
#define BYTE_STREAM_H_

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "byte_buffer.h"


typedef struct sByteStream {
	uint8_t* Data;
	int maxSize;
	int size;
}* ByteStream;



int			ByteStream_writeUint8(ByteBuffer* self, uint8_t byte);
int			ByteStream_readUint8(ByteBuffer* self, uint8_t* byte);
int			ByteStream_readUint16(ByteBuffer* self, uint16_t* value);						// чтение из буфера в ByteStream

int			ByteStream_readOctets(ByteBuffer* self, uint8_t* targetBuffer, int size);

#endif /* BYTE_STREAM_H_ */
