#include "Sentinel.h"

void GetStaticSentinel(bool shouldDelete=false)
{
	static Sentinel sVal(97);
	if (shouldDelete)
	{
		delete &sVal;
	}
}

int* GetArrayOfNumbers(int numCount)
{
	int * arr = new int[numCount];

	for (int i = 0; i < numCount; ++i)
	{
		arr[i] = i;
	}

	return arr;
}

int * GetArrayOfNumbersAutomatic(int numCountUpTo100)
{
	int arr[100];

	for (int i = 0; i < numCountUpTo100; ++i)
	{
		arr[i] = i;
	}

	return arr;
}

int main()
{
	// AUTOMATIC
	{
		int number = 0;
		Sentinel sVal(5);
		Sentinel sVal2(20);
	}

	// DYNAMIC
	Sentinel * dVal = new Sentinel(255);

	delete dVal;

	int * arrOfNums = GetArrayOfNumbers(25);
	int * autoArrOfNums = GetArrayOfNumbersAutomatic(25);

	// STATIC
	GetStaticSentinel();
	GetStaticSentinel();
	GetStaticSentinel();
	GetStaticSentinel();
	GetStaticSentinel();
	GetStaticSentinel();
	GetStaticSentinel(true);

	delete[] arrOfNums;

	// Resource
	// Acquisition
	// Is
	// Initialization





	// declaring a variable for the array of arrays
	int ** grid;

	// create the outer array
	grid = new int * [3];

	// create the inner array at each element of the outer array
	grid[0] = new int[3];
	grid[1] = new int[3];
	grid[2] = new int[3];

	return 0;
}