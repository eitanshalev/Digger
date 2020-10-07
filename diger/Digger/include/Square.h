#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Unmovable.h"


class Square : public Entity
{
public:
	Square(sf::Vector2f location, sf::Texture *m_texture, int width, int height);
	void draw(sf::RenderWindow& window) ;
	bool checkLocation(const sf::Vector2f& location);
	virtual void handleCollision(Digger& digger) override; //here we are going to handle collisions
	virtual void handleCollision(Wall& wall) override;  //here we are going to handle collisions
	virtual void handleCollision(Rock& rock) override;  //here we are going to handle collisions
	virtual void handleCollision(Diamond& diamond) override;  //here we are going to handle collisions
	virtual void handleCollision(Monster* monster) override {}
	void setTaken() { taken = true; }
	bool isTaken() { return taken; }

private:
	sf::Sprite m_square;
	bool taken;
};
