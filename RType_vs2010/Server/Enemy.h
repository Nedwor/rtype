#pragma once
#include "AObject.h"

class Enemy : public AObject
{
public:
	Enemy(AObject::objectType, int, int, int, int, int, int, int);
	~Enemy();
private:
};
