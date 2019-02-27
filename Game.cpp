#include "Game.h"

namespace gamePR
{
	Game::Game(int width, int height, const std::string &title)
	{
		_gameData->window.create(sf::VideoMode(width, height), title);
		_gameData->width = width;
		_gameData->height = height;
	}

	void Game::run()
	{
		Gameplay _gameplay(_gameData);

		
		float newTime, frameTime, interpolation;
		float accumulator = 0.0f;
		float currentTime = this->_clock.getElapsedTime().asSeconds();

		while (_gameData->window.isOpen()) {
			newTime = this->_clock.getElapsedTime().asSeconds();

			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
				frameTime = 0.25f;
			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt) {
				_gameplay.handleInput();
				_gameplay.update(dt);
				accumulator -= dt;
			}
			interpolation = accumulator / dt;
			_gameplay.draw();
		}
	}

	Game::~Game()
	{
	}
}
