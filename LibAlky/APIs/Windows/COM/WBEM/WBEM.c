/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/COM/WBEM/WBEM.h>

#define NUMODULE_NAME "WBEM"

HRESULT IWbemLocator_ConnectServer(
  const BSTR strNetworkResource,
  const BSTR strUser,
  const BSTR strPassword,
  const BSTR strLocale,
  LONG lSecurityFlags,
  const BSTR strAuthority,
  void *pCtx, // IWbemContext*
  void **ppNamespace // IWbemServices**
) {
	NuLog("IWbemLocator::ConnectServer");
	
	if(ppNamespace)
		INIT_CLASS(IWbemServices, *ppNamespace);
	
	return 0;
}