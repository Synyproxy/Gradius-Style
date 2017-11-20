#ifndef GRADIUS_PLAYER_H
#define GRADIUS_PLAYER_H

#include <SFML/Graphics.hpp>
#include "ProjectileManager.h"

namespace Gradius
{
    class Player
    {
    public:
        Player(sf::RenderWindow *window, int SCREEN_H, int SCREEN_W);
        ~Player(){}
        void Draw();
        void Update(float deltaTime, sf::Vector2f dir);
        void Fire();

    private:
        int life;
        float mouvementSpeed;
        sf::RenderWindow *window;
        sf::Vector2f position;
        sf::Vector2f screenLimit;
        sf::Texture playerTexture;
        sf::Sprite playerSprite;
        ProjectileManager *projectileManager;

    };
}

#endif //GRADIUS_PLAYER_H
