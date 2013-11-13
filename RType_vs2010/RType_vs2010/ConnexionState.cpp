#include "ConnexionState.h"

ConnexionState::ConnexionState()
	:_frames(0), _lastKey(sf::Keyboard::Unknown), _testKey(0)
{
	this->_keyMap[sf::Keyboard::A] = &ConnexionState::addA;
	this->_keyMap[sf::Keyboard::B] = &ConnexionState::addB;
	this->_keyMap[sf::Keyboard::C] = &ConnexionState::addC;
	this->_keyMap[sf::Keyboard::D] = &ConnexionState::addD;
	this->_keyMap[sf::Keyboard::E] = &ConnexionState::addE;
	this->_keyMap[sf::Keyboard::F] = &ConnexionState::addF;
	this->_keyMap[sf::Keyboard::G] = &ConnexionState::addG;
	this->_keyMap[sf::Keyboard::H] = &ConnexionState::addH;
	this->_keyMap[sf::Keyboard::I] = &ConnexionState::addI;
	this->_keyMap[sf::Keyboard::J] = &ConnexionState::addJ;
	this->_keyMap[sf::Keyboard::K] = &ConnexionState::addK;
	this->_keyMap[sf::Keyboard::L] = &ConnexionState::addL;
	this->_keyMap[sf::Keyboard::M] = &ConnexionState::addM;
	this->_keyMap[sf::Keyboard::N] = &ConnexionState::addN;
	this->_keyMap[sf::Keyboard::O] = &ConnexionState::addO;
	this->_keyMap[sf::Keyboard::P] = &ConnexionState::addP;
	this->_keyMap[sf::Keyboard::Q] = &ConnexionState::addQ;
	this->_keyMap[sf::Keyboard::R] = &ConnexionState::addR;
	this->_keyMap[sf::Keyboard::S] = &ConnexionState::addS;
	this->_keyMap[sf::Keyboard::T] = &ConnexionState::addT;
	this->_keyMap[sf::Keyboard::U] = &ConnexionState::addU;
	this->_keyMap[sf::Keyboard::V] = &ConnexionState::addV;
	this->_keyMap[sf::Keyboard::W] = &ConnexionState::addW;
	this->_keyMap[sf::Keyboard::X] = &ConnexionState::addD;
	this->_keyMap[sf::Keyboard::Y] = &ConnexionState::addY;
	this->_keyMap[sf::Keyboard::Z] = &ConnexionState::addZ;
	this->_keyMap[sf::Keyboard::Num1] = &ConnexionState::add1;
	this->_keyMap[sf::Keyboard::Num2] = &ConnexionState::add2;
	this->_keyMap[sf::Keyboard::Num3] = &ConnexionState::add3;
	this->_keyMap[sf::Keyboard::Num4] = &ConnexionState::add4;
	this->_keyMap[sf::Keyboard::Num5] = &ConnexionState::add5;
	this->_keyMap[sf::Keyboard::Num6] = &ConnexionState::add6;
	this->_keyMap[sf::Keyboard::Num7] = &ConnexionState::add7;
	this->_keyMap[sf::Keyboard::Num8] = &ConnexionState::add8;
	this->_keyMap[sf::Keyboard::Num9] = &ConnexionState::add9;
	this->_keyMap[sf::Keyboard::Num0] = &ConnexionState::add0;
	this->_keyMap[sf::Keyboard::Numpad1] = &ConnexionState::add1;
	this->_keyMap[sf::Keyboard::Numpad2] = &ConnexionState::add2;
	this->_keyMap[sf::Keyboard::Numpad3] = &ConnexionState::add3;
	this->_keyMap[sf::Keyboard::Numpad4] = &ConnexionState::add4;
	this->_keyMap[sf::Keyboard::Numpad5] = &ConnexionState::add5;
	this->_keyMap[sf::Keyboard::Numpad6] = &ConnexionState::add6;
	this->_keyMap[sf::Keyboard::Numpad7] = &ConnexionState::add7;
	this->_keyMap[sf::Keyboard::Numpad8] = &ConnexionState::add8;
	this->_keyMap[sf::Keyboard::Numpad9] = &ConnexionState::add9;
	this->_keyMap[sf::Keyboard::Numpad0] = &ConnexionState::add0;
	this->_keyMap[sf::Keyboard::Period] = &ConnexionState::addPoint;

	this->ConnexionMusic.openFromFile("..\\..\\..\\ConnexionSong.wav");
	this->font = new sf::Font;
	this->MusicOn = false;

	this->ConnexButtonT = new sf::Texture;
	this->ConnexButtonS = new sf::Sprite;

	this->AddrText = new sf::Text;
	this->AddrBoxT = new sf::Texture;
	this->AddrBoxS = new sf::Sprite;
	this->RecordAddr = false;

	this->PortText = new sf::Text;
	this->PortBoxT = new sf::Texture;
	this->PortBoxS = new sf::Sprite;
	this->RecordPort = false;

	this->NameText = new sf::Text;
	this->NameBoxT = new sf::Texture;
	this->NameBoxS = new sf::Sprite;
	this->RecordName = false;
	this->font->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\bitlow.ttf");
	//TODO (pouvoir changer la taille de la fenetre )

	this->AddrBoxS->setPosition((1024 / 2) - 250, ((763 / 3) * 2) - 51);
	this->AddrText->setPosition(((1024 / 2) - 250) + 20, ((763 / 3) * 2) - 46);
	this->AddrText->setCharacterSize(25);
	this->AddrText->setColor(sf::Color::White);
	this->AddrText->setFont(*this->font);
	this->AddrBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxAddr.jpg");
	this->AddrBoxS->setTexture(*this->AddrBoxT, false);

	this->PortBoxS->setPosition((1024 / 2) + 100, ((763 / 3) * 2) - 51);
	this->PortText->setPosition(((1024 / 2) + 100) + 20, ((763 / 3) * 2) - 47);
	this->PortText->setCharacterSize(25);
	this->PortText->setColor(sf::Color::White);
	this->PortText->setFont(*this->font);
	this->PortBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxPort.jpg");
	this->PortBoxS->setTexture(*this->PortBoxT, false);

	this->NameBoxS->setPosition((1024 / 2) - 250, ((763 / 3) * 2) + 6);
	this->NameText->setPosition(((1024 / 2) - 250) + 20, ((763 / 3) * 2) + 10);
	this->NameText->setCharacterSize(25);
	this->NameText->setColor(sf::Color::White);
	this->NameText->setFont(*this->font);
	this->NameBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxName.jpg");							  
	this->NameBoxS->setTexture(*this->NameBoxT, false);

	this->ConnexButtonS->setPosition((1024 / 2) - 100, ((763 / 3) * 2) + 100);
	this->ConnexButtonT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\ButtonConnex.jpg");							  
	this->ConnexButtonS->setTexture(*this->ConnexButtonT, false);

	#ifdef _WIN32
		//socket = new WinSocket;
		WSADATA WSAData;
		WSAStartup(MAKEWORD(2,0), &WSAData);
	#endif
		this->_isclicked = false;
}

void	ConnexionState::presentation(sf::RenderWindow& window)
{
	this->Planete = new sf::Texture;
	this->Background = new sf::Sprite;
	i = 1;
//	this->ConnexionMusic.play();
	while (i <= 24)
	{
		std::ostringstream	oss;
		std::string			res;
		oss << i;
		res = oss.str();
		this->Planete->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\BackgroundConnexion" + res + ".jpg");
		this->Background->setTexture(*this->Planete, false);
		window.draw(*this->Background);
		window.display();
		i++;
		Sleep(500);
	}
}

void		ConnexionState::draw(sf::RenderWindow& window)
{
	window.draw(*this->Background);
	window.draw(*this->AddrBoxS);
	window.draw(*this->PortBoxS);
	window.draw(*this->NameBoxS);
	window.draw(*this->ConnexButtonS);
	window.draw(*this->AddrText);
	window.draw(*this->PortText);
	window.draw(*this->NameText);
}

void	ConnexionState::execute(sf::RenderWindow& window)
{
	if (this->_frames <= 2)
	{
		this->_frames += 1;
		return;
	}
	this->_frames = 0;
	sf::Vector2i MousePos = sf::Mouse::getPosition(window);
	sf::IntRect AddrRect(this->AddrBoxS->getPosition().x, this->AddrBoxS->getPosition().y, this->AddrBoxS->getLocalBounds().width, this->AddrBoxS->getLocalBounds().height);
	sf::IntRect PortRect(this->PortBoxS->getPosition().x, this->PortBoxS->getPosition().y, this->PortBoxS->getLocalBounds().width, this->PortBoxS->getLocalBounds().height);
	sf::IntRect NameRect(this->NameBoxS->getPosition().x, this->NameBoxS->getPosition().y, this->NameBoxS->getLocalBounds().width, this->NameBoxS->getLocalBounds().height);
	sf::IntRect ConnexRect(this->ConnexButtonS->getPosition().x, this->ConnexButtonS->getPosition().y, this->ConnexButtonS->getLocalBounds().width, this->ConnexButtonS->getLocalBounds().height);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		this->RecordAddr = false;
		this->RecordPort = false;
		this->RecordName = false;
	}
	if (ConnexRect.contains(MousePos))
	{
		this->ConnexButtonT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\ButtonConnexHover.jpg");
		this->ConnexButtonS->setTexture(*this->ConnexButtonT, false);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->_isclicked == false)
		{
			this->_isclicked = true;
			std::stringstream ss;
			short Port;
			ss << this->PortString;
			ss >> Port;
	#ifdef _WIN32
			this->_socket = new WinSocket;
	#endif
	#ifndef _WIN32
			this->_socket = new WinSocket;
	#endif
			t_TCPConnection Connection;

			Connection.header.type = CONNECTION;
			Connection.header.packetSize = sizeof(Connection);
			char buf[1025];
			int i = 0;
			while (this->NameString[i])
				Connection.name[i] = this->NameString[i++];
			std::cout << Connection.name << std::endl;
			this->ConnexTest = this->_socket->connectToServer(this->AddrString, Port);
			this->_socket->sendBinary(&Connection, sizeof(Connection));
			this->_socket->recBinary(&buf, sizeof(Connection.header));
			t_TCPHeader *header;
			header = (t_TCPHeader *)buf;
			if (header->type == PACKET_ERROR)
			{
				std::cout << "Error during loging" << std::endl;
				this->_isclicked = false;
			}
			else if (header->type = ESTABLISHED)
			{
				t_TCPCreate cr;

				std::cout << "Creating" << std::endl;
				cr.header.type = CREATE_GAME;
				cr.header.packetSize = sizeof(cr);
				cr.nb_max = 4;
				this->_socket->sendBinary(&cr, sizeof(cr));
			}
				std::cout << "Successfully logged" << std::endl;
			std::string buffer;
			if (this->ConnexTest == false)
				std::cout << "loooooool" << std::endl;
			else
				std::cout << "ok" << std::endl;
		}
	}
	else
	{
		this->ConnexButtonT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\ButtonConnex.jpg");
		this->ConnexButtonS->setTexture(*this->ConnexButtonT, false);
	}
	if (AddrRect.contains(MousePos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->AddrBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxAddrClicked.jpg");
			this->AddrBoxS->setTexture(*this->AddrBoxT, false);
			this->RecordAddr = true;
			this->RecordPort = false;
			this->RecordName = false;
		}
	}
	if (PortRect.contains(MousePos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->PortBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxPortClicked.jpg");
			this->PortBoxS->setTexture(*this->PortBoxT, false);
			this->RecordPort = true;
			this->RecordAddr = false;
			this->RecordName = false;
		}
	}
	if (NameRect.contains(MousePos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->NameBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxNameClicked.jpg");
			this->NameBoxS->setTexture(*this->NameBoxT, false);
			this->RecordName = true;
			this->RecordAddr = false;
			this->RecordPort = false;
		}
	}
	if (this->RecordAddr)
	{
		if (sf::Keyboard::isKeyPressed(this->_lastKey) == false || this->_testKey > 0 || sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) == true)
		{
			this->_testKey = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) == true && this->AddrString.size() > 0)
				this->AddrString.replace(this->AddrString.size() - 1, 1, "\0");
			for (int c = 0; c < sf::Keyboard::KeyCount; ++c)
				if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(c)) && this->AddrString.size() < 16)
				{
					this->_lastKey = static_cast<sf::Keyboard::Key>(c);
					this->addCharToAddr(static_cast<sf::Keyboard::Key>(c));
					this->AddrText->setString(this->AddrString);
				}
		}
		else
			this->_testKey += 1;
	}
	else
	{
		if (this->AddrString.size() == 0)
			this->AddrBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxAddr.jpg");
	}
	if (this->RecordPort)
	{
		if (sf::Keyboard::isKeyPressed(this->_lastKey) == false || this->_testKey > 0 || sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) == true)
		{
			this->_testKey = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) == true && this->PortString.size() > 0)
				this->PortString.replace(this->PortString.size() - 1, 1, "\0");
			for (int c = 0; c < sf::Keyboard::KeyCount; ++c)
				if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(c)) && this->PortString.size() < 5)
				{
					this->_lastKey = static_cast<sf::Keyboard::Key>(c);
					this->addCharToPort(static_cast<sf::Keyboard::Key>(c));
					this->PortText->setString(this->PortString);
				}
		}
		else
			this->_testKey += 1;
	}
	else
	{
	if (this->PortString.size() == 0)
			this->PortBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxPort.jpg");
	}
	if (this->RecordName)
	{
		if (sf::Keyboard::isKeyPressed(this->_lastKey) == false || this->_testKey > 0 || sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) == true)
		{
			this->_testKey = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) == true && this->NameString.size() > 0)
				this->NameString.replace(this->NameString.size() - 1, 1, "\0");
			for (int c = 0; c < sf::Keyboard::KeyCount; ++c)
				if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(c)) && this->NameString.size() < 5)
				{
					this->_lastKey = static_cast<sf::Keyboard::Key>(c);
					this->addCharToName(static_cast<sf::Keyboard::Key>(c));
					this->NameText->setString(this->NameString);
				}
		}
		else
			this->_testKey += 1;
	}
	else
	{
		if (this->NameString.size() == 0)
			this->NameBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxName.jpg");
	}
}

void	ConnexionState::addCharToAddr(sf::Keyboard::Key key)
{
  CsPtrFunc ptr;

  if (this->_keyMap.find(key) != this->_keyMap.end())
    {
      ptr = this->_keyMap[key];
      (*this.*ptr)(1);
    }
  else
    return;
}

void	ConnexionState::addCharToPort(sf::Keyboard::Key key)
{
  CsPtrFunc ptr;

  if (this->_keyMap.find(key) != this->_keyMap.end())
    {
      ptr = this->_keyMap[key];
      (*this.*ptr)(2);
    }
  else
    return;
}

void	ConnexionState::addCharToName(sf::Keyboard::Key key)
{
  CsPtrFunc ptr;

  if (this->_keyMap.find(key) != this->_keyMap.end())
    {
      ptr = this->_keyMap[key];
      (*this.*ptr)(3);
    }
  else
    return;
}

void	ConnexionState::addChar(int box, char c)
{
  if (box == 1)
    this->AddrString.push_back(c);
  else if (box == 2)
	this->PortString.push_back(c);
  else if (box == 3)
	this->NameString.push_back(c);
}

void ConnexionState::addA(int i)
{
  this->addChar(i, 'A');
}

void ConnexionState::addB(int i)
{
  this->addChar(i, 'B');
}

void ConnexionState::addC(int i)
{
  this->addChar(i, 'C');
}

void ConnexionState::addD(int i)
{
  this->addChar(i, 'D');
}

void ConnexionState::addE(int i)
{
  this->addChar(i, 'E');
}

void ConnexionState::addF(int i)
{
  this->addChar(i, 'F');
}

void ConnexionState::addG(int i)
{
  this->addChar(i, 'G');
}

void ConnexionState::addH(int i)
{
  this->addChar(i, 'H');
}

void ConnexionState::addI(int i)
{
  this->addChar(i, 'I');
}

void ConnexionState::addJ(int i)
{
  this->addChar(i, 'J');
}

void ConnexionState::addK(int i)
{
  this->addChar(i, 'K');
}

void ConnexionState::addL(int i)
{
  this->addChar(i, 'L');
}

void ConnexionState::addM(int i)
{
  this->addChar(i, 'M');
}

void ConnexionState::addN(int i)
{
  this->addChar(i, 'N');
}

void ConnexionState::addO(int i)
{
  this->addChar(i, 'O');
}

void ConnexionState::addP(int i)
{
  this->addChar(i, 'P');
}

void ConnexionState::addQ(int i)
{
  this->addChar(i, 'Q');
}

void ConnexionState::addR(int i)
{
  this->addChar(i, 'R');
}

void ConnexionState::addS(int i)
{
  this->addChar(i, 'S');
}

void ConnexionState::addT(int i)
{
  this->addChar(i, 'T');
}

void ConnexionState::addU(int i)
{
  this->addChar(i, 'U');
}

void ConnexionState::addV(int i)
{
  this->addChar(i, 'V');
}

void ConnexionState::addW(int i)
{
  this->addChar(i, 'W');
}

void ConnexionState::addX(int i)
{
  this->addChar(i, 'X');
}

void ConnexionState::addY(int i)
{
  this->addChar(i, 'Y');
}

void ConnexionState::addZ(int i)
{
  this->addChar(i, 'Z');
}

void ConnexionState::add1(int i)
{
  this->addChar(i, '1');
}

void ConnexionState::add2(int i)
{
  this->addChar(i, '2');
}

void ConnexionState::add3(int i)
{
  this->addChar(i, '3');
}

void ConnexionState::add4(int i)
{
  this->addChar(i, '4');
}

void ConnexionState::add5(int i)
{
  this->addChar(i, '5');
}

void ConnexionState::add6(int i)
{
  this->addChar(i, '6');
}

void ConnexionState::add7(int i)
{
  this->addChar(i, '7');
}

void ConnexionState::add8(int i)
{
  this->addChar(i, '8');
}

void ConnexionState::add9(int i)
{
  this->addChar(i, '9');
}

void ConnexionState::add0(int i)
{
  this->addChar(i, '0');
}

void ConnexionState::addPoint(int i)
{
  this->addChar(i, '.');
}

ConnexionState::~ConnexionState(void)
{
}
