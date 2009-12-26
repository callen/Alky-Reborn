/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_SHELL32_SHELL32_H__
#define __APIS_WINDOWS_SHELL32_SHELL32_H__

#include <APIs/Windows/Windows.h>

WINAPI HRESULT SHGetFolderPathA(
    HWND hwndOwner,
    int nFolder,
    HANDLE hToken,
    DWORD dwFlags,
    LPSTR pszPath
);

#endif
