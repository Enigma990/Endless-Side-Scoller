#pragma once
#include<SFML/Graphics.hpp>

class Camera
{
	float cameraSpeed;

	public:
		sf::View cameraView;
	
		sf::Texture texBackground;
		sf::Sprite background1;
		sf::Sprite background2;
		//sf::RectangleShape background;

		Camera();
		void Cameramovement(sf::Text&);
		void draw(sf::RenderWindow&);
};

