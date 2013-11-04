#include <stdio.h>
#include <string.h>
#include "UnixLister.h"
#ifndef _WIN32
#include <glob.h>


UnixLister::UnixLister(void) {}

UnixLister::~UnixLister(void) {}

std::list<std::string> *UnixLister::getFileList(std::string const &path)
{
  std::list<std::string> *list = new std::list<std::string>;

  glob_t g;
  glob(path.c_str(), 0, NULL, &g);
  unsigned int i;
  for (i = 0; i < g.gl_pathc; i++)
    {
      std::string str(g.gl_pathv[i]);
      int pos = str.size();
      for (; pos > 0 && str[pos] != '/'; pos--);
      if (pos != 0)
	str.replace(0, pos + 1, "");
      list->push_back(str);

    }
  return list;
}

#endif