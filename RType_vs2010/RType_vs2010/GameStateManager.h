#pragma once
#define NOMINMAX
#ifdef _WIN32
	#include "WinSocket.h"
#endif
#ifndef _WIN32
	#include "UnixSocket.h"
#endif
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <stack>
#include <iostream>
#include <sstream>
#include <windows.h>
//#include <Clock.hpp>

//#include "WinSocket.h"
#include "rfc.h"


class IGameState;

class GameStateManager
{
	sf::RenderWindow* _win;
	std::stack<IGameState*>	_states;
	sf::Clock	_clock;
/*  ObjectsManager	_Object;
	HandleConnexion	_connexion;
	IThread		_connexionThread;
	IThread		_inputThread;
	IThread		_executeThread;*/
public:
	GameStateManager(IGameState& state, sf::RenderWindow* window);
	~GameStateManager();
	void	run();
	void	pause();
	void	createObject(int index);
	void	connect(std::string name, std::string ip);
	IGameState*	getCurrentState();
	void	pushState(IGameState* state);
	void	popState();
};
