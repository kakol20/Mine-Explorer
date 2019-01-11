#include "Mage.h"

Mage::Mage()
{
}

Mage::~Mage()
{
}

int Mage::calculateDamage()
{
	float randStr = (float)(rand() % m_strength + 1);
	float randInt = (float)(rand() % m_intelligence + 1);
	float randDxt = (float)(rand() % m_dexterity + 1);

	float total = (randInt * 0.5f) + (randDxt * 0.33f) + (randStr * 0.17f); // unique way of calculating damage compared to other player classes
	//total = total / 3.0f;

	return (int)total;
}

void Mage::displayStats()
{
	float maxDamage = (m_intelligence * 0.5f) + (m_dexterity * 0.33f) + (m_strength * 0.17f);
	//maxDamage = maxDamage / 3;

	std::cout << "Class - Mage\n";
	std::cout << "Position         - x: " << m_position.x << " y: " << m_position.y << "\n";
	std::cout << "Gold             - " << m_gold << "\n";
	std::cout << "Health           - " << m_health << "\n";
	std::cout << "Strength         - " << m_strength << "\n";
	std::cout << "Intelligence     - " << m_intelligence << "\n";
	std::cout << "Dexterity        - " << m_dexterity << "\n";
	std::cout << "Possible Max Dmg - " << (int)maxDamage << "\n";
}
