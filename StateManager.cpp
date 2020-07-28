#include "StateManager.h"

StateManager::StateManager()
{
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "REKT");
	window.setFramerateLimit(60);

	stateId = 0;
	prevState = 0;
	changeState();
}

StateManager::~StateManager()
{
}

void StateManager::run()
{
	while (window.isOpen())
	{
		if (prevState != stateId)
			changeState();

		prevState = stateId;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		currentState->update(sf::Vector2f(sf::Mouse::getPosition(window)), stateId);
		window.clear();
		currentState->draw(window);
		window.display();

	}
}

void StateManager::changeState()
{
	switch (stateId)
	{
		case -1:
			window.close();
			break;

		case 0:
			currentState = &mainMenu;
			break;

		case 1:
			delete gameOver;
			game = new Game();
			currentState = game;
			break;

		case 2:
			delete game;
			gameOver = new GameOver();
			currentState = gameOver;
			break;

		case 3:
			currentState = &pauseMenu;
			break;

		default:
			break;
	}
}