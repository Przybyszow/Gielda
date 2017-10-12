#ifndef GIELDA_GRA_H__
#define GIELDA_GRA_H__

#include "gracz.h"

#include <vector>

class Gra
{
	// lista aktualnie połączonych graczy
	std::vector<Gracz> _gracze;

public:
	// startuje nową grę z aktualnie połączonymi graczami
	void start();
	// zapisuje stan rozgrywki
	void zapisz(const char* sciezka);
	// wczytuje zapisany wcześniej stan
	void wczytaj(const char* sciezka);
	
	// dodaje gracza o podanej nazwie
	// zwraca 0, jeśli uda sie dodać gracza - w przeciwnym wypadku 1
	int dodajGracza(const char* nazwa_gracza);
	// usuwa wszystkich graczy o podanej nazwie
	void usunGracza(const char* nazwa_gracza);
	
	// funkcja testowa
	void info();
};

#endif // GIELDA_GRA_H__
