#ifndef GRADIUS_ENEMYMANAGER_H
#define GRADIUS_ENEMYMANAGER_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Enemy.h"

namespace Gradius
{
    class EnemyManager
    {
    public:
        EnemyManager(sf::RenderWindow& window);
        ~EnemyManager(){}
        void Draw() const;
        void Update(float deltaTime);
		const sf::Vector2f& getEnemyPosition() const;
		void Randomize();

    private:
        sf::RenderWindow& window;
        std::vector<Enemy> enemies;
    };
}

#endif //GRADIUS_ENEMYMANAGER_H
