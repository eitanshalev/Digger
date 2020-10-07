#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include "Board.h"
#include "Digger.h"
#include "Entity.h"
#include "Menu.h"


class Controller {
public:
	Controller(sf::RenderWindow& ,int level, bool fullscreen);
	void run();
	void buildStats();
	void updateStats(Digger& digger, float timeLeft, bool wake_up);
	bool handle_keboard_press_situations_please(sf::Clock& currLevel);
	void centerSprite(sf::Sprite &);
	void centerText(sf::Text &);
	void levelCompleted(int &, int&);
	void drawStats();
	void drawGameOver();


private:
	bool m_P_pressed;
	sf::RenderWindow &m_window;
	Board m_board;
	std::vector<sf::Text> m_stats;
	int m_levelNum = 1 ;
	int m_timeStopped;
	float m_pauseTime;
	sf::Sprite m_gameOver;
	sf::Sprite m_paused;
	int m_timeLeft;
	bool fullscreen;
	sf::Sprite m_background;
	int rocksToEat;
	sf::Sound levelPassed;
	sf::Sound heDied;
	sf::Sound gameFinished;
	sf::Sound tickTock;
	sf::Sound music;
	//sf::Music backgroundMusic;
};