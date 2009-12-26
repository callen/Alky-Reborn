/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_IPHLPAPI_IPHLPAPI_H__
#define __APIS_WINDOWS_IPHLPAPI_IPHLPAPI_H__

#include <APIs/Windows/Windows.h>

#define MAX_ADAPTER_DESCRIPTION_LENGTH  128
#define MAX_ADAPTER_NAME_LENGTH         256
#define MAX_ADAPTER_ADDRESS_LENGTH      8

typedef struct {
    char String[4 * 4];
} IP_ADDR_STRING, *PIP_ADDR_STRING, IP_MASK_STRING, *PIP_MASK_STRING;

typedef struct _IP_ADAPTER_INFO {
  struct _IP_ADAPTER_INFO* Next;
  DWORD ComboIndex;
  char AdapterName[MAX_ADAPTER_NAME_LENGTH + 4];
  char Description[MAX_ADAPTER_DESCRIPTION_LENGTH + 4];
  UINT AddressLength;
  BYTE Address[MAX_ADAPTER_ADDRESS_LENGTH];
  DWORD Index;
  UINT Type;
  UINT DhcpEnabled;
  PIP_ADDR_STRING CurrentIpAddress;
  IP_ADDR_STRING IpAddressList;
  IP_ADDR_STRING GatewayList;
  IP_ADDR_STRING DhcpServer;
  BOOL HaveWins;
  IP_ADDR_STRING PrimaryWinsServer;
  IP_ADDR_STRING SecondaryWinsServer;
  time_t LeaseObtained;
  time_t LeaseExpires;
} IP_ADAPTER_INFO,
 *PIP_ADAPTER_INFO;

WINAPI DWORD GetAdaptersInfo(
  PIP_ADAPTER_INFO pAdapterInfo,
  PULONG pOutBufLen
);

#endif
