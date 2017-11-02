
/*
 * ##### P L I K I   Z A P I S U #####
 * 
 * 		{typ;wartość1;wartość2;(...)}
 * 
 * 1. 	Cały dokument składa się z powyższych znaczników.
 * 		Jeżeli jakiś tekst znajduje się poza klamrami znacznika, to
 * 		nie jest interpretowany i jest traktowany jako komentarz.
 * 2.	Pierwszym elementem każdego znacznika jest liczba reprezentująca
 * 		typ znacznika. Określa, jaki obiekt opisuje ten znacznik.
 * 3.	Elementy znaczników oddzielane są średnikiem.
 * 4.	Znacznik ma nieokreśloną liczbę elementów.
 * 5.	Każdy dokument rozpoczyna się znacznikiem z pierwszym argumentem
 * 		równym 1 i drugim argumentem określającym rodzaj dokumentu.
 * 		Każdy dokument kończy się znacznikiem z pierwszym argumentem
 * 		równym 2.
 * */


#ifndef GIELDA_ZAPIS_WCZYT_H__
#define GIELDA_ZAPIS_WCZYT_H__

#include "obiekty_transakcji.h"

#include <string>

enum class TypZnacznika {
	NIEZDEFINIOWANY 	= 0,
	STARTUJACY 			= 1,
	KONCZACY 			= 2,
	
	ZAPISU_ROZGRYWKI 	= 3,
	KONFIGURACYJNY 		= 4,
	
	SPOLKA				= 10,
	WALUTA				= 11
};

std::string utworzZnacznik(TypZnacznika typ, void* dane);

void zapiszDane(const char* sciezka, TypZnacznika typ, void* dane);

void wczytajDane(const char* sciezka, void* obiekt_docelowy);

#endif // GIELDA_ZAPIS_WCZYT_H__
