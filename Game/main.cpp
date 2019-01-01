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

	system("pause");
	
	delete game;
	game = nullptr;


	return 0;
}