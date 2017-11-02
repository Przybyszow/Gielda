#include <iostream>

#include "app.h"

#include "zapis_wczyt.h"

int main(int argc, const char* argv[])
{
	App::inicjalizacja();
	
	Gra* gra = &App::_gra;
	
	gra->start();
	
	gra->zapisz("dane/zapis_v2.txt");
	
	
	
	App::czyszczenie();
	return 0;
}
