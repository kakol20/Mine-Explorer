#include <iostream>
#include "Game.h"


int main() 
{
	Game* game = new Game;

	game->Init();
	game->mainLoop();

	delete game;
	game = nullptr;

	system("pause");

	return 0;
}