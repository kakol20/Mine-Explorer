#ifndef BASE_H
#define BASE_H

struct Position 
{
	int x;
	int y;
};

enum DIRECTIONS { NORTH, EAST, SOUTH, WEST };

enum CLASSES { KNIGHT, MAGE, ARCHER };

enum ENEMYTYPE { ORC, WITCH, SKELETONARCHER };

enum OPTIONS { MOVE, NOTHING, QUIT, INTERACT };

enum TILE_TYPE { MINE, EMPTY };

const int height = 15;
const int width = 15;

const int maxEnemyBases = 5;
const int maxMines = 5;

#endif // !BASE_H
