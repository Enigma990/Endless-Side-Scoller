#include "EnemyType1.h"

EnemyType1::EnemyType1()
{
//	spawn();
	attackSpeed = 10;
	posY = 550;

	enemyState = false;
}

void EnemyType1::spawn(Player& player)
{
	enemy.setRadius(20);
	enemy.setOrigin(10, 10);
	enemy.setPosition(player.getX() + 1000, posY);
	enemy.setFillColor(sf::Color::Yellow);
}

void EnemyType1::attack()
{
	enemy.move(-attackSpeed, 0);
}

void EnemyType1::destroy(Player& player, int& kills)
{
	for (unsigned int i = 0; i < player.bulletList.size(); i++)
	{
		if (enemy.getGlobalBounds().intersects(player.bulletList[i]->bullet.getGlobalBounds()))
		{
			enemyState = true;
			player.bulletList[i]->destroy();
			kills++;
		}
	}

	if (enemy.getPosition().x < player.getX() - 500)
	{
		enemyState = true;
	}
}

bool EnemyType1::isDestroyed()
{
	return enemyState;
}

void EnemyType1::draw(sf::RenderTarget& window)
{
	window.draw(enemy);
}

void EnemyType1::playerCollision(Player& player)
{
	if (enemy.getGlobalBounds().intersects(player.collider()))
	{
		player.dead();
	}
}