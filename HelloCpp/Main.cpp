#include <iostream>	// std::cout

int Sum(int a, int b);	// DECLARING a sum function

// DON'T DO THIS
// using namespace std; // EVERYTHING from the std namespace

// DO THIS
using std::cout;
using std::endl;

int main()
{
	cout << "Hello World!" << endl;
	printf("Hello World!\n");

	int total = Sum(2, 3);

	cout << total << endl;
	printf("%d", total);

	return 0;
}

int Sum(int a, int b)	// DEFINING a sum function
{
	return a + b;
}
