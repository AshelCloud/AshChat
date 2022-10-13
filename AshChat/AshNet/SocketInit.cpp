#include "SocketInit.h"
#include <WS2tcpip.h>
#include <iostream>

SocketInit g_socketInit;

SocketInit::SocketInit()
{
	WSADATA wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	std::cout << "Startup code : " << result << std::endl;
}

void SocketInit::Touch()
{
}
