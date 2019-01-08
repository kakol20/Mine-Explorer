#ifndef ENEMYBASE_H
#define ENEMYBASE_H

#include "Tile.h"
#include "Orc.h"

class EnemyBase : public Tile
{
public:
	EnemyBase(int x, int y);
	EnemyBase(const EnemyBase& copyEnemy);
	EnemyBase& operator=(const EnemyBase& copyEnemy);
	virtual ~EnemyBase();

	virtual void Activate();

private:

	Enemy * enemy;
};

#endif // !ENEMYBASE_H
