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
	char tmp;

	for (tmp = 0; this->map.find(tmp) != this->map.end(); tmp++)
	{
		if (tmp >= this->nb_max)
			return -1;
	}
	this->map[tmp] = cl;
	cl->setIdPlayer(tmp);
	return tmp;
}

bool Room::deleteClient(char id)
{
	if (this->map.find(id) != this->map.end())
	{
		this->map.erase(id);
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