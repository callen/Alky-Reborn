/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_GDI32_GDI32_H__
#define __APIS_WINDOWS_GDI32_GDI32_H__

#include <APIs/Windows/Windows.h>

typedef struct tagPIXELFORMATDESCRIPTOR {
  WORD  nSize; 
  WORD  nVersion; 
  DWORD dwFlags; 
  BYTE  iPixelType; 
  BYTE  cColorBits; 
  BYTE  cRedBits; 
  BYTE  cRedShift; 
  BYTE  cGreenBits; 
  BYTE  cGreenShift; 
  BYTE  cBlueBits; 
  BYTE  cBlueShift; 
  BYTE  cAlphaBits; 
  BYTE  cAlphaShift; 
  BYTE  cAccumBits; 
  BYTE  cAccumRedBits; 
  BYTE  cAccumGreenBits; 
  BYTE  cAccumBlueBits; 
  BYTE  cAccumAlphaBits; 
  BYTE  cDepthBits; 
  BYTE  cStencilBits; 
  BYTE  cAuxBuffers; 
  BYTE  iLayerType; 
  BYTE  bReserved; 
  DWORD dwLayerMask; 
  DWORD dwVisibleMask; 
  DWORD dwDamageMask; 
} PIXELFORMATDESCRIPTOR,
*LPPIXELFORMATDESCRIPTOR;

typedef struct tagBITMAPINFOHEADER{
  DWORD  biSize; 
  LONG   biWidth; 
  LONG   biHeight; 
  WORD   biPlanes; 
  WORD   biBitCount; 
  DWORD  biCompression; 
  DWORD  biSizeImage; 
  LONG   biXPelsPerMeter; 
  LONG   biYPelsPerMeter; 
  DWORD  biClrUsed; 
  DWORD  biClrImportant; 
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef struct tagRGBQUAD {
  BYTE    rgbBlue; 
  BYTE    rgbGreen; 
  BYTE    rgbRed; 
  BYTE    rgbReserved; 
} RGBQUAD;

typedef struct tagBITMAPINFO { 
  BITMAPINFOHEADER bmiHeader; 
  RGBQUAD          bmiColors[1]; 
} BITMAPINFO, *PBITMAPINFO;

WINAPI int ChoosePixelFormat(
  HDC  hdc,
  CONST PIXELFORMATDESCRIPTOR *  ppfd
);

WINAPI BOOL SetPixelFormat(
  HDC  hdc,
  int  iPixelFormat,
  CONST PIXELFORMATDESCRIPTOR *  ppfd
);

WINAPI BOOL SwapBuffers(
  HDC  hdc
);

WINAPI HDC CreateCompatibleDC(
  HDC hdc
);

WINAPI int GetDeviceCaps(
  HDC hdc,
  int nIndex
);

WINAPI HGDIOBJ SelectObject(
  HDC hdc,
  HGDIOBJ hgdiobj
);

WINAPI BOOL DeleteObject(
  HGDIOBJ hObject
);

WINAPI BOOL GdiFlush();

WINAPI BOOL DeleteDC(
  HDC hdc
);

WINAPI int SetDIBits(
  HDC hdc,
  HBITMAP hbmp,
  UINT uStartScan,
  UINT cScanLines,
  CONST VOID *lpvBits,
  CONST BITMAPINFO *lpbmi,
  UINT fuColorUse
);

WINAPI HBITMAP CreateDIBSection(
  HDC hdc,
  CONST BITMAPINFO *pbmi,
  UINT iUsage,
  VOID **ppvBits,
  HANDLE hSection,
  DWORD dwOffset
);

WINAPI BOOL GetDeviceGammaRamp(
  HDC hDC,
  LPVOID lpRamp
);

WINAPI BOOL SetDeviceGammaRamp(
  HDC hDC,
  LPVOID lpRamp
);

WINAPI int DescribePixelFormat(
  HDC  hdc,
  int  iPixelFormat,
  UINT  nBytes,
  LPPIXELFORMATDESCRIPTOR  ppfd
);

WINAPI HBITMAP CreateCompatibleBitmap(
  HDC hdc,
  int nWidth,
  int nHeight
);

WINAPI HGDIOBJ GetStockObject(
  int fnObject
);

WINAPI HFONT CreateFontA(
  int nHeight,
  int nWidth,
  int nEscapement,
  int nOrientation,
  int fnWeight,
  DWORD fdwItalic,
  DWORD fdwUnderline,
  DWORD fdwStrikeOut,
  DWORD fdwCharSet,
  DWORD fdwOutputPrecision,
  DWORD fdwClipPrecision,
  DWORD fdwQuality,
  DWORD fdwPitchAndFamily,
  LPCSTR lpszFace
);

WINAPI HDC CreateICA(
  LPCSTR lpszDriver,
  LPCSTR lpszDevice,
  LPCSTR lpszOutput,
  CONST DEVMODE *lpdvmInit
);

#define PFD_DRAW_TO_WINDOW          0x00000004
#define PFD_SUPPORT_OPENGL          0x00000020

#endif
