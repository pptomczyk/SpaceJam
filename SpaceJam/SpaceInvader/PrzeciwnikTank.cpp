#include "PrzeciwnikTank.h"

PrzeciwnikTank::PrzeciwnikTank(unsigned int m_x, unsigned int m_y): Przeciwnik(100, 3, 1)
{
	statekObiekt.setPosition(m_x, m_y);
	ruch = Vector2f(0.2f, 0.0f);
	
}
