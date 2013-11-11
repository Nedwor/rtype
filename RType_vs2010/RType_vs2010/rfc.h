#ifndef _RFC_H__
#define _RFC_H__

enum TCP_PACKET_TYPE {
	CONNECTION = 0,
	ESTABLISHED,
	LIST_GAMES,
	GAME,
	END_LIST_GAMES,
	CONNECT_GAME,
	PLAYER,
	CREATE_GAME,
	GAMESTATE,
	PACKET_ERROR
};


typedef struct s_TCPHeader
{
	short packetSize;
	TCP_PACKET_TYPE type;
}t_TCPHeader;

typedef struct s_TCPConnection
{
	t_TCPHeader header;
	char		name[32];
}t_TCPConnection;

#endif