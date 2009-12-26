/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_USER32_USER32_H__
#define __APIS_WINDOWS_USER32_USER32_H__

typedef struct _RECT RECT;
typedef struct _RECT *LPRECT;

typedef struct _RGNDATA RGNDATA;
typedef struct _RGNDATA *PRGNDATA;

#include <APIs/Windows/Windows.h>

typedef struct WNDCLASSA_s {
	UINT      style;
	WNDPROC   lpfnWndProc;
	INT       cbClsExtra;
	INT       cbWndExtra;
	HINSTANCE hInstance;
	HICON     hIcon;
	HCURSOR   hCursor;
	HBRUSH    hbrBackground;
	LPCSTR      lpszMenuName;
	LPCSTR      lpszClassName;
} WNDCLASSA, *PWNDCLASSA, *LPWNDCLASSA;

typedef struct {
    UINT cbSize;
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
    HICON hIconSm;
} WNDCLASSEXA, *PWNDCLASSEXA, *LPWNDCLASSEXA;

struct _RECT { 
  LONG left;
  LONG top;
  LONG right;
  LONG bottom;
};

typedef struct _RGNDATAHEADER {
    DWORD   dwSize;
    DWORD   iType;
    DWORD   nCount;
    DWORD   nRgnSize;
    RECT    rcBound;
} RGNDATAHEADER, *PRGNDATAHEADER;

struct _RGNDATA {
    RGNDATAHEADER   rdh;
    char            Buffer[1];
};

typedef struct {
	LONG x, y;
} POINT,
*LPPOINT;

typedef struct {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
} MSG, *PMSG, *LPMSG;

typedef struct _POINTL {
    LONG x;
    LONG y;
} POINTL;

typedef VOID (WINAPI *TIMERPROC)(
    HWND hwnd,
    UINT uMsg,
    UINT_PTR idEvent,
    DWORD dwTime
);

typedef struct User32_s {
	int message_start;
	MSG *messages[1024];
	
	WINAPI LRESULT (*msgHookProc)(int code, WPARAM wParam, LPARAM lParam);
} User32;

NuContext_SingletonDecl(User32_GetContext, User32);

WINAPI int MessageBoxA(
    void *hWnd,
    char *lpText,
    char *lpCaption,
    int uType
);

WINAPI BOOL GetCursorPos(
    LPPOINT lpPoint
);

WINAPI int GetSystemMetrics(
  int nIndex
);

WINAPI BOOL GetUserObjectInformationA(
  HANDLE hObj,
  int nIndex,
  PVOID pvInfo,
  DWORD nLength,
  LPDWORD lpnLengthNeeded
);

WINAPI HWINSTA GetProcessWindowStation(void);

WINAPI UINT_PTR SetTimer(
    HWND hWnd,
    UINT_PTR nIDEvent,
    UINT uElapse,
    TIMERPROC lpTimerFunc
);

WINAPI UINT GetDoubleClickTime();

WINAPI ATOM RegisterClassA(
    CONST WNDCLASSA *lpWndClass
);

WINAPI ATOM RegisterClassExA(
    CONST WNDCLASSEXA *lpWndClass
);

WINAPI BOOL UnregisterClassA(
	LPCSTR lpClassName,
	HINSTANCE hInstance
);

WINAPI DWORD GetClassLongA(
	HWND hWnd,
	int nIndex
);

WINAPI DWORD GetWindowLongA(
	HWND hWnd,
	int nIndex
);

WINAPI HWND CreateWindowExA(
	DWORD dwExStyle, 
	LPCSTR lpClassName, 
	LPCSTR lpWindowName, 
	DWORD dwStyle, 
	int x, 
	int y, 
	int nWidth, 
	int nHeight, 
	HWND hWndParent, 
	HMENU hMenu, 
	HINSTANCE hInstance, 
	LPVOID lpParam 
);

WINAPI BOOL DestroyWindow(
    HWND hWnd
);

WINAPI BOOL ShowWindow(
    HWND hWnd,
    int nCmdShow
);

WINAPI BOOL UpdateWindow(
    HWND hWnd
);

WINAPI BOOL CloseWindow(
    HWND hWnd
);

WINAPI BOOL SetForegroundWindow(
    HWND hWnd
);

WINAPI HWND GetFocus();

WINAPI HWND SetFocus(
    HWND hWnd
);

WINAPI HWND GetActiveWindow(VOID);
WINAPI HWND GetDesktopWindow(VOID);
WINAPI HWND GetLastActivePopup(VOID);

WINAPI LONG SetWindowLongA(
    HWND hWnd,
    int nIndex,
    LONG dwNewLong
);

WINAPI BOOL SetWindowTextA(
    HWND hWnd,
    LPCSTR lpString
);

WINAPI BOOL SetWindowPos(
    HWND hWnd,
    HWND hWndInsertAfter,
    int X,
    int Y,
    int cx,
    int cy,
    UINT uFlags
);

WINAPI HWND GetForegroundWindow(VOID);

WINAPI HWND FindWindowA(
	LPCSTR lpClassName,
	LPCSTR lpWindowName
);

WINAPI BOOL SwapMouseButton(
	BOOL fSwap
);

WINAPI BOOL AdjustWindowRect( 
  LPRECT lpRect, 
  DWORD dwStyle, 
  BOOL bMenu
);

WINAPI BOOL GetClientRect(
    HWND hWnd,
    LPRECT lpRect
);

WINAPI BOOL AdjustWindowRectEx( 
  LPRECT lpRect, 
  DWORD dwStyle, 
  BOOL bMenu, 
  DWORD dwExStyle 
);

WINAPI HICON LoadIconA(
    HINSTANCE hInstance,
    LPCSTR lpIconName
);

WINAPI HCURSOR LoadCursorA(
    HINSTANCE hInstance,
    LPCSTR lpCursorName
);

WINAPI HCURSOR SetCursor(
    HCURSOR hCursor
);

WINAPI int ShowCursor_(
    BOOL bShow
);

WINAPI HDC GetDC(
  HWND hWnd
);

WINAPI int ReleaseDC(
  HWND hWnd,
  HDC hDC
);

WINAPI BOOL EnumDisplaySettings(
  LPCSTR lpszDeviceName,
  DWORD iModeNum,
  LPDEVMODE lpDevMode
);

WINAPI LONG ChangeDisplaySettingsA(
  LPDEVMODE lpDevMode,
  DWORD dwflags
);

WINAPI BOOL PeekMessageA(
    LPMSG lpMsg,
    HWND hWnd,
    UINT wMsgFilterMin,
    UINT wMsgFilterMax,
    UINT wRemoveMsg
);

WINAPI BOOL GetMessageA(
    LPMSG lpMsg,
    HWND hWnd,
    UINT wMsgFilterMin,
    UINT wMsgFilterMax
);

WINAPI BOOL TranslateMessage(
    MSG *lpMsg
);

bool PostMessage(MSG *message);

WINAPI LRESULT DispatchMessageA(
    const MSG *lpmsg
);

WINAPI UINT RegisterWindowMessageA(
    LPCSTR lpString
);

WINAPI LRESULT SendMessageA(
    HWND hWnd,
    UINT Msg,
    WPARAM wParam,
    LPARAM lParam
);

WINAPI LRESULT DefWindowProcA(
    HWND hWnd,
    UINT Msg,
    WPARAM wParam,
    LPARAM lParam
);

WINAPI void PostQuitMessage(
    int nExitCode
);

WINAPI UINT RegisterClipboardFormatA(
    LPCSTR lpszFormat
);

WINAPI BOOL OpenClipboard(
    HWND hWndNewOwner
);

WINAPI BOOL CloseClipboard();

WINAPI BOOL EmptyClipboard();

WINAPI HANDLE SetClipboardData(
    UINT uFormat,
    HANDLE hMem
);

WINAPI DWORD GetSysColor(
  int nIndex
);

WINAPI HBRUSH GetSysColorBrush(
  int nIndex
);

WINAPI UINT MapVirtualKeyA(
  UINT uCode,
  UINT uMapType
);

WINAPI int ToAscii(
    UINT uVirtKey,
    UINT uScanCode,
    PBYTE lpKeyState,
    LPWORD lpChar,
    UINT uFlags
);

WINAPI SHORT GetKeyState(
    int nVirtKey
);

WINAPI HHOOK SetWindowsHookExA(
    int idHook,
    HOOKPROC lpfn,
    HINSTANCE hMod,
    DWORD dwThreadId
);

#define DISP_CHANGE_SUCCESSFUL 0

#define IDOK                1
#define IDCANCEL            2
#define IDABORT             3
#define IDRETRY             4
#define IDIGNORE            5
#define IDYES               6
#define IDNO                7
#define IDCLOSE             8
#define IDHELP              9

#define HC_ACTION           0
#define HC_GETNEXT          1
#define HC_SKIP             2
#define HC_NOREMOVE         3
#define HC_NOREM            HC_NOREMOVE
#define HC_SYSMODALON       4
#define HC_SYSMODALOFF      5

#define PM_NOREMOVE         0x0000
#define PM_REMOVE           0x0001
#define PM_NOYIELD          0x0002

#define WH_MIN              (-1)
#define WH_MSGFILTER        (-1)
#define WH_JOURNALRECORD    0
#define WH_JOURNALPLAYBACK  1
#define WH_KEYBOARD         2
#define WH_GETMESSAGE       3
#define WH_CALLWNDPROC      4
#define WH_CBT              5
#define WH_SYSMSGFILTER     6
#define WH_MOUSE            7
#define WH_HARDWARE         8
#define WH_DEBUG            9
#define WH_SHELL           10
#define WH_FOREGROUNDIDLE  11
#define WH_CALLWNDPROCRET  12

#define WM_NULL                 0x0000
#define WM_CREATE               0x0001
#define WM_DESTROY              0x0002
#define WM_MOVE                 0x0003
#define WM_SIZEWAIT             0x0004
#define WM_SIZE                 0x0005
#define WM_ACTIVATE             0x0006
#define WM_SETFOCUS             0x0007
#define WM_KILLFOCUS            0x0008
#define WM_SETVISIBLE           0x0009
#define WM_ENABLE               0x000a
#define WM_SETREDRAW            0x000b
#define WM_SETTEXT              0x000c
#define WM_GETTEXT              0x000d
#define WM_GETTEXTLENGTH        0x000e
#define WM_PAINT                0x000f
#define WM_CLOSE                0x0010
#define WM_QUERYENDSESSION      0x0011
#define WM_QUIT                 0x0012
#define WM_QUERYOPEN            0x0013
#define WM_ERASEBKGND           0x0014
#define WM_SYSCOLORCHANGE       0x0015
#define WM_ENDSESSION           0x0016
#define WM_SYSTEMERROR          0x0017
#define WM_SHOWWINDOW           0x0018
#define WM_CTLCOLOR             0x0019
#define WM_WININICHANGE         0x001a
#define WM_SETTINGCHANGE        WM_WININICHANGE
#define WM_DEVMODECHANGE        0x001b
#define WM_ACTIVATEAPP          0x001c
#define WM_FONTCHANGE           0x001d
#define WM_TIMECHANGE           0x001e
#define WM_CANCELMODE           0x001f
#define WM_SETCURSOR            0x0020
#define WM_MOUSEACTIVATE        0x0021
#define WM_CHILDACTIVATE        0x0022
#define WM_QUEUESYNC            0x0023
#define WM_GETMINMAXINFO        0x0024

#define WM_KEYDOWN          0x0100
#define WM_KEYUP            0x0101
#define WM_CHAR             0x0102
#define WM_DEADCHAR         0x0103

#define WM_MOUSEFIRST                   0x0200
#define WM_MOUSEMOVE                    0x0200
#define WM_LBUTTONDOWN                  0x0201
#define WM_LBUTTONUP                    0x0202
#define WM_LBUTTONDBLCLK                0x0203
#define WM_RBUTTONDOWN                  0x0204
#define WM_RBUTTONUP                    0x0205
#define WM_RBUTTONDBLCLK                0x0206
#define WM_MBUTTONDOWN                  0x0207
#define WM_MBUTTONUP                    0x0208
#define WM_MBUTTONDBLCLK                0x0209

/* Virtual key codes */
#define VK_LBUTTON          0x01
#define VK_RBUTTON          0x02
#define VK_CANCEL           0x03
#define VK_MBUTTON          0x04
/*                          0x05-0x07  Undefined */
#define VK_BACK             0x08
#define VK_TAB              0x09
/*                          0x0A-0x0B  Undefined */
#define VK_CLEAR            0x0C
#define VK_RETURN           0x0D
/*                          0x0E-0x0F  Undefined */
#define VK_SHIFT            0x10
#define VK_CONTROL          0x11
#define VK_MENU             0x12
#define VK_PAUSE            0x13
#define VK_CAPITAL          0x14
/*                          0x15-0x19  Reserved for Kanji systems */
/*                          0x1A       Undefined */
#define VK_ESCAPE           0x1B
/*                          0x1C-0x1F  Reserved for Kanji systems */
#define VK_SPACE            0x20
#define VK_PRIOR            0x21
#define VK_NEXT             0x22
#define VK_END              0x23
#define VK_HOME             0x24
#define VK_LEFT             0x25
#define VK_UP               0x26
#define VK_RIGHT            0x27
#define VK_DOWN             0x28
#define VK_SELECT           0x29
#define VK_PRINT            0x2A /* OEM specific in Windows 3.1 SDK */
#define VK_EXECUTE          0x2B
#define VK_SNAPSHOT         0x2C
#define VK_INSERT           0x2D
#define VK_DELETE           0x2E
#define VK_HELP             0x2F
#define VK_0                0x30
#define VK_1                0x31
#define VK_2                0x32
#define VK_3                0x33
#define VK_4                0x34
#define VK_5                0x35
#define VK_6                0x36
#define VK_7                0x37
#define VK_8                0x38
#define VK_9                0x39
/*                          0x3A-0x40  Undefined */
#define VK_A                0x41
#define VK_B                0x42
#define VK_C                0x43
#define VK_D                0x44
#define VK_E                0x45
#define VK_F                0x46
#define VK_G                0x47
#define VK_H                0x48
#define VK_I                0x49
#define VK_J                0x4A
#define VK_K                0x4B
#define VK_L                0x4C
#define VK_M                0x4D
#define VK_N                0x4E
#define VK_O                0x4F
#define VK_P                0x50
#define VK_Q                0x51
#define VK_R                0x52
#define VK_S                0x53
#define VK_T                0x54
#define VK_U                0x55
#define VK_V                0x56
#define VK_W                0x57
#define VK_X                0x58
#define VK_Y                0x59
#define VK_Z                0x5A

#define VK_LWIN             0x5B
#define VK_RWIN             0x5C
#define VK_APPS             0x5D
/*                          0x5E-0x5F Unassigned */
#define VK_NUMPAD0          0x60
#define VK_NUMPAD1          0x61
#define VK_NUMPAD2          0x62
#define VK_NUMPAD3          0x63
#define VK_NUMPAD4          0x64
#define VK_NUMPAD5          0x65
#define VK_NUMPAD6          0x66
#define VK_NUMPAD7          0x67
#define VK_NUMPAD8          0x68
#define VK_NUMPAD9          0x69
#define VK_MULTIPLY         0x6A
#define VK_ADD              0x6B
#define VK_SEPARATOR        0x6C
#define VK_SUBTRACT         0x6D
#define VK_DECIMAL          0x6E
#define VK_DIVIDE           0x6F
#define VK_F1               0x70
#define VK_F2               0x71
#define VK_F3               0x72
#define VK_F4               0x73
#define VK_F5               0x74
#define VK_F6               0x75
#define VK_F7               0x76
#define VK_F8               0x77
#define VK_F9               0x78
#define VK_F10              0x79
#define VK_F11              0x7A
#define VK_F12              0x7B
#define VK_F13              0x7C
#define VK_F14              0x7D
#define VK_F15              0x7E
#define VK_F16              0x7F
#define VK_F17              0x80
#define VK_F18              0x81
#define VK_F19              0x82
#define VK_F20              0x83
#define VK_F21              0x84
#define VK_F22              0x85
#define VK_F23              0x86
#define VK_F24              0x87
/*                          0x88-0x8F  Unassigned */
#define VK_NUMLOCK          0x90
#define VK_SCROLL           0x91
/*                          0x92-0x9F  Unassigned */

#endif
