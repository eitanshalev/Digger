#include "Resources.h"

Resources::Resources()
{
	//LOADING TEXTURES, SOUNDS, AND FONTS
	sf::Texture texture;
	texture.setSmooth(true);
	texture.loadFromFile("digger.png");		//digger = 0
	m_textures.push_back(texture);

	texture.loadFromFile("monster.png");	//monster = 1
	m_textures.push_back(texture);

	texture.loadFromFile("diamond.png");    // diamond = 2
	m_textures.push_back(texture);

	texture.loadFromFile("rock.png");	    //rock = 3
	m_textures.push_back(texture);

	texture.loadFromFile("wall.png");	    //wall = 4
	m_textures.push_back(texture);

	texture.loadFromFile("background.png");	//tile = 5
	m_textures.push_back(texture);

	texture.loadFromFile("time_bonus.png");	//tile = 6
	m_textures.push_back(texture);

	texture.loadFromFile("speed_bonus.png");//tile = 7
	m_textures.push_back(texture);

	texture.loadFromFile("gun_bonus.png");	//tile = 8
	m_textures.push_back(texture);

	texture.loadFromFile("pause.png");
	m_textures.push_back(texture);			//pause = 9

	texture.loadFromFile("gameover.jpg");
	m_textures.push_back(texture);			//game_over = 10
	
	texture.loadFromFile("levelcomplete.png");
	m_textures.push_back(texture);		   //level complete = 11


	texture.loadFromFile("backg.png");
	m_textures.push_back(texture);         //tile 2nd bacground = 12

	if(texture.loadFromFile("background_sprite.png"))
	m_textures.push_back(texture);			// background = 13

	if (texture.loadFromFile("backg_2.png"))
	m_textures.push_back(texture); // background = 14

	if (texture.loadFromFile("loading.jpg"))
	m_textures.push_back(texture); // loading = 15


	sf::SoundBuffer sound;
	sound.loadFromFile("MusicFile.wav"); //0
	m_sounds.push_back(sound);
	
	sound.loadFromFile("hurt.wav");	//1
	m_sounds.push_back(sound);
		
	sound.loadFromFile("death.wav"); //2
	m_sounds.push_back(sound);


	sound.loadFromFile("coin.wav"); //3
	m_sounds.push_back(sound);

	
	sound.loadFromFile("coliide.wav"); //4
	m_sounds.push_back(sound);

	sound.loadFromFile("present.wav"); //5
	m_sounds.push_back(sound);

	sound.loadFromFile("ticktock.wav"); //6
	m_sounds.push_back(sound);

	sound.loadFromFile("levelpassed.wav"); //7
	m_sounds.push_back(sound);

	sound.loadFromFile("finishgame.wav"); //8
	m_sounds.push_back(sound);
	
	sf::Font font;
	font.loadFromFile("Balonku-Regular.ttf");
	m_fonts.push_back(font);
	font.loadFromFile("Stencil.ttf");
	m_fonts.push_back(font);
}

Resources::~Resources()
{
	m_textures.clear();
	m_fonts.clear();
	m_sounds.clear();
}

Resources& Resources::loadResources()
{
	static Resources loadTextures;
	return loadTextures;
}


sf::Texture &Resources::getTexture(textureType type)
{
	return m_textures[type];
}

sf::Font& Resources::getFont(fontType type)
{
	return m_fonts[type];
}

sf::SoundBuffer &Resources::getSoundBuffer(enum sound type)
{
	return m_sounds[type];
}