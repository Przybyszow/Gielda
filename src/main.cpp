#include <iostream>

#include "app.h"

#include "zapis_wczyt.h"

int main(int argc, const char* argv[])
{
	App::inicjalizacja();
	
	Gra* gra = &App::_gra;
	
	gra->start();
	
	gra->wczytaj("dane/startowe_dane.txt");
	gra->zapisz("dane/startowe_dane.txt");
	
	gra->info();
	
	App::czyszczenie();
	return 0;
}
