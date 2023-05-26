#pragma once
#include "SFML/Graphics.hpp"
#include "Global.h"
#include "TablicaPociskow.h"



using namespace sf;
class Statek
{
public:
	Clock zegarPociski;
	Clock zegarNiesmiertelnosci;

	Sprite statekObiekt;
	Vector2f linia;
	Vector2f xy;
	Vector2f ruch;

	unsigned int id; // 0 -gracz, 1- przeciwnik(tank, strzelajacy) , 2- przeciwnik(snajper) ,3-boss
	unsigned int zycie;
	float przeladowanie;

	bool niesmietelnosc;
	void Niesmiertelnosc();



	Statek(unsigned int m_zycie, unsigned int m_id, float m_przeladowanie);

	Vector2f ZwrocPozycje();
	void UstawPozycje(Vector2f m_xy);

	unsigned int ZwrocId();
	
	unsigned int ZwrocZycie();
	void Obrazenia();
	bool CzyZywy();

	float ZwrocPrzeladowanie();

	bool KolizjaScian(Sprite m_obiekt);

	void Strzal(TablicaPociskow& m_tab, Sprite m_obiekt);

	void Rysuj(RenderWindow& m_okno);



	Vector2f Linia(Sprite m_obiekt);


};

