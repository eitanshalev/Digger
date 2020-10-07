#include "GunPresent.h"

GunPresent::GunPresent(sf::Vector2f m_position, sf::Texture* texture, int width, int height)
	:Present(m_position, texture, width, height)
{
	
}

void GunPresent::handleCollision(Digger& digger)
{
	if (isThere()) {
		playSound();
		this->erase();
		//add to digger 5  option to save himself
		digger.addLife();
	}

}

void GunPresent::handleCollision(Wall& wall)
{
}

void GunPresent::handleCollision(Rock& rock)
{
}

void GunPresent::handleCollision(Diamond& diamond)
{
}
