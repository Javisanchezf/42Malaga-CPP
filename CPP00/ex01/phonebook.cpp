/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:52:37 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/07 21:36:12 by javiersa         ###   ########.fr       */
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

std::string	phonebook::_getinput(std::string	str) const
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
	this->_contact[new_index].set_data(0, _getinput(BLUE"First name\t: "DEFAULT));
	this->_contact[new_index].set_data(1, _getinput(BLUE"Last name\t: "DEFAULT));
	this->_contact[new_index].set_data(2, _getinput(BLUE"Nickname\t: "DEFAULT));
	this->_contact[new_index].set_data(3, _getinput(BLUE"Phone number\t: "DEFAULT));
	this->_contact[new_index].set_data(4, _getinput(BLUE"Darkest secret\t: "DEFAULT));
	this->_index++;
}

void		phonebook::search_contact(void) const
{
	int		i;
	int		j;

	i = 0;
	std::cout << CYAN "---------------------------------------------\n";
	std::cout << BOLD"|  INDEX   |FIRST NAME|LAST  NAME| NICKNAME |\n" DEFAULT CYAN;
	std::cout << "---------------------------------------------\n";
	while (this->_index > i && i < 8)
	{
		j = -1;
		std::cout << "|    " << i << "     |";
		while (++j < 5)
		{
			std::cout << this->_contact[i].get_data(j) << "|";
		}
		std::cout << "\n";
		i++;
	}
	std::cout << "---------------------------------------------\n" DEFAULT;
}
