#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <stack>
#include <iostream>
#include <sstream>
//#include "WinSocket.h"
#include <windows.h>

using namespace sf;
using namespace std;

class ConnexionState;

typedef void (ConnexionState::*CsPtrFunc)(int);

class ConnexionState
{
private:
	stack<Sprite*>						BgVec;
	//ISocket								*socket;
	Texture								*Planete;
	Sprite								*Background;
	Music								ConnexionMusic;
	Sprite								*AddrBoxS;
	Sprite								*AddrBoxHoverS;
	Texture								*AddrBoxT;
	Texture								*AddrBoxHoverT;
	string								AddrString;
	Text								*AddrText;
	Sprite								*PortBoxS;
	Sprite								*PortBoxHoverS;
	Texture								*PortBoxT;
	Texture								*PortBoxHoverT;
	string								PortString;
	Text								*PortText;
	Sprite								*NameBoxS;
	Sprite								*NameBoxHoverS;
	Texture								*NameBoxT;
	Texture								*NameBoxHoverT;
	string								NameString;
	Text								*NameText;
	Font								*font;
	bool								RecordAddr;
	bool								RecordPort;
	bool								RecordName;
	bool								MusicOn;
	int									i;
	map<Keyboard::Key, CsPtrFunc>       _keyMap;

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

	void		Draw(RenderWindow*);
	void		Presentation(RenderWindow*);
	void		addCharToAddr(Keyboard::Key);
	void		addCharToPort(Keyboard::Key);
	void		addCharToName(Keyboard::Key);
	void		addChar(int, char);
};