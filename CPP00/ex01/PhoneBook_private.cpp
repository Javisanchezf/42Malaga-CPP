/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_private.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:49:44 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/09 19:52:09 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"PhoneBook.hpp"

std::string	PhoneBook::_fix_column(std::string word) const
{
	std::string	fix;
	size_t		size;

	size = word.length();
	if (size >= 10)
	{
		fix = word.substr(0, 9);
		fix += '.';
	}
	else
	{
		fix = word;
		while (fix.length() < 10)
				fix = " " + fix;
	}
	return (fix);
}

std::string	PhoneBook::_getinput(std::string str) const
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

int		PhoneBook::_getintinput(std::string str, int max) const
{
	std::string	strinput;
	int			input;
	bool		valid = false;

	if (max > 7)
		max = 7;
	while (!valid)
	{
		strinput = _getinput(str);
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
			if (input > max || input < 0)
			{
				std::cerr << RED "Input out of range for contact; please try 0 to " << max << ".\n" DEFAULT;
				valid = false;
			}
		}
	}
	return(input);
}
