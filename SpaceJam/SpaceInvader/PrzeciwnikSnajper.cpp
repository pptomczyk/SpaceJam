#include "PrzeciwnikSnajper.h"

PrzeciwnikSnajper::PrzeciwnikSnajper(unsigned int m_x, unsigned int m_y, float m_przeladowanie) : Przeciwnik(m_przeladowanie, 2, 2)
{

	statekObiekt.setPosition(m_x, m_y);
	ruch = Vector2f(0.0f, 0.0f);

}


