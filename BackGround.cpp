#include <iostream>
#include "Background.h"

using namespace Gradius;

constexpr float kScrollSpeed = 80.0f;

BackGround::BackGround(sf::RenderWindow& window) : 
	window{ window },
	screenWidth{ static_cast<float>(window.getSize().x) }
{
    const sf::Vector2f initialPos = sf::Vector2f(0.0f, 0.0f);
    const sf::Vector2f delayedPos = sf::Vector2f(screenWidth, 0.0f);

    bg_texture.loadFromFile("res/1bg.png");
    moon_texture.loadFromFile("res/2moon.png");
	clouds_texture.loadFromFile("res/3clouds.png");
	mountainfar_texture.loadFromFile("res/4mountainfar.png");
	mountains_texture.loadFromFile("res/5mountains.png");
	backtrees_texture.loadFromFile("res/6backtrees.png");
	closetrees_texture.loadFromFile("res/7closetrees.png");

	auto createElementPair = [&](
		const sf::Texture& texture,
		float animationSpeed,
		sf::Color firstColor = sf::Color::White,
		sf::Color secondColor = sf::Color::White) {
		ParallaxElement element{ sf::Sprite{ texture }, animationSpeed };
		ParallaxElement elementDelayed{ sf::Sprite{ texture }, animationSpeed };

		element.sprite.setPosition(initialPos);
		element.sprite.setColor(firstColor);
		elementDelayed.sprite.setPosition(delayedPos);
		elementDelayed.sprite.setColor(secondColor);

		parallaxElements.push_back(std::move(element));
		parallaxElements.push_back(std::move(elementDelayed));
	};

	createElementPair(bg_texture, 1);
	createElementPair(moon_texture, 2, sf::Color{ 240, 175, 255 });
	createElementPair(clouds_texture, 3);
	createElementPair(mountainfar_texture, 4);
	createElementPair(mountains_texture, 5);
	createElementPair(backtrees_texture, 6);
	createElementPair(closetrees_texture, 7);
}

void BackGround::Draw()
{
	for (const auto& element : parallaxElements) {
		window.draw(element.sprite);
	}
}

void BackGround::Update(float deltaTime)
{
	for (auto& element : parallaxElements) {
		element.sprite.move({
			-(kScrollSpeed * element.animationSpeed * deltaTime),
			0.0f
		});

		const float offset = element.sprite.getPosition().x + screenWidth;

		if (offset < 0) {
			element.sprite.setPosition(sf::Vector2f(screenWidth + offset, 0));
		}
	}
}
