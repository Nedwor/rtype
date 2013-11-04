#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include "IAnimal.h"
#include "DLManager.h"
#ifndef _WIN32
#include <unistd.h>
#endif

int	main()
{
  std::string str1("lib_platypute");
  std::string str2("create");
  DLManager<IAnimal *> manager;
	manager.LoadAllLibFromPath("./");
	IAnimal * an = manager.getClass(str1, str2);
	if (an == NULL)
	  printf("bite\n");
	an->crier();
	manager.closeAllLib();
	an = manager.getClass("lib_platypute", "create");
	if (an == 0)
		std::cout << "COOL" << std::endl;
#ifdef _WIN32
	Sleep(100000000);
#endif
#ifndef _WIN32
	sleep(100000000);
#endif
}
