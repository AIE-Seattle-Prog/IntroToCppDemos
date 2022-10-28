#include "MathUtils.h"

#include <cstdlib>
#include <ctime>

void SeedRandom(unsigned * seed)
{
	// if null, use time
	if (seed == nullptr)
	{
		std::srand(std::time(nullptr));
	}
	// else, use the value pointed by seed
	else
	{
		std::srand(*seed);
	}
}

int RandomRange(int minIncl, int maxExcl)
{
	int range = maxExcl - minIncl;
	return minIncl + std::rand() % range;

	// TODO: look into a better random
}
