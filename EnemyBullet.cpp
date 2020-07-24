#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(sf::Color bulletColor)
{
	bullet.setRadius(5);
	bullet.setFillColor(bulletColor);
	bulletState = false;
}

void EnemyBullet::bulletPosition(sf::Vector2f newPos)
{
	bullet.setPosition(newPos);
}

void EnemyBullet::fire(sf::Vector2f dir)
{
	bullet.move(dir);
}

void EnemyBullet::draw(sf::RenderTarget& window)
{
	window.draw(bullet);
}

void EnemyBullet::destroy()
{
	bulletState = true;
}

bool EnemyBullet::isDestroyed()
{
	return bulletState;
}