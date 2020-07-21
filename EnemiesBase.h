#pragma once
#include<SFML/Graphics.hpp>
#include "Player.h"

class EnemiesBase
{
	public:

		virtual void spawn(Player&) = 0;
		virtual void attack() = 0;
		virtual void destroy(Player&, int&) = 0;
		virtual void draw(sf::RenderWindow&) = 0;
		virtual void playerCollision(Player&) = 0;

		virtual bool isDestroyed() = 0;
};

