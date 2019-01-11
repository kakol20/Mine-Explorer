#ifndef TILE_H
#define TILE_H

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

#include "Base.h"

#include "Player.h"
//#include "Enemy.h"
#include "Orc.h"
#include "Witch.h"
#include "Goblin.h"

class Tile {
public:
	Tile(int x, int y);
	virtual ~Tile();

	/*Player(const Player& copyPlayer);
	Player& operator=(const Player& copyPlayer);*/
	Tile(const Tile& copyTile);
	virtual Tile& operator=(const Tile& copyTile);

	//virtual void getEnemyType();
	virtual void Activate(Player* player, int turns) = 0;

	bool isDiscovered();

	//void discover();

	void setDiscovered(bool discovered);

	Position getPosition();

protected:
	Position m_position;
	bool m_discovered;
};
#endif // !TILE_H
