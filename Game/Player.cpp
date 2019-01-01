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

	m_position.x = 0;
	m_position.y = 0;
}

void Player::Move()
{
	std::cout << "Choose a direction\n0 - North\n1 - East\n2 - South\n3 - West\n";
	int chosen;
	std::cin >> chosen;

	switch (chosen) {
		case NORTH:
			if (m_position.y > 0) {
				m_position.y--;
			}
			break;

		case EAST:
			if (m_position.x < width) {
				m_position.x++;
			}
			break;

		case SOUTH:
			if (m_position.y < height) {
				m_position.y++;
			}
			break;

		case WEST:
			if (m_position.x > 0) {
				m_position.x--;
			}
			break;
	}
	

	//return 0;
}

Position Player::getPosition()
{
	return m_position;
}
