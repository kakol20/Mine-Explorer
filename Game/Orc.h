#ifndef ORC_H
#define ORC_H

#include "Enemy.h"

class Orc : public Enemy
{
public:
	Orc();
	Orc(const Orc &copyOrc);
	virtual Orc& operator=(const Orc &copyOrc);
	virtual ~Orc();

	virtual void Init(int turns);

	//virtual int getEnemyType();

	virtual int calculateDamage();

	virtual void displayStats();

private:

};

#endif // !ORC_H
