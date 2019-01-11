#include "Goblin.h"

Goblin::Goblin()
{
}

Goblin::Goblin(const Goblin & copyGoblin) : Enemy(copyGoblin)
{

}

Goblin & Goblin::operator=(const Goblin & copyGoblin)
{
	if (this == &copyGoblin) return *this;

	m_dexterity = copyGoblin.m_dexterity;
	m_intelligence = copyGoblin.m_intelligence;
	m_strength = copyGoblin.m_strength;

	return *this;
}

Goblin::~Goblin()
{
}

void Goblin::Init(int turns)
{
	m_dexterity = rand() % 5 + (10 + (turns / 10));
	m_strength = rand() % 5 + (5 + (turns / 10));
	m_intelligence = rand() % 3 + (3 + (turns / 10));
}

int Goblin::calculateDamage()
{
	int randStr = (rand() % m_strength + 1);
	int randInt = (rand() % m_intelligence + 1);
	int randDxt = (rand() % m_dexterity + 1);

	//float total = randStr + (randDxt / 2.0f) + (randInt / 3.0f);
	float total = (randDxt * 0.5f) + (randStr * 0.33f) + (randInt * 0.17f); // unique way to calculate damage compared to other enemy classes

	return (int)total;
}

void Goblin::displayStats()
{
	float possibleDamage = (m_dexterity * 0.5f) + (m_strength * 0.33f) + (m_intelligence * 0.17f);
	//possibleDamage = possibleDamage / 3.0f;

	std::cout << "Mage -\n" <<
		"Strength         - " << m_strength << "\n" <<
		"Intelligence     - " << m_intelligence << "\n" <<
		"Dexterity        - " << m_dexterity << "\n" <<
		"Possible Max Dmg - " << (int)possibleDamage << "\n";
}
