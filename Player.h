#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include <SFML/Graphics.hpp>

#include "Bullet.h"

#include <iostream>

namespace gamePR
{
	class Player
	{
	public:
		Player();
		Player(float posX, float posY, const std::string& texturePath);
		Player(sf::Vector2f pos, const std::string& texturePath);
		~Player();

		void handleInput();
		void update(float dt, sf::Vector2i mousePosition);
		void draw(sf::RenderWindow &window);

		void setBulletTexture(const std::string& texturePath);

	private:
		sf::Sprite _player;
		sf::Vector2f _position;
		sf::Texture _texture;
		sf::Texture _bulletTexture;


		const float HERO_SPEED{ 3.0f };
		const float RADTODEG{ 57.3248407643 };
		const int SHOOT_COOLDOWN{ 1 };

		sf::Vector2f _speed{ HERO_SPEED,HERO_SPEED };

		std::vector< std::unique_ptr<Bullet>> _bullets;

		float _angle;
		float _diffX{ 0 };
		float _diffY{ 0 };
		enum {UP,DOWN,LEFT,RIGHT,STAY}_direction;

		sf::Clock _clock;

	};
}



