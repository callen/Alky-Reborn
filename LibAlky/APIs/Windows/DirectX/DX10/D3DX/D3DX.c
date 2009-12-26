/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#define DEFINE_CLASSES
#include <APIs/Windows/DirectX/DX10/D3DX/D3DX.h>
#include <APIs/Windows/DirectX/DX10/D3DX/D3DX_Classes.h>

#define NUMODULE_NAME "D3DX10"

VTABLE_SETUP_FUNC(
	D3DX10,
	VTABLE_SETUP(ID3DX10Font)
	VTABLE_SETUP(ID3DX10Sprite)
);
