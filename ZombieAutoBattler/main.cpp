#include "Zombie.h"

#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(nullptr));
	int randomInt = std::rand(); // 0 to RAND_MAX

	// min-inclusive
	// max-exclusive
	int random0to10 = std::rand() % 10;

	// technically "more random"
	int randomComplex = std::rand() / ((RAND_MAX + 1u) / 10);

	// the number of zombies to have
	int zombieCount = 5 + (std::rand() % 3);

	Zombie * zombies = new Zombie[zombieCount];
	zombies[0] = Zombie(12, 8, 6); // for the player!

	// skip first zombie - that's for the player (special!)
	for (int i = 1; i < zombieCount; ++i)
	{
		int startHP = 10 + (std::rand() % 6);

		zombies[i] = Zombie(startHP, 7, 2);
	}

	// for clean-up!
	delete[] zombies;
}
