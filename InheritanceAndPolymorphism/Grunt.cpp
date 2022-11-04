#include "Grunt.h"

#include <iostream>

Grunt::Grunt()
{
	std::cout << "A Grunt!" << std::endl;
}
Grunt::~Grunt()
{
	std::cout << "Destroying a Grunt!" << std::endl;
}

void Grunt::Update()
{
	std::cout << "Grunt Updated!!" << std::endl;
}