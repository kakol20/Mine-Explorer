#ifndef TILE_H
#define TILE_H

#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "Base.h"

class Tile {
public:
	Tile(int x, int y);
	virtual ~Tile();

	/*Player(const Player& copyPlayer);
	Player& operator=(const Player& copyPlayer);*/
	Tile(const Tile& copyTile);
	virtual Tile& operator=(const Tile& copyTile);

	virtual void Activate() = 0;

	bool isDiscovered();

	//void discover();

	void setDiscovered(bool discovered);

	Position getPosition();

protected:
	Position m_position;
	bool m_discovered;
};
#endif // !TILE_H
