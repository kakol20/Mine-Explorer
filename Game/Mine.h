#ifndef MINE_H
#define MINE_H

#include "Tile.h"
#include "Orc.h"

class Mine : public Tile 
{
public:
	Mine(int x, int y);
	//Mine(const )
	virtual ~Mine();

	Mine(const Mine& copyMine);
	virtual Mine& operator=(const Mine& copyMine);

	virtual void Activate(Player* player, int turns);

	void setValue(int value);
	int getValue();

	bool isDamaged();
	bool isEnemySpawned();
	void setDamage(bool damaged);

	void spawnEnemy();

	int interact(int playerDamage);

private:
	int m_value;
	bool m_damaged;

	bool m_enemySpawned;

	Enemy* m_attackingEnemy;
};
#endif // !MINE_H
