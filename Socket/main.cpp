#include <SFML/Graphics.hpp>
#include "WinSocket.h"
#include <stdio.h>
#include <windows.h>

int main()
{
    //sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
	ISocket *socket = new WinSocket;
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2,0), &WSAData);
	bool test;
	socket->initUDP(4040);
	string lol = "test";
	while (42)
	{
		if (socket->sendDataTo(lol, "127.0.0.1 ", 4040) == -1)
			printf("ERROR\n");
	}
	WSACleanup();
/*    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;*/
}