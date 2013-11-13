#pragma once

#include "GameStateManager.h"

class IGameState
{
public:
	virtual ~IGameState(){}
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void execute(sf::RenderWindow&) = 0;
};
