#pragma once
#include<SFML/Graphics.hpp>
#include "EnemiesBase.h"
#include "Player.h"

class EnemyType1 : public EnemiesBase
{
	int attackSpeed;
	int posY;

	bool enemyState;

	sf::CircleShape enemy;

	public:

		EnemyType1();

		void spawn(Player&);
		void attack();
		void destroy(Player&, int&);
		void draw(sf::RenderWindow&);

		bool isDestroyed();
};

