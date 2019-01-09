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

	return *this;
}

Orc::~Orc()
{
}

void Orc::Init(int turns)
{

	m_strength = rand() % 5 + (10 + (turns / 10));
	m_dexterity = rand() % 5 + (5 + (turns / 10));
	m_intelligence = rand() % 3 + (3 + (turns / 10));
}

int Orc::calculateDamage()
{
	int randStr = (rand() % m_strength + 1);
	int randInt = (rand() % m_intelligence + 1);
	int randDxt = (rand() % m_dexterity + 1);

	float total = randStr + (randDxt / 2.0f) + (randInt / 3.0f);

	return (int)total;
	//return 0;
}

void Orc::displayStats()
{
	float possibleDamage = m_strength + (m_dexterity / 2.0f) + (m_intelligence / 3.0f);

	std::cout << "Orc -\n" <<
		"Strength         - " << m_strength << "\n" <<
		"Intelligence     - " << m_intelligence << "\n" <<
		"Dexterity        - " << m_dexterity << "\n" <<
		"Possible Max Dmg - " << (int)possibleDamage << "\n";
}
