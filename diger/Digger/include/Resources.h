#pragma once

#include "Globals.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>


//#include "Globals.h"


class Resources
{
public:
	~Resources();
	static Resources& loadResources();
	sf::Texture &getTexture(textureType type);
	sf::SoundBuffer& getSoundBuffer(sound type);
	sf::Font& getFont(fontType type);


private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;
	std::vector<sf::SoundBuffer> m_sounds;
	std::vector<sf::Texture> m_textures;
	std::vector<sf::Font> m_fonts;

};

