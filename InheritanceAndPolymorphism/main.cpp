#include "Enemy.h"
#include "Grunt.h"
#include <iostream>

int main()
{
	int actualEnemies = 4;

	//Enemy * anEnemy = new Grunt();

	BaseEnemy * enemies[5] = {};

	std::cout << "Object 1" << std::endl;
	enemies[0] = new Enemy();
	std::cout << "Object 2" << std::endl;
	enemies[1] = new Enemy();
	std::cout << "Object 3" << std::endl;
	enemies[2] = new Grunt();

	for (int i = 0; i < actualEnemies; ++i)
	{
		enemies[i]->Update();
	}
	//anEnemy->Update();

	for (int i = 0; i < actualEnemies; ++i)
	{
		delete enemies[i];
	}

	//delete anEnemy;

	return 0;
}