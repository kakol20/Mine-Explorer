#define NOMINMAX

#include <windows.h>
#include <iostream>
//#include <algorithm>

#include <stdlib.h>

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

		std::cout << "Do you want to play again?\n"
			<< "0. Yes\n"
			<< "1. No\n";

		int option;
		std::cin >> option;

		while (std::cin.fail() || (option < 0 || option > 1))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nInvalid input\n";
			std::cout << "Do you want to play again?\n"
				<< "0. Yes\n"
				<< "1. No\n";

			std::cin >> option;
		}

		if (option == 1)
		{
			break;
		}
	}

	return 0;
}