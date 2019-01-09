#ifndef ENEMY_H
#define ENEMY_H

#include "Base.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

class Enemy
{
public:
	Enemy();
	Enemy(const Enemy &copyEnemy);
	virtual Enemy& operator=(const Enemy &copyEnemy);
	virtual ~Enemy();

	virtual void Init(int turns);
	
	//virtual int getEnemyType();

	virtual int calculateDamage() = 0;

	virtual void displayStats();

	/*int getStrength();
	int getIntelligence();
	int get*/

protected:
	
	int m_strength;
	int m_intelligence;
	int m_dexterity;
};
#endif // !ENEMY_H

