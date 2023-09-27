/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:01 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/27 21:42:29 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

Ice::Ice(void): AMateria("ice")
{
	std::cout << "Ice " << this->_type << " created.\n";
}

/*----------------------------DESTRUCTORS----------------------------*/

Ice::~Ice(void)
{
	std::cout << "Ice " << this->_type << " destroyed.\n";
}

/*----------------------------COPY-METHODS----------------------------*/

Ice::Ice(const Ice &copy): AMateria("ice")
{
	this->_type = copy._type;
	std::cout << "Ice " << this->_type << " copied.\n";
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

Ice& Ice::operator=(const Ice &equal)
{
	std::cout << "Copy assignment operator called.\n";
	this->_type = equal._type;
	return (*this);
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

AMateria*			Ice::clone() const
{
	return new Ice(*this);
}

void				Ice::use(ICharacter& target)
{
	std::cout << "Ice " << this->_type << " * shoots an ice bolt at" << target.getName() <<" *.\n";
}
