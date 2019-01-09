#ifndef KNIGHT_H
#define KNIGHT_H

#include "Player.h"

class Knight : public Player
{
public:
	Knight();
	virtual ~Knight();

	virtual int calculateDamage();

	virtual void displayStats();
	//virtual void Attack();

private:

};

#endif // !KNIGHT_H

