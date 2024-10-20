#include "Game.h"

using namespace Gradius;

constexpr uint32_t kScreenWidth = 1280;
constexpr uint32_t kScreenHeight = 720;

Game::Game():
	window {sf::VideoMode(kScreenWidth, kScreenHeight), "GRADIUS"},
	bg{ window },
	input{ window },
	enemyManager{ window },
	player{ window, enemyManager.getEnemyPosition() }
{
    srand(static_cast<unsigned int>(time(nullptr)));
    state = Gamestate::RUNNING;
    window.setFramerateLimit(60);

	font.loadFromFile("res/game_over.ttf");
	text.setFont(font);
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::White);
	sf::FloatRect bound = text.getLocalBounds();
	text.setStyle(sf::Text::Regular);
	text.setPosition(0, 0);
}

void Game::Draw()
{
    window.clear();
    bg.Draw();
    player.Draw();
    enemyManager.Draw();
	window.draw(text);
    window.display();
}

void Game::Update(float deltaTime)
{
    bg.Update(deltaTime);
    player.Update(deltaTime, input.getdir());

	//When player Hits an enemy, enemy respawns with some rand values
	if (player.didPlayerHitEnemy())
	{
		enemyManager.Randomize();
		player.resetPlayerHitEnemy();
	}
    enemyManager.Update(deltaTime);
	text.setString("Score: " + std::to_string(player.getPlayerScore()));
}

void Game::Run()
{
    float deltaTime = 0;
    while(state != Gamestate::EXIT && input.getInputState() != Inputs::ESCAPE)
    {
        InputListen();
        Update(deltaTime);
        Draw();
        input.Reset();
        deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();
    }
}

void Game::InputListen()
{
    input.EventListener();

    if(input.getInputState() == Inputs::ESCAPE)
    {
        window.close();
    }
    if(input.getInputState() == Inputs::FIRE)
    {
        player.Fire();
    }
}
