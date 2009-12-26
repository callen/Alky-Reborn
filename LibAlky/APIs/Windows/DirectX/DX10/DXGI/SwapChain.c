/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/DXGI/DXGI.h>
#include <APIs/Windows/DirectX/DX10/DXGI/DXGI_Classes.h>

#define NUMODULE_NAME "DXGI10"

WINAPI HRESULT DXGI_CreateSwapChain(
	void *pDevice, /* ID3D10Device */
	DXGI_SWAP_CHAIN_DESC *pDesc,
	void **ppSwapChain /* IDXGISwapChain */
) {
	CSTRUCT(IDXGISwapChain) *_SwapChain;
	D3D10_TEXTURE2D_DESC texDesc;
	
	RECT rect;
	HDC wdc;
	HGLRC wgc;
	
	PIXELFORMATDESCRIPTOR pfd = { 
	    sizeof(PIXELFORMATDESCRIPTOR),   // size of this pfd 
	    1,                     // version number 
	    PFD_DRAW_TO_WINDOW |   // support window 
	    PFD_SUPPORT_OPENGL |   // support OpenGL 
	    PFD_DOUBLEBUFFER,      // double buffered 
	    PFD_TYPE_RGBA,         // RGBA type 
	    24,                    // 24-bit color depth 
	    0, 0, 0, 0, 0, 0,      // color bits ignored 
	    8,                     // no alpha buffer 
	    0,                     // shift bit ignored 
	    32,                     // no accumulation buffer 
	    0, 0, 0, 0,            // accum bits ignored 
	    32,                    // 32-bit z-buffer 
	    32,                     // no stencil buffer 
	    0,                     // no auxiliary buffer 
	    PFD_MAIN_PLANE,        // main layer 
	    0,                     // reserved 
	    0, 0, 0                // layer masks ignored 
	};
	
	SETUP_VTABLE(DXGI10);
	INIT_CLASS(IDXGISwapChain, *ppSwapChain);
	
	_SwapChain = GET_CLASS_STRUCT(IDXGISwapChain, *ppSwapChain);
	
	_SwapChain->device = pDevice;
	_SwapChain->window = pDesc->OutputWindow;
	
	wdc = GetDC(_SwapChain->window);
	SetPixelFormat(wdc, ChoosePixelFormat(wdc, &pfd), &pfd);
	wgc = wglCreateContext(wdc);
	wglMakeCurrent(wdc, wgc);
	
	GetClientRect(_SwapChain->window, &rect);
	texDesc.Width = rect.right - rect.left;
	texDesc.Height = rect.bottom - rect.top;
	_SwapChain->buffer = D3D10_CreateTexture2D(&texDesc, None);
	
	return S_OK;
}

/* IDXGISwapChain Methods */

WINAPI ULONG IDXGISwapChain_Release(/* IDXGISwapChain */ void *this_) {
	return 0;
}

WINAPI HRESULT IDXGISwapChain_GetBuffer(
	/* IDXGISwapChain */ void * this_,
	UINT Buffer,
	REFIID riid,
	void **ppSurface
) {
	CSTRUCT(IDXGISwapChain) *_SwapChain;
	
	_SwapChain = GET_CLASS_STRUCT(IDXGISwapChain, this_);
	
	*ppSurface = _SwapChain->buffer;
	
	return S_OK;
}

WINAPI HRESULT IDXGISwapChain_Present(
	/* IDXGISwapChain */ void * this_,
	UINT SyncInterval,
	UINT Flags
) {
	CSTRUCT(IDXGISwapChain) *_SwapChain = GET_CLASS_STRUCT(IDXGISwapChain, this_);
	
	SwapBuffers(GetDC((HWND *) _SwapChain->window));
	
	return S_OK;
}
