/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:46:23 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/05 19:24:27 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// Definición de la función independiente _getInput
std::string _getInput(const std::string& str)
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
	return	input;
}

// Ejemplo de una clase que utiliza la función _getInput
class Contact {
public:
    std::string getName() const {
        return _getInput("Enter name: ");
    }

    std::string getEmail() const {
        return _getInput("Enter email: ");
    }
};

int main() {
    Contact contact;
    std::string name = contact.getName();
    std::string email = contact.getEmail();

    std::cout << "Name: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;

    return 0;
}
