#pragma once

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
	~Socket();
	
	//bind, connet, listen, accept, close, send, recv
public:
	void Bind(const EndPoint& endPoint);
	void Connect(const EndPoint& endPoint);
};

#pragma comment (lib, "ws2_32.lib")