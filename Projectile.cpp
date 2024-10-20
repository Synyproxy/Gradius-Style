#include <iostream>
#include <cmath>
#include "Projectile.h"

using namespace Gradius;

Projectile::Projectile(sf::RenderWindow& window, sf::Vector2f spawnPos) : window(window)
{
    mouvementSpeed = 1500.0f;
	spawnPos.x += 20;
	spawnPos.y += 20;
    projectileTexture.loadFromFile("res/Projectile.png");
    projectileSprite.setTexture(projectileTexture);
    projectileSprite.setPosition(spawnPos);
    projectileSprite.scale(sf::Vector2f(3, 3));
    x = 0;
    wavePeriod = 0.5f;
    waveAmplitude = 15.0f;
    active = true;

	sf::RectangleShape rect(sf::Vector2f(40, 40));

	float x = (rect.getLocalBounds().width - rect.getLocalBounds().left) / 2;
	float y = (rect.getLocalBounds().height - rect.getLocalBounds().top) / 2;

	projectileSprite.setOrigin(x, y);

}

void Projectile::Draw() const
{
    window.draw(projectileSprite);
}

void Projectile::Update(float deltaTime)
{
    if(position.x >= 1280)
    {
        active = false;
        position.x = -420;
        position.y = -420;
        projectileSprite.setPosition(sf::Vector2f(-420, -420));
        return;
    }
    float y;

    y = static_cast<float>((waveAmplitude * sin((x) + (screenLimit.y / 2) - 40)));
    projectileSprite.move( mouvementSpeed * deltaTime, y);
    x -= wavePeriod;
    position.x = projectileSprite.getPosition().x;
    position.y = projectileSprite.getPosition().y;
}

bool Projectile::isActive() const
{
    return active;
}

void Projectile::Activate(sf::Vector2f spawnPos)
{
	spawnPos.x += 20;
	spawnPos.y += 20;
    projectileSprite.setPosition(spawnPos);
    position.x = projectileSprite.getPosition().x;
    position.y = projectileSprite.getPosition().y;
    active = true;
}

const sf::Sprite& Projectile::getProjectileSprite() const
{
	return projectileSprite;
}