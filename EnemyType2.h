#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include "EnemiesBase.h"
#include "Player.h"
#include "EnemyBullet.h"

class EnemyType2 :	public EnemiesBase
{
	int attackSpeed;
	int posY;

	bool enemyState;

	sf::CircleShape enemy;

	sf::Clock fireTime;

	std::vector<EnemyBullet*> enemyBullets;

	public:

		EnemyType2();

		void spawn(Player&);
		void attack();
		void destroy(Player&, int&);
		void draw(sf::RenderWindow&);
		void playerCollision(Player&);

		bool isDestroyed();
};

