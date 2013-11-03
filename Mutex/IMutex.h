#ifndef                __IMUTEX__
#define                __IMUTEX__

class                IMutex
{
public:
  virtual IMutex(){};
  virtual void        init() = 0;
  virtual void        lock() = 0;
  virtual void        trylock() = 0;
  virtual void        unlock() = 0;
  virtual void        destroy() = 0;
};

#endif