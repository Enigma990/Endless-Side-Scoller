#pragma once
#include<SFML/Graphics.hpp>

class Camera
{
	float cameraSpeed;

	public:
		sf::View cameraView;
	
		sf::Texture texBackground;
		sf::RectangleShape background;

		Camera();
		void Cameramovement(sf::Text&);
};

