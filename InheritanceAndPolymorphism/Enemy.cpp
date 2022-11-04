#include "Enemy.h"

#include <iostream>

Enemy::Enemy()
{
	std::cout << "An Enemy!" << std::endl;
}

Enemy::~Enemy()
{
	std::cout << "Destroying an Enemy!" << std::endl;
}

void Enemy::Update()
{
	std::cout << "Enemy Updated!" << std::endl;
}
