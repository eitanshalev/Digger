#pragma once

#include "Creature.h"
#include <SFML/Graphics.hpp>



class Digger : public Creature
{
public:
	
	Digger(sf::Vector2f m_position, sf::Texture *texture, int m_lives, int m_score);
	int getScore() { return m_score; }
	void update(float delatTime);
	virtual void handleCollision(Digger& digger) override; //here we are going to handle collisions
	virtual void handleCollision(Wall& wall) override;  //here we are going to handle collisions
	virtual void handleCollision(Rock& rock) override;  //here we are going to handle collisions
	virtual void handleCollision(Diamond& diamond) override;  //here we are going to handle collisions
	virtual void handleCollision(Monster* monster) override;
	void restoreDiggerScore(int& score);
	void restoreDigger(int& lives, int& score);
	void addPoints();
	void levelBonus();
	void stayInPlace();
	void speedBonus();
	void resetSpeed();
	int getLives() { return m_lives; }
	void setRocks(int rocks) { rocksToEat = rocks; }
	int getRocks() { return rocksToEat; }
	void ateRock() { rocksToEat--; }
	int get_score() { return m_score;  }
	void ouchie();
	bool isHit() { return ouch; }
	void continueGame(){ ouch = false; }
	int diamondsEaten() { return m_currDiamondsEaten; }
	int rocksEaten() { return rocksToEat; }
	void timeBonus() { m_timeBonus = 10; }
	int getTimeBonus();
	void addLife() { m_lives++; }
	void Animate();

private:
	int m_currDiamondsEaten;
	int m_lives;
	int m_score = 0;
	sf::Sprite m_sprite;
	sf::Vector2f prevLocation;
	float speed;
	int rocksToEat;
	bool ouch;
	int m_timeBonus;
};



