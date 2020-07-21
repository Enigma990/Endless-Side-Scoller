#include "MainMenu.h"

MainMenu::MainMenu()
{
	if (menuFont.loadFromFile("Assets/Beon-Regular.otf") == false)
	{
		std::cerr << "Font Loading Failed" << std::endl;
	}

	//Menu Option 1
	menu[0].setFont(menuFont);
	menu[0].setFillColor(sf::Color::Red);
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

	update();
}

MainMenu::~MainMenu()
{

}

void MainMenu::update()
{
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "REKT");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::W:

						if (selectedItem > 0)
						{
							menu[selectedItem].setFillColor(sf::Color::White);
							selectedItem--;
							menu[selectedItem].setFillColor(sf::Color::Red);
						}
						break;

					case sf::Keyboard::D:

						if (selectedItem + 1 < MAXITEMS)
						{
							menu[selectedItem].setFillColor(sf::Color::White);
							selectedItem++;
							menu[selectedItem].setFillColor(sf::Color::Red);
						}
						break;


					default:
						break;
				}
			}

		}

	}

}

void MainMenu::draw()
{
	for (int i = 0; i < MAXITEMS; i++)
	{
		window.draw(menu[i]);
	}
}