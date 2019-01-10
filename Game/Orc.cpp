#include "Orc.h"

Orc::Orc() : Enemy()
{
}

Orc::Orc(const Orc & copyOrc)
{
}

Orc & Orc::operator=(const Orc & copyOrc)
{
	if (this == &copyOrc) return *this;

	m_dexterity = copyOrc.m_dexterity;
	m_intelligence = copyOrc.m_intelligence;
	m_strength = copyOrc.m_strength;

	return *this;
}

Orc::~Orc()
{
}

void Orc::Init(int turns)
{

	m_strength = rand() % 5 + (10 + (turns / 7));
	m_dexterity = rand() % 5 + (5 + (turns / 7));
	m_intelligence = rand() % 3 + (3 + (turns / 7));
}

int Orc::calculateDamage()
{
	int randStr = (rand() % m_strength + 1);
	int randInt = (rand() % m_intelligence + 1);
	int randDxt = (rand() % m_dexterity + 1);

	//float total = randStr + (randDxt / 2.0f) + (randInt / 3.0f);
	float total = (randStr * 0.5f) + (randDxt * 0.33f) + (randInt * 0.17f);

	return (int)total;
	//return 0;
}

void Orc::displayStats()
{
	float possibleDamage = (m_strength * 0.5f) + (m_dexterity * 0.33f) + (m_intelligence * 0.17f);
	//possibleDamage = possibleDamage / 3.0f;

	std::cout << "Orc -\n" <<
		"Strength         - " << m_strength << "\n" <<
		"Intelligence     - " << m_intelligence << "\n" <<
		"Dexterity        - " << m_dexterity << "\n" <<
		"Possible Max Dmg - " << (int)possibleDamage << "\n";
}
