/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __NUCLEUS_FILE_FILE_H__
#define __NUCLEUS_FILE_FILE_H__

#include <Nucleus/Nucleus.h>

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#ifndef WINDOWS
#include <sys/mman.h>
#include <glob.h>
#endif

struct NuFile_s {
	void *magic;
	FILE *file;
	int   fd;
	char *filename;
	char *mode;
} typedef NuFile;

struct NuFile_Context_s {
    void *padding;
} typedef NuFile_Context;

typedef struct NuGlob_s {
#ifndef WINDOWS
    glob_t glob_obj;
    char *glob_string;
    int glob_iter;
#else
     void *paddingFTW;
#endif
} NuGlob;

bool           NuFile_Setup();
inline NuFile *NuFile_Open(char *filename, char *mode);
inline void   *NuFile_MMap(NuFile *file, void *addr, int prot);
inline bool    NuFile_MUnMap(NuFile *file, int length);
inline bool    NuFile_Close(NuFile *file);
inline int     NuFile_Write(NuFile *file, void *data, int length);
inline int     NuFile_Read(NuFile *file, void *buf, int length);
inline int     NuFile_GetSize(NuFile *file);
inline bool    NuFile_Seek(NuFile *file, int offset, bool absolute);
inline int     NuFile_Tell(NuFile *file);
inline bool    NuFile_Flush(NuFile *file);
inline bool    NuFile_IsDirectory(char *filename);

inline NuGlob *NuGlob_Glob(char *glob_string);
inline char   *NuGlob_Next(NuGlob *glob);
inline bool    NuGlob_Free(NuGlob *glob);

NuContext_SingletonDecl(NuFile_GetContext, NuFile_Context);

#endif
