/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#include <stdio.h>

#define NUMODULE_NAME "Kernel32"

WINAPI HANDLE CreateFileA(
  LPCSTR lpFileName,
  DWORD dwDesiredAccess,
  DWORD dwShareMode,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  DWORD dwCreationDisposition,
  DWORD dwFlagsAndAttributes,
  HANDLE hTemplateFile
) {
	NuFile *file;
	char *mode;
	char filename_tmp[256];
	int i;
	
	NuLog("CreateFileA %s", lpFileName);
	
	switch(dwDesiredAccess) {
		case GENERIC_WRITE:
			mode = "wb";
			break;
		case GENERIC_READ|GENERIC_WRITE:
			mode = "wb+";
			break;
		case GENERIC_READ:
		default:
			mode = "rb";
			break;
	}
	
	strncpy(filename_tmp, lpFileName, 256);
	
	for(i = 0; i < 256, filename_tmp[i] != 0; ++i) {
		if(filename_tmp[i] == '\\')
			filename_tmp[i] = '/';
	}
	
	file = NuFile_Open((char *) filename_tmp, mode);
	
	if(file == None) {
		if(dwDesiredAccess & GENERIC_WRITE)
			NuError("Writing %s failed!", lpFileName);
		if(dwCreationDisposition == CREATE_NEW) {
			file = NuFile_Open((char *) filename_tmp, "w");
			NuFile_Close(file);
			
			file = NuFile_Open((char *) filename_tmp, mode);
		}
	}
	
	if(file == None)
		return INVALID_HANDLE_VALUE;
		
	return file;
}

WINAPI BOOL ReadFile(
  HANDLE hFile,
  LPVOID lpBuffer,
  DWORD nNumberOfBytesToRead,
  LPDWORD lpNumberOfBytesRead,
  LPOVERLAPPED lpOverlapped
) {
	DWORD read;
	
	NuAssert(lpOverlapped == None);
	
	read = NuFile_Read(hFile, lpBuffer, nNumberOfBytesToRead);
	
	if(lpNumberOfBytesRead != None)
		*lpNumberOfBytesRead = read;
	
	return True;
}

WINAPI BOOL WriteFile(
  HANDLE hFile,
  LPCVOID lpBuffer,
  DWORD nNumberOfBytesToWrite,
  LPDWORD lpNumberOfBytesWritten,
  LPOVERLAPPED lpOverlapped
) {
	*lpNumberOfBytesWritten = NuFile_Write(hFile, lpBuffer, nNumberOfBytesToWrite);
	
	return True;
}

WINAPI BOOL CopyFileA(
	LPCSTR lpExistingFileName,
	LPCSTR lpNewFileName,
	BOOL bFailIfExists
) {
	NuWarn("CopyFileA not yet implemented");
	
	return True;
}

WINAPI DWORD SetFilePointer(
  HANDLE hFile,
  LONG lDistanceToMove,
  PLONG lpDistanceToMoveHigh,
  DWORD dwMoveMethod
) {
	NuAssert(hFile != None);
	NuAssert(lpDistanceToMoveHigh == 0);
	
	switch(dwMoveMethod) {
		case FILE_BEGIN:
			NuFile_Seek((NuFile *) hFile, lDistanceToMove, True);
			break;
		case FILE_CURRENT:
			if(lDistanceToMove > 0)
				NuFile_Seek((NuFile *) hFile, lDistanceToMove, False);
			break;
		case FILE_END:
			NuFile_Seek((NuFile *) hFile, ~lDistanceToMove, True);
			break;
	}
	
	return NuFile_Tell((NuFile *) hFile);
}

WINAPI HANDLE CreateFileMappingA(
  HANDLE hFile, 
  LPSECURITY_ATTRIBUTES lpFileMappingAttributes, 
  DWORD flProtect, 
  DWORD dwMaximumSizeHigh, 
  DWORD dwMaximumSizeLow, 
  LPCSTR lpName 
) {
	return NuFile_MMap((NuFile *) hFile, None, PROT_READ);
}

WINAPI LPVOID MapViewOfFile(
  HANDLE hFileMappingObject,
  DWORD dwDesiredAccess,
  DWORD dwFileOffsetHigh,
  DWORD dwFileOffsetLow,
  SIZE_T dwNumberOfBytesToMap
) {
	return hFileMappingObject + dwFileOffsetLow;
}

WINAPI BOOL UnmapViewOfFile(
  LPCVOID lpBaseAddress
) {
	NuWarn("UnmapViewOfFile not yet implemented");
	
	return True;
	// return NuFile_MUnMap((NuFile *) lpBaseAddress, 0);
}

WINAPI BOOL CloseHandle(
  HANDLE hObject
) {
	return NuFile_Close((NuFile *) hObject);
}

WINAPI HANDLE GetStdHandle(
  DWORD nStdHandle
) {
	NuLog("GetStdHandle %i", (int) nStdHandle);
	switch(nStdHandle) {
		case (DWORD) -10:
			return stdin;
		case (DWORD) -11:
			return stdout;
		case (DWORD) -12:
			return stderr;
	}
}

WINAPI DWORD GetFileType(
  HANDLE hFile
) {
	NuLog("GetFileType");
	NuWarn("This only checks stdin, stdout, stderr.");
	
	if(
		hFile == stdin ||
		hFile == stdout ||
		hFile == stderr
	)
		return FILE_TYPE_CHAR;
	
	return FILE_TYPE_DISK;
}

WINAPI DWORD GetFileSize(
  HANDLE hFile,
  LPDWORD lpFileSizeHigh
) {
	return NuFile_GetSize(hFile);
}

WINAPI UINT SetHandleCount(UINT count) {
	NuLog("SetHandleCount");

	return count;
}

WINAPI DWORD GetFullPathNameA(
  LPCSTR lpFileName,
  DWORD nBufferLength,
  LPSTR lpBuffer,
  LPSTR* lpFilePart
) {
	char *cwd = getcwd(None, None);
	snprintf(lpBuffer, nBufferLength, "%s/%s", cwd, lpFileName);
	
	*lpFilePart = &lpBuffer[strlen(cwd) + 1];
	
	return strlen(lpBuffer);
}

WINAPI DWORD GetCurrentDirectoryA(
  DWORD nBufferLength,
  LPSTR lpBuffer
) {
	NuWarn("GetCurrentDirectoryA not yet implemented");
	
	getcwd(lpBuffer, nBufferLength);
	
	return strlen(lpBuffer) + 1;
}

char *filterGlobbedName(char *glob, char *name) {
	char *lastSlash = name;
	char *ret;
	
	while(*name) {
		if(*name == '/')
			lastSlash = name;
		else if(*name == '*')
			break;
		name++;
	}
	
	return lastSlash + 1;
}

WINAPI HANDLE FindFirstFileA(
  LPCSTR lpFileName,
  LPWIN32_FIND_DATAA lpFindFileData
) {
	NuGlob *glob_obj;
	char *glob_path;
	char *temp;
	int i;
	
	glob_path = strdup((char *) lpFileName);
	for(i = 0; i < strlen(glob_path); ++i) {
		if(glob_path[i] == '\\')
			glob_path[i] = '/';
	}
	
	NuLog("Finding %s", glob_path);
	
	memset(lpFindFileData, 0, sizeof(WIN32_FIND_DATAA));
	
	glob_obj = NuGlob_Glob(glob_path);
	
	if(glob_obj != None) {
		temp = NuGlob_Next(glob_obj);
		
		strncpy(lpFindFileData->cFileName, filterGlobbedName(glob_path, temp), MAX_PATH-1);
		
		if(NuFile_IsDirectory(temp))
			lpFindFileData->dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
		else
			lpFindFileData->dwFileAttributes = FILE_ATTRIBUTE_NORMAL;
		
		return glob_obj;
	} else {
		NuWarn("Glob failed");
		
		return INVALID_HANDLE_VALUE;
	}
}

WINAPI BOOL FindNextFileA(
  HANDLE hFindFile,
  LPWIN32_FIND_DATAA lpFindFileData
) {
	NuGlob *glob_obj = hFindFile;
	char *temp;
	
	if(glob_obj == INVALID_HANDLE_VALUE || glob_obj == 0)
		return False;
	
	temp = NuGlob_Next(glob_obj);
	
	if(temp == None)
		return False;
	
	strncpy(lpFindFileData->cFileName, filterGlobbedName(glob_obj->glob_string, temp), MAX_PATH-1);
	
	if(NuFile_IsDirectory(temp))
		lpFindFileData->dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
	else
		lpFindFileData->dwFileAttributes = FILE_ATTRIBUTE_NORMAL;
	
	return True;
}

WINAPI BOOL FindClose(
  HANDLE hFindFile
) {
	NuLog("Closing find");
	
	if(hFindFile == INVALID_HANDLE_VALUE || hFindFile == 0)
		return False;
	
	NuGlob_Free((NuGlob *) hFindFile);
	
	return True;
}

WINAPI BOOL CreateDirectoryA(
  LPCSTR lpPathName,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes
) {
	NuWarn("CreateDirectoryA not yet implemented");
	
	NuLog("%s", lpPathName);
	
	return True;
}

WINAPI BOOL GetDiskFreeSpaceExA(
  LPCSTR lpDirectoryName,
  PULARGE_INTEGER lpFreeBytesAvailable,
  PULARGE_INTEGER lpTotalNumberOfBytes,
  PULARGE_INTEGER lpTotalNumberOfFreeBytes
) {
	if(lpFreeBytesAvailable)
		*lpFreeBytesAvailable = 0x1000000000;
	
	if(lpTotalNumberOfBytes)
		*lpTotalNumberOfBytes = 0x100000000000;
	
	if(lpTotalNumberOfFreeBytes)
		*lpTotalNumberOfFreeBytes = 0x100000000;
		
	
	return True;
}

WINAPI DWORD GetLogicalDrives() {
	NuWarn("GetLogicalDrives not yet implemented");
	
	return 12;
}

WINAPI DWORD GetIllogicalDrives() {
	NuError("Whee for easter eggs.  If you happen to have an illogical drive, let me know.");
}

WINAPI DWORD GetLogicalDriveStringsA(
  DWORD nBufferLength,
  LPSTR lpBuffer
) {
	NuWarn("GetLogicalDriveStringsA not yet implemented");
	
	memcpy(lpBuffer, "C\0D\0\0", 5);
	
	return 2;
}

WINAPI UINT GetDriveTypeA(
  LPCSTR lpRootPathName
) {
	NuWarn("GetDriveTypeA not yet implemented(%s)", lpRootPathName);
	
	switch(lpRootPathName[0]) {
		case 'C':
			return DRIVE_FIXED;
		case 'D':
			return DRIVE_CDROM;
	}
	
	return DRIVE_FIXED;
}

WINAPI BOOL GetVolumeInformationA(
  LPCSTR lpRootPathName,
  LPSTR lpVolumeNameBuffer,
  DWORD nVolumeNameSize,
  LPDWORD lpVolumeSerialNumber,
  LPDWORD lpMaximumComponentLength,
  LPDWORD lpFileSystemFlags,
  LPSTR lpFileSystemNameBuffer,
  DWORD nFileSystemNameSize
) {
	NuWarn("GetVolumeInformationA not yet implemented");
	
	if(lpRootPathName == 'D')
		strcpy(lpVolumeNameBuffer, "MYST");
	else
		strcpy(lpVolumeNameBuffer, "psjf");
	
	return True;
}

WINAPI BOOL DeleteFileA(
  LPCSTR lpFileName
) {
	NuWarn("DeleteFileA not yet implemented");
	
	return True;
}

WINAPI BOOL GetFileInformationByHandle(
  HANDLE hFile,
  LPBY_HANDLE_FILE_INFORMATION lpFileInformation
) {
	NuWarn("GetFileInformationByHandle not yet implemented");
	
	memset(lpFileInformation, 0x7F, sizeof(BY_HANDLE_FILE_INFORMATION));
	
	lpFileInformation->nFileSizeHigh = 0;
	lpFileInformation->nFileSizeLow = NuFile_GetSize((NuFile *) hFile);
	
	return True;
}

WINAPI UINT GetPrivateProfileIntA(
  LPCSTR lpAppName,
  LPCSTR lpKeyName,
  INT nDefault,
  LPCSTR lpFileName
) {
	NuWarn("GetPrivateProfileIntA not yet implemented");
	
	NuLog(
		"lpAppName=`%s' lpKeyName=`%s' nDefault=%i lpFileName=`%s'",
		lpAppName,
		lpKeyName,
		nDefault,
		lpFileName
	);
	
	if(strcmp(lpKeyName, "VERSION") == 0) {
		NuLog("VERSION override; returning 0x0F");
		
		return 0x0F;
	}
	
	return 0; // nDefault;
}

WINAPI DWORD GetPrivateProfileStringA(
  LPCSTR lpAppName,
  LPCSTR lpKeyName,
  LPCSTR lpDefault,
  LPSTR lpReturnedString,
  DWORD nSize,
  LPCSTR lpFileName
) {
	NuWarn("GetPrivateProfileStringA not yet implemented");
	
	NuLog(
		"lpAppName=`%s' lpKeyName=`%s' lpDefault=`%s' lpFileName=`%s' nSize=%i",
		lpAppName,
		lpKeyName,
		lpDefault,
		lpFileName,
		nSize
	);
	
	// memcpy(lpReturnedString, lpDefault, strlen(lpDefault) + 1);
	
	return 0; // strlen(lpReturnedString);
}

WINAPI DWORD GetFileAttributesA(LPCSTR lpFileName) {
	NuWarn("GetFileAttributesA not yet implemented");
	
	return 0;
}

WINAPI BOOL DuplicateHandle(
	HANDLE hSourceProcessHandle,
	HANDLE hSourceHandle,
	HANDLE hTargetProcessHandle,
	LPHANDLE hTargetHandle,
	DWORD dwDesiredAccess,
	BOOL bInheritHandle,
	DWORD dwOptions
) {
	NuWarn("DuplicateHandle not yet implemented");
	
	*hTargetHandle = hSourceHandle;
	
	return True;
}

WINAPI BOOL FlushFileBuffers(
	HANDLE hFile
) {
	NuFile_Flush((NuFile *) hFile);
	
	return True;
}
