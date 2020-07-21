#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

#define MAXITEMS 3
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class MainMenu
{
	int selectedItem;

	sf::Font menuFont;
	sf::Text menu[MAXITEMS];

	sf::RenderWindow window;

	public:

		MainMenu();
		~MainMenu();

		void update();
		void draw();
};

