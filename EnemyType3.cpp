#include "EnemyType3.h"

EnemyType3::EnemyType3()
{
	//	spawn();
	attackSpeed = 5;
	posY = 550;

	enemyState = false;
}

void EnemyType3::spawn(Player& player)
{
	enemy.setRadius(80);
	enemy.setOrigin(40, 40);
	enemy.setPosition(player.getX() + 2000, posY);
	enemy.setFillColor(sf::Color::White);
}

void EnemyType3::attack()
{

}

void EnemyType3::destroy()
{
	enemyState = true;
}

bool EnemyType3::isDestroyed()
{
	return enemyState;
}

void EnemyType3::draw(sf::RenderWindow& window)
{
	window.draw(enemy);
}