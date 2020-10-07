#pragma once

#include "Unmovable.h"
#include "Digger.h"
class Present : public Unmovable
{

public:
	Present(sf::Vector2f m_position, sf::Texture* texture, int width, int hight);
	
	void playSound();
	//virtual void handleCollision(Digger& digger) override =0; //here we are going to handle collisions
	//virtual void handleCollision(Wall& wall) override=0;  //here we are going to handle collisions
	//virtual void handleCollision(Rock& rock) override=0;  //here we are going to handle collisions
	//virtual void handleCollision(Diamond& diamond) override;  //here we are going to handle collisions
	//virtual void handleCollision(Monster* monster) override {}
	
private:
	sf::Sound giftSound;

};


