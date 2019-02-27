#include "Player.h"

namespace gamePR
{
	Player::Player() {}
	Player::Player(float posX, float posY, const std::string& texturePath)
	{
		_texture.loadFromFile(texturePath);
		_player.setTexture(_texture);

		_position = sf::Vector2f(posX, posY);
		_player.setPosition(_position);
		_player.setOrigin(_player.getGlobalBounds().width/2,_player.getGlobalBounds().height/2);
	}

	Player::Player(sf::Vector2f pos, const std::string& texturePath)
	{
		_texture.loadFromFile(texturePath);
		_player.setTexture(_texture);

		_position = pos;
		_player.setPosition(_position);

		_player.setOrigin(_player.getGlobalBounds().width / 2, _player.getGlobalBounds().height / 2);

	}


	void Player::handleInput()
	{
		_direction = STAY;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			_direction = RIGHT;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			_direction = LEFT;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			_direction = UP;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			_direction = DOWN;
		}
	}
	
	void Player::update(float dt, sf::Vector2i mousePosition)
	{
		 _diffX = mousePosition.x - _player.getPosition().x;
		 _diffY = mousePosition.y - _player.getPosition().y;


		if (abs(_diffX) > _player.getGlobalBounds().width / 4 || abs(_diffY) > _player.getGlobalBounds().height / 4) {

			_angle = atan2(_diffY, _diffX);
			_player.setRotation(90 +_angle*RADTODEG);

			if (_direction==UP){
				_player.move(HERO_SPEED*cos(_angle), HERO_SPEED*sin(_angle));
			}
			else if (_direction == DOWN){
				_player.move(-HERO_SPEED * cos(_angle)*0.5, -HERO_SPEED * sin(_angle)*0.5);
			}
			else if (_direction == RIGHT){
				_player.move(HERO_SPEED*cos(90 + _angle)*0.5, HERO_SPEED*sin(90 + _angle)*0.5);
			}
			else if (_direction == LEFT){
				_player.move(-HERO_SPEED * cos(90 + _angle)*0.5, -HERO_SPEED * sin(90 + _angle)*0.5);
			}
		}

		if (_clock.getElapsedTime().asMilliseconds() > SHOOT_COOLDOWN){
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				_bullets.emplace_back(std::make_unique<Bullet>(_player.getPosition().x, _player.getPosition().y, _angle, _bulletTexture));
				_clock.restart();
			}
		}

		for (int i=0; i<_bullets.size(); ++i){
			_bullets[i]->update(dt);
			if (_bullets[i]->isDestroyed(1200, 900))
				_bullets.erase(_bullets.begin() + i);
		}

		 

		//std::cout << _bullets.size() << std::endl;
	}
	
	void Player::draw(sf::RenderWindow &window)
	{
		window.draw(_player);
		for (auto& bullet : _bullets)
		{
			bullet->draw(window);
		}
	}

	void Player::setBulletTexture(const std::string& texturePath)
	{
		_bulletTexture.loadFromFile(texturePath);
	}


	Player::~Player()
	{
	}
}
