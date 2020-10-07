#include "Easymonster.h"


Easymonster::Easymonster(sf::Vector2f position, sf::Texture* texture, int width, int height)
	: Monster(position, texture, width, height)
{
	m_sprite = Entity::getSprite();
	//m_sprite.setOrigin(Entity::origin());

	//sf::Rect<float> size = m_sprite.getLocalBounds();
	//m_sprite.setOrigin(sf::Vector2f(size.width / 2, size.height / 2));

	faceRight = true;
}

void Easymonster::move(Digger &digger , float deltaTime)
{
	m_sprite = getSprite();


	float speed = 150;
	lastPlace = m_sprite.getPosition();
	sf::Vector2f movement(0.0f, 0.0f);

	//lastPlace = monsterLocation;

	static int my_position = 0;
		
	static int counter = 0;
	
	if (counter == 100)
	{	
		my_position = rand() % 4;
		counter = 0;
	}
	

	switch (my_position) {
	case 0:
		movement.y -= speed * deltaTime;
		animation(UP, m_sprite);
		break;
	case 1:
		movement.y += speed * deltaTime;
		animation(DOWN, m_sprite);
		break;
	case 2:
	{
		animation(LEFT, m_sprite);
		movement.x -= speed * deltaTime;
		break;
	}

	case 3: {
		movement.x += speed * deltaTime;
		animation(RIGHT, m_sprite);
		break;
	}

	default:break;
	}
	counter++;
	m_sprite.move(movement);

	sf::Vector2f newLocation = m_sprite.getPosition();
	sf::Rect<float> size = m_sprite.getGlobalBounds();

	if (!(newLocation.x <= WIDTH - size.width / 2 && newLocation.x >= size.width / 2 && newLocation.y <= HEIGHT - size.height / 2 && newLocation.y >= size.height / 2))
		m_sprite.setPosition(lastPlace);

	Entity::setSprite(m_sprite);

}

void Easymonster::stayInPlace()
{
	m_sprite.setPosition(lastPlace);
	setSprite(m_sprite);
}

