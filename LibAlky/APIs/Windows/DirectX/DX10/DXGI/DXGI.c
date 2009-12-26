/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#define DEFINE_CLASSES
#include <APIs/Windows/DirectX/DX10/DXGI/DXGI.h>
#include <APIs/Windows/DirectX/DX10/DXGI/DXGI_Classes.h>

#define NUMODULE_NAME "DXGI10"

VTABLE_SETUP_FUNC(
	DXGI10,
	VTABLE_SETUP(IDXGIAdapter)
	VTABLE_SETUP(IDXGIFactory)
	VTABLE_SETUP(IDXGIOutput)
	VTABLE_SETUP(IDXGISwapChain)
);

