#include "Zombie.h"

#include <iostream>

Zombie::Zombie()
{
	Health = 0;
	AttackPower = 0;
	Defense = 0;
}

Zombie::Zombie(int startHP, int startATK, int startDEF)
{
	Health = startHP;
	AttackPower = startATK;
	Defense = startDEF;
}

int Zombie::GetHealth()
{
	return Health;
}

void Zombie::Attack(Zombie * victim)
{
	std::cout << "TODO: ATTACK!" << std::endl;
}
