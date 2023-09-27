/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:04 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/27 14:12:17 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
#define CAT_HPP

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
class Cat : public Animal
{		
	private:
		Brain	*_brain;
	public:
		Cat(void);
		Cat(const Cat& src);
		Cat& operator=(const Cat& src);
		~Cat();

		void	makeSound(void) const;
};

#endif