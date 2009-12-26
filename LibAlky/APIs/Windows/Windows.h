/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_WINDOWS_H__
#define __APIS_WINDOWS_WINDOWS_H__

#include <Nucleus/Nucleus.h>

#ifdef MAC
#define WINAPI __attribute__((stdcall)) __attribute__((force_align_arg_pointer))
#define WINAPI_CDECL __attribute__((force_align_arg_pointer))
#else
#define WINAPI __attribute__((stdcall))
#define WINAPI_CDECL
#endif

#ifndef WINDOWS
#include <APIs/Windows/Types.h>
#endif

#include <APIs/Windows/Core/Core.h>

#ifndef WINDOWS
#include <APIs/Windows/User32/User32.h>
#include <APIs/Windows/AdvApi32/AdvApi32.h>
#include <APIs/Windows/GDI32/GDI32.h>
#include <APIs/Windows/GLU32/GLU32.h>
#include <APIs/Windows/GLUT32/GLUT32.h>
#include <APIs/Windows/IPHlpApi/IPHlpApi.h>
#include <APIs/Windows/Kernel32/Kernel32.h>
#include <APIs/Windows/OLE32/OLE32.h>
#include <APIs/Windows/OLEAUT32/OLEAUT32.h>
#include <APIs/Windows/OpenAL32/OpenAL32.h>
#include <APIs/Windows/OpenGL32/OpenGL32.h>
#include <APIs/Windows/Shell32/Shell32.h>
#include <APIs/Windows/Version/Version.h>
#include <APIs/Windows/WinMM/WinMM.h>
#include <APIs/Windows/WSock32/WSock32.h>
#else
#include <windows.h>
#include <stdint.h>

typedef unsigned char UINT8;
#endif

#include <APIs/Windows/DirectX/DirectX.h>

#endif
