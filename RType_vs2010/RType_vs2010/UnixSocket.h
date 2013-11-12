#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "isocket.h"

class UnixSocket :
	public ISocket
{
public:
	UnixSocket(void);
	~UnixSocket(void);
	virtual bool initSocket(int type, int protocol);
	virtual bool connectToServer(std::string const & host, short port);
	virtual bool bindSocket(short port);
	virtual int recData(std::string & buffer, int blocksize);	virtual int sendData(std::string const & data);
	virtual bool closeSocket();
private:
	int	sock;
	sockaddr_in	sin;
	sockaddr_in	sin_s;
};

