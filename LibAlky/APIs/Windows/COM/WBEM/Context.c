/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/COM/WBEM/WBEM.h>

#define NUMODULE_NAME "WBEM"

HRESULT IWbemContext_BeginEnumeration(
  LONG lFlags
) {
	NuWarn("IWbemContext::BeginEnumeration not yet implemented");
	
	return None;
}

HRESULT IWbemContext_Clone(
  void **ppNewCopy
) {
	NuWarn("IWbemContext::Clone not yet implemented");
	
	return None;
}

HRESULT IWbemContext_DeleteAll() {
	NuWarn("IWbemContext::DeleteAll not yet implemented");
	
	return None;
}

HRESULT IWbemContext_DeleteValue(
  LPCWSTR strName,
  LONG lFlags
) {
	NuWarn("IWbemContext::DeleteValue not yet implemented");
	
	return None;
}

HRESULT IWbemContext_EndEnumeration() {
	NuWarn("IWbemContext::EndEnumeration not yet implemented");
	
	return None;
}

HRESULT IWbemContext_GetNames(
  LONG lFlags,
  void **pNames // SAFEARRAY (BSTR)** pNames // XXX: FIX THIS
) {
	NuWarn("IWbemContext::GetNames not yet implemented");
	
	return None;
}

HRESULT IWbemContext_GetValue(
  LPCWSTR strName,
  LONG lFlags,
  VARIANT* pValue
) {
	NuWarn("IWbemContext::GetValue not yet implemented");
	
	return None;
}

HRESULT IWbemContext_Next(
  LONG lFlags,
  BSTR* pstrName,
  VARIANT* pValue
) {
	NuWarn("IWbemContext::Next not yet implemented");
	
	return None;
}

HRESULT IWbemContext_SetValue(
  LPCWSTR strName,
  LONG lFlags,
  VARIANT* pValue
) {
	NuWarn("IWbemContext::BeginEnumeration not yet implemented");
	
	return None;
}