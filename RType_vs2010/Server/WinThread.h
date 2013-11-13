#pragma once
#ifdef WIN32

#ifndef __WINTHREAD__
#define __WINTHREAD__

#include "IThread.h"
#include        <windows.h>
class WinThread :
	public IThread
{
public:
	WinThread(void);
	~WinThread(void);

  void                create(void *(*start_routine)(void *), void *arg);
  void                destroy();
  void                join();
  
private:
  HANDLE        thread;
};

#endif
#endif