#include "Boss.h"

Boss::Boss() :HP(id), Przeciwnik(5, 60, 3)
{
	texture.loadFromFile("Textures/Boss.png");
	statekObiekt.setTexture(texture);
	statekObiekt.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	statekObiekt.setPosition(WIDTH / 2, HEIGHT * 1/2 - SIZE);
	ruch = Vector2f(0.2f, 0.2f);
	niesmietelnosc = false ;
	przyspieszony = false;
	
}

void Boss::StrzalBoss( TablicaPociskow& m_tab, Sprite m_obiekt)
{
	
	if (zycie >= 50)
	{
		if (zegarPociski.getElapsedTime().asSeconds() > przeladowanie)
		{
			m_tab.Dodaj(statekObiekt, 3, Linia(m_obiekt));
			m_tab.Dodaj(statekObiekt, 4, Linia(m_obiekt));

			zegarPociski.restart();
		}

		if (zegarPom.getElapsedTime().asSeconds() > 1)
		{
			m_tab.Dodaj(statekObiekt, 2, Linia(m_obiekt));

			zegarPom.restart();
		}
		
	}
	else if (zycie >=40)
	{
		
		if (zegarPociski.getElapsedTime().asSeconds() > przeladowanie)
		{
			m_tab.Dodaj(statekObiekt, 3, Linia(m_obiekt));
			m_tab.Dodaj(statekObiekt, 4, Linia(m_obiekt));
			m_tab.Dodaj(statekObiekt, 2, Linia(m_obiekt));

			zegarPociski.restart();
		}
			
		if (zegarPom.getElapsedTime().asSeconds() > 1)
		{
			m_tab.Dodaj(statekObiekt, 3, Linia(m_obiekt));
			m_tab.Dodaj(statekObiekt, 4, Linia(m_obiekt));
	
			zegarPom.restart();
		}
	}
	else if (zycie >= 30)
	{
		
		if (zegarPociski.getElapsedTime().asSeconds() > przeladowanie)
		{
			m_tab.Dodaj(statekObiekt, 3, Linia(m_obiekt));
			m_tab.Dodaj(statekObiekt, 4, Linia(m_obiekt));
			m_tab.Dodaj(statekObiekt, 2, Linia(m_obiekt));

			zegarPociski.restart();
		}

		if (zegarPom.getElapsedTime().asSeconds() > 4)
		{
			
			m_tab.Dodaj(statekObiekt, 6, Linia(m_obiekt));
			m_tab.Dodaj(statekObiekt, 5, Linia(m_obiekt));


			zegarPom.restart();
		}
	}
	else if (zycie >= 15)
	{
		
		if(zegarPociski.getElapsedTime().asSeconds() > przeladowanie)
		{
			m_tab.Dodaj(statekObiekt, 3, Linia(m_obiekt));
			m_tab.Dodaj(statekObiekt, 4, Linia(m_obiekt));
			

			zegarPociski.restart();
		}

		if (zegarPom.getElapsedTime().asSeconds() > 3)
		{
			m_tab.Dodaj(statekObiekt, 1, Linia(m_obiekt));
			m_tab.Dodaj(statekObiekt, 6, Linia(m_obiekt));
			m_tab.Dodaj(statekObiekt, 5, Linia(m_obiekt));


			zegarPom.restart();
		}
	}
	else if (zycie < 15)
	{
		
		if (zegarPociski.getElapsedTime().asSeconds() > przeladowanie)
		{
			m_tab.Dodaj(statekObiekt, 3, Linia(m_obiekt));
			m_tab.Dodaj(statekObiekt, 4, Linia(m_obiekt));


			zegarPociski.restart();
		}

		if (zegarPom.getElapsedTime().asSeconds() > 0.3)
		{
			m_tab.Dodaj(statekObiekt, 2, Linia(m_obiekt));



			zegarPom.restart();
		}
	}
}

bool Boss::KolizjaScianBoss()
{
	Vector2f pozycja = statekObiekt.getPosition();
	if (pozycja.y  - SIZE < 0 || pozycja.y+SIZE > HEIGHT / 2)
	{
		return true;
	}
	return false;
}


void Boss::Restart()
{
	zycie = 60;
	statekObiekt.setPosition(WIDTH / 2, HEIGHT * 1 / 2 - SIZE);
	przyspieszony = false;
	zegarPociski.restart();
	zegarPom.restart();

}

void Boss::Ruch(RenderWindow& m_okno, TablicaPociskow& m_tab, Sprite m_obiekt)
{
	if (CzyZywy())
	{

		if (KolizjaScian(statekObiekt))
		{
			ruch.x = -ruch.x;
		}
		if (KolizjaScianBoss())
		{
			ruch.y = -ruch.y;
		}
		statekObiekt.move(ruch);

		HP.RysujBoss(m_okno, zycie);

		StrzalBoss(m_tab, m_obiekt);
		
		Rysuj(m_okno);
	}
	


}
