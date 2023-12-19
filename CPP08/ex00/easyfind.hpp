#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>

template <typename T>
bool	easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		return 0;
	return 1;
	// int i = 0;
	// while (container.begin() != container.end())
	// {
	// 	if (*container.begin() == n)
	// 		return i;
	// 	i++;
	// 	container.erase(container.begin());
	// }
	// throw std::exception();
}

#endif