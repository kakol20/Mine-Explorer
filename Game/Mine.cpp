#include "Mine.h"

Mine::Mine(int x, int y) : Tile(x, y)
{
	m_damaged = false;
}

Mine::~Mine()
{
}

Mine::Mine(const Mine & copyMine) : Tile(copyMine)
{
	m_value = copyMine.m_value;
	m_damaged = copyMine.m_damaged;
}

Mine & Mine::operator=(const Mine & copyMine)
{
	if (this == &copyMine) return *this;

	m_damaged = copyMine.m_damaged;
	m_discovered = copyMine.m_discovered;
	m_position.x = copyMine.m_position.x;
	m_position.y = copyMine.m_position.y;
	m_value = copyMine.m_value;

	return *this;
}

void Mine::Activate()
{
	if (!m_discovered) {
		// generate a random mine value between 1 to 5 - this will determine how much gold the player will gain from it
		int randVal = (rand() % 5) + 1;
		m_value = randVal;

		m_discovered = true;

		std::cout << "You have discovered a mine!\n";
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
