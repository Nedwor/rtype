#pragma once
#include "AObject.h"

class Player : public AObject
{
public:
	Player(AObject::objectType, int, int, int, int, int, int, int);
	~Player();
private:
};