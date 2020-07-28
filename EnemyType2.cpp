#include "EnemyType2.h"

EnemyType2::EnemyType2()
{
	//	spawn();
	attackSpeed = 2;
	posY = 510;

	enemyState = false;
}

void EnemyType2::spawn(Player& player)
{
	enemy.setRadius(40);
	enemy.setOrigin(20, 20);
	enemy.setPosition(player.getX() + 2000, posY - 130);
	enemy.setFillColor(sf::Color::Green);
}

void EnemyType2::attack()
{
	if (fireTime.getElapsedTime().asSeconds() > attackSpeed/2)
	{
		EnemyBullet* newBullet = new EnemyBullet(sf::Color::Red);	
		newBullet->bulletPosition(sf::Vector2f(enemy.getPosition().x + 10, enemy.getPosition().y + 40));
		enemyBullets.push_back(newBullet);

		fireTime.restart();
	}

	/*
	for (std::vector<EnemyBullet*>::iterator itr = enemyBullets.begin(); itr != enemyBullets.end(); itr++)
	{
		if ((*itr)->bullet.getGlobalBounds().intersects(player.bulletList[i]->bullet.getGlobalBounds()))
		{
			(*itr)->destroy();
			player.bulletList[i]->destroy();
		}
	}
	*/
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

			for (auto& singleBullet : enemyBullets)
			{
				singleBullet->destroy();
			}
		}

	}

	for (unsigned int i = 0; i < enemyBullets.size(); i++)
	{
		if (enemyBullets[i]->isDestroyed())
		{
			delete enemyBullets[i];
			enemyBullets.erase(enemyBullets.begin() + i);
		}
	}

	if (enemy.getPosition().x < player.getX() - 1000)
	{
		enemyState = true;
	}
}

bool EnemyType2::isDestroyed()
{
	return enemyState;
}

void EnemyType2::draw(sf::RenderTarget& window)
{
	window.draw(enemy);

	for (unsigned int i = 0; i < enemyBullets.size(); i++)
	{
		enemyBullets[i]->fire(sf::Vector2f(0, attackSpeed*10));
		enemyBullets[i]->draw(window);
	}
}

void EnemyType2::playerCollision(Player& player)
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