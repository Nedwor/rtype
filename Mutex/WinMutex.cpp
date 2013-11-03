#include "WinMutex.h"

#ifdef                WIN32

WinMutex::WinMutex()
{ }

WinMutex::~WinMutex()
{ }

void        WinMutex::init()
{
  InitializeCriticalSection(&(this->criticalSection));
}

void        WinMutex::lock()
{
  EnterCriticalSection(&(this->criticalSection));
}

void        WinMutex::trylock()
{
  TryEnterCriticalSection(&(this->criticalSection));
}

void        WinMutex::unlock()
{
  LeaveCriticalSection(&(this->criticalSection));
}

void        WinMutex::destroy()
{
  DeleteCriticalSection(&(this->criticalSection));
}

#endif
