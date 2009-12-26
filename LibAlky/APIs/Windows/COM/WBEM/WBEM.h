/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_COM_WBEM_WBEM_H__
#define __APIS_WINDOWS_COM_WBEM_WBEM_H__

#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

HRESULT IWbemLocator_ConnectServer(
  const BSTR strNetworkResource,
  const BSTR strUser,
  const BSTR strPassword,
  const BSTR strLocale,
  LONG lSecurityFlags,
  const BSTR strAuthority,
  void *pCtx, // IWbemContext*
  void **ppNamespace // IWbemServices**
);

CLASS(
	IWbemLocator,
	STRUCT(),
	VTABLE(
		CMEMBER(IWbemLocator_ConnectServer)
	)
);

HRESULT IWbemContext_BeginEnumeration(
  LONG lFlags
);

HRESULT IWbemContext_Clone(
  void **ppNewCopy
);

HRESULT IWbemContext_DeleteAll();

HRESULT IWbemContext_DeleteValue(
  LPCWSTR strName,
  LONG lFlags
);

HRESULT IWbemContext_EndEnumeration();

HRESULT IWbemContext_GetNames(
  LONG lFlags,
  void **pNames // SAFEARRAY (BSTR)** pNames // XXX: FIX THIS
);

HRESULT IWbemContext_GetValue(
  LPCWSTR strName,
  LONG lFlags,
  VARIANT* pValue
);

HRESULT IWbemContext_Next(
  LONG lFlags,
  BSTR* pstrName,
  VARIANT* pValue
);

HRESULT IWbemContext_SetValue(
  LPCWSTR strName,
  LONG lFlags,
  VARIANT* pValue
);

CLASS(
	IWbemContext,
	STRUCT(),
	VTABLE(
		CMEMBER(IWbemContext_BeginEnumeration),
		CMEMBER(IWbemContext_Clone),
		CMEMBER(IWbemContext_DeleteAll),
		CMEMBER(IWbemContext_DeleteValue),
		CMEMBER(IWbemContext_EndEnumeration),
		CMEMBER(IWbemContext_GetNames),
		CMEMBER(IWbemContext_GetValue),
		CMEMBER(IWbemContext_Next),
		CMEMBER(IWbemContext_SetValue)
	)
);

CLASS(
	IWbemServices,
	STRUCT(),
	VTABLE(
		CSTUB(IWbemServices_OpenNamespace),
		CSTUB(IWbemServices_CancelAsyncCall),
		CSTUB(IWbemServices_QueryObjectSink),
		CSTUB(IWbemServices_GetObject),
		CSTUB(IWbemServices_GetObjectAsync),
		CSTUB(IWbemServices_PutClass),
		CSTUB(IWbemServices_PutClassAsync),
		CSTUB(IWbemServices_DeleteClass),
		CSTUB(IWbemServices_DeleteClassAsync),
		CSTUB(IWbemServices_CreateClassEnum),
		CSTUB(IWbemServices_CreateClassEnumAsync),
		CSTUB(IWbemServices_PutInstance),
		CSTUB(IWbemServices_PutInstanceAsync),
		CSTUB(IWbemServices_DeleteInstance),
		CSTUB(IWbemServices_DeleteInstanceAsync),
		CSTUB(IWbemServices_CreateInstanceEnum),
		CSTUB(IWbemServices_CreateInstanceEnumAsync),
		CSTUB(IWbemServices_ExecQuery),
		CSTUB(IWbemServices_ExecQueryAsync),
		CSTUB(IWbemServices_ExecNotificationQuery),
		CSTUB(IWbemServices_ExecNotificationQueryAsync),
		CSTUB(IWbemServices_ExecMethod),
		CSTUB(IWbemServices_ExecMethodAsync)
	)
);

#endif
