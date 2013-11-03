#include        "UnixMutex.h"

#ifndef                WIN32

UnixMutex::UnixMutex()
{ }

UnixMutex::~UnixMutex()
{ }

void        UnixMutex::init()
{
  this->mutex = PTHREAD_MUTEX_INITIALIZER;
}

void        UnixMutex::lock()
{
  pthread_mutex_lock(&(this->mutex));
}

void        UnixMutex::trylock()
{
  pthread_mutex_trylock(&(this->mutex));
}

void        UnixMutex::unlock()
{
  pthread_mutex_unlock(&mutex);
}

void        UnixMutex::destroy()
{
  pthread_mutex_destroy(&mutex);
}

#endif