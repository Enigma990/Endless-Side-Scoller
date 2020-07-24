#include "MainMenu.h"

MainMenu::MainMenu()
{
	if (menuFont.loadFromFile("Assets/Beon-Regular.otf") == false)
	{
		std::cerr << "Font Loading Failed" << std::endl;
	}

	//Menu Option 1
	menu[0].setFont(menuFont);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / (MAXITEMS + 1) * 1));

	//Menu Option 2
	menu[1].setFont(menuFont);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Option");
	menu[1].setPosition(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / (MAXITEMS + 1) * 2));

	//Menu Option 3
	menu[2].setFont(menuFont);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / (MAXITEMS + 1) * 3));


	//Background Image
	if (!texBackground.loadFromFile("Assets/background.jpeg"))
	{
		std::cerr << "Background Image Loading Failed" << std::endl;
	}

	background.setTextureRect(sf::IntRect(0, 0, 800, 600));
	background.setPosition(0, 0);
	background.setTexture(texBackground);

}

MainMenu::~MainMenu()
{

}

void MainMenu::update(sf::Vector2f mPos, int& stateId)
{
	for (int i = 0; i < MAXITEMS; i++)
	{
		if (menu[i].getGlobalBounds().contains(mPos))
		{
			menu[i].setFillColor(sf::Color::Red);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				switch (i)
				{
					case 0 :
						stateId = 1;
						break;

					case 2:
						stateId = -1;
						break;

					default:
						break;
				}
			}

		}
		else
		{
			menu[i].setFillColor(sf::Color::	White);
		}
	}
}

void MainMenu::draw(sf::RenderTarget& window)
{
	window.draw(background);

	for (int i = 0; i < MAXITEMS; i++)
	{
		window.draw(menu[i]);
	}
}