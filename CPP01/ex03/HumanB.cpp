/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:57:55 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/11 22:02:45 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	_weapon = NULL;
}

HumanB::~HumanB()
{
	std::cout << RED "HumanB " << this->_name << " destroyed.\n" DEFAULT;
}

void	HumanB::attack(void) const
{
	if (_weapon)
		std::cout << this->_name << " attacks with their " << _weapon->getType() << "\n";
	else
		std::cout << this->_name << " can't attack because he has no weapon.\n";
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
