#pragma once
#include<SFML/Graphics.hpp>

class State
{
	public:

		virtual void update(sf::Vector2f mPos, int& stateId) = 0;
		virtual void draw(sf::RenderTarget& target) = 0;
};