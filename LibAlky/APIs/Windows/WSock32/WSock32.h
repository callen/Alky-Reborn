/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_WSOCK32_WSOCK32_H__
#define __APIS_WINDOWS_WSOCK32_WSOCK32_H__

#include <APIs/Windows/Windows.h>

#include <sys/socket.h>

#define WSADESCRIPTION_LEN 255
#define WSASYS_STATUS_LEN 127

typedef struct WSAData {
  WORD wVersion;
  WORD wHighVersion;
  char szDescription[WSADESCRIPTION_LEN+1];
  char szSystemStatus[WSASYS_STATUS_LEN+1];
  unsigned short iMaxSockets;
  unsigned short iMaxUdpDg;
  char *lpVendorInfo;
} WSADATA,
 *LPWSADATA;

WINAPI int WSAStartup(
  WORD wVersionRequested,
  LPWSADATA lpWSAData
);

WINAPI int WSAGetLastError();

WINAPI int ioctlsocket(
  int s,
  long cmd,
  u_long* argp
);

#ifdef DEFINE_SOCK_WRAPPERS
#define SOCK_WRAPPER(ret, name, args, argnames) \
WINAPI ret name##_ args { return name argnames; }
#else
#define SOCK_WRAPPER(ret, name, args, argnames) \
WINAPI ret name##_ args
#endif

SOCK_WRAPPER(
	UINT,
	ntohl,
	(UINT netlong),
	(netlong)
);

SOCK_WRAPPER(
	UINT,
	htonl,
	(UINT hostlong),
	(hostlong)
);

SOCK_WRAPPER(
	unsigned short,
	htons,
	(unsigned short hostshort),
	(hostshort)
);

SOCK_WRAPPER(
	UINT,
	inet_addr,
	(const char *addr),
	(addr)
);

SOCK_WRAPPER(
	int,
	setsockopt,
	(int socket, int level, int option_name, const void *option_value, socklen_t option_len),
	(socket, level, option_name, option_value, option_len)
);

SOCK_WRAPPER(
	int,
	bind,
	(int socket, const struct sockaddr *address, socklen_t address_len),
	(socket, address, address_len)
);

SOCK_WRAPPER(
	int,
	socket,
	(int domain, int type, int protocol),
	(domain, type, protocol)
);

SOCK_WRAPPER(
	ssize_t,
	send,
	(int socket, const void *buffer, size_t length, int flags),
	(socket, buffer, length, flags)
);

SOCK_WRAPPER(
	ssize_t,
	sendto,
	(int socket, const void *buffer, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len),
	(socket, buffer, length, flags, dest_addr, dest_len)
);

SOCK_WRAPPER(
	ssize_t,
	recv,
	(int socket, void *buffer, size_t length, int flags),
	(socket, buffer, length, flags)
);

SOCK_WRAPPER(
	ssize_t,
	recvfrom,
	(int socket, void *buffer, size_t length, int flags, struct sockaddr *address, socklen_t address_len),
	(socket, buffer, length, flags, address, address_len)
);

/*
SOCK_WRAPPER(
	int,
	select,
	(int nfds, fd_set *readfds, fd_set *writefds, fd_set *errorfds),
	(nfds, readfds, writefds, errorfds)
);
*/

SOCK_WRAPPER(
	int,
	connect,
	(int socket, const struct sockaddr *address, socklen_t address_len),
	(socket, address, address_len)
);

SOCK_WRAPPER(
	struct hostent *,
	gethostbyname,
	(const char *name),
	(name)
);

SOCK_WRAPPER(
	int,
	getsockname,
	(int socket, struct sockaddr *address, socklen_t *address_len),
	(socket, address, address_len)
);

#endif
