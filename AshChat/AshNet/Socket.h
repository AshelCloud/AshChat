#pragma once

#include <WS2tcpip.h>
#include <string>

class EndPoint;

enum class SocketType
{
	TCP,
	UDP
};

class Socket
{
public:
	static const int MaxReceiveLength = 512;

public:
	Socket();
	Socket(SocketType socketType);
	~Socket();

	//Handle
	SOCKET m_fd;

	//Overlapped I/O를 사용하기 위한 Overlapped 객체
	WSAOVERLAPPED m_readOverlappedStruct;

	char m_receiveBuffer[MaxReceiveLength];
	
public:
	//bind, connet, listen, accept, close, send, recv
	void Bind(const EndPoint& endPoint);
	void Connect(const EndPoint& endPoint);
	void Listen();
	int Accept(Socket& acceptedScoket);
	int Receive();
	int Send(const char* data, int length);
	void Close();
};

std::string GetLastErrorAsString();

#pragma comment (lib, "ws2_32.lib")