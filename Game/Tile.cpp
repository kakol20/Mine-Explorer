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

bool Tile::isDiscovered()
{
	return m_discovered;
}

void Tile::setDiscovered(bool discovered)
{
	m_discovered = discovered;
}

Position Tile::getPosition()
{
	return m_position;
}
