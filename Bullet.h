#pragma once
#include<SFML/Graphics.hpp>
#include<vector>

class Bullet
{
	public:

		sf::RectangleShape bullet;

		bool bulletState;

		//Bullet Functions

		Bullet();

		void bulletPosition(sf::Vector2f);
		void fire(sf::Vector2f);
		void draw(sf::RenderWindow&);
		void destroy();

		bool isDestroyed();
};