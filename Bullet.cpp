#include "Bullet.h"

Bullet::Bullet()
{
	bullet.setSize(sf::Vector2f(10.0f, 5.0f));
	bullet.setFillColor(sf::Color::Red);
	bulletState = false;
}

void Bullet::bulletPosition(sf::Vector2f newPos)
{
	bullet.setPosition(newPos);
}

void Bullet::fire(sf::Vector2f dir)
{
	bullet.move(dir);
}

void Bullet::draw(sf::RenderWindow& window)
{
	window.draw(bullet);
}

void Bullet::destroy()
{
	bulletState = true;
}

bool Bullet::isDestroyed()
{
	return bulletState;
}