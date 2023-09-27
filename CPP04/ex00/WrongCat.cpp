/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:02:27 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/27 13:07:47 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called.\n";
}

/*----------------------------DESTRUCTORS----------------------------*/

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destroyed.\n";
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

void			WrongCat::makeSound(void) const
{
	std::cout << "\"😺 Meooow!\"\n";
}
