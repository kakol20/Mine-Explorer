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

void Map::init(Player* player, int turns)
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
	m_enemyBaseCount = 0;

	//Position pos = player->getPosition();//player->getPosition();
	Position playerPos = player->getPosition();

	// --------------- SPAWNS MINES ---------------
	for (int i = 0; i < maxMines; i++)
	{
		int randX = rand() % width;
		int randY = rand() % height;

		// makes sure that mine does not spawn on top of the player
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

	// --------------- SPAWNS ENEMY BASES ---------------
	for (int i = 0; i < maxEnemyBases; i++)
	{
		int randX = rand() % width;
		int randY = rand() % height;
		
		while (grid[randX][randY] != nullptr || (randX == playerPos.x && randY == playerPos.y))
		{
			randX = rand() % width;
			randY = rand() % height;
		}

		grid[randX][randY] = new EnemyBase(randX, randY);
		m_enemyBaseCount++;

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

	// --------------- SPAWNS SHOP ---------------
	for (int i = 0; i < maxShops; i++)
	{
		int randX = rand() % width;
		int randY = rand() % height;

		while (grid[randX][randY] != nullptr || (randX == playerPos.x && randY == playerPos.y))
		{
			randX = rand() % width;
			randY = rand() % height;
		}

		grid[randX][randY] = new Shop(randX, randY);
		m_enemyBaseCount++;

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

	// Any other tile will be empty
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (grid[x][y] == nullptr) {
				grid[x][y] = new Empty(x, y);
			}
		}
	}

	revealNear(playerPos.x, playerPos.y, player, turns);

}

void Map::draw(Position playerPos)
{
	Position center = playerPos;
	//Position playerPos = center;
	// Changes the center of left map if player is near edge
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
			// draws edges
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

		// displays right map
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
				else
				{
					std::cout << "   ";
				}
			}
			else
			{
				// displays square if undiscovered
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
					Mine * temp = dynamic_cast<Mine*>(grid[x][y]);
					std::cout << temp->getValue();

					if (temp->isDamaged())
					{
						if (temp->isEnemySpawned())
						{
							std::cout << "W ";
						}
						else
						{
							std::cout << "D ";
						}
					}
					else
					{
						std::cout << "M ";
					}
				}
				else if (dynamic_cast<EnemyBase*>(grid[x][y]))
				{
					std::cout << " E ";
				}
				else if (dynamic_cast<Shop*>(grid[x][y]))
				{
					std::cout << " S ";
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

	// more edges
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

	// displays whole map in less detail reperesented by letters or squares
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
					Mine* mine = dynamic_cast<Mine*>(grid[xMiniMap][yMiniMap]);

					if (mine->isDamaged())
					{
						if (mine->isEnemySpawned())
						{
							std::cout << "W ";
						}
						else
						{
							std::cout << "D ";
						}
					}
					else
					{
						std::cout << "M ";
					}
				}
				else if (dynamic_cast<EnemyBase*>(grid[xMiniMap][yMiniMap]))
				{
					std::cout << "E ";
				}
				else if (dynamic_cast<Shop*>(grid[xMiniMap][yMiniMap]))
				{
					std::cout << "S ";
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
	// displays map legend
	else if (yMiniMap == height + 1)
	{
		std::cout << "P = player";
	}
	else if (yMiniMap == height + 2)
	{
		std::cout << "nM = mine preceded by its value 'n'";
	}
	else if (yMiniMap == height + 3)
	{
		std::cout << "nD = damaged mine preceded by it's value 'n'";
	}
	else if (yMiniMap == height + 4)
	{
		std::cout << "nw = enemy occupied mine preceded by it's value 'n'";
	}
	else if (yMiniMap == height + 5)
	{
		std::cout << "E = enemy base";
	}
	else if (yMiniMap == height + 6)
	{
		std::cout << "S = shop";
	}
	else if (yMiniMap == height + 7)
	{
		std::cout << (char)254 << " = undiscovered area";
	}
	std::cout << "\n";
}

void Map::revealNear(int x, int y, Player* player, int turns)
{
	// reveals adjacent tiles as discovered as the player moves
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i >= 0 && j >= 0 && i < width && j < height)
			{
				if (!grid[i][j]->isDiscovered()) 
				{
					grid[i][j]->Activate(player, turns);
				}
			}
		}
	}
}

void Map::nextTurn(Player * player, int turns)
{
	int chance = rand() % 20; // 1 in 20 chance of spawning an enemy on
	int chosenMine = rand() & maxMines;
	int count = 0;

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (grid[x][y]->isDiscovered())
			{

				// goes through every discovered mine
				if (dynamic_cast<Mine*>(grid[x][y]))
				{
					Mine* mine = dynamic_cast<Mine*>(grid[x][y]);
					
					// mine will not give gold if it's damaged by an enemy
					if (!mine->isDamaged())
					{
						if (chance == 0)
						{
							if (count == chosenMine)
							{
								mine->spawnEnemy();

								std::cout << "Enemy spawned at (" << x << ", " << y << ")!\n";

								mine->setDamage(true);
							}
						}
						else
						{
							player->addGold(mine->getValue());
						}

						count++;
					}
					else
					{
						count = maxMines * -2;
					}
					
				}
			}
		}
	}
}

bool Map::isOnTileType(Player * player)
{
	if (dynamic_cast<Mine*>(grid[player->getPosition().x][player->getPosition().y]))
	{
		Mine* mine = dynamic_cast<Mine*>(grid[player->getPosition().x][player->getPosition().y]);
		if (mine->isDamaged())
		{
			return true;
		}
	}
	else if (dynamic_cast<EnemyBase*>(grid[player->getPosition().x][player->getPosition().y]))
	{
		return true;
	}
	else if (dynamic_cast<Shop*>(grid[player->getPosition().x][player->getPosition().y]))
	{
		return true;
	}
	
	return false;
}

void Map::interact(Player * player, int turns)
{
	//Position pos = player->getPosition()
	Position pos = player->getPosition();

	if (dynamic_cast<Mine*>(grid[pos.x][pos.y]))
	{
		Mine* mine = dynamic_cast<Mine*>(grid[pos.x][pos.y]);

		if (mine->isDamaged())
		{

			int netDamage = mine->interact(player->calculateDamage());

			if (netDamage < 0)
			{
				player->changeHealth(netDamage);
			}
		}
	}
	else if (dynamic_cast<EnemyBase*>(grid[pos.x][pos.y]))
	{
		EnemyBase* base = dynamic_cast<EnemyBase*>(grid[pos.x][pos.y]);

		int netDamage = base->interact(player->calculateDamage());

		if (netDamage > 0) // player won
		{
			// deletes enemy base from grid and replaces it with an empty tile
			delete grid[pos.x][pos.y];
			grid[pos.x][pos.y] = new Empty(pos.x, pos.y);
			grid[pos.x][pos.y]->Activate(player, turns);
			m_enemyBaseCount--;

			system("pause");

			player->customiseStats(10);
		}
		else if (netDamage < 0)
		{
			player->changeHealth(netDamage);
		}

	}
	else if (dynamic_cast<Shop*>(grid[pos.x][pos.y]))
	{
		Shop* shop = dynamic_cast<Shop*>(grid[pos.x][pos.y]);

		shop->buy(player);
	}

	//if (dynamic_cast<grid[])
	//fdd

}

bool Map::isComplete()
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (dynamic_cast<EnemyBase*>(grid[x][y]))
			{
				return false;
			}
			else if (dynamic_cast<Mine*>(grid[x][y]))
			{
				Mine* mine = dynamic_cast<Mine*>(grid[x][y]);

				if (mine->isEnemySpawned())
				{
					return false;
				}
			}
		}
	}

	return true;
}
