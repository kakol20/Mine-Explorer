#ifndef BASE_H
#define BASE_H

struct Position 
{
	int x;
	int y;
};

enum DIRECTIONS { NORTH, EAST, SOUTH, WEST };

enum CLASSES { KNIGHT, MAGE, ARCHER };

enum ENEMYTYPE { ORC, WITCH, GOBLIN};

enum OPTIONS { MOVE, NOTHING, QUIT, INTERACT };

enum TILE_TYPE { MINE, EMPTY, BASE, SHOP };

enum POTIONS { S_STR, M_STR, L_STR, S_INT, M_INT, L_INT, S_DXT, M_DXT, L_DXT, S_HLTH, M_HLTH, L_HLTH };

const int height = 15;
const int width = 15;

const int maxEnemyBases = 5;
const int maxMines = 5;
const int maxShops = 10;

#endif // !BASE_H
