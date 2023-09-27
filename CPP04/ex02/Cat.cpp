/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:01 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/27 14:31:57 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

Cat::Cat(void): Animal("Cat")
{
	std::cout << "Cat constructor called.\n";
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

Cat::Cat(const Cat &copy): Animal("Cat")
{
	std::cout << "Cat copied.\n";
	*this = copy;
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

Cat& Cat::operator=(const Cat &equal)
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

Cat::~Cat(void)
{
	delete  this->_brain;
	std::cout << "Cat destroyed.\n";
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

void			Cat::makeSound(void) const
{
	std::cout << "\"😺 Meooow!\"\n";
}
