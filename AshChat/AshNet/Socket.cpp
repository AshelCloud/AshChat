#include "Socket.h"
#include "EndPoint.h"
#include <iostream>

Socket::Socket()
{
}

Socket::Socket(SocketType socketType)
{
	m_fd = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);

	ZeroMemory(&m_readOverlappedStruct, sizeof(m_readOverlappedStruct));
}

Socket::~Socket()
{

}

void Socket::Bind(const EndPoint& endPoint)
{
	if (bind(m_fd, (sockaddr*)&endPoint.m_ipv4EndPoint, sizeof(endPoint.m_ipv4EndPoint)) < 0)
	{
		std::cout << "bind failed" << std::endl;
	}
}

void Socket::Connect(const EndPoint& endPoint)
{
}