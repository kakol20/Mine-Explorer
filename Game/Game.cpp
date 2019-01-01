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

	if (test != nullptr) {
		delete test;
		test = nullptr;
	}
}

void Game::Init()
{
	std::cout << "Game initialized\n";

	test = new Knight();
	test->Init();

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (grid[x][y] == nullptr) {
				grid[x][y] = new Empty(x, y);
			}
		}
	}

	Position pos = test->getPosition();
	grid[pos.x][pos.y]->setDiscovered(true);

	for (int i = 0; i < maxMines; i++) {
		int randX = rand() % width;
		int randY = rand() % height;

		while (!dynamic_cast<Empty*>(grid[randX][randY]) || (randX == test->getPosition().x && randY == test->getPosition().y)) {
			randX = rand() % width;
			randY = rand() % height;
		}

		delete grid[randX][randY];
		//grid[randX][randY] = nullptr;
		grid[randX][randY] = new Mine(randX, randY);	
	}
	
	//grid[test->getPosition().x][test->getPosition().y]->discover();
	//grid[test->getPosition().x][test->getPosition().y]->discover();

}

void Game::mainLoop()
{
	system("cls");

	test->Move();

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
			//if (grid[x][y] != nullptr) {

			//	//if (grid[x][y].)

			//	

			//}
			//else {
			//	//std::cout << (char)219 << "\n";

			//	std::cout << (char)219 << " ";

			//}

			if (grid[x][y]->isDiscovered()) {
				if (x == test->getPosition().x && y == test->getPosition().y) {
					std::cout << "P ";
				}
				else if (dynamic_cast<Mine*>(grid[x][y])) {
					std::cout << "M ";
				}
				else {
					std::cout << "  ";
				}

				/*if (dynamic_cast<Mine*>(grid[x][y])) {
					std::cout << "M ";
				}*/
			}
			else {
				std::cout << (char)219 << " ";

			}
		}
		std::cout << "|\n";
	}

	for (int i = 0; i < width; i++) {
		std::cout << " ---";
	}
	std::cout << "\n";
}
