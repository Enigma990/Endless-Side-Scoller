#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"States.h"

#define MAXITEMS 3
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class MainMenu :public State
{
	sf::Texture texBackground;
	sf::Sprite background;

	sf::Font menuFont;
	sf::Text menu[MAXITEMS];

	sf::RenderWindow window;

	public:

		MainMenu();
		~MainMenu();

		void update(sf::Vector2f, int&);
		void draw(sf::RenderTarget&);
};

