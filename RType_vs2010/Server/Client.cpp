#include "Client.h"


Client::Client(AObject::objectType type, int idObject, int x, int y, int height, int width, int Vx, int Vy)
	: AObject(type, idObject, x, y, height, width, Vx, Vy)
{
}


Client::~Client(void)
{
	this->name ="";
	this->ip = "";
}
void Client::setName(std::string const &name)
{
	this->name = name;
}
void Client::setIp(std::string const &ip)
{
	this->ip = ip;
}

std::string Client::getName() const
{
	return this->name;
}

std::string Client::getIp() const
{
	return this->ip;
}

ISocket* Client::getSocket() const
{
	return this->socket;
}

void Client::setSocket(ISocket* sock)
{
	this->socket = sock;
}

void Client::setIdPlayer(char id)
{
	this->id_player = id;
}

short Client::getIdPlayer() const
{
	return this->id_player;
}


