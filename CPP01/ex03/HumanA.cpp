/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:57:49 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/11 22:02:16 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon){}

HumanA::~HumanA()
{
	std::cout << RED "HumanA " << this->_name << " destroyed.\n" DEFAULT;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " << _weapon.getType() << "\n";
}
