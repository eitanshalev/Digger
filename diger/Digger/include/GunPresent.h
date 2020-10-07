#pragma once

#include "Present.h"


class GunPresent : public Present
{

public:
	GunPresent(sf::Vector2f m_position, sf::Texture* texture, int width, int height);
	//Easymonster(sf::Vector2f position, sf::Texture* texture, int width, int height);
//	/*virtual*/ void move(Digger&, float deltaTime) override;

	virtual void handleCollision(Digger& digger) override; //here we are going to handle collisions
	virtual void handleCollision(Wall& wall) override;  //here we are going to handle collisions
	virtual void handleCollision(Rock& rock) override;  //here we are going to handle collisions
	virtual void handleCollision(Diamond& diamond) override;  //here we are going to handle collisions
	virtual void handleCollision(Monster* monster) override {}

private:
	sf::Sprite m_sprite;

};