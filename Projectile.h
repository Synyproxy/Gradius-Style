#ifndef GRADIUS_PROJECTILE_H
#define GRADIUS_PROJECTILE_H

#include <SFML/Graphics.hpp>

namespace Gradius
{
    class Projectile
    {
    public:
        Projectile(sf::RenderWindow *window, sf::Vector2f spawnPos);
        ~Projectile(){}
        void Draw();
        void Update(float deltaTime);
        bool isActive();
        void Activate(sf::Vector2f spawnPos);

    private:
        bool active;
        float x;
        float wavePeriod;
        float waveAmplitude;
        float mouvementSpeed;
        sf::RenderWindow *window;
        sf::Vector2f position;
        sf::Vector2f screenLimit;
        sf::Texture projectileTexture;
        sf::Sprite projectileSprite;
    };
}

#endif //GRADIUS_PROJECTILE_H
