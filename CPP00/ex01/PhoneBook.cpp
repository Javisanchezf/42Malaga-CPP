/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:52:37 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/09 18:40:11 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << RED "🗑️\tPhoneBook deleted\t🗑️\n" DEFAULT;
}

void			PhoneBook::welcome(void)
{
	std::cout << "----------------------------------------------\n";
	std::cout << BOLD "|  📞 Welcome to your personal PhoneBook 📞  |\n";
	std::cout << "--------------------USAGE---------------------\n";
	std::cout << "| ADD : To add a contact.                    |\n";
	std::cout << "| SEARCH : To search for a contact.          |\n";
	std::cout << "| EXIT : to quite the PhoneBook.             |\n";
	std::cout << "--------------------OTHER---------------------\n";
	std::cout << "| LIMITS : 8 contacts.                       |\n";
	std::cout << "----------------------------------------------\n" DEFAULT;
}

void		PhoneBook::add_contact(void)
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

void		PhoneBook::search_contact(void) const
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
