#include "zapis_wczyt.h"

#include "gra.h"

#include <cstdlib>
#include <iostream>
#include <fstream>

std::string utworzZnacznik(TypZnacznika typ, void* dane)
{
	char buffer[512];
	
	std::string znacznik = "";
	znacznik.append("{");
	
	sprintf(buffer, "%x;", (int)typ);
	znacznik.append(buffer);
	
	switch(typ)
	{
		case TypZnacznika::STARTUJACY:
		{
			TypZnacznika* typ = (TypZnacznika*)dane;
			sprintf(buffer, "%x", (int)(*typ));
			
			znacznik.append(buffer);
		} break;
		
		// F O R M A T   Z A P I S U   S P O L E K
		case TypZnacznika::SPOLKA:
		{
			Spolka* spl = (Spolka*)dane;
			sprintf(buffer, "%x;%s;%x;%x",
				spl->typ_spolki,
				spl->nazwa,
				spl->wartosc_akcji,
				spl->dostepne_akcje );
			
			znacznik.append(buffer);
		} break;
		
		// F O R M A T   Z A P I S U   W A L U T
		case TypZnacznika::WALUTA:
		{
			Waluta* waluta = (Waluta*)dane;
			sprintf(buffer, "%s;%.2f", waluta->nazwa, waluta->wartosc);
			
			znacznik.append(buffer);
		} break;
	}
	
	znacznik.append("}");
	
	return znacznik;
}

void zapiszDane(const char* sciezka, TypZnacznika typ, void* dane)
{
	std::ofstream plik;
	
	plik.open(sciezka, std::ofstream::out);
	if( plik.fail() )
	{
		fprintf(stderr, "Błąd przy tworzeniu nowego pliku: %s\n", sciezka);
		return;
	}
	
	if( typ == TypZnacznika::STARTUJACY && typ == TypZnacznika::KONCZACY )
	{
		fprintf( stderr, "Niewłaściwa wartość głównego znacznika zapisywanego pliku!\n" );
		return;
	}
	
	plik << utworzZnacznik(TypZnacznika::STARTUJACY, &typ) << std::endl;
	
	switch(typ)
	{
		case TypZnacznika::ZAPISU_ROZGRYWKI:
		{
			Gra* gra = (Gra*)dane;
			
			for( unsigned int i = 0; i < gra->_spolki.size(); ++i )
			{
				plik << utworzZnacznik(TypZnacznika::SPOLKA, &(gra->_spolki[i])) << std::endl;
			}
			
			for( unsigned int i = 0; i < gra->_waluty.size(); ++i )
			{
				plik << utworzZnacznik(TypZnacznika::WALUTA, &(gra->_waluty[i])) << std::endl;
			}
			
		} break;
		case TypZnacznika::KONFIGURACYJNY:
		{
			
		} break;
		case TypZnacznika::NIEZDEFINIOWANY:
		{
			
		} break;
	}
	
	plik << utworzZnacznik(TypZnacznika::KONCZACY, nullptr) << std::endl;
	
	plik.close();
}

void wczytajDane(const char* sciezka, void* obiekt_docelowy)
{
	std::ifstream plik;
	
	plik.open(sciezka, std::ifstream::in);
	if(plik.fail())
	{
		fprintf( stderr, "Błąd otwarcia pliku: %s!\n", sciezka );
		return;
	}
	
	
	
	
	plik.close();
}
