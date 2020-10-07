#include "Creature.h"


Creature::Creature(sf::Vector2f& location, sf::Texture* texture, int width, int height)
	: Entity(location, texture, width, height)
{
	m_sprite = getSprite();
	animation(DOWN, m_sprite);
	m_sprite.scale(2.9, 2.9);
	setSprite(m_sprite);
}

void Creature::setLastLocation(sf::Vector2f lastLocation)
{
	prevLocation = lastLocation;
}
void Creature::animation(enum Direction way,sf::Sprite & sprite)
{
 
	m_source.y = way;
	animationCounter += clock.restart().asMilliseconds();
	if (animationCounter >= animationFrameDuration)
	{
		animationCounter -= animationFrameDuration;
		m_source.x++;
	}
	if (m_source.x * SPRITE_SHEET_SIZE >= SPRITE_SHEET_SIZE * 3)
		m_source.x = 0;


	sprite.setTextureRect(sf::IntRect(m_source.x * SPRITE_SHEET_SIZE, m_source.y * SPRITE_SHEET_SIZE, SPRITE_SHEET_SIZE, SPRITE_SHEET_SIZE));
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	setSprite(sprite);
}
