#ifndef __DLLOADERUNIX__
#define __DLLOADERUNIX__
#ifndef _WIN32

#include <string>
#include <iostream>
#include <dlfcn.h>
#include "IDlLoader.h"

template <typename T>
class	DlLoaderUnix : public IDlLoader<T>
{
  typedef T (*ptr_t)();
public:
  DlLoaderUnix() {}
  virtual ~DlLoaderUnix() {}
  bool openLib(std::string const & path) { void *dlhandle;
    dlhandle = dlopen(path.c_str(), RTLD_LAZY);
    if (dlhandle == NULL) {
      std::cerr << "dlopen " << std::endl;
      return false;
    }
    if (dlerror()) {
      std::cerr << "dlerror" << std::endl;
      return false;
    }
    this->_dlhandle = dlhandle;
    return true;
  }
  T	getInstance(std::string const &name) { ptr_t ptr;
    if ((ptr = reinterpret_cast<ptr_t>(dlsym(this->_dlhandle, name.c_str()))) == NULL) {
      std::cerr << "Error on dlsym." << std::endl;
      return NULL;
    }
    return ptr();
  }
  bool	closeLib() {
    if (dlclose(this->_dlhandle) == 0)
      return true;
    return false;
  }
private:
  void *_dlhandle;
};

#endif
#endif
