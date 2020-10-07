#pragma once
#include "Entity.h"


Entity::Entity(sf::Vector2f position, sf::Texture *texture, int width, int height)
	:m_position(position), m_width(width), m_height(height), m_texture(texture)
{
	exists = true;
	float rectWidth = WIDTH / m_width;
	float rectHeight = HEIGHT / m_height; 

	m_sprite.setColor(sf::Color::White);
	m_sprite.setTexture(*m_texture);
	sf::Vector2f set = (sf::Vector2f)m_texture->getSize();
	sf::Vector2f newScale;
	newScale.x = rectWidth / set.x;
	newScale.y = rectHeight / set.y;
	m_sprite.scale(newScale);
	
	m_origin = m_sprite.getOrigin();
	sf::Vector2f newPos = m_position;
	newPos.x = m_position.x + rectWidth / 2;
	newPos.y = m_position.y + rectHeight / 2;
	m_position = newPos;

	startingPosition = m_position;

	sf::Rect<float> size = m_sprite.getLocalBounds();
	m_sprite.setOrigin(size.width /2, size.height /2);
	m_sprite.setPosition(m_position);
}

Entity::~Entity()
{
}

void Entity::erase()
{
	exists = false;
}

void Entity::unErase()
{
	exists = true;
}

bool Entity::checkLocation(sf::Vector2f location)
{
	if (m_sprite.getGlobalBounds().contains(location))
		return true;

	return false;
}

void Entity::resetPosition()
{
	m_sprite.setPosition(startingPosition);
}

sf::Vector2f Entity::origin() {

	return m_origin;

}
void Entity::setSize(int width, int height)
{
	m_width = width;
	m_height = height;
}

void Entity::setImage(sf::Texture* texture)
{
	m_texture = texture;
}


void Entity::draw(sf::RenderWindow& window) 
{
	if(exists)
	window.draw(m_sprite);

}


void Entity::setLocation(const sf::Vector2f& location)
{
	m_position = location;

}

void Entity::placeInSquare() {

	//sf::Rect<float> size = m_sprite.getLocalBounds();
	//m_sprite.setOrigin(sf::Vector2f(size.width/5, size.height/5));
}

//This function handles collision between objects

