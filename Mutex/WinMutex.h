#pragma once
#ifdef WIN32
#ifndef __WINMUTEX__
#define __WINMUTEX__

#include "IMutex.h"
#include <windows.h>
class WinMutex :
	public IMutex
{
public:
	WinMutex(void);
	virtual ~WinMutex(void);
	void                init();
	void                lock();
	void                trylock();
	void                unlock();
	void                destroy();
private:
  CRITICAL_SECTION        criticalSection;
};

#endif
#endif