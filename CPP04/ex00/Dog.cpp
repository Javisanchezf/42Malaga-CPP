/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:01 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/27 12:55:15 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

Dog::Dog(void): Animal("Dog")
{
	std::cout << "Dog constructor called.\n";
}

/*----------------------------DESTRUCTORS----------------------------*/

Dog::~Dog(void)
{
	std::cout << "Dog destroyed.\n";
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

void			Dog::makeSound(void) const
{
	std::cout << "\"🐶 Woof Woof!\"\n";
}
