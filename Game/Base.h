#ifndef BASE_H
#define BASE_H

struct Position 
{
	int x;
	int y;
};

enum DIRECTIONS { NORTH, EAST, SOUTH, WEST };

enum CLASSES { KNIGHT, MAGE, ARCHER };

enum OPTIONS { MOVE, QUIT };

const int height = 15;
const int width = 15;

#endif // !BASE_H
