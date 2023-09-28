/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:01 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/28 11:10:43 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Cure " << this->_type << " created.\n";
}

/*----------------------------COPY-METHODS----------------------------*/

Cure::Cure(const Cure &copy): AMateria("cure")
{
	this->_type = copy._type;
	std::cout << "Cure " << this->_type << " copied.\n";
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

Cure& Cure::operator=(const Cure &equal)
{
	std::cout << "Copy assignment operator called.\n";
	this->_type = equal._type;
	return (*this);
}

/*----------------------------DESTRUCTORS----------------------------*/

Cure::~Cure(void)
{
	std::cout << "Cure " << this->_type << " destroyed.\n";
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

AMateria*			Cure::clone() const
{
	return new Cure(*this);
}

void				Cure::use(ICharacter& target)
{
	std::cout << GREEN " * heals" << target.getName() <<"’s wounds *.\n" DEFAULT;
}
