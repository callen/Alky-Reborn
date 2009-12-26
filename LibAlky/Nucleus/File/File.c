/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/File/File.h>

#define NUMODULE_NAME "NuFile"

NuContext_Singleton(NuFile_GetContext, NuFile_Context, NUMODULE_NAME);

bool NuFile_Setup() {
	NuFile_Context *_Context;
	
	NuLog("Setup");
	
	_Context = NuFile_GetContext();
	
	memset(_Context, 0, sizeof(_Context));
}

inline NuFile *NuFile_Open(char *filename, char *mode) {
	NuFile_Context *_Context = NuFile_GetContext();
	NuFile *file;
	FILE   *fp;
	
	int i;

	NuLog("Opening file `%s' with mode `%s'", filename, mode);
	
	fp = fopen((const char *) filename, (const char *) mode);
	
	
	if(fp == None) {
		NuLog("Could not open file `%s'", filename);
		return None;
	}
	
	file = (NuFile *) NuMemory_Alloc(sizeof(NuFile));
	
	file->magic = 0xDEADBEEF;
	
	if(file == None) {
		NuError("Could not allocate memory for NuFile %s", filename);
		return None;
	}
	
	file->filename = strdup(filename);
	file->mode = mode;
	file->file = fp;
	
	return file;
}

inline void *NuFile_MMap(NuFile *file, void *addr, int prot) {
	void *ret;
	
	NuLog("Memory mapping %s", file->filename);
	
	file->fd = fileno(file->file);
	
	ret = mmap(
		addr, NuFile_GetSize(file), prot,
		MAP_SHARED, file->fd, 0
	);
	
	if(ret == MAP_FAILED)
		NuError("Memory mapping failed: %s", strerror(errno));
	
	return ret;
}

inline bool NuFile_MUnMap(NuFile *file, int length) {
	void *ret;
	
	NuLog("Memory un-mapping %s", file->filename);
	
	NuWarn("MUnMap oesn't actually unmap yet!");
	
	return True;
}

inline bool NuFile_Close(NuFile *file) {
	if(file->filename[0] == None || file->magic != 0xDEADBEEF)
		return True;
		
	NuLog("Closing file %s", file->filename);
	
	fclose(file->file);
	
	NuMemory_Free(file);
	
	return True;
}

inline int NuFile_Write(NuFile *file, void *data, int length) {
	NuAssert(file != None);
	NuAssert(file->file != None);
	
	NuLog("Writing %i bytes to file `%s'", length, file->filename);
	
	return fwrite(data, 1, length, file->file);
}

inline int NuFile_Read(NuFile *file, void *buf, int length) {
	NuAssert(file != None);
	NuAssert(file->file != None);
	
	// NuLog("Reading %i bytes from file `%s'", length, file->filename);
	
	return fread(buf, 1, length, file->file);
}

inline int NuFile_GetSize(NuFile *file) {
	int prev, ret;
	
	prev = ftell(file->file);
	fseek(file->file, 0,    SEEK_END);
	ret = ftell(file->file);
	fseek(file->file, prev, SEEK_SET);
	
	return ret;
}

inline bool NuFile_Seek(NuFile *file, int offset, bool absolute) {
	if(absolute) {
		if(offset >= 0)
			fseek(file->file, offset, SEEK_SET);
		else
			fseek(file->file, ~offset, SEEK_END);
	}
	else
		fseek(file->file, offset, SEEK_CUR);
	
	return True;
}

inline int NuFile_Tell(NuFile *file) {
	return ftell(file->file);
}

inline bool NuFile_Flush(NuFile *file) {
	fflush(file->file);
	
	return True;
}

inline bool    NuFile_IsDirectory(char *filename) {
	struct stat st;
	
	if(stat(filename, &st) != 0)
		return False;
	
	if(st.st_mode & S_IFDIR)
		return True;
	
	return False;
}

