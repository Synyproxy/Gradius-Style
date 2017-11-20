#ifndef GRADIUS_PROJECTILEMANAGER_H
#define GRADIUS_PROJECTILEMANAGER_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Projectile.h"

namespace Gradius
{
    class ProjectileManager
    {
    public:
        ProjectileManager(sf::RenderWindow *window);
        ~ProjectileManager(){}
        void Draw();
        void Update(float deltaTime);
        void Fire(sf::Vector2f spawnPos);

    private:
        std::list<Projectile> projectileList;
        sf::RenderWindow *window;
    };
}

#endif //GRADIUS_PROJECTILEMANAGER_H
