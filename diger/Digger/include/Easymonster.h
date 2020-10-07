#pragma once

#include "Monster.h"


class Easymonster : public Monster
{

public:
	Easymonster(sf::Vector2f position, sf::Texture* texture, int width, int height);
	 void move(Digger &, float deltaTime) override;
	void stayInPlace();

private:
	sf::Sprite m_sprite;
	bool faceRight;
	sf::Vector2f lastPlace;
};