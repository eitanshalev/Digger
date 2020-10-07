#include "Menu.h"
#include <iostream>
#include "SFML/Audio.hpp"


Menu::Menu()
	
{
	m_background.setTexture(Resources::loadResources().getTexture(background));
	sf::Vector2f set = (sf::Vector2f)Resources::loadResources().getTexture(background).getSize();
	sf::Vector2f newScale;
	newScale.x = WIDTH / set.x;
	newScale.y = (HEIGHT + 50) / set.y;
	m_background.scale(newScale);


	sf::Text text;
	text.setFont(Resources::loadResources().getFont(gaming));
	text.setColor(sf::Color::Red);
	text.setString("Play Game");

	text.setPosition(sf::Vector2f(MENU_WIDTH ,MENU_HEIGHT + SPACE *1));
	text.setCharacterSize(FONT_MENU_SIZE);
	text.Bold;
	menu.push_back(text); //0

	text.setColor(sf::Color::White);
	text.setString("Full Screen: OFF");
	text.setPosition(sf::Vector2f(MENU_WIDTH, MENU_HEIGHT + SPACE *2));
	text.setCharacterSize(FONT_MENU_SIZE);
	text.Bold;
	menu.push_back(text);//1

	text.setString("Exit");
	text.setPosition(sf::Vector2f(MENU_WIDTH , MENU_HEIGHT + SPACE *3));
	text.setCharacterSize(FONT_MENU_SIZE);
	text.Bold;
	menu.push_back(text); // 2
	m_selectItemIndex = 0;

	clickSound.setBuffer(Resources::loadResources().getSoundBuffer(click));

}

Menu::~Menu()
{
	
}

bool Menu::runMenu(bool &fullscreen, sf::RenderWindow &window)
{
	window.create(sf::VideoMode(WIDTH, HEIGHT+50), "Digger");


	bool start = false;
	fullscreen = false;
	int item = 0;
	bool enter_pressed = false;
	while (window.isOpen())
	{

		window.draw(m_background);
		draw(window);

		window.display();
	
		auto event = sf::Event{};
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
				return false;
			}

			switch (event.type)
			{
			case sf::Event::KeyReleased:

				clickSound.play();
				
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					item--;
					
					break;
				case sf::Keyboard::Down:
					item++;
					break;
				case sf::Keyboard::Enter:
					if (enterPressed((menuSelection)item, fullscreen, start)) {
						clickSound.stop();
						clickSound.resetBuffer();
						
						return false;
					}
					enter_pressed = true;
					break;
				}
		
			}
			selectItem(item);
			
		}
		

		if (enter_pressed)
		{
			if (fullscreen)
			{
				window.create(sf::VideoMode(WIDTH, HEIGHT + 50), "Digger Editor", sf::Style::Fullscreen);
			}
			else
			{
				window.create(sf::VideoMode(WIDTH, HEIGHT + 50), "Digger Editor", sf::Style::Default);
			}
			enter_pressed = false;
		}

		if (start)
			return true;

	
	}
	
	return true;
	
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < menu.size(); i++)
	{
		window.draw(menu[i]);
	}
}


void Menu::selectItem(int& item)
{
	while (item < 0)
	{
		item += menu.size();
	}
	item = item % menu.size();
	
	for (int i = 0; i < menu.size(); i++)
	{
		if (i != item)
		{
			menu[i].setFillColor(sf::Color::White);
		}
		else menu[i].setFillColor(sf::Color::Red);
	}

}

bool Menu::enterPressed(menuSelection select, bool &fullscreen, bool& start)
{
	bool quit = false;
	switch (select)
	{
	case play_game:
		start = true;
		break;
	case options:
		if (!fullscreen) {
			fullscreen = true;
			menu[options].setString("Full Screen: ON");
		}
		else
		{
			fullscreen = false;
			menu[options].setString("Full Screen: OFF");
		}
		break;
	case exit_game:
		quit = true;
		break;
	default:
		break;
	}
	
	return quit;
	
}

