#include <iostream>

#include "ParsingXml.hpp"

ParsingXml::ParsingXml()
{
}

ParsingXml::~ParsingXml()
{
}

bool		ParsingXml::openFile(std::string fileName)
{
  if (_doc.LoadFile(fileName))
    return true;
  TiXmlElement *frd = new TiXmlElement("players"); 
  _doc.LinkEndChild(frd);
  return (_doc.SaveFile());
}

bool		ParsingXml::closeFile()
{
  //return (_doc.loadFile(name));
}

bool            ParsingXml::storeScore(std::string &playerName, int data)
{
  TiXmlElement *players = this->_doc.FirstChildElement("players");
  if (players)
    {
      unsigned int nb = 0;
      for(TiXmlElement *player = players->FirstChildElement("player"); player; player = player->NextSiblingElement("player"))
        {
	  nb++;
          if (player->Attribute("name") == playerName)
	    {
	      player->SetAttribute("score", data);
	      return _doc.SaveFile();
	    }
        }
      TiXmlElement *player = new TiXmlElement("player");
      player->SetAttribute("id", nb);
      player->SetAttribute("name", playerName);
      player->SetAttribute("score", data);
      players->LinkEndChild(player);
      return _doc.SaveFile();
    }
  return false;
}

bool            ParsingXml::storeFriend(std::string &playerName, std::string &data)
{
  TiXmlElement *players = this->_doc.FirstChildElement("players");
  if (players)
    {
      for (TiXmlElement *player = players->FirstChildElement("player"); player; player = player->NextSiblingElement("player"))
        {
          if (player->Attribute("name") == playerName)
	    {
	      for (TiXmlElement *frd = player->FirstChildElement("friend"); frd; frd = frd->NextSiblingElement("friend"))
		{
		  if (frd->Attribute("name") == data)
		    return false;
		}
	      TiXmlElement *frd = new TiXmlElement("friend");
	      frd->SetAttribute("name", data);
	      player->LinkEndChild(frd);
	      return _doc.SaveFile();
	    }
        }
    }
  return false;
}

std::string	ParsingXml::getPlayerScore(std::string &playerName)
{
  TiXmlElement *players = this->_doc.FirstChildElement("players");
  if (players)
    {
      for(TiXmlElement *player = players->FirstChildElement("player"); player; player = player->NextSiblingElement("player"))
	{
	  if (player->Attribute("name") == playerName)
	    return player->Attribute("score");
	}
    }
  return NULL;
}

std::list<std::string>	*ParsingXml::getPlayerFriends(std::string &playerName)
{
  TiXmlElement *players = this->_doc.FirstChildElement("players");
  std::list<std::string> *friends = new std::list<std::string>();
  if (players)
    {
      TiXmlElement *player;
      for(player = players->FirstChildElement("player"); player; player = player->NextSiblingElement("player"))
          if (player->Attribute("name") == playerName)
	    break;
      if (player->Attribute("name") != playerName)
	return friends;
      for(TiXmlElement *child = player->FirstChildElement("friend"); child; child = child->NextSiblingElement("friend") )
	  friends->push_back(child->Attribute("name"));
    }
  return friends;
}
