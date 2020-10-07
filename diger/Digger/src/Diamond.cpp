#include "Diamond.h"


void Diamond::handleCollision(Digger& digger)
{
	if (isThere()) {
		m_coinSound.play();
		digger.addPoints();
		erase();
	}
//	std::cout << "emerlad\n";
}
//2901