#ifndef TILE_H
#define TILE_H

#include "Enums.h"

class Tile {
public:
	Tile(int x, int y);
	virtual ~Tile();

	virtual void Activate() = 0;

	Position getPosition();

protected:
	Position m_position;
	bool m_discovered;
};
#endif // !TILE_H
