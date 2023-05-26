#include "Pocisk.h"



Pocisk::Pocisk(Sprite m_sprite, unsigned int m_id, Vector2f m_linia)
{
	obiektPocisk.setOrigin(SIZE / 2, SIZE / 2);


	switch (m_id)
	{
	case 0: // Gracz
		predkosc_y = -1; 
		predkosc_x = 0;
		xy = m_sprite.getPosition() - Vector2f(0,32);
		
		break;
		
	case 1: //Normalny Przeciwnik
		predkosc_y = 1;
		predkosc_x = 0;
		xy = m_sprite.getPosition() + Vector2f(0, 32);
		obiektPocisk.setRotation(180);
		
		break;

	case 2:// Snajper
		predkosc_x = 1*(m_linia.x/sqrt(m_linia.x*m_linia.x+ m_linia.y * m_linia.y));
		predkosc_y = 1*(m_linia.y/sqrt(m_linia.x * m_linia.x + m_linia.y * m_linia.y));
		xy = m_sprite.getPosition() + Vector2f(0, 32);
		
		break;
	case 3://Boss namierzane lewo
		predkosc_x = 1 * (m_linia.x / sqrt(m_linia.x * m_linia.x + m_linia.y * m_linia.y));
		predkosc_y = 1 * (m_linia.y / sqrt(m_linia.x * m_linia.x + m_linia.y * m_linia.y));
		xy = m_sprite.getPosition() + Vector2f(-32, 32);
		
		break;
	case 4:// Boss namierzane prawo
		predkosc_x = 1 * (m_linia.x / sqrt(m_linia.x * m_linia.x + m_linia.y * m_linia.y));
		predkosc_y = 1 * (m_linia.y / sqrt(m_linia.x * m_linia.x + m_linia.y * m_linia.y));
		xy = m_sprite.getPosition() + Vector2f(32, 32);
		
		break;
	case 5://Boss krêcone
		typPocisku = 1;
		xy = m_sprite.getPosition();
		
		break;
	case 6://Boss lewo-prawo
		typPocisku = 2;
		xy = m_sprite.getPosition();

		break;
	}
}

Pocisk::~Pocisk()
{
	
}



void Pocisk::Ruch()
{
	float t = time.getElapsedTime().asSeconds();
	float r = 0.2 * t;
	float theta = 2 * t;

	switch (typPocisku)
	{
	case 2:
		xy.x += 0.4 * cos(t);
		xy.y += 0.05;

		break;
	case 1:
		
		xy.x += r * cos(theta);
		xy.y += r * sin(theta);

		break;
	default:
		xy.x += predkosc_x;
		xy.y += predkosc_y;
		break;
	}


	
	obiektPocisk.setPosition(xy);
	
	
}

void Pocisk::Rysuj(RenderWindow& m_okno)
{
	
	Ruch();
	m_okno.draw(obiektPocisk);

}





bool Pocisk::KolizjaScian()
{
	if (obiektPocisk.getPosition().y < 0 || obiektPocisk.getPosition().y > HEIGHT)
	{
		return true;
	}
	return false;
}


