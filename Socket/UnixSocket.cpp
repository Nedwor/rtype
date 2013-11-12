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
	if (connect(this->sock, (sockaddr *)&this->sin_s, sizeof(this->sin_s)) == -1)
		return false;
	return true;
}

bool	UnixSocket::bindSocket(short port)
{
	this->sin.sin_addr.s_addr = inet_addr(INADDR_ANY);
	this->sin.sin_family = AF_INET;
	this->sin.sin_port = htons(port);
	if (bind(this->sock, (sockaddr *)&this->sin, sizeof(this->sin)) == -1)
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

bool UnixSocket::initUDP(int port)
{
	if (!this->initSocket(SOCK_DGRAM, 0))
		return false;
	return this->bindSocket(port);
}

bool UnixSocket::closeSocket()
{
	if (close(this->sock) == -1)
		return false;
	return true;
}

int UnixSocket::recDataFrom(std::string &buffer, int blocksize)
{
	char		buf[blocksize + 1];
	sockaddr_in	sin;
	unsigned int	size = sizeof(sin);

	if (recvfrom(this->sock, buf, blocksize, 0, (sockaddr *)(&sin), &size) == -1)
		return -1;
	buffer = buf;
	return 0;
}

int UnixSocket::sendDataTo(std::string const &data, std::string const &host, int port)
{
	sockaddr_in	sin;
	int	size = sizeof(sin);

	sin.sin_addr.s_addr = inet_addr(host.c_str());
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	return sendto(this->sock, (char *)data.c_str(), data.length(), 0, (sockaddr *)(&sin), size);
}

void UnixSocket::setSocket(int socket)
{
	this->sock = socket;
}

int UnixSocket::getSocket() const
{
	return this->sock;
};
