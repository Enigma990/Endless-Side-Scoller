#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<vector>
#include "Bullet.h"

class Player
{
	private:

		float moveSpeed;
		float gravity;
		float posX;
		float posY;
		float jumpSpeed;
		float moveY;
		float jumpHeight;
		float bulletSpeed;
		float fireRate;

		bool isJumping;
		bool isFiring;

		sf::SoundBuffer bulletBuffer;
		sf::Sound bulletSound;
	
	public:

		sf::RectangleShape playerRect;			//Player

		std::vector<Bullet*> bulletList;
		
		sf::Clock lastFire;						


		//Player Position
		float getX();
		float getY();

		//player actions
		
		Player();

		void movement();
		void shoot(sf::RenderWindow&);
};