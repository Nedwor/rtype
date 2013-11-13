#ifndef _WIN32
#include "UnixSocket.h"


UnixSocket::UnixSocket(void)
{
}


UnixSocket::~UnixSocket(void)
{
}

bool	UnixSocket::initSocket(int type, int protocol)
{
	if ((this->sock = socket(AF_INET, type, protocol)) == -1)
			return false;
	return true;
}

bool	UnixSocket::connectToServer(std::string const & host, short port)
{
	this->sin_s.sin_addr.s_addr = inet_addr(host.c_str());
	this->sin_s.sin_family = AF_INET;
	this->sin_s.sin_port = htons(port);
	if (connect(this->sock, (SOCKADDR *)&this->sin_s, sizeof(this->sin_s)) == -1)
		return false;
	return true;
}

bool	UnixSocket::bindSocket(short port)
{
	this->sin.sin_addr.s_addr = inet_addr(INADDR_ANY);
	this->sin.sin_family = AF_INET;
	this->sin.sin_port = htons(port);
	if (bind(this->sock, (SOCKADDR *)&this->sin, sizeof(this->sin)) == SOCKET_ERROR)
		return false;
	return true;
}

int UnixSocket::recData(std::string & buffer, int blocksize)
{
	int len;
	char	buff[255];

	if ((len = recv(this->sock, buff, blocksize, 0)) == -1)
		return len;
	buffer = buff;
	return len;
}

int UnixSocket::sendData(std::string const & data)
{
	int	len;

	if ((len = send(this->sock, data.c_str(), data.length(), 0)) == -1)
		return (len);
	return len;
}

bool UnixSocket::closeSocket()
{
	if (close(this->sock) == -1)
		return false;
	return true;
}

#endif