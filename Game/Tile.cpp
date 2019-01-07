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

Tile::Tile(const Tile & copyTile)
{
	m_position.x = copyTile.m_position.x;
	m_position.y = copyTile.m_position.y;

	m_discovered = copyTile.m_discovered;
}

Tile & Tile::operator=(const Tile & copyTile)
{
	if (this == &copyTile) return *this;

	m_discovered = copyTile.m_discovered;

	m_position.x = copyTile.m_position.x;
	m_position.y = copyTile.m_position.y;

	return *this;
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
