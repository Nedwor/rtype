#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#include "WinLister.h"
#endif

WinLister::WinLister(void)
{
}


WinLister::~WinLister(void)
{
}

std::list<std::string> *WinLister::getFileList(std::string const &path)
{
	std::wstring str;
	int	i = 0;
	while (i != path.size())
		str[i] = path[i++];
	str[i] = '\0';

	WIN32_FIND_DATA File;
	HANDLE hSearch;
	std::string s;
	std::list<std::string > *list = new std::list<std::string>;
	int l = 0;
    hSearch = FindFirstFile(path.c_str(), &File);
    if (hSearch != INVALID_HANDLE_VALUE)
    {
		while (File.cFileName[l])
			s += (char)File.cFileName[l++];
		if ((char *)s[0] != ".")
			list->push_back(s);
		while (FindNextFile(hSearch, &File))
		{
			std::string str;
			l = 0;
			while (File.cFileName[l])
				str += (char)File.cFileName[l++];
		if ((char *)str[0] != ".")
			list->push_back(str);
		}
        FindClose(hSearch);
    }
    return list;
}
