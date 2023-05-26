#include "Hitbox.h"

void Hitbox::HitboxStatekPocisk(Statek& m_statek, TablicaPociskow& m_pociski)
{

	for (int i = 0; i < m_pociski.pociski.size(); i++)
	{
		if (m_pociski.pociski[i].obiektPocisk.getGlobalBounds().intersects(m_statek.statekObiekt.getGlobalBounds()))
		{
			
			m_pociski.pociski.erase(m_pociski.pociski.begin() + i);
		
			m_statek.Obrazenia();
			
			
		}
	}
}

void Hitbox::HitboxStatekPocisk(TablicaPrzeciwnikow& m_przeciwnicy, TablicaPociskow& m_pociski)
{
	for (int j = 0; j < m_przeciwnicy.przeciwnicy.size(); j++)
	{
		for (int i = 0; i < m_pociski.pociski.size(); i++)
		{
			if (m_pociski.pociski[i].obiektPocisk.getGlobalBounds().intersects(m_przeciwnicy.przeciwnicy[j].statekObiekt.getGlobalBounds()))
			{

				m_pociski.pociski.erase(m_pociski.pociski.begin() + i);

				m_przeciwnicy.przeciwnicy[j].Obrazenia();


			}
		}
	}
	
}

void Hitbox::HitboxStatekStatek(Statek& m_statek, TablicaPrzeciwnikow& m_przeciwnicy)
{
	if (!m_statek.niesmietelnosc)
	{
		for (int i = 0; i < m_przeciwnicy.przeciwnicy.size(); i++)
		{
			if (m_przeciwnicy.przeciwnicy[i].statekObiekt.getGlobalBounds().intersects(m_statek.statekObiekt.getGlobalBounds()))
			{


				m_przeciwnicy.przeciwnicy[i].Obrazenia();
				m_statek.Obrazenia();


			}
		}
	}
	
}

void Hitbox::HitboxStatekBoss(Statek& m_statek, Boss& m_boss)
{
	if (!m_statek.niesmietelnosc)
	{
		
		if (m_boss.statekObiekt.getGlobalBounds().intersects(m_statek.statekObiekt.getGlobalBounds()))
			{


				m_boss.Obrazenia();
				m_statek.Obrazenia();


			}

	}
}
