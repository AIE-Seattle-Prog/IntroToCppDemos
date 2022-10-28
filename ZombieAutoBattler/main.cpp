#include <iostream>

#include "MathUtils.h"

#include "Zombie.h"

#include <cassert>
#include <string>

int main()
{
	//
	// Initialization
	//
	SeedRandom(nullptr);

	Zombie playerZombie = Zombie(12, 8, 6);
	playerZombie.Name = "My Zombie";
	playerZombie.IsPlayer = true;

	//
	// Game Loop
	//

	bool isGameOver = false;

	while (!isGameOver)
	{
		int zombieCount = RandomRange(5, 8);

		Zombie * zombies = new Zombie[zombieCount];
		zombies[0] = playerZombie; // for the player!
		zombies[0].Heal(zombies[0].MaxHealth);

		std::string names[] = {
			"John",
			"Uppy",
			"Mario",
			"Larissa",
			"Luigi",
			"Baird",
			"Sally",
			"Will",
			"Elizabeth",
			"Harold",
			"Alexa",
			"Todd Howard",
			"Terry"
		};
		int ancestry[13]{};

		// skip first zombie - that's for the player (special!)
		for (int i = 1; i < zombieCount; ++i)
		{
			int startHP = RandomRange(10, 16);

			zombies[i] = Zombie(startHP, 7, 2);
			int nameIndex = RandomRange(0, 13);

			if (ancestry[nameIndex] == 0)
			{
				zombies[i].Name = names[nameIndex];
				++ancestry[nameIndex];
			}
			else
			{
				zombies[i].Name = names[nameIndex] + " the " + std::to_string(ancestry[nameIndex] + 1);
				++ancestry[nameIndex];
			}
		}

		int activeZombies = zombieCount;

		while (activeZombies > 1)
		{
			for (int i = 0; i < activeZombies; ++i)
			{
				// TODO: avoid attacking ourselves
				// pick a random target
				int targetIndex = (i + RandomRange(1, activeZombies)) % activeZombies;

				assert(targetIndex != i);

				std::cout << "Zombie " << zombies[i].Name << " is attacking!" << std::endl;
				std::cout << "Zombie " << zombies[targetIndex].Name << " is targeted!" << std::endl;

				// attack as this zombie
				// the other zombie recv' damage
				zombies[i].Attack(&zombies[targetIndex]);

				// check for defeat
				if (zombies[targetIndex].GetHealth() <= 0)
				{
					std::cout << "A zombie has been defeated!" << std::endl;

					// swap it with w/ the last active zombie
					Zombie temp = zombies[activeZombies - 1];
					zombies[activeZombies - 1] = zombies[targetIndex];
					zombies[targetIndex] = temp;

					// decrement the activeZombies count
					--activeZombies;
				}

				std::cout << " ... " << std::endl;
			}
		}

		std::cout << zombies[0].Name << " is the victor!" << std::endl;

		// TODO: save the player if they won!
		if (zombies[0].IsPlayer)
		{
			std::cout << "You win! You did it! Get a stat increase!" << std::endl;
			int statIncreased = RandomRange(0, 3); // 0, 1, 2

			int increase = RandomRange(1, 4); // 1-3

			switch (statIncreased)
			{
			case 0:
				playerZombie.MaxHealth += increase;
				break;
			case 1:
				playerZombie.AttackPower += increase;
				break;
			case 2:
				playerZombie.Defense += increase;
				break;
			default:
				std::cout << "No stat increased! Oops?" << std::endl;
			}
		}
		else
		{
			isGameOver = true;
		}

		// do you want to play again?
		if (!isGameOver)
		{
			std::cout << "Do you want to keep playing? (Y/N)" << std::endl;
			char userAnswer = '\0';

			std::cin >> userAnswer;
			switch (userAnswer)
			{
			case 'n':
			case 'N':
				isGameOver = true;
				break;
			default:
				break;
			}
		}

		// for clean-up!
		delete[] zombies;
	}

	//
	// Clean-Up
	//

	return 0;
}
