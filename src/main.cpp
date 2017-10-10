#include "app.h"

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
	
	App::czyszczenie();
	return 0;
}
