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
		virtual ~Game() = default;
        void Draw();
        void Update(float deltaTime);
        void Run();
        void InputListen();

    private:
        sf::RenderWindow window;
        BackGround bg;
        Input input;
        EnemyManager enemyManager;
        Player player;
        Gamestate state;
        sf::Clock clock;
		sf::Font font;
		sf::Text text;
    };
}

#endif //GRADIUS_GAME_H
