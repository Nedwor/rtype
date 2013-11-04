
#include <string>
#include <map>
#include <list>
#include <iostream>

#ifdef _WIN32
#include "WinLister.h"
#include "DlLoaderWin.h"
#endif
#ifndef _WIN32
#include "UnixLister.h"
#include "DlLoaderUnix.h"
#endif

template <typename T>
class DLManager
{
public:
	DLManager(void){};
	~DLManager(void){};
	bool LoadAllLibFromPath(std::string const  & path)
	{
	#ifdef _WIN32
		ILister *lister = new WinLister;
		std::string ext = ".dll";
	#endif
	#ifndef _WIN32
		ILister *lister = new UnixLister;
		std::string ext = ".so";
	#endif
		std::list<std::string> *list;
		std::string rpath;
		rpath = (std::string)path += "*";
		rpath += ext;
		if ((list = lister->getFileList(rpath)) == 0)
			return false;
		if (list->size() == 0)
		  return true;
		for (std::list<std::string>::iterator it = list->begin(); it != list->end();++it)
		{
				#ifdef _WIN32
					IDlLoader<T> *loader = new DlLoaderWin<T>;
				#endif
				#ifndef _WIN32
					IDlLoader<T> *loader = new DlLoaderUnix<T>;
				#endif
					if (loader->openLib((std::string)path += *it) == true)
					{
						std::cout << "Library " << *it<< " loaded." << std::endl;
						this->getName(ext, *it);
						this->map[*it] = loader;
					}
					else
						std::cout << "Library " << (std::string)*it << " not loaded." << std::endl;
		}
		return true;
	}

	T	getClass(std::string const & name, std::string const &funcName)
	{
		typename std::map<std::string, IDlLoader<T> *>::iterator it;
		it = this->map.find(name);
		if (it != this->map.end())
		{
			T instance = (map[name])->getInstance(funcName);
			return instance;
		}
		return 0;
	}
	bool closeLib(std::string const &name)
	{
		typename std::map<std::string, IDlLoader<T> *>::iterator it;
		it = this->map.find(name);
		if (it != this->map.end())
		{
			if ((map[name])->closeLib() == false)
				return false;
		}
		delete (*it).second;
		map.erase(it);
		return false;
	}
	void closeAllLib()
	{
		typename std::map<std::string, IDlLoader<T> *>::iterator it;
		it = this->map.begin();
		while (it != this->map.end())
		{
			delete (*it).second;
			this->map.erase(it++);
		}
	}
private:
	void getName(std::string const &ext, std::string &file)
	{
		int found;

		if ((found = (file.find(ext))) != std::string::npos)
		{
			file.erase(found, ext.length());
		}
	};
	std::map<std::string, IDlLoader<T> *>	map;
};

