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
	enemy.setPosition(player.getX() + 2000, posY - 20);
	enemy.setFillColor(sf::Color::Green);
}

void EnemyType2::attack()
{

}

void EnemyType2::destroy(Player& player, int& kills)
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

bool EnemyType2::isDestroyed()
{
	return enemyState;
}

void EnemyType2::draw(sf::RenderWindow& window)
{
	window.draw(enemy);
}