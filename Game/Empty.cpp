#include "Empty.h"

Empty::Empty(int x, int y) : Tile(x, y)
{
}

Empty::~Empty()
{
}

void Empty::Activate(Player* player, int turns)
{
	m_discovered = true;
}
