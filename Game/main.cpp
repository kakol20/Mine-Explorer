#include <iostream>
#include <windows.h>

#include "Game.h"


int main() 
{
	SetConsoleCP(437);
	SetConsoleOutputCP(437);

	Game* game = new Game;

	game->Init();

	game->mainLoop();

	delete game;
	game = nullptr;

	system("pause");

	return 0;
}