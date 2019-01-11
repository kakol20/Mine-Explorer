#ifndef GOBLIN_H
#define GOBLIN_H

#include "Enemy.h"

class Goblin : public Enemy
{
public:
	Goblin();
	Goblin(const Goblin &copyGoblin);
	virtual Goblin& operator=(const Goblin &copyGoblin);
	virtual ~Goblin();

	virtual void Init(int turns);

	//virtual int getEnemyType();

	virtual int calculateDamage();

	virtual void displayStats();

};

#endif // !GOBLIN_H
