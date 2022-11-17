#include "Container.h"

#include <vector>

struct Vector2
{
	int x, y;

	Vector2 operator+(Vector2 & other)
	{
		return { x + other.x, y + other.y };
	}
};

template <typename T>
T Add(T a, T b)
{
	return a + b;
}

template <typename T>
T Lerp(T start, T end, T alpha)
{
	T diff = start - end;
	return start + diff * alpha;
}

int main()
{
	// explicit template parameter deduction
	int sumExplicit = Add<int>(5, 7);

	// implicit template parameter deduction
	int sumImplicit = Add(5, 7);

	float fSum = Add(5.0f, 7.0f);
	double dSum = Add(5.0, 7.0);
	short sSum = Add(5, 7);

	Vector2 vSum = Add(Vector2{}, Vector2{});


	float nums[10] = { 0, 1, 2 };

	TContainer<int> containerOfInts;
	TContainer<float> containerOfFloat;
	containerOfFloat.SetData(nums);

	std::vector<int *> vectorOfIntPtrs;
}