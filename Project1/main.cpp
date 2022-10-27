#include <iostream>

int main()
{
	int val = 5;

	// & is the "address-of" operator
	int * ptrToVal = &val;

	std::cout << "val\t\t" << val << std::endl;
	std::cout << "ptrToVal\t" << ptrToVal << std::endl;
	std::cout << "*ptrToVal\t" << *ptrToVal << std::endl;
}