#pragma once

#include <string>

#include <SFML/Graphics.hpp>

namespace gamePR
{
	class Bullet
	{
	public:
		Bullet();
		Bullet(int posX, int posY, float angle, const sf::Texture &bulletTexture);

		void update(float dt);
		void draw(sf::RenderWindow &window);

		bool isDestroyed(int windowWidth, int windowHeight);
		sf::FloatRect getGlobalBounds();

		~Bullet();
	private:
		const float BULLET_SPEED{ 8.0f };
		sf::Vector2f _speed{ BULLET_SPEED,BULLET_SPEED };
		sf::Vector2f _position;
		sf::Sprite _bullet;
		float _angle = 0;
	};
}

