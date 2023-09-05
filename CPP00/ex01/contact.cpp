/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:33:13 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/05 20:15:23 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"contact.hpp"

contact::contact(void)
{
}

contact::~contact(void)
{
}

std::string	contact::_getstrinput(std::string	str) const
{
	std::string	input;
	bool		valid;

	valid = false;
	while (!valid)
	{
		std::cout << str;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			valid = true;
		else
			std::cout << "Invalid input; please try again.\n";
		std::cin.clear();
	}
	return(input);
}

int		contact::_getintinput(std::string	str) const
{
	std::string	strinput;
	int			input;
	bool		valid;

	valid = false;
	while (!valid)
	{
		std::cout << str;
		strinput = _getstrinput(str);
		try
		{
			input = std::stoi(strinput);
			valid = true;
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << "Invalid input; please enter a valid integer.\n";
		}
		catch (const std::out_of_range& e)
		{
			std::cout << "Input out of range for integer; please enter a smaller number.\n";
		}
		if (valid)
		{
			char leftover;
			if (std::cin.get(leftover) && !std::isspace(leftover))
			{
				std::cout << "Invalid input; please enter a valid phone number (Only numbers).\n";
				valid = false;
			}
		}
	}
	return(input);
}

void	contact::init(void)
{
	this->_firstname = _getstrinput("First name: ");
	this->_lastname = _getstrinput("Last name: ");
	this->_nickname = _getstrinput("Nickname: ");
	this->_phone = _getintinput("Phone number: ");
	this->_secret = _getstrinput("Darkest secret: ");
	
}