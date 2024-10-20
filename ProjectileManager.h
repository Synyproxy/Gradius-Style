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
        ProjectileManager(sf::RenderWindow& window, const sf::Vector2f& enemyPosition);
        ~ProjectileManager(){}
        void Draw();
        void Update(float deltaTime);
        void Fire(sf::Vector2f spawnPos);
		bool didProjectileHitEnemy();
		void ResetHitEnemy();

    private:
        std::list<Projectile> projectiles;
        sf::RenderWindow& window;
		const sf::Vector2f& enemyPosition;
		bool hitEnemy;
    };
}

#endif //GRADIUS_PROJECTILEMANAGER_H
