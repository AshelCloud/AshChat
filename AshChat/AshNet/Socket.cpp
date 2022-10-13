#include "Socket.h"
#include "EndPoint.h"
#include "Exception.h"
#include "SocketInit.h"
#include <iostream>
#include <sstream>

std::string GetLastErrorAsString();

Socket::Socket()
{
	g_socketInit.Touch();

	m_fd = -1;
	ZeroMemory(&m_readOverlappedStruct, sizeof(m_readOverlappedStruct));
}

Socket::Socket(SocketType socketType)
{
	g_socketInit.Touch();

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
		std::stringstream ss;
		ss << "bind failed: " << GetLastErrorAsString() << std::endl;

		throw Exception(ss.str().c_str());
	}
}

void Socket::Connect(const EndPoint& endPoint)
{
	if (connect(m_fd, (sockaddr*)&endPoint.m_ipv4EndPoint, sizeof(endPoint.m_ipv4EndPoint)) < 0)
	{
		std::cout << "connect error" << std::endl;
	}
}

void Socket::Listen()
{
	listen(m_fd, 5);
}

int Socket::Accept(Socket& acceptedScoket)
{
	acceptedScoket.m_fd = accept(m_fd, NULL, 0);
	if (acceptedScoket.m_fd == -1)
	{
		return -1;
	}

	return 0;
}

int Socket::Receive()
{
	return (int)recv(m_fd, m_receiveBuffer, MaxReceiveLength, 0);
}

int Socket::Send(const char* data, int length)
{
	return send(m_fd, data, length, 0);
}

void Socket::Close()
{
	closesocket(m_fd);
}

//Returns the last Win32 error, in string format. Returns an empty string if there is no error.
// ÃâÃ³: https://stackoverflow.com/questions/1387064/how-to-get-the-error-message-from-the-error-code-returned-by-getlasterror
std::string GetLastErrorAsString()
{
#ifdef _WIN32
	//Get the error message, if any.
	DWORD errorMessageID = ::GetLastError();
	if (errorMessageID == 0)
		return std::string(); //No error message has been recorded

	LPSTR messageBuffer = nullptr;
	size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

	std::string message(messageBuffer, size);

	//Free the buffer.
	LocalFree(messageBuffer);

#else 
	std::string message = strerror(errno);
#endif
	return message;
}
