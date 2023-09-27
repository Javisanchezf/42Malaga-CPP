/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:55:40 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/26 20:43:58 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap from ClapTrap " << this->_name << " created with default constructor.\n";
	this->_health = 100;
	this->_energy = 50;
	this->_attack = 20;
	this->_guarding_gate = false;
}

ScavTrap::ScavTrap(std::string const &name): ClapTrap(name)
{
	std::cout << "ScavTrap from ClapTrap " << this->_name << " created.\n";
	this->_health = 100;
	this->_energy = 50;
	this->_attack = 20;
	this->_guarding_gate = false;
}

/*----------------------------COPY-METHODS----------------------------*/

ScavTrap::ScavTrap(ScavTrap const &copy): ClapTrap(copy)
{
	std::cout << "ScavTrap from ClapTrap " << this->_name << " copied.\n";
	this->_guarding_gate = copy._guarding_gate;
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout << "Assignment operator for ScavTrap called.\n";
	ClapTrap::operator=(copy);
	this->_guarding_gate = copy._guarding_gate;
	return (*this);
}

/*----------------------------DESTRUCTORS----------------------------*/

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap from ClapTrap " << this->_name << " destroyed.\n";
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

void	ScavTrap::guardGate(void)
{
	if (this->_health <= 0)
	{
		std::cout << YELLOW << this->_name << " is already dead...\n" DEFAULT;
		return ;
	}
	else if (this->_guarding_gate == false)
		std::cout << BLUE "ScavTrap from ClapTrap " << this->_name << " switched to mode: \"Gate keeper mode\".\n" DEFAULT;
	else
		std::cout << CYAN "ScavTrap from ClapTrap " << this->_name << " is already in \"Gate keeper mode\".\n" DEFAULT;
	this->_guarding_gate = true;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_health > 0  && this->_guarding_gate == false && check_energy(*this))
		std::cout << RED << this->_name << " from Scavtrap attacks to " << target << " with " << this->_attack << " attack damage!\n" DEFAULT;
	else if (this->_health > 0  && this->_guarding_gate == true && check_energy(*this))
	{
		std::cout << RED << this->_name << " from Scavtrap leave the \"Gate keeper mode\" and attacks to " << target << " with " << this->_attack << " attack damage!\n" DEFAULT;
		this->_guarding_gate = false;
	}
	else if (this->_health <= 0)
		std::cout << YELLOW << this->_name << " from Scavtrap is already dead...\n" DEFAULT;
	else
		std::cout << YELLOW << this->_name << " from Scavtrap doesn't have enough energy to attack...\n" DEFAULT;
		
}