#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#pragma once
#include "ISocket.h"
#include <winsock2.h>
#include <iostream>
#include <Ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
class WinSocket :
	public ISocket
{
public:
	WinSocket(void);
	~WinSocket(void);
	//TCP functions
	bool initServer(int port);
	bool connectToServer(std::string const & host, short port);
	bool listenSocket(int backlog);
	ISocket * acceptedConnection();
	int  recData(std::string & buffer, int blocksize);
	int  sendData(std::string const & data);
	int			recBinary(void *point, int blocksize);
	int			sendBinary(void *point, int len);
	//UDP function
	bool initUDP(int port);
	bool closeSocket();
	int  recDataFrom(std::string & buffer, int blocksize);
	int  sendDataTo(std::string const & data, std::string const &host, int port);

	//All
	void	setSocket(int socket);
	int			getSocket() const;
	std::string	getIp();
private:
	sockaddr_in	sin;
	SOCKET sock;
	sockaddr_in	sin_s;
};
#endif
