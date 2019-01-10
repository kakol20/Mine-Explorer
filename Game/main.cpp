#include <iostream>
#include <windows.h>

#include "Game.h"

int main() 
{
	SetConsoleCP(437);
	SetConsoleOutputCP(437);


	while (true)
	{
		Game* game = new Game;

		game->Init();

		while (game->mainLoop());

		system("pause");

		delete game;
		game = nullptr;


	}

	return 0;
}