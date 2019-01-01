//#ifndef MINE_H
//#define MINE_H
//
//#include "Tile.h"
//
//class Mine : public Tile
//{
//public:
//	Mine(int x, int y);
//	virtual ~Mine();
//
//	virtual void Activate();
//
//	void setValue(int value);
//	int getValue();
//
//	bool isDamaged();
//	void setDamage(bool damaged);
//
//private:
//	int m_value;
//	bool m_damaged;
//};
//#endif // !MINE_H

#ifndef EMPTY_H
#define EMPTY_H

#include "Tile.h"

class Empty : public Tile 
{
public:
	Empty(int x, int y);
	virtual ~Empty();

	virtual void Activate();

private:

};

#endif // !EMPTY_H

