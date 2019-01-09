#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(const Enemy & copyEnemy)
{
	m_dexterity = copyEnemy.m_dexterity;
	m_intelligence = copyEnemy.m_intelligence;
	m_strength = copyEnemy.m_strength;

}

Enemy & Enemy::operator=(const Enemy & copyEnemy)
{
	if (this == &copyEnemy) return *this;

	m_dexterity = copyEnemy.m_dexterity;
	m_intelligence = copyEnemy.m_intelligence;
	m_strength = copyEnemy.m_strength;

	return *this;
}

Enemy::~Enemy()
{
}

void Enemy::Init(int turns)
{
}

void Enemy::displayStats()
{
}
