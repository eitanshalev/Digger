#include "..\include\Rock.h"

void Rock::handleCollision(Digger& digger)
{
	// 
	//delete this;

	if (isThere()) {
		digger.ateRock();
		erase();
	}
}


void Rock::handleCollision(Wall& wall)
{
}

void Rock::handleCollision(Rock& rock)
{
}

void Rock::handleCollision(Diamond& diamond)
{
}

void Rock::handleCollision(Monster* monster)
{
	if(isThere())
	monster->stayInPlace();
}

