#include "WinSocket.h"
#include "ConnexionState.h"

using namespace sf;
using namespace std;

int main()
{
	/*WSADATA WSAData;
	WSAStartup(MAKEWORD(2,0), &WSAData);
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
        window.clear();
		CS.Draw(&window);
		window.display();
    }
	WSACleanup();*/
#ifdef _WIN32
	ISocket *socket = new WinSocket;
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2,0), &WSAData);
#endif
	bool test;
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
			Sleep(1000000);
	}
#ifdef _WIN32
	WSACleanup();
#endif
    return 0;
}