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

bool AObject::getCollision(AObject obj)
{
  if (this->_x + this->_width/4) < obj->getPosX() - (obj->getWidth()/4) * 3) return false;
  if (this->_x - ((this->_width/4) * 3) > obj->getPosX() + obj->getWidth()/4)return false;
  if (this->_y + this->_height/4) < obj->getPosY() - (obj->getHeight()/4) * 3) return false;
  if (this->_y - ((this->_height/4) * 3) > obj->getPosY() + obj->getHeight()/4) return false;
  return true;
}
