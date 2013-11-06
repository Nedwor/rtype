#define FILENAME "config"

#include "ParsingXml.hpp"

int	main(int ac, char **av)
{
  ParsingXml *pars = new ParsingXml;
  std::string	fileName(FILENAME);
  pars->openFile("." + fileName + ".xml");
  fileName = "toto";
  std::list<std::string> *list;
  list = pars->getPlayerFriends(fileName);
  while (!list->empty())
    {
      std::cout << "friend =>" << list->front() << std::endl;
      list->pop_front();
    }
}
