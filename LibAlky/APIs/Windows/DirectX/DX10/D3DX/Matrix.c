/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3DX/D3DX.h>
#include <APIs/Windows/DirectX/DX10/D3DX/D3DX_Classes.h>

#define NUMODULE_NAME "D3DX10"

WINAPI D3DXMATRIX * D3DXMatrixLookAtLH(
  D3DXMATRIX *pOut,
  CONST D3DXVECTOR3 *pEye,
  CONST D3DXVECTOR3 *pAt,
  CONST D3DXVECTOR3 *pUp
) {
	/*
zaxis = normal(At - Eye)
xaxis = normal(cross(Up, zaxis))
yaxis = cross(zaxis, xaxis)
    
 xaxis.x           yaxis.x           zaxis.x          0
 xaxis.y           yaxis.y           zaxis.y          0
 xaxis.z           yaxis.z           zaxis.z          0
-dot(xaxis, eye)  -dot(yaxis, eye)  -dot(zaxis, eye)  l
	*/
	
	D3DXVECTOR3 temp, xaxis, yaxis, zaxis;
	
	D3DXVec3Subtract(&temp, pAt, pEye);
	D3DXVec3Normalize(&zaxis, &temp);
	
	D3DXVec3Cross(&temp, pUp, &zaxis);
	D3DXVec3Normalize(&xaxis, &temp);
	
	D3DXVec3Cross(&yaxis, &zaxis, &xaxis);
	
	pOut->gl[ 0] = xaxis.x;
	pOut->gl[ 1] = yaxis.x;
	pOut->gl[ 2] = zaxis.x;
	pOut->gl[ 3] = 0.0f;

	pOut->gl[ 4] = xaxis.y;
	pOut->gl[ 5] = yaxis.y;
	pOut->gl[ 6] = zaxis.y;
	pOut->gl[ 7] = 0.0f;

	pOut->gl[ 8] = xaxis.z;
	pOut->gl[ 9] = yaxis.z;
	pOut->gl[10] = zaxis.z;
	pOut->gl[11] = 0.0f;

	pOut->gl[12] = -D3DXVec3Dot(&xaxis, pEye);
	pOut->gl[13] = -D3DXVec3Dot(&yaxis, pEye);
	pOut->gl[14] = -D3DXVec3Dot(&zaxis, pEye);
	pOut->gl[15] = 1.0f;

	return pOut;
}

WINAPI D3DXMATRIX * D3DXMatrixMultiply(
  D3DXMATRIX * pOut,
  CONST D3DXMATRIX *pM1,
  CONST D3DXMATRIX *pM2
) {
	pOut->dx._11 = pM1->dx._11*pM2->dx._11 + pM1->dx._12*pM2->dx._21 + pM1->dx._13*pM2->dx._31 + pM1->dx._14*pM2->dx._41;
	pOut->dx._12 = pM1->dx._11*pM2->dx._12 + pM1->dx._12*pM2->dx._22 + pM1->dx._13*pM2->dx._32 + pM1->dx._14*pM2->dx._42;
	pOut->dx._13 = pM1->dx._11*pM2->dx._13 + pM1->dx._12*pM2->dx._23 + pM1->dx._13*pM2->dx._33 + pM1->dx._14*pM2->dx._43;
	pOut->dx._14 = pM1->dx._11*pM2->dx._14 + pM1->dx._12*pM2->dx._24 + pM1->dx._13*pM2->dx._34 + pM1->dx._14*pM2->dx._44;
	
	pOut->dx._21 = pM1->dx._21*pM2->dx._11 + pM1->dx._22*pM2->dx._21 + pM1->dx._23*pM2->dx._31 + pM1->dx._24*pM2->dx._41;
	pOut->dx._22 = pM1->dx._21*pM2->dx._12 + pM1->dx._22*pM2->dx._22 + pM1->dx._23*pM2->dx._32 + pM1->dx._24*pM2->dx._42;
	pOut->dx._23 = pM1->dx._21*pM2->dx._13 + pM1->dx._22*pM2->dx._23 + pM1->dx._23*pM2->dx._33 + pM1->dx._24*pM2->dx._43;
	pOut->dx._24 = pM1->dx._21*pM2->dx._14 + pM1->dx._22*pM2->dx._24 + pM1->dx._23*pM2->dx._34 + pM1->dx._24*pM2->dx._44;
	
	pOut->dx._31 = pM1->dx._31*pM2->dx._11 + pM1->dx._32*pM2->dx._21 + pM1->dx._33*pM2->dx._31 + pM1->dx._34*pM2->dx._41;
	pOut->dx._32 = pM1->dx._31*pM2->dx._12 + pM1->dx._32*pM2->dx._22 + pM1->dx._33*pM2->dx._32 + pM1->dx._34*pM2->dx._42;
	pOut->dx._33 = pM1->dx._31*pM2->dx._13 + pM1->dx._32*pM2->dx._23 + pM1->dx._33*pM2->dx._33 + pM1->dx._34*pM2->dx._43;
	pOut->dx._34 = pM1->dx._31*pM2->dx._14 + pM1->dx._32*pM2->dx._24 + pM1->dx._33*pM2->dx._34 + pM1->dx._34*pM2->dx._44;
	
	pOut->dx._41 = pM1->dx._41*pM2->dx._11 + pM1->dx._42*pM2->dx._21 + pM1->dx._43*pM2->dx._31 + pM1->dx._44*pM2->dx._41;
	pOut->dx._42 = pM1->dx._41*pM2->dx._12 + pM1->dx._42*pM2->dx._22 + pM1->dx._43*pM2->dx._32 + pM1->dx._44*pM2->dx._42;
	pOut->dx._43 = pM1->dx._41*pM2->dx._13 + pM1->dx._42*pM2->dx._23 + pM1->dx._43*pM2->dx._33 + pM1->dx._44*pM2->dx._43;
	pOut->dx._44 = pM1->dx._41*pM2->dx._14 + pM1->dx._42*pM2->dx._24 + pM1->dx._43*pM2->dx._34 + pM1->dx._44*pM2->dx._44;
	
	return pOut;
}

WINAPI D3DXMATRIX * D3DXMatrixPerspectiveFovLH(
  D3DXMATRIX * pOut,
  FLOAT fovy,
  FLOAT Aspect,
  FLOAT zn,
  FLOAT zf
) {
	/*
xScale     0          0               0
0        yScale       0               0
0          0       zf/(zf-zn)         1
0          0       -zn*zf/(zf-zn)     0
where:
yScale = cot(fovY/2)

xScale = aspect ratio / yScale
	*/
	
	FLOAT yScale = 1.0f / tan(fovy / 2.0f);
	
	pOut->gl[ 0] = yScale / Aspect;
	pOut->gl[ 1] = 0.0f;
	pOut->gl[ 2] = 0.0f;
	pOut->gl[ 3] = 0.0f;
	
	pOut->gl[ 4] = 0.0f;
	pOut->gl[ 5] = yScale;
	pOut->gl[ 6] = 0.0f;
	pOut->gl[ 7] = 0.0f;

	pOut->gl[ 8] = 0.0f;
	pOut->gl[ 9] = 0.0f;
	pOut->gl[10] = zf / (zf - zn);
	pOut->gl[11] = 1.0f;

	pOut->gl[12] = 0.0f;
	pOut->gl[13] = 0.0f;
	pOut->gl[14] = -zn * zf / (zf - zn);
	pOut->gl[15] = 0.0f;
	
	return pOut;
}

WINAPI D3DXMATRIX * D3DXMatrixRotationY(
  D3DXMATRIX * pOut,
  FLOAT Angle
) {
	FLOAT c = cos(Angle), s = sin(Angle);
	
	pOut->gl[ 0] = c;
	pOut->gl[ 1] = 0.0f;
	pOut->gl[ 2] = s;
	pOut->gl[ 3] = 0.0f;
	
	pOut->gl[ 4] = 0.0f;
	pOut->gl[ 5] = 1.0f;
	pOut->gl[ 6] = 0.0f;
	pOut->gl[ 7] = 0.0f;
	
	pOut->gl[ 8] = -s;
	pOut->gl[ 9] = 0.0f;
	pOut->gl[10] = c;
	pOut->gl[11] = 0.0f;
	
	pOut->gl[12] = 0.0f;
	pOut->gl[13] = 0.0f;
	pOut->gl[14] = 0.0f;
	pOut->gl[15] = 1.0f;
	
	return pOut;
}

WINAPI D3DXMATRIX * D3DXMatrixRotationZ(
  D3DXMATRIX * pOut,
  FLOAT Angle
) {
	FLOAT c = cos(Angle), s = sin(Angle);
	
	pOut->gl[ 0] = c;
	pOut->gl[ 1] = -s;
	pOut->gl[ 2] = 0.0f;
	pOut->gl[ 3] = 0.0f;
	
	pOut->gl[ 4] = s;
	pOut->gl[ 5] = c;
	pOut->gl[ 6] = 0.0f;
	pOut->gl[ 7] = 0.0f;
	
	pOut->gl[ 8] = 0.0f;
	pOut->gl[ 9] = 0.0f;
	pOut->gl[10] = 1.0f;
	pOut->gl[11] = 0.0f;
	
	pOut->gl[12] = 0.0f;
	pOut->gl[13] = 0.0f;
	pOut->gl[14] = 0.0f;
	pOut->gl[15] = 1.0f;
	
	return pOut;
}

WINAPI D3DXMATRIX * D3DXMatrixScaling(
  D3DXMATRIX * pOut,
  FLOAT sx,
  FLOAT sy,
  FLOAT sz
) {
	pOut->gl[ 0] = sx;
	pOut->gl[ 1] = 0.0f;
	pOut->gl[ 2] = 0.0f;
	pOut->gl[ 3] = 0.0f;
	
	pOut->gl[ 4] = 0.0f;
	pOut->gl[ 5] = sy;
	pOut->gl[ 6] = 0.0f;
	pOut->gl[ 7] = 0.0f;
	
	pOut->gl[ 8] = 0.0f;
	pOut->gl[ 9] = 0.0f;
	pOut->gl[10] = sz;
	pOut->gl[11] = 0.0f;
	
	pOut->gl[12] = 0.0f;
	pOut->gl[13] = 0.0f;
	pOut->gl[14] = 0.0f;
	pOut->gl[15] = 1.0f;
	
	return pOut;
}

WINAPI D3DXMATRIX *D3DXMatrixTranslation(
	D3DXMATRIX *pOut,
	FLOAT x,
	FLOAT y,
	FLOAT z
) {
	pOut->gl[ 0] = 1.0f;
	pOut->gl[ 1] = 0.0f;
	pOut->gl[ 2] = 0.0f;
	pOut->gl[ 3] = x;
	
	pOut->gl[ 4] = 0.0f;
	pOut->gl[ 5] = 1.0f;
	pOut->gl[ 6] = 0.0f;
	pOut->gl[ 7] = y;

	pOut->gl[ 8] = 0.0f;
	pOut->gl[ 9] = 0.0f;
	pOut->gl[10] = 1.0f;
	pOut->gl[11] = z;

	pOut->gl[12] = 0.0f;
	pOut->gl[13] = 0.0f;
	pOut->gl[14] = 0.0f;
	pOut->gl[15] = 1.0f;
	
	return pOut;
}
