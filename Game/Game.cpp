#include "Game.h"

Game::Game()
{
	srand(time(0));

}

Game::~Game()
{
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (grid[x][y]) delete grid[x][y];
			grid[x][y] = nullptr;
		}
	}
}

void Game::Init()
{
	std::cout << "Game initialized\n";

	for (int i = 0; i < maxEnemyBases; i++) {
		int randX = rand() % maxEnemyBases;
		int randY = rand() % maxEnemyBases;

		while (grid[randX][randY]) {
			randX = rand() % maxEnemyBases;
			randY = rand() % maxEnemyBases;
		}

		grid[randX][randY] = new Mine(randX, randY);
	}
}
