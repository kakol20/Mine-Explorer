#ifndef SHOP_H
#define SHOP_H

#include "Tile.h"

class Shop : public Tile
{
public:
	Shop(int x, int y);

	Shop(const Shop& copyShop);
	virtual Shop& operator=(const Shop& copyShop);

	virtual void Activate(Player* player, int turns);

	void buy(Player* player);


	virtual ~Shop();

private:

	//int m_max;
	int m_available[5];

	std::string getPotionName(int itemID);
	std::string getStatName(int itemID);
	int getPotionCost(int itemID);
	int getPotionValue(int itemID);

};

#endif // !SHOP_H
