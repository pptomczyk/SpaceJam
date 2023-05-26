#include "PrzeciwnikStrzelec.h"
PrzeciwnikStrzelec::PrzeciwnikStrzelec(unsigned int m_x, unsigned int m_y, float m_przeladowanie) : Przeciwnik(m_przeladowanie, 1, 1)
{

	statekObiekt.setPosition(m_x, m_y);
	ruch = Vector2f(0.3f, 0.0f);
}