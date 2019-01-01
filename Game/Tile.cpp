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

void Tile::discover()
{
	m_discovered = true;
}

Position Tile::getPosition()
{
	return m_position;
}
