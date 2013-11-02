#include "stdafx.h"
#include "Platypute.h"
#include <windows.h>
#include <stdio.h>

#define EOF (-1)
 
#ifdef __cplusplus    // If used by C++ code, 
extern "C" {          // we need to export the C interface
#endif
 
__declspec(dllexport) IAnimal *__cdecl create()
{
  return new Platypute;
}
 
#ifdef __cplusplus
}

void	Platypute::crier()
{
	printf("PUUUUUUUUUUUUUUUUUUUUTE");
}

#endif