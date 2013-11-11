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

enum ERROR_TYPE{
	LOGIN,
	GAME_FULL,
	GAME_NOT_EXIST,
	SERVER_FULL
};

enum STATUS
{
	NOT_READY,
	READY,
	DISCONNECTED
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

typedef struct s_TCPError
{
	t_TCPHeader header;
	ERROR_TYPE  error;
}t_TCPError;

typedef struct s_TCPGame
{
	t_TCPHeader header;
	short id_game;
	char  nb_max;
	char  nb_ingame;
}t_TCPGame;

typedef struct s_TCPCreate
{
	t_TCPHeader header;
	char nb_max;
}t_TCPCreate;

typedef struct s_TCPPlayer
{
	t_TCPHeader header;
	STATUS	status;
	char	name[32];
	char	player_id;
}t_TCPPlayer;

#endif