#include <iostream>
#include "Input.h"

using namespace Gradius;

Input::Input(sf::RenderWindow *window)
{
    this->window = window;
    this->input = Inputs::IDLE;
    dir = sf::Vector2f(0,0);
}

void Input::EventListener()
{
    sf::Event event;

    while(this->window->pollEvent(event))
    {
        //ClosedWindow
        if(event.type == sf::Event::Closed)
            this->input = Inputs::ESCAPE;

        //Keypressed
        if(event.type == sf::Event::KeyPressed)
        {
            //PLayer Shoot
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                this->input = Inputs::FIRE;
            }
            //Movement
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                this->dir.y = -1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                this->dir.y = 1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                this->dir.x = 1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                this->dir.x = -1;
            }

        }
        //KeyRelease
        if(event.type == sf::Event::KeyReleased)
        {
            if(event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down)
            {
                this->dir.y = 0;
            }
            if(event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Left)
            {
                this->dir.x = 0;
            }
        }

    }
}

void Input::Reset()
{
    if(this->input != Inputs::ESCAPE)
        this->input = Inputs::IDLE;
}

Inputs Input::getInputState()
{
    return this->input;
}

sf::Vector2f &Input::getdir()
{
    return this->dir;
}
