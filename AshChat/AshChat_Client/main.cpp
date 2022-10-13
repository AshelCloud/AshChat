#include "../AshNet/AshNet.h"

int main()
{
	Socket socket(SocketType::TCP);

	socket.Bind(EndPoint::Any);
}