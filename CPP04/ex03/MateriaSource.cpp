/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:01 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/28 11:06:54 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

MateriaSource::MateriaSource(void)
{
	for (int _ = 0; _ < 4; _++)
			this->_bag[_] = NULL;
	std::cout << "MateriaSource created.\n";
}

/*----------------------------COPY-METHODS----------------------------*/

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
	std::cout << "MateriaSource copied.\n";
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

MateriaSource& MateriaSource::operator=(const MateriaSource &equal)
{
	if (this != &equal)
		for (int _ = 0; _ < 4; _++)
			this->_bag[_] = equal._bag[_];
	std::cout << "Copy assignment operator called.\n";
	return (*this);
}

/*----------------------------DESTRUCTORS----------------------------*/

MateriaSource::~MateriaSource(void)
{
	for (int _ = 0; _ < 4; _++)
		if (this->_bag[_] != NULL)
			delete this->_bag[_];
	std::cout << "MateriaSource destroyed.\n";
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

void		MateriaSource::learnMateria( AMateria* m )
{
	bool flag = false;

	for (int _ = 0; _ < 4; _++)
		if (this->_bag[_] == NULL)
		{
			this->_bag[_] = m;
			std::cout << YELLOW "MateriaSource " << m->getType() << " learned in slot " << _ << ".\n" DEFAULT;
			return;
			flag = true;
		}
	if (flag == false)
		std::cout << "There are no space.\n";
}

AMateria*   MateriaSource::createMateria( std::string const& type )
{
	for (int _ = 0; _ < 4; _++)
		if (this->_bag[_] != NULL && this->_bag[_]->getType() == type )
			return this->_bag[_]->clone();
	return NULL;
}
