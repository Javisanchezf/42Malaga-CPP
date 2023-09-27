/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:26:02 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/27 14:26:11 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

/*----------------------------LIBRARIES----------------------------*/
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

/*----------------------------COLORS----------------------------*/
# define BOLD		"\033[1m"
# define GRAY		"\033[30;1m"
# define RED		"\033[31;1m"
# define GREEN		"\033[32;1m"
# define YELLOW		"\033[33;1m"
# define BLUE		"\033[34;1m"
# define MAGENTA	"\033[35;1m"
# define CYAN		"\033[36;1m"
# define WHITE		"\033[37;1m"
# define DEFAULT	"\033[0m"

/*----------------------------CLASSES----------------------------*/
class Dog : public Animal
{		
	private:
		Brain	*_brain;
	public:
		Dog(void);
		Dog(const Dog& src);
		Dog& operator=(const Dog& src);
		~Dog();

		void	makeSound(void) const;
};

#endif