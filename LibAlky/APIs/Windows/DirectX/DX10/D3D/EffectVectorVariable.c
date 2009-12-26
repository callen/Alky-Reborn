/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3D/D3D.h>
#include <APIs/Windows/DirectX/DX10/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D10"

WINAPI void ID3D10EffectVectorVariable_SetFloatVector(
	/* ID3D10EffectVectorVariable */ void *this, 
	float *pData
) {
	NuWarn("ID3D10EffectVectorVariable::SetFloatVector not yet implemented");
	
	glColor3f(pData[0], pData[1], pData[2]);
}

WINAPI void ID3D10EffectVectorVariable_SetFloatVectorArray(
	/* ID3D10EffectVectorVariable */ void *this, 
	float *pData, 
	UINT Offset, 
	UINT Count
) {
	NuWarn("ID3D10EffectVectorVariable::SetFloatVectorArray not yet implemented");
}
