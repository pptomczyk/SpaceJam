#pragma once
#include "Pocisk.h"
#include <vector>

using namespace std;

class TablicaPociskow
{
	Texture texturePocisk;
	Texture textureAlien;
	Texture textureGalaktyka;
	Texture textureSaturn;
public:
	

	vector<Pocisk> pociski;
	
	void Restart();
	void Dodaj(Sprite m_sprite, unsigned int m_id, Vector2f m_linia);
	void Rysuj(RenderWindow& m_okno);
	
};

