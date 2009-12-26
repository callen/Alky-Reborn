/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Shell32/Shell32.h>

#define NUMODULE_NAME "Shell32"

WINAPI HRESULT SHGetFolderPathA(
    HWND hwndOwner,
    int nFolder,
    HANDLE hToken,
    DWORD dwFlags,
    LPSTR pszPath
) {
	NuWarn("SHGetFolderPath not yet implemented");
	
	strcpy(pszPath, "./");
	
	return S_OK;
}