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

const int maxEnemyBases = 10;
const int maxMines = 10;

class Game 
{
public:
	Game();
	~Game();

	void Init();

	bool mainLoop();

private:
	
	Tile* grid[width][height];

	void drawGrid();
	//void displayStats();
	void revealNear(int x, int y);
	void nextTurn();

	void displayMiniMap(int yMiniMap);

	Player* player;

};
#endif // !GAME_H
