#include "WinSocket.h"
#include "ConnexionState.h"
#include "rfc.h"


int main()
{
#ifdef _WIN32
	ISocket *socket = new WinSocket;
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2,0), &WSAData);
#endif
	bool test;
	t_TCPConnection header;
	header.header.type = CONNECTION;
	header.header.packetSize = 320;
	header.name[0] = '\0';
	header.name[1] = 'e';
	header.name[2] = 's';
	header.name[3] = 't';
	header.name[4] = '\0';
	test = socket->connectToServer("127.0.0.1", 7273);
	std::string buffer;
	if (test == false)
		std::cout << "loooooool" << std::endl;
	else
		std::cout << "ok" << std::endl;
	while (42)
	{
			socket->recData(buffer, 255);
			std::cout << "Received" << buffer << std::endl;
			std::cout << header.header.packetSize << std::endl;
			socket->sendBinary(&header, sizeof(header));
			socket->recBinary(&header.header, 1024);
			std::cout << "Type " << header.header.type << std::endl;
			Sleep(1000000);
	}
#ifdef _WIN32
	WSACleanup();
#endif
    return 0;
}