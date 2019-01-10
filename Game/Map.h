#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>

#include <stdlib.h>
#include <time.h>

#include "Base.h"

#include "Empty.h"
#include "Mine.h"
#include "EnemyBase.h"

#include "Knight.h"

//#include "Map.h"

class Map
{
public:

	Map();
	~Map();

	void init(Player* player, int turns);
	void draw(Position playerPos);
	void revealNear(int x, int y, Player* player, int turns);

	void nextTurn(Player* player, int turns);
	
	bool isOnTileType(Player* player);
	void interact(Player* player, int turns);


private:

	Tile* grid[width][height];

	void displayMiniMap(int yMiniMap, Position playerPos);	

	int m_enemyBaseCount;
};

#endif // !MAP_H
