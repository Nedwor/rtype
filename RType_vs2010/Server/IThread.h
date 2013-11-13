#ifndef                __ITHREAD__
#define                __ITHREAD__

class                IThread
{
public:
  virtual			  ~IThread(){};
  virtual void        create(void *(*start_routine)(void *), void *arg) = 0;
  virtual void        destroy() = 0;
  virtual void        join() = 0;
};

#endif