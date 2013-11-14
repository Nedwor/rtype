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
	std::string getName() const;
	void setName(std::string const &name);
private:
	std::map<char, Client *> map;
	std::string _name;
	char nb_max;
	char nb_ingame;
	short game_id;
};

