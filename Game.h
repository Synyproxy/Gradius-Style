#ifndef GRADIUS_GAME_H
#define GRADIUS_GAME_H

#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Input.h"
#include "Player.h"
#include "EnemyManager.h"

enum class Gamestate {RUNNING, EXIT};

namespace Gradius
{
    class Game
    {
    public:
        Game();
        ~Game();
        void Draw();
        void Update(float deltaTime);
        void Run();
        void InputListen();
        static const int SCREEN_W;
        static const int SCREEN_H;

    private:
        sf::RenderWindow window;
        BackGround *bg;
        Input *input;
        Player *player;
        EnemyManager *enemyManager;
        Gamestate state;
        sf::Clock clock;
    };
}

#endif //GRADIUS_GAME_H
