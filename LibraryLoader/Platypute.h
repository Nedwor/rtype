#include "IAnimal.h"

class Platypute : public IAnimal
{
	public:
	Platypute(){};
	virtual ~Platypute(){};
	virtual void crier();
};