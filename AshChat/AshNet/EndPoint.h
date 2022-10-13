#pragma once

#include <WS2tcpip.h>

class EndPoint
{
public:
	EndPoint();
	EndPoint(const char* address, int port);
	~EndPoint();

	sockaddr_in m_ipv4EndPoint;

	static EndPoint Any;
};

