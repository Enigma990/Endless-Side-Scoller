#include "EnemyType2.h"

EnemyType2::EnemyType2()
{
	//	spawn();
	attackSpeed = 5;
	posY = 550;

	enemyState = false;
}


void EnemyType2::spawn(Player& player)
{
	enemy.setRadius(40);
	enemy.setOrigin(20, 20);
	enemy.setPosition(player.getX() + 1000, posY);
	enemy.setFillColor(sf::Color::Green);
}

void EnemyType2::attack()
{

}

void EnemyType2::destroy()
{
	enemyState = true;
}

bool EnemyType2::isDestroyed()
{
	return enemyState;
}

void EnemyType2::draw(sf::RenderWindow& window)
{
	window.draw(enemy);
}