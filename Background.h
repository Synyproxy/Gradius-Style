#ifndef GRADIUS_BACKGROUND_H
#define GRADIUS_BACKGROUND_H

#include <SFML/Graphics.hpp>

namespace Gradius
{
	struct ParallaxElement {
		sf::Sprite sprite;
		float animationSpeed;
	};

    class BackGround
    {
    public:
        BackGround(sf::RenderWindow& window);
		virtual ~BackGround() = default;
        void Draw();
        void Update(float deltaTime);

    private:
		std::vector<ParallaxElement> parallaxElements;
        
        sf::RenderWindow& window;
		const float screenWidth;

        sf::Texture bg_texture;
        sf::Texture moon_texture;
        sf::Texture clouds_texture;
        sf::Texture mountainfar_texture;
        sf::Texture mountains_texture;
        sf::Texture backtrees_texture;
        sf::Texture closetrees_texture;
    };
}

#endif //GRADIUS_BACKGROUND_H
