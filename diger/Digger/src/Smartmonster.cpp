#include "..\include\Smartmonster.h"
#include "Smartmonster.h"
//12

Smartmonster::Smartmonster(sf::Vector2f position, sf::Texture* texture, int width, int height)
	: Monster(position, texture, width, height)
{
	
	stay_in_place = false;
	m_sprite = Entity::getSprite();
	speed = 350;
	monsterClock.restart();
	//m_sprite.setOrigin(Entity::origin());

	//sf::Rect<float> size = m_sprite.getLocalBounds();
	//m_sprite.setOrigin(sf::Vector2f(size.width / 2, size.height / 2));

	faceRight = true;
}


void Smartmonster::move(Digger& digger, float deltaTime)
{
	int randomMove = 0;
	//monsterClock.restart();
	m_sprite = getSprite();
	sf::Vector2f movement(0.0f, 0.0f);
	sf::Vector2f diggerLocation = digger.getSprite().getPosition();
	sf::Vector2f monsterLocation = m_sprite.getPosition();
	lastPlace = monsterLocation;


	//speed = rand() % 300;
	speed = 150;
	if ((int)monsterClock.getElapsedTime().asSeconds() % 3 == 0) {
		randomMove = 1;
	}

	else if ((int)monsterClock.getElapsedTime().asSeconds() % 5 == 0) {
		randomMove = 0;
	}
	static int counter = 0;

	if (stay_in_place == true && counter != 0) //we didnt move enough to changposition
	{
		changeDirection(deltaTime, counter);
	}

	if (diggerLocation.x == monsterLocation.x)
		randomMove = 1;
	
	if (diggerLocation.y == monsterLocation.y)
		randomMove = 0;

	if (randomMove == 0) {
		if (diggerLocation.x < monsterLocation.x)
		{
		
			movement.x -= speed * deltaTime;
			animation(LEFT, m_sprite);
			//monsterClock.restart();

		}

		if (diggerLocation.x > monsterLocation.x + 1)
		{
			movement.x += speed * deltaTime;

			animation(RIGHT, m_sprite);
			//monsterClock.restart();

		}
	}

	else {
		if (diggerLocation.y > monsterLocation.y + 1) {
			movement.y += speed * deltaTime;
			animation(DOWN, m_sprite);
		}


		if (diggerLocation.y < monsterLocation.y) {
			movement.y -= speed * deltaTime;
			animation(UP, m_sprite);

		}
	}




	m_sprite.move(movement);


	sf::Vector2f newLocation = m_sprite.getPosition();
	sf::Rect<float> size = m_sprite.getGlobalBounds();
	if (newLocation == lastPlace)
	{
		counter++;
		if (stay_in_place == true)
		{
			counter += 500;
		}
		//stay_in_place = false;
		changeDirection(deltaTime, counter);
	}



	if (!(newLocation.x <= WIDTH - size.width / 2 && newLocation.x >= size.width / 2 && newLocation.y <= HEIGHT - size.height / 2 && newLocation.y >= size.height / 2))
		stayInPlace();

	setSprite(m_sprite);
}

void Smartmonster::stayInPlace()
{
	stay_in_place = true;
	m_sprite.setPosition(lastPlace);
	setSprite(m_sprite);
}

sf::Vector2f Smartmonster::getDistance(Digger& digger)
{
	sf::Vector2f diggerPosition = digger.getLocation();

	sf::Vector2f monsterPosition = getLocation();

	return sf::Vector2f(diggerPosition.x - monsterPosition.x, diggerPosition.y - monsterPosition.y);
}

void Smartmonster::changeDirection(float deltaTime, int& counter)
{
	float speed = 200;
	sf::Vector2f prevLocation = m_sprite.getPosition();
	sf::Vector2f movement(0.0f, 0.0f);


	static int my_position = 0;
//	speed *= 2;


	if (counter >= NUMBER_OF_DIRECTION )
	{
		my_position = rand() % 4;
		counter = 0;
		stay_in_place = false;
		speed /= 2;
		return;
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
		animation(RIGHT, m_sprite);
		movement.x += speed * deltaTime;

		
		break;
	}

	default:break;
	}
	counter++;
	if (counter >= 1000)
	{
		my_position = rand() % 4;
		counter = 0;
		stay_in_place = false;
		return;
	}
	m_sprite.move(movement);

	sf::Vector2f newLocation = m_sprite.getPosition();
	sf::Rect<float> size = m_sprite.getGlobalBounds();

	if (!(newLocation.x <= WIDTH - size.width / 2 && newLocation.x >= size.width / 2 && newLocation.y <= HEIGHT - size.height / 2 && newLocation.y >= size.height / 2))
		m_sprite.setPosition(prevLocation);

	Entity::setSprite(m_sprite);
}







//void Smartmonster::move(Digger& digger, float deltaTime)
//{
//	m_sprite = getSprite();
//	static sf::Clock monsterMove;
//
//
//	sf::Vector2f diggerLocation = digger.getSprite().getPosition();
//
//	float monserSpeed = 100;
//	sf::Vector2f monsterLocation = getSprite().getPosition();
//	bool inPlace = (lastPlace == monsterLocation);
//	lastPlace = monsterLocation;
//	sf::Vector2f movement(0.0f, 0.0f);
//
//	bool moved = false;
//	//if ((int)monsterMove.getElapsedTime().asSeconds() % 3 == 0) {
//		if (diggerLocation.x < monsterLocation.x && !moved)// && !inPlace)
//		{
//			movement.x -= speed * deltaTime;
//		//	m_sprite.move(-10, 0);
//			animation(LEFT, m_sprite);
//			moved = true;
//		}
//
//		if (diggerLocation.x > monsterLocation.x + 1 && !moved)
//		{
//			movement.x += speed * deltaTime;
//			m_sprite.move(10, 0);
//			animation(RIGHT, m_sprite);
//			moved = true;
//
//		}
//
//		if (diggerLocation.y > monsterLocation.y + 1 && !moved) {
//			movement.y += speed * deltaTime;
//			m_sprite.move(0, 10);
//			animation(DOWN, m_sprite);
//			moved = true;
//
//		}
//
//
//		if (diggerLocation.y < monsterLocation.y && !moved) {
//			movement.y -= speed * deltaTime;
//			m_sprite.move(0, -10);
//			animation(UP, m_sprite);
//			moved = true;
//
//
//		}
//	//}
//
//
//	
//	
//
//	sf::Vector2f newLocation = m_sprite.getPosition();
//	sf::Rect<float> size = m_sprite.getGlobalBounds();
//
//	if (!(newLocation.x <= WIDTH - size.width / 2 && newLocation.x >= size.width / 2 && newLocation.y <= HEIGHT - size.height / 2 && newLocation.y >= size.height / 2))
//		m_sprite.setPosition(lastPlace);
//
//	Entity::setSprite(m_sprite);
//
//
//}