#include "Game.h"

Game::Game()
{
	initialization();
}

void Game::initialization()
{
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
	spawnTime3 = 8.0f;

	//Background Music
	if(!backgroundMusic.openFromFile("Assets/BackgroundMusic.wav"))
	{
		std::cerr << "Error while loading background audio" << std::endl;
	}
	backgroundMusic.setLoop(true);
	backgroundMusic.play();
	backgroundMusic.setPlayingOffset(sf::seconds(1.5f));
}

void Game::spawnEnemy()
{
	spawnType = rand() % spawnFrequency + 1;
	EnemiesBase* newEnemy;

	switch (spawnType)
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
}

void Game::destroyCondition()
{
	for (unsigned int i = 0; i < enemiesList.size(); i++)
	{
		enemiesList[i]->playerCollision(player);
		enemiesList[i]->destroy(player, kills);
	}

}

void Game::destroy()
{
	//Destroying enemies
	for (unsigned int i = 0; i < enemiesList.size(); i++)
	{
		if (enemiesList[i]->isDestroyed())
		{	
			delete enemiesList[i];
			enemiesList.erase(enemiesList.begin()+i);
		}
	}

	//Destroying Bullets
	for (unsigned int i = 0; i < player.bulletList.size(); i++)
	{
		if (player.bulletList[i]->isDestroyed())
		{
			std::vector<Bullet*>::iterator itr;
			itr = player.bulletList.begin();
			delete* itr;
			player.bulletList.erase(itr);
		}
	}

	if (player.getX() < camera.cameraView.getCenter().x - 600)
	{
		player.dead();
	}

}

void Game::reset()
{
	camera.cameraView.reset(sf::FloatRect(0, 0, 800, 600));
	score.setPosition(scorePosition);
	player.reset();
}

void Game::update(sf::Vector2f mPos, int& stateId)
{
	//Score Update
	currentScore.open("currentScore.txt");
	std::stringstream scoreText;
	scoreText << "Score: " << kills;
	score.setString(scoreText.str());
	currentScore << std::to_string(kills);
	currentScore.close();

	//Game Update
	camera.Cameramovement(score);
	player.movement();
	player.shoot();
	if (player.isDead())
	{
		stateId = 2;	//GameOver Menu
		reset();
	}

	//Enemy Update
	spawnEnemy();
	destroyCondition();
	destroy();
}

void Game::draw(sf::RenderTarget& window)
{
	camera.draw(window);
	window.draw(score);

	//Enemies Bullet render
	for (unsigned int i = 0; i < enemiesList.size(); i++)
	{
		enemiesList[i]->attack();
		enemiesList[i]->draw(window);
	}

	//Player render
	player.draw(window);
}
