#include "easyfind.hpp"

int main()
{
	int first = 5;
	int second = 1234;
	std::vector<int> v;
	for (int i = 5; i < 15; i++)
		v.push_back(i);

	std::cout << "Trying to find " << first << " in the vector: " << std::endl;
	if (easyfind(v, first))
		std::cout << "Found\n" << std::endl;
	else
		std::cout << "Not found\n" << std::endl;

	std::cout << "Trying to find " << second << " in the vector: " << std::endl;
	if (easyfind(v, second))
		std::cout << "Found\n" << std::endl;
	else
		std::cout << "Not found\n" << std::endl;
	return 0;
}