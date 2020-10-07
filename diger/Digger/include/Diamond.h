#pragma once
#include "Unmovable.h"
#include "Digger.h"


class Diamond : public Unmovable
{
public:
	Diamond(sf::Vector2f location, sf::Texture *texture, int width, int height) : Unmovable(location, texture, width, height) {
		m_coinSound.setBuffer(Resources::loadResources().getSoundBuffer(coin));
	}
	void handleCollision(Digger& digger);
	
private:
	sf::Sound m_coinSound;
};