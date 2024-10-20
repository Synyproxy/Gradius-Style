#include "Enemy.h"
#include <cmath>
#include <iostream>

#include <ctime>

using namespace Gradius;

Enemy::Enemy(sf::RenderWindow& window) :
	window(window),
	x(0),
	mouvementSpeed(400.0f)
{
	const sf::Vector2i windowSize = window.getPosition();

	screenLimit = sf::Vector2f{
		static_cast<float>(windowSize.x),
		static_cast<float>(windowSize.y)
	};

    enemyTexture.loadFromFile("res/Enemy1.png");
    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(screenLimit.x + 100 , 400 );
    enemySprite.scale(sf::Vector2f(1.3f,1.3f));
    enemySprite.setColor(sf::Color(249, 238, 14));

	float xCenter = (enemySprite.getLocalBounds().width - enemySprite.getLocalBounds().left) / 2;
	float yCenter = (enemySprite.getLocalBounds().height - enemySprite.getLocalBounds().top) / 2;

	enemySprite.setOrigin(xCenter, yCenter);
    position.x = enemySprite.getPosition().x;
    position.y = enemySprite.getPosition().y;

    wavePeriod = 0.1f;
    waveAmplitude = 10.0f;
    active = true;
}

void Enemy::Draw() const
{
    window.draw(enemySprite);
}

void Enemy::Update(float deltaTime)
{
    if(position.x <= 0)
    {
        Randomize();
    }

    float y;

    y = static_cast<float>((-waveAmplitude * sin((x) + (screenLimit.y / 2) - 40)));
    enemySprite.move(-mouvementSpeed * deltaTime, y);
    x -= wavePeriod;
    position.x = enemySprite.getPosition().x;
    position.y = enemySprite.getPosition().y;
}

bool Enemy::isActive()
{
    return active;
}

void Enemy::Activate()
{
    active;
}

void Enemy::Randomize()
{
    //Randomize Spawn Y
    int spawnY = rand()%720+1;
    enemySprite.setPosition(screenLimit.x + 100 , static_cast<float>(spawnY));
    position.x = enemySprite.getPosition().x;
    position.y = enemySprite.getPosition().y;

    //Randomize Period
    float period = (float)(rand()%5+1)/10;
    wavePeriod = period;

    //Randomize Amplitude
    float amplitude = (float)(rand()%7+30);
    waveAmplitude = amplitude;

    //Randomize Speed
    float speed = (float)(rand()%6+3) *100;
    mouvementSpeed = speed;
}

const sf::Vector2f& Enemy::getPosition() const
{
	return position;
}
