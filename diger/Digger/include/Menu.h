#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Resources.h"


class Menu
{
public:
	Menu( );
	~Menu();
	bool runMenu(bool& fullscreen, sf::RenderWindow& window);
	void draw(sf::RenderWindow&);
	void selectItem(int &item);
	bool enterPressed(menuSelection select, bool&, bool&);
private:
	int m_selectItemIndex;
	std::vector<sf::Text> menu;
	sf::Sprite m_background;
	sf::Sound clickSound;

};