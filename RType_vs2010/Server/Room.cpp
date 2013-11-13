#include "Room.h"


Room::Room(void)
{
	this->nb_ingame = 0;
	this->nb_max = 0;
	this->game_id = 0;
}


Room::~Room(void)
{
}


char Room::getNbMax() const
{
	return this->nb_max;
}

char Room::getNbIngame() const
{
	return this->nb_ingame;
}

void Room::setNbMax(char nb)
{
	this->nb_max = nb;
}

void Room::setNbIngame(char nb)
{
	this->nb_ingame = nb;
}

char Room::addClient(Client *cl)
{
	char tmp = 0;
	for (tmp = 0; this->map.find(tmp) != this->map.end(); tmp++)
	{
		if (tmp >= this->nb_max)
			return -1;
	}
	this->map[tmp] = cl;
	this->nb_ingame++;
	cl->setIdPlayer(tmp);
	return tmp;
}

bool Room::deleteClient(char id)
{
	if (this->map.find(id) != this->map.end())
	{
		this->map.erase(id);
		this->nb_ingame--;
		return true;
	}
	return false;
}

void Room::setGameId(short game_id)
{
	this->game_id = game_id;
}

short Room::getGameId() const
{
	return this->game_id;
}

void	*initGame(void *arg)
{
	Room *room;

	room = (Room *)arg;
	room->initGame();
	return NULL;
}

bool Room::initGame()
{
	while (42)
	{
		if (this->nb_ingame == 0)
		{
			std::cout << "Partie terminée" << std::endl;
			return true;
		}
		std::cout << "ouech" << std::endl;
		Sleep(100);
	}
	return true;
}