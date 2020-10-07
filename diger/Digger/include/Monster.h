#pragma once

#include "Creature.h"
#include "Digger.h"
class Monster : public Creature
{

public:
	Monster(sf::Vector2f m_position, sf::Texture* texture, int width, int hight);
	virtual void move(Digger& digger, float deltaTime) = 0;

	virtual void handleCollision(Digger& digger) override; //here we are going to handle collisions
	virtual void handleCollision(Wall& wall) override;  //here we are going to handle collisions
	virtual void handleCollision(Rock& rock) override;  //here we are going to handle collisions
	virtual void handleCollision(Diamond& diamond) override;  //here we are going to handle collisions
	virtual void handleCollision(Monster* monster) override {}
	sf::Vector2f getLastLocation() { return m_lastLocation; }
	virtual void stayInPlace() = 0;
	virtual void changeDirection(float deltaTime, int& counter) {}

	//void setLastLocation(sf::Vector2f &lastLocation);
	//void setSprite(sf::Sprite &);
private:

	sf::Sprite m_sprite;
	bool faceRight;
	sf::Vector2f m_lastLocation;
	sf::Sound m_hitSound;

};


