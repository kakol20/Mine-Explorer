#include "Mine.h"

Mine::Mine(int x, int y) : Tile(x, y)
{
	m_damaged = false;
	m_enemySpawned = false;
}

Mine::~Mine()
{
	if (m_attackingEnemy != nullptr)
	{
		delete m_attackingEnemy;
		m_attackingEnemy = nullptr;
	}
}

Mine::Mine(const Mine & copyMine) : Tile(copyMine)
{
	m_value = copyMine.m_value;
	m_damaged = copyMine.m_damaged;
	m_enemySpawned = copyMine.m_enemySpawned;
	
	m_attackingEnemy = copyMine.m_attackingEnemy;
}

Mine & Mine::operator=(const Mine & copyMine)
{
	if (this == &copyMine) return *this;

	m_damaged = copyMine.m_damaged;
	m_discovered = copyMine.m_discovered;
	m_position.x = copyMine.m_position.x;
	m_position.y = copyMine.m_position.y;
	m_value = copyMine.m_value;

	if (copyMine.m_attackingEnemy != nullptr)
	{
		if (m_attackingEnemy != nullptr)
		{
			delete m_attackingEnemy;
			m_attackingEnemy = nullptr;

			if (dynamic_cast<Orc*>(copyMine.m_attackingEnemy))
			{
				m_attackingEnemy = new Orc(*dynamic_cast<Orc*>(copyMine.m_attackingEnemy));
			}
			else if (dynamic_cast<Witch*>(copyMine.m_attackingEnemy))
			{
				m_attackingEnemy = new Witch(*dynamic_cast<Witch*>(copyMine.m_attackingEnemy));
			}
			else if (dynamic_cast<Goblin*>(copyMine.m_attackingEnemy))
			{
				m_attackingEnemy = new Goblin(*dynamic_cast<Goblin*>(copyMine.m_attackingEnemy));
			}
		}
	}

	return *this;
}

void Mine::Activate(Player* player, int turns)
{
	if (!m_discovered) 
	{
		m_damaged = false;
		// generate a random mine value between 1 to 2 - this will determine how much gold the player will gain from it
		int randVal = (rand() % 2) + 1;
		m_value = randVal;

		m_discovered = true;

		std::cout << "You have discovered a mine at (" << m_position.x << ", " << m_position.y << ")\n";
	}
}

void Mine::setValue(int value)
{
	m_value = value;
}

int Mine::getValue()
{
	return m_value;
}

bool Mine::isDamaged()
{
	return m_damaged;
}

bool Mine::isEnemySpawned()
{
	return m_enemySpawned;
}

void Mine::setDamage(bool damaged)
{
	m_damaged = damaged;
}

void Mine::spawnEnemy(int turns)
{
	int random = rand() % 3;

	//temp
	//random = 0;

	if (random == ORC)
	{
		m_attackingEnemy = new Orc();

		m_attackingEnemy->Init(turns);

		m_enemySpawned = true;
	}
	else if (random == WITCH)
	{
		m_attackingEnemy = new Witch();

		m_attackingEnemy->Init(turns);

		m_enemySpawned = true;
	}
	else if (random == GOBLIN)
	{
		m_attackingEnemy = new Goblin();

		m_attackingEnemy->Init(turns);

		m_enemySpawned = true;
	}
}

int Mine::interact(int playerDamage)
{
	int netDamage = 0;

	if (m_damaged)
	{
		if (m_enemySpawned)
		{
			// if an enemy spawned, player need to kill it to complete game
			int enemyDamage = m_attackingEnemy->calculateDamage();
			netDamage = playerDamage - enemyDamage;

			m_attackingEnemy->displayStats();

			int option;

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

				if (dynamic_cast<Orc*>(m_attackingEnemy))
				{
					std::cout << "Orc's";
				}
				else if (dynamic_cast<Witch*>(m_attackingEnemy))
				{
					std::cout << "Witch's";
				}
				else if (dynamic_cast<Goblin*>(m_attackingEnemy))
				{
					std::cout << "Goblin's";
				} // change output based on enemie's class

				std::cout << " damage is " << enemyDamage << "\n";

				if (netDamage > 0)
				{
					std::cout << "You won against the enemy!\nIt has been killed\n";
					m_enemySpawned = 0;

					delete m_attackingEnemy;
					m_attackingEnemy = nullptr;
				}
				else if (netDamage < 0)
				{
					std::cout << "You lost against the enemy!\nYou lose " << (-1 * netDamage) << " health\n";
				}
			}
		}
		else
		{
			int option;

			/*for (int i = 0; i < 30; i++)
			{
				std::cout << (char)205;
			}
			std::cout << "\n";*/

			std::cout << "Do you want to repair this mine?\n" << // player do not have to repair mine to win
				"0. Yes\n" <<
				"1. No\n";
			std::cin >> option;

			while (std::cin.fail() || (option < 0 || option > 1))
			{
				// loops infinitely if a letter is inputted if this is not done
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\nInvalid input\n";
				std::cout << "Do you want to repair this mine?\n" <<
					"0. Yes\n" <<
					"1. No\n";
				std::cin >> option;
			}

			if (option == 0)
			{
				m_damaged = false;
				netDamage = 0;
			}
		}
	}

	return netDamage;
}
