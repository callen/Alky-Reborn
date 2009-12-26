/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
 */

#ifndef __APIS_WINDOWS_DINPUT_DINPUT_H__
#define __APIS_WINDOWS_DINPUT_DINPUT_H__

#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

#define DI_OK                           S_OK
#define DI_NOTATTACHED                  S_FALSE
#define DI_BUFFEROVERFLOW               S_FALSE
#define DI_PROPNOEFFECT                 S_FALSE
#define DI_NOEFFECT                     S_FALSE
#define DI_POLLEDDEVICE                 ((HRESULT)0x00000002L)
#define DI_DOWNLOADSKIPPED              ((HRESULT)0x00000003L)
#define DI_EFFECTRESTARTED              ((HRESULT)0x00000004L)
#define DI_TRUNCATED                    ((HRESULT)0x00000008L)
#define DI_TRUNCATEDANDRESTARTED        ((HRESULT)0x0000000CL)

 typedef struct DIDEVICEOBJECTDATA {
    DWORD dwOfs;
    DWORD dwData;
    DWORD dwTimeStamp;
    DWORD dwSequence;
} DIDEVICEOBJECTDATA, *LPDIDEVICEOBJECTDATA;

typedef struct DIOBJECTDATAFORMAT {
  CONST GUID * pguid;
  DWORD dwOfs;
  DWORD dwType;
  DWORD dwFlags;
} DIOBJECTDATAFORMAT, 
 *LPDIOBJECTDATAFORMAT;

typedef struct DIDATAFORMAT {
  DWORD dwSize;
  DWORD dwObjSize;
  DWORD dwFlags;
  DWORD dwDataSize;
  DWORD dwNumObjs;
  LPDIOBJECTDATAFORMAT rgodf;
} DIDATAFORMAT, 
 *LPDIDATAFORMAT, 
 *LPCDIDATAFORMAT;

typedef struct DIPROPHEADER {
  DWORD dwSize;
  DWORD dwHeaderSize;
  DWORD dwObj;
  DWORD dwHow;
} DIPROPHEADER, 
 *LPDIPROPHEADER,
 *LPCDIPROPHEADER;

WINAPI HRESULT DirectInputCreateA(
  HINSTANCE hinst,
  DWORD dwVersion,
  LPVOID* ppvOut,
  LPUNKNOWN *pUnkOuter
);

WINAPI HRESULT DirectInput8Create(
    HINSTANCE hinst,
    DWORD dwVersion,
    REFIID riidltf,
    LPVOID *ppvOut,
    LPUNKNOWN *pUnkOuter
);

WINAPI HRESULT IDirectInput7_Release(
    void *this_
);

WINAPI HRESULT IDirectInput7_CreateDevice(
  void *this_,
  REFGUID rguid,
  void **lplpDirectInputDevice,
  LPUNKNOWN pUnkOuter
);

WINAPI HRESULT IDirectInputDevice7A_Release(
    void *this_
);

WINAPI HRESULT IDirectInputDeviceA_GetDeviceData(
  void *this_,
  DWORD cbObjectData,
  LPDIDEVICEOBJECTDATA rgdod,
  LPDWORD pdwInOut,
  DWORD dwFlags
);

WINAPI HRESULT IDirectInputDeviceA_SetDataFormat(
  void *this_,
  LPCDIDATAFORMAT lpdf
);

WINAPI HRESULT IDirectInputDeviceA_SetCooperativeLevel(
  void *this_,
  HWND hwnd,
  DWORD dwFlags
);

WINAPI HRESULT IDirectInputDeviceA_SetProperty(
  void *this_,
  REFGUID rguidProp,
  LPCDIPROPHEADER pdiph
);

WINAPI HRESULT IDirectInputDeviceA_Acquire(void *this_);
WINAPI HRESULT IDirectInputDeviceA_Unacquire(void *this_);

typedef void *LPDICONFIGUREDEVICESCALLBACK;
typedef void *LPDICONFIGUREDEVICESPARAMS;

WINAPI HRESULT IDirectInput8_Release(
    void *this_
);

WINAPI HRESULT IDirectInput8_ConfigureDevices(
	void *this_,
	LPDICONFIGUREDEVICESCALLBACK lpdiCallback,
	LPDICONFIGUREDEVICESPARAMS lpdiCDParams,
	DWORD dwFlags
);

WINAPI HRESULT IDirectInput8_CreateDevice(
  void *this_,
  REFGUID rguid,
  void ** lplpDirectInputDevice,
  LPUNKNOWN *pUnkOuter
);

WINAPI HRESULT IDirectInputDevice8_Release(
    void *this_
);

WINAPI HRESULT IDirectInputEffect_Release(
    void *this_
);

#define LOWORD(n) ((n) & 0xFF)

#define DIDFT_ALL		0x00000000
#define DIDFT_RELAXIS		0x00000001
#define DIDFT_ABSAXIS		0x00000002
#define DIDFT_AXIS		0x00000003
#define DIDFT_PSHBUTTON		0x00000004
#define DIDFT_TGLBUTTON		0x00000008
#define DIDFT_BUTTON		0x0000000C
#define DIDFT_POV		0x00000010
#define DIDFT_COLLECTION	0x00000040
#define DIDFT_NODATA		0x00000080
#define DIDFT_OPTIONAL		0x80000000
#define DIDFT_ANYINSTANCE	0x00FFFF00
#define DIDFT_INSTANCEMASK	DIDFT_ANYINSTANCE
#define DIDFT_MAKEINSTANCE(n)	((WORD)(n) << 8)
#define DIDFT_GETTYPE(n)	LOBYTE(n)
#define DIDFT_GETINSTANCE(n)	LOWORD((n) >> 8)
#define DIDFT_FFACTUATOR	0x01000000
#define DIDFT_FFEFFECTTRIGGER	0x02000000
#define DIDFT_OUTPUT		0x10000000
#define DIDFT_ENUMCOLLECTION(n)	((WORD)(n) << 8)
#define DIDFT_NOCOLLECTION	0x00FFFF00
#define DIDF_ABSAXIS		0x00000001
#define DIDF_RELAXIS		0x00000002

#define DIGDD_PEEK			0x00000001

#define DI8DEVTYPE_DEVICE           0x11
#define DI8DEVTYPE_MOUSE            0x12
#define DI8DEVTYPE_KEYBOARD         0x13
#define DI8DEVTYPE_JOYSTICK         0x14
#define DI8DEVTYPE_GAMEPAD          0x15
#define DI8DEVTYPE_DRIVING          0x16
#define DI8DEVTYPE_FLIGHT           0x17
#define DI8DEVTYPE_1STPERSON        0x18
#define DI8DEVTYPE_DEVICECTRL       0x19
#define DI8DEVTYPE_SCREENPOINTER    0x1A
#define DI8DEVTYPE_REMOTE           0x1B
#define DI8DEVTYPE_SUPPLEMENTAL     0x1C

#endif
