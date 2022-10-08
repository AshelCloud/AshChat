#include "EndPoint.h"

EndPoint::EndPoint():
	m_ipv4EndPoint()
{
	memset(&m_ipv4EndPoint, 0, sizeof(m_ipv4EndPoint));
	m_ipv4EndPoint.sin_family = AF_INET;
}

EndPoint::EndPoint(const char* address, int port):
	m_ipv4EndPoint()
{
	memset(&m_ipv4EndPoint, 0, sizeof(m_ipv4EndPoint));
	m_ipv4EndPoint.sin_family = AF_INET;
	inet_pton(AF_INET, address, &m_ipv4EndPoint.sin_addr);
	m_ipv4EndPoint.sin_port = htons(port);
}

EndPoint::~EndPoint()
{
}