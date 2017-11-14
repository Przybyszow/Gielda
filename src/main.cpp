#include <iostream>
#include <SFML/Graphics.hpp>

#include "app.h"

#include "zapis_wczyt.h"

int main(int argc, const char* argv[])
{
	App::inicjalizacja("Gielda", 640, 400);
	
	Gra* gra = &App::_gra;
	
	gra->start();
	
	gra->wczytaj("dane/startowe_dane.txt");
	//gra->zapisz("dane/startowe_dane.txt");
	
	//gra->info();
	
	App::czyszczenie();
	
	
	sf::CircleShape shape(100.0f);
	shape.setFillColor(sf::Color::Green);
	
	while(App::_glowneOkno.isOpen())
	{
		App::sprawdzWydarzenia();
		
		App::_glowneOkno.clear();
		App::_glowneOkno.draw(shape);
		App::_glowneOkno.display();
	}
	
	return 0;
}
