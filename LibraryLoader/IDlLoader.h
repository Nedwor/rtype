#include <string>

template <typename T>
class IDlLoader
{
	typedef T (__cdecl *MYPROC)();
public:
	IDlLoader(){};
	virtual ~IDlLoader(){};
	virtual bool openLib(std::string const & path) = 0;
	virtual T getInstance(std::string const &name) = 0;
	virtual bool closeLib() = 0;
};