#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<sstream>
#include "States.h"

#define MAXITEMS 3
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class GameOver :public State
{
	sf::Texture texBackground;
	sf::Sprite background;

	sf::Font gameOverFont;
	sf::Text score;
	std::ifstream currentScore;
	std::string scoreText;

	sf::Text highScore;
	std::fstream highScoreFile;
	std::string highScoreText;

	sf::Text menu[MAXITEMS];

	public:

		GameOver();
		~GameOver();
		
		void update(sf::Vector2f mPos, int& stateId);
		void draw(sf::RenderTarget& target);
		void updateScore();

};