#pragma once
#include <SFML/Graphics.hpp>
#include "Global.h"
#include <math.h>



using namespace sf;

class Pocisk
{
	Texture texture;
	Vector2f xy;

	float predkosc_y;
	float predkosc_x;

	Clock time;

public:

	unsigned int typPocisku;
	Sprite obiektPocisk;

	Pocisk(Sprite m_sprite, unsigned int m_id, Vector2f m_linia);

	~Pocisk();

	void Ruch();
	void Rysuj(RenderWindow& m_okno);


	bool KolizjaScian();
	
};

