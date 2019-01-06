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

#include "Map.h"

class Game 
{
public:
	Game();
	~Game();

	void Init();

	bool mainLoop();

private:
	
	void nextTurn();

	int m_turns;

	Player* player;

	Map* map;

};
#endif // !GAME_H
