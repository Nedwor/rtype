#ifndef __IDLLOADER__
#define __IDLLOADER__

#include <string>

template <typename T>
class IDlLoader
{
#ifdef _WIN32
  typedef T (__cdecl *MYPROC)();
#endif
#ifndef _WIN32
  typedef T (*ptr)();
#endif
public:
	IDlLoader(){};
	virtual ~IDlLoader(){};
	virtual bool openLib(std::string const & path) = 0;
	virtual T getInstance(std::string const &name) = 0;
	virtual bool closeLib() = 0;
};

#endif
