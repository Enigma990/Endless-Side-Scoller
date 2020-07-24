#pragma once
#include<SFML/Graphics.hpp>

class EnemyBullet
{
	public:

		sf::CircleShape bullet;

		bool bulletState;

		//Bullet Functions

		EnemyBullet(sf::Color);

		void bulletPosition(sf::Vector2f);
		void fire(sf::Vector2f);
		void draw(sf::RenderTarget&);
		void destroy();

		bool isDestroyed();
};

