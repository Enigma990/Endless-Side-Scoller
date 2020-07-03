#include "Camera.h"


Camera::Camera()
{
	cameraSpeed = 2.5f;

	// Camera properties
	cameraView.setSize(800, 600);
	cameraView.setCenter(400, 300);
	
	// Background properties
	texBackground.loadFromFile("Assets/background.png");
	
	background.setSize(sf::Vector2f(800, 600));
	background.setPosition(0, 0);
	background.setTexture(&texBackground);
}

void Camera::Cameramovement(sf::Text& score)
{
	cameraView.move(cameraSpeed, 0);
	score.move(cameraSpeed, 0);
//	background.move(cameraSpeed, 0);
}