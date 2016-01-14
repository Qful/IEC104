/*
 *  byte_stream.c
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

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "stack_config.h"

#include "byte_stream.h"
#include "socket_lwIP.h"
//#include "hal.h"




/*************************************************************************
 * ByteStream_writeUint8(ByteStream self, uint8_t byte)
 *************************************************************************/
int	ByteStream_writeUint8(ByteBuffer* self, uint8_t byte)
{
    if (ByteBuffer_appendByte(self, byte))
        return 1;
    else
        return -1;
}

/*************************************************************************
 * ByteStream_readUint8
 * читаем из потока 1 байт
 *************************************************************************/
int		ByteStream_readUint8(ByteBuffer* self, uint8_t* byte){

    if (ByteBuffer_readByteUint8(self, byte))		return 1;
    else	return -1;
}
/*************************************************************************
 * ByteStream_readUint8
 * читаем из приёмного буфера 1 слово
 *************************************************************************/
int		ByteStream_readUint16(ByteBuffer* self, uint16_t* value){

	int reti;

	reti = ByteBuffer_readByteUint16(self, value);

	if (reti) return	reti;
	else	return -1;

}
/*************************************************************************
 * ByteStream_skipBytes
 *
 *************************************************************************/
int	ByteStream_skipBytes(ByteStream self, int number)
{
	/*
    int c = 0;
    uint8_t byte;

    uint64_t start = Hal_getTimeInMs();

    do {
        int readBytes = Socket_read(self->socket, &byte, 1);

        if (readBytes < 0)
            return -1;
        else
            c = c + readBytes;

    } while ((c < number)
            && ((Hal_getTimeInMs() - start) < CONFIG_TCP_READ_TIMEOUT_MS));

    return c;
    */
}
/*************************************************************************
 * ByteStream_readOctets
 * переписываем принятые данные в буфер buffer из self буфера
 *************************************************************************/
int		ByteStream_readOctets(ByteBuffer* self, uint8_t* buffer, int size)
{
    int readBytes = 0;

    do {
    	if (ByteStream_readUint8(self,&buffer[readBytes])){
    		readBytes++;
    	} else{
    		return -1;
    	}

    } while (readBytes < size);

    return readBytes;

}

