/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:55:40 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/26 18:07:16 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap from ClapTrap " << this->_name << " created with default constructor.\n";
}

ScavTrap::ScavTrap(std::string const &name): ClapTrap(name)
{
	std::cout << "ScavTrap from ClapTrap " << this->_name << " created.\n";
}

/*----------------------------DESTRUCTORS----------------------------*/

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap from ClapTrap " << this->_name << " destroyed.\n";
}

/*----------------------------DESTRUCTORS----------------------------*/

ScavTrap::ScavTrap(ScavTrap const &copy): ClapTrap(copy)
{
	std::cout << "ScavTrap from ClapTrap " << this->_name << " copied.\n";
}

/*----------------------------DESTRUCTORS----------------------------*/

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout << "Assignment operator for ScavTrap called.\n";
	ClapTrap::operator=(copy);
	return (*this);
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

void	ScavTrap::guardGate(void)
{
	if (this->_health <= 0)
		std::cout << YELLOW << this->_name << " is already dead...\n" DEFAULT;
	else
		std::cout << BLUE "ScavTrap from ClapTrap " << this->_name << " switched to mode: \"Gate keeper mode\".\n" DEFAULT;
}