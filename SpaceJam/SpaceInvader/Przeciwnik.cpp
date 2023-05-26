#include "Przeciwnik.h"


Przeciwnik::Przeciwnik(float m_przeladowanie, unsigned int m_zdrowie, unsigned int m_id ) : Statek(m_zdrowie,m_id,m_przeladowanie )
{
	statekObiekt.setOrigin(SIZE / 2, SIZE / 2);
}

void Przeciwnik::Ruch(RenderWindow& m_okno, TablicaPociskow& m_tab, Sprite m_obiekt)
{
	

	if (CzyZywy())
	{
		if (KolizjaScian(statekObiekt))
		{
			ruch = -ruch;
		}
		statekObiekt.move(ruch);

		if (zegarPociski.getElapsedTime().asSeconds() > przeladowanie)
		{
			Strzal(m_tab, m_obiekt);

			zegarPociski.restart();
		}
		Rysuj(m_okno);
	}
}
