#pragma once
#include "SFML/Graphics.hpp"
#include "Global.h"


using namespace sf;

class ZdrowiePasek
{
	Sprite pasekZdrowia;
	Texture textureGracz;
	Texture textureBoss;
	unsigned int poziomHP;
	RectangleShape HP;
public:



	ZdrowiePasek(int m_id);
	void RysujGracz(RenderWindow& m_okno, unsigned int m_poziomHP);

	void RysujBoss(RenderWindow& m_okno, unsigned int m_poziomHP);
};

