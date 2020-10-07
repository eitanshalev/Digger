#include "Controller.h"

Controller::Controller(sf::RenderWindow &window ,int level, bool the_fullscreen)
	:m_board(level), m_levelNum(level), fullscreen(the_fullscreen), m_window(window)
{

	rocksToEat = 0;

	m_background.setTexture(Resources::loadResources().getTexture(background));
	sf::Vector2f set = (sf::Vector2f)Resources::loadResources().getTexture(background).getSize();
	sf::Vector2f newScale;
	newScale.x = WIDTH / set.x;
	newScale.y = (HEIGHT + 50) / set.y;
	m_background.scale(newScale);

	m_timeStopped = 0;
	m_pauseTime = 0;
	m_P_pressed = false;

	m_gameOver.setTexture(Resources::loadResources().getTexture(game_over));
	m_paused.setTexture(Resources::loadResources().getTexture(pause_game));
	
	centerSprite(m_paused);

	m_timeLeft = m_board.getTime();

	heDied.setBuffer(Resources::loadResources().getSoundBuffer(death));
	tickTock.setBuffer(Resources::loadResources().getSoundBuffer(ticktock));
	levelPassed.setBuffer(Resources::loadResources().getSoundBuffer(levelpassed));
	gameFinished.setBuffer(Resources::loadResources().getSoundBuffer(finishgame));
	music.setBuffer(Resources::loadResources().getSoundBuffer(theme));
}

void Controller::run()
{
	music.play();
	sf::Clock GiftTime;
	bool diggerIsHit = false;
	Menu menu;
	fullscreen = false;
	static int first_time = 0;
	m_window.display();
	auto event = sf::Event{};
	float timeBonus = 0;
	sf::Clock currLevel;
	currLevel.restart();
	
	sf::Vector2f diggerLocation = m_board.findDigger();
	m_board.findUnmovables();
	
	Digger   myDigger(diggerLocation, &Resources::loadResources().getTexture(digger), m_board.getWidth(), m_board.getHeight());
	myDigger.setRocks(m_board.getRocks());

	std::vector <Monster*>   myMonsters =  m_board.findMonsters();
	sf::Clock clock;

	bool wake_up = false;
	buildStats();
	sf::Text readyTime;
	readyTime.setFont(Resources::loadResources().getFont(gaming));
	readyTime.setColor(sf::Color::White);
	centerText(readyTime);
	bool StartLevel = false;
	int currLevelScore = 0;

	while (m_window.isOpen() && m_levelNum!= USR_FINISHD)
	{
		if (myDigger.getLives() == LIVES_OVER)
		{
			music.stop();
			heDied.play();
			drawGameOver();
			return;
		}
		m_window.clear(sf::Color(101, 67, 33));

		if (!StartLevel) {
			if (!diggerIsHit) {
				currLevelScore = myDigger.get_score();
				diggerIsHit = false;
			}
			currLevel.restart();
			auto smallEvent = sf::Event{};

			while ((int)currLevel.getElapsedTime().asSeconds() < 4)
			{
				m_window.clear();
				m_window.draw(m_background);
				m_board.drawBoard(m_window);
				myDigger.draw(m_window);
				readyTime.setCharacterSize(500);
				readyTime.setPosition(515, 30);
				readyTime.Bold;
				readyTime.setString(std::to_string(3 - (int)currLevel.getElapsedTime().asSeconds()));

				if ( (3 - (int)currLevel.getElapsedTime().asSeconds()) == 3)
				{
					readyTime.setColor(sf::Color::Red);
				}
				if ( (3 - (int)currLevel.getElapsedTime().asSeconds()) == 2)
				{
					readyTime.setColor(sf::Color::Yellow);
				}
				if ( (3 - (int)currLevel.getElapsedTime().asSeconds()) == 1)
				{
					readyTime.setColor(sf::Color::Green);
				}
				if( (3 - (int)currLevel.getElapsedTime().asSeconds()) == 0)
				{
					readyTime.setCharacterSize(FONT_MENU_SIZE+50);
					readyTime.Bold;
					readyTime.setPosition(120, 200);
					readyTime.setColor(sf::Color::Blue);
					//centerText(readyTime);
					readyTime.setString("GO! GOOD LUCK!");
				}
				if ((3 - (int)currLevel.getElapsedTime().asSeconds()) == -1)
					break;
				m_window.draw(readyTime);
				m_window.display();
				handle_keboard_press_situations_please(currLevel);
			
			}

			clock.restart();

			currLevel.restart();
			StartLevel = true;
		}
		
		m_board.drawBoard(m_window);
		myDigger.draw(m_window);
;
		m_timeLeft += myDigger.getTimeBonus();



		auto event = sf::Event{};
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}
		}

		float deltaTime = clock.restart().asSeconds();
		
		if(handle_keboard_press_situations_please(currLevel))
			float deltaTime = clock.restart().asSeconds();
		
			for (int i = 0; i < myMonsters.size(); i++)
			{
				myMonsters[i]->move(myDigger, deltaTime );
			}
			myDigger.update(deltaTime );
	
		m_board.checkCollision(myDigger);
		int number_of_eaten_diamond = myDigger.diamondsEaten();
		 rocksToEat = myDigger.rocksEaten();

		if ( (m_timeLeft - m_timeStopped - (int)currLevel.getElapsedTime().asSeconds()) == 0 && m_timeLeft != -1)
		{
			m_board.reset();
			rocksToEat = m_board.getRocks();
			myDigger.setRocks(rocksToEat);
			number_of_eaten_diamond = 0;
			StartLevel = false;
			myDigger.restoreDiggerScore(currLevelScore);
			myDigger.ouchie();
			myDigger.continueGame();
		}
		if (m_timeLeft - m_timeStopped - currLevel.getElapsedTime().asSeconds() < WAKE_UP && m_timeLeft != -1)
			wake_up = true;
		else	
			wake_up = false;
		
		updateStats(myDigger, m_timeLeft - m_timeStopped - currLevel.getElapsedTime().asSeconds(), wake_up);
		drawStats();

		int number_of_diamond = m_board.getDiamonds();
	
	
		if (number_of_diamond == number_of_eaten_diamond || m_board.isGameOver()) //means we finished the game...
		{
			myDigger.levelBonus();
			music.pause();
			if (!m_board.isGameOver())
			{
				music.pause();
				levelPassed.play();
				
				levelCompleted(currLevelScore, m_levelNum);
				if (m_window.isOpen())
					music.play();

				else return;
				m_board.clear_board();
				m_levelNum++;
				m_board = Board(m_levelNum);

				
	
			}
			
			if (!m_board.isGameOver() )//&& (m_levelNum =! USR_FINISHD))
			{
				number_of_eaten_diamond = 0;
				m_board.findUnmovables();
				
				diggerLocation = m_board.findDigger();
				int saveLives = myDigger.getLives();
				int saveScore = myDigger.getScore(); 
				
				Digger  newDigger(diggerLocation, &Resources::loadResources().getTexture(digger), m_board.getWidth(), m_board.getHeight());
				newDigger.restoreDigger(saveLives, saveScore);

				myDigger = newDigger;
				myDigger.setRocks(m_board.getRocks());
				myMonsters = m_board.findMonsters();
				m_timeLeft = m_board.getTime();
				StartLevel = false;
				m_timeStopped = 0;
			}
			else
			{

				music.stop();
				gameFinished.play();
				updateStats(myDigger, m_timeLeft - m_timeStopped - currLevel.getElapsedTime().asSeconds(), wake_up);
				drawGameOver();
				return;
			}
		}

		myDigger.draw(m_window);

	
		if (myDigger.isHit())
		{
			diggerIsHit = true;
			for (int i = 0; i < myMonsters.size(); i++)
			{
				myMonsters[i]->resetPosition();

			}
			myDigger.continueGame();
			StartLevel = false;
			continue;
		}

		if (rocksToEat == -1)
		{
			m_board.reset();
			rocksToEat = m_board.getRocks();
			myDigger.setRocks(rocksToEat);
			number_of_eaten_diamond = 0;
			StartLevel = false;
			myDigger.restoreDiggerScore(currLevelScore);
			myDigger.ouchie();
			myDigger.continueGame();
		}

	static bool giftGiven = false;

		if ((int)currLevel.getElapsedTime().asSeconds() % GIFT_TIME == 0 && !giftGiven) //each 15 secounds
		{
			m_board.insertGift();
			giftGiven = true;
		}

		if ((int)GiftTime.getElapsedTime().asSeconds() % 10 == 0)
		{
			m_board.removeGift();
			giftGiven = false;
		}



		if ((int)currLevel.getElapsedTime().asSeconds() % 10 == 0)
		{
			myDigger.resetSpeed();
		}
		
		
		m_window.display();
	}
}

void Controller::buildStats()
{
	sf::Text text;

		text.setFont(Resources::loadResources().getFont(serious));
		text.setCharacterSize(32); // in pixels, not points!
	
		text.setStyle(sf::Text::Bold );
		text.setColor(sf::Color(100, 234, 1));
		sf::Vector2f Location = sf::Vector2f(0.0f, HEIGHT);
		text.setString("Score:");
		text.setPosition(Location);
		m_stats.push_back(text);

		 Location = sf::Vector2f(100.0f, HEIGHT);
		text.setString("0");
		text.setPosition(Location);
		m_stats.push_back(text);

		 Location = sf::Vector2f(200.0f, HEIGHT);
		text.setString("Lives:");
		text.setPosition(Location);
		m_stats.push_back(text);

		Location = sf::Vector2f(300.0f, HEIGHT);
		text.setString("3");
		text.setPosition(Location);
		m_stats.push_back(text);

		Location = sf::Vector2f(400.0f, HEIGHT);
		text.setString("Rocks Left:");
		text.setPosition(Location);
		m_stats.push_back(text);

		Location = sf::Vector2f(600.0f, HEIGHT);
		text.setString("7");
		text.setPosition(Location);
		m_stats.push_back(text);

		 Location = sf::Vector2f(700.0f, HEIGHT);
		text.setString("Time left:");
		text.setPosition(Location);
		m_stats.push_back(text);

	    Location = sf::Vector2f(900.0f, HEIGHT);
		text.setString("30");
		text.setPosition(Location);
		m_stats.push_back(text);

		Location = sf::Vector2f(1000.0f, HEIGHT);
		text.setString("Level:");
		text.setPosition(Location);
		m_stats.push_back(text);
		
		 Location = sf::Vector2f(1100.0f, HEIGHT);
		text.setString("1");
		text.setPosition(Location);
		m_stats.push_back(text);


		
}

void Controller::updateStats(Digger& digger, float timeLeft, bool wake_up)
{
	m_stats[scoreCount].setString(std::to_string(digger.getScore()));
	m_stats[LivesCount].setString(std::to_string(digger.getLives()));
	m_stats[RocksCount].setString(std::to_string(digger.getRocks()));
	if (wake_up)
	{
		m_stats[clockCount].setColor(sf::Color::Red);
		static bool largetime = false;
		if (largetime == false)
		{
			m_stats[clockCount].setCharacterSize(37);
			largetime = true;
		}
		else {
			m_stats[clockCount].setCharacterSize(32);
			largetime = false;
		}
	

	}
	else
	{
		m_stats[clockCount].setColor(sf::Color(100, 234, 1));
	}
	m_stats[clockCount].setString(std::to_string((int)timeLeft));
	m_stats[LevelCount].setString(std::to_string(m_levelNum));
}

void Controller::drawStats()
{
	for (int i = 0; i < m_stats.size(); i++) {
		if (!(m_timeLeft == -1 && i == clockCount))
			m_window.draw(m_stats[i]);
	}
}

void Controller::drawGameOver()
{

	sf::Text endDetails;
	endDetails = m_stats[scoreCount];
	
		
	endDetails.setColor(sf::Color(233,159,112));
	endDetails.setPosition(870, 440);
	endDetails.setCharacterSize(90);

	sf::Vector2f set = (sf::Vector2f)Resources::loadResources().getTexture(game_over).getSize();
	sf::Vector2f newScale;
	newScale.x = WIDTH / set.x;
	newScale.y = HEIGHT / set.y;
	m_gameOver.scale(newScale);
	m_window.clear();
	drawStats();
	m_window.draw(m_gameOver);
	m_window.draw(endDetails);
	m_window.display();

		while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				m_window.close();
				return;
			}

		}

		return;
}

bool Controller::handle_keboard_press_situations_please(sf::Clock &currLevel)
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		static bool fullscreen = false;
		if (fullscreen == true)
		{
			m_window.create(sf::VideoMode(WIDTH, HEIGHT + 50), "Digger", sf::Style::Fullscreen);
			fullscreen = false;
		}
		else if (fullscreen == false)
		{
			m_window.create(sf::VideoMode(WIDTH, HEIGHT + 50), "Digger", sf::Style::Default);
			fullscreen = true;
		}
	}	
	
	bool escapePressed = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
	{
		music.pause();

		escapePressed = true;
		m_P_pressed = true;
		sf::Clock PauseTime;
		PauseTime.restart();
		m_timeStopped += currLevel.getElapsedTime().asSeconds();
		
		m_window.draw(m_paused);
		m_window.display();

		while (m_P_pressed)
		{

			currLevel.getElapsedTime();

	

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
			{
				m_levelNum = USR_FINISHD;
				break; 
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
			{
				 m_P_pressed = false;
				 currLevel.restart();
				 m_pauseTime = PauseTime.restart().asSeconds();
				 music.play();
				 break;
			}
		}
	}
	return escapePressed;
}

void Controller::centerSprite(sf::Sprite& sprite)
{
	sprite.setPosition((float)WIDTH / 2, (float)HEIGHT / 2);
	sf::Rect<float> size = sprite.getLocalBounds();
	sprite.setOrigin(size.width / 2, size.height / 2);
}

void Controller::centerText(sf::Text& text)
{
	text.setPosition((float)WIDTH / 2, (float)HEIGHT / 2);
	sf::Rect<float> size = text.getLocalBounds();
	text.setOrigin(size.width / 2, size.height / 2);
}

void Controller::levelCompleted(int &score, int &levelNum)
{
	sf::Sprite levelDone;
	levelDone.setTexture(Resources::loadResources().getTexture(level_complete));
	sf::Vector2f set = (sf::Vector2f)Resources::loadResources().getTexture(level_complete).getSize();
	sf::Vector2f newScale;
	newScale.x = WIDTH / set.x;
	newScale.y = HEIGHT / set.y;
	levelDone.scale(newScale);
	sf::Text scoreText = m_stats[scoreCount];
	scoreText.setFont(Resources::loadResources().getFont(serious));
	scoreText.setFillColor(sf::Color(185,125,92));
	scoreText.setColor((sf::Color(185, 125, 92)));

	scoreText.setCharacterSize(94);
	scoreText.setPosition(400, 240);

	sf::Text bonus = scoreText;
	centerText(bonus);
	bonus.setColor(sf::Color::Green);

	bonus.setString("+ 20 Bonus!");

	centerSprite(levelDone);

	m_window.draw(levelDone);
	m_window.draw(scoreText);
	m_window.draw(bonus);
	m_window.display();

	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_window.close();
			return;
		}
	}
	
	return;
}

