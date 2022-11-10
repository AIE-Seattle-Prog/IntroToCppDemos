#include "String.h"

#include <utility>

String GetRandomName()
{
	return String("John Madden");
}

int main()
{
	String name("Terry");

	// use the copy constructor
	String nameCopy(name);

	String blank;
	// use the copy assignment
	blank = name;

	// use the move constructor
	String aRandomName = std::move(GetRandomName());

	// use the move assignment
	String moveBlank;

	moveBlank = GetRandomName();

	return 0;
}