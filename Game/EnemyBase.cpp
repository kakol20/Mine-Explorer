#include "EnemyBase.h"

EnemyBase::EnemyBase(int x, int y) : Tile(x, y)
{
}

EnemyBase::EnemyBase(const EnemyBase & copyEnemy) : Tile(copyEnemy)
{
}

EnemyBase & EnemyBase::operator=(const EnemyBase & copyEnemy)
{
	if (this == &copyEnemy) return *this;

	m_discovered = copyEnemy.m_discovered;
	m_position.x = copyEnemy.m_position.x;
	m_position.y = copyEnemy.m_position.y;

	return *this;
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::Activate()
{
	if (!m_discovered)
	{
		// TODO: Generate random enemy

		m_discovered = true;
		std::cout << "You have discovered an enemy base!\n";
	}
}
