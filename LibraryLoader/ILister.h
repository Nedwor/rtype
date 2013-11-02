#ifndef __ILISTER__
#define __ILISTER__

#include <list>
#include <string>

class ILister
{
public:
	ILister(){};
	virtual ~ILister(){};
	virtual std::list<std::string> *getFileList(std::string const &path) = 0;
};
#endif