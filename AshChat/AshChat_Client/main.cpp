#include "../AshNet/AshNet.h"
#include <iostream>

int main()
{
	try
	{
		Socket socket(SocketType::TCP);

		socket.Bind(EndPoint::Any);
		std::cout << "Connection..." << std::endl;
		socket.Connect(EndPoint("127.0.0.1", 5959));

		std::cout << "Sending..." << std::endl;

		const char* text = "hello\n";

		socket.Send(text, strlen(text) + 1);

		socket.Close();

		system("pause");
	}
	catch (Exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}