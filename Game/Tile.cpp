#include "Tile.h"

Tile::Tile(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
	m_discovered = false;

	srand((int)time(0));
}

Tile::~Tile()
{
}

Position Tile::getPosition()
{
	return m_position;
}
