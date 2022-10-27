#include <iostream>

struct Vector3 { float x, y, z; };

class Enemy
{
public:
	Vector3 Position;
};

class Player
{
public:
	float Health;
	float Attack;

	Vector3 Position;
	Enemy * ptrToClosestEnemy = nullptr;
};

void TeleportPlayer(Player * player)
{
	player->Position = { 2.5f, .9f, .4f };
}

int main()
{
	Player p1;
	TeleportPlayer(&p1);

	// will cause a NULL ACCESS exception!
	//std::cout << p1.ptrToClosestEnemy->Position.x << std::endl;
	//std::cout << p1.ptrToClosestEnemy->Position.y << std::endl;


	// if you write NEW ...
	int * arr = new int[5];

	arr[0] = 2;
	arr[1] = 4;
	arr[2] = 6;
	arr[3] = 8;
	arr[4] = 10;

	// immediately write DELETE ...
	delete[] arr;
	arr = nullptr;

	if (arr != nullptr)
	{
		arr[0] = 5;
	}
}
