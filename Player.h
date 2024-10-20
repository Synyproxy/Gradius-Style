#ifndef GRADIUS_PLAYER_H
#define GRADIUS_PLAYER_H

#include <SFML/Graphics.hpp>
#include "ProjectileManager.h"

namespace Gradius
{
    class Player
    {
    public:
        Player(sf::RenderWindow& window, const sf::Vector2f& enemyPosition);
        ~Player(){}
        void Draw();
        void Update(float deltaTime, sf::Vector2f dir);
        void Fire();
		int getPlayerScore();
		bool didPlayerHitEnemy();
		void resetPlayerHitEnemy();

    private:
        int playerScore;
        float mouvementSpeed;
        sf::RenderWindow& window;
        sf::Vector2f position;
        sf::Vector2f screenLimit;
        sf::Texture playerTexture;
        sf::Sprite playerSprite;
        ProjectileManager *projectileManager;
		sf::Clock playerClock;
		float playerAttackCoolDown;
		const sf::Vector2f& enemyPosition;
		bool playerHitEnemy;
    };
}

#endif //GRADIUS_PLAYER_H
