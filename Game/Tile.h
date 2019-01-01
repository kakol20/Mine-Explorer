#ifndef TILE_H
#define TILE_H

#include <stdlib.h>
#include <time.h>

#include "Base.h"

class Tile {
public:
	Tile(int x, int y);
	virtual ~Tile();

	virtual void Activate() = 0;

	bool isDiscovered();

	void discover();

	Position getPosition();

protected:
	Position m_position;
	bool m_discovered;
};
#endif // !TILE_H
