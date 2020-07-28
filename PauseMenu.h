#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<sstream>
#include "States.h"

#define MAXITEMS 3
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class PauseMenu :public State
{
	sf::Texture texBackground;
	sf::Sprite background;

	sf::Text score;
	std::ifstream currentScore;
	std::string scoreText;

	sf::Font menuFont;
	sf::Text menu[MAXITEMS];

	sf::RenderWindow window;

public:

	PauseMenu();
	~PauseMenu();

	void update(sf::Vector2f, int&);
	void draw(sf::RenderTarget&);

};

