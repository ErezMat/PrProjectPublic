#include "Bullet.h"


namespace gamePR
{
	Bullet::Bullet()
	{
	}

	Bullet::Bullet(int posX, int posY, float angle, const sf::Texture &texture)
	{
		_bullet.setTexture(texture);

		_position = sf::Vector2f(posX,posY);
		_bullet.setPosition(_position);

		_angle = angle;
		_bullet.setRotation(angle);

		_bullet.setOrigin(_bullet.getGlobalBounds().width / 2, _bullet.getGlobalBounds().height / 2);
	}

	void Bullet::update(float dt)
	{
		_bullet.move(BULLET_SPEED*cos(_angle)*2, BULLET_SPEED*sin(_angle)*2);

	}

	void Bullet::draw(sf::RenderWindow &window)
	{
		window.draw(this->_bullet);
	}

	bool Bullet::isDestroyed(int windowWidth, int windowHeight)
	{
		if (_bullet.getPosition().x<0 || _bullet.getPosition().x>windowWidth ||
			_bullet.getPosition().y<0 || _bullet.getPosition().y>windowHeight) 
			return true;
		return false;
	}

	sf::FloatRect Bullet::getGlobalBounds()
	{
		return _bullet.getGlobalBounds();
	}

	Bullet::~Bullet()
	{
	}
}
