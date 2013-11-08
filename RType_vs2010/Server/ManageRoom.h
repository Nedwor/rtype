#pragma once
#include "WinSocket.h"
#include <iostream>
#include <list>
#include "Client.h"
#include "rfc.h"

class ManageRoom
{
public:
	ManageRoom(void);
	~ManageRoom(void);
	std::list<Client *> getClientList() const;
	void setClientList(std::list<Client *> const &clList);
	void lauchServeur(int port);
	void	check_list();
	int	getMaxFDAndSet();
private:
	std::list<Client *> clList;
	fd_set read;
	ISocket *server;
};

