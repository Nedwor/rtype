#pragma once
#include "WinSocket.h"
#include <iostream>
#include <list>
#include "Client.h"
#include "rfc.h"
#include <map>
#include "Room.h"
#include "WinThread.h"

class ManageRoom
{
	typedef void (ManageRoom:: *ptr)(void *buffer, Client *cl);
public:
	ManageRoom(void);
	~ManageRoom(void);
	std::list<Client *> getClientList() const;
	void	setClientList(std::list<Client *> const &clList);
	void	lauchServeur(int port);
	void	check_list();
	int		getMaxFDAndSet();
	void	sendErrorPacket(ISocket *socket, ERROR_TYPE err);
	void	handleConnection(void *buffer, Client *cl);
	void	handleListGames(void *buffer, Client *cl);
	void	handleConnectGame(void *buffer, Client *cl);
	void	handleCreateGame(void *buffer, Client *cl);
private:
	std::list<Client *> clList;
	fd_set read;
	ISocket *server;
	ISocket *Udp;
	std::map<TCP_PACKET_TYPE, ptr> TCPActions;
	std::map<short, Room *> listRoom;
	std::map<std::string, Room *>	_access;
	int currentGameId;
};