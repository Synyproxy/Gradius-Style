#include "Enemy.h"
#include <cmath>
#include <iostream>

#include <ctime>

using namespace Gradius;

Enemy::Enemy(sf::RenderWindow *window, int SCREEN_H, int SCREEN_W)
{
    this->window = window;
    this->screenLimit.x = SCREEN_H;
    this->screenLimit.y = SCREEN_W;
    this->x = 0;
    this->mouvementSpeed = 400.0f;

    enemyTexture.loadFromFile("res/Enemy1.png");
    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(this->screenLimit.x + 100 , 400 );
    enemySprite.scale(sf::Vector2f(1.3f,1.3f));
    enemySprite.setColor(sf::Color(249, 238, 14));

	float xCenter = (enemySprite.getLocalBounds().width - enemySprite.getLocalBounds().left) / 2;
	float yCenter = (enemySprite.getLocalBounds().height - enemySprite.getLocalBounds().top) / 2;

	this->enemySprite.setOrigin(xCenter, yCenter);
    this->position.x = enemySprite.getPosition().x;
    this->position.y = enemySprite.getPosition().y;

    this->wavePeriod = 0.1f;
    this->waveAmplitude = 10.0f;
    this->active = true;
}

void Enemy::Draw()
{
    this->window->draw(this->enemySprite);
}

void Enemy::Update(float deltaTime)
{
    if(this->position.x <= 0)
    {
        Randomize();
    }

    float y;

    y = static_cast<float>((-this->waveAmplitude * sin((this->x) + (this->screenLimit.y / 2) - 40)));
    this->enemySprite.move(-this->mouvementSpeed * deltaTime, y);
    x -= this->wavePeriod;
    this->position.x = this->enemySprite.getPosition().x;
    this->position.y = this->enemySprite.getPosition().y;
}

bool Enemy::isActive()
{
    return this->active;
}

void Enemy::Activate()
{
    this->active;
}

void Enemy::Randomize()
{
    //Randomize Spawn Y
    int spawnY = rand()%720+1;
    this->enemySprite.setPosition(this->screenLimit.x + 100 , spawnY );
    this->position.x = this->enemySprite.getPosition().x;
    this->position.y = this->enemySprite.getPosition().y;

    //Randomize Period
    float period = (float)(rand()%5+1)/10;
    this->wavePeriod = period;

    //Randomize Amplitude
    float amplitude = (float)(rand()%7+30);
    this->waveAmplitude = amplitude;

    //Randomize Speed
    float speed = (float)(rand()%6+3) *100;
    this->mouvementSpeed = speed;
}

sf::Vector2f* Enemy::getEnemyPosition()
{
	return &this->position;
}
