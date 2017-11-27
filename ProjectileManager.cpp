#include "ProjectileManager.h"
#include <iostream>

using namespace Gradius;

ProjectileManager::ProjectileManager(sf::RenderWindow *window, sf::Vector2f *enemyPosition):
	window {window},
	enemyPosition {enemyPosition},
	hitEnemy {false}
{
}

void ProjectileManager::Draw()
{
    if(projectileList.empty())
        return;
    std::list<Projectile>::iterator it = projectileList.begin();

    while (it != projectileList.end())
    {
        if(it->isActive())
            it->Draw();
        ++it;
    }
}

void ProjectileManager::Update(float deltaTime)
{
    if(projectileList.empty())
        return;
    std::list<Projectile>::iterator it = projectileList.begin();

    while (it != projectileList.end())
    {
        if(it->isActive() && !hitEnemy)
        {
			sf::RectangleShape rect(sf::Vector2f(50, 50));

			float x = (rect.getLocalBounds().width - rect.getLocalBounds().left) / 2;
			float y = (rect.getLocalBounds().height - rect.getLocalBounds().top) / 2;

			rect.setOrigin(x, y);
			rect.setPosition((*enemyPosition).x, (*enemyPosition).y);
			rect.setFillColor(sf::Color::Red);
			this->window->draw(rect);
			if(it->getProjectileSprite().getGlobalBounds().intersects(rect.getGlobalBounds()))
				hitEnemy = true;
			
			it->Update(deltaTime);
        }
            
        ++it;
    }
}

void ProjectileManager::Fire(sf::Vector2f spawnPos)
{
	
	std::list<Projectile>::iterator it = projectileList.begin();

	while (it != projectileList.end())
	{
		if (!it->isActive())
		{
			it->Activate(spawnPos);
			return;
		}
		++it;
	}
	Projectile *newProjectile = new Projectile(this->window, spawnPos);
	projectileList.push_back(*newProjectile);
		
}

bool ProjectileManager::didProjectileHitEnemy()
{
	return this->hitEnemy;
}

void ProjectileManager::ResetHitEnemy()
{
	this->hitEnemy = false;
}
