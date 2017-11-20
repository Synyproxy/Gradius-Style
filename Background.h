#ifndef GRADIUS_BACKGROUND_H
#define GRADIUS_BACKGROUND_H

#include <SFML/Graphics.hpp>

namespace Gradius
{
    class BackGround
    {
    public:
        BackGround(sf::RenderWindow *window, int SCREEN_W);
        ~BackGround();
        void Draw();
        void Update(float deltaTime);

    private:
        std::vector<sf::Sprite> parallaxSprites;
        std::vector<sf::Sprite> delayedParallax;
        sf::RenderWindow *window;
        float scrollSpeed;
        int SCREEN_W;

        sf::Texture bg_texture;
        sf::Sprite bg_sprite1;
        sf::Sprite bg_sprite2;

        sf::Texture moon_texture;
        sf::Sprite moon_sprite1;
        sf::Sprite moon_sprite2;

        sf::Texture clouds_texture;
        sf::Sprite clouds_sprite1;
        sf::Sprite clouds_sprite2;

        sf::Texture mountainfar_texture;
        sf::Sprite mountainfar_sprite1;
        sf::Sprite mountainfar_sprite2;

        sf::Texture mountains_texture;
        sf::Sprite mountains_sprite1;
        sf::Sprite mountains_sprite2;

        sf::Texture backtrees_texture;
        sf::Sprite backtrees_sprite1;
        sf::Sprite backtrees_sprite2;

        sf::Texture closetrees_texture;
        sf::Sprite closetrees_sprite1;
        sf::Sprite closetrees_sprite2;
    };
}

#endif //GRADIUS_BACKGROUND_H
