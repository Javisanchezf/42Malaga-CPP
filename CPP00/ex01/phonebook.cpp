/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:52:37 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/08 21:31:57 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"phonebook.hpp"

phonebook::phonebook(void)
{
	this->_index = 0;
}

phonebook::~phonebook(void)
{
	std::cout << RED "🗑️\tPhonebook deleted\t🗑️\n" DEFAULT;
}

void			phonebook::welcome(void)
{
	std::cout << "----------------------------------------------\n";
	std::cout << BOLD "|  📞 Welcome to your personal phonebook 📞  |\n";
	std::cout << "--------------------USAGE---------------------\n";
	std::cout << "| ADD : To add a contact.                    |\n";
	std::cout << "| SEARCH : To search for a contact.          |\n";
	std::cout << "| EXIT : to quite the PhoneBook.             |\n";
	std::cout << "--------------------OTHER---------------------\n";
	std::cout << "| LIMITS : 8 contacts.                       |\n";
	std::cout << "----------------------------------------------\n" DEFAULT;
}

std::string	phonebook::_getinput(std::string str) const
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
			std::cout << RED "Invalid input; please try again.\n" DEFAULT;
		std::cin.clear();
	}
	return(input);
}

void		phonebook::add_contact(void)
{
	int		new_index;

	new_index = this->_index % 8;
	this->_contact[new_index].set_data(0, _getinput(BLUE "First name\t: " DEFAULT));
	this->_contact[new_index].set_data(1, _getinput(BLUE "Last name\t: " DEFAULT));
	this->_contact[new_index].set_data(2, _getinput(BLUE "Nickname\t: " DEFAULT));
	this->_contact[new_index].set_data(3, _getinput(BLUE "Phone number\t: " DEFAULT));
	this->_contact[new_index].set_data(4, _getinput(BLUE "Darkest secret\t: " DEFAULT));
	this->_index++;
}
std::string	phonebook::_fix_column(std::string word) const
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

int		phonebook::_getintinput(std::string str, int max) const
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
				std::cout << RED "Invalid input; please enter a valid integer.\n" DEFAULT;
				valid = false;
				break ;
			}
		}
		if (valid)
		{
			input = std::atoi(strinput.c_str());			
			if (input > max || input < 0)
			{
				std::cout << RED "Input out of range for contact; please try 0 to " << max << ".\n" DEFAULT;
				valid = false;
			}
		}
	}
	return(input);
}

void		phonebook::search_contact(void) const
{
	int			i;
	int			j;
	std::string	nbr;

	i = 0;
	if (this->_index == 0)
	{
		std::cout << RED "There are no contacts to search yet.\n" DEFAULT;
		return ;
	}
	std::cout << GREEN "---------------------------------------------\n";
	std::cout << BOLD"|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|\n" DEFAULT GREEN;
	std::cout << "---------------------------------------------\n";
	while (this->_index > i && i < 8)
	{
		j = -1;
		std::cout << "|         " << i << "|";
		while (++j < 3)
		{
			std::cout << _fix_column(this->_contact[i].get_data(j)) << "|";
		}
		std::cout << "\n";
		i++;
	}
	std::cout << "---------------------------------------------\n" DEFAULT;
	i = _getintinput(BLUE "Enter the index of the entry you want to see: " DEFAULT, this->_index - 1);
	std::cout << GREEN "First name\t: " << this->_contact[i].get_data(0) << "\n";
	std::cout << "Last name\t: " << this->_contact[i].get_data(1) << "\n";
	std::cout << "Nickname\t: " << this->_contact[i].get_data(2) << "\n";
	std::cout << "Phone number\t: " << this->_contact[i].get_data(3) << "\n";
	std::cout << "Darkest secret\t: " << this->_contact[i].get_data(4) << "\n" DEFAULT;
	
}
