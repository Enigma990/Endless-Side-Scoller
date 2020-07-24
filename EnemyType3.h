#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include "EnemiesBase.h"
#include "Player.h"
#include "EnemyBullet.h"

class EnemyType3 :	public EnemiesBase
{
	int attackSpeed;
	int posY;
	int health;

	bool enemyState;

	sf::CircleShape enemy;

	sf::Clock fireTime;

	std::vector<EnemyBullet*> enemyBullets;

	public:

		EnemyType3();

		void spawn(Player& player);
		void attack();
		void destroy(Player&, int& kills);
		void draw(sf::RenderTarget&);
		void playerCollision(Player&);

		bool isDestroyed();
};

