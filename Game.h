#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

#include "Gameplay.h"


namespace gamePR
{
	

	class Game
	{
	public:
		Game(int width, int height, const std::string &title);
		~Game();
		void run();

	private:
		gameDataRef _gameData = std::make_shared<gameData>();

		const float dt = 1.0f / 60.0f;

		sf::Clock _clock;
	};
}
