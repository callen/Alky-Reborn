/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3D/D3D.h>
#include <APIs/Windows/DirectX/DX10/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D10"

WINAPI /* ID3D10Effect */ void *D3D10_CreateEffect(/* ID3D10Device */ void *device) {
	void *ret;
	
	SETUP_VTABLE(D3D10);
	INIT_CLASS(ID3D10Effect, ret);
	
	return ret;
}

WINAPI ULONG ID3D10Effect_Release(/* ID3D10Effect */ void *this) {
	return 0;
}

WINAPI /* ID3D10EffectVariable */ void *ID3D10Effect_GetVariableByName(
	/* ID3D10Effect */ void *this, 
	LPCSTR Name
) {
	NuWarn("ID3D10Effect::GetVariableByName not yet implemented");
	
	NuLog("Variable: %s", Name);
	
	return D3D10_CreateEffectVariable(this, Name);
}

WINAPI /* ID3D10EffectTechnique */ void *ID3D10Effect_GetTechniqueByName(
	/* ID3D10Effect */ void *this,
	LPCSTR Name
) {
	static void *technique = None;
	
	NuWarn("ID3D10Effect::GetTechniqueByName not yet implemented");
	
	if(technique == None)
		technique = D3D10_CreateEffectTechnique(this);
	
	return technique;
}
