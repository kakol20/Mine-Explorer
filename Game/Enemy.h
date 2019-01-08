#ifndef ENEMY_H
#define ENEMY_H

#include "Base.h"

#include <stdlib.h>
#include <time.h>

class Enemy
{
public:
	Enemy();
	Enemy(const Enemy &copyEnemy);
	Enemy& operator=(const Enemy &copyEnemy);
	virtual ~Enemy();

	virtual void Init(int turnNumber);

	virtual int calculateDamage() = 0;

protected:
	
	int m_strength;
	int m_intelligence;
	int m_dexterity;
};
#endif // !ENEMY_H

