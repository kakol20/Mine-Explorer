#ifndef ORC_H
#define ORC_H

#include "Enemy.h"

class Orc : public Enemy
{
public:
	Orc();
	Orc(const Orc &copyOrc);
	Orc& operator=(const Orc &copyOrc);
	virtual ~Orc();

	virtual void Init(int turnNumber);

	virtual int calculateDamage();

private:

};

#endif // !ORC_H
