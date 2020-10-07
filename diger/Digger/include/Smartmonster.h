#pragma once

#include "Monster.h"
#include "Digger.h"


class Smartmonster : public Monster
{
	
public:
	Smartmonster(sf::Vector2f position, sf::Texture* texture, int width, int height);
	sf::Vector2f getDistance(Digger& digger);
	void move(Digger &digger, float deltaTime) override;
	void stayInPlace();
	void newMove(Digger& digger);

	void changeDirection(float deltaTime, int& counter) override;

private:
	bool stay_in_place;
	sf::Sprite m_sprite;
	bool faceRight;
	float speed;
	sf::Vector2f lastPlace;
	sf::Clock monsterClock;
	
};