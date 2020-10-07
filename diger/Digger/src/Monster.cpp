
#include "Monster.h"




Monster::Monster(sf::Vector2f position, sf::Texture* texture, int width, int height)
	: Creature(position, texture, width, height)
{

	faceRight = true;
	m_sprite = Entity::getSprite();
	m_hitSound.setBuffer(Resources::loadResources().getSoundBuffer(hurt));

}

void Monster::handleCollision(Digger& digger)
{
	m_hitSound.play();
	digger.ouchie();

	//std::cout << "help! a monster ate me!!!!!!!" <<std::endl;
}

void Monster::handleCollision(Wall& wall)
{
}

void Monster::handleCollision(Rock& rock)
{
}

void Monster::handleCollision(Diamond& diamond)
{
}

//void Monster::setLastLocation(sf::Vector2f &lastLocation)
//{
//	m_sprite.setPosition(lastLocation);
//	Entity::setSprite(m_sprite);
//}
//
//void Monster::setSprite(sf::Sprite &sprite)
//{
//	Entity::setSprite(sprite);
//	m_sprite = sprite;
//}
//
