#include "Square.h"



Square::Square(sf::Vector2f location , sf::Texture *texture ,int width, int height)
	:Entity(location,texture,width,height)
{
	taken = false;
	m_square = Entity::getSprite();
	//m_square.setOrigin(origin());

}



void Square::draw(sf::RenderWindow& window)  
{
	window.draw(m_square);
}


//sf::Vector2f Square::getLocation() {
//	return m_position;
//}
//
//void Square::hoverSquare(const sf::Vector2f& location)
//{
//	if (checkLocation(location))
//	{
//		m_color = sf::Color::Green;
//	}
//
//	else m_color = sf::Color(150, 75, 0);
//}

bool Square::checkLocation(const sf::Vector2f& location)
{
	if (m_square.getGlobalBounds().contains(location))
		return true;

	return false;
	
}

void Square::handleCollision(Digger& digger)
{
}

void Square::handleCollision(Wall& wall)
{
}

void Square::handleCollision(Rock& rock)
{
}

void Square::handleCollision(Diamond& diamond)
{
}

