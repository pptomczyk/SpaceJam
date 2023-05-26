#pragma once
#include "Statek.h"
#include "TablicaPociskow.h"
#include "ZdrowiePasek.h"

class Gracz : public Statek
{
	Texture texture;
public:
	
	ZdrowiePasek HP;

	Gracz();

	void Restart();
	void Ruch(RenderWindow& m_okno, TablicaPociskow& m_tab);
	
};

