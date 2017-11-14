#include "app.h"

sf::RenderWindow App::_glowneOkno;
Gra App::_gra;
sf::Event App::_wydarzenie;
bool App::klawiszWcisniety[LICZBA_KLAWISZY];
bool App::przyciskMyszyWcisniety[LICZBA_PRZYCISKOW_MYSZY];
int App::pozMyszy_x, App::pozMyszy_y;

void App::inicjalizacja(const char* tytul, int szerOkna, int wysOkna)
{
	_glowneOkno.create(sf::VideoMode(szerOkna, wysOkna), tytul, sf::Style::Close|sf::Style::Titlebar);
	
	for(int i = 0; i < LICZBA_KLAWISZY; ++i)
		klawiszWcisniety[i] = false;
	for(int i = 0; i < LICZBA_PRZYCISKOW_MYSZY; ++i)
		przyciskMyszyWcisniety[i] = false;
}

void App::czyszczenie()
{
	
}

void App::sprawdzWydarzenia()
{
	while(_glowneOkno.pollEvent(_wydarzenie))
	{
		switch(_wydarzenie.type)
		{
			case sf::Event::Closed:
				_glowneOkno.close();
				break;
			
			case sf::Event::KeyPressed:
				klawiszWcisniety[_wydarzenie.key.code] = true;
				break;
			case sf::Event::KeyReleased:
				klawiszWcisniety[_wydarzenie.key.code] = false;
				break;
			
			case sf::Event::MouseMoved:
				pozMyszy_x = _wydarzenie.mouseMove.x;
				pozMyszy_y = _wydarzenie.mouseMove.y;
				break;
			case sf::Event::MouseButtonPressed:
				przyciskMyszyWcisniety[_wydarzenie.mouseButton.button] = true;
				break;
			case sf::Event::MouseButtonReleased:
				przyciskMyszyWcisniety[_wydarzenie.mouseButton.button] = false;
				break;
		}
	}
}
