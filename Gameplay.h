#pragma once
#include <string>

#include <SFML/Graphics.hpp>

#include "Player.h"

namespace gamePR
{
	struct gameData
	{
		sf::RenderWindow window;
		int width;
		int height;
	};

	using gameDataRef = std::shared_ptr<gameData>;

	class Gameplay
	{
	public:
		Gameplay();
		Gameplay(gameDataRef Data);
		~Gameplay();

		void handleInput();
		void update(float dt);
		void draw();
		

	private:
		sf::Vector2i _mousePosition;
		sf::Clock _clock;

		gameDataRef _data;
		Player _player;

	};
}


			
			