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

	if (copyEnemy.enemy != nullptr)
	{
		if (enemy != nullptr)
		{
			//if ()

			delete enemy;
			enemy = nullptr;
			
			if (dynamic_cast<Orc*>(copyEnemy.enemy))
			{
				enemy = new Orc();

				enemy = copyEnemy.enemy;
			}
		}
	}

	

	return *this;
}

EnemyBase::~EnemyBase()
{
	if (enemy != nullptr)
	{
		//if ()

		delete enemy;
		enemy = nullptr;
	}
}

void EnemyBase::Activate()
{
	if (!m_discovered)
	{
		int chosen = rand() % 3;


		chosen = ORC; // temporary

		if (chosen == ORC)
		{
			enemy = new Orc();
			enemy->Init();
		}

		m_discovered = true;
		std::cout << "You have discovered an enemy base!\n";
	}
}

int EnemyBase::getDamage()
{
	return enemy->calculateDamage();
}

int EnemyBase::getEnemyType()
{
	if (dynamic_cast<Orc*>(enemy))
	{
		return ORC;
	}
}

void EnemyBase::interact(int playerDamage)
{
	enemy->displayStats();
}
