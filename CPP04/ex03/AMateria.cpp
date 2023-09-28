/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:01 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/28 10:52:24 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

AMateria::AMateria(void): _type("Unnamed")
{
	std::cout << "AMateria " << this->_type << " created.\n";
}

AMateria::AMateria(std::string type): _type(type)
{
	std::cout << "AMateria " << this->_type << " created.\n";
}

/*----------------------------DESTRUCTORS----------------------------*/

AMateria::~AMateria(void)
{
	std::cout << "AMateria " << this->_type << " destroyed.\n";
}

/*----------------------------COPY-METHODS----------------------------*/

AMateria::AMateria(const AMateria &copy): _type(copy._type)
{
	std::cout << "AMateria " << this->_type << " copied.\n";
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

AMateria& AMateria::operator=(const AMateria &equal)
{
	std::cout << "Copy assignment operator called.\n";
	this->_type = equal._type;
	return (*this);
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

std::string	const&	AMateria::getType(void) const
{
	return (this->_type);
}

AMateria*			AMateria::clone() const
{
	return (AMateria*)this;
}

void				AMateria::use(ICharacter& target)
{
	std::cout << "AMateria " << this->_type << " used on" << target.getName() <<".\n";
}
