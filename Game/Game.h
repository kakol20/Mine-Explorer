#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

#include <stdlib.h>
#include <time.h>

#include "Base.h"

#include "Empty.h"
#include "Mine.h"

#include "Knight.h"

const int maxEnemyBases = 5;
const int maxMines = 5;

class Game 
{
public:
	Game();
	~Game();

	void Init();

	void mainLoop();

private:
	
	Tile* grid[width][height];

	void drawGrid();

	Player* test;

};
#endif // !GAME_H
