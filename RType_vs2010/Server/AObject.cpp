#include "AObject.h"


AObject::AObject(void)
{
}



int AObject::getPosX() const
{
	return this->x;
}
int AObject::getPosY() const
{
	return this->y;
}
int AObject::getVecVx() const
{
	return this->Vx;
}
int AObject::getVecVy() const
{
	return this->Vy;
}
void AObject::setPosX(int x)
{
	this->x = x;
}
void AObject::setPosY(int y)
{
	this->y = y;
}
void AObject::setVecVx(int Vx)
{
	this->Vx = Vx;
}
void AObject::setVecVy(int Vy)
{
	this->Vy = Vy;
}