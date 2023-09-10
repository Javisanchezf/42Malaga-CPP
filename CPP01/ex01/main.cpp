/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:29:56 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/10 13:49:20 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <climits>

std::string	cin_plus(std::string str)
{
	std::string	input;
	bool		valid = false;

	while (!valid)
	{
		std::cout << str;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			valid = true;
		else if (std::cin.eof())
			exit(0);
		else
			std::cerr << RED "Invalid input; please try again.\n" DEFAULT;
		std::cin.clear();
	}
	return(input);
}

int		getintinput(std::string str)
{
	std::string	strinput;
	int			input;
	bool		valid = false;

	while (!valid)
	{
		strinput = cin_plus(str);
		valid = true;
		for (size_t _ = 0; _ < strinput.length(); _++)
		{
			if (!std::isdigit(strinput[_]))
			{
				std::cerr << RED "Invalid input; please enter a valid integer.\n" DEFAULT;
				valid = false;
				break ;
			}
		}
		if (valid)
		{
			input = std::atoi(strinput.c_str());			
			if (input > INT_MAX || input < 0)
			{
				std::cerr << RED "Input out of range; please try 0 to " << INT_MAX << ".\n" DEFAULT;
				valid = false;
			}
		}
	}
	return(input);
}

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int	size;

	size = getintinput("Number of Zombies: ");
	Zombie *horde = zombieHorde(size ,cin_plus("Zombies name: "));
	std::cout << BLUE "\nCalling announce()\n" DEFAULT;
	for (int i = 0; i < size; i++)
		horde[i].announce();
	std::cout << BLUE "\nFreeing allocated memory on heap\n" DEFAULT;
	delete [] horde;
}