#include "ConnexionState.h"

ConnexionState::ConnexionState()
{
	this->_keyMap[Keyboard::A] = &ConnexionState::addA;
	this->_keyMap[Keyboard::B] = &ConnexionState::addB;
	this->_keyMap[Keyboard::C] = &ConnexionState::addC;
	this->_keyMap[Keyboard::D] = &ConnexionState::addD;
	this->_keyMap[Keyboard::E] = &ConnexionState::addE;
	this->_keyMap[Keyboard::F] = &ConnexionState::addF;
	this->_keyMap[Keyboard::G] = &ConnexionState::addG;
	this->_keyMap[Keyboard::H] = &ConnexionState::addH;
	this->_keyMap[Keyboard::I] = &ConnexionState::addI;
	this->_keyMap[Keyboard::J] = &ConnexionState::addJ;
	this->_keyMap[Keyboard::K] = &ConnexionState::addK;
	this->_keyMap[Keyboard::L] = &ConnexionState::addL;
	this->_keyMap[Keyboard::M] = &ConnexionState::addM;
	this->_keyMap[Keyboard::N] = &ConnexionState::addN;
	this->_keyMap[Keyboard::O] = &ConnexionState::addO;
	this->_keyMap[Keyboard::P] = &ConnexionState::addP;
	this->_keyMap[Keyboard::Q] = &ConnexionState::addQ;
	this->_keyMap[Keyboard::R] = &ConnexionState::addR;
	this->_keyMap[Keyboard::S] = &ConnexionState::addS;
	this->_keyMap[Keyboard::T] = &ConnexionState::addT;
	this->_keyMap[Keyboard::U] = &ConnexionState::addU;
	this->_keyMap[Keyboard::V] = &ConnexionState::addV;
	this->_keyMap[Keyboard::W] = &ConnexionState::addW;
	this->_keyMap[Keyboard::X] = &ConnexionState::addD;
	this->_keyMap[Keyboard::Y] = &ConnexionState::addY;
	this->_keyMap[Keyboard::Z] = &ConnexionState::addZ;
	this->_keyMap[Keyboard::Num1] = &ConnexionState::add1;
	this->_keyMap[Keyboard::Num2] = &ConnexionState::add2;
	this->_keyMap[Keyboard::Num3] = &ConnexionState::add3;
	this->_keyMap[Keyboard::Num4] = &ConnexionState::add4;
	this->_keyMap[Keyboard::Num5] = &ConnexionState::add5;
	this->_keyMap[Keyboard::Num6] = &ConnexionState::add6;
	this->_keyMap[Keyboard::Num7] = &ConnexionState::add7;
	this->_keyMap[Keyboard::Num8] = &ConnexionState::add8;
	this->_keyMap[Keyboard::Num9] = &ConnexionState::add9;
	this->_keyMap[Keyboard::Num0] = &ConnexionState::add0;
	this->_keyMap[Keyboard::Numpad1] = &ConnexionState::add1;
	this->_keyMap[Keyboard::Numpad2] = &ConnexionState::add2;
	this->_keyMap[Keyboard::Numpad3] = &ConnexionState::add3;
	this->_keyMap[Keyboard::Numpad4] = &ConnexionState::add4;
	this->_keyMap[Keyboard::Numpad5] = &ConnexionState::add5;
	this->_keyMap[Keyboard::Numpad6] = &ConnexionState::add6;
	this->_keyMap[Keyboard::Numpad7] = &ConnexionState::add7;
	this->_keyMap[Keyboard::Numpad8] = &ConnexionState::add8;
	this->_keyMap[Keyboard::Numpad9] = &ConnexionState::add9;
	this->_keyMap[Keyboard::Numpad0] = &ConnexionState::add0;
	this->_keyMap[Keyboard::Period] = &ConnexionState::addPoint;

	this->ConnexionMusic.openFromFile("..\\..\\..\\ConnexionSong.wav");
	this->font = new Font;
	this->MusicOn = false;

	this->AddrText = new Text;
	this->AddrBoxT = new Texture;
	this->AddrBoxS = new Sprite;
	this->RecordAddr = false;

	this->PortText = new Text;
	this->PortBoxT = new Texture;
	this->PortBoxS = new Sprite;
	this->RecordPort = false;

	this->NameText = new Text;
	this->NameBoxT = new Texture;
	this->NameBoxS = new Sprite;
	this->RecordName = false;
	this->font->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\bitlow.ttf");
	//TODO (pouvoir changer la taille de la fenetre )

	this->AddrBoxS->setPosition((1024 / 2) - 250, ((763 / 3) * 2) - 51);
	this->AddrText->setPosition(((1024 / 2) - 250) + 20, ((763 / 3) * 2) - 46);
	this->AddrText->setCharacterSize(25);
	this->AddrText->setColor(Color::White);
	this->AddrText->setFont(*this->font);
	this->AddrBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxAddr.jpg");
	this->AddrBoxS->setTexture(*this->AddrBoxT, false);

	this->PortBoxS->setPosition((1024 / 2) + 100, ((763 / 3) * 2) - 51);
	this->PortText->setPosition(((1024 / 2) + 100) + 20, ((763 / 3) * 2) - 47);
	this->PortText->setCharacterSize(25);
	this->PortText->setColor(Color::White);
	this->PortText->setFont(*this->font);
	this->PortBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxPort.jpg");
	this->PortBoxS->setTexture(*this->PortBoxT, false);

	this->NameBoxS->setPosition((1024 / 2) - 250, ((763 / 3) * 2) + 6);
	this->NameText->setPosition(((1024 / 2) - 250) + 20, ((763 / 3) * 2) + 10);
	this->NameText->setCharacterSize(25);
	this->NameText->setColor(Color::White);
	this->NameText->setFont(*this->font);
	this->NameBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxName.jpg");							  
	this->NameBoxS->setTexture(*this->NameBoxT, false);
}

void	ConnexionState::Presentation(RenderWindow *window)
{
	this->Planete = new Texture;
	this->Background = new Sprite;
	i = 1;
	this->ConnexionMusic.play();
	while (i <= 24)
	{
		ostringstream	oss;
		string			res;
		oss << i;
		res = oss.str();
		this->Planete->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\BackgroundConnexion" + res + ".jpg");
		this->Background->setTexture(*this->Planete, false);
		window->draw(*this->Background);
		window->display();
		i++;
		Sleep(500);
	}
}

void	ConnexionState::Draw(RenderWindow *window)
{
	Sleep(75);
	Vector2i MousePos = Mouse::getPosition(*window);
	IntRect AddrRect(this->AddrBoxS->getPosition().x, this->AddrBoxS->getPosition().y, this->AddrBoxS->getLocalBounds().width, this->AddrBoxS->getLocalBounds().height);
	IntRect PortRect(this->PortBoxS->getPosition().x, this->PortBoxS->getPosition().y, this->PortBoxS->getLocalBounds().width, this->PortBoxS->getLocalBounds().height);
	IntRect NameRect(this->NameBoxS->getPosition().x, this->NameBoxS->getPosition().y, this->NameBoxS->getLocalBounds().width, this->NameBoxS->getLocalBounds().height);
	if (Keyboard::isKeyPressed(Keyboard::Tab) || Keyboard::isKeyPressed(Keyboard::Escape) || Keyboard::isKeyPressed(Keyboard::Return))
	{
		this->RecordAddr = false;
		this->RecordPort = false;
		this->RecordName = false;
	}
	if (AddrRect.contains(MousePos))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
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
		if (Mouse::isButtonPressed(Mouse::Left))
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
		if (Mouse::isButtonPressed(Mouse::Left))
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
		if (Keyboard::isKeyPressed(Keyboard::BackSpace) == true && this->AddrString.size() > 0)
			this->AddrString.replace(this->AddrString.size() - 1, 1, "\0");
		for (int c = 0; c < Keyboard::KeyCount; ++c)
			if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(c)) && this->AddrString.size() < 16)
			{
				this->addCharToAddr(static_cast<Keyboard::Key>(c));
				this->AddrText->setString(this->AddrString);
			}
	}
	else
	{
		if (this->AddrString.size() == 0)
			this->AddrBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxAddr.jpg");
	}
	if (this->RecordPort)
	{
		if (Keyboard::isKeyPressed(Keyboard::BackSpace) == true && this->PortString.size() > 0)
			this->PortString.replace(this->PortString.size() - 1, 1, "\0");
		for (int c = 0; c < Keyboard::KeyCount; ++c)
			if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(c)) && this->PortString.size() < 5)
			{
				this->addCharToPort(static_cast<Keyboard::Key>(c));
				this->PortText->setString(this->PortString);
			}
	}
	else
	{
	if (this->PortString.size() == 0)
			this->PortBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxPort.jpg");
	}
	if (this->RecordName)
	{
		if (Keyboard::isKeyPressed(Keyboard::BackSpace) == true && this->NameString.size() > 0)
			this->NameString.replace(this->NameString.size() - 1, 1, "\0");
		for (int c = 0; c < Keyboard::KeyCount; ++c)
			if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(c)) && this->NameString.size() < 5)
			{
				this->addCharToName(static_cast<Keyboard::Key>(c));
				this->NameText->setString(this->NameString);
			}
	}
	else
	{
		if (this->NameString.size() == 0)
			this->NameBoxT->loadFromFile("..\\Release\\ressources\\PresentationConnexion\\TextBoxName.jpg");
	}
	window->draw(*this->Background);
	window->draw(*this->AddrBoxS);
	window->draw(*this->PortBoxS);
	window->draw(*this->NameBoxS);
	window->draw(*this->AddrText);
	window->draw(*this->PortText);
	window->draw(*this->NameText);
}

void	ConnexionState::addCharToAddr(Keyboard::Key key)
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

void	ConnexionState::addCharToPort(Keyboard::Key key)
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

void	ConnexionState::addCharToName(Keyboard::Key key)
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
