#pragma once
#include "Statek.h"
#include "TablicaPociskow.h"
#include "TablicaPrzeciwnikow.h"
#include "Boss.h"

class Hitbox
{
public:
	void HitboxStatekPocisk(Statek& m_statek, TablicaPociskow& m_pocisk);
	void HitboxStatekPocisk(TablicaPrzeciwnikow& m_przeciwnicy, TablicaPociskow& m_pocisk);
	void HitboxStatekStatek(Statek& m_statek, TablicaPrzeciwnikow& m_przeciwnicy);
	void HitboxStatekBoss(Statek& m_statek, Boss& m_boss);

};

