#include "RunPresent.h"

RunPresent::RunPresent(sf::Vector2f m_position, sf::Texture* texture, int width, int height)
	:Present(m_position, texture, width, height)
{
	
}

void RunPresent::handleCollision(Digger& digger)
{
	if (isThere()) {
		playSound();
		this->erase();
		digger.speedBonus();

		
	}
}

void RunPresent::handleCollision(Wall& wall)
{
}

void RunPresent::handleCollision(Rock& rock)
{
}

void RunPresent::handleCollision(Diamond& diamond)
{
}
