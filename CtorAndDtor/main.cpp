#include "Player.h"

#include <iostream>

int main()
{
	Player p1;
	p1.AddItem({ 6, 20 });
	p1.AddItem({ 7, 7 });

	Player p2;
	p2 = p1;

	p1.AddItem({ 20, 1 });

	Item * slot2item = p2.GetItem(2);

	std::cout << "Yayy" << std::endl;
}