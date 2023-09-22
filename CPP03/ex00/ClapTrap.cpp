/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:01 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/22 19:17:45 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

ClapTrap::ClapTrap(std::string name):
_name(name), _health(10), _energy(10), _attack(0)
{
	std::cout << "Default constructor called.\n";
	// this->_name = name;
	// this->_health = 10;
	// this->_energy = 10;
	// this->_attack = 0;
}

/*----------------------------DESTRUCTORS----------------------------*/

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called.\n";
}

/*----------------------------COPY-METHODS----------------------------*/

ClapTrap::ClapTrap(const ClapTrap &copy):
_name(copy._name), _health(copy._health), _energy(copy._energy), _attack(copy._attack)
{
	std::cout << "Copy constructor called.\n";
	// this->_name = copy._name;
	// this->_health = copy._health;
	// this->_energy = copy._energy;
	// this->_attack = copy._attack;
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

ClapTrap& ClapTrap::operator=(const ClapTrap &equal)
{
	std::cout << "Copy assignment operator called.\n";
	this->_name = equal._name;
	this->_health = equal._health;
	this->_energy = equal._energy;
	this->_attack = equal._attack;
	return (*this);
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

void	ClapTrap::attack(const std::string& target)
{
	
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	
}