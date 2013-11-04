#ifndef __UNIXLISTER__
#define __UNIXLISTER__

#include <list>
#include <string>
#include <iostream>
#include "ILister.h"

class UnixLister : public ILister
{
 public:
  UnixLister(void);
  virtual ~UnixLister(void);
  virtual std::list<std::string> *getFileList(std::string const &path);
};

#endif
