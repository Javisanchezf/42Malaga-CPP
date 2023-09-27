/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:26:27 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/27 14:32:22 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

Dog::Dog(void): Animal("Dog")
{
	std::cout << "Dog constructor called.\n";
	try
	{
		this->_brain = new Brain();
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << RED "Memory allocation fail : " << e.what() << ".\n" DEFAULT;
	}
}

/*----------------------------COPY-METHODS----------------------------*/

Dog::Dog(const Dog &copy): Animal("Dog")
{
	std::cout << "Dog copied.\n";
	*this = copy;
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

Dog& Dog::operator=(const Dog &equal)
{
	std::cout << "Copy assignment operator called.\n";
	if (this != &equal)
	{
		this->_type = equal._type;
		this->_brain = equal._brain;
	}
	return (*this);
}

/*----------------------------DESTRUCTORS----------------------------*/

Dog::~Dog(void)
{
	delete  this->_brain;
	std::cout << "Dog destroyed.\n";
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

void			Dog::makeSound(void) const
{
	std::cout << "\"🐶 Woof Woof!\"\n";
}
