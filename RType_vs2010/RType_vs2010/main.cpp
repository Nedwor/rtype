#include "ConnexionState.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "R-Type");
	ConnexionState	CS;
	CS.presentation(window);
	GameStateManager manager(CS, &window);
	manager.run();
#ifdef _WIN32
	WSACleanup();
#endif
    return 0;
}