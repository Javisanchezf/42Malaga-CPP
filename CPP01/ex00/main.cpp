/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:57:50 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/09 21:14:25 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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

int	main(void)
{
	std::cout << BLUE "Creating zombie on the stack.\n" DEFAULT;
	Zombie zombi0(cin_plus("Zombie name: "));
	std::cout << BLUE "Creating other zombie on the stack.\n" DEFAULT;
	Zombie zombi1(cin_plus("Zombie name: "));
	std::cout << BLUE "Calling announce().\n" DEFAULT;
	zombi1.announce();

	std::cout << BLUE "\nCalling newZombie().\n" DEFAULT;
	Zombie *zombi2 = newZombie(cin_plus("Zombie name: "));
	std::cout << BLUE "Freeing allocated memory on heap.\n" DEFAULT;
	delete zombi2;

	std::cout << BLUE "\nCalling randomChump().\n" DEFAULT;
	randomChump(cin_plus("Zombie name: "));

	std::cout << BLUE "\nFinishing the program.\n" DEFAULT;
	return 0;
}