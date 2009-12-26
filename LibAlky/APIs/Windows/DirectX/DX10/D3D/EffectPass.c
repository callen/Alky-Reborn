/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3D/D3D.h>
#include <APIs/Windows/DirectX/DX10/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D10"

WINAPI /* ID3D10EffectPass */ void *D3D10_CreateEffectPass(
	/* ID3D10EffectTechnique */ void *technique
) {
	void *ret;
	
	SETUP_VTABLE(D3D10);
	INIT_CLASS(ID3D10EffectPass, ret);
	
	return ret;
}

WINAPI void ID3D10EffectPass_GetDesc(
	/* ID3D10EffectPass */ void *this,
	D3D10_PASS_DESC *pDesc
) {
	NuWarn("ID3D10EffectPass::GetDesc not yet implemented");
}

WINAPI void ID3D10EffectPass_Apply(
	/* ID3D10EffectPass */ void *this, 
	UINT Flags
) {
	NuWarn("ID3D10EffectPass::Apply not yet implemented");
}
