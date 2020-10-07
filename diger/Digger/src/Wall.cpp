#include "..\include\Wall.h"

void Wall::handleCollision(Digger &digger)
{
	digger.stayInPlace(); //digger doesnt move further
}

void Wall::handleCollision(Monster* monster)
{
	//monster->setLocation(monster->getLastLocation());
	//sf::Vector2f lastLocation = monster->getLastLocation();
	//monster->setLastLocation(lastLocation);

	monster->stayInPlace();
}
