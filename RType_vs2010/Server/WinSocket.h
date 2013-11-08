#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#pragma once
#include "ISocket.h"
#include <WinSock2.h>
#include <iostream>
#include <Ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
class WinSocket :
	public ISocket
{
public:
	WinSocket(void);
	virtual ~WinSocket(void);
	//TCP functions
	virtual bool initServer(int port);
	virtual bool connectToServer(std::string const & host, short port);
	virtual bool listenSocket(int backlog);
	virtual ISocket * acceptedConnection();
	virtual int  recData(std::string & buffer, int blocksize);	virtual int  sendData(std::string const & data);

	//UDP function
	virtual bool initUDP(int port);
	virtual bool closeSocket();
	virtual int  recDataFrom(std::string & buffer, int blocksize);	virtual int  sendDataTo(std::string const & data, std::string const &host, int port);

	//All
	virtual void	setSocket(int socket);
	virtual int			getSocket() const;
	std::string	getIp();
private:
	SOCKET sock;
	sockaddr_in	sin;
	sockaddr_in	sin_s;
};
#endif

