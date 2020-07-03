#include "Game.h"

Game::Game()
{
	initialization();
}

void Game::initialization()
{
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "REKT");
	window.setFramerateLimit(60);

	//Score Initialization
	kills = 0;
	
	//Font
	if (font.loadFromFile("Assets/Beon-Regular.otf") == false)
	{
		std::cout << "Font Loading Failed" << std::endl;
	}

	//Score text
	scorePosition = sf::Vector2f(325, 10);

	score.setFont(font);
	score.setCharacterSize(30);
	score.setPosition(scorePosition);
	score.setFillColor(sf::Color::White);
	score.setString("Score: 0");

	//Random number seeding
	srand(static_cast<unsigned int>(time(0)));
	spawnFrequency = 3;

	//Enemy Spawn Time 
	spawnTime1 = 3.0f;
	spawnTime2 = 5.0f;
	spawnTime3 = 10.0f;
}

void Game::gameLoop()
{
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//Rendering game
		window.clear();
		window.setView(camera.cameraView);
		window.draw(camera.background);
		window.draw(player.playerRect);
		update();
		window.draw(score);
		window.display();
	}
}

void Game::update()
{
	//Score Update
	std::stringstream scoreText;
	scoreText << "Score: " << kills;
	score.setString(scoreText.str());

	//Game Update
	camera.Cameramovement(score);
	player.movement();
	player.shoot(window);
	
	//Enemy Update
	spawnEnemy();
}

void Game::spawnEnemy()
{
	spawnType = rand() % spawnFrequency + 1;
	EnemiesBase* newEnemy;

	switch (int(spawnType))
	{
		case 1:
			if (enemyTime1.getElapsedTime().asSeconds() > spawnTime1)
			{

				newEnemy = new EnemyType1();
				newEnemy->spawn(player);
				enemiesList.push_back(newEnemy);

				enemyTime1.restart();

				break;
			}
		case 2:

			if (enemyTime2.getElapsedTime().asSeconds() > spawnTime2)
			{
				newEnemy = new EnemyType2();
				newEnemy->spawn(player);
				enemiesList.push_back(newEnemy);
				
				enemyTime2.restart();

				break;
			}
		case 3:
			if (enemyTime3.getElapsedTime().asSeconds() > spawnTime3 && kills % 10 == 0)
			{
				newEnemy = new EnemyType3();
				newEnemy->spawn(player);
				enemiesList.push_back(newEnemy);

				enemyTime3.restart();

				break;
			}
		default:
			break;
	}



	for (unsigned int i = 0; i < enemiesList.size(); i++)
	{
		//enemiesList[i]->spawn(player);
		enemiesList[i]->attack();
		enemiesList[i]->draw(window);
	}
}