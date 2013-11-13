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
        window.clear();
		CS.Execute(&window);
		CS.Draw(&window);
		window.display();
	}
#ifdef _WIN32
	WSACleanup();
#endif
    return 0;
}