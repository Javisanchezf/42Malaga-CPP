#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	for (int i = 5; i < 15; i++)
		v.push_back(i);
	try
	{
		std::cout << "Position: " << easyfind(v, 5) << "\tNumber: "<<v[easyfind(v, 5)] << std::endl;
		std::cout << "Position: " << easyfind(v, 25) << "\tNumber: "<<v[easyfind(v, 5)] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	return 0;
}