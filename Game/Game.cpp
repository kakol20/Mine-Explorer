#include "Game.h"

Game::Game()
{
	srand((int)time(0));

	map = new Map();
}

Game::~Game()
{
	if (map != nullptr)
	{
		delete map;
		map = nullptr;
	}

	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}
}

void Game::Init()
{
	std::cout << "Game initialized\n";

	// Temporary until all classes added (if have time)
	player = new Knight();
	player->Init();

	map->init(player->getPosition());
	
	//grid[test->getPosition().x][test->getPosition().y]->discover();
	//grid[test->getPosition().x][test->getPosition().y]->discover();

	m_turns = 0;

}

bool Game::mainLoop()
{
	system("cls");

	bool loop = true;

	// ---------- DRAW MAIN MAP AND MINIMAP ----------

	map->draw(player->getPosition() );

	//std::cout << "---------------\n";
	// https://en.wikipedia.org/wiki/Code_page_437#Character_set
	for (int i = 0; i < 37; i++)
	{
		std::cout << (char)205;
	}
	std::cout << (char)188;

	std::cout << "\n";

	// ---------- OUTPUT PLAYER STATS ----------
	std::cout << "Turn " << m_turns << "\n";

	player->displayStats();

	int option = 10000;

	for (int i = 0; i < 30; i++)
	{
		std::cout << (char)205;
	}
	std::cout << "\n";

	// ---------- OUTPUT INTERFACE ----------
	/*std::cout << "Choose an option:\n" <<
		"0: Move\n" <<
		"1: Quit\n";
	std::cin >> option;*/

	std::cout << "Choose an option:\n" <<
		"0: Move\n" <<
		"1: Nothing\n"
		"2: Quit\n";

	/*if (dynamic_cast<Mine*>(grid[player->getPosition().x][pla]))*/
	if (map->isOnTileType(player))
	{
		std::cout << "3: Interact with tile\n";
	}
	std::cin >> option;

	// error trapping
	while (std::cin.fail() || (option != MOVE && option != QUIT && option != NOTHING && option != INTERACT)	)
	{
		// loops infinitely if a letter is inputted if this is not done
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nInvalid input\n";
		std::cout << "Choose an option:\n" <<
			"0: Move\n" <<
			"1: Nothing\n"
			"2: Quit\n";
		if (map->isOnTileType(player))
		{
			std::cout << "3: Interact with tile\n";
		}

		std::cin >> option;
	}

	for (int i = 0; i < 30; i++)
	{
		std::cout << (char)205;
	}
	std::cout << "\n";

	if (option == MOVE)
	{
		// player can input 100 directions
		char directions[100];

		do
		{
			std::cout << "Choose direction to move\n 'n' for north, 'e' for east, 's' for south & 'w' for west\n";
			std::cin >> directions;
		} while (!player->checkInput(directions));

		for (int i = 0; i < (int)strlen(directions); i++) {
			// what to type to reveal map : nnnnnneeeeeesssssssssssswwwwwwwwwwwwnnnnnnnnnnnneeessssssssseeeeeennnnnn
			player->Move(directions[i]);

			map->revealNear(player->getPosition().x, player->getPosition().y);

			// each movement will take one turn
			nextTurn();

			//system("pause");
		}
		system("pause");
	}
	else if (option == QUIT)
	{
		loop = false;
	}
	else if (option == NOTHING)
	{
		nextTurn();
	}
	else if (option == INTERACT)
	{
		map->interact(player);
	}
	/*else 
	{
		std::cout << "Invalid input\n";
		mainLoop();
	}*/
	
	return loop;
}

void Game::nextTurn()
{
	map->nextTurn(player);

	m_turns++;
}
