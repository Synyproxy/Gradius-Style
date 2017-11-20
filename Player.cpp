#include <iostream>
#include "Player.h"
#include "Projectile.h"

using namespace Gradius;

Player::Player(sf::RenderWindow *window, int SCREEN_H, int SCREEN_W)
{
    playerTexture.loadFromFile("res/Player.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(80, SCREEN_H / 2 -50);
    this->position = sf::Vector2f(80, SCREEN_H /2);
    playerSprite.scale(sf::Vector2f(2,2));

    this->life = 100;
    this->mouvementSpeed = 800.0f;
    this->window = window;
    this->screenLimit.x = SCREEN_W;
    this->screenLimit.y = SCREEN_H;
    this->projectileManager = new ProjectileManager(this->window);

}

void Player::Draw()
{
    this->window->draw(this->playerSprite);
    this->projectileManager->Draw();
}

void Player::Update(float deltaTime, sf::Vector2f dir)
{
    if(this->position.x <= 0)
    {
        this->playerSprite.move(1,0);
        this->position.x = this->playerSprite.getPosition().x;
    }
    if(this->position.x >= this->screenLimit.x - 80)
    {
        this->playerSprite.move(-1,0);
        this->position.x = this->playerSprite.getPosition().x;
    }

    if(this->position.y <= 0)
    {
        this->playerSprite.move(0,1);
        this->position.y = this->playerSprite.getPosition().y;
    }
    if(this->position.y >= this->screenLimit.y - 80)
    {
        this->playerSprite.move(0,-1);
        this->position.y = this->playerSprite.getPosition().y;
    }

    if(this->position.x >= 0 && this->position.x <= this->screenLimit.x -80
       && this->position.y >= 0 && this->position.y <= this->screenLimit.y - 80 )
    {
        this->playerSprite.move(dir.x * this->mouvementSpeed * deltaTime, dir.y * this->mouvementSpeed * deltaTime);
        this->position.x = this->playerSprite.getPosition().x;
        this->position.y = this->playerSprite.getPosition().y;
    }
    this->projectileManager->Update(deltaTime);
}

void Player::Fire()
{
    this->projectileManager->Fire(sf::Vector2f(this->position.x + 50, this->position.y  + 57));
}
