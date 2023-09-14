/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:21:58 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/14 12:54:34 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Fixed.hpp"
#include	<iostream>
#include	<iomanip>
#include 	<string>
#include	<cstdlib>
#include	<limits.h>

std::string	cinplus(std::string str)
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

int		cintplus(std::string str)
{
	std::string	strinput;
	long		input;
	bool		valid = false;

	while (!valid)
	{
		strinput = cinplus(str);
		valid = true;
		size_t		i = 0;
		if (strinput[i] == '-' && strinput[i + 1])
			i++;
		while (strinput[i] && valid == true)
		{
			if (!std::isdigit(strinput[i]))
			{
					std::cerr << RED "Invalid input; please enter a valid integer.\n" DEFAULT;
					valid = false;
			}
			i++;
		}
		if (valid)
		{
			input = std::atoll(strinput.c_str());			
			if (input > INT_MAX || input < INT_MIN)
			{
				std::cerr << RED "Input out of range for contact; please try ["<< INT_MIN << " to " << INT_MAX << "].\n" DEFAULT;
				valid = false;
			}
		}
	}
	return((int)input);
}

int main( void )
{
	// Fixed	a;
	// Fixed	b(a);
	// Fixed	c;
	// c = b;
	// std::cout << a.getRawBits() << std::endl;
	// std::cout << b.getRawBits() << std::endl;
	// std::cout << c.getRawBits() << std::endl;
	Fixed	F0;
	Fixed	F1;
	F0.setRawBits(cintplus("[Calling setRawBits] Set F0 value: "));
	F1.setRawBits(cintplus("[Calling setRawBits] Set F1 value: "));
	std::cout << GREEN "\n";
	Fixed F2 = F0;
	std::cout << "[Calling getRawBits]\n";
	std::cout << "F0: " << F0.getRawBits() << "\nF1: " << F1.getRawBits() << "\nF2: " << F2.getRawBits() << "\n\n" YELLOW;
	F1 = F2;
	std::cout << "[Calling getRawBits]\n";
	std::cout << "F0: " << F0.getRawBits() << "\nF1: " << F1.getRawBits() << "\nF2: " << F2.getRawBits() << "\n\n" DEFAULT;
	return 0;
}
