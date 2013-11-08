#include "WinSocket.h"
#include <iostream>
#include <list>
#include "Client.h"

int main()
{
#ifdef _WIN32
	ISocket *socket = new WinSocket;
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2,0), &WSAData);
#endif
	bool test;
	std::list<Client *> sock; 

	if (socket->initServer(7273) == false)
		return (-1);
	std::string buffer;
	while (42)
	{
		ISocket * sock;
		socket->listenSocket(42);
		if ((sock = socket->acceptedConnection()) != NULL)
		{
			Client *cl = new Client;
			cl->setSocket(sock);
			std::cout << sock->getIp() << std::endl;
			sock->sendData("Bienvenue\n");
		}
		else
		{
			std::cout << "Refuser" << std::endl;
		}
		Sleep(100);
	}
#ifdef _WIN32
	WSACleanup();
#endif
    return 0;
}