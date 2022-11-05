#pragma once

#include <iostream>

class Sentinel
{
	int instId = -1;

public:
	Sentinel(int idNum)
	{
		instId = idNum;
		std::cout << "Sentinel " << instId << " ctor!" << std::endl;
	}

	~Sentinel()
	{
		std::cout << "Sentinel " << instId << " destroyed!" << std::endl;
	}
};

// 1. What was the goal?
// 2. What did you get done?
// 3. What is the goal for next time?