/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:33:13 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/06 21:48:04 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"contact.hpp"

contact::contact(void)
{
}

contact::~contact(void)
{
}

std::string		contact::get_firstname(void)	const
{
	return (this->_firstname);
}

std::string		contact::get_lastname(void)	const
{
	return (this->_lastname);
}

std::string		contact::get_nickname(void)	const
{
	return (this->_nickname);
}

std::string		contact::get_phone(void)	const
{
	return (this->_phone);
}

std::string		contact::get_secret(void)	const
{
	return (this->_secret);
}

void			contact::set_firstname(std::string str)
{
	this->_firstname = str;
}

void			contact::set_lastname(std::string str)
{
	this->_lastname = str;
}

void			contact::set_nickname(std::string str)
{
	this->_nickname = str;
}

void			contact::set_phone(std::string str)
{
	this->_phone = str;
}

void			contact::set_secret(std::string str)
{
	this->_secret = str;
}

// std::string	contact::_getstrinput(std::string	str) const
// {
// 	std::string	input;
// 	bool		valid;

// 	valid = false;
// 	while (!valid)
// 	{
// 		std::cout << str;
// 		std::getline(std::cin, input);
// 		if (std::cin.good() && !input.empty())
// 			valid = true;
// 		else
// 			std::cout << "Invalid input; please try again.\n";
// 		std::cin.clear();
// 	}
// 	return(input);
// }

// int		contact::_getintinput(std::string	str) const
// {
// 	std::string	strinput;
// 	int			input;
// 	bool		valid;

// 	valid = false;
// 	while (!valid)
// 	{
// 		std::cout << str;
// 		strinput = _getstrinput(str);
// 		try
// 		{
// 			input = std::stoi(strinput);
// 			valid = true;
// 		}
// 		catch (const std::invalid_argument& e)
// 		{
// 			std::cout << "Invalid input; please enter a valid integer.\n";
// 		}
// 		catch (const std::out_of_range& e)
// 		{
// 			std::cout << "Input out of range for integer; please enter a smaller number.\n";
// 		}
// 		if (valid)
// 		{
// 			char leftover;
// 			if (std::cin.get(leftover) && !std::isspace(leftover))
// 			{
// 				std::cout << "Invalid input; please enter a valid phone number (Only numbers).\n";
// 				valid = false;
// 			}
// 		}
// 	}
// 	return(input);
// }

// void	contact::init(void)
// {
// 	this->_firstname = _getstrinput("First name: ");
// 	this->_lastname = _getstrinput("Last name: ");
// 	this->_nickname = _getstrinput("Nickname: ");
// 	this->_phone = _getintinput("Phone number: ");
// 	this->_secret = _getstrinput("Darkest secret: ");
	
// }