#pragma once
#ifndef WIN32
#ifndef __UNIXTHREAD__
#define __UNIXTHREAD__
#include "IThread.h"
#include        <pthread.h>

class UnixThread :
	public IThread
{
public:
	UnixThread(void);
	~UnixThread(void){};
  void                create(void *(*start_routine)(void *), void *arg);
  void                destroy();
  void                join();
private:
	pthread_t        thread;
};

#endif
#endif