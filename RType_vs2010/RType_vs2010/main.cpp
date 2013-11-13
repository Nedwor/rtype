#include "WinSocket.h"
#include "ConnexionState.h"
#include "rfc.h"


int main()
{
	RenderWindow window(sf::VideoMode(1024, 768), "R-Type");
	ConnexionState	CS;
	CS.Presentation(&window);
	while (window.isOpen())
	{
		Event	event;
        while (window.pollEvent(event))
        {
		   if (event.type == Event::Closed)
                window.close();
        }
		/*
		socket->recData(buffer, 255);
		std::cout << "Received" << buffer << std::endl;
		std::cout << header.header.packetSize << std::endl;
		socket->sendBinary(&header, sizeof(header));
		socket->recBinary(&header.header, 1024);
		std::cout << "Type " << header.header.type << std::endl;
		*/
//		Sleep(1000000);
        window.clear();
		CS.Draw(&window);
		window.display();
	}
#ifdef _WIN32
	WSACleanup();
#endif
    return 0;
}