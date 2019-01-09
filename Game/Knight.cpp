#include "Knight.h"

// empty for now
Knight::Knight()
{
}

Knight::~Knight()
{
}

int Knight::calculateDamage()
{
	float randStr = (float)(rand() % m_strength + 1);
	float randInt = (float)(rand() % m_intelligence + 1);
	float randDxt = (float)(rand() % m_dexterity + 1);

	float total = randStr + (randDxt / 2.0f) + (randInt / 3.0f);

	return (int)total;
}
