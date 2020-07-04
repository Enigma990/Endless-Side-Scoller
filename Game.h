#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<sstream>
#include<vector>
#include "Player.h"
#include "Camera.h"
#include "EnemiesBase.h"
#include "EnemyType1.h"
#include "EnemyType2.h"
#include "EnemyType3.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class Game
{
	int kills;

	int  spawnFrequency;
	int  spawnType;

	float spawnTime1;
	float spawnTime2;
	float spawnTime3;

	sf::Clock gameTime;
	sf::Clock enemyTime1;
	sf::Clock enemyTime2;
	sf::Clock enemyTime3;
	
	public:

		sf::RenderWindow window;

		sf::Font font;
		sf::Text score;
		sf::Vector2f scorePosition;

		std::vector<EnemiesBase*> enemiesList;

		Player player;
		Camera camera;

		//Game Functions
		Game();

		void initialization();
		void gameLoop();
		void update();
		void spawnEnemy();
		void destroyCondition();
		void destroy();
};

