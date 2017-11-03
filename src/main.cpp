#include <iostream>

#include "app.h"

#include "zapis_wczyt.h"

int main(int argc, const char* argv[])
{
	App::inicjalizacja();
	
	Gra* gra = &App::_gra;
	
	gra->start();
	
	gra->dodajGracza("Kacper");
	
	//gra->zapisz("dane/zapis_v2.txt");
	gra->wczytaj("dane/zapis_v2.txt");
	
	gra->info();
	
	App::czyszczenie();
	return 0;
}
