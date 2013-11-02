#include <windows.h> 
#include <stdio.h> 
#include "IAnimal.h"
#include "DLManager.h"


int	main()
{
	DLManager<IAnimal *> manager;
	manager.LoadAllLibFromPath("../");
	IAnimal * an = manager.getClass("Platypute", "create");
	an->crier();
	manager.closeAllLib();
	an = manager.getClass("Platypus", "create");
	if (an == 0)
		std::cout << "COOL" << std::endl;
	Sleep(100000000);
}