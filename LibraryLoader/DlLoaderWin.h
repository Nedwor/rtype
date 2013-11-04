#pragma once
#include <windows.h>
#include <stdio.h>
#include "IDlLoader.h"

template <typename T>
class DlLoaderWin : public IDlLoader<T>
{
typedef T (__cdecl *MYPROC)();
public:
	DlLoaderWin(void){};
	virtual ~DlLoaderWin(void){};
	bool openLib(std::string const & path)
	{
		std::string str;
		int	i = 0;
		while (i != path.size())
			str += path[i++];
		if ((this->hinstLib = LoadLibrary(path.c_str())) == NULL)
			return false;
		return true;
	};
	T getInstance(std::string const &name)
	{
		MYPROC ret;
		if ((ret = (MYPROC)GetProcAddress(this->hinstLib, name.c_str())) == NULL)
			return NULL;
		return (ret)();
	};
	bool closeLib()
	{
		if (FreeLibrary(this->hinstLib) == 0)
			return false;
		return true;
	};
private:
	HINSTANCE hinstLib;
};

