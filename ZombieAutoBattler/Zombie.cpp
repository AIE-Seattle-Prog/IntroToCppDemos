#include "Zombie.h"

#include "MathUtils.h"

#include <iostream>

Zombie::Zombie()
{
	Health = 0;
	AttackPower = 0;
	Defense = 0;
	IsPlayer = false;
}

Zombie::Zombie(int startHP, int startATK, int startDEF) : Zombie()
{
	MaxHealth = startHP;
	Health = startHP;
	AttackPower = startATK;
	Defense = startDEF;
}

int Zombie::GetHealth()
{
	return Health;
}

void Zombie::Heal(int healing)
{
	Health = Clamp(Health + healing, 0, MaxHealth);
}

void Zombie::Attack(Zombie * victim)
{
	std::cout << "Zombie attacks for " << AttackPower << " DMG" << std::endl;
	victim->TakeDamage(AttackPower);
}

void Zombie::TakeDamage(int damageDealt)
{
	int realDamage = damageDealt - Defense;
	Health -= realDamage;
	std::cout << "Zombie takes " << realDamage << " DMG" << std::endl;
	std::cout << "Zombie has " << Health << " HP remaining!" << std::endl;
}
