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

	sf::Vector2f horizontal;
	sf::Vector2f vertical;

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
				vertical.y = -1;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				horizontal.y = 1;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				vertical.x = -1;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				horizontal.x = 1;
			

        }
        //KeyRelease
        if(event.type == sf::Event::KeyReleased)
        {
            if(event.key.code == sf::Keyboard::Up)
                vertical.y = 0;

			if (event.key.code == sf::Keyboard::Down)
				horizontal.y = 0;

			if (event.key.code == sf::Keyboard::Left)
				vertical.x = 0;
			if (event.key.code == sf::Keyboard::Right)
				horizontal.x = 0;
        }
		dir = vertical + horizontal;
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
