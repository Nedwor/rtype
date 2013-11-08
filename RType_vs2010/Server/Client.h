#pragma once
#include <string>
#include "ISocket.h"
#include "AObject.h"
#ifndef _WIN32
#include "UnixSocket.h"
#endif
#ifdef _WIN32
#include "WinSocket.h"
#endif

class Client : public AObject
{
public:
	Client(void);
	~Client(void);
	void setName(std::string const &name);
	std::string getName() const;
	void setIp(std::string const &ip);
	std::string getIp() const;
	ISocket *getSocket() const;
	void setSocket(ISocket *sock);
private:
	std::string ip;
	std::string name;
	ISocket *socket;
};

