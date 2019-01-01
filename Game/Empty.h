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

