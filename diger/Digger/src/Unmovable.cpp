#pragma once
#include "Unmovable.h"
#include <cmath>
#include <algorithm>


Unmovable::Unmovable(sf::Vector2f location, sf::Texture *texture, int width, int height)
	:	Entity(location, texture, width, height)
{
	
}

void Unmovable::handleCollision(Digger& digger)
{
	std::cout << " Digger went into object\n";
}

void Unmovable::handleCollision(Wall& wall)
{
}

void Unmovable::handleCollision(Rock& rock)
{
}

void Unmovable::handleCollision(Diamond& diamond)
{
}

void Unmovable::handleCollision(Monster* monster)
{

}






