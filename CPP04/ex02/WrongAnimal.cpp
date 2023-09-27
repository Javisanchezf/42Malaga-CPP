/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:03:53 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/27 13:03:56 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

WrongAnimal::WrongAnimal(void): _type("Unnamed")
{
	std::cout << "WrongAnimal " << this->_type << " created.\n";
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
	std::cout << "WrongAnimal " << this->_type << " created.\n";
}

/*----------------------------DESTRUCTORS----------------------------*/

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal " << this->_type << " destroyed.\n";
}

/*----------------------------COPY-METHODS----------------------------*/

WrongAnimal::WrongAnimal(const WrongAnimal &copy): _type(copy._type)
{
	std::cout << "WrongAnimal " << this->_type << " copied.\n";
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &equal)
{
	std::cout << "Copy assignment operator called.\n";
	this->_type = equal._type;
	return (*this);
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

void			WrongAnimal::makeSound(void) const
{
	std::cout << "\"Undefined sound\"\n";
}

std::string		WrongAnimal::getType(void) const
{
	return (this->_type);
}
