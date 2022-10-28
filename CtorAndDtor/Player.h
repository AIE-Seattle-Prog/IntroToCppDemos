#pragma once


class Item
{
public:
	int goldValue;
	int weightValue;
};

class Player
{
	int currentItemCount;
	int maxItemCount;
	Item * inventory;

public:
	Player();
	~Player();

	// TODO: for NEXT TIME on GAME PROGRAMMING
	Player(Player & player);	// copy constructor
								// copy assignment

	void AddItem(Item item);
	Item * GetItem(int idx);
	int ItemsHeld();
};