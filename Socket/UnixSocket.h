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
	virtual bool initSocket(int type, int protocol);
	virtual bool connectToServer(std::string const & host, short port);
	virtual bool bindSocket(short port);
	virtual int recData(std::string & buffer, int blocksize);
	virtual int sendData(std::string const & data);

	//UDP functions
	virtual bool initUDP(int port);
	virtual bool closeSocket();
	virtual int  recDataFrom(std::string & buffer, int blocksize);
	virtual int  sendDataTo(std::string const & data, std::string const &host, int port);

	//All
	virtual void	setSocket(int socket);
	virtual int	getSocket() const;

private:
	int	sock;
	sockaddr_in	sin;
	sockaddr_in	sin_s;
};

#endif
