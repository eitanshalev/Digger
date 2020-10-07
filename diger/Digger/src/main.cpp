#include "Controller.h"
//#include "SFML/Audio.hpp"
//16012020
int main() {

	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode(WIDTH, HEIGHT + 50), "Digger");
	gameWindow.clear(sf::Color::Black);
	bool fullscreen;
	Menu mainMenu;

	


	int StartingLevel = 1;
	
	while (mainMenu.runMenu(fullscreen,gameWindow)) {

		Controller game(gameWindow,StartingLevel,fullscreen);

		game.run();
	}


}