/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:36:49 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/26 20:40:35 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap from ClapTrap " << this->_name << " created with default constructor.\n";
	this->_health = 100;
	this->_energy = 100;
	this->_attack = 30;
}

FragTrap::FragTrap(std::string const &name): ClapTrap(name)
{
	std::cout << "FragTrap from ClapTrap " << this->_name << " created.\n";
	this->_health = 100;
	this->_energy = 100;
	this->_attack = 30;
}

/*----------------------------COPY-METHODS----------------------------*/

FragTrap::FragTrap(FragTrap const &copy): ClapTrap(copy)
{
	std::cout << "FragTrap from ClapTrap " << this->_name << " copied.\n";
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

FragTrap	&FragTrap::operator=(FragTrap const &copy)
{
	std::cout << "Assignment operator for FragTrap called.\n";
	ClapTrap::operator=(copy);
	return (*this);
}

/*----------------------------DESTRUCTORS----------------------------*/

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap from ClapTrap " << this->_name << " destroyed.\n";
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

void	FragTrap::highFivesGuys(void)
{
	if (this->_health <= 0)
		std::cout << YELLOW << this->_name << " is already dead...\n" DEFAULT;
	else
		std::cout << BLUE "FragTrap from ClapTrap " << this->_name << " says: \"High five! ✋😎\".\n" DEFAULT;
}