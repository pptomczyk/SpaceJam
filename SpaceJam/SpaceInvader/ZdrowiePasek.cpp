#include "ZdrowiePasek.h"

ZdrowiePasek::ZdrowiePasek(int m_id)
{
	textureGracz.loadFromFile("Textures/ZycieGracz.png");
	textureBoss.loadFromFile("Textures/ZycieBoss.png");

	switch (m_id)
	{
	case 0:
		HP.setPosition(SIZE + 16 , HEIGHT - SIZE+3);
		HP.setFillColor(Color::Color(43,184,255));
	
		pasekZdrowia.setPosition(SIZE/2, HEIGHT - SIZE);
		pasekZdrowia.setTexture(textureGracz);
		break;
	case 3:
		HP.setOrigin(textureBoss.getSize().x / 2, textureBoss.getSize().y / 2);
		HP.setPosition(WIDTH / 2 - 50, 37);
		HP.setFillColor(Color::Color(14, 201, 23));

		pasekZdrowia.setOrigin(textureBoss.getSize().x / 2, textureBoss.getSize().y / 2);
		
		pasekZdrowia.setPosition(WIDTH / 2 - 64, 32);
		pasekZdrowia.setTexture(textureBoss);
		break;
	}
}

void ZdrowiePasek::RysujGracz(RenderWindow& m_okno, unsigned int m_poziomHP)
{
	
	HP.setSize(Vector2f(m_poziomHP/0.3 *25,25));

	m_okno.draw(HP);
	m_okno.draw(pasekZdrowia);
}

void ZdrowiePasek::RysujBoss(RenderWindow& m_okno, unsigned int m_poziomHP)
{

	HP.setSize(Vector2f(m_poziomHP / 0.6 * 2.7, 25));

	m_okno.draw(HP);
	m_okno.draw(pasekZdrowia);
}
