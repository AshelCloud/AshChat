#include "../AshNet/AshNet.h"
#include <iostream>

int main()
{
	try
	{
		Socket listenSocket(SocketType::TCP);

		listenSocket.Bind(EndPoint("0.0.0.0", 5959));
		listenSocket.Listen();

		std::cout << "Server Start." << std::endl;

		Socket connectionSocket;
	
		listenSocket.Accept(connectionSocket);

		while (true)
		{
			std::string recvDta;
			std::cout << "Receiving data.." << std::endl;

			int result = connectionSocket.Receive();

			if (result == 0)
			{
				std::cout << "Connection close." << std::endl;
				break;
			}
			else if (result < 0)
			{
				std::cout << "Connection Lost." << std::endl;
			}

			std::cout << "Received: " << connectionSocket.m_receiveBuffer << std::endl;
		}

		connectionSocket.Close();

		system("pause");
	}
	catch(Exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}