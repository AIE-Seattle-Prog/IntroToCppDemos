// 1. is NULL a valid answer? if so, use a pointer
// 2. am I expecting an object or a pointer? if pointer, use a pointer

class GameObject {};
class Inventory {};
class Player { public: Inventory inv; };

void SetTarget(GameObject * ptrToTarget)
{
	if (ptrToTarget == nullptr)
	{
		// we're done aiming, go back to movement mode
	}
	else
	{
		// we have a target, prepare to aim!!!
	}
}

void SetOwningPlayer(Player & owner)
{

}

int main()
{
	int health = 100;
	int & healthRef = health; // must be an LVALUE (variable)

	// OK - sets the reference, which refers to health, so health is now 200
	healthRef = 200;

	int respawnHealth = 500;
	healthRef = respawnHealth;
	healthRef = health;
	healthRef = 300; // only affects health, not respawnHealth
	
	return 0;
}