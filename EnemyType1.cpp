#include "EnemyType1.h"

EnemyType1::EnemyType1()
{
//	spawn();
	attackSpeed = 5;
	posY = 550;

	enemyState = false;
}

void EnemyType1::spawn(Player& player)
{
	enemy.setRadius(20);
	enemy.setOrigin(10, 10);
	enemy.setPosition(player.getX() + 600, posY);
	enemy.setFillColor(sf::Color::Yellow);
}

void EnemyType1::attack()
{
	enemy.move(-attackSpeed, 0);
}

void EnemyType1::destroy()
{
	enemyState = true;
}

bool EnemyType1::isDestroyed()
{
	return enemyState;
}

void EnemyType1::draw(sf::RenderWindow& window)
{
	window.draw(enemy);
}