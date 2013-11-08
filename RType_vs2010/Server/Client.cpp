#include "Client.h"


Client::Client(void)
{
}


Client::~Client(void)
{
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

