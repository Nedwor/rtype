#pragma once
#include <string>

class ISocket
{
public:
	virtual  ~ISocket(){};
	//TCP functions
	virtual bool		initServer(int port) = 0;
	virtual bool		connectToServer(std::string const & host, short port) = 0;
	virtual bool		listenSocket(int backlog) = 0;
	virtual ISocket *	acceptedConnection() = 0;
	virtual int			recData(std::string & buffer, int blocksize) = 0;	virtual int			sendData(std::string const & data) = 0;
	virtual int			recBinary(void *point, int blocksize) = 0;
	virtual int			sendBinary(void *point, int len) = 0;

	//UDP function
	virtual bool		initUDP(int port) = 0;
	virtual bool		closeSocket() = 0;
	virtual int			recDataFrom(std::string & buffer, int blocksize) = 0;	virtual int			sendDataTo(std::string const & data, std::string const &host, int port) = 0;
	
	//All
	virtual void		setSocket(int socket) = 0;
	virtual int			getSocket() const = 0;
	virtual std::string getIp() = 0;
};