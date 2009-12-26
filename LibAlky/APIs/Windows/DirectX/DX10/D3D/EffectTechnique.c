/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3D/D3D.h>
#include <APIs/Windows/DirectX/DX10/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D10"

WINAPI /* ID3D10EffectTechnique */ void *D3D10_CreateEffectTechnique(
	/* ID3D10Effect */ void *effect
) {
	void *ret;
	
	SETUP_VTABLE(D3D10);
	INIT_CLASS(ID3D10EffectTechnique, ret);
	
	return ret;
}

WINAPI void ID3D10EffectTechnique_GetDesc(
	/* ID3D10EffectTechnique */ void *this, 
	D3D10_TECHNIQUE_DESC *pDesc
) {
	NuWarn("ID3D10EffectTechnique::GetDesc not yet implemented");
	
	pDesc->Passes = 1;
}

WINAPI /* ID3D10EffectPass */ void *ID3D10EffectTechnique_GetPassByIndex(
	/* ID3D10EffectTechnique */ void *this,
	UINT Index
) {
	static void *pass = None;
	
	NuWarn("ID3D10EffectTechnique::GetPassByIndex not yet implemented");
	
	if(pass == None)
		pass = D3D10_CreateEffectPass(this);
	
	return pass;
}

