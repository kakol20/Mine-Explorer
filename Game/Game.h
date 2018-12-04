#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

#include <stdlib.h>
#include <time.h>

#include "Mine.h"

const int height = 10;
const int width = 10;

const int maxEnemyBases = 5;

class Game 
{
public:
	Game();
	~Game();

	void Init();

private:
	
	Tile* grid[width][height];

};
#endif // !GAME_H
