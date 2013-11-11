#include "ManageRoom.h"


ManageRoom::ManageRoom(void)
{
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
		
		if (socket != NULL)
		{
			int fd = socket->getSocket();
			if (FD_ISSET(fd, &(this->read)))
			{
				std::string buffer;
				int len;
				t_TCPHeader header;
				if ((len = socket->recBinary(&header, 1024)) <= 0)
				{
					socket->closeSocket();
					this->clList.erase(it++);
				}
				std::cout << len << " buffer = " <<  header.type << " End" << std::endl;
			}
		}
	}
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
				Client *cl = new Client;
				cl->setSocket(sock);
				clList.push_front(cl);
				sock->sendData("Bienvenue\n");
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