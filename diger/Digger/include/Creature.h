#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Entity.h"

class Creature : public Entity {
public:

	Creature(sf::Vector2f &, sf::Texture*, int , int );
	void setLastLocation(sf::Vector2f lastLocation);
	void animation(enum Direction way, sf::Sprite& sprite);

private:

	sf::Sprite m_sprite;
	sf::Vector2f prevLocation;
	sf::Vector2i m_source;
	sf::Clock clock;
	int animationCounter = 0 ,
		animationFrameDuration = 200;
};