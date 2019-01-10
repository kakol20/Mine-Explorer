#ifndef ENEMYBASE_H
#define ENEMYBASE_H

#include "Tile.h"
#include "Orc.h"

//#include <stdlib.h>
//#include <time.h>

class EnemyBase : public Tile
{
public:
	EnemyBase(int x, int y);
	EnemyBase(const EnemyBase& copyEnemy);
	EnemyBase& operator=(const EnemyBase& copyEnemy);
	virtual ~EnemyBase();

	virtual void Activate(Player* player, int turns);

	//int getDamage();
	//int getEnemyType();

	int interact(int playerDamage);

private:

	Enemy * m_enemy;
};

#endif // !ENEMYBASE_H
