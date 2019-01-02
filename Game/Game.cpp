#include "Game.h"

Game::Game()
{
	srand((int)time(0));

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			
			grid[x][y] = nullptr;

		}
	}
}

Game::~Game()
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (grid[x][y] != nullptr)
			{ 
				delete grid[x][y]; 
				grid[x][y] = nullptr;
			}
			
		}
	}

	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}
}

void Game::Init()
{
	std::cout << "Game initialized\n";

	player = new Knight();
	player->Init();

	Position pos = player->getPosition();

	for (int i = 0; i < maxMines; i++)
	{
		int randX = rand() % width;
		int randY = rand() % height;

		while (grid[randX][randY] != nullptr || (randX == player->getPosition().x && randY == player->getPosition().y))
		{
			randX = rand() % width;
			randY = rand() % height;
		}

		delete grid[randX][randY];
		//grid[randX][randY] = nullptr;
		grid[randX][randY] = new Mine(randX, randY);

		// to prevent mines spawning adjacent to each other

		for (int i = randX - 1; i <= randX + 1; i++)
		{
			for (int j = randY - 1; j <= randY + 1; j++)
			{
				if (i >= 0 && j >= 0 && i < width && j < height)
				{
					if (grid[i][j] == nullptr)
					{
						grid[i][j] = new Empty(i, j);
					}
				}
			}
		}
	}

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (grid[x][y] == nullptr) {
				grid[x][y] = new Empty(x, y);
			}
		}
	}
	
	revealNear(player->getPosition().x, player->getPosition().y);
	//grid[test->getPosition().x][test->getPosition().y]->discover();
	//grid[test->getPosition().x][test->getPosition().y]->discover();

}

bool Game::mainLoop()
{
	system("cls");

	bool loop = true;

	

	// ---------- DRAW MAIN MAP AND MINIMAP ----------

	drawGrid();

	//std::cout << "---------------\n";
	// https://en.wikipedia.org/wiki/Code_page_437#Character_set
	for (int i = 0; i < 37; i++)
	{
		std::cout << (char)205;
	}
	std::cout << (char)188;

	std::cout << "\n";

	// ---------- OUTPUT PLAYER STATS ----------
	player->displayStats();

	int option = 10000;

	for (int i = 0; i < 30; i++)
	{
		std::cout << (char)205;
	}
	std::cout << "\n";

	// ---------- OUTPUT INTERFACE ----------
	std::cout << "Choose an option:\n" <<
		"0: Move\n" <<
		"1: Quit\n";
	std::cin >> option;

	for (int i = 0; i < 30; i++)
	{
		std::cout << (char)205;
	}
	std::cout << "\n";

	if (option == MOVE)
	{
		char directions[100];

		do
		{
			std::cout << "Choose direction to move\n 'n' for north, 'e' for east, 's' for south & 'w' for west\n";
			std::cin >> directions;
		} while (!player->checkInput(directions));

		for (int i = 0; i < (int)strlen(directions); i++) {
			// what to type to reveal map : nnnnnneeeeeesssssssssssswwwwwwwwwwwwnnnnnnnnnnnneeessssssssseeeeeennnnnn
			player->Move(directions[i]);

			revealNear(player->getPosition().x, player->getPosition().y);

			nextTurn();

			//system("pause");
		}
		system("pause");
	}
	else if (option == QUIT)
	{
		loop = false;
	}
	else 
	{
		std::cout << "Invalid input\n";
		mainLoop();
	}

	//switch (option)
	//{
	//case MOVE:

	//	

	//	break;

	//case QUIT:
	//	
	//	break;

	///*default:
	//	std::cout << "Invalid input\n";
	//	mainLoop();
	//	loop = false;
	//	break;*/
	//}

	//if (option != MOVE && option != QUIT)
	//{
	//	
	//}

	
	return loop;
}

void Game::drawGrid()
{
	// OLD WAY OF DISPLAYING MAP
	/* for (int y = 0; y < height; y++) {
		for (int i = 0; i < width; i++) {
			std::cout << " ---";
		}
		std::cout << "\n";

		for (int x = 0; x < width; x++) {
			std::cout << "| ";
			//if (grid[x][y] != nullptr) {

			//	//if (grid[x][y].)

			//	

			//}
			//else {
			//	//std::cout << (char)219 << "\n";

			//	std::cout << (char)219 << " ";

			//}

			if (grid[x][y]->isDiscovered()) {
				if (x == test->getPosition().x && y == test->getPosition().y) {
					std::cout << "P ";
				}
				else if (dynamic_cast<Mine*>(grid[x][y])) {
					std::cout << "M ";
				}
				else {
					std::cout << "  ";
				}

				/*if (dynamic_cast<Mine*>(grid[x][y])) {
					std::cout << "M ";
				}
			}
			else {
				std::cout << (char)219 << " ";

			}
		}
		std::cout << "|\n";

		for (int i = 0; i < width; i++) {
			std::cout << " ---";
		}
		std::cout << "\n";
	} */

	Position center = player->getPosition();
	Position playerPos = center;
	int viewSize = 3;
	if (center.x < viewSize)
	{
		center.x = viewSize;
	}
	if (center.y < viewSize)
	{
		center.y = viewSize;
	}
	if (center.x >= (width - viewSize))
	{
		center.x = width - viewSize - 1;
	}
	if (center.y >= (height - viewSize))
	{
		center.y = height - viewSize - 1;
	}

	int yMiniMap = -1;

	for (int y = center.y - viewSize; y <= (center.y + viewSize); y++) 
	{
		// using ascii to display grid
		for (int i = 0; i < (viewSize * 2) + 1; i++)
		{
			//std::cout << " ";

			if (y == center.y - viewSize)
			{
				if (i == 0)
				{
					std::cout << (char)218;
				}
				else
				{
					std::cout << (char)194;
				}
			}
			else
			{
				if (i == 0)
				{
					std::cout << (char)195;
				}
				else
				{
					std::cout << (char)197;
				}
			}

			for (int j = 0; j < 4; j++)
			{
				std::cout << (char)196;
			}
			//std::cout << " ---";
		}

		if (y == center.y - viewSize)
		{
			std::cout << (char)191;
		}
		else
		{
			std::cout << (char)180;
		}
		std::cout << " ";

		yMiniMap++;
		displayMiniMap(yMiniMap);

		for (int x = center.x - viewSize; x <= (center.x + viewSize); x++) 
		{
			// top part of grid - will display player
			std::cout << (char)179 << " ";
			if (grid[x][y]->isDiscovered()) 
			{
				if (x == playerPos.x && y == playerPos.y) 
				{
					std::cout << "P  ";
				}
				/*else if (dynamic_cast<Mine*>(grid[x][y])) 
				{
					std::cout << "M  ";
				}*/
				else 
				{
					std::cout << "   ";
				}
			}
			else 
			{
				std::cout << (char)220 << (char)220 << " ";
			}
		}
		std::cout << (char)179 << " ";
		yMiniMap++;
		displayMiniMap(yMiniMap);

		// bottom part of grid - will display tile type
		//std::cout << (char)179 << " ";
		for (int x = center.x - viewSize; x <= (center.x + viewSize); x++)
		{
			// top part of grid - will display player
			std::cout << (char)179 << " ";
			if (grid[x][y]->isDiscovered())
			{
				if (dynamic_cast<Mine*>(grid[x][y]))
				{
					std::cout << " M ";
				}
				else
				{
					std::cout << "   ";
				}
			}
			else
			{
				std::cout << (char)223 << (char)223 << " ";
			}
		}
		std::cout << (char)179 << " ";
		yMiniMap++;
		displayMiniMap(yMiniMap);
	}

	for (int i = 0; i < (viewSize * 2) + 1; i++) 
	{
		if (i == 0)
		{
			std::cout << (char)192;
		}
		else
		{
			std::cout << (char)193;
		}

		//std::cout << " ";
		for (int j = 0; j < 4; j++)
		{
			std::cout << (char)196;
		}
	}
	std::cout << (char)217;

	std::cout << " ";
	yMiniMap++;
	displayMiniMap(yMiniMap);
	//std::cout << "\n";
}

void Game::revealNear(int x, int y)
{
	/*grid[pos.x][pos.y]->Activate();

	if (pos.x - 1 >= 0) {
		if (!grid[])
	}*/

	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i >= 0 && j >= 0 && i < width && j < height)
			{
				if (!grid[i][j]->isDiscovered()) {
					grid[i][j]->Activate();
				}
			}
		}
	}
}

void Game::nextTurn()
{
}

void Game::displayMiniMap(int yMiniMap)
{

	Position playerPos = player->getPosition();

	if (yMiniMap == height)
	{
		std::cout << (char)204;
	}
	else
	{
		std::cout << (char)186 << " ";
	}

	if (yMiniMap < height)
	{
		for (int xMiniMap = 0; xMiniMap < width; xMiniMap++)
		{
			if (grid[xMiniMap][yMiniMap]->isDiscovered())
			{
				if (xMiniMap == playerPos.x && yMiniMap == playerPos.y)
				{
					std::cout << "P ";
				}
				else if (dynamic_cast<Mine*>(grid[xMiniMap][yMiniMap]))
				{
					std::cout << "M ";
				}
				else
				{
					std::cout << "  ";
				}
			}
			else
			{
				std::cout << (char)254 << " ";
			}
		}
	}
	else if (yMiniMap == height)
	{
		for (int i = 0; i < 30; i++)
		{
			std::cout << (char)205;
		}
	}
	else if (yMiniMap == height + 1)
	{
		std::cout << "P = player";
	}
	else if (yMiniMap == height + 2)
	{
		std::cout << "M = mine";
	}
	else if (yMiniMap == height + 3)
	{
		std::cout << (char)254 << " = undiscovered area";
	}
	std::cout << "\n";
}
