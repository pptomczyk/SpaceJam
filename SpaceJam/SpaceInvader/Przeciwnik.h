#pragma once
#include "Statek.h"
#include "TablicaPociskow.h"
#include <random>

class Przeciwnik : public Statek
{
public:
	
	Przeciwnik(float m_przeladowanie,unsigned int m_zdrowie, unsigned int m_id);

	void Ruch(RenderWindow& m_okno, TablicaPociskow& m_tab, Sprite m_obiekt);
	
};

