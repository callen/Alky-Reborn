/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/GDI32/GDI32.h>

#define NUMODULE_NAME "GDI32"

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
) {
	NuWarn("CreateFontA not yet implemented");

	return None;
}
