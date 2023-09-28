/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:01 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/28 11:13:38 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

Character::Character(void): _name("Unnamed")
{
	for (int _ = 0; _ < 4; _++)
			this->_bag[_] = NULL;
	std::cout << "Character " << this->_name << " created.\n";
}

Character::Character(std::string name): _name(name)
{
	std::cout << "Character " << this->_name << " created.\n";
}

/*----------------------------COPY-METHODS----------------------------*/

Character::Character(const Character &copy): _name(copy._name)
{
	*this = copy;
	std::cout << "Character " << this->_name << " copied.\n";
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

Character& Character::operator=(const Character &equal)
{
	if (this != &equal)
	{
		this->_name = equal._name;
		for (int _ = 0; _ < 4; _++)
			this->_bag[_] = equal._bag[_];
	}
	std::cout << "Copy assignment operator called.\n";
	return (*this);
}

/*----------------------------DESTRUCTORS----------------------------*/

Character::~Character(void)
{
	for (int _ = 0; _ < 4; _++)
		if (this->_bag[_] != NULL)
			delete this->_bag[_];
	std::cout << "Character " << this->_name << " destroyed.\n";
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

std::string	const&	Character::getName(void) const
{
	return (this->_name);
}

void				Character::equip(AMateria* m)
{
	for (int _ = 0; _ < 4; _++)
		if (this->_bag[_] == NULL)
		{
			this->_bag[_] = m;
			return ;
		}
	std::cout << this->_name << " has the inventory full and can't eqquip " << m->getType() << ".\n";
}

void				Character::unequip(int idx)
{
	if (this->_bag[idx])
	{
		delete this->_bag[idx];
		this->_bag[idx] = NULL;
		std::cout << "Character " << this->_name << " unequipped.\n";
	}
	else
		std::cout << "Character " << this->_name << " can't unequip.\n";
}

void				Character::use(int idx, ICharacter& target)
{
	if (this->_bag[idx])
	{
		std::cout << "Character " << this->_name << " uses "<< this->_bag[idx]->getType() << ".\n";
		this->_bag[idx]->use(target);
		delete this->_bag[idx];
		this->_bag[idx] = NULL;
	}
	else
		std::cout << "Character " << this->_name << " has no materias in that space....\n";
}
