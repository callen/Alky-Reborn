/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3D/D3D.h>
#include <APIs/Windows/DirectX/DX10/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D10"

WINAPI void ID3D10EffectShaderResourceVariable_SetResource(
	/* ID3D10EffectShaderResourceVariable */ void *this, 
	/* ID3D10ShaderResourceView */ void *pResource
) {
	CSTRUCT(ID3D10ShaderResourceView) *resource;
	CSTRUCT(ID3D10Texture2D) *texture;
	
	NuWarn("ID3D10EffectShaderResourceVariable::SetResource not yet implemented");
	
	
	if(resource != None) {
		resource = GET_CLASS_STRUCT(ID3D10ShaderResourceView, pResource);
		
		if(resource->texture2D != None) {
			texture = GET_CLASS_STRUCT(ID3D10Texture2D, resource->texture2D);
			
			if(texture->tex != 0xDEADBEEF)
				glBindTexture(GL_TEXTURE_2D, texture->tex);
		}
	}
}
