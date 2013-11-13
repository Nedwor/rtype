#include "IGameState.h"

GameStateManager::GameStateManager(IGameState& state, sf::RenderWindow* window)
	:_win(window)
{
	this->_states.push(&state);
}

GameStateManager::~GameStateManager()
{
}

void	GameStateManager::connect(std::string name, std::string ip)
{
	//this->_connexion.connect(name, ip);
}

void	GameStateManager::run()
{
	while (this->_win->isOpen())
	{
		sf::Event	event;
		while (this->_win->pollEvent(event))
        {
		   if (event.type == sf::Event::Closed)
			   this->_win->close();
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
		this->_win->clear();
		this->_states.top()->execute(*this->_win);
		this->_states.top()->draw(*this->_win);
		this->_win->display();
	}

	/*IGameState* currState = this->getCurrentState();
	while (currState != NULL)
	{
		SF::Time time = this->_clock.restart();
		if (time.asMicroseconds() < (1/60))
			usleep(1/60 - time.asMicroseconds());
		currState = this->getCurrentState();
	}*/
}