#pragma once

#include "Present.h"


class TimePresent : public Present
{

public:
	TimePresent(sf::Vector2f m_position, sf::Texture* texture, int width, int height);

	virtual void handleCollision(Digger& digger) override; //here we are going to handle collisions
	virtual void handleCollision(Wall& wall) override;  //here we are going to handle collisions
	virtual void handleCollision(Rock& rock) override;  //here we are going to handle collisions
	virtual void handleCollision(Diamond& diamond) override;  //here we are going to handle collisions
	virtual void handleCollision(Monster* monster) override {}

private:
	sf::Sprite m_sprite;
};