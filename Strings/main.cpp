#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <string>

using std::string;

int main()
{
	// EXAMPLE OF THE IMPORTANCE OF THE
	// NULL TERMINATING CHARACTER
	int numbers[] = { 4,1,2,6,9 };
	char name[] = "John";
	name[4] = 'E'; // removes the null-term - so reading will go out of bounds
	char name2[] = "Madden";

	std::cout << numbers << std::endl;
	std::cout << name << std::endl;

	// STRCAT
	char cFullName[20] = "John";
	char cFastName[] = "Madden";

	strcat(cFullName, cFastName);

	std::cout << cFullName;

	// std::string and Copying
	string firstName = "Terry";
	string lastName = "Nguyen";
	
	string firstNameCopy = firstName;

	string firstNameButWithSomething = firstName;
	firstNameCopy[0] = 'J';

	string fullname = firstName + lastName;

	return 0;
}