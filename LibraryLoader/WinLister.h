#ifndef __WINLISTER__
#define __WINLISTER__

#pragma once
#include "ILister.h"
class WinLister : public ILister
{
public:
	WinLister(void);
	virtual ~WinLister(void);
	virtual std::list<std::string> *getFileList(std::string const &path);
};
#endif

