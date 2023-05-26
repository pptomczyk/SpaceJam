#pragma once
#include "PrzeciwnikTank.h"
#include "PrzeciwnikStrzelec.h"
#include "PrzeciwnikSnajper.h"


#include <vector>

using namespace std;

class TablicaPrzeciwnikow
{
	Texture textureTank;
	Texture textureStrzelec;
	Texture textureSnajper;
public:
	


	vector<Przeciwnik> przeciwnicy;

	void Restart();
	void Dodaj(int poziom);
	void Rysuj(RenderWindow& m_okno, TablicaPociskow& m_tab, Sprite m_obiekt);
	void NiesmiertelnoscPrzeciwnik();
	bool Pusto();
};

