#include "Shop.h"

Shop::Shop(int x, int y) : Tile(x, y)
{
	//m_max = 10;
}

Shop::Shop(const Shop & copyShop) : Tile(copyShop)
{
	srand((int)time(0));
}

Shop & Shop::operator=(const Shop & copyShop)
{
	if (this == &copyShop) return *this;

	for (int i = 0; i < 5; i++)
	{
		m_available[i] = copyShop.m_available[i];
	}

	return *this;
}

void Shop::Activate(Player * player, int turns)
{
	if (!m_discovered)
	{
		m_discovered = true;

		for (int i = 0; i < 5; i++)
		{
			m_available[i] = rand() % (L_HLTH + 1);
		}
		m_available[0] = S_HLTH;

		std::cout << "You have discovered a shop at (" << m_position.x << ", " << m_position.y << ")\n";
		
	}
}

void Shop::buy(Player * player)
{
	std::cout << "Shop Inventory:\n";

	int option;

	for (int i = 0; i < 5; i++)
	{
		std::cout << i << ". " << getPotionName(m_available[i]) << " - " << getPotionCost(m_available[i]) << " gold\n";
	}

	std::cout << "5. Exit\n" << "Choose an option from the above\n";
	std::cin >> option;

	while (std::cin.fail() || (option < 0 || option > 5))
	{
		// loops infinitely if a letter is inputted if this is not done
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nInvalid input\n";
		std::cout << "Choose an option from the above\n";

		std::cin >> option;
	}
	int itemID = m_available[option];

	if (option >= 0 && option <= 4)
	{
		if (player->getGold() < getPotionCost(itemID))
		{
			std::cout << "You do not have enough gold!\n";
		}
		else
		{
			std::cout << "You gained: ";

			std::cout << getPotionValue(itemID) << " " << getStatName(itemID) << "\n";
			player->changeStat(itemID, getPotionValue(itemID));
		}	
	}
}

Shop::~Shop()
{
}

std::string Shop::getPotionName(int itemID)
{
	if (itemID == S_DXT)
	{
		return "Small Dexterity Potion";
	}
	else if (itemID == M_DXT)
	{
		return "Medium Dexterity Potion";
	}
	else if (itemID == L_DXT)
	{
		return "Large Dexterity Potion";
	}

	else if (itemID == S_INT)
	{
		return "Small Intelligence Potion";
	}
	else if (itemID == M_INT)
	{
		return "Medium Intelligence Potion";
	}
	else if (itemID == L_INT)
	{
		return "Large Intelligence Potion";
	}

	else if (itemID == S_STR)
	{
		return "Small Strength Potion";
	}
	else if (itemID == M_STR)
	{
		return "Medium Strength Potion";
	}
	else if (itemID == L_STR)
	{
		return "Large Strength Potion";
	}

	else if (itemID == S_HLTH)
	{
		return "Small Health Potion";
	}
	else if (itemID == M_HLTH)
	{
		return "Medium Health Potion";
	}
	else if (itemID == L_HLTH)
	{
		return "Large Health Potion";
	}

	return "N/A";
}

std::string Shop::getStatName(int itemID)
{
	if (itemID >= S_STR && itemID <= L_STR)
	{
		return "strength";
	}
	else if (itemID >= S_INT && itemID <= L_INT)
	{
		return "intelligence";
	}
	else if (itemID >= S_DXT && itemID <= L_DXT)
	{
		return "dexterity";
	}
	else if (itemID >= S_HLTH && itemID <= L_HLTH)
	{
		return "health";
	}
	return "N/A";
}

int Shop::getPotionCost(int itemID)
{
	if (itemID == S_DXT || itemID == S_HLTH || itemID == S_INT || itemID == S_STR)
	{
		return 5;
	}
	else if (itemID == M_DXT || itemID == M_HLTH || itemID == M_INT || itemID == M_STR)
	{
		return 25;
	}
	else if (itemID == L_DXT || itemID == L_HLTH || itemID == L_INT || itemID == L_STR)
	{
		return 50;
	}
	return 0;
}

int Shop::getPotionValue(int itemID)
{
	if (itemID == S_DXT || itemID == S_HLTH || itemID == S_INT || itemID == S_STR)
	{
		return 3;
	}
	else if (itemID == M_DXT || itemID == M_HLTH || itemID == M_INT || itemID == M_STR)
	{
		return 6;
	}
	else if (itemID == L_DXT || itemID == L_HLTH || itemID == L_INT || itemID == L_STR)
	{
		return 9;
	}
	return 0;
}
