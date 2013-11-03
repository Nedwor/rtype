#pragma once
#ifndef                __UNIXMUTEX__
#define                __UNIXMUTEX__

#ifndef                WIN32

#include        "IMutex.hh"
#include        <pthread.h>

class	UnixMutex : 
	public IMutex
{
public:
           UnixMutex();
           ~UnixMutex();

  void                init();
  void                lock();
  void                trylock();
  void                unlock();
  void                destroy();

private:
  pthread_mutex_t        mutex;
};

#endif

#endif
