/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3D/D3D.h>
#include <APIs/Windows/DirectX/DX10/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D10"

WINAPI void ID3D10EffectMatrixVariable_SetMatrix(
	/* ID3D10EffectMatrixVariable */ void *this, 
	float *pData
) {
	CSTRUCT(ID3D10EffectMatrixVariable) *Matrix;
	
	static float view[16] = {1.0f, 0.0f, 0.0f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.0f, 0.0f, 1.0f};
	static float world[16] = {1.0f, 0.0f, 0.0f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.0f, 0.0f, 1.0f};
	static float projection[16] = {1.0f, 0.0f, 0.0f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.0f, 0.0f, 1.0f};
	
	NuWarn("ID3D10EffectMatrixVariable::SetMatrix not yet implemented");
	
	Matrix = GET_CLASS_STRUCT(ID3D10EffectMatrixVariable, this);
	
	if(strcmp(Matrix->Name, "View") == 0)
		memcpy(view, pData, sizeof(float) * 16);
	else if(strcmp(Matrix->Name, "World") == 0)
		memcpy(world, pData, sizeof(float) * 16);
	else if(strcmp(Matrix->Name, "Projection") == 0)
		memcpy(projection, pData, sizeof(float) * 16);
	else
		return;
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMultMatrixf(view);
	glMultMatrixf(world);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMultMatrixf(projection);
}

WINAPI void ID3D10EffectMatrixVariable_SetMatrixArray(
	/* ID3D10EffectMatrixVariable */ void *this, 
	float *pData, 
	UINT Offset, 
	UINT Count
) {
	NuWarn("ID3D10EffectMatrixVariable::SetMatrixArray not yet implemented");
	
	return S_OK;
}
