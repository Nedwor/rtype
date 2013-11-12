#define FILENAME "config"

#include "ParsingXml.hpp"

int	main(int ac, char **av)
{
  if (ac != 3)
    return 0;
  ParsingXml *pars = new ParsingXml;
  std::string	fileName(FILENAME);
  std::string	name(av[1]);
  pars->openFile(fileName + ".xml");
  fileName = av[2];
  pars->storeFriend(name, fileName);
  std::list<std::string> *list;
  list = pars->getPlayerFriends(name);
  while (!list->empty())
    {
      std::cout << "friend =>" << list->front() << std::endl;
      list->pop_front();
    }
}
