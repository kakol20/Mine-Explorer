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

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (grid[x][y] == nullptr) {
				grid[x][y] = new Empty(x, y);
			}
		}
	}

	Position pos = player->getPosition();

	for (int i = 0; i < maxMines; i++)
	{
		int randX = rand() % width;
		int randY = rand() % height;

		while (!dynamic_cast<Empty*>(grid[randX][randY]) || (randX == player->getPosition().x && randY == player->getPosition().y))
		{
			randX = rand() % width;
			randY = rand() % height;
		}

		delete grid[randX][randY];
		//grid[randX][randY] = nullptr;
		grid[randX][randY] = new Mine(randX, randY);	
	}
	
	revealNear(player->getPosition().x, player->getPosition().y);
	//grid[test->getPosition().x][test->getPosition().y]->discover();
	//grid[test->getPosition().x][test->getPosition().y]->discover();

}

bool Game::mainLoop()
{
	system("cls");

	bool loop = true;

	drawGrid();
	player->displayStats();

	int option = 10000;

	std::cout << "Choose an option:\n" <<
		"0: Move\n" <<
		"1: Quit\n";
	std::cin >> option;

	switch (option)
	{
	case MOVE:
		

		char directions[100];

		do
		{
			std::cout << "Choose direction to move\n 'n' for north, 'e' for east, 's' for south & 'w' for west\n";
			std::cin >> directions;
		} while (!player->checkInput(directions));	

		for (int i = 0; i < (int)strlen(directions); i++) {
			player->Move(directions[i]);

			revealNear(player->getPosition().x, player->getPosition().y);

			nextTurn();

			//system("pause");
		}
		

		break;

	case QUIT:
		loop = false;
		break;
	}
	
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

	for (int y = center.y - viewSize; y <= (center.y + viewSize); y++) 
	{
		for (int i = 0; i < (viewSize * 2) + 1; i++)
		{
			std::cout << " ---";
		}
		std::cout << "\n";

		for (int x = center.x - viewSize; x <= (center.x + viewSize); x++) 
		{
			std::cout << "| ";

			if (grid[x][y]->isDiscovered()) 
			{
				if (x == playerPos.x && y == playerPos.y) 
				{
					std::cout << "P ";
				}
				else if (dynamic_cast<Mine*>(grid[x][y])) 
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
				std::cout << (char)219 << " ";
			}

			//std::cout << " | ";
		}
		std::cout << "|\n";
	}
	for (int i = 0; i < (viewSize * 2) + 1; i++) 
	{
		std::cout << " ---";
	}
	std::cout << "\n";
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
