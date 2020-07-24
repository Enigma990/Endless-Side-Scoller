#pragma once
#include<SFML/Graphics.hpp>
#include "States.h"
#include "MainMenu.h"
#include "Game.h"
#include "GameOver.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class StateManager
{
	private:

		sf::RenderWindow window;

		Game *game;
		MainMenu mainMenu;
		GameOver gameOver;

		void changeState();
		
		State* currentState;
		int stateId;
		int prevState;

	public:

		StateManager();
		~StateManager();

		void run();
};

