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

	void init(Position playerPos);
	void draw(Position playerPos);
	void revealNear(int x, int y);

	void nextTurn(Player* player);
	
	bool isOnTileType(Player* player);
	void interact(Player* player);


private:

	Tile* grid[width][height];

	void displayMiniMap(int yMiniMap, Position playerPos);	
};

#endif // !MAP_H
