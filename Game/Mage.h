#ifndef MAGE_H
#define MAGE_H

#include "Player.h"

class Mage : public Player
{
public:

	Mage();
	virtual ~Mage();

	virtual int calculateDamage();

	virtual void displayStats();
};
#endif // !MAGE_H
