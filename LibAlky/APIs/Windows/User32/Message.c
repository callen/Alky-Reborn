/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/User32/User32.h>

#define NUMODULE_NAME "User32"

unsigned char SDLKToVK(SDLKey);

WINAPI BOOL PeekMessageA(
    LPMSG lpMsg,
    HWND hWnd,
    UINT wMsgFilterMin,
    UINT wMsgFilterMax,
    UINT wRemoveMsg
) {
	User32 *_Context = User32_GetContext();
	
	NuGUI_Event *event;
	
	int message_start = 0;
	MSG *messages[1024];
	
	NuLog("PeekMessageA(%s)", (wRemoveMsg) ? "Popping" : "Not Popping");
	
	if(_Context->messages[_Context->message_start]) {
		memcpy(lpMsg, _Context->messages[_Context->message_start], sizeof(MSG));
		
		if(wRemoveMsg)
			_Context->message_start++;
		
		return True;
	}
	
	event = NuGUI_GetEvent(SDL_QUIT, wRemoveMsg ? True : False);
	if(event)
		goto gotEvent;
	
	event = NuGUI_GetEvent(SDL_KEYDOWN, wRemoveMsg ? True : False);
	if(event)
		goto gotEvent;
	
	event = NuGUI_GetEvent(SDL_KEYUP, wRemoveMsg ? True : False);
	if(event)
		goto gotEvent;
	
	event = NuGUI_GetEvent(SDL_MOUSEMOTION, wRemoveMsg ? True : False);
	if(event)
		goto gotEvent;
	
	return False;
	
gotEvent:

	memset(lpMsg, 0, sizeof(MSG));
	
	lpMsg->hwnd = hWnd;
	lpMsg->lParam = 0;
	
	switch(event->type) {
		case SDL_KEYDOWN:
			lpMsg->message = WM_KEYDOWN;
			lpMsg->wParam = SDLKToVK(event->key.keysym.sym);

			NuLog("Key %i pressed", lpMsg->wParam);

			break;
		case SDL_KEYUP:
			lpMsg->message = WM_KEYUP;
			lpMsg->wParam = SDLKToVK(event->key.keysym.sym);
			
			NuLog("Key %i unpressed", lpMsg->wParam);
			
			break;
		case SDL_QUIT:
			lpMsg->message = WM_QUIT;
			break;
		case SDL_MOUSEMOTION:
			lpMsg->message = WM_MOUSEMOVE;
			lpMsg->wParam = 0;
			lpMsg->lParam = (short) event->motion.xrel;
			lpMsg->lParam |= ((short) event->motion.yrel) << 16;
			
			NuGUI_MouseReset();
			break;
		default:
			if(wRemoveMsg)
				NuGUI_FreeEvent(event);
			return False;
	}
	
	if(_Context->msgHookProc != None)
		_Context->msgHookProc(HC_ACTION, (wRemoveMsg) ? PM_REMOVE : PM_NOREMOVE, (LPARAM) lpMsg);
	
	if(wRemoveMsg)
		NuGUI_FreeEvent(event);

	return True;
}

WINAPI BOOL GetMessageA(
    LPMSG lpMsg,
    HWND hWnd,
    UINT wMsgFilterMin,
    UINT wMsgFilterMax
) {
	NuLog("GetMessageA");
	return PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, 1);
}

WINAPI BOOL TranslateMessage(
    MSG *lpMsg
) {
	MSG *outMsg;
	
	NuLog("TranslateMessage");
	
	if(lpMsg->message == WM_KEYDOWN) {
		outMsg = (MSG *) NuMemory_Alloc(sizeof(MSG));
		outMsg->message = WM_CHAR;
		
		outMsg->wParam = 'w';
		outMsg->lParam = 0;
		outMsg->hwnd = lpMsg->hwnd;
		
		PostMessage(outMsg);
		
		return True;
	}
	
	switch(lpMsg->message) {
		case WM_KEYDOWN:
		case WM_KEYUP:
		// case WM_SYSKEYDOWN:
		// case WM_SYSKEYUP:
			return True;
		default:
			return False;
	}
}

bool PostMessage(MSG *message) {
	User32 *_Context = User32_GetContext();
	int pos = _Context->message_start + 1;
	
	while(pos != _Context->message_start) {
		if(_Context->messages[pos] == None)
			break;
		pos++;
	}
	
	if(_Context->messages[pos] == None) {
		_Context->messages[pos] = message;
		return True;
	} else {
		return False;
	}
}

unsigned char SDLKToVK(SDLKey key) {
	switch(key) {
		case SDLK_UP: return VK_UP;
		case SDLK_DOWN: return VK_DOWN;
		case SDLK_LEFT: return VK_LEFT;
		case SDLK_RIGHT: return VK_RIGHT;
		case SDLK_a: return VK_A;
		case SDLK_b: return VK_B;
		case SDLK_c: return VK_C;
		case SDLK_d: return VK_D;
		case SDLK_e: return VK_E;
		case SDLK_f: return VK_F;
		case SDLK_g: return VK_G;
		case SDLK_h: return VK_H;
		case SDLK_i: return VK_I;
		case SDLK_j: return VK_J;
		case SDLK_k: return VK_K;
		case SDLK_l: return VK_L;
		case SDLK_m: return VK_M;
		case SDLK_n: return VK_N;
		case SDLK_o: return VK_O;
		case SDLK_p: return VK_P;
		case SDLK_q: return VK_Q;
		case SDLK_r: return VK_R;
		case SDLK_s: return VK_S;
		case SDLK_t: return VK_T;
		case SDLK_u: return VK_U;
		case SDLK_v: return VK_V;
		case SDLK_w: return VK_W;
		case SDLK_x: return VK_X;
		case SDLK_y: return VK_Y;
		case SDLK_z: return VK_Z;
		default: return key;
	}
}

WINAPI UINT RegisterWindowMessageA(
    LPCSTR lpString
) {
	NuWarn("RegisterWindowMessageA not yet implemented");
	
	NuLog("%s", lpString);
	
	return 0xC000;
}

WINAPI LRESULT SendMessageA(
    HWND hWnd,
    UINT Msg,
    WPARAM wParam,
    LPARAM lParam
) {
	NuGUI_Window *window;
	LRESULT (WINAPI *WndProc)(HWND, UINT, WPARAM, LPARAM);
	
	NuLog("SendMessageA");
	
	if(hWnd != None)
		window = (NuGUI_Window *) hWnd;
	else
		window = NuGUI_WindowById(0);

	if(window == None || window->wndclass == None)
		return True;

	WndProc = window->wndclass->callback;

	if(WndProc) {
		return WndProc(
			hWnd, Msg,
			wParam, lParam
		);
	}
	
	return True;
}

WINAPI LRESULT DispatchMessageA(
    const MSG *lpmsg
) {
	NuLog("DispatchMessageA");
	
	return SendMessageA(lpmsg->hwnd, lpmsg->message, lpmsg->wParam, lpmsg->lParam);
}

WINAPI LRESULT DefWindowProcA(
    HWND hWnd,
    UINT Msg,
    WPARAM wParam,
    LPARAM lParam
) {
	NuWarn("DefWindowProcA not yet implemented");
	
	return None;
}

WINAPI void PostQuitMessage(
    int nExitCode
) {
	NuWarn("PostQuitMessage not yet implemented");
}
