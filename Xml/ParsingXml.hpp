#include <iostream>
#include <list>

#include "tinyxml.h"

class ParsingXml
{
  TiXmlDocument _doc;
public:
  ParsingXml();
  ~ParsingXml();
  bool				openFile(std::string fileName);
  bool				closeFile();
  bool				storeScore(std::string &playerName, int data);
  bool				storeFriend(std::string &playerName, std::string &data);
  std::string			getPlayerScore(std::string &playerName);
  std::list<std::string>	*getPlayerFriends(std::string &playerName);
};
