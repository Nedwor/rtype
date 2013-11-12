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
	void setPosX(int x);
	void setPosY(int y);
	void setVecVx(int Vx);
	void setVecVy(int Vy);

private:
	int	x;
	int	y;
	int Vx;
	int Vy;
};

