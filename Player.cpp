#include "Player.h"
#include <iostream>

using namespace Gradius;

Player::Player(sf::RenderWindow& window, const sf::Vector2f& enemyPosition) :
	window {window},
	playerAttackCoolDown{ 0.2f },
	enemyPosition {enemyPosition},
	playerHitEnemy {false}
{
	const float screenWidth = static_cast<float>(window.getSize().x);
	const float screenHeight = static_cast<float>(window.getSize().y);
	const float halfScreenWidth = screenWidth / 2.0f;
	const float halfScreenHeight = screenHeight / 2.0f;

    playerTexture.loadFromFile("res/Player.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(80, halfScreenWidth - 50);
    position = sf::Vector2f(80, halfScreenHeight);
    playerSprite.scale(sf::Vector2f(2,2));

	playerScore = 0;
    mouvementSpeed = 800.0f;
	screenLimit = sf::Vector2f{ screenWidth, screenHeight };
    projectileManager = new ProjectileManager(window, enemyPosition);
	playerClock.restart();
}

void Player::Draw()
{
	projectileManager->Draw();
    window.draw(playerSprite);
}

void Player::Update(float deltaTime, sf::Vector2f dir)
{
	sf::RectangleShape rect(sf::Vector2f(50, 50));

	float x = (rect.getLocalBounds().width - rect.getLocalBounds().left) / 2;
	float y = (rect.getLocalBounds().height - rect.getLocalBounds().top) / 2;

	rect.setOrigin(x, y);
	rect.setPosition(enemyPosition.x, enemyPosition.y);

	if (playerSprite.getGlobalBounds().intersects(rect.getGlobalBounds()))
		playerScore = 0;

	if(projectileManager->didProjectileHitEnemy())
	{
		playerHitEnemy = true;
		playerScore += 10;
		projectileManager->ResetHitEnemy();
	}
    if(position.x <= 0)
    {
        playerSprite.move(1,0);
        position.x = playerSprite.getPosition().x;
    }
    if(position.x >= screenLimit.x - 80)
    {
        playerSprite.move(-1,0);
        position.x = playerSprite.getPosition().x;
    }

    if(position.y <= 0)
    {
        playerSprite.move(0,1);
        position.y = playerSprite.getPosition().y;
    }
    if(position.y >= screenLimit.y - 80)
    {
        playerSprite.move(0,-1);
        position.y = playerSprite.getPosition().y;
    }

    if(position.x >= 0 && position.x <= screenLimit.x -80
       && position.y >= 0 && position.y <= screenLimit.y - 80 )
    {
        playerSprite.move(dir.x * mouvementSpeed * deltaTime, dir.y * mouvementSpeed * deltaTime);
        position.x = playerSprite.getPosition().x;
        position.y = playerSprite.getPosition().y;
    }
    projectileManager->Update(deltaTime);
}

void Player::Fire()
{
	if (playerClock.getElapsedTime().asSeconds() > playerAttackCoolDown)
	{
		projectileManager->Fire(sf::Vector2f(position.x + 50, position.y + 57));
		playerClock.restart();
	}
}

int Player::getPlayerScore()
{
	return playerScore;
}

bool Player::didPlayerHitEnemy()
{
	return playerHitEnemy;
}

void Player::resetPlayerHitEnemy()
{
	playerHitEnemy = false;
}
