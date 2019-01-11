#ifndef WITCH_H
#define WITCH_H

#include "Enemy.h"

class Witch : public Enemy
{
public:
	Witch();
	Witch(const Witch &copyWitch);
	virtual Witch& operator=(const Witch &copyWitch);
	virtual ~Witch();

	virtual void Init(int turns);

	//virtual int getEnemyType();

	virtual int calculateDamage();

	virtual void displayStats();
	
};

#endif // !WITCH_H
