#include "Input.h"

using namespace Gradius;

Input::Input(sf::RenderWindow& window) : window(window)
{
    input = Inputs::IDLE;
    dir = sf::Vector2f(0,0);
}

void Input::EventListener()
{
    sf::Event event;

	sf::Vector2f horizontal{ 0.0f, 0.0f };
	sf::Vector2f vertical{ 0.0f, 0.0f };

	while (window.pollEvent(event))
	{
		//ClosedWindow
		if (event.type == sf::Event::Closed)
			input = Inputs::ESCAPE;
	}

    //Player Shoot
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        input = Inputs::FIRE;
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

	dir = vertical + horizontal;
}

void Input::Reset()
{
    if(input != Inputs::ESCAPE)
        input = Inputs::IDLE;
}

Inputs Input::getInputState()
{
    return input;
}

sf::Vector2f &Input::getdir()
{
    return dir;
}
