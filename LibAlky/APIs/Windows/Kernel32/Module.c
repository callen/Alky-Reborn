/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#include <dlfcn.h>

#define NUMODULE_NAME "Kernel32"

WINAPI DWORD GetModuleFileNameA(
  HMODULE hModule,
  LPSTR lpFilename,
  DWORD nSize
) {
	NuWarn("GetModuleFileNameA not yet implemented");
	
	if(hModule == 0) {
		strncpy(lpFilename, "foo", nSize);
		
		return 4;
	} else {
		strncpy(lpFilename, hModule, nSize);
		strncpy(&lpFilename[strlen(lpFilename)], ".dll", 4);
		return strlen(lpFilename) + 1;
	}
}

WINAPI DWORD GetModuleFileNameW(
  HMODULE hModule,
  LPWSTR lpFilename,
  DWORD nSize
) {
	NuWarn("GetModuleFileNameW not yet implemented");
	
	if(hModule == 0) {
		memcpy(lpFilename, "f\0o\0o\0\0\0", 8);
		
		return 8;
	} else {
		memcpy(lpFilename, hModule, wcslen((LPWSTR *) hModule));
		return (wcslen((LPWSTR *) hModule) * 2) + 2;
	}
}

WINAPI HMODULE GetModuleHandleA(
  LPCSTR lpModuleName
) {
	void *buf;
	NuFile *file;
	
	char *module_lower;
	char *module_copy;
	
	int i;
	
	NuLog("GetModuleHandleA %s", lpModuleName);
	
	if(lpModuleName == None)
		return 0x400000; "\0\0\0";
		
	module_copy = strdup(lpModuleName);

	for(i = 0; i < strlen(module_copy); ++i) {
		if(module_copy[i] == '\\')
			module_copy[i] = '/';
	}
	
	if(module_copy[0] == '/') {
		NuFile *file = NuFile_Open(module_copy, "rb");
		
		if(file)
			NuFile_Close(file);
		else {
			free(module_copy);
			
			Kernel32_SetLastError(ERROR_FILE_NOT_FOUND);
			
			return None;
		}
	}
	
	module_lower = strtolower(lpModuleName);
	
	if(strcmp(&module_lower[strlen(module_lower) - 4], ".dll") == 0)
		module_copy[strlen(module_copy) - 4] = 0;
	
	free(module_lower);
	
	return module_copy;
}

WINAPI HMODULE LoadLibraryA(
  LPCSTR lpModuleName
) {
	NuLog("LoadLibraryA %s", lpModuleName);
	
	return GetModuleHandleA(lpModuleName);
}

WINAPI FARPROC GetProcAddress(
  HMODULE hModule,
  LPCSTR lpProcName
) {
	void *proc;
	
	proc = NuCore_Import(hModule, lpProcName, None);
	
	if(proc == None) {
		NuWarn("Could not resolve symbol %s::%s: %s", hModule, lpProcName, NuCore_Error());
		
		return None;
	}
}

WINAPI BOOL FreeLibrary(
  HMODULE hModule
) {
	NuWarn("FreeLibrary not yet implemented");
	
	return True;
}
