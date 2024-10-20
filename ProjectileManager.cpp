#include "ProjectileManager.h"
#include <iostream>

using namespace Gradius;

ProjectileManager::ProjectileManager(sf::RenderWindow& window, const sf::Vector2f& enemyPosition):
	window {window},
	enemyPosition {enemyPosition},
	hitEnemy {false}
{
}

void ProjectileManager::Draw()
{
	for (const auto& projectile : projectiles)
	{
		if (projectile.isActive())
		{
			projectile.Draw();
		}
	}
}

void ProjectileManager::Update(float deltaTime)
{
	for (auto& projectile : projectiles)
    {
        if(projectile.isActive() && !hitEnemy)
        {
			sf::RectangleShape rect(sf::Vector2f(50, 50));

			float x = (rect.getLocalBounds().width - rect.getLocalBounds().left) / 2;
			float y = (rect.getLocalBounds().height - rect.getLocalBounds().top) / 2;

			rect.setOrigin(x, y);
			rect.setPosition(enemyPosition.x, enemyPosition.y);
			rect.setFillColor(sf::Color::Red);
			window.draw(rect);
			if (projectile.getProjectileSprite().getGlobalBounds().intersects(rect.getGlobalBounds()))
			{
				hitEnemy = true;
			}
			
			projectile.Update(deltaTime);
        }
    }
}

void ProjectileManager::Fire(sf::Vector2f spawnPos)
{
    for (auto& projectile : projectiles)
    {
        if (!projectile.isActive())
        {
            projectile.Activate(spawnPos);
            return;
        }
    }

    projectiles.emplace_back(window, spawnPos);
}

bool ProjectileManager::didProjectileHitEnemy()
{
	return hitEnemy;
}

void ProjectileManager::ResetHitEnemy()
{
	hitEnemy = false;
}
