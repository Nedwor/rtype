#include "AObject.h"

AObject::AObject(objectType type, int idObject, int x, int y, int height, int width, int Vx, int Vy)
  : _type(type), _idObject(idObject), _x(x), _y(y), _height(height), _width(width), _Vx(Vx), _Vy(Vy)
{
}
AObject::objectType AObject::getType() const
{
  return this->_type;
}
int AObject::getIdObject() const
{
  return this->_idObject;
}
int AObject::getPosX() const
{
	return this->_x;
}
int AObject::getPosY() const
{
	return this->_y;
}
int AObject::getHeight() const
{
  return this->_height;
}
int AObject::getWidth() const
{
  return this->_width;
}
int AObject::getVecVx() const
{
	return this->_Vx;
}
int AObject::getVecVy() const
{
	return this->_Vy;
}
void AObject::setType(objectType type)
{
  this->_type = type;
}
void AObject::setIdObject(int idObject)
{
  this->_idObject = idObject;
}
void AObject::setPosX(int x)
{
	this->_x = x;
}
void AObject::setPosY(int y)
{
	this->_y = y;
}
void AObject::setVecVx(int Vx)
{
	this->_Vx = Vx;
}
void AObject::setVecVy(int Vy)
{
	this->_Vy = Vy;
}

void	AObject::setWidth(int w)
{
	this->_width = w;
}

void	AObject::setHeight(int h)
{
	this->_height = h;
}

bool AObject::getCollision(AObject *obj)
{
  if ((this->_x + this->_width/4) < ((obj->getPosX() - (obj->getWidth()/4) * 3))) return false;
  if (this->_x - ((this->_width/4) * 3) > obj->getPosX() + obj->getWidth()/4)return false;
  if ((this->_y + this->_height/4) < (obj->getPosY() - (obj->getHeight()/4) * 3)) return false;
  if (this->_y - ((this->_height/4) * 3) > (obj->getPosY() + obj->getHeight()/4)) return false;
  return true;
}
