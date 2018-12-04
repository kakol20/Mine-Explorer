#include "Game.h"

Game::Game()
{
	srand((int)time(0));

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			
			grid[x][y] = nullptr;

		}
	}
}

Game::~Game()
{
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (grid[x][y] != nullptr) { 
				delete grid[x][y]; 
				grid[x][y] = nullptr;
			}
			
		}
	}
}

void Game::Init()
{
	std::cout << "Game initialized\n";

	for (int i = 0; i < maxMines; i++) {
		int randX = rand() % maxMines;
		int randY = rand() % maxMines;

		while (grid[randX][randY] != nullptr) {
			randX = rand() % maxMines;
			randY = rand() % maxMines;
		}

		grid[randX][randY] = new Mine(randX, randY);
	}
}

void Game::mainLoop()
{
	drawGrid();
}

void Game::drawGrid()
{
	for (int y = 0; y < height; y++) {
		for (int i = 0; i < width; i++) {
			std::cout << " ---";
		}
		std::cout << "\n";

		for (int x = 0; x < width; x++) {
			std::cout << "| ";
			if (grid[x][y] != nullptr) {

				if (dynamic_cast<Mine*>(grid[x][y])) {
					std::cout << "M ";
				}

			}
			else {
				std::cout << "  ";

			}
		}
		std::cout << "|\n";
	}

	for (int i = 0; i < width; i++) {
		std::cout << " ---";
	}
	std::cout << "\n";
}
