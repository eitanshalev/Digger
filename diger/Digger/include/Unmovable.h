#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Globals.h"
#include "Entity.h"
#include "Monster.h"

class Unmovable :  public Entity{

public:

	Unmovable(sf::Vector2f location, sf::Texture *texture, int width, int height);
	virtual void handleCollision(Digger& digger) override; //here we are going to handle collisions
	virtual void handleCollision(Wall& wall) override;  //here we are going to handle collisions
	virtual void handleCollision(Rock& rock) override;  //here we are going to handle collisions
	virtual void handleCollision(Diamond& diamond) override;  //here we are going to handle collisions
	virtual void handleCollision(Monster *monster) override;

private:


};
