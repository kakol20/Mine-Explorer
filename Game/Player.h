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

	Player(const Player& copyPlayer);
	Player& operator=(const Player& copyPlayer);

	virtual int calculateDamage() = 0;

	//virtual void Attack() = 0;

	void Init();
	void Move(char direction);
	void displayStats();
	void addGold(int add);
	void removeGold(int remove);

	Position getPosition();

	bool checkInput(char directions[]);

protected:
	Position m_position;

	std::string m_name;

	int m_health;
	int m_strength;
	int m_intelligence;
	int m_dexterity;

	int m_gold;
};

#endif // !PLAYER_H
