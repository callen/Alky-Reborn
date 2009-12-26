/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_TYPES_H__
#define __APIS_WINDOWS_TYPES_H__

#include <wchar.h>

typedef unsigned long long LARGE_INTEGER;
typedef unsigned long long*PULARGE_INTEGER;
typedef unsigned int       DWORD;
typedef unsigned int       *DWORD_PTR;
typedef unsigned int      **PDWORD_PTR;
typedef unsigned long long DWORDLONG;
typedef unsigned int       LPARAM;
typedef unsigned int       WPARAM;
typedef unsigned int       UINT;
typedef unsigned int      *UINT_PTR;
typedef unsigned int      *PUINT;
typedef int                LONG;
typedef int               *PLONG;
typedef int               *LPLONG;
typedef unsigned int      *PULONG;
typedef unsigned int       ULONG;
typedef unsigned int       LRESULT;
typedef int                INT;
typedef size_t             SIZE_T;
typedef void              *LPVOID;
typedef void              *VARIANT;
typedef void              *LPUNKNOWN;
typedef void              *PVOID;
typedef const void        *LPCVOID;
typedef void               VOID;
typedef short              SHORT;
typedef unsigned short     WORD;
typedef unsigned short    *LPWORD;
typedef unsigned char      BYTE;
typedef unsigned char      UINT8;
typedef unsigned char     *PBYTE;
typedef char               CHAR;
typedef char              *LPSTR;
typedef unsigned short     WCHAR;
typedef unsigned short    *LPWSTR;
typedef const unsigned short *LPCWSTR;
typedef const char        *LPCSTR;
typedef unsigned char     *LPBYTE;
typedef unsigned char     *LPCH;
typedef bool               BOOL;
typedef bool              *LPBOOL;

typedef float              FLOAT;

typedef void             **REFIID;

typedef void              *LOCAL;
typedef void              *PROC;
typedef void              *HANDLE;
typedef HANDLE          *LPHANDLE;
typedef void              *HBITMAP;
typedef void              *HDC;
typedef void              *HFONT;
typedef void              *HGLOBAL;
typedef void              *HGLRC;
typedef void              *HGDIOBJ;
typedef void              *HHOOK;
typedef void              *HLOCAL;
typedef void              *HKEY;
typedef void             **PHKEY;
typedef void              *HWND;
typedef void              *HMENU;
typedef void              *HMODULE;
typedef void              *HICON;
typedef void              *HCURSOR;
typedef void              *HINSTANCE;
typedef void              *HRESULT;
typedef void              *HWINSTA;
typedef void              *ATOM;
typedef void              *FARPROC;
typedef void              *WNDPROC;
typedef void              *HOOKPROC;
typedef void              *HBRUSH;
typedef void              *LPEXCEPTION_POINTERS;

typedef void              *LCID;
typedef void              *LCTYPE;

typedef DWORD             *ULONG_PTR;
typedef DWORD             *LPDWORD;

typedef DWORD              MMRESULT;

typedef DWORD              REGSAM;

typedef LPCSTR             BSTR;

typedef WINAPI LONG (*LPTOP_LEVEL_EXCEPTION_FILTER)(LPEXCEPTION_POINTERS);

#define CONST const

typedef struct _STARTUPINFOA {
  DWORD cb;
  LPSTR lpReserved;
  LPSTR lpDesktop;
  LPSTR lpTitle;
  DWORD dwX;
  DWORD dwY;
  DWORD dwXSize;
  DWORD dwYSize;
  DWORD dwXCountChars;
  DWORD dwYCountChars;
  DWORD dwFillAttribute;
  DWORD dwFlags;
  WORD wShowWindow;
  WORD cbReserved2;
  LPBYTE lpReserved2;
  HANDLE hStdInput;
  HANDLE hStdOutput;
  HANDLE hStdError;
}  STARTUPINFOA,
*LPSTARTUPINFOA;

typedef struct _STARTUPINFOW {
  DWORD cb;
  LPWSTR lpReserved;
  LPWSTR lpDesktop;
  LPWSTR lpTitle;
  DWORD dwX;
  DWORD dwY;
  DWORD dwXSize;
  DWORD dwYSize;
  DWORD dwXCountChars;
  DWORD dwYCountChars;
  DWORD dwFillAttribute;
  DWORD dwFlags;
  WORD wShowWindow;
  WORD cbReserved2;
  LPBYTE lpReserved2;
  HANDLE hStdInput;
  HANDLE hStdOutput;
  HANDLE hStdError;
}  STARTUPINFOW,
*LPSTARTUPINFOW;

typedef struct _GUID {
  DWORD Data1;
  WORD Data2;
  WORD Data3;
  BYTE Data4[8];
} GUID,
*REFGUID,
*LPCGUID,
  CLSID,
 *REFCLSID;

#define CCHDEVICENAME 32
#define CCHFORMNAME   32

typedef struct _devicemode { 
  CHAR  dmDeviceName[CCHDEVICENAME]; 
  WORD   dmSpecVersion; 
  WORD   dmDriverVersion; 
  WORD   dmSize; 
  WORD   dmDriverExtra; 
  DWORD  dmFields; 
  union {
    struct {
      short dmOrientation;
      short dmPaperSize;
      short dmPaperLength;
      short dmPaperWidth;
      short dmScale; 
      short dmCopies; 
      short dmDefaultSource; 
      short dmPrintQuality; 
    };
    void *dmPosition_foo; // POINTL dmPosition;
    DWORD  dmDisplayOrientation;
    DWORD  dmDisplayFixedOutput;
  };

  short  dmColor; 
  short  dmDuplex; 
  short  dmYResolution; 
  short  dmTTOption; 
  short  dmCollate; 
  BYTE  dmFormName[CCHFORMNAME]; 
  WORD  dmLogPixels; 
  DWORD  dmBitsPerPel; 
  DWORD  dmPelsWidth; 
  DWORD  dmPelsHeight; 
  union {
    DWORD  dmDisplayFlags; 
    DWORD  dmNup;
  };
  DWORD  dmDisplayFrequency; 
} DEVMODE,
*LPDEVMODE;

#define ERROR_SUCCESS 0

#endif
