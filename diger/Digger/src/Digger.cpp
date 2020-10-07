#include "Digger.h"
#include "Board.h"


Digger::Digger(sf::Vector2f position, sf::Texture *texture, int width, int height)
	: m_lives(3), m_score(0), Creature(position, texture, width, height)
{
	m_currDiamondsEaten = 0;
	m_sprite = Entity::getSprite();
	speed = DIGGERSPEED;
	rocksToEat = 0;
	ouch = false;
	m_timeBonus = 0;
}



void Digger::update(float deltaTime) 
{
	prevLocation = m_sprite.getPosition();
	setLastLocation(prevLocation);


	sf::Vector2f movement(0.0f, 0.0f);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		movement.y -= speed * deltaTime;
		animation(UP,m_sprite);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		movement.y += speed * deltaTime;
		animation(DOWN, m_sprite);
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
	{
		movement.x -= speed * deltaTime;
		animation(LEFT, m_sprite);
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
	{
		movement.x += speed * deltaTime;
		animation(RIGHT, m_sprite);
	}

	m_sprite.move(movement);
	
	sf::Vector2f newLocation = m_sprite.getPosition();
	sf::Rect<float> size = m_sprite.getGlobalBounds();

	if (!(newLocation.x <= WIDTH - size.width / 2 && newLocation.x >= size.width / 2 && newLocation.y <= HEIGHT - size.height / 2 && newLocation.y >= size.height / 2))
		m_sprite.setPosition(prevLocation);

	Entity::setSprite(m_sprite);

}

void Digger::handleCollision(Digger& digger)
{
}

void Digger::handleCollision(Wall& wall)
{
	setLocation(prevLocation);
}

void Digger::handleCollision(Rock& rock)
{
}

void Digger::handleCollision(Diamond& diamond)
{
	std::cout << "i ate an Emerald!! " << std::endl;
}

void Digger::handleCollision(Monster* monster)
{
}


void Digger::restoreDiggerScore(int& score)
{
	m_currDiamondsEaten = 0;
	m_score = score;
}
void Digger::restoreDigger(int& lives, int& score)
{
	m_lives = lives;
	m_score = score;
}

void Digger::addPoints()
{
	m_currDiamondsEaten++;
	m_score += 15;
}

void Digger::levelBonus()
{
	m_score += 20;
}



void Digger::stayInPlace()
{
	m_sprite.setPosition(prevLocation);
	setSprite(m_sprite);
}

void Digger::speedBonus()
{
	speed *= 2;
}

void Digger::resetSpeed()
{
	if (DIGGERSPEED != speed)
	{
	speed /= 2;
	}

}

void Digger::ouchie()
{
	ouch = true;
	m_lives--;
	resetPosition();
	m_sprite = getSprite();
	//m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
}

int Digger::getTimeBonus()
{
	int temp = m_timeBonus;
	m_timeBonus = 0;
	return temp;
}

void Digger::Animate()
{
	sf::Texture texture = Resources::loadResources().getTexture(digger);

	sf::Sprite sprite(texture, sf::IntRect(0, 0, 30, 30));
	m_sprite = sprite;


}



