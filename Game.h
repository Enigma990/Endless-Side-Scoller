#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include "States.h"
#include "Player.h"
#include "Camera.h"
#include "EnemiesBase.h"
#include "EnemyType1.h"
#include "EnemyType2.h"
#include "EnemyType3.h"

class Game : public State
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

	std::ofstream currentScore;
	
	public:

		sf::Font font;
		sf::Text score;
		sf::Vector2f scorePosition;

		sf::Music backgroundMusic;

		std::vector<EnemiesBase*> enemiesList;

		Player player;
		Camera camera;

		//Game Functions
		Game();
		void update(sf::Vector2f, int&);
		void draw(sf::RenderTarget&);

		void initialization();
		void spawnEnemy();
		void destroyCondition();
		void destroy();
		void reset();
};

