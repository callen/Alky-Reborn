# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

ordinals = {
	'OLEAUT32.DLL' : {
		4 : 'SysAllocStringLen',
		6 : 'SysFreeString',
	},
	'USER32.DLL' : {
		17 : 'InitCommonControls',
	},
	'DSOUND.DLL' : {
		1  : 'DirectSoundCreate',
		2  : 'DirectSoundEnumerateA',
		3  : 'DirectSoundEnumerateW',
		6  : 'DirectSoundCaptureCreate',
		7  : 'DirectSoundCaptureEnumerateA',
		8  : 'DirectSoundCaptureEnumerateW',
		9  : 'GetDeviceID',
		10 : 'DirectSoundFullDuplexCreate',
		11 : 'DirectSoundCreate8',
		12 : 'DirectSoundCaptureCreate8'
	},
	'WSOCK32.DLL' : {
		1 : 'accept',
		2 : 'bind',
		3 : 'closesocket',
		4 : 'connect',
		5 : 'getpeername',
		6 : 'getsockname',
		7 : 'getsockopt',
		8 : 'htonl',
		9 : 'htons',
		10 : 'inet_addr',
		11 : 'inet_ntoa',
		12 : 'ioctlsocket',
		13 : 'listen',
		14 : 'ntohl',
		15 : 'ntohs',
		16 : 'recv',
		17 : 'recvfrom',
		18 : 'select',
		19 : 'send',
		20 : 'sendto',
		21 : 'setsockopt',
		22 : 'shutdown',
		23 : 'socket',
		
		51 : 'gethostbyaddr',
		52 : 'gethostbyname',
		53 : 'getprotobyname',
		54 : 'getprotobynumber',
		55 : 'getservbyname',
		56 : 'getservbyport',
		57 : 'gethostname',
		
		101 : 'WSAAsyncSelect',
		102 : 'WSAAsyncGetHostByAddr',
		103 : 'WSAAsyncGetHostByName',
		104 : 'WSAAsyncGetProtoByNumber',
		105 : 'WSAAsyncGetProtoByName',
		106 : 'WSAAsyncGetServByPort',
		107 : 'WSAAsyncGetServByName',
		108 : 'WSACancelAsyncRequest',
		109 : 'WSASetBlockingHook',
		110 : 'WSAUnhookBlockingHook',
		111 : 'WSAGetLastError',
		112 : 'WSASetLastError',
		113 : 'WSACancelBlockingCall',
		114 : 'WSAIsBlocking',
		115 : 'WSAStartup',
		116 : 'WSACleanup',
		
		151 : '__WSAFDIsSet'
	}
}