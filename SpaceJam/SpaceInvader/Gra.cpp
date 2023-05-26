#include "Gra.h"

Gra::Gra()
{
	okno.create(VideoMode(WIDTH, HEIGHT), "Moja Gra", Style::Fullscreen);

	font.loadFromFile("Font/Designer.otf");

	wyborW.loadFromFile("Textures/Wskaznik.png");

	textureTlo0.loadFromFile("Textures/Poziom0.jpg");
}
void Gra::Poziom(unsigned int m_poziom)
{
	gracz.Restart();
	przeciwnicy.Restart();
	pociskiGracza.Restart();
	pociskiPrzeciwnikow.Restart();
	boss.Restart();
	

	textureTlo1.loadFromFile("Textures/Poziom1.png");
	textureTlo2.loadFromFile("Textures/Poziom2.png");
	textureTlo3.loadFromFile("Textures/Poziom3.png");
	switch (m_poziom)
	{
	case 1:
		tlo.setTexture(textureTlo1);

		przeciwnicy.Dodaj(1);
		break;
	case 2:
		tlo.setTexture(textureTlo2);

		przeciwnicy.Dodaj(2);
		break;
	case 3:
		tlo.setTexture(textureTlo3);

		przeciwnicy.Dodaj(3);

		

		break;
	};
	tlo.setPosition(0, 0);

	

	while (okno.isOpen())
	{
		okno.clear();
		okno.draw(tlo);

		Event event;

		while (okno.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				okno.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				okno.close();
			}

		}


		if (m_poziom == 3)
		{
			boss.Niesmiertelnosc();
			boss.Ruch(okno, pociskiPrzeciwnikow, gracz.statekObiekt);
			hitbox.HitboxStatekBoss(gracz, boss);
			hitbox.HitboxStatekPocisk(boss, pociskiGracza);
		} 

		
		gracz.Niesmiertelnosc();
		przeciwnicy.NiesmiertelnoscPrzeciwnik();

		gracz.Ruch(okno, pociskiGracza);

		przeciwnicy.Rysuj(okno, pociskiPrzeciwnikow, gracz.statekObiekt);

		hitbox.HitboxStatekPocisk(gracz, pociskiPrzeciwnikow);
		hitbox.HitboxStatekPocisk(przeciwnicy, pociskiGracza);
		
		hitbox.HitboxStatekStatek(gracz, przeciwnicy);
		

		pociskiGracza.Rysuj(okno);
		pociskiPrzeciwnikow.Rysuj(okno);

		
		if (!gracz.CzyZywy())
		{
			Porazka(m_poziom);
		}
		if (przeciwnicy.Pusto() || (przeciwnicy.Pusto() && !boss.CzyZywy()))
		{
			Zwyciestwo(m_poziom);
		}

		okno.display();

	}

}

void Gra::Start()
{
	tlo.setTexture(textureTlo0);
	zegar.restart();
	
	Text tekstStart("SPACE JAM", font, 100); tekstStart.setFillColor(Color::Color(219, 107, 15));
	Text tekstPoziom1("Poziom I", font, 100);
	Text tekstPoziom2("Poziom II", font, 100);
	Text tekstPoziom3("BOSS", font, 100); tekstPoziom3.setFillColor(Color::Color(111, 8, 156));
	Text tekstWyjscie("Wyjscie", font, 100);

	tekstStart.setOrigin(tekstStart.getLocalBounds().width / 2, tekstStart.getLocalBounds().height / 2);
	tekstPoziom1.setOrigin(tekstPoziom1.getLocalBounds().width / 2, tekstPoziom1.getLocalBounds().height / 2);
	tekstPoziom2.setOrigin(tekstPoziom2.getLocalBounds().width / 2, tekstPoziom2.getLocalBounds().height / 2);
	tekstPoziom3.setOrigin(tekstPoziom3.getLocalBounds().width / 2, tekstPoziom3.getLocalBounds().height / 2);
	tekstWyjscie.setOrigin(tekstWyjscie.getLocalBounds().width / 2, tekstWyjscie.getLocalBounds().height / 2);

	tekstStart.setPosition(WIDTH / 2, HEIGHT * 1 / 6);
	tekstPoziom1.setPosition(WIDTH / 2, HEIGHT * 2 / 6);
	tekstPoziom2.setPosition(WIDTH / 2, HEIGHT * 3 / 6);
	tekstPoziom3.setPosition(WIDTH / 2, HEIGHT * 4 / 6);
	tekstWyjscie.setPosition(WIDTH / 2, HEIGHT * 5 / 6);

	unsigned int pozycja = 0;

	wybor.setTexture(wyborW);
	wybor.setPosition(tekstPoziom1.getPosition().x - tekstPoziom1.getLocalBounds().width / 2 - 64, tekstPoziom1.getPosition().y + 8);

	while (okno.isOpen())
	{
		okno.clear();
		okno.draw(tlo);
		Event event;



		while (okno.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				okno.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				okno.close();
			}
		}


		

		if ((Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)) && pozycja == 0 && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			pozycja += 1;
			wybor.setPosition(tekstPoziom2.getPosition().x - tekstPoziom2.getLocalBounds().width / 2 - 64, tekstPoziom2.getPosition().y + 16);
			zegar.restart();
		}
		if ((Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)) && pozycja == 1 && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			pozycja += 1;
			wybor.setPosition(tekstPoziom3.getPosition().x - tekstPoziom3.getLocalBounds().width / 2 - 64, tekstPoziom3.getPosition().y + 8);
			zegar.restart();
		}
		if ((Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)) && pozycja == 2 && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			pozycja += 1;
			wybor.setPosition(tekstWyjscie.getPosition().x - tekstWyjscie.getLocalBounds().width / 2 - 64, tekstWyjscie.getPosition().y + 8);
			zegar.restart();
		}
		if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) && pozycja == 1 && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			pozycja -= 1;
			wybor.setPosition(tekstPoziom1.getPosition().x - tekstPoziom1.getLocalBounds().width / 2 - 64, tekstPoziom1.getPosition().y + 8);
			zegar.restart();
		}
		if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) && pozycja == 2 && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			pozycja -= 1;
			wybor.setPosition(tekstPoziom2.getPosition().x - tekstPoziom2.getLocalBounds().width / 2 - 64, tekstPoziom2.getPosition().y + 16);
			zegar.restart();
		}
		if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) && pozycja == 3 && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			pozycja -= 1;
			wybor.setPosition(tekstPoziom3.getPosition().x - tekstPoziom3.getLocalBounds().width / 2 - 64, tekstPoziom3.getPosition().y + 8);
			zegar.restart();
		}

		okno.draw(wybor);
		okno.draw(tekstStart);
		okno.draw(tekstPoziom1);
		okno.draw(tekstPoziom2);
		okno.draw(tekstPoziom3);
		okno.draw(tekstWyjscie);

		if ((Keyboard::isKeyPressed(Keyboard::Enter) || Keyboard::isKeyPressed(Keyboard::Space)) && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			switch (pozycja)
			{
			case 0:
				Poziom(1);
				break;
			case 1:
				Poziom(2);
				break;
			case 2:
				Poziom(3);
				break;
			case 3:
				okno.close();

			}
			zegar.restart();
		}

		okno.display();
	}
}


void Gra::Porazka(unsigned int m_poziom)
{
	tlo.setTexture(textureTlo0);
	Text tekstPorazka("GAME OVER", font, 100); tekstPorazka.setFillColor(Color::Color(184, 0, 0));
	Text tekstRestart("Restart", font, 100);
	Text tekstPoziom("Wybierz Poziom", font, 100);
	Text tekstWyjscie("Wyjscie", font, 100);
	

	tekstPorazka.setOrigin(tekstPorazka.getLocalBounds().width/ 2, tekstPorazka.getLocalBounds().height / 2);
	tekstPoziom.setOrigin(tekstPoziom.getLocalBounds().width/2 , tekstPoziom.getLocalBounds().height/2);
	tekstRestart.setOrigin(tekstRestart.getLocalBounds().width / 2, tekstRestart.getLocalBounds().height / 2);
	tekstWyjscie.setOrigin(tekstWyjscie.getLocalBounds().width / 2, tekstWyjscie.getLocalBounds().height / 2);

	tekstPorazka.setPosition(WIDTH / 2, HEIGHT * 1 / 5);
	tekstPoziom.setPosition(WIDTH / 2, HEIGHT * 3 / 5);
	tekstRestart.setPosition(WIDTH / 2, HEIGHT * 2 / 5);
	tekstWyjscie.setPosition(WIDTH / 2, HEIGHT * 4 / 5);


	wybor.setTexture(wyborW);
	wybor.setPosition(tekstRestart.getPosition().x - tekstRestart.getLocalBounds().width / 2  -64 , tekstRestart.getPosition().y + 8);

	unsigned int pozycjal = 0;


	while (okno.isOpen())
	{
		okno.clear();
		okno.draw(tlo);
		Event event;

		

		while (okno.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				okno.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				okno.close();
			}
		}
		



		if ((Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)) && pozycjal == 0 && zegar.getElapsedTime().asSeconds() >0.2)
		{
			pozycjal += 1;
			wybor.setPosition(tekstPoziom.getPosition().x - tekstPoziom.getLocalBounds().width / 2 - 64, tekstPoziom.getPosition().y + 16);
			zegar.restart();
		}
		if ((Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)) && pozycjal == 1 && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			pozycjal += 1;
			wybor.setPosition(tekstWyjscie.getPosition().x - tekstWyjscie.getLocalBounds().width / 2 - 64, tekstWyjscie.getPosition().y + 8);
			zegar.restart();
		}
		if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) && pozycjal == 1 && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			pozycjal -= 1;
			wybor.setPosition(tekstRestart.getPosition().x - tekstRestart.getLocalBounds().width / 2 - 64, tekstRestart.getPosition().y + 8);
			zegar.restart();
		}
		if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) && pozycjal == 2 && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			pozycjal -= 1;
			wybor.setPosition(tekstPoziom.getPosition().x - tekstPoziom.getLocalBounds().width / 2 - 64, tekstPoziom.getPosition().y + 16);
			zegar.restart();
		}

		okno.draw(wybor);
		okno.draw(tekstPorazka);
		okno.draw(tekstPoziom);
		okno.draw(tekstRestart);
		okno.draw(tekstWyjscie);

		okno.display();

		if ((Keyboard::isKeyPressed(Keyboard::Enter) || Keyboard::isKeyPressed(Keyboard::Space)) && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			switch (pozycjal)
			{
			case 0:
				Poziom(m_poziom);
				
				break;
			case 1:
				
				Start();
				break;
			case 2:
				okno.close();
				break;

			}
			zegar.restart();
		}

	}
}

void Gra::Zwyciestwo(unsigned int m_poziom)
{
	tlo.setTexture(textureTlo0);
	Text tekstZwyciestwo("Wygrana", font, 100); tekstZwyciestwo.setFillColor(Color::Color(229, 242, 41));
	Text tekstNext("Kolejny Poziom", font, 100);
	Text tekstPoziom("Wybierz Poziom", font, 100);
	Text tekstWyjscie("Wyjscie", font, 100);

	tekstZwyciestwo.setOrigin(tekstZwyciestwo.getLocalBounds().width / 2, tekstZwyciestwo.getLocalBounds().height / 2);
	tekstPoziom.setOrigin(tekstPoziom.getLocalBounds().width / 2, tekstPoziom.getLocalBounds().height / 2);
	tekstNext.setOrigin(tekstNext.getLocalBounds().width / 2, tekstNext.getLocalBounds().height / 2);
	tekstWyjscie.setOrigin(tekstWyjscie.getLocalBounds().width / 2, tekstWyjscie.getLocalBounds().height / 2);

	tekstZwyciestwo.setPosition(WIDTH / 2, HEIGHT * 1 / 5);
	tekstNext.setPosition(WIDTH / 2, HEIGHT * 2 / 5);
	tekstPoziom.setPosition(WIDTH / 2, HEIGHT * 3 / 5);
	tekstWyjscie.setPosition(WIDTH / 2, HEIGHT * 4 / 5);

	wybor.setTexture(wyborW);
	wybor.setPosition(tekstNext.getPosition().x - tekstNext.getLocalBounds().width / 2 - 64, tekstNext.getPosition().y + 8);

	unsigned int pozycjal = 0;

	while (okno.isOpen())
	{
		okno.clear();
		okno.draw(tlo);
		Event event;



		while (okno.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				okno.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				okno.close();
			}
		}




		if ((Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)) && pozycjal == 0 && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			pozycjal += 1;
			wybor.setPosition(tekstPoziom.getPosition().x - tekstPoziom.getLocalBounds().width / 2 - 64, tekstPoziom.getPosition().y + 16);
			zegar.restart();
		}
		if ((Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)) && pozycjal == 1 && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			pozycjal += 1;
			wybor.setPosition(tekstWyjscie.getPosition().x - tekstWyjscie.getLocalBounds().width / 2 - 64, tekstWyjscie.getPosition().y + 8);
			zegar.restart();
		}
		if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) && pozycjal == 1 && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			pozycjal -= 1;
			wybor.setPosition(tekstNext.getPosition().x - tekstNext.getLocalBounds().width / 2 - 64, tekstNext.getPosition().y + 8);
			zegar.restart();
		}
		if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) && pozycjal == 2 && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			pozycjal -= 1;
			wybor.setPosition(tekstPoziom.getPosition().x - tekstPoziom.getLocalBounds().width / 2 - 64, tekstPoziom.getPosition().y + 16);
			zegar.restart();
		}

		okno.draw(wybor);
		okno.draw(tekstZwyciestwo);
		okno.draw(tekstNext);
		okno.draw(tekstPoziom);
		okno.draw(tekstWyjscie);

		okno.display();

		if ((Keyboard::isKeyPressed(Keyboard::Enter) || Keyboard::isKeyPressed(Keyboard::Space)) && zegar.getElapsedTime().asSeconds() > 0.2)
		{
			switch (pozycjal)
			{
			case 0:
				Poziom(m_poziom + 1);

				break;
			case 1:

				Start();
				break;
			case 2:
				okno.close();
				break;

			}
			zegar.restart();
		}

	}
}	

