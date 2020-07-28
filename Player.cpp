#include "Player.h"

Player::Player()
{
	moveSpeed = 10.0f;
	gravity = 10.0f;
	posX = 100;
	posY = 530;
	jumpSpeed = 10.0f;
	moveY = 0;
	jumpHeight = 380;
	bulletSpeed = 25.0f;
	fireRate = 0.5f;

	isJumping = false;
	isFiring = false;
	isAlive = true;

	//Player definition

	if (playerTexture.loadFromFile("Assets/Player Texture.jpeg") == false)
	{
		std::cerr << "Player Texture loading failed" << std::endl;
	}

	playerRect.setSize(sf::Vector2f(100, 20));
	playerRect.setPosition(sf::Vector2f(posX, posY));
	playerRect.setOrigin(sf::Vector2f(50, 10));
	playerRect.setTexture(&playerTexture);

	//Bullet sound
	if (bulletBuffer.loadFromFile("Assets/BulletSound.wav") == false)
		std::cout << "Error while loading sound";

	bulletSound.setBuffer(bulletBuffer);
}

float Player::getX()
{
	return playerRect.getPosition().x;
}

float Player::getY()
{
	return playerRect.getPosition().y;
}

sf::FloatRect Player::collider()
{
	return playerRect.getGlobalBounds();
}


void Player::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		posX += moveSpeed;
		playerRect.move(moveSpeed, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		posX -= moveSpeed;
		playerRect.move(-moveSpeed, 0);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (playerRect.getPosition().y >= posY)
		{
			isJumping = true;
			moveY = -jumpSpeed;
		}
	}

	if (isJumping)
	{
		playerRect.move(0, moveY);
		if (playerRect.getPosition().y < jumpHeight)
		{
			playerRect.setPosition(posX, jumpHeight);
			moveY = gravity;
			isJumping = false;
		}
	}
	else
	{
		playerRect.move(0, moveY);
		if (playerRect.getPosition().y >= posY)
		{
			moveY = 0;
		}
	}
}

void Player::shoot()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastFire.getElapsedTime().asSeconds() > fireRate)
	{
		isFiring = true;
		lastFire.restart();
	}
	
	if (isFiring)
	{
		Bullet* newBullet = new Bullet();
		newBullet->bulletPosition(sf::Vector2f(getX() + 50, getY()));
		bulletList.push_back(newBullet);
		isFiring = false; 
		bulletSound.play();
	}
	
	//Checking bullet condition
	for (unsigned int i = 0; i < bulletList.size(); i++)
	{
		if (bulletList[i]->bullet.getPosition().x > getX() + 800)
		{
			bulletList[i]->destroy();
		}
	}
}

void Player::dead()
{
	isAlive = false;
}

bool Player::isDead()
{
	return !isAlive;
}

void Player::reset()
{
	playerRect.setPosition(sf::Vector2f(posX, posY));
	isAlive = true;
}

void Player::draw(sf::RenderTarget& window)
{
	window.draw(playerRect);

	//Displaying bullet
	for (unsigned int i = 0; i < bulletList.size(); i++)
	{
		bulletList[i]->fire(sf::Vector2f(bulletSpeed, 0));
		bulletList[i]->draw(window);
	}
}