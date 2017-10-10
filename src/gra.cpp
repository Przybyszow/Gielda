#include "gra.h"

#include <string.h>
#include <iostream>


void Gra::start()
{
	
}

void Gra::zapisz(const char* sciezka)
{
	
}

void Gra::wczytaj(const char* sciezka)
{
	
}

int Gra::dodajGracza(const char* nazwa_gracza)
{
	// Jeżeli string składa się z mniej niż 4 liter
	// lub zaczyna się cyfrą
	if( !(strlen(nazwa_gracza)<=3) && ((*nazwa_gracza > '0') && (*nazwa_gracza < '9')) )
	{
		fprintf(stderr, "Nazwa gracza musi składać się min. z 4 liter i nie może zaczynać się cyfrą!\n");
		return 1;
	}
	
	_gracze.push_back( new Gracz(nazwa_gracza) );
	
	return 0;
}

void Gra::usunGracza(const char* nazwa_gracza)
{
	
	// Szuka graczy o nazwie równej łańcuchowi nazwa_gracza
	for( int i = 0; i < _gracze.size(); ++i )
	{
		if( !strcmp((_gracze[i]->wezNazweGracza().c_str()), nazwa_gracza) )
		{
			delete _gracze[i];
			_gracze.erase(_gracze.begin()+i);
		}
	}
}

void Gra::info()
{
	printf("Gracze:\n");
	for( int i = 0; i < _gracze.size(); ++i )
	{
		printf("%d. %s\n", i+1, _gracze[i]->wezNazweGracza().c_str());
	}
}
