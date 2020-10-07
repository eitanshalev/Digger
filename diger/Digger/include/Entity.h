#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <iostream>
#include <vector>
#include "Globals.h"
#include "Resources.h"

class Digger;
class Wall;
class Rock;
class Diamond;
class Monster;

class Entity 
{

public:
	Entity(sf::Vector2f position, sf::Texture* texture, int width, int height);
	~Entity();
	void setSize(int width, int height);
	void setImage(sf::Texture* texture);
	void draw(sf::RenderWindow& window);
	void setLocation(const sf::Vector2f& location);
	sf::Vector2f getLocation() { return m_position; }
	sf::Sprite getSprite() { return m_sprite; }
	void setSprite(sf::Sprite& sprite) { m_sprite = sprite; }
	void placeInSquare();
	virtual void handleCollision(Digger & digger) = 0; //here we are going to handle collisions
	virtual void handleCollision(Wall & wall) = 0;  //here we are going to handle collisions
	virtual void handleCollision(Rock & rock) = 0;  //here we are going to handle collisions
	virtual void handleCollision(Diamond & diamond) = 0;  //here we are going to handle collisions
	virtual void handleCollision(Monster* monster) = 0;
	virtual void erase();
	virtual void unErase();
	virtual bool isThere() {return exists;}
	virtual bool checkLocation(sf::Vector2f location);
	void resetPosition();
	sf::Vector2f origin();



private:

	sf::Vector2f startingPosition;

	int m_width;
	int m_height;
	sf::Vector2f m_origin;
	sf::Vector2f m_position;
	sf::Texture *m_texture;
	sf::Sprite m_sprite;
	bool exists;
	
	//sf::Vector2f prevLocation;
};
