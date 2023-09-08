/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:02:08 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/08 21:56:10 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"PhoneBook.hpp"

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
			std::cout << RED "Invalid input; please try again.\n" DEFAULT;
		std::cin.clear();
	}
	return(input);
}

int	main(void)
{
	PhoneBook	book;
	std::string	command;

	book.welcome();
	while (true)
	{
		command = cin_plus( CYAN "Enter the command: " DEFAULT);
		if (command.compare("ADD") == 0)
			book.add_contact();
		else if (command.compare("SEARCH") == 0)
			book.search_contact();
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << RED "Invalid command. You can only use ADD, \
SEARCH or EXIT.\n" DEFAULT;
	}
}
