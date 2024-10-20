#include "EnemyManager.h"

using namespace Gradius;

#include <cassert>

EnemyManager::EnemyManager(sf::RenderWindow& window) : window(window)
{
	enemies.emplace_back(window);
}

void EnemyManager::Draw() const
{
    for (auto& enemy : enemies) {
		enemy.Draw();
	}
}

void EnemyManager::Update(float deltaTime)
{
	for (auto& enemy : enemies) {
		enemy.Update(deltaTime);
	}
}

const sf::Vector2f& EnemyManager::getEnemyPosition() const
{
	assert(enemies.size() > 0, && "There is no enemy!!!");
	return enemies.front().getPosition();
}

void EnemyManager::Randomize()
{
	for (auto& enemy : enemies) {
		enemy.Randomize();
	}
}
