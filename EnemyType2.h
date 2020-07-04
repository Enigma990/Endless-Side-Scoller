#pragma once
#include<SFML/Graphics.hpp>
#include "EnemiesBase.h"
#include "Player.h"

class EnemyType2 :	public EnemiesBase
{
	int attackSpeed;
	int posY;

	bool enemyState;

	sf::CircleShape enemy;

	public:

		EnemyType2();

		void spawn(Player&);
		void attack();
		void destroy(Player&, int&);
		void draw(sf::RenderWindow&);

		bool isDestroyed();
};

