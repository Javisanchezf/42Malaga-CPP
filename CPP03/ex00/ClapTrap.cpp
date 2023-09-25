/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:01 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/25 21:24:47 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

ClapTrap::ClapTrap(void):
_name("Unnamed"), _health(10), _energy(10), _attack(0)
{
	std::cout << "Default constructor called.\n";
}

ClapTrap::ClapTrap(std::string name):
_name(name), _health(10), _energy(10), _attack(0)
{
	std::cout << "Default constructor called.\n";
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

/*----------------------------PRIVATE-FUNCTIONS----------------------------*/
bool	ClapTrap::check_energy(ClapTrap &clapi)
{
	if (clapi._energy > 0)
	{
		clapi._energy--;
		return 1;
	}
	return 0;
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

void	ClapTrap::attack(const std::string& target)
{
	if (this->_health > 0 && check_energy(*this))
		std::cout << RED << this->_name << " attacks to " << target << " with " << this->_attack << " attack damage!\n" DEFAULT;
	else if (this->_health <= 0)
		std::cout << YELLOW << this->_name << " is already dead...\n" DEFAULT;
	else
		std::cout << YELLOW << this->_name << " doesn't have enough energy to attack...\n" DEFAULT;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health - amount > 0)
	// {
	// 	this->_health -= amount;
	// 	std::cout << RED << this->_name << " attacks to " << target << " with " << this->_attack << " attack damage!\n" DEFAULT;
	// }
	// else if (this->health <= 0)
	// 	std::cout << YELLOW << this->_name << " is already dead...\n" DEFAULT;
	// else
	// 	std::cout << RED << this->_name << " attacks to " << target << " with " << this->_attack << " attack damage!\n" DEFAULT;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_health > 0 && check_energy(*this))
	{
		this->_health += amount;
		std::cout << GREEN << this->_name << " repaired itself and gained " << amount << " health points! Current hit points: " << this->_health << "\n" DEFAULT;
	}
	else if (this->_health <= 0)
		std::cout << YELLOW << this->_name << " is already dead...\n" DEFAULT;
	else
		std::cout << YELLOW << this->_name << " doesn't have enough energy to repair...\n" DEFAULT;
}
