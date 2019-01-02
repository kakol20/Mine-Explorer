#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init()
{
	std::cout << "What is your name? ";
	std::getline(std::cin, m_name);

	m_health = 100;

	// hard code stats for now
	m_strength = 10;
	m_intelligence = 10;
	m_dexterity = 10;

	m_position.x = width / 2;
	m_position.y = height / 2;
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
	std::cout << "Health       - " << m_health << "\n";
	std::cout << "Strength     - " << m_strength << "\n";
	std::cout << "Intelligence - " << m_intelligence << "\n";
	std::cout << "Dexterity    - " << m_dexterity << "\n";
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
