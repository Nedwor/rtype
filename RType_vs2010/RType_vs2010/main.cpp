#include <windows.h>
#include "ConnexionState.h"

using namespace sf;
using namespace std;

int main()
{
	//WSADATA WSAData;
	//WSAStartup(MAKEWORD(2,0), &WSAData);
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
	//WSACleanup();
    return 0;
}