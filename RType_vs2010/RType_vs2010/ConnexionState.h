#pragma once

#include "IGameState.h"

class ConnexionState;

typedef void (ConnexionState::*CsPtrFunc)(int);

class ConnexionState : public IGameState
{
private:
	std::stack<sf::Sprite*>						BgVec;
	sf::Texture								*Planete;
	sf::Sprite								*Background;
	sf::Music								ConnexionMusic;
	sf::Sprite								*AddrBoxS;
	sf::Texture								*AddrBoxT;
	sf::Texture								*AddrBoxHoverT;
	std::string								AddrString;
	sf::Text								*AddrText;
	sf::Sprite								*PortBoxS;
	sf::Texture								*PortBoxT;
	sf::Texture								*PortBoxHoverT;
	std::string								PortString;
	sf::Text								*PortText;
	sf::Sprite								*NameBoxS;
	sf::Texture								*NameBoxT;
	sf::Texture								*NameBoxHoverT;
	sf::Sprite								*ConnexButtonS;
	sf::Texture								*ConnexButtonT;
	sf::Texture								*ConnexButtonHoverT;
	std::string								NameString;
	sf::Text								*NameText;
	sf::Font								*font;
	t_TCPConnection						*header;
	//ISocket								*socket;
	bool								ConnexTest;
	bool								RecordAddr;
	bool								RecordPort;
	bool								RecordName;
	bool								MusicOn;
	int									i;
	std::map<sf::Keyboard::Key, CsPtrFunc>       _keyMap;

	void		addA(int);
	void		addB(int);
	void		addC(int);
	void		addD(int);
	void		addE(int);
	void		addF(int);
	void		addG(int);
	void		addH(int);
	void		addI(int);
	void		addJ(int);
	void		addK(int);
	void		addL(int);
	void		addM(int);
	void		addN(int);
	void		addO(int);
	void		addP(int);
	void		addQ(int);
	void		addR(int);
	void		addS(int);
	void		addT(int);
	void		addU(int);
	void		addV(int);
	void		addW(int);
	void		addX(int);
	void		addY(int);
	void		addZ(int);
	void		add1(int);
	void		add2(int);
	void		add3(int);
	void		add4(int);
	void		add5(int);
	void		add6(int);
	void		add7(int);
	void		add8(int);
	void		add9(int);
	void		add0(int);
	void		addPoint(int);

public:
	ConnexionState(void);
	~ConnexionState(void);

	virtual void		draw(sf::RenderWindow&);
	virtual void		execute(sf::RenderWindow&);
	void		presentation(sf::RenderWindow&);
	bool		tryToConnect();
	void		addCharToAddr(sf::Keyboard::Key);
	void		addCharToPort(sf::Keyboard::Key);
	void		addCharToName(sf::Keyboard::Key);
	void		addChar(int, char);
};