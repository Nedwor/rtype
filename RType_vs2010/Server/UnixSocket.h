#ifndef _WIN32
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "ISocket.h"

#ifndef UNIXSOCKET_H_
#define UNIXSOCKET_H_

class UnixSocket :
	public ISocket
{
public:
	UnixSocket(void);
	~UnixSocket(void);
	//TCP functions
	bool initSocket(int type, int protocol);
	bool connectToServer(std::string const & host, short port);
	bool bindSocket(short port);
	int recData(std::string & buffer, int blocksize);
	int sendData(std::string const & data);

	//UDP functions
	bool initUDP(int port);
	bool closeSocket();
	int  recDataFrom(std::string & buffer, int blocksize);
	int  sendDataTo(std::string const & data, std::string const &host, int port);
	int	 recBinaryFrom(void *buffer, int blocksize, std::string &ip);
	int	 sendBinaryTo(void *buffer, std::string const & host, int port, int blocksize);
	//All
	void	setSocket(int socket);
	int	getSocket() const;

private:
	int	sock;
	sockaddr_in	sin;
	sockaddr_in	sin_s;
};

#endif
#endif
