#include <iostream>
#include "Background.h"

using namespace Gradius;

BackGround::BackGround(sf::RenderWindow *window, int SCREEN_W)
{

    this->SCREEN_W = SCREEN_W;
    sf::Vector2f initialPos = sf::Vector2f(0,0);
    sf::Vector2f delayedPos = sf::Vector2f(SCREEN_W,0);

    //bg
    bg_texture.loadFromFile("res/1bg.png");
    bg_sprite1.setTexture(bg_texture);
    bg_sprite1.setPosition(initialPos);
    parallaxSprites.push_back(bg_sprite1);
    bg_sprite2.setTexture(bg_texture);
    bg_sprite2.setPosition(delayedPos);
    delayedParallax.push_back(bg_sprite2);

    //moon
    moon_texture.loadFromFile("res/2moon.png");
    moon_sprite1.setTexture(moon_texture);
    moon_sprite1.setPosition(initialPos);
    moon_sprite1.setColor(sf::Color(240, 175, 255));
    parallaxSprites.push_back(moon_sprite1);
    moon_sprite2.setTexture(moon_texture);
    moon_sprite2.setPosition(sf::Vector2f(this->SCREEN_W + 500, 0));
    delayedParallax.push_back(moon_sprite2);

    //clouds
    clouds_texture.loadFromFile("res/3clouds.png");
    clouds_sprite1.setTexture(clouds_texture);
    clouds_sprite1.setPosition(initialPos);
    parallaxSprites.push_back(clouds_sprite1);
    clouds_sprite2.setTexture(clouds_texture);
    clouds_sprite2.setPosition(delayedPos);
    delayedParallax.push_back(clouds_sprite2);

    //mountainfar
    mountainfar_texture.loadFromFile("res/4mountainfar.png");
    mountainfar_sprite1.setTexture(mountainfar_texture);
    mountainfar_sprite1.setPosition(initialPos);
    parallaxSprites.push_back(mountainfar_sprite1);
    mountainfar_sprite2.setTexture(mountainfar_texture);
    mountainfar_sprite2.setPosition(delayedPos);
    delayedParallax.push_back(mountainfar_sprite2);

    //mountains
    mountains_texture.loadFromFile("res/5mountains.png");
    mountains_sprite1.setTexture(mountains_texture);
    mountains_sprite1.setPosition(initialPos);
    parallaxSprites.push_back(mountains_sprite1);
    mountains_sprite2.setTexture(mountains_texture);
    mountains_sprite2.setPosition(delayedPos);
    delayedParallax.push_back(mountains_sprite2);

    //backtrees
    backtrees_texture.loadFromFile("res/6backtrees.png");
    backtrees_sprite1.setTexture(backtrees_texture);
    backtrees_sprite1.setPosition(initialPos);
    parallaxSprites.push_back(backtrees_sprite1);
    backtrees_sprite2.setTexture(backtrees_texture);
    backtrees_sprite2.setPosition(delayedPos);
    delayedParallax.push_back(backtrees_sprite2);

    //closetrees
    closetrees_texture.loadFromFile("res/7closetrees.png");
    closetrees_sprite1.setTexture(closetrees_texture);
    closetrees_sprite1.setPosition(initialPos);
    parallaxSprites.push_back(closetrees_sprite1);
    closetrees_sprite2.setTexture(closetrees_texture);
    closetrees_sprite2.setPosition(delayedPos);
    delayedParallax.push_back(closetrees_sprite2);


    this->window = window;
    this->scrollSpeed = 80.0f;
}

void BackGround::Draw()
{
    std::vector<sf::Sprite>::iterator it1 = parallaxSprites.begin();
    std::vector<sf::Sprite>::iterator it2 = delayedParallax.begin();

    while (it1 != parallaxSprites.end())
    {
        this->window->draw(*it1);
        this->window->draw(*it2);
        ++it1;
        ++it2;
    }
}

void BackGround::Update(float deltaTime)
{
    std::vector<sf::Sprite>::iterator it1 = parallaxSprites.begin();
    std::vector<sf::Sprite>::iterator it2 = delayedParallax.begin();

    float parallax = 0.5f;
    float parallaxOffset = 0.8f;

    while (it1 != parallaxSprites.end())
    {
        if(it1->getPosition().x < -this->SCREEN_W)
            it1->setPosition(sf::Vector2f(this->SCREEN_W-1,0));

        if(it2->getPosition().x < -this->SCREEN_W)
            it2->setPosition(sf::Vector2f(this->SCREEN_W-1,0));

        it1->setPosition(it1->getPosition().x - (this->scrollSpeed * deltaTime * parallax), it1->getPosition().y);
        it2->setPosition(it2->getPosition().x - (this->scrollSpeed * deltaTime * parallax), it1->getPosition().y);

        parallax /= parallaxOffset;

        ++it1;
        ++it2;
    }
}

BackGround::~BackGround()
{
    //if(this->window != nullptr)
        //delete this->window;
}
