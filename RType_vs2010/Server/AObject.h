#pragma once
class AObject
{
public:
	AObject(void);
	virtual ~AObject(void){};
	int getPosX() const;
	int getPosY() const;
	int getVecVx() const;
	int getVecVy() const;
	int getWidth() const;
	int getHeight() const;
	void	setWidth(int w);
	void	setHeight(int w);
	void setPosX(int x);
	void setPosY(int y);
	void setVecVx(int Vx);
	void setVecVy(int Vy);
	bool getCollision(AObject *obj);
private:
	int	_x;
	int	_y;
	int _Vx;
	int _Vy;
	int _width;
	int _height;
};

