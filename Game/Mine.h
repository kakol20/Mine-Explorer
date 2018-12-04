#ifndef MINE_H
#define MINE_H

#include "Tile.h"

class Mine : public Tile 
{
public:
	Mine(int x, int y);
	virtual ~Mine();

	virtual void Activate();

private:
};
#endif // !MINE_H
