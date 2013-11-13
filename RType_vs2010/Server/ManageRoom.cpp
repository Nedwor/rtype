#include "ManageRoom.h"


ManageRoom::ManageRoom(void)
{
	this->TCPActions[CONNECTION] = &ManageRoom::handleConnectGame;
	this->TCPActions[LIST_GAMES] = &ManageRoom::handleListGames;
	this->TCPActions[CREATE_GAME] = &ManageRoom::handleCreateGame;
	this->currentGameId = 1;
}


ManageRoom::~ManageRoom(void)
{
}

std::list<Client *> ManageRoom::getClientList() const
{
	return (this->clList);
}
void ManageRoom::setClientList(std::list<Client *> const &clList)
{
	this->clList = clList;
}

int	ManageRoom::getMaxFDAndSet()
{
	int max = 0;

	FD_ZERO(&(this->read));
	max = this->server->getSocket();
	FD_SET(max, &(this->read));
	for (std::list<Client *>::iterator it = this->clList.begin(); it != this->clList.end(); ++it)
	{
		ISocket *s = (*it)->getSocket();
		if (s != 0)
		{
			int fd = s->getSocket();
			FD_SET(fd, &(this->read));
			if (max < fd)
				max = fd;
		}
	}
	return max + 1;
}

void	ManageRoom::check_list()
{
	for (std::list<Client *>::iterator it = this->clList.begin(); it != this->clList.end(); ++it)
	{
		ISocket *socket;
		socket = (*it)->getSocket();
		char *buf = new char[1025];

		if (socket != NULL)
		{
			int fd = socket->getSocket();
			if (FD_ISSET(fd, &(this->read)))
			{
				std::string buffer;
				int len;
				t_TCPHeader *header;
				if ((len = socket->recBinary(buf, 1024)) < 0)
				{
					this->clList.erase(it++);
					std::map<std::string, Room *>::iterator it;
					std::string ip = socket->getIp();
					if ((it = this->_access.find(ip)) != this->_access.end())
						this->_access.erase(it);
					socket->closeSocket();
				}
				else
				{
					header = (t_TCPHeader *)buf;
					if (this->TCPActions.find(header->type) != this->TCPActions.end())
					{
	        			 ptr p;
						 t_TCPConnection *con;
						 con = (t_TCPConnection *)buf;
						 p = this->TCPActions[header->type];
						 if ((*it)->getName().empty() == 1 && header->type == CONNECTION)
							(this->*p)(buf, *it);
						 else if (!(*it)->getName().empty() == 1)
							 (this->*p)(buf, *it);
						 else
							this->sendErrorPacket(socket, NOT_LOGGED);
					}
				}
			}
		}
	}
}

void ManageRoom::sendErrorPacket(ISocket *socket, ERROR_TYPE err)
{
	t_TCPError header;

	header.header.type = PACKET_ERROR;
	header.header.packetSize = sizeof(header);
	header.error = err;
	socket->sendBinary(&header, sizeof(header));
}

void ManageRoom::lauchServeur(int port)
{
	#ifdef _WIN32
	ISocket *socket = new WinSocket;
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2,0), &WSAData);
#endif
	this->server = socket;
	if (socket->initServer(7273) == false)
		return;
	std::string buffer;
	this->server->listenSocket(42);
	struct timeval time;
	while (42)
	{
		int max = getMaxFDAndSet();
		ISocket * sock;
		time.tv_sec = 1;
		time.tv_usec = 0;
		if(select(max, &(this->read), 0,0, &time) == SOCKET_ERROR)
		{
			std::cout << "Select Error" << std::endl;
			return ;
		}
		if (FD_ISSET(this->server->getSocket(), &(this->read)))
		{
			if ((sock = this->server->acceptedConnection()) != NULL)
			{
				Client *cl = new Client(AObject::Ally, 0, 0, 0, 0, 0, 0, 0);
				cl->setSocket(sock);
				clList.push_front(cl);
			}
			else
				std::cout << "Refusé" << std::endl;
		}
		else
			check_list();
	}
#ifdef _WIN32
	WSACleanup();
#endif
}

void	ManageRoom::handleCreateGame(void *buffer, Client *cl)
{
	t_TCPCreate *create;
	create = (t_TCPCreate *)buffer;

	Room *room = new Room;

	room->setGameId(this->currentGameId);
	room->setNbMax(create->nb_max);
	char id = room->addClient(cl);
	this->listRoom[this->currentGameId++] = room;
	int i = 0;
	int len;
	const char *str = cl->getName().c_str();
	ISocket *sock;
	t_TCPPlayer Player;

	//On prépare le packet pour prévenir le joueur de sa connection à la partie créée

	while (str[i])
		Player.name[i] = str[i++];
	Player.player_id = id;
	Player.status = NOT_READY;
	Player.header.packetSize = sizeof(Player);
	Player.header.type = PLAYER;

	sock = cl->getSocket();
	this->_access[sock->getIp()] = room;
	if ((len = sock->sendBinary(&Player, sizeof(Player))) < 0)
		std::cout << "Error while sending Create" << std::endl;
}

void	ManageRoom::handleListGames(void *buffer, Client *cl)
{
	t_TCPGame	Game;
	int			len;
	ISocket *sock;
	sock = cl->getSocket();

	Game.header.packetSize = sizeof(Game);
	Game.header.type = GAME; 
	for (std::map<short, Room *>::iterator it = this->listRoom.begin(); it != this->listRoom.end(); ++it)
	{
		Game.nb_ingame = ((*it).second)->getNbIngame();
		Game.nb_max = ((*it).second)->getNbMax();
		Game.id_game = ((*it).second)->getGameId();
		if ((len = sock->sendBinary(&Game, sizeof(Game))) < 0)
			std::cout << "Error while sending Game" << std::endl;
	}
	Game.header.packetSize = sizeof(Game.header);
	Game.header.type = END_LIST_GAMES;
	if ((len = sock->sendBinary(&Game, sizeof(Game.header))) < 0)
			std::cout << "Error while sending End Game" << std::endl;
}

void	ManageRoom::handleConnectGame(void *buffer, Client *cl)
{
	t_TCPConnection *res;
	ISocket *sock;
	std::string name;
	res = (t_TCPConnection *)buffer;
	cl->setName(res->name);
	std::cout << res->name << std::endl;
	sock = cl->getSocket();
	cl->setIp(sock->getIp());
	if (!cl->getName().empty())
	{
		t_TCPHeader Header;
		Header.type = ESTABLISHED;
		Header.packetSize = sizeof(Header);
		sock->sendBinary(&Header, sizeof(Header));
	}
	else
	{
		t_TCPError Header;
		Header.header.type = PACKET_ERROR;
		Header.header.packetSize = sizeof(Header);
		Header.error = LOGIN;
		sock->sendBinary(&Header, sizeof(Header));
	}
}