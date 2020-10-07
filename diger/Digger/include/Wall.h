#pragma once

#include "Unmovable.h"
#include "Digger.h"

class Wall : public Unmovable
{
	
public:
	Wall(sf::Vector2f location, sf::Texture *texture, int width, int height) : Unmovable(location, texture, width, height) {}
	virtual void handleCollision(Digger &digger) override; //here we are going to handle collisions
	//virtual void handleCollision(Wall& wall) override;  //here we are going to handle collisions
	//virtual void handleCollision(Rock& rock) override;  //here we are going to handle collisions
	//virtual void handleCollision(Diamond& diamond) override;  //here we are going to handle collisions
	virtual void handleCollision(Monster* monster) override;
	
};