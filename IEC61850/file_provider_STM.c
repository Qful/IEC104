/*
 *  file_provider_linux.c
 *
 *  Copyright 2014 Michael Zillgith
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

#include <string.h>
//#include <dirent.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "libiec61850_platform_includes.h"

#include "hal_filesystem.h"

#include "stack_config.h"

extern int8_t		TimeZone_my;

struct sDirectoryHandle {
    DIR* handle;
};

struct sFileHandle {
    FIL* handle;
};

enum
  {
    DT_UNKNOWN = 0,
# define DT_UNKNOWN	DT_UNKNOWN
    DT_FIFO = 1,
# define DT_FIFO	DT_FIFO
    DT_CHR = 2,
# define DT_CHR		DT_CHR
    DT_DIR = 4,
# define DT_DIR		DT_DIR
    DT_BLK = 6,
# define DT_BLK		DT_BLK
    DT_REG = 8,
# define DT_REG		DT_REG
    DT_LNK = 10,
# define DT_LNK		DT_LNK
    DT_SOCK = 12,
# define DT_SOCK	DT_SOCK
    DT_WHT = 14
# define DT_WHT		DT_WHT
  };

/***********************************************************************
 * FileSystem_openFile
 * открываем файл
 ***********************************************************************/
FileHandle		FileSystem_openFile(char* fileName, bool readWrite)
{
	FRESULT	res;
    FileHandle 	Myfile;

	USART_TRACE_BLUE("FileSystem_openFile: '%s'\n",fileName);

    //Myfile = GLOBAL_MALLOC(sizeof(FileHandle));
    Myfile = GLOBAL_MALLOC(sizeof(FIL));		// похоже и тут надо выделять для структуры память

    if (readWrite){

    	/* FILE *fopen (filename, type)
    	 * Функция fopen открывает файл с именем filename, ассоциирует с ним
    	 * поток и возвращает указатель на структуру типа FILE, соответствующую этому потоку.
    	 *
    	 */

    	res = f_open((FIL*)Myfile,(const TCHAR*)fileName,FA_WRITE);
    	if (res != FR_OK){
    		USART_TRACE_RED("FileSystem_openFile ERROR\n");

    		GLOBAL_FREEMEM(Myfile);
    		Myfile = NULL;
    	}

    }
    else{
    	res = f_open((FIL*)Myfile,(const TCHAR*)fileName,FA_READ);

    	if (res != FR_OK){
    		USART_TRACE_RED("FileSystem_openFile ERROR\n");

    		GLOBAL_FREEMEM(Myfile);
    		Myfile = NULL;
    	}else{
    		USART_TRACE_GREEN("FileSystem_openFile 0x%x\n",(unsigned int)Myfile);
    	}
    }

    return Myfile;
}
/***********************************************************************
 * FileSystem_readFile
 * читаем файл
 ***********************************************************************/
int		FileSystem_readFile(FileHandle handle, uint8_t* buffer, int maxSize)
{
	FRESULT	res;
	UINT nmb;

	USART_TRACE_BLUE("FileSystem_readFile. 0x%x maxSize:\n",(unsigned int)handle,maxSize);


//    return fread(buffer, maxSize, 1, (FILE*) handle);
	res = f_read(handle, buffer, maxSize, &nmb);
    if (res == FR_OK){
    	USART_TRACE_GREEN("FileSystem_readFile.  OK. 0x%x: %u\n",(unsigned int)buffer,nmb);
    	return nmb;
    }
    else{
		USART_TRACE_RED("FileSystem_readFile ERROR\n");
    	return -1;
    }

}
/***********************************************************************
 * FileSystem_closeFile
 * закрываем файл
 ***********************************************************************/
void	FileSystem_closeFile(FileHandle handle)
{
	USART_TRACE_BLUE("FileSystem_closeFile. 0x%x\n",handle);

//    fclose((FILE*) handle);
    f_close((FIL*)handle);

	USART_TRACE_BLUE("GLOBAL_FREEMEM. 0x%x\n",handle);

    GLOBAL_FREEMEM((void*)handle);
}

/***********************************************************************
 * FileSystem_deleteFile
 * удалить файл
 ***********************************************************************/
bool	FileSystem_deleteFile(char* filename)
{
	   if (f_unlink(filename) == 0)
//    if (remove(filename) == 0)
        return true;
    else
        return false;
}
/***********************************************************************
 * FileSystem_renameFile
 * переименовать файл
 ***********************************************************************/
bool	FileSystem_renameFile(char* oldFilename, char* newFilename)
{
 //   if (rename(oldFilename, newFilename) == 0)
    if (f_rename(oldFilename, newFilename) == 0)
        return true;
    else
        return false;
}

/***********************************************************************
 * FileSystem_getFileInfo
 *
 * информация о файле, размер и время изменения
 *
 * Двухбайтовая отметка даты имеет следующий формат:
 * биты 0—4 — день месяца, допускаются значения 1—31;
 * биты 5—8 — месяц года, допускаются значения 1—12;
 * биты 9—15 — год, считая от 1980 года («эпоха MS-DOS»), возможны значения от 0 до 127 включительно, то есть 1980—2107 годы.
 * Два байта, отвечающие отметке времени, распределяются так:
 *
 * биты 0—4 — счётчик секунд (по две), допустимы значения 0—29, то есть 0—58 секунд;
 * биты 5—10 — минуты, допустимы значения 0—59;
 * биты 11—15 — часы, допустимы значения 0—23.
 ***********************************************************************/
bool	FileSystem_getFileInfo(char* filename, uint32_t* fileSize, uint64_t* lastModificationTimestamp)
{
	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;
	uint64_t	sectmp,den;
	FILINFO FileInfo;
	FRESULT res;

	USART_TRACE_BLUE("FileSystem_getFileInfo.\n");


	res = f_stat(filename, &FileInfo);
    if (res == FR_OK){
    	/* Время измеряется в секундах от 00:00:00 1 января 1970г. по Гринвичу */

        if (lastModificationTimestamp != NULL){

        	sDate.Date = FileInfo.fdate & 0b11111;
        	sDate.Month = FileInfo.fdate>>5 & 0b1111;
        	sDate.Year = FileInfo.fdate>>9 & 0b1111111;
        	//sDate.Year += 10;

        	sTime.Seconds = (FileInfo.ftime & 0b11111)*2;
        	sTime.Minutes = FileInfo.ftime>>5 & 0b111111;
        	sTime.Hours = FileInfo.ftime>>11 & 0b11111;


        	den 	= (30+sDate.Year) * 365 + (30+sDate.Year+2)/4 - 2;

        	switch(sDate.Month) {
        	    case 2 : den +=31; break;	//31	31
        	    case 3 : den +=59; break;	//59	28
        	    case 4 : den +=90; break;	//90	31
        	    case 5 : den +=120; break;	//120	30
        	    case 6 : den +=151; break;	//151	31
        	    case 7 : den +=181; break;	//181	30
        	    case 8 : den +=212; break;	//212	31
        	    case 9 : den +=243; break;	//243	31
        	    case 10 : den +=273; break;	//273	30
        	    case 11 : den +=304; break;	//304	31
        	    case 12 : den +=334; break;	//334	30
        	   };

        	if (!((30+sDate.Year+2)%4) && sDate.Month>2) den++;

        	 den += sDate.Date;

        	 sectmp = den * 86400;
        	 sectmp += sTime.Hours * 3600;
        	 sectmp += sTime.Minutes * 60;
        	 sectmp += sTime.Seconds;

        	 sectmp -= TimeZone_my*60*60;			//отнимем часовой пояс, для получения отсчетов UTC стандарта.

        	 sectmp *= 1000;

            *lastModificationTimestamp = sectmp;
        }

    	  if (fileSize != NULL)
    	        *fileSize = FileInfo.fsize;

    	USART_TRACE_GREEN("FileSystem_getFileInfo return...\n");
    return true;

    }else{
		USART_TRACE_RED("FileSystem_getFileInfo ERROR\n");
		return false;
    }
}
/***********************************************************************
 * FileSystem_openDirectory
 * открываем директорию - directoryName - стартовая директория
 ***********************************************************************/
DirectoryHandle		FileSystem_openDirectory(char* directoryName)
{
    DirectoryHandle handle;
	DIR* dirHandle;
	FRESULT res;
	int	sz = sizeof(DIR);
	USART_TRACE_BLUE("FileSystem_openDirectory.\n");

// тут нужно выделять память не на sDirectoryHandle а на всю структуру DIR*
//	dirHandle = GLOBAL_MALLOC(sizeof(struct sDirectoryHandle));
	dirHandle = GLOBAL_MALLOC(sizeof(DIR));
    if (!dirHandle) return NULL;

    //    DIR* dirHandle = opendir(directoryName); //Функция opendir() открывает поток каталога, соответствующий каталогу name, и возвращает указатель на этот поток. Поток устанавливается на первой записи в каталоге.
    //dirHandle - Указатель на чистый объект директории, который будет заполнен данными.
    res = f_opendir(dirHandle, directoryName);

//TODO: тут ошибка с выделением памяти, нужно исправить
    if(res == FR_OK) {
    	USART_TRACE_BLUE("/%s/\n",directoryName);
        handle = GLOBAL_MALLOC(sizeof(DirectoryHandle));
        handle->handle = dirHandle;
        return handle;
    } else{
		USART_TRACE_RED("FileSystem_openDirectory ERROR\n");

    	GLOBAL_FREEMEM(dirHandle);
    	//dirHandle = NULL;
        return NULL;
    }
 return NULL;
}
/***********************************************************************
 * FileSystem_readDirectory
 * читаем директорию
 ***********************************************************************/
char*		FileSystem_readDirectory(DirectoryHandle directory, bool* isDirectory)
{
	static FILINFO  fno;
    static char *fn;

    FRESULT res;
    DIR dirHandle;

	USART_TRACE_BLUE("FileSystem_readDirectory.\n");

    res = f_readdir(directory->handle,&fno);		//Функция f_readdir последовательно, друг за другом читает элементы (файлы и папки), находящиеся в директории DirObject. Все элементы директории могут быть прочитаны повторяющимися вызовами f_readdir. Когда будут прочитаны все элементы в директории, функция вернет пустую ASCIIZ-строку в поле fname[] (т. е. fname[0]==0) без какой-либо ошибки. Когда в качестве параметра FileInfo указан null указатель, то позиция чтения директории отматывается на начало.
//	res = f_readdir(directory,&fno);
    if(res != FR_OK || fno.fname[0] == 0) {
      		return NULL;
     }else
    if(res == FR_OK) {
            if (fno.fname[0] == '.')				// пропускаем каталог корня.                               лучше сделать проверку по fsize, т.к. он для директорий всегда равен 0.
        	//res = f_readdir(directory->handle,&fno);		//Функция f_readdir последовательно, друг за другом читает элементы (файлы и папки), находящиеся в директории DirObject. Все элементы директории могут быть прочитаны повторяющимися вызовами f_readdir. Когда будут прочитаны все элементы в директории, функция вернет пустую ASCIIZ-строку в поле fname[] (т. е. fname[0]==0) без какой-либо ошибки. Когда в качестве параметра FileInfo указан null указатель, то позиция чтения директории отматывается на начало.
    		return	FileSystem_readDirectory(directory, isDirectory);
            else{
            	if (isDirectory != NULL) {
            		if (fno.fattrib & AM_DIR)
            			 *isDirectory = true;
            		else
            			 *isDirectory = false;
            	}
            	fn = fno.fname;
            	USART_TRACE_BLUE("-> '%s'\n",fn);
            	return	fn;
            }
    }
    else
    	return NULL;
}
/***********************************************************************
 * FileSystem_closeDirectory
 * закрываем директорию и освободим память
 ***********************************************************************/
void	FileSystem_closeDirectory(DirectoryHandle directory)
{
	USART_TRACE_BLUE("FileSystem_closeDirectory.\n");

//	f_closedir(directory);
//	GLOBAL_FREEMEM(directory);


    f_closedir(directory->handle);
    GLOBAL_FREEMEM(directory->handle);
    GLOBAL_FREEMEM(directory);

}

