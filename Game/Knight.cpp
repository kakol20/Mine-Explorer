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

void Knight::displayStats()
{
	int maxDamage = m_strength + (m_dexterity / 2) + (m_intelligence / 3);

	std::cout << "Position         - x: " << m_position.x << " y: " << m_position.y << "\n";
	std::cout << "Gold             - " << m_gold << "\n";
	std::cout << "Health           - " << m_health << "\n";
	std::cout << "Strength         - " << m_strength << "\n";
	std::cout << "Intelligence     - " << m_intelligence << "\n";
	std::cout << "Dexterity        - " << m_dexterity << "\n";
	std::cout << "Possible Max Dmg - " << maxDamage << "\n";
}
