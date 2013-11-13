#pragma once
class AObject
{
public:
	enum objectType 
	{
    Ally,
    Ennemy,
    Env
	};
	AObject(objectType, int, int, int, int, int, int, int);
	virtual ~AObject(void){};
	objectType getType() const;
	int getIdObject() const;
	int getPosX() const;
	int getPosY() const;
	int getVecVx() const;
	int getVecVy() const;
	int getWidth() const;
	int getHeight() const;
	void setType(objectType);
	void setIdObject(int);
	void	setWidth(int w);
	void	setHeight(int w);
	void setPosX(int x);
	void setPosY(int y);
	void setVecVx(int Vx);
	void setVecVy(int Vy);
	bool getCollision(AObject *obj);
private:
	objectType	_type;
	int	_idObject;
	int	_x;
	int	_y;
	int _width;
	int _height;
	int _Vx;
	int _Vy;
};

