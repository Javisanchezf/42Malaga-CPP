/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:33:40 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/10 13:28:03 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
}
Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " has been destroyed.\n";
}
void	Zombie::announce(void)
{
	std::cout << this->_name <<": BraiiiiiiinnnzzzZ...\n";
}
