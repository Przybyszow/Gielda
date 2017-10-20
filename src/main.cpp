#include <iostream>

#include "app.h"

#include "zapis_wczyt.h"

int main(int argc, const char* argv[])
{
	App::inicjalizacja();
	
	Gra* gra = &App::_gra;
	
	for( int i = 1; i < argc; ++i )
	{
		gra->dodajGracza(argv[i]);
	}
	
	gra->info();
	
	gra->start();
	
	gra->wczytaj("dane/zapis.txt");
	//gra->zapisz("dane/zapis.txt");
	
	
	
	App::czyszczenie();
	return 0;
}
