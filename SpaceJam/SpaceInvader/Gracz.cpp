#include "Gracz.h"

Gracz::Gracz() : HP(id), Statek(3, 0, 1)
{
	texture.loadFromFile("Textures/Gracz.png");
	statekObiekt.setTexture(texture);
	statekObiekt.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	UstawPozycje(Vector2f(WIDTH / 2, HEIGHT * 3 / 4));
}



void Gracz::Restart()
{
	zycie = 3;
	UstawPozycje(Vector2f(WIDTH / 2, HEIGHT * 3 / 4));
	zegarPociski.restart();
}

void Gracz::Ruch(RenderWindow& m_okno , TablicaPociskow& m_tab)
{
	if (CzyZywy())
	{
		

		ruch = Vector2f(0.0f, 0.0f);

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			ruch.x -= SPEED;
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			ruch.x += SPEED;
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			ruch.y -= SPEED;
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			ruch.y += SPEED;
		}

		//kopia statku i sprawdzanie kolizji krawedzi
		Sprite kopia;
		kopia.setPosition(statekObiekt.getPosition());
		kopia.move(ruch);

		if (!KolizjaScian(kopia))
		{
			statekObiekt.move(ruch);
		}


		// Strza³
		if (Keyboard::isKeyPressed(Keyboard::Space)&& zegarPociski.getElapsedTime().asSeconds() > przeladowanie)
		{
			Strzal(m_tab, statekObiekt);

			zegarPociski.restart();
		}

		HP.RysujGracz(m_okno, zycie);

		Rysuj(m_okno); // Rysowanie statku
	}
	else
	{
		m_okno.close();
	}
}




