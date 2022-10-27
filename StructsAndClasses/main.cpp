#include <iostream>

// You don't pay for what you don't use

struct Vector2
{
	float x, y;
};

int main()
{
	Vector2 posA = {};
	Vector2 posB = {5.0f};

	Vector2 * somePos = &posB;

	std::cout << posA.x << posA.y << std::endl;
	std::cout << somePos->x << somePos->y << std::endl;

	return 0;
}