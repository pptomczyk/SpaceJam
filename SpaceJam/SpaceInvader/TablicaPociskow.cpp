#include "TablicaPociskow.h"



void TablicaPociskow::Restart()
{
	pociski.clear();
}

void TablicaPociskow::Dodaj(Sprite m_sprite, unsigned int m_id, Vector2f m_linia)
{
	texturePocisk.loadFromFile("Textures/Pocisk.png");
	textureAlien.loadFromFile("Textures/PociskKosmita.png");
	textureGalaktyka.loadFromFile("Textures/PociskGalaktyka.png");
	textureSaturn.loadFromFile("Textures/PociskSaturn.png");
	Pocisk pocisk(m_sprite, m_id, m_linia);
	switch (m_id)
	{
	case 0:
		pocisk.obiektPocisk.setTexture(texturePocisk);
		break;
	case 1:
		pocisk.obiektPocisk.setTexture(texturePocisk);
		break;
	case 2:
		pocisk.obiektPocisk.setTexture(textureAlien);
		break;
	case 3:
		pocisk.obiektPocisk.setTexture(textureAlien);
		break;
	case 4:
		pocisk.obiektPocisk.setTexture(textureAlien);
		break;
	case 5:
		pocisk.obiektPocisk.setTexture(textureGalaktyka);
		break;
	case 6:
		pocisk.obiektPocisk.setTexture(textureSaturn);
		break;
	}
	pociski.push_back(pocisk);
	
}




void TablicaPociskow::Rysuj(RenderWindow& m_okno)
{
	for (int i = 0; i < pociski.size(); i++)
	{
		if (pociski[i].KolizjaScian())
		{
			pociski.erase(pociski.begin() + i);
		}
		else
		{
			
			pociski[i].Rysuj(m_okno);


		}

	}
}
