//#ifndef MINE_H
//#define MINE_H
//
//#include "Tile.h"
//
//class Mine : public Tile
//{
//public:
//	Mine(int x, int y);
//	//Mine(const )
//	virtual ~Mine();
//
//	Mine(const Mine& copyMine);
//	Mine& operator=(const Mine& copyMine);
//
//	virtual void Activate();
//
//	void setValue(int value);
//	int getValue();
//
//	bool isDamaged();
//	void setDamage(bool damaged);
//
//private:
//	int m_value;
//	bool m_damaged;
//};
//#endif // !MINE_H

#ifndef ENEMY_H
#define ENEMY_H

#include "Tile.h"

class EnemyBase : public Tile
{
public:
	EnemyBase(int x, int y);
	EnemyBase(const EnemyBase& copyEnemy);
	EnemyBase& operator=(const EnemyBase& copyEnemy);
	virtual ~EnemyBase();

	virtual void Activate();

private:

};

#endif // !ENEMY_H
