#include "Map.h"

Map::Map()
{
	srand((int)time(0));

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			//delete grid[x][y];
			grid[x][y] = nullptr;

		}
	}

	/*for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{

			grid[x][y] = new Empty(x, y);

		}
	}*/

}

Map::~Map()
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
}

void Map::init(Position playerPos)
{
	//Position pos = player->getPosition();//player->getPosition();

	for (int i = 0; i < maxMines; i++)
	{
		int randX = rand() % width;
		int randY = rand() % height;

		while (grid[randX][randY] != nullptr || (randX == playerPos.x && randY == playerPos.y))
		{
			randX = rand() % width;
			randY = rand() % height;
		}

		//delete grid[randX][randY];
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

	revealNear(playerPos.x, playerPos.y);

}

void Map::draw(Position playerPos)
{
	Position center = playerPos;
	//Position playerPos = center;
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
		displayMiniMap(yMiniMap, playerPos);

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
		displayMiniMap(yMiniMap, playerPos);

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
		displayMiniMap(yMiniMap, playerPos);
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
	displayMiniMap(yMiniMap, playerPos);
}

void Map::displayMiniMap(int yMiniMap, Position playerPos)
{
	//Position playerPos = player->getPosition();

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

void Map::revealNear(int x, int y)
{
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

void Map::nextTurn(Player * player)
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (grid[x][y]->isDiscovered())
			{
				if (dynamic_cast<Mine*>(grid[x][y]))
				{
					Mine* mine = dynamic_cast<Mine*>(grid[x][y]);

					if (!mine->isDamaged())
					{
						player->addGold(mine->getValue());
					}
					else {

					}
				}
			}
		}
	}

}
