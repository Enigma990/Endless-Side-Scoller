#pragma once
#include<SFML/Graphics.hpp>
#include "EnemiesBase.h"
#include "Player.h"

class EnemyType3 :	public EnemiesBase
{
	int attackSpeed;
	int posY;

	bool enemyState;

	sf::CircleShape enemy;

	public:

		EnemyType3();

		void spawn(Player& player);
		void attack();
		void destroy();
		void draw(sf::RenderWindow&);

		bool isDestroyed();
};

