#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "Base.h"

class Player 
{
public:
	Player();
	virtual ~Player();

	virtual void Attack() = 0;

	void Init();
	void Move();
	void displayStats();

	Position getPosition();

protected:
	Position m_position;

	std::string m_name;

	int m_health;
	int m_strength;
	int m_intelligence;
	int m_dexterity;
};

#endif // !PLAYER_H
