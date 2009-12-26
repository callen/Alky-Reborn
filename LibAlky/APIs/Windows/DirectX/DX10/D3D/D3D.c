/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#define DEFINE_CLASSES
#include <APIs/Windows/DirectX/DX10/D3D/D3D.h>
#include <APIs/Windows/DirectX/DX10/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D10"

VTABLE_SETUP_FUNC(
	D3D10,
	VTABLE_SETUP(ID3D10Buffer)
	VTABLE_SETUP(ID3D10Device)
	VTABLE_SETUP(ID3D10Effect)
	VTABLE_SETUP(ID3D10EffectPass)
	VTABLE_SETUP(ID3D10EffectTechnique)
	VTABLE_SETUP(ID3D10EffectVariable)
	VTABLE_SETUP(ID3D10EffectMatrixVariable)
	VTABLE_SETUP(ID3D10EffectScalarVariable)
	VTABLE_SETUP(ID3D10EffectShaderResourceVariable)
	VTABLE_SETUP(ID3D10EffectVectorVariable)
	VTABLE_SETUP(ID3D10ShaderResourceView)
	VTABLE_SETUP(ID3D10StateBlock)
	VTABLE_SETUP(ID3D10Texture1D)
	VTABLE_SETUP(ID3D10Texture2D)
);
