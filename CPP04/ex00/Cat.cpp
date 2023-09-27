/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:01 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/27 12:55:07 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

Cat::Cat(void): Animal("Cat")
{
	std::cout << "Cat constructor called.\n";
}

/*----------------------------DESTRUCTORS----------------------------*/

Cat::~Cat(void)
{
	std::cout << "Cat destroyed.\n";
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

void			Cat::makeSound(void) const
{
	std::cout << "\"😺 Meooow!\"\n";
}
