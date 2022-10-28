#include "Player.h"

// RAII
// Resource
// Acquisition
// is
// Initialization

// Called when the object when created
Player::Player()
{
	maxItemCount = 12;
	inventory = new Item[maxItemCount];
	currentItemCount = 0;
}

// Called when the object is irrelevant
Player::~Player()
{
	delete[] inventory;
	inventory = nullptr;
}

void Player::AddItem(Item item)
{
	inventory[currentItemCount] = item;
	++currentItemCount;
}

Item * Player::GetItem(int idx)
{
	return &inventory[idx];
}

int Player::ItemsHeld()
{
	return currentItemCount;
}
