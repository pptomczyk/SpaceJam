#pragma once
#include "Przeciwnik.h"
#include "Global.h"
#include "Pocisk.h"
#include "ZdrowiePasek.h"

class Boss : public Przeciwnik
{
	Texture texture;
	Clock zegarPom;
	bool przyspieszony;

public:

	Boss();
	
	
	ZdrowiePasek HP;

	void Restart();
	void Ruch(RenderWindow& m_okno, TablicaPociskow& m_tab, Sprite m_obiekt);
	void StrzalBoss(TablicaPociskow& m_tab, Sprite m_obiekt);
	bool KolizjaScianBoss();
};

