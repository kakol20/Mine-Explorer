#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "Base.h"

#include <stdlib.h>
#include <time.h>

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
	virtual void displayStats();
	void addGold(int add);
	void removeGold(int remove);
	void changeHealth(int delta);

	int getGold();
	int getHealth();

	void changeStat(int itemID, int value);

	void customiseStats(int availablePoints);

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
