#include "Gameplay.h"
namespace gamePR
{

	Gameplay::Gameplay() 
	{

	}

	Gameplay::Gameplay(gameDataRef Data) :
		_data(Data),
		_player(200, 200, "img/Ball.png")
	{
		_player.setBulletTexture("img/Ball2.png");
	}

	void Gameplay::handleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				this->_data->window.close();
			}
			
		}
		_player.handleInput();
		
	}

	void Gameplay::update(float dt)
	{
		_mousePosition = sf::Mouse::getPosition(_data->window);
		_player.update(dt,_mousePosition);
	}

	void Gameplay::draw()
	{
		_data->window.clear(sf::Color(40,40,40));

		
		_player.draw(_data->window);

		
		_data->window.display();
	}

	Gameplay::~Gameplay()
	{
	}
}