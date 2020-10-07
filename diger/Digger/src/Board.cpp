#include "Board.h"



//16/01/2020  21:58
Board::Board(int &levelNum)
{
	static std::ifstream boardFile;
	

	if (levelNum == 1)
		boardFile.seekg(0, std::ios::beg);
	//static std::ifstream boardFile;
	if (!boardFile.eof())
	{
		gameOver = false;
		m_diamond = 0;
		 //this integer will help us know if it is the fisrt loading
		static bool first_loading = true; 

		if (first_loading)
		{
			boardFile.open("Board.txt", std::ifstream::in);
			first_loading = false;
		}

		if (boardFile.is_open())
		 {
			static int in_is_the_sec_stage = 0;
			 //means we in the secound's (or other except level 0) level
			if (in_is_the_sec_stage == 1)
			{
				boardFile.get();
			}



			boardFile >> m_height >> m_width >> m_rocksToEat >> m_seconds;
			char c = boardFile.get();

			//auto result = std::vector <std::string>();//define the vector

			std::string line;
			for (int num_of_line = 0; num_of_line < m_height; num_of_line++)
			{
				std::getline(boardFile, line);
				m_board.push_back(line);
			}
			srand(17);
			int random = rand()%20;
			
			int row = 0;
			int counter = 0;
			for (int i = 0; i < m_height; i++) {
				int col = 0;
				
				for (int j = 0; j < m_width; j++) {
					//build the board thathas recived fron user/ boarb.txt
					 random = rand()%50;
					auto pos = sf::Vector2f(col, row);
					if ( !(random ==1 || random == 2))//counter != 15)
					{
						if(random % 2 == 0)
						{
							m_squares.push_back(Square(pos, &Resources::loadResources().getTexture(tile_g_another), m_width, m_height));
	
						}
						else
							m_squares.push_back(Square(pos, &Resources::loadResources().getTexture(tile), m_width, m_height));
						
					}
					else 
					{
						m_squares.push_back(Square(pos, &Resources::loadResources().getTexture(tile_g), m_width, m_height));
						
					}
					

					col += (WIDTH / m_width);
				}
				row += ((HEIGHT / m_height));
			}
		}


		//m_boadtx = boardFile
	}

	else gameOver = true;

}

void Board::clear_board()
{
	m_squares.clear();
	m_board.clear();

	for (auto p : m_unmovables)
	{
		delete p;
	}
	m_unmovables.clear();


	for (auto p : m_monsters)
	{
		delete p;
	}
	m_monsters.clear();

	for (auto p : m_gifts)
	{
		delete p;
	}

	m_gifts.clear();
}

void Board::checkCollision(Digger &myDigger)
{
	for (auto i = size_t(0); i < m_monsters.size(); i++)
	{

		if (m_monsters[i]->getSprite().getGlobalBounds().intersects(myDigger.getSprite().getGlobalBounds() ))
		{
			m_monsters[i]->handleCollision(myDigger);

		}
	}

	for (auto i = size_t(0); i < m_unmovables.size(); i++)
	{

		if (m_unmovables[i]->getSprite().getGlobalBounds().intersects(myDigger.getSprite().getGlobalBounds()))
		{
			m_unmovables[i]->handleCollision(myDigger);

		}
		for (auto j = size_t(0); j < m_monsters.size(); j++)
		{
			if (m_unmovables[i]->getSprite().getGlobalBounds().intersects(m_monsters[j]->getSprite().getGlobalBounds()))

			{
				m_unmovables[i]->handleCollision(m_monsters[j]);
				//m_monsters[j]->handleCollision(m_objects[i]);
			}
				

		}
	}

	

	for (auto i = size_t(0); i < m_gifts.size(); i++)
	{

		if (m_gifts[i]->getSprite().getGlobalBounds().intersects(myDigger.getSprite().getGlobalBounds()))
		{
			m_gifts[i]->handleCollision(myDigger);
			if(m_gifts[i]->isThere())
			giftSound.play();
		}
	
	}


	//for (auto& m_objects : m_objects){
	//if (m_objects->getSprite().getLocalBounds().intersects(myDigger.getSprite().getLocalBounds() ))
	//	{
	//		//intersects (const Rect< T > &rectangle, Rect< T > &intersection) const
	//		m_objects->handleCollision(myDigger);

	//	}
	//	}


}

void Board::removeGift()
{
	for (int i = 0; i < m_gifts.size(); i++) {

		if (m_gifts[i]->isThere())
		{
			m_gifts[i]->erase();
			return;
		}
	}
}

void Board::insertGift()
{
	
	/*while()*/
	

for (int i = rand()% m_squares.size(); i < m_squares.size(); i++)
	{
		sf::Vector2f squareLocation = m_squares[i].getLocation(); // 
		if (m_squares[i].isTaken()) //in case there is an object in square
		{
			//sf::Vector2f giftLocation = 
			for (int j = 0; j < m_unmovables.size(); j++)
			{
				if ( m_unmovables[j]->checkLocation(squareLocation) && !m_unmovables[j]->isThere() )
				{
					
					int indexOfPresent = rand() % NUMBER_OF_GIFTS; // 3 kind of presents
					switch (indexOfPresent) 
					{
					case 0: //runbounus
						m_gifts.push_back(new RunPresent(squareLocation, &Resources::loadResources().getTexture(speedBonus), m_width, m_height));
						break;
					case 1:
						m_gifts.push_back(new TimePresent(squareLocation, &Resources::loadResources().getTexture(timeBonus), m_width, m_height));
						break;
					case 2:
						m_gifts.push_back(new GunPresent(squareLocation, &Resources::loadResources().getTexture(gun_bonus), m_width, m_height));
						break;
					default:
						break;

					}
					
					updateSquare(m_squares[i].getLocation());
					return;
				}
				
			}
		}
		else //in case its empty
		{

			
			int indexOfPresent = rand() % NUMBER_OF_GIFTS; // 3 kind of presents
			switch (indexOfPresent)
			{
			case 0: //runbounus
				m_gifts.push_back(new RunPresent(squareLocation, &Resources::loadResources().getTexture(speedBonus), m_width, m_height));
				break;
			case 1:
				m_gifts.push_back(new TimePresent(squareLocation, &Resources::loadResources().getTexture(timeBonus), m_width, m_height));
				break;
			case 2:
				m_gifts.push_back(new GunPresent(squareLocation, &Resources::loadResources().getTexture(gun_bonus), m_width, m_height));
				break;
			default:
				break;

			}
			
			updateSquare(m_squares[i].getLocation());
			return;
		}

		
	}
}

void Board::updateSquare(sf::Vector2f location)
{

	for (int i = 0; i < m_squares.size(); i++) {
		if (m_squares[i].checkLocation(location)) {
			m_squares[i].setTaken();
			return;
		}
	}

}

void Board::reset()
{
	for (auto i = size_t(0); i < m_monsters.size(); i++)
	{
		m_monsters[i]->resetPosition();
	}

	for (auto i = size_t(0); i < m_unmovables.size(); i++)
	{
		m_unmovables[i]->unErase();
	}
}


void Board::drawBoard(sf::RenderWindow& window)
{


	for (auto i = size_t(0); i < m_squares.size(); i++)
	{
		m_squares[i].draw(window);
	}
	for (auto i = size_t(0); i < m_monsters.size(); i++)
	{
		m_monsters[i]->draw(window);
	}

	for (auto i = size_t(0); i < m_unmovables.size(); i++)
	{
		m_unmovables[i]->draw(window);
	}
	for (auto i = size_t(0); i < m_gifts.size(); i++)
	{
		m_gifts[i]->draw(window);
	}
}

sf::Vector2f Board::findDigger() const
{
	
	for (int row = 0; row < m_height; row++)
	{
		for (int col = 0; col < m_width; col++)
		{
			if (m_board[row][col] == DIGGER)
			{
				sf::Vector2f diggerLocation;
				diggerLocation.x = col*  (WIDTH / m_width);
				diggerLocation.y = row* (HEIGHT / m_height);
				return diggerLocation;
			}
		}
	}
}

std::vector < Monster* > Board::findMonsters()
{
	
	bool smart_monster = true;
	for (int row = 0; row < m_height; row++)
	{
		for (int col = 0; col < m_width; col++)
		{
			if (m_board[row][col] == MONSTER)
			{
				sf::Vector2f MonsterLocation;
				MonsterLocation.x = col* (WIDTH / m_width);
				MonsterLocation.y = row * (HEIGHT / m_height);
	
				if (smart_monster == true)
				{

					m_monsters.push_back(new Smartmonster(MonsterLocation, &Resources::loadResources().getTexture(monster), m_width, m_height));
					smart_monster = false;
				}
				else
				{
					m_monsters.push_back(new Easymonster(MonsterLocation, &Resources::loadResources().getTexture(monster), m_width, m_height));
					smart_monster = true;
				}
				updateSquare(MonsterLocation);
			}
		}
	}

	return m_monsters;
}
void Board::moveDigger( Digger &digger, sf::Vector2f prevlocation)
{
		if (!isLegal(digger.getLocation()))
			digger.setLocation(prevlocation);

}


void Board::findUnmovables()
{
	sf::Vector2f ObjectLocation;
	for (int row = 0; row < m_height; row++)
	{
		bool foundObject = false;
		for (int col = 0; col < m_width; col++)
		{
			bool foundObject = false;

				ObjectLocation.x = col * (WIDTH / m_width);
				ObjectLocation.y = row * (HEIGHT / m_height);
				char ObjectType = m_board[row][col];
				switch (ObjectType)
				{
				case ROCK:
					m_unmovables.push_back(new Rock(ObjectLocation, &Resources::loadResources().getTexture(rock), m_width, m_height));
					foundObject = true;
					break;
				case DIAMOND:
					m_unmovables.push_back(new Diamond(ObjectLocation, &Resources::loadResources().getTexture(diamond), m_width, m_height));
					m_diamond++;
					foundObject = true;
					break;
				case WALL:
					m_unmovables.push_back(new Wall(ObjectLocation, &Resources::loadResources().getTexture(wall), m_width, m_height));
					foundObject = true;
					break;
				case PRESENT:
					for (int i = 0; i < m_squares.size(); i++) {
						if (m_squares[i].checkLocation(ObjectLocation)) {
							m_gifts.push_back(new GunPresent(m_squares[i].getLocation(), &Resources::loadResources().getTexture(gun_bonus), m_width, m_height));
							break;
						}
					}
					break;
				default:
					break;
				}
			if (foundObject)
				updateSquare(ObjectLocation);
		}
	}
}

int Board::getWidth() {
return m_width;
}

int Board::getHeight()
{
	return m_height;
}



bool Board::isLegal(const sf::Vector2f& location)
{
	return (location.y < HEIGHT && location.x < WIDTH &&
		location.y >= 0 && location.x >= 0);
}
