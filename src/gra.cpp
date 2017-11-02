#include "gra.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <string>

Gra::Gra()
{
}
Gra::~Gra()
{
}

void Gra::start()
{
	_tura = 0;
	
	dodajSpolke(Spolka::Typ::PRZEMYSL_BUDOWLANY, "Dom Development", 50);
	dodajSpolke(Spolka::Typ::PRZEMYSL_BUDOWLANY, "Budimex", 195);
	dodajSpolke(Spolka::Typ::PRZEMYSL_BUDOWLANY, "Mostostal", 14);
	dodajSpolke(Spolka::Typ::PRZEMYSL_BUDOWLANY, "Energomontaż", 14);
	dodajSpolke(Spolka::Typ::PRZEMYSL_BUDOWLANY, "J.W. Construction", 4);
	
	dodajSpolke(Spolka::Typ::PRZEMYSL_SPOZYWCZY, "Soklłów", 5);
	dodajSpolke(Spolka::Typ::PRZEMYSL_SPOZYWCZY, "Morliny", 8);
	dodajSpolke(Spolka::Typ::PRZEMYSL_SPOZYWCZY, "Żywiec", 440);
	dodajSpolke(Spolka::Typ::PRZEMYSL_SPOZYWCZY, "Kruszwica", 56);
	dodajSpolke(Spolka::Typ::PRZEMYSL_SPOZYWCZY, "Carrefour", 4);
	
	dodajSpolke(Spolka::Typ::PRZEMYSL_ENERGETYCZNY, "Coalenergy", 2);
	dodajSpolke(Spolka::Typ::PRZEMYSL_ENERGETYCZNY, "PGNiG", 5);
	dodajSpolke(Spolka::Typ::PRZEMYSL_ENERGETYCZNY, "PKN Orlen", 74);
	dodajSpolke(Spolka::Typ::PRZEMYSL_ENERGETYCZNY, "PGE", 14);
	dodajSpolke(Spolka::Typ::PRZEMYSL_ENERGETYCZNY, "Energa", 15);
	
	dodajSpolke(Spolka::Typ::BANKOWOSC, "Mbank", 340);
	dodajSpolke(Spolka::Typ::BANKOWOSC, "Alior bank", 70);
	dodajSpolke(Spolka::Typ::BANKOWOSC, "Millenium", 5);
	dodajSpolke(Spolka::Typ::BANKOWOSC, "ING", 120);
	dodajSpolke(Spolka::Typ::BANKOWOSC, "PKO bp", 27);
	
	dodajSpolke(Spolka::Typ::UBEZPIECZENIA, "PZU", 35);
	dodajSpolke(Spolka::Typ::UBEZPIECZENIA, "Metlive", 15);
	dodajSpolke(Spolka::Typ::UBEZPIECZENIA, "TALANX", 100);
	dodajSpolke(Spolka::Typ::UBEZPIECZENIA, "Warta", 215);
	dodajSpolke(Spolka::Typ::UBEZPIECZENIA, "Aviva", 415);
	
	dodajWalute("Złoty", 1.00f);
	dodajWalute("Euro", 4.20f);
	dodajWalute("Dolar", 3.50f);
	dodajWalute("Funt", 5.40f);
}

void Gra::zapisz(const char* sciezka)
{
	zapiszDane(sciezka, TypZnacznika::ZAPISU_ROZGRYWKI, this);
}

void Gra::wczytaj(const char* sciezka)
{
	// usuwanie starych danych
	usunWszystkieDane();
	
	// wczytywanie nowych danych
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
	
	_gracze.push_back( Gracz(nazwa_gracza) );
	
	return 0;
}

void Gra::usunGracza(const char* nazwa_gracza)
{
	
	// Szuka graczy o nazwie równej łańcuchowi nazwa_gracza
	for( int i = 0; i < _gracze.size(); ++i )
	{
		if( !strcmp((_gracze[i].wezNazweGracza().c_str()), nazwa_gracza) )
		{
			_gracze.erase(_gracze.begin()+i);
		}
	}
}

void Gra::info()
{
	printf("Gracze:\n");
	for( int i = 0; i < _gracze.size(); ++i )
	{
		printf("%d. %s\n", i+1, _gracze[i].wezNazweGracza().c_str());
	}
}

void Gra::dodajSpolke(Spolka::Typ typ_spolki, const char* nazwa, unsigned int wartosc_akcji)
{
	Spolka nowa_spolka;
	nowa_spolka.typ_spolki = typ_spolki;
	nowa_spolka.nazwa = nazwa;
	nowa_spolka.wartosc_akcji = wartosc_akcji;
	nowa_spolka.dostepne_akcje = 1000;
	
	_spolki.push_back(nowa_spolka);
}

void Gra::usunSpolke(const char* nazwa)
{
	for( int i = 0; i < _spolki.size(); ++i )
	{
		if( !strcmp( _spolki[i].nazwa, nazwa ) )
		{
			_spolki.erase(_spolki.begin()+i);
		}
	}
}

void Gra::dodajWalute(const char* nazwa, float wartosc)
{
	Waluta nowa_waluta;
	nowa_waluta.nazwa = nazwa;
	nowa_waluta.wartosc = wartosc;
	
	_waluty.push_back(nowa_waluta);
}

void Gra::usunWalute(const char* nazwa)
{
	for( int i = 0; i < _waluty.size(); ++i )
	{
		if( !strcmp( _waluty[i].nazwa, nazwa ) )
		{
			_waluty.erase(_waluty.begin()+i);
		}
	}
}

void Gra::usunWszystkieDane()
{
	_spolki.clear();
	_waluty.clear();
}
