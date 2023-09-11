/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:58:03 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/11 22:02:58 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	this->_type = name;
}

Weapon::~Weapon()
{
	std::cout << RED "Weapon " << this->_type << " destroyed.\n" DEFAULT;
}

const std::string	Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string newtype)
{
	this->_type = newtype;
}
