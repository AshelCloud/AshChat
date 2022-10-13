#pragma once

#include <WS2tcpip.h>


class EndPoint;

enum class SocketType
{
	TCP,
	UDP
};

class Socket
{
public:
	Socket();
	Socket(SocketType socketType);
	~Socket();

	//Handle
	SOCKET m_fd;

	//Overlapped I/O를 사용하기 위한 Overlapped 객체
	WSAOVERLAPPED m_readOverlappedStruct;
	
	//bind, connet, listen, accept, close, send, recv
public:
	void Bind(const EndPoint& endPoint);
	void Connect(const EndPoint& endPoint);
};

#pragma comment (lib, "ws2_32.lib")