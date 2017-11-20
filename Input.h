#ifndef GRADIUS_INPUT_H
#define GRADIUS_INPUT_H

#include <SFML/Graphics.hpp>

namespace Gradius
{

    enum class Inputs
    {
        IDLE,
        FIRE,
        ESCAPE
    };

    class Input
    {
    public:
        Input(sf::RenderWindow * window);
        ~Input(){}
        void EventListener();
        void Reset();
        Inputs getInputState();
        sf::Vector2f &getdir();

    private:
        Inputs input;
        sf::RenderWindow *window;
        sf::Vector2f dir;
    };
}

#endif //GRADIUS_INPUT_H
