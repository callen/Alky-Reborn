/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_KERNEL32_KERNEL32_H__
#define __APIS_WINDOWS_KERNEL32_KERNEL32_H__

#include <APIs/Windows/Windows.h>

#include <glob.h>

struct Kernel32_s {
	DWORD lastError;
	void *lpTopLevelExceptionFilter;
} typedef Kernel32;

typedef struct _SECURITY_ATTRIBUTES {
  DWORD nLength;
  LPVOID lpSecurityDescriptor;
  BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, 
 *PSECURITY_ATTRIBUTES,
 *LPSECURITY_ATTRIBUTES;

typedef struct _OVERLAPPED {
  ULONG_PTR Internal;
  ULONG_PTR InternalHigh;
  union {
    struct {
      DWORD Offset;
      DWORD OffsetHigh;
    };
    PVOID Pointer;
  };
  HANDLE hEvent;
} OVERLAPPED, 
 *LPOVERLAPPED;

typedef struct _OSVERSIONINFOA {
  DWORD dwOSVersionInfoSize;
  DWORD dwMajorVersion;
  DWORD dwMinorVersion;
  DWORD dwBuildNumber;
  DWORD dwPlatformId;
  CHAR szCSDVersion[128];
} OSVERSIONINFOA;

typedef struct _OSVERSIONINFOEXA {
  DWORD dwOSVersionInfoSize;
  DWORD dwMajorVersion;
  DWORD dwMinorVersion;
  DWORD dwBuildNumber;
  DWORD dwPlatformId;
  CHAR szCSDVersion[128];
  WORD wServicePackMajor;
  WORD wServicePackMinor;
  WORD wSuiteMask;
  BYTE wProductType;
  BYTE wReserved;
} OSVERSIONINFOEXA, 
 *POSVERSIONINFOEXA, 
 *LPOSVERSIONINFOEXA;

typedef struct _FILETIME {
  DWORD dwLowDateTime;
  DWORD dwHighDateTime;
} FILETIME, 
 *LPFILETIME;

typedef struct _SYSTEMTIME {
  WORD wYear;
  WORD wMonth;
  WORD wDayOfWeek;
  WORD wDay;
  WORD wHour;
  WORD wMinute;
  WORD wSecond;
  WORD wMilliseconds;
} SYSTEMTIME, 
 *PSYSTEMTIME,
 *LPSYSTEMTIME;

typedef struct _TIME_ZONE_INFORMATION {
  LONG Bias;
  WCHAR StandardName[32];
  SYSTEMTIME StandardDate;
  LONG StandardBias;
  WCHAR DaylightName[32];
  SYSTEMTIME DaylightDate;
  LONG DaylightBias;
} TIME_ZONE_INFORMATION,
 *PTIME_ZONE_INFORMATION,
*LPTIME_ZONE_INFORMATION;

typedef struct _CRITICAL_SECTION {
	int foo;
} *LPCRITICAL_SECTION;

// These should be right...
#define MAX_DEFAULTCHAR 2
#define MAX_LEADBYTES 12

struct _cpinfo { 
  UINT MaxCharSize; 
  BYTE DefaultChar[MAX_DEFAULTCHAR]; 
  BYTE LeadByte[MAX_LEADBYTES]; 
} typedef CPINFO, *LPCPINFO;

typedef struct _MEMORYSTATUS {
  DWORD dwLength;
  DWORD dwMemoryLoad;
  SIZE_T dwTotalPhys;
  SIZE_T dwAvailPhys;
  SIZE_T dwTotalPageFile;
  SIZE_T dwAvailPageFile;
  SIZE_T dwTotalVirtual;
  SIZE_T dwAvailVirtual;
} MEMORYSTATUS, 
 *LPMEMORYSTATUS;

typedef struct _MEMORYSTATUSEX {
  DWORD dwLength;
  DWORD dwMemoryLoad;
  DWORDLONG ullTotalPhys;
  DWORDLONG ullAvailPhys;
  DWORDLONG ullTotalPageFile;
  DWORDLONG ullAvailPageFile;
  DWORDLONG ullTotalVirtual;
  DWORDLONG ullAvailVirtual;
  DWORDLONG ullAvailExtendedVirtual;
} MEMORYSTATUSEX, 
 *LPMEMORYSTATUSEX;

typedef struct _MEMORY_BASIC_INFORMATION {
  PVOID BaseAddress;
  PVOID AllocationBase;
  DWORD AllocationProtect;
  SIZE_T RegionSize;
  DWORD State;
  DWORD Protect;
  DWORD Type;
} MEMORY_BASIC_INFORMATION, 
 *PMEMORY_BASIC_INFORMATION;

typedef struct _SYSTEM_INFO {
  union {
    DWORD dwOemId;
    struct {
      WORD wProcessorArchitecture;
      WORD wReserved;
    };
  };
  DWORD dwPageSize;
  LPVOID lpMinimumApplicationAddress;
  LPVOID lpMaximumApplicationAddress;
  DWORD_PTR dwActiveProcessorMask;
  DWORD dwNumberOfProcessors;
  DWORD dwProcessorType;
  DWORD dwAllocationGranularity;
  WORD wProcessorLevel;
  WORD wProcessorRevision;
} SYSTEM_INFO,
*LPSYSTEM_INFO;

#define MAX_PATH 260

typedef struct _WIN32_FIND_DATAA {
  DWORD dwFileAttributes;
  FILETIME ftCreationTime;
  FILETIME ftLastAccessTime;
  FILETIME ftLastWriteTime;
  DWORD nFileSizeHigh;
  DWORD nFileSizeLow;
  DWORD dwReserved0;
  DWORD dwReserved1;
  CHAR cFileName[MAX_PATH];
  CHAR cAlternateFileName[14];
} WIN32_FIND_DATAA, 
 *PWIN32_FIND_DATAA, 
 *LPWIN32_FIND_DATAA;

typedef VOID (WINAPI *PTIMERAPCROUTINE)(
  LPVOID lpArgToCompletionRoutine,
  DWORD dwTimerLowValue,
  DWORD dwTimerHighValue
);

typedef struct _BY_HANDLE_FILE_INFORMATION {
  DWORD dwFileAttributes;
  FILETIME ftCreationTime;
  FILETIME ftLastAccessTime;
  FILETIME ftLastWriteTime;
  DWORD dwVolumeSerialNumber;
  DWORD nFileSizeHigh;
  DWORD nFileSizeLow;
  DWORD nNumberOfLinks;
  DWORD nFileIndexHigh;
  DWORD nFileIndexLow;
} BY_HANDLE_FILE_INFORMATION, 
 *LPBY_HANDLE_FILE_INFORMATION;

WINAPI DWORD TlsAlloc(void);
WINAPI LPVOID TlsGetValue(DWORD dwTlsIndex);
WINAPI BOOL TlsSetValue(DWORD dwTlsIndex, LPVOID value);
WINAPI BOOL TlsFree(DWORD dwTlsIndex);

WINAPI DWORD FlsAlloc(void *callback);
WINAPI LPVOID FlsGetValue(DWORD dwTlsIndex);
WINAPI BOOL FlsSetValue(DWORD dwTlsIndex, LPVOID value);
WINAPI BOOL FlsFree(DWORD dwTlsIndex);

WINAPI void InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
WINAPI void DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
WINAPI void TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
WINAPI void EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
WINAPI void LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
WINAPI LONG InterlockedDecrement(LONG volatile* Addend);
WINAPI LONG InterlockedIncrement(LONG volatile* Addend);
WINAPI LONG InterlockedExchange(LPLONG Target, LONG Value);

WINAPI HANDLE CreateMutexA(
  LPSECURITY_ATTRIBUTES lpMutexAttributes,
  BOOL bInitialOwner,
  LPCSTR lpName
);

WINAPI HANDLE CreateSemaphoreA(
  LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
  LONG lInitialCount,
  LONG lMaximumCount,
  LPCSTR lpName
);

WINAPI BOOL ReleaseSemaphore(
	HANDLE hSemaphore,
	LONG lReleaseCount,
	LPLONG lpPreviousCount
);

WINAPI HANDLE CreateEventA(
  LPSECURITY_ATTRIBUTES lpEventAttributes,
  BOOL bManualReset,
  BOOL bInitialState,
  LPCSTR lpName
);

WINAPI BOOL SetEvent(
  HANDLE hEvent
);

WINAPI BOOL ResetEvent(
  HANDLE hEvent
);

WINAPI DWORD WaitForSingleObject(
  HANDLE hHandle,
  DWORD dwMilliseconds
);

WINAPI void ExitProcess(
	int exit_code
);

WINAPI DWORD GetVersion(void);

WINAPI BOOL GetVersionExA(
  LPOSVERSIONINFOEXA lpVersionInfo
);

WINAPI DWORD GetLastError(void);
WINAPI void SetLastError(DWORD error);

DWORD Kernel32_GetLastError(void);
void Kernel32_SetLastError(DWORD error);

WINAPI BOOL IsBadReadPtr(
  const VOID* lp,
  UINT_PTR ucb
);

WINAPI BOOL IsBadWritePtr(
  const VOID* lp,
  UINT_PTR ucb
);

WINAPI HANDLE GetProcessHeap(void);

WINAPI HANDLE HeapCreate(
  DWORD flOptions,
  SIZE_T dwInitialSize,
  SIZE_T dwMaximumSize
);

WINAPI LPVOID HeapAlloc(
  HANDLE hHeap,
  DWORD dwFlags,
  SIZE_T dwBytes
);

WINAPI LPVOID HeapReAlloc(
  HANDLE hHeap,
  DWORD dwFlags,
  LPVOID lpMem,
  SIZE_T dwBytes
);

WINAPI BOOL HeapFree(
  HANDLE hHeap,
  DWORD dwFlags,
  LPVOID lpMem
);

WINAPI SIZE_T HeapSize(
  HANDLE hHeap,
  DWORD dwFlags,
  LPCVOID lpMem
);

WINAPI BOOL HeapValidate(
  HANDLE hHeap,
  DWORD dwFlags,
  LPCVOID lpMem
);

WINAPI LPVOID VirtualAlloc(
  LPVOID lpAddress,
  SIZE_T dwSize,
  DWORD flAllocationType,
  DWORD flProtect
);

WINAPI HLOCAL LocalAlloc(
  UINT uFlags,
  SIZE_T uBytes
);

WINAPI LOCAL LocalReAlloc(
  HLOCAL hMem,
  SIZE_T uBytes,
  UINT uFlags
);

WINAPI HLOCAL LocalFree(
  HLOCAL hMem
);

WINAPI HLOCAL GlobalAlloc(
  UINT uFlags,
  SIZE_T uBytes
);

WINAPI HLOCAL GlobalReAlloc(
  HLOCAL hMem,
  SIZE_T uBytes,
  UINT uFlags
);

WINAPI HLOCAL GlobalFree(
  HLOCAL hMem
);

WINAPI LPVOID GlobalLock(
  HGLOBAL hMem
);

WINAPI LPVOID GlobalUnlock(
  HGLOBAL hMem
);

WINAPI PVOID EncodePointer(
  PVOID Ptr
);

WINAPI PVOID DecodePointer(
  PVOID Ptr
);

WINAPI void GlobalMemoryStatus(
  LPMEMORYSTATUS lpBuffer
);

WINAPI BOOL GlobalMemoryStatusEx(
  LPMEMORYSTATUSEX lpBuffer
);

WINAPI BOOL VirtualLock(
  LPVOID lpAddress,
  SIZE_T dwSize
);

WINAPI SIZE_T VirtualQuery(
  LPCVOID lpAddress,
  PMEMORY_BASIC_INFORMATION lpBuffer,
  SIZE_T dwLength
);

WINAPI VOID GetStartupInfoA(
  LPSTARTUPINFOA lpStartupInfo
);

WINAPI VOID GetStartupInfoW(
  LPSTARTUPINFOW lpStartupInfo
);

WINAPI void GetSystemInfo(
  LPSYSTEM_INFO lpSystemInfo
);

WINAPI void OutputDebugStringA(
  LPCSTR lpOutputString
);

WINAPI BOOL IsDebuggerPresent();

WINAPI void RaiseException(
  DWORD dwExceptionCode,
  DWORD dwExceptionFlags,
  DWORD nNumberOfArguments,
  const ULONG_PTR* lpArguments
);

WINAPI HANDLE CreateFileA(
  LPCSTR lpFileName,
  DWORD dwDesiredAccess,
  DWORD dwShareMode,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  DWORD dwCreationDisposition,
  DWORD dwFlagsAndAttributes,
  HANDLE hTemplateFile
);

WINAPI BOOL ReadFile(
  HANDLE hFile,
  LPVOID lpBuffer,
  DWORD nNumberOfBytesToRead,
  LPDWORD lpNumberOfBytesRead,
  LPOVERLAPPED lpOverlapped
);

WINAPI BOOL CopyFileA(
	LPCSTR lpExistingFileName,
	LPCSTR lpNewFileName,
	BOOL bFailIfExists
);

WINAPI DWORD SetFilePointer(
  HANDLE hFile,
  LONG lDistanceToMove,
  PLONG lpDistanceToMoveHigh,
  DWORD dwMoveMethod
);

WINAPI HANDLE CreateFileMappingA(
  HANDLE hFile, 
  LPSECURITY_ATTRIBUTES lpFileMappingAttributes, 
  DWORD flProtect, 
  DWORD dwMaximumSizeHigh, 
  DWORD dwMaximumSizeLow, 
  LPCSTR lpName 
);

WINAPI LPVOID MapViewOfFile(
  HANDLE hFileMappingObject,
  DWORD dwDesiredAccess,
  DWORD dwFileOffsetHigh,
  DWORD dwFileOffsetLow,
  SIZE_T dwNumberOfBytesToMap
);

WINAPI BOOL UnmapViewOfFile(
  LPCVOID lpBaseAddress
);

WINAPI BOOL CloseHandle(
  HANDLE hObject
);

WINAPI DWORD GetFileType(
  HANDLE hFile
);

WINAPI UINT SetHandleCount(
  UINT count
);

WINAPI DWORD GetFullPathNameA(
  LPCSTR lpFileName,
  DWORD nBufferLength,
  LPSTR lpBuffer,
  LPSTR* lpFilePart
);

WINAPI DWORD GetCurrentDirectoryA(
  DWORD nBufferLength,
  LPSTR lpBuffer
);

WINAPI HANDLE FindFirstFileA(
  LPCSTR lpFileName,
  LPWIN32_FIND_DATAA lpFindFileData
);

WINAPI BOOL FindNextFileA(
  HANDLE hFindFile,
  LPWIN32_FIND_DATAA lpFindFileData
);

WINAPI BOOL FindClose(
  HANDLE hFindFile
);

WINAPI BOOL CreateDirectoryA(
  LPCSTR lpPathName,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

WINAPI BOOL GetDiskFreeSpaceExA(
  LPCSTR lpDirectoryName,
  PULARGE_INTEGER lpFreeBytesAvailable,
  PULARGE_INTEGER lpTotalNumberOfBytes,
  PULARGE_INTEGER lpTotalNumberOfFreeBytes
);

WINAPI DWORD GetLogicalDrives();
WINAPI DWORD GetIllogicalDrives();

WINAPI DWORD GetLogicalDriveStringsA(
  DWORD nBufferLength,
  LPSTR lpBuffer
);

WINAPI BOOL GetVolumeInformationA(
  LPCSTR lpRootPathName,
  LPSTR lpVolumeNameBuffer,
  DWORD nVolumeNameSize,
  LPDWORD lpVolumeSerialNumber,
  LPDWORD lpMaximumComponentLength,
  LPDWORD lpFileSystemFlags,
  LPSTR lpFileSystemNameBuffer,
  DWORD nFileSystemNameSize
);

WINAPI BOOL DeleteFileA(
  LPCSTR lpFileName
);

WINAPI BOOL GetFileInformationByHandle(
  HANDLE hFile,
  LPBY_HANDLE_FILE_INFORMATION lpFileInformation
);

WINAPI UINT GetPrivateProfileIntA(
  LPCSTR lpAppName,
  LPCSTR lpKeyName,
  INT nDefault,
  LPCSTR lpFileName
);

WINAPI DWORD GetFileAttributesA(LPCSTR lpFileName);

WINAPI BOOL DuplicateHandle(
	HANDLE hSourceProcessHandle,
	HANDLE hSourceHandle,
	HANDLE hTargetProcessHandle,
	LPHANDLE hTargetHandle,
	DWORD dwDesiredAccess,
	BOOL bInheritHandle,
	DWORD dwOptions
);

WINAPI BOOL FlushFileBuffers(
	HANDLE hFile
);

WINAPI LPSTR GetCommandLineA(void);
WINAPI LPWSTR GetCommandLineW(void);

WINAPI LPVOID GetEnvironmentStringsW(void);
WINAPI LPVOID GetEnvironmentStrings(void);

WINAPI BOOL FreeEnvironmentStringsA(
  LPCH lpszEnvironmentBlock
);

WINAPI UINT GetOEMCP(void);
WINAPI UINT GetACP(void);

WINAPI BOOL GetCPInfo(
  UINT CodePage,
  LPCPINFO lpCPInfo
);

WINAPI int MultiByteToWideChar(
	UINT CodePage,
	DWORD dwFlags,
	LPCSTR lpMultiByteStr,
	int cchMultiByte,
	LPWSTR lpWideCharStr,
	int cchWideChar
);

WINAPI BOOL GetStringTypeW(
	DWORD dwInfoType,
	LPCWSTR lpSrcStr,
	int cchSrc,
	LPWORD lpCharType
);

WINAPI int LCMapStringA(
	LCID Locale,
	DWORD dwMapFlags,
	LPCSTR lpSrcStr,
	int cchSrc,
	LPSTR lpDestStr,
	int cchDest
);

WINAPI int LCMapStringW(
	LCID Locale,
	DWORD dwMapFlags,
	LPCWSTR lpSrcStr,
	int cchSrc,
	LPWSTR lpDestStr,
	int cchDest
);

WINAPI GetLocaleInfoA(
	LCID Locale,
	LCTYPE LCType,
	LPSTR lpLCData,
	int cchData
);

WINAPI LPSTR lstrcpyA(
    LPSTR lpString1,
    LPSTR lpString2
);

WINAPI int MulDiv(
  int nNumber,
  int nNumerator,
  int nDenominator
);

WINAPI VOID Sleep(
  DWORD dwMilliseconds
);

WINAPI BOOL IsProcessorFeaturePresent(
  DWORD ProcessorFeature
);

WINAPI UINT SetErrorMode(
  UINT uMode
);

WINAPI DWORD GetModuleFileNameA(
  HMODULE hModule,
  LPSTR lpFilename,
  DWORD nSize
);

WINAPI DWORD GetModuleFileNameW(
  HMODULE hModule,
  LPWSTR lpFilename,
  DWORD nSize
);

WINAPI HMODULE GetModuleHandleA(
  LPCSTR lpModuleName
);

WINAPI HMODULE LoadLibraryA(
  LPCSTR lpModuleName
);

WINAPI FARPROC GetProcAddress(
  HMODULE hModule,
  LPCSTR lpProcName
);

WINAPI BOOL FreeLibrary(
  HMODULE hModule
);

WINAPI void GetSystemTimeAsFileTime(
  LPFILETIME lpSystemTimeAsFileTime
);

WINAPI DWORD GetTickCount(void);

WINAPI BOOL QueryPerformanceCounter(
    LARGE_INTEGER *lpPerformanceCount
);

WINAPI BOOL QueryPerformanceFrequency(
    LARGE_INTEGER *lpFrequency
);

WINAPI DWORD GetTimeZoneInformation(
  LPTIME_ZONE_INFORMATION lpTimeZoneInformation
);

WINAPI BOOL FileTimeToLocalFileTime(
  const FILETIME* lpFileTime,
  LPFILETIME lpLocalFileTime
);

WINAPI BOOL FileTimeToSystemTime(
  const FILETIME* lpFileTime,
  LPSYSTEMTIME lpSystemTime
);

WINAPI HANDLE CreateWaitableTimerA(
  LPSECURITY_ATTRIBUTES lpTimerAttributes,
  BOOL bManualReset,
  LPCSTR lpTimerName
);

WINAPI BOOL SetWaitableTimer(
  HANDLE hTimer,
  const LARGE_INTEGER* pDueTime,
  LONG lPeriod,
  PTIMERAPCROUTINE pfnCompletionRoutine,
  LPVOID lpArgToCompletionRoutine,
  BOOL fResume
);

WINAPI DWORD GetCurrentProcessId();
WINAPI DWORD GetCurrentThreadId();
WINAPI HANDLE GetCurrentThread(void);
WINAPI HANDLE GetCurrentProcess(void);

WINAPI BOOL SetProcessWorkingSetSize(
  HANDLE hProcess,
  SIZE_T dwMinimumWorkingSetSize,
  SIZE_T dwMaximumWorkingSetSize
);

WINAPI BOOL GetProcessAffinityMask(
  HANDLE hProcess,
  PDWORD_PTR lpProcessAffinityMask,
  PDWORD_PTR lpSystemAffinityMask
);

WINAPI BOOL SetProcessAffinityMask(
  HANDLE hProcess,
  DWORD_PTR dwProcessAffinityMask
);

WINAPI LPTOP_LEVEL_EXCEPTION_FILTER SetUnhandledExceptionFilter(
  LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter
);

WINAPI LONG UnhandledExceptionFilter(
  LPEXCEPTION_POINTERS ExceptionInfo
);

WINAPI DWORD TlsAlloc(void);

typedef DWORD (WINAPI *LPTHREAD_START_ROUTINE)(
  LPVOID lpParameter
);

WINAPI HANDLE CreateThread(
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  SIZE_T dwStackSize,
  LPTHREAD_START_ROUTINE lpStartAddress,
  LPVOID lpParameter,
  DWORD dwCreationFlags,
  LPDWORD lpThreadId
);

WINAPI DWORD ResumeThread(HANDLE hThread);

WINAPI BOOL SetThreadPriority(
  HANDLE hThread,
  int nPriority
);

WINAPI int WideCharToMultiByte(
  UINT CodePage,
  DWORD dwFlags,
  LPCWSTR lpWideCharStr,
  int cchWideChar,
  LPSTR lpMultiByteStr,
  int cbMultiByte,
  LPCSTR lpDefaultChar,
  LPBOOL lpUsedDefaultChar
);

NuContext_SingletonDecl(Kernel32_GetContext, Kernel32);

#define FILE_TYPE_UNKNOWN       0
#define FILE_TYPE_DISK          1
#define FILE_TYPE_CHAR          2
#define FILE_TYPE_PIPE          3
#define FILE_TYPE_REMOTE        32768

#define DRIVE_CANNOTDETERMINE      0
#define DRIVE_DOESNOTEXIST         1
#define DRIVE_REMOVABLE            2
#define DRIVE_FIXED                3
#define DRIVE_REMOTE               4
#define DRIVE_CDROM                5
#define DRIVE_RAMDISK              6

#define GENERIC_READ            0x80000000L
#define GENERIC_WRITE           0x40000000L
#define GENERIC_EXECUTE         0x20000000L
#define GENERIC_ALL             0x10000000L

#define FILE_BEGIN              0
#define FILE_CURRENT            1
#define FILE_END                2

#define CREATE_NEW              1
#define CREATE_ALWAYS           2
#define OPEN_EXISTING           3
#define OPEN_ALWAYS             4
#define TRUNCATE_EXISTING       5

#define INVALID_HANDLE_VALUE    -1

#define WAIT_ABANDONED          0x00000080L
#define WAIT_OBJECT_0           0x00000000L
#define WAIT_TIMEOUT            0x00000102L

#define FILE_ATTRIBUTE_READONLY			0x00000001
#define FILE_ATTRIBUTE_HIDDEN			0x00000002
#define FILE_ATTRIBUTE_SYSTEM			0x00000004
#define FILE_ATTRIBUTE_DIRECTORY		0x00000010
#define FILE_ATTRIBUTE_ARCHIVE			0x00000020
#define FILE_ATTRIBUTE_DEVICE			0x00000040
#define FILE_ATTRIBUTE_UNKNOWNXXX0		0x00000060
#define FILE_ATTRIBUTE_NORMAL			0x00000080
#define FILE_ATTRIBUTE_TEMPORARY		0x00000100
#define FILE_ATTRIBUTE_SPARSE_FILE		0x00000200
#define FILE_ATTRIBUTE_REPARSE_POINT		0x00000400
#define FILE_ATTRIBUTE_COMPRESSED		0x00000800
#define FILE_ATTRIBUTE_OFFLINE			0x00001000
#define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED	0x00002000
#define FILE_ATTRIBUTE_ENCRYPTED		0x00004000

#define NO_ERROR                                           0
#define ERROR_SUCCESS                                      0
#define ERROR_INVALID_FUNCTION                             1
#define ERROR_FILE_NOT_FOUND                               2
#define ERROR_PATH_NOT_FOUND                               3
#define ERROR_TOO_MANY_OPEN_FILES                          4
#define ERROR_ACCESS_DENIED                                5
#define ERROR_INVALID_HANDLE                               6
#define ERROR_ARENA_TRASHED                                7
#define ERROR_NOT_ENOUGH_MEMORY                            8
#define ERROR_INVALID_BLOCK                                9

#define LCMAP_LOWERCASE           0x00000100  // lower case letters
#define LCMAP_UPPERCASE           0x00000200  // upper case letters
#define LCMAP_SORTKEY             0x00000400  // WC sort key (normalize)
#define LCMAP_BYTEREV             0x00000800  // byte reversal

#define LCMAP_HIRAGANA            0x00100000  // map katakana to hiragana
#define LCMAP_KATAKANA            0x00200000  // map hiragana to katakana
#define LCMAP_HALFWIDTH           0x00400000  // map double byte to single byte
#define LCMAP_FULLWIDTH           0x00800000  // map single byte to double byte

#define LCMAP_LINGUISTIC_CASING   0x01000000  // use linguistic rules for casing

#define LCMAP_SIMPLIFIED_CHINESE  0x02000000  // map traditional chinese to simplified chinese
#define LCMAP_TRADITIONAL_CHINESE 0x04000000  // map simplified chinese to traditional chinese

#endif
