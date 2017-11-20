#include <iostream>
#include <cmath>
#include "Projectile.h"

using namespace Gradius;

Projectile::Projectile(sf::RenderWindow *window, sf::Vector2f spawnPos)
{
    this->window = window;
    this->mouvementSpeed = 1500.0f;

    this->projectileTexture.loadFromFile("res/Projectile.png");
    this->projectileSprite.setTexture(projectileTexture);
    this->projectileSprite.setPosition(spawnPos);
    this->projectileSprite.scale(sf::Vector2f(3, 3));
    this->projectileSprite.rotate(-90);
    this->x = 0;
    this->wavePeriod = 0.5f;
    this->waveAmplitude = 15.0f;
    this->active = true;
}

void Projectile::Draw()
{
    this->window->draw(this->projectileSprite);
}

void Projectile::Update(float deltaTime)
{
    if(this->position.x >= 1280)
    {
        this->active = false;
        this->position.x = -420;
        this->position.y = -420;
        this->projectileSprite.setPosition(sf::Vector2f(-420, -420));
        return;
    }
    float y;

    y = static_cast<float>((this->waveAmplitude * sin((this->x) + (this->screenLimit.y / 2) - 40)));
    this->projectileSprite.move( this->mouvementSpeed * deltaTime, y);
    x -= this->wavePeriod;
    this->position.x = this->projectileSprite.getPosition().x;
    this->position.y = this->projectileSprite.getPosition().y;
}

bool Projectile::isActive()
{
    return this->active;
}

void Projectile::Activate(sf::Vector2f spawnPos)
{
    this->projectileSprite.setPosition(spawnPos);
    this->position.x = this->projectileSprite.getPosition().x;
    this->position.y = this->projectileSprite.getPosition().y;
    this->active = true;
}
