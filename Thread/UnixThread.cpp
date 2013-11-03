#ifndef WIN32

#include "UnixThread.h"


UnixThread::UnixThread()
{
}

UnixThread::~UnixThread()
{ }

void        UnixThread::create(void *(*start_routine)(void *), void *arg)
{
  pthread_create(&(this->thread), NULL, start_routine, arg);
}

void        UnixThread::destroy(void)
{
  pthread_cancel(this->thread);
}

void        UnixThread::join(void)
{
  pthread_join(this->thread, NULL);
}

#endif