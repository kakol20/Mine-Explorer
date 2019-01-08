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

void Orc::Init(int turnNumber)
{
	/*TODO:
		1. Randomly generate stats
		2. Orc will have bias towards strength
	*/
}

int Orc::calculateDamage()
{
	/*TODO:
		1. Calculate damage based on their stats
	
	*/
	return 0;
}
