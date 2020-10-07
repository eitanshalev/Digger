#include "Present.h"

Present::Present(sf::Vector2f location, sf::Texture* texture, int width, int height)
	: Unmovable(location, texture, width, height) // Entity(location, texture, width, height)
{
	giftSound.setBuffer(Resources::loadResources().getSoundBuffer(present));
	giftSound.setPlayingOffset(sf::seconds(0.5f));
	sf::Sprite sprite = getSprite();
	float rectWidth = WIDTH / width;
	float rectHeight = HEIGHT / height;
	sf::Vector2f newPos = location;
	newPos.x = location.x - rectWidth / 2;
	newPos.y = location.y - rectHeight / 2;
	location = newPos;
	
	sprite.setPosition(location);


	sprite.setOrigin(origin());
	setSprite(sprite);
}


void Present::playSound()
{
	giftSound.play();
}

