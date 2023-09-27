/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:57:43 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/27 14:09:27 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

Brain::Brain(void)
{
	std::cout << "Brain constructor called.\n";
}

/*----------------------------COPY-METHODS----------------------------*/

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copied.\n";
	*this = copy;
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

Brain& Brain::operator=(const Brain &equal)
{
	std::cout << "Copy assignment Brain operator called.\n";
	if (this != &equal)
		for(int _ = 0; _ < 100; _++)
			this->_ideas[_] = equal._ideas[_];
	return (*this);
}

/*----------------------------DESTRUCTORS----------------------------*/

Brain::~Brain(void)
{
	std::cout << "Brain destroyed.\n";
}
