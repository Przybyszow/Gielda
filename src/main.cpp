#include <iostream>
#include <SFML/Graphics.hpp>

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
	
	
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.0f);
	shape.setFillColor(sf::Color::Green);
	
	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		window.draw(shape);
		window.display();
	}
	
	return 0;
}
