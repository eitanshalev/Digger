#pragma once
//21/01/2020
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include "Digger.h"
#include "Globals.h"
#include "Square.h"
#include "Entity.h"
#include "Smartmonster.h"
#include "Easymonster.h"
#include "Wall.h"
#include "Rock.h"
#include "Diamond.h"
#include "Present.h"
#include "RunPresent.h"
#include "TimePresent.h"
#include "GunPresent.h"

class Board {
public:

	Board(int &levelNum);
	void clear_board();
	void drawBoard(sf::RenderWindow &window);
	sf::Vector2f findDigger() const;
	int getWidth();
	int getHeight();
	void moveDigger(Digger& digger, sf::Vector2f prevlocation);
	bool isLegal(const sf::Vector2f& location);
	std::vector < Monster* > findMonsters();
	void findUnmovables();
	void checkCollision(Digger& digger);
	void removeGift();
	int getRocks() { return m_rocksToEat; }
	void insertGift();
	void updateSquare(sf::Vector2f location);
	int getDiamonds() { return m_diamond;  }
	bool isGameOver() { return gameOver; }
	void setGameOver() { gameOver = true; }
	int getTime() { return m_seconds; }
	void reset();

private:

	std::vector <Square> m_squares;
	std::vector <std::string> m_board;
	std::vector <Unmovable*> m_unmovables;
	int m_height;
	int m_width;
	int m_rocksToEat;
	std::vector < Monster* > m_monsters;
	std::vector <Present*> m_gifts;
	int m_diamond;
	bool gameOver;
	int m_seconds;
	sf::Sound giftSound;
	//bool loaded;

	
};
