#ifndef __IANIMAL__
#define __IANIMAL__
class IAnimal
{
public:
	IAnimal(){};
	virtual ~IAnimal(){};
	virtual void crier() = 0;
};
#endif