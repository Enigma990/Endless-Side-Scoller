#include "Camera.h"


Camera::Camera()
{
	cameraSpeed = 2.5f;

	// Camera properties
	cameraView.setSize(800, 600);
	cameraView.setCenter(400, 300);
	
	// Background properties
	texBackground.loadFromFile("Assets/background.jpeg");
	
	background1.setTextureRect(sf::IntRect(0,0,800, 600));
	background1.setPosition(0, 0);
	background1.setTexture(texBackground);

	background2.setTextureRect(sf::IntRect(0, 0, 800, 600));
	background2.setPosition(800,0);
	background2.setTexture(texBackground);
}

void Camera::Cameramovement(sf::Text& score, sf::RectangleShape& pauseButton)
{
	cameraView.move(cameraSpeed, 0);
	score.move(cameraSpeed, 0);
	pauseButton.move(cameraSpeed, 0);

	if (background2.getPosition().x + 400 == cameraView.getCenter().x)
	{
		background1.setPosition(cameraView.getCenter().x + 400, 0);
	}

	if (background1.getPosition().x + 400 == cameraView.getCenter().x)
	{
		background2.setPosition(cameraView.getCenter().x + 400, 0);
	}

}

void Camera::draw(sf::RenderTarget& window)
{
	window.setView(cameraView);
	window.draw(background1);
	window.draw(background2);
}