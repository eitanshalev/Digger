//22/01/20
#include "TimePresent.h"

TimePresent::TimePresent(sf::Vector2f m_position, sf::Texture* texture, int width, int height)
	:Present(m_position, texture, width, height)
{

}

void TimePresent::handleCollision(Digger& digger)
{
	if (isThere()) {
		playSound();
		this->erase();
		digger.timeBonus();
		//digger.speedBonus();
		//digger.timeBonus();
		//AddTime();
	}
}

void TimePresent::handleCollision(Wall& wall)
{
}

void TimePresent::handleCollision(Rock& rock)
{
}

void TimePresent::handleCollision(Diamond& diamond)
{
}
