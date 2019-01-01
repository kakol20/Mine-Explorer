#include "Mine.h"

Mine::Mine(int x, int y) : Tile(x, y)
{
	m_damaged = false;
}

Mine::~Mine()
{
}

void Mine::Activate()
{
	if (!m_discovered) {
		// generate a random mine value between 5 to 10
		int randVal = (rand() % 6) + 5;
		m_value = randVal;

		m_discovered = true;
	}
}

void Mine::setValue(int value)
{
	m_value = value;
}

int Mine::getValue()
{
	return m_value;
}

bool Mine::isDamaged()
{
	return m_damaged;
}

void Mine::setDamage(bool damaged)
{
	m_damaged = damaged;
}
