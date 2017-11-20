#ifndef GRADIUS_ENEMYMANAGER_H
#define GRADIUS_ENEMYMANAGER_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Enemy.h"

namespace Gradius
{
    class EnemyManager
    {
    public:
        EnemyManager(sf::RenderWindow *window);
        ~EnemyManager(){}
        void Draw();
        void Update(float deltaTime);

    private:
        std::list<Enemy> enemyList;
        sf::RenderWindow *window;
    };
}

#endif //GRADIUS_ENEMYMANAGER_H
