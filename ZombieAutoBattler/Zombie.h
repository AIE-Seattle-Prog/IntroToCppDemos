#pragma once

#include <string>

class Zombie
{
	int Health;

public:
	int AttackPower;
	int Defense;

	int MaxHealth;

	std::string Name;
	bool IsPlayer;

	Zombie();
	Zombie(int startHP, int startATK, int startDEF);

	// Rule 0/3/5
	// 
	// destructor
	// copy constructor
	// copy assignment
	// 
	// move constructor
	// move assignment

	// Provides read-only access to health
	int GetHealth();

	void Heal(int healing);

	// Attack another zombie
	// (will call TakeDamage to apply damage)
	void Attack(Zombie * victim);

	// Handle taking damage
	// (will consider DEF before subtracting health)
	void TakeDamage(int damageDealt);
};
