#pragma once
#include<SFML/Graphics.hpp>

class Bullet
{
	public:

		sf::RectangleShape bullet;

		bool bulletState;

		//Bullet Functions

		Bullet();

		void bulletPosition(sf::Vector2f);
		void fire(sf::Vector2f);
		void draw(sf::RenderTarget&);
		void destroy();

		bool isDestroyed();
};