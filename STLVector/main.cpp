// C++03 tend to prefer raw arrays
// C++11 tend to prefer std::vector (safer! less error prone!)

#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> numbers;

	numbers.reserve(10);

	numbers.push_back(2);
	numbers.push_back(4);
	numbers.push_back(6);
	numbers.push_back(8);
	numbers.push_back(10);

	numbers.pop_back();

	int count = numbers.size();

	// iteration by index
	for (int i = 0; i < numbers.size(); ++i)
	{
		std::cout << numbers[i] << std::endl;
	}

	// iteration by iterator
	auto it = numbers.begin();
	int beginValue = *it;

	it += 2;

	int nextValue = *it;

	for (auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	// iteration by range-based for
	// (C++ equiv. of C#'s foreach)
	for (auto num : numbers)
	{
		std::cout << num << std::endl;
	}

	return 0;
}