/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3D/D3D.h>
#include <APIs/Windows/DirectX/DX10/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D10"

WINAPI /* ID3D10EffectVariable */ void *D3D10_CreateEffectVariable(
	/* ID3D10Effect */ void *Effect,
	LPCSTR Name
) {
	CSTRUCT(ID3D10EffectVariable) *Variable;
	
	void *ret;

	SETUP_VTABLE(D3D10);
	INIT_CLASS(ID3D10EffectVariable, ret);
	Variable = GET_CLASS_STRUCT(ID3D10EffectVariable, ret);
	
	Variable->Effect = Effect;
	Variable->Name = strdup(Name);
	
	return ret;
}

WINAPI /* ID3D10EffectScalarVariable */ void *ID3D10EffectVariable_AsScalar(
	/* ID3D10EffectVariable */ void *this
) {
	CSTRUCT(ID3D10EffectVariable) *Variable;
	CSTRUCT(ID3D10EffectScalarVariable) *Scalar;

	void *ret;
	
	NuWarn("ID3D10EffectVariable::AsScalar not yet implemented");
	
	Variable = GET_CLASS_STRUCT(ID3D10EffectVariable, this);
	
	INIT_CLASS(ID3D10EffectScalarVariable, ret);
	Scalar = GET_CLASS_STRUCT(ID3D10EffectScalarVariable, ret);
	
	Scalar->Effect = Variable->Effect;
	Scalar->Name = strdup(Variable->Name);
	
	Scalar->Value = 0.0f;
	
	return ret;
}

WINAPI /* ID3D10EffectVectorVariable */ void *ID3D10EffectVariable_AsVector(
	/* ID3D10EffectVariable */ void *this
) {
	CSTRUCT(ID3D10EffectVariable) *Variable;
	CSTRUCT(ID3D10EffectVectorVariable) *Vector;

	void *ret;
	
	NuWarn("ID3D10EffectVariable::AsVector not yet implemented");
	
	Variable = GET_CLASS_STRUCT(ID3D10EffectVariable, this);
	
	INIT_CLASS(ID3D10EffectVectorVariable, ret);
	Vector = GET_CLASS_STRUCT(ID3D10EffectVectorVariable, ret);
	
	Vector->Effect = Variable->Effect;
	Vector->Name = strdup(Variable->Name);
	
	Vector->Vector.x = 0.0f;
	Vector->Vector.y = 0.0f;
	Vector->Vector.z = 0.0f;
	Vector->Vector.w = 0.0f;
	
	return ret;
}

WINAPI /* ID3D10EffectMatrixVariable */ void *ID3D10EffectVariable_AsMatrix(
	/* ID3D10EffectVariable */ void *this
) {
	CSTRUCT(ID3D10EffectVariable) *Variable;
	CSTRUCT(ID3D10EffectMatrixVariable) *Matrix;

	void *ret;
	
	NuWarn("ID3D10EffectVariable::AsMatrix not yet implemented");
	
	Variable = GET_CLASS_STRUCT(ID3D10EffectVariable, this);
	
	INIT_CLASS(ID3D10EffectMatrixVariable, ret);
	Matrix = GET_CLASS_STRUCT(ID3D10EffectMatrixVariable, ret);
	
	Matrix->Effect = Variable->Effect;
	Matrix->Name = strdup(Variable->Name);
	
	Matrix->Matrix.gl[ 0] = 1.0f;
	Matrix->Matrix.gl[ 1] = 0.0f;
	Matrix->Matrix.gl[ 2] = 0.0f;
	Matrix->Matrix.gl[ 3] = 0.0f;
	
	Matrix->Matrix.gl[ 4] = 0.0f;
	Matrix->Matrix.gl[ 5] = 1.0f;
	Matrix->Matrix.gl[ 6] = 0.0f;
	Matrix->Matrix.gl[ 7] = 0.0f;
	
	Matrix->Matrix.gl[ 8] = 0.0f;
	Matrix->Matrix.gl[ 9] = 0.0f;
	Matrix->Matrix.gl[10] = 1.0f;
	Matrix->Matrix.gl[11] = 0.0f;
	
	Matrix->Matrix.gl[12] = 0.0f;
	Matrix->Matrix.gl[13] = 0.0f;
	Matrix->Matrix.gl[14] = 0.0f;
	Matrix->Matrix.gl[15] = 1.0f;
	
	return ret;
}

WINAPI /* ID3D10EffectShaderResourceVariable */ void *ID3D10EffectVariable_AsShaderResource(
	/* ID3D10EffectVariable */ void *this
) {
	CSTRUCT(ID3D10EffectVariable) *Variable;
	CSTRUCT(ID3D10EffectShaderResourceVariable) *Resource;

	void *ret;
	
	NuWarn("ID3D10EffectVariable::AsShaderResource not yet implemented");
	
	Variable = GET_CLASS_STRUCT(ID3D10EffectVariable, this);
	
	INIT_CLASS(ID3D10EffectShaderResourceVariable, ret);
	Resource = GET_CLASS_STRUCT(ID3D10EffectShaderResourceVariable, ret);
	
	Resource->Effect = Variable->Effect;
	Resource->Name = strdup(Variable->Name);
	
	return ret;
}
