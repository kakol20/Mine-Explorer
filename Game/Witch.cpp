#include "Witch.h"

Witch::Witch()
{
}

Witch::Witch(const Witch & copyWitch) : Enemy(copyWitch)
{
}

Witch & Witch::operator=(const Witch & copyWitch)
{
	if (this == &copyWitch) return *this;

	m_dexterity = copyWitch.m_dexterity;
	m_intelligence = copyWitch.m_intelligence;
	m_strength = copyWitch.m_strength;

	return *this;
}

Witch::~Witch()
{
}

void Witch::Init(int turns)
{
	m_intelligence = rand() % 5 + (10 + (turns / 7));
	m_dexterity = rand() % 5 + (5 + (turns / 7));
	m_strength = rand() % 3 + (3 + (turns / 7));
}

int Witch::calculateDamage()
{
	int randStr = (rand() % m_strength + 1);
	int randInt = (rand() % m_intelligence + 1);
	int randDxt = (rand() % m_dexterity + 1);

	//float total = randStr + (randDxt / 2.0f) + (randInt / 3.0f);
	float total = (randInt * 0.5f) + (randDxt * 0.33f) + (randStr * 0.17f);

	return (int)total;
}

void Witch::displayStats()
{
	float possibleDamage = (m_intelligence * 0.5f) + (m_dexterity * 0.33f) + (m_strength * 0.17f);
	//possibleDamage = possibleDamage / 3.0f;

	std::cout << "Witch -\n" <<
		"Strength         - " << m_strength << "\n" <<
		"Intelligence     - " << m_intelligence << "\n" <<
		"Dexterity        - " << m_dexterity << "\n" <<
		"Possible Max Dmg - " << (int)possibleDamage << "\n";
}
