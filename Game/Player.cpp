#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

Player::Player(const Player & copyPlayer)
{
	m_position.x = copyPlayer.m_position.x;
	m_position.y = copyPlayer.m_position.y;

	m_name = copyPlayer.m_name;

	m_health = copyPlayer.m_health;
	m_strength = copyPlayer.m_strength;
	m_intelligence = copyPlayer.m_intelligence;
	m_dexterity = copyPlayer.m_dexterity;
}

Player & Player::operator=(const Player & copyPlayer)
{
	if (this == &copyPlayer) return *this;

	m_position.x = copyPlayer.m_position.x;
	m_position.y = copyPlayer.m_position.y;

	m_name = copyPlayer.m_name;

	m_health = copyPlayer.m_health;
	m_strength = copyPlayer.m_strength;
	m_intelligence = copyPlayer.m_intelligence;
	m_dexterity = copyPlayer.m_dexterity;

	return *this;
}

void Player::Init()
{
	std::cout << "What is your name? ";
	std::getline(std::cin, m_name);

	m_health = 100;

	// hard code stats for now
	// TODO: Customisable stats based on the class they chose
	m_strength = 5;
	m_intelligence = 5;
	m_dexterity = 5;

	displayStats();

	m_position.x = width / 2;
	m_position.y = height / 2;

	m_gold = 0;

	customiseStats(20);
}

void Player::Move(char direction)
{
	/*std::cout << "Choose a direction\n0 - North\n1 - East\n2 - South\n3 - West\n";
	int chosen;
	std::cin >> chosen;*/

	switch (direction) {
		case 'n':
			if (m_position.y > 0) {
				m_position.y--;
			}
			break;

		case 'e':
			if (m_position.x < width - 1) {
				m_position.x++;
			}
			break;

		case 's':
			if (m_position.y < height - 1) {
				m_position.y++;
			}
			break;

		case 'w':
			if (m_position.x > 0) {
				m_position.x--;
			}
			break;
	}
	

	//return 0;
}

void Player::displayStats()
{
	std::cout << "Position     - x: " << m_position.x << " y: " << m_position.y << "\n";
	std::cout << "Gold         - " << m_gold << "\n";
	std::cout << "Health       - " << m_health << "\n";
	std::cout << "Strength     - " << m_strength << "\n";
	std::cout << "Intelligence - " << m_intelligence << "\n";
	std::cout << "Dexterity    - " << m_dexterity << "\n";
}

void Player::addGold(int add)
{
	m_gold += add;
}

void Player::removeGold(int remove)
{
	m_gold -= remove;
}

void Player::changeHealth(int delta)
{
	m_health += delta;
}

int Player::getGold()
{
	return m_gold;
}

void Player::changeStat(int itemID, int value)
{
	if (itemID >= S_STR && itemID <= L_STR)
	{
		m_strength += value;
	}
	else if (itemID >= S_INT && itemID <= L_INT)
	{
		m_intelligence += value;
	}
	else if (itemID >= S_DXT && itemID <= L_DXT)
	{
		m_dexterity += value;
	}
	else if (itemID >= S_HLTH && itemID <= L_HLTH)
	{
		m_health += value;
	}
}

void Player::customiseStats(int availablePoints)
{
	int option;

	system("cls");

	displayStats();

	std::cout << "\nChoose a stat to customise:\n" <<
		"0. Strength\n" <<
		"1. Intelligence\n" <<
		"2. Dexterity\n";

	std::cin >> option;

	while (std::cin.fail() || (option < 0 || option > 2))
	{
		// loops infinitely if a letter is inputted if this is not done
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nInvalid input\n";
		std::cout << "Choose a stat to customise:\n" <<
			"0. Strength\n" <<
			"1. Intelligence\n" <<
			"2. Dexterity\n";

		std::cin >> option;
	}

	int toSpend;
	std::cout << "Chosen: ";
	switch (option)
	{
	case 0:
		std::cout << "Strength\n";
		break;

	case 1:
		std::cout << "Intelligence\n";
		break;

	case 2:
		std::cout << "Dexterity\n";
		break;

	default:
		break;
	}

	std::cout << "\nHow many points do you want to spend? max: " << availablePoints << "\n";
	std::cin >> toSpend;

	while (std::cin.fail() || (toSpend < 0 || toSpend > availablePoints))
	{
		// loops infinitely if a letter is inputted if this is not done
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nInvalid input\n";
		std::cout << "\nHow many points do you want to spend? max: " << availablePoints << "\n";
		std::cin >> toSpend;

	}
	
	int pointsLeft = availablePoints;

	if (option == 0)
	{
		m_strength += toSpend;

		pointsLeft -= toSpend;
	}
	else if (option == 1)
	{
		m_intelligence += toSpend;
		pointsLeft -= toSpend;
	}
	else if (option == 2)
	{
		m_dexterity += toSpend;

		pointsLeft -= toSpend;
	}

	if (pointsLeft > 0)
	{
		customiseStats(pointsLeft);
	}
}

Position Player::getPosition()
{
	return m_position;
}

bool Player::checkInput(char directions[]) // check for valid input
{
	//char d[] = direction;

	int length = (int)strlen(directions);

	for (int i = 0; i < length; i++) 
	{
		if (directions[i] != 'n' && directions[i] != 'e' && directions[i] != 's' && directions[i] != 'w')
		{
			return false;
		}
	}

	return true;
}
