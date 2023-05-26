#include "Statek.h"

Statek::Statek(unsigned int m_zycie, unsigned int m_id, float m_przeladowanie)
{
    zycie = m_zycie;
    id = m_id;
    przeladowanie = m_przeladowanie;
    niesmietelnosc = false;
}


void Statek::UstawPozycje(Vector2f m_xy)
{
    xy = m_xy;
    statekObiekt.setPosition(xy);
}

unsigned int Statek::ZwrocId()
{
    return id;
}

unsigned int Statek::ZwrocZycie()
{
    return zycie;
}

void Statek::Obrazenia()
{
    if (!niesmietelnosc)
    {
        zycie -= 1;
        niesmietelnosc = true;
        zegarNiesmiertelnosci.restart();
    }
}

void Statek::Niesmiertelnosc() 
{
    if (niesmietelnosc)
    {
        if (zegarNiesmiertelnosci.getElapsedTime().asSeconds() >2)
        {
            niesmietelnosc = false;
            statekObiekt.setColor(Color::White);
        }
        else
        {
            if (int(zegarNiesmiertelnosci.getElapsedTime().asMilliseconds())%2==0 || int(zegarNiesmiertelnosci.getElapsedTime().asMilliseconds()) % 3 == 0)
            {
                statekObiekt.setColor(Color::Transparent);
            }
            else
            {
                statekObiekt.setColor(Color::White);
            }
            

            
        }
    }
}

bool Statek::CzyZywy()
{
    if (zycie == 0)
    {
        return false;
    }
    return true;
}

float Statek::ZwrocPrzeladowanie()
{
    return przeladowanie;
}

bool Statek::KolizjaScian(Sprite m_obiekt)
{

    Vector2f pozycja = m_obiekt.getPosition();

    if (pozycja.x - (SIZE / 2) < 0 || pozycja.x + (SIZE / 2) > WIDTH)
    {
        return true;
    }
    if (pozycja.y - (SIZE / 2) < 0 || pozycja.y + (SIZE / 2) > HEIGHT)
    {
        return true;
    }
    return false;
}

void Statek::Rysuj(RenderWindow& m_okno)
{
    if (CzyZywy())
    {
        m_okno.draw(statekObiekt);
       
    }
    
}



void Statek::Strzal(TablicaPociskow& m_tab, Sprite m_obiekt)
{
    
    m_tab.Dodaj(statekObiekt, id, Linia(m_obiekt));
    
}

Vector2f Statek::Linia(Sprite m_obiekt)
{
    Vector2f a = m_obiekt.getPosition();
    Vector2f b = statekObiekt.getPosition();
    
    linia = Vector2f(a.x - b.x,a.y-b.y);
    
    return linia;
}