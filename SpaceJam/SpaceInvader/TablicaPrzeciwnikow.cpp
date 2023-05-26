#include "TablicaPrzeciwnikow.h"

void TablicaPrzeciwnikow::Restart()
{
	przeciwnicy.clear();
}

void TablicaPrzeciwnikow::Dodaj(int poziom)
{
	textureTank.loadFromFile("Textures/KosmitaTank.png");
	textureStrzelec.loadFromFile("Textures/Kosmita.png");
	textureSnajper.loadFromFile("Textures/KosmitaSnajper.png");

	srand((unsigned)time(0));

	switch (poziom)
	{
	case 1:
		for (int i = 0; i <3; i++)
		{
			PrzeciwnikTank przeciwnikTank(rand() % (WIDTH - SIZE -1) + SIZE + 1, rand() % HEIGHT * 1 / 10 + HEIGHT/4 );
			przeciwnikTank.statekObiekt.setTexture(textureTank);
			przeciwnicy.push_back(przeciwnikTank);
		}
		for (int i = 0; i < 10; i++)
		{
			PrzeciwnikStrzelec przeciwnikStrzelec(rand() % (WIDTH - SIZE -1) + SIZE + 1, rand() % HEIGHT * 1 / 5 + SIZE, rand()%7+3);
			przeciwnikStrzelec.statekObiekt.setTexture(textureStrzelec);
			przeciwnicy.push_back(przeciwnikStrzelec);
		}
		for (int i = 0; i < 0; i++)
		{
			PrzeciwnikSnajper przeciwnikSnajper(rand() % (WIDTH - SIZE - 1) + SIZE + 1, rand() % HEIGHT * 1 / 7 + SIZE, rand() % 10+4);
			przeciwnikSnajper.statekObiekt.setTexture(textureSnajper);
			przeciwnicy.push_back(przeciwnikSnajper);
		}
		
		break;

	case 2:
		for (int i = 0; i < 5; i++)
		{
			PrzeciwnikTank przeciwnikTank(rand() % (WIDTH - SIZE - 1) + SIZE + 1, rand() % HEIGHT * 1 / 10 + HEIGHT / 4);
			przeciwnikTank.statekObiekt.setTexture(textureTank);
			przeciwnicy.push_back(przeciwnikTank);
		}
		for (int i = 0; i < 15; i++)
		{
			PrzeciwnikStrzelec przeciwnikStrzelec(rand() % (WIDTH - SIZE - 1) + SIZE + 1, rand() % HEIGHT * 1 / 5 + SIZE, rand() % 7 + 3);
			przeciwnikStrzelec.statekObiekt.setTexture(textureStrzelec);
			przeciwnicy.push_back(przeciwnikStrzelec);
		}
		for (int i = 0; i < 4; i++)
		{
			PrzeciwnikSnajper przeciwnikSnajper(rand() % (WIDTH - SIZE - 1) + SIZE + 1, rand() % HEIGHT * 1 / 7 + SIZE, rand() % 10 + 4);
			przeciwnikSnajper.statekObiekt.setTexture(textureSnajper);
			przeciwnicy.push_back(przeciwnikSnajper);
		}

		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{
			PrzeciwnikTank przeciwnikTank(rand() % (WIDTH - SIZE - 1) + SIZE + 1, rand() % HEIGHT * 1 / 10 + HEIGHT / 4);
			przeciwnikTank.statekObiekt.setTexture(textureTank);
			przeciwnicy.push_back(przeciwnikTank);
		}
		for (int i = 0; i < 5; i++)
		{
			PrzeciwnikStrzelec przeciwnikStrzelec(rand() % (WIDTH - SIZE - 1) + SIZE + 1, rand() % HEIGHT * 1 / 5 + SIZE, rand() % 7 + 3);
			przeciwnikStrzelec.statekObiekt.setTexture(textureStrzelec);
			przeciwnicy.push_back(przeciwnikStrzelec);
		}
		for (int i = 0; i < 6; i++)
		{
			PrzeciwnikSnajper przeciwnikSnajper(rand() % (WIDTH - SIZE - 1) + SIZE + 1, rand() % HEIGHT * 1 / 7 + SIZE, rand() % 10 + 4);
			przeciwnikSnajper.statekObiekt.setTexture(textureSnajper);
			przeciwnicy.push_back(przeciwnikSnajper);
		}

		break;
	}


}

void TablicaPrzeciwnikow::Rysuj(RenderWindow& m_okno, TablicaPociskow& m_tab, Sprite m_obiekt)
{
	for (int i = 0; i < przeciwnicy.size(); i++)
	{
		if (przeciwnicy[i].CzyZywy())
		{
			przeciwnicy[i].Ruch(m_okno, m_tab, m_obiekt);
			
		}
		else
		{
			przeciwnicy.erase(przeciwnicy.begin() + i);
		}
	}
}

void TablicaPrzeciwnikow::NiesmiertelnoscPrzeciwnik()
{
	for (int i = 0; i < przeciwnicy.size(); i++)
	{
		przeciwnicy[i].Niesmiertelnosc();
	}
}

bool TablicaPrzeciwnikow::Pusto()
{
	if (przeciwnicy.size() == 0)
	{
		return true;
	}
	return false;
}
