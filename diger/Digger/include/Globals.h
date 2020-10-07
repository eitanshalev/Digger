#pragma once
const int WIDTH = 1380;
const int HEIGHT = 720;
const int TIME = 90;
const int GIFT_TIME = 10;
const int DIGGERSPEED = 250;
const int  NUMBER_OF_DIRECTION = 1400;
const int NUMBER_OF_GIFTS = 3;
const int USR_FINISHD = -1;
const int LIVES_OVER = -1;
const int WAKE_UP = 15;
const char DIAMOND = 'D';
const char ROCK = '@';
const char MONSTER = '!';
const char DIGGER = '/';
const char WALL = '#';
const char PRESENT = '+';
const int MAX_NUM_OF_ITEMS = 3;
const int MENU_WIDTH = 450;
const int MENU_HEIGHT = 90;
const int SPACE = 100;
const int FONT_MENU_SIZE = 80;
const int SPRITE_SHEET_SIZE = 32;
enum textureType {
	digger,
	monster,
	diamond,
	rock,
	wall,
	tile,
	timeBonus,
	speedBonus,
	gun_bonus,
	pause_game,
	game_over,
	level_complete,
	tile_g,
	background,
	tile_g_another,
	loading,
};

enum stats {
	scoreText,
	scoreCount,
	LivesText,
	LivesCount,
	RocksText,
	RocksCount,
	clockText,
	clockCount,
	LevelText,
	LevelCount,


};

enum menuSelection {
	play_game,
	options,
	exit_game,
};

enum Direction {
	DOWN,
	LEFT,
	RIGHT,
	UP,

};

enum sound {
	theme,
	hurt,
	death, 
	coin,
	click,
	present,
	ticktock,
	levelpassed,
	finishgame,
};

enum fontType {
	gaming,
	serious,
};