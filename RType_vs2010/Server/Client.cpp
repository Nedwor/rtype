#include "Client.h"


Client::Client(void)
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


