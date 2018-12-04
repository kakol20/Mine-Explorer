#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

#include <stdlib.h>
#include <time.h>

#include "Mine.h"

const int height = 15;
const int width = 15;

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
	
	Tile * grid[width][height];

	void drawGrid();

};
#endif // !GAME_H
