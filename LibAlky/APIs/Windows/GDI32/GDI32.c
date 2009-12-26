/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/GDI32/GDI32.h>

#define NUMODULE_NAME "GDI32"

WINAPI int ChoosePixelFormat(
  HDC  hdc,
  CONST PIXELFORMATDESCRIPTOR *  ppfd
) {
	NuWarn("ChoosePixelFormat not yet implemented");
	
	return True;
}

WINAPI BOOL SetPixelFormat(
  HDC  hdc,
  int  iPixelFormat,
  CONST PIXELFORMATDESCRIPTOR *  ppfd
) {
	NuWarn("SetPixelFormat not yet implemented");
	
	return True;
}

WINAPI BOOL SwapBuffers(
  HDC  hdc
) {
	NuGUI_SwapBuffers((NuGUI_Window *) hdc);
	
	return True;
}

WINAPI HGDIOBJ SelectObject(
  HDC hdc,
  HGDIOBJ hgdiobj
) {
	NuWarn("SelectObject not yet implemented");
	
	return hgdiobj;
}

WINAPI BOOL DeleteObject(
  HGDIOBJ hObject
) {
	NuWarn("DeleteObject not yet implemented");
	
	return True;
}

WINAPI BOOL GdiFlush() {
	NuWarn("GdiFlush not yet implemented");
	
	return True;
}

WINAPI int DescribePixelFormat(
  HDC  hdc,
  int  iPixelFormat,
  UINT  nBytes,
  LPPIXELFORMATDESCRIPTOR  ppfd
) {
	NuWarn("DescribePixelFormat not yet implemented");
	
	ppfd->dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	ppfd->cColorBits = 24;
	ppfd->cRedBits = 8;
	ppfd->cRedShift = 24;
	ppfd->cGreenBits = 8;
	ppfd->cGreenShift = 16;
	ppfd->cBlueBits = 8;
	ppfd->cBlueShift = 8;
	ppfd->cAlphaBits = 8;
	ppfd->cAlphaShift = 0;	
	
	return 10;
}

WINAPI HBITMAP CreateCompatibleBitmap(
  HDC hdc,
  int nWidth,
  int nHeight
) {
	NuWarn("CreateCompatibleBitmap not yet implemented");
	
	return None;
}

WINAPI HGDIOBJ GetStockObject(
  int fnObject
) {
	NuWarn("GetStockObject not yet implemented");
	
	return None;
}
