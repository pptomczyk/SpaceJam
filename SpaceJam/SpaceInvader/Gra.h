#pragma once
#include "SFML/Graphics.hpp"
#include "Global.h"
#include "TablicaPociskow.h"
#include "TablicaPrzeciwnikow.h"
#include "Gracz.h"
#include "Boss.h"
#include "Hitbox.h"

using namespace sf;

class Gra
{
	Texture textureTlo1;
	Texture textureTlo2;
	Texture textureTlo3;
	Texture textureTlo0;

	Sprite tlo;
	
	RenderWindow okno;

	Gracz gracz;

	TablicaPrzeciwnikow przeciwnicy;

	TablicaPociskow pociskiGracza;
	TablicaPociskow pociskiPrzeciwnikow;

	Hitbox hitbox;

	Boss boss;

	Font font;

	Texture wyborW;
	Sprite wybor;

	Clock zegar;

public:
	
	
	Gra();

	void Poziom(unsigned int m_poziom);

	void Start();

	void Porazka(unsigned int m_poziom);

	void Zwyciestwo(unsigned int m_poziom);

};

