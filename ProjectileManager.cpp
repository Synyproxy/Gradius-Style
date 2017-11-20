#include <iostream>
#include "ProjectileManager.h"

using namespace Gradius;

ProjectileManager::ProjectileManager(sf::RenderWindow *window)
{
    this->window = window;
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
        if(it->isActive())
            it->Update(deltaTime);
        ++it;
    }
}

void ProjectileManager::Fire(sf::Vector2f spawnPos)
{
    std::list<Projectile>::iterator it = projectileList.begin();

    while(it != projectileList.end())
    {
        if(!it->isActive())
        {
            it->Activate(spawnPos);
            return;
        }
        ++it;
    }
    Projectile *newProjectile = new Projectile(this->window, spawnPos);
    projectileList.push_back(*newProjectile);
}
