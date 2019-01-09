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

void EnemyBase::Activate(Player* player, int turns)
{
	if (!m_discovered)
	{
		int chosen = rand() % 3;


		chosen = ORC; // temporary

		if (chosen == ORC)
		{
			enemy = new Orc();
			enemy->Init(turns);
		}

		m_discovered = true;
		std::cout << "You have discovered an enemy base at ( " << m_position.x << ", " << m_position.y << ")\n";
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

int EnemyBase::interact(int playerDamage)
{
	int enemyDamage = enemy->calculateDamage();

	// player must get damage value higher than enemy's damage
	// if player gets lower, the damage done to their health is the difference
	int netDamageToPlayer = playerDamage - enemyDamage;

	enemy->displayStats();

	int option;

	for (int i = 0; i < 30; i++)
	{
		std::cout << (char)205;
	}
	std::cout << "\n";

	std::cout << "Choose an option -\n"
		<< "0. Attack\n"
		<< "1. Nothing\n";
	std::cin >> option;

	while (std::cin.fail() || (option < 0 || option > 1))
	{
		// loops infinitely if a letter is inputted if this is not done
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nInvalid input\n";
		std::cout << "Choose an option -\n"
			<< "0. Attack\n"
			<< "1. Nothing\n";
		std::cin >> option;
	}

	
	if (option == 0)
	{
		std::cout << "Your damage is " << playerDamage << " and the  ";

		if (dynamic_cast<Orc*>(enemy))
		{
			std::cout << "Orc's";
		}

		std::cout << " damage is " << enemyDamage << "\n";

		if (netDamageToPlayer > 0)
		{
			std::cout << "You won against the enemy!\nIt has disappered from the map\n";
		}
		else if (netDamageToPlayer < 0)
		{
			std::cout << "You lost against the enemy!\nYou lose " << (-1 * netDamageToPlayer) << " health\n";
		}
	}
	else if (option == 1)
	{
		netDamageToPlayer = 0;
	}

	return netDamageToPlayer;
}
