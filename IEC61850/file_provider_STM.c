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

struct sDirectoryHandle {
    DIR* handle;
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

FileHandle
FileSystem_openFile(char* fileName, bool readWrite)
{
    FileHandle newHandle = NULL;

    if (readWrite)
//        newHandle = (FileHandle) fopen(fileName, "w");
    	f_open((FIL*)fileName,newHandle,FA_WRITE);
    else
//        newHandle = (FileHandle) fopen(fileName, "r");
    	f_open((FIL*)fileName,newHandle,FA_READ);

    return newHandle;
}

int
FileSystem_readFile(FileHandle handle, uint8_t* buffer, int maxSize)
{
	int nmb;
//    return fread(buffer, maxSize, 1, (FILE*) handle);
    if (f_read((FIL*) handle, buffer, maxSize, &nmb) == FR_OK)
    return nmb;
    else
    return -1;

}

void
FileSystem_closeFile(FileHandle handle)
{
//    fclose((FILE*) handle);
    f_close((FIL*)handle);
}

bool
FileSystem_deleteFile(char* filename)
{
//    if (remove(filename) == 0)
//        return true;
//    else
        return false;
}

bool
FileSystem_renameFile(char* oldFilename, char* newFilename)
{
 //   if (rename(oldFilename, newFilename) == 0)
    if (f_rename(oldFilename, newFilename) == 0)
        return true;
    else
        return false;
}


bool
FileSystem_getFileInfo(char* filename, uint32_t* fileSize, uint64_t* lastModificationTimestamp)
{
    struct stat fileStats;

    if (stat(filename, &fileStats) == -1)
        return false;

    if (lastModificationTimestamp != NULL)
        *lastModificationTimestamp = (uint64_t) (fileStats.st_mtime) * 1000LL;
        // does not work on older systems --> *lastModificationTimestamp = (uint64_t) (fileStats.st_ctim.tv_sec) * 1000LL;

    if (fileSize != NULL)
        *fileSize = fileStats.st_size;

    return true;
}

DirectoryHandle
FileSystem_openDirectory(char* directoryName)
{
	FRESULT res;
    DIR* dirHandle;

    res = f_opendir(dirHandle, directoryName);

    DirectoryHandle handle = NULL;

    if (dirHandle != NULL) {
        handle = GLOBAL_MALLOC(sizeof(struct sDirectoryHandle));
        handle->handle = dirHandle;
    }

    return handle;
}

char*
FileSystem_readDirectory(DirectoryHandle directory, bool* isDirectory)
{
    FILINFO  *dir;
    FRESULT res;

    res = f_readdir(directory->handle,dir);

    if (dir != NULL) {
        if (dir->fname[0] == '.')
            return FileSystem_readDirectory(directory, isDirectory);
        else {
            if (isDirectory != NULL) {
                if (dir->fattrib == DT_DIR)
                    *isDirectory = true;
                else
                    *isDirectory = false;
            }

            return dir->fname;
        }
    }
    else
        return NULL;
}

void
FileSystem_closeDirectory(DirectoryHandle directory)
{
    f_closedir(directory->handle);
    GLOBAL_FREEMEM(directory);
}

