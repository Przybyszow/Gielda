#ifndef APP_GIELDA_H__
#define APP_GIELDA_H__

#include <SFML/Graphics.hpp>
#include "gra.h"

#define LICZBA_KLAWISZY 256
#define LICZBA_PRZYCISKOW_MYSZY 32

class App
{
public:
	static sf::RenderWindow _glowneOkno;
	static Gra _gra;
	
	static sf::Event _wydarzenie;
	static bool klawiszWcisniety[LICZBA_KLAWISZY];
	static bool przyciskMyszyWcisniety[LICZBA_PRZYCISKOW_MYSZY];
	static int pozMyszy_x, pozMyszy_y;
	
public:
	static void inicjalizacja(const char* tytul, int szerOkna, int wysOkna);
	static void czyszczenie();
	
	static void sprawdzWydarzenia();
};

#endif // APP_GIELDA_H__
