#ifndef ARCHER_H
#define ARCHER_H

#include "Player.h"

class Archer : public Player
{
public:
	Archer();
	virtual ~Archer();

	virtual int calculateDamage();

	virtual void displayStats();
};

#endif // !ARCHER_H

