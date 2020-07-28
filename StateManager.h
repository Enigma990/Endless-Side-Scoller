#pragma once
#include<SFML/Graphics.hpp>
#include "States.h"
#include "MainMenu.h"
#include "Game.h"
#include "GameOver.h"
#include "PauseMenu.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class StateManager
{
	private:

		sf::RenderWindow window;

		MainMenu mainMenu;
		PauseMenu pauseMenu;

		Game *game;
		GameOver *gameOver;

		void changeState();
		
		State* currentState;
		int stateId;
		int prevState;

	public:

		StateManager();
		~StateManager();

		void run();
};

