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
	enemy.setPosition(player.getX() + 1000, posY - 80);
	enemy.setFillColor(sf::Color::White);
}

void EnemyType3::attack()
{

}

void EnemyType3::destroy(Player& player, int& kills)
{
	for (unsigned int i = 0; i < player.bulletList.size(); i++)
	{
		if (enemy.getGlobalBounds().intersects(player.bulletList[i]->bullet.getGlobalBounds()))
		{
			enemyState = true;
			player.bulletList[i]->destroy();
			kills++;
		}

		if (enemy.getPosition().x < player.getX() - 1000)
		{
			enemyState = true;
		}
	}
}

bool EnemyType3::isDestroyed()
{
	return enemyState;
}

void EnemyType3::draw(sf::RenderWindow& window)
{
	window.draw(enemy);
}