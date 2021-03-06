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

	std::cout << "Choose a class you want to play as:\n"
		<< "0. Knight (strength build)\n"
		<< "1. Mage (intelligence build)\n"
		<< "2. Archer (dexterity build)\n";
	int option;
	std::cin >> option;

	while (std::cin.fail() || (option < KNIGHT || option > ARCHER)) // prevents letters from being inputted
	{
		
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nInvalid input\n";
		std::cout << "Choose a class you want to play as:\n"
			<< "0. Knight (strength build)\n"
			<< "1. Mage (intelligence build)\n"
			<< "2. Archer (dexterity build)\n";
		int option;
		std::cin >> option;

		//std::cout 
		std::cin >> option;
	}

	// assigns player class based on chosen class
	if (option == KNIGHT)
	{
		player = new Knight();
	}
	else if (option == ARCHER)
	{
		player = new Archer();
	}
	else if (option == MAGE)
	{
		player = new Mage();
	}
	player->Init();

	system("cls");

	// ---------- GAME INTRODUCTION ----------

	std::cout << "Welcome to Mine Kingdom!\n"
		<< "You are an adventurer.\n"
		<< "Your home kingdom's king wants to expand the kingdom.\n"
		<< "So you have been hired to explore the surrounding area and eliminate\n"
		<< " any enemies that you find as quickly as possible\n\n"
		<< "Quest -\n"
		<< "1. Eliminate all enemies (including ones occupying a mine)\n"
		<< "2. Discover everything\n";

	system("pause");

	map->init(player, m_turns);

	m_turns = 0;

}

bool Game::mainLoop()
{
	system("cls");

	bool loop = true;

	if (player->getHealth() <= 0)
	{
		system("cls");
		std::cout << "Game Over! You died!\n";
		loop = false;
	}
	else if (map->isComplete()) // check for quest complete
	{
		system("cls");
		std::cout << "Congratulations! You won!\n"
			<< "You completed in " << m_turns << " turns\n";
		loop = false;
	}
	else
	{
		// ---------- DRAW MAIN MAP AND MINIMAP ----------

		map->draw(player->getPosition());

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

		std::cout << "Choose an option:\n" <<
			"0: Move\n" <<
			"1: Nothing\n" <<
			"2: Quit\n";
		if (map->isOnTileType(player))
		{
			std::cout << "3: Interact with tile\n";
		}
		std::cin >> option;

		// error trapping

		if (map->isOnTileType(player))
		{
			while (std::cin.fail() || (option < MOVE || option > INTERACT))
			{
				// loops infinitely if a letter is inputted if this is not done
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\nInvalid input\n";
				std::cout << "Choose an option:\n" <<
					"0: Move\n" <<
					"1: Nothing\n" <<
					"2: Quit\n" <<
					"3: Interact with tile\n";

				//std::cout 
				std::cin >> option;
			}
			// interact option should only appear if they are on a tile they can interact with
		}
		else
		{
			while (std::cin.fail() || (option < MOVE || option > QUIT))
			{
				// loops infinitely if a letter is inputted if this is not done
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\nInvalid input\n";
				std::cout << "Choose an option:\n" <<
					"0: Move\n" <<
					"1: Nothing\n" <<
					"2: Quit\n";

				std::cin >> option;
			}
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
				std::cout << "Tip: you can type multiple directions to move more than once\n";
				std::cin >> directions;
			} while (!player->checkInput(directions));

			for (int i = 0; i < (int)strlen(directions); i++) {
				// what to type to reveal map : nnnnnneeeeeesssssssssssswwwwwwwwwwwwnnnnnnnnnnnneeessssssssseeeeeennnnnn
				player->Move(directions[i]);

				map->revealNear(player->getPosition().x, player->getPosition().y, player, m_turns);

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
			map->interact(player, m_turns);

			system("pause");
		}
	}
	
	return loop;
}

void Game::nextTurn()
{
	map->nextTurn(player, m_turns);

	m_turns++;
}
