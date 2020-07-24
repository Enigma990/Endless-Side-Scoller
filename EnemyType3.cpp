#include "EnemyType3.h"

EnemyType3::EnemyType3()
{
	//	spawn();
	attackSpeed = 5;
	posY = 550;
	health = 3;

	enemyState = false;
}

void EnemyType3::spawn(Player& player)
{
	enemy.setRadius(80);
	enemy.setOrigin(40, 40);
	enemy.setPosition(player.getX() + 3000, posY - 80);
	enemy.setFillColor(sf::Color::White);
}

void EnemyType3::attack()
{
	if (fireTime.getElapsedTime().asSeconds() > attackSpeed)
	{
		EnemyBullet* newBullet = new EnemyBullet(sf::Color::White);
		newBullet->bulletPosition(sf::Vector2f(enemy.getPosition().x, posY));
		enemyBullets.push_back(newBullet);

		fireTime.restart();
	}
}

void EnemyType3::destroy(Player& player, int& kills)
{
	for (unsigned int i = 0; i < player.bulletList.size(); i++)
	{
		if (enemy.getGlobalBounds().intersects(player.bulletList[i]->bullet.getGlobalBounds()))
		{
			if (health == 0)
			{
				enemyState = true;
				player.bulletList[i]->destroy();
				kills++;
			}
			else
			{
				health--;
				player.bulletList[i]->destroy();
			}
		}

		for (auto& singleBullet : enemyBullets)
		{
			if (singleBullet->bullet.getGlobalBounds().intersects(player.bulletList[i]->bullet.getGlobalBounds()))
			{
				player.bulletList[i]->destroy();
			}
		}
	}

	if (enemy.getPosition().x < player.getX() - 1000)
	{
		enemyState = true;
	}
}

bool EnemyType3::isDestroyed()
{
	return enemyState;
}

void EnemyType3::draw(sf::RenderTarget& window)
{
	window.draw(enemy);

	for (auto& singleBullet : enemyBullets)
	{
		singleBullet->fire(sf::Vector2f(-attackSpeed, 0));
		singleBullet->draw(window);
	}
}

void EnemyType3::playerCollision(Player& player)
{
	//Bullet Collision
	for (auto& singleBullet : enemyBullets)
	{
		if (singleBullet->bullet.getGlobalBounds().intersects(player.collider()))
		{
			player.dead();
		}

		else
		{
			for (unsigned int i = 0; i < player.bulletList.size(); i++)
			{
				if (singleBullet->bullet.getGlobalBounds().intersects(player.bulletList[i]->bullet.getGlobalBounds()))
				{
					player.bulletList[i]->destroy();
				}
			}
		}
	}

	//Enemy Collision
	if (enemy.getGlobalBounds().intersects(player.collider()))
	{
		player.dead();
	}
}