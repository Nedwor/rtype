#pragma once
#include <map>
#include "Client.h"

void *initGame(void *arg);
class Room
{
public:
	Room(void);
	~Room(void);
	char getNbMax() const;
	char getNbIngame() const;
	void setNbMax(char nb);
	void setNbIngame(char nb);
	char addClient(Client *cl);
	bool deleteClient(char id);
	void setGameId(short game_id);
	short getGameId() const;
	bool  initGame();
private:
	std::map<char, Client *> map;
	char nb_max;
	char nb_ingame;
	short game_id;
};

