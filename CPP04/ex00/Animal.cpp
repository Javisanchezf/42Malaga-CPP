/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:01 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/27 12:31:18 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

Animal::Animal(void): _type("Unnamed")
{
	std::cout << "Animal " << this->_type << " created.\n";
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "Animal " << this->_type << " created.\n";
}

/*----------------------------DESTRUCTORS----------------------------*/

Animal::~Animal(void)
{
	std::cout << "Animal " << this->_type << " destroyed.\n";
}

/*----------------------------COPY-METHODS----------------------------*/

Animal::Animal(const Animal &copy): _type(copy._type)
{
	std::cout << "Animal " << this->_type << " copied.\n";
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

Animal& Animal::operator=(const Animal &equal)
{
	std::cout << "Copy assignment operator called.\n";
	this->_type = equal._type;
	return (*this);
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

void			Animal::makeSound(void) const
{
	std::cout << "\"Undefined sound\"\n";
}

std::string		Animal::getType(void) const
{
	return (this->_type);
}
